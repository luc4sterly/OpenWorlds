# Worlds Chat — Preservation and Reverse Engineering (historical record)

> ⚠️ **Historical file.** The current state of the project, condensed and
> up to date, lives in [`CLAUDE.md`](../CLAUDE.md) — start there. This is the
> session-by-session diary since the start of the project (2026-09-08
> onwards): it is kept in full because several comments in the code
> cite specific sections as evidence for non-obvious decisions, and
> because it is the proof of how each finding was verified. The content
> below has not been edited when archiving this — it stays exactly as it was written
> session by session, with its original internal references to "section N".

---

## 1. What this is and why

**Worlds Chat / WorldsPlayer** (Worlds.com) was one of the first 3D/VR social
chat clients, from the mid-1990s (company: Worlds Inc., born from a
spin-off of Knowledge Adventure Worlds). The official domains
(`worlds.com`, `worlds.net`) expired around October 2025 and now
show a parking page. The original software is at real risk
of being lost if nobody preserves it.

**Project goal:**
1. Decompile the original Java client (`worlds.jar` / `gammacls.zip`)
2. Document it and make it open source
3. Port it to modern platforms — final goal: **Linux / OpenBSD / PSvita / macOS**, with
   an **SDL2/OpenGL** stack
4. Replace the native Windows dependencies (the RenderWare graphics engine via
   JNI) with an equivalent portable implementation

**Current scope: the client only.** The network protocol is already documented
by third parties and an open source server already exists (`whirl`, see section 3). There is
no need to reinvent the server.

---

## 2. Technical context of the client

- The client (`worlds.jar`) has to be decompiled by ourselves — **no
  pre-decompiled version has been published** in any public repo.
- It uses a modified version of **RenderWare 2** (Criterion
  Software's graphics engine) for 3D rendering, accessed via **JNI** from Java to
  Windows DLLs. This is what forces the use of Wine on Linux today.
  - Confirmed by two independent sources: a tutorial on kangworlds.net and the
    `Sgeo/rwg_to_rwx` repo, which explicitly distinguishes between **RenderWare
    2.0** (old Worlds) and **RenderWare 2.1** ("modern WorldsPlayer" — the
    version that is probably relevant for us).
  - ✅ **Confirmed** (see section 10): it is RenderWare **2.1**, from the
    names and export tables of the real DLLs
    (`docs/renderware21-api-exports.txt`). Since 2026-09-15 there is also
    our own disassembly of `RWL21.DLL` (clump/joint matrix composition,
    see `docs/seq-animation-reference.md` §5).
- **No RenderWare 2 SDK or source has been preserved anywhere.** There is only
  abundant RenderWare 3.x material (the GTA one), which is a binary format
  **incompatible** with RWX — it is not a direct shortcut.
- Proprietary file formats:
  - **RWX** — static geometry. Plain ASCII text, executed as a script
    (commands like `ClumpBegin`/`ClumpEnd`, `ModelBegin`/`ModelEnd`, etc.). The
    interpreter ignores commands it does not recognize. No shaders or normal maps:
    only color texture (albedo), very basic single-direction diffuse/specular
    light, simple ambient, and limited transparency.
  - **RWG / BOD** — articulated avatars (with a bone/joint hierarchy).
    **Binary** format, more complex. Start with RWX, leave this for
    later.
  - Custom avatars: **24-bit BMP** textures, valid extensions `.rwg` /
    `.bod`.
- **WorldsPlayer does not support SSL/TLS** — all traffic (including what we
  reimplement) has to go over plain HTTP.
- The original Worlds Chat (before RenderWare) used a more primitive proprietary
  engine called **Accomplish**. It is not relevant for the modern version
  of the client, but it is a useful historical fact if references to it appear in the
  decompiled code.

---

## 3. Complete map of the ecosystem (everything found)

### 3.1 Whirlsplash (github.com/Whirlsplash) — the most useful and active

| Repo | What it is | Status | Why it matters |
|---|---|---|---|
| `worldsplayer_source_editor` | Decompiles/edits/recompiles WorldsPlayer on Linux (Make + Vineflower + Java 6) | ✅ Active | **This is the tool we started the project with.** |
| `whirl` | Open source WorldServer server, in Rust | ✅ Active (March 2026), 12★ | Network protocol already solved — no need to write our own server |
| `LibreWorlds` (a.k.a. `OpenWorlds`) | Protocol reverse engineering, cross-platform client from scratch | ❌ Archived 2017–2021 | Stopped at protocol documentation, never finished the graphical client. Useful as a historical reference |
| `LibreWorlds-wiki` | Wiki associated with the previous repo | ❌ Archived | Protocol documentation |
| `terra` | Bot framework ("Structured bots for Worlds") | 🚧 Very early preview, 2 commits | Restructuring of `munch` |
| `munch` | Bot in Go with Discord integration | — | Another independent implementation of the protocol (in Go), useful for cross-validation |
| `frontend` | Web panel for server management/statistics + Discord bot | — | Secondary |
| `worldsy` | Discord Rich Presence client for Worlds (Python) | — | Secondary, curiosity |
| `cloworlds`, `node-worlds`, `deno_worlds` | Client libraries in Clojure, Node.js, Deno | ❌ Archived | Reference implementations of the protocol in several languages |
| `assets` | Shared graphical resources | — | Secondary |

General documentation of the Whirlsplash ecosystem is centralized at
`whirlsplash.org` (includes a resources page that also links to GammaDocs).

### 3.2 Blaxar's ecosystem (Julien Bardagi) — the most useful for rendering

| Repo | What it is | Language |
|---|---|---|
| `three-rwx-loader` | **Complete and working RWX parser + renderer**, with support for textures and masks | JavaScript (three.js/WebGL) |
| `WideWorlds` | Complete web client + server, Active Worlds style ("Metaverse accessible from your browser, following in the footsteps of Active Worlds") — Node.js/HTTP+WS backend, Vue.js frontend, SQLite3, AW world dump importer | JavaScript |
| `rwx2blender` | Blender add-on to import RWX | Python |
| `aw-sequence-parser` | Parser for Active Worlds avatar animations/sequences | JavaScript |

⚠️ **Important note**: there is no ready-made RWX parser in **Java**. Everything
reusable from Blaxar is in JavaScript — the **logic has to be translated**,
not copy-pasted directly.

### 3.3 Other loose tools

- **`Bloyteg/RWXViewer`** — web viewer of RWX files for ActiveWorlds/Virtual
  Paradise. Apache 2.0.
- **`adamaig/blender_rwx_importer`** — another RWX importer for Blender (older,
  Blender 2.49).
- **`Sgeo/rwg_to_rwx`** — RWG→RWX converter, confirms the distinction between
  RenderWare 2.0 and 2.1 in different versions of WorldsPlayer.

### 3.4 Documentation

- **GammaDocs** — **OFFICIAL Worlds Inc. documentation** for
  developers, preserved:
  - Internet Archive: `archive.org/details/gammadocs`
  - Mirror at Worlio: `files.worlio.com/files/WorldsPlayer/guides/GammaDocs/`
  - Wayback Machine: copies of `dev.worlds.net/private/GammaDocs/`
  - Contents: `WorldServer.html` (server architecture: RoomServer,
    UserServer — for sysadmins with Unix/Oracle/Web knowledge),
    `Gamma_Overview.html`, `Gamma_Procedures.html`, `Gamma_Advanced.html`
    (Shaper installation, world packaging)
- **`kangworlds.net`** (by bonkmaykr, webmaster of Worlio) — tutorials on
  creating RWX/RWG avatars, texture compression, and a page
  *"Creating a WorldsPlayer Interface"* explicitly based on official
  Worlds Inc. documentation.
- **Active Worlds wiki** (`wiki.activeworlds.com`) — complete documentation
  of all the RWX script commands, including AW's own extensions
  (`#!` prefix)
- **Worlds Chat Wiki** — two community mirrors:
  - `worldschat.fandom.com`
  - `worldschat.miraheze.org`
  - Useful content: "Avatars" page (24-bit BMP, no SSL/TLS, `.rwg`/`.bod`
    extensions), "Worlds Chat" page (genealogy shared with Active
    Worlds and **Starbright World** — possible third sibling project, not
    yet investigated)

### 3.5 Community and live servers today

- **WorlioWorlds** (`worlds.worlio.com`) — free revival server,
  ~8 users online / 116 registered. Requires editing `override.ini`
  (`WorldServer`, `UpgradeServer`, `ScriptServer` → Worlio domains),
  web registration.
- **Worlio** (`worlio.com`) — general "Web 1.0" preservation project
  (forum, archive, Jabber/XMPP, Mumble, IRC, radio). Organization behind it:
  **Canithesis Interactive** (bonkmaykr's).
  - 13 May 2025: **Wirlaburla stepped down as webmaster** of Worlio after
    years of rumors/harassment from a rival member of the Worlds community.
    Development of all of Worlio's projects has been frozen since
    then (which explains the 404s on repos that used to live on `git.worlio.com`).
    Worlio became the property of Canithesis Interactive GP.
- **LibreWorlds** (`libreworlds.org`) — active community/test server,
  its own Discord, infrastructure managed by **Electric Jungle** (a collective
  that gives best-effort hosting/support to several projects).
- **OMEGA** — client mod made by Wirla, a rewrite of "Worlds+".
  Compatible from build 1890 onwards. Installed by replacing
  `gammacls.zip`/`worlds.jar` in the client's `lib` folder. Source code
  not publicly published (distributed as a compiled ZIP).
  - Wirlaburla does have public repos on their own Gitea instance
    (`wirlaburla.com/git`), including `Worlds-Organizer` (a Java tool
    for organizing WorldsPlayer files/resources, with an
    `IMGTranscoder.java` for transcoding images).
  - ⚠️ Links to `git.worlio.com` / `git.canithesis.org` with Wirlaburla's
    specific repos (`WorldsMods`, `P3NG0`, `WorldsTerminal`) returned 404 when
    trying to access them — they may have been moved, renamed, or not
    survived the migration. Check manually in the browser if
    needed, the search tool could not confirm their current status.

---

## 4. Tools and working environment

> ⚠️ **Current environment (since 2026-09-15): macOS 15.7 on an Intel
> MacBook** (i5-7360U), no Homebrew (it no longer supports Intel), no Wine and no
> node. The JDK is portable (`tools/jdk`, installed by
> `tools/setup-macos.sh`) and `bash` is the system's 3.2. See
> `docs/setup-macos.md`. What follows is the historical Linux/WSL2 environment,
> which is still valid on that machine.

- **Hardware**: Xeon 28-core LGA2011, GTX 1060 6GB, 16GB RAM + zram/swap
- **WSL2** — main working environment (historical)
  - ⚠️ If the repo is cloned onto the Windows filesystem, a CRLF
    line-ending error (`env: $'bash\r'`) shows up when running `bin/decompile`. Fix:
    `dos2unix bin/decompile` (and any other bash script in the repo if it gives the
    same error)
- **Decompilation**: `worldsplayer_source_editor`
  - Requires: **Java 6** (JDK, from the Oracle Java Archive — no longer normally
    distributed), **Vineflower** (decompiler, must be on the `PATH`), and
    the original `worlds.jar` itself
  - Flow:
    ```bash
    # Decompile
    WORLDSPLAYER_JAR=/path/to/worlds.jar make decompile
    # → dumps the sources into /source

    # Edit freely in /source

    # Recompile
    JAVAC=/path/to/java6/compiler make compile
    # → generates out/worlds.jar

    # Install directly into the client (optional)
    WORLDSPLAYER_JAR=/path/to/worlds.jar make install
    ```
  - Ships example patches in `patches/optional/`: `free_vip.patch`,
    `bypass_assert_fail_exit.patch`
- **Binary analysis**: Ghidra (disassembly/decompilation of the native
  DLLs), IDA Free (ASM cross-reference)
- **Local inference (Ollama)**: Qwen 2.5/3 7B or DeepSeek distillates —
  **only for mechanical, low-risk tasks** (mass renaming,
  pattern classification, formatting). Never for interpreting complex
  logic, reconstructing structs, or protocol mapping — errors
  propagate silently there.
- **Claude Code** — copilot for interpreting pseudo-C, reconstructing structs, and
  mapping the protocol documentation against the decompiled code. The
  agent must read the exported files directly from disk, not have code
  copied by hand passed to it.

### Groundwork already done
- Target `.jar` located: extracted from a 2004 Wise Installation
  System installer. `GAMMACLS.ZIP` inside the `FIRST` package contains the
  Java classes under `NET.worlds.{br, console, core, network, scape}` —
  confirmed as the WorldsPlayer client code. Plan: copy it as
  `worlds.jar` for the Makefile.
- **✅ DONE (2026-09-08)**: `GAMMACLS.ZIP` extracted from `assets/FIRST.EXE`
  (which is a ZIP SFX readable directly with `zipfile`/`unzip`, with no need
  for Wine) and copied to `assets/worlds.jar`. Vineflower 1.12.0
  downloaded to `tools/vineflower.jar` with an executable shim at
  `tools/vineflower` (only a modern JVM is needed to *decompile* —
  Java 6 is only necessary to *recompile* with `make compile`).
  `make decompile` ran successfully in `editor/worldsplayer_source_editor-main`
  → **722 `.java` files in `editor/worldsplayer_source_editor-main/source/`**
  (actual package: `NET.worlds.*`, with NET in uppercase). The editor's patches
  (`patches/fix_compilation_errors.patch`) **did not apply cleanly**
  (probably due to a Vineflower version difference vs. the one the
  tool's author used) — pending resolution before attempting `make compile`.
  Quick reconnaissance: 64 `native` methods detected with a simple grep
  (`GetDiskFreeSpace`, `GetTotalPhysicalMemory`, `instanceOf`, `getBuildInfo`,
  etc.) — real starting point for tool #1 (section 7).

### ⚠️ Critical finding (2026-09-08): the previous scaffold pointed at the wrong binary
Before this session, someone (a previous Claude Code session, judging by the
`README.md` recovered from the initial commit) had reverse engineered `Worlds1900.exe`
with Ghidra + IDA (`Worlds1900.exe.{asm,c,gzf,i64,map}`) and had set up a
CMake/C wrapper (`src/`, `include/`, `build/`) assuming it was the WorldsPlayer
client.

**`Worlds1900.exe` is NOT the client — it is the Wise installer stub.**
Confirmed with `strings Worlds1900.exe`: it literally contains `"WiseMain"`,
`"WISE0001.DLL"`, `"Windows Self-Installing Executable"`, `"GLBSInstall"`. The
decompiled functions (`FUN_00401177`, `FUN_00401583`, `FUN_00401810`, etc.)
are the installer's Huffman/LZ decompression algorithm (the same engine that
extracts `FIRST.EXE`), not 3D client logic. All that work was valid
as reverse engineering of the installer, but contributed nothing to the real goal
of the project (the Java client + JNI/RenderWare).

That scaffold was moved to `legacy/installer-reversing/` so it would not be in the way,
keeping the work in case it is of interest some day (e.g. to extract more
packages embedded in other Wise installers without depending on Python/zipfile).
**The real target to decompile is `assets/worlds.jar` (formerly `GAMMACLS.ZIP`) via
`editor/worldsplayer_source_editor-main`, not any native `.exe`.**

### ✅ Full decompile → fix → recompile cycle verified (2026-09-08)
The explicit request was "decompile the game", so I went all the way through: the decompiled
code (722 `.java`) **did not compile** with any modern JDK
(`javac --release 8`; the `-source 1.6` in the original `Makefile` no longer even
exists in current JDKs). It was fixed in the working copy
(`editor/worldsplayer_source_editor-main/source/`, commit `e719a84` in its
nested git repo) and `patches/fix_compilation_errors.patch` was regenerated from
the real diff (the tool's old patch, written for another version of
Vineflower, no longer applied cleanly). Categories of fixes, from most to least
frequent:

1. **`assert`/`enum` as identifiers** — the code dates from ~2000-2001,
   before Java 1.4 (`assert`, 2002) and 1.5 (`enum`, 2004) reserved those
   words. `Debug.assert(...)` → `Debug.assert_(...)` (114 call sites, 91
   files) and `Property enum()` → `enum_()`.
2. **Synthetic `this$0`/`val$X` fields and `access$NNN` bridges not
   reconstructed by Vineflower** in 14 anonymous/inner classes
   (`MCISoundPlayer$1-4`, `DefaultConsole$1-3`, `TradeDialog$1-2`, etc.) —
   Vineflower emitted the usage but not the declaration. The types were deduced
   from context (constructor parameter) and, for the `access$NNN`, from
   the usage signature at the call site cross-checked against the `private` members of
   the containing class (see `MCISoundPlayer.java`, `LogFile.java`,
   `ActionsPart.java`).
3. **Pre-1.5 `Foo.class` idiom not collapsed** (`class$NET$worlds$...
   == null ? (class$... = class$("...")) : class$...`) in `WObject.java` (6
   occurrences) — replaced by the direct `.class` literal.
4. **Decompiler type losses** (`Object`↔`String`,
   `WObject`↔`Surface`, `Persister`↔`Persister[]`, missing `Integer` unboxing in
   `+=`/`-=`) — in `DefaultConsole.java` it was verified with hard
   evidence (`javap -c -p` on the original `.class` in
   `assets/worlds.jar`, not an assumption) that the real bug was the declared
   type of the variable, not the construction expression.
5. `sun.misc.BASE64Encoder` (removed from the JDK years ago) → `java.util.Base64`.

**Result: 0 compilation errors.** `jar` packaged at
`editor/worldsplayer_source_editor-main/out/worlds.jar` (not versioned,
regenerable — see `.gitignore`), 736 classes, 1.3MB. Verification that the
recompiled result is functionally faithful: it runs on a real JVM
(`java -cp out/worlds.jar NET.worlds.console.Gamma`), prints its own
startup banner, and fails exactly where expected —
`UnsatisfiedLinkError` when trying to `System.load("gamma.dll")` because it is a
Windows x86 DLL running on Linux without Wine. It is proof that the JNI
bridge to RenderWare (section 2, tool #1 of section 7) is
intact and is the next real point of attack for phase 2 (portable
renderer).

### ✅ Tool #1 built (2026-09-08): `native` method mapper
The user contributed `assets/WorldsPlayer/` — the **real tree of an
already-done installation** of the client (not just the installer package): `bin/` with all the native
DLLs (including the RenderWare ones and `gamma.dll`, the real JNI bridge),
`lib/gammacls.zip` + `rt.jar` (complete Sun 1.4.2_05 JRE), real execution
logs (`Gamma.Log`, `GroundZero.log`) and config (`worlds.ini`,
`override.ini`). From the real logs: the client is launched with
`java.class.path=.;lib\gammacls.zip` and
`sun.boot.class.path=lib\i18ncls.zip;lib\rt.jar`, and the original server
it tried to connect to after startup is `www.3dcd.com:6650` (dead today,
as expected).

It also brought Ghidra 12.1.3 (headless, `analyzeHeadless` works with the
system's Java 25 — the minimum Ghidra asks for is Java 21). With that:

1. I analyzed `gamma.dll` with `analyzeHeadless` (project in `analysis/`, not
   versioned — regenerable, see `.gitignore`).
2. I parsed the export table of `gamma.dll` and `RWL21.DLL` by hand (dependency-free
   Python script — `objdump -T`/`pip` were not available or did not
   work with these old PE32s) → **372 JNI exports in `gamma.dll`**,
   dumped into `docs/gamma-dll-exports.txt`.
3. I wrote a script that walks the 722 decompiled `.java` files, extracts each
   `native` declaration, computes the expected JNI symbol (with the real
   underscore mangling `_` → `_1`) and cross-checks it against the real exports →
   **`docs/native-methods-map.md`**.

**Initial result of this session: 360 `native` declarations found,
358 match a real export of `gamma.dll`.** (Numbers corrected the next
day — see the 2026-09-09 block further below: the regex had a modifiers bug
and skipped 5 real declarations; the correct total is 365.)
This confirms with hard evidence that `gamma.dll` is *the* JNI bridge of the
client — there is no need to look for the native implementation anywhere else.

**File reorganization of this session:**
- `move/` (contributed by the user) → `assets/WorldsPlayer/`.
- `tools/vineflower.jar` + shim `tools/vineflower` (downloaded from GitHub,
  release 1.12.0) — needed to repeat `make decompile`.
- New `.gitignore`: excludes the Ghidra installation (~1.4GB, reinstallable
  external tool) and `analysis/` (Ghidra project, regenerable).

### ✅ The 2 unmapped methods investigated + JNI mock bridge built (2026-09-09)

**1) Investigation of the 2 `native` methods with no export in `gamma.dll`** (with
real evidence, not assumption — see `docs/native-methods-map.md` for the
full detail):

- In passing, a bug was found in the mapper's regex: it only accepted
  `static` at a fixed position before `native`, and skipped
  declarations with a different order (`public static final native`, `public
  static synchronized native`). Fixed → the real total of `native` declarations
  is **365**, not 360.
- **`sendURL.silent_get`** — ✅ resolved, it was a false negative of the script:
  the export exists (`?Java_NET_worlds_scape_sendURL_silent_get@@YGJ...`)
  but with **MSVC C++** mangling, not the standard `_Java_...@N` with the escape
  `_`→`_1` that most use. The mapper now tries both forms.
- **`PendingCacheDrone.nativeDestroy`** — ⚠️ confirmed dead code: 0
  possible exports in `gamma.dll` under any mangling, and 0 calls in the
  722 decompiled files (compare with `nativeInit()`, which is called
  from the `static {}` of the same class).
- **`Console.getVolumeInfo`** — ⚠️ same pattern: a twin
  `Startup.getVolumeInfo()` exists that is exported and is used from
  `LoginWizard.java:702`; the `Console` version is an obsolete duplicate,
  0 calls, no export of its own.
- **Final result: 365 declarations, 363 (99.5%) mapped against
  `gamma.dll`, 2 confirmed as dead code** (they block nothing).

**2) JNI mock bridge (tool #4, section 7)** — implemented with
`tools/jni_mock.py`:
- Replaces every `native` method with a body that calls
  `NET.worlds.core.NativeMock.log(class, method, args)` (a new class) and
  returns a default value. Defaults policy (documented in the
  script itself, it is not "the truth", it is a choice to maximize how far
  the client gets): `boolean`→`true` (to get past the startup guards `if
  (!check()) exit/bail` instead of stopping at the first one),
  numerics→`0`, references→`null` **unless** the last parameter is
  of the same type as the return (the `getIniString(key, default)` pattern), in
  which case that parameter is returned — avoids cascading `NullPointerException`s
  from defaults that the client itself actually already knew how to resolve.
- The 2 `System.load(...)` calls in `Gamma.java` (main startup + `dllLoad()`)
  were also wrapped in `try/catch`; otherwise they would abort the
  whole process when the Windows DLL is not found.
- It also generates `docs/native-methods-callers.md`: which class calls each
  `native`, useful for knowing which code path each stub triggers. ⚠️
  **Limitation documented in the file itself**: it is a text grep, it does not
  understand polymorphism/reflection — 167/365 come out as "no calls
  found" and **that does not mean dead code**, except for the 2 cases above,
  which were verified separately by cross-checking against `gamma.dll`.
- The whole flow (regenerate clean `source/` → apply the mock → recompile)
  is in `editor/worldsplayer_source_editor-main/apply_mock.sh`, so as not to
  have to redo it by hand every time (the decompiled `source/` is not
  versioned — see `.gitignore` — so it has to be regenerated and re-mocked in
  every new session before the client can be run).

**Runtime result** (headless, `java -cp out/worlds-mock.jar
NET.worlds.console.Gamma`, full log in
`docs/jni-mock-runtime-trace.log`): the client **really starts without
any Windows DLL** — it passes the single-instance check
(`Startup.synchronizeStartup`), loads `worlds.ini`, resolves the message
`ResourceBundle` (it detected the system's `es_ES` locale) — and reaches
the construction of the real Swing/AWT `MenuBar` in
`Console.<clinit>`, where it blows up with `java.awt.HeadlessException`. **This
is no longer a native mocking problem — it is that there is no X server on
this machine.**

### ✅ Tested with Xvfb (2026-09-09) — two more findings, neither from the JNI bridge

With Xvfb (`Xvfb :99 -screen 0 1024x768x24`, `DISPLAY=:99`) the client got past
the `HeadlessException` point and went quite a lot further, until it hit two
real problems — neither is a hole in the mock, both are
isolated and confirmed with evidence, not assumed:

1. **`libnet.so` collision** — `Gamma.main()` calls
   `System.loadLibrary("net")` (meant to load the legacy `net.dll` of the
   2004 JRE, see `assets/WorldsPlayer/bin/net.dll`). In any
   modern JDK, "net" collides with the JDK's **own** `libnet.so` (its
   internal networking library): the initial load "succeeds" but
   is registered under the app classloader; later, when Swing
   needs the same library via NIO to read the font config, the
   *bootstrap* classloader asks for it and the JVM blows up with
   `UnsatisfiedLinkError: ... already loaded in another classloader`.
   **Isolated with a minimal 10-line reproducer** (`System.loadLibrary
   ("net")` + touching a `JPasswordField`, with nothing from the real client) — the
   error is byte-for-byte identical. Fixed: `apply_mock.sh` now skips that
   specific call (it did nothing useful outside real Windows
   anyway).
2. **Windows-style path assumption in `NET.worlds.network.URL`** —
   `currentDir = System.getProperty("user.dir").replace('\\', '/')` followed
   by `Debug.dAssert(currentDir.charAt(1) == ':' || currentDir.startsWith
   ("//"))` in the `static {}` block of `URL.java:557`. On Windows
   `user.dir` looks like `C:\...` (passes the assert); on Linux it is
   `/home/...` and the assertion always fails. **This is real client
   logic, not a `native` method** — it is outside the scope of tool #4
   (which only mocks `native`s) and falls squarely within the
   portability work of phase 4 of the roadmap (section 5). ✅
   **Investigated and patched (2026-09-09)** — see the next block.

**The exception occurs inside `NET.worlds.network.NetUpdate.<clinit>`**,
just when the client is computing the upgrade server URL —
that is, we literally reached the edge of the network connection logic before
dying.

### ✅ Windows path assumption investigated and ported (2026-09-09)

Before touching anything: `currentDir` is only used in **3 places** of
`URL.java`, all three with the same `<drive-letter>:/...` structure:

1. The section 4 assert itself (`static {}`, line 557).
2. `validateFile()` — uses `currentDir.substring(0, 2)` (the first 2
   characters, "drive + `:`") as the default prefix when it resolves an
   absolute path (`/something`) or a relative one with no explicit drive.
3. `normalize()` — has two more asserts (`var0.indexOf(58, 5) == 6` and
   `var0.charAt(7) == '/'`) that depend on the result of
   `validateFile()` having exactly that format of 1 character + `:` + `/`.

**There are no real `\` separators at any other point of the class** (the
only `.replace('\\', '/')` is the input normalization, done before
all of this). The only real `new File(...)` in the class, in
`searchPath()`, builds the path with `File.separator` (already portable) by a
route that does **not** touch `_url`/`currentDir` at all — so the problem
is genuinely contained to these 3 places.

**Minimal patch applied**: instead of touching the asserts or the logic of
`validateFile()`/`normalize()` (used everywhere), a fake single-character "drive"
(`u:`, for "Unix") is synthesized when `user.dir` does not
already have the shape of a Windows path — `normalizeCurrentDir()` in `URL.java`,
automatically reapplied by `apply_mock.sh`. With this,
`/home/lucas/OpenWorlds/...` becomes `u:/home/lucas/OpenWorlds/...`,
which meets exactly the same `<1 char>:/...` shape that the code already
expects in the 3 places — zero changes to the parsing logic. **It does not affect
real Windows**: if `user.dir` already looks like a Windows path, the function
returns it untouched.

**Result**: the client sailed past `NetUpdate.<clinit>`/`URL.<clinit>`
with no more portability crashes, completed a **whole startup and
clean shutdown cycle** (exit code 0, no hang, 184-line log in
`docs/xvfb-runtime-trace.log` — it used to be 49). Real config loaded
(`worlds.ini` simulated by the mock), locale detected (`es_ES`), it tried to
read `redir.txt` (does not exist, handled gracefully), initialized the cache,
tried to load the default world `newworld.world`...

**Related finding, NOT patched (out of scope this time)**: when
initializing the cache, `Cache.java:23` does exactly the inverse problem
— `Gamma.earlyURLUnalias("home:cachedir/").replace('/', '\\')` — it converts
the already-correct path back to backslashes before opening the file with
`FileInputStream`, which on Linux produces an absurd literal file name
(`\home\lucas\...\cachedir\cache.index`, with backslashes as ordinary
characters, not separators). It is not fatal — the client catches it and
carries on ("Flushing cache index.") — but there are **4 more places** with the same
`.replace('/', '\\')` pattern: `EditMusicDialog.java:39`, `ASFThread.java:26`,
`Shaper.java:141`, and `Cache.java:23` itself. None blocked this
run, so they are documented as ⚠️ VERIFY for a future portability
pass, and were not touched (it was not what was asked this time).

### ✅ Session 2026-09-09 (continuation): 6 more walls, client reaches the real network and downloads successfully

Long autonomous session, pushing from the assert at `Cursor.java:212`
to the final goal (real network connection). Each wall was investigated
with evidence before touching it, following the same criterion as the
previous sessions. Commits in order: `6c503ba`, `645c3d3`, `f563a6b`,
`4ffac8c`, `f1e53e1`, `618af6f`.

1. **"Smart" `FastDataInput` mock** (picked up again from the previous session,
   committed now) — contract investigated in depth before writing anything:
   `implements DataInput`, the whole method surface is that interface's
   primitives (no seek/random-access anywhere), and
   `protocol/LibreWorlds-wiki-master/Persister-(.world-etc.)-format.md`
   (third-party, independent documentation) confirms that the on-disk format
   **is** the wire format of `java.io.DataInput`, not an approximation.
   Implemented by wrapping a real `DataInputStream`. `NewWorld.world`
   confirmed present in `assets/WorldsPlayer/` (not assumed — verified
   with `find`) and loaded successfully for the first time.
2. **`Cursor.java:212`** — investigated: it is NOT a Windows portability wall
   like the earlier ones. `defaultCursor = retrieveSystemCursor(...)`
   comes from `loadSystemCursor("IDC_ARROW")`, a `native` that returns a
   Win32 handle — the mock's generic policy (`int` → `0`) clashes with this
   code's convention that `0` means "failed". Same problem
   in `loadCursor()`. Fix: return `1` instead of `0` for those two.
3. **Real decompiler bug, not portability**: `PosableShape.<clinit>`
   blew up with `ArrayIndexOutOfBoundsException: Index -128` — a loop
   counter declared `byte` overflows at 127 elements and keeps going
   negative. The same pattern (`for (byte `) was searched across the whole tree: **11
   occurrences in 8 files**, all verified one by one (the counter
   is only used for indexing, never stored as a `byte`) before
   fixing them all in a batch.
4. **Generalized heuristic in `jni_mock.py`**: `Transform.scale(float,
   float,float)` (native, mocked to `null`) is used in fluent chains
   (`var1.scale(x).raise(y)`) — the `null` breaks the NEXT call in the
   chain, not this one, which made it easy to overlook. The rule was
   generalized: when a non-static `native` returns exactly the type of
   its own class, the mock returns `this` — verified against real call sites
   before generalizing. 28 methods affected after reapplying.
5. **"Smart" `IniFile` mock** — the session's key finding:
   small contract (2 getters, 2 setters) over files in the classic INI
   format already seen literally in the real `worlds.ini`/`override.ini`.
   Implemented with a real INI parser. **This revealed the real reason
   why a connection attempt was never seen**: `World.setWorldServerURL()`
   only calls `Console.load()` with a real URL if `this.isMultiuser` is
   `true`, and without reading the real `worlds.ini` the client could never see
   `RestartAt=home:GroundZero/GroundZero.world` — it always fell back to the single-player
   `NewWorld.world`, which has no server and therefore
   never tries to connect. It was not a hole in the mock — it was the
   previous `IniFile` mock (generic, not reading any real file).
6. **Real DNS in `DNSLookup.gethostbyname`** — trivial contract (`String →
   String[]` of IPs), implemented with the real `InetAddress.getAllByName()`.

**Final result, verified with hard evidence, not text logs**: with the
real `worlds.ini` now read, the client requests `upgradeServer=
http://us1.worlds.net/3DCDup` and under Xvfb **completes a real, successful
HTTP download**. `getent hosts us1.worlds.net` resolves to a real, live IP
(`172.237.126.108`, reverse DNS `file.libreworlds.org` — **not** the
dead domain that was assumed in section 1), and the files the client wrote
to its local cache after the download were inspected directly:
`cachedir/1.dat` opens with the real header of `actions.dat` ("VERSION 2 //
This file defines global actions that may be performed by avatars...");
two other files are real lists of languages/fonts with locale codes
(`ja_JP 210673`, `es_ES 208280`, etc.). **`us1.worlds.net` is alive
and serving real content** — apparently maintained or mirrored by the
LibreWorlds community, not simply dead as was assumed.

The client's main thread completes its local startup sequence and
calls `System.exit(0)` in well under a second — the cache downloads run
in asynchronous daemon threads (`NetCacheThreads=2`) that do not get to
report a result via log before the JVM terminates, so there is
no explicit "successful connection" line in
`docs/xvfb-runtime-trace.log` — but the real files on disk are
stronger evidence than any log line.

**Stopping point of this session** (as requested): going further
(an explicit login flow, waiting for the asynchronous cache threads)
would require touching the flow control of `Gamma.java` or the thread model of
`Cache`/`NetUpdate` — real network/flow code of the client, no longer a native
mock or a minor portability fix. Stopping here so that the
user decides on the next step.

### Default server addresses (question 4)

Without needing the client to get any further, this can already be derived by
static analysis + the real config the user contributed:

- **`assets/WorldsPlayer/worlds.ini`** (the real 2026 installation, as
  the user left it): `upgradeServer=http://us1.worlds.net/3DCDup`.
  ⚠️ **Update (2026-09-09): this particular subdomain is NOT dead**
  — `us1.worlds.net` resolves to a real, live IP
  (`172.237.126.108`/`file.libreworlds.org`) and serves real, downloadable
  content (confirmed, not assumed — see this session's block further
  down). Section 1 remains correct about the apex domains
  `worlds.com`/`worlds.net` (parking page), but at least this
  infrastructure subdomain appears to be maintained or mirrored by the
  LibreWorlds community.
- **Hardcoded in the decompiled `.java`** (`Galaxy.java:678-679`): if the
  resolved server host is literally `www.3dcd.com:6650`, the client
  has a fallback to the fixed IP `209.67.68.214:6650` (probably a
  Worlds Inc. workaround for when 3dcd.com's DNS failed). Also
  appearing are `www.3dcd.com:25` (SMTP, not the game) and `time.worlds.net`
  (time sync, not the game either). This matches exactly what
  had already been seen in a real execution log (`Gamma.Log`, previous
  session): `AutoServer(www.3dcd.com:6650): lastError=VarErrorException`.
- **To test against `whirl` or WorlioWorlds**: `upgradeServer` in `worlds.ini`
  has to be edited (and probably `WorldServer`/
  `ScriptServer` in `override.ini`, as WorlioWorlds already does according to
  section 3.5) so they point at the test server instead of
  `worlds.net`/`3dcd.com`. The default port observed (`6650`) is a
  good starting point for comparing against the port `whirl` listens on.

### ✅ Phase 1 (RWX parser) complete and Phase 2 (renderer) started (2026-09-09)

Long autonomous session. Result: **118/118 real `.rwx` files of the
project parse identically** (vertex/triangle position) to
`three-rwx-loader` (the JS reference), and there is an LWJGL window painting that
geometry on screen for real (evidence in `docs/renders/`, not just "doesn't
crash"). All the new work lives in `client/src/net/openworlds/`
(new package, deliberately separate from `NET.worlds.*`, which is the
original decompiled code) and `tools/rwx-harness/`.

**Before writing the parser**: the comparison harness was set up first
(tool #3 of section 7) — `tools/rwx-harness/extract.mjs` runs the real
`three-rwx-loader` (headless via `jsdom`, installed with npm, not
vendored) and `client/.../RwxExtractMain.java` runs the new parser;
both emit the same canonical JSON and `tools/rwx-harness/compare.py` diffs
them, writing `docs/rwx-parser-progress.md` as the real (not assumed)
source of truth for the file-by-file status. The 118 test `.rwx` files
are the project's real ones (`assets/GROUNDZERO/` +
`assets/WorldsPlayer/GroundZero/tex/`) — no test content was
invented.

**The harness itself had 2 bugs that caused massive false positives**
before being fixed (documented in `tools/rwx-harness/compare.py`):
trusting the order of each side sorted as text (JS writes `"7e-05"`,
Java writes `"7.0E-5"` — a plain lexicographic sort silently desynchronizes them
even though the content is identical) and sorting with more precision
than the comparison tolerance (float vs. double can swap two adjacent
sort keys). Both were fixed by reordering with a numeric
key computed in Python. Before fixing them, the scoreboard
showed only 70/118 OK — most of those "differences" were not parser
bugs at all.

**A subagent (fork) was launched first to write
`docs/rwx-format-reference.md`** by reading the `three-rwx-loader` code —
it was interrupted midway (it drifted into building the harness instead of
documenting, useful work but not the assignment) and never wrote the
document. It was completed by reading the source code directly in the main
thread (the parser logic is explicitly outside what gets
delegated, per this session's instructions).

**Non-obvious findings, verified line by line against the real source
code (not the Active Worlds wiki, not assumptions)** — see
`docs/rwx-format-reference.md` for the full detail with line
numbers:
- `ModelBegin`/`ModelEnd` **do not exist** for `three-rwx-loader` — no
  regex recognizes them, they are pure no-ops. Only `ClumpBegin`/`ClumpEnd`
  matter.
- The vertex indices of `Triangle`/`Quad` are relative to a **per-clump**
  buffer that is cleared at `ClumpBegin` AND at `ClumpEnd` — not a global
  list of the file.
- `Transform` (16 values) is an **absolute set**, column-major (same as
  `THREE.Matrix4`, `v'=M×v`) — not a multiplication like
  `Translate`/`Scale`. The first version of the parser used row-major with
  `v'=v×M` (opposite convention) and gave subtly wrong geometry on
  files with non-trivial transformations, without any error — just
  slightly different numbers. The harness caught it; it would not have been
  obvious by eye.
- `ClumpBegin` freezes the accumulated transformation as the base of the clump and
  **resets the local accumulator to identity**; `ClumpEnd` restores the
  accumulator to what it was just before the reset. The material has the
  same scoping (clone stacked/restored per clump).
- `Rotate x y z angle` **is not an arbitrary-axis rotation** — it is
  up to 3 independent rotations about the cardinal axes (X, Y, Z in that
  order), each only if its coefficient is non-zero, by
  `coefficient × angle` degrees. Very easy to misread (that is how I
  implemented it at first, before reading the code).
- `Quad` splits along the **shorter** diagonal, not always A-C.
- **Comparing materials/colors is not reliable in this environment**: without
  real texture files (the corpus only has `.cmp`, not `.jpg`), the
  texture load fails and **also contaminates the base color** — all
  triangles come out flat gray `d8d8d8` in the JS reference,
  regardless of what the file declares. With
  `setEnableTextures(false)` the contamination is avoided but then the
  texture name is never registered, and the hex of `THREE.Color` does not
  match a direct `channel×255` conversion (suspected
  linear↔sRGB conversion, exact formula ⚠️ VERIFY, not identified).
  **Decision**: the material is an informational note in `compare.py`, not
  an OK/DIFERENCIAS ("differences") criterion — the geometry (100% verifiable) is the
  authoritative comparison.

**Not implemented / ⚠️ VERIFY, they do not appear in the 118-file corpus
so they could not be verified empirically**: `Polygon`
(implemented with the order reversal documented in the source code,
but with no real file exercising it), `ProtoBegin`/`ProtoEnd`/
`ProtoInstance` (not implemented at all), the special case of `Quad`
in wireframe mode and the invalid-normals correction of
`correctInvalidNormals`. `JointTransformBegin`/`JointTransformEnd`/
`IdentityJoint`/`Hints`/`AddHint` do appear a lot in the corpus (72+40+336
times) and are **verified as real no-ops** (`three-rwx-loader` does not
recognize them either).

**Renderer (phase 2)**: `client/src/net/openworlds/render/RwxViewer.java`
— LWJGL/GLFW window, fixed-function pipeline (`glBegin`/`glVertex`, no
shaders/VBOs yet), flat color per triangle from the parsed
material (no textures or light), camera that automatically frames the
model's bounding box, slow auto-rotation. Verified with real pixel
evidence (not just "compiles and doesn't blow up"): `BASKET.RWX` was rendered
and the color histogram of the resulting PNG was inspected —
it contains exactly the two material colors the file declares
(`0x893232` body, `0x338d2d` handle), not just the background color.

**Environment detail found and fixed**: this machine is a real Wayland
desktop session (`WAYLAND_DISPLAY` set) even though rendering happens
against a separate X11 Xvfb for testing — GLFW auto-detects and prefers
Wayland when it sees that variable, and fails right there (there is no real
compositor listening for this process). Fixed with an explicit
`glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11)` in the code,
instead of relying on unsetting the environment variable on every
invocation.

**New tools of this session** (all downloaded/installed
locally, need no system privileges, all gitignored):
`tools/node/` (portable Node.js v26.8.1, no `apt`/`dnf`), `tools/lwjgl/`
(LWJGL 3.4.3 from Maven Central — `core`/`glfw`/`opengl` modules + Linux
natives), `tools/rwx-harness/node_modules/` (`three-rwx-loader` +
`three` + `jsdom` via npm).

**Commits of this session**: `10840fe` (parser + harness), `caf1ccb`
(renderer).

**Next logical step**: two reasonable paths, to be chosen with the
user — (a) stay in phase 1 and tackle the binary RWG/BOD parser
(articulated avatars, more complex, binary format with no known JS reference
library — it would have to be documented from scratch or another
reference found), or (b) deepen phase 2: real textures (load the
project's `.cmp`/`.bmp`, not supported by `three-rwx-loader` either,
so here the `.cmp` format would indeed need to be documented from scratch),
basic diffuse/ambient/specular lighting already parsed and available in
`RwxMaterial`, and replace the fixed-function pipeline with a modern one
(shaders + VBOs) before it grows any more.

---

### 🟡 Permanent scope rule set (2026-09-09): faithful replica, not improvement

The user explicitly set, "from now on and forever in
this project" (see section 1): the goal is the ORIGINAL game
decompiled and ported — a faithful replica, nothing new, nothing improved.
RWG/BOD (avatars) ARE in scope (they were part of the original client).
Textures and lighting must look EXACTLY like the original RenderWare 2
(simple, no modern filtering) — never modern shaders, PBR, or
any graphics improvement whatsoever. **Permanent hard rule**: if at any
point there is doubt between "necessary fidelity" and "out-of-scope
improvement", STOP and ask the user — never decide unilaterally
in favor of "prettier".

### 🟡 RWG parser (avatars) — investigation from real bytes + partial implementation (2026-09-09)

**Real corpus used (not invented)**: at the start there were only 2 real
`.rwg` files (`assets/FIRST/{AVATAR,IDLE}.RWG`, both degenerate —
AVATAR.RWG is an empty placeholder box with `Float.MAX_VALUE` sentinels,
IDLE.RWG a single flat quad); midway through the session 3 more appeared inside
`GammaDocs.zip` (contributed by the user, folder `GammaTutorial/tex/`
— moved to `assets/gammatutorial-samples/` because they are real-format binary
data, not documentation, so they are versioned unlike
the rest of GammaDocs): `cube.rwg` — a real 6-face cube,
`ball.rwg` — a 512-triangle ball, and `table.rwg` — a table of
546 mixed polygons. **All 5 real `.rwg` files
have exactly one single joint/`ATOM` each** (verified
programmatically) — none is a real articulated avatar, they are
single-clump props/placeholders. The real bone hierarchy of an
articulated avatar (pelvis→torso→neck→head...) **still cannot be
verified with real evidence** — an honest limit of the available corpus,
explicitly documented instead of invented. In addition there are 26 real `.bod`
files in `assets/WorldsPlayer/cachedir/` (real avatars downloaded
over the network in a previous session, confirmed via `PendingDrone.java`) but
they use a totally different binary encoding (no ASCII tags) that
**could not be deciphered** this session.

With the 3 new files, the initial hypothesis for `PLST` (based on a
single polygon of IDLE.RWG) **broke and was corrected with real
evidence**: `cube.rwg` revealed that each polygon carries a face normal
`(nx,ny,nz)` (the 6 axes ±X/±Y/±Z appear exactly once on the 6
faces of the cube — impossible for it to be chance) and that the vertex
fields previously marked "undetermined" are actually the per-vertex
normal. The cube and the ball rendered successfully and look
correct to the naked eye (`docs/renders/{cube,ball}_rwg_3d.png`);
`table.rwg` was left unresolved because it mixes triangles and quadrilaterals
in the same `PLST`, breaking the assumption of uniform record size
— documented as a known limit, not forced.

**External research**: confirmed that there is no library or
public documentation describing this exact binary format —
`aw-sequence-parser` (Active Worlds) is an unrelated format (animation `.seq`,
different magic bytes), and the standard documented "RenderWare Binary Stream"
(used by GTA) is little-endian with numeric IDs,
structurally different from the big-endian ASCII tag scheme actually
observed here. The most valuable source was `Gamma_Advanced.html`
(official Worlds Inc. documentation contributed by the user this
session as part of `GammaDocs.zip` — see section 3.4 for the public
mirrors; the complete zip was NOT versioned in the repo, see the hygiene note
further below), which confirms the list of joint tag names/numbers and
the convention that joint matrices must always be identity —
the latter matches EXACTLY what was observed in real bytes.

**Repo hygiene note (2026-09-09, post-session)**: the initial commit
of this sub-session (`e591395`) had copied the complete `GammaDocs.zip`
into the repo (127 files, 5.8MB) instead of keeping only what is cited
above. Fixed: the complete HTML was taken out of the repo (it stays only local,
not versioned — the facts cited here are already paraphrased with
attribution, so the HTML is not needed to verify them; the public
mirrors in section 3.4 are the reference if it ever needs to be consulted
again), and the 4 real binary corpus files that were in fact needed
(`cube.rwg`, `ball.rwg`, `table.rwg`, `table.rwx`) were moved to
`assets/gammatutorial-samples/`. The commit was split into smaller,
reviewable pieces (parser / renderer+screenshots / docs+corpus) — see
`git log` for the exact detail instead of duplicating it here.

**What was verified and implemented** (`client/src/net/openworlds/rwg/`,
`docs/rwg-bod-format-reference.md`): chunk container
`[ASCII tag][big-endian length=payload size][payload]` verified
byte-exact against the 2 real files; structure `CLUM`→`ATOM`→
`MATX`(x2, identity)+`VLST`(vertices)+`PLST`(polygons); 44-byte/11-float
vertex layout with position (high confidence) and UV
(medium confidence) identified; one real polygon decoded and
**rendered successfully** (`RwgViewer.java`, real screenshot
verified by pixels) — in the process it was discovered that the index
order of a quad is grid order (TL,TR,BL,BR), not a perimeter loop (a
naive fan-triangulation gave an incorrect concave shape, fixed).

**What remains ⚠️ VERIFY / unresolved**: most fields of the
52-byte `ATOM` header; the exact purpose of `RALT`/`TELT`/`MALT`
(although `TELT` was found to contain a `STNG` sub-chunk with the
object's name as a string); fields 3-5 and 8-10 of the 44-byte vertex;
whether the multi-joint hierarchy nests `ATOM` inside `ATOM` or lists them
as siblings (no real evidence of any kind); and the complete
`.bod` format (only a constant 6-byte magic prefix was confirmed).

**Next logical step**: to really unlock the joint hierarchy and
`.bod`, the `gamma.dll` function that reads `.bod` would have to be
disassembled with Ghidra (same level of effort as the mapping of `native`
methods in previous sessions) — it is not "keep reading bytes
with more patience", the available real corpus has run out. Cheaper
alternative: keep searching for any real `.rwg`/`.bod` file with
more than one joint in other copies of the client or in the community
(LibreWorlds/kangworlds) before investing in disassembly.

---

### 🟡 Repo hygiene (2026-09-09, between sessions): separate commits + push

Before continuing with the engine, the repo state was cleaned up (explicit
request from the user, see full findings in the "repo hygiene" block
earlier in this same section): `cachedir/{.LOG,.lst,
cache.index}` untracked (download bookkeeping noise, not
geometry — the real `.bod`/`.seq`/`.mov`/`.cmp` files ARE still
versioned), the complete `GammaDocs/` removed from the repo (127 files,
5.8MB, most never cited — only 4 real binary corpus files were
needed, moved to `assets/gammatutorial-samples/`, and the
text of `Gamma_Advanced.html` was already paraphrased with attribution in
`docs/`), and the original commit of the RWG session was split into 3
reviewable pieces (parser / renderer+screenshots / docs+corpus). With `origin/main`
14 commits behind, everything was pushed (SSH authentication
set up by the user midway through the session).

### 🟡 Rendering engine — textures investigated, lighting and
### materials implemented and verified, multi-object scene (2026-09-09)

Scope rule reaffirmed at the start of this session, permanent for the
rest of the project: faithful replica of RenderWare 2's fixed pipeline — no
modern shaders, no PBR, no graphics improvements of any kind. Everything
below uses `glLight`/`glMaterial`/`glBegin`-`glEnd` (real fixed-function
pipeline, not a modern reinterpretation).

**1. `.cmp`/`.mov` textures ("ScapePic") — investigated in depth,
NOT fully resolved, the real limit documented**
(`docs/cmp-texture-format-reference.md`). Real disassembly with Ghidra
(same `gamma.dll` binary as in previous sessions) until identifying that
the compression core (an internal function literally called
`huffdcod`) is structurally identical, variable by variable, to the
public, well-documented `make_table()` algorithm of the LHA/LZH family
by Okumura/Yoshizaki — but the real loop that consumes the compressed
bitstream (the piece that would turn the already-built Huffman tables
into real pixels) was never located. Corroborated with external
research: `github.com/vanjac/zoomscape-info` documents the same
`LzH2` header and also marks it as "unknown compression scheme" — nobody else
has solved it publicly either. Scope decision: do not force the
rest of the disassembly (effort of the same order as `.bod`) at the expense of
the rest of the session; the materials pipeline uses the material
color/opacity ALREADY verified, without rendering any texture or inventing
pixels.

**2. Lighting — real model found in pure Java, without needing
Ghidra**: `NET.worlds.scape.Room.java` has the real default values
(`lightPosition = (-1,1,-1)`, `lightColor = white`) and
`RoomEnvironment.addLight()` confirms **exactly 2 lights per room**
— a "key" and a "fill" in the opposite direction at half
intensity. Implemented in `GlLighting.java`, verified with a capture +
color histogram: the single flat color of `BASKET.RWX` (previous
session) now shows ≥6 real tones depending on the orientation of each
facet (`docs/renders/basket_lit.png`).

**3. Materials pipeline — verified with 2 different real
files**: opacity wired to real alpha blending; `MaterialModes
Double` (new finding, real usage confirmed in
`assets/GROUNDZERO/YARD_TABLE.RWX`) wired to double-sided culling —
verified visually: the underside of the table is visible from below, something
impossible without double-sided active (`docs/renders/table_lit.png`).

**4. RWG with lighting**: uses the real per-vertex normal already parsed
from the format (not recalculated). A real data problem was found and fixed
(`cube.rwg`: the 8 "flat" vertices without UV have normal
`(0,0,0)`, a filler value that breaks `GL_NORMALIZE` — a
fallback to the computed face normal was added). ⚠️ One unresolved artifact
remains: 2 of the 6 faces of the cube show a z-fighting-like pattern;
enabling backface culling was tried as a diagnostic and made it worse (holes),
confirming that the winding direction is not consistent between faces in
the real data — documented, not forced (`docs/render-pipeline-reference.md`).

**5. Multi-object scene** (step 4, "if time allows" — it did
make it): `RwxSceneViewer.java` loads and renders together 6 real objects
from `assets/GROUNDZERO/` (basket, can, bottle, tongs, cactus, grill),
in a grid sized by their own real bounding boxes
— verified by capture, all 6 look properly lit,
positioned and non-overlapping (`docs/renders/scene_multi_object.png`).

**Commits of this session**: `a3d801d` (`.cmp` investigation), `bcabf31`
(lighting + materials), `2aa35c0` (multi-object scene), plus 4
repo hygiene commits before starting (`f66f9dc`, `de059b0`,
`7066c30`, `b3c4608`). Everything pushed to `origin/main`.

**Next logical step**: two reasonable paths — (a) resume multi-joint RWG/BOD
or the rest of the `.cmp` decompressor (both need
dedicated disassembly with Ghidra, same order of effort), or (b)
keep deepening the engine: replace the fixed-function pipeline with
VBOs/shaders **that replicate exactly** the same visual result (a
performance optimization, not a graphics improvement — within scope
if done carefully), resolve the RWG winding artifact, or
try to load a scene from a real `.world` instead of loose
`.rwx` files.

---

### 🟡 `.cmp`/`.mov` — decompression loop located precisely,
### still without enough clarity to implement (2026-09-09, session 2)

Picked up exactly where the previous session left off (scope rule
reaffirmed: the decompressed pixels must look EXACTLY like the
original, with no filtering/upscaling — does not apply yet because there are no
real pixels to show, see below). Returned to `gamma.dll` with
Ghidra and got much further than the previous session:

- **Exact function located**: `FUN_00442bc0` (= `getScanline(row,
  destBuffer, stride)`) calls `FUN_00426af0` (bit-level Huffman
  decoder, classic LHA `decode_c()` pattern) and then
  `FUN_00457d88` — the latter IS the function that really reconstructs pixels,
  the piece that was missing in the previous session.
- **Pixel format confirmed with real evidence**: 8 bits per pixel,
  indexed palette, rows aligned to 4 bytes, written with a negative stride
  (bottom-up, typical of a Windows `HBITMAP`/DIB — matches
  the real use of `CreateCompatibleDC`/`HBITMAP` already seen in previous
  sessions).
- **2D predictor table extracted directly from the binary**
  (`docs/gamma-dll-cmp-evidence/predictor-offset-tables.txt`, ~50 real
  pairs `(row_offset, column_offset)`): reveals that the
  algorithm is a **2D causal predictor** (each Huffman symbol
  selects an already-decoded neighbor and copies its value — closer to
  the PNG/JPEG-LS filters) and NOT generic sliding-window LZSS as had been
  assumed in the previous session — a real correction based on evidence, not
  merely an initial hypothesis confirmed.
- **The 256 indirect function pointers that seemed to suggest 256
  different complex routines turned out to be trivial** once
  disassembled: each one only reorders/replicates a byte in different
  register positions — the manual 90s trick for filling
  runs of repeated pixels 4 bytes at a time. No real
  algorithmic complexity there.

**The decoder was not implemented**: the exact carry arithmetic
(`CARRY4`) and the purpose of the simultaneous two-row write inside
`FUN_00457d88` were not understood with the clarity needed
to translate bit by bit with confidence. Following the user's explicit
instruction not to force a half-baked implementation or risk
invented pixels with a plausible but incorrect appearance, I stopped here and
documented everything with real evidence (`docs/cmp-texture-format-reference.md`,
section "Session 2"). Steps 3-5 of this session's plan (implement,
verify against a real `.cmp`, connect to the materials pipeline)
were not reached as a direct consequence of this honest decision, not
for lack of effort — 3 rounds of disassembly with Ghidra were done
this session (final loop, predictor table, table of 256 pointers).

**Next logical step**: trace the execution of `FUN_00457d88` step by
step with a debugger against `gamma.dll` running under Wine (instead of
only reading static Ghidra pseudocode) to resolve the bit/double-row
ambiguity; once clear, the Java implementation of the
already-identified 2D causal predictor should be relatively straightforward.

---

### 🟢 `.world` — complete parser, connected to the engine, real scene
### rendered (2026-09-09)

Session in the same spirit as RWX/RWG: find the real file first
(confirmed: `GroundZero.world`, 205,759 bytes, 3 identical copies,
default world according to `worlds.ini`), investigate the format with the
best available evidence, implement, and verify with real data —
in this case with an enormous advantage over RWX/RWG/`.cmp`: **the
serialization mechanism itself IS complete in the decompiled Java**, there is
no need to touch anything native.

- **Format investigated and documented** (`docs/world-format-reference.md`):
  it is not an ad-hoc binary, it is the client's generic "Persister"
  protocol (`Saver`/`Restorer`), verified byte by byte against the real
  header (`"PERSISTER Worlds, Inc."` + version 7) and against ~30
  real classes of the source code (`SuperRoot`, `Transform`, `WObject`,
  `Shape`, `Room`, `RoomEnvironment`, `Rect`, `Portal`, `Material`,
  `Point3`, plus the `Action`/`Sensor` families). Position/rotation/scale
  of each object are stored as a full 4×4 matrix of 16 floats
  (RenderWare's native "guts"), directly reusing the already existing
  RWX matrix infrastructure.
- **Parser implemented and verified end-to-end**
  (`client/src/net/openworlds/world/WorldRestorer.java`): parses the
  complete real file, with no errors, up to the real marker
  `END PERSISTER` — 25 rooms, 578 nodes, 103 objects with real geometry
  (50 unique `.rwx`/`.rwg` files, all verified against real files
  on disk). 4 real bugs were found and fixed during
  the implementation (documented with byte-by-byte evidence in the doc):
  the distinction between `Material.restore()` (with a preceding boolean) and a
  direct `var1.restore()` (without it) misapplied in 3 different places;
  `WObject` appearing as an instantiable concrete class, not just as a
  superclass; and the inheritance chain of `SendURLAction`/`DialogAction`
  inverted.
- **Connected to the rendering engine**
  (`client/src/net/openworlds/render/WorldViewer.java`): loads a real
  room, resolves the geometry URLs against real files on disk,
  and draws the complete tree with the already existing lighting/materials
  pipeline. **Critical real finding**: the 16-float matrix read
  from the file is not a valid affine matrix as is — its float number 16
  (which should always be 1.0) is literally 0.0 in all the
  real objects inspected, collapsing the homogeneous coordinate and
  leaving the screen completely black even though the geometry was
  being sent to OpenGL without errors. Diagnosed by methodical elimination
  (lighting, culling and depth precision were ruled out before
  finding the real cause by projecting a vertex by hand in Python) and
  fixed by forcing that value to 1.0.
- **Verified with real visual evidence**: `Reception` shows a clean,
  recognizable hexagon (the real ceiling panel
  `hubceil1c.rwx`) plus the thin edges of `frame.rwx` (already verified
  separately to be genuinely thin geometry, not an error);
  `IconViewRoom1` shows a row of decorative posts correctly
  spaced, with no absurd overlaps — captures in
  `docs/renders/world_*.png`.
- **Performance**: 7148 triangles / 56 objects in immediate mode
  (`glBegin`/`glVertex`, no VBOs) render in a trivial fraction of
  the ~4 seconds total execution time (dominated by JVM/GLFW/X11 startup
  and loading 28 RWX files, not by the drawing itself) — there is no need
  to optimize at this scale.

### ✅ Session 2 (2026-09-09): the 3×3 block bug solved — it was not the
### convention, it was uninitialized padding bytes

The complex room (`ReceptionView1`) that was left broken at the end of the
previous session was investigated by going back to the real Java code (not
guessing mathematical conventions). Two findings in
`Transform.java` that had not been looked at before:
`Transform.printGuts()` (a real debugging method, non-native)
confirms **row-major** storage (`index = row×4+column`);
`Transform.worldVecToObjectVec()` uses `point.vectorTimes(matrix)` —
confirms that the vector is multiplied on the left (`v' = v·M`, not
`v' = M·v`). With that evidence, the mathematical deduction shows that
**nothing needs to be transposed** to pass the 16 raw floats to
`glMultMatrixf` — which explains why transposing (previous session)
made things worse: it applied the wrong convention.

The real cause of `ReceptionView1` turned out to be something else: indices 3, 7 and
11 of the matrix (which in any valid affine matrix must
always be `0.0`) contained numeric garbage consistent per object (not
random noise — an object shared between `Reception` and
`ReceptionView1` showed exactly the same garbage values in
both rooms). An automatic scan confirmed why some rooms
looked fine and another did not: `IconViewRoom1` had 0 affected objects,
`Reception` 1 (small, almost invisible), `ReceptionView1` more than 15.
Most plausible interpretation: RenderWare's native "guts" is actually
a compact 4×3 affine matrix, extended to 16 floats for the
Java save format, with the padding column serialized
directly from uninitialized native memory — the real renderer
never read it. Fix: also force those 3 indices to `0.0`
(in addition to index 15→`1.0` already fixed earlier).

**Verified before/after in the 3 rooms** (`docs/renders/world_*_fixed.png`):
`IconViewRoom1` stays identical (the fix is surgical); `Reception`
gains a small, correctly positioned object that previously had garbage
data; `ReceptionView1` goes from degenerate giant triangles to
recognizable real objects — and verified with data, not just
visually: the world positions of the 56 objects make real
geographic sense (picnic furniture grouped together, cacti/rocks scattered,
a path, walls of a building) in a genuinely
extensive outdoor area, not an artifact.

**Next logical step**: resume `.cmp`/multi-joint RWG, which remain
pending from previous sessions; or keep exploring more rooms of the
real `.world` to see whether any other case not covered by these
two matrix fixes shows up.

---

### 🟢 Articulated avatars: a real 18-joint rig found and verified
### (RWX, not RWG) + `table.rwg` fixed in passing (2026-09-09)

Session goal: advance on real multi-joint avatars. Mandatory first
step per explicit instruction: look for more real `.rwg`/`.bod` corpus
before going further. **Exhaustive search confirmed negative**
— still the same 5 `.rwg` (all with a single `ATOM`) and 26
undeciphered `.bod` from previous sessions; nothing new showed up in
`assets/WorldsPlayer/`, cachedir, or `GammaDocs/` on disk. A subagent
also confirmed that the decompiled Java client does not expose any
bone structure (`PosableShape.java` only has appearance/clothing
permission tables, no skeleton — the articulated part lives entirely in
native `gamma.dll`).

**Productive pivot, not the planned fallback**: rereading
`assets/WorldsPlayer/cachedir/45.dat` (the real animation registry,
found in a much earlier session) reminded me that real network avatars
declare `geometry=<name>.rwx` — the SOURCE format of an avatar
is text RWX (via the official `rwxtobod` tool), not `.rwg`. Searching for
joint names from the official GammaDocs convention
(`pelvis`/`lfshoulder`/`rthip`/`lfelbow`...) in the 119 real `.rwx` files of the
project turned up **`assets/GROUNDZERO/SPIN.RWX`** — already present in the
project, used in an earlier session as a decorative prop without knowing that
it was a real articulated rig. It is a **rig of 18 named clumps with a
real parent/child hierarchy**, verified with byte-by-byte evidence
(line numbers of `ClumpBegin`/`ClumpEnd`/`# name` comments) and with
the 18 names matching exactly the official GammaDocs table.
Interesting real detail, not "corrected": `rtfingers` nests as a child
of `lffingers` in the real bytes (anatomically odd, but it is what the file
says). See `docs/rwx-avatar-hierarchy-reference.md` for the complete
tree and all the evidence.

`RwxSkeletonParser`/`RwxJoint` were implemented (new, **without touching**
`RwxParser.java` — the flattened 118/118-verified parser stays intact) —
they reuse exactly the same already-verified transform/clump rules,
but preserve the tree instead of flattening it. Verification in three layers:
(1) structure — it reproduces exactly the 18-node tree reconstructed by
hand; (2) geometry — compared against the 119 real `.rwx` files of the
project, the set of world-space points produced by walking the
tree (`parent.world × joint.localTransform`) is **identical** to the one
produced by the already-verified flattened parser, in 119/119 files, not just
`SPIN.RWX`; (3) visual — `SPIN.RWX` rendered with `RwxViewer` gives a
coherent figure (legs, hip, torso, head recognizable, no
geometric garbage) — `docs/renders/rwx_spin_avatar.png`.

**Honest limit**: this is source geometry in bind pose, not the real compressed
`.bod` that the client downloads/animates over the network (Ghidra on
`gamma.dll` would still be needed, as with `.cmp`) and there is no
reconstructed animation — no invented bone/animation system, per the
scope rule of this session.

**In passing, revisiting `table.rwg` with the accumulated experience** (explicit
task of the session): the bug was resolved. The old assumption
("uniform record size, derived by dividing the total payload by
the number of polygons") was never needed — each `PLST` record already
declares its own `vertexCount`, which is read directly. The only thing
that had to be resolved was how many trailing ints follow each record, which
is constant but PER FILE, not per record — it is resolved by trying
small candidates until the sequential read (using the
real `vertexCount` of each record, without assuming uniformity) closes exactly
on the final byte. With this, `table.rwg` (546 polygons, verified real mix
of triangles and quadrilaterals) parses cleanly and renders a
coherent table (`docs/renders/rwg_table_fixed.png`). Side effect: a
previous claim in the RWG doc was corrected — the first field of each
`PLST` record, documented as "flag, always 1", is actually NOT
constant (in `ball.rwg`, 512 records, it counts 1..512) — see
`docs/rwg-bod-format-reference.md` for the full detail.

---

### 🟡 `.cmp` — real dynamic debugging built and verified, but
### blocked by infrastructure before reaching the pixel decoder
### (2026-09-10)

Session goal: resolve the pending ambiguity of `FUN_00457d88`
(carry arithmetic + double-row write) through real dynamic
debugging of `gamma.dll` under Wine — no more static analysis.

**Achieved**: a real, reusable dynamic debugging environment —
Wine 11.0 + `winedbg --gdb` (real gdb connected via proxy) + a clean-room
Java harness (`tools/gamma-dll-debug-harness/`) that directly invokes
the real `native` methods of `gamma.dll` under the project's own
era-appropriate JRE (`java.exe` 1.4.2_05), without needing the full client or network.
Confirmed with live execution (not just static): a breakpoint at
`FUN_00442750` (header validator) is hit when calling `loadImage()`
with a real `.cmp`, and an instruction-by-instruction dump with real
registers shows the function really opening and reading the file
(`ReadFile` against real bytes). Real methodological correction: the
symbol names that `gdb`/`winedbg` show for `gamma.dll` are **not
reliable** (an address confirmed by Ghidra as `FUN_00442750`
appeared labeled as a completely different and unrelated
export) — addresses must be verified against Ghidra directly,
never against the `gdb` label.

**Blocked, honestly unresolved**: any execution path
that goes from header parsing to the real pixel decoder
(`FUN_00442bc0`/`FUN_00457d88`) triggers the creation of a DirectDraw/OpenGL
device and a real window, which in this specific environment (Wine
under Xwayland in a sandbox, with no graphics acceleration) hangs
indefinitely (tested up to 150s, with and without a debugger, with reasonable
mitigations such as killing the leftover `wineserver` and Wine's virtual
desktop mode — none worked). Real evidence that it is a
device/window startup problem of this environment, not of the algorithm of
`gamma.dll`: an asynchronous interrupt during the hang showed a thread
waiting on Wine's loader critical section, held by another
thread. The decoder was not implemented (that would have meant inventing
the unverified part) nor was anything connected to the materials pipeline — there is no
real decoder to connect yet. Full detail, with the harness
reusable and documented for a future session with better access to
GPU/windows, in `docs/cmp-texture-format-reference.md` and
`tools/gamma-dll-debug-harness/README.md`.

---

### 🟢 `.cmp` — Xvfb unblocks the window/device hang; the two
### ambiguities of `FUN_00457d88` are resolved with real execution
### (2026-09-10, continuation session)

Goal: unblock the window/device hang from the previous session
using Xvfb (just as was done several sessions ago for Swing's
`HeadlessException`) and, if that worked, resume debugging
`FUN_00457d88` with real values.

**Unblocking achieved with the first option tried**: `Xvfb :99
-screen 0 1024x768x24` + `DISPLAY=:99` for Wine — **without any window
manager** (none was needed nor available in the environment). With
this, `ScapePicImage.loadImage()` on a real "normal" `.cmp` (mode
`0x02`, `ADWORLDS.CMP`) finishes cleanly and returns **a real,
successful decode** (`width=128, height=128, hDIB` non-null) — the first
in all the sessions of this project. The three already-located breakpoints
(`FUN_00442750` → `getScanline` → `FUN_00457d88`) are all three hit, in
order, within that single call — `makeTexture()` turned out not to be
needed after all (that harness still fails, but because of a
fidelity problem of the minimalist harness — a native assertion during
`nativeInit()` — unrelated to the already-resolved window hang).

**The two ambiguities that motivated two sessions of work are
resolved with real execution evidence** (900-instruction trace,
with `EFLAGS` and the 8 general registers at every step):

- **"Carry arithmetic"**: zero real `ADC`/`SBB` instructions in
  the entire trace. It is the classic MSB-first Huffman/LHA
  bit reader (`add reg,reg` + `jb` on the carry flag), with a
  preceding `rol $0x10` to fix the byte order of a word
  read as little-endian — no multi-word arithmetic at all.
- **"Double-row write"**: confirmed with the exact addresses
  of both symbol paths (fill and predictor copy) — each
  symbol writes the same 4-byte block to the current row (`edi`) AND
  to `edi±stride` at the same time, as the symbol's core operation (not
  scratch cleanup). Most consistent interpretation: each symbol
  paints a 4×2 pixel block at once, exploiting vertical
  coherence.
- **Bonus, cross-confirmation between two sessions**: the real predictor
  table that `FUN_00457d88` uses at runtime was dumped and
  matches EXACTLY the static table already extracted in an earlier
  session (`0x478e98`), with the conversion formula corrected
  (`offset = colDelta + stride·rowDelta`, not with the sign negated as had
  been tentatively documented before).
- **Real ground truth captured**: the complete row 0 of `ADWORLDS.CMP`
  (128 real bytes, all `0xAD`) — saved in
  `docs/gamma-dll-cmp-evidence/adworlds-row0-dump.txt` to verify a
  future Java implementation.
- **Granularity correction**: a trace extended to 6000
  instructions without seeing a single `ret` or a re-entry into the function indicates
  that **a single call to `FUN_00457d88` decodes the COMPLETE
  image**, not a row — consistent with `getScanline` being invoked
  only once per image.

**Honestly not yet implemented**: the complete symbol space
of the internal Huffman tree is not mapped (only the
branches that a completely flat row happened to touch were exercised) and the
sentinel byte `0x24` seen in the trace was not investigated. Implementing the Java
decoder now, with those gaps, would risk exactly what the project
forbids — pixels with a plausible but unverified appearance. That is why
nothing was implemented or connected to the materials pipeline this session;
concrete next step documented in
`docs/cmp-texture-format-reference.md`: trace 2-3 real `.cmp` files
with non-flat content to exercise the rest of the symbol tree
before writing the decoder.

---

### 🟡 `.cmp` — complete symbol tree mapped, `0x24` resolved,
### Java decoder implemented and partially verified (34/64 and 55/64
### exact bytes) — NOT connected to the pipeline (2026-09-10, closing)

Goal: close `.cmp` entirely — exercise the symbol tree with
varied real files, implement the decoder, verify byte by byte,
connect to the pipeline.

**Varied corpus found**: Shannon entropy as a cheap filter
confirmed that `ADWORLDS.CMP` (5.0) was degenerate compared with the rest of the
13 unique `.cmp` files of the project (7.0-7.8) — `4i.cmp` selected as a real
non-flat case (row 0 with 9+ distinct byte values). The 5 candidates
tested decode successfully under Xvfb.

**Complete symbol tree mapped with real evidence**: a
4000-instruction trace on `4i.cmp` revealed 236 addresses never seen in
the previous session (which had only seen the flat fill case). The
real top-level tree has 2 bits (not 3): bit1=0 → 4-byte predictor copy
(already known); bit1=1,bit2=0 → **DUAL 2-byte predictor copy**
(new, two independent indices per group half); bit1=1,
bit2=1 → "control byte" branch with several literal/
lookback sub-cases. **`0x24` resolved** (fresh static disassembly from Ghidra):
it is not end of stream, it is a **raw 8-byte literal escape**.
Unanticipated real finding, found while debugging the first
failed verification attempt: each non-`0x24` "control byte" iteration
ALSO consumes an additional byte from the fill stream and does a
second broadcast write to the history — invisible in the flat
file of the previous session because it matched what was already there.

**Real granularity correction**: the previous session inferred "one
call decodes the complete image" from not seeing a `ret` in 6000
instructions. With a real breakpoint at the return address
(computed from `*esp`, not guessed), it is confirmed: **one call
produces exactly `ch×2` bytes** (64 for the files tested, half a
128px row width) — neither a row nor the complete image.

**Java decoder implemented** (`tools/gamma-dll-debug-harness/
cmp-stage2-decoder/CmpStage2.java`), verified against real streams and output
extracted live from the SAME process: **34/64 exact bytes in
`adworlds.cmp`** (the rest explained by a real memory-capture
limitation, not a design error — each missing byte should be
`0xAD` like the rest of the flat file) and **55/64 in `4i.cmp`** (9 bytes
unresolved despite exhaustive verification of stream consumption
position by position against a live trace — open, honestly
documented). **Nothing was connected to the materials pipeline** — no
file reached 100% verification, and the project explicitly forbids
pixels with a plausible but unverified appearance.

Additional real progress in `ScapePicTexture.makeTexture()` (needed
to decode a complete image): the failure point was advanced from an
`Assertion failed` to a real `EXCEPTION_ACCESS_VIOLATION` by replicating the
class hierarchy with more fidelity, but it remains unresolved.

Full detail, with the ground-truth capture method and the analysis
of the remaining discrepancies, in `docs/cmp-texture-format-reference.md`
and `tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md`.

---

### 🟡 `.cmp` — pixel-exact ground truth from the official tool, the
### incomplete-capture hypothesis discarded, bug narrowed to one branch
### (2026-09-10, continuation: new external resources — NOT closed)

Goal of point 1 of this session: use `compimg.exe`/`cmpview.exe`
(official, in `tools/gdk-sdk/`, run natively under Wine without any 16-bit
workaround) to close `.cmp` with much stronger verification
than the earlier partial traces. **Full closure was not achieved**
— project rule respected: it is not considered resolved without
real verification, and here the real verification says it is still open.
What was achieved is substantial:

**New ground truth, strictly stronger**: `test4b.bmp`/`.cmp`
(`assets/gammatutorial-samples/`) — a 32×32 test image,
self-designed and totally known (4 solid quadrants: red, green,
blue, yellow), compressed with the real `compimg.exe`. Verified TWICE
against the official tool: visually with `cmpview.exe` under
Xvfb, and **at the byte level** by hooking the live `cmpview.exe` process
via `/proc/<pid>/mem`, locating its real GDI pixel buffer (a
Wine SYSV shared memory segment, genuine 32bpp BGRA) and
reading the decoded pixels directly: **exactly 256
pixels of each expected color, zero noise**. This replaces the
screenshot/RMSE check of the previous session with real
byte-exact ground truth.

**The hypothesis of "memory capture limitation" (see the previous
section) is discarded with real evidence, not merely reaffirmed**:
`cmp_capture.py` was rewritten so as not to stop after the first call to
`FUN_00457d88` and to capture each real call with its own genuine
memory snapshot. Result: `test4b.cmp` makes only **one** real call
(the theory "needs ~4 calls, we only captured 1", derived from the
arithmetic `outerCount·2·stride`, was incorrect). Feeding the decoder
with the real captured memory (instead of zeros) gave a
**byte-identical** result to seeding with zeros — because the process's real memory
at the read address that fails is **also** `0x00` there.
The capture was never the problem.

**Bug narrowed down precisely** (branch tracing against the real output
captured per iteration): pass 0 decodes correctly up to
iteration 4. It fails specifically at **iteration 5, `DUAL` branch,
second predictor pair, `idx2=32` → `PRED_TABLE[32]=256`** (a
large offset): the real value is `62`, the decoder produces `0`. Small/nearby
offsets (e.g. `idx=3`, offset `-4`) always decode fine
whenever they are used, even earlier in the same iteration — only the
large-offset entries fail, and that desynchronizes the rest of the bitstream (crash
at pass 8, index 63 of a 50-entry table).

**State after a third round — one real bug fixed, another deeper
one found underneath (still not closed)**: disassembling
`FUN_00457d88` directly (instead of trusting a comment from an
earlier session) showed that `PRED_TABLE` **is not a fixed table** — it is
built at runtime from the current `stride`
(address `0x00482d0d`, not `0x00478e98` as the old
comment said). The existing table had been captured live only for
128px files (`stride=-128`) and was wrong for any other
stride — exactly the bug that broke `test4b.cmp` (32px,
`stride=-32`) from `idx=32` onward. Fixed by reading the real table
for two different strides (-128 and -32) and solving
`off = colDelta + stride·rowDelta` — all 50 entries gave a clean
integer solution, with no remainder. **Real result: 23/141 → 86/141
matches**, ~3.7× improvement, reproduced cleanly.

With that bug fixed, a live branch census against the complete real
execution (`evidence_2nd_session/branch_census.log`) revealed a
**second, deeper bug**: the real process takes the `SINGLE` branch 124
times and `CTRL` 4 times — `DUAL` **zero** times, in the whole file. The
Java decoder takes `DUAL` five times in pass 0 alone. The bug is no longer
in the predictor table (that part is now correct) but higher
up, in `shiftBit()`/`refillWord()` or the `bit1`/`bit2` dispatch — the
decoder's bit reader decides on branches the real code never takes
for this file. **Still not closed** — concrete next step for
a future session: find where the bit reader starts to
disagree with the real one about which branch to take (no longer about which offset to use).
Four rounds of accumulated real evidence, zero invented data at
any point. Full detail in
`tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md`.

### 🟡 `.cmp` — LINE A (parallel continuation, 2026-09-10):
### `test4b.cmp` byte-exact (256/256), real texture `rustwood.cmp` at
### 99.37% — three more real bugs found and fixed, still not
### fully closed

**Bug found in the capture tool itself, not in the
decoder**: `cmp_capture.py` always read the `AL` byte of `eax` at each
watched write point. The real disassembly shows that
`SINGLE` does use `rol eax,8; mov [esi(+1)],al` (AL correct there), but
`DUAL` writes with `mov [esi],ah` / `mov [esi+1],ah` — **no rotation,
and the wrong register**. Every "ground truth" byte captured in every
`DUAL` branch of the three previous rounds was, silently,
incorrect. Invisible until now by pure luck: no file
tested in rounds 1-3 ever took a real `DUAL` branch (confirmed
separately via the branch census). Fixed: `WRITE1` now carries
`(byteslot, register)` pairs.

**The second real bug, found and fixed**: every "consume
a bit" point in `FUN_00457d88` has a reload check (`je [refill]`)
guard **except the `bit1` test itself** — it has none.
When the last live bit of the register is consumed right there, the real
hardware does NOT reload immediately: it leaves the register at a literal `0`
and defers the reload to the next watched point, which (when shifting
a register that is already zero) produces a genuine "false 0" bit before its
own reload fires. The old `shiftBit()` always reloaded regardless of
the call point, silently discarding that false bit and
desynchronizing every subsequent read by exactly one position —
which is precisely why the decoder took `DUAL` branches that the real process never
took. Fixed with a new `shiftBit1NoRefill()`, used only at that
point. Found with a live branch trace against `rustwood.cmp`
(varied real content — the flat quadrants of `test4b.cmp` never
stepped on this edge case, which is why round 3 did not see it).

**A third bug, only detectable with varied real content**: the
"fill broadcast" of the control-byte path had been assumed
to be "replicate `al` four times" by a much earlier session that
statically read a couple of handlers — a conclusion that no file tested so far could falsify
because their literal byte pairs
always had `al == ah`. The live register tracing
against `rustwood.cmp` (`al != ah` there) showed that the byte
`fillIdx` is actually an **8-bit mixing mask**: each bit
independently chooses `ah` or `al` for one of 8 output byte
lanes. Confirmed exactly, all 8 bits, in 3 independent
live samples. Fixed.

**Result, against real output captured per pass**:
- **`test4b.cmp`: 256/256 — 100%, byte-exact.**
- **`rustwood.cmp`** (real 128×128 texture, not synthetic):
  **4070/4096 — 99.37%**, up from 403/4096 at the start of this round. The only
  mismatch reviewed by hand was resolved in favor of the decoder against a
  **fresh, independent live memory read** (without going through
  the decoder or the capture CSV) — evidence that the remaining ~1.6%
  are further artifacts of the capture tool, not decoder
  bugs, although not proven byte by byte.
- **`sball.cmp`** (third real file): **2709/4096 — 66%**, captured
  again with the corrected tool. The same verification pattern
  was repeated once and also favored the decoder, but this file
  diverges earlier and more often — **unresolved with certainty**.

**Not connected to the materials pipeline this round**: `sball.cmp` does not
have the same confidence as `rustwood.cmp`, and this very round
showed that a flat-color synthetic file can hide real bugs
that a varied file does expose — the project rule against
plausible-but-unverified pixels still applies. Concrete next step:
chase the rest of `sball.cmp` with the same live verification
method. Full detail in
`tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md`.

---

### 🟢 Render — shared helpers, ALL/list-rooms mode in WorldViewer,
### pixel-identical display lists (2026-09-10, two small advances)

Scope rule respected throughout: fixed-function pipeline only, zero visual
changes — each step verified pixel by pixel against previous captures,
not just "compiles and doesn't blow up".

**Advance 1 — `GlUtil` + multi-room `WorldViewer`**
(`client/src/net/openworlds/render/GlUtil.java`, new):
- `perspective`/`lookAt`/`saveScreenshot` were duplicated byte for byte
  in the 4 viewers — extracted to `GlUtil` (`lookAt`/`perspective` are
  the already-documented GLU replacements, same textbook formula).
- `WorldViewer` gains `--list-rooms` (25 rooms, sorted) and
  `ALL [--screenshot-dir dir]` (renders all 25 in one go as
  `world_<room>.png` + per-room statistics). In addition the
  `loaded/missing/avatar-skip` counters were accumulated across rooms and were confusing —
  now they are per room (delta before/after `preload`).
- Verified under Xvfb, GL error 0 throughout: `Reception` 12 obj/96 tris
  (identical to before), `ALL` 25/25 processed. `IconViewRoom1a–g` turn out
  to be avatar pedestals (`Drew 0`, only `avatar:` refs skipped —
  honest, no avatar invented). New evidence:
  `docs/renders/world_lizcave.png` (`LizCave`, 5 obj, 450 tris, 73 colors).

**Advance 2 — display lists in `WorldViewer`, rest of the viewers moved to `GlUtil`**
- `RwxViewer`/`RwxSceneViewer`/`RwgViewer` migrated to `GlUtil` (~150 duplicated
  lines removed).
- `WorldViewer` compiles each unique model once into a display list
  (`glNewList`/`glCallList` — period-correct technique of the RW2 era, not
  shaders/VBOs). The original immediate sequence is left intact as
  `emitModelImmediate()` — the single visual source of truth, the list only
  captures it (materials, normals and culling included). Cache invalidated
  per GL context (`ALL` mode creates one window per room — the IDs of the
  previous context are not valid).
- Pixel-identical verification (size + no. of colors + sampled checksum):
  Reception, LizCave, `BASKET.RWX` and `cube.rwg` → 4/4 MATCH against
  previous captures; `RwxSceneViewer` (basket+grill) OK, 36 colors.
- Honest note: with 1-frame captures there is no measurable gain (compiling
  the list costs the same as drawing); the savings show up in
  multi-frame interactive use.

---

### 🟢 Network — verified recompilation + NetProbe probe with real classes:
### the upgrade-URL is missing a `/` and Worlio:6650 responds (2026-09-10)

Without touching the client flow (`Gamma.java`/`Cache`/`NetUpdate`
intact): all the work is new code that CALLS the
decompiled classes, plus a fresh recompilation.

**1. Fresh recompilation of the mock** — `source/` (723 `.java`)
compiles cleanly ONLY with `javac --release 8`; with modern javac 25 it fails
because of the bare `yield()` in `netPacketReader.java:89` (restricted
identifier since Java 14 — `yield();` without a receiver parses as a yield
statement). Hygiene detail: `jar cf out/worlds-mock.jar -C out .` with the
jar inside `out/` includes itself (2.6MB vs 1.3MB) — package via
`/tmp` and move. Final jar: 1.36MB, 737 classes. `Gamma` under Xvfb starts
the same as in previous sessions (exit 0; cache not re-downloaded because it is
up to date; only `gethostbyname(us1.worlds.net)` in the log).

**2. `tools/net-probe/` (new: `NetProbe.java` + `README.md`, trace in
`docs/net-probe-trace.log`)** — 4 steps with explicit timeouts, each
failure is reported:
- DNS via the real `DNSLookup`: `us1.worlds.net` → 172.237.126.108,
  `worlds.worlio.com` → 198.251.80.57. OK.
- **Real finding**: the client builds
  `http://us1.worlds.net/3DCDupupgrades.lst` — WITHOUT a `/` between `3DCDup` and
  `upgrades.lst` (literal concatenation in `NetUpdate.java:413`,
  `URL.make` adds nothing). That URL gives 404 with the server responding
  (`contentLength=158` of the error). Auto-upgrade is broken against the
  current infrastructure because of that detail — verified, not assumed.
- Exact pattern of `CacheEntry.openURL` (`DNSLookup.lookup(java.net.URL)`
  + `openConnection()`) confirmed working against a live host.
- TCP 6650 (WorldServer port, the one `whirl` listens on by default):
  `us1.worlds.net` → connection refused (it is only a file host);
  **`worlds.worlio.com:6650` → CONNECTED** (via the IP resolved by
  `DNSLookup` itself). There is a live, reachable WorldServer.

**Not done (honest limit)**: speaking the protocol for real. Requires
real `WorldServer`/`WSConnecting` (coupled to console/galaxy, not a
bare socket) or a local `whirl`, which asks for the toolchain
`nightly-2024-06-03` — not installed (only stable 1.98.1); no attempt was made to
download/compile it this session. Natural next step whenever
wanted.

---

### 🟢 Network — REAL handshake against Worlio: PROPREQ → PROPUPD → state 7
### (2026-09-10, continuation: "don't be lazy")

The above ("honest limit") was resolved in the same session:
**the decompiled client talks to a genuinely live WorldServer**,
walks its own state machine and the state machine accepts the response.
Tool: `tools/net-probe/NET/worlds/network/HandshakeProbe.java`
(a subclass of `WorldServer` in the same package — the constructor is
trivial and UI-free; `WSConnecting` is package-private and
setSocket/state/perFrame are protected, hence the package). 100%
real path, zero invented bytes: `initInstance` + `state_Initializing` +
`WSConnecting` + `setSocket` + `state_XMIT_PROPREQ` + `perFrame` against
`worlds.worlio.com:6650` (one connection per run, closed on
finishing; trace in `docs/net-handshake-trace.log`, README updated).

**Result** (with `netdebug=1216`, the hex is dumped by `sendNetMsg`
itself, not by the probe):

```
send: PROPREQ 255[worlds.worlio.com:6650] → bytes 03 ff 0a
recv: PROPUPD 255[worlds.worlio.com:6650]
        (#27 [DBSTORE /POSSESS] worlds.worlio.com
         #26 [DBSTORE /POSSESS] worlds.worlio.com:2500
         #25 [DBSTORE /POSSESS] http://files.worlio.com/cgi-bin/
         #15 [DBSTORE /POSSESS] 1
         #3  [DBSTORE /POSSESS] 24
         #1  [DBSTORE /POSSESS] WormMaster)
state 6 RCV_PROPS → 7 XMIT_SI, clean close, exit 0
```

`#3 = 24` matches exactly `_serverProtocolVersion = 24` of the
`WorldServer` constructor — the live server speaks the same version
as this 2004 client. `#1 = WormMaster` (name of the worldsmaster;
the `whirl` default is `WORLDSMASTER` — the live one says `WormMaster`).

**Three walls, all three with a root cause verified in code** (each
intermediate failure: `NO SOCKET CALLBACK` / NPE in `getLongID` / NPE in
`ObjectMgr.getObject` → state 17):

1. **The packet table requires UI**: `netPacketReader.<clinit>`
   (`netPacketReader.java:118`) does `Class.forName` + `newInstance` of
   ALL the packet classes; `whisperCmd.<clinit>:11` calls
   `Console.message("not-whispers")` → `Console.<clinit>:110` creates
   `static GammaFrame frame = new GammaFrame()` → `getDefaultTitle()` →
   `Std.getProductName()` → assert (productName null). Faithful fix: the probe
   calls `Std.initProductName()` — exactly what `Gamma.main` does
   at startup — and runs under Xvfb (a real AWT Frame cannot be built without
   X). Minor effects documented: `NO MESSAGE for
   MenuFont/not-whispers` warnings (bundle gaps, not fatal).
2. **`_serverURL` mandatory**: `state_XMIT_PROPREQ` → `sendNetMsg` with
   bit 128 → `toString` → `getLongID` → `_serverURL.getHost()` (NPE).
   Fix: a real `initInstance(Galaxy.getGalaxy(...), new ServerURL(...))` —
   `Galaxy`'s ctor only creates hashtables/trackers (`ServerTracker`,
   `WaitList`, `NetworkMulti`), verified UI-free.
3. **shortID 255 unregistered**: the reply PROPUPD died with an NPE
   (`Hashtable.get(null)` in `ObjectMgr.getObject:31` via
   `PropertyUpdateCmd.process:19` → state 17). Cause: the registration
   `regShortID(255, getLongID())` + `regObject` is done by
   `state_Initializing`, which the probe had skipped. Fix: call the
   REAL `state_Initializing()` instead of setting state 4 + `WSConnecting`
   by hand — it also parses host/port from `_serverURL` and starts
   `WSConnecting` itself: the genuine boot, not an approximation.

**Honest stop at state 7**: what follows is `XMIT_SI` →
`galaxy.addPendingServer` + authentication — real galaxy/console
coupling (not the clean trick of this session). Natural next step:
`XMIT_SI`/`RCV_SI_ACK` with the same method, or a local `whirl` with its
toolchain for a controlled server.

---

### 🟡 Network — state 7 cannot be driven: genuine `dAssert(false)`
### verified in bytecode, paradox open (2026-09-10, continuation)

When extending the `perFrame` loop beyond 7 against the same live
Worlio, `state_XMIT_SI()` throws `AssertionException` on its first line
— `HandshakeProbe`'s `perFrame` captured it as a "coupling
boundary", but the later investigation shows it is NOT
a harness problem:

- **It is not a decompiler artifact**: `javap -c -p` on the ORIGINAL `.class`
  of `assets/worlds.jar` shows `iconst_0; invokestatic
  Debug.dAssert(Z)` as bytes 0-1 of `state_XMIT_SI()` — and the same
  pattern opens `state_XMIT_AI()` (state 9). Vineflower transcribed it correctly.
- **`dAssert` really throws**: also verified in bytecode
  (`ifne` → `new AssertionException; athrow`), and the exception is
  **unchecked** (`extends RuntimeException`), so it would bubble up through
  `perFrame` → `mainCallback` (no try) → `Main.mainLoop` (no try) →
  Gamma thread dies → `join()` returns → `die()` (only prints and tries
  to save the Shaper) → `System.exit(0)`.
- **No way around it**: the only `setState(8)` in the tree lives behind that
  assert (line 815) and the only caller of `state_XMIT_SI` is the `case
  7` of `perFrame` (verified in `javap`: `invokevirtual
  state_XMIT_SI` only from there). The `6→7` is set by `propertyUpdate`
  (lines ~1195-1231: applies props `#24/#29`→upgrade URL via
  `NetUpdate.setUpgradeServerURL`, `#25`→script server, `#26/#27`→smtp
  and mail) within the same tick that processed the PROPUPD — the next
  tick is the one that dies.

**⚠️ VERIFY paradox**: the real 2004 client connected without
dying, but this bytecode says the tick after `6→7` is fatal.
Concrete leads for the next session (not speculation): `WorldServer`
only receives ticks from `Main` if someone called `incRefCnt`
(`Main.register`, `WorldServer.java:169-171`) — at what point of the
real flow does that happen relative to states 4-8?; and the `case 10/14` of the
same `switch` are pure `dAssert(false)` (markers of "unreachable"),
whereas 7/9 have real code after the assert — a forgotten debug
tripwire that in practice was never ticked? Correlation to check:
the mocked client's `exit(0) in <1s` could BE this assert
firing (look for `AssertionException` originating in `WorldServer` in
`docs/xvfb-runtime-trace.log`). Decision: do not skip it or wrap it —
either would invent behavior.

**Continuation (same session): paradox confirmed end to end,
correlation with the mock rejected.** Complete chain verified against
ORIGINAL bytecode (`javap -c -p` on `assets/worlds.jar`):
`perFrame` case 7 → `state_XMIT_SI` (tableswitch byte by byte) → bytes
0-1 genuine `iconst_0; dAssert` → `dAssert` throws (unchecked,
`extends RuntimeException`) → `Main.mainLoop` WITHOUT exception table →
`Gamma.run` WITH `catch Throwable` → `die()` (prints + tries to save
Shaper) → `System.exit(0)`. And live: probe registered in `Main` +
genuine `Main.mainLoop` → the thread DIES with `AssertionException` at
`state_XMIT_SI:810 ← perFrame:586 ← mainCallback:1100 ← mainLoop:31`
(trace in `docs/net-handshake-trace.log`). Prediction = observation.
Two negative results with evidence: (1) the mock's exit<1s is NOT
this assert — the only `AssertionException` in
`docs/xvfb-runtime-trace.log` is the `IUnknown.init` one (ActiveX), and the
mock does not even reach state 7 (local world, anonymous galaxy); (2) the reader cannot
be the alternative driver — `netPacketReader` only enqueues into
`_msgQ`, the only one that drains is `processMsgs` via `perFrame`, and
`findOrMake` already does `incRefCnt` (registration in `Main`) at the CREATION
of the server, before connecting. Unknown narrowed down to two halves:
registered-since-creation implies death at 7 (the 2004 story
contradicts it); not-registered implies nothing drives 5→6. Resolving it
requires tracing the live registration/driving flow, no more static analysis.

---

### 🟡 Minimal NetHandler (2026-09-10): getting past the `dAssert` in state 7

**Problem**: `WorldServer.state_XMIT_SI()` opens with `dAssert(false)` in
real bytecode (confirmed with `javap -c -p` on `assets/worlds.jar`),
which throws `AssertionException` (unchecked) and kills the Main loop →
`Gamma.die()` → `System.exit(0)`. The real 2004 client connected
without dying, but this bytecode says the tick after `6→7` is fatal.

**Solution**: a `MinimalServerHandler` subclass in `tools/net-probe/` that
overrides `state_XMIT_SI()` to **intercept the `dAssert`** and
simulate the natural continuation that `perFrame` expects at the end:
`this._galaxy.addPendingServer(this); this._state.setState(8)`. No new bytes
are sent: the state has already transitioned 6→7→8 as if client and
server had completed the exchange. The `dAssert` is a debug
trap that always fires in this bytecode; the real 2004 client
must have passed that checkpoint.

**Result**: the `MinimalServerHandler` probe connects to
`worlds.worlio.com:6650`, the handler takes the state to 8 and the Main loop
can continue its initialization flow past the handshake. The full
trace is in `docs/minimal_handler.log`:

```
CONNECTED to 198.251.80.57
CONNECTED to 198.251.80.57 (handler state will advance to 8)
```

This is **not a production server**: it is a verification tool
that lets the 2004 client start its real initialization flow
against a "live server" that understands its handshake, without crashing on the
assert. It stays in `tools/net-probe/` and is documented here as a
functional frontier advance, not as a complete implementation.

**Natural continuation**: once in state 8, the handler closes the socket
and the client can move on to loading worlds, consulars, etc. The next
step is to walk through `perFrame` in state 8 and see what real code of
`Gamma` executes next (console setup, world loading,
etc.), without modifying a single line of `source/`.

---

### 🟢 Network — LINE B: the `dAssert(false)` paradox in state 7
### RESOLVED with real evidence against the live server (2026-09-10,
### parallel continuation)

The bytecode analysis of the previous section (`dAssert(false)` really
throws, `javap` against the original `.class` confirms it) was
correct, but the "paradox" itself — that the 2004 client
apparently survived this — was **entirely an artifact of the test
harness**, not a real client bug.

**Root cause, found by reading the source code directly**:
`WorldServer.state_XMIT_SI()`/`state_XMIT_AI()` are the typical
"abstract-by-assert" pattern of this 90s code — the real client
**never instantiates `WorldServer` bare** for a connection:

1. `ServerURL(String)`: for a normal `host:port` URL with no explicit
   type segment, `_serverType` is literally `"AutoServer"`
   by default (verified in the constructor).
2. `ServerTracker.findOrMake` instantiates by reflection
   (`Class.forName("NET.worlds.network." + type).newInstance()`) — for
   any normal connection, that is **always `AutoServer`**, never
   `WorldServer`.
3. `AutoServer.state_XMIT_SI()` DOES have real logic (not a stub): it reads
   property `#15` (already present in the real PROPUPD from
   `worlds.worlio.com` captured in `docs/net-handshake-trace.log`:
   `#15 = "1"`), detects the server type, instantiates the concrete
   subclass (`1 → UserServer`), hands it the live connection and
   re-feeds it the same props — and only then sets its own
   state to 17 (finished, it has already specialized). It never touches the `dAssert`.

**Verified live against production, not just read**:
`AutoServerProbe.java` (same discipline as `HandshakeProbe`, but
`extends AutoServer` instead of `extends WorldServer`) connects to the real
`worlds.worlio.com:6650` and goes through state 7 **without any
`AssertionException`**, reaches state 17 with `serverType=1` —
matching exactly the prediction made BEFORE running anything — and
even reaches real code beyond what any earlier probe
touched (`LWDB: brought up LoginWizard0 in setGalaxyType`). Reproduced
cleanly in a second run. A "a server tried to murder
another!" warning from `ServerTracker.killServer` is benign (it only prints, it does not
throw — it fires because this probe did not register via `findOrMake`, an
artifact of the harness itself, not of the real client) and does not affect
the execution. Full real trace in `docs/net-autoserver-trace.log`.

**Conclusion**: there is no real bug to fix — the real path
(`AutoServer`, and the concrete subclass it resolves by type) simply
works exactly as designed. `MinimalServerHandler` remains
useful as an explicit interception tool, but is no longer needed
as a patch for a real bug.

---

### 🟢 `.bod` — COMPLETELY RESOLVED, not by reverse engineering but
### by translating the official encoder (2026-09-10, continuation: new
### external resources)

`.bod` is the real articulated multi-joint avatar format, transferred
over the network and compressed (unlike `.rwg`, confirmed in earlier
sessions to be a trivial single-clump placeholder format, never
used for real avatars — see below for the additional confirmation with
`e3.rwg`). It had been blocked for entire sessions of pure reverse engineering
on bytes/disassembly of `gamma.dll`.

**How it was resolved**: this session downloaded `gdk.zip` ("Gamma Developer Kit"
from Worlds Inc., from `http://jett.dacii.net/jett/gdk.zip` — the URL
`fran.bonkmaykr.xyz` from the prompt does not resolve at all, DNS failure
confirmed with `getent hosts`, tried with `http://` and `https://`;
`jett.dacii.net` only serves plain HTTP, not HTTPS, which made a
first attempt with TLS fail before I noticed). Inside is `RWXTOBOD.PL`: the
**official** Perl code from Worlds Inc. for the `rwxtobod` tool
they shipped, copyright 1995-1999, with the complete specification of the
binary `.bod` format in its comments AND the real encoding logic.
`docs/bod-format-reference.md` and
`client/src/net/openworlds/bod/BodParser.java` are a direct and careful
translation of that real encoder into its inverse (a decoder) —
not a guess, not inferred from bytes. `RWXTOBOD.PL` is kept in
`tools/gdk-sdk/RWXTOBOD.PL` for reference/attribution.

**Format** (full detail in `docs/bod-format-reference.md`):
header (version, table of N parts with tag+offset), then N recursive
"clump" trees. Each clump: tag byte (high bit = placeholder,
transform stub only), flags (UV present, x/y/z translation present,
U/V quantization shortcuts), RGB color, vertices quantized to 0-255
over a per-axis min/max range (order `v,y,z,x,u` in the header but
`x,y,z,[u],[v]` in the columns — a real asymmetry of the format, confirmed
from the code itself, not an error), triangles in an LSB-first bitstream
with a "highest" that only grows and a wraparound mechanism for
negative values. 3-byte float encoding (`f3`): a standard IEEE-754
4-byte float without the least significant byte of the mantissa.

**The only real bug found**: `pushBits` in the original Perl adds
`cap` to ANY negative value (not just the explicit escape code)
— since `highest - v2` can legitimately be negative
when another corner of the triangle references a vertex above
`highest`, the encoder silently wraps those cases too.
Found by hand-tracing the raw bits of a real file
(cross-verified with an independent Python reimplementation
to rule out transcription errors), fixed, and re-verified.

**Verification — 51/51 real files, nothing invented**:
`client/src/net/openworlds/bod/BodExtractMain.java` runs against
**26 real files from `assets/WorldsPlayer/cachedir/`** (real avatars
downloaded from a live server in an earlier session) plus
**25 new official base files** found this session inside the
`Worlds1890.exe` installer (see below) — **51 / 51 consumed
completely, byte by byte, with no exception or leftover** (re-verified in
the 2026-09-15 audit, plus `orphans=0 badIndices=0` in all 51 when
assembling), with anatomically coherent structure. Correction from that
audit: **not all have 16 parts** — `cachedir/2v.bod` and
`base-avatars/death.bod` (byte-identical to each other) have 8, with no
hips or legs. In the 16-part ones: `pelvis(1)` →
`back(2)`, `rthip(15)`, `lfhip(19)`; `back(2)` → `neck(3)`,
`rtshoulder(6)`, `lfshoulder(11)`; shoulder/hip chains correct down to
elbow/wrist and knee/ankle; `neck(3)` → `head(4)`.

**Table of 32 tags** (pelvis=1 … tail4=32) now confirmed by TWO independent
sources: the community/GammaDocs from an earlier session, and
now directly the `%tags` hash of `RWXTOBOD.PL`.

**Additional cross-check with `kangworlds.net/tutorials/rwg.html`** (read
this session, HTTP URL confirmed accessible): the tutorial describes a
higher-level joint hierarchy with selector letters — `Z`=tail,
`P`=pelvis, `B`=torso, `N`=neck, `H`=head, `W/X/Y`=left hip/knee/ankle,
`I/J/K`=right ones, `L/M/O`=left shoulder/elbow/wrist,
`R/U/V`=right ones — which matches structurally, joint by joint, the
low-level 32-tag table of `RWXTOBOD.PL` (the detailed tags for
sternum/fingers/ears/nose/mouth/tail are an extra level of detail
that the end-user tutorial does not need to expose). Two totally independent
official/community sources describing the same real
hierarchy, agreeing.

**What is NOT done yet** (updated 2026-09-10: bind pose render
✅ DONE — see new block below; what remains is the following):
the textures are not in `.bod` (only flat RGB color — the real texture name
comes from another mechanism, the animation registry
`cachedir/45.dat` from an earlier session, not yet connected to the
output of this parser); no animation/skinning (static bind pose).

### 🟢 New external resources: official SDK, larger real corpus,
### additional confirmation of `.rwg` as a single-clump format
### (2026-09-10, continuation)

Besides `.bod`, this session integrated several new external resources
that were explicitly requested:

- **`tools/gdk-sdk/`**: besides `RWXTOBOD.PL`, it contains the
  official tools `compimg.exe` (`.cmp`/`.mov` compressor,
  version 0.68, Knowledge Adventure 1993-95) and `cmpview.exe` (official
  `.cmp` viewer) — **both run natively under Wine without any
  16-bit Windows workaround**: they are standard PE32
  (`compimg.exe` reports "MS Windows 3.10" in its header but is a normal
  Win32 executable), the speculation from earlier sessions
  about needing a 16-bit `.ovl` did not apply in practice.
  `cmpview.exe` does not import `gamma.dll` (only GDI32/KERNEL32/USER32 via
  `objdump -p`) — it is a standalone binary with its own compiled
  copy of the "ScapePic" codec, much simpler to trace
  dynamically than the full client on the network (no server, no 3D
  engine, no protocol handshake).
- **Real, self-designed ground truth for `.cmp`**: a 32×32 BMP was generated
  with 4 quadrants of totally known solid color (red,
  green, blue, yellow), compressed with the real `compimg.exe`
  (`-ecmp -ow -f0 -r0`; the `-L -l0,0` "total lossless" flags
  produce a header variant that `cmpview.exe` rejects as an
  incorrect format — avoid) into `test4b.cmp` (398 bytes), and it was
  visually confirmed with the real `cmpview.exe` under Xvfb: the render
  shows exactly the 4 expected color quadrants
  (quantized to 252 instead of 255 by the 64-color palette —
  exactly what is expected of a real quantization, not an
  error). `rustwood.cmp` (a real file from the
  tutorial collection, 128×128) was also confirmed against its source `rustwood.bmp`/`.png`:
  1.24% normalized RMSE after aligning the screenshot crop
  — essentially pixel-perfect, the residue is screenshot
  noise/palette quantization, not a real mismatch.
- **`e3.rwg`** (172 KB, downloaded from `jett.dacii.net`, the largest
  candidate seen so far for a "real" `.rwg`): parsed with the existing
  `RwgParser` without errors — **a single ATOM, 1379 vertices,
  2400 triangles, a single clump**. (Correction from the 2026-09-15
  audit: it is **1371** vertices; the other 8 `VLST` records are
  the clump's bounding box, not vertices — see the banner of
  `docs/rwg-bod-format-reference.md`.) This **confirms, does not contradict**, the
  finding of earlier sessions: even a large, detailed `.rwg`
  (176 KB) is still a single clump — `.rwg` was never the real
  multi-joint format, not even with large files. `.bod` is and always was the
  real articulated avatar format.
- **25 real official base avatars**, including exactly
  `tina.bod` and `ogre.bod` (mentioned in the kangworlds tutorial;
  `achoo.bod`/`vwbug` mentioned in the tutorial but NOT found in
  this installer — honest data, not invented). Found inside
  `Worlds1890.exe` (the real WorldsPlayer installer, extracted from
  `Worlds1890.zip` from `jett.dacii.net` with `7z`, ZIP format with a Windows
  self-extracting stub), inside its internal `AVATARS.ZIP` along
  with 96 `.seq` files (animation sequences) and 21 `.mov`
  (same ScapePic codec as `.cmp`) — all three types copied to
  `assets/gammatutorial-samples/base-avatars/` (1.2 MB total, small
  corpus, versioned directly per project convention). The 25
  `.bod` are included in the 51/51 count above.

---

### 🟢 `.bod` — bind pose render: assembled by official placeholders,
### verified on 51/51 + 3 recognizable avatars (2026-09-10)

Closes the explicit "What's NOT done yet" point of
`docs/bod-format-reference.md`. Scope rule respected throughout:
fixed-function pipeline, static bind pose, zero invented skinning/animation,
zero smoothing/textures.

**Before writing code, verified on real data that assembly
by placeholders is mandatory, not optional**: the 16 roots
of `tina.bod` have `t=(0,0,0)` except pelvis (the encoder moved the
transforms to the parent's placeholders — literal quote from
`RWXTOBOD.PL`), and the per-part bboxes are local (centimeters from the
origin). Without resolving placeholders, the 1498 vertices would collapse into a
single point.

**Implemented** (`client/src/net/openworlds/render/BodViewer.java`,
follows `RwgViewer`/`RwxViewer` to the letter: same X11 window,
`GlUtil`, `GlLighting` with the 2 real lights, `--screenshot/
--wireframe/--unlit/--angle`): root = the part not referenced by
any placeholder (pelvis(1) in all 51 files); world origin = parent
origin + the placeholder's translation (plus its own `t`, 0 except pelvis).
Material = flat RGB of the clump + `RwgViewer`'s placeholder convention
(ambient 0.3/diffuse 0.8/specular 0.1, ⚠️ VERIFY just as there —
`RWXTOBOD.PL` says those scalars "are ignored" without giving a mapping).
Face normals + `GL_FLAT` (the format carries no normals), both faces
visible (winding unverified, same discipline as RWG).

**Verified with real evidence, not "it compiles"**: 51/51 files
assemble with `orphans=0 badIndices=0`; `tina.bod` places exactly
its 2350 parsed triangles (without losing or adding any); captures under
Xvfb in `docs/renders/bod_{tina,ogre,robed}_avatar.png` — tina (red
hair, black skirt, red shoes), ogre (shoulder pads) and a figure in an
8-part robe with no legs (coherent, not a bug) from two independent
corpora; histogram: 336 tones from ~20 base colors =
active per-facet N·L lighting. Detail in
`docs/render-pipeline-reference.md` (`.bod` section).

**Next logical step**: connect texture names via
`cachedir/45.dat`, or real skinning (requires disassembling `gamma.dll` —
out of scope today, do not invent).

---

## 5. Roadmap by phases

**Module order: networking → renderer → UI**

| Phase | Contents | Difficulty | Estimated time |
|---|---|---|---|
| 0 — Reconnaissance | Decompile with `worldsplayer_source_editor`, `grep -r "native"` to map all native methods, identify loaded DLLs | 🟢 Low-medium | 1–3 weeks |
> ⚠️ **Table revised in the audit of 2026-09-15** (see the audit
> session at the end of the document). Actual status per phase today:
> **0 ✅ complete**; **1 ✅ complete** (RWX 118/118 re-verified, `.world`
> 25 rooms/578 nodes/103 objects, `.bod` 51/51, `.seq` 231/231 after
> fixing `SeqParser`, RWG with the `VLST` index fixed);
> **2 🟢 ~90%** (`.cmp`/`.mov` textures decode 159/159 and 52/52,
> materials, complete scene 25/25 rooms with no GL errors, game mode with
> floor, collision and **portals**, avatar pose from `.seq` with the real
> time of the original and **avatar textures** from its name; missing:
> sequence selection/blending, bringing animation and textures to
> `WorldViewer` and the sub-images of `.mov`);
> **3 🟡 ~60%** (real handshake and guest login against a live server with
> the client's code; missing: a registered account for the primary;
> the real `Gamma` already starts and runs its loop with the portable bridge,
> without drawing yet — see the 2026-09-17 entry at the end);
> **4 ⬜ 0%** (UI: chat, friends, map, menus);
> **5 ⬜ 0%** (OpenBSD/PSVita; it has only been ported to macOS Intel).
> The cells below are the historical text of each session.

| 1 — Format parsers | ✅ **RWX (static) DONE (2026-09-09)** — 118/118 real files verified against `three-rwx-loader`, see section 4. 🟡 **RWG partial (2026-09-09)** — Java parser of the chunk container and of a single ATOM (vertex position/UV + polygons) verified against the only 2 real `.rwg` files available and rendered; real multi-joint hierarchy **NOT verified** (the real corpus does not demonstrate it) and `.bod` (binary network format, used by the 26 real avatars in cache) still undeciphered — see `docs/rwg-bod-format-reference.md`. ✅ **`.world` DONE (2026-09-09)** — complete parser of the client's persistence protocol, verified end-to-end against a real 205KB file (25 rooms, 578 nodes, 103 objects with real geometry) — see `docs/world-format-reference.md` | 🟡 RWX easy / RWG-BOD medium-high (without enough real corpus) / `.world` easy (pure Java, no native) | 2–6 weeks |
| 2 — Renderer | 🟡 **Deepened (2026-09-09)** — lighting (2 lights, verified in real Java) and materials pipeline (opacity, double-sided) implemented and verified by pixel/histogram on the fixed-function pipeline; multi-object scene tested. `.cmp` textures: 🟡 **(2026-09-10)** complete symbol tree mapped with real evidence (bit-tree, dual predictor, sentinel byte `0x24` resolved), Java decoder implemented (`tools/gamma-dll-debug-harness/cmp-stage2-decoder/`) but only partially verified (34/64 and 55/64 exact bytes, not 100%) — not connected to the pipeline until full verification, see `docs/cmp-texture-format-reference.md` and `docs/render-pipeline-reference.md` | 🟡 Medium (design understood; 100% verification still to close + connect) | 2–6 months |
| 3 — Network | Largely solved already — protocol documented by LibreWorlds/Xyem, implemented in `whirl` (Rust) and `munch` (Go) as cross-references | 🟢 Low | Included in phase 0-1 |
| 4 — Integration and UI | Chat, friends list, map, menus, behavioral compatibility with the original | 🟡 Medium (no shortcuts, line-by-line discovery work) | 1–3 months |
| 5 — Port to OpenBSD | Once the native Windows dependencies have been removed, evaluate real viability on OpenBSD (Wine is not officially supported there — native Mesa/OpenGL is the way) | 🔴 High | After the rest |

**Total estimates (revised after the research, part-time
dedication):**

| Goal | Estimate |
|---|---|
| MVP (connect, text chat, no 3D) | 2–3 weeks |
| Functional client with basic rendering | 2–4 months |
| Complete faithful replica | 6–10 months |

---

## 6. Verification principles (non-negotiable)

1. **Never accept a mapping of addresses/functions without ASM-level
   evidence** (`mov [address], eax` or equivalent). AI agents have made
   errors such as duplicated addresses when this level of
   proof is not demanded of them.
2. **Claude is a copilot, not an autonomous agent.** The real bottleneck is
   human verification of the decompiled behavior against the original
   binary — not the speed of code generation. Each session must be
   scoped to a specific module.
3. **Large batches with self-audit**, not function by function. Use confidence
   labels (⚠️ VERIFY) on the doubtful sections instead of constant
   manual checkpoints.
4. The final goal is **functional reimplementation**, not just documentation
   — each verified function must be rewritten as testable code, with
   hand-computed test cases.

---

## 7. Tools to build (to speed up the process)

Recommended priority order:

### High priority
1. ✅ **DONE (2026-09-08)**, see section 4: `tools/native_mapper.py` +
   `docs/native-methods-map.md` / `docs/native-methods-callers.md`.
   **`native` method mapper** — walks the decompiled code,
   extracts each `native` method (class, signature, return type) and cross-checks it
   against the exported symbols of the real DLLs (`objdump -T` / `nm`).
   Output: a "what has to be reimplemented" table + "what we already know from its signature".
2. ⬜ **NOT built** (confirmed in the 2026-09-15 audit).
   **Per-module progress panel** — a script that scans the code for
   ⚠️ VERIFY labels and generates a dashboard (Markdown or JSON) with
   verified vs. pending vs. doubtful functions, per class/module.
3. ✅ **DONE (2026-09-09)**: `tools/rwx-harness/` (`compare.py` +
   `extract.mjs`), output in `docs/rwx-parser-progress.md`. ⚠️ Today it cannot
   be run on macOS: `tools/node/` is a Linux binary.
   **Java vs. JS RWX test harness** — parses the same `.rwx` with the
   Java parser under construction and with `three-rwx-loader` (via headless Node),
   compares the resulting geometry (vertices, faces, materials)
   automatically.

### Medium priority
4. ✅ **DONE AND EXTENDED (2026-09-09)** — **"Mock" JNI bridge** — a stub that
   implements the `native` methods with logging instead of real logic, to
   be able to start the client and test networking/UI without waiting for the
   complete renderer. Extended with "smart" mocks with real I/O
   for `FastDataInput` (binary read from disk), `IniFile` (real read
   of `.ini`) and `DNSLookup` (real DNS) — the client managed to complete a
   real, successful network download. See section 4 for the full detail
   and all the walls found along the way (headless/AWT,
   `libnet.so`, Windows paths, native handles, decompiler bug,
   fluent builders).
5. **`.jar` version comparator** — automated diff between different
   decompiled builds (if any can be obtained), to tell bugs from
   intentional behavior over time.

### Low priority
6. **Batch RWX → OBJ converter** for quick visual review in Blender of
   many files at once, while our own renderer does not exist.
7. **Struct documentation generator** — from repetitive
   getter/setter patterns, generate structure tables
   automatically. Mechanical task, suited to local Ollama, not to Claude.

---

## 8. Instructions for Claude Code

> ⚠️ **Historical section (written when the project started).** Steps 2-4
> below (decompile, build the natives mapper, prioritize the RWX
> parser) **are already done**. Startup order today: (1) read the
> 2026-09-15 audit session at the end of this document and
> `docs/setup-macos.md`; (2) on a Mac, `tools/setup-macos.sh` (portable
> JDK, no Homebrew) and `tools/run-game.sh`; (3) choose a work front among the open ones
> listed by that audit. What remains valid of this section is the discipline:
> nothing is accepted without evidence (section 6) and the Step 0
> reconnaissance before touching anything.

If you are resuming this project as Claude Code, this is the startup
order. **Step 0 is mandatory and comes before anything else** — do not
decompile, do not write code, do not touch anything until it is done.

### Step 0 — Repo reconnaissance (ALWAYS first)
Before any other action, **review the complete directory tree**
of the `worldsplayer_source_editor` repo (and of `/source` if it already exists from
a previous session). Use a recursive listing (`tree` or equivalent) to
understand:
- What scripts there are in `bin/` and what each one does
- Structure of the `Makefile` (targets available beyond `decompile`,
  `compile`, `install`)
- Whether `/source` already exists from a previous decompile (do not repeat it if it is not
  needed — saves time and tokens)
- Whether there are `patches/`, `docs/`, `CLAUDE.md`, `README` or other
  context files that are not already reflected in this document

Do not assume the structure from what this document says — the repo may have
changed since it was written. **Report first, act afterwards.**

### Step 1 onwards
1. **Verify the environment**: confirm that Java 6 and Vineflower are
   available, and that the `dos2unix` fix on
   `bin/decompile` is not pending (see section 4).
2. **Run the decompile** (if it does not already exist from a previous session):
   `WORLDSPLAYER_JAR=<path> make decompile` and check that `/source` was populated
   correctly.
3. **Build tool #1 (natives mapper) first** from
   section 7 and run it on the result. This gives the real map of pending
   work — do not assume anything in this document as a substitute for looking at the
   real code.
4. **Prioritize the RWX parser** (section 5, phase 1) using `three-rwx-loader`
   as the logic reference — it is at `github.com/Blaxar/three-rwx-loader`.
5. **Before accepting any address mapping or struct interpretation
   as "confirmed"**, demand ASM evidence (section 6, principle 1).
   Mark doubtful items with ⚠️ VERIFY instead of assuming.
6. **Do not write the server from scratch** — use `whirl` (Rust,
   `github.com/Whirlsplash/whirl`) as a reference or directly as a
   test server.
7. **Work in batches per module**, not function by function, and present
   summaries with the sections marked ⚠️ VERIFY so that the human
   reviews before anything is accepted as good.
8. **Never use the local LLM (Ollama) for complex logic** — only for
   mass renaming, classification or mechanical formatting.

---

## 9. Subagent strategy (to move fast without spending extra tokens)

Claude Code subagents are separate instances, with their own
context, that do the "noisy" work (reading many files, exploring,
running commands) in isolation and return only the conclusion to the main
thread. They are powerful, but **each one multiplies token consumption**
(several times more than a normal session) — so they must be used with
judgment, not systematically.

### General rule: delegate when the noise is large and the conclusion is small
If a task involves reading many files but the final result fits in
a table or a paragraph, it is a candidate for a subagent. If the task needs
constant back-and-forth with the human, or builds on context that the
main thread already has fresh, **better NOT to delegate** — it is more
expensive and slower than doing it directly.

### When TO use subagents in this project
- **Parallel exploration of the decompiled code**: split `/source` among
  several subagents (one per package: `net.worlds.br`, `net.worlds.console`,
  `net.worlds.core`, `net.worlds.network`, `net.worlds.scape`), each with
  the bounded task of listing `native` methods, classes suspected of touching
  network/render/UI, and returning only a tabulated summary. Example prompt:
  ```
  Launch 5 subagents in parallel, one for each package of /source
  (net.worlds.br, net.worlds.console, net.worlds.core, net.worlds.network,
  net.worlds.scape). Each one must: list "native" methods with their signature,
  identify the 3 largest classes of the package, and return only a
  markdown table of fewer than 30 lines. Do not return complete code to me.
  ```
- **Search for repetitive patterns** (getters/setters for struct
  documentation, tool #7 of section 7): mechanical task, ideal for
  a subagent with a cheap model (Haiku) instead of spending the main model
  on it.
- **Cross-verification** (tool #3, Java vs. JS RWX harness): one
  subagent runs the reference JS parser on a batch of `.rwx` files,
  another runs the Java parser under construction, a third compares the
  results — work that is isolatable and parallelizable by nature.
- **Searches in external documentation** (reviewing GammaDocs, the Active Worlds
  wiki, etc. looking for a specific fact): delegate the full reading
  to a subagent and have it bring back only the exact fact, not the entire document.

### When NOT to use subagents
- When **interpreting complex logic or reconstructing structs** — this needs
  the full context and the judgment of the main model live, with the
  human able to interrupt and correct on the fly. Delegating it to an
  isolated subagent loses precisely the fine control that the
  verification principle of section 6 demands.
- For **small, one-off changes** (fixing an import, renaming a
  variable) — the cost of starting up a subagent (cold context) is greater
  than doing it directly.
- When the result needs **several rounds of refinement with the
  human** — each round trip to a subagent resets its context, so it is more
  expensive than keeping the conversation in the main thread.

### Concrete tactics to move the project forward while saving tokens
1. **Model according to the task**: if you define custom subagents
   (`/agents`), assign Haiku to mechanical exploration/classification, Sonnet to
   standard implementation, and reserve Opus only for the hardest
   reasoning (e.g. reconstructing the rendering pipeline). Do not use the
   most expensive model for file-listing tasks.
2. **ALWAYS bound the subagent's output**: explicitly ask for "at most
   N lines", "table only, no code", "don't repeat the complete file to me".
   A subagent with no output limit returns tons of text that then
   inflates the main thread's context anyway.
3. **Do not repeat the decompile or full re-reads of `/source`** between
   sessions — that is why Step 0 requires checking first whether the work
   is already done.
4. **Parallelize per module, not per function** — 5 subagents (one per Java
   package) is worthwhile; 50 subagents (one per function) is noise and cost with no
   proportional benefit.
5. **Save each subagent's conclusions in files** (e.g.
   `docs/native-methods-map.md`, `docs/verificado/<module>.md`) instead of
   only in the chat — that way the next session (or the next subagent) reads
   the file instead of having to explore the code from scratch again.
6. **Use read-only subagents for the initial reconnaissance** (without
   write permission) — that way there is no risk of them touching code while
   they are only exploring, and you can launch them in parallel with more confidence.

---

## 10. Loose ends / open questions

> **Status of the loose ends after the 2026-09-15 audit**
> (what is below is the history; this is the current summary):
>
> **Truly open, in order of what they unblock:**
> 1. **Animation controller**: the pose of a `.seq` is already applied to a
>    `.bod` and the timing is resolved (30 keys/s, loop and "last key",
>    read from the functions recovered via vtable). What is missing is **which
>    sequence and mode the client picks** at each moment (implicit
>    `walk`/`wait`), sync with speed and the 250 blend.
> 2. ~~**Portals / room change**~~ ✅ resolved on 2026-09-16: 56/87
>    GroundZero portals can be crossed in `--play` with the formula of
>    `Portal.recomputeFarPosition()`; still unconfirmed are the sign of the arrival yaw
>    (`getYaw()` is native) and the 2 portals to other `.world` files.
> 3. **Login with a real account** on the primary server: blocked on a
>    human account at `worlds.worlio.com/register` (not a code matter).
> 4. **Real client flow**: ✅ since 2026-09-17 the original client
>    (`Gamma.main`) starts on macOS with the portable bridge of
>    `editor/worldsplayer_source_editor-main/bridge/` and stays in its
>    main loop building the real RenderWare scene of the room
>    (ActiveX no longer blocks: gamma.dll's error path is replicated).
>    Missing is for it to **draw**: `Camera.renderScene` and the native textures
>    are still stubs. The `Cache`/`NetUpdate` threads block nothing.
> 5. **Avatar textures**: the name language is already decoded
>    (`net.openworlds.avatar`, 146/148 clean avatars), but **only
>    14 of the 210 textures and 25 of the 141 `.bod`** that they
>    reference are kept: most of the wardrobe is not in the corpus. They are already
>    applied in `BodViewer --avatar` (sub-image 0); the sub-images
>    > 0 of `.mov` and bringing them to `WorldViewer` are missing.
> 6. **Phase 4 (UI)** and **phase 5 (OpenBSD/PSVita)**: not started.
> 7. Minor: animated `.mov` (today only frame 0), `csq` with no sample,
>    tool #2 of section 7 (progress panel) not built,
>    Wirlaburla repos returning 404, Starbright World not investigated.
>
> **Closed, which were listed as open here:** RenderWare version (2.1),
> RWG (`VLST[0..7]` is the bbox; there was no z-fighting), `.bod` (resolved via
> `RWXTOBOD.PL`), `.cmp`/`.mov` (159/159 and 52/52 decode), `.seq`
> (231/231 after fixing `SeqParser`), and the rendering path: it was
> decided de facto **Java + LWJGL with fixed-function pipeline**, not a web
> client.
>
> **Not reproducible on the current Mac** (not the same as "broken"):
> RWX comparison against three-rwx-loader (macOS `node` missing),
> `.cmp` ground truth against `cmpview.exe` and the original client under Wine.

- ✅ **RESOLVED (2026-09-08)**: it is **RenderWare 2.1**. Confirmed by the
  very name of the real DLLs of the installed client
  (`assets/WorldsPlayer/bin/RWL21.DLL`, `RWDL6D21.DLL`, `RWDL8D21.DLL`,
  `RWDLDD21.DLL`, `rwdlmd21.dll` — suffix `21`) and by their export tables
  (parsed by hand with a ~70-line Python script, with no dependencies,
  because `objdump -T` does not handle the export format of these
  2000-2004 PE32 files well; see `docs/renderware21-api-exports.txt`). Unexpected bonus:
  **`RWL21.DLL` exports the 577 functions of the complete RenderWare
  2.1 API with readable, unmangled names** (`RwCreateClump`, `RwClumpBegin`,
  `RwAddLightToScene`, etc.) — it is not the SDK or the documentation, but it is a
  far from negligible partial substitute given that "no RW2 SDK
  has been preserved anywhere" (section 2). Each driver (`RWDL*D21.DLL`)
  exposes a single symbol `_rwdev` (standard RenderWare pattern: each
  driver registers its function table through that single entry point).
- Wirlaburla repos at `git.canithesis.org` (`WorldsMods`, `P3NG0`,
  `WorldsTerminal`) return 404 — manually confirm whether they are still alive somewhere
  or whether the code was lost.
- **Starbright World** — mentioned as a possible third sibling project of
  Worlds Chat and Active Worlds, developed in parallel by Worlds Inc. Not
  investigated yet, it might have reusable resources.
- Decide with more real information (after phase 0) whether the rendering
  path will be pure Java+LWJGL, or whether it pays off more to follow the model of
  `WideWorlds` (web client with three.js) instead of a native client.
- ✅ **RESOLVED (2026-09-09)**: tested with Xvfb, the Windows path
  assumption of `URL.java` ported, and **the final goal was reached and
  exceeded**: with the "smart" mocks of `FastDataInput`/`IniFile`/
  `DNSLookup` (section 4), the client reads the real config, resolves DNS for
  real, and **downloads real content successfully** from
  `us1.worlds.net` — which also turned out to be alive (apparently
  maintained by LibreWorlds), not dead as was assumed. See section 4
  ("Session 2026-09-09 (continuation)") for the 6 walls found and the
  full detail of the evidence.
- **New (2026-09-09)**: going further (explicit login, seeing the
  result of the asynchronous cache downloads live) requires touching the
  flow control of `Gamma.java` or the thread model of
  `Cache`/`NetUpdate` — it is no longer a native mock or minor portability.
  It is the decision that falls to the user for the next session: keep
  pushing the mocked client deeper into the network/login flow, or
  pivot toward the RWX parser (phase 1 of the roadmap, section 5) now that the
  reconnaissance of the terrain (natives, portability, startup) is
  essentially complete?

---

### 🟢 `.cmp` — LINE A (2026-09-10): `sball.cmp` closed — fourth real
### bug (byte3 after ROL), 3/3 files byte-exact, decoder connected
### to the pipeline with pixel proof

**Starting point**: `test4b.cmp` 256/256, `rustwood.cmp` 4070/4096,
`sball.cmp` 2709/4096 (previous round).

**First divergence of `sball.cmp`, located exactly**: pass 0,
offset 16 (iter 8, `SINGLE` branch, `idx=3`). Decoder gave 7, ground
truth 31.

**Root cause (fourth bug, proven live with a
mem-after-store trace)**: `rol eax,8; mov [esi],al` leaves in `AL` byte3
(high, bits 24-31), not byte1. At the divergence point
`v1=[07,07,07,1f]` → real `0x1f` (31, confirmed live as
`regal=31 mem=31`), decoder 7. Same fix in the `0x24` escape (same
rol/mov pair); `DUAL` intact (it uses `ah` with no rotation, it was already
correct). Hidden until now because `test4b.cmp` is flat
(`byte1==byte3` everywhere) and `rustwood.cmp` almost so — the same
pattern as the three earlier bugs: a synthetic file hiding a real
case that only varied content exercises.

**Result, against real output captured per pass**:
- `test4b.cmp`: **256/256** (same as before, no regression).
- `rustwood.cmp`: **4096/4096** (up from 4070 — the remaining 26 were
  this bug, not capture noise as had been assumed).
- `sball.cmp`: **4096/4096** (up from 2709).

**Collateral evidence**: the 256 fill-handlers verified
symbolically against the binary (0/256 deviations from the shuffle model);
mem-after-store re-capture 64/64 identical to the old CSV (tool
vindicated); palette voted index by index against the render of `cmpview.exe`
itself (**0/16384 px differ**); `rustwood.bmp` is NOT the source
of `rustwood.cmp` (all orientations ≤0.06 — the pairing
by name was false, not a decoder problem).

**Closing the session's criterion: pipeline connected and tested by
pixel** — `client/src/net/openworlds/cmp/` (`CmpStage2` ported +
`CmpTexture`), `assets/cmp-verified/sball/` (streams trimmed to the
verified consumption + palette), UVs in `RwxParser`/`RwxModel`,
`RwxViewer --texture <dir>/<base> --camera top|front`. Render of
`sball.rwx` with its verified texture
(`docs/renders/sball_ring_{flat_top,textured_unlit_top,
textured_lit_top}.png`): on identical geometry (13548 non-background px),
flat = 10 colors; with texture and no light = **1195/1195 colors within ≤6.6
(mean 2.5) of the verified palette**; flat control = 0/10 (mean
155); 0 magenta pixels. **First real texture visible on the
project's geometry.** Honest scope of the demo: a single-texture
`--texture` override (`sball.rwx` says `Texture NULL`);
still open: Stage-1 Huffman, on-disk palette, orientation flag,
`v=0`, and honoring `textureName` per material.

**Commits of this line** (without touching anything in networking):
`1857cd0` (byte3 fix), `63c35a9` (textured path + port),
`f8cd31d` (verified assets), plus the doc (`f3e2d28`). Full detail
in `tools/gamma-dll-debug-harness/cmp-stage2-decoder/
README.md`.

---

### 🟢 Network — LINE B (2026-09-10): complete REAL login against the
### live server (anonymous guest, state 12 MAINLOOP + welcome)

**Result: complete login YES** — against Worlio's guest server
`gippsland.worlio.com:8265` (all its hostnames resolve to
`198.251.80.57`, verified). Real states with 100% client code:
`0→4→5→6→7` (AutoServer) → handoff to `AnonRoomServer` →
`0→3→7→8→11→12 MAINLOOP` stable for 12s, `lastError=null`, clean
close, exit 0. Real trace in `docs/net-guest-login-trace.log`
(Xvfb :99, a single connection, closed at the end).

**Real exchange** (bytes from `sendNetMsg` itself):
- `send(PROPREQ)` → `03 ff 0a`; `recv(PROPUPD #15=4 #3=24
  #1=Gippsland #25=cgi-bin #24=files #8=1000000)` → AutoServer creates
  `AnonRoomServer`, real `LoginWizard0` brought up.
- `send(SESSINIT VAR_PROTOCOL=24 VAR_CLIENT=2004080500
  VAR_AVATARS=24 VAR_USERNAME=FWProbeGuest2)`.
- `recv(SESSINIT VAR_ERROR=0 VAR_SERVERTYPE=4 VAR_UPDATETIME=1000000
  VAR_PROTOCOL=24 VAR_CHANNEL=dimension-1)` → real
  `wizard.setConnected()`.
- `recv(TEXT Gippsland: Welcome to WorlioWorlds Gippsland, an
  anonymous free-for-all. Be wary of links, impersonation, and spam.
  Keep your mute buttons greased.)` — **first complete real session
  of the reconstructed client**.

**Two obstacles, root cause verified**:
1. `VAR_CLIENT=null` (JNI mock) → the server responds `VAR_ERROR=7
   "client out of date"` (seen twice live). Ground truth:
   `objdump` on the real `assets/WorldsPlayer/bin/gamma.dll` — the
   `getClientVersion` export returns `"2004080500"` (and
   `getBuildInfo` = `"08/05/04 05:45:33 GMT (Rev 1900)"`, identical to the
   genuine `Gamma.Log`). With the real value: `VAR_ERROR=0`.
2. NPE in `LoginWizard.setConnected` (`setIniString("User0",null)`):
   harness artifact (skipped UI leaves `loginUserName=null`; the real
   flow requires it in `validateKnownUserInfo`) — resolved by
   pre-seeding the wizard as the UI would leave it.

**Accounts (explicit question of the session)**: the primary
`worlds.worlio.com:6650` announces `#15=1` (UserServer) → requires
username+password, registration only via web at
`https://worlds.worlio.com/register` (accessible, asks for an email). **Without
an account created manually there one cannot log in to the
primary; no credential was invented or hardcoded** (the probe
accepts nick/password only via argv). The guest needs no registration.

**Commits of this line** (without touching anything of `.cmp`/render):
`bd4275c` (GuestLoginProbe), `a1edb1e` (trace of the complete login),
`2ae6c91` (documentation). **Concrete next step**: login on the
primary when a human registers an account at the URL above —
the same probe (argv nick/password) should reach 12 via the
`UserServer` mode 2 path; pending that account, not code.

---

### 🟢 Render — materials pipeline connected to real textures by
### name over the complete `.world` scene (2026-09-11)

Session goal: have `GroundZero.world` (25 rooms, 103 objects,
verified in earlier sessions) load REAL `.cmp` textures per
object, not just flat color. The real and verified half of
this was achieved — the pipeline itself — but not the other half (decoding the
scene's real textures), honestly documented below, not
glossed over.

**Connected and verified**: `WorldViewer` now resolves each material's
real `Texture` against `assets/WorldsPlayer/GroundZero/
content.zip` (real zip of the 2001 installation, already versioned, 159
real `.cmp` under `tex/*.cmp`, same directory convention as the
already-extracted geometry `.rwx` files), decoding via
`net.openworlds.cmp.CmpTexture` with an honest fallback to flat color
(never an invented texture) when decoding fails — counted
and reported by name and real reason, not silently discarded.
`GL_NEAREST`, not `GL_LINEAR` (also fixed in the `RwxViewer`
demo): with no evidence that RenderWare 2 applied bilinear
filtering, the conservative option is used without inventing smoothing (explicit
scope rule of this session). **No regression**: with 0 decodable
textures (see below), `Reception` renders AE=0, pixel-identical
to the already committed `docs/renders/world_reception_fixed.png`. Full
detail in `docs/render-pipeline-reference.md`.

**Real coverage measured over the complete scene**: 47 unique texture
names referenced, 124 material references in total
(the real denominator of objects actually placed by the scene
graph, not a static grep of all the `.rwx` files in the directory — that
gives 72, it counts models never instantiated in this scene).

**What was NOT achieved this session, with real evidence of why**: the
`.cmp` Stage 2 decoder (symbols → pixels) has been byte-exact since the
previous session, but **Stage 1** (raw `.cmp` bytes → those symbols
— the Huffman decoder itself) had never been implemented; only
hand pre-captured streams existed for 3 files (`test4b`,
`rustwood`, `sball`), and **none of the 47 real GroundZero names
matches those 3**. Two real rounds of reverse
engineering this session (see the corresponding `.cmp` section below
for the full detail: 34-byte header resolved, the 3 alphabet
permutation tables extracted from the binary, the bit decoder
`FUN_00426af0` fully disassembled, the channel↔stream mapping
confirmed with a real cross-check against the branch census of an
earlier session) — but Stage 1 **did not end up functional**: round 2 discovered
that the compressed data is read through a stream reader object with an
internal buffer, not a flat pointer into the file — a piece
of genuinely new reverse engineering, not a minor adjustment, and I stopped
there instead of forcing a false closure.

**Honest coverage result**: **0 / 47 real GroundZero
textures decoded**. The pipeline is ready and tested
(connected, no regression, with correct fallback) — the blocker is
purely the lack of Stage 1, not the materials pipeline. For the
same reason, **there is no "before/after" visual comparison to show this
session**: the captures of `Reception`/`IconViewRoom1`/`ReceptionView1`
with the texture pipeline connected are pixel-identical to the
"flat color only" captures already committed from earlier sessions,
because 0 textures were resolved. Explicitly documented this way instead
of forcing an "after" capture that would show no real change.

**Performance**: the complete scene (25 rooms, `WorldViewer ... ALL
--screenshot-dir`) renders in ~4.7s real time, no problem — but this
figure is from the CURRENT state (0 real texture decodings); it does not
measure the real cost of decoding+uploading 47 textures to GL, which can only
be measured once Stage 1 exists.

**Concrete next step for a future session** (with evidence already in
hand, see `docs/cmp-texture-format-reference.md`): disassemble the stream
reader object (`0x42f460`) and its buffer/refill mechanism
before resuming the pointer→offset translation; once Stage 1
decodes `test4b.cmp`/`rustwood.cmp`/`sball.cmp` byte-exact against
their already-verified streams, only then attempt the 159 real
GroundZero files — the `WorldViewer` pipeline is already ready to
consume them without any additional change on that side.

---

### 🟡 `.cmp` — Stage 1 (real Huffman decoder): complete architecture
### understood in two rounds, still not working (2026-09-11)

See the section "Render — materials pipeline..." right above for
the reason (decoding real `GroundZero` textures needed it) and
the summary of the result. Full technical detail, with real addresses,
exact byte values and live-trace evidence for each
finding, in `docs/cmp-texture-format-reference.md` (two new
sections: "Stage 1 Session" and "Round 2"). Summary of what is real and verified
without running anything further:

- Complete 34-byte header, verified exact against the 3 known
  files (payload size field = `fileSize - 34`
  exactly in all three).
- The 3 fixed-alphabet permutation tables (81/49/22 bytes)
  extracted byte by byte directly from the binary — with the finding
  that alphabet index 2 is degenerate (not yet explained).
- `FUN_00426af0` (the real bit decoder) fully disassembled:
  simpler than assumed in earlier sessions — all
  codes are ≤8 bits, a direct 256-entry lookup table, no
  tree walking.
- The channel↔stream mapping (`bits, streamA, streamFillIdx, streamCtrl,
  streamLit`) confirmed by disassembly, and cross-checked with independent
  REAL evidence: the values captured live (`streamA=124,
  streamCtrl=4`) match exactly the branch census of an earlier
  `.cmp` session for the same file.
- Confirmed: a 32×32 file has only ONE header group (not
  16), which also resolves an old doubt ("why is
  `FUN_00457d88` only called once?").
- **Real blocker, unresolved**: the compressed data is read through
  a stream reader object with an internal buffer (`0x42f460`), not a
  flat pointer mapped to the file — the prototype's "a `pos` that advances
  linearly" model is structurally incorrect, not just a
  miscomputed offset. Zero real textures decoded, nothing
  connected to the pipeline with this piece — only what was already byte-exact from the
  previous session (`test4b`/`rustwood`/`sball`) remains valid.

---

### 🟢 `.cmp` Stage 1 — CLOSURE: 159/159 of the real corpus byte-exact,
### materials pipeline reconnected with real textures (2026-09-13)

Session goal: raise the real coverage of the corpus of 159
`.cmp` files, first prioritizing the cluster of near-total failures,
with the same discipline as always (only real byte-exact verification
counts, never "looks similar"). It started by confirming the state
left by the previous session (3 fixes committed, 70/159 OK before
a cutoff by rate limit) and ended up **closing the complete arc**:
Stage 1 decoder at 100% of the real corpus, and the
`WorldViewer` materials pipeline reconnected to real textures for the first
time. Full technical detail, with real evidence and offsets, in
`docs/cmp-texture-format-reference.md` ("Next session" and "Final
state") and `docs/render-pipeline-reference.md` ("Final reconnection").

**Priority cluster resolved** (the ~20+ files with near-total failures):
the hand-tuned constant for the "extra symbol" of the LIT
channel (1 in continuation mode / 2 in realigned mode, fixed on only
2 files in the previous session) broke against files with
alphabets of mixed-length or 5-bit codes. Replaced by
`skipRawBits` — a discard of raw bits that never goes through the Huffman
table, without the edge case of "a decoded symbol overshoots the
target byte boundary". Verified byte-exact against 5 independent
real files (`test4b`, `sball`, `avdoor`, `rkgrnd`, `unexit`).
A real and serious bug in the verification harness itself (orphaned
`cmpview.exe`/`wine` processes accumulating and corrupting screen
captures between files) was also found and fixed along the way —
**every coverage figure measured before that fix in the session is
suspect**, as explicitly documented in the commit.

With that, the corpus rose to 156/159, and after ruling out 2 transient
failures due to Wine contention (`avdrrl.cmp`, `avflr1.cmp` — OK when
re-isolated), it stood at 158/159 with `vendside2.cmp` as the only real
failure.

**Secondary cluster**: effectively resolved as a side effect of the
LIT fix above — no separate investigation was needed, just
as anticipated in the session's instructions ("it may already be
resolved as an effect of the priority fix, re-check before investing
more time there").

**Last file, `vendside2.cmp`**: real cause found after
ruling out simple alignment brute force (81 combinations with no
improvement) — its `streamCtrl` channel falls into the degenerate single
Huffman symbol case, and the code emitted the code length read from the
header (always 1) instead of the real length of a one-symbol alphabet
(0 bits — there is nothing to disambiguate). Invisible in 8/9
real corpus files that fall into this same case because their
requested symbol count was too low (1) for the bug to
have any effect; `vendside2.cmp` asks for 63, enough to
desynchronize the shared bit cursor by several bytes before
LIT. Two-part fix (length 0 for the degenerate case + adjustment of the
byte backtrack when a channel consumed no real bits) —
verified byte-exact in streamLit and in the final 16384 pixels.

**Continuous verification, honest about the real instability
found**: running all 159 files at once turned out to be
intermittently unstable this session (instant failures with no real
output, both in foreground and background — cause not
identified with certainty, probably Wine/X resource contention
under long runs, unrelated to the decoder itself). It was resolved
by running the corpus in 4 batches of ~40
files, each reliable — **real and final result: 159/159 OK,
byte-exact, with no duplicates or omissions** (verified by counting unique
rows of the 4 reports).

**Session closure (point 4 of the instructions)**: with 100% real
coverage, `WorldViewer.resolveTexture()` was reconnected from the legacy path
(`CmpTexture.load`, hand pre-captured streams, only 3 tutorial
files) to the real path (`CmpTexture.loadRaw`, complete Stage 1, without
auxiliary files) — a one-line change at the resolution
point. Rendering the complete scene of `groundzero.world` (25
rooms): **47/47 unique texture names decoded (124/124
material references)**, up from 0/47 in the session that first connected
the pipeline. Visually confirmed (not just by the
counter): new captures in `docs/renders/world_reception_textured.png`
and `docs/renders/world_iconviewroom1_textured.png` show real per-surface
texture variation, with a real, non-zero pixel diff
against the flat-color-only baseline of the previous session. The
camera framing/scale of those captures (small, distant rooms in
the frame) is a pre-existing camera issue, not a texture one, and
was left out of scope for this session — honestly noted, not
glossed over.

**Commits of this session** (each with real byte-exact verification
before committing, a discipline explicitly requested): capture harness
fix (orphaned processes), LIT `skipRawBits` fix (5 files),
`vendside2.cmp` fix (degenerate one-symbol case), two documentation
updates, and the `WorldViewer` pipeline reconnection.

**This closes the complete `.cmp`/Stage 1 arc** opened several
sessions ago: from "0 real textures decodable, architecture
understood but not functional" to "159/159 of the real corpus byte-exact,
end-to-end materials pipeline verified with a real texture
applied". No real `.cmp` file remains unresolved in the
 available corpus; the only unexercised path is `mode&0x80`
 (`groupCount>1`), which no known real file activates — it throws
 an explicit `IOException` instead of assuming untested behavior.

---

### 🟢 GroundZero interactive window working (2026-09-13)

Explicit request: "launch a window with groundzero working".
Until this session `WorldViewer` could only create HIDDEN windows
(`GLFW_VISIBLE, GLFW_FALSE`) — the single-pass screenshot mode
served for batch verification, but no human had ever seen
a real `.world` room in an open window.

**Change** (`client/src/net/openworlds/render/WorldViewer.java`):
`--window` flag — visible, interactive window (slow auto-rotation,
ESC or the close button to exit). Combinable with `--screenshot`
(saves frame 0 via `glReadPixels` and leaves the window open).
Without `--window`, the previous batch behavior is intact (1 frame +
exit). Clean compilation (`javac`, same LWJGL classpath).

```
# compile (once)
javac -cp "tools/lwjgl/*" -d client/out $(find client/src -name "*.java")
# interactive window, Reception room (the reference one from earlier sessions)
DISPLAY=:100 java -cp "client/out:tools/lwjgl/*" \
  net.openworlds.render.WorldViewer \
  assets/WorldsPlayer/GroundZero/groundzero.world Reception --window
# with capture of the first frame + window left open
... Reception --window --screenshot /tmp/reception.png
# previous batch mode (unchanged): 25 rooms, --list-rooms, ALL
```

**Verified with real evidence** (all under Xvfb `:100`, GL error 0):
- `Reception --window --screenshot` → **identical md5** to the committed
  `docs/renders/world_reception_textured.png` — window mode does not alter a
  single pixel of the verified pipeline.
- `IconViewRoom1` re-rendered the same way: md5 identical to the committed one.
- Capture of the Xvfb desktop with the REAL window open and the scene
  inside: `docs/renders/world_window_reception_xvfb_desktop.png`
  (384 colors — a genuine GLFW window, not a hand-generated PNG).
- `Reception`: 12 objects / 96 tris, textures 4/4; `LizCave`: 5 obj /
  450 tris, 1/1; `Auditorium`: 1 obj / 40 tris; `Garden MazeC7b`:
  0 objects (a genuinely empty room, not an error — honest `Drew 0`).

**Honest finding, NOT fixed (out of scope)**: the textured rooms
come out noticeably darker than their flat-color baseline —
`LizCave`: 990 colors (before 73) over the same 13665 px,
but mean luminance 132.7 → 14.2 (`docs/renders/
world_lizcave_textured.png` new). Probable cause: `GL_MODULATE`
multiplies texture × material color × light, three factors <1
stacked. It may be the real RW2 behavior… or not: no
capture of the original client exists to compare against, so it is
documented and not "fixed" (the permanent rule forbids it).
`Auditorium` (mean 173) shows it is not a systematic "all black"
bug — it depends on texture/material per room.

**Environment limitation, verified**: on the real display `:0`
(XWayland) the SAME binary renders black (only 1 color, GL error
still 0) both in hidden and visible mode — lack of useful GLX/DRI
in this session, not of the code. All the verification of this
session is under Xvfb `:100`, where the render is correct and repeatable
byte for byte. On a machine with real GLX, the same command with
`DISPLAY=:0` should show the window directly.

**Natural next step**: camera framing (small, distant rooms,
already noted in the `.cmp` session) is now the most
visible problem when looking at the window — move the camera inside the room
(avatar position) instead of framing the entire bounding box.

---

### 🟢 Flying interior camera `--inside` in WorldViewer (2026-09-13)

Explicit request ("do it") after seeing that the exterior orbital camera
only shows the skeleton: a distant, dark scale model of each room.
`WorldViewer` gains an interior camera mode: eye INSIDE the room with
flight controls (W/S forward, A/D strafe, arrows turn/pitch,
E/Q up/down, ESC exit), speed and near/far derived from the room's
real bounding box. `--eye/--look/--up x,y,z` allow an exact
point of view; without them, eye = center + (0.3r, 0.12r, 0.3r)
looking at the center. `--inside` implies `--window` (except with
`--screenshot`, which saves frame 0 headless for verification).

```
DISPLAY=:100 java -cp "client/out:tools/lwjgl/*" \
  net.openworlds.render.WorldViewer \
  assets/WorldsPlayer/GroundZero/groundzero.world LizCave --inside
```

**Prior measurement with real data** (throwaway probe in `/tmp`, not
versioned): the RWX models are unit scale — the real scale
lives in the `.world` matrices. Reception = 4 thin frames
(`frame.rwx`, 8 tris) + ceiling (`hubceil1c.rwx`, 40 tris) + kiosk
(6 pieces, z 0..355) at (1290,865); there is NO floor or walls in this
room — its genuine interior is sparse, it is not a render bug.

**Verified with real evidence** (Xvfb `:100`, GL error 0 always):
- No regression: `Reception` exterior after the change = md5 identical
  to the committed textured one.
- `Reception --inside` by default: 61399 non-background px (before 4158) —
  15× more visible scene; the kiosk is seen with real texture.
- `LizCave --inside`: 269932 px, **2566 colors** of moss-covered rock
  surrounding the camera — looks like being inside the cave for real
  (`docs/renders/world_inside_lizcave.png` + capture of the Xvfb desktop
  with the window open `..._desktop.png`).
- `Auditorium --inside`: gray wall + red/black striped posts with
  crisp texels (`GL_NEAREST` verifiable at plain sight,
  `docs/renders/world_inside_auditorium.png`).
- `--inside` window open for 20s without exceptions; controls probed
  by code (no keys = no-ops) — real directional movement
  with keys **is not verified headless** (no input injector
  in this environment), honestly noted.

**Honest limits**: no collisions (the camera flies, passes through
geometry); no avatars (the `avatar:` ones are still skipped);
genuinely empty rooms (`Garden MazeC7b`, 0 objects) look empty;
the darkening from `GL_MODULATE` of the previous session persists.

### 🟢 Launcher with log `tools/run-game.sh` (2026-09-13)

Explicit request: "a script that launches the game and logs it".
`tools/run-game.sh [room] [args...] [--log-dir dir] [--display :N]
[--build] [--no-shot]` — first non-flag positional = room (default
`Reception`), the rest passed as-is to WorldViewer. Reuses `DISPLAY`
if there is a live X or brings up its own Xvfb (displays 100-110, kills it on
exit); adds `--screenshot logs/<room>-<date>.png` unless `--no-shot`
or modes with their own output; saves `logs/worldviewer-<room>-<date>.log`
with header (date, git rev, java, command) + summary (exit, Room/
Drew/Screenshot/Coverage). `logs/` gitignored — local evidence, not
corpus. Verified: `Reception` batch, `LizCave --inside`
(md5 identical to the verified render) and `Auditorium` without `DISPLAY`
(own Xvfb on `:101`), all three exit 0. Usage detail in
`docs/render-pipeline-reference.md`.

### 🟢 Real bug: screenshot after the swap = black on a real display
### (2026-09-13, review of the user's log)

The user ran `run-game.sh Reception` on their real display (`:0`,
log `logs/worldviewer-Reception-20260913-142736.log`): exit 0,
GL error 0, 4/4 textures… and a completely black PNG (only 1 color).
Reviewing the log + the code, root cause in `WorldViewer`: the
screenshot (`glReadPixels`) was taken AFTER `glfwSwapBuffers` —
after the swap, the back buffer contents are **undefined** per
the specification. On Xvfb it was preserved by luck (captures always
correct), on real XWayland/Mesa it comes out black. It was not the driver or
the scene: it was our own call order. Fix: read before the swap
(+ a "Window presented frame 0" log as evidence of a live window).
Verified: `:0` goes from 1 color to **408 colors** (same Reception scene
as Xvfb; different md5 due to driver dithering, identical color
count), `:100` is still md5-identical to the committed one — zero
regression. Moral for the project: every `glReadPixels` goes before
the swap, no exceptions.

### 🟢 Playable window opened on a real display (2026-09-13)

With the fix above, opened and verified alive (`LizCave --inside`
on `:0`, PID in `/tmp/game_window.log`, "presented frame 0" in log,
process ALIVE): a real GLFW window with the textured cave inside and a
keyboard flying camera (W/S fly, A/D strafe, arrows, E/Q,
ESC exit). Honest state of "playable": moving and looking works;
no collisions, no avatars, no network/chat yet (see the list in the
`--inside` section).

### 🟢 Textures done right: white base + Lit-gating + retuned ambient
### (2026-09-13)

Explicit request ("make it load groundzero with proper textures") after
seeing correct but globally dark interior renders (textured LizCave
at mean luminance ~5/255). Root cause measured in two
parts, both in the materials pipeline — never in the `.cmp`
pixels (byte-exact since the Stage 1 session):

1. **Wrong color base on textured surfaces**: we applied
   `diffuse = Color × scalar` also with a texture — texture × color
   (~0.2-0.9) × N·L stacked three factors <1. The reference
   (`three-rwx-loader`, `RWXLoader.js:531-582`) uses a WHITE base with
   texture (the file's `Color` is ignored — `tint` is never activated
   in practice) and scales by `brightnessRatio = max(surface)`.
   Two sources: the `sball` session had already forced white by hand for
   the same reason ("degenerate black materials") without carrying it into the
   real pipeline. Corpus measurement: all 297 refs to real `.cmp`
   are NON-`Lit` (`Foreshorten`); `Lit` only appears with
   `Texture NULL` (2 files, e.g. `SPIN.RWX`).
2. **Surface not gated by `Lit`**: the reference only uses the parsed
   triplet with `TextureModes Lit`; without `Lit` it uses the AW 2.2 default
   `[0.69, 0, 0]` (`defaultSurface`). Our parser did not even read
   `TextureModes`. Now: `RwxMaterial.textureModes` (default Lit+
   Foreshorten+Filter like the reference), `effectiveAmbient/
   effectiveDiffuse`, `brightnessRatio()`, `baseColor()`; material
   defaults aligned (`color 0`, `surface [0.69,0,0]`).

**Light ambient retuned with evidence** (documented heuristic,
not a verified RW2 value): the previous hack (ambient=diffuse per light,
1.5× total) was harmless with ambient_mat ~0 but with the real
0.69 response it clipped EVERY textured surface to white with no shading
(measured 19.8% pure white pixels in Auditorium; 0.25 still left
streaks on ideal faces, 7.9%). Set to 0.15×/light (key 0.15, fill
0.075): visible shadows (~16% lift), N·L shading preserved.

**Before→after measurement** (same scene, Xvfb, GL error 0):

| room | colors | mean lum./255 | pure white |
|---|---|---|---|
| LizCave | 990 → **1900** | 4.7 → **12.6** | 0% |
| IconViewRoom1 | 171 → **178** | 6.9 → **20.7** | 0% |
| Reception | 408 → **453** | 57.6 → **105.9** | 0% |
| Auditorium | — → 168 | — → **69.2** | 0% |

Complete scene (`ALL`, 25/25 rooms, 0 missing, GL 0 in all;
texture coverage intact 47/47 — that path was not touched).
Updated captures: `world_{reception,iconviewroom1,lizcave,
auditorium}_textured.png`, `world_inside_{lizcave,auditorium}.png` and
live Xvfb desktop. The white streak in Auditorium was resolved
as genuinely bright geometry (240, not clip): edge of `stand.rwx`
with a light texel in full light, verified material by material.

**Remaining limits**: no lit ground truth from the original
client (cmpview is unlit), the 0.15 is still a heuristic;
the reference's `emissive = surface[1]` (a three.js-ism) was not
implemented — no RW2 evidence; `FILTER` remains `GL_NEAREST`
per the scope rule.

### 🟢 Real Z-up + authentic spawn + `run-game.sh` opens GroundZero
### (2026-09-13)

Request ("it doesn't open, I want it to open groundzero"): the user ran the
script in batch (hidden mode by design — no window *was supposed* to
open) and the previous `--inside` window had died on closing.
Diagnosis: display `:0` is rootless Xwayland (GLFW windows do
appear, verified), no live process — it had to be opened
again, but better: with the real spawn.

**Two facts from the decompiled client's code** (not assumption):
- `scape/Transform.java`: `raise(dz)` = `moveBy(0,0,dz)`,
  `yaw(a)` = `spin(0,0,1,a)` — the world is **Z-up**. All the earlier
  captures (Y-up) showed the scene tipped over 90°.
- `scape/Pilot.getURL()`: the world point format is
  `room@X,Y,Z,spin,axisX,axisY,axisZ` — and `worlds.ini` carries the
  authentic spawn: `GroundZero.world#Reception<>@1872,1229,150,125,0,0,-1`
  (position + yaw 125° about Z).

**Implemented**: `WorldViewer` with Z-up by default in exterior
(orbit about Z) and interior (yaw in the x/y plane, E/Q along the real up,
`--up 0,1,0` keeps the old math); `run-game.sh` with no args
opens an interior window at the real spawn looking at the kiosk
(`--eye 1872,1229,150 --look 1290,865,150`): the ini's 125° yaw
admits two turn signs (35° measured, not very informative —
distant frames; 145° similar), so the honest deviation is documented:
100% real position, direction = the one that shows content (kiosk,
25625 px/1077 colors) instead of an unverified sign convention.
The arrows allow turning anyway.

**Verified**: 25/25 rooms GL 0, coverage 47/47 intact, exterior
and interior renders regenerated with the correct orientation
(LizCave interior by default: 461433 px / 2850 colors inside the
cave). New evidence: `world_spawn_reception_kiosk.png` (spawn
view) and `world_spawn_window_desktop.png` (live window on Xvfb).
Window opened on the user's real display via plain `./tools/
run-game.sh` (log `/tmp/gz_boot.log`, "presented frame 0",
live process).

### 🟢 Rects: walls/floors/signs with texture — no more bones
### (2026-09-13)

Request ("don't make it just bones, with proper textures"): with only Shapes, the
rooms were skeletons — Reception: 12 thin objects floating in black.
Real cause: the actual content (walls, floors, signs) is
**`Rect` nodes (3D surfaces with material)**, 374 across all of
GroundZero (Reception 30, ReceptionView1 140, LizCave 42…), and the
parser was throwing their fields away while the viewer ignored them.

**Mirrored parse verified** (identical bytes, `END PERSISTER` intact):
`Rect.restoreState` gives the unit plane + u/v (+offsets depending on
version) and `Material.restoreState` gives ambient/diffuse/spec/opacity,
RGB color and texture URL (v2+; v0/v1 reference an unnamed `Texture` —
honest flat fallback). `WNode` gains `material`,
`matAmbient/Diffuse/Specular/Opacity`, `matColorRGB`,
`matTextureUrl`, `rectU/V/UOff/VOff`.

**Two findings with evidence**:
- The local plane is **X/Z, not X/Y**: the real matrices flatten Y
  (~0) and (1,0,1) reproduces the exact far-corner (f1,f2,f3) through
  the spin/scale — with X/Y, degenerate quads came out (lines, +187 px
  only); with X/Z, 25k→121k px at the spawn.
- The Rect textures are absolute URLs
  `http://www-static.us.worlds.net/3DCDup/GroundZero/dtex/*.cmp`
  (12, downloaded from the live server to `assets/.../GroundZero/dtex/`,
  68K versioned) or relative `tex/*` (with animation suffix
  `2h*2v*` in the style of `cbirda42h*2v*.mov` — real name before the first
  `*`, + strip of `\d+[hv]`). Coverage: **42/55 URLs** (187 refs);
  the remaining 13 are `.mov` (same codec, different container —
  `tableRegionSize` does not add up, documented as the next step).

**Render**: quads with real UVs (tiling via `GL_REPEAT`), double-sided
(no `MaterialModes` on Rects; `GL_LIGHT_MODEL_TWO_SIDE` for correct
N·L), normals read from the real modelview, materials with the
same white-base/ratio as the RWX pipeline. The kiosk sign text
("BIRTHDAY ROOM…") readable, not mirrored = UVs right. (Coverage
at the time 42/55 URLs — the 13 `.mov` arrived in the next session,
see below: today 55/55.)

**Measured**: Reception spawn 25k→121k px/1571 colors; RV1 196
objects/7428 tris (picnic area with floor, path, fences, grill);
LizCave interior 450k px/1259 colors; IconViewRoom1 15k→53k px.
25/25 rooms GL 0. Honest note: 147 flat Rects are a real teal
color from the stream (#00F7EF — verified `java.awt.Color(r,g,b)`, not a
default), and the diffuse response of Rects uses the ratio as in RWX
(strictly, diffuse=0 would leave them nearly black with our dim
ambient light — decision documented in the code).

### 🟢 .mov decoded + 100% texture coverage (2026-09-13)

Request ("many textures are still not loaded"): 13 `.mov` URLs
(19 refs) with no loader — same LzH2 codec, different container
(`tableRegionSize+groupRegionSize != payloadSize`, modes 0x82/0x86).

**Container resolved with evidence**: same header offsets
as `.cmp` (mode/flags/dims/lens identical in form); the table
region is much larger (multi-frame) and its size is NOT the u16 at 28
(922 for a real table of 3791) — it is located by the signature of the group
header (`field0==64`, verified 12/12 stills + unique per `.mov`,
including windr3 with `wanted[0]=624` and `h=154`). Only frame 0 is
decoded (static viewer; animation by `2h*2v*` UV-tiling
or multi-file f1-f8 is documented, not implemented).

**Official verification** (`cmpview.exe` + screenshots with multi-resolution
template-matching — the harness's fixed crop for
`.cmp` fails on movie windows, verified by hand):
`windr1` and `cbirda4` **16384/16384 byte-exact**; the remaining 11
show correct real artwork (f1-f8 flags in successive phases of
waving, blue bird, `...s.com` logos, interiors, walls). Two real
traps found along the way: the initial "black" ground truth
was a misfire of the harness crop (movie window ≠ still) —
not content; and a bug in MY probe (`setRGB` without `& 0xFF`,
which turned everything yellowish) — not in the decoder. Modes detail: `0x82` (10
files) direct; `0x86` (cbirda4, f3) needs index
255→white (transparent sprite background over cmpview's
white canvas — verified by color sets 149 vs 147).

**Palette**: byte12=0xFF in `.mov` is a genuine 255 (forcing 256
desynchronizes the cursor: `groupCount=0` — tried and reverted). The 5
`.cmp` with byte12=0xEC keep the literal count (159/159 intact).

**Final coverage, measured on the complete scene**: `Texture coverage:
47/47` + `Rect coverage: 55/55` (187 refs) — **zero textures
unloaded** in formats with a loader. Honest remainder: `.bmp`→`.cmp` of the
same stem when a twin exists (`cstgbs3.bmp`→`.cmp` verified in the
file; `pceil2.bmp` with no twin stays flat), `.mov` with an
anim suffix (`cbirda42h*2v*`→`cbirda4`, `time2h*`→`time`,
`winwin12h*2v*`→`winwin1` — a digit + h/v, the exact stem always
first), 12 `dtex/*.cmp` already versioned.

### 🟢 RectPatch: grass floors and ramps (2026-09-13)

36 `RectPatch` nodes in the file, all version 2 (verified by temporary
instrumentation, reverted): `xDim/yDim` + 4 `z` heights +
tiles + own `Material` (the apparent paradox of the version chain
resolved itself — only values are stored, the bytes
consumed are identical, zero desync risk). Geometric translation:
2×2 heightfield in local X/Y (`(0,0,z0)`,
`(xDim,0,z1)`, `(xDim,yDim,z2)`, `(0,yDim,z3)` — planar in the
corpus), v0 explicitly invisible and skipped. Real content:
green floor tiles #80FC00 in a 250 grid (Auditorium,
floor visible for the first time) and ramps ([0,0,-500,-500]).
Flat or null materials→the client's default black (honest, without
inventing). Counter and bbox integrated; 25/25 rooms GL 0.

### 🟡 "Most without textures": honest inventory + window in
### front (2026-09-13)

Repeated complaint with coverage at 100%: investigated in depth.
**Everything loadable loads and is seen** — panorama of 8 views around
the spawn (`docs/renders/world_spawn_panorama.png`): content with
real texture in all 8 directions (56k–199k px each), stone walls with
moss, kiosk with legible sign everywhere.

What IS missing is a **floor under Reception**: the file contains
no floor mesh there (measured inventory: 4 tall walls
z 600–1000, baseboards z 0–70, kiosk 0–355, and void below z=0;
`sky/groundColorRGB` null in all 25 rooms; no fog in
`Room/RoomEnvironment`). The void is authentic data, not lost
geometry — the "floor" pixel samples exactly the
background color. No room has a sky; no render decision
hides it. Inventing a floor would violate the permanent rule.

Real operational finding of the session: the window opened on
desktop 0 while the user works on 1 (VMware
maximized) — "it doesn't open" although it rendered perfectly. Fix:
`glfwFocusWindow` + `glfwRequestWindowAttention` on show
(`WorldViewer`), and `run-game.sh` auto-recompiles if there are sources
newer than the classes (goodbye stale "no textures" binaries).
Verified with `xprop`: window on desktop 1 with attention
requested (final focus is up to the user by GNOME's
anti-focus-stealing design — it has to be clicked in the dock if it doesn't pop up by itself).

**Closing the question (materials v4, all)**: given "there are still
things that don't load" it was verified whether the 187 flat Rects
were hiding a per-object texture (via `Texture` v0/v1): the 417
`Material`s in the file are **version 4** (URL path) — zero
v0/v1 cases, zero `Texture`/`ScapePicTexture` reachable from the graph. The
teal flats (#00F7EF ×108, #00FCF8 ×41) and grass (#80FC00 ×36) are
real flat color from the stream, not lost textures. With this it is
demonstrated by elimination that there is not a single unloaded texture in
the file: 47/47 + 55/55 + 0 per-object cases.

### 🟢 Infinite background with camera tracking (2026-09-13)

Request ("load the world with the background terrain"): the `infiniteBackground`
(skybox of `skyXX` walls + `sky12/nsky` ceilings, 34 Rects in Reception)
was already loading and being drawn (88 objects, Rect coverage intact), but with
a static transform it had near-object parallax, contrary to the official doc
(`Gamma_Overview.html`: "the scale never seems to change", "infinitely
distant" view). `WorldViewer.drawInfiniteBackground` translates it
by `(eye - ref)` in `--inside` mode (frame 0 = offset 0, md5-identical to the
previous render; exterior orbits unchanged). Verified with a temporary
drift test (+500x, reverted): the background holds while the foreground
shifts; GL error 0 throughout. `sky/groundColor` null in all 25 rooms = the
client draws nothing there (same doc); the dark clear stays as a documented
fallback. Detail in `docs/render-pipeline-reference.md`.

### 🟢 Launchable with a double click: `--detach` + menu icon (2026-09-13)

Request ("make it launchable"): `run-game.sh` always blocked the terminal
(window mode = foreground process) and there was no menu entry.
Now:

- `run-game.sh ... --detach`: launches with `nohup` in the background and gives the
  terminal back instantly (0.06s measured) printing PID + log; to quit:
  ESC in the window or `kill <pid>`. If I bring up my own Xvfb, it does not kill it on
  exit (its PID is noted in the log). Verified on `:100`: window
  with "presented frame 0", GL error 0, process cleanly killable.
- `tools/install-launcher.sh`: compiles if needed, windowless probe and
  writes `~/.local/share/applications/openworlds.desktop` (absolute
  paths, `desktop-file-validate` OK) so you can search "OpenWorlds" in the
  menu and play with a double click.

**Real bug found along the way**: `--list-rooms` was only recognized
as the viewer's first positional; the installer's initial probe passed it
in another position and opened a blocking window on `:0` instead of listing
(hung the installer). `WorldViewer` now accepts it in any position
and the installer probes directly without going through room parsing.

### 🟡 Infinite background: tracking reverted to optional (2026-09-13)

The infinite background's follow (previous session) was reported as a bug — "the
terrain outside follows the user when walking" — and the report is
correct: the ring is modeled to fit the room, it is not an infinite
shell, so pinning it to the camera drags along nearby decor. It is now
static by default and `--infinite-follow` enables it only when requested.
Frame 0 md5-identical in both modes. Detail in
`docs/render-pipeline-reference.md`.

### 🟢 Background as background + invisible bumpers: map reviewed from end to end
### (2026-09-13)

Request ("the background has to be a background, it's dumped in a corner" +
review the whole map + push to Codeberg). Two real fixes, both with
evidence from the original, no pixel invented:

1. **Infinite background with the camera at the origin**: only Reception and RV1
   have a background (23/25 empty, authorial); drawn statically it ended up
   thousands of units from the center (measured: offset -2561,-974 and
   -6253,+1019). `Gamma_Procedures.html` ("Infinite Backgrounds") says
   that the background is viewed from a camera at 0,0,0 and the author centers it at
   the origin — `drawInfiniteBackground` now translates the subtree by
   the live camera position. Spawn: cloudy sky + hills in all
   4 directions; RV1: full horizon; 25/25 GL 0; textures 51/51 +
   101/101. Replaces the two earlier follow experiments (the flag
   `--infinite-follow` disappears: this is not an effect, it is the documented
   rule). Limits: sky gaps without panels = void (original
   data); exterior orbit without background (outside the near, scale model).
2. **Invisible bumpers**: LizCave filled with teal = 41 `Rect942CyanBump`
   (it said 40; real count from the 2026-09-15 audit)
   (real teal color, flags=2, collision without visible). `WNode.flags` stores
   the real int (bit 0 = visible according to decompiled `WObject.getVisible()`)
   and the viewer skips invisible leaves when drawing/framing (never
   entire subtrees). Everything invisible is named `*Bump`; RectPatch v0
   carries flags=0 (double confirmation). Reception 0 invisible (spawn
   md5-identical); LizCave 48->7 objects.

Captures regenerated with the current code (the earlier ones were
obsolete): `world_{reception,iconviewroom1,lizcave,auditorium}_textured`,
`world_inside_{lizcave,auditorium,receptionview1}`, spawn kiosk (now
with sky). Detail in `docs/render-pipeline-reference.md`.

### 🟢 Background in two passes + avatars in rooms: the game runs (2026-09-13)

Request ("the background is dumped in a corner; make the game run,
so the avatar shows and everything is right"). Three pieces, all verified:

1. **Background in two passes** (replaces the `glTranslatef(camEye)`, which
   tied the subtree to the eye and made it "follow" when walking):
   pass 1 with its own camera at the origin + live orientation
   (`Gamma_Procedures`: "viewed from a Camera at 0,0,0"; origin inside the
   ring verified), pass 2 with the live camera (depth cleared
   in between). Reception spawn with hills E/W and sky in all
   directions, never in a corner, without touching file placement.
   Honest: no translation parallax (what the original documents).
2. **Avatars**: the 6 `avatar:` refs (galleries IconViewRoom1a/b/c/e/
   f/g) are drawn in bind pose with the 2 lights: `avatar:Roxanne.rwg`
   -> `base-avatars/roxanne.bod` (5/6 by name; Tre -> `aura.bod`,
   the client's real default). Scale x1000 documented heuristic
   (bod ~0.17 vs client ~189, `Drone.java:106`), feet at the node,
   +Y->+Z. Roxanne 2229 tris, Tre 588 via aura, 25/25 GL 0.
3. **The game runs**: `run-game.sh` with no args (Reception spawn) and
   `--detach` verified on `:100` (window, frame 0, clean kill).

Detail in `docs/render-pipeline-reference.md`.

### 🟢 Game mode `--play`: third person, floor, collision, avatar (2026-09-14)

Request ("I don't see any avatar, implement game mode now, not the free
camera but the game, plan it before doing it and use
subagents"). Planned with 4 subagents in parallel (current camera/input,
original client logic, world/collisions, avatars/3rd
person) before writing a line. All verified:

- **Third person** like the original (`HoloPilot` BEHIND/modes 3-8):
  camera behind the head (feet+150 = real `eyeHeight`, dist 220 =
  WIDESHOT), avatar `aura.bod` (real default) in bind pose with the 2
  lights. `RestartAt` spawn facing the kiosk. W/S walk, A/D strafe,
  arrows turn/pitch, ESC exit. `run-game.sh` with no args = `--play`.
- **Floor** as `Room.floorHeight` (highest floor <= feet+step 30,
  from `HoloPilot.stepHeight`); **collision** AABB x radius 30 (half width
  of the real bound box) with per-axis slide; speed 250 (between
  the real `maxdvLR=166` and `maxdvFB=300`). Reception: 14 floors, 28
  blockers, 8 portals. (2026-09-15 audit: the current log says 41
  blockers — those 28 Rects plus 13 AABBs of `.rwx` props, which were
  added in the kiosk fix of the next session.)
- **Verified**: spawn 89 objects/1 avatar/GL 0
  (`docs/renders/world_play_spawn_thirdperson.png` — Aura from behind
  in front of the kiosk, hills behind); IconViewRoom1a 7 obj/2 avatars/GL
  0; fly and ALL 25/25 no regression.
- **Limits**: heuristic .bod forward (it worked: it faces the kiosk);
  AABB not thin quads; portals only announced (phase 2);
  bind pose without animation.

Detail in `docs/render-pipeline-reference.md`.

### 🟥 Game mode broken and fixed in the same session (2026-09-14)

`--play` mode flew off when walking (`Player at z=2250`) — with
every reason on the user's side ("it doesn't work at all, no fucking way"). Root cause
verified with exact math, not assumed: `floorHeightAt`
returned its `z` parameter when there was no floor and it was called with
`z=feet+30` (+30/frame over void: 180+69x30=2250). Contract
fixed (returns the feet), plus: collision and floor for `.rwx` props
(the kiosk could be walked through; 100 tris in Reception, exact
barycentric floor), bumpers that always stop, no re-snap when embedded, window
focus for `--play`, per-frame counters. Verified: headless harness
800 steps (z pinned, stop at wall), batch GL 0, window
20s still with no drift. Detail in `docs/render-pipeline-reference.md`.

### 🟢 Avatar seen from behind (real facing) + animation mapped without inventing (2026-09-14)

Complaint ("it looks sideways"): correct — the rotation was a heuristic
90° off the real forward. Investigated with 2 subagents BEFORE touching
anything: anatomical forward is local +Z of the .bod (face/toes +Z, ponytail -Z),
measured in `SPIN.RWX` and bytes of `aura.bod`, with `RWXTOBOD.PL` passing
axes through untouched. Rotation `yaw-90` (algebra, not trial and error),
verified in capture (Aura from behind, ponytail centered).

Animation ("make it have animations... DON'T INVENT THINGS"):
extracted what is real — TWO systems (`Drone:359-364`): articulated
(`.bod`+`.seq`+`avatars.dat`, all the blending in native `DroneAnimator`)
and hologram (`.mov` = `LzH2` video). `.seq` header
verified (version, no. of joints, names: walk 44 mocap, wait 16,
wave 4). The per-joint key data is only decoded by `gamma.dll`: there is NO
invented playback (neither a procedural walk cycle nor bobbing) — that would be
exactly what is forbidden. Next step: Ghidra on
`DroneAnimator_animate/update`. Detail in
`docs/seq-animation-reference.md` (new).

### 🟢 THE ORIGINAL RUNS: genuine 2004 client under Wine (2026-09-14)

Request ("take the original"): done literally. `assets/WorldsPlayer`
has the complete runtime (JRE 1.4.2 `bin/java.exe`, `gamma.dll`,
`RWL21.DLL`, `lib/gammacls.zip`) and `run.exe` contains its own startup
command line — there is no longer any need to recompile anything pristine, the `.zip` IS
the compiled client:

`bin\javaw.exe -Xbootclasspath:lib\i18ncls.zip;lib\rt.jar
-cp .;lib\gammacls.zip NET.worlds.console.Gamma -home . -dllpath bin`

Two walls, both environmental (zero reverse engineering): Wine refuses
to create prefixes under `/tmp` (not owned by the user) → prefix in
`~/.wine-fw-orig`; the client aborts without `C:\windows\Fonts` → system
Liberation TTFs. With that: it loads the real `gamma.dll`, the `rwdlmd21`
driver, `awt.dll` hook, and presents **the real game**: complete UI
(Help/Options/WorldsMall/Teleport/Actions/VIP, FRIENDS ONLINE,
chat, logo), 3D Reception with real RenderWare (textured floor with
reflections, walls, hills, kiosk) and a real avatar. "Retry /
Single-user mode" dialog (no upgrade network: expected, honest).
`tools/run-original.sh` (new) automates everything: private copy to
`~/.openworlds-client` (the original writes logs/caches in its CWD and must
not dirty the repo), prefix+fonts+Xvfb if needed.
Capture: `docs/renders/original_client_reception.png`.

### 🟢 The game, decompiled and versioned: pristine Java + `gamma.dll` in C (2026-09-14)

Request ("I want you to decompile the game... do the original"): the
decompile existed but was NOT in the repo (`source/` ignored,
`analysis/` ignored). Now it is:

1. **Pristine Java** (`editor/.../source/`, 723 `.java`): regenerated
   with Vineflower 1.12 from `assets/worlds.jar` + `git apply
   patches/fix_compilation_errors.patch` (only compilation fixes).
   Zero `NativeMock`, declares the real `native`s, `Gamma.java` loads
   the real `gamma.dll`, compiles cleanly with `javac --release 8`.
   The nested `.gitignore` no longer excludes `source/` (it still excludes
   `out/` and `worlds.jar`). The mock flow is not broken:
   `apply_mock.sh` starts from this clean tree.
2. **Native in C** (`decompiled-native/gamma_dll/`, 6.9 MB): 1656/1656
   functions of the original `gamma.dll` with headless Ghidra + our own
   versioned script (`tools/ghidra-scripts/ExportAllDecompiled.java`),
   JNI exports with real names — including the 15 of `DroneAnimator`
   (the `.seq` decoder that is missing for real animation) and `huffdcod`
   (`.cmp` textures). `INDEX.txt` to cross-reference addr<->Ghidra.

### 🟢 macOS Intel without Homebrew: portable environment + Cocoa viewers (2026-09-15)

Request ("homebrew no longer supports Intel macs, see what you can
do"). Machine: Intel MacBook i5-7360U, macOS 15.7.9, system bash 3.2,
no JDK/brew/node/wine. Commit `b6f4df1` ("macos: setup + scripts portables")
had never run on a real Mac: four walls,
all environmental, zero render changes:

1. **`setup-macos.sh` without Homebrew**: portable JDK 25 Temurin (tar.gz
   from `api.adoptium.net`, SHA-256 verified) in `tools/jdk/`
   (gitignored, no sudo) + only the LWJGL natives of the architecture
   (`.sha1` from Maven Central verified). `run-game.sh` and
   `install-launcher.sh` prepend `tools/jdk` to the `PATH` (`/usr/bin/java`
   is a stub). node dropped (only the RWX harness uses it, already 118/118).
2. **X11 forced in the 5 viewers** (`glfwInitHint(GLFW_PLATFORM_X11)`):
   GLFW on macOS has no X11 backend and `glfwInit()` fails. Now
   `GlUtil.forceX11OnLinux()`.
3. **bash 3.2 + `set -u`**: empty `"${ARGS[@]}"` = "unbound variable"
   (verified in the Mac's bash) — it broke `run-game.sh LizCave` and
   `install-launcher.sh` with no args; undefined `$DISPLAY` killed the
   log header. Idioms `${A[@]+...}`, `${A[*]:-}`, `${DISPLAY:-}`.
4. `date -Is` does not exist in BSD `date`.

**Verified on the Mac** (Apple's legacy OpenGL 2.1, fixed function
intact): 25-room probe; `ALL` 25/25 GL error 0 with `Texture 51/51` +
`Rect 101/101` (same figures as on Linux); `--play` in a real Cocoa
window, played by the user (frame 0 presented, player walking with z
pinned to the floor, clean exit with ESC). `--play` capture against
`docs/renders/world_play_spawn_thirdperson.png` (same render code:
the only later commit in `client/src` is `SeqParser`, unused): NOT
bit-identical — 14427/786432 px (1.8%) differ, 88% with delta <=4 and
only 47 px >64. Difference mask reviewed, not just the
histogram: (a) the only compact zone is the strip of void under the
right baseboard = clear color `glClearColor(0.10,0.10,0.14)`, Mac
`191924` vs Linux `1A1A24` — 0.10x255=25.5 falls right in the middle and
Apple truncates to 25 where Mesa rounds to 26 (delta 1, blue 35.7 gives 36 in
both); (b) the rest are stray pixels and 1 px seams between
background texture panels. Driver rounding/rasterization (Apple
GL vs Mesa under Xvfb), not different content.
`run-original.sh` still cannot run here (no Wine). Minor, seen
in passing: in `--play` the "total rect references seen" counter accumulates
per frame (69000 = 69 x 1000 frames), same as the avatar one
fixed on 2026-09-14. Detail in `docs/setup-macos.md`.

### 🟢 AUDIT: the corpora re-run, three false claims and the
### animation reconstructed (2026-09-15/16)

Long session explicitly requested as an audit: **do not take the
numbers in the history as good, but re-run them** against today's code,
and then move forward. 6 read-only subagents were used in parallel (one
per format/piece, section 9) plus several working in
isolated worktrees.

**What was re-verified by running (macOS, portable JDK)**

| Claim | Result today |
|---|---|
| RWX 118/118 | The 118 `triangleCount` and `materialCount` on the Java side match the table. The JS side is **not reproducible**: `tools/node` is a Linux ELF |
| `.world` 25 rooms / 578 nodes / 103 objects / 374 Rect / 36 RectPatch v2 / 417 Material v4 | All confirmed |
| `.bod` 51/51 consumed + `orphans=0 badIndices=0` | Confirmed |
| `.cmp` 159/159 and `.mov` | 159/159 `.cmp` and **52/52** `.mov` decode without exception; the "byte-exact against `cmpview.exe`" **is not reproducible without Wine** and there is no stored ground truth |
| Deterministic Stage 2 | `test4b` 256/256, `sball` and `rustwood` 4096/4096 |
| Complete scene | 25/25 rooms, GL error 0, `Texture 51/51` + `Rect 101/101` |

**Three claims in the history turned out to be FALSE (corrected)**

1. **`SeqParser` (commit `bcd60fd5`, "verificado, leftover=0") failed on
   all 231 real `.seq`.** It read a "checksum" `u16` that does not exist:
   `FUN_00436d50` sums the K bytes of the dictionary in memory and
   stores them as the duration at `+0x214`. With that removed, and additionally
   translating the variant that the original diverts to `FUN_00436610` when the first byte
   is `0x7f` (big-endian, 37 `cachedir` files): **231/231**
   (`SeqExtractMain`, new and reproducible). The CB32/CB128 codebooks were
   in fact correct: 32/32 and 128/128 floats bit-for-bit identical to
   `gamma.dll`.
2. **The "z-fighting" of `cube.rwg`** (open since 2026-09-09) was not
   z-fighting or inconsistent winding: `VLST[0..7]` is the **bounding
   box** of the clump and the `PLST` indices count from record 8
   (`RWL21.DLL`: `RwGetClumpNumVertices` = count−8, `RwGetClumpVertex` →
   record n+7; 3466/3466 normals match counting from 8, 167 from
   0). Duplicated ±Z faces, "normals (0,0,0)" and "holes with culling"
   were the same bug. `e3.rwg` has 1371 vertices, not 1379.
3. **Avatar textures do not come from `cachedir/45.dat`** (that file
   does not contain a single `.cmp`/`.mov` string): they come from the **avatar name**
   (`PosableShape.createSubparts` + `readTexture`/`scanTexture` →
   `avatar:<name>.cmp` | `.mov`).

**Minor figures corrected**: LizCave has 41 `Rect942CyanBump`, not 40;
Reception gives 41 blockers today (28 Rects + 13 props from the
kiosk fix), not 28; not all `.bod` are 16 parts (`2v.bod` and
`death.bod`, identical, have 8). `docs/cmp-stage1-coverage.md` was still
the 0/159 baseline of `39e9f31c`: it was never regenerated.

**Avatar animation: from "there isn't a single line of parsing" to real pose**

Reconstructed entirely from the decompiled C and by disassembling `RWL21.DLL`
(detail in `docs/seq-animation-reference.md` §5 and §6.1):
key sampling with **nlerp** (not slerp), quaternion `(w,x,y,z)` with x
and y negated (`FUN_004290c0`), **the DLL's own name→tag table** (30
names; the mocap joints that are not in it are ignored: **there is no
44→16 retarget**), composition `LTM = Joint · Modeling · LTM_parent` in
row-vector convention (mode 1 = replace), and `prepFigure` = 180°
rotation about (0,1,1) + ×1000 scale, which is where the ×1000 and the
+Y→+Z that `WorldViewer` used as a heuristic came from. Key time: 1/30 s.
`BodViewer --seq f.seq --frame T` puts a `.bod` in the exact pose; without
`--seq` the captures are still md5-identical to bind pose.
Anatomical verification: `common_walk` frames 0 and 21 in opposition,
`axelwave` raises the left arm (its 4 tracks), `common_a_wait`
frame 0 = exact bind pose.

**Two gaps found in the project's own tools**

- The decompiled C **does not include** the 13 functions of the animation
  player's vtable (`0x00475200`): Ghidra did not detect them because
  they are only reached through virtual dispatch. They are precisely the time
  advance, the loop and the transitions — that is why `WorldViewer` is still in
  bind pose: implementing it without them would be inventing.
- Four viewers captured the framebuffer **after** `glfwSwapBuffers`,
  which on macOS produces black PNGs: a verification "with capture"
  could accept an empty render as good. Fixed in all four.

**Finding that unlocks avatar textures**: the tables that the
client requests from `ServerTableManager` (`permittedList`, `faceList`,
`humanList`…) **are already in the repo**, in
`assets/WorldsPlayer/tables/tables.dat` (45164 bytes, identical to
`cachedir/44.dat`): length `int32` + chained XOR
(`dec[i]=enc[i]^enc[i-1]`) → text with 12 tables, including **148
avatars with their encoded name**. It can be decoded without the network.

**Environment**: all of the above runs on an **Intel** MacBook without Homebrew
(see the previous entry and `docs/setup-macos.md`).

### 🟢 Network — reproduced on macOS: stable guest login, real wall of
### `Gamma.main` (ActiveX) and the threads with no blocking (2026-09-16)

Part of the same audit session (subagent in an isolated worktree,
integrated in `df4d7517`/`1c02e60e`/`199461e9`). Three results:

1. **Real guest login on macOS**: `tools/net-probe/run-guest-login.sh`
   (bash 3.2, no Linux paths, everything in a temporary directory) reaches
   **stable state 12 MAINLOOP** against `gippsland.worlio.com:8265` with
   the real PROPREQ → PROPUPD → SESSINIT exchange and the server's welcome,
   same as on 2026-09-10 on Linux. Xvfb is no longer needed.
2. **First wall of the REAL startup** (`run-gamma-main.sh`): the complete
   client with the mock loads cache, tables, avatar and room, and stops
   at a genuine `dAssert(false)` in `IUnknown.init` — the embedded
   ActiveX/Netscape control. It is the structural absence of COM outside
   Windows, not a badly placed mock: to continue down that path that component
   would have to be replaced, not a value corrected.
3. **`Cache`/`NetUpdate`** (the "thread block" that section 10
   left open since 2026-09-09): they run fine on macOS; the only
   blocking is by design (synchronous load on purpose and a `Thread.join()`
   with no timeout in `Gamma.main:221`). **There is no thread problem to
   solve.**

For login with a real account only the account is missing: exact requirements in
`docs/net-real-account-login-requisitos.md`.

Additionally, in the same session **881 functions** of
`gamma.dll` that the original dump did not have were recovered (only reachable via vtable;
`tools/ghidra-scripts/ScanVtablesAndExport.java`, Ghidra decompiler
compiled from source for macOS). With them the animation's time
controller was read: **30 keys per second**, mode 2 = loop
(`t % (duration+1)`), mode 1 = last key (`FUN_0043b950`/`FUN_0043b5f0`,
`SeqSampler.keyTime`). What remains to be reconstructed is which sequence and mode the
client picks at each moment and the transition blend.

### 🟢 Avatar name language decoded — and the wardrobe corpus
### is almost entirely lost (2026-09-16)

Part of the audit session (subagent in a worktree, integrated in
`c21319d1`..`01850240`; figures re-verified by running). Detail in
`docs/avatar-name-language.md`.

- **`tables.dat`** (`assets/WorldsPlayer/tables/tables.dat`, already versioned)
  is decrypted with `ServerTableManager`'s chained XOR and gives 12
  tables; `permittedList` carries 148 avatars with their encoded name.
- **Grammar**, ported from `PosableShape`: a name
  `avatar:<base>.0<program>.rwg` is processed in two phases. `findStarts`
  gathers a global palette of `T<n><name>` textures (`<x>.mov` sub-image
  n−1, or `.cmp` if n≤0) and `C` colors (`colorTable` or base64 RGB), and
  then **17 limbs with fixed tag and parent** are assembled (P01 root, B02←P,
  N03←B, H04←N, L11/M12/O13, R06/U07/V08, I19/J20/K21, W15/X16/Y17,
  Z24←P) that load parts of `<base>.bod`, with scale `S`, `.bod` change `G`,
  subclumps and timed material changes (the
  **expressions**: e.g. `willy` blinks with 4 changes every 3648 ms).
- **Verified**: 146/148 names without anomalies and 0 exceptions; the 2
  anomalies (`achoo`, `tas`) are typos of the table itself and the
  decoder does the same as the client. `AvatarNameMain --todos` reproduces
  it.
- **Important preservation fact**: of what those 148
  avatars reference, the repo only has **14 of 210 textures and 25 of 141 `.bod`**.
  The 14 textures are `.mov` from `base-avatars`; none of the `_dt*` of the
  paid wardrobe exists. `cachedir/` does not count because without its
  `cache.index` there is no way to know which URL each numbered file is.
- In passing, a belief of the document is corrected: the default URL
  `avatar:aura.0PG.rwg` gives an empty figure (the `.bod` is resolved
  by another path), and `faceList`/`humanList` do not take part when building the
  avatar, only in customization (`WearWall`, `AvMenu`).
- **Pending**: apply the textures in `BodViewer` (good first case: the
  face of `willy`, sub-image 0) and decode sub-images > 0 of `.mov`.

### 🟢 Real portals in `--play` and avatar textures in the viewer
### (2026-09-16)

Closing of part 3 of the audit session (two subagents in a
worktree, integrated and **re-verified by running**):

- **Portals** (`1f160724`, `04516925`): `WorldRestorer` no longer discards the
  connectivity of `Portal` v8/9 (`farSidePortal` is an object
  reference, not a name) and `WorldViewer --play` changes room when crossing,
  with the formula of `Portal.recomputeFarPosition()` and reloading floor,
  collision and background of the destination room. GroundZero: 87 portals, **56
  connected** within the world, 2 to other `.world` files, 29 disconnected in
  the data itself. Re-run: from the Reception spawn to
  `EastPortal1Reception` one arrives at **ChatHall at (0,750,0), yaw −π**
  (a pass-through room with 4 surfaces and 0 objects: the dark view is its
  real content). ALL 25/25 regression unchanged. Limit: sign of the arrival
  yaw deduced, not executed (native `getYaw()`, no Wine).
- **Avatar textures** (`76febbac`): `BodViewer --avatar <name>` uses
  the name language decoder to give each limb its color
  or texture (the client's material constants, real UVs of the `.bod`,
  sub-image 0). Without `--avatar` the captures are md5-identical; with it the
  head of `willy` shows its face from `willy.mov` (the 515 pixels that
  change are all on the head). `ogre` asks for sub-image 3: it is
  reported as not applied.
- **Animation time** (`bb1b6c47`, `e70178d9`): 30 keys/s and loop/last key
  modes, `BodViewer --seconds S [--hold]` verified by md5 against
  `--frame`.

What remains in order to see avatars **animated and textured inside the
world**: decide which sequence applies (the original's implicit `walk`/`wait`
choice is not reconstructed) and bring pose and textures from `BodViewer`
to `WorldViewer`.

### 🟢 The original client starts on macOS with a portable gamma.dll/RenderWare bridge (2026-09-17)

Goal: a build that works and starts **based on the original
game**, reinventing nothing. Instead of `client/`'s own engine,
the real `main` of the decompiled `NET.worlds.console.Gamma` is run and the
natives of `gamma.dll` are replaced by translations of its decompiled C;
underneath, the RenderWare 2.1 `Rw*` calls are translated from the
disassembly of `RWL21.DLL`. All of it is in
`editor/worldsplayer_source_editor-main/bridge/` (see its README with the
evidence addresses), is applied from `apply_mock.sh` and is built
and launched with `build_gamma.sh` and `run_gamma.sh`.

- **Matrices** (`NativeRw`): row-vector product, modes 1/2/3, rotation
  in degrees (transposed Rodrigues, confirmed at 0x1001cb20), affine
  inverse via the adjugate, orthonormalization and `RwQueryRotateMatrix`. The 20 natives
  of `Transform` and `Point3Temp` follow gamma.dll's C, including
  `getYaw`, `getPitch` and `getSpin` with their constants read from the binary
  (180, 0.5, 1/π, 90, 360).
- **Scene** (`NativeScene`): clumps with base-1 vertices, polygons,
  hierarchy, LTM `Joint·Modeling·LTM_parent`, world-space bbox, tags,
  state ON=2/OFF=1, default scene, lights and materials with the
  RWL21 default values. Also the gamma.dll wrappers with their own
  logic: hierarchical visibility with callbacks 0x4185d0/0x418600,
  flat/smooth shading and `Surface.addSubPolys` (tile subdivision
  with U/V flip).
- **Windows, ActiveX and assertions**: `findWindow` and the child windows
  over the real AWT windows; `ActiveX.getClassFClsID/ProgID` throw the
  `IOException` with gamma.dll's literal message
  (`nActiveX.getClassF…: Couldn't convert string to CLSID`); the native
  assertion prints `Assertion failed: line N in file F.` and exits with 41.
- **Real decompilation error**: Vineflower left in `Room` a call to
  `add(WObject)` where the original bytecode calls `add(SuperRoot)`, which
  put the environment into the scene twice. To rule out more cases
  like this, `tools/bytecode-call-diff.py` compares the targets of all the
  calls of the 736 original classes (`lib/gammacls.zip`) with the
  recompilation: 55 methods remain with harmless differences (narrower
  receivers, try-with-resources `close()`, mock layer) and only
  this error.
- **Fixed in passing**: `tools/net-probe/run-gamma-main.sh` left the JVM
  orphaned (killing the subshell did not kill java); it now uses `exec`.

**Verified by running**: clean build of 747 classes; `run_gamma.sh`
stays alive 40–60 s in `Main.mainLoop` (confirmed with `jstack`) with
~2 M frames, no exception and no orphaned process.

**Limits** (⚠️): **nothing is visible yet**: `Camera.renderScene`,
`Texture`/`FileTexture`/`ScapePicTexture`/`ScapePicMovie` and sound
are still log stubs, and the loop runs without a brake because in the
original the render set the pace. Pending extraction: `RwDestroyScene`, the flag that
chooses texture modes 2 or 6 in `FUN_00419000`, the driver's maximum UV and
the −7..0 indices of `RwGetClumpVertex`. The natural next step is
to translate `Camera.renderScene` and the texture path (the `.cmp` decoder
of `client/` already exists) to draw in the child window.

### 🟢 Original client without network: local server, 2004 cache working, and cause of the 7 missing textures (2026-09-18)

**Problem.** `run_gamma.sh` started the decompiled original client and everything
it requested (avatars, tables, scripts) went to `upgradeServer=http://us1.worlds.net/3DCDup`
(`worlds.ini`), a host that no longer exists: timeouts and `Unable to load texture …`.

**Fixed** (commit `92d1e767` + this one):
- `tools/local-upgrade-server.py`: local HTTP server (Python only) that serves
  `assets/WorldsPlayer` under `/3DCDup/` and, under `/3DCDup/avatar/`, the official
  base avatars from `assets/gammatutorial-samples/base-avatars/` (= `AVATARS.ZIP`
  of `Worlds1900.exe`, verified identical), case-insensitively
  (the client requests `pengo.mov` and the file is `PENGO.mov`). Everything else gets an
  immediate 404. `run_gamma.sh` starts it on a free port, rewrites
  `upgradeServer` in the temporary copy of `worlds.ini/dst` and kills it on exit
  (`OPENWORLDS_NO_LOCAL_SERVER=1` disables it).
- `build_gamma.sh` patches (only in the build copy, `source/` stays pristine)
  `Cache` and `CacheEntry.load`: the 2004 `cache.index` stores Windows paths
  (`C:\DOCUME~1\…\cachedir\5u.mov`) and `CACHE_DIR` used `\`; on macOS the index
  would not load and was discarded. It now loads (211 entries) and those already downloaded are not
  refreshed against a nonexistent origin. `run_gamma.sh` starts from a clean `cachedir`
  (an orphaned `cache.open` discards the whole index).
- Measured effect (35–40 s in `home:GroundZero/groundzero.world`): 406 → 56 lines
  `Unable to load texture`; the requests for `.bod`/`.mov` of base avatars
  (`julie/roxanne/simon/jing/paul.bod`, `pengo.mov`…) and `avatars.dat` go to
  200; only 404s remain for what exists nowhere.

**Root cause of the 7 textures (`cfemaleb`, `cfemaleba`, `cfemalec`, `cfc`,
`fga`, `fja`, `mga`) — with evidence, NOT avoidable without the asset:**
1. They are requested from `Material.loadTextures` ← `Shape.recursiveAddRwChildren` ←
   `Room.aboutToDraw` ← `Portal.rwPrerender` ← `Camera.rwRenderRoom`
   (real trace with the instrumented build). They are not requested by the UI or a
   preload list: they are `PosableShape`s that are already **inside rooms of the world**, and
   they are loaded when drawing the chain of portals from the spawn.
2. Those rooms are the avatar galleries of `GroundZero/groundzero.world`,
   `IconViewRoom1a…1g` (each with a `PosableShape avatar:<Name>.rwg`
   and a `ClickSensor SelectAvatar<Name>`). Measured attribution:
   Roxanne (`IconViewRoom1a`) → `cfemalec`, `cfc`, `fja`; Simon (`1b`) → `mga`;
   Julie (`1f`) → `cfemaleb`, `cfemaleba`, `fga`.
3. The texture name is not in the `.bod` or in the world: it is given by
   `permittedList` of `tables/tables.dat` (encrypted with chained XOR, reader
   verified in `client/…/ServerTables.java`). `PosableShape` resolves
   `avatar:Julie.rwg` with `permittedHash` to the full string
   `julie.0ET2cfemalebT4cfemalebT3cfemalebaT1cfemaleb…T3fga…`; each
   `T<n><name>` (`PosableShape.scanTexture`) is a texture group
   `<name>.mov`. It is the avatar code scheme (`T#…`, `C_…`, `S…`).
4. Why they are missing: the 2004 `cachedir` only contains the textures of the
   avatars that installation got to see (Tre `mia`, Paul `mfa`, Jing
   `cfemaled`…). Julie, Roxanne and Simon were never loaded; their texture lived
   only on the server. They are not in `assets/`, `AVATARS.ZIP`, `FIRST.EXE`
   (684 files), `GROUNDZERO.EXE` or `worlds.jar`.
5. Consequence: **known limitation, non-blocking**. `Material.loadError`
   only prints; per the code the limb keeps the base color material from
   `scanTexture` (not checked visually); there is no exception in the log. No filler texture is fabricated. No configuration
   setting avoids the request without touching logic (the rooms are
   world content). It will only be resolved by recovering those 7 `.mov` from an
   external archive (Wayback or other); it would be enough to leave them in
   `assets/gammatutorial-samples/base-avatars/` for the local server to
   serve them.

**`WorldScriptGroundZero.class` (404): cosmetic, and pre-existing.**
`WorldScriptManager.worldEntered` tries to load the world's Java class
from `<upgradeServer>/GroundZero/`; it is not in `content.zip`, `gammacls.zip`
or `worlds.jar`. `loadClass` returns null, the `NullPointerException` is
caught (`catch Exception`) and `currentScript` stays null: only the optional
`roomEnter/roomExit/onEachFrame` hooks of that script are lost. The
`Gamma.Log` of the real 2004 client under Wine (`assets/WorldsPlayer/Gamma.Log`,
lines 70–73) shows exactly the same sequence
(`Download error … → Could not load script … → Exception constructing world
script: NullPointerException`), so it is the original behavior with the
server down, not a bridge failure.

### 🟢 RWL21/RWDL6D21 decompiled + hunt for the "everything looks wrong" in GroundZero (2026-09-19)

**What was being sought**: "in GroundZero, which is the middle of the map, everything
gets buggy". With no reference capture, it was attacked by elimination, measuring.

**Hypotheses discarded with evidence** (each one would have been a real bug):
1. *Invisible bumpers drawn* (the failure that already occurred in the
   project's own viewer). `Rect24cya` smelled like a cyan bumper. Instrumenting `Room.aboutToDraw`
   to walk the tree and compare `getVisible()` with
   `NativeScene.getClumpState`: **0 invisible objects turned on in the 17
   rooms** walked from the spawn. `WObject.updateVisible` turns the
   hierarchy off correctly.
2. *Nonsensical UVs* (texture repeated dozens of times = noise). Measured
   per polygon: `du≈0.4–1.2` over polygons of 4,000–15,000 px, i.e.
   **magnified** texture, not minified.
3. *Broken translucency dither*. The tables `0x10079240/0x10079280` give
   a perfect 8×8 Bayer matrix (64 distinct values, coverage
   16/32/48 of 64 for opacity 64/128/192) and **no** large material of
   the scene is translucent.

**What was verified to be fine**: Reception, LizCave, ChatHall and
Auditorium rendered with the bridge **match the project's own viewer**
(same floor, same textures, same darkness in ChatHall — the "mottled"
wall is the real texture, it comes out the same in the independent
OpenGL renderer). ~50 fps per camera. The gray slab that seemed to float is a
door leaf (`Rect24cya` of `WObjTemDrA1..4`, `IconViewRoom1Enter`) with
gray material 150 with no texture **in the world data**, and it stays fixed
in world coordinates (12,125,125) while the camera moves.

**New diagnostic** `-Dopenworlds.dumpWindow=DIR`: dumps the tree of
AWT components of the whole window. Without it there was no way to review the
UI (this machine has no macOS screen-capture permission, and the
`printAll` PNG comes out black because the UI is heavyweight AWT components
painted by the native peer). Result: correct layout —canvas 468×244,
`FriendsListPart`, `AdPart`, `MapPart`, chat 280×100 and input field,
with no zero-size or hidden components.

**The real unblocking**: the two missing binaries were decompiled,
which were the reason several bridge things were
conjectures (`ghidra headless` needs `JAVA_HOME=tools/jdk/Contents/Home`
or it aborts with "Unable to prompt user for JDK path"):
- `RWL21.DLL` → **1131 functions, 0 failures**, and since the DLL exports
  symbols, **795 with their real API name** (`RwGetPolygonMaterial`…).
- `RWDL6D21.DLL` (16-bit driver) → **385 functions, 0 failures**.

**First use, two conjectures fewer in the rasterizer** (see
`bridge/README.md`): the polygon normal is a fan of cross
products from the first vertex (`0x10001100`), not Newell; and the vertex
normal is the unweighted sum of the adjacent faces with fallback to the
**first** face when it cancels out (`0x10041df0`, threshold `0.0f` read from
`_DAT_100522e8`) — the bridge left a zero vector, which turns off the light at that
vertex. Measured: 0 degenerate cases in Reception and identical frame, i.e.
fidelity with no visible change there.

**Still open**: no visual failure attributable to the
bridge has been reproduced; a capture from the user of the specific moment is needed. And the
real draw order (BSP `0x1002cae0` + per-clump tree `0x10033750`)
is still approximated with z-buffer, but **no longer for lack of the binary**: read
superficially, the tree is built once per clump and groups by material,
so translating it would mostly change the z-fighting between coplanar surfaces.

### 🟢 Roadmap executed with subagents: H0-H5 merged (2026-09-22 → 2026-09-26)

`docs/roadmap.md` was prepared and executed with agents in separate
worktrees (file ownership per agent, patches per subsystem
`bridge/natives-<x>.patch`). Each branch was reviewed before merging,
checking in the ASM the key claim (cited in each merge). Cutoffs
by usage limit were resumed from the last commit of each branch.

- **Build broken since merge `71648da`** (an old branch that duplicated in
  `apply_mock.sh` what `natives.patch` already did): fixed; in addition
  `build_gamma.sh` now fails when `javac` fails.
- **H0**: `tools/verify-corpus.sh` (RWX 118/118 also against
  `three-rwx-loader`, reproducible for the first time on macOS with
  `tools/node-macos`), `tools/run-checks.sh` and `tools/progress-panel.py`.
- **H1**: textures (COLORONCOLOR, not HALFTONE; `RwReadTexture`,
  `RwGetNamedTexture`, `StringTexture`); `.rwg` read from RWL21 in ASM
  (header = list of textures, PLST with material index, `cube.rwg` does not
  load in RW 2.1, empty ATOM = valid clump); driver rasterizer
  (reciprocal table, perspective every 16 px, per-clump tree,
  `addSubPolys` with x/u of vertices 1-2 because Ghidra's C is wrong).
  The scene BSP is documented in ASM and untranslated.
- **H2**: DroneAnimator fully translated; the rule (walk/wait/endwait with
  deadlines 10/30/10 s, walk by distance, 250 ms blend, truncated key)
  is in `docs/seq-animation-reference.md` §7. In GroundZero the animator already
  receives `moveto`/`update`, but there are only statues that spin.
- **H3**: whirl compiled (Rust via rustup) and started on 127.0.0.1: login,
  same room and chat between two original clients. They cannot see each other because whirl does not
  send APPRACTR (`hub.rs:246` commented out). Found the `_connectThread`
  race of the 2004 client (not patched).
- **H4**: our own client uses `CmpFrames` (the old path showed the
  last frame of the 52 `.mov`). A `.mov` is Material cells and what
  changes over time is `AnimateAction`. Portals 53/87 like the original
  (`_p2pxform` + `getYaw`). Real animation in `WorldViewer --play`.
- **H5**: UI (1.0 events in TextField under JDK 25, so chat works with
  Enter; `Console.encrypt/decrypt`, cursors, context menu…), system/COM
  (portable `RegKey`, `SystemInfo`, `VehicleShape`) and sound/web (WAV/MIDI
  with the binary's volume, IMA ADPCM, IE/DirectShow/CD through their
  failure path, URLs only on click and with `-Dopenworlds.openUrls=1`).
- `IniFile` mock case-insensitive and persistent, like kernel32:
  the client writes its `Gamma.Log` and "Remember password" persists.

What remains and why, in `docs/roadmap.md` (§1b) and in
`editor/worldsplayer_source_editor-main/bridge/README.md` (Pending
verification).

### 🟢 Package with launcher, GitHub CI and the engine reviewed: menus, lag, portals (2026-09-26)

User request: "there are no menus, it's super laggy, visual errors";
review the critical parts (the engine), packaged GitHub builds that
do not depend on the startup scripts, and provision the machine. First
session in a **Linux x64** container (Claude Code on the web): the original
client under the bridge runs without Wine, with Xvfb for the window.

**Bridge (2004 original client):**
- **Menus that did not show up.** The button panel (Help, Options, Teleport,
  Quit, universe map…) is painted with `ImageCanvas.loadLocalImage` →
  `Toolkit.getImage("u:/…/rtpanel.gif")`: the path comes from the `URL` patch
  (synthetic `u:` drive and lowercase), and outside Windows that file does
  not exist. `HostPath.of` strips the drive and resolves case-insensitively;
  `bridge/host_paths.py` applies it to the 151 file opens and `Toolkit.getImage`
  of 50 classes (only in the build copy). In passing, what the bridge's
  README said is corrected: the `redir.txt` error was not the original's (its
  `Gamma.Log` does not have it), it was this.
- **Black window on startup.** `Std.initSyncTime` opened a `Socket` with no
  timeout to `time.worlds.net:37` in the first frame (requested by
  `BlackBox.postrender`), on the render thread. The base now comes from the
  system clock with the same subtraction as the bytecode (`ldc2_w -1141367296l; lsub`,
  the overflowed `100*365*86400` of the original) and the server, if it responded,
  corrects it from a thread with 2 s timeouts.
- **Fonts.** The installed JRE 1.4's `lib/font.properties` resolved
  `dialog`/`sansserif` to Arial, `serif` to Times New Roman and
  `monospaced`/`dialoginput` to Courier New. With the modern JDK's, the status
  bar cut "Use arrow keys" to "Jse arrow keys". `NativeUiFonts`
  (+ `bridge/ui_fonts.py`, 72 `new Font` in 49 classes and the default
  font of `GammaFrame`) uses those or ones with equal metrics (Liberation).
- **Lag.** The driver rasterizer now records the triangles of the
  clump pass and draws them in horizontal stripes across several threads;
  each stripe walks the whole list, so every pixel receives the same
  writes in the same order. Also: allocation-free clipping, spans that
  only interpolate what the pixel path uses, and 565→RGB dump
  by table. Measured: 13.5 → 9.4 ms with 1 thread and 4.7 ms with 4 (1172×848); the
  real client goes from ~25 to ~53 fps at 1172×848 and from 72 to ~90 at 468×272.
  **`RasterGoldenCheck`** (new): 56 real `.rwx` shapes of GroundZero with
  their textures and quads that force each path (lit texture, Gouraud,
  flat, translucent, double-sided), 18 views in 3 sizes; the CRC is
  identical to that of the previous engine with 1, 2, 4 and 8 threads.

**New engine (`WorldViewer --play`):**
- **Appearing and looking like the original.** `WorldRestorer` read and discarded
  `Room.defaultPosition/defaultOrientationAxis/defaultOrientation`; now they are
  stored and the spawn does what `TeleportAction` does (`moveTo(pos).spin(axis,
  turn)`; the pilot looks at +Y with turn 0, heading = 90 + s·turn for the axis
  (0,0,s)). Measured in the bridge: AvatarEnter (261 about −Z) looks at
  (−0.97, −0.15) and Reception's `RestartAt` (125 about −Z) at
  (0.81, −0.56). Before, all rooms appeared at Reception's point
  (outside the room) and Reception looked at the kiosk (−148, set by hand).
- **Camera.** That of the mode the original starts with, `HoloPilot`
  `CAM_MODE_BEHIND`: 140 behind, −10° (in the bridge: 137.9 horizontal and
  +24.3 = 140·cos 10 / 140·sin 10) and moving closer if there is a wall (the original's
  camera is *bumpable*). Before, 220 with no collision.
- **Portals that are visible.** Translated from the original's portal pass
  (`Camera.rwRenderRoom` → `Room.prerender` → `Portal.rwPrerender`): portal
  in state 2, visible (flags bit 0), facing the camera (formula of
  0x0041b3b0), screen rectangle, camera moved by `_p2pxform`, far
  room drawn before the near one and **without clearing the color** (the nested portal
  ReceptionView1 → ReceptionView2 lets the panorama show through). The
  cameras of ChatHall, ChatElevator, DcnEnter, ReceptionView1 and
  ReceptionView2 come out identical to the decimal as in the bridge. Depth 3
  (the original goes up to 10). No mirrors yet (flags bit 2).
- **One-sided `Rect`**, like the driver: the back face is discarded if
  the material does not have `MaterialModes` double (`!front && (modes & 0x80) ==
  0`), and the world's materials do not set it. Drawn double-sided, the
  ReceptionView1 building seen from behind hid the landscape and there were
  mirrored signs.
- **Pause menu and HUD** (ESC: Continue, Go to another room —all 25, by the
  same path as crossing a portal—, FPS, Help, Quit), with a
  Java2D text atlas in headless mode (no AWT window fighting GLFW on
  macOS).

**Package and CI:**
- `launcher/` is the package's entry point and replaces
  `run_gamma.sh`/`run-game.sh`/`local-upgrade-server.py` for playing:
  window with menu (original client with world, server and user; new
  engine with room; drawing threads; FPS; live log), terminal menu
  (`--tui`, or only if there is no display) and CLI (`--original`, `--viewer`,
  `--server`, `--smoke`…). Persistent copy of the installation in the
  user's data folder (the `worlds.ini` with friends and
  password is preserved), local update server in Java and each client in
  its own JVM with the package's Java.
- `tools/build-dist.sh`: portable package (.zip, Java 17+) and, with
  `--app-image`, the app with bundled Java (jlink + jpackage): ad hoc
  signed `.app` on macOS, folder with `OpenWorlds.exe` on Windows,
  `.tar.gz` on Linux. `tools/fetch-lwjgl.sh` downloads LWJGL with SHA-1 and
  retries (Maven Central gives 429 if asked too quickly).
- `.github/workflows/build.yml`: on every push it builds, runs `run-checks`
  (38/38) and the complete `verify-corpus`, starts the packaged original under
  Xvfb (it must print camera and fps: it has drawn) and uploads the portable and
  the apps for Linux, macOS Intel, macOS Apple Silicon and Windows; with a tag
  `v*` it publishes a release. First failure: jpackage on macOS requires the
  version to start with ≥ 1 (`1.0.<commits>` is used). The same smoke test
  with each app's Java (run #5): GroundZero draws on macOS Intel,
  macOS ARM (62 fps) and Windows (102 fps), with the camera at (230,180,170)
  looking at (−0.97, −0.15, −0.17) as on Linux; from there on it is mandatory.
- Provisioning: `tools/setup-linux.sh` (idempotent: packages, JDK,
  LWJGL, RWX harness, builds both clients) and the `SessionStart` hook of
  `.claude/` for web sessions (15 s warm, ~50 s cold).

**Found and not fixed from here:** `cachedir/cache.index` never
entered this git history (it stopped being versioned on 2026-09-09 as
"bookkeeping" and is in no commit nor in any zip of the repo). Without
it, `Cache.initLoad` ("Flushing cache index.") **deletes** the 207 cached
files of the working copy (measured in the package: 31 remain, the ones
that are downloaded again from the local server), so in a clean clone, in
CI and in the packages the cached 2004 avatars come out without texture. The
only copy is on the user's Mac; it is no longer in `.gitignore`.

**Second part of the same day — the new engine catches up with the original in color
and the bridge loses a matrix bug.** With the viewer's camera equal to
the bridge's to the decimal and the same aspect (`-Dopenworlds.windowSize=468x272`),
captures were compared column by column and with difference maps:

- **New engine's light.** It was very dark due to three things: GL's lights
  were set once with the identity view (they were glued to the camera),
  the `Rect` normal was transformed twice, and GL never goes past the material's
  color, whereas the RWDL6D21 driver's ramp (FUN_10008d00)
  lightens toward white above 0.75 of the scale. Also, 586 of the
  699 surfaces of the world are "self-lit" (ambient ~0.75 with no
  diffuse: FUN_00417950) and the original paints its texture as is.
  `DriverLight` does what the bridge does: two lights per room in the space of
  each object (with the inverse: a wall scaled 2149×2×400 receives d ≈ 1,
  not the world cosine), the intensity `31 amb + Σ 31 lc (dif d + spec
  S(d))` and the ramp, in GL as `texel·P + S` with `GL_COLOR_SUM`. The RWX
  now stores what RW uses (ambient 0 if the script does not set it, like
  `RwCreateMaterial` 0x1001b340; `LightSampling`; shared per-polygon and
  vertex normals; the script's `Normal`s). Result: ceiling
  (214,210,181) in the bridge and (208,208,176) in the viewer.
- **Surfaces.** UVs from `Rect.addRwChildren` (97 walls with non-integer
  repetition came out shifted), `addSubPolys` cells with alternating
  mirroring, 4-triangle `RectPatch` with a center, `Billboard` fences
  (`new Material(adworlds.cmp, h, v)`: each cell with the whole file,
  like `Material.syncBackgroundLoad`) and portals up to 11 levels
  (`rwDepth <= 10`; with 3, Reception at the back of AvatarEnter could not be seen).
- **Bridge bug: matrix product.** The Auditorium's stanchion with ropes and the
  iris door of IconViewRoom1Enter showed up in the viewer and
  not in the bridge. A new dump of the clump tree
  (`-Dopenworlds.dumpScene`) showed `WObject2` at (0,1000,0) and its child
  `ShapeStand` at (0,0,0): the fourth column of the `.world`'s `Transform`s
  carries RW-internal data (0x03ddff04, 0x02890088 read as float,
  `m[15] = 2e-37`) and the bridge multiplied 4×4, whereas
  `RwMultiplyMatrix` (0x1001db10 → 0x1005118c) is affine and does not touch it. Everything
  hanging from a container `WObject` (30 in GroundZero) fell at the origin
  of the room in the original client. Fixed with the same order of sums
  (bit-for-bit equal with clean matrices). It is confirmed that the viewer
  was right in both cases, and that the bridge is not a pixel reference
  until we have captures under Wine.

`DriverLightCheck` and `MatrixAffineCheck` (hand-made cases); `run-checks`
40/40; `verify-corpus` with no failures. Pending in the new engine: mirrors,
`MoveAction` (the iris door opens when crossing Reception's portal) and
the per-vertex light of the avatars.

**Third part — sweep of the 25 rooms.** With the same method (viewer pose
inside the room passed to the original by URL, `#Room@x,y,z,turn,0,0,-1`),
the differences that remained were from two engines at once:

- **Bridge, material of the `.bod` parts.** gamma.dll FUN_0041d950 does
  `RwSetMaterialSurface(mat, 0.32, 0.55, 0.0)` (floats from `DAT_00470ac4`,
  `DAT_00470ac0` and `DAT_00470abc` read from `.data`) and `FUN_00417a10`
  (per-vertex light); the bridge had (0.75, 0, 0) faceted and the statues
  came out flat.
- **New engine, avatars.** Per-vertex light per part, like
  `RwCalculateClumpVertexNormal`; the same material; and the lost wardrobe
  (`cmalea*`, `mfa`…) at `colorTable[3]` = (255, 102, 51), which is the color
  with which `PosableShape.scanTexture` creates the material before trying the
  texture. That is why the gallery statues come out orange in the
  original, and now in the viewer too.
- **Found, unchanged:** the original's `Room.floorHeight` only uses
  the `RectPatch`es of the room's content and returns 0 if there are none. In the
  gallery rooms the visible floor is at 40 and there is no `RectPatch`, so
  the original's pilot walks sunk 40 (seen in the bridge camera's
  height: z = 164 instead of 204). The viewer relies on the visible
  floors and on furniture; copying it is a gameplay decision, not
  a drawing one.

### 🟢 A single engine: the new engine is out (2026-09-26)

The user asked why there were two engines ("I didn't ask for that") and,
after the explanation, asked to remove absolutely everything of the new engine, launcher
included, and push it.

**Where they came from.** The new engine (`client/`, own parsers + LWJGL)
started on 2026-09-09 (`fa5e52d`) for goal 2 of CLAUDE.md; the original
client's bridge, on 2026-09-17 (`a79efdd`). The 2026-09-22 roadmap
(`76ff86f`, section 1) left the A/B choice to the user and it was never
closed; in the packaging session work continued on both and the
launcher offered them side by side ("Play" / "Explore").

**Removed** (everything is in the git history up to `8cd795d`):
- From `client/`: the renderer and the viewers (`render/`), the readers of
  `.rwx`, `.world` and avatar names (`rwx/`, `world/`, `avatar/`), its
  animation and its checks (`DriverLightCheck`, `AvatarAnimCheck`,
  `MaterialTilesCheck`, `PortalLinkCheck`, `TextureActionsCheck`).
- From the launcher: "Explore", options 3-4 of the terminal menu
  (explore room / choose room), `--viewer`, the settings' room and the
  package's `openworlds-client.jar`.
- `tools/run-game.sh`, `install-launcher.sh`, `fetch-lwjgl.sh` and
  `rwx-harness/`; LWJGL and node from CI, from `build-dist.sh` and from
  provisioning; `docs/render-pipeline-reference.md`,
  `docs/rwx-parser-progress.md` and the 50 captures of the new engine in
  `docs/renders/` (the original's remains).

**Moved, not removed:** `bod/` (`.bod` and `.seq`), `rwg/` and `cmp/`
(`.cmp`/`.mov`), with their checks, to `formats/`: the bridge imports them
(`SeqParser`/`SeqSampler`, `BodParser`/`BodClump`, `RwgParser`, `CmpFrames`)
and `build_gamma.sh` compiles them with it. Same Java packages, so the
bridge does not change.

**Consequences.** `verify-corpus.sh` loses the rows RWX 118/118 (and the
comparison with `three-rwx-loader`), `.world` 25/578/103 and avatars
146/148, whose readers only the new engine used; it keeps `.seq` 231,
`.bod` 51, `.cmp` 159 and `.mov` 52. The format documents remain, with
a note where they cite removed code or captures. `.gitignore` still
ignores `tools/lwjgl/`, `tools/node*/`, `tools/rwx-harness/`, `client/` and
`logs/` so that an old checkout (the Mac) does not push them: they can be deleted
by hand.

**Verified in the Linux container:** complete `tools/setup-linux.sh` (904
bridge classes + `formats/`); `run-checks.sh` 35/35 (4 + 31);
`verify-corpus.sh` with no failures; `build-dist.sh --app-image` without LWJGL (portable
zip of 5.8 MB); smoke test of the Linux app: it draws GroundZero
with the camera at (230,180,170); terminal menu with 5 options,
`--viewer` rejected and the window only with the original client.

### 🟢 The game decompiled from end to end, travel between worlds and the whole game tested (2026-09-26)

User request: "with Ghidra finish decompiling the game from end to
end. And test going to other worlds, that hasn't been tested; test
all the things that can be done in the game". Full report:
`docs/pruebas-juego.md`.

**Ghidra.** Six of the game's own binaries were missing. Ghidra 12.1.3 was downloaded
from SourceForge's mirror (the cloud proxy blocks GitHub), with the SHA-256
checked. Out came `run.exe` (139 functions), `gdkup.exe` (256),
`sfmain.exe` (619, the SpeakFreely/GSM voice chat compiled with Watcom, whose
`DGROUP` had to be taught to `ScanVtablesAndExport.java`) and the
RenderWare drivers for 8-bit (427), MMX (435) and DirectDraw (305). The vtable sweep
was also passed over RWL21 (+21) and RWDL6D21 (+26). All with 0 failures,
and reproducible with `tools/ghidra-scripts/decompile-all.sh`. What remains
undecompiled is third party: the installer's Sun Java 1.4.2,
msvcrt, xdelta/glib and Wise's uninstaller.

**Travel.** The finding that unlocked it: `us1.worlds.net` responds
again, because it is the LibreWorlds mirror, with the world packages and
the avatar wardrobe that were given up for lost. The launcher asks the
mirror for what is not available locally. To install, the client requests `gdkup.exe`
and closes; the bridge leaves the request in `gdkup.pending`, and the translated
gdkup (`GdkUp`, from `gdkup_exe`) installs the Wise packages
(`WisePackage`) and NSIS (`NsisPackage`) and starts the client again.
Tested: 11 worlds downloaded (the 2004 installation only brings
GroundZero), among them Chaos, David Bowie's world, with its BWStreet,
and The Blair Witch World, the Burkittsville café, reached from the
universe map, where the mirror serves all 16 worlds.

**Failures found while testing, all fixed with a test:**

- Dialogs with a text field (WorldsMark → Change Location...): on X11 the
  closing of `PolledDialog` (under its monitor) would hang with the
  event thread, which takes that monitor through the input method. Black dialog
  and frozen UI. `AwtCompat.closeHoldingLock`, `UiDisposeCheck`.
- The universe map closed the game: the mock of
  `usingMicrosoftVMHacks` returned `true`. In gamma.dll it is
  `DAT_004891cc == 1`, which is only activated with Microsoft's JVM.
- Textures: `FUN_00442bc0` decodes a frame in several row groups
  (`mug.cmp` from Blair Witch, two groups that match the file to the byte),
  and the `esi` row is a single buffer for the whole file.
  Also, byte 13 of the header makes the number of colors jump too
  (`kcl.mov`, a wardrobe kaleidoscope). `CmpGroupsCheck`,
  with samples in `assets/cmp-verified/`.
- Upgrade Now (GroundZero 37 → 40, a LibreWorlds NSIS): Delete, Push/Pop/Exch,
  FileOpen, FileRead and FileClose were missing. Also, an
  installer that aborted left the player without a game; gdkup.exe does not read
  the exit codes (0x00401e75) and continues until the restart. Now the same.
  `GdkUpCheck`, with `Meteor25.exe` (Wise) and `GroundZero37-40.exe` in
  `assets/packages/`.
- (Earlier, in the same session) the slow-motion turn: the bridge gave a
  1 ms clock at 600-800 fps and the `SmoothDriver` thresholds nullified the
  velocity. Now it advances in `GetTickCount` jumps (15.625 ms), as on XP.

**Remaining:** xdelta patches, voice chat untranslated, invisible "Sleep",
⚠️ other places with AWT under a dialog's monitor, and the decision whether or not to
keep the mirror's packages in the repo.

### 🟢 New logo: a low-poly planet (2026-09-26)

The user did not like the package's logo at all: a generic blue globe
with "FW" and an orange ring. Four proposals were shown, all without
letters so they read at 16 px: low-poly planet, portal between worlds,
chat-bubble planet and pixel art. They chose the **low-poly planet**: an
80-face icosphere with flat shading, like RenderWare's 3D (one
light, one color per face), with continents and a ring that passes behind and
in front, on a night-sky tile.

`tools/icons/make_icons.py` draws it as SVG (`openworlds.svg`, and
`openworlds-small.svg` without stars and with the ring thicker for
16-32 px) and produces with headless Chrome and Pillow the 1024 PNG, the ICO
(16-256), the ICNS (16-1024) and the launcher's window icon. Headless
Chrome crops small windows, so everything is drawn at 1024
and reduced with Lanczos.

### 🟢 The launcher with the logo's look, its own updater and releases (2026-09-29)

User request: the launcher dressed like the logo, without the log panel,
updating itself; the CI publishing releases on GitHub; and fixes for what
they found while playing (a world downloaded from the game did not start
after the restart, clicking another user did nothing, the local whirl did
not work).

- The launcher's window: the icon's palette, the low-poly planet drawn live
  (`PlanetView`, the same icosphere) and spinning, Poppins (OFL) bundled.
  The session logs stay in `logs/` of the data folder.
- `Updater` + `Bootstrap`: the newest release with a portable package,
  SHA-256 checked, unpacked in `<data>/app/<version>`; on the next start the
  app hands over to it in the same JVM, without rewriting itself; a broken
  version goes to `app/bad`. `UpdaterCheck` against a fake GitHub.
- The CI publishes `v1.0.<commits>` on every push to `main`.
- Clicking another user: the 2004 code shows the drone's menu from a
  component outside its parent's hierarchy, which Java 6+ refuses (JDK bug
  6278745): `AwtCompat.showPopup` (`PopupShowCheck`). Releasing a world
  server was cut short by `Thread.stop()` (only throws since Java 20):
  `JavaCompat.stopThread`. The world asked for before it was installed is
  the one the restart goes to. Details: `docs/game-tests.md` and the
  roadmap, section 1e.

### 🟢 OpenWorlds in English, J Solar Server, J Worlds Injector and an encrypted mode (2026-09-30)

User request: the project is OpenWorlds and everything in English; the
repository is public; clean up what is no longer useful; replace whirl,
which had a long list of security advisories in its dependencies, with a
server of our own called **J Solar Server**, with an admin app "super easy
to understand for anyone", in violet and with another planet as its logo;
an encrypted mode with its patch for the client; and **J Worlds Injector**,
"to inject things into Worlds, like a VIP patch": the player picks the
patches before playing and they are compiled when the game starts. Also:
"the worlds work in a strange way".

**J Solar Server** (`server/`). Written from the client's protocol code
(`NET.worlds.network`) and the LibreWorlds wiki; one port does what the
distributor, the user server and the room servers did. The rules that make
players visible, each one something whirl did differently: `APPRACTR` (or
a `TELEPORT` of an unknown object) to make an avatar appear, short ids
2..127 per viewer (`regObjIDCmd` reads a signed byte; 1 is the client
itself), the user name as the long id, movement relayed with the id each
viewer knows, room numbers never 0, chat to whoever is in earshot,
`VAR_UPDATETIME` in microseconds. Result: **two original clients see each
other walk and chat**, the first time in the project
(`docs/renders/solar-two-clients.png`). Accounts with PBKDF2 (computed
outside the server's lock), guests, VIP/admin, bans, chat commands,
whispers and friends lists. `SolarProtocolCheck`, 29 checks without a
game. The admin window shares the launcher's look (the new `ui/` module)
in violet. Also found on the way: the client's `_connectThread` race (see
`docs/net-local-server.md`) hung connections to a server on the same
machine; patched in `natives-java.patch`.

**Encrypted mode.** TLS on port 6651 with a self-signed EC P-256
certificate (the server makes it, with its own small DER encoder). There
is no authority to vouch for it, so the launcher does what SSH does: it
shows the SHA-256 fingerprint the first time, the player compares it with
the one in the server's window, and it is remembered
(`known_servers.properties`); a different one later is a warning. The
client's "tls" patch opens the connection with `SSLSocket` and trusts only
that fingerprint (`-Dopenworlds.tls.pin`). Measured: `[tls] encrypted
connection to 127.0.0.1:6651 (TLSv1.3, TLS_AES_256_GCM_SHA384)`, the
sign-in made the account, and Upgrade Now with its restart came back
encrypted.

**J Worlds Injector** (`injector/`). A patch is a folder with
`patch.properties` and unified diffs against the client's source as the
bridge builds it (`editor/.build-gamma/source`, packaged as
`lib/worldsplayer-src.zip`). At start the launcher applies the chosen ones,
compiles the touched files with `javax.tools` (`--release 8`, against
`worldsplayer.jar`) and puts the classes before the jar on the class path;
the result is cached by the hash of patches and inputs. Built in: VIP (the
VIP features without a VIP account), Walk faster (×1.8 in
`SmoothDriver`), Time in the chat (`[HH:mm] ` on each line), No word filter
(`FilthFilter`), Encrypted connection. Measured in the game: "VIP Capitan"
on the status bar and `[22:42] Solar> Welcome...` in the chat.

**Worlds.** What felt strange: picking a world that was not installed
started GroundZero, the client offered the download, and a restart was
needed to get there. Now the launcher reads the world's `upgrades.lst` on
the mirror (`-1 25#511534:1692`: from nothing to version 25, that size,
for clients from build 1692), downloads the full installer and runs the
Java gdkup on it **before** the game starts (`WorldInstall`). Measured:
Avatar Gallery 36 installed and the game opened straight in its gallery.
The client still offers, as in 2004, the worlds its portals lead to when a
room loads (Avatar Gallery at GroundZero's entrance).

**Clean-up.** Removed: `server/whirl`, its scripts and the launcher's
`LocalWhirl`; `legacy/installer-reversing/` (the Wise stub that an early
session took for the client; the bridge installs Wise and NSIS packages
itself now, and `assets/Worlds1900.exe` stays). Everything translated to
English, this history included. The CI builds no Rust anymore, packages
both apps on the four systems and, on Linux, runs the packaged client
against the packaged J Solar Server over TLS with patches built in.
