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

## Honest bottom line

The core mechanism (bit-tree dispatch, all three top-level symbol shapes,
the predictor table and its offset formula, the double-row write, and the
previously-unknown extra fill-broadcast on the control-byte path) is
**understood and substantially verified against real execution**, not
guessed. It is **not yet 100% byte-exact** on either test file, for
reasons that look like a data-capture gap rather than a design gap, but
that is not proven. **Given this, no decoder was wired into the render
pipeline this session** — the project rule against shipping
plausible-but-unverified pixels applies here as much as anywhere else.
The next session should: (a) get a cleaner ground-truth capture method
that doesn't need a one-time memory snapshot at all (e.g. breakpoint on
every individual write instruction and log immediately, rather than
polling `$pc` every `stepi` — should also just be faster), and (b) resolve
the 9-byte 4i.cmp gap with that cleaner data before trusting this decoder
with real texture output.
