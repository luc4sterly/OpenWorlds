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

Known limitation this tool does NOT solve (documented, not hidden): a
STATIC one-time memory snapshot of the "history" scratch buffer
(gamma.dll's `edi`-addressed 2D-predictor working area) is unreliable -
confirmed across 2 earlier sessions, a single upfront `read_memory()` call
only sees ~120 bytes forward from the starting position even though the
real process reads much further without crashing later (most likely a
lazily-committed page that only becomes valid once nearby writes trigger
the OS to grow it - something no single Python-side snapshot call can
replicate). This tool sidesteps the problem instead of solving it: it does
NOT capture the history buffer at all. The current best hypothesis (see
docs/cmp-texture-format-reference.md, "outer loop" discovery) is that the
real buffer is freshly allocated (hence OS-zero-initialized) and the
decode process builds all its own history context across the outer loop's
64 passes - if true, a Java re-implementation needs no external history
seed whatsoever. This tool captures what's needed to test that hypothesis
(the 5 streams, generously sized) rather than trying to capture history
directly.
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
results = {{}}  # (pass_index, offset) -> byte value
state = {{"esi0": None, "pass_index": 0, "last_offset": -1, "done": False}}

# Auto-continuing breakpoints (stop() returns False) - these run at full
# native speed between hits, unlike single-stepping every instruction,
# which is what made earlier sessions' captures slow (thousands of stepi
# round-trips through the winedbg-gdb proxy for even a partial decode).
# A full 64-outer-pass x 32-inner-iteration decode only hits these ~4000
# times total, not the ~1-2 million raw instructions it would take to
# single-step through - this is the actual "cleaner method" fix.
WRITE1 = {{
    0x03a97e39: 0, 0x03a97e4f: 1,
    0x03a97ebb: 0, 0x03a97ee5: 1,
    0x03a97fbd: 0, 0x03a97fd3: 1,
}}

class Write1Bp(gdb.Breakpoint):
    def __init__(self, addr, byteslot):
        super(Write1Bp, self).__init__("*0x%x" % addr, internal=False)
        self.byteslot = byteslot
    def stop(self):
        if state["esi0"] is None:
            return False
        esi = int(gdb.parse_and_eval("$esi")) & 0xffffffff
        off = esi - state["esi0"]
        if off < state["last_offset"]:
            state["pass_index"] += 1
        state["last_offset"] = off
        al = int(gdb.parse_and_eval("$eax")) & 0xff
        results[(state["pass_index"], off + self.byteslot)] = al
        return False

class Write2Bp(gdb.Breakpoint):
    def stop(self):
        if state["esi0"] is None:
            return False
        esi = int(gdb.parse_and_eval("$esi")) & 0xffffffff
        off = esi - state["esi0"]
        if off < state["last_offset"]:
            state["pass_index"] += 1
        state["last_offset"] = off
        eax = int(gdb.parse_and_eval("$eax")) & 0xffff
        results[(state["pass_index"], off)] = eax & 0xff
        results[(state["pass_index"], off + 1)] = (eax >> 8) & 0xff
        return False

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
    log.append("edi0=%08x esi0=%08x outer0=%d ch0=%d stride0=%d" % (edi0, esi0, outer0, ch0, stride0_raw))
    log.append("structptr=%08x bits_ptr=%08x" % (structptr, bits_ptr))
    log.append("stream_a=%08x stream_fillidx=%08x stream_ctrl=%08x stream_lit=%08x" % (stream_a, stream_fillidx, stream_ctrl, stream_lit))
    state["esi0"] = esi0

    N = {stream_bytes}
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
        log.append("dumped %s: %d bytes from 0x%08x" % (name, len(data), addr))

    # return address, so we can stop cleanly instead of running past the
    # real end of the function into unrelated later code
    esp_now = int(gdb.parse_and_eval("$esp")) & 0xffffffff
    # esp moved since entry (prologue pushes) - retrieve the original
    # return address we noted before those pushes ran instead
    retaddr = state.get("retaddr")

    for addr, slot in WRITE1.items():
        Write1Bp(addr, slot)
    Write2Bp("*0x03a97f65")

    gdb.execute("continue", to_string=True)  # runs until ReturnBp (set below) or a real crash/exit

    log.append("done=%s, captured %d (pass,offset) write events across %d passes seen" % (state["done"], len(results), state["pass_index"] + 1))

    max_pass = max((p for p, _ in results.keys()), default=-1)
    last_pass_bytes = bytearray(ch0 * 2)
    for (p, o), v in results.items():
        if p == max_pass and 0 <= o < len(last_pass_bytes):
            last_pass_bytes[o] = v
    with open(os.path.join(outdir, "esi_final_pass.bin"), "wb") as f:
        f.write(bytes(last_pass_bytes))

    with open(os.path.join(outdir, "esi_all_passes.csv"), "w") as f:
        f.write("pass,offset,value\\n")
        for (p, o), v in sorted(results.items()):
            f.write("%d,%d,%d\\n" % (p, o, v))
    log.append("last pass index=%d, wrote esi_final_pass.bin (%d bytes) and esi_all_passes.csv" % (max_pass, len(last_pass_bytes)))
except Exception as e:
    log.append("STOP: " + str(e))

with open(os.path.join(outdir, "extract_log.txt"), "w") as f:
    f.write("\\n".join(log))
print("=== CAPTURE DONE ===")
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
                     help="max single-step budget for the full-decode trace (default 400000)")
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
        max_steps=args.max_steps,
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
