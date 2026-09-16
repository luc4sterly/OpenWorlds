# Nativo decompilado (`gamma.dll`)

C decompilado con Ghidra 12.1.3 (headless) de la `gamma.dll` ORIGINAL
de 2004 (`assets/WorldsPlayer/bin/gamma.dll`, 613 KB) — el puente JNI
del cliente y todo su codigo nativo: `DroneAnimator` (animacion de
avatares `.seq`), `huffdcod`/ScapePic (texturas `.cmp`/`.mov`),
`Transform`, `PendingCacheDrone`, etc.

- `gamma_dll/`: 1656 funciones (`<addr>_<nombre>.c`, 0 fallos) +
  `INDEX.txt` (addr, fichero, nombre). Los exports JNI conservan su
  nombre real (`_Java_NET_worlds_...`).
- **Funciones alcanzables solo por vtable** (añadidas 2026-09-16): el
  primer volcado (1656) no las incluía porque Ghidra no detecta como
  función un destino al que solo se salta por despacho virtual — entre
  ellas las 13 de la vtable del reproductor de animación (`0x00475200`),
  que resultaron ser el avance de tiempo y el bucle. El script
  `tools/ghidra-scripts/ScanVtablesAndExport.java` recorre las tablas de
  punteros a `.text` de `.data` (1216 candidatos), fuerza función donde no
  la hay y exporta solo las nuevas: **881 funciones más**, `INDEX.txt`
  pasa a 2537 entradas, sin tocar ningún fichero anterior. 268 candidatos
  caían dentro de otra función y se omitieron; no se ha auditado a fondo
  si alguno de los 881 es una jump-table en vez de una función.
- **Ghidra en macOS Intel**: esta distribución (12.1.3) no trae el binario
  nativo del decompilador para `mac_x86_64`; se compila desde el fuente
  incluido (`Ghidra/Features/Decompiler/src/decompile/cpp`, target
  `ghidra_opt`) con el `g++`/`bison`/`flex` de las Command Line Tools y se
  copia a `os/mac_x86_64/decompile`. Arranca con el JDK de `tools/jdk`.
- Regenerable: `tools/ghidra-scripts/ExportAllDecompiled.java` +
  `analyzeHeadless` (el proyecto Ghidra vive fuera del repo,
  `~/ghidra-fw`, ver `.gitignore` de `analysis/`).
- Este C es salida del decompilador (no compila tal cual): fuente de
  ingenieria inversa versionable, no un build. Cada fichero cita su
  direccion para cruzar con Ghidra.

Java decompilado (pristino, Vineflower 1.12 + patch de compilacion):
`editor/worldsplayer_source_editor-main/source/` (723 `.java`, 0
`NativeMock`, declara los `native` que este C implementa).
