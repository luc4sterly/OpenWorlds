# mug.cmp

Hologram of the mug from the diner in The Blair Witch World
(`TheBurkittsvilleDiner`, 2000-2001).

- Origin: `http://us1.worlds.net/3DCDup/TheBurkittsvilleDiner/TheBurkittsvilleDiner14.exe`
  (a Wise package of 1,103,334 bytes that the LibreWorlds mirror serves today),
  `content.zip` → `tex/mug.cmp`.
- 4,688 bytes, SHA-256 `8e2aea9543a7321a4f35115fc5be7dea6f89a3c2daac3faf729eebf435303ad3`.

It is the first sample with **two groups of rows in a single frame**
(FUN_00442bc0): 213×233, 117 row pairs split into 76 + 41. The frame table
gives the first group (offset 943, 2,071 bytes), and its header gives the
size of the second (1,674). 943 + 2,071 + 1,674 = 4,688, the exact end of
the file. Each group consumes exactly its five streams. Before, only the
first group was decoded: past row 152 the zero padding was read, `CmpStage2`
stopped at the `idx == 0` case and the game said
"Unable to load hologram: rel:home:theburkittsvillediner/tex/mug.cmp".

The header carries 255 colors (byte 12), so index 255 is not in the
palette and is the hologram's transparent one: the four corners use it.

It is checked by `formats/test/net/openworlds/cmp/CmpGroupsCheck.java`.
