set confirm off
set pagination off
python
import gdb
state = {"armed": False}
def on_new_objfile(event):
    try:
        name = event.new_objfile.filename
    except Exception:
        return
    if name and 'gamma.dll' in name.lower() and not state["armed"]:
        state["armed"] = True
        gdb.execute('break *0x3a97f77')
        gdb.execute('break *0x3a97f7e')

gdb.events.new_objfile.connect(on_new_objfile)
end
continue
python
import gdb

hits = 0
MAX_HITS = 40
pending_al = None
pending_edx = None

while hits < MAX_HITS:
    try:
        pc = int(gdb.parse_and_eval("$pc")) & 0xffffffff
    except Exception as e:
        print("STOP:", e)
        break
    if pc == 0x3a97f77:
        eax = int(gdb.parse_and_eval("$eax")) & 0xffffffff
        edx = int(gdb.parse_and_eval("$edx")) & 0xffffffff
        print("PRE  call: eax=%08x edx(idx)=%08x al=%02x" % (eax, edx, eax & 0xff))
    elif pc == 0x3a97f7e:
        eax = int(gdb.parse_and_eval("$eax")) & 0xffffffff
        ebx = int(gdb.parse_and_eval("$ebx")) & 0xffffffff
        ecx = int(gdb.parse_and_eval("$ecx")) & 0xffffffff
        edx = int(gdb.parse_and_eval("$edx")) & 0xffffffff
        print("POST call: eax=%08x ebx=%08x ecx=%08x edx=%08x" % (eax, ebx, ecx, edx))
        hits += 1
    try:
        gdb.execute("continue", to_string=True)
    except Exception as e:
        print("STOP2:", e)
        break

print("=== TRACE DONE ===")
end
quit
