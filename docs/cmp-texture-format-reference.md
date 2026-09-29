# `.cmp`/`.mov` format reference ("ScapePic" textures), investigation from bytes + real disassembly

## Executive summary

`.cmp`/`.mov` are the compressed textures of WorldsPlayer ("ScapePic",
internal name confirmed by the classes `NET.worlds.scape.ScapePicTexture`
and `NET.worlds.console.ScapePicImage` of the decompiled client). **The
decompression happens entirely in `gamma.dll` (native), not in Java** —
just like RWX/RWG. Unlike RWG, this session DID disassemble the real
code with Ghidra (the same binary/tool used in earlier sessions to map
`native` methods) and found strong evidence:

- The container uses a **canonical Huffman + probable LZSS** compression
  scheme, with an internal function literally named
  `huffdcod` (source module name embedded as an assertion string
  — "Huffman decode") whose table-construction algorithm
  (`FUN_004266f0`/`FUN_00426820` at the disassembled addresses)
  matches **structurally, variable by variable**, the public and well
  documented function `make_table()` of the LHA/LZH family of algorithms
  by Okumura/Yoshizaki (canonical Huffman: frequency count
  per code length from 0 to 8 bits, table of accumulated offsets
  `start[i+1] = (count[i]+start[i])*2`, expansion of the lookup table
  by prefix).
- It is **NOT, however, a publicly documented variant under the
  name "LzH2"** — confirmed by external research (see below):
  nobody has published a decoder or a specification for this exact variant.
  It is plausible that Worlds Inc. adapted/derived the public LHA
  algorithm (which was widely reused in 1994-1997)
  for its own internal "ScapePic" tool, changing the magic tag.
- **The real LZSS decompression loop (which consumes the compressed
  bitstream using the Huffman tables already built) was NOT
  disassembled/understood in this session** — it is the missing piece for a
  complete decoder. See "Next step" at the end.

**Scope decision made this session**: instead of investing the rest of
the session in finishing the complete reverse engineering of the pixel
decoder (an effort of the same order as the disassembly of `.bod`,
which the user themselves asked to postpone in the previous session), the
real evidence found was documented up to a reasonable time limit, and the
rest of the session (lighting, materials pipeline, scene) was
implemented using the material color/opacity ALREADY verified (parsed
RWX/RWG), **without rendering any texture and without inventing pixels**, with
an explicit flat-color fallback, not with an invented texture (the
captures of that renderer, the new engine's, were withdrawn with it on
2026-09-26 and are in the git history up to commit `8cd795d`).

---

## Real corpus used

17 real `.cmp` files from the project (`assets/FIRST/*.CMP`,
`assets/WorldsPlayer/*.cmp`, `assets/WorldsPlayer/cachedir/*.cmp` — the
latter, like the `.bod`, are real content downloaded from a
server in an earlier session, not invented). Sizes between 1637 and
10973 bytes.

## Header structure (real hex dump, confirmed byte by byte)

The first 16 bytes are identical in form in the 6 files
inspected (`ADWORLDS.CMP`, `IDLE.CMP`, `ADFRAME.CMP`,
`cachedir/47.cmp`, `48.cmp`, `49.cmp`):

```
4c 7a 48 32 | XX | 80 80 00 80 00 | YY YY | ZZ | 29 ?? ...
"L  z  H  2"  mode   (constant)      ?      ?
```

- **4-byte magic**: `"LzH2"` (`4C 7A 48 32`) — confirmed constant
  in the 17 files.
- **Byte 4 ("mode")**: `0x02` in most files, `0x06` in
  `IDLE.CMP`/`idle.cmp`. ⚠️ VERIFY exact meaning — possible
  compression variant or different color depth.
- **Bytes 5-9**: `80 80 00 80 00`, constant in ALL the files
  inspected. ⚠️ VERIFY — their meaning was not determined
  (possibly part of the initial Huffman code table itself, not
  a "flat" header field — see below, the analysis of
  `FUN_00442750` suggests that the "flat" header is much shorter
  than it seems at first sight and these bytes already form part of
  internal structures of the format, already with packed floats/flags).
- The rest of the bytes from 10 onward varies per file and appears to be
  already part of the compressed stream/code tables — **the exact
  separation between "header" and "compressed data" was not completed**.

## External official/community evidence (research subagent)

- **`github.com/vanjac/zoomscape-info`** (wiki, "Images" page):
  documents the same `LzH2` header, the same list of related
  extensions (`.CMP`/`.CMS`/`.CMX`/`.IMG`/`.IMS`/`.IM2`/`.IM5`/`.OVL`),
  and includes a copy of the original binary `T.EXE` ("ScapePic") — the
  period inspection/decompression tool. **The wiki itself marks the
  compression scheme as "unknown"** — it confirms that nobody else has
  solved it publicly either.
- **`community.worlio.com/forum/12/thread/81`** ("Figuring out the
  CMP/MOV format"): independently confirms the same magic bytes
  `4C 7A 48 32`, suggests that the 5th byte is a
  version/compression-type flag, and describes the format as multi-frame
  (animations, rotatable avatars) — `.cmp` and `.mov` are the same
  container with a different extension.
- **`kangworlds.net/tutorials/cmp`**: practical tutorial (not at byte
  level) about `COMPIMG` (tool of the "Accomplish" SDK) for generating
  `.cmp`/`.mov` — confirms that it is an indexed palette, conceptually
  based on BMP/Sun RAS, with no binary specification.
- **There is no open-source decoder** for this format in any
  language (confirmed by search) — unlike RWX
  (`three-rwx-loader`), here there is no external library shortcut.
  Possible lead of "ZoomScape" as a sibling product (same `LzH2` tag,
  same name "ScapePic") — **unconfirmed** that they share real code
  with Worlds Inc., only search hints.

## Evidence from the real disassembly (Ghidra, `gamma.dll`)

Call chain confirmed from the JNI entry point to the Huffman core
(real addresses of the binary, build of
`assets/WorldsPlayer/bin/gamma.dll`):

```
Java_NET_worlds_console_ScapePicImage_loadImage@12  (0x004103e0)  [JNI entry point]
  -> FUN_00442fd0 (0x00442fd0)      [builds the image object]
       -> FUN_004425f0 (0x004425f0) [initializes fields, delegates if header OK]
            -> FUN_00442750 (0x00442750)  [reads and validates the "flat" header
                                            (0x22=34 bytes), then 5 tables]
                 -> FUN_004269c0 x4  (one per "channel"/table, indices 0-3)
                      -> FUN_00426930  ["huffdcod" - builds Huffman table]
                           -> FUN_00426640   [unpacks the 4-bit code lengths
                                              per symbol, remapped
                                              by a fixed permutation table]
                           -> FUN_004266f0   [== LHA's make_table(): counts
                                              frequencies per length (0-8),
                                              assigns canonical codes]
                           -> FUN_00426820   [== expansion phase of make_table:
                                              fills the lookup table by
                                              prefix with the leaf symbol]
                 -> FUN_0044df50 (table index 4: direct memcpy, NO Huffman -
                                  probably the color palette or the
                                  row offsets, uncompressed)
```

- **Confirmed**: 4 of the 5 internal "tables" are built with canonical
  Huffman (a different code table for each table — a typical pattern of
  plane-based image compression: probably 3 color planes +
  1 plane of "exceptions"/mask, or run-length/position splits in
  the classic LZSS style), the 5th is an uncompressed block copied
  as is.
- **Confirmed**: each table uses a FIXED "pattern" of code table
  lengths according to its index (`FUN_00442590`: index 0 → 81 bytes of
  pattern, index 1 → 49 bytes, index 3 → 22 bytes) — this is exactly
  the classic LHA trick of having alphabets of a known fixed size
  for each type of table (e.g. table of code lengths itself, table of
  positions/distances) instead of encoding the alphabet size in the
  file.
- **NOT completed**: the loop that, once the Huffman tables are built,
  actually decodes the compressed bitstream into symbols and expands them
  into pixels (probably a function like LHA's `decode_c`/`decode_p`,
  with an LZSS sliding window) was not located/disassembled. Without
  that piece a working Java decoder cannot be produced — building
  just the tables without being able to consume the bitstream does not allow
  extracting any real pixel yet.

## Session 2 (continuation, 2026-09-09): the final loop was located — it is still
## not clear enough to implement with confidence

Resuming exactly where the previous session left off, we went back to
`gamma.dll` with Ghidra and followed the call chain beyond
`FUN_00442750` (which only builds the Huffman tables) until finding
**the function that actually decodes a row of pixels and writes it
into the image buffer**: `FUN_00442bc0` (invoked as
`this->getScanline(rowIndex, destBuffer, stride)` from
`FUN_00443180`/`ScapePicTexture_makeTexture`). Its interior:

1. Calls `FUN_00426af0` — the real bit-level Huffman decoder
   (shift register, 256-entry table, exactly the classic `decode_c()` pattern
   of LHA) — to produce up to 5 "channels" of decoded symbols per row.
2. Calls `FUN_00457d88` — the function that **really reconstructs the
   pixels** from those symbols and writes them into the final buffer.
   This IS the piece that was missing in the previous session.

**Concrete, verifiable findings inside `FUN_00457d88` and its
context** (not speculation — real data extracted from the binary):

- **Confirmed pixel format: 8 bits per pixel, indexed palette**,
  with the row width rounded to multiples of 4 bytes (`(width+3)/4`
  DWORDs per row) — it matches exactly what the community had
  already reported (`kangworlds.net/tutorials/cmp`: "indexed palette, based
  on BMP") but now confirmed at the level of real code, not just of a user
  tutorial.
- **Rows written with negative stride** (`param_5 = -stride`) — bottom-up
  convention typical of a Windows `HBITMAP`/DIB (it matches the fact
  that the function that assembles the final bitmap,
  `FUN_00422260`/`FUN_00422150`, literally uses
  `CreateCompatibleDC`/`HBITMAP` of the Windows API).
- **Table of spatial predictors extracted directly from the binary**
  (not inferred): at `0x478e98`-`0x478f5f` there is a real table of pairs
  `(row_offset, column_offset)` — e.g. `(0,-6)`,
  `(0,-5)`... `(0,-2)`, `(-4,0)`, `(-4,1)`... `(-4,6)`, `(-4,-6)`...
  forming a causal window of ~50 candidate positions within the
  last ~4-6 rows and ±6 columns. Combined at run time with the real
  stride of the image (`offset = colDelta - stride*rowDelta`) to
  obtain a concrete byte offset. **This reveals that the real
  algorithm is not LZSS with arbitrary offsets from a generic sliding
  window, but a 2D predictor of causal neighbors**: each
  Huffman-decoded symbol selects one of those ~50 already decoded
  neighbors and copies its pixel value — much more similar to the
  predictive filters of PNG/JPEG-LS than to classic LZSS. This corrects
  the "LZSS" hypothesis of the previous session with real evidence.
- **The table of 256 indirect function pointers** (`PTR_LAB_00483844`,
  invoked once per symbol) that at first glance seemed to suggest
  256 distinct reconstruction routines (feared complexity) **turned out
  to be trivial once disassembled**: each of the 256 entries is
  a function of 5-7 instructions that only reorders/replicates the input
  byte into different combinations of 8/16/32-bit registers — it is
  the classic manual trick of the 90s for "filling 4 bytes at a time
  with the same value, with different alignment offsets", used
  to speed up the filling of runs of repeated pixels. **It adds
  no real algorithmic complexity** — in Java it is trivially equivalent to
  an ordinary fill loop, with no need to replicate the x86 register trick.

**Why it was NOT implemented anyway, following the user's explicit
instruction not to force anything half-done**: although the `what`
(2D causal predictor + run fill) is already reasonably clear,
the `exact how` of `FUN_00457d88` is still not clear enough to
trust a bit-exact translation: it uses carry arithmetic
(`CARRY4`) on a pair of packed accumulators that carry at the same time
a repetition counter and a bit shift register,
and it writes TWO output rows simultaneously for each symbol consumed
(offset `_DAT_00482d05` besides the main one) — the reason for that
"doubling" of rows was not fully understood. Implementing without that
clarity would risk exactly what was asked to be avoided: producing
plausible-looking but incorrect pixels, presented as verified without
being so. It was decided to stop here and document, not guess.

## Dynamic debugging session (2026-09-10): real environment built and
## verified, but an infrastructure blocker (not of the algorithm) prevented
## reaching the pixel decoder

Goal of this session: resolve the real pending ambiguity (carry arithmetic
+ double-row write in `FUN_00457d88`) through real dynamic debugging —
no more static analysis — running `gamma.dll` under Wine, step by step,
with real register and memory values.

### Debugging environment: built and verified, it works

Chosen tool: **Wine 11.0 (Staging) + `winedbg --gdb`** (a proxy that
launches the process under Wine and connects a real `gdb` via the remote
protocol), with Python scripting embedded in gdb to automate what manual
interaction could not. Documented in detail, with the reusable code, in
`tools/gamma-dll-debug-harness/README.md`. Key pieces:
- **Minimal clean-room Java harness** (`tools/gamma-dll-debug-harness/`):
  instead of bringing up the whole client (which needs a real network/server),
  minimal Java classes were written that declare only the `native`
  methods with the exact signature (`NET.worlds.console.ScapePicImage.
  loadImage(String)`, `NET.worlds.scape.ScapePicTexture.makeTexture(String,
  String)` — signatures confirmed with `javap` against the REAL classes of
  `assets/worlds.jar`, not assumed) and call them directly. These
  classes are run under the period JRE included in the project
  (`assets/WorldsPlayer/bin/java.exe`, Java 1.4.2_05) — the same binary
  the real client would have used. Necessary trick: a modern `javac` cannot
  emit such old bytecode (minimum `--release 8`, classfile 52, which
  1.4.2 rejects), so it is compiled with `--release 8` and the
  major-version byte of the `.class` is patched by hand (52→48) — safe
  because the source code is deliberately trivial (no generics, no string
  concatenation with `+`, no autoboxing — nothing that depends on runtime
  classes later than 1.4).
- **Confirmed real, with live execution**: a breakpoint at
  `FUN_00442750` (the header validator already located by static
  analysis) IS reached when invoking `loadImage()` with a real `.cmp`, and
  an instruction-by-instruction dump with real register values
  shows the function really opening and reading the file (a real `ReadFile`
  against the real bytes of the `.cmp`) — the first live (not only static)
  confirmation that the code identified in earlier sessions is indeed
  the one that processes these files.
- **Real methodological correction found**: the symbol names that
  `gdb`/`winedbg` show for addresses of `gamma.dll` **are not
  reliable** — the same address that Ghidra (freshly reopened on the
  exact binary, `analysis/GammaDLL.gpr`, to verify) confirms as
  `FUN_00442750` (a real internal function) appeared in `gdb` labeled
  as `_Java_NET_worlds_core_SystemInfo_GetProcessorType@8+736` — a
  completely different and unrelated export. The address arithmetic
  (`runtime_base - preferred_ImageBase + static_VA`) is
  correct and reproducible between runs (`gamma.dll` always loads at
  `0x03A40000` in this environment); what must not be done is to trust the
  label that `gdb` prints — one has to verify against Ghidra directly.

### The real blocker: it is not the algorithm, it is the window/graphics device

`loadImage()` with `IDLE.CMP` (mode `0x06`, atypical) returns quickly with
`width=height=hDIB=0` — evidence that that mode takes an early exit branch,
not that the decoder fails. With a "normal" file (mode
`0x02`, `ADWORLDS.CMP` — exactly the type of simple file that was asked to
be tried first) and also with `ScapePicTexture.makeTexture()` (the
function that, according to the documentation of earlier sessions, is the one
that really invokes `getScanline`/`FUN_00442bc0`), the real execution DOES
advance beyond the header parsing — but before reaching
`FUN_00442bc0`/`FUN_00457d88` it enters the initialization of a
DirectDraw/OpenGL device and a real window, which in this particular
environment (Wine under sandboxed Xwayland, without real graphics
acceleration) **hangs indefinitely** — confirmed repeatedly, with and
without an attached debugger, with timeouts of up to 150 seconds, with evidence
of real bytes (`err:clipboard:convert_selection Timed out waiting for SelectionNotify
event`, `libEGL warning: egl: failed to create dri2 screen`, and an
asynchronous interrupt during the hang that showed a thread waiting on a
critical section of Wine's own loader held by another thread — a
device/window startup contention pattern under Wine, not an infinite
loop inside the logic of `gamma.dll` itself). Reasonable mitigations were
tried (killing the leftover `wineserver` from previous interrupted runs, Wine's
virtual desktop mode
`explorer /desktop=...`) without success within the time available in this
session.

**Honest conclusion**: the original ambiguity (carry arithmetic +
double-row write in `FUN_00457d88`) **remains unresolved** —
not for lack of trying with real execution evidence, but because
this particular environment does not allow getting that far in the real
execution of the decoder. The decoder was not implemented in Java (it
would have meant inventing the unverified part, exactly what was asked to
be avoided), and therefore no decoder was connected to the engine's
materials pipeline either — there is nothing real to connect yet.

### Concrete next step for a future session

1. Repeat the harness of `tools/gamma-dll-debug-harness/` in an environment
   with real GPU/DRI access or with a real window manager available — the
   README itself documents the exact blocker so that it does not have to be
   rediscovered. If the hang disappears there, the rest of the original plan
   (single-step through `FUN_00442bc0`/`FUN_00457d88` with real values) is
   still the right path and now there is an already verified and working
   debugging environment to do it, instead of starting from scratch.
2. Alternative if the blocker persists: investigate whether there is any way
   to invoke `FUN_00442bc0`/`FUN_00457d88` without going through the real
   creation of the device/window (e.g. calling the internal functions
   directly from `gdb` with a hand-built `this` object once its layout is
   known more precisely) — not attempted this session because of the
   risk of investing a lot of time in a layout reconstruction without
   sufficient evidence.
3. Once that is clear, implement in Java the 2D causal predictor already
   identified (copy the value of one of the ~50 neighbors of the real
   extracted table, or repeat a literal N times) and verify dimensions +
   expected output size before accepting any pixel as good.
4. Verify against the project's 17 real `.cmp` files and, if it
   shows up, against the RWX material that references them.

---

## Unblocking session (2026-09-10): Xvfb unblocks the window/device
## hang — carry and double-row ambiguity RESOLVED with real
## execution

Starting point: the previous session built a real dynamic debugging
environment (Wine + `winedbg --gdb`) but got blocked because any
execution path that went past the header parsing toward the pixel decoder
triggered the creation of a DirectDraw/OpenGL window/device, which
hung indefinitely in the sandbox (no real X, no window manager).

### The unblock: Xvfb alone, no window manager

`Xvfb :99 -screen 0 1024x768x24` was started (same pattern as the session
of the Swing `HeadlessException`, several sessions back) and
`DISPLAY=:99` was exported for Wine. **This alone was enough** — no window
manager was needed (`fluxbox`/`openbox`/etc. are not installed in this
environment and could not be installed for lack of `sudo`, but they were
not needed). With `ScapePicImage.loadImage()` on a "normal" file
(`ADWORLDS.CMP`, mode `0x02`, the simple type of file asked for) the
process no longer hangs: it finishes cleanly (`EXIT 0`) and returns
**`width=128, height=128, hDIB=0x0309004D`** — the first real,
successful decode obtained in all the sessions of this project on
`.cmp`. (The `ScapePicTexture.makeTexture()` harness of the previous session
does still fail under Xvfb, but with a DIFFERENT error unrelated to
windows — `Assertion failed: line 98 in file nScapePicTexture` during
`nativeInit()`, consistent with the minimalist harness of that class not
replicating all the fields that the native code expects; irrelevant for
this session because `loadImage()` alone, without `makeTexture()`, already
reaches and runs the real pixel decoder.)

With the environment unblocked, a breakpoint placed at `FUN_00442750`
(header validator), `FUN_00442bc0` (`getScanline`) and `FUN_00457d88`
(pixel reconstructor) — the three addresses already identified by
earlier sessions — **all three are reached, in order, during a single call
to `loadImage()`** (`ScapePicTexture.makeTexture()` is not needed
afterwards after all). Runtime addresses confirmed stable once
more (`gamma.dll` still always loads at `0x03A40000` in this environment):
`0x03A82750`, `0x03A82BC0`, `0x03A97D88`.

### Ambiguity #1 resolved: "carry arithmetic" = MSB-first bit reading,
### not multi-precision arithmetic

Real trace of 900 instructions (full single-step, with EFLAGS and the
8 general registers at each step) captured from the entry of
`FUN_00457d88`. **Zero real `ADC`/`SBB` instructions appear in the
trace** — what Ghidra flagged as `CARRY4` in its pseudocode turns out
to be the classic pattern of "reading one bit at a time from a shift
register" by means of `add %edx,%edx` (equivalent to `shl $1,%edx`)
followed by `jb`/`jae`/`je` on the resulting carry flag — the bit
that "falls off" position 31 when shifting is left in `CF`, and the code
uses it to walk a 2-3 level Huffman tree through chained
conditional jumps (not a prefix lookup table in this
part — the LHA lookup table already identified serves another
stage). Before this loop, the 32-bit register just read from the
stream is passed through `rol $0x10,%edx` (swaps the two 16-bit
halves) — a byte-order correction needed so that MSB-first extraction of
bits works on a word read in little-endian.
**There is no real multi-word carry arithmetic** — the original
ambiguity is resolved: it is the canonical LHA/Huffman bit reader already
documented in earlier sessions, applied here with complete
literalness.

### Ambiguity #2 resolved: the "double-row write" is a deliberate
### vertical duplication of 2 rows per symbol

Real evidence, address by address, of BOTH symbol paths that
write pixels (run fill and copy by predictor):

```
; fill (run-fill), after obtaining an already replicated 4-byte value
; (dx=cx=bx=ax, via the trivial dispatch handler of PTR_LAB_00483844)
mov %dx,(%edi)           ; writes 2 bytes in the CURRENT row
mov %cx,0x2(%edi)        ; writes 2 more bytes in the CURRENT row (4 in total)
add DAT_3ac2d05,%edi     ; edi += stride  (DAT_3ac2d05 = -128 for this image)
mov %bx,(%edi)           ; writes 2 bytes in the OTHER row (edi+stride)
mov %ax,0x2(%edi)        ; writes 2 more bytes in the OTHER row (4 in total)
sub DAT_3ac2d05,%edi     ; edi -= stride  (back to the current row)
```

```
; copy by 2D predictor (table at 0x3ac2d0d, see below)
mov 0x3ac2d0d(,%ebx,4),%ebx  ; ebx = table[index] = byte offset of the neighbor
mov (%ebx,%edi,1),%eax        ; reads 4 bytes of the predicted neighbor
mov %eax,(%edi)                ; writes them in the CURRENT row
rol $0x8,%eax
mov %al,(%esi)                  ; 1 byte to the "palette" output buffer (esi)
add DAT_3ac2d05,%edi            ; edi += stride
mov (%edi,%ebx,1),%eax          ; reads 4 bytes of the neighbor, this time relative to the OTHER row
mov %eax,(%edi)                  ; writes them in the OTHER row
sub DAT_3ac2d05,%edi              ; back to the current row
rol $0x8,%eax
mov %al,0x1(%esi)                   ; next output byte
```

**Confirmed with real evidence: each symbol (fill or copy by
predictor) writes the same 4-byte block into TWO rows separated by
exactly one `stride`** — it is not the cleaning of a scratch buffer nor an
accidental side effect; it is the central operation of the symbol. Given
that the stride is negative ("bottom-up" DIB) and all the rest of the
evidence (predictor table with row offsets down to -4,
below) indicates that the image is decoded in the standard
top-to-bottom direction while the physical buffer grows toward lower
addresses, the most consistent interpretation is that **each symbol paints a
block of 4×2 pixels (4 wide, 2 rows high) with the same value
at once** — a deliberate compression optimization that
exploits the vertical coherence typical of textures of smooth surfaces,
not an auxiliary construction. (Alternative not entirely ruled out: that
it is a pre-seeding of the next row before decoding it — in
any case, the verified fact relevant to implementing the
decoder is the SAME: write the block at `edi` and at `edi±stride` at
once.)

### Bonus: the runtime predictor table matches EXACTLY the
### static table already extracted, with the conversion formula corrected

The real table that `FUN_00457d88` uses at `0x3ac2d0d` was dumped
(24 dwords, live memory, not inferred):

```
0x3ac2d0d: 0x00000000 0xfffffffa 0xfffffffb 0xfffffffc
0x3ac2d1d: 0xfffffffd 0xfffffffe 0x00000200 0x00000201
0x3ac2d2d: 0x00000202 0x00000203 0x00000204 0x00000205
0x3ac2d3d: 0x00000206 0x000001fa 0x000001fb 0x000001fc
0x3ac2d4d: 0x000001fd 0x000001fe 0x000001ff 0x00000180
0x3ac2d5d: 0x00000181 0x00000182 0x00000183 0x00000184
```

Compared against the static table of `(row_offset,
column_offset)` already extracted from `0x478e98` in an earlier session
(`docs/gamma-dll-cmp-evidence/predictor-offset-tables.txt`), **every
entry matches exactly** the formula
`offset = colDelta + stride·rowDelta` (with `stride=-128` for this
image) — for example `(0,-6)→-6`, `(-4,0)→0+(-128)·(-4)=512=0x200`,
`(-4,6)→6+512=518=0x206`, `(-4,-6)→-6+512=506=0x1FA`. **Real correction
relative to the previous session**: the tentative formula documented then
was `offset = colDelta - stride·rowDelta` (with a negative sign) — the real
execution confirms that it is `colDelta + stride·rowDelta` (not negated).
This connects solidly, with evidence from two different sessions (static
extraction of the table + real use in execution), the 2D prediction
mechanism documented from the beginning.

### Real ground truth captured: row 0 decoded, byte by byte

The real output row (128 bytes, pointed to by `esi` =
`0xc(%ebp)`) was dumped right upon returning from the ONLY real call to
`FUN_00457d88` during a `loadImage()` of `ADWORLDS.CMP` (128×128): **the
128 bytes are constant `0xAD`** — it matches exactly the pattern
`0xadadadad` seen repeated throughout the rest of the trace (the value
replicated by the trivial dispatch handler), cross-confirming that
this row was decoded entirely via the "fill" path (run-fill). Saved
as raw evidence in
`docs/gamma-dll-cmp-evidence/adworlds-row0-dump.txt` to verify
against a future Java reimplementation.

### Important real correction: `FUN_00457d88` is invoked ONLY ONCE
### per `loadImage()`, not once per row

With the 3 breakpoints (`FUN_00442750`, `FUN_00442bc0`/`getScanline`,
`FUN_00457d88`) armed, all three are reached **exactly once each**
during an entire `loadImage()` — the process ends normally without
hitting any of them again, even for an image of 128
rows. This corrects the initial assumption of this session ("one call =
one row decoded per `ch`, a counter of groups of 4 pixels"): with
`ch=32` and width=128 (`128/4=32`), that arithmetic DOES fit for a single
row, but the evidence of a single total invocation pointed to the fact that
either (a) this call decodes the COMPLETE image in an outer loop
beyond the 900 traced instructions, or (b) `loadImage()` itself only
materializes one representative row and the rest is decoded later via
`makeTexture()`.

**Resolved in favor of (a), with additional evidence**: the trace was
extended to 6000 instructions (only recording the PC at each step, without
dumping complete registers, to keep it manageable), checking at
each step whether `ESP` rose again above its entry value (which would
indicate a real `ret` back to the caller) and whether the `PC` returned to
`0x03A97D88` (a real re-entry into the function). **Neither of the two
things happened in 6000 instructions** — execution continues inside the
function (final `PC` `0x03a97e31`, within the same address range
already seen). Given that decoding a single row of 128 pixels at ~4 per
symbol with ~20-30 instructions per symbol would fit in about 700-900
instructions (right where the first trace was cut), and even so at 6000 it
still does not return, the much more consistent explanation is that
**a single call to `FUN_00457d88` decodes the COMPLETE image
(all 128 rows), not a single row** — consistent with `getScanline`
only needing to invoke the decoder once and then serve each
subsequent row by returning pointers into the already fully decoded
buffer. The real `ret` was not witnessed (it would have been necessary to
trace tens of thousands more instructions, a cost not justified for this
session), so this remains a strong inference backed by real negative
evidence (absence of return/re-entry in 6000 steps),
not a direct observation of the `ret`.

### What remains genuinely unverified

- The exact meaning of the sentinel byte `0x24` (36 decimal) that
  causes an early exit from the "control byte" branch was not
  investigated beyond confirming that it exists.
- The full symbol space of the internal Huffman tree (only the
  branches that this particular row, entirely flat, happened to exercise
  were traced — a file with more pixel variation would exercise more
  branches and could reveal behavior not seen here).
- A Java decoder was not yet implemented or verified against the
  real ground truth captured — given that the two
  specific ambiguities that motivated this session (carry arithmetic, double
  row) ARE resolved, and the call granularity was also reasonably
  clarified (one call decodes the complete image),
  but the full symbol space of the Huffman tree is NOT — only the
  branches that a completely flat row happened to touch were
  exercised — implementing now would risk exactly what the project
  prohibits: producing plausible-looking but unverified pixels. Concrete and
  honest next step for a future session: trace 2-3 additional real
  `.cmp` files with non-flat content (to exercise more
  branches of the symbol tree, including the 2D predictor copy path and
  the sentinel byte `0x24`) before writing the decoder.

**Conclusion**: the two ambiguities that motivated all the dynamic
research of this session and the previous one — carry arithmetic and
purpose of the double-row write — are **resolved with real
execution evidence**, not just hypotheses. What is missing for a complete
Java decoder is additional implementation and verification work (not
design ambiguity), documented above as concrete next steps.

---

## Closing session (2026-09-10, continuation): symbol tree widened
## with varied real files, `0x24` resolved, Java decoder implemented
## and partially verified — NOT connected to the pipeline yet

Goal: close the `.cmp` decompressor by exercising the complete symbol tree
(not just the trivial flat-row case of the previous session), implement
the decoder in Java, and verify it byte by byte against the real
`gamma.dll` before connecting it to the materials pipeline.

### Varied real corpus located and confirmed non-flat

Of the project's 13 unique real `.cmp` files, the Shannon entropy of each
was computed as a cheap filter before spending debugging cycles:
`ADWORLDS.CMP` (the row already analyzed) has entropy 5.0, far below
the rest (7.0-7.8), confirming that it was a degenerate case.
`4i.cmp`, `4h.cmp`, `48.cmp`, `4a.cmp` and
`ADFRAME.CMP` (entropy 7.4-7.8) were selected as real non-flat candidates; all 5
decode successfully under Xvfb (128×128, real `hDIB`). Row 0
of `4i.cmp` was dumped and turned out to be genuinely varied (9+ distinct
byte values in 16 bytes, versus the constant `0xAD` of `ADWORLDS.CMP`) —
a valid corpus to exercise new branches of the symbol tree.

### Important real correction: the call granularity of earlier sessions
### was wrong — `ch` produces exactly `ch×2` bytes,
### not a row nor the complete image

The previous session, on not seeing a `ret` or a re-entry in 6000
traced instructions, inferred that a single call to `FUN_00457d88`
decodes the COMPLETE image. Real verification this session (placing a
breakpoint at the real return address, computed from `*esp` on entering the
function, instead of assuming) shows that **one call produces
exactly `ch×2` bytes of real output** (`ch=32` in all the files
tested ⇒ 64 bytes = half a row width for a 128px image) — neither
a complete row nor the whole image. Future sessions that need the
complete image will still need to resolve `ScapePicTexture.
makeTexture()` (see below) or understand how `getScanline` composes
several calls.

### Complete symbol space, mapped with real evidence (live and
### static)

With the varied file (`4i.cmp`), a trace of 4000 instructions revealed
**236 new addresses** never seen in the flat trace of the previous
session. Analyzed with complete registers, they reveal the complete
structure of the upper binary tree (2 real bits, not 3 — the third
jump that seemed to be an additional level actually re-evaluates the SAME
result of a single `add edx,edx`, reading the carry flag and the zero
flag separately):

- **bit1=0** → 4-byte predictor copy (one index, already documented
  before).
- **bit1=1, bit2=0** → **DUAL 2-byte predictor copy** (new):
  two independent indices, one per 2-pixel half of the group of 4,
  each with its own double-row write.
- **bit1=1, bit2=1** → **"control byte" branch** (before, only the trivial
  fill case of the flat row had been seen): a control byte
  determines, according to its low 3 bits and bits 3+, between a direct
  literal pair, a back reference (`lookback`) inside the already written
  output row itself, or a combination of both.

**The sentinel byte `0x24` (36 decimal) — actively sought, never
appeared live in the files tested (0 matches in 58 real
comparisons), but resolved with fresh static disassembly from Ghidra** of
the destination address (`0x00457fb0`): it is **NOT an end-of-stream
marker** as suspected — it is an **8-byte raw literal escape path**: it reads
8 bytes directly from the literal stream and writes them as two
4-byte blocks (one per row, the same double-write pattern as
everything else), without going through the predictor table at all.
Consistent with the rest of the design: a generic escape mechanism for
content that fits no prediction/fill pattern.

**Real unanticipated finding, found while debugging the first failed
verification attempt**: every iteration of the "control byte" branch that
is NOT `0x24` **also** consumes, without exception, a byte of the
fill-index stream (the same stream used by the flat fill path of the
previous session) and does an additional broadcast write (4
copies of the byte that ended up in the output of this iteration) into the
history — with the same double-row pattern as everything else. This had
not been documented before because in the flat file of the previous
session it was indistinguishable from "doing nothing" (the broadcast
value matched the value already present). It was found only when
verifying against a real file with variation, when the Java decoder
failed on ALL the bytes until this was corrected.

### Java decoder implemented and verified — partially

`tools/gamma-dll-debug-harness/cmp-stage2-decoder/CmpStage2.java`
implements the complete Stage 2 (symbols already Huffman-decoded →
real pixels) with the whole structure above. Verified against
real data extracted live (streams + history window + real output,
all from the SAME process in a single run, to avoid comparing across
different runs — a real mistake made and corrected during this
session):

- **`adworlds.cmp`**: 34/64 bytes exact. The remaining 30 are a single
  contiguous block, and each one corresponds to a predictor read with an
  offset >250 bytes forward — beyond what a single memory dump can
  reliably capture (the real process may keep reading there without failing,
  probably due to lazily committed pages as one writes nearby; a static
  Python dump at a single instant cannot reproduce that). A data-capture
  limitation, not evidence of a design error — in this completely flat
  file, EACH of those bytes should be `0xAD` just like the rest, and the
  decoder produces them wrong only because my zero-fill takes the place of
  real data that I could not capture.
- **`4i.cmp`**: 55/64 bytes exact. The remaining 9 (positions 41-49)
  were investigated in depth: the EXACT sequence of control bytes and the
  consumption of literal stream position were verified, iteration
  by iteration, against a live trace (26 "control byte" iterations
  compared one by one, perfect match), and the specific literal byte
  that the decoder reads was confirmed in live memory at the correct
  position — and even so, the "ground truth" captured for those specific
  positions does not match. Not resolved before the time of this session
  ran out. See the "ground truth" capture method in
  `tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md` — the most
  likely explanation, given everything else independently verified, is a
  problem of the capture method itself, not of the algorithm, but **it has
  not been demonstrated** and is honestly documented as open.

### `ScapePicTexture.makeTexture()` — real progress, still blocked

An attempt was made again to unblock `makeTexture()` (needed to decode
a complete image, not just 64 bytes) by replicating more faithfully the
real class hierarchy (`Texture` with `textureID`/`refs`/`classCookie`,
`ScapePicMovie` with the exact type). This DID advance the failure point (from
`Assertion failed: line 98` to `line 99`, and finally to a real
`EXCEPTION_ACCESS_VIOLATION` — deeper in the real code than
before) but it was not fully resolved. It was not investigated further
because of the session's time limit.

### Why nothing was connected to the materials pipeline this session

Following the project's explicit rule (never plausible-looking but
unverified pixels), and given that NO real file reached 100%
byte-exact verification (34/64 and 55/64, not 64/64), **the decoder was
not connected to the rendering pipeline**. It would have been easy to show
"something" on screen, but it cannot honestly be claimed to be the
real texture until the verification is complete. Concrete and prioritized next
step for a future session: (1) improve the ground-truth capture method
(real breakpoints at each write instruction instead of polling
`$pc` on every `stepi` — faster and more reliable), (2)
resolve the 9-byte gap of `4i.cmp` with cleaner data, (3) once
100% verified on 2-3 files, connect to the pipeline and verify by
color histogram that real texture patterns appear.

---

## Stage 1 session (2026-09-11): the real Huffman decoder actually
## disassembled with real evidence — complete architecture understood,
## the exact chaining between "rows" is still not closed (NOT functional yet)

Goal: implement the real Stage 1 (raw `.cmp` bytes → the 5
symbol streams that `CmpStage2` already consumes byte-exactly), motivated
by the need to decode real `GroundZero` textures (159
official `.cmp` files with no prior stream capture — without Stage 1, none
of them is decodable). **It was not fully closed**,
but a much longer chain than before was disassembled with real evidence
(Ghidra/`llvm-objdump`, no guessing), including
**the complete real bit decoder**, and everything is documented here with
byte-by-byte precision so that a future session does not have to repeat
this work.

### 34-byte header — complete layout, verified against the 3
### known real files

`FUN_00442750` (runtime offset confirmed, `0x03A82750` in this
environment) reads and validates 34 bytes (`0x22`) as follows:

```
[0..3]   "LzH2" (magic, compared with memcmp against 0x479324)
[4]      "mode" (0x02 in the 3 test files)
[5]      flags: bit7 must be 1; bits 2,3,4,6 must be 0; bits 0,1,5 free
           (bit0=1 in test4b, 0 in rustwood/sball — strong candidate to be
           the "orientation" flag that `CmpTexture.java` already votes per file
           as `orient`, without knowing its origin — this session locates it
           in the header, without connecting it yet)
[6..7]   W (u16 LE)          -- already used by CmpTexture.java
[8..9]   H (u16 LE)          -- already used by CmpTexture.java
[10..18] not decoded (9 bytes, they vary per file)
[19]     must be 0 (verified in the 3 files)
[20..31] not decoded (12 bytes)
[32..33] payload size = fileSize - 34 (u16 LE) — **verified exact in
           the 3 files**: test4b 364, rustwood 6539, sball 3954,
           each = total file size minus 34.
```

### The 3 fixed-alphabet permutation tables — extracted byte by byte
### directly from the binary (not from the memory of earlier sessions)

`FUN_00442590(tableIndex, flag, &out)` is a 4-way switch (real jump
table at VA `0x4792e8`, read directly from the file):

- index 0 → 81 bytes at VA `0x47927c`:
  `555657595a5b5d5e5f656667696a6b6d6e6f757677797a7b7d7e7f959697999a9b9d9e9fa5a6a7a9aaabadaeafb5b6b7b9babbbdbebfd5d6d7d9dadbdddedfe5e6e7e9eaebedeeeff5f6f7f9fafbfdfeff`
  (real permutation, not sequential)
- index 1 → 49 bytes at VA `0x479028`:
  `0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f3031`
  (sequential 1..49 — de facto identity)
- index 2 → **degenerate**: the jump table points to the same "out of
  range" case as index≥4 (`eax=0`, `*out` stays at 0 without being
  written) — the channel of index 2 has no permutation table nor fixed
  alphabet at all. Real meaning NOT resolved (see below).
- index 3 → 22 bytes at VA `0x4792d0`:
  `0001020304080a0b0c1011131418191a1c2021222324`

### The 5-channel loop in `getScanline` (`FUN_00442bc0`) — channel↔stream
### mapping confirmed by disassembly, not assumed

Complete disassembly of `0x442e63`-`0x442f5b`: for each "group"
(called once before each call to Stage 2, `FUN_00457d88`), it reads
a pointer `dec` from a small structure and, for `edi=0..4`, if
`dec_orig[2+edi*2]` (u16) is non-zero, it calls
`FUN_00426af0(this=tableHandle, compressedPtr, outputPtr, wantedLen)` —
and **the result is stored in a local array `[-0x28(ebp)+edi*4]` that
is literally the same pointer (`structptr`) that is later passed as the
5th argument to `FUN_00457d88`/Stage 2** — it confirms with real
disassembly (not just with `cmp_capture.py`, which had already found it
empirically) the channel order: `edi=0→bits, 1→streamA,
2→streamFillIdx, 3→streamCtrl, 4→streamLit`. **Channel 4 (`lit`) uses
a direct copy** (it does not go through `FUN_00426af0`), consistent with "1 of 5
without Huffman".

**Intriguing implication, unresolved**: channel 2 (`streamFillIdx`)
is exactly the one that has a degenerate alphabet (index 2, no
permutation) according to `FUN_00442590` — but `streamFillIdx` DOES have
real, varied content in the verified files (it is the 8-bit mask that
chooses `al`/`ah` per lane, documented in
`cmp-stage2-decoder/README.md`). Either "degenerate" does not mean "empty"
but "uses 1-byte code lengths without permuting" (an alternative
interpretation of `FUN_00426640` not ruled out), or the
channel↔alphabet-index mapping is not 1:1 with the channel↔output-stream
mapping that was just confirmed above — **open, explicitly marked
so as not to invent an explanation**.

### The real bit decoder, `FUN_00426af0` — completely disassembled,
### simple algorithm and now understood with high confidence

Contrary to what was assumed in earlier sessions ("2-3 level Huffman
tree"), the real disassembly (VA `0x426af0`-`0x426bae`) shows that
**all codes have length ≤ 8 bits** — there is no need to walk
any tree, it is a direct lookup table of 256 entries:

```
table: 512 bytes per channel = [0..255]=symbol, [256..511]=code_length
window = (byte[pos]<<8) | byte[pos+1]; pos += 2   # first load, 16 bits
bitsAvailable = 8   # signed counter (ch, 1 byte)
for each one of the `wantedLen` output bytes:
    idx = (window >> 8) & 0xFF          # top byte of the 32-bit window
    symbol = table[idx]; length = table[256+idx]
    emit(symbol)
    oldBits = bitsAvailable
    bitsAvailable -= length
    if bitsAvailable < 0:              # a reload is needed
        window <<= oldBits            # consumes the bits that WERE there
        newByte = byte[pos++]
        window = (window & ~0xFF) | newByte   # only the low byte
        missing = length - oldBits
        bitsAvailable += 8
        window <<= missing               # aligns the new byte
    else:
        window <<= length
returns: final_pos - initial_pos   # bytes consumed from the compressed stream
```

This reproduces exactly the classic LHA/LZH trick of a 32-bit
accumulator with a 1-low-byte reload on demand — but with NO "long
code" path at all (unlike generic LHA, which does need to
handle codes >8 bits with an overflow table). It matches the
"frequency count per length 0-8" already documented.

### Table construction (`FUN_00426640`/`FUN_004266f0`/`FUN_00426820`)
### — recognized as LHA's `make_table()`, PARTIALLY ported, with
### an unverified degenerate case

`FUN_00426640` unpacks 4-bit nibbles (2 per input byte,
one per symbol of the REDUCED alphabet of size 81/49/22) and
scatters them into an array of 256 lengths using the permutation table
as the destination index — confirmed by line-by-line disassembly.
`FUN_004266f0` recognized with high confidence as the canonical
`make_table()` of LHA (counts frequencies per length, computes
`start[l+1]=(count[l]+start[l])·2`, assigns codes in a 2nd pass) —
**with a special degenerate case** (`if sum<=1: return early`) whose exact
behavior in the expansion phase (`FUN_00426820`) was only partially
disassembled: there is a "simple" branch (`[ebp+0xc]<=1`) that
fills the whole symbol table with the value `0` — but the GENERAL case
(>1 real symbol) of `FUN_00426820`, which expands the canonical codes
assigned into the direct 256-entry table, **was implemented following the
textbook LHA pattern (filling `2^(8-length)` consecutive slots from the code
aligned to 8 bits), not a literal instruction-by-instruction translation of
the disassembly** — a real risk of being subtly wrong.

### Java implementation attempt: NOT functional yet — the "advance
### between groups" of the outer loop is the piece that fails

With everything above, a Java prototype (not included in the repo,
it lived in `/tmp` during this session) built the 4 Huffman tables
correctly (the count of bytes consumed to unpack the lengths —
41+25+0+11=77 bytes — matches exactly what is expected for
alphabets 81/49/0/22), but the outer loop that should read, group by
group, 5 length fields (u16) and decode each channel, **diverges
after 3-4 groups**: the first groups read length 0 in the 5
channels (plausible for an almost entirely flat file such as `test4b.cmp`,
but not verified as correct), and by group 3-5 lengths appear
that exceed the total byte budget of the file
(`lit=252` when only ~287 bytes remain in the whole payload for
`outer=16` groups) — a clear sign that the pointer advance between
groups (assumed `+0x10=16` bytes, taken literally from the disassembly of
`getScanline`) and/or the exact position of the 5 length fields
within that 16-byte structure **is not yet well modeled**
— 6 of the 16 bytes per group remain unexplained (possibly more metadata,
or the count `outer=H/2` is not the real number of groups).

### What remains for the next session, with evidence already in hand

1. Trace live (winedbg/gdb, an environment already tested and working this
   session: `Xvfb` + `wineserver -k` + `winedbg --gdb` with temporary
   breakpoints at the return address, do NOT use `finish` — it does not
   behave as in native gdb under the winedbg proxy, confirmed
   this session) a breakpoint at the TOP of the outer loop of
   `getScanline` (`0x442e05`/`0x442fab` at runtime, variable delta —
   see the note "gamma.dll's load base is NOT fixed" in the README of the
   harness) to capture live how many groups actually run
   and what exactly each 16-byte block contains (the 2 u16 fields
   already identified at offsets 0 and 0xc of `dec_orig`, besides the 5
   lengths at offsets 2-11 — offsets 12-15 remain to be decoded and the
   0/0xc to be confirmed).
2. Verify the general case of `FUN_00426820` with complete line-by-line
   disassembly (this session only read it partially) instead of the
   textbook implementation used in the prototype.
3. Resolve the anomaly of channel 2 (`streamFillIdx`) with a degenerate
   alphabet — it probably needs to be traced live to see what
   `FUN_00426930` really builds when `alphabetSize=0`.
4. Once the prototype decodes `test4b.cmp` byte-exactly against
   `assets/gammatutorial-samples/test4b.cmp` (comparing against its already
   verified streams in `tools/gamma-dll-debug-harness/
   cmp-stage2-decoder/test4b_stream_*.bin`), repeat against
   `rustwood.cmp`/`sball.cmp`, and only then attempt the 159
   real files of `assets/WorldsPlayer/GroundZero/content.zip`.

**None of this is connected to the materials pipeline** — not a single byte
of the 159 real GroundZero textures was decoded this session; the
prototype did not manage to produce verifiable output against any known
file. Honestly documented as real but incomplete research, not as
functional progress.

### Round 2 (2026-09-11, the same session continued): the outer loop
### has A SINGLE group, not 16 — and a deeper architectural problem is
### discovered (buffered stream reader, not a flat pointer into the
### file)

Live trace (`winedbg`/`gdb`, auto-continuing breakpoint at
`0x442e66` — right AFTER `eax` loads the `dec_orig` pointer, not
at `0x442e63` as in the first attempt, which captured the OLD value of
`eax` before the load instruction itself) against `test4b.cmp`:

**Finding 1 — there is only ONE group, not `h/2=16`**: the breakpoint (which
auto-continues, so it would have captured any real repetition) fired
only **once** in the whole `loadImage()`. The real content of those
16 bytes was `10 00 20 00 7c 00 04 00 04 00 05 00 00 00 00 00` —
interpreted with the already known layout (offset 0 and 0xc = unidentified
fields, offsets 2-11 = 5 u16 lengths): `bits=32 streamA=124
streamFillIdx=4 streamCtrl=4 streamLit=5`. **Strong cross-confirmation,
not a coincidence**: `streamA=124` and `streamCtrl=4` match
EXACTLY the branch census independently established in an earlier
`.cmp` session for this same file ("real: 124 SINGLE + 4
CTRL + 0 DUAL") — SINGLE consumes one `streamA` index per iteration,
CTRL one `streamCtrl` byte — validating that the semantic
interpretation of these 5 fields is correct. This also resolves an old doubt
from earlier `.cmp` sessions ("why only one real call to
`FUN_00457d88`?"): `FUN_00457d88` receives ALL the channel data at
once (a single group covers the whole image) and loops internally over
its `outer` passes using that already complete buffer — no more than
one call is needed.

**Finding 2 — the memory-address→file-offset mapping is NOT linear,
architecture more complex than assumed**: searching for the exact
content of those 16 bytes inside the `test4b.cmp` file itself, it appears at
**offset 359** (of 398 total) —
confirming that the group DOES live somewhere correlatable with the
real file. But when attempting the SAME correlation for the pointers
used in building the Huffman tables (captured with a breakpoint at
`FUN_00426640` and at the call site of `FUN_004269c0`
inside the loop of `FUN_00442750`), **the computed offsets come out
negative** (using `fileBase = addr_group - 359` as a reference) —
that is, those pointers do NOT fall within the same linear address space
as the group pointer. This indicates that **the compressed data
is not read as a flat buffer mapped 1:1 with the
file** — the already documented call chain (`FUN_00442750` calls
`0x42f460`, identified in earlier sessions as a
`ReadBytes(readerObject, dest, size)`, not a simple `memcpy`) confirms
that there is a **stream reader object with its own internal buffer**
(probably Win32 `ReadFile` with buffering), and the different
phases (table construction, then channel decoding) read
through that reader, not from a flat array — so "position X in the
pointer seen in memory" and "offset X in the file" only coincide
by chance of content (as with the group, found by
content search, not by pointer arithmetic).

**Honest implication**: my model of "a `pos` that advances linearly
over the bytes of the file, consumed both by the table construction and by
the channel decoding" (used in the Java prototype of round 1) is
**structurally incorrect** — it is not just a wrongly computed
offset, it is a buffered stream-reading architecture that has not been
investigated yet. Really closing this requires
understanding the reader object (`0x42f460` and its refill/internal
buffer counterpart) before being able to translate "how many bytes
this phase consumed" into "where the file continues" reliably — it is not
a minor correction of offsets, it is a new piece of reverse engineering.

**What IS genuinely gained this round**: the semantic mapping of
the 5 length fields per group (with real and independent
cross-evidence for 2 of the 5: `streamA` and `streamCtrl`), and the
confirmation that there is only one group per image (not one group per pair
of rows) — both real and useful facts for the next session,
even though the stream reader object remains undisassembled.

**No attempt was made** to verify `FUN_00426820` in detail or to decode
any real GroundZero file — the finding about the stream reader
made those steps premature (following the explicit instruction not to
speculatively chase the degenerate channel 2 before resolving the
above). Concrete and bounded next step: disassemble `0x42f460` (the
reader) and its buffer/refill mechanism, with live tracing of the
real file-position value that it keeps internally, BEFORE
resuming the pointer→offset translation.

## Real Stage 1 session (2026-09-12): the "buffered reader" was a
## mirage, Stage 1 actually implemented — 4/5 streams byte-exact,
## embedded palette discovered, one unresolved color-mapping bug

Goal of the session: resolve the blocker of the "buffered stream reader"
(found in the previous session) and get Stage 1 working against real
files from the game, not just the 3 test ones. A verification
harness against the complete real corpus was built first (see
`docs/cmp-stage1-coverage.md`), and then the blocker was resolved with 3
read-only subagents in parallel.

### The "buffered stream reader" does not exist — it was a comparison between
### pointers of two different heap allocations

Three read-only subagents, each investigating a different hypothesis
(structure/initialization of the reader; refill mechanism; cross-comparison
among the 3 known files), independently and consistently confirmed:

- `FUN_0042f460` is literally MSVC/Dinkumware's
  `std::istream::read(buf, count)` — with no buffering complexity of its own
  beyond what the standard streambuf already does. There is no need to model
  any special reader object.
- For `test4b.cmp` (398 bytes) there are exactly 3 read calls,
  verified live byte by byte: 34 bytes (header, file offset
  `[0,34)`), 325 bytes (table-construction region, `[34,359)`), and 39
  bytes (group region, `[359,398)`) — contiguous, with no gaps, with no
  overlap.
- The "negative offset paradox" of the previous session (table-construction
  pointers did not correlate linearly with the group pointer) is
  completely explained: they are two DIFFERENT heap allocations
  (the 325-byte region goes to one buffer, the 39-byte region of the
  group to another) — there was never a reader with a complex window, unrelated
  memory pointers were just being subtracted.

### 34-byte header — 2 new fields decoded with real evidence

```
[28..29] tableRegionSize (u16 LE) — exact size of the 2nd read
           (325 for test4b, 34+325=359 matches exactly the group offset
           already known by content search)
[30..31] groupRegionSize (u16 LE) — exact size of the 3rd read (39
           for test4b); tableRegionSize+groupRegionSize == payloadSize
           always, verified exact
[14..18] 5 bytes, one per channel (0=bits,1=streamA,2=streamFillIdx,
           3=streamCtrl,4=streamLit): exact byteLen that this channel
           consumes during the construction of its Huffman table in the
           table region — verified exact against live capture
           (28,16,1,7,32 for test4b)
```

### The "buffered reader" disappeared, but a real preamble appeared: an
### embedded color palette, never decoded before

Before the 4 Huffman table constructions, the table region has
a preamble (239 of 325 bytes for test4b) that was thought to be ~7 bytes in
earlier sessions. Real disassembly of `FUN_00442750` (the stretch between
the 2nd read and the table-construction loop) reveals that it is an
**embedded color palette**, decoded by `FUN_004426b0`:

```
count = header[12] (if 0, 256)   -- 64 for test4b
for each one of the `count` entries:
    for each one of the 3 components (R,G,B in that order):
        read 6 bits from the stream (MSB first, 1-byte accumulator with
        per-byte refill, same mechanism as FUN_00426af0 but for 1
        bit instead of a complete code)
        component = value_6_bits << 2   (scale 6→8 bits)
    write 3 real bytes + 1 null padding byte (does not count for the
    bit stream, it is only the memory layout of gamma.dll)
```

Verified bit by bit by hand against the raw bytes of the file (not just
with the code itself): the 4 real entries of test4b (58→green,
60→red, 62→yellow, 63→blue) match exactly when extracting the bits
manually with Python, confirming that the bit extraction is 100%
correct against the real file — the problem (see below) is not in
this extraction.

After the palette, the cursor advances conditionally according to bits of
the **mode** byte (offset 4, not flags) and of the **flags** byte (offset 5):

```
cursor = bytesConsumedByPalette
if (mode & 0x02) == 0: cursor += count
if header[13] != 0: cursor += floor((header[13]*18+7)/8)
if (flags & 0x01) != 0: cursor += floor(count/2) + count - 1
if (mode & 0x08) != 0: cursor += 4
if (mode & 0x80) != 0: groupCount = u16(cursor); cursor += 14
else: groupCount = 1   (always the case in the 3 known files)
```

For test4b: mode bit1=1 (does not add), header[13]=0 (does not add), flags
bit0=1 (adds 95), mode bit3/bit7=0 (does not add) → cursor=144+95=239,
exact.

### The 4 Huffman tables — complete algorithm verified with real data,
### 2 implementation bugs found and fixed

`FUN_00426640` (nibble unpacking) disassembled instruction by
instruction: `effectiveCount = min(alphabetSize, 2*byteLen)` nibbles are
read (NOT always `alphabetSize` nibbles as was assumed) — the symbols of
the reduced alphabet that fall outside `effectiveCount` simply
keep length 0 (no code). Confirmed exact against the 4
real `byteLen` of test4b.

`FUN_004266f0`/`FUN_00426820` (canonical assignment + expansion into the
direct 256-entry table) — 2 real bugs found this session when
implementing in Java, both with clear symptoms:

1. **Off-by-one in the `start[]` array**: `start[1] = 0` directly (not
   derived from `count[0]`, which never participates — length-0 symbols
   have no code). The initial implementation computed
   `start[1] = count[0]*2`, producing codes that overflowed the
   256-entry table (an immediate `ArrayIndexOutOfBoundsException` when
   tested).
2. **Incorrect length in the degenerate case** (a single real symbol):
   the initial implementation set `length=0` for all 256 entries
   of the degenerate table — but the real length must be that of the ONLY
   real symbol (e.g. 1 bit), not 0. The symptom was invisible in the
   degenerate channel itself (`streamFillIdx`, which yields the constant
   symbol 0 no matter how many bits are consumed), but it desynchronized
   the SHARED bit cursor for the next channel (`streamCtrl`), which then
   failed with symptoms that looked like a bit-alignment problem.

### The bit decoder needs SHARED state across channels

Confirmed empirically (not just by reading the previous documentation,
which was ambiguous about this): the 16-bit window and the
available-bits counter of `FUN_00426af0` must persist across the 5
per-channel calls within a group — ONLY the first channel (`bits`) does the
initial fresh 16-bit load; channels 2-5 continue from where the
previous one left the state (including loose bits in the middle of a byte).
Explicitly tested against both models (fresh reload per channel vs. shared
continuation) — only the shared model reproduces
`streamA` (124 symbols, with many real refills) byte-exact.

### The mystery of channel 2's "degenerate alphabet" — resolved

Confirmed by complete static disassembly (read-only subagent): it is NOT
an empty channel. `FUN_004269c0` checks
`permTablePtr==0 || alphabetSize==0` and in that case synthesizes an
identity permutation of 256 symbols (`0,1,2,...,255`) and forces
`alphabetSize=256` BEFORE building the table — so channel 2
(`streamFillIdx`) is Huffman-coded over the FULL alphabet of
256 bytes instead of one of the 3 reduced alphabets (81/49/22), which
fits perfectly with it being the only channel that needs to represent
any byte value (the al/ah lane selection mask), not an
opcode/escape from a small closed set.

### Verified byte by byte against the already captured streams of test4b.cmp

`bits`, `streamA`, `streamFillIdx`, `streamCtrl`: **0 discrepancies**,
byte-exact against `tools/gamma-dll-debug-harness/cmp-stage2-decoder/
test4b_stream_*.bin` (live capture from earlier sessions, independent
ground truth). `streamLit` (channel 4, the literal escape mechanism,
little used): very close but NOT exact — see the limitation below.

### Two honest limitations, explicitly documented in the code
### (`CmpStage1.java`), NOT resolved this session

1. **`streamLit` (channel 4)**: the real mechanism of building its table
   uses `FUN_0044df50` (a flat 32-byte memcpy), not
   `FUN_004269c0` like channels 0-3 — treating it the same as the
   degenerate case of channel 2 (identity alphabet of 256) gives an output
   VERY close to the real one (the same 4 symbol values, same code lengths)
   but rotated by exactly one code position with respect to the
   expected value. Several hypotheses were tried (fresh reload instead of
   continuing; swapping the order with `ctrl`; direct-index table of
   5 bits) without success — it remains open.
2. **Mapping of decoded pixel index → palette entry**: the bit
   extraction of the embedded palette was verified 100% exact
   against the raw bytes of the file (by hand, with Python, byte by byte),
   and the spatial regions of the image decode perfectly
   (independent proof that the symbol streams are correct) —
   but the final color assigned to each index comes out ROTATED among the 4
   real entries used (58,60,62,63 for test4b): index 58
   needs to show red but `palette[58]` contains green (which
   belongs to another index). Several transformation hypotheses were
   tried (uniform index shift, XOR, subtraction, reversed
   read order, reordering of the R/G/B components) — none
   explains the exact rotation observed. Documented in detail in the
   `KNOWN LIMITATION` comment of `CmpStage1.java`, not hidden.

### `CmpTexture.loadRaw(File)` — real integration, no regression

`CmpTexture.loadRaw(File cmpFile)` was added, which decodes a
real `.cmp` using `CmpStage1` and reuses the ALREADY VERIFIED pipeline of
`CmpStage2` (the same code that `load()` already used with
pre-captured streams). The original path `load()` (pre-captured streams +
hand-made `palette.txt`) was tested unchanged against `sball.cmp` — it still
works exactly, zero regression.

### Verification against the real corpus (closing criterion of this session)

See `docs/cmp-stage1-coverage.md` for the complete numerical result
against the 159 real files of `content.zip` using `loadRaw()` — given
the unresolved palette mapping bug above, it is expected that most
files will NOT decode to correct pixels yet, but the
complete corpus was run anyway to have the real number, not an
estimate.

## Continuation (same session, 2026-09-12): the palette WAS correct —
## the real bug was in `streamLit`; `test4b.cmp` now decodes
## pixel-exact end to end

The "palette mapping bug" of the previous section was a wrong diagnosis.
What is real:

1. **The palette (direct sequential reading, `palette[i]` = i-th entry
   read, no shift) was correct from the start.**
   Verified in two independent ways: manual bit-by-bit extraction
   against `test4b.cmp`, and index-by-index comparison against the
   `sball.palette.txt` already voted by hand (16/16 entries match
   exactly with simple identity indexing). An attempt at "+1"
   within this same session was a dead end — it narrowly matched the sparse
   evidence of test4b but not the dense evidence of sball.
2. **The real bug was in channel 4 (`streamLit`)**: complete disassembly
   of `FUN_0044df50` (the 32-byte "memcpy") and its deferred caller
   `FUN_00442bc0`/`FUN_00442bee` confirms that channel 4 MECHANICALLY uses
   the same path as channel 2 (`FUN_004269c0` with
   `permTablePtr=0`, `alphabetSize=0` → identity alphabet of 256), only
   that the table construction happens in a deferred way. With that
   established, a brute-force search (sliding the window of decoded
   symbols against the real pixel of `test4b.bmp`, also trying
   the 4 orientation combinations) found a single
   answer with 0 differences: **discard the first decoded symbol
   of the LIT channel** (decode `wanted[4]+1` symbols, keep the
   last `wanted[4]`). Confirmed as the ONLY combination with 0
   differences among all the shifts and orientations tried,
   not a coincidence.
3. **This fix does NOT generalize**: the same brute-force search
   against `sball.cmp` (a much richer LIT alphabet — `byteLen[4]=128`
   versus the 32 of test4b) never reaches 0 differences at any
   shift 0-6 nor orientation (best result: ~74% of pixels
   still incorrect). The real mechanism for rich alphabets remains
   unresolved — see the ongoing research below. It is possible that channel
   2 (`streamFillIdx`) has the same latent bug for rich alphabets
   (for `sball.cmp` it also has `byteLen[2]=128`), never before put to
   the test because in `test4b.cmp` that channel is degenerate.
4. **Orientation (`pass0Top`) was also wrongly derived**: the previous
   session tied it to bit 0 of `flags`, an adjustment made against the
   still broken LIT decode. With LIT fixed, `test4b.cmp` needs
   `pass0Top=false` (the opposite of what that bit would give) — just like
   `sball.cmp`. Neither of the 2 known cases correlates with that bit
   under the correct understanding, so `CmpTexture.loadRaw` sets it to
   `false` for now, pending more real examples.

**Verified result**: `test4b.cmp` decodes byte-exact (0/3072
bytes, 0/1024 pixels) end to end against the real render of
`cmpview.exe`, through the complete `loadRaw()` pipeline — with no
pre-captured streams, no hand-made `palette.txt`. `sball.cmp` and rich
LIT alphabets in general remain unresolved — no corpus closure is claimed
yet; active research via live tracing against `sball.cmp` was
ongoing at the time of writing this.

The coverage harness was also fixed: ImageMagick's `compare -metric AE`
gave impossible values in this environment (4.4e7 different "pixels"
for an image of 1024 pixels) — replaced by a direct byte
comparison in Python in `cmp_stage1_coverage.py`, which does give reliable
numbers (confirmed: `test4b.cmp` reports 0/1024 through the
harness, matching the independent verification).

## Continuation (same session): real corpus baseline (7/159) points to
## the root cause, live-tracing subagent finds it — 2 real bugs,
## `sball.cmp` also byte-exact

With `test4b.cmp` closed, the complete corpus of 159 real files of
`content.zip` was run as a real baseline (not estimated): **7/159 OK,
152 FAIL** (of which only 2 are exceptions/crashes —
`roofb.cmp` and `vendside2.cmp`, `ArrayIndexOutOfBoundsException`, not yet
investigated; the rest decode without failing but with
incorrect pixels). `groupCount` was 1 for all 159 files — the
`mode&0x80` path (multiple groups) remains unexercised by any known
real file.

Cross-checking the header fields of the 7 files that DID pass against
a sample of 8 that failed revealed the real pattern: the 7 that pass
have a degenerate `streamFillIdx` (channel 2) (`byteLen=1`, like
`test4b.cmp`); the 8 that fail have a RICH `streamFillIdx`
(`byteLen≈127-128`, like `sball.cmp`) — regardless of the
`byteLen` of `streamLit` (channel 4), which is 128 in both groups. This
pointed to a latent bug in channel 2 for rich alphabets, not
(only) in channel 4 as was thought.

A live-tracing subagent (gdb + wine, same method as
`cmp_capture_stage1.py`) confirmed and resolved this with real memory
captures of `gamma.dll` against `sball.cmp`, finding **2 real bugs**
(not the earlier "+1" patch, which was superseded):

1. **The length table must be indexed by SYMBOL VALUE, not by
   the slot of the lookup window.** A live capture of the real table
   of 512 bytes (`[obj+4]`, 256 symbol bytes + 256 length bytes) for
   the 5 channels of `sball.cmp` confirms that the length half only has
   non-zero values at the indices that are real SYMBOL VALUES
   (e.g. `table[256+0x55]=4` for the first real symbol of PERM0), never
   at the many slots that alias to that symbol. Real disassembly of
   `FUN_00426af0` (`0x426b74-0x426b7b`) explains why: `mov bl,[ebx]`
   loads the symbol into BL — the low byte of EBX, which is the
   256-byte-aligned table pointer OR'd with the lookup index — so that
   same instruction MUTATES the low byte of EBX to the symbol value, and the
   next instruction `mov cl,[ebx+0x100]` ends up reading
   `length[symbol]`, not `length[lookupIndex]`. Invisible against
   `test4b.cmp` (whose real alphabets are degenerate or small enough for
   slot==symbol in the codes actually used)
   but it broke any real file with a richer alphabet — exactly
   the correlation with `streamFillIdx` found in the baseline of the
   corpus.
2. **The bit transition between channels is conditioned by bit 0
   of `flags`, it is not always "continue in mid-byte":** with
   `flags&1==1` (`test4b.cmp`) each channel continues the window of the
   previous channel exactly (the original "primed" `BitCursor` model,
   unchanged). With `flags&1==0` (`sball.cmp`) the real caller in
   `gamma.dll` instead realigns to a full byte before each following
   channel (steps back 1 byte, fresh 16-bit reload). Confirmed in
   both directions against live capture: applying the realignment to
   `test4b.cmp` breaks `ctrl`/`lit`; not applying it to `sball.cmp` leaves
   `streamA`/`fillIdx`/`ctrl` 50-97% incorrect.

With both bugs fixed, the peculiarity of the "extra symbol at the
beginning" of the LIT channel (documented as an honest limitation before)
becomes a clean, verified constant: **1 extra symbol in
continuation mode, 2 in realigned mode** — found by brute-force
search against ground truth captured live for both files,
not yet explained mechanistically (the corresponding extra read
in the disassembly of `FUN_00442750` was not identified), but exact and
reproducible in both cases.

**Verified result**: `sball.cmp` now decodes byte-exact in
all 5 symbol streams (bits 0/512, streamA 0/1940, fillIdx 0/593,
ctrl 0/593, lit 0/997 discrepancies) against ground truth captured live,
and pixel-exact end to end against the real render of
`cmpview.exe` — just like `test4b.cmp`. Scope of the verification: 2
files (one for each value of `flags` bit 0), with high confidence because
it is based on disassembly and matches real memory dumps exactly, but
pending running against the complete corpus before
claiming closure — see `docs/cmp-stage1-coverage.md` for the real
updated number.

## Next session: LIT goes from a "constant fitted to 2 files" to a
## real byte-alignment rule, the capture harness had a wine process leak,
## the complete corpus reaches 159/159

The constant "1 extra symbol in continuation mode, 2 in realigned mode"
for the LIT channel (above) turned out to be fitted to only 2
data points and broke when verified against more real files:

- `avdoor.cmp` (realigned mode) only needed 1 extra symbol, not 2 —
  refuting the fixed constant. The real rule (first replacement):
  discard whole symbols, one at a time, decoding them through the real
  Huffman table, until the SUM of their real code lengths reaches
  `bc.bitsAvail`. Verified against 3 files.
- `rkgrnd.cmp` and `unexit.cmp` (found independently by two research
  subagents in parallel) broke THAT rule too:
  `rkgrnd.cmp` has LIT symbols with mixed lengths 7 and 8 — discarding
  by whole symbol can overshoot the byte boundary (a 7-bit symbol
  followed by an 8-bit one overshoots by 7 bits the target of 8), eating
  real data of `wanted[4]`. `unexit.cmp` uses exclusively
  5-bit codes, which never add up to exactly 8 with whole symbols. **Final
  fix**: `skipRawBits(bc, n)` — a raw bit discard that never goes
  through the Huffman table at all, without that edge case. Verified
  byte-exact against 5 independent real files that cover both modes of
  `flags` bit0 and uniform and mixed code-length distributions:
  `test4b.cmp`, `sball.cmp`, `avdoor.cmp`, `rkgrnd.cmp`, `unexit.cmp`.

With that committed, a real and serious bug was found and fixed in the
verification harness itself: `cmp_ground_truth.py` only reliably killed the
`wine` launcher process, never the `cmpview.exe` (nor the internal
`start.exe` that sometimes wraps it) that it actually spawns. Over
the course of a 159-file run these orphaned processes accumulate,
ending up leaving several overlapping windows in the X session —
which silently breaks the module's assumption of "a single window at the
origin" and corrupts the screen captures (confirmed
directly: a completely black capture, and `ps aux` showing processes from
HOURS earlier still alive). Fix: `pkill -9 -f cmpview.exe` /
`pkill -9 -f "start.exe /exec"` both before and after each
capture, not just at the end. **Every corpus coverage figure measured
before this fix in the same session is suspect and must not be
trusted** — it was honestly re-measured afterwards.

With the harness fixed, the complete corpus rose to 156/159, and after
discarding 2 transient failures due to contention among concurrent wine
processes (`avdrrl.cmp`, `avflr1.cmp` — both OK when re-tested in
isolation) it stood at **158/159**, with `vendside2.cmp` as the only
remaining real failure.

### `vendside2.cmp`: the single-symbol alphabet bug

Direct investigation (streams `bits`/`streamA`/`streamFillIdx`/
`streamCtrl` byte-exact, only `streamLit` diverged from byte 0) and
brute force over the LIT entry point (byte shift
×  discarded bits, 81 combinations) found no simple alignment that
worked — a sign that the bug was not one of the LIT alignment itself, but
something structural upstream.

Real cause: the `streamCtrl` channel (channel 3) of this file falls into the
degenerate single-symbol case of `buildFromLengths` (`sum<=1`) —
a Huffman alphabet of a single real symbol. The code emitted the code
length EXACTLY as it was read from the header nibble (always 1 in every real
occurrence in the corpus), when a single-symbol alphabet needs
**0 bits** per code — there is nothing to disambiguate. A scan of the
complete corpus showed that 9/159 files fall into this exact case
(`byteLen=1`, `onlyLen=1`, `flags=0x80`), but in 8 of them the channel
only asks for 1 symbol (`wanted[3]=1`) — neither 0 nor 1 bit of cost ever
manages to trigger a byte reload, so the bug is mathematically invisible
there. `vendside2.cmp` asks for 63 symbols (`wanted[3]=63`) — with length
1 (bug), decoding them advances the shared bit cursor ~7 bytes that
should never have been consumed, corrupting every following LIT symbol.

Two-part fix: (1) the degenerate single-symbol case emits length
0, not `lengths[only]`. (2) a new field
`reloadedDuringChannel` in `BitCursor`, set when the inner loop of
`decodeChannel` actually reloads a byte — a channel that truly consumes
0 bits never touches its own 2-byte prefetch, so the standard "1 byte"
step back before the next channel overshoots by 1 byte in that case; it
needs to step back 2. The specific LIT-after-ctrl transition already had a
pre-existing, verified double step back ("LIT needs 1 extra byte beyond
the normal") — that one was left untouched (it is still an unconditional
`-1`) and the conditional adjustment was applied only to the normal
transition right before it, so as not to duplicate the correction.

**Verified**: `vendside2.cmp` byte-exact in `streamLit` (0/126) and in
the final 16384 pixels against the real render of `cmpview.exe`. Complete
corpus re-confirmed in 4 batches of ~40 files (running all 159 at
once turned out to be intermittently unstable this session —
probably Wine/X resource contention under long runs,
unrelated to the decoder — batches of ~40 files proved
reliable): **159/159 OK, byte-exact, 0 regressions.**

## Final state: complete coverage of the real corpus (159/159)

The `.cmp` Stage 1 decoder (`CmpStage1.java` +
`CmpStage2.java`) decodes byte-exact, pixel by pixel, against the
real render of `cmpview.exe` for the 159 real `.cmp` files of
`GroundZero/content.zip` — not a sample, not an estimate, the complete
corpus. The `mode&0x80` path (multiple groups, `groupCount>1`)
IS now exercised and verified — by the `.mov` files (see next
section); in `.cmp` no known real file triggers it and the
explicit `IOException` is kept for that case.

## `.mov`: same codec, multi-frame container (2026-09-13)

The 13 real `.mov` files of `content.zip` (`tex/*.mov`, referenced
from Rects with animation suffixes `2h*2v*`) are LzH2 with the
same header offsets as `.cmp`, modes `0x82`/`0x86`, palette
`byte12=0xFF` (=255 genuine, proven: forcing 256 desynchronizes).
Differences: a much larger table region (multi-frame tables; the
u16 at 28 is NOT their size) — it is located by group header signature
(`field0==64`, unique per file, incl. `windr3` with
`wanted[0]=624`, `h=154`) — and `groupCount>1` (frames): only
group 0 is decoded (static frame for the viewer; the tiling
`2h*2v*`/multi-file f1-f8 is animation by UV/time, out of
scope). Index 255 = transparent background → white (canvas of
cmpview; `.mov` only, the `.cmp` keep their real entry).
Verification against `cmpview.exe`: `windr1` and `cbirda4`
16384/16384 byte-exact; the rest with correct real artwork (flags
f1-f8 in successive wave phases, bird, logos, interiors).
Implementation: `CmpStage1.decodeMovFrame0` + `CmpTexture.loadMov`.
Honest limits: static frame 0 (no temporal animation);
cmpview's movie window includes its own UI (post/seek) that is not
content — do not confuse it when verifying.

### Correction (2026-09-22): the "frame 0" above was the LAST frame

The previous section is superseded on two points, measured on the 52
`.mov` and the 159 `.cmp` of `content.zip`:
1. **The group signature was finding the last frame, not the first.** The
   frames go in the file in the order of the frame table that
   `gamma.dll` reads (`FUN_00442750` header, `FUN_00442bc0` per frame): after
   the table region (`u16@28` bytes from 34) and the palette cursor,
   entries of 20 bytes (absolute offset u32, size u16, next u16,
   reference u16 or `0xFFFF`). The groups are contiguous and the last one ends
   at the end of the file (e.g. `windr3`: 1037+2012 = 3049, …,
   8555+3074 = 11629 bytes). The signature scan (`field0==64` and zeros at
   +12/+14) does not match the group header of frame 0 and stopped at the
   last group in the 52 files. Result of the old path: 49 `.mov` showed
   exactly the last frame (34 of 4 frames, 15 of 2); 2
   (`logo256`, `splashscreen`) decoded the last group without its reference
   frame (it matches no frame); `windr3` also came out transposed.
2. **Width = `u16@8`, height = `u16@6`.** `windr3.mov` is 154 wide by
   128 high (64 row pairs, 39 nibble columns); the old path
   gave it as 128×154. In the `.cmp` files it is not noticeable because
   all 159 are square.

`CmpTexture.loadRaw`/`loadMov`/`loadMovFrames` now use `CmpFrames` (the
same decoding that the bridge uses); `CmpStage1.decodeMovFrame0` and
`CmpStage1.decode` have been retired. Measured: **159/159 `.cmp` with the
same RGB as before, 52/52 `.mov` change from frame 0** (and all 52 decode
all their frames). Outside `content.zip`, the avatar `.mov` files
(21 in `base-avatars/`, 31 in `cachedir/`) go from 37/52 decodable files
to 52/52: the 15 that failed have sizes other than 128 (104×135,
118×100, 150×150, 160×150…) or up to 16 frames. Check:
`formats/test/net/openworlds/cmp/CmpTextureCheck.java`.

The "byte-exact against `cmpview.exe`" verification of `windr1` and
`cbirda4` of 2026-09-13 was comparing, therefore, the **last** frame (if
that comparison was correct, `cmpview` shows the end of the movie). It is not
a reference for frame 0, and it is not reproducible on this Mac (no Wine).

### What the client uses the frames of a `.mov` for (2026-09-22)

A `.mov` is **not played back over time** by itself. In the original Java
(`NET/worlds/scape`) its frames are:

- **Cells of a Material** (`Material.calcRes`/`loadTextures`/
  `syncBackgroundLoad`): the name `x2h*2v*.mov` asks for 2×2 textures from
  the file `x.mov`; texture `k*hRes + c` is frame
  `hRes*vRes*sPos + (vRes-1-k)*hRes + c`, and the Rect is split into those
  cells (`Surface.addSubPolys`, gamma.dll `0x004206d0`; polygon *i* ←
  material *i* mod *hRes·vRes*, `Surface.nativeSetMaterial` `0x00420500`).
  With a Rect of u = v = 1, frame 0 ends up at the top left and the
  others in reading order. `Ns*` chooses the N-th group of
  *hRes·vRes* frames. In GroundZero **all** the `.mov` files are used this way, and
  their number of frames is exactly *hRes·vRes*: 34 of 4 frames with `2h*2v*`,
  and those of 2 frames with `2h*` (flags `f1`–`f8`, `signa&a`, `signtel`,
  `time`) or `2v*` (`drs1`, `drs5`). Thus, for example, the 14 `sky*.mov`
  of the background of `ReceptionView1` form a single continuous panorama of
  mountains: before, the new engine's viewer stretched a
  single cell over each panel.
- **Faces of a Hologram** depending on the viewing angle
  (`Hologram.setActiveSide`, native).
- **Avatar sub-images** (`PosableShape`, outside this document).

What does change over time is the **entire Material**, with an
`AnimateAction` fired by a sensor (see
`docs/world-format-reference.md`, "Actions that change textures"): the
flag of `ReceptionView1` alternates `f12h*.mov` … `f82h*.mov` (8 phases
in 1000 ms) and the dressing-room sign `drs12v*.mov`/`drs52v*.mov` every
3 s.

In the bridge the cells are done by `NativeScene.addSubPolys` (hand-computed
cases in `bridge/test/SubPolysCheck.java`).

### Several groups per frame, byte 13 and the skip of `idx == 0` (2026-09-26)

Three things that did not show up in the GroundZero corpus and did in worlds
downloaded from the mirror (samples and provenance in `assets/cmp-verified/`,
test in `formats/test/net/openworlds/cmp/CmpGroupsCheck.java`):

- **A frame can be several groups of rows.** `FUN_00442bc0` is a
  `while (rows < height)` loop: each group brings its 16-byte header
  (`u16` row pairs, 5 stream lengths, `u16` size of the
  **next** group and a `u16` that must be 0), its five streams
  decoded with the same Huffman tables and its call to
  `FUN_00457d88` with `edi = ((even height − 1) − rows done) · pitch + base`,
  that is, right where the previous group ended. The size of the first group
  comes from the frame table and that of the following ones from the header
  of the previous one. `tex/mug.cmp` of The Blair Witch World (213×233) is in
  two groups of 76 and 41 pairs; 943 + 2,071 + 1,674 = 4,688, the exact end of
  the file, and each group spends its streams exactly. In the `.mov` files
  the "next" field gives the size of the frame that follows (its first group).
- **The `esi` row is a single one per file.** `FUN_00442750` allocates it
  once (`this+0x3c`, `(width+3>>2)·2` bytes, not cleared) and `FUN_00442bc0`
  passes it to all the groups and frames. A look-back when starting a
  frame reads what the last pass of the previous one left. Preserving it
  changed frame 3 of `logo256.mov` and frame 1 of `splashscreen.mov` of
  GroundZero, and no frame 0.
- **Header byte 13 different from 0**: in the table region,
  gamma.dll skips `(byte13·18+7)>>3` bytes **and also** the number of
  colors (0x442963..0x442983). Only `kcl.mov` (avatar dressing room:
  kaleidoscope of 8 frames, mode `0xc2`) uses it; before, it was
  256 bytes off and crashed while building the tables.
- **`idx == 0` in the simple copy path of `FUN_00457d88`**
  (0x457e22 `and ebx,0xff` / `je 0x457e0c`) writes nothing. It consumes the
  fill bit (0x457e0c `add edx,edx` / `je` reload) and advances `edi += 4` and
  `esi += 2`, so that the 2×4 block keeps what it had. ⚠️ VERIFY:
  translated from assembly, with no known file that uses it.
  `mug.cmp` only got there because the old reader read the zero padding
  after the first group.
