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
C++ project ── + Clearwing's runtime (GC, threads, java.lang/util/io...)
           ── + vita/runtime: java.awt, javax.sound, sockets... (to write)
   │  VitaSDK: arm-vita-eabi GCC
   ▼
eboot.bin → .vpk (LiveArea)
```

## Layout

| Path | What |
|---|---|
| `tools/setup-vitasdk.sh` | builds VitaSDK from source (pinned `vitasdk/buildscripts` + `vitasdk-buildscripts.patch`: zlib and libelf from mirrors too, gdb optional) |
| `tools/setup-clearwing.sh` | gets Clearwing VM at v3.1.3, applies `clearwing/patches`, builds the transpiler and its runtime with javac (Maven Central jars checked by SHA-256) |
| `tools/transpile.sh` | classes → C++ project → program for this machine, to test before the Vita |
| `tools/run-conformance.sh` | `test/conformance` on a JVM and transpiled: the outputs must be identical |
| `clearwing/patches/` | our fixes to Clearwing VM (below) |
| `test/conformance/` | the Java semantics the client relies on (arithmetic, conversions, exceptions, threads, strings, collections) |

Everything is built under `build/vita/` (ignored by git).

## Status

| Step | Status | Note |
|---|---|---|
| VitaSDK built here | ✅ | GCC 15.2 for arm-vita-eabi, newlib, pthread-embedded; the SDK's C++ sample builds to a `.vpk` |
| Clearwing VM | ✅ | v3.1.3 with 13 patches; `run-conformance.sh`: 46 lines identical to the JVM |
| The client transpiled | 🟡 | the transpiler reads all 917 classes (client, bridge, `formats/`) in 6 s; it stops on what the runtime lacks (next rows) |
| Own `java.awt` | ⬜ | the biggest piece: 101 classes, 652 references from the client |
| The rest of the runtime | ⬜ | 15 classes and 43 methods (list below) |
| Platform layer (screen, input, sound, network) | ⬜ | SDL2, which exists for both Linux and the Vita |
| `.vpk` of the client | ⬜ | |

### What the client needs that the runtime does not have

Measured from the bytecode (every JDK class, method and field the 917
classes reference, against Clearwing's runtime classes):

- **AWT**: `java.awt` (Frame, Dialog, Panel, Canvas, Button, Label,
  TextField, TextArea, List, Choice, Checkbox, Scrollbar, ScrollPane, menus,
  FileDialog, the five layouts, Graphics, Font/FontMetrics, Image,
  MediaTracker, Toolkit, EventQueue...), `java.awt.event` (both the 1.0
  event model the 2004 code mostly uses — `handleEvent`, `action`,
  `mouseDown`... — and the 1.1 listeners), `java.awt.image`
  (BufferedImage, ColorModel, ImageProducer...).
- **Others**: `java.net.Socket`, `ServerSocket` (and a working `URL`),
  `javax.sound.sampled` and `javax.sound.midi`, `javax.imageio.ImageIO`,
  `java.nio.file.Files`/`Paths`, `FileLock`, `Base64`, `CountDownLatch`,
  `java.lang.management`, `UnsatisfiedLinkError`, `SwingUtilities`; and
  `RandomAccessFile`, `File.list(FilenameFilter)`, `System.setOut`,
  `URL.getHost()`... (43 methods of classes that do exist).

### Fixes to Clearwing VM (`clearwing/patches`)

Found with the conformance test; each one would have broken the client:

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

Known differences left as they are (the client does not depend on them):
`HashMap`'s iteration order, and no `ArrayStoreException`.

## Building

```bash
vita/tools/setup-vitasdk.sh          # once, 20-60 min; then export VITASDK=~/vitasdk
vita/tools/setup-clearwing.sh        # once, seconds
vita/tools/run-conformance.sh        # the transpiler against the JVM
```

## Plan

1. **Own AWT, tested on a desktop JVM first.** Java 17+ can run the client
   with our `java.awt` instead of the JDK's (`--limit-modules java.base
   -Xbootclasspath/a:...`), drawing into memory: fast to iterate and to
   test, with the real JVM's errors. The same classes are then transpiled.
   Widgets painted in the look of the 2004 Windows client; text with
   Liberation Sans (Arial's metrics, which the bridge already uses).
2. **The rest of the runtime**, in Java over a few natives.
3. **Platform layer on SDL2** (window or Vita screen, touch and buttons as
   mouse and keys, the IME for text, sound): the same C++ on Linux and on
   the Vita, so the transpiled client is tried on Linux before the Vita.
4. **Vita build and `.vpk`**, single player first (GroundZero, installed
   worlds), then online against J Solar Server.
5. **Speed**: the 3D view is the bridge's software rasterizer (RWDL6D21),
   at 444 MHz probably at a reduced resolution. If it is not enough, a GPU
   driver for RenderWare, as the original had several (8-bit, 16-bit, MMX,
   DirectDraw): RWL21, the engine itself, stays the translated original.
