# Nativo decompilado (`gamma.dll`, `RWL21.DLL`, `RWDL6D21.DLL`)

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

## `RWL21.DLL` (RenderWare 2.1, 389 KB) — anadido 2026-09-19

`rwl21_dll/`: **1131 funciones, 0 fallos**, mismo script headless
(`tools/ghidra-scripts/ExportAllDecompiled.java`). Es el motor RenderWare
en si (el driver de 16 bits es `RWDL6D21.DLL`, aun sin volcar).

A diferencia de `gamma.dll`, la DLL **exporta sus simbolos**, asi que
**795 de las 1131 salen con su nombre real de la API** (`RwGetPolygonMaterial`,
`RwSetPolygonMaterial`, `RwDestroyPolygon`...) y solo 336 quedan como
`FUN_<addr>`. Eso hace el cruce con el puente mucho mas directo que en
`gamma.dll`.

Desbloquea lo que `editor/.../bridge/README.md` marcaba como pendiente por
no tener el binario: el recorrido BSP de clumps (`FUN_1002cae0`), el arbol
de ordenacion de poligonos por clump (`FUN_10033750`), el rasterizador
Gouraud (`FUN_100259e0`) y la iluminacion del driver (`FUN_1000d230`).

Reproducir (JDK portable del repo; sin `JAVA_HOME` el lanzador de Ghidra
aborta con "Unable to prompt user for JDK path"):

```
JAVA_HOME=tools/jdk/Contents/Home \
ghidra_*/ghidra_*/support/analyzeHeadless <projdir> RWL21 \
  -import assets/WorldsPlayer/bin/RWL21.DLL \
  -scriptPath tools/ghidra-scripts \
  -postScript ExportAllDecompiled.java decompiled-native/rwl21_dll
```

No se ha pasado aun `ScanVtablesAndExport.java` (el que en `gamma.dll`
saco 881 funciones mas alcanzables solo por vtable).

## `RWDL6D21.DLL` (driver RenderWare de 16 bits, 578 KB) — anadido 2026-09-19

`rwdl6d21_dll/`: **385 funciones, 0 fallos**. Es el rasterizador por
software real (el que el puente traduce en `NativeCamera.raster`), con
148 nombres reales, aunque muchos son del runtime de C (`__ftol`,
`__CRT_INIT`). Aqui vive lo que sigue pendiente en el puente: la division
de perspectiva por tramos de 16 pixeles y las tablas de color del driver.
