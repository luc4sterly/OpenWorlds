# `.cmp` Stage 2 decoder (scanline pixel reconstruction) — real evidence, partially verified

`CmpStage2.java` is a from-scratch Java re-implementation of `gamma.dll`'s
`FUN_00457d88` (the function that turns already-Huffman-decoded symbol
streams into real pixel bytes), built entirely from live dynamic-debugging
evidence gathered in the 2026-09-10 continuation session — see
`docs/cmp-texture-format-reference.md`, section "Cerrando el descompresor
`.cmp`", for the full narrative and derivation of every branch below.

**What this does NOT do**: implement the Huffman bit-decoder
(`FUN_00426af0`) that turns a raw compressed `.cmp` file into the 5 input
streams this code consumes. This is Stage 2 only (symbol streams → pixels),
verified against the *real* streams extracted live from a running
`gamma.dll` process, not from a hand-written Stage 1.

## The algorithm, as understood and largely verified

Each call decodes `ch` iterations (`ch` = width/4 for the files tested,
32 for a 128px-wide row), each producing exactly 2 output bytes, driven by
5 independent streams (bit-shift register, predictor-index bytes,
fill-handler-index bytes, control bytes, literal-data bytes) — matching the
"5 tables, 4 Huffman + 1 raw" structure found by static analysis in an
earlier session. Per iteration, up to 2 bits are read MSB-first from a
32-bit shift register (refilled from the `bits` stream, byte-swapped via a
16-bit rotate) to pick one of three symbol shapes:

- **bit1=0 — single 4-byte predictor copy**: one index byte selects an
  entry in the 50-entry predictor-offset table (verified live to be
  exactly the static table found in an earlier session, at
  `0x00478e98`, via `offset = colDelta + stride·rowDelta` — the earlier
  session's tentative formula had the sign backwards, corrected here with
  live evidence); reads 4 bytes from that neighbor, writes them to both
  the current row and current-row-plus-stride ("double-row write"),
  emits `byte[1]` of each of the two reads.
- **bit1=1, bit2=0 — dual 2-byte predictor copy**: two index bytes, one
  per 2-pixel half of the 4-pixel group, each doing the same double-row
  write at half width.
- **bit1=1, bit2=1 — control-byte branch**: reads one control byte.
  `0x24` is a raw 8-byte literal escape (writes 2×4 real bytes straight
  from the literal stream to both rows). Any other value selects among
  literal-pair / lookback-into-already-output-row / lookback+literal
  sub-cases based on its low 3 bits and bits 3+ — **and, newly found this
  session, every non-`0x24` control-byte iteration ALSO unconditionally
  consumes one byte from the fill-handler-index stream and does an
  additional run-fill-style broadcast of its own output byte into the
  history buffer** (missing this was the single biggest source of
  verification failures before it was found via a live trace).

The 256-entry "fill handler" jump table (used by both the control-byte
broadcast above and needed for a full trace) was confirmed in an earlier
session to be a trivial byte-replication trick with no real complexity —
not reimplemented here as a lookup table, just inlined as
`al * 0x01010101`.

## Verification status: real, but NOT 100% byte-exact yet

Tested against 2 real `.cmp` files' first-64-output-bytes (`ch=32`, one
call = the leftmost 64 pixels of row 0 for a 128px-wide image — see the
"call granularity" note in `docs/cmp-texture-format-reference.md`):

- **`adworlds.cmp`** (flat, mode 0x02): 34/64 bytes match exactly. All 30
  mismatches are a single contiguous block (positions 34-63), and every
  one of them is the decoder correctly computing "read from a predictor
  offset 256+ bytes past the starting position" — which the real process
  can genuinely do, but which fell outside what a *single, one-time*
  `read_memory()` snapshot could capture (confirmed: the real process's
  forward-readable region from a static snapshot ends ~124 bytes past the
  start position, yet the real code doesn't crash reading further,
  implying the OS commits more pages as execution writes nearby ones —
  something a static Python-side memory dump cannot replicate). This is a
  **data-capture limitation, not a demonstrated algorithm error** — every
  one of these missing bytes should legitimately be `0xAD` for this flat
  file, exactly matching what the (zero-padded, hence wrong) decoder
  fails to produce there.
- **`4i.cmp`** (real varied content, mode 0x02): 55/64 bytes match
  exactly. The remaining 9 (positions 41-49) were investigated in depth —
  the exact same control/predictor-index stream sequence and consumption
  count was cross-verified byte-for-byte against a live register trace
  (26 control-byte iterations, all matching), and the specific literal
  byte my code reads was independently confirmed live at the correct
  stream position too — yet the "expected" value captured for a few
  output positions there doesn't match. Not resolved before this
  session's time ran out; most likely a subtlety in the *ground-truth
  capture* method (see below) rather than the decode logic itself, given
  how much of the surrounding evidence cross-validates independently, but
  this is **not proven** — flagged honestly rather than dismissed.

### How the "real" ground truth was captured

Two approaches were tried:

1. Run to completion (`finish`/return-address breakpoint) then dump
   memory - **unreliable**, produces stale/wrong bytes past a point (the
   buffer appears to get reused/corrupted between decode finishing and
   the read happening - even a single command right after return showed
   this).
2. **Register-level tracing** (used for the files here): single-step
   through the whole decode, and record the exact byte(s) at the moment
   each of the 6 known real esi-write instruction addresses fires,
   indexed by the live `esi` register's actual position. This proved far
   more trustworthy (cross-verified byte-for-byte against a fully manual
   instruction-by-instruction trace for the first several iterations) and
   is almost certainly right for the bulk of both files - but the
   unresolved 9-byte gap above means it isn't unconditionally trusted.

## Running it

```
javac CmpStage2.java
java CmpStage2 . adworlds_   # or: java CmpStage2 . 4i_
```

The checked-in `<prefix>*.bin` files are the exact real data (streams,
history window, bit source, and captured real output) extracted live from
`gamma.dll` for each file - see `<prefix>extract_log.txt` for the raw
addresses/offsets involved.

## 2026-09-10 continuation: real official-tool ground truth, data-capture
## gap ruled out, bug narrowed to one predictor-table branch

A later session found the official `compimg.exe`/`cmpview.exe` tools
(Knowledge Adventure, 1993-95) and confirmed they run natively under
Wine with no 16-bit-Windows workaround. Built `test4b.bmp`/`.cmp`
(`assets/gammatutorial-samples/`) — a **self-designed, fully-known**
32×32 test image (4 solid quadrants: red/green/blue/yellow) compressed
by the real `compimg.exe`.

**New, strictly stronger ground truth**: attached to the live
`cmpview.exe` process via `/proc/<pid>/mem`, located its real GDI pixel
buffer (a Wine SYSV shared-memory segment, genuine 32bpp BGRA), and read
out the decoded pixels directly — **exactly 256 pixels of each expected
color, zero noise**. This replaces the previous screenshot/RMSE-based
check with byte-exact ground truth.

**The old "data-capture gap" hypothesis (see "Verification status"
above) is ruled out, with real evidence, not just re-asserted:**
- Rewrote `cmp_capture.py`'s capture loop to stop gating on a single
  call and capture every real call to `FUN_00457d88` with a genuine
  memory snapshot each time. Result: `test4b.cmp` only makes **one** real
  call — the earlier "needs ~4 calls, we only captured 1" theory (from
  the `outerCount·2·stride` arithmetic) was wrong.
  (`test4b_call0/`: real history + per-pass output for that one call.)
- Fed the decoder the **actual captured real memory** (not a zero-seed)
  for up to 2048 bytes around the read window. Result: byte-identical
  to the zero-seed run (still 23/141 matches, same mismatch pattern) —
  because the real process's own memory at the failing read address
  genuinely **is** `0x00` there too. The capture was never the problem.

**Bug precisely isolated** (branch tracing against real captured
per-iteration output, `test4b_esi_all_passes.csv`): pass 0 decodes
correctly through iteration 4 (`CTRL`, `SINGLE`, `DUAL`, `DUAL`, `CTRL`).
It breaks specifically at **iteration 5's `DUAL` branch, second
predictor pair, `idx2=32` → `PRED_TABLE[32]=256`** (a *large* offset):
real output is `62`, the decoder produces `0`. Small/nearby offsets
(e.g. `idx=3`, offset `-4`) decode correctly every time they're used,
including earlier in this same iteration — only the large-offset table
entries go wrong, then cascade into a full bitstream desync (crash at
pass 8, `PRED_TABLE` index 63, table only has 50 entries).

**Bottom line, updated**: this is now a genuine, narrow decode-logic bug
— most likely in how large `PRED_TABLE` offsets combine with `idx2`/the
row stride in the `DUAL` branch (overflow, sign-extension, or a
stride-scaling mistake that only bites at larger magnitudes), or a
subtle bit-consumption miscount earlier that only shows up once a
large-offset read exposes it. **Not closed** — the next session should
directly compare `PRED_TABLE[32]`'s real value/stride math (live,
single-stepped through this exact iteration in `gamma.dll`) against what
`CmpStage2.java` computes for `idx2=32`, rather than re-deriving the
whole algorithm from scratch. This is a much smaller, well-evidenced
target than "something's wrong somewhere in 64 bytes."

## 2026-09-10, round 3: `PRED_TABLE` bug found and fixed (real fix,
## 23/141 → 86/141), second deeper bug found underneath (still not closed)

Disassembling `FUN_00457d88` directly (rather than trusting an earlier
session's comment) showed the predictor-offset lookup is
`mov ebx, DWORD PTR [ebx*4+0x482d0d]` — **not** `0x00478e98` as an
earlier session's code comment claimed (that address holds unrelated
data; reading it statically from the file returns garbage). `0x482d0d`
is in `.data` and is all-zero in the static file: **the table is built
by `gamma.dll` at runtime from the current `stride`**, not a fixed
constant. The old `PRED_TABLE` array (this file's original version) had
been captured live, but only ever for 128-wide files (`stride=-128`),
then baked in as fixed combined offsets — correct only for that one
stride.

**Real proof of the model**: live-read the runtime table for two
different real strides (`-128` and `-32`, via winedbg/gdb) and solved
`off = colDelta + stride·rowDelta` as two linear equations per entry.
**Every one of the 50 entries produced a clean integer solution, no
residual** — strong confirmation this is the actual recipe, not a
coincidence. Entries with `rowDelta=0` (the small/nearby offsets, idx
0-5) are stride-independent, which is exactly why `idx=3` always
decoded correctly even with the old bug — it's why the round-2 bug
report ("idx=32 gives 256 instead of 62") looked like an isolated
oddity rather than a systemic stride bug. Fixed: `PRED_COL`/`PRED_ROW`
arrays plus `predOffset(idx) = PRED_COL[idx] + stride*PRED_ROW[idx]`,
replacing the flat `PRED_TABLE`.

**Result**: 23/141 → **86/141** matches against real captured per-pass
output — reproduced cleanly, a real ~3.7x improvement, not noise.

**A second, deeper bug remains** (the reason `test4b.cmp` still isn't
byte-exact): a live branch-dispatch census across the *entire* real
decode (`evidence_2nd_session/branch_census.log`, address-tagged
breakpoint hit counts) shows the real execution takes **`SINGLE` 124
times and `CTRL` 4 times — `DUAL` zero times**, for the whole file.
`CmpStage2.java`'s own trace (`TRACE` flag, left in the code) shows it
taking `DUAL` five times in pass 0 alone. **The real code never takes
the branch this decoder thinks it's taking at this point** — meaning
the residual gap isn't in the predictor table at all; it's upstream, in
`shiftBit()`/`refillWord()` or the `bit1`/`bit2` dispatch logic itself,
misreading the bitstream into a branch decision the real code never
makes.

**Not closed.** `rustwood.cmp` wasn't checked since `test4b.cmp` itself
still isn't byte-exact. Next concrete step for a future session: use
the `TRACE` flag plus the same live-branch-census technique to find
where the decoder's bit reader first disagrees with the real one about
which branch to take (not which offset to use — that part is now
right).

## 2026-09-10, round 4 (LÍNEA A): `test4b.cmp` byte-exact, real texture
## `rustwood.cmp` at 99.37%, THREE more real bugs found and fixed

**Bug found in the capture tool itself, not the decoder**: `cmp_capture.py`'s
`Write1Bp` breakpoint class always read the `AL` byte of `eax` for every
tracked write site. Real disassembly shows `SINGLE`'s writes really do
use `rol eax,8; mov [esi(+1)],al` (AL is correct there), but `DUAL`'s
writes are plain `mov [esi],ah` / `mov [esi+1],ah` — **no rotation, and
the wrong register**. Every DUAL-covered "ground truth" byte captured by
every prior round was silently wrong. Invisible until now purely by
luck: no file tested in rounds 1-3 ever took a real `DUAL` branch
(confirmed separately via the branch census). Fixed: `WRITE1` entries now
carry `(byteslot, register)` pairs.

**The real second bug, found and fixed**: disassembly shows every
"consume a bit" call site in `FUN_00457d88` has a guarding `je [refill]`
check **except bit1's own test** (`0x457e1a`: `add edx,edx; jb 0x457e80`
— no `je` at all). When the shift register's last surviving bit is
consumed exactly at that unguarded site, real hardware does **not**
refill immediately — it leaves the register at literal `0` and defers
the refill to whichever guarded site runs next, which (shifting an
already-zero register) produces one genuine "fake" 0 bit before its own
refill finally fires. The old `shiftBit()` refilled eagerly regardless
of call site, silently dropping that fake bit and desyncing every later
bit read by exactly one position whenever this edge case hit — which is
exactly why the decoder spuriously took `DUAL` branches the real process
never took. Fixed: a new `shiftBit1NoRefill()` used only at the bit1
site; every other site keeps the original guarded `shiftBit()`. Found
via a live branch-dispatch trace against `rustwood.cmp` (real varied
content — `test4b.cmp`'s flat quadrants never happened to exercise this
edge case at all, which is also why round 3 didn't find it).

**A third bug, uncovered once real varied content could be tested**: the
"fill broadcast" on the control-byte path (`ctrl != 0x24`) was NOT a
uniform "replicate `al` four times into both rows," as a much earlier
session's static read of a couple of handler bodies had concluded — that
conclusion happened to be unfalsifiable against every file tested so far
because those files' literal byte pairs always had `al == ah`. Live
register tracing against `rustwood.cmp` (`al != ah` there) around the
`call [edx*4+0x483844]` dispatch showed the `fillIdx` stream byte is
actually an **8-bit shuffle mask** — each bit independently selects `ah`
(1) or `al` (0) for one of 8 output byte lanes (`dl,dh,cl,ch,bl,bh,
axLo,axHi`, bit 0..7 in that order). Confirmed exactly, all 8 bits, on 3
independent live samples. Fixed accordingly.

**Also fixed**: `lookback()` was refusing any `idx >= outPos` for the
*current* pass, on the theory that later positions were "not yet
written." Real evidence (`test4b.cmp` pass 8, iteration 0) shows a
lookback can legitimately read a **previous pass's** leftover value at
the same output-array slot — the `out` buffer, like the history buffer,
is never cleared between passes. Fixed to only reject indices outside
the buffer entirely.

**Match results** (against real per-pass captured output, with the
capture tool's own AL/AH bug fixed first):
- **`test4b.cmp`: 256/256 — 100%, byte-exact.**
- **`rustwood.cmp`** (real 128×128 texture, not synthetic): **4070/4096
  — 99.37%**, up from 403/4096 at the start of this round. The one
  remaining mismatch spot-checked was resolved in the decoder's favor:
  a **fresh, independent live memory read** (bypassing both the decoder
  and the capture tool's stored CSV entirely) matched the decoder's
  output, not the CSV — evidence the residual ~26 bytes are further
  undiagnosed capture-tool artifacts, not decoder bugs, though this
  isn't proven for every remaining byte.
- **`sball.cmp`** (third real file): **2709/4096 — 66%**, captured
  fresh with the corrected tool. The same live-read-vs-CSV spot-check
  pattern repeated once (a `fillIdx=24` case) and again sided with the
  decoder over the stored capture — but this file diverges earlier and
  more often than `rustwood.cmp`, so there may be a real, additional,
  undiagnosed issue specific to it (or simply more capture noise this
  round didn't have time to track down). **Not resolved with
  certainty.**

**Did not connect to the render pipeline this round** — `sball.cmp`'s
gap isn't resolved with the same confidence as `rustwood.cmp`'s, and the
project rule against shipping plausible-but-unverified pixels applies
here. `test4b.cmp` alone being byte-exact isn't enough: it's a synthetic
flat-color image that (as this very round demonstrated) can hide real
bugs a varied texture exposes.

**Next step for a future session**: chase the `sball.cmp` residual with
the same live-read-vs-CSV spot-check method, on the working hypothesis
that most or all of it is further capture-tool artifacts rather than
decoder bugs (per the pattern in both `rustwood.cmp` and `sball.cmp` so
far) — but that is not yet proven, only suggestive.

## 2026-09-10, round 5 (LÍNEA A): `sball.cmp` CLOSED — fourth real bug
## (`ROL` emits byte3, not byte1); all 3 files byte-exact; pipeline connected

Starting point: `test4b.cmp` 256/256, `rustwood.cmp` 4070/4096,
`sball.cmp` 2709/4096.

**First divergence, precisely located** (same per-pass comparison as
round 4): `sball.cmp` pass 0, offset 16 = iteration 8, first byte —
a `SINGLE` with `idx=3` (offset −4). Decoder emits 7, capture says 31.
`sball.cmp` uses all three branches from pass 0 on
(`CTRL,CTRL,DUAL,CTRL,CTRL,DUAL,CTRL,CTRL,SINGLE,...`), unlike
`test4b.cmp` (whose real execution never takes `DUAL` at all). Both
files are 128×128 (`ch0=32, outer=64, stride=-128`); their `.cmp`
headers differ at bytes 8-15 (`sball` `0204 ff00…`, `rustwood`
`ffff 0000…`, `test4b` `0507 4000…`) — possibly a flags field, still
open (see orientation note below).

**Live evidence first, as required** — two tooling facts learned the
hard way this round:
- `gamma.dll`'s load base is NOT fixed at `0x03A40000` (the previous
  session's comment): observed `0x03840000`/`0x03841000` across runs
  (fresh `wineserver` vs reused one changes the layout). Worse,
  `info sharedlibrary`'s `From` address is base+`0x1000` (first section,
  headers skipped) — arming breakpoints off it silently lands `0x1000`
  high and the process runs to exit untouched. Fix used for every trace
  this round: self-validate the candidate ENTRY against the real first
  16 bytes from the PE file (`c8000000565753558b4510a3002d4800`,
  RVA `0x57d88`), trying `delta` and `delta-0x1000`.
- A full static disassembly of `FUN_00457d88` was obtained
  (`llvm-objdump -d --adjust-vma=0x400000`, `0x457d88-0x458000`) and
  used to reinterpret every breakpoint. Correction to round 3's census
  method: `0x457eed` is NOT "the CTRL dispatch" — it is the
  `low3==0` re-entry (`je` from `0x457f56`), so it fires only for
  `low3==0` non-`0x24` CTRLs. `low3!=0`/`0x24` CTRLs are invisible to
  it (decoder iter 7, `ctrl=1`, correctly produces no hit there).

**Branch sync confirmed live** (breakpoint-hit order, unbuffered
winedbg notices): pass 0 starts `CTRL,CTRL,DUAL,CTRL,CTRL,DUAL,CTRL,`
then the first `SINGLE` — exactly the decoder's sequence, with matching
`SINGLE` indices (3, 1, 2). A register dump at that first `SINGLE`
showed history bytes `07 07 07 1f 07 07 07 1f` — exactly the decoder's
own iter-7 fill output. So the decoder's bit reader, branch dispatch,
stream positions, and history state are all correct at the divergence
point — yet the emitted byte disagrees.

**Decisive experiment**: a fresh mem-after-store capture (break at each
of the 7 esi-write sites, single-step OVER the store, read the target
`[esi]` byte — no register interpretation involved), pass 0 of
`sball.cmp`, 64/64 bytes (`PARAMS edi0=04ae3f80 esi0=03149b58 outer0=64
ch0=32 stride0=-128`, same shape as the checked-in capture, different
heap base). Result: the new capture matches the OLD csv **64/64
(0 diffs)** — the capture tool is vindicated, deterministic and
correct — while the decoder matches it only **58/64**, with all 6
diffs at `SINGLE`-produced positions (offs 16, 26, 27, 29, 30, 31;
off 29 is a lookback cascade of the earlier ones, not a new bug).

**Root cause — the fourth real bug, same style as the previous three
(a real case prior files never exercised)**: `SINGLE` does
`rol eax,8; mov [esi(+1)],al` (`0x457e36/0x457e39`,
`0x457e4c/0x457e4f`). x86 `ROL r32,8` rotates toward the MSB, so the
new `AL` is the OLD HIGH byte — **byte3 (bits 24-31), not byte1**.
The decoder emitted byte1 (as if the rotation were `ROR`). At the
divergence point `v1=[07,07,07,1f]`: real `AL` after `ROL` is `0x1f`
(31, confirmed live as `regal=31 mem=31`), byte1 is `0x07` (the
decoder's wrong 7). The `0x24` literal escape uses the same
`rol; mov al` pair (`0x457fba/0x457fbd`, `0x457fd0/0x457fd3`) and had
the same bug — fixed too. `DUAL` is genuinely byte1: it stores `ah`
with NO rotation (`0x457ebb/0x457ee5`) — left untouched (and every
live `DUAL` byte already matched before this fix). Why it hid:
`test4b.cmp`'s flat quadrants have all four history-word bytes equal
(byte1==byte3 everywhere — a synthetic image hiding a real bug, exactly
the failure mode round 4 warned about); `rustwood.cmp` happened to
have byte1==byte3 at all but 26 positions.

**Statically verified on the side**: all 256 fill-handler bodies
(symbolic simulation of their `mov`/`xchg`/`ret` instruction streams
against the file's pointer table at `0x483844`) implement EXACTLY the
round-4 shuffle model (each output lane = `al`/`ah` per `fillIdx` bit)
— 0/256 mismatches. The shuffle model is now proven for every index,
not just 3 live samples. Also confirmed in disassembly: the refill
`je 0x457e8e` re-tests bit2 via a carry→`sbb`→ZF chain (equivalent to
the decoder's carry-preserving `shiftBit()`), and `idx==0` consumes a
stream byte plus a guarded bit with no output (never fires for these
files — the decoder's throw there never triggered).

**Final scores, full re-run over all 3 files (fix breaks nothing)**:
- `test4b.cmp`: **256/256 — still byte-exact.**
- `rustwood.cmp`: **4096/4096 — byte-exact** (was 4070/4096: the 26
  "capture artifacts" round 4 couldn't prove were, in fact, this bug —
  corrected here with the evidence above).
- `sball.cmp`: **4096/4096 — byte-exact** (was 2709/4096).

**Independent end-to-end ground truth** (the `/proc`-vs-`cmpview` pixel
check this round's tasking demanded): `cmpview.exe` screenshots under
Xvfb/`import` (window at fixed coords, 1:1 pixels).
- `test4b.cmp` renders 32×32 with exactly 256 px each of
  `(252,0,0)/(0,252,0)/(0,0,252)/(252,252,0)` (252 = Wine's 6-bit visual
  quantization of 255): TL=red TR=green BL=blue BR=yellow, giving the
  palette `{63:red, 62:green, 60:blue, 58:yellow}` and proving pass 0 =
  TOP row pair for this file.
- `sball.cmp` renders a 128×128 tile/ornament pattern (134 distinct
  colors). The decoder's full-history image (all 16384 index bytes, not
  the branch-mixed esi subsample) maps onto these pixels under ONE
  orientation (`pass0=BOTTOM + within-pair swap`, vs `pass0=TOP` for
  `test4b` — orientation evidently varies per file, presumably the
  header-bytes flag above; never guessed, stored per-file as
  `orient 0 0`): with the voted mode-color palette, the render differs
  from cmpview's screenshot in **0/16384 pixels**. Indices and colors
  are each independently grounded (live process memory / official tool
  display) — the vote only aligns them.
- Negative result, documented honestly: `rustwood.bmp` is NOT the
  source of `rustwood.cmp` — no orientation scores above 0.06
  (vs 1.00 for sball), so the earlier grayscale/palette-correlation
  failures were a false pairing by filename, not a decoder problem.
  (`test4b.bmp`↔`test4b.cmp` is genuine self-made ground truth.)

**Pipeline connection (this round's close-out criterion)** (the Java
package now lives in `formats/src/net/freeworlds/cmp/`; `RwxParser`,
`RwxModel` and `RwxViewer` were removed with the new engine on 2026-09-26
and remain in git history):
`client/src/net/freeworlds/cmp/` (`CmpStage2` port of this directory's
verified decoder + `CmpTexture` loader), `assets/cmp-verified/sball/`
(`.cmp` + 5 Stage-2 streams trimmed to exact verified consumption —
sball A 1940/2048, ctrl/fill 593/640, lit 997/1024, bits 516/576 —
plus the voted palette; zero history seed, proven live to be all
zeros at call entry), UV parsing in `RwxParser`/`RwxModel`, and
`RwxViewer --texture <dir>/<base> --camera top|front [--doubleside]`.
Rendered `sball.rwx` (768 verts, 256 tris, real per-vertex UVs
spanning u 0-1, v 0.62-1.0) with its verified texture —
`docs/renders/sball_ring_{flat_top,textured_unlit_top,textured_lit_top}.png`.
Pixel proof on identical geometry (13548 non-bg px): flat = 10
saturated material colors; unlit-textured = **1195/1195 colors within
6.6 (mean 2.5, GL_LINEAR blend noise) of the verified texture
palette**; lit-textured = 1274/1452 within 12 (shading darkens the
rest, still texture-family); flat control = 0/10 near palette (mean
distance 155). Zero magenta pixels (no unmapped palette index ever
sampled). Real verified `.cmp` pixels are on the geometry — not flat
color. Demo scope, stated in the code: single-texture `--texture`
override (sball.rwx itself says `Texture NULL`; its own materials are
degenerate black, forced to white under MODULATE), no per-material
`textureName` honoring yet.
- Open, NOT claimed: Huffman Stage 1 (other `.cmp` files still
  undecodable — the trimmed streams are its verified outputs for this
  file); palette on-disk location; the orientation header flag; RWX
  `v=0` convention (renders are flip-ambiguous, histograms are not);
  winding/culling for textured plates (`--doubleside` demo aid).
