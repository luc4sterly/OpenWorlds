# Roadmap — OpenWorlds

Prepared on 2026-09-22 from the real tree at `89d4548`, plus the uncommitted
diff of `NativeCamera`/`NativeTextures`. Whatever could not be
checked in this review is marked ⚠️ VERIFY.

## 0. What changes with respect to CLAUDE.md

1. **Frames > 0 of `.mov` are already decoded, but only in the bridge.**
   `CmpFrames` (commit `496f102`) decodes all the frames and
   `bridge/NET/worlds/core/ScapePic.java:27` uses it. Our own client is still
   on `CmpStage1.decodeMovFrame0` (`client/.../cmp/CmpTexture.java:144`),
   with the two errors that commit documents: in `cave`/`cbirda4`/`club…`
   it takes the **last** frame, and in `windr3` it swaps width and height.
2. **The original's avatar animation goes through `DroneAnimator`, and it is
   not in the bridge.** Its 16 natives are all exported by gamma.dll
   (`docs/gamma-dll-exports.txt`) and decompiled
   (`decompiled-native/gamma_dll/004165c0_…animate…`, `00416530_…moveto…`,
   …). The Java part that calls them already runs: `PosableShape.java:1180`
   (`animate`), `:1237` (`moveto`), `PendingDrone.java:192` (`loadconfig`
   of `avatars.dat`). In other words, open item #1 ("which sequence does the
   client choose") is solved **by translating those natives**, not by deducing it.
3. **"UI 0 %" only applies to our own client.** Under the bridge, the original's
   AWT UI already gets built: `-Dopenworlds.dumpWindow` shows
   `FriendsListPart`, `MapPart`, a 280×100 chat and an input field. What
   is missing there are specific natives (the H5 table) and a server to
   talk to.
4. **`server/whirl` does not check the password.** `distributor.rs:78-83`
   only reads `VAR_USERNAME` from the `SessInit`. If we build it locally (Rust
   pinned to `nightly-2024-06-03`, SQLite included in the build, installable
   with rustup without Homebrew), we can test the session flow (chat,
   friends, rooms, several clients) without the real account. ⚠️ VERIFY that the
   client accepts the server type that whirl announces: the primary
   answers `#15=1`, which leads to `UserServer`.
5. **The `Light.setLightTransform` missing from the bridge affects nothing:**
   `lightID` is never assigned in the decompiled Java. The room light goes through
   `Room.addLight`/`setLightPosition`, which are translated.
6. **There is uncommitted work:** the texture audit
   (`-Dopenworlds.matStats` now dumps the dictionary inventory and
   the textures that are not 128×128; `-Dopenworlds.fps` gives the % of pixels
   with a texture). It is tied to the bridge's ⚠️ `StretchBlt(HALFTONE)`.
7. **There is no regression runner.** The ✅ figures (118 / 25-578-103 / 231 /
   51 / 159 / 52) were re-run by hand in the audit of
   2026-09-15. There are no automatic tests; the only thing close to it are the
   `RunTest4b*.java` of the `.cmp` decoder.
8. **`.git` now takes up 82 MB.** The history purge that was still pending
   is no longer needed.

## 1. The strategic decision: a single engine (2026-09-26)

Until 2026-09-26 two clients coexisted: **A**, the 2004 original with
the bridge (`editor/worldsplayer_source_editor-main/bridge/`: the natives
translated from the decompiled C, a software rasterizer in pure Java), and
**B**, a separate reimplementation (`client/src/net/openworlds/`: our own
parsers plus LWJGL with fixed-function OpenGL). This roadmap
recommended A as the main line and B as the target of the port.

**Decided by the user: only A.** B was removed entirely from the repo (code,
viewers, its part of the launcher, scripts, LWJGL and captures); it is in the
git history up to commit `8cd795d`. The `.bod`/`.seq`,
`.rwg` and `.cmp`/`.mov` readers that A imports remain in `formats/`.

- A already has the original's game logic, UI and networking. Each
  translated native closes a gap and can be verified against the C.
- A is pure Java + AWT, so in principle it runs on Linux and OpenBSD without
  Wine (⚠️ VERIFY OpenBSD).

**The first milestone that makes sense for preservation** is this: the 2004 client,
without Windows or Wine, drawing, with animated avatars and chat against a
local server. That is H1 + H2 + H3.

A second question remains open for phase 5: how to get to the PSVita,
where there is no practical JVM (⚠️ VERIFY) nor A's AWT UI. It blocks nothing
until H6.

## 1b. Status as of 2026-09-26

Everything marked [x] is merged into `main` and verified:
`tools/verify-corpus.sh` with no failures and `tools/run-checks.sh` 37/37. The
coordinator checked the key claim of each branch in the assembly
before merging it (constants and addresses cited in each merge).
[~] = partly done, with the cause noted.

| Milestone | Status | What remains |
|---|---|---|
| H0 | ✅ | — |
| H1 | 🟢 almost | scene clump BSP and 16-bit z-buffer per group (documented in ASM, untranslated); translucent and textured Gouraud rasterizers; pixel reference under Wine and the capture of the visual glitch (they depend on you) |
| H2 | ✅ rule / 🟡 in game | the animator receives `moveto`/`update` in GroundZero, but there are only statues that spin there (states 1/2, no sequence): seeing a drone walk is still missing |
| H3 | 🟡 | login + same room + chat between two clients against whirl ✅; **they cannot see each other** because whirl does not send APPRACTR (`hub.rs:246` commented out, whirl is not touched); real account pending |
| H4 | retired | it was "our own client catches up with the original": the new engine was removed on 2026-09-26 (section 1) |
| H5 | ✅ in the original | UI, system/COM and sound/web translated; chat with Enter |
| H6 | ⬜ | cannot be done on this machine (no Linux, OpenBSD or Vita) |

Findings that correct what was believed:
- A `.mov` is not a movie: its frames are cells of a Material.
- Texture scaling is COLORONCOLOR, not HALFTONE (0x422682).
- Ghidra's C for `Surface.addSubPolys` is wrong (x/u of vertices 1-2).
- The animation key is truncated, not rounded.
- The `.rwg` header is the list of textures, and PLST's "id/flag" is the
  material index.
- `cube.rwg` is not loaded by RW 2.1.
- The bridge build had been broken since merge `71648da`.

Decisions that are up to you:
- Whether or not to patch the `_connectThread` race of the 2004 client (it hangs
  about 4 out of 27 connections against a local server).
- Whether or not to fix the original's bug in `setDIBPixelInts`.
- How to get to the PSVita in phase 5 (section 1).

## 1c. Packaging session (2026-09-26)

Task: menus that did not show up, lag, visual glitches, review the engine,
packaged builds on GitHub (not depending on the startup scripts) and
provision the machine. Done in a Linux x64 container of Claude Code
on the web, without Wine: the original client under the bridge runs the same as on
the Mac (xvfb for the window). Verified at the end: `verify-corpus.sh` with no
failures and `run-checks.sh` 38/38.

| Area | Status | Evidence / what remains |
|---|---|---|
| The original's menus outside Windows | ✅ | the button panel (Help, Options, Teleport, Quit, map…) came out black on macOS and Linux: the client opens `u:/…` paths in lowercase (`URL` patch) with `Toolkit.getImage`/`java.io.File`, which only exist on Windows. `HostPath` + `bridge/host_paths.py` resolve them in the build copy (151 file opens in 50 classes; `source/` untouched). It also fixes the reading of `redir.txt` |
| Black window on startup | ✅ | `Std.initSyncTime` opened a `Socket` with no timeout to time.worlds.net:37 inside the render thread (black until the TCP timeout). Now the base comes from the local clock with the same subtraction as the bytecode (`ldc2_w -1141367296l; lsub`) and the server is queried on another thread with a 2 s timeout |
| Fonts | ✅ | those of JRE 1.4 (`font.properties`: Arial, Times New Roman, Courier New) or their metric-compatible substitutes (Liberation); fixes cut-off text ("Jse arrow keys") |
| Lag of the bridge's rasterizer | ✅ | deferred triangle list + bands on several threads with the same per-pixel write order. 1172×848: 13.5 → 4.7 ms (4 threads); the client goes from ~25 to ~53 fps. `RasterGoldenCheck`: 18 views with a CRC identical to the previous engine |
| Bridge: matrices | ✅ | affine product like RWL21 (0x1005118c): whatever hangs from a container `WObject` ended up at the origin (the Auditorium stand, the iris door) |
| Bridge: `.bod` material | ✅ | gamma.dll FUN_0041d950: `RwSetMaterialSurface(0.32, 0.55, 0)` + smooth; it was (0.75, 0, 0) faceted and the statues came out flat |
| Package | ✅ | `launcher/` (window, `--tui` terminal menu, CLI) + `tools/build-dist.sh`: portable (.zip, Java 17+) and an app with Java included (jlink + jpackage). Copy of the installation in the user's data folder; local update server in Java |
| CI | ✅ | on every push: checks, corpus, apps for Linux, macOS Intel, macOS Apple Silicon and Windows, and on each one the smoke test of the packaged original (it has to draw; mandatory). Run #5: GroundZero on all four with the camera at (230,180,170), 62 fps on ARM and 102 on Windows; with a `v*` tag, a release |
| Provisioning | ✅ | `tools/setup-linux.sh` (idempotent) and the web `SessionStart` hook |
| A single engine | ✅ | the new engine (`client/`, its part of the launcher, LWJGL, scripts and captures) was removed entirely by your decision (section 1); the readers the bridge uses moved to `formats/` |

New items that remain:
- **`cache.index`** was not versioned (`.gitignore`): without it, a clean
  clone, the CI and the packages cannot find the cached avatars from
  2004. It is only on your Mac: `git add -f assets/WorldsPlayer/cachedir/cache.index`.
- Test the apps by hand on real machines (Gatekeeper with ad hoc signing,
  SmartScreen on Windows): the CI only tests that they start and draw.


## 1d. Fully decompiled, travel between worlds and the whole game tested (2026-09-26)

Request: finish decompiling the game with Ghidra, test travelling to other
worlds and test everything that can be done in the game.

| Area | Status | Evidence / what remains |
|---|---|---|
| Ghidra | ✅ | all 9 of the game's own binaries, 0 failures: besides gamma.dll, RWL21 and RWDL6D21 (with their vtable sweep, +21 and +26), `run.exe`, `gdkup.exe`, `sfmain.exe` (voice chat) and the 8-bit, MMX and DirectDraw drivers. `tools/ghidra-scripts/decompile-all.sh`. What is not decompiled is third-party (Sun Java 1.4.2, msvcrt, xdelta/glib, Wise): `decompiled-native/README.md` |
| Travel between worlds | ✅ | `us1.worlds.net` responds again (the LibreWorlds mirror). The 11 worlds that the 2004 installation does not include are downloaded and installed as on Windows: `gdkup.pending` → `GdkUp` (Wise and NSIS) → restart with `world:restart`. Tested: AvatarGallery, WorldsChat, AnimalHouse, lets, Meteor, Dcn, PolyGram, DressingRoom, Chaos (Bowie), BWStreet and The Blair Witch World; GroundZero 37 → 40 with Upgrade Now |
| The whole game | ✅ | `docs/game-tests.md`: Help/Options/WorldsMail/WorldsMark/Teleport/Actions/VIP menus, friends, mail, universe map, cameras, chat. Fixed: closing dialogs (deadlock on X11), universe map (it closed the game), clock (slow turning), `.cmp` with several groups and byte 13, 5 NSIS instructions, gdkup that did not restart after an abort |
| Tests | ✅ | `run-checks.sh` 38/38: `CmpGroupsCheck`, `GdkUpCheck` (real packages in `assets/packages/`), `UiDisposeCheck` |

What remains from this: the xdelta patches of the old worlds, the voice
chat (untranslated), the "Sleep" gesture that is invisible on the penguin, and ⚠️ other
places in the 2004 code that touch AWT while holding a dialog's
monitor. **Your decision:** whether or not to keep the mirror's world packages
in the repo (Bowie is 13 MB; PolyGram, 12.6 MB).

## 1e. Launcher with the logo's look, updater, releases and local whirl (2026-09-29)

Request: the launcher with the logo's look, without the logs part, with
automatic updates; the CI releases published on GitHub; and
fix bugs (worlds that do not start after the restart, clicking on a user
does nothing, local whirl that does not work) and polish.

| Area | Status | Evidence / what remains |
|---|---|---|
| Launcher | ✅ | the palette of `tools/icons/make_icons.py`: indigo sky with stars, the low-poly planet drawn live (`PlanetView`, the same icosphere; at rest it is the icon) spinning, and still while the game is being played, "Worlds" with the ring's gradient, Play button with that gradient, Poppins (OFL) bundled. No log panel, Logs button or "FPS in the log" (the files are still in `logs/`, the last 20). List of worlds with their status, re-read at the end of each game session, plus those installed from the universe map; server with three options; Settings kept separate |
| Updater | ✅ | `Updater` + `Bootstrap`: the newest release with a portable package, SHA-256 checked, installed in `<data>/app/<version>`; on startup the app hands over to that version in the same JVM, without rewriting itself. Broken version → `app/bad` and back to the bundled one. `UpdaterCheck` (34 checks against a fake GitHub). (Then the repository was private and needed a read-only token; public since 2026-09-30, no token) |
| Releases | ✅ in CI | every push to `main` publishes `v1.0.<commits>` with the five packages and `SHA256SUMS.txt`; `v*` tags likewise; a prerelease by hand from another branch (Run workflow). The version (`launcher/VERSION` + number of commits) is the same in the tag and in the jar |
| Local whirl | ✅ | `LocalWhirl` starts the app's whirl if nothing is listening on the port, fills in User0 and Password0 (encrypted with the bridge's `Console.encode`; whirl does not check it: just "Sign In") and stops it when done. The CI builds it on the four runners and puts it in the apps (Windows: a 2023 nightly, see `build.yml`); smoke test with whirl on Linux |
| Game copy | ✅ | `Install.prepare` with a manifest: a new version (or the template at another path, macOS App Translocation) no longer overwrites what the client or gdkup changed (it undid GroundZero 37 → 40). `InstallCheck` |
| Polish | ✅ partial | "Single player" without the "cannot connect" dialog (`bridge/natives-launcher.patch`, only with `-Dopenworlds.singleUser`); the game window at two thirds of the screen the first time (before, 568×424) |

## 1f. OpenWorlds in English, J Solar Server and J Worlds Injector (2026-09-30)

Request: everything named OpenWorlds and in English, clean-up of what is no
longer useful, the repository public; whirl replaced by a server of our own
called J Solar Server (whirl's dependencies had many security advisories)
with an admin app anyone can use, in violet, with its own planet; an
encrypted mode (HTTPS-like) and its client patch; and **J Worlds Injector**,
patches the player picks before playing that are compiled when the game
starts. Also "the worlds work in a strange way".

| Area | Status | Evidence / what remains |
|---|---|---|
| J Solar Server | ✅ | `server/`: one port for distributor, user and room server, written from the client's protocol code; accounts (PBKDF2), guests, VIP/admin, bans, chat commands, friends, whispers. **Two original clients see each other** for the first time in the project (`docs/renders/solar-two-clients.png`). `SolarProtocolCheck` (29 checks), `SolarBot` (scripted walker). `docs/net-local-server.md` |
| Admin app | ✅ | the launcher's look in violet with its own planet (`tools/icons/make_icons.py`, variant "solar"); players, accounts, chat & log, settings; `--headless` console; shared `ui/` module |
| Encrypted mode | ✅ | TLS on port 6651 with a self-signed EC certificate; the launcher checks its SHA-256 fingerprint with the player the first time and remembers it (like SSH, `Trust`); the client's "tls" patch trusts only that certificate. Tested: `[tls] encrypted connection to 127.0.0.1:6651 (TLSv1.3, TLS_AES_256_GCM_SHA384)`, sign-in, account made, Upgrade Now and the restart, all encrypted |
| J Worlds Injector | ✅ | `injector/`: unified diffs over the client's source as the bridge builds it, compiled with `javax.tools` against `worldsplayer.jar` into classes that go first on the class path, cached by content. Built in: VIP, Walk faster, Time in the chat, No word filter, Encrypted connection. Players' own in `<data>/patches/`. `InjectorCheck` |
| Launcher | ✅ | "Single player" / "Online" (address, name, password, "Encrypted connection"), the patches row, the game's sign-in filled in (`Login`), Stop also ends the preparation; whirl and `LocalWhirl` gone |
| Worlds | ✅ | a world picked in the list that is not installed is installed from the mirror **before** the game starts (`WorldInstall`, from the world's `upgrades.lst`): no detour through GroundZero and no restart. The client's own prompts (portals, universe map, Upgrade Now) still work as in 2004 |
| English | ✅ | code comments, runtime messages, docs and the history (`docs/worlds-chat-project.md`) |
| Clean-up | ✅ | removed: `server/whirl`, `tools/run-whirl.sh`, `tools/net-probe/run-whirl-duo.sh`, `legacy/installer-reversing/` (the installer itself stays in `assets/`) |
| CI | ✅ | no Rust; both apps on the four systems; on Linux a second smoke test: the packaged client connects over TLS to the packaged J Solar Server with patches built in; releases carry both apps |

## 2. Milestones

Sizes: **S** ≈ 1 session · **M** ≈ 2–4 sessions · **L** = more.

Recommended order: **H0 → H2 → H1 (H3 in parallel, it is independent) → H5 → H6.**
H2 goes before H1 because it closes open item #1 with evidence from the
binary, while H1 is partly blocked by captures (section 3).

### H0 — Solid ground (S)

- [x] Commit or discard the diff of the texture audit.
- [x] `tools/verify-corpus.sh` (compatible with bash 3.2): a single command
      that re-runs the ✅ counts and fails if any of them changes.
      It covers `.seq` 231, `.bod` 51, `.cmp` 159 and `.mov` 52 (until
      2026-09-26 also RWX 118, `.world` 25/578/103 and the avatars
      146/148, with readers from the new engine, removed along with it).
- [x] Progress panel (tool #2 of
      `worlds-chat-project.md`, which was never built): count
      ⚠️/VERIFY/TODO per file and generate `docs/progress.md`. Today there are 33
      markers between `client/` and the bridge.
- [x] Node for macOS x64 in `tools/node-macos/` for the RWX harness against
      `three-rwx-loader` (harness and node were removed with the new engine on
      2026-09-26).
- [x] Update CLAUDE.md with points 1–3 and 8 of section 0.

**Done when** `verify-corpus.sh` passes cleanly on this Mac.

### H2 — Living avatars: `DroneAnimator` (M) ← open item #1

- [x] Translate the 16 natives of `DroneAnimator` from
      `decompiled-native/gamma_dll/`: `init`, `loadconfig`, `getnameindex`,
      `getindexgeom`, `prepFigure`, `addtype`/`deltype`,
      `CreateRep`/`DestroyRep`, `moveto`/`moveby`, `update`, `animate`,
      `getAnimationTime`, `getActionList` and `endanimations`. Also
      `PendingCacheDrone.notifySeqLoaded`/`nativeInit`/`nativeDestroy`.
- [x] Reuse the `.seq` decoder (231/231, now in `formats/`), just
      as the bridge already reuses `CmpFrames`.
- [x] Write down in `docs/seq-animation-reference.md`, with addresses, the
      real walk/wait rule, the synchronization with speed and the 250
      blend.
- [x] Hand-computed test cases: given a series of `moveto` calls with their
      times, which action and which frame come out.

**Done when**, in GroundZero and under the bridge, a drone and the pilot
walk and stop with the sequence that the C dictates, and the rule is written down.

### H1 — Make the original draw faithfully (M)

The pending items come from `bridge/README.md`, section "⚠️ Pending
verification":

- [ ] Reproduce the visual glitch you reported. A **capture** is needed,
      or granting Screen Recording permission to the terminal/java, or catching the
      moment with `-Dopenworlds.dumpRange`.
- [ ] **Pixel reference.** Capture Reception and GroundZero with the
      original under Wine on the Linux/WSL2 machine (`tools/run-original.sh`),
      from the same camera position (`-Dopenworlds.fps` already prints
      position and direction), and compare them with the bridge. Without this, "faithful"
      is an opinion.
- [x] Draw order: replace the global z-buffer with the BSP traversal
      `0x1002cae0` plus the per-clump tree `0x10033750` of RWL21.
- [x] Perspective in 16 px spans and slopes with the reciprocal table
      `DAT_10079214` (RWDL6D21). Today it is done per pixel and in floating
      point.
- [x] Extract the Gouraud interpolation space and the texture
      dithering.
- [x] Textures that are not 128×128: `StretchBlt(HALFTONE)` and
      `RwReadTexture`, which are resolved today with a box average. This continues
      the uncommitted audit.
- [x] `.rwg`: decode the MALT/TELT tables. Today those shapes come out with
      the default material.
- [x] `StringTexture` (2 natives): signs and nametags (`NametagDrone`).
- [x] Minor items from the README: UVs outside the driver's range, `RwDestroyScene`,
      `Shape.convertSpecial` and highlighting.

**Done when** there is a pixel diff against the Wine reference in at
least 3 rooms, with each difference explained.

### H3 — Networking with a session, locally (M)

- [x] Install Rust with rustup in the home directory (`x86_64-apple-darwin`, the
      toolchain of `server/whirl/rust-toolchain.toml`) and build whirl.
      **Without touching its code.** If any adjustment were needed, it goes in a
      separate, documented patch. (Superseded: whirl was replaced by J Solar
      Server on 2026-09-30, section 1f.)
- [x] Point the original under the bridge at whirl, in the temporary copy of
      `worlds.ini`, just as is already done with `upgradeServer`.
- [x] Test with two instances: login, entering a room, seeing each other, chatting
      and the friends list — with J Solar Server (`docs/net-local-server.md`).
- [ ] Real login against `worlds.worlio.com`: **you need to register an
      account** (see `docs/net-real-account-login.md`). It remains
      as a final verification and no longer blocks anything.

**Done when** two original clients on this Mac see each other move (with
H2) and chat through whirl. Met with J Solar Server instead of whirl,
except the walk animation of the other player, which is H2's ⚠️ VERIFY.

### H4 — Our own client catches up with the original (retired)

Retired on 2026-09-26: the new engine was removed from the repo (section 1). What
it got to do is in the git history up to commit `8cd795d`.
⚠️ The `.rwg` with several joints still has no corpus to confirm it: do not
make it up.

### H5 — UI and peripherals, phase 4 (L)

There are 41 files with natives outside the bridge. `FastDataInput`, `IniFile` and
`DNSLookup` already have a mock with real I/O, `DroneAnimator` goes in H2,
`StringTexture` in H1 and `Light` is harmless. What remains:

| Group | Classes (no. of natives) | Proposal |
|---|---|---|
| Cursor, overlay and menus | `Cursor` 6, `RenderCanvasOverlay` 3, `RightMenu` 6, `Console` 3, `FileSysDialog` 1, `Startup` 3 | translate |
| Sound | `WavSoundPlayer` 4, `MCISoundPlayer` 6, `ASFSoundPlayer` 1, `DirectShow` 9, `CDPlayerAction` 14 | `javax.sound` for WAV/MIDI; the rest, a documented stub |
| Embedded web | `IEWebControlImp` 12, `IWebBrowserApp` 5, `WebBrowser` 3, `TextureSurface` 6, `DDEMLClass` 5, `sendURL` 3, `SendURLAction` 1, `NSProtocolHandler` 1 | open in the system browser; web surfaces ⚠️ to be decided |
| System and COM | `RegKey` 9, `SystemInfo` 10, `IUnknown` 4, `IDispatch` 1, `IClassFactory` 2, `INetscapeRegistry` 2 | mock with documented fixed values |
| Others | `VehicleShape` 10, `ImageConverter` 6, `ScapePicImage` 3, `ScapePicCanvas` 1, `Restorer` 1, `Pilot` 1, `RenderWare` 2, `NetUpdate` 1, `VoiceChat` 1 | as they show up in use |

### H6 — Portability, phase 5 (L)

- [x] Linux: A runs on Linux x64 without Wine (the web container and CI,
      with Xvfb; §1c). What was macOS-specific was about paths (`HostPath`) and
      fonts (`NativeUiFonts`), not `build_gamma.sh`.
- [ ] OpenBSD: A with the OpenJDK from ports (⚠️ VERIFY the version and AWT).
- [~] macOS Apple Silicon: the CI generates the arm64 app (arm64 Java from the
      `macos-15` runner); ⚠️ VERIFY on a
      real machine.
- [~] Windows: the CI generates the x64 app (a folder with `OpenWorlds.exe`); the
      bridge does nothing with paths on Windows (`HostPath`). ⚠️
      VERIFY on a real machine.
- [ ] PSVita: requires a native engine (C + SDL2/vitaGL, ⚠️ VERIFY). It has to be
      decided before starting (section 1).

## 3. What depends on you

1. A capture of the visual glitch, or Screen Recording permission (H1).
2. Reference captures on the Linux machine with Wine (H1).
3. An account registered at `worlds.worlio.com/register`, when we get
   to H3.
4. How to get to the PSVita in phase 5 (section 1); the A/B decision has already
   been made: only A.
5. Search elsewhere (Wayback, archives) for the 7 `.mov` of Julie, Roxanne and Simon:
   `cfemaleb`, `cfemaleba`, `cfemalec`, `cfc`, `fga`, `fja` and `mga`. And the
   lost wardrobe: 196 of 210 textures and 116 of 141 `.bod`. It would be enough to
   drop them in `assets/gammatutorial-samples/base-avatars/`.
6. Upload `assets/WorldsPlayer/cachedir/cache.index` from your Mac (§1c): there
   is no other copy in the repo or in the CI.
7. Test the apps on your Intel Mac and, if you can, on Windows and an ARM Mac:
   once this branch reaches `main`, on the Releases page.
8. ~~**Updates with the private repository**~~: solved, the repository is
   public since 2026-09-30 and the updater needs no token.
9. Merge the branch into `main` so that the first release comes out (the CI
   publishes on every push to `main`).

## 4. Minor and parked

- `csq` without a sample of its own.
- Starbright World not investigated.
- Wirlaburla's repos return 404.
- Version comparator for the `.jar` (tool #5).
