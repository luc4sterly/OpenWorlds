#!/usr/bin/env python3
"""Reusable capture tool for gamma.dll's FUN_00457d88 (.cmp scanline
pixel-reconstruction function) - built in the 2026-09-10+ continuation
session after 3 sessions of one-off, hand-run gdb scripts. Automates the
whole cycle: launch java.exe under Wine+winedbg/gdb (needs a running Xvfb -
see below), break at the function entry, extract the 5 input streams (big
enough to cover a full-image decode, not just one row) plus the real
per-position output for the FINAL outer pass, and write everything to a
structured directory.

Prerequisite: an Xvfb display must already be running and exported as
DISPLAY, e.g.:
    Xvfb :99 -screen 0 1024x768x24 &
    export DISPLAY=:99
(This script does not manage Xvfb's lifecycle itself, since a session may
want to reuse one across many capture runs.)

Usage:
    python3 cmp_capture.py <path-to.cmp> <output-dir> [--stream-bytes N]

Superseded limitation (was: "does not capture history, assumes zero-seed
suffices"): a 2026-09-10 session found real per-pass evidence that the
zero-seed hypothesis is WRONG - a single FUN_00457d88 call only covers
~1/4 of the image (confirmed on a 32x32 self-designed ground-truth file:
outerCount*2*stride == -(width*height) for ONE call, but ch0 == width/4
means each call only ever WRITES half a row per pass, so ~4 calls are
needed to cover a full image), and earlier calls' real output is exactly
what later calls' predictor reads pull from - not zero. This tool now
loops over EVERY call to FUN_00457d88 (not just the first) and, at each
call's entry, takes a real memory snapshot of the history window around
that call's edi0 (generous +/-`--hist-margin` bytes) - since by the time
call N starts, whatever call N-1 wrote is real, committed process memory
(the earlier "unreliable static snapshot" problem was specifically about
reading FORWARD from a mid-call breakpoint into pages the call itself
hadn't reached yet; reading at a FRESH call's entry, after prior calls
already wrote there, does not have that problem - confirmed empirically,
see the session's report). Each call's streams/history/real per-pass
output are written to `<outdir>/call<N>/`; the 5 symbol streams are only
captured once (at call 0) since they are the same continuous buffers read
across all calls, not reset per call.
"""
import argparse
import os
import subprocess
import sys
import time
import textwrap

REPO_ROOT = "/home/lucas/FreeWorlds"
JAVA_EXE = f"{REPO_ROOT}/assets/WorldsPlayer/bin/java.exe"
HARNESS_SRC = f"{REPO_ROOT}/tools/gamma-dll-debug-harness/NET/worlds/console/ScapePicImage.java"
HARNESS_OUT = f"{REPO_ROOT}/tools/gamma-dll-debug-harness/.harness_out"

# Runtime addresses of FUN_00457d88 and its internals, relative to
# gamma.dll's runtime load base. Confirmed deterministic across many runs
# in this environment: gamma.dll always loads at 0x03A40000, delta from its
# preferred static base (0x00400000, per Ghidra) is always 0x03640000. If
# this ever changes (different gamma.dll build, different environment),
# re-derive via `WINEDEBUG=+loaddll wine ... 2>&1 | grep gamma.dll` and
# recompute FUNC_ENTRY = static_addr + (new_base - 0x00400000).
GAMMA_BASE_RUNTIME = 0x03A40000
GAMMA_BASE_STATIC = 0x00400000
DELTA = GAMMA_BASE_RUNTIME - GAMMA_BASE_STATIC
FUNC_ENTRY = 0x00457d88 + DELTA


def sh(cmd, **kw):
    print(f"+ {cmd}")
    return subprocess.run(cmd, shell=True, **kw)


def ensure_harness_built():
    marker = f"{HARNESS_OUT}/NET/worlds/console/ScapePicImage.class"
    if os.path.exists(marker):
        return
    os.makedirs(HARNESS_OUT, exist_ok=True)
    r = sh(f"javac --release 8 -d {HARNESS_OUT} {HARNESS_SRC}")
    if r.returncode != 0:
        sys.exit("harness compile failed")
    sh(textwrap.dedent(f"""
        python3 -c "
data = bytearray(open('{marker}', 'rb').read())
data[6] = 0; data[7] = 48
open('{marker}', 'wb').write(data)
"
    """).strip())


GDB_SCRIPT_TEMPLATE = """
set confirm off
set pagination off
python
import gdb
state = {{"armed": False}}
def on_new_objfile(event):
    try:
        name = event.new_objfile.filename
    except Exception:
        return
    if name and 'gamma.dll' in name.lower() and not state["armed"]:
        state["armed"] = True
        gdb.execute('break *0x{func_entry:X}')

gdb.events.new_objfile.connect(on_new_objfile)
end
continue
python
import gdb, os

def rd(addr, n):
    inf = gdb.selected_inferior()
    return bytes(inf.read_memory(addr, n))

log = []
outdir = {outdir!r}
os.makedirs(outdir, exist_ok=True)
N = {stream_bytes}
HIST_MARGIN = {hist_margin}
MAX_CALLS = {max_calls}

# Per-call state, reset at the top of each loop iteration. Shared (not
# per-call-local) because the Write1Bp/Write2Bp breakpoint objects below
# are created ONCE and persist across all calls - they close over this
# dict rather than being recreated per call.
cstate = {{"esi0": None, "pass_index": 0, "last_offset": -1}}
cresults = {{}}  # (pass_index, offset) -> byte value, cleared each call

# Auto-continuing breakpoints (stop() returns False) - these run at full
# native speed between hits, unlike single-stepping every instruction,
# which is what made earlier sessions' captures slow (thousands of stepi
# round-trips through the winedbg-gdb proxy for even a partial decode).
WRITE1 = {{
    0x03a97e39: (0, 'al'), 0x03a97e4f: (1, 'al'),
    0x03a97ebb: (0, 'ah'), 0x03a97ee5: (1, 'ah'),
    0x03a97fbd: (0, 'al'), 0x03a97fd3: (1, 'al'),
}}

class Write1Bp(gdb.Breakpoint):
    # SINGLE (0x...e39/e4f) and the 0x24 literal escape (0x...fbd/fd3) both
    # do "rol eax,8; mov [esi(+1)],al" - the real byte is pre-rotated into
    # AL before the store. DUAL (0x...ebb/ee5) has no such rotation - its
    # real instructions are "mov [esi],ah" / "mov [esi+1],ah" (confirmed by
    # disassembly AND a live single-step trace, 2026-09-10, LINEA A
    # session). An earlier version of this script always read AL regardless
    # of address, which silently captured the WRONG byte for every DUAL
    # write - invisible against every file tested so far because none of
    # them took a real DUAL branch (confirmed separately via a live branch
    # census), until rustwood.cmp exposed it. `reg` picks which byte to read.
    def __init__(self, addr, byteslot, reg):
        super(Write1Bp, self).__init__("*0x%x" % addr, internal=False)
        self.byteslot = byteslot
        self.reg = reg
    def stop(self):
        if cstate["esi0"] is None:
            return False
        esi = int(gdb.parse_and_eval("$esi")) & 0xffffffff
        off = esi - cstate["esi0"]
        if off < cstate["last_offset"]:
            cstate["pass_index"] += 1
        cstate["last_offset"] = off
        eax = int(gdb.parse_and_eval("$eax")) & 0xffffffff
        val = eax & 0xff if self.reg == 'al' else (eax >> 8) & 0xff
        cresults[(cstate["pass_index"], off + self.byteslot)] = val
        return False

class Write2Bp(gdb.Breakpoint):
    def stop(self):
        if cstate["esi0"] is None:
            return False
        esi = int(gdb.parse_and_eval("$esi")) & 0xffffffff
        off = esi - cstate["esi0"]
        if off < cstate["last_offset"]:
            cstate["pass_index"] += 1
        cstate["last_offset"] = off
        eax = int(gdb.parse_and_eval("$eax")) & 0xffff
        cresults[(cstate["pass_index"], off)] = eax & 0xff
        cresults[(cstate["pass_index"], off + 1)] = (eax >> 8) & 0xff
        return False

for addr, (slot, reg) in WRITE1.items():
    Write1Bp(addr, slot, reg)
Write2Bp("*0x03a97f65")

# We are already stopped at call 0's FUNC_ENTRY (the top-level `continue`
# above ran until gamma.dll loaded AND the first call happened to hit it -
# on_new_objfile arms the breakpoint, which then behaves like any other
# breakpoint for every subsequent call too, so later loop iterations'
# gdb.execute("continue") calls land here again for call 1, 2, 3...).
call_idx = 0
while call_idx < MAX_CALLS:
    try:
        for _ in range(5):
            gdb.execute("stepi", to_string=True)
        ebp = int(gdb.parse_and_eval("$ebp")) & 0xffffffff
        edi0 = int(gdb.parse_and_eval("*(int*)(%d+0x8)" % ebp)) & 0xffffffff
        esi0 = int(gdb.parse_and_eval("*(int*)(%d+0xc)" % ebp)) & 0xffffffff
        outer0 = int(gdb.parse_and_eval("*(int*)(%d+0x10)" % ebp)) & 0xffffffff
        ch0 = int(gdb.parse_and_eval("*(int*)(%d+0x14)" % ebp)) & 0xff
        stride0_raw = int(gdb.parse_and_eval("*(int*)(%d+0x18)" % ebp))
        structptr = int(gdb.parse_and_eval("*(int*)(%d+0x1c)" % ebp)) & 0xffffffff
        bits_ptr = int(gdb.parse_and_eval("*(int*)(%d)" % structptr)) & 0xffffffff
        stream_a = int(gdb.parse_and_eval("*(int*)(%d+0x4)" % structptr)) & 0xffffffff
        stream_fillidx = int(gdb.parse_and_eval("*(int*)(%d+0x8)" % structptr)) & 0xffffffff
        stream_ctrl = int(gdb.parse_and_eval("*(int*)(%d+0xc)" % structptr)) & 0xffffffff
        stream_lit = int(gdb.parse_and_eval("*(int*)(%d+0x10)" % structptr)) & 0xffffffff

        call_outdir = os.path.join(outdir, "call%d" % call_idx)
        os.makedirs(call_outdir, exist_ok=True)
        clog = []
        clog.append("edi0=%08x esi0=%08x outer0=%d ch0=%d stride0=%d" % (edi0, esi0, outer0, ch0, stride0_raw))
        clog.append("structptr=%08x bits_ptr=%08x" % (structptr, bits_ptr))
        clog.append("stream_a=%08x stream_fillidx=%08x stream_ctrl=%08x stream_lit=%08x" % (stream_a, stream_fillidx, stream_ctrl, stream_lit))

        if call_idx == 0:
            # the 5 symbol streams are the SAME continuous buffers read
            # across ALL calls (gamma.dll does not reset these pointers
            # per call) - capture once, generously, from call 0's start
            dumps = {{
                "bits": (bits_ptr, N),
                "stream_a": (stream_a, N),
                "stream_fillidx": (stream_fillidx, N),
                "stream_ctrl": (stream_ctrl, N),
                "stream_lit": (stream_lit, N),
            }}
            for name, (addr, n) in dumps.items():
                data = rd(addr, n)
                with open(os.path.join(outdir, name + ".bin"), "wb") as f:
                    f.write(data)
                log.append("dumped %s: %d bytes from 0x%08x (call 0 only)" % (name, len(data), addr))

        # REAL history snapshot around THIS call's edi0 - by now, whatever
        # earlier calls wrote is real, committed process memory (not the
        # "reading forward past what a mid-call snapshot can see" problem
        # documented in the module docstring - that was about reading
        # ahead of where the CURRENT call itself had written so far).
        # The allocation backing this buffer can be smaller than a fixed
        # margin guess (confirmed live: 4096 bytes back from edi0 hit an
        # unmapped page for a tiny 32x32 image) - shrink EACH DIRECTION
        # independently until it succeeds, rather than a single symmetric
        # margin (the predictor table has offsets up to +518, which can
        # need real forward room well past what's valid backward).
        def shrink_read(start_addr, want, direction):
            m = want
            while m >= 32:
                try:
                    return rd(start_addr, m) if direction > 0 else rd(start_addr - m, m)
                except Exception:
                    m //= 2
            return b""

        back_data = shrink_read(edi0, HIST_MARGIN, -1)
        fwd_data = shrink_read(edi0, HIST_MARGIN, 1)
        back_margin = len(back_data)
        fwd_margin = len(fwd_data)
        hist_data = back_data + fwd_data
        hist_start = edi0 - back_margin
        with open(os.path.join(call_outdir, "history.bin"), "wb") as f:
            f.write(hist_data)
        clog.append("history.bin: %d bytes from 0x%08x (edi0 at offset %d; back_margin=%d fwd_margin=%d)" %
                     (len(hist_data), hist_start, back_margin, back_margin, fwd_margin))

        cstate["esi0"] = esi0
        cstate["pass_index"] = 0
        cstate["last_offset"] = -1
        cresults.clear()

        gdb.execute("continue", to_string=True)  # runs this call's outer-pass decode; stops at the NEXT call's FUNC_ENTRY, or raises if the process exits

        max_pass = max((p for p, _ in cresults.keys()), default=-1)
        last_pass_bytes = bytearray(ch0 * 2)
        for (p, o), v in cresults.items():
            if p == max_pass and 0 <= o < len(last_pass_bytes):
                last_pass_bytes[o] = v
        with open(os.path.join(call_outdir, "esi_final_pass.bin"), "wb") as f:
            f.write(bytes(last_pass_bytes))
        with open(os.path.join(call_outdir, "esi_all_passes.csv"), "w") as f:
            f.write("pass,offset,value\\n")
            for (p, o), v in sorted(cresults.items()):
                f.write("%d,%d,%d\\n" % (p, o, v))
        clog.append("captured %d (pass,offset) write events across %d passes seen" % (len(cresults), max_pass + 1))
        with open(os.path.join(call_outdir, "extract_log.txt"), "w") as f:
            f.write("\\n".join(clog))
        log.append("call%d: done, %d write events, %d passes" % (call_idx, len(cresults), max_pass + 1))
        call_idx += 1
    except Exception as e:
        log.append("loop stopped at call_idx=%d: %s" % (call_idx, e))
        break

log.append("total calls captured: %d" % call_idx)
with open(os.path.join(outdir, "extract_log.txt"), "w") as f:
    f.write("\\n".join(log))
print("=== CAPTURE DONE (%d calls) ===" % call_idx)
end
quit
"""


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmp_file", help="path to a real .cmp file")
    ap.add_argument("outdir", help="directory to write captured evidence into")
    ap.add_argument("--stream-bytes", type=int, default=65536,
                     help="bytes to dump per stream (default 65536, generous enough for a full-image decode)")
    ap.add_argument("--max-steps", type=int, default=400000,
                     help="max single-step budget for the full-decode trace (default 400000, currently unused by the template but kept for CLI compatibility)")
    ap.add_argument("--max-calls", type=int, default=8,
                     help="max number of FUN_00457d88 calls to capture (default 8; a full image typically needs ~4, generous upper bound so the loop stops on its own when the process exits)")
    ap.add_argument("--hist-margin", type=int, default=4096,
                     help="bytes of real history to snapshot before AND after each call's edi0 (default 4096)")
    ap.add_argument("--timeout", type=int, default=600, help="wine/gdb subprocess timeout in seconds")
    args = ap.parse_args()

    if not os.environ.get("DISPLAY"):
        sys.exit("DISPLAY not set - start Xvfb first (see this script's docstring)")

    cmp_abs = os.path.abspath(args.cmp_file)
    outdir_abs = os.path.abspath(args.outdir)
    os.makedirs(outdir_abs, exist_ok=True)

    ensure_harness_built()

    wine_c_target = os.path.expanduser("~/.wine/drive_c/_capture_target.cmp")
    sh(f"cp {cmp_abs!r} {wine_c_target!r}")

    sh("wineserver -k", )
    time.sleep(1)

    gdb_script = GDB_SCRIPT_TEMPLATE.format(
        func_entry=FUNC_ENTRY,
        outdir=outdir_abs,
        stream_bytes=args.stream_bytes,
        max_calls=args.max_calls,
        hist_margin=args.hist_margin,
    )
    script_path = os.path.join(outdir_abs, "_gdbscript.txt")
    with open(script_path, "w") as f:
        f.write(gdb_script)

    win_harness_path = HARNESS_OUT.replace("/home/lucas/FreeWorlds", r"Z:\home\lucas\FreeWorlds").replace("/", "\\")
    cmd = (
        f"winedbg --gdb 'Z:\\home\\lucas\\FreeWorlds\\assets\\WorldsPlayer\\bin\\java.exe' "
        f"-cp '{win_harness_path}' NET.worlds.console.ScapePicImage 'C:\\_capture_target.cmp' "
        f"< {script_path!r} > {outdir_abs}/_run.log 2>&1"
    )
    r = sh(f"timeout {args.timeout} {cmd}")
    print(f"exit code: {r.returncode}")

    log_path = os.path.join(outdir_abs, "extract_log.txt")
    if os.path.exists(log_path):
        print("--- extract_log.txt ---")
        print(open(log_path).read())
    else:
        print("!! no extract_log.txt written - check _run.log for errors")

    sh("wineserver -k")
    os.remove(wine_c_target) if os.path.exists(wine_c_target) else None


if __name__ == "__main__":
    main()
