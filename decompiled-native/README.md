# Decompiled native code: all of the game's own binaries

C decompiled with Ghidra 12.1.3 (headless), 0 failures in all of them:

| Folder | Binary | Functions | Via vtable | What it is |
|---|---|---|---|---|
| `gamma_dll/` | `bin/gamma.dll` (613 KB) | 2537 | 881 | the client's JNI bridge and its codecs (`.seq`, `.cmp`/`.mov`) |
| `rwl21_dll/` | `bin/RWL21.DLL` (389 KB) | 1152 | 21 | RenderWare 2.1, the engine (795 with their real API name) |
| `rwdl6d21_dll/` | `bin/RWDL6D21.DLL` (578 KB) | 411 | 26 | 16-bit RenderWare driver: the rasterizer that the bridge translates |
| `rwdl8d21_dll/` | `bin/RWDL8D21.DLL` (560 KB) | 427 | 33 | 8-bit (palette) RenderWare driver, DirectDraw |
| `rwdlmd21_dll/` | `bin/rwdlmd21.dll` (653 KB) | 435 | 28 | RenderWare driver with MMX (120 `emms`, `cpuid`), DirectDraw |
| `rwdldd21_dll/` | `bin/RWDLDD21.DLL` (252 KB) | 305 | 2 | DirectDraw RenderWare driver (`DirectDrawEnumerateA`) |
| `run_exe/` | `run.exe` (49 KB) | 139 | 0 | the 2004 launcher: finds Java and starts `NET.worlds.console.Gamma -home . -dllpath bin` (what gdkup restarts with `run.exe world:restart`) |
| `gdkup_exe/` | `bin/gdkup.exe` (42 KB) | 256 | 9 | the updater (`\GAMMA\network\gdkup`): runs `updates.lst` line by line and restarts the client; translated in `bridge/.../GdkUp.java` |
| `sfmain_exe/` | `sfmain.exe` (315 KB) | 619 | 51 | the voice chat (SpeakFreely with GSM, `\GAMMA\speakfre`), compiled with Watcom |

"Via vtable" counts the functions that are only reached through pointer
tables, which Ghidra does not see as functions (see below). `tools/ghidra-scripts/decompile-all.sh`
regenerates everything except `gamma_dll/`, which was done earlier with the same two
scripts.

What is left undecompiled in `assets/WorldsPlayer` is third-party, not part of the
game:

- **Sun Java 1.4.2_05**, which the installer shipped: `java.exe`,
  `javaw.exe`, `awt.dll`, `java.dll`, `net.dll`, `nio.dll`, `zip.dll`,
  `jpeg.dll`, `fontmanager.dll`, `jsound.dll`, `jawt.dll`, `verify.dll`,
  `hpi.dll`, `hprof.dll`, `jdwp.dll`, `jcov.dll`, `rmi.dll`, `ioser12.dll`,
  `jaas_nt.dll`, `w2k_lsa_auth.dll`, `dt_shmem.dll`, `dt_socket.dll`,
  `cmm.dll`, `dcpr.dll`, `JdbcOdbc.dll`, and the Java plug-in
  (`jpi*.dll`, `jpins*.dll`, `NPJava*.dll`, `NPJPI142_05.dll`,
  `NPOJI610.dll`, `axbridge.dll`, `eula.dll`, `RegUtils.dll`). The bridge
  replaces all of this with a modern Java.
- `msvcrt.dll` (Microsoft's C runtime).
- `xdelta.exe` and `glib-1.2.dll`: xdelta 1.x (GPL, with published source
  code), for the incremental `%XDZ` patches of the old worlds.
  It is not translated: `GdkUp` treats those patches as not applicable.
- `UNWISE32.EXE`: the Wise uninstaller.

## This session (2026-09-26)

- **Ghidra 12.1.3** from the SourceForge mirror
  (`https://sourceforge.net/projects/ghidra.mirror/files/Ghidra_12.1.3_build/ghidra_12.1.3_PUBLIC_20260817.zip/download`),
  because the cloud proxy cuts off the download from GitHub. SHA-256
  checked against the one in the release's README:
  `93a5d11a9ad510622acaaf908c556a7b9b764d338e78a7567f3689bf5081fd54`. On
  Linux it ships the native decompiler, so there is no need to build it as on
  macOS Intel.
- `ScanVtablesAndExport.java` also accepts Watcom's `DGROUP` block
  (`sfmain.exe` has no `.data`/`.rdata`). The check of the 13
  entries of the animation player's vtable is only done on
  `gamma.dll`.

## `gamma.dll`

C decompiled with Ghidra 12.1.3 (headless) from the ORIGINAL 2004 `gamma.dll`
(`assets/WorldsPlayer/bin/gamma.dll`, 613 KB) — the client's JNI
bridge and all of its native code: `DroneAnimator` (animation of
`.seq` avatars), `huffdcod`/ScapePic (`.cmp`/`.mov` textures),
`Transform`, `PendingCacheDrone`, etc.

- `gamma_dll/`: 1656 functions (`<addr>_<name>.c`, 0 failures) +
  `INDEX.txt` (addr, file, name). The JNI exports keep their
  real name (`_Java_NET_worlds_...`).
- **Functions reachable only through a vtable** (added 2026-09-16): the
  first dump (1656) did not include them because Ghidra does not detect a
  target that is only jumped to through virtual dispatch as a function — among
  them the 13 in the animation player's vtable (`0x00475200`),
  which turned out to be the time advance and the loop. The script
  `tools/ghidra-scripts/ScanVtablesAndExport.java` walks the tables of
  pointers into `.text` found in `.data` (1216 candidates), forces a function where there
  is none and exports only the new ones: **881 more functions**, `INDEX.txt`
  grows to 2537 entries, without touching any earlier file. 268 candidates
  fell inside another function and were skipped; it has not been thoroughly audited
  whether any of the 881 is a jump table rather than a function.
- **Ghidra on macOS Intel**: this distribution (12.1.3) does not ship the native
  decompiler binary for `mac_x86_64`; it is built from the included source
  (`Ghidra/Features/Decompiler/src/decompile/cpp`, target
  `ghidra_opt`) with the `g++`/`bison`/`flex` from the Command Line Tools and
  copied to `os/mac_x86_64/decompile`. It starts with the JDK in `tools/jdk`.
- Regenerable: `tools/ghidra-scripts/ExportAllDecompiled.java` +
  `analyzeHeadless` (the Ghidra project lives outside the repo,
  `~/ghidra-fw`, see the `.gitignore` of `analysis/`).
- This C is decompiler output (it does not compile as is): versionable
  reverse-engineering source, not a build. Each file cites its
  address for cross-checking with Ghidra.

Decompiled Java (pristine, Vineflower 1.12 + compilation patch):
`editor/worldsplayer_source_editor-main/source/` (723 `.java`, 0
`NativeMock`; it declares the `native` methods that this C implements).

## `RWL21.DLL` (RenderWare 2.1, 389 KB) — added 2026-09-19

`rwl21_dll/`: **1131 functions, 0 failures**, same headless script
(`tools/ghidra-scripts/ExportAllDecompiled.java`). It is the RenderWare engine
itself (the 16-bit driver is `RWDL6D21.DLL`, not dumped yet).

Unlike `gamma.dll`, the DLL **exports its symbols**, so
**795 of the 1131 come out with their real API name** (`RwGetPolygonMaterial`,
`RwSetPolygonMaterial`, `RwDestroyPolygon`...) and only 336 remain as
`FUN_<addr>`. That makes cross-checking against the bridge much more direct than with
`gamma.dll`.

It unblocks what `editor/.../bridge/README.md` marked as pending for
lack of the binary: the clump BSP traversal (`FUN_1002cae0`), the per-clump
polygon sorting tree (`FUN_10033750`), the Gouraud
rasterizer (`FUN_100259e0`) and the driver's lighting (`FUN_1000d230`).

To reproduce (the repo's portable JDK; without `JAVA_HOME` Ghidra's launcher
aborts with "Unable to prompt user for JDK path"):

```
JAVA_HOME=tools/jdk/Contents/Home \
ghidra_*/ghidra_*/support/analyzeHeadless <projdir> RWL21 \
  -import assets/WorldsPlayer/bin/RWL21.DLL \
  -scriptPath tools/ghidra-scripts \
  -postScript ExportAllDecompiled.java decompiled-native/rwl21_dll
```

`ScanVtablesAndExport.java` (2026-09-26): 28 candidates, 21 new
functions, `INDEX.txt` grows to 1152.

## `RWDL6D21.DLL` (16-bit RenderWare driver, 578 KB) — added 2026-09-19

`rwdl6d21_dll/`: **385 functions, 0 failures**. It is the real software
rasterizer (the one the bridge translates in `NativeCamera.raster`), with
148 real names, although many are from the C runtime (`__ftol`,
`__CRT_INIT`). This is where what is still pending in the bridge lives: the perspective
division in 16-pixel spans and the driver's color tables.
`ScanVtablesAndExport.java` (2026-09-26): 26 more functions, 411 in total.
