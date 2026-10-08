# OpenWorlds for the PSVita

The **original** 2004 WorldsPlayer client and the portable bridge (the same
Java code the desktop version runs: `NET.worlds.*` plus gamma.dll,
RenderWare 2.1 and its software rasterizer translated to Java) running on a
PlayStation Vita. No new engine: the Vita has no Java, so the Java bytecode
is translated to C++ and compiled for the Vita, and the parts of the Java
runtime the client needs and the Vita lacks (above all `java.awt`) are
written here.

```
2004 client + bridge (Java bytecode, unchanged)
   │  Clearwing VM: bytecode → C++ (v3.1.3 + vita/clearwing/patches)
   ▼
C++ project ── + Clearwing's runtime (GC, threads, java.lang/util/io/net...)
           ── + vita/runtime: java.awt, javax.sound, javax.imageio (ours)
           ── + vita/native: the platform natives on SDL2 (screen, input, sound)
   │  VitaSDK: arm-vita-eabi GCC
   ▼
eboot.bin → .vpk (LiveArea)
```

## Layout

| Path | What |
|---|---|
| `tools/setup-vitasdk.sh` | builds VitaSDK from source (pinned `vitasdk/buildscripts` + `vitasdk-buildscripts.patch`: zlib and libelf from mirrors too, gdb optional) |
| `tools/setup-clearwing.sh` | gets Clearwing VM at v3.1.3, applies `clearwing/patches`, builds the transpiler and its runtime with javac (Maven Central jars checked by SHA-256) |
| `tools/transpile.sh` | classes → C++ project (with `native/CMakeLists.txt` and our natives) → program for this machine, to test before the Vita |
| `tools/run-conformance.sh` | `test/conformance` on a JVM and transpiled: the outputs must be identical |
| `tools/run-runtime-conformance.sh` | the same programs on a JVM with the JDK's classes and with ours (`runtime/` on java.base alone): quick, no transpiling |
| `tools/run-awt-check.sh`, `run-layout-conformance.sh` | our `java.awt` on a JVM limited to java.base, on a screen in memory: `test/awt/AwtCheck` (widgets, menus, events, pictures) and the layouts against the JDK's |
| `tools/run-sound-check.sh` | `test/sound/SoundCheck`: our sound lines and mixer, the output written to a WAV file and measured |
| `tools/run-coding-fuzz.sh` | `test/coding`: our character encoders and decoders against the JDK's on random bytes |
| `clearwing/patches/` | our fixes to Clearwing VM (below) |
| `runtime/src/` | the part of the Java runtime that is ours (below) |
| `native/` | the platform natives (C++ over SDL2), copied into every transpiled project |
| `test/` | the checks above |

Everything is built under `build/vita/` (ignored by git). Transpiling for
this machine needs cmake, ninja, a C++20 compiler, zlib, zziplib, libffi
and SDL2 (Debian/Ubuntu: `zlib1g-dev libzzip-dev libffi-dev libsdl2-dev`).

## Status

| Step | Status | Note |
|---|---|---|
| VitaSDK built here | ✅ | GCC 15.2 for arm-vita-eabi, newlib, pthread-embedded; the SDK's C++ sample builds to a `.vpk` |
| Clearwing VM | ✅ | v3.1.3 with 29 patches; `run-conformance.sh`: 4 programs, 448 lines, identical to the JVM |
| The Java the client uses | ✅ | every JDK class, method and field the 917 classes (client, bridge, `formats/`) reference now exists: in Clearwing's runtime (with our patches) or in ours. It was 734 missing |
| Own `java.awt` | ✅ | 151 classes; `AwtCheck` 18/18 on java.base alone; layouts as JDK 1.4.2's (39 of 44 like today's JDK, the 5 others are 1.4.2's own) |
| `javax.sound`, `javax.imageio`, `SwingUtilities` | ✅ | `SoundConformance` the same as the JDK's (232 lines); `SoundCheck` 20/20. ⚠️ No MIDI synthesizer yet: the sequencer keeps time, the music is silent |
| The client transpiled | 🟡 | next: the whole client and bridge, run on Linux with our runtime |
| Platform layer (screen, input, sound, network) | 🟡 | SDL2 natives written (`native/clearwing/src/openworlds/`): `Screen.cpp` (a thread of its own owns the window; mouse, touch, keyboard, IME text; the Vita's buttons as a pointer and arrow keys, ⚠️ VERIFY on a Vita) and `Audio.cpp`. Network: BSD sockets in Clearwing (patch 0026). Our whole AWT transpiled to C++: `AwtCheck` 18/18, its pictures pixel-identical to the JVM's |
| `.vpk` of the client | ⬜ | |

### The runtime that is ours (`runtime/src`)

What depends on the machine, or what Clearwing's runtime has none of:

- `java.awt` (and `.event`, `.image`, `.font`, `.geom`, `.color`): the
  2004 client's whole AWT, painted in the look of the Windows client it was
  written for: Frame, Dialog, the widgets, menus and popups (shown as on
  Windows: `PopupMenu.show` waits for the choice), FileDialog, the five
  layouts as JDK 1.4.2's, Graphics with TrueType text (Liberation Sans:
  Arial's metrics), images (GIF, PNG, JPEG, BMP), both event models (the
  1.0 `handleEvent`/`action` most of the 2004 code uses and the 1.1
  listeners). One screen: `WindowSystem` composes the windows.
- `javax.sound.sampled`: WAV files read as the JDK reads them, the
  conversions to 16-bit PCM with its arithmetic (checked sample by
  sample), and lines mixed (`net.openworlds.awt.AudioMixer`) into one
  48 kHz output.
- `javax.sound.midi`: Standard MIDI Files, tracks and tempo maps as the
  JDK's, a real-time sequencer.
- `javax.imageio.ImageIO` (PNG out, the bridge's captures) and
  `javax.swing.SwingUtilities.getWindowAncestor`.
- `net.openworlds.awt`: what the above needs from the machine: `Screen`
  (pixels out, input in) and `AudioDevice` (blocks of samples out), each
  with a native implementation (SDL2) and one for tests (in memory, or a
  WAV file).

Pure JDK classes with no machine behind them go into Clearwing's runtime
instead, as patches.

### Fixes to Clearwing VM (`clearwing/patches`)

Found with the conformance tests; each one would have broken the client:

- `Thread.join` never returned (a finished thread did not notify its monitor).
- `wait()` released only one level of a re-entered monitor and could lose a
  `notify`; `Thread.sleep` locked the Thread's own monitor and left it
  locked when interrupted (a later `join` hung).
- With two handlers on the same code (`catch` plus `finally`), the
  `finally` one was tried first: `catch` blocks were skipped.
- Floating point constants were written with 7 digits (`%e`): now exact
  (hexadecimal literals).
- Division by zero threw a ClassCastException; negative array indexes were
  not checked; `new int[-1]` crashed; arrays threw IndexOutOfBounds instead
  of ArrayIndexOutOfBounds.
- Integer arithmetic followed C++, not Java: shift counts, `MIN_VALUE / -1`,
  float to int conversion (NaN, overflow), signed overflow (`-fwrapv`).
- `Double`/`Float.toString` printed 6 decimals; `Math.max/min` with NaN and
  -0.0; `Random.nextDouble`/`nextBoolean`; a few missing methods.
- The program ended with `main` even with other threads running (it now
  waits for the non-daemon ones); `Thread.start` returned before the thread
  was alive and its daemon flag could be lost; no thread priorities;
  `System` properties and the command line arguments were missing.
- Character encodings: only UTF-8, and wrong with surrogates; now the
  JDK's UTF-8, UTF-16 (all three), ISO-8859-1, US-ASCII and windows-1252,
  fuzzed against the JDK.
- String literals with some characters broke the transpiled code.
- `java.io.File` (paths, listing, rename, times...), `RandomAccessFile`,
  `FileChannel` locks, `java.nio.file.Paths`/`Files`: as the JDK's.
- `java.net`: real sockets (connect with timeout, read timeouts,
  ServerSocket), name lookups, `URL` parsing as the JDK, HTTP through
  `URL.openConnection` (chunked bodies, redirects, If-Modified-Since, error
  streams); `URI.toURL` returned null.
- Calling an interface method on null crashed instead of throwing a
  NullPointerException.
- Members the client uses that were missing: `NumberFormat`, `Calendar`,
  `Date.UTC`, `Base64`, `CountDownLatch`, `java.lang.management`,
  `UnsatisfiedLinkError`...

Known differences left as they are (the client does not depend on them):
`HashMap`'s iteration order, no `ArrayStoreException`, `System.nanoTime`
in milliseconds.

⚠️ To do: object serialization. Clearwing's `ObjectInputStream` and
`ObjectOutputStream` are stubs, and the client keeps its cache index
(`cachedir/cache.index`: which downloaded files, the 2004 avatars among
them, it already has) as a serialized `Cache`. Without them it starts with
an empty cache every time (it says "Flushing cache index." and carries on).

## Building

```bash
vita/tools/setup-vitasdk.sh          # once, 20-60 min; then export VITASDK=~/vitasdk
vita/tools/setup-clearwing.sh        # once, seconds
vita/tools/run-awt-check.sh          # our runtime on a JVM (also builds it)
vita/tools/run-sound-check.sh
vita/tools/run-runtime-conformance.sh
vita/tools/run-conformance.sh        # the transpiler against the JVM (minutes)
```

## Plan

1. ✅ **Own AWT, tested on a desktop JVM first.** Java 17+ can run the client
   with our `java.awt` instead of the JDK's (`--limit-modules java.base
   -Xbootclasspath/a:...`), drawing into memory: fast to iterate and to
   test, with the real JVM's errors. The same classes are then transpiled.
   Widgets painted in the look of the 2004 Windows client; text with
   Liberation Sans (Arial's metrics, which the bridge already uses).
2. ✅ **The rest of the runtime**, in Java over a few natives.
3. **Platform layer on SDL2** (window or Vita screen, touch and buttons as
   mouse and keys, the IME for text, sound): the same C++ on Linux and on
   the Vita, so the transpiled client is tried on Linux before the Vita.
4. **Vita build and `.vpk`**, single player first (GroundZero, installed
   worlds), then online against J Solar Server.
5. **Speed**: the 3D view is the bridge's software rasterizer (RWDL6D21),
   at 444 MHz probably at a reduced resolution. If it is not enough, a GPU
   driver for RenderWare, as the original had several (8-bit, 16-bit, MMX,
   DirectDraw): RWL21, the engine itself, stays the translated original.
