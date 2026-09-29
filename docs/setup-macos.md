# Development on macOS

Guide to following OpenWorlds development on a Mac (Intel or Apple Silicon).
The repo has already been pushed to Codeberg: `git@codeberg.org:JoseAntonio/OpenWorlds.git`.

**No Homebrew**: Homebrew no longer supports Intel Macs, so the setup does
not use it. The JDK is downloaded as a portable copy inside the repo, into a
gitignored directory, without `sudo`.

## 1. Clone

```bash
git clone git@codeberg.org:JoseAntonio/OpenWorlds.git
cd OpenWorlds
```

> Alternative over HTTPS: `https://codeberg.org/JoseAntonio/OpenWorlds.git`

## 2. Automatic setup

Prerequisite: Command Line Tools (they bring `git` and `python3`). If they
are missing: `xcode-select --install`.

```bash
tools/setup-macos.sh
```

It does, in order (idempotent):

1. Checks for `python3` (Command Line Tools).
2. Downloads **JDK 25 Temurin** (tar.gz from `api.adoptium.net`, for the
   Mac's architecture) into `tools/jdk/`, verifying the SHA-256 that
   Adoptium publishes.
3. Compiles the readers in `formats/src` → `formats/out/` and the original
   client with the bridge (`build_gamma.sh` → `editor/.build-gamma/out`).

## 3. Play / develop

To play, the package with the launcher:

```bash
tools/build-dist.sh                              # build/dist/OpenWorlds (+ portable .zip)
open build/dist/OpenWorlds/OpenWorlds.command    # or double-click in Finder
tools/build-dist.sh --app-image                  # plus OpenWorlds.app with its own Java
```

Or the one from each push on GitHub (CI Artifacts; `OpenWorlds-<ver>-macOS-X64`
on an Intel Mac).

For diagnostics, the original client directly (it accepts `JAVA_OPTS`, see
`editor/worldsplayer_source_editor-main/bridge/README.md`):

```bash
editor/worldsplayer_source_editor-main/run_gamma.sh home:GroundZero/groundzero.world
```

Verification (all with the JDK in `tools/jdk`):

```bash
tools/run-checks.sh      # the *Check classes of formats/test and bridge/test
tools/verify-corpus.sh   # .seq 231, .bod 51, .cmp 159, .mov 52 and then run-checks

# .seq: parses the whole corpus and summarizes version/joints/extras
java -cp formats/out net.openworlds.bod.SeqExtractMain -q \
  assets/gammatutorial-samples/base-avatars/*.seq assets/WorldsPlayer/cachedir/*.seq

# .bod / .rwg: structural summary
java -cp formats/out net.openworlds.bod.BodExtractMain  assets/gammatutorial-samples/base-avatars/*.bod
java -cp formats/out net.openworlds.rwg.RwgExtractMain  assets/gammatutorial-samples/cube.rwg
```

macOS notes:

- **Portable JDK**: `build_gamma.sh`, `run_gamma.sh` and the scripts in
  `tools/` put `tools/jdk/Contents/Home/bin` at the front if it exists
  (`/usr/bin/java` on macOS is a stub that fails when no JDK is installed).
- **`bring_to_front.py`** is X11-only and is not needed on Mac.
- `tools/run-original.sh` (2004 client under Wine) **does not work on modern
  Macs** (x86 Win32 + `gamma.dll`): vanilla Wine does not run that on Apple
  Silicon. The script says so and exits with code 2 unless you pass
  `--force-macos` with your own Wine (CrossOver/Whisky/Parallels) already
  configured. On Mac you play with the launcher (or `run_gamma.sh`): the same
  client with the portable bridge, without Wine.

## 4. What is NOT versioned (already in `.gitignore`)

| Path | Why |
|---|---|
| `tools/jdk/` | Portable JDK per architecture |
| `formats/out/`, `editor/.build-gamma/`, `build/`, `analysis/` | generated |
| `.DS_Store`, `._*`, etc. | Finder/macOS noise |

The following are still ignored, in case they are left over from before
2026-09-26: `tools/lwjgl/`, `tools/node*/`, `tools/rwx-harness/`, `client/`
and `logs/`: they are leftovers of the new engine, now removed, and can be
deleted by hand.

## 5. Manual requirements (if you do not use the script)

- JDK 17+ (tested with 25): Temurin tar.gz from
  `https://adoptium.net/temurin/releases/` (macOS, x64 or aarch64),
  unpacked into `tools/jdk/` (it must end up as `tools/jdk/Contents/Home/bin/java`)
- Compile: `bash editor/worldsplayer_source_editor-main/build_gamma.sh`
  (uses `python3` and `patch`, which macOS already includes)
- Play: `editor/worldsplayer_source_editor-main/run_gamma.sh home:GroundZero/groundzero.world`,
  or the package from `tools/build-dist.sh`
