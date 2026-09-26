# Nativo decompilado: todos los binarios propios del juego

C decompilado con Ghidra 12.1.3 (headless), 0 fallos en todos:

| Carpeta | Binario | Funciones | Por vtable | Qué es |
|---|---|---|---|---|
| `gamma_dll/` | `bin/gamma.dll` (613 KB) | 2537 | 881 | puente JNI del cliente y sus códecs (`.seq`, `.cmp`/`.mov`) |
| `rwl21_dll/` | `bin/RWL21.DLL` (389 KB) | 1152 | 21 | RenderWare 2.1, el motor (795 con nombre real de la API) |
| `rwdl6d21_dll/` | `bin/RWDL6D21.DLL` (578 KB) | 411 | 26 | driver de RenderWare de 16 bits: el rasterizador que traduce el puente |
| `rwdl8d21_dll/` | `bin/RWDL8D21.DLL` (560 KB) | 427 | 33 | driver de RenderWare de 8 bits (paleta), DirectDraw |
| `rwdlmd21_dll/` | `bin/rwdlmd21.dll` (653 KB) | 435 | 28 | driver de RenderWare con MMX (120 `emms`, `cpuid`), DirectDraw |
| `rwdldd21_dll/` | `bin/RWDLDD21.DLL` (252 KB) | 305 | 2 | driver de RenderWare DirectDraw (`DirectDrawEnumerateA`) |
| `run_exe/` | `run.exe` (49 KB) | 139 | 0 | el lanzador de 2004: busca el Java y arranca `NET.worlds.console.Gamma -home . -dllpath bin` (lo que gdkup reinicia con `run.exe world:restart`) |
| `gdkup_exe/` | `bin/gdkup.exe` (42 KB) | 256 | 9 | el actualizador (`\GAMMA\network\gdkup`): ejecuta `updates.lst` línea a línea y reinicia el cliente; traducido en `bridge/.../GdkUp.java` |
| `sfmain_exe/` | `sfmain.exe` (315 KB) | 619 | 51 | el chat de voz (SpeakFreely con GSM, `\GAMMA\speakfre`), compilado con Watcom |

"Por vtable" son las funciones a las que solo se llega por tablas de
punteros, que Ghidra no ve como función (abajo). `tools/ghidra-scripts/decompile-all.sh`
regenera todo menos `gamma_dll/`, que se hizo antes con los mismos dos
scripts.

Lo que queda en `assets/WorldsPlayer` sin decompilar es de terceros, no del
juego:

- **Java de Sun 1.4.2_05** que traía el instalador: `java.exe`,
  `javaw.exe`, `awt.dll`, `java.dll`, `net.dll`, `nio.dll`, `zip.dll`,
  `jpeg.dll`, `fontmanager.dll`, `jsound.dll`, `jawt.dll`, `verify.dll`,
  `hpi.dll`, `hprof.dll`, `jdwp.dll`, `jcov.dll`, `rmi.dll`, `ioser12.dll`,
  `jaas_nt.dll`, `w2k_lsa_auth.dll`, `dt_shmem.dll`, `dt_socket.dll`,
  `cmm.dll`, `dcpr.dll`, `JdbcOdbc.dll`, y el plug-in de Java
  (`jpi*.dll`, `jpins*.dll`, `NPJava*.dll`, `NPJPI142_05.dll`,
  `NPOJI610.dll`, `axbridge.dll`, `eula.dll`, `RegUtils.dll`). El puente
  sustituye a todo esto con un Java moderno.
- `msvcrt.dll` (runtime de C de Microsoft).
- `xdelta.exe` y `glib-1.2.dll`: xdelta 1.x (GPL, con código fuente
  publicado), para los parches incrementales `%XDZ` de los mundos viejos.
  No está traducido: `GdkUp` da esos parches por no aplicables.
- `UNWISE32.EXE`: el desinstalador de Wise.

## Esta sesión (2026-09-26)

- **Ghidra 12.1.3** desde el espejo de SourceForge
  (`https://sourceforge.net/projects/ghidra.mirror/files/Ghidra_12.1.3_build/ghidra_12.1.3_PUBLIC_20260817.zip/download`),
  porque la descarga de GitHub la corta el proxy de la nube. SHA-256
  comprobado contra el del README de la versión:
  `93a5d11a9ad510622acaaf908c556a7b9b764d338e78a7567f3689bf5081fd54`. En
  Linux trae el decompilador nativo, así que no hay que compilarlo como en
  macOS Intel.
- `ScanVtablesAndExport.java` acepta además el bloque `DGROUP` de Watcom
  (`sfmain.exe` no tiene `.data`/`.rdata`). La comprobación de las 13
  entradas de la vtable del reproductor de animación solo se hace en
  `gamma.dll`.

## `gamma.dll`

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

`ScanVtablesAndExport.java` (2026-09-26): 28 candidatos, 21 funciones
nuevas, `INDEX.txt` pasa a 1152.

## `RWDL6D21.DLL` (driver RenderWare de 16 bits, 578 KB) — anadido 2026-09-19

`rwdl6d21_dll/`: **385 funciones, 0 fallos**. Es el rasterizador por
software real (el que el puente traduce en `NativeCamera.raster`), con
148 nombres reales, aunque muchos son del runtime de C (`__ftol`,
`__CRT_INIT`). Aqui vive lo que sigue pendiente en el puente: la division
de perspectiva por tramos de 16 pixeles y las tablas de color del driver.
`ScanVtablesAndExport.java` (2026-09-26): 26 funciones más, 411 en total.
