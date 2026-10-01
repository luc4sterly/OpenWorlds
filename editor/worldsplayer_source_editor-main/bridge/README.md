# Portable bridge for gamma.dll / RenderWare 2.1

It lets the decompiled **original** client (`NET.worlds.console.Gamma`,
Java from `lib/gammacls.zip`) start on macOS/Linux without `gamma.dll` or
`RWL21.DLL`. It is not a new engine: each native body is a translation of
what the decompiled C of `gamma.dll`
(`decompiled-native/gamma_dll/`) does and, underneath, of what the
RenderWare 2.1 functions do according to the disassembly of `RWL21.DLL`. The
evidence addresses are in the comments of each method.

## Usage

To play, use the package (`tools/build-dist.sh` or the CI artifacts):
its launcher prepares a copy of the installation in the user's data
folder, starts the local update server and starts `Gamma` with
the package's Java (see `launcher/`). To develop and diagnose:

```bash
editor/worldsplayer_source_editor-main/build_gamma.sh
```

```bash
editor/worldsplayer_source_editor-main/run_gamma.sh home:GroundZero/groundzero.world
```

`build_gamma.sh` copies `source/` (pristine) to `editor/.build-gamma/`
(ignored by git), applies `apply_mock.sh` (stubs + this bridge), the platform
adaptations of `build_gamma.sh` (2004 cache, `Std.initSyncTime`,
`host_paths.py` and `ui_fonts.py`, see below) and compiles
with `javac --release 8` (~900 classes, including the `.cmp`,
`.rwg` and `.bod`/`.seq` decoders from `formats/`). After `natives.patch`, the
`natives-<subsystem>.patch` files are applied in name order (animator, media, system,
text, ui). If `javac` fails, `build_gamma.sh` exits with 1. `run_gamma.sh [URL]` copies `assets/WorldsPlayer` to a
working directory (`$OPENWORLDS_GAMMA_DIR`, by default
`$TMPDIR/openworlds-gamma`) and starts the real `main`; the optional URL is the
world argument of `Gamma.main` itself (without it, it starts at
`home:NewWorld.world`, like the original before the login).

Console: the `[NATIVE-MOCK]` trace is opt-in (`JAVA_OPTS=-Dopenworlds.nativeLog=true`)
and each texture that fails to load is reported only once. The 2004 client sends
its output to `Gamma.Log.open` (`LogFile=` in `worlds.ini`); `run_gamma.sh`
empties that key in the working copy so that the output stays in the
terminal, and `OPENWORLDS_GAMMA_LOG=1` keeps the original log.

Other options: `-Dopenworlds.animLog=1` (DroneAnimator), `-Dopenworlds.mute=1`
(without opening audio; same logic and timing), `-Dopenworlds.openUrls=1` (open in
the system browser the URLs that the user requests with a click; by
default they are only logged), `-Dopenworlds.typeChat=MS:text` /
`-Dopenworlds.typePassword=MS:[x]text` (type like a person),
`-Dopenworlds.registry=FILE` (portable Windows registry, REGEDIT4) and
`-Dopenworlds.volumeSerial=0x…` (volume serial to decrypt a
password saved on another disk). Networked session against J Solar Server
on this machine: `OPENWORLDS_SERVER=127.0.0.1:6650` (+ `OPENWORLDS_USER`,
`OPENWORLDS_LOGIN`, `OPENWORLDS_CHAT`, `OPENWORLDS_NETDEBUG`); see
`docs/net-local-server.md`.

Checks: `bridge/test/*Check.java` (hand-calculated cases, one per
subsystem) are run with `tools/run-checks.sh`, which rebuilds the bridge
if its build is older than the changes.

`-Dopenworlds.dumpWindow=DIR` dumps the AWT component tree of the
whole window (class, text and bounds) at seconds 12/20/30/40, to
review the UI layout without being able to capture the screen. The PNG that
it attempts with `printAll` comes out black on macOS —the UI is made of
heavyweight AWT components painted by the native peer— so it is only written if it
is not black.

Diagnostics (disabled by default): `JAVA_OPTS` with
`-Dopenworlds.dumpFrames=DIR` saves frames 1, 10, 100, 1000… of each
camera as PNG (or, with `-Dopenworlds.dumpSeconds=S1,S2`, the first frame
after each second; or, with `-Dopenworlds.dumpRange=SEC:N`, N
**consecutive** frames from second SEC, which is what is needed to look at
a turn), and `-Dopenworlds.scriptKeys=MS:KEYCODE:HOLD_MS,...`
injects synthetic AWT key presses into the canvas. The macOS screen capture
is not permitted on this machine.

To find out **which object paints what**: `-Dopenworlds.matStats=SEC` lists, once
per second and per room, the visible materials sorted by pixels
drawn, with their 565 color, whether the texture is set and resolved, and the
owning `WObject`; `-Dopenworlds.probePixel=X,Y` tells which object ends up with that
pixel; `-Dopenworlds.traceTextures=1` traces each `RwSetMaterialTexture`; and
`-Dopenworlds.fps=1` prints the frames per second of the main camera,
its position and its direction, plus the coverage (pixels written per frame
versus the raster size: above 100 % there is overdraw).

⚠️ When reading `matStats`: the color shown is the **base color of the material**,
not the pixel's. The world's `Rect`s have their texture set by the
client (`Material.nativeSetTexture`), not by the shape's script, so
their `.rwx` texture name is null even though they are textured —
measured: in GroundZero **all** the visible materials come out as
`WITH texture` (literal `matStats` output).

## Verified status (2026-09-26)

- `home:GroundZero/groundzero.world` enters GroundZero and draws it with
  its geometry and its textures, with the driver's rasterizer (fan
  triangles, reciprocal table, perspective every 16 px) and the cell `Rect`s
  (`2h*2v*`) that previously did not appear.
- The 6 figures in the galleries (`avatar.rwg`, a valid empty clump) create their
  DroneAnimator and receive `prepFigure` and `moveto`/`update`
  (`-Dopenworlds.animLog=1`). They rotate, and the C code leaves them in states 1/2,
  which have no sequence.
- Against J Solar Server on the same machine: two clients sign in, see each
  other walk, chat (typed with Enter), whisper and keep friends lists; also
  encrypted, with the injector's "tls" patch (`docs/net-local-server.md`).
- The client writes its 2004 `Gamma.Log` with `OPENWORLDS_GAMMA_LOG=1`,
  with the `SystemInfo.Record` report.
- `tools/run-checks.sh`: 45/45 (5 from `formats/`, 35 from the bridge, with
  `RasterGoldenCheck`, `MatrixAffineCheck`, `GdkUpCheck` and
  `UiDisposeCheck`, and 1 + 3 + 1 from the injector, the launcher and J Solar
  Server; the 5 of the new engine left with it on 2026-09-26);
  the exceptions
  that appear in GroundZero (`WorldScriptGroundZero` and
  `NoWebControlException` from the signs) are the client's own path. Correction of
  2026-09-26: the `redir.txt` error that appeared
  here was **not** from the original (its `Gamma.Log` does not have it): it was the
  lowercase `u:/...` path, fixed with `HostPath`.

### Added on 2026-09-26 (packaging session)

- **Window menus now visible.** `ImageCanvas.loadLocalImage` used to call
  `Toolkit.getImage("u:/.../rtpanel.gif")`: on Windows that worked, here the
  file does not exist and the `ImageButtons` (Help, Options, WorldsMail,
  Teleport, Actions, VIP, Quit, Universe Map...), the map and the friends list
  came out black. `HostPath.of` (with `host_paths.py`, 151 calls in
  50 classes of the pristine code) strips the synthetic drive and resolves
  case-insensitively in every `new File/FileInputStream/.../ZipFile` and
  `Toolkit.getImage`. On Windows it does nothing.
- **No blocking at startup.** The first `Std.getSynchronizedTime()` (requested
  by `BlackBox.postrender` on every frame) opened a `Socket` with no timeout
  to `time.worlds.net:37` inside the render thread: black window until the
  TCP timeout (75 s on macOS). The base now comes from the system clock
  with the same subtraction as the bytecode (`ldc2_w -1141367296l; lsub`: the
  original's overflowed `100*365*86400`, origin 1999-12-08) and the
  server, if it responded, corrects it from another thread with 2 s timeouts.
- **Fonts with the 2004 metrics** (`NativeUiFonts`, `ui_fonts.py`):
  the `font.properties` of the installation's JRE 1.4 resolved `dialog` and
  `sansserif` to Arial; a modern JDK uses DejaVu/Lucida, which are wider, and the
  status bar said "Jse arrow keys". Arial is used if present (macOS,
  Windows) or one with identical metrics (Liberation/Arimo on Linux).
  `-Dopenworlds.modernFonts=true` goes back to the JDK's own.
- **Striped rasterizer** (`NativeCamera.rasterize`): the clump pass
  records the triangles (in the driver's order) and they are drawn in
  horizontal bands on `-Dopenworlds.rasterThreads` threads (by default
  the number of processors, maximum 8). Each band walks the whole list and a
  triangle only writes its own rows, so every pixel receives the same
  writes in the same order: `RasterGoldenCheck` compares the CRC of 18
  views of a scene of 56 real shapes with the previous engine (identical
  with 1, 2, 4 and 8 threads). Also: clipping without allocations, spans that only
  interpolate what the pixel path uses, and screen blit through a
  565→RGB table (the `drawImage` of the 565 image went through Java2D's
  generic loop). GroundZero at 1172×848: 25 → ~53 fps; at 468×272: 72 → ~90.
- **Affine matrix product** (`NativeRw.mul/mulInto`): RWL21 multiplies
  only the 3×3 plus the translation row (`RwMultiplyMatrix` 0x1001db10 →
  0x1005118c) and does not touch the fourth column; the bridge did a full 4×4.
  The `Transform`s of the `.world` carry RW internal data there (e.g.
  `m[15] = 2e-37`), so a child lost its parent's translation and everything
  hanging from a container `WObject` (30 in GroundZero) was drawn
  at the room's origin: the Auditorium's support with ropes
  and the iris door of IconViewRoom1Enter were missing (visible from AvatarEnter and
  from the "Avatar Gallery" door in Reception). Same order of sums:
  with clean matrices, bit for bit identical (`MatrixAffineCheck`,
  `RasterGoldenCheck`).
- `-Dopenworlds.dumpScene=SEC` (and `dumpSceneMatrices`): dumps the tree of
  clumps of each scene (object, state, polygons, position in the world).
- **Material of the `.bod` parts** (`NativeShapes.buildBod`): gamma.dll
  FUN_0041d950 does `RwPushCurrentMaterial`,
  `RwSetMaterialSurface(0.32, 0.55, 0.0)` (the floats of `DAT_00470ac4`,
  `DAT_00470ac0` and `DAT_00470abc` read from gamma.dll's `.data`: the
  same surface as `PosableShape`), the part's color and
  `FUN_00417a10` (`RwSetMaterialLightSampling(2)` +
  `RwAddTextureModeToMaterial(1)`): smooth, with per-vertex light. Here it
  was (0.75, 0, 0) and faceted, and the statues and drones came out flat, without
  shading.

### Added on 2026-09-26 (travel between worlds and game tests)

Full report in `docs/game-tests.md`.

- **Installing worlds and updates.** The client requests `gdkup.exe
  updates.lst <pid>` (`NetUpdate.runUpdates` → `CreateProcSpecial`,
  0x00404740) and closes. The bridge leaves the request in `gdkup.pending`
  (`NativeSysProcess`). Whoever started the client (the launcher, `Session`,
  or `run_gamma.sh`) runs gdkup in Java (`GdkUp`, translated from
  `decompiled-native/gdkup_exe`), which installs each package like its own
  installer: `WisePackage` (WiseMain + PKZIP, destinations and
  `[InstalledWorlds]` read from the compiled script) and `NsisPackage` (an
  NSIS 3 Unicode machine with the 22 instructions that the packages use).
  On its exit code 10 the client is started again with `world:restart`. Like
  gdkup.exe, it does not read the exit code of each line (0x00401e75): an
  installer that aborts does not prevent the restart. `WinIni` does
  Get/WritePrivateProfileString. What is missing locally is requested from the
  mirror by the launcher's update server (`us1.worlds.net`, now
  LibreWorlds).
- **Clock like `GetTickCount`** (`NativeInput.tick`): gamma.dll's `Std.nativeGetMillis`
  uses `GetTickCount()` (the `timeGetTime` branch depends on
  `DAT_00489054`, which is never written), which on XP advances in jumps of
  15.625 ms. With the bridge's 1 ms clock and 600-800 fps, the thresholds of
  `SmoothDriver` (minFB_vel=4, minLR_vel=3) zeroed the velocity every
  frame and turning was extremely slow. `-Dopenworlds.tickMs=N` changes the step (0 =
  1 ms).
- **Closing dialogs with a text field** (`AwtCompat.closeHoldingLock`):
  `PolledDialog.mainCallback` is `synchronized` and closes with
  `setVisible(false)`, `requestFocus` and `dispose()`. On X11 the input
  method makes the event thread take the window's monitor
  (`InputContext.add/removeClientWindowListeners`), and today's Java does
  `dispose()` waiting for that thread: deadlock, black dialog and frozen
  UI (WorldsMark → Change Location...). The three calls now go
  to the event thread with the monitor released. `UiDisposeCheck` tests it and
  reproduces the deadlock with the original close. ⚠️ There are other places with
  AWT under a dialog's monitor (the first `mainCallback`, the
  `activeCallback` of `LoginWizard`) with no deadlock seen.
- **`Window.usingMicrosoftVMHacks`** returns `DAT_004891cc == 1`
  (0x0040de40), which only `doMicrosoftVMHacks` (0x0040de30) sets, with the
  Microsoft JVM. The mock returned `true` and the universe map closed the game
  (`getLocationOnScreen` of the hidden canvas in `RenderCanvas.handle`).
- **Textures**: several row groups per frame and the single `esi` row
  (`formats/.../CmpFrames`), the skip of header byte 13
  (`CmpStage1`) and the `idx == 0` of the simple copy (`CmpStage2`); see
  `docs/cmp-texture-format-reference.md`. They load the Blair Witch mug
  hologram and the wardrobe's `kcl.mov` kaleidoscope.

Network: `run_gamma.sh` starts `tools/local-upgrade-server.py` and points
the temporary copy's `upgradeServer` to `127.0.0.1`. What is not available locally
it requests from the mirror, the original `upgradeServer` (`OPENWORLDS_MIRROR=0` removes
it), and it answers 404 instantly for what the mirror does not have either. On
exit, the pending update in `gdkup.pending` is applied and the client is started again, like the
launcher. `build_gamma.sh` patches
`Cache`/`CacheEntry` so that the 2004 `cache.index` loads on macOS
(Windows path separator and `localName`) and the already cached entries are not
refreshed against the server. Missing, and not available anywhere, are the
textures `cfemaleb`, `cfemaleba`, `cfemalec`, `cfc`, `fga`, `fja` and `mga` of
Julie, Roxanne and Simon (`docs/worlds-chat-project.md`, 2026-09-18).

## What it contains

| File | Translates |
|---|---|
| `NET/worlds/core/NativeRw.java` | RW 2.1 matrices: multiplication (0x1005118c), modes 1/2/3 (0x1001c500), `RwRotateMatrix` (0x1001de70→0x1001cb20), `RwScaleMatrix`, `RwTranslateMatrix`, affine `RwInvertMatrix` via the adjugate (0x1001dbc0), `RwOrthoNormalizeMatrix` (0x1001c150), `RwQueryRotateMatrix` (0x1001e060), `RwTransformPoint/Vector` |
| `NET/worlds/core/NativeScene.java` | RWL21 clumps, scenes, lights and materials (1-based vertices, polygons, hierarchy, LTM, world/local bbox, tags, state ON=2/OFF=1, default scene) and the gamma.dll wrappers with their own logic (`FUN_00417ac0`, `FUN_00418820/860` and their callbacks, `FUN_00417950/a10`, `FUN_00419000`, `Surface.addSubPolys` 0x004206d0) |
| `NET/worlds/core/NativeCamera.java` | Cameras and software rendering of the 16-bit driver (`RWDL6D21`): per-window cache (0x00415fb0), `RwTransformCamera` with orthonormalization and det>0.9, RWL21 projection and clipping (0x10009dd0), on-screen area culling (0x10051000), ambient/diffuse/specular lighting per facet or vertex and conversion to 5-6-5 (driver 0x1000d230/0x10019920), transparent texel 0, opacity as "screen door", horizon (0x00417dc0), highlight mark (0x00417c40), picking. Driver triangles (vertices snapped to the grid, slopes with the reciprocal table 0x1000a008, step before painting, fan from the last to the first), textured span 0x1002cbb0 with perspective every 16 px and packed u/v, Gouraud in color space with G dithering (0x1006a340), per-clump sorting tree 0x10033750 and hints modes (0x10033600: more than 1000 polygons → editable), UV range 0..256 (0x10017de0), `RwDestroyScene` (0x100306b0), `WObject.nativeInCamSpace` (0x00413910) |
| `NET/worlds/core/NativeTextures.java` | Textures: StretchBlt COLORONCOLOR (mode 3, 0x422682 → `GDI32!SetStretchBltMode` through the IAT 0x487814) to 128×128 5-6-5 (FUN_004222b0) with the palette of FUN_00422b30; RW dictionary (base name 0x10043e80, comparison 0x10043f20, duplicates rejected) with gamma.dll's count (0x004183e0/0x00418370); `RwReadTexture`: BMP/RAS (0x10021620/0x10021da0), area rescaling to 128 or 16 (0x10042f30), driver conversion (0x10007a80, black → 1); `RwGetNamedTexture` with the ".;.." path and .ras/.tex/.env/.bmp/.rle; `StringTexture` (0x00424af0/0x00424870) |
| `NET/worlds/core/ScapePic.java` | ScapePic header (0x00442750) on top of `formats/src/net/openworlds/cmp/CmpFrames` (all the `.mov` frames through the frame table) |
| `NET/worlds/core/NativeWindows.java` | Windows: the render child is the real AWT `RenderCanvas` (0x0040e3f0), window instance with render size (0x0040f250/0x0040d950) |
| `NET/worlds/core/RwxReader.java` | The `.rwx` script interpreter of RWL21 (`RwReadShape` 0x10009bf0, loop 0x100163e0), command by command: CTM, joint and material stacks with a copy on entering a block, `ClumpBegin` freezing the CTM (0x1000f560), `ClumpEnd` merging the geometry and re-attaching the grandchildren (0x1000f980), vertices with the internal CTM applied (0x10010270), 1-based indices per clump, `Tag`/`Hints`/`AxisAlignment`, `Proto`/`Include` and the full material state; `Texture`/`TextureExt` resolves with `RwGetNamedTexture` on reading (0x10014b00) and if there is no texture the whole shape returns 0 |
| `NET/worlds/core/NativeShapes.java` | What `ShapeLoader` receives from RenderWare: the `.rwx` through `RwxReader` + callback 0x004187e0 (tag < 0x4000000 → hints 2, otherwise OFF); preliminary texture sweeps of `loadTextFile` (0x0041cba0) and of the `.rwg` header (FUN_0041c970); `RwReadStreamChunk(CLUM)` (0x10039e40, read in ASM) with TELT (dictionary/shapes path, error 0x5e), MALT materials, PLST with material and tag, ATOM with state/axes/matrices/children (empty ATOM = valid clump); `.bod` bodies (0x0041e440); `Shape.convertSpecial` (0x0041f1b0 → `TwoWayPortal`/`Rect`) |
| `NET/worlds/core/NativeSystem.java` | The `GlobalMemoryStatus` of `StatMemNode.updateMemoryStatus` (0x0040a360) |
| `NET/worlds/core/NativeInput.java` | Input: gamma.dll's WndProc (0x0040c970, keys/buttons 0x0040c440, motion/delta 0x0040c2c0) on top of the canvas's AWT events, native queue with motion merging (0x00416940/0x00416b00), pressed keys released on losing focus or releasing the last button, delta mode and hidden cursor (0x0040c6a0/0x0040c780/0x0040e670); `GetTickCount` clock in jumps of 15.625 ms (0x00402d10) and `Std.getTimeZero` (0x00403e6a) |
| `NET/worlds/core/NativeAnimator.java` + `Anim*.java`, `natives-animator.patch` | gamma.dll's `DroneAnimator` and `PendingCacheDrone`: `avatars.dat` registry (flex FUN_0042a4c0, FUN_0042cb90), `.seq` cache and downloads (FUN_0042ffd0/0042fc90, 0x44bda0), time-based and distance-based drivers (truncated key: RC chop at 0x43b9c0), 250 ms blend of implicit animations ({0, 0xfa} in FUN_00432d10) and of gestures 8x(1−x), walk/wait/endwait state machine (FUN_00434670), `update` (FUN_00435520/00433710), pose application (FUN_00434470) and `prepFigure` (FUN_00434f00). The rule is written down in `docs/seq-animation-reference.md` §7 |
| `NET/worlds/core/NativeUi*.java`, `natives-ui.patch` | Platform adaptation (not from gamma.dll): restores the 1.0 event model to the `TextField`/`TextArea`, whose lightweight peer (JDK ≥ 9, macOS) sets `newEventsOnly`, with the rules of `AWTEvent.convertToOld`: chat works with Enter. `Console.encrypt/decrypt` (0x0040b7f0/0x0040bb00); volume serial and single instance of `Startup` (0x00409e70/80, 0x004098b0 + FUN_00409ce0, hooked into `Window.install`); `Cursor` (IDC table at 0x0046e81c, `.cur`, applied by `Window.setCursor`); `RightMenu`, `FileSysDialog`, `RenderCanvasOverlay`, `ImageConverter`, `ScapePicImage`/`ScapePicCanvas` |
| `NET/worlds/core/NativeSys*.java`, `natives-system.patch` | `RegKey` on top of a portable REGEDIT4 registry (0x00402360-0x00402770); `SystemInfo` with the binary's arithmetic and strings (0x00442020-0x00442470); COM outside Windows: `getPtr`, gamma.dll's own class factory and the ole32 failure branches with their literal messages (0x0040ab80-0x0040b450, 0x00441f30); `VehicleShape` (0x0043f4c0-0x0043f580); `CreateProcSpecial` (0x00404740); `Restorer.makeArray` (0x0041a8d0); `get3DHardware*` = false (0x0043c4f0/510); `Pilot.nativeInit`; `VoiceChat.terminateVC` |
| `NET/worlds/core/NativeMedia*.java`, `ImaAdpcmWav.java`, `natives-media.patch` | Sound: `PlaySound` and `waveOutSetVolume` of `WavSoundPlayer` (0x00420120..0x00420200; 65535.0f at 0x4711f8), MCI waveaudio/sequencer of `MCISoundPlayer` (0x0041f780..0x0041fe40), ASF without `playfile.exe` (0x0041f670), `disableWav/MIDI/ASF` flags (0x00420260/0x00420030); output through javax.sound and IMA ADPCM WAV. DirectShow and CD through their failure path (0x0043f180..0x0043f450, 0x004153e0..0x00415ea0). Embedded IE (`nativeInit` → false), `WebBrowser`/`IWebBrowserApp` (IOException), DDE, `TextureSurface`; `launchViaRegistry`/`sendURL` log the URL |
| `natives-text.patch` | `StringTexture.makeStringTexture` → `NativeTextures.makeStringTexture` |
| `NET/worlds/core/GdkUp.java`, `WisePackage.java`, `NsisPackage.java`, `WinIni.java` | gdkup.exe (`decompiled-native/gdkup_exe`: WinMain 0x004020a9, each line 0x00401d52, process end 0x00401e75) and the installers of the world packages: Wise 2000 (compiled script and PKZIP) and NSIS 3 Unicode (22 instructions of `exec.c`), with kernel32's Get/WritePrivateProfileString |
| `NET/worlds/core/AwtCompat.java` | Platform: closing `PolledDialog` on the event thread with the dialog's monitor released (on X11 the original close deadlocks with today's Java) |
| `NET/worlds/core/NativeAssert.java` | Native assertion `FUN_00402800`: same message and `exit(41)` (without the modal MessageBox) |
| `NET/worlds/core/HostPath.java`, `host_paths.py` | Platform: the client's `u:/...` paths to real files at every file open and `Toolkit.getImage` |
| `NET/worlds/core/NativeUiFonts.java`, `ui_fonts.py` | Platform: `new Font(...)` and `GammaFrame`'s default font with the fonts of the 2004 `font.properties` (or ones with identical metrics) |
| `natives.patch` | Bodies of the stubs of `Transform`, `Point3Temp`, `WObject`, `Surface`, `Room`, `RoomEnvironment`, `Material`, `Camera` (`renderScene` 0x00415190 and the room pass 0x00414aa0), `Texture`, `FileTexture`, `ScapePicTexture`, `ScapePicMovie`, `EventQueue`, `Window`, `ActiveX`, and those of `Std` (clock, `instanceOf`, `byteArraysEqual`, `getenv`, `exit(42)`, version 1900 and gamma.dll's literal build strings); `NativeMock` with a bounded log and `localFile`; `Archive` opens files and `content.zip` through `localFile` (the synthetic `u:` drive of the `URL` patch); `PolledDialog` closes with `AwtCompat.closeHoldingLock` (with `isDisplayable()` instead of `getPeer()`, removed after Java 8; a reflection sweep of the 934 JDK calls finds no further cases); `Window.usingMicrosoftVMHacks` with gamma.dll's value; and the `Room` fix below |

## Decompilation error found

`Room` called `super.add(this.environment)`, which Java resolves as
`WObject.add(WObject)` and puts the environment into the scene twice (assertion
in `RoomEnvironment.addLight`). The original bytecode calls
`WObject.add(SuperRoot)`. To check that there are no more cases like this, the
targets of all the calls of the 736 original classes are compared
with the recompiled ones (`tools/bytecode-call-diff.py`): 55 methods remain with
differences, all harmless (narrower receivers, `close()` of
try-with-resources, the mock layer itself), except this one.

## ⚠️ Pending verification

Render:
- **Scene clump BSP** (RWL21 0x1002d170, traversal 0x1002cae0):
  read in ASM and not translated; it is incremental and its result depends on the
  history of operations. What is known:
  - Each clump is a node (0x1002c120). They are sorted by diagonal² (MSVC
    qsort 0x10045270, comparator 0x1002f0f0) and inserted from largest to smallest.
  - The planes come from 0x1002dde0, with a margin of -0.01f.
  - What is not separated forms type 2 lists and 0x10 conflicts.
  - A clump that moves is removed and reinserted.
  - The traversal forms groups with its own 16-bit z-buffer
    (0x10069650, `RwDeviceControl(7)`).

  The bridge keeps a global 1/Z z-buffer and the per-clump tree; the
  information on "z only in the conflicting spans" is computed but
  unused.
- Untranslated rasterizers: translucent (0x1001a860, 0x10027de0/0x1006a440)
  and textured Gouraud (0x1002ffc0). The effect of the
  "native" texture bit 8 has not been checked either.
- Exact order of the x87 operations at 0x10069650 and FPU precision
  (the bridge assumes 53 bits); interpolation of fixed-point UVs in the clipper.
- `NativeScene` does not store PLST's face normal, the 3 reals of
  flag 4 or the unnormalized vertex normal (a difference of 1e-4 in the
  corpus).

Textures:
- StretchBlt is COLORONCOLOR, not HALFTONE. Which source pixel gdi32 picks
  and how it converts the color to 5-6-5 is not in our binaries. The
  bridge uses `d*s/D` and discards the low bits; only a capture on Windows
  will settle it.
- `StringTexture` glyphs: Java2D without antialiasing, not GDI (MS Gothic is not
  on this Mac).

Shapes:
- `.rwg`: RALT/RAST and ATOM with children are read according to the binary, but there is
  no real sample; RAST is not converted (0 if a TELT uses it).
  `cube.rwg` does not load in RW 2.1 (16-byte TELT); confirming it under Wine is still pending.
- The mask of `Texture … mask` is not translated (it is ignored).
- `RwxReader` accepts unknown commands, where RW fails with error 4, and
  it lacks `block`, `cylinder`, `cone`, `disc`, `sphere`, `hemisphere`,
  `trace` and `texture*state` (table 0x1005a260).

Animation:
- No avatar has been seen walking or in wait inside GroundZero: the
  statues rotate (~70°/s) and stay in states 1/2. J Solar Server now sends
  networked drones (other players): ⚠️ VERIFY their walk/wait cycle frame by
  frame against the translated rule.
- The catch for the syntax errors of `avatars.dat` (a C++ throw) has not
  been located.

UI, system and media:
- The password saved in 2004 can only be decrypted with
  `-Dopenworlds.volumeSerial`: the volume serial here is `unix:dev`.
- `setDIBPixelInts` reproduces a bug of the original: it addresses in bytes,
  so a direct-color JPEG ends up in the first quarter of the texture.
  Whether to fix it remains to be decided.
- Cursors with no AWT equivalent: APPSTARTING, NO and UPARROW; the `.ani` files
  are not decoded.
- `FileSysDialog`: AWT has no filter list or `lpstrDefExt`.
- Behaviors that can only be checked on Windows:
  - `CoRevokeClassObject` with an unknown cookie;
  - `advapi32` with empty components or creating under KEY_READ;
  - the 2 GB limit of `GetDiskFreeSpace` on Win9x;
  - the argument splitting of `CommandLineToArgvW`.
- waveOut volume curve (linear here); `SND_PURGE` with a name; texts
  of `mciGetErrorString`; the IMA ADPCM decoder has not been compared
  sample by sample with `imaadp32.acm`.
- The URL lock (`-Dopenworlds.openUrls` + user origin) is a
  criterion of the bridge, not of the binary.

Network:
- `_connectThread` race of the 2004 client (verified in the bytecode:
  `WSConnecting` starts its threads before `state_Initializing` assigns
  the field). Against a local server about 4 out of every 27 connections
  hung. Patched (`natives-java.patch`): `WorldServer.setSocket` first takes
  the lock of `_state`, which `state_Initializing` holds until it has stored
  the thread.

Input:
- AWT→Win32 VK table for the keys whose code differs; auto-repeat is
  detected by "already pressed" (AWT does not give bit 30 of
  lParam); `QueryPerformanceCounter` is `System.nanoTime` with frequency 1e9.
- `Window.install` returns 0 as hInstance.
