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
