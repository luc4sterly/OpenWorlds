# kcl.mov

Animated kaleidoscope from the avatar dressing room (used by `Rect931` of
DressingRoom): 128×128, 8 frames.

- Origin: `http://us1.worlds.net/3DCDup/avatar/kcl.mov` (LibreWorlds
  mirror), requested by the client when entering DressingRoom.
- 42,099 bytes, SHA-256 `b159f2c1baa2a2bd67d0f563c2299ec05b504830451cca2fd3f42b19f63392e1`.

It is the only known file with **header byte 13 different from 0**
(it is 4) and with the 0x40 bit of the mode (`0xc2`). With byte 13 different
from 0, gamma.dll skips `(byte13·18+7)>>3` bytes in the tables region **and
also the number of colors** (0x442963..0x442983, in FUN_00442750). The reader
only skipped the former: with 256 colors it was off by 256 bytes, read "256
frames" and crashed while building the Huffman tables
(`CmpStage1.buildFromLengths`, index 1408 of 256). The 0x40 bit is not looked
at by the constructor.

With the full skip: a table of 1,190 bytes + 8 entries of 20 bytes, so the
first frame starts at 34 + 1,190 + 160 = 1,384. The 8 groups are contiguous,
the last one ends at 42,099 (the size of the file) and each one consumes
exactly its streams.

It is checked by `formats/test/net/openworlds/cmp/CmpGroupsCheck.java`.
