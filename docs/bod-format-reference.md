# `.bod` format — fully resolved from the official encoder source

`.bod` is the real, compressed, network-transferred articulated-avatar
format (as opposed to `.rwg`, confirmed in an earlier session to be a
trivial local-only single-clump placeholder format never used for real
avatars). It had been undeciphered for the entire life of this project —
multiple sessions tried reverse-engineering it from raw bytes and from
`gamma.dll` disassembly and got stuck on the multi-joint hierarchy.

## How this got resolved: the official encoder source, not reverse engineering

This session downloaded `gdk.zip` (Worlds Inc.'s "Gamma Developer Kit",
found at `http://jett.dacii.net/jett/gdk.zip` — the `fran.bonkmaykr.xyz`
URL from the session prompt does not resolve at all, DNS failure, tried
both `http://` and `https://`; `jett.dacii.net` only serves plain HTTP,
not HTTPS, which is why an initial `https://` attempt via `curl`/`WebFetch`
failed with a TLS error before this was noticed). It contains
`RWXTOBOD.PL` — Worlds Inc.'s own Perl source for the officially-shipped
`rwxtobod` tool, copyright 1995-1999, complete with a full inline
specification of the `.bod` binary format in its header comments AND the
actual encoder logic implementing it. **`docs/bod-format-reference.md`
(this file) and `client/src/net/freeworlds/bod/BodParser.java` are a
direct, careful translation of that real encoder into its inverse (a
decoder)** — not a guess, not inferred from bytes. Kept at
`tools/gdk-sdk/RWXTOBOD.PL` for reference/attribution.

## File layout

```
u8       version              (always 1 in every real file seen)
u8       numParts
numParts x { u8 tag, u16le offset }   -- offset from the START of the
                                          part-data region (right after
                                          this table) to that part's root
                                          clump
numParts x <clump>             -- one recursive clump tree per part, in
                                   table order
```

## Clump (recursive)

```
u8   tagByte     -- high bit (0x80) set => PLACEHOLDER: this clump is
                     JUST a transform stub (re-attaches a "part" at the
                     right place in its parent's hierarchy) and has NO
                     further fields at all past the translation below -
                     not even a children count.
u8   flag        -- bit7=hasUV, bit6=xPresent, bit5=yPresent,
                     bit4=zPresent; for non-placeholder clumps with
                     hasUV, bit3=vEqualsZ, bit2=vInvertY, bit1=uEqualsX
                     (quantization shortcuts, see below)
f3   xTranslation   -- only if xPresent
f3   yTranslation   -- only if yPresent
f3   zTranslation   -- only if zPresent
-- placeholder clumps stop here --
u8   r, g, b
u16le numVerts
if numVerts > 0:
  [if hasUV] f3 minV, f3 maxV
  f3 minY, f3 maxY
  f3 minZ, f3 maxZ
  f3 minX, f3 maxX
  [if hasUV] f3 minU, f3 maxU
  numVerts x u8   -- quantized X (always present)
  numVerts x u8   -- quantized Y (always present)
  numVerts x u8   -- quantized Z (always present)
  [if hasUV && !uEqualsX] numVerts x u8            -- quantized U
  [if hasUV && !(vEqualsZ || vInvertY)] numVerts x u8  -- quantized V
u16le numTris
if numTris > 0:
  triangle[0] = (0, 1, 2)      -- implicit, never stored
  then a bit-packed stream (see below) for triangles 1..numTris-1
u8   numChildren
numChildren x <clump>   -- recursively. NOT present for placeholder clumps.
```

`f3` = a 3-byte float: take the standard 4-byte little-endian IEEE-754
encoding and drop its least-significant mantissa byte (byte 0); to
reconstruct, prepend a `0x00` low byte to the 3 stored bytes.

Per-vertex quantized bytes are a linear 0-255 code across `[min, max]`
for that vertex's real (x/y/z/u/v) value: `real = min + (max-min)*(byte/255)`
(and `real = min` when `max == min`, avoiding a divide-by-zero — the
encoder always emits byte `0` in that degenerate case, so the formula is
self-consistent either way).

**Vertex order in the min/max header block is `v,y,z,x,u`** (matches the
comment in `RWXTOBOD.PL`) but **the per-vertex quantized byte columns are
written in `x,y,z,[u],[v]` order** — a real asymmetry in the format, not a
mistake: confirmed directly from the encoder's actual field-write order,
which differs from its own header comment's simplified summary.

### The U/V quantization shortcuts

When a clump has UV coordinates, the encoder checks whether V's quantized
byte happens to numerically track Z's byte (`vEqualsZ`), or whether
`vByte + yByte ≈ 255` (`vInvertY`), or whether U's byte tracks X's byte
(`uEqualsX`) — checked in **quantized byte space**, not float space (the
two axes can have completely different min/max ranges). When true, the
encoder skips writing that column entirely and the decoder reconstructs
it from the other axis's *byte*, requantized against **its own** min/max:

```
u = uEqualsX ? dequant(xByte, minU, maxU) : dequant(uByte, minU, maxU)
v = vEqualsZ  ? dequant(zByte, minV, maxV)
  : vInvertY  ? dequant(255 - yByte, minV, maxV)
  :             dequant(vByte, minV, maxV)
```

Reusing the *other axis's already-dequantized float value* directly
(rather than its raw byte, requantized against U/V's own range) is a
tempting first guess and is wrong - it happened to matter for zero real
test files here (the corpus's UV columns didn't hit this exact branch
hard enough to expose it as a bug during development), but the encoder's
own byte-space comparison makes clear it's a byte-level coincidence
across two potentially-different ranges, not a claim the float values are
equal.

## Triangle bitstream

A continuous, byte-packed, **LSB-first** bitstream (bits within a byte
fill from bit 0 upward; the byte-packing state carries across all
triangles of one clump, flushed to a byte boundary before `numChildren`).
Decoding triangle `i` (1-indexed, `i=0` is the implicit `(0,1,2)`):

```
cap = highest + 4         # highest starts at 2
k = ceil(log2(cap))       # bits needed to represent 0..cap-1
loop:
  v1bit = read(1 bit)
  if v1bit == 1:
    v2raw = read(k bits)
    if v2raw == cap - 1:            # escape code
      highest += 1; cap += 1; k = ceil(log2(cap))
      continue loop                  # try again for the SAME triangle slot
    v1 = highest + 1
    v2 = highest - v2raw
    v3raw = read(k bits); v3 = highest - v3raw
  else:
    v1 = highest
    v2raw = read(k bits); v2 = highest - v2raw
    v3raw = read(k bits); v3 = highest - v3raw
  break
# v2/v3 can come out negative (a triangle's other two corners aren't
# always <= highest) - the encoder wraps a negative value by adding cap
# before storing it (RWXTOBOD.PL's pushBits does this for ANY negative
# input, not just triangle deltas), so decode must undo exactly that:
if v2 < 0: v2 += cap
if v3 < 0: v3 += cap
triangle[i] = (v1, v2, v3)
highest = max(v1, v2, v3)
```

**This wraparound was the one real bug found while implementing this** -
without it, real files decoded plausible-looking triangles for the first
few, then went visibly wrong (negative vertex indices, then wildly
implausible vertex/triangle counts cascading from the resulting
byte-misalignment). Found by tracing one real file's raw bits by hand
(cross-checked with an independent Python re-implementation to rule out
arithmetic transcription mistakes) until the exact divergence point, then
recognizing the negative-value pattern matches `pushBits`'s own
documented negative-value handling.

The "1 bit v1 selector, then possibly an escape code" structure lets a
triangle sequence skip past vertices that never got a triangle of their
own (rare, but real meshes can have this), without wasting bits when
`highest` only ever increases by 1 at a time (the common case).

## Body-part tags

Exactly the table found in earlier sessions from community sources and
GammaDocs, confirmed here directly from `RWXTOBOD.PL`'s own `%tags` hash
— this is now confirmed from TWO independent official sources, not just
one:

| tag | part | tag | part | tag | part | tag | part |
|---|---|---|---|---|---|---|---|
| 1 | pelvis | 9 | rtfingers | 17 | rtankle | 25 | mouth |
| 2 | back | 10 | lfsternum | 18 | rttoes | 26 | nose |
| 3 | neck | 11 | lfshoulder | 19 | lfhip | 27 | lfear |
| 4 | head | 12 | lfelbow | 20 | lfknee | 28 | rtear |
| 5 | rtsternum | 13 | lfwrist | 21 | lfankle | 29 | back3 |
| 6 | rtshoulder | 14 | lffingers | 22 | lftoes | 30 | tail2 |
| 7 | rtelbow | 15 | rthip | 23 | back2 | 31 | tail3 |
| 8 | rtwrist | 16 | rtknee | 24 | tail | 32 | tail4 |

A clump with **tag 0** is a synthetic child the encoder inserts when a
single `.rwx` clump uses more than one color/texture (a "material
split") — it's just more geometry belonging to its parent visually, not a
real limb; several real `.bod` files in the corpus have these (e.g. a
separate-material "hair" or "shoe" piece as a tag-0 child of `head`(4) or
`ankle`(17/21)).

## Verification

`client/src/net/freeworlds/bod/BodExtractMain.java` parses a `.bod` and
prints its full clump tree plus totals. Run against **all 26 real `.bod`
files** in `assets/WorldsPlayer/cachedir/` (genuine avatar downloads from
a live server in an earlier session, not synthetic):

```
26 / 26 files fully consumed without error
```

Every byte of every real file is accounted for (no leftover/misaligned
trailing bytes, which the triangle-wraparound bug above would have
caused before it was fixed), and the resulting structure is anatomically
coherent for every 16-part file checked: `pelvis(1)` has children
`back(2)`, `rthip(15)`, `lfhip(19)`; `back(2)` has `neck(3)`,
`rtshoulder(6)`, `lfshoulder(11)`; the shoulder/hip chains continue
correctly through elbow/wrist and knee/ankle; `neck(3)` → `head(4)`.
Real, plausible vertex/triangle counts throughout (e.g. `head` typically
has the most detail of any part - confirmed in the corpus). There is no
independent reference decoder anywhere to diff against (checked - Worlds
Inc. never shipped one, per `docs/rwg-bod-format-reference.md`'s earlier
research), so this structural self-consistency across the WHOLE real
corpus, byte-exact to the end of every file, is the strongest verification
available.

## What's NOT done yet

- No visual rendering of a decoded `.bod` avatar yet (geometry is fully
  extracted - vertices, UVs, triangles, per-limb transforms - the next
  step is feeding it through the existing RWX-era rendering pipeline).
- `RWXTOBOD.PL`'s `-unexplode`/`-swapYZ` options and the 3ds2rwx-specific
  scale/translation-doubling logic (see the script's own comments) were
  not needed for decoding (they're encode-time input-normalization
  choices, baked into the file either way) but are worth knowing about if
  a future session needs to go the OTHER direction (encode a NEW avatar).
- Texture names aren't stored per-vertex in `.bod` at all (only flat
  RGB color) - real avatar textures come from a separate mechanism (the
  animation registry found in an earlier session, `cachedir/45.dat`) not
  yet connected to this parser's output.
