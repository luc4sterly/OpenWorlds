# gamma.dll dynamic-debugging harness (Wine)

Minimal, clean-room Java classes that call `gamma.dll`'s real exported JNI
native methods directly, under Wine's own bundled period-correct JRE
(`assets/WorldsPlayer/bin/java.exe`, Java 1.4.2_05) - built for the
2026-09-10 `.cmp` dynamic-debugging session (see
`docs/cmp-texture-format-reference.md`, "Sesión de depuración dinámica").
They don't implement the real `NET.worlds.*` classes (those need the full
client tree) - they only declare the exact `native` method signatures with
matching class/package names, which is all JNI's name-mangled symbol
resolution (`Java_NET_worlds_console_ScapePicImage_loadImage`, etc.)
actually requires.

## Why bytecode-patch instead of a period javac

Modern `javac --release 8` (the oldest release still accepted by current
JDKs) emits class file major version 52, which Java 1.4.2 refuses to load
(`UnsupportedClassVersionError` - 1.4.2 only accepts up to major 48). Since
the source here is deliberately trivial (no generics, no string
concatenation via `+` - that would emit `StringBuilder` calls, a class that
doesn't exist in the 1.4.2 rt.jar - no enhanced-for, no autoboxing), the
compiled class file uses no bytecode features newer than Java 1.2, so it's
safe to patch the class file's major-version bytes (offset 6-7, big-endian
`u2`) from 52 down to 48 after compiling. **Keep new harness code this
plain** if you add more classes here, or the patched class will load but
throw `NoClassDefFoundError` for a runtime-library class 1.4.2 doesn't have.

```
javac --release 8 -d out NET/worlds/console/ScapePicImage.java
python3 -c "
data = bytearray(open('out/NET/worlds/console/ScapePicImage.class','rb').read())
data[6] = 0; data[7] = 48
open('out/NET/worlds/console/ScapePicImage.class', 'wb').write(data)
"
```

## Running under Wine

The sandboxed shell in this environment blocks the syscalls Wine's loader
needs (`ws2_32.dll` fails with `STATUS_INVALID_IMAGE_HASH` and the process
never gets past `wineboot`) - every Wine invocation needs
`dangerouslyDisableSandbox: true` on the Bash tool call.

```
wine assets/WorldsPlayer/bin/java.exe \
  -cp <dir containing NET/worlds/... /out> \
  NET.worlds.console.ScapePicImage 'C:\path\to\file.cmp'
```

`gamma.dll` is found via the default DLL search path (same directory as
`java.exe`) - no need to set `java.library.path` if you run the bundled
`java.exe` in place. Wine's `Z:` drive maps to host `/` by default, so a
host path can be passed directly as `Z:\home\lucas\FreeWorlds\...`.

**Stale-process gotcha**: a killed/timed-out Wine process leaves
`wineserver` (and `winedevice.exe` helpers) running in the background,
and subsequent launches sharing that same `wineserver` instance can inherit
lock contention from the dead process and hang for no apparent reason. Run
`wineserver -k` before a fresh test if a previous run was killed by
`timeout`.

## Driving it under a debugger (winedbg --gdb)

`winedbg --gdb <full Windows path to java.exe> <args...>` launches the
process under Wine and attaches a real `gdb` to it via a proxy. Two
non-obvious things you need to work around:

1. **Setting a breakpoint by raw address fails until the target module is
   actually loaded** (`Cannot access memory at address ...`) - `gamma.dll`
   is `LoadLibrary`'d well after process start (from `System.loadLibrary`
   inside `main`), so a `break *0x...` issued immediately after attach
   always fails. Use gdb's Python API to react to the DLL actually loading
   instead of guessing a delay:

   ```python
   python
   import gdb
   state = {"armed": False}
   def on_new_objfile(event):
       name = getattr(event.new_objfile, "filename", "") or ""
       if "gamma.dll" in name.lower() and not state["armed"]:
           state["armed"] = True
           gdb.execute("break *0x<runtime address>")
   gdb.events.new_objfile.connect(on_new_objfile)
   end
   continue
   ```

2. **gdb's symbol names for `gamma.dll` addresses are unreliable** -
   this session repeatedly saw addresses mislabeled against the *wrong*
   exported function (e.g. a real, Ghidra-confirmed internal function at
   static VA `0x00442750` was displayed by gdb as
   `_Java_NET_worlds_core_SystemInfo_GetProcessorType@8+736`, which is a
   *different*, unrelated export). Don't trust the label; compute the
   runtime address yourself (`runtime_base - preferred_ImageBase(0x00400000)
   + static_VA`, where `runtime_base` comes from a `loads DLL ... at
   0xXXXXXXXX` trace line - stable/deterministic across runs of the same
   binary in this setup) and cross-check the *static* VA against a fresh
   Ghidra disassembly (`analysis/GammaDLL.gpr`) of the exact same file, not
   old session notes - see the 2026-09-10 session's finding that gdb's own
   labels, not the underlying addresses, were the thing that was wrong.

## RESOLVED (2026-09-10, continuation session): Xvfb alone unblocks it

Root cause of the device/window hang below was simply **no X server**
for Wine to talk to. Starting a virtual one and pointing Wine at it fixes
it completely, with no window manager needed:

```
Xvfb :99 -screen 0 1024x768x24 &
DISPLAY=:99 wine assets/WorldsPlayer/bin/java.exe -cp <out> \
  NET.worlds.console.ScapePicImage 'C:\path\to\file.cmp'
```

With `DISPLAY` pointing at a live Xvfb, `ScapePicImage.loadImage()` on a
normal-mode (`0x02`) `.cmp` file completes cleanly and reaches all three
breakpoints (`FUN_00442750` → `FUN_00442bc0`/`getScanline` →
`FUN_00457d88`/pixel-reconstruct) in order, in a single call - no need
for `ScapePicTexture.makeTexture()` after all. See
`docs/cmp-texture-format-reference.md`, "Sesión de desbloqueo
(2026-09-10)", for the resulting single-step trace and the two
previously-open ambiguities (carry arithmetic, double-row write) it
resolved.

`ScapePicTexture.makeTexture()` still fails even under Xvfb, but with an
unrelated, more mundane problem: `Assertion failed: line 98 in file
nScapePicTexture` during `nativeInit()`, most likely because this
harness's minimal `ScapePicTexture` class (it doesn't extend the real
`Texture` superclass) is missing a field or registration step the native
code expects. Not investigated further since `loadImage()` alone already
reaches the pixel decoder - fixing this only matters if a future session
specifically needs `makeTexture()`'s code path (e.g. to see whether it
decodes rows `loadImage()` alone doesn't reach).

### Original blocker writeup (kept for context)

Any code path that got past header parsing into real pixel decode
triggered DirectDraw/OpenGL device and window creation, which hung
indefinitely (`err:clipboard:convert_selection Timed out waiting for
SelectionNotify event`, `libEGL warning: egl: failed to create dri2
screen`, then no further progress even after 150s+) - at the time, tried
killing stale `wineserver`, Wine's own virtual-desktop mode (`wine
explorer /desktop=name,WxH ...`), both software and hardware gdb
breakpoints, and a timed async interrupt to inspect the actual stall
point (which showed a Wine loader-critical-section wait between threads).
None of those fixed it; Xvfb, tried in the next session, did.
