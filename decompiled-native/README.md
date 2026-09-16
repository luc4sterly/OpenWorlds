# Nativo decompilado (`gamma.dll`)

C decompilado con Ghidra 12.1.3 (headless) de la `gamma.dll` ORIGINAL
de 2004 (`assets/WorldsPlayer/bin/gamma.dll`, 613 KB) — el puente JNI
del cliente y todo su codigo nativo: `DroneAnimator` (animacion de
avatares `.seq`), `huffdcod`/ScapePic (texturas `.cmp`/`.mov`),
`Transform`, `PendingCacheDrone`, etc.

- `gamma_dll/`: 1656 funciones (`<addr>_<nombre>.c`, 0 fallos) +
  `INDEX.txt` (addr, fichero, nombre). Los exports JNI conservan su
  nombre real (`_Java_NET_worlds_...`).
- ⚠️ **El volcado NO es exhaustivo** (auditoría 2026-09-15): faltan las
  funciones que solo se alcanzan por despacho virtual, porque Ghidra no
  las detecta como funciones. Caso comprobado: las 13 entradas de la
  vtable del reproductor de animación (`0x00475200`: `0x00432010`,
  `0x00431e90`, `0x00432020`, `0x00432070`, `0x00432090`, `0x004320b0`,
  `0x00432550`, `0x00432790`, `0x004327b0`, `0x00432800`, `0x00432820`,
  `0x00432830`, `0x00432840`) no están en `INDEX.txt`, y son justo las
  del avance de tiempo, el bucle y las transiciones de animación. Para
  completarlo hay que forzar función en las direcciones de las tablas de
  punteros a `.text` antes de exportar.
- Regenerable: `tools/ghidra-scripts/ExportAllDecompiled.java` +
  `analyzeHeadless` (el proyecto Ghidra vive fuera del repo,
  `~/ghidra-fw`, ver `.gitignore` de `analysis/`).
- Este C es salida del decompilador (no compila tal cual): fuente de
  ingenieria inversa versionable, no un build. Cada fichero cita su
  direccion para cruzar con Ghidra.

Java decompilado (pristino, Vineflower 1.12 + patch de compilacion):
`editor/worldsplayer_source_editor-main/source/` (723 `.java`, 0
`NativeMock`, declara los `native` que este C implementa).
