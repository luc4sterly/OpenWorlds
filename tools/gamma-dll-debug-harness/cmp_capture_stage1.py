#!/usr/bin/env python3
"""One-off live-trace tool for the Stage 1 table-construction region
(FUN_00442750, the header+table-building function) - adapted directly from
the proven cmp_capture.py pattern (same wineprefix, same on_new_objfile
arming so raw-address breakpoints never land before gamma.dll is mapped).

Captures, for a given .cmp file:
  - every FUN_0042f460 (the plain sequential file-read wrapper, confirmed
    this session by 3 independent forks to be just std::istream::read, no
    complex buffering) call's (dest, size) args and a hex dump of what
    landed in dest after the call returns.
  - every FUN_004269c0 (per-table Huffman construction, called 4x for table
    indices 0-3) call's cursor-pointer argument, so table-region byte
    offsets can be computed as cursor deltas relative to the 2nd
    FUN_0042f460 call's destination buffer.

Usage: python3 cmp_capture_stage1.py <path-to.cmp> <output-dir>
Requires: DISPLAY already set to a running Xvfb.
"""
import os
import subprocess
import sys
import time
import textwrap

REPO_ROOT = "/home/lucas/OpenWorlds"
HARNESS_SRC = f"{REPO_ROOT}/tools/gamma-dll-debug-harness/NET/worlds/console/ScapePicImage.java"
HARNESS_OUT = f"{REPO_ROOT}/tools/gamma-dll-debug-harness/.harness_out"

GAMMA_BASE_RUNTIME = 0x03A40000
GAMMA_BASE_STATIC = 0x00400000
DELTA = GAMMA_BASE_RUNTIME - GAMMA_BASE_STATIC

FUNC_ENTRY = 0x00442750 + DELTA   # FUN_00442750, header/table setup - arming point
READ_FN = 0x0042f460 + DELTA      # FUN_0042f460, sequential read wrapper
TABLE_FN = 0x004269c0 + DELTA     # FUN_004269c0, per-table Huffman construction


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
        gdb.execute('break *0x{read_fn:X}')
        gdb.execute('break *0x{table_fn:X}')

gdb.events.new_objfile.connect(on_new_objfile)
end
continue
python
import gdb

def rd(addr, n):
    inf = gdb.selected_inferior()
    try:
        return bytes(inf.read_memory(addr, n))
    except Exception as e:
        return b""

log = []
read_calls = []
table_calls = []
func_entry_hits = 0
pending_ret = None  # (retaddr, dest, size, dumpname) awaiting post-return dump
dump_count = 0

for i in range(600):
    try:
        pc = int(gdb.parse_and_eval("$pc")) & 0xffffffff
    except Exception as e:
        log.append("no pc, stopping: %s" % e)
        break
    if pending_ret is not None and pc == pending_ret[0]:
        retaddr, dest, size, dumpname = pending_ret
        data = rd(dest, size)
        with open({outdir!r} + "/" + dumpname, "wb") as f:
            f.write(data)
        log.append("dumped %s: %d bytes from 0x%x (wanted %d)" % (dumpname, len(data), dest, size))
        gdb.execute("clear *0x%x" % retaddr, to_string=True)
        pending_ret = None
    elif pc == 0x{func_entry:X}:
        func_entry_hits += 1
        log.append("FUNC_ENTRY hit #%d" % func_entry_hits)
    elif pc == 0x{read_fn:X}:
        esp = int(gdb.parse_and_eval("$esp")) & 0xffffffff
        stack = [int(gdb.parse_and_eval("*(int*)(%d+%d)" % (esp, k))) & 0xffffffff for k in (0,4,8,0xc,0x10)]
        read_calls.append(("entry", stack))
        log.append("READ_FN entry stack[0..4*4]=%s" % ["0x%x" % s for s in stack])
        retaddr, dest, size = stack[0], stack[1], stack[2]
        if size < 0x10000 and pending_ret is None:
            dump_count += 1
            dumpname = "read%d_dump.bin" % dump_count
            gdb.execute("break *0x%x" % retaddr, to_string=True)
            pending_ret = (retaddr, dest, size, dumpname)
    elif pc == 0x{table_fn:X}:
        esp = int(gdb.parse_and_eval("$esp")) & 0xffffffff
        stack = [int(gdb.parse_and_eval("*(int*)(%d+%d)" % (esp, k))) & 0xffffffff for k in (0,4,8,0xc,0x10,0x14)]
        table_calls.append(("entry", stack))
        log.append("TABLE_FN entry stack[0..5*4]=%s" % ["0x%x" % s for s in stack])
    try:
        gdb.execute("continue", to_string=True)
    except Exception as e:
        log.append("continue raised, process likely exited: %s" % e)
        break

with open({outfile!r}, "w") as f:
    f.write("\\n".join(log))
    f.write("\\n\\n=== READ_FN calls ===\\n")
    for tag, stack in read_calls:
        f.write("%s %s\\n" % (tag, stack))
    f.write("\\n=== TABLE_FN calls ===\\n")
    for tag, stack in table_calls:
        f.write("%s %s\\n" % (tag, stack))
print("=== TRACE DONE, %d read calls, %d table calls, %d func entries, %d dumps ===" % (len(read_calls), len(table_calls), func_entry_hits, dump_count))
end
quit
"""


def main():
    cmp_path = sys.argv[1]
    outdir = sys.argv[2]
    os.makedirs(outdir, exist_ok=True)

    if not os.environ.get("DISPLAY"):
        sys.exit("DISPLAY not set")

    ensure_harness_built()

    wine_c_target = os.path.expanduser("~/.wine/drive_c/_capture_target.cmp")
    sh(f"cp {os.path.abspath(cmp_path)!r} {wine_c_target!r}")

    sh("wineserver -k")
    time.sleep(1)

    outfile = os.path.join(outdir, "trace_result.txt")
    gdb_script = GDB_SCRIPT_TEMPLATE.format(
        func_entry=FUNC_ENTRY, read_fn=READ_FN, table_fn=TABLE_FN, outfile=outfile, outdir=outdir,
    )
    script_path = os.path.join(outdir, "_gdbscript.txt")
    with open(script_path, "w") as f:
        f.write(gdb_script)

    win_harness_path = HARNESS_OUT.replace("/home/lucas/OpenWorlds", r"Z:\home\lucas\OpenWorlds").replace("/", "\\")
    cmd = (
        f"winedbg --gdb 'Z:\\home\\lucas\\OpenWorlds\\assets\\WorldsPlayer\\bin\\java.exe' "
        f"-cp '{win_harness_path}' NET.worlds.console.ScapePicImage 'C:\\_capture_target.cmp' "
        f"< {script_path!r} > {outdir}/_run.log 2>&1"
    )
    r = sh(f"timeout 180 {cmd}")
    print(f"exit code: {r.returncode}")
    if os.path.exists(outfile):
        print(open(outfile).read())
    else:
        print("!! no trace_result.txt - check _run.log")
        print(open(os.path.join(outdir, "_run.log")).read()[-3000:])

    sh("wineserver -k")
    os.remove(wine_c_target) if os.path.exists(wine_c_target) else None


if __name__ == "__main__":
    main()
