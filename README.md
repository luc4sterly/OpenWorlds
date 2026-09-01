# LibreWorlds — Open‑Source Revival of Worlds Chat

## 1. What this repository contains

| Category | Path (relative) | Description |
|----------|------------------|-------------|
| **De‑compiled native client** | `Worlds1900.exe.c` / `src/worlds_original.c` | Full C source produced by Ghidra (original Windows client). |
| **Modern C build system** | `CMakeLists.txt` + `src/*` + `include/*` | Thin wrapper (`src/main.c`) + platform abstraction (`platform_win32.c`, `platform_stub.c`). |
| **Original game assets** | `assets/` | All binaries, maps, textures (`*.RWX`, `*.GIF`, `*.WORLD`), music, and the original executables (`FIRST.EXE`, `GROUNDZERO.EXE`, `Worlds1900.exe`). |
| **Java editor for WorldsPlayer** | `editor/` | `worlds.jar` + Make‑based de‑compile / compile workflow, optional patches, and a tiny Git repo. |
| **Protocol & data‑format wiki** | `protocol/` | 30 + Markdown files detailing packet IDs, binary structures, object model, flags, property IDs, persistence format, etc. |
| **Open‑source server implementation (Whirl)** | `server/whirl/` | Rust‑based re‑implementation of the Worlds Server (GPL‑3.0). Includes multiple crates (`whirl`, `whirl_api`, `whirl_common`, `whirl_config`, `whirl_db`, `whirl_prompt`, `whirl_server`), Cargo‑make scripts, Diesel migrations, and CI‑ready docs. |
| **Miscellaneous assets** | `assets‑main/` | Graphic and audio resources used by the wiki and the editor (e.g. Munch, Whirlsplash). |
| **Documentation & meta files** | `README.md` (this file), `editor/README.md`, `server/whirl/README.rst` | High‑level overviews for each sub‑project. |
| **Version‑control metadata** | `.git/` directories under several sub‑folders | Internal history for the extracted projects – not needed for the final product. |

## 2. What can be built / run

| Target | How to build | How to run |
|--------|--------------|-----------|
| **Native client (Windows)** | ```powershell
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
``` | `./Release/WorldsChat.exe` – will load assets from `assets/`. |
| **Native client (Linux/macOS)** | ```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
``` | `./WorldsChat` – runs with bundled assets (POSIX stubs may miss some Win32 features). |
| **Whirl server (Rust)** | ```bash
cd server/whirl
cargo +nightly build --release
# Set up DB (requires SQLite/PostgreSQL + diesel_cli)
 diesel setup && diesel migration run
``` | ```bash
./target/release/whirl_server --config config/whirl.toml
``` – server listens on the default Worlds port (usually 19199). |
| **WorldsPlayer Java editor** | ```bash
cd editor
export WORLDSPLAYER_JAR=/path/to/worlds.jar   # original client JAR
make decompile   # produces `source/` tree
# edit any Java file in `source/`
make compile   # creates `out/worlds.jar`
``` | Replace the original `worlds.jar` in the Windows client with the newly built JAR and run the client. |
| **Asset conversion (optional)** | Write a small script (Python/Rust) that reads the `*.RWX` and `*.WORLD` formats (documented in `Persister‑…‑format.md`) and exports to GLTF/OBJ and PNG. | Use the converted models in a modern engine (e.g. Godot, Unity) or in the rewritten C client. |

## 3. How the pieces fit together

1. **Protocol definition** (wiki) – *All network packets, object flags, property IDs and binary formats are described in the Markdown files.* Use these specs to implement a new client or server in any language or to verify that Whirl’s implementation matches the original.
2. **Server** – `whirl` – fully open‑source, written in safe Rust. Implements the same packet set described in the wiki. Can be started locally and pointed to by the de‑compiled client (or the Java editor).
3. **Client** – either:
   - **C client** (`WorldsChat.exe`) – compiled from the de‑compiled source. Minimal changes required; loads the original asset files directly.
   - **Java client** – rebuilt with the editor; useful for rapid UI hacks or for testing protocol changes.
4. **Assets** – stored in `assets/`. The client reads them verbatim; no conversion needed for the original binary. For modern graphics pipelines convert them once (script) and keep the converted files alongside the originals.
5. **Documentation** – the wiki is the *single source of truth* for the protocol and object model. Keep it up‑to‑date if you extend or modify the server/client.

## 4. What can be safely removed

| Item | Reason for removal |
|------|-------------------|
| **`.git` directories inside sub‑folders** (`editor/.git`, `server/whirl/.git`, etc.) | They only hold history for the extracted projects and are not needed for the combined repository. |
| **`Libreworlds/LibreWorlds-master/`** | The raw original source is duplicated by the de‑compiled C (`Worlds1900.exe.c`). Keeping it adds no value. |
| **`Libreworlds/LibreWorlds-wiki-master/README.md`** and other empty placeholder files | The top‑level README now covers the overview; these placeholders can be deleted. |
| **`src_worlds_extraction1/GAMMACLS/` and its sub‑folders** | Belong to an old Java server implementation that is superseded by `whirl`. |
| **`src_worlds_extraction1/Worlds1900/` and its nested Java server** | Same reason as above – obsolete. |
| **Duplicate executable files** (`FIRST.EXE`, `GROUNDZERO.EXE`, `Worlds1900.exe` copies in nested folders) | One copy in `assets/` is sufficient; extra copies increase repo size. |
| **`Libreworlds/assets‑main/`** | Contains auxiliary graphics/sounds that are not required for the core game; the needed assets are already present in `assets/`. |
| **Any empty directories after the moves** | Cleaned up automatically. |

> **Note:** The removal suggestions are *non‑destructive* – they affect only repository size and clarity. No code that is required for the listed build/usage paths is touched.

## 5. How to contribute

1. **Fork** the repository. 
2. **Keep the wiki accurate** – any protocol change must be reflected in the Markdown files. 
3. **Add tests**: 
   - For the C client, add unit‑style sanity checks (e.g. parsing a known packet). 
   - For Whirl, use the `whirl_server` integration tests (`cargo test`). 
4. **Submit PRs** with clear descriptions and updated documentation. 

## 6. Licensing

| Component | License |
|-----------|---------|
| **Whirl server (Rust crates)** | GPL‑3.0 (see `server/whirl/LICENSE`). |
| **Java editor & patches** | GPL‑3.0 (see `editor/LICENSE`). |
| **De‑compiled C client** | *Original code is proprietary* – this repository contains only the result of a reverse‑engineering effort. Distribute only under *fair‑use / research* provisions; do not publish the source as your own copyrighted work. |
| **Assets** | Original assets belong to Worlds.com. Use only for personal / research purposes unless you replace them with your own open‑source versions. |
| **Documentation (wiki Markdown)** | MIT (author‑provided). Feel free to copy, modify, and redistribute. |

## 7. Quick‑start cheat‑sheet

```bash
# -------------------------------------------------
# 1️⃣ Build native client (Windows)
mkdir build && cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
./Release/WorldsChat.exe   # runs with bundled assets

# -------------------------------------------------
# 2️⃣ Build native client (Linux/macOS)
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
./WorldsChat               # runs with bundled assets

# -------------------------------------------------
# 3️⃣ Run open‑source server (Whirl)
cd server/whirl
cargo +nightly build --release
# Set up DB (requires SQLite/PostgreSQL + diesel_cli)
 diesel setup && diesel migration run
./target/release/whirl_server --config config/whirl.toml

# -------------------------------------------------
# 4️⃣ Rebuild Java client (WorldsPlayer)
cd editor
export WORLDSPLAYER_JAR=/path/to/original/worlds.jar
make decompile   # source/ populated
# edit any .java file in `source/`
make compile   # creates out/worlds.jar
# replace original JAR in the Windows client folder

# -------------------------------------------------
# 5️⃣ Convert assets (example stub)
python tools/convert_rwx.py assets/FIRST/*.RWX assets_glb/
```

---

**All you need is here:** a working client, a modern open‑source server, the full protocol spec, the original world assets, and a Java editor for rapid tweaks. By cleaning the unused Git metadata and old Java‑server remnants, the repository becomes a clean, documented platform for anyone who wants to keep *Worlds Chat* alive in the open‑source world.

This repository contains a **decompiled** version of the original `Worlds1900.exe` (the client for *Worlds Chat* from worlds.com).  The code was generated by Ghidra and therefore:

- Uses autogenerated names like `FUN_00401000` and platform‑specific Win32 APIs.
- Includes a large amount of CRT and runtime support code.
- Is a single monolithic C source file (`Worlds1900.exe.c`).

## Goal of this project

- Make the code **more accessible** and **portable** while preserving the original game logic so it remains playable.
- Replace obscure autogenerated identifiers with readable names where the purpose is clear.
- Add concise documentation/comments to the most important functions.
- Organise the source tree into logical modules.
- Provide a modern build system (CMake) that works on Windows, Linux and macOS.

## Build instructions (Windows)

```bat
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"   # or any VS generator you have
cmake --build . --config Release
```

The resulting executable will be `WorldsChat.exe` inside the build directory.

## Build instructions (Linux/macOS)

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

> **Note**: The current code still depends on a few Win32 functions (e.g., `GetCommandLineA`, `GetVersion`).  Stub implementations are provided in `src/platform_stub.c` for non‑Windows platforms.  These stubs are sufficient for the program to start and run the core game loop, but further platform‑specific work may be required for full feature parity.

## Project layout (proposed)

```
src/
  main.c            # entry point wrapper that calls the original entry()
  worlds_original.c # the untouched decompiled source (renamed from Worlds1900.exe.c)
  platform_win32.c   # Windows‑specific wrappers
  platform_stub.c   # Minimal POSIX stubs for other platforms
include/
  worlds.h          # public declarations and cleaned‑up types
CMakeLists.txt
README.md
```

## Next steps (implemented)

1. Added this README.
2. Added a basic `CMakeLists.txt` that compiles the original source.
3. Created a thin wrapper `src/main.c` that calls `entry()`.
4. Added platform abstraction files (`platform_win32.c`, `platform_stub.c`).
5. Began documenting the `entry()` function with comments describing each major step.

Further work will focus on:
- Renaming functions/variables based on their observed behaviour.
- Re‑organising the massive source file into smaller, logical modules.
- Replacing CRT helpers with the C standard library equivalents.
- Extending the POSIX stubs to cover all required Win32 calls.
- Writing unit‑style sanity checks to ensure the game still runs.

Feel free to explore, contribute, or ask for specific refactorings.
