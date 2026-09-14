# Nativo decompilado (`gamma.dll`)

C decompilado con Ghidra 12.1.3 (headless) de la `gamma.dll` ORIGINAL
de 2004 (`assets/WorldsPlayer/bin/gamma.dll`, 613 KB) — el puente JNI
del cliente y todo su codigo nativo: `DroneAnimator` (animacion de
avatares `.seq`), `huffdcod`/ScapePic (texturas `.cmp`/`.mov`),
`Transform`, `PendingCacheDrone`, etc.

- `gamma_dll/`: 1656 funciones (`<addr>_<nombre>.c`, 0 fallos) +
  `INDEX.txt` (addr, fichero, nombre). Los exports JNI conservan su
  nombre real (`_Java_NET_worlds_...`).
- Regenerable: `tools/ghidra-scripts/ExportAllDecompiled.java` +
  `analyzeHeadless` (el proyecto Ghidra vive fuera del repo,
  `~/ghidra-fw`, ver `.gitignore` de `analysis/`).
- Este C es salida del decompilador (no compila tal cual): fuente de
  ingenieria inversa versionable, no un build. Cada fichero cita su
  direccion para cruzar con Ghidra.

Java decompilado (pristino, Vineflower 1.12 + patch de compilacion):
`editor/worldsplayer_source_editor-main/source/` (723 `.java`, 0
`NativeMock`, declara los `native` que este C implementa).
