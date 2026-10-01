# OpenWorlds

Reverse engineering of **Worlds Chat / WorldsPlayer** (Worlds Inc., mid
1990s), one of the first 3D social chat clients, and a modern way to play
it: the original 2004 client runs unchanged on a portable re-implementation
of its native engine, with a launcher, a world server of our own and
patches to choose from. `worlds.com`/`worlds.net` expired in 2025; the
original software could easily be lost.

**Full session-by-session history** (how each conclusion was reached, with
all the evidence): [`docs/worlds-chat-project.md`](docs/worlds-chat-project.md).
This file is the condensed current state — start here, and go there only
when you need the raw evidence for a specific finding.

## Goal and scope

1. Decompile the original Java client (`worlds.jar` / `gammacls.zip`) and
   document it openly.
2. Re-implement the native graphics engine (RenderWare 2.1 via JNI) from
   scratch so the client can be ported to modern platforms — final goal:
   Linux / OpenBSD / PSVita / macOS. It is done in the **portable bridge**
   (`editor/worldsplayer_source_editor-main/bridge/`), which translates
   gamma.dll, RWL21 and RWDL6D21 to Java so the original client runs as it
   is. **One engine** (the user's decision, 2026-09-26): the separate new
   engine (`client/`, own parsers + LWJGL) was removed from the repo. Do not
   create another one unless asked.
3. **J Solar Server** (`server/`): our own world server in Java, written from
   the client's protocol code and the third-party protocol documentation
   (`protocol/LibreWorlds-wiki-master/`). It replaced the vendored Rust
   server whirl on 2026-09-30 (the user's request): with whirl players never
   saw each other, and its dependencies carried many security advisories.
   It comes with an admin window anyone can use, and an encrypted mode (TLS).
4. **J Worlds Injector** (`injector/`): patches for the 2004 client that
   players choose in the launcher, applied to its source and compiled when
   the game starts. The decompiled source itself is never edited.

**Everything in the repository is in English** (code, comments, runtime
messages, docs).

## Non-negotiable technical context

- The 3D engine is **RenderWare 2.1** by Criterion Software, reached through
  JNI from Java into Windows DLLs. Confirmed by the real names/exports of
  the DLLs (`docs/renderware21-api-exports.txt`). **No RenderWare 2 SDK or
  source survives anywhere** — everything known about its API comes from
  decompiling the real binaries.
- Own formats:
  - **`.rwx`** — static geometry, ASCII text interpreted as a script
    (`ClumpBegin`/`ModelBegin`/...). No shaders/normal maps: albedo only,
    basic one-direction diffuse/specular, simple ambient.
  - **`.rwg` / `.bod`** — articulated avatars (binary, joint hierarchy).
    More complex than RWX.
  - **`.world`** — scenes/persistence (rooms, nodes, objects).
  - **`.seq`** — avatar animation. **`.cmp`/`.mov`** — own compressed
    textures.
- **The original protocol has no SSL/TLS** — everything travels as plain
  TCP/HTTP. Encryption exists only between J Solar Server and a client with
  the injector's "Encrypted connection" patch.
- The pre-RenderWare engine was called **Accomplish**: only relevant if
  historical references show up in the decompiled code.

## Repository layout

```
formats/src/net/openworlds/   verified readers the bridge uses: bod/ (.bod and .seq), rwg/, cmp/ (.cmp and .mov)
ui/src/net/openworlds/ui/     shared Swing look (logo palette, Poppins, the live planet): used by the launcher and J Solar Server
launcher/src/net/openworlds/launcher/   the game's launcher (window with the logo's look, terminal menu, CLI): installs worlds, builds patches, starts the 2004 client, updates itself
launcher/test/                launcher checks (updater, game copy, online/TLS/world-install helpers)
injector/                     J Worlds Injector: src/ (unified diffs applied and compiled with javax.tools), patches/ (built-in patches), test/
server/                       J Solar Server: src/ (the server, its admin window and console), resources/, test/ (protocol check, scripted walker)
.github/workflows/build.yml   CI: build + checks + corpus + smoke tests; apps for macOS/Windows/Linux; a release on every push to main
.claude/hooks/session-start.sh   provisions each Claude Code on the web session (calls tools/setup-linux.sh)
editor/worldsplayer_source_editor-main/   Whirlsplash's tool: decompiles/edits/recompiles the original .jar
  source/                      722 decompiled .java (Vineflower), NET.worlds.* — pristine, do not touch
  bridge/                      portable JNI bridge that replaces gamma.dll/RenderWare (no Wine)
decompiled-native/            Ghidra output for the native binaries (table below) — versionable text, not a build
protocol/LibreWorlds-wiki-master/   third-party wiki with the network protocol already documented
assets/                       verified test corpus (installed client, avatars, samples, the 2004 installer) — versioned on purpose
docs/                         reference per format + evidence; see "References" below
tools/                        provisioning scripts and utilities (table below)
analysis/                     Ghidra project of gamma.dll — gitignored, regenerable
build/                        output of tools/build-dist.sh (packages) — gitignored
```

The real target has always been `assets/worlds.jar` (formerly
`GAMMACLS.ZIP`). An early session decompiled `assets/Worlds1900.exe`
assuming it was the client; it is the Wise **installer stub** (strings
`WiseMain`, `WISE0001.DLL`). That work (`legacy/installer-reversing/`) was
removed on 2026-09-30: the bridge now installs Wise and NSIS packages
itself (`WisePackage`, `NsisPackage`); it is in the git history.

## Status by subsystem

| Subsystem | Status | Note |
|---|---|---|
| `.rwx` (static geometry) | ✅ Complete | the original reads it with `bridge/.../RwxReader` (translated from RWL21); format in `docs/rwx-format-reference.md`. The own reader verified 118/118 against `three-rwx-loader` went away with the new engine (git history, `8cd795d`) |
| `.world` (scenes) | ✅ Complete | the original reads it with its own `Restorer`; format in `docs/world-format-reference.md` (25 rooms / 578 nodes / 103 objects, measured with the own reader, removed with the new engine) |
| `.seq` (animation) | ✅ Complete | 231/231; `SeqSampler.keyTime` truncates like the `fistp` in chop mode of gamma.dll (0x43b9c0) |
| `.bod` (avatar, network format) | ✅ Complete | solved by translating the official encoder `RWXTOBOD.PL`, 51/51 |
| `.cmp` / `.mov` (textures) | ✅ Complete | 159/159 and 52/52 through `CmpFrames` (gamma.dll's frame table); frames in several row groups (FUN_00442bc0, Blair Witch's `mug.cmp`) and header byte 13 (`kcl.mov`), samples in `assets/cmp-verified/`. The frames of a `.mov` are **Material cells** (`Nh*`/`Nv*`/`Ns*`), not a movie; what changes over time is the whole Material via `AnimateAction` |
| `.rwg` (avatar, geometry) | 🟢 Almost complete | reader translated from RWL21 (TELT/MALT/RALT/ATOM/VLST/PLST, from the ASM); 5/6 of the corpus (`cube.rwg` does not load in RW 2.1 either); ATOM with children and RAST read as the binary does, without a real sample |
| Avatar name language | ✅ Documented | run by the original's `PosableShape`; `docs/avatar-name-language.md` (146/148 clean); **wardrobe corpus mostly lost** (only 14/210 textures and 25/141 `.bod` survive locally) |
| Animation (DroneAnimator) | ✅ Rule closed | 16+2 natives translated (walk/wait/endwait, sync with distance, 250 ms and gesture blends) in the bridge. ⚠️ VERIFY a drone's walk frame by frame now that J Solar Server shows other players |
| Worlds and installer | ✅ tested | 12 worlds visited in the original; the 2004 install only has GroundZero; the others come from the mirror (`us1.worlds.net`, today LibreWorlds): Wise and NSIS through the Java gdkup (`GdkUp`, `WisePackage`, `NsisPackage`). A world picked in the launcher's list is installed before the game starts (`WorldInstall`); the client's own downloads (universe map, portals, Upgrade Now) restart it with `world:restart`. Report: `docs/game-tests.md` |
| Original client on the portable bridge (macOS, Linux; Windows in CI) | 🟢 draws and is played | GroundZero with the RWDL6D21 driver's rasterizer, **in bands on several threads and pixel-identical** (`RasterGoldenCheck`; 1172×848: 25 → ~53 fps); affine matrix product like RWL21; `.bod` part material from the binary (0.32/0.55/0, flat); window menus (`u:/` paths resolved by `HostPath`), fonts with Arial metrics like the 2004 JRE, no hang at start (time.worlds.net); UI, sound, system and COM translated; chat with Enter; `GetTickCount` clock steps; dialogs close without the X11 hang (`AwtCompat`); the `_connectThread` race patched (`natives-java.patch`). Missing: the scene BSP (documented in ASM) |
| Network / protocol | 🟢 with J Solar Server | two original clients sign in, **see each other**, walk, chat, whisper and keep friends lists; plain (6650) and TLS (6651); `docs/net-local-server.md`. Guest login against the real `worlds.worlio.com` works; a registered account there is still missing |
| J Solar Server | ✅ | one port does distributor + user + room server; accounts (PBKDF2), guests, VIP/admin, bans, chat commands; TLS with a self-signed certificate that players pin; admin window in violet (players, accounts, chat, network, settings) or `--headless` console. `SolarProtocolCheck` (29 checks) |
| J Worlds Injector | ✅ | built-in patches: VIP, Walk faster, Time in the chat, No word filter, Encrypted connection (TLS, certificate pinned); players' own in `<data>/patches/`. `InjectorCheck` builds each patch alone and all together against the bridge |
| UI (chat, friends, map, menus) | 🟢 in the original | the 2004 AWT UI runs under the bridge and was tested in full (`docs/game-tests.md`) |
| Packages and CI | ✅ | `tools/build-dist.sh`: portable (.zip, Java 17+) and apps with their own Java (jlink + jpackage) for OpenWorlds and J Solar Server on macOS Intel/ARM, Windows and Linux. `.github/workflows/build.yml` does it on every push and **every push to main publishes a release** (`v1.0.<commits>`, packages + `SHA256SUMS.txt`) |
| Launcher | ✅ | the logo's look (live planet, Poppins OFL); "Single player" or "Online" (address, name, password, "Encrypted connection" with the certificate checked with the player the first time, like SSH); patches; the game's sign-in filled in; **updates itself** from the releases (`Updater`/`Bootstrap`, the new version in `<data>/app/`; the repo is public, no token needed). The game copy keeps what the client changes (manifest in `Install.prepare`) |
| OpenBSD / PSVita port | ⬜ 0% | phase 5. Note: the original client is Java with an AWT UI, and there is no Java on the PSVita |

Detailed status of the bridge, with what is pending:
`editor/worldsplayer_source_editor-main/bridge/README.md`.
Roadmap with what was done and what remains: `docs/roadmap.md`.

### Decompiled native code (`decompiled-native/`)

All the game's own binaries, 0 failures (the rest belong to Sun's Java
1.4.2 that came with the installer, msvcrt, xdelta/glib and Wise's
uninstaller: list and reason in `decompiled-native/README.md`):

| Binary | Functions | What it is |
|---|---|---|
| `gamma_dll/` | 2537 | JNI bridge + native codecs (`.seq`/`.cmp`/`.mov`) |
| `rwl21_dll/` | 1152 (795 with the real API name) | the RenderWare 2.1 engine itself |
| `rwdl6d21_dll/` | 411 | 16-bit software driver/rasterizer (the one the bridge translates) |
| `rwdl8d21_dll/`, `rwdlmd21_dll/`, `rwdldd21_dll/` | 427, 435, 305 | 8-bit, MMX and DirectDraw drivers |
| `run_exe/` | 139 | the 2004 launcher (`run.exe world:restart`) |
| `gdkup_exe/` | 256 | the updater; translated in `bridge/.../GdkUp.java` |
| `sfmain_exe/` | 619 | voice chat (SpeakFreely + GSM, Watcom); not translated |

Regenerable with `tools/ghidra-scripts/decompile-all.sh` (Ghidra 12.1.3
headless, `ExportAllDecompiled.java` + `ScanVtablesAndExport.java`); the
Ghidra project lives outside the repo.

## Development environment

**The user's machine: macOS 15.7 Intel (i5-7360U, 8 GB), no Homebrew (it no
longer supports Intel), no Wine.** The system bash is 3.2 — scripts must be
compatible (e.g. empty arrays under `set -u` fail in 3.2; avoid them).

- `tools/setup-macos.sh` — installs a portable Temurin JDK in `tools/jdk/`
  (gitignored). Run it first on a new machine.
- `tools/run-original.sh` — runs the **original** 2004 client under
  **Wine**. Only works on Linux/WSL2 (historical) — not available on this
  Mac.

Historical Linux/WSL2 environment (another machine): 28-core Xeon, GTX
1060, still valid there. Full detail in `docs/setup-macos.md`.

**Cloud (Claude Code on the web) and Linux:** `tools/setup-linux.sh` gets
the machine ready (xvfb, patch, zip, fonts-liberation; JDK 17+; compiles
`formats/` and the bridge). `.claude/hooks/session-start.sh` runs it at the
start of each web session. No display: `xvfb-run -a` or your own `Xvfb :99`.

**Packages to try without scripts:** `tools/build-dist.sh [--app-image]`
locally, or the *Artifacts* of each CI run on GitHub, or the Releases page.
The launcher (`OpenWorlds`, window or `--tui`) replaces `run_gamma.sh` for
playing; the script stays for diagnosis with `JAVA_OPTS`.

## Tools (`tools/`)

| Script/dir | What for |
|---|---|
| `build-dist.sh` | portable packages and, with `--app-image`, the native apps with their own Java (jlink + jpackage) for OpenWorlds (with the injector and `lib/worldsplayer-src.zip`) and J Solar Server; version `<launcher/VERSION>.<commits>`; the CI uses it |
| `setup-linux.sh`, `setup-macos.sh` | provision Linux/the cloud (the first one is called by the session hook) or a Mac: JDK, packages, compile `formats/` and the bridge |
| `dist-README.txt`, `dist-README-server.txt`, `icons/` | READMEs that go inside the packages; own icons, not Worlds.com's: a low-poly planet with a ring, and a violet one for J Solar Server (`icons/make_icons.py` draws them in SVG and makes the PNG, ICO, ICNS and the window icons) |
| `native_mapper.py` | crosses the decompiled Java's `native` methods with the real DLL exports |
| `jni_mock.py` + `gamma-dll-debug-harness/` | mock JNI bridge with logging, to start the client without a full renderer |
| `verify-corpus.sh` | regression in one command: compiles `formats/` and re-runs `.seq` 231, `.bod` 51, `.cmp` 159 and `.mov` 52 over the real corpus, then `run-checks.sh`; exits ≠0 if anything changes |
| `run-checks.sh` | runs every `*Check.java` of `formats/test/**`, `bridge/test/`, `injector/test/`, `launcher/test/` and `server/test/` (rebuilds the bridge if its build is stale); 45 today (5 + 35 + 1 + 3 + 1), including `RasterGoldenCheck` (CRC of 18 rasterizer views), `GdkUpCheck` (installs `assets/packages/`), `InjectorCheck`, `SolarProtocolCheck` and `UiDisposeCheck` (needs a display: the CI runs it under `xvfb-run`) |
| `progress-panel.py` | counts ⚠️/VERIFY/TODO/FIXME markers per module and file → `docs/progress.md` |
| `net-probe/` | real network probes against Worlio servers (handshake, guest login) |
| `ghidra-scripts/` | `ExportAllDecompiled.java`, `ScanVtablesAndExport.java` and `decompile-all.sh` — regenerate `decompiled-native/` |
| `local-upgrade-server.py` | local HTTP server that serves `assets/WorldsPlayer` to the original client and, with `--mirror`, asks the mirror for what is missing (`run_gamma.sh` uses it; the launcher has its Java version: `UpgradeServer`) |
| `rwg-explore/`, `gdk-sdk/` | `.rwg` exploration and official avatar tools recovered from GammaTutorial |
| `bring_to_front.py`, `bytecode-call-diff.py`, `pe_exports.py` | one-off utilities |

## Verification principles (non-negotiable)

1. **Never accept an address/function mapping without ASM-level
   evidence.** AI agents have made mistakes (duplicated addresses, etc.)
   when this level of proof was not required.
2. **Claude is a copilot, not an autonomous agent.** The bottleneck is the
   human verification of decompiled behaviour against the original
   binary, not the speed of generating code.
3. **Large batches with self-audit**, not function by function. ⚠️ VERIFY
   tags on whatever is doubtful, instead of constant manual checkpoints.
4. The goal is **verified functional re-implementation**, not just
   documentation — each confirmed function is rewritten as testable code,
   with test cases worked out by hand.

## How to work here

**Step 0, always first:** survey the real tree before touching anything —
do not assume this document still describes the exact repo (it may have
changed). Report first, act afterwards.

- Work by module/format, not function by function; present summaries with
  what is marked ⚠️ VERIFY so the human audits before anything is taken as
  good.
- The decompiled source (`editor/.../source/`) is never edited: the bridge
  changes it through its `*.patch` files at build time, and players' choices
  through the injector's patches.
- Protocol questions are answered from the client's own code
  (`NET.worlds.network`) and `protocol/LibreWorlds-wiki-master/`;
  `server/test/.../SolarProtocolCheck.java` is where a server behaviour gets
  pinned down.
- Local LLM (Ollama) only for low-risk mechanical tasks (bulk renaming,
  classification). Never to interpret complex logic or map protocol.
- **Subagents**: use them when the task means reading a lot but the
  conclusion fits in a short table (parallel exploration of `/source` by
  package, one-off searches in external documentation) or for mechanical
  bulk work (translations). Always bound the output ("at most N lines",
  "table only"). **Do not use them** to interpret complex logic/rebuild
  structs (it loses the fine control verification needs) nor for trivial
  one-off changes.

## Open right now

In order of what they unblock (detail in `docs/roadmap.md`):

0. **`assets/WorldsPlayer/cachedir/cache.index` is not in git** (it was in
   `.gitignore` as "bookkeeping"): without it, in a clean clone, in the CI
   and in the packages the original client does not find the 2004 cached
   avatars (GroundZero's statues have no texture). It only exists on the
   user's Mac: `git add -f assets/WorldsPlayer/cachedir/cache.index`. It is
   no longer ignored; `build-dist.sh` warns when it is missing.
1. **See avatars animate in the original**: J Solar Server now shows other
   players (`docs/renders/solar-two-clients.png`); check a drone's
   walk/wait cycle frame by frame against the translated rule. Same setup
   for the other open client item: whether clicking a hologram avatar
   (`HoloDrone`, nearly all of them) hits it and opens its menu
   (`docs/game-tests.md`, fixed bug 9).
2. **Login with a real account** on the primary server
   (`worlds.worlio.com/register` needs a human to register):
   `docs/net-real-account-login.md`.
3. **Scene clump BSP** of RWL21 (0x1002d170 / 0x1002cae0) and the 16-bit
   z-buffer per group: documented in ASM, not translated.
4. **Pixel reference**: captures of the original under Wine (Linux
   machine) to compare with the bridge, and the capture of the visual glitch
   that was reported.
5. Open decisions: fix or not the original's bug in `setDIBPixelInts`;
   language of the final engine for phase 5.
6. Phase 5 (OpenBSD/PSVita): not started.
7. Try the CI apps on real machines: the macOS ones are signed ad hoc
   (Gatekeeper: "Open Anyway" or `xattr -dr com.apple.quarantine`). In the
   CI the packaged original draws GroundZero on the four runners (Linux,
   macOS Intel and ARM, Windows; mandatory smoke test) and, on Linux,
   connects over TLS to the packaged J Solar Server with patches built in;
   nobody has opened the apps by hand outside the CI yet.
8. Minor: `csq` without a sample of its own, Starbright World not
   investigated, the 7 lost `.mov` of Julie/Roxanne/Simon (**note**: the
   mirror serves `avatar/cfemaleb.mov`, `cfc.mov`, `fga.mov`...: check
   whether they are those).
9. From the game tests (`docs/game-tests.md`): xdelta patches of the old
   worlds not applied; voice chat (`sfmain.exe`) not translated; the
   "Sleep" gesture does not show on the penguin; ⚠️ other places where the
   2004 code touches AWT while holding a dialog's monitor (the first
   `mainCallback`, `LoginWizard`'s `activeCallback`) could hang on X11 like
   the closing did (no case seen). The client offers to download the worlds
   its portals lead to as soon as a room loads (e.g. AvatarGallery at
   GroundZero's entrance): that is the 2004 behaviour; picking the world in
   the launcher installs it beforehand. **Open decision:** keep the mirror's
   world packages in the repo (today only two, for the tests, in
   `assets/packages/`).

**Not reproducible on the current Mac** (not the same as "broken"): `.cmp`
ground truth against `cmpview.exe` and the original client under Wine
(they need Windows/Wine).

## References

Technical documentation per format, generated and verified against the
real corpus — the source of truth for each format, not the history of how
it was reached:

- `docs/rwx-format-reference.md`, `docs/rwg-bod-format-reference.md`,
  `docs/bod-format-reference.md`, `docs/world-format-reference.md`,
  `docs/seq-animation-reference.md`, `docs/cmp-texture-format-reference.md`
  — file formats
- `docs/rwx-avatar-hierarchy-reference.md` — joint hierarchy in RWX
- `docs/native-methods-map.md`, `docs/native-methods-callers.md`,
  `docs/renderware21-api-exports.txt`, `docs/gamma-dll-exports.txt` —
  native/JNI bridge
- `docs/avatar-name-language.md`, `docs/net-real-account-login.md`,
  `docs/net-local-server.md` — avatars and network (J Solar Server and the
  protocol rules the client needs)
- `docs/game-tests.md` — everything tested in the game (worlds, menus,
  installing worlds) with the fixed bugs and what is open
- `docs/setup-macos.md` — macOS environment detail
- `docs/renders/` — captures (the original client, J Solar Server; those of
  the new engine are in the git history, up to `8cd795d`)
- `docs/gamma-dll-cmp-evidence/`, `docs/*.log`, `docs/*-trace*.txt` — raw
  evidence (real traces, dumps) cited from the code and from
  `docs/worlds-chat-project.md`; not reading documentation, they are the
  proof behind specific decisions
- **`docs/worlds-chat-project.md`** — full session-by-session history since
  the start of the project (2026-09-08 onwards). Look there when you need
  the full *why* of a non-obvious decision; several comments in the code
  cite it directly by section.
