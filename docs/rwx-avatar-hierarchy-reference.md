# Joint hierarchy in RWX (articulated avatars), reconstructed from real bytes

> **2026-09-26:** the new engine was removed from the repository, and with it
> its Java `.rwx` reader (`RwxJoint`, `RwxSkeletonParser`, `RwxViewer`...)
> and the captures in `docs/renders/`; what is cited below is in the
> git history, up to commit `8cd795d`. The original client reads the
> `.rwx` files with the bridge's reader (`bridge/NET/worlds/core/RwxReader.java`,
> translated from RWL21).

⚠️ **This is RWX (text), not `.rwg`/`.bod`.** This session's search
started from the instruction to advance on real multi-joint avatars. After
confirming (see `docs/rwg-bod-format-reference.md`) that none of the
project's 5 real `.rwg` files has more than one `ATOM`, and that the
decompiled Java client exposes no visible bone structure (everything
articulated lives in `gamma.dll`, native, not deciphered), the only piece
of real evidence available was found by another route: the real animation
registry (`assets/WorldsPlayer/cachedir/45.dat`, "animation registry
version 0.3") confirms that real network avatars (e.g. "Achoo",
"Aggie") declare `geometry=<name>.rwx` — the SOURCE format of an avatar
is text RWX, not `.rwg` (which only appears in the project as a trivial
local format for `AVATAR.RWG`/`IDLE.RWG`, both single-clump placeholders).
Searching by joint-name convention (`pelvis`, `lfshoulder`,
`rthip`, `lfelbow`...) in the project's 119 real `.rwx` files
(`grep -liE "pelvis|lfshoulder|rthip|lfelbow"`), exactly one file turned
up: **`assets/GROUNDZERO/SPIN.RWX`** (with an identical copy at
`assets/WorldsPlayer/GroundZero/tex/spin.rwx`) — already present in the
project and used in an earlier session as a generic decorative prop,
without knowing it was a real articulated rig.

## The file: `SPIN.RWX`, 19 named clumps, real hierarchy verified

Format: standard text RWX, the same one already verified 118/118 against
`three-rwx-loader` in session 1 (`docs/rwx-format-reference.md`) — no new
parser is needed for the geometry itself, only preserving the
`ClumpBegin`/`ClumpEnd` hierarchy that the existing parser
(`RwxParser.java`) discards when flattening everything into a single mesh.

Naming convention: each joint has a comment `# name` right before its
`TransformBegin`/`Transform`/`ClumpBegin` block. The 19 names found match
EXACTLY the official GammaDocs table (`Gamma_Advanced.html`, section
"Articulated Avatars" — see `docs/rwg-bod-format-reference.md` for the full
citation): pelvis, back, neck, head, lfshoulder/lfelbow/lfwrist,
rtshoulder/rtelbow/rtwrist, lfhip/lfknee/lfankle, rthip/rtknee/rtankle,
lffingers, rtfingers.

Real tree (reconstructed and verified programmatically — see
`RwxSkeletonDumpMain`, next section):

```
pelvis  [v=139 t=260]
  lfhip  [v=30 t=47]
    lfknee  [v=30 t=48]
      lfankle  [v=51 t=86]
  rthip  [v=30 t=47]
    rtknee  [v=30 t=48]
      rtankle  [v=51 t=86]
  lffingers  [v=36 t=60]
    rtfingers  [v=19 t=30]
  back  [v=46 t=80]
    neck  [v=48 t=84]
      head  [v=77 t=138]
    lfshoulder  [v=29 t=49]
      lfelbow  [v=14 t=24]
        lfwrist  [v=14 t=24]
    rtshoulder  [v=26 t=42]
      rtelbow  [v=14 t=24]
        rtwrist  [v=14 t=24]
```

(`v`/`t` = vertices/triangles of THAT clump itself, in its local frame —
not accumulated from its children.)

**Real note, not "corrected"**: `rtfingers` nests as a CHILD of `lffingers`
in the real bytes (its `ClumpBegin`/`ClumpEnd` falls entirely within the
range of `lffingers`), something anatomically unexpected (one would expect
both to be siblings under `pelvis`, or each to hang from its own wrist).
It was left as is — it is what the real bytes say, it was not
"fixed" to look more sensible. 18 nodes in total (not 19 —
GammaDocs lists 17 single-letter codes including `tail`, which this
file does not use; in exchange it has `lffingers`/`rtfingers`, which GammaDocs
does list in its table of numeric tags but not in the one of letter codes).

Raw evidence (real line numbers, `grep -n`):

```
3:    # pelvis
8:        ClumpBegin
759:                ClumpBegin      # lfhip (comment at 754)
855:                        ClumpBegin   # lfknee (850)
952:                                ClumpBegin  # lfankle (947)
1157-1161: ClumpEnd x3 (closes lfankle/lfknee/lfhip)
1163:            # rthip
1168-1570: analogous to lfhip (rtknee 1259/1264, rtankle 1356/1361)
1572:            # lffingers  →  1577 ClumpBegin
1795:                # rtfingers  →  1800 ClumpBegin  (nested INSIDE lffingers, closes at 1935, before lffingers closes at 1937)
1939:        # back  →  1944 ClumpBegin
2156:            # neck  →  2161 ClumpBegin
2739:                # head  →  2744 ClumpBegin, closes 3288, neck closes 3290
3292:            # lfshoulder → 3297 ClumpBegin
3389:                # lfelbow → 3394 ClumpBegin
3446:                    # lfwrist → 3451 ClumpBegin, closes 3503, lfelbow closes 3505, lfshoulder closes 3507
3509:            # rtshoulder → 3514 ClumpBegin (analogous: rtelbow 3596/3601, rtwrist 3653/3658)
3718: ClumpEnd (pelvis)
```

## Parser: `RwxSkeletonParser`/`RwxJoint` (new, does not touch `RwxParser`)

`RwxParser.java` (the flattened parser, verified 118/118) was not modified
— it still produces exactly the same `RwxModel` as before. Instead, a
sibling parser was added, `RwxSkeletonParser` (+ `RwxJoint` as the output
node), which reuses EXACTLY the same transform/clump/material rules
(copied literally from the already-verified behavior — see the class
javadoc of both files) but instead of flattening everything into a single
mesh in root space, produces a tree:

- Each `RwxJoint` has: `name` (from the `# name` comment that precedes
  its `ClumpBegin` — captured BEFORE the line loop discards the
  comments, since that is exactly where the flattened parser throws them
  away), `localTransform` (the matrix that `ClumpBegin` "freezes" for that
  clump, relative to the parent — the same value the flattened parser uses
  for `groupWorld`, but WITHOUT composing it with the parent chain), and its
  own geometry (`vertices`/`triangles`) in its local frame.
- A real detail replicated with care: the RWX vertex index buffer
  is reset both at `ClumpBegin` AND at `ClumpEnd` (behavior
  already documented and verified in `RwxParser`) — that is, a single clump
  can have geometry "before" and "after" a nested child, with file
  indices that restart at 1 in each segment even though the clump is
  the same. `RwxSkeletonParser` reproduces this exactly
  (map of segment-local-index → joint-persistent-index), not
  just the simple case of a single segment per clump.

### Verification (not just "it compiles and does not blow up")

1. **Structure**: `RwxSkeletonDumpMain` on `SPIN.RWX` reproduces
   EXACTLY the 18-node tree reconstructed by hand above (same
   names, same nesting, including the real anomaly
   `rtfingers`-inside-`lffingers`), with no warnings.
2. **Geometry — byte-for-byte match with the already-verified parser**:
   for the project's 119 real `.rwx` files (not just
   `SPIN.RWX`), the set of unique world-space points produced
   by (a) `RwxParser` (flattened, already verified 118/118 against
   `three-rwx-loader`) and (b) walking the `RwxSkeletonParser` tree
   composing `world = parent.world × joint.localTransform` and applying
   that to each joint's local vertices was compared. **All 119 files give
   identical point sets** (0 discrepancies) — strong evidence
   that the captured hierarchy is mathematically equivalent to the
   already-verified geometry, not an approximate reconstruction.
   Additionally, the triangle count matches exactly (1201 on
   both paths for `SPIN.RWX`); the vertex count differs (3603
   flattened vs. 698 in the tree) only because `RwxModel.addVertex` duplicates a
   vertex for each use in a triangle (without deduplicating) while the
   tree stores each local vertex only once — expected behavior,
   not an error.
3. **Visual**: `SPIN.RWX` rendered with the existing `RwxViewer` (which
   uses the flattened parser — geometry already proven identical to the
   tree, see point 2) produces a coherent articulated figure, not
   geometric garbage: legs with feet, hip, torso, head, no
   degenerate triangles. See `docs/renders/rwx_spin_avatar.png`.

### What this does NOT solve (honest limits)

- **`.bod`, the real network transport format, is still not deciphered.**
  The pipeline documented in GammaDocs is source `.rwx` → `rwxtobod`
  tool → compiled `.bod`. This work verifies the SOURCE side
  (`.rwx` with a joint hierarchy), not the compressed binary that the
  client actually downloads and animates (`PendingDrone.java` confirmed in
  an earlier session). Ghidra on `gamma.dll` would still be needed for
  that, just like with `.cmp`.
- **No real animation has been reconstructed** — only the static geometry in
  bind pose (the pose in which `SPIN.RWX` was exported). No additional
  animation/bone system was invented: by the scope rule of
  this session (avatars must look/behave EXACTLY like
  the original, no improved systems), this work is limited to
  extracting the hierarchy that the file itself ALREADY contains.
- **`SPIN.RWX` is a single specimen** — it was not verified that ALL real
  avatars use this same 19-name convention (although
  GammaDocs documents it as the standard of the official pipeline, so it is
  reasonable to assume it for any avatar exported with the same
  process).

## Files

- `client/src/net/openworlds/rwx/RwxJoint.java` — tree node (name,
  local transform, local geometry, children).
- `client/src/net/openworlds/rwx/RwxSkeletonParser.java` — sibling parser
  of `RwxParser`, same transform/clump/material behavior,
  produces the tree instead of flattening.
- `client/src/net/openworlds/rwx/RwxSkeletonDumpMain.java` — verification
  CLI (`java -cp out net.openworlds.rwx.RwxSkeletonDumpMain
  <file.rwx>`), prints the indented tree with vertex/
  triangle counts per joint.
