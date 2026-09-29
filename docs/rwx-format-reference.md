# RWX format reference, verified against three-rwx-loader

Everything in this document comes from reading directly
`three-rwx-loader/src/RWXLoader.js` (an npm package, not vendored; it was
installed in `tools/rwx-harness/node_modules`) — not from the Active
Worlds wiki or from assumptions. Where the real behavior is surprising or
contradicts what one would expect, it is explained with evidence (line
number, code fragment). It was implemented in
`client/src/net/openworlds/rwx/` and verified with
`tools/rwx-harness/compare.py` against the project's 118 real `.rwx`
files: **118/118 OK**.

> **2026-09-26:** that reader, the `tools/rwx-harness` harness and its report
> `docs/rwx-parser-progress.md` belonged to the new engine and were removed
> with it; they are in the git history, up to commit `8cd795d`. The
> original client reads the `.rwx` files with the bridge's reader
> (`bridge/NET/worlds/core/RwxReader.java`, translated from RWL21).

**Note about this document**: a first attempt to generate it with a
read-only subagent was interrupted midway (it got sidetracked building the
comparison harness, which was completed and works, but never wrote this
file). It was completed by reading the source code directly in the main
thread, since it is the core logic of the parser (out of scope for
delegating, according to the project's instructions).

---

## 0. Most important structural finding: per-clump scoping

Before reading the command tables, this is what made most of the parser's
initial bugs disappear all at once:

- **`ModelBegin`/`ModelEnd` do NOT exist for the parser.** There is no regex
  that recognizes them (`this.clumpbeginRegex = /^ *(clumpbegin).*$/i` —
  nothing about "model"). They are pure no-ops. The real scope
  establishment is done by the first `ClumpBegin` immediately inside.
- **The vertex indices of `Triangle`/`Quad`/`Polygon` are relative to a
  vertex buffer *per clump*, not to a global list for the entire file.**
  `ClumpBegin` clears the buffer (`clearGeometry()`, line 596) AND
  `ClumpEnd` clears it again. If a parent clump declares `Vertex` before
  AND after a nested child clump, the `Triangle`s "after" index from 0
  again — they do not continue where the parent left off.
- **The material also has clump scope**: `ClumpBegin` clones the current
  material and pushes it (`pushCurrentMaterial`, line 1277);
  `ClumpEnd` restores it (`popCurrentMaterial`, line 1285). A `Color`
  inside a child clump does not leak to the following siblings.
- **The transformation also has clump scope, but in a different way from
  `TransformBegin`/`TransformEnd`**: `ClumpBegin` freezes what had been
  accumulated as the "base" of this clump and **resets the local
  accumulator to identity** for what is declared inside
  (`pushCurrentGroup`, line 1258); `ClumpEnd` restores the local accumulator
  to what it was right before the reset, discarding what the child clump did
  with it (`popCurrentGroup`, line 1270). `TransformBegin`/`TransformEnd`,
  in contrast, only save/restore without resetting to identity
  (`saveCurrentTransform`/`loadCurrentTransform`, lines 1292-1298).

Implemented in `RwxParser.java` as: a `groupWorld` (the "world" transform of
the clump that wraps the current one) + a stack of saves; a
`currentTransform` LOCAL to the current clump (reset to identity at each
`ClumpBegin`) + a separate stack for `TransformBegin`/`TransformEnd`. The
vertex baked in at the moment of `Vertex`/`VertexExt` is
`groupWorld × currentTransform × raw-position` — evaluated
immediately, not deferred.

---

## Batch (a): basic static geometry

### `ClumpBegin` / `ClumpEnd`
See section 0. Also: the first time a `ClumpBegin` is seen in the
file, three-rwx-loader marks it as "the real root of the topology"
(line 2269) — an internal naming detail, with no effect on geometry.

### `Vertex x y z [UV u v]` / `VertexExt` (same regex, same treatment)
- It is transformed **immediately** with `currentTransform` (line 2542:
  `tmpVertex.applyMatrix4(ctx.currentTransform)`) and added to the buffer
  of the current clump — not deferred to the moment the triangle is emitted.
- UV: if there is no `UV u v`, `(0, 0)` is used. If there is, V is inverted:
  `1 - v` (line 2555). It does not affect the geometry/position comparison;
  it would affect a real renderer with textures.
- ⚠️ **VERIFY**: it was not checked whether `VertexExt` (vs. plain `Vertex`)
  has any additional real field in this project's files — in the
  118 test files, `VertexExt` behaves identically to `Vertex` according to
  the shared regex (`this.vertexRegex` covers both names).

### `Triangle a b c [tag N]`
- 1-based indices in the file → 0-based internally (line 2406:
  `parseInt(entry) - 1`).
- The optional `tag` parameter is used for a "signs" mechanism
  (`signTag`/`setMaterialRatio`) unrelated to pure geometry — not implemented
  in the Java parser, does not affect the vertex/face comparison.

### `Quad a b c d [tag N]`
- **It does NOT always cut along the A-C diagonal.** It cuts along the
  **shorter** diagonal: `cutAC = distSq(A,C) > distSq(B,D)` (line 772) —
  that is, if A-C is longer than B-D, it cuts along B-D instead. With
  `cutAC`: triangles `(a,b,c)` and `(a,c,d)`; otherwise: `(a,b,d)` and
  `(b,c,d)`.
- Special case NOT implemented in the Java parser (⚠️ out of scope for now,
  it does not appear in the 118 test files): if
  `GeometrySampling == WIREFRAME`, the quad is rendered as only the outer
  edges (lines 732-754), which is rendering logic, not fill-geometry logic.
- Special case NOT implemented (⚠️ likewise, it does not appear in the corpus):
  `correctInvalidNormals` — if enabled and the chosen cut would produce
  invalid normals, it duplicates the 4 vertices and uses those copies instead
  of the original indices (lines 778-814). It would require computing
  real normals, which the current Java parser does not compute (positions
  only).

### `Polygon n v1 v2 ... vn [tag N]`
- **The order of the indices is reversed before fan triangulation**:
  `polyIDs.unshift(parseInt(id) - 1)` in an ascending loop (line 2508) —
  since `unshift` inserts at the front, the result ends up in the
  reverse of the file's order.
- Forces `LightSampling.FACET` for the material during emission
  (line 830) — a lighting effect, not a geometry one.
- It does not appear in the 118 test files; implemented in the Java parser
  followed by the order reversal documented above, but **not verified
  against a real file** — ⚠️ VERIFY if an `.rwx` with
  `Polygon` shows up in the future.

---

## Batch (b): materials and textures

### `Color r g b`
Direct set of `material.color = [r,g,b]` (line 2579) — it is **not** mixed
with `Ambient`/`Diffuse`/`Specular`, they are completely separate fields.

### `Surface a d s`
Sets all THREE coefficients at once: `material.surface = [a,d,s]`
(ambient, diffuse, specular, in that order — line 2727).

### `Ambient a` / `Diffuse d` / `Specular s`
Each one overwrites only its own position inside `material.surface[0/1/2]`
(lines 2735-2751) — they do not touch `color` or the other two positions.

### `Opacity o`
Direct set of `material.opacity`.

### `Texture name [mask]`
- Only processed if `this.enableTextures` is on (default `true` in
  the real loader, line 1988) — **but the comparison harness disables it
  on purpose**, see the big warning below.
- `Texture NULL` (case-insensitive) clears the texture.

### ⚠️ Important finding: comparing three-rwx-loader materials in this
### environment (headless Node, no real image files) is NOT reliable

With `enableTextures` on (the default), loading any file from
our corpus produces the same flat gray material `d8d8d8` with no texture
on **all** the triangles, regardless of what `Color`/`Texture` declare in the
`.rwx` — confirmed by directly inspecting the resulting
`THREE.Material` objects (not just the harness JSON), in files with
and without `Texture`, with different `Color` values. The most likely cause:
the corpus only has textures in `.cmp` format (Worlds' own), not
`.jpg` (the loader's default `textureExtension`) nor any format that
the headless loading pipeline can resolve, and the load failure
contaminates the base color too, not just the map.

**Mitigation applied**: `tools/rwx-harness/extract.mjs` calls
`loader.setEnableTextures(false)` to avoid the contamination — but with
this the texture name is NEVER recorded on the reference side
(while the Java parser does record it correctly), so **the
`map`/`textureName` field is not comparable between the two sides with this
configuration**. Also, even with textures disabled, the hex color that
`THREE.Color.getHexString()` produces **does not match** a direct
`round(channel*255)` conversion — strong suspicion of an internal linear↔sRGB
conversion in `THREE.Color` (confirmed with an isolated test:
`new THREE.Color(0.537255, 0.196078, 0.196078).getHexString()` gives
`"c27a7a"`, not `"893232"` as a direct conversion would; and the value that
actually comes out of the real loader is a THIRD, different value, `"732828"` —
the exact formula was not identified).

**Decision made**: `tools/rwx-harness/compare.py` reports the material
count as an **informational note, not as an OK/DIFFERENCES criterion**
— the authoritative comparison is geometry (vertices/triangles), which
is 100% verifiable and gives 118/118 OK. ⚠️ **VERIFY pending**: the exact
color conversion formula of `THREE.Color`, if in the future exact colors need
to be verified (for example when the LWJGL renderer needs
to paint with the correct color).

### Material commands recognized by the parser but WITHOUT a verified
### geometry effect beyond storing the field (not explored in depth,
### low impact for phase 1): `MaterialModes`, `TextureModes`,
### `GeometrySampling`, `LightSampling`, `CollisionEnabled`. All have their
### own regex in the real loader but only mutate rendering/collision flags,
### not positions — confirmed by reading the code (not tested
### exhaustively against the real corpus).

---

## Batch (c): transformations

### `Identity`
`currentTransform.identity()` — absolute reset (line 2599).

### `Transform` (16 values)
- **Absolute set**, not multiplication: `currentTransform.fromArray(tprops)`
  (line 2623).
- The 16 values are read in **column-major order**, exactly like
  `THREE.Matrix4.fromArray` — **not** row-major. See the note on conventions
  below, it is the most likely source of bugs if this is reimplemented
  without verifying.
- ⚠️ **Confirmed quirk of the AW/Worlds client** (explicit comment in the
  source code, line 2615): if the last value (position 15, bottom-right
  corner in column-major) is `0`, it is forced to `1`. Replicated as is in
  `RwxParser.parseTransformMatrix`.

### `Translate x y z` / `Scale x y z`
They post-multiply: `currentTransform.multiply(M)` (lines 2646, 2710) — that
is, `currentTransform = currentTransform * M`.

### `Rotate x y z angle`
**It is not an arbitrary-axis rotation.** It is up to THREE
independent rotations about the cardinal axes X, Y, Z (in that order),
each applied only if its coefficient is non-zero, with angle
`coefficient × angle` degrees (lines 2668-2687):
```
if (x != 0) currentTransform *= RotationX(x * angle degrees)
if (y != 0) currentTransform *= RotationY(y * angle degrees)
if (z != 0) currentTransform *= RotationZ(z * angle degrees)
```
This is easy to misread as "normalized arbitrary axis +
Rodrigues formula" (that is how I implemented it at first, incorrectly,
before reading the source code) — it is not. No `Rotate` appears in
the corpus of 118 test files (all of them use `Transform` with a
raw matrix), so this is implemented but **without empirical verification
against a real file** — ⚠️ VERIFY if one shows up.

### Matrix convention: column-major, `M × v`

All of the `three-rwx-loader` code uses the conventions of `THREE.js`:
column-major storage (`e[0..3]` = column 0, etc.), `a.multiply(b)`
means `a = a * b`, and a point is transformed as `v' = M * v` (column
vector). `client/src/net/openworlds/rwx/RwxMatrix4.java` replicates this
exactly — the first version of the parser used row-major with
`v' = v * M` (the opposite convention) and produced subtly
incorrect geometry in files with non-trivial transformations, without giving
any compilation error or exception — just slightly different numbers.
Detected thanks to the comparison harness, it would not have been obvious
at a glance.

---

## Batch (d): clump/proto hierarchy

### `ProtoBegin` / `ProtoEnd` / `ProtoInstance`
Recognized by the real loader (lines 2310-2358, a reusable-template mechanism
with `ctx.rwxPrototypes`), but **they do not appear in any of the project's
118 test files**. **Not implemented in the Java
parser** — ⚠️ VERIFY and add if models from another
source (`.rwg`/`.bod` avatars or other worlds) that do use them are needed.

### Commands with their own regex in the loader that also did NOT reach
### the test corpus: (none more relevant to hierarchy — `Tag` is the
### only one that appears frequently, see below).

### `Tag N`
It only puts `N` in `userData.rwx.tag` of the current group (line 3001) —
pure metadata, with no effect on geometry or real hierarchy.

---

## Commands that three-rwx-loader does NOT recognize (verified: there is no
## regex for them in the whole file) — pure no-ops, confirmed to appear
## profusely in the real corpus with no effect whatsoever on the final geometry:

- `ModelBegin` / `ModelEnd` (section 0 — the most important finding)
- `JointTransformBegin` / `JointTransformEnd` / `IdentityJoint`
- `Hints` / `AddHint`

The last 4 appear 72+40+336 times combined in the corpus (avatars and
props with bones/joints) and **do absolutely nothing** in
three-rwx-loader. The Java parser lets them fall through to `default:`
(ignore) — behavior verified as correct, not an accidental omission.

---

## Verification methodology (harness)

- `tools/rwx-harness/extract.mjs`: parses with the real three-rwx-loader
  (`setFlatten(false)`, `setEnableTextures(false)` — see Batch (b)),
  flattens the group hierarchy by multiplying matrices manually
  (`walk()`), excludes the `rwx-scale-group` group that the loader adds with
  a fixed scale of 10x (Active Worlds' "decameter" convention,
  lines 2233-2239 of the loader — it does **not** come from the `.rwx` file,
  the loader always adds it) in order to compare in the same "raw" units as a
  parser that does not apply that scale.
- `client/src/net/openworlds/rwx/RwxExtractMain.java`: same JSON output format
  from the Java parser.
- `tools/rwx-harness/compare.py`: runs both, reorders the triangles of
  each side with a numeric key computed in Python (it does not trust the
  internal order of each side — see the big comment in
  `numeric_sort_key()`, it was the cause of massive false positives until
  it was fixed), compares position per vertex with tolerance `1e-3`, and
  writes `docs/rwx-parser-progress.md`.
- **Final result: 118/118 files OK** in geometry (vertices and
  triangles). Material is informational only (see Batch (b)).
