# kcl.mov

Caleidoscopio animado del vestuario de avatares (lo usa `Rect931` de
DressingRoom): 128×128, 8 fotogramas.

- Origen: `http://us1.worlds.net/3DCDup/avatar/kcl.mov` (espejo de
  LibreWorlds), pedido por el cliente al entrar en DressingRoom.
- 42 099 bytes, SHA-256 `b159f2c1baa2a2bd67d0f563c2299ec05b504830451cca2fd3f42b19f63392e1`.

Es el único fichero conocido con el **byte 13 de la cabecera distinto de 0**
(vale 4) y con el bit 0x40 del modo (`0xc2`). Con el byte 13 distinto de 0,
gamma.dll salta en la región de tablas `(byte13·18+7)>>3` bytes **y además
el número de colores** (0x442963..0x442983, en FUN_00442750). El lector solo
saltaba lo primero: con 256 colores se descuadraba 256 bytes, leía "256
fotogramas" y se caía construyendo las tablas de Huffman
(`CmpStage1.buildFromLengths`, índice 1408 de 256). El bit 0x40 no lo mira
el constructor.

Con el salto completo: tabla de 1 190 bytes + 8 entradas de 20 bytes, así
que el primer fotograma empieza en 34 + 1 190 + 160 = 1 384. Los 8 grupos
son contiguos, el último acaba en 42 099 (el tamaño del fichero) y cada uno
consume exactamente sus flujos.

Lo comprueba `formats/test/net/freeworlds/cmp/CmpGroupsCheck.java`.
