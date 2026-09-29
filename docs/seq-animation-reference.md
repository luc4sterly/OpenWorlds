# Avatar animation: `.seq`/`.mov` format and how the original plays it

> Status (2026-09-15): **`.seq` format complete, translated from the
> decompiled C of `gamma.dll` and verified on the real corpus**:
> `SeqParser` consumes 231/231 whole files (`SeqExtractMain`).
> Update 2026-09-23: the playback of `DroneAnimator` (sequence choice,
> blends, application to joints) is translated in the bridge of the
> original client; see section 7.
>
> 2026-09-26: the new engine (`client/`, with `BodViewer`, `WorldViewer` and
> its copy of this rule) was removed from the repository; what is cited from
> it below, `docs/renders/` captures included, is in the git history up to
> commit `8cd795d`. `SeqParser` and `SeqSampler` remain in
> `formats/`, because the bridge uses them.
>
> Audit correction: commit `bcd60fd5` claimed "leftover=0",
> but its `SeqParser` failed on 231/231 files (it read a `u16`
> "checksum" that does not exist in the file). Fixed and re-verified.

## 1. Two distinct systems (verified in `Drone.java:359-364`)

- **Articulated** (Axel, Aura…): `.bod` + `.seq` + `avatars.dat`.
  `PosableDrone` → `PosableShape` → `DroneAnimator.animate/update`
  (native blending).
- **Hologram** (`avatar:*.mov`): `.mov` = ScapePic texture movie
  (magic `LzH2`, same as `.cmp`), NOT skeletal.
  `HoloDrone` → `Hologram` → `ScapePicMovie` (native). Image frames,
  never joints.

## 2. `.seq` format (verified: C + bytes + 231/231)

The loader is `FUN_00436d50`: if the first byte is `0x7f` it jumps to the
big-endian variant `FUN_00436610`; otherwise, format v1.

### v1 (little-endian, packed deltas) — 194 files

```
u8   version            (0x01 in the whole corpus; the original does not check it)
u8   nJoints            (0 = error)
u8   len + figure       (FUN_0042f3b0, no NUL)
u16  K                  no. of keyframes
u8[K] dictionary        time delta per key; time_i = sum(dict[0..i])
nJoints × { u8 len + name ; track 0x10 }
u8   nExtra ; nExtra × track (index 3 → 0x10, the rest → 4)
```

- **There is no checksum in the file**: the sum of the K bytes is computed in
  memory and stored (short) at `+0x214` — it is the total duration.
- Track 0x10 (`FUN_00437550`): 4 base LE floats, in file order
  (4-component object `FUN_00428fe0`), + (K-1) × 3 bytes = 4 indices
  of 6 bits; each one: 5 bits of magnitude in the `CB32` codebook + sign
  (`>0x1f` = negative), summed cumulatively.
- Track 4: 1 base float + (K-1) × 1 byte (7 bits in `CB128` + sign).
- Codebooks in `gamma.dll` (file offset `0x729c0` = CB32,
  `0x72a40` = CB128): bit-for-bit identical to those of `SeqParser`.
- Example worked out by hand, `axelwave.seq` (265 B): `01 04 06 "harold"`,
  K=13, 13 dictionary bytes, 4 joints (`back`, `lfshoulder`,
  `lfelbow`, `lfwrist`) × (name + 16 B + 36 B), `nExtra=0` → exactly 265.
- First value of many joints = `(1,0,0,0)`. Together with the
  0x7f variant, which stores the 3-float tracks as `(0,a,b,c)`, it points to
  the first component being the real part of the quaternion. ⚠️ VERIFY in
  the code that consumes the track (not yet read).
- 4 real joints with base `(0,0,0,0)` (`common_g1_no`: pelvis/rthip/
  lfhip; `common_g3_spin`: head): file data, not a parse error.

### Variant `0x7f7f7f7a` (big-endian, unpacked) — 37 files from `cachedir`

```
u8[4] 7f 7f 7f 7a
u16  duration           (→ +0x214; < 1 = error)
u32  nJoints            (≤ 0 = error)
u16 len + figure        (the NUL goes inside the length)
u16 len + root joint    (→ +0x114)
nJoints × { u16 len + name ; track }
u32  nExtra ; nExtra × track
track (FUN_004364e0 / FUN_00436260):
  u32 sizeFlag (4 | 0xc | 0x10) ; u32 nKeys ;
  nKeys × { u32 time ; 1 | 3 | 4 floats }   (0xc is stored as (0,a,b,c))
```

Figures seen: `SeqBed-Aura`, `pose53_a/b`, `male`, `slim`, `breaker`
(root `Box01`), `male` with root `Cube`… — exported from another tool
(3ds Max-style names), not from the classic Gamma rig.

### Observed rigs

- 16 joints (classic Gamma rig), 44 joints (LifeForms mocap with
  `lumbar_*`/`thorax_*`/`cervical_*`, e.g. `axelwalk`), partial ones of 3-4
  joints (`axelwave`: left arm only). Full histogram in the
  output of `SeqExtractMain`.
- `axelwait.seq` is byte-identical to `axelendwave.seq` (cause unverified).

To reproduce: `java -cp formats/out net.openworlds.bod.SeqExtractMain -q
assets/gammatutorial-samples/base-avatars/*.seq assets/WorldsPlayer/cachedir/*.seq`.

## 3. `avatars.dat` / `45.dat` registry (text, `# animation registry version 0.3`)

Blocks `avatar name=X geometry=Y.rwx beginimp{walk=… wait=… endwait=…}
beginexp{wave=… yes=… dance=…}`. The values are names WITHOUT extension
(`walk=achoowalk`); the client adds `avatars\<name>.seq`
(`PendingCacheDrone.java:34`). The Java does NOT choose `.seq` by state: the
native code resolves the implicit ones (`walk/wait`, in `update`) and the explicit
ones (`*gesture*` in chat → `Pilot` → `PosableDrone/PosableShape.animate` →
`DroneAnimator.animate` with `getAnimationTime` as duration).

## 4. Tag→joint table (only official source: `tools/gdk-sdk/RWXTOBOD.PL:150-183`)

`pelvis=1, back=2, neck=3, head=4, rtshoulder=6… lfankle=21…` (same in
`Avatar building text.txt:430-493`). The Gamma `.seq` files use those names;
the mocap ones (44) are incompatible with the 1-32 table — the native
retarget is NOT verified. `SeqFile.java` only passes the path to the native code
(`notifySeqLoaded`); `DroneAnimator` (15 methods, all native, confirmed in
`docs/native-methods-map.md:231-246`) does the rest.

## 5. Playback in `gamma.dll` (decompiled C, verified 2026-09-15)

93 functions of `gamma.dll` are `EnterCriticalSection` + a single
`Rw*` call (e.g. `FUN_00418a50` = `RwRotateMatrix`, `FUN_00419950` =
`RwPushScratchMatrix`), which makes the animation chain readable.

- **JNI chain**: `DroneAnimator.update` → `FUN_00435520` →
  `FUN_00433710` (dispatch through a C++ vtable); `animate` → `FUN_004355a0`
  (looks up the action by name with `FUN_00433e90` and starts it with
  `FUN_00432d10`); `getAnimationTime` → `FUN_00435630` → `FUN_00432be0`
  (returns `sec + ms/1000`, `DAT_00472020` = 1000); `prepFigure` →
  `FUN_00434f00`. Java: `PosableShape.handle(FrameEvent)` calls
  `moveto(x,y,z,-yaw,t-1)` + `update(null, this, Std.getRealTime(),
  scaleX, distance>700)` every frame (`PosableShape.java:1235-1238`).
- **Sampling a track** (`FUN_00435a10` → `FUN_00435ab0` /
  `FUN_00435b20`): index = last key with time ≤ t (0 if t < first);
  at the last key or at exact t → the key's value; otherwise, `f = (t-t0)/(t1-t0)`
  (with `dt` short; `dt<1` → key 0) clamped to [0,1] and
  **per-component linear interpolation + normalization** (nlerp: `FUN_004271c0` +
  `FUN_00426f40`, normalizes only if |q|²>1e-5), not slerp; scalars and
  vectors linear. No keys → identity. No looping in the sampling.
  Translated in `formats/src/net/openworlds/bod/SeqSampler.java`.
- **Quaternion**: object (vptr, w, x, y, z). Identity `FUN_00428f10` =
  (1,0,0,0); axis-angle `FUN_00428f40` stores `cos(a/2)` at +4; Hamilton
  product `FUN_004272c0`; to matrix `FUN_00427040` (4×4 row-major,
  s = 2/|q|²). → **the first float of each key is w** (resolves the ⚠️ of
  section 2).
- **Pose** (`FUN_00438300`): extras 0..2 = root translation; extra 3 =
  root rotation; each 0x10 joint → entry (key = internal id of the
  name, quaternion with **x and y negated** by `FUN_004290c0`,
  `DAT_00473440` = −1). The root's z is negated or zeroed depending on a flag
  (`DAT_00475fec` = −1) whose caller is not yet located ⚠️.
- **Name → tag**: own table of 30 names in `gamma.dll` (strings at
  fileoff `0x71314`, pointers at `0x71420`, registered by
  `FUN_004298b0`), exact comparison with `strcmp` (`FUN_0044d730`).
  Tags 1..22 = same names as `RWXTOBOD.PL`; 23..30 = `neck2`, `tail`,
  `tail2`, `tail3`, `tail4`, `obj`, `obj2`, `obj3` (in `RWXTOBOD.PL`
  23 is `back2`, etc.). There are no `lumbar`/`thorax`/`cervical` strings in the
  DLL: **mocap joints without a name in the table are ignored; there is no
  44→16 retarget, only name matching** (`common_walk` applies 22
  of its 44 tracks).
- **Application** (`FUN_00434470`): for each tag 1..30,
  `RwFindTaggedClump(figure, tag)` + `RwTransformClumpJoint(clump,
  quaternion_matrix, 1)`; tag without a track → identity. The root
  translation × 0.1 (`DAT_00475490`) is written into row 3 of the modeling
  matrix of the figure's first child, multiplied by its diagonal
  (`FUN_00431990`, `RwTransformClump(…, 1)`). The root rotation (extra 3)
  is computed but not applied there.
- **Composition in RenderWare 2.1** (disassembly of `RWL21.DLL`,
  verified): row-vector convention with the translation in row 3;
  **`LTM_child = Joint · Modeling · LTM_parent`** (`0x10004747`: tmp =
  M(+0xEC)·LTM_parent; `0x10004788`: LTM = J(+0x130)·tmp; with no parent LTM =
  J·M). Modes of `RwTransformClump`/`ClumpJoint`/`Matrix`/`RotateMatrix`
  (common routine `0x1001c500`): **1 = replace**, **2 = X·destination**
  (pre-concatenate, in local space), **3 = destination·X** (post). The LTM is
  cached and invalidated when transforming or reattaching. `RwGetClumpMatrix`
  returns only the modeling one (+0xEC).
- **Figure** (`ShapeLoader.loadBodFile` loads ONE part per call →
  `FUN_0041e240` → `FUN_0041d950`): each part = clump with
  `RwSetClumpTag(tag)` and its translation in the **modeling matrix**;
  placeholder = child clump with tag `0x8000000|tag` and its translation. The
  native `WObject.addChildToClump` hangs each part from the placeholder with
  its tag (if there is none, from the parent). That is why `RwFindTaggedClump` only
  finds parts and each rotation pivots on the origin of its part.
- **`prepFigure`** (`FUN_00434f00`): the figure's joint matrix =
  `RwRotateMatrix(axis (0,1,1), 180°)` (Y-up of the `.bod` → Z-up of the
  world) + `RwScaleMatrix(1000)`; it moves the translation of the first child
  (pelvis) into that matrix and sets it to 0 in the pelvis (that is why the
  root translation of the `.seq` can replace it), and re-places by the COG
  (only z if `COG=false`). It gives evidence for the ×1000 and +Y→+Z that
  `WorldViewer` used as a heuristic.
- **Time and looping** (resolved on 2026-09-16, after recovering with Ghidra
  the functions that are only reached through a vtable): the player stores the
  sequence at `+0xc`, the **current time as a short at `+0x14`**, the elapsed
  time at `+0x18` and the duration in seconds at `+0x1c`
  (`FUN_0043b490`: `key_duration · 1/30`, `DAT_00476ec0`). The two advance
  variants — `FUN_0043b950` (time {sec,ms}) and `FUN_0043b5f0`
  (seconds as a float) — agree on the rule:

  ```
  t = trunc(seconds * 30)                       // DAT_00476ec8 = 30.0
  if t > duration:  mode 2 -> t % (duration + 1)   // loop
                    mode 1 -> duration              // stays at the last key
                    other  -> playback ends
  ```

  That is, **the keys run at exactly 30 per second** (consistent with
  `common_walk` = 42 keys = a 1.4 s cycle). Translated in
  `SeqSampler.keyTime`. ⚠️ Correction 2026-09-23: the conversion to integer
  **truncates**, it does not round: before the `fistpl` both functions set the
  control word to "chop" (`orb $0xc` at 0x43b9c0 and 0x43b70f);
  `SeqSampler.keyTime` uses `Math.round` and gives one extra key in the
  upper half of each 1/30 s. The bridge uses truncation
  (`AnimGraph.TimeDriver`/`DistanceDriver`). The two functions that output the
  pose (`FUN_0043b770`, `FUN_0043baa0`) differ only in the flag that
  zeroes or keeps the z of the root translation — the `param_3` that
  used to remain ⚠️.
- **Controller**: reconstructed on 2026-09-23, see section 7
  ("Sequence selection in the client"). The 0xfa blend is 250
  **ms** (`{0 s, 250 ms}`) and the curve `clamp(8·r·(1−r), 0, 1)`
  (`FUN_0043ab30`) is that of the **explicit** ones, not that of the
  implicit change (which is linear, `FUN_0043a540`).

## 6. What is missing for real animation (next step)

1. ~~`.seq` key-data decoder~~ ✅ (section 2). ~~Sampling, quaternion order,
   name→tag, retarget~~ ✅ (section 5). ~~LTM formula
   and RenderWare 2.1 pre/post~~ ✅ (section 5). ~~Apply the pose to a
   `.bod`~~ ✅ `BodViewer --seq <f.seq> --frame T` (see below).
2. ~~**Controller**~~ ✅ (section 7): `walk`/`wait`/`endwait` selection,
   synchronization with the distance traveled, blends and looping, translated
   in the bridge (`bridge/NET/worlds/core/Anim*.java`, `NativeAnimator.java`).
3. ~~Flag for the z of the root translation~~ ✅: the time-based drivers
   (wait, gestures) keep it negated; the distance-based ones (walk) zero it.
4. `.mov` as a texture video (today only frame 0). Minor: `csq` (cited
   in GDK, no specimen).

## 6.1. Pose verification (2026-09-15, macOS)

`BodViewer --seq f.seq --frame T [--keep-root-z]` applies the pose. Without
`--seq` the result is bit-for-bit identical to the previous one (same md5 on
`aura`, `tina`, `ogre`, `death`, `axel`; `orphans=0 badIndices=0`), so
the LTM change does not introduce a regression in bind pose.

With a pose, an **anatomical** verification (there is no pixel-by-pixel
comparison with the original: the 2004 client needs Wine and this Mac does
not have it):

- `aura.bod` + `common_walk.seq`: frame 0 and frame 21 (half a cycle) give
  legs and arms in opposition and with the phases inverted relative to each
  other — `docs/renders/bod_aura_common_walk_f0.png` and `_f21.png`. It
  applies 22 of the 44 tracks (the mocap ones without a tag name are
  ignored, section 5).
- `axel.bod` + `axelwave.seq` (4 tracks: `back`, `lfshoulder`,
  `lfelbow`, `lfwrist`): at frame 80 it raises the **left** arm,
  the one those tracks animate — `docs/renders/bod_axel_axelwave_f80.png`.
  With the wrong x/y sign or matrix convention the arm
  would come out backwards, inside the body or on the opposite side.
- `aura.bod` + `common_a_wait.seq`: frame 0 is exactly the bind pose
  (all quaternions identity) and toward frame 144 there are small
  breathing displacements —
  `docs/renders/bod_aura_common_a_wait_f144.png`.

## 6. Forward of the `.bod` (verified)

Face and tips of the feet in **local +Z** (Y-up), ponytail/heels in −Z:
`SPIN.RWX` (head −0.006/+0.043, foot −0.005/+0.059) + bytes of
`aura.bod` (ponytail −Z, face +Z); `RWXTOBOD.PL:7,21-25,799-806` passes axes
through untouched. Bod +Z maps to world +Y → rotation `yaw−90°` (algebra).
GammaDocs confirms Y-up/X-wide (`Avatar building text.txt:240,402-405`).

## 7. Sequence selection in the client (DroneAnimator)

Translated on 2026-09-23 from the animation engine of `gamma.dll`
(0x0042b000–0x0043c500) into the bridge (`bridge/NET/worlds/core/`:
`AnimRegistry`, `AnimSeqCache`, `AnimGraph`, `AnimPose`, `AnimAnimator`,
`AnimMotion`, `NativeAnimator`; natives hooked in by
`bridge/natives-animator.patch`). Checks: `bridge/test/Animator*Check.java`.

### 7.1 What Java decides and what the native code decides

Java (`PosableShape.handle(FrameEvent)`, `PosableShape.java:1219`) only
reports: every frame, if the avatar is less than 900 from the camera
(`closestView`, which `prerender` computes with `inCamSpace`), it calls
`moveto(type, (short)x, (short)y, (short)z, (short)-yaw, t-1)` and
`update(null, this, t, scaleX, far>700)`. Gestures arrive through
`animate(type, name, t)` (chat `*gesture*`, `Pilot`, `PosableAction`...),
whose duration (`getAnimationTime`) `PosableShape` uses to chain
sequences with `&`. **Everything else is decided by the native code**: which
implicit one applies, at what rate it advances and how it is blended. `far` is
not used (it reaches `FUN_00433710`, which does `ret 0x14` without reading
`0x18(%ebp)`).

### 7.2 Registry (`avatars.dat`)

`loadconfig` (FUN_00434b70) empties the registry and parses the text
(`Archive.readTextFile`, without CR). A 32-character header → grammar
0.3 (FUN_0042cda0) or 0.2 (FUN_0042d840, with a fixed type `cy`). The
scanner is a flex (FUN_0042a4c0) with tables in the binary; these rules come
out of them: `#…\n` and blanks are skipped; the number is **a single
digit** (`version 3`); identifier `[A-Za-z0-9_][A-Za-z0-9_.-]*`
(`123`, `2v` and `Skating-1` are identifiers). The action keys are
lowercased (FUN_004280b0); sequences and attributes are not.
`getnameindex` compares the `name` attribute case-insensitively
(FUN_004508c0); the index is the order in the file.

### 7.3 The five implicit ones and the state machine

Table of implicit ones (0x475288, 12 bytes: name, arg1, arg2):

| idx | name | advances by | when it ends |
|---|---|---|---|
| 1 | (none) | — | empty pipe = rest pose |
| 2 | (none) | — | empty pipe |
| 3 | `walk` | distance (arg1 0) | loop (arg2 2) |
| 4 | `wait` | time (arg1 1) | stays at the last key (1) |
| 5 | `endwait` | time | last key |
| 6–9 | `run`, `fly`, `hover`, `sit` | 0/0/1/1 | loop — no state chooses them |

`moveto`/`moveby` (FUN_004351b0/FUN_004352f0) pass position and
orientation (Z axis, `yaw·π/180`) to FUN_00434670, which classifies the
movement with the table `{3,3,2,1}` (DAT_004754e0): **3** if the
position changed (exact equality of the `short`s), **2** if only the
orientation changed (`|dot(q,q') − 1| ≥ 0.0005`, about 3.6°), **1** if
nothing:

```
state 1 (just arrived):    turns -> 2, walks -> 3, 10 s still -> 4
state 2 (turning):         still -> 1, walks -> 3
state 3 (walk):            still -> 4 (straight to wait), turns -> 2
state 4 (wait):            turns -> 2, walks -> 3, 30 s -> 5
state 5 (endwait):         turns -> 2, walks -> 3, 10 s -> 4
```

The deadlines are `{10,0}`, `{30,0}`, `{10,0}` since the last change (time
of `moveto`, unsigned `<=` comparison). The first `moveto` sets
state 1. The chosen index is looked up by name among the implicit ones of
the type; if the avatar does not have that key, empty pipe.

### 7.4 Synchronization with speed

The walk (distance driver, 0x476ff4) does not advance with the clock but with
the distance traveled: `FUN_00431440` stores the horizontal part of the
displacement between two positions (the Z component is removed) with sign
(negative if in the avatar's system `y` is `<= 0`: walking backwards plays
the walk in reverse). `update` (FUN_00435520) computes
`scale = 10 / (scaleX · m00 · 1000)` with `m00` from the modeling matrix
of the pelvis (first child of the figure) and advances the driver
`amount = distance · |scale|` sequence "seconds"; key =
`trunc(accumulated · 30)`, looping with `fmod` (negatives wrap around).
With the `.bod` scale (1000 from `prepFigure`, pelvis 1): 100 world units
= 1 s of walk = 30 keys. The other implicit ones and the gestures
advance with the real dt (`update` − previous `update`).

### 7.5 Blends

- Implicit change (FUN_00432d10 → `shiftto`, 0x476e14): from whatever there
  was to the new sequence over **{0 s, 250 ms}** (0xfa), linear weight
  `clamp(t/250 ms, 0, 1)` (FUN_0043a540); joints that are only in one of
  the two are blended with the identity.
- Gesture (`animate` → `overlay`, 0x476df8): on top of the implicit one for
  the duration of the `.seq` (`floor(keys·(1/30f))` s + ms, FUN_00427a50);
  weight `clamp(8x(1−x), 0, 1)` with `x = t/duration` (FUN_0043ab30: rises in
  the first 14.6% and falls in the last); **only the gesture's joints**: the
  rest continues with the implicit one (table 0x4771fc copy A). With
  `override.ini [Runtime] NoImpChange=1` the weight is 1 and there is no changeimp.
- Interpolation (FUN_00439450): nlerp with hemisphere change.
- `beginchangeimp` (FUN_004330a0): when launching a gesture with a block, its
  pairs replace the animator's implicit sequences (e.g.
  `chairsit` → `wait=lgSeated`), effective at the next change of
  implicit. The sequences that only appear in those blocks
  (`willendwait`, `willwalk` in 45.dat) are not registered by `addtype`
  (FUN_0042b160 only walks implicit and explicit ones) and therefore are never
  loaded: rest pose. Bug of the original: a changeimp key that
  is not among the implicit ones writes a position beyond the vector
  (it compares with the end of the explicit list, 0x433378).

### 7.6 Time, looping and what `animate`/`getAnimationTime` return

- Time driver (0x476fdc): `key = trunc((s + ms/1000)·30)`; if
  `key > duration`: loop `key % (duration+1)` (mode 2), last key (1) or
  ends (0, the gestures). Empty driver (no `.seq`): lasts {10000 s}.
- `animate` and `getAnimationTime` return `s + ms/1000` of the gesture's
  duration (e.g. `axelwave`, 142 keys → 4.733); 0.0 if the name is not
  there (DAT_00475524). A gesture with no loadable `.seq` lasts **10000 s**.
  The time that `animate` receives is not used.
- Loading: `addtype` registers the type's sequences in the cache
  (`./avatars\NAME.seq`); they are requested from Java
  (`PendingCacheDrone.downloadSeqFile`) **synchronously the first time they
  are needed** (FUN_0042fc90) or asynchronously if another type already
  shared them.

### 7.7 Pose application and `prepFigure`

FUN_00434470: tags 1..30 (ids 3..32 through FUN_004298b0) in order;
`RwFindTaggedClump` + `RwTransformClumpJoint(replace)`; tag without an entry
→ identity; the root translation (extras 0–2) ×0.1 goes to row 3 of the
modeling matrix of the pelvis multiplied by its diagonal; the root rotation
(extra 3) is not applied. `prepFigure` (FUN_00434f00) = section 5, plus: the
point that is re-placed is (center x, center y, minimum z) of the box of the
tree in the world (FUN_00418900); with COG = false only the z (feet on the
ground).

### 7.8 Verified and pending

- `AnimatorRegistryCheck` (45.dat, 221 types), `AnimatorPlaybackCheck`
  (durations, keys, blends, loop, hold) and `AnimatorMotionCheck`
  (states at 1000/10999/11000/40999/41000/51000 ms, walk 100 u → key 30,
  backwards → 15, pelvis scale, pose in the joint, `prepFigure`).
- In game (GroundZero, `IconViewRoom1a`): `addtype`, `prepFigure`,
  `moveto`/`update` run and the figures stand upright at scale. The
  statues in the galleries **spin** (~70°/s), so the C keeps them
  in states 1/2 (no sequence): they do not reach `wait`. ⚠️ To see them
  animate in the bridge it also takes (outside these files)
  `WObject.nativeInCamSpace` (0x00413910; today a stub that returns `z = 0`,
  so `closestView` never drops below 900) and that `RwReadStreamChunk` of
  a `.rwg` without vertices (`avatar.rwg`) return an empty clump instead of
  0 (otherwise the `PosableShape` is never `isFullyLoaded` and does not
  create the animator).
- ⚠️ Precision: the operations are done in `double` assuming the x87 control
  word 0x027F of the JVM (53 bits, round-to-even); it only affects exact
  ties.
- ⚠️ The `catch` for syntax errors in `avatars.dat` (C++ throw)
  is not located: the bridge warns and keeps the types read.

### 7.9 `SeqSampler.keyTime`

`SeqSampler.keyTime` (in `formats/`) truncates like the drivers (`fistp` in
chop, 0x43b9c0). The new engine came to have a copy of this whole rule
(`client/src/net/openworlds/avatar/`, 2026-09-25); it was removed with it on
2026-09-26 and is in the git history up to commit `8cd795d`.
