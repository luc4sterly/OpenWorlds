# Avatar name language (`avatar:<base>.0<program>.rwg`)

Reconstructed from the client's decompiled Java,
`editor/worldsplayer_source_editor-main/source/NET/worlds/scape/PosableShape.java`
(abbreviated `PS`). The original client runs it with its own
`PosableShape`. The Java translation of this document
(`client/src/net/openworlds/avatar/`, with `AvatarNameMain --todos`) belonged
to the new engine and was removed along with it on 2026-09-26: it is in the
git history up to commit `8cd795d`.

## Origin of the tables

`permittedList`, `faceList`, `humanList`, etc. come from `tables/tables.dat`
(`ServerTableManager.java:99-245`): a big-endian `int32` with the length +
a payload with XOR chained over the ciphertext (`dec[i]=enc[i]^enc[i-1]`) →
UTF-8 text with blocks `private static String[] <n> = {...};`.
`assets/WorldsPlayer/tables/tables.dat`: VERSION 2, 12 tables,
permittedList 296 entries (148 pairs).

## Header (`createSubparts`, PS:1054-1090)

- `avatar:<base>.rwg` (no `0` after the dot): `<base>` is looked up in
  `permittedHash` (PS:1324-1335) and replaced by the encoded name;
  if it is not there, there is no program: 17 default limbs from `<base>.bod`.
- `avatar:<base>.0<program>.rwg`: the program is in the URL itself.
- Anything else: base `aura`, no program.

## Phase 1: `findStarts` (PS:636-687)

Walks the whole program. Each uppercase letter in limb position records
`starts[letter]` (the last occurrence wins). Inside the limb:

| token | effect in findStarts |
|---|---|
| `G` int name | skipped |
| `S` c c c | skipped (3 chars) |
| `Q` | no-op |
| `D` c | skipped (1 char) |
| `A` name | skipped |
| `T` int name | **texture material** → palette; an empty name inherits the last one (initially `<base>`) |
| `C` `_`L / `C` b64 b64 b64 | **color material** → palette |
| `[a-z0-9]` | skipped |
| other uppercase letter | end of limb, another one starts |
| any other character | truncates the program there |

Each `T`/`C` is rewritten in the string as `Q<'a'+index>` (PS:646-661):
the palette is **global and in order of appearance**, and the loose
lowercase letters of the original name are indices into that palette.

- Texture (`scanTexture`, PS:248-258): `n<=0` → `avatar:<x>.cmp`;
  `n>0` → `avatar:<x><n>s*.mov`. `Material.calcRes/loadTextures`
  (Material.java:265-325) interprets `<n>s*` as sub-image `n-1` of the
  file `<x>.mov`.
- Color (`readColor`, PS:294-315): `_`+letter → `colorTable[letter-'A']`
  (PS:37-65, 26 colors); out of range (e.g. `C__`) → `origMat`, which
  `getLimb` does not apply (the color of the `.bod` stays). Otherwise, RGB =
  `4*base64(c)` per component, base64 = `-0-9a-zA-Z+` (PS:69).

## Phase 2: 17 limbs (`getLimb`, PS:355-470; table PS:1094-1110)

| letter | tag | parent | | letter | tag | parent |
|---|---|---|---|---|---|---|
| P | 01 | (figure) | | R | 06 | B |
| B | 02 | P | | U | 07 | R |
| N | 03 | B | | V | 08 | U |
| H | 04 | N | | I | 19 | P |
| L | 11 | B | | J | 20 | I |
| M | 12 | L | | K | 21 | J |
| O | 13 | M | | W | 15 | P |
| Z | 24 | P | | X | 16 | W |
| | | | | Y | 17 | X |

`A C D E F G Q S T` are never instantiated: `E` is, in 147/148 names, the
block where the palette is declared.

Each limb: URL `avatar:<base><2-digit tag>.bod` (PS:361). The root uses
`<base>`; the rest inherit the `.bod` base of the parent (`Shape.getBodBase`,
Shape.java:270). The real file is `<base>.bod` and the tag is the part
number (`Shape.addRwChildren/getBodPartNum`, Shape.java:276-313).
Tokens inside the limb (over the rewritten string):

| token | effect |
|---|---|
| `G` n name | current node → `avatar:<name><n or tag>.bod`; an empty name → **the limb is discarded** (and its children lose the base) |
| `S` x y z | per-axis scale: `a..z` → `1-(k)*0.025615385`, `A..Z` → inverse, other → 1; `SZZZ` disables prepFigure (PS:386-393) |
| `Q` | no-op |
| `D` c | delay += `1000*(1.0932^b64(c) - 0.9)` ms |
| `A` name | animation name |
| `[a-z]` | palette material for the current node; if there was already one, timed changes are scheduled (default delay 50 ms) → facial expressions (PS:410-433, 472-492) |
| digits | new `SubclumpShape` `system:subclump<n - subclumps already created>` (relative because `extractSubclump` keeps extracting parts, Shape.java:286-301) |
| other uppercase letter | end of limb |
| leftover `T`/`C` | "Illegal av" / assert (does not happen in the corpus) |

Example `willy`: `C__`×6 (origMat over the whole body) and the head
`HDgT2willyT3T2T1`: face `willy.mov` sub-image 0 at rest with a blink
2-3-2-1 every 3648 ms (+50 ms per frame).
`avatar:aura.0PG.rwg` (default URL): `G` without a name discards the root
and, in cascade, all the limbs → empty figure.

## Verification against the corpus (permittedList, 148 names)

- 146/148 without anomalies; 0 exceptions. The 2 anomalies are real typos
  in the table, reproduced as the client treats them:
  - `achoo`: a space after `T4achoo` → `findStarts` truncates; the avatar
    ends up with no materials on its limbs.
  - `tas`: `Lh`/`Mh` reference material 7 with a palette of 7
    (a..g) → `getMat` returns null and it is not applied.
- Limbs instantiated: 2514/2516; `craig` U and V discarded (`G` without a
  name in `RGUGVG`; the later R overwrites the start of R).
- Palette: 2132 materials; 387 `origMat` colors.
- Textures referenced (distinct files): 210; in the repo 14
  (`aggie aura axel barbra chloe death dude john monster ogre shanubia
  sonya tina willy .mov`, all in base-avatars); 196 are missing.
- `.bod` files referenced: 141; in the repo 25 (those of base-avatars);
  116 are missing.
- `cachedir/` cannot be attributed by name: `cache.index` is missing,
  so the numbered files do not count as present.

## Limits

- Sub-image `n-1` of a `.mov`: `CmpFrames` decodes all the frames through
  the frame table of gamma.dll (2026-09-25); before, only frame 0
  (`CmpStage1.decodeMovFrame0`). Tested at 128×128 on willy/aura/tina.
- `faceList`/`getFace` and `humanList`/`getHuman` are used by `WearWall` and
  `AvMenu` (customization) and by the substitution by a human; they are not
  used by `createSubparts`, so they do not affect the geometry/material of
  the name.
- That part N of the `.bod` and its UV fit the resolved sub-image was only
  seen on `willy`, with the new engine's viewer (2026-09-16, now
  retired): the face falls upright and on the front of the head.
  `ogre` asks for sub-image 3 of its `.mov` on 10 parts.
- ⚠️ With a texture the client sets `colorTable[3]` as the base color; whether
  RenderWare 2 tints the texture with it has not been verified.
