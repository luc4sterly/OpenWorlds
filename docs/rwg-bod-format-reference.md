# RWG/BOD format reference, reconstructed from real bytes

> **2026-09-26:** the new engine was removed from the repository. Its viewers
> (`RwgViewer`, `BodViewer`) and the captures in `docs/renders/` cited
> below are in the git history, up to commit `8cd795d`.
> `RwgParser` and the `.bod` reader remain in `formats/`, because the
> bridge of the original client uses them.

⚠️ **Unlike RWX, there is no library or external documentation that
documents the exact binary format of `.rwg`/`.bod`** —
confirmed with real research, not assumed (see the "External research"
section below). Everything here comes from: (1) hex dumps of real
files from the project, (2) `Gamma_Advanced.html` (OFFICIAL documentation
from Worlds Inc., "Articulated Avatars" section — provided by the user in
this session as part of `GammaDocs.zip`; the full documentation is NOT
versioned in this repo because of its volume — see section 3.4 of
`docs/worlds-chat-project.md` for the known public mirrors:
`archive.org/details/gammadocs`, Worlio, Wayback Machine — the facts
cited here are paraphrased/quoted with attribution, so the full HTML is
not needed to verify them), and (3) the decompiled Java code of the real
client (which confirms what the client itself does NOT do, see below). **No
data was invented** — where the evidence is insufficient it is explicitly
marked ⚠️ VERIFY, not filled in with assumptions.

> **Corrections from the 2026-09-15 audit — they take precedence over the
> historical text below:**
>
> 1. **`VLST[0..7]` are not vertices: they are the 8 corners of the local
>    bounding box of the clump**, and the 1-based indices of `PLST` count
>    from record 8. Evidence: in `RWL21.DLL`,
>    `RwGetClumpNumVertices` (0x10003fe0) returns count−8 and
>    `RwGetClumpVertex` (0x100319f0, helper 0x10041c90) addresses
>    record n+7; in the 8 `.rwg` files of the repo the first 8 entries are
>    exactly the bbox of the rest (error 0), and counting from 8 the
>    geometric normal in fan order matches the face normal of
>    `PLST` in 3466/3466 polygons (167 if counting from 0).
>    Consequences: `cube.rwg` has 24 vertices (not 32), `e3.rwg` 1371
>    (not 1379); `AVATAR.RWG` is not "a cube of sentinels" but an
>    empty clump with a bbox of ±FLT_MAX; the "grid order" of the quads, the
>    "(0,0,0) normals" and the "inconsistent winding" of `cube.rwg` were
>    effects of the same error: the polygons are convex loops (fan) and
>    the winding is consistent. Fixed in `RwgParser` (commit
>    `1cc135b5`); render in `docs/renders/cube_rwg_bbox_fix_lit.png`.
> 2. **`.bod` is solved** (the final "NOT solved" section is
>    historical): see `docs/bod-format-reference.md`.
> 3. There are **8 real `.rwg`** files in the repo (including `e3.rwg` and the
>    copies of `AVATAR`/`IDLE` in `assets/WorldsPlayer/`), all with a single
>    `ATOM`.

> **Translation from the binaries (2026-09-24) — takes precedence over
> everything below.** The format is no longer deduced from bytes: it has been
> translated from the real reader, `RwReadStreamChunk` of `RWL21.DLL`
> (0x10039e40, read in assembly with `objdump`, the C from Ghidra for that
> function is broken) and from the part of `gamma.dll` that opens the file.
> Implemented in
> `formats/src/net/openworlds/rwg/RwgParser.java`, checked in
> `formats/test/net/openworlds/rwg/RwgTablesCheck.java`. See the section
> "Format according to the binary" right below.

## Format according to the binary (RWL21 + gamma.dll)

All big-endian. A chunk is `[tag][length][content]`. RW does **not** read
the children by position: each reader looks for the chunk it wants with a
loop (e.g. 0x1003a205) that reads a tag and, if it is not the one sought,
skips that chunk with `RwSkipStreamChunk` (0x10039cd0); it never jumps to the
end of the parent chunk. A `STRT` is read with a maximum: min(length, max)
bytes are read and (length − max) is skipped, signed (0x1003b17a). gamma opens
the file in memory (`RwOpenStream(3,1,…)`, FUN_004181d0): reading or skipping
past the end is error 0x58 and a read of 0 bytes is an error.
Any FALSE aborts the whole CLUM and `finishLoadingBinaryFile`
returns −1.

**Header (gamma.dll, not RW).** `FUN_00419af0`: tag `ZZZ[`, length L
(must be > 8), and the words `0x13765342`, `1`. The next L−8 bytes
(`FUN_00419a20`) **are not the name of the object**: they are the
**texture list** that `FUN_0041c970` (the constructor of
`ShapeLoader.loadBinaryFile` 0x0041e5d0) requests from Java *before* reading
the CLUM, string by string until an empty one, with `.cmp` (DAT_00470a7c) if the
name has no dot, via `ShapeLoader.startTextureLoad`. Only if the
list ends in the empty string is the load marked as good (`this+0xc`,
which `finishLoadingBinaryFile` 0x0041e630 requires). IDLE → `idle.cmp`, e3 →
`earthkin.cmp`, AVATAR/ball/table → nothing.

**CLUM** (0x1003a03d): creates a context with five lists and looks for, in
this order, `RALT`, `TELT`, `MALT` and the root `ATOM`.

| Chunk | Contents | Address |
|---|---|---|
| `RALT` | STRT(12) `[n, ?, ?]` and n `RAST` chunks (STRT of 10 integers: width, height, ?, stride, format; and a `DATA` with the pixels) | 0x1003c4e3, RAST 0x1003c72a. ⚠️ no real sample: the whole corpus has n = 0 |
| `TELT` | STRT(12) `[n, record size, ?]`; per entry it **always** reads 0x14 bytes = 5 integers `[raster, mipmap raster, ?, ?, ?]` and, if the record size is **smaller** than 0x14, it also skips forward (0x14 − size); then it looks for a `STNG` with the name | 0x1003cb3f, 0x1003cc68 |
| `MALT` | STRT(12) `[n, record size, ?]`; per material it reads 0x28 bytes = 10 integers and, if the size is larger, skips the rest | 0x1003bfce, 0x1003c0ab |
| `ATOM` | STRT(0x34) of 13 integers, 2 `MATX`, `VLST`, `PLST` and the child ATOMs | 0x1003b569 |

**TELT entry → texture.** Raster 0 (the only case in the corpus):
named texture (0x1003cde9): it is looked up in the current texture dictionary
(FUN_100184d0) and, if it is not there and a file with that name exists in
the shape path (FUN_10021270: as is and with `.ras`, `.tex`, `.env`,
`.bmp`, `.rle`, read from DAT_1005ad00..1005ace0), `RwGetNamedTexture`;
if there is no texture, error 0x5e and **the CLUM fails**. Raster ≠ 0
(0x1003cd40): a new texture over that raster of RALT (and that of the mipmap if
≠ 0) and into the dictionary with the name (⚠️ no real sample). The texture is
added to the list **only if it was not already there** (0x1003ce42), so two
entries that yield the same texture take up a single index.

**MALT record → material** (RwCreateMaterial and 0x1003c119..c180):

| Field | Destination |
|---|---|
| [0] | texture: 1-based index into the TELT list (0 or out of range = none) → `RwSetMaterialTexture` |
| [1] | word 0 of the material: sampling. Geometry = 1 if < 4, 2 if < 8, 3 if < 0xc, otherwise 4 (RwGetMaterialGeometrySampling 0x10019e40); light = 2 if bit 0, otherwise 1 (0x10019ea0) |
| [2] | byte of material+0x30: `& 0x1f` texture modes (1 lit, 2 foreshorten, 4 filter, 0x10 trilinear), `& 0xc0` material modes (0x80 double-sided) |
| [3..5] | color r, g, b (reals) → `RwSetMaterialColor` |
| [6] | opacity → `RwSetMaterialOpacity` |
| [7..9] | ambient, diffuse, specular → `RwSetMaterialSurface` |

Real values: IDLE `[1, 0x14, 2, 0.96875, 0.984375, 0.96875, 1, 0.75,
0, 0]` (texture "idle", solid, facet, foreshorten without lit, ambient
0.75 = gamma's "self-lit" FUN_00417950); e3 `[1, 0x15, 2, 0.5,
0.5, 0.5, 1, 0.1, 0.5, 0.9]` (per vertex); ball 512 red materials
`[0, 0xd, 1, …]`, one per triangle; table a single orange one.

**ATOM, STRT of 13:** [0] → clump+0x8c and [1] → clump+0x90 (⚠️
meaning undetermined), [2] tag (+0xe8), [3..7] not read, [8]
hints, [9] axis alignment (+0x18c), [10] state (+0x190, 1 OFF 2 ON),
[11] **number of child ATOMs** (they are read after PLST and attached with
`RwAddChildToClump`; ⚠️ no real sample, the whole corpus has 0), [12]
light sampling frequency (real). The two MATX go to clump+0xec and
clump+0x130.

**VLST** (0x1003b1be): STRT `[n, size, flags]`. Record: x,y,z;
flag 1 normal (marks the vertex with 0x40, normal set); flag 2
u,v; flag 4 three reals (vertex +0x10..+0x18, ⚠️ meaning
undetermined). UV and flag 4 are stored as 16.16 (× 65536.0 =
DAT_10052298, `__ftol`). The first 8 records are the local box
(see the audit correction, below).

**PLST** (0x1003a583): STRT `[n, size, flags]`. Record:
**material** (1-based index into MALT; it is the field that used to be called
"id/flag" and that in ball counts 1..512), number of vertices, indices;
flag 1 face normal (polygon +0x10); flag 4 three reals at 16.16
(polygon +0x04..+0x0c, ⚠️ undetermined); flag 0x10 tag (16 bits at
+0x38). The "number of trailing fields per file" (6 in cube/ball/table,
7 in IDLE) is this: flags 7 → 3+3, flags 0x17 → 3+3+1. Each
polygon goes through FUN_10001220, which removes consecutive repeated indices and
the last one if it repeats the first; with fewer than 3 the whole PLST fails.

**gamma callback after reading** (FUN_00419a60 → `RwForAllClumpsInHierarchy`
with 0x004187e0 without hardware 3D): tag < 0x4000000 → `RwSetClumpHints(2)`;
otherwise `RwSetClumpState(OFF)`. The same after an `.rwx` (FUN_004199c0).

**Consequences measured in the corpus:**

- **`cube.rwg` is not read by the RW 2.1 of WorldsPlayer.** Its TELT has
  16-byte records (`[0,1,0,1]`); RW reads 20 (it eats the `STNG` tag), skips 4
  more (its length) and the STNG search ends outside the stream (0x5a).
  It was probably generated by another version of RWX2RWG; ⚠️ confirming it would
  require loading it in the original under Wine.
- `AVATAR.RWG` (the default `xShape`) is a **valid, empty** clump:
  0 vertices, 0 polygons, tag 0, state ON.
- IDLE and e3 **require** their texture in the dictionary (or a
  `.ras/.tex/.env/.bmp/.rle` file with that name): in the client the earlier
  load of the header puts it there (`idle.cmp` is in `WorldsPlayer/`).
- `table.rwg`: 524 vertices (532 records − 8).

## Important update: a larger real corpus was found inside the official
## GammaDocs tutorial (`cube.rwg`, `ball.rwg`, `table.rwg` +
## `table.rwx` source, now in `assets/gammatutorial-samples/`)

These 3 files came packaged in the official documentation
(`GammaDocs.zip`, provided by the user, folder `GammaTutorial/tex/`),
they are not synthetic — they are binary data in the real format, not
documentation, so they were moved to `assets/gammatutorial-samples/` and ARE
versioned (unlike the rest of GammaDocs). When tested against the
freshly written parser with only `AVATAR.RWG`/`IDLE.RWG` as evidence,
they **broke the initial hypothesis about `PLST`** (which had only been
verified against ONE polygon) — which is exactly the signal that
the first hypothesis was insufficient, and it was corrected with real evidence
instead of being kept. Result, with the corrected `PLST`:

- **`cube.rwg`** (2168 bytes, a 6-face/32-vertex cube) — **parses
  cleanly** and provides the strongest evidence of the whole session: each
  of the 6 `PLST` records has a face normal field
  `(nx,ny,nz)` with a single axis at `~±1.0` — **all 6 possible axes
  appear exactly once each** (+X,-X,+Y,-Y,+Z,-Z),
  matching perfectly the 6 faces of an axis-aligned cube.
  This also revealed that the vertex fields that were previously
  "undetermined" (floats[3:6)) **are the per-vertex normal**, not a
  mystery — confirmed because it matches exactly the face normal
  of `PLST` in every case.
- **`ball.rwg`** (55108 bytes, 512 triangles, ~258 vertices) — also
  **parses cleanly** with the same structure (vertCount=3 instead of 4,
  correctly generalizing the algorithm).
- **`table.rwg`** (49692 bytes, 546 polygons, a real mix of triangles and
  quadrilaterals) — initially **did not parse** (it broke the assumption of
  "uniform record size derived by division"); **resolved** in
  the articulated-avatar session (2026-09-09) without needing that
  assumption — see details in the `PLST` section below.

## ⚠️ Central finding of this session: the real corpus is degenerate for
## the goal of "articulation"

The available real corpus (`assets/FIRST/{AVATAR,IDLE}.RWG`,
`assets/WorldsPlayer/cachedir/*.bod`, and now also
`assets/gammatutorial-samples/{cube,ball,table}.rwg`) is real — not
invented — but:

- **The 5 real `.rwg` files available (`AVATAR.RWG`, `IDLE.RWG`, and the 3 of
  `assets/gammatutorial-samples/`: `cube.rwg`, `ball.rwg`, `table.rwg`)
  have exactly a single `ATOM` each** (verified by counting the tag
  in the 5 files). None is an avatar properly speaking — they are
  single-clump tutorial props (a cube, a ball, a table) or
  placeholders. `AVATAR.RWG` is a degenerate cube using sentinels
  `Float.MAX_VALUE`/`-Float.MAX_VALUE` as vertices (0 polygons) — a
  placeholder, not real geometry. **None of the 5 demonstrates a real
  hierarchy of multiple joints** — which is precisely the declared goal
  of this session ("ARTICULATED avatars"). It was not possible to verify
  with real evidence how several `ATOM`s nest/reference each other
  to form a complete skeleton (pelvis→torso→neck→head...). What was
  achieved, on the other hand, was a solid verification of the static geometry
  of ONE clump (position, per-vertex normal, UV, polygons with face normal)
  against 4 of the 5 files, including a 6-face cube and a ball
  of 512 triangles — much more robust than the initial verification of
  a single polygon.
- **The 26 real `.bod` files of `cachedir/`** (confirmed with
  `PendingDrone.java:91` that they are indeed avatars downloaded from
  `AvatarUpgrades/<name>.zip`, not animations — see the BOD section further
  below) probably DO contain real articulation (they are larger,
  2-10KB vs. the ~750-1050 bytes of the trivial .rwg files) — but they use
  a **completely different** binary encoding, with no recognizable ASCII
  tag, and their structure could not be deciphered with the evidence and
  time available this session.

**Honest conclusion**: what follows in this document is a SOLID and VERIFIED
reconstruction of the geometry of a single clump/ATOM in `.rwg` format
(vertex position + polygons) — useful and reusable — but it **does not
constitute a complete solution to the "articulated avatar" problem**,
because the real corpus did not allow verifying the bone hierarchy with
evidence. Implementing it ANYWAY would have meant inventing the hierarchy
part without evidence, violating the project's verification principle — it
was decided to document the real limit instead of filling the gap with an
assumption.

---

## External research (subagent, summary)

- **aw-sequence-parser** (Blaxar): UNRELATED format — file magic
  `[0x7f,0x7f,0x7f,0x79/0x7a]`, no 4-letter ASCII tags, it is
  for `.seq` animations (quaternion per frame), not static geometry.
  It confirms big-endian (matches what is seen in the real bytes of
  `.rwg`), but nothing else applicable.
- **Standard RenderWare Binary Stream** (the one documented by
  kaitai-struct/gtamods.com, used by GTA and derivatives): uses **little-endian
  numeric section IDs**, NOT ASCII tags, and is
  **little-endian** — the opposite of what is observed in the real bytes
  of `.rwg` (literal ASCII tags such as "CLUM"/"ATOM", big-endian).
  **Evidence that the Worlds.com binary is NOT the same "standard" binary RW
  format documented for RenderWare 3.x/GTA** — it may be a proprietary variant
  of RenderWare 2.x (earlier, with no known public documentation) or a format
  entirely proprietary to Worlds Inc.
- **kangworlds.net** and the Worlds Chat wiki: confirm joint names
  (Pelvis→Torso→Neck→Head, Hip→Knee→Ankle,
  Shoulder→Elbow→Wrist) — matches the EXACT names found in
  GammaDocs (see below), but with no binary format detail.

---

## Official source: `Gamma_Advanced.html` (GammaDocs), section "Articulated
## Avatars" (real Worlds Inc. documentation, not third-party)

Facts confirmed verbatim in the official documentation:

- **`.bod` is generated from `.rwx` with the `rwxtobod` tool** (e.g.
  `rwxtobod amy` → `amy.bod` from `amy.rwx`). The source `.rwx` must use Y
  as the height axis, 1 unit = 10 meters (ActiveWorlds convention).
- **Clump hierarchy required in the source `.rwx`**, each one
  identified by a comment `# name` (3DS Max exporter convention), with a
  code letter for the "custom avatar language":
  `P pelvis, B back, N neck, H head, L lfshoulder, M lfelbow, O lfwrist,
  R rtshoulder, U rtelbow, V rtwrist, I lfhip, J lfknee, K lfankle,
  W rthip, X rtknee, Y rtankle, Z tail`.
- **Tag numbers** (used in the avatar name language, `G` command):
  pelvis=1, back=2, neck=3, head=4, rtsternum=5, rtshoulder=6,
  rtelbow=7, rtwrist=8, rtfingers=9, lfsternum=10, lfshoulder=11,
  lfelbow=12, lfwrist=13, lffingers=14, rthip=15, rtknee=16, rtankle=17,
  rttoes=18, lfhip=19, lfknee=20, lfankle=21, lftoes=22, back2=23,
  tail=24, mouth=25, nose=26, lfear=27, rtear=28, back3=29, tail2=30,
  tail3=31, tail4=32.
  - ⚠️ Possible unconfirmed lead: in the real `.rwg` files, the value `23`
    (=0x17) appears as a constant in ALL the RALT/TELT/MALT/
    PLST sections of both test files — coincidentally `back2=23` in this
    table. It could be a coincidence (both files are a single clump with no
    explicit tag) or it could be a real tag field set to a
    default value. **It could be neither confirmed nor ruled out** — neither of
    the 2 test files uses a tag other than 23 to compare.
- **"All joint matrices must be identity matrices, since the system
  overwrites them internally when animating"** — matches EXACTLY
  what was observed: both `MATX` of each `ATOM` in both files are
  4x4 identity matrices (16 floats, see below).
- The minimal valid avatar is just the `pelvis` clump (the others are
  optional, but an intermediate one cannot be skipped).
- `.bod`, at the time this official documentation was written (~2000-2001),
  "are not currently loadable over the network" — **but the real
  decompiled Java code confirms that in a later version they ARE**
  (`PendingDrone.java`, see below) — the official doc may be out of
  date with respect to the real build we have, or "loadable over the network"
  referred to a different route (direct reference in a world URL) as opposed
  to the "avatar update package" mechanism that does exist in the real
  client.

---

## What the decompiled Java client confirms (without parsing the format
## itself — important)

- `PendingDrone.java` downloads avatars as
  `AvatarUpgrades/<name>.zip` from the upgrade server, extracts the zip, and
  copies any `.bod`/`.seq`/`.dat`/`.cmp`/`.mov` file to
  `avatars/`. It confirms that **`.bod` is real avatar geometry, `.seq` is
  animation — two different things**, and that the 26 real `.bod` files of
  `cachedir/` (obfuscated cache names like `3.bod`, `33.bod`) are indeed
  genuinely downloaded avatars.
- **No avatar-related class
  (`PosableDroneLoader`/`DroneLoader`/`PosableDrone`/`PosableShape`) has
  `native` methods of its own or parses the binary `.rwg`/`.bod` in Java** —
  it matches what we already knew about RWX/RenderWare (section 2 of the
  master document): the real loading of 3D geometry goes through native
  RenderWare (`gamma.dll`/RenderWare DLLs), not through Java code. This
  confirms that, just as with RWX, **there is no shortcut in the decompiled
  code** — the only way is to reconstruct the format from the bytes.

---

## `.rwg` format: chunk structure (VERIFIED with real hex dumps)

### Container
- Magic: 4 literal ASCII bytes **`"ZZZ["`** (`5A 5A 5A 5B`).
- Then a 4-byte big-endian field giving the **length of the variable
  header block** that follows.
- Header block: 4 constant bytes `13 76 53 42` (the same in both
  test files — ⚠️ VERIFY what exactly it is: version? secondary
  magic?) + 4 bytes `00 00 00 01` (also constant, ⚠️ VERIFY) +
  an **ASCII string with the name of the object**, zero-padded
  (`AVATAR.RWG` has an empty 4-byte name; `IDLE.RWG` has
  `"idle\0\0\0\0"`, 8 bytes). The size of this name field =
  `header_length - 8`.
- From there on: nested chunks, each
  `[4-byte ASCII tag][4-byte big-endian length = exact size
  of the payload, does NOT include the length field itself][payload]`.
  **Mathematically verified**: adding up the header + each top-level chunk
  with this convention, the final offset matches EXACTLY the real size of the
  file in both test files (748 and 1056 bytes).

### Chunks found, in order, inside a `CLUM` (top level)

| Tag | Verified contents | Status |
|---|---|---|
| `RALT` | A `STRT` with 3 integers of 4 bytes: `[0, 0, 23]` in both files | ⚠️ VERIFY purpose — only 12 bytes of purely numeric data, no text or geometry |
| `TELT` | `STRT` of `[?, N, 23]` + extra data. **Finding**: in IDLE.RWG the extra data contains a nested sub-chunk `STNG` (`53 54 4E 47`) = `[length=8]["idle\0\0\0\0"]` — the string **is literally "idle", the same object name** that already appears in the file header. Possibly a table of names/labels (Texture ELemenT? STring tag?). In AVATAR.RWG (empty name) the STRT of TELT is `[0,0,23]` and there is no extra data — consistent with "no name → no STNG". | ⚠️ VERIFY the exact meaning of TELT, but the sub-chunk STNG = name is well evidenced |
| `MALT` | `STRT` of `[?, N, 23]` + extra data: in IDLE.RWG, 5 floats `[0.969, 0.984, 0.969, 1.0, 0.75]` followed by 2 zeros. It could be a bounding box/scale or a color — values in the range [0,1] suggest RGB color plus something, but 5 values do not fit cleanly into RGB(A). | ⚠️ VERIFY — not enough data to confirm |
| `ATOM` | The actual content: a joint/segment with transform + geometry | ✅ Internal structure verified, see below |
| `PLST` (sometimes it also appears outside, as in the top-level AVATAR/IDLE) | Polygon list, see below | ✅ |

The constant "23" (`0x17`) in RALT/TELT/MALT/PLST could coincide with the
`back2=23` tag of the official GammaDocs table — **unconfirmed
coincidence**, see the note above.

### `ATOM` (a joint/segment — the best-understood part of the format)

1. **Its own `STRT`, 52 bytes = 13 integers of 4 bytes.** First two
   values in both files: `[1, 4, ...]`. The rest varies. ⚠️ VERIFY the
   exact meaning of each field — they were decoded as integers and as
   floats but no interpretation gave a signal as clear as that of
   `VLST`/`PLST` (see below). Possible: child counter, flags, tag
   number of the joint (related to the official table above).
2. **Two `MATX` blocks, each with a 64-byte `STRT` = 16 floats =
   a 4x4 matrix.** **Verified: in both files, both matrices are
   the identity matrix** (`1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1`) —
   matches EXACTLY the official documentation ("all joint matrices
   must be identity, the system overwrites them when animating").
   The matrix layout (row-major vs column-major) **could not be
   determined** with an identity matrix, which is the same in both
   conventions — ⚠️ VERIFY with a real file that has a
   non-identity matrix (neither of the 2 available has one).
3. **`VLST`** (vertex list) — **the best-verified part of the whole
   format**:
   - Its own 12-byte `STRT` = 3 integers: `[vertex_count,
     bytes_per_vertex, 23]`. **Mathematically verified in both
     files**: `count × bytes_per_vertex` matches exactly the rest
     of the `VLST` payload (8×44=352 in AVATAR, 12×44=528 in IDLE).
   - Each vertex record = **44 bytes = 11 big-endian floats**.
     - **Floats[0:3] = position (x, y, z)** — verified with very high
       confidence: in `AVATAR.RWG` the 8 vertices are exactly the 8
       corners of a cube using the sentinels `Float.MAX_VALUE`/
       `-Float.MAX_VALUE` (0x7F7FFFFF/0xFF7FFFFF) — an "uninitialized
       bounding box" pattern, confirming that it is a placeholder with no
       real geometry. In `IDLE.RWG` they are small, coherent coordinates
       (±0.4, 0/-0.8) forming a plane — plausible dimensions for an
       avatar (units ~ meters/decimeters).
     - **Floats[3:6) = per-vertex normal (nx, ny, nz)** — ✅ solved with
       `cube.rwg` (a real 6-face/32-vertex cube): for each of the
       6 faces, the 4 vertices of that face share the same ±1.0 axis in
       this position, and it matches exactly the face normal
       verified in `PLST` (see below). Before having `cube.rwg`
       this had been wrongly marked as "undetermined" (with only
       IDLE.RWG available, a single quad, "normal" could not be distinguished
       from "boolean flag").
     - **Floats[6:8] appear to be texture UVs** — in `IDLE.RWG` and
       `cube.rwg`, the vertices "duplicated" per face (the classic pattern of
       "vertex duplicated per UV seam", the same as was seen in RWX
       this same session) have values such as `0.0039` and `0.9961` in
       these positions — it matches the typical pattern of UV coordinates
       at the edges of a texture (≈0 and ≈1 with a slight margin of
       quantization). **Medium-high confidence, not absolute.**
     - **Floats[8:11]: undetermined.** Always zero in the 5 test files
       available — no evidence of what they represent
       (possibly reserved, or a skinning field that no real test file
       exercises because none has more than one joint).
4. **`PLST`** (polygon list) — ✅ **general structure solved and
   verified against the 5 real files** (`AVATAR.RWG` with 0
   polygons, `IDLE.RWG` with 1 quad, `cube.rwg` with 6 quads, `ball.rwg`
   with 512 triangles, and `table.rwg` with 546 polygons of mixed type):
   - Its own 12-byte `STRT` = 3 integers: `[polygon_count,
     field2, field3]`. Neither of the last two is constant across
     files: `field2` is 36 in AVATAR/IDLE but 32 in cube/ball/table;
     `field3` is 23 in AVATAR/IDLE but **7** in cube/ball/table (it was
     documented earlier as "always 23" with only 2 files of evidence —
     corrected on re-verifying against the remaining 3 this session). ⚠️
     VERIFY its exact meaning (it could be related to the record
     size, but it does not match cleanly the real bytes of any
     file).
   - **Each polygon record = `[id/flag][vertexCount][vertexCount
     1-based indices][trailing fields]`.** The first field was documented
     initially as "flag, always 1" (true in AVATAR/IDLE/cube, which
     only have 0/1/6 records) but it is **not constant**: in
     `ball.rwg` (512 records) it counts 1..512, one per polygon — it is
     some kind of id/counter per record, not a boolean. The parser
     (`RwgParser.parsePlst`) no longer validates it, it just discards it.
   - **The first 3 trailing fields = face normal (nx, ny, nz)** — ✅
     confirmed with very high confidence in `cube.rwg`: its 6 records
     (one per face) each have a single axis at `~±1.0000863` (not
     exactly 1.0 — a rounding error typical of an export from 3DS
     Max) and the other two axes at 0, and **all 6 possible axes appear
     exactly once each** — it cannot be a coincidence.
     Also verified indirectly in `ball.rwg` (non axis-aligned normals,
     coherent with a triangulated sphere) and `IDLE.RWG`
     (normal `(0,0,~1.0)`, which matches its only quad facing +Z).
   - **The exact number of trailing fields VARIES between files** — 6 in
     `cube.rwg`/`ball.rwg` but 7 in `IDLE.RWG` (an extra unexplained
     padding field). The parser (`RwgParser.parsePlst`) solves it by
     computing the record size by dividing the total payload by
     the number of polygons — it works because every `PLST` observed so
     far has a uniform `vertexCount` for all its records.
   - ✅ **`table.rwg` SOLVED (articulated-avatar session,
     2026-09-09)**: the assumption of "uniform record size derived
     by division" was never needed — each record ALREADY declares its own
     `vertexCount` in the second field, which is read directly without
     assuming anything. The only thing that needed solving was the number of
     trailing ints after the indices, which IS constant,
     but per file, not per record (6 in `cube.rwg`, 6 in `ball.rwg`,
     7 in `IDLE.RWG`). `RwgParser.resolvePlstTrailingCount()` now tries
     small candidates (0..16) and keeps the one that makes reading the
     `polyCount` records — using the real `vertexCount` of each one,
     without assuming uniformity — end exactly at the final byte of the
     `PLST`. With this, `table.rwg` (546 polygons, a real mix of
     triangles and quadrilaterals confirmed byte by byte, e.g. records 541-544
     have 4 indices and 545 has 3) resolves `trailingCount=6` and parses
     cleanly — additionally verified by rendering the result
     (`RwgViewer`, see
     `docs/renders/rwg_table_fixed.png`): a coherent table (circular
     top + crossed legs), not geometric garbage.
   - **Side effect, important correction**: the first field of each
     `PLST` record, documented until now as "`flag`, always
     1", is **NOT constant** — on re-verifying against the real bytes of
     `ball.rwg` (512 records) it turned out to be a 1..512 counter, one per
     polygon, not a boolean. `cube.rwg`/`IDLE.RWG` do have it fixed at
     1 (with only 6 and 1 records respectively it was not enough to notice the
     pattern). The parser no longer validates or depends on this field — it reads it and
     discards it. Real meaning: unknown (polygon id?
     smoothing group?) — no interpretation was invented without evidence.
   - ✅ **Verified by real rendering** (`RwgViewer.java` +
     pixel inspection): the 4 indices `[0,1,2,3]` of the quad of
     IDLE.RWG are in **grid order** (0=top-left, 1=top-right,
     2=bottom-left, 3=bottom-right), NOT in perimeter loop order. A naive
     fan-triangulation `(0,1,2)+(0,2,3)` produced a visibly incorrect
     concave "chevron"; the correct triangulation for 4
     vertices in this order is `(0,1,2)+(1,3,2)` ("strip" order), which
     did produce a solid flat rectangle — confirmed by a real screen
     capture. ⚠️ VERIFY with more real quads whether this ordering
     convention always holds, or whether it is specific to how the
     3DS Max exporter (mentioned in GammaDocs) emits quads.
   - ✅ **Also verified with the full `cube.rwg` and `ball.rwg`**
     (`docs/renders/cube_rwg_3d.png`, `docs/renders/ball_rwg_3d.png`): the
     real cube renders as a recognizable 3D cube from an angle
     (3 visible faces, correct silhouette) and the ball as a
     faceted sphere — both using only the data that comes out of the parser
     (position + indices), with no manual per-file adjustment.

---

## `.bod` format: NOT solved this session

Confirmed with evidence (not assumed):
- 4-byte magic **constant and identical in all 26 real files**:
  `01 10 01 00`, followed by 2 more bytes that are also constant `00 02` — a
  fixed 6-byte header, **completely different** from the `"ZZZ["` of
  `.rwg`.
- No recognizable ASCII tags at any point in the files
  inspected — it is not the same chunk scheme.
- After the header, the bytes do not follow any obviously sensible pattern of
  32-bit integers or floats in the first few hundred bytes
  inspected — it could be a delta/compressed encoding (which would make
  sense given that `.bod` is distributed over the network, where bandwidth
  mattered in 1999-2004) or a variable-size record format.
- **No external reference or logic was found in the decompiled Java
  client that reveals the exact layout** (see above: the real loading
  happens in native RenderWare, out of our reach without
  disassembling the DLLs).

**Logical next step to solve `.bod`** (not attempted this session,
bigger effort): disassemble with Ghidra the function of `gamma.dll` that
reads `.bod` files (we already have Ghidra installed and used in earlier
sessions for `gamma.dll`) — it is reverse-engineering work at the level of
x86 ASM, more like what was done to map the `native` methods
than like "continuing to read bytes with more patience".
