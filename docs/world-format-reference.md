# `.world` format reference, reconstructed from the client's real Java code

> **2026-09-26:** the new engine was removed from the repository, and with it
> its `.world` reader (`WorldRestorer` and company), `WorldViewer`, its checks
> and the captures in `docs/renders/`. What this document says about the
> format is still valid; the code and captures cited below are in the
> git history, up to commit `8cd795d`. The original client reads the
> `.world` files with its own `Restorer`.

## Executive summary

Unlike RWX/RWG/`.cmp`, `.world` **is not a proprietary binary format with an
ad-hoc structure** — it is the serialization of the client's own Java object
graph, using a generic persistence mechanism
("Persister"/`Saver`/`Restorer`) that IS fully implemented in pure,
decompiled Java (`NET.worlds.scape.{Saver,Restorer,SuperRoot,
Transform,WObject,Shape,World,Room,...}`) — no native disassembly is needed
for this format, unlike RWX/RWG/`.cmp`. It is, by a wide margin, the most
reliable source of evidence in the whole project: the very code that writes
and reads the format is there, complete.

**Implemented and verified end-to-end** (with the new engine's reader,
`client/src/net/openworlds/world/WorldRestorer.java`, now in the git
history): it parses `assets/GROUNDZERO/GROUNDZERO.WORLD` (a
real file of 205,759 bytes) **completely, without errors, up to the
`END PERSISTER` marker** — 25 real rooms, 578 nodes in the object graph,
103 `Shape`/`PosableShape` objects with a real reference to
geometry (50 unique `.rwx`/`.rwg` files, all verified against
real files in `assets/GROUNDZERO/`).

## Container: the generic `Persister` protocol

Verified byte by byte against the real header of the file:

```
[bool isNull=false][UTF "PERSISTER Worlds, Inc."]   <- fixed header
[int version]                                        <- 7 in the real file
... N calls to restore() ...
[bool isNull=false][UTF "END PERSISTER"]             <- fixed tail
```

Each `restore()` (the generic method that reads ANY persisted object, from
`World` down to a simple `Point3`) follows this pattern:

```
[int objectId]
  if objectId already seen: use the cached object, do NOT read anything else
  otherwise:
    [int classId]
      if classId already seen: use the cached class name
      otherwise: [UTF full class name, e.g. "NET.worlds.scape.Room"]
    ... the fields of that class itself, see below ...
```

**Critical detail, easy to overlook** (verified in
`Restorer.restoreVersion()`): the version number of each class is read
from the stream **only the first time that class appears**, and is
**cached for the rest of the entire file** (indexed by a "cookie"
that in the real client is a static field per class). This means
that if `WObject` uses version 10 the first time, ALL the
`WObject`-derived objects in the file (`Room`, `Rect`, `Shape`, ...) share
that same version 10 — it cannot be assumed that each object carries its
own version number in the stream.

## Inheritance chain and fields — verified against the real source code

Each Java class corresponds to a `restoreState()` method with a
`switch` on its own version number, almost always ending in
`super.restoreState(var1)` to delegate to the parent class. The
spatial chain relevant to geometry is:

```
SuperRoot   (name — a String)
  └─ Transform  (x/y/z scale + 4x4 matrix of 16 floats = "guts", native)
      └─ WObject  (flags, "contents" children [recursive], handlers, actions,
                    bumpCalc, sharer, tooltip, mouseOver)
          ├─ Shape       (+ geometry URL .rwx/.rwg)
          │   └─ PosableShape  (+ COG bool — posable avatars)
          ├─ Surface     (+ Material)
          │   └─ Rect    (+ u,v,uOff,vOff — texture coordinates)
          │       ├─ Portal       (+ teleport destination)
          │       └─ WebPageWall  (+ embedded web page URL)
          ├─ RoomEnvironment  (the real visible 3D content of a room)
          └─ Room        (+ sky/ground colors, default position,
                            light position/color, environment, teleport)
              └─ WrStaircase  (+ 1 extra float, no version of its own)
```

**Position/rotation/scale**: each `Transform`-derived object stores its
transformation as a **full 4x4 matrix of 16 floats** (RenderWare's native
`float[] guts`), not as separate position+rotation+scale
— it matches exactly the `RwxMatrix4` already used for RWX,
reused directly instead of creating a new class.

**Lighting** (verified in an earlier session, `Room.java`): the light position
and color of each room are explicit fields of `Room` itself
(`lightPosition`, `lightColor` — a `Point3` and an RGB `int`), read
like the rest — no new assumption is needed, the 2-light
lighting engine (earlier session) can be fed directly from these real
per-room values instead of the fixed default value.

## Real bugs found and fixed during the implementation

All found through stream desynchronization (an invalid UTF format exception,
or an "unrecognized" class with a corrupted name) and
diagnosed **by comparing byte by byte against the real file** — never
"it seems to work" without evidence:

1. **`Surface.restoreState` case 1**: the real code uses
   `(Material)var1.restore()` — a DIRECT call, without the preceding
   "can be null" boolean. Case 0, on the other hand, uses the static helper
   `Material.restore(var1)`, which DOES internally do
   `restoreMaybeNull()`. Confusing the two (using `restoreMaybeNull()` in
   case 1) desynchronized the stream by exactly 1 byte — the hardest
   bug to find of the session, diagnosed by comparing real
   offsets computed with a literal search of the class string
   `"NET.worlds.scape.Material"` in the file. The same pattern
   (`Material.restore()` vs `(Material)var1.restore()`) was repeated, wrongly,
   in `RectPatch` and `Portal` — fixed in all three places.
2. **`NET.worlds.scape.WObject` appears directly as an instantiable class**
   in real content (e.g. `"WObVendMachine1"`, an organizational node
   that groups several pieces of a vending machine) —
   not only as an abstract superclass of others. Without an explicit case
   for this class, the parser failed with "unrecognized class".
3. **`SendURLAction` extends `DialogAction`, not `Action`
   directly** — its version 6-9 cases call
   `super.restoreState(var1)`, which in the real inheritance chain of
   THIS class is `DialogAction.restoreState()` (with its own 2
   booleans `showDialog`/`cancelOnly`), whereas its cases 3-5 use the special
   method `dialogActionSkipRestore()` which DOES jump
   directly to `Action` without those 2 booleans. I had implemented
   both cases the wrong way round.
4. **`Billboard.restoreState` case 3 was missing the final field
   `isAdBanner`** (a boolean) — my first transcription assumed
   (incorrectly) that the fields accumulated the same way as in
   `WebPageWall`, without verifying the complete case 3 of `Billboard` on
   its own.

## Verification performed (with no external reference — it is the only parser
## that exists for this exact format of this client)

- The whole file parses from start to end without any exception,
  reaching the real `END PERSISTER` marker.
- 25 room names extracted (`ChatHall`, `Reception`, `AvatarEnter`,
  `IconViewRoom1`...) verified as present literally in the bytes of the
  real file (direct search, not just "the parser says so").
- 103 objects with a geometry URL, 50 unique `.rwx`/`.rwg` file
  names, verified against real files existing in
  `assets/GROUNDZERO/` (`FRAME.RWX`, `KIOSKBASE.RWX`, `POST1A.RWX`,
  `KEDGE.RWX`, `EARCH.RWX`, ...).
- Avatar references (`avatar:Tre.rwg`, `avatar:Julie.rwg`...) using
  a special `avatar:` URL scheme — consistent with the avatar mechanism
  already documented in `docs/rwg-bod-format-reference.md`.

## What remains uncovered (outside the scope of "position + geometry")

The `Action`/`Sensor` classes (18 of the 33 classes of the real graph) are
parsed correctly to keep the stream in sync. Since
2026-09-22 the ones that move textures are kept (see "Actions that change
textures" below); the remaining fields (teleports, clicks, movements) are
not modeled.

---

## Connection with the rendering engine: `WorldViewer.java`

`client/src/net/openworlds/render/WorldViewer.java` loads a real `.world`,
resolves each geometry URL against real files on disk
(relative to the directory of the `.world` itself, with a case-insensitive
search because the URLs in the file do not always match the real
name — e.g. `"tex/frame.rwx"` in the file vs. the real `Frame.rwx` on
disk), and draws the complete tree of a room with the already existing
lighting/materials pipeline (`GlLighting`, verified in earlier
sessions).

### Real, critical finding: the 16-float transformation matrix is not a
### valid affine matrix as it comes in the file

When trying to draw the first real room (`Reception`, the real
`groundzero.world`), the screen came out **completely black** — 96 real
triangles sent to OpenGL, without any GL error, but nothing visible.
Diagnosed step by step, assuming nothing:

1. Lighting was ruled out (tested with `GL_LIGHTING` disabled and a fixed
   white color — still black).
2. Back-face culling was ruled out (tested with a global
   `glDisable(GL_CULL_FACE)` — still black).
3. Depth precision was ruled out (the near/far plane was adjusted to the
   real size of the scene — still black).
4. **Projecting by hand, in Python, a real vertex through the exact
   camera+projection used**, it was found that the Z coordinate in
   clip space (NDC) fell at `0.9999991` — stuck to the far
   plane, consistent with the homogeneous component "w" of the matrix
   collapsing to 0 instead of staying at 1.
5. Dumping the complete 16-float matrix of a real object (not just
   the translation), it was confirmed: **float number 16 (the one that in any
   valid affine matrix must be 1.0) is literally `0.0` in ALL the real
   objects inspected** — it is not random noise, it is
   consistent. The translation (floats 13-15) always had real values
   consistent with the expected position of the object.

**Conclusion (⚠️ VERIFY the exact reason, but the fix is
empirically verified)**: RenderWare's native "guts" representation of
`Transform` apparently does not bother to write that redundant
value — leaving it at 0 collapses the homogeneous computation of
any standard OpenGL consumer. Forcing float 16 to `1.0` when reading
the matrix (`WorldRestorer.fixMatrix()`) fully resolved the
black screen — from 0 visible objects to recognizable real geometry.

### Session 2 (2026-09-09): the real convention of the 3×3 block, read from
### the source code — not guessed

The previous state left `ReceptionView1` with severely degenerate geometry,
and the hypothesis of "transposing the 3×3 block" had already been
tested and ruled out (it made `Reception` worse). This session, following
an explicit instruction from the user, went back to the real Java code
instead of continuing to try "reasonable" mathematical conventions
blindly.

**Real evidence, not abstract math**, found in
`Transform.java`:

1. **`Transform.printGuts()`** (a real debugging method, NOT native —
   unlike `getGuts`/`setGuts`) prints the 16 floats like this:
   ```java
   for (int var8 = 0; var8 < 4; var8++) {      // var8 = row
      for (int var5 = 0; var5 < 4; var5++) {   // var5 = column
         String var6 = var2[var8 * 4 + var5];  // index = row*4 + column
   ```
   This confirms **row-major storage**: `matrix[row*4+column]`
   — NOT column-major as had been assumed without verifying.
2. **`Transform.worldVecToObjectVec()`** (line 285):
   ```java
   Point3Temp var3 = Point3Temp.make(var1).vectorTimes(var2)...
   ```
   A `Point3Temp` (the vector/point) is the receiver of `.vectorTimes()`,
   and the `Transform` (the matrix) is the argument — that is, **the vector
   is multiplied on the left: `v' = v · M`** (row-vector convention),
   not `v' = M · v` (column-vector convention, the one that
   OpenGL/`glMultMatrixf` assumes by default).

**Mathematical deduction from this evidence** (not a convention
chosen a priori): with `M` stored row-major as
`matrix[row*4+column]` and used as `v' = v·M`, the column-major array
that `glMultMatrixf` expects in order to produce the same result (`v' = G·v`)
is `G = M^T`. Writing out the column-major storage of `M^T`:
`Garray[column*4+row] = M^T[row][column] = M[column][row] =
matrix[column*4+row]` — **exactly the same index that the raw array
already has**. That is: **nothing needs to be transposed** — passing
the 16 floats as they are to `glMultMatrixf` already correctly implements the
client's real `v·M` semantics. This explains why transposing (earlier
session) made things worse: it would have applied `v' = M·v`, the wrong
convention.

### The real cause of `ReceptionView1`: it was not the convention, it was
### uninitialized padding bytes

With the convention already confirmed as correct (without transposing), each
real matrix of `ReceptionView1` was compared against the only
mathematically valid values that an affine matrix can have outside the
rotation/scale block and the translation: indices 3, 7 and 11 (last
column of rows 0-2) must always be `0.0`, and index 15
(bottom-right corner) must always be `1.0`.

**Finding**: in EVERY problematic object, those 4 indices contain numerical
garbage — neither zeros nor random noise, but values that are consistent
per object (a tiny denormalized float at index 3, a huge float such as
`1.3E10` at index 7, a "reasonable but false" float such as `0.125` at
index 11). A shared object
(`WObLOGO`/`Rect843cy`, present in `Reception` and `ReceptionView1` with
identical data, confirming it is not read noise) showed
exactly: `matrix[3]=1.0021795E-38, matrix[7]=1.3061306E10,
matrix[11]=0.125, matrix[15]=0.0`.

**Why it only affected some rooms**: scanning the 3 test rooms with an
automatic out-of-range value detector, `Reception`
had exactly 1 affected object (small, almost hidden),
`IconViewRoom1` had 0, and `ReceptionView1` had more than 15 — it matches
exactly why those rooms looked fine and this one did not.

**Most plausible interpretation (⚠️ the ultimate reason is still not
confirmed at the native disassembly level, but the pattern is
unmistakable)**: RenderWare's native "guts" representation
is probably in fact a compact 4×3 affine matrix (3×3 rotation/
scale + 3×1 translation), expanded to 16 floats for the convenience of the
Java save format — and that padding column was serialized
directly from whatever was in native memory at that moment, without being
initialized to zero. The real native renderer, using
a 4×3 matrix internally, never read that column — so forcing it to the only
mathematically valid values (`[0,0,0,1]`) reproduces the
real behavior of the original client, instead of trusting bytes
that the client itself never used.

**Fix applied** (`WorldRestorer.fixMatrix()`): besides forcing
index 15 to `1.0` (already done in the previous session), indices 3, 7
and 11 are now also forced to `0.0`. Without transposing anything — the
deduction above confirms it is not needed.

### Before/after verification (same 3 rooms, real captures)

- **`IconViewRoom1`** (`docs/renders/world_iconviewroom1_fixed.png`,
  0 objects affected by the bug): **identical** to the previous render — the
  fix is surgical, it does not touch data that was already valid.
- **`Reception`** (`docs/renders/world_reception_fixed.png`, 1 object
  affected): the hexagon and the lines of `frame.rwx` are just as
  recognizable as before, and now a small reddish quadrilateral also
  appears, correctly positioned near the center — the object that
  previously had garbage data (`Rect843cy`) and that used to be projected
  outside of any reasonable position.
- **`ReceptionView1`** (before: `docs/renders/world_receptionview1_anomaly.png`,
  after: `docs/renders/world_receptionview1_fixed.png`) — a
  drastic change: the giant degenerate triangles disappear
  completely, replaced by real recognizable objects (a panel, some small
  shapes, a thin figure). Also verified with data: the
  real world position of the 56 objects was dumped, and the result makes
  geographic sense — a cluster of picnic furniture
  (`grill`/`yard_table`/`cokecan`/`bottle1`/`umbrella`/`steak`/`fork`,
  all between coordinates ~(100-400, -2000, 300-400)), cacti and rocks
  scattered across a large outdoor area, a road (`road_01.rwx`) at
  the edge, and walls/roof of a building (`sideh*`/`roof.rwx`) — the
  bounding box is still large (~38,600 units wide) but
  **it is real**: it is a genuinely extensive outdoor scene, not an
  artifact.

**Conclusion**: the `ReceptionView1` bug was not the mathematical
convention of the 3×3 block (that one was already correctly implemented,
now confirmed with evidence from the real source code instead of only by
elimination), but 4 bytes of uninitialized padding in the original
client's own save format, which had to be recognized and discarded
explicitly. The `.world` → positioned real geometry →
render pipeline is verified on the 3 test rooms, including the one that
used to fail.

### `Portal` v8/9: real connectivity (2026-09-16)

Confirmed in GroundZero (version 9, `WORLD_DEBUG=1`): after
`farSideIsPortal` and `allowDownload`, `farSidePortalName` (string) is read,
then `farSidePortal` (**object reference** via `restoreMaybeNull`: resolved
by identity, not by name; `Restorer.java:165-175`, `Portal.java:689`),
`farSideWorld`, `farSideRoomName` and `farx/fary/farz/fartheta`. Those 4
floats only count when `farSideIsPortal=false`: in
portal-to-portal connections they are 0.0 in the file because the client
recomputes them in
`postRestore()` → `recomputeFarPosition()` (`Portal.java:711-722`,
`220-240`). `WorldRestorer.readPortal` no longer discards them; the stream
is still consumed the same way (578 nodes, `END PERSISTER` intact). Of the 87
portals in GroundZero, 56 resolve within the world, 2 point to another
`.world` and 29 are disconnected in the data itself.

### Actions that change textures (2026-09-22)

`WorldRestorer` now keeps, instead of discarding them:

- `WObject.eventHandlers` and `WObject.actions` (`WNode.handlers`/`actions`),
  in the real order of `WObject.restoreWObjectState`: contents, handlers,
  actions (version 0 does not save actions; **version 1 does**, and the
  parser skipped it: fixed, although GroundZero does not use those versions).
- `Sensor.actions` (in the sensor's `WNode.actions`), `SequenceAction`
  (components, `loopCount`, `loopInfinite`; in v0/v1 a negative
  `loopCount` is infinite), `WaitAction.duration` and the fields of
  `AnimateAction` (`cycleTime` ms, `cycles`, `infiniteLoop`, `frameList`;
  in v0/v1 `cycleTime` comes as a float and `infiniteLoop = cycles == 0`).

What is in GroundZero (owner = the object in whose action list it sits):

| Room | Owner | Trigger | Materials | Cadence |
|---|---|---|---|---|
| ReceptionView1 | 2× `Rect840Flag2` | StartupSensor | `f12h*.mov` … `f82h*.mov` | 8 in 1000 ms, loop |
| IconViewRoom1 | `Rect840` | StartupSensor | `drs12v*.mov`, `drs52v*.mov` | 2 in 6000 ms, loop |
| AvatarEnter | 4 Rects (floor, ceiling, 2 walls) | StartupSensor | `avflr1/2/3/2.cmp` | 4 in 1000 ms, loop |
| Reception | 4 kiosks `Rect84cyan1..4` | StartupSensor → infinite SequenceAction | `knews*`/`kevent*`/`kstore*.cmp` | Wait 1 s + Animate (5 in 500 ms, 1 cycle) … |

In the original the StartupSensor fires on the first frame of the room and
the live actions are called once per frame (`RunningActionHandler`).
In `ReceptionView1` the StartupSensor also launches 8 `MoveAction`s (birds,
plane and logo) that do not change textures.

### Cells of a Rect: `Surface.addSubPolys` (gamma.dll `0x004206d0`)

With a material of several textures (`Nh*`/`Nv*`, see
`docs/cmp-texture-format-reference.md`) the Rect is not a quadrilateral but
a grid of cells. What the binary says, which is **not** what Ghidra's
C for that function says:

- The C reads vertices 1, 2 and 4 into the same local variables and
  seems to use only 1 and 4 for everything. In the disassembly,
  `0x00420768-0x00420794` stores `x2-x1` and `u2-u1` in `[ebp-0x8c]` and
  `[ebp-0x88]` **before** reading vertex 4, and `0x00420b0c-0x00420b1a`
  divides `x2-x1` by `hRes*(u2-u1)`; `z` and `v` do come from vertices
  1 and 4 (`0x00420b00-0x00420b0b`). In a Rect (vertices of
  `Rect.addRwChildren`: 1 = (0,0,0), 2 = (1,0,0), 4 = (0,0,1)) using
  vertex 4 for x/u gives 0/0 and no cell.
- The start and end cells are rounded with `frndint` under two different
  control words: `0x00480a7c` = `0x077f` (toward −∞) for uMin/vMin
  and `0x00480a78` = `0x0b7f` (toward +∞) for uMax/vMax.
- Within each block the row of cells is walked from bottom to top and from
  left to right (except for flipping, flags `0x100000`/`0x80000`, which
  alternates from block to block), and polygon *i* carries material
  *i* mod *hRes·vRes*.

In the bridge: `NativeScene.addSubPolys`, with cases computed by hand in
`bridge/test/SubPolysCheck.java`.

### Portals: state, crossing and arrival, like the original (2026-09-22)

Corrects the 2026-09-16 section ("56 resolve… 29 disconnected"):

- **Crossable = state 2 and bumpable: 53/87.** The state comes from
  `Portal.postRestore` → `newFarSide` (with a reference to the far portal) or
  `reset()`/`findFarSidePortal` (without one). `WObject.detectBump` only looks
  at objects with `flags` bit 1 (`getBumpable`): the 3 self-connected mirrors
  (`WestPortal1AuditoriumHall`, `EastPortal2AuditoriumHall`,
  `EastPortalReflection`, flags `0x5`) are not bumpable and the original
  never crosses them; the viewer used to (it counted 56).
- **The 31 that do not cross, by cause**:
  29 without `farSideRoomName` (`reset()` leaves them at −1: 14
  `WestPortalNNTrigger` in ReceptionView1 and 6 `EastPortal1Patch*Trigger`
  in Garden MazeC7b, invisible and bumpable, which only fire actions;
  and 9 ends of one-way portals: `EastPortal1..3ReceptionView2`,
  `EastPortal2..6ReceptionView1`, `WestPortal2Garden MazeC7b`); 2 to another
  `.world` (`UserHomePortal` → `home:AvatarGallery/avatar.world`,
  `WestPortal1DcnEnter` → `rel:home:Dcn/dcn.world`), which are not in the
  corpus (neither in `assets/` nor in `cachedir/`): the original would load or
  download them (`World.load` → `loadedURLSelf`, `NetUpdate.loadWorld`).
- **Detection**: `PassthroughBumpCalc` cuts the pilot's path against
  the bottom edge of the portal (position + `(1,0,1)·M`, in x/y) with
  `BumpEventTemp.isCollision`, which only accepts one direction (path to the
  left of the edge = toward local +Y).
- **Arrival**: `_p2pxform` of `Portal.setTransform` (gamma.dll
  `0x0041b170`) = inverse(LTM without its own scale) · [mirror: −x column]
  · `Rz(fartheta)` · `T(farx,fary,farz)`, with `recomputeFarPosition`
  (own position of the far portal + `(1,0,1)·M` in x/y except for the mirror;
  `fartheta = (−getYaw + 180) % 360`) and `getYaw` from gamma.dll
  `0x00425440`. The whole pilot is multiplied by that matrix: the cut
  position (+0.2) and, as vectors, the rest of the path and the forward
  step. Previously the viewer placed the player at `farx/fary` (the far
  corner of the portal, regardless of the crossing point: it changes in 53/53)
  with a deduced heading that disagrees with the real one in 40/53 portals
  (typically 180°, facing the portal one has just left).
- Check: the 44 round-trip pairs give `p2p·p2p' = I` (maximum
  error 1.2e-4), which would not happen with the sign of `getYaw` reversed.
