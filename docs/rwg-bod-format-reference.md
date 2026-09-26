# Referencia del formato RWG/BOD, reconstruida desde bytes reales

> **2026-09-26:** el motor nuevo se quitó del repositorio. Sus visores
> (`RwgViewer`, `BodViewer`) y las capturas de `docs/renders/` que se citan
> abajo están en el historial de git, hasta el commit `8cd795d`.
> `RwgParser` y el lector de `.bod` siguen en `formats/`, porque los usa el
> puente del cliente original.

⚠️ **A diferencia de RWX, no existe ninguna biblioteca ni documentación
externa que documente el formato binario exacto de `.rwg`/`.bod`** —
confirmado con investigación real, no asumido (ver sección "Investigación
externa" más abajo). Todo lo de aquí viene de: (1) hex dumps de archivos
reales del proyecto, (2) `Gamma_Advanced.html` (documentación OFICIAL de
Worlds Inc., sección "Articulated Avatars" — aportada por el usuario en
esta sesión como parte de `GammaDocs.zip`; la documentación completa NO
está versionada en este repo por su volumen — ver sección 3.4 de
`docs/worlds-chat-project.md` para los mirrors públicos conocidos:
`archive.org/details/gammadocs`, Worlio, Wayback Machine — los hechos
citados aquí están parafraseados/entrecomillados con atribución, así que
no hace falta el HTML completo para verificarlos), y (3) el código Java
decompilado del cliente real (que confirma qué NO hace el propio
cliente, ver más abajo). **No se inventó ningún dato** — donde la
evidencia es insuficiente está marcado ⚠️ VERIFICAR explícitamente, no
rellenado con suposiciones.

> **Correcciones de la auditoría 2026-09-15 — prevalecen sobre el texto
> histórico de abajo:**
>
> 1. **`VLST[0..7]` no son vértices: son las 8 esquinas de la bounding
>    box local del clump**, y los índices 1-based de `PLST` cuentan a
>    partir del registro 8. Evidencia: en `RWL21.DLL`,
>    `RwGetClumpNumVertices` (0x10003fe0) devuelve count−8 y
>    `RwGetClumpVertex` (0x100319f0, helper 0x10041c90) direcciona el
>    registro n+7; en los 8 `.rwg` del repo las 8 primeras entradas son
>    exactamente la bbox del resto (error 0), y contando desde 8 la normal
>    geométrica en orden de abanico coincide con la normal de cara de
>    `PLST` en 3466/3466 polígonos (167 si se cuenta desde 0).
>    Consecuencias: `cube.rwg` tiene 24 vértices (no 32), `e3.rwg` 1371
>    (no 1379); `AVATAR.RWG` no es "un cubo de centinelas" sino un clump
>    vacío con bbox ±FLT_MAX; el "orden de rejilla" de los quads, las
>    "normales (0,0,0)" y el "bobinado inconsistente" de `cube.rwg` eran
>    efectos del mismo error: los polígonos son lazos convexos (abanico) y
>    el bobinado es consistente. Corregido en `RwgParser` (commit
>    `1cc135b5`); render en `docs/renders/cube_rwg_bbox_fix_lit.png`.
> 2. **`.bod` está resuelto** (la sección final "NO resuelto" es
>    histórica): ver `docs/bod-format-reference.md`.
> 3. Hay **8 `.rwg` reales** en el repo (incluye `e3.rwg` y las copias de
>    `AVATAR`/`IDLE` en `assets/WorldsPlayer/`), todos de un solo `ATOM`.

> **Traducción desde los binarios (2026-09-24) — prevalece sobre todo lo
> de abajo.** El formato ya no se deduce de bytes: se ha traducido del
> lector real, `RwReadStreamChunk` de `RWL21.DLL` (0x10039e40, leído en
> ensamblador con `objdump`, el C de Ghidra de esa función está roto) y de
> la parte de `gamma.dll` que abre el fichero. Implementado en
> `formats/src/net/freeworlds/rwg/RwgParser.java`, comprobado en
> `formats/test/net/freeworlds/rwg/RwgTablesCheck.java`. Ver la sección
> "Formato según el binario" justo debajo.

## Formato según el binario (RWL21 + gamma.dll)

Todo big-endian. Un chunk es `[tag][longitud][contenido]`. RW **no** lee
los hijos por posición: cada lector busca el chunk que quiere con un
bucle (p. ej. 0x1003a205) que lee un tag y, si no es el buscado, salta
ese chunk con `RwSkipStreamChunk` (0x10039cd0); nunca salta al final del
chunk padre. Un `STRT` se lee con un máximo: se leen min(longitud, máx)
bytes y se salta (longitud − máx) con signo (0x1003b17a). gamma abre el
fichero en memoria (`RwOpenStream(3,1,…)`, FUN_004181d0): leer o saltar
más allá del final es el error 0x58 y una lectura de 0 bytes es un error.
Cualquier FALSE aborta el CLUM entero y `finishLoadingBinaryFile`
devuelve −1.

**Cabecera (gamma.dll, no RW).** `FUN_00419af0`: tag `ZZZ[`, longitud L
(tiene que ser > 8), y las palabras `0x13765342`, `1`. Los L−8 bytes
siguientes (`FUN_00419a20`) **no son el nombre del objeto**: son la
**lista de texturas** que `FUN_0041c970` (el constructor de
`ShapeLoader.loadBinaryFile` 0x0041e5d0) pide a Java *antes* de leer el
CLUM, cadena a cadena hasta una vacía, con `.cmp` (DAT_00470a7c) si el
nombre no tiene punto, vía `ShapeLoader.startTextureLoad`. Solo si la
lista acaba en la cadena vacía se marca la carga como buena (`this+0xc`,
que `finishLoadingBinaryFile` 0x0041e630 exige). IDLE → `idle.cmp`, e3 →
`earthkin.cmp`, AVATAR/ball/table → nada.

**CLUM** (0x1003a03d): crea un contexto con cinco listas y busca, en este
orden, `RALT`, `TELT`, `MALT` y el `ATOM` raíz.

| Chunk | Contenido | Dirección |
|---|---|---|
| `RALT` | STRT(12) `[n, ?, ?]` y n chunks `RAST` (STRT de 10 enteros: ancho, alto, ?, paso, formato; y un `DATA` con los píxeles) | 0x1003c4e3, RAST 0x1003c72a. ⚠️ sin muestra real: todo el corpus tiene n = 0 |
| `TELT` | STRT(12) `[n, tamaño de registro, ?]`; por entrada **siempre** lee 0x14 bytes = 5 enteros `[raster, raster del mipmap, ?, ?, ?]` y, si el tamaño de registro es **menor** que 0x14, salta además (0x14 − tamaño) hacia delante; luego busca un `STNG` con el nombre | 0x1003cb3f, 0x1003cc68 |
| `MALT` | STRT(12) `[n, tamaño de registro, ?]`; por material lee 0x28 bytes = 10 enteros y, si el tamaño es mayor, salta el resto | 0x1003bfce, 0x1003c0ab |
| `ATOM` | STRT(0x34) de 13 enteros, 2 `MATX`, `VLST`, `PLST` y los ATOM hijos | 0x1003b569 |

**Entrada de TELT → textura.** Raster 0 (el único caso del corpus):
textura con nombre (0x1003cde9): se busca en el diccionario de texturas
actual (FUN_100184d0) y, si no está y existe un fichero con ese nombre en
la ruta de formas (FUN_10021270: tal cual y con `.ras`, `.tex`, `.env`,
`.bmp`, `.rle`, leídas en DAT_1005ad00..1005ace0), `RwGetNamedTexture`;
si no hay textura, error 0x5e y **el CLUM falla**. Raster ≠ 0
(0x1003cd40): textura nueva sobre ese raster de RALT (y el del mipmap si
≠ 0) y al diccionario con el nombre (⚠️ sin muestra real). La textura se
añade a la lista **solo si no estaba ya** (0x1003ce42), así que dos
entradas que den la misma textura ocupan un solo índice.

**Registro de MALT → material** (RwCreateMaterial y 0x1003c119..c180):

| Campo | Destino |
|---|---|
| [0] | textura: índice base 1 en la lista de TELT (0 o fuera de rango = ninguna) → `RwSetMaterialTexture` |
| [1] | palabra 0 del material: muestreo. Geometría = 1 si < 4, 2 si < 8, 3 si < 0xc, si no 4 (RwGetMaterialGeometrySampling 0x10019e40); luz = 2 si bit 0, si no 1 (0x10019ea0) |
| [2] | byte de material+0x30: `& 0x1f` modos de textura (1 lit, 2 foreshorten, 4 filter, 0x10 trilinear), `& 0xc0` modos de material (0x80 doble cara) |
| [3..5] | color r, g, b (reales) → `RwSetMaterialColor` |
| [6] | opacidad → `RwSetMaterialOpacity` |
| [7..9] | ambiente, difusa, especular → `RwSetMaterialSurface` |

Valores reales: IDLE `[1, 0x14, 2, 0.96875, 0.984375, 0.96875, 1, 0.75,
0, 0]` (textura "idle", sólido, faceta, foreshorten sin lit, ambiente
0.75 = el "autoiluminado" de gamma FUN_00417950); e3 `[1, 0x15, 2, 0.5,
0.5, 0.5, 1, 0.1, 0.5, 0.9]` (por vértice); ball 512 materiales rojos
`[0, 0xd, 1, …]`, uno por triángulo; table uno naranja.

**ATOM, STRT de 13:** [0] → clump+0x8c y [1] → clump+0x90 (⚠️
significado sin determinar), [2] tag (+0xe8), [3..7] sin leer, [8]
hints, [9] alineación de ejes (+0x18c), [10] estado (+0x190, 1 OFF 2 ON),
[11] **número de ATOM hijos** (se leen tras PLST y se cuelgan con
`RwAddChildToClump`; ⚠️ sin muestra real, todo el corpus tiene 0), [12]
frecuencia de muestreo de luz (real). Los dos MATX van a clump+0xec y
clump+0x130.

**VLST** (0x1003b1be): STRT `[n, tamaño, banderas]`. Registro: x,y,z;
bandera 1 normal (marca el vértice con 0x40, normal puesta); bandera 2
u,v; bandera 4 tres reales (vértice +0x10..+0x18, ⚠️ significado sin
determinar). UV y bandera 4 se guardan a 16.16 (× 65536.0 =
DAT_10052298, `__ftol`). Los 8 primeros registros son la caja local
(ver corrección de la auditoría, abajo).

**PLST** (0x1003a583): STRT `[n, tamaño, banderas]`. Registro:
**material** (índice base 1 en MALT; es el campo que antes se llamó
"id/flag" y que en ball cuenta 1..512), número de vértices, índices;
bandera 1 normal de cara (polígono +0x10); bandera 4 tres reales a 16.16
(polígono +0x04..+0x0c, ⚠️ sin determinar); bandera 0x10 tag (16 bits en
+0x38). El "número de campos finales por fichero" (6 en cube/ball/table,
7 en IDLE) es esto: banderas 7 → 3+3, banderas 0x17 → 3+3+1. Cada
polígono pasa por FUN_10001220, que quita índices repetidos seguidos y el
último si repite el primero; con menos de 3 el PLST entero falla.

**Callback de gamma tras leer** (FUN_00419a60 → `RwForAllClumpsInHierarchy`
con 0x004187e0 sin 3D por hardware): tag < 0x4000000 → `RwSetClumpHints(2)`;
si no, `RwSetClumpState(OFF)`. Lo mismo tras un `.rwx` (FUN_004199c0).

**Consecuencias medidas en el corpus:**

- **`cube.rwg` no lo lee RW 2.1 de WorldsPlayer.** Su TELT tiene registros
  de 16 bytes (`[0,1,0,1]`); RW lee 20 (se come el tag `STNG`), salta 4
  más (su longitud) y la búsqueda del STNG acaba fuera del stream (0x5a).
  Seguramente lo generó otra versión de RWX2RWG; ⚠️ confirmarlo exigiría
  cargarlo en el original bajo Wine.
- `AVATAR.RWG` (el `xShape` por defecto) es un clump **válido y vacío**:
  0 vértices, 0 polígonos, tag 0, estado ON.
- IDLE y e3 **exigen** su textura en el diccionario (o un fichero
  `.ras/.tex/.env/.bmp/.rle` con ese nombre): en el cliente la pone ahí
  la carga previa de la cabecera (`idle.cmp` está en `WorldsPlayer/`).
- `table.rwg`: 524 vértices (532 registros − 8).

## Actualización importante: se encontró un corpus real más grande dentro
## del tutorial oficial de GammaDocs (`cube.rwg`, `ball.rwg`, `table.rwg` +
## `table.rwx` fuente, ahora en `assets/gammatutorial-samples/`)

Estos 3 archivos venían empaquetados en la documentación oficial
(`GammaDocs.zip`, aportada por el usuario, carpeta `GammaTutorial/tex/`),
no son sintéticos — son datos binarios de formato real, no documentación,
así que se movieron a `assets/gammatutorial-samples/` y SÍ están
versionados (a diferencia del resto de GammaDocs). Al probarlos contra el
parser recién escrito con solo `AVATAR.RWG`/`IDLE.RWG` como evidencia,
**rompieron la hipótesis inicial de `PLST`** (que solo se había
verificado contra UN polígono) — lo cual es exactamente la señal de que
la primera hipótesis era insuficiente, y se corrigió con evidencia real
en vez de mantenerse. Resultado, con el `PLST` corregido:

- **`cube.rwg`** (2168 bytes, un cubo de 6 caras/32 vértices) — **parsea
  limpio** y aporta la evidencia más fuerte de toda la sesión: cada uno
  de los 6 registros de `PLST` tiene un campo de normal de cara
  `(nx,ny,nz)` con un único eje en `~±1.0` — **los 6 ejes posibles
  aparecen exactamente una vez cada uno** (+X,-X,+Y,-Y,+Z,-Z),
  coincidiendo perfectamente con las 6 caras de un cubo axis-aligned.
  Esto también reveló que los campos del vértice que antes estaban
  "sin determinar" (floats[3:6)) **son la normal por vértice**, no un
  misterio — confirmado porque coincide exactamente con la normal de cara
  de `PLST` en cada caso.
- **`ball.rwg`** (55108 bytes, 512 triángulos, ~258 vértices) — también
  **parsea limpio** con la misma estructura (vertCount=3 en vez de 4,
  generalizando correctamente el algoritmo).
- **`table.rwg`** (49692 bytes, 546 polígonos, mezcla real de triángulos y
  cuadriláteros) — inicialmente **no parseaba** (rompía la asunción de
  "tamaño de registro uniforme derivado por división"); **resuelto** en
  la sesión de avatares articulados (2026-09-09) sin necesitar esa
  asunción — ver detalle en la sección de `PLST` más abajo.

## ⚠️ Hallazgo central de esta sesión: el corpus real es degenerado para
## el objetivo de "articulación"

El corpus real disponible (`assets/FIRST/{AVATAR,IDLE}.RWG`,
`assets/WorldsPlayer/cachedir/*.bod`, y ahora también
`assets/gammatutorial-samples/{cube,ball,table}.rwg`) es real — no
inventado — pero:

- **Los 5 `.rwg` reales disponibles (`AVATAR.RWG`, `IDLE.RWG`, y los 3 de
  `assets/gammatutorial-samples/`: `cube.rwg`, `ball.rwg`, `table.rwg`)
  tienen exactamente un solo `ATOM` cada uno** (verificado contando el tag
  en los 5 archivos). Ninguno es un avatar propiamente dicho — son props
  de tutorial de un solo clump (un cubo, una pelota, una mesa) o
  placeholders. `AVATAR.RWG` es un cubo degenerado usando centinelas
  `Float.MAX_VALUE`/`-Float.MAX_VALUE` como vértices (0 polígonos) — un
  placeholder, no geometría real. **Ninguno de los 5 demuestra una
  jerarquía real de múltiples joints** — que es justamente el objetivo
  declarado de esta sesión ("avatares ARTICULADOS"). No se pudo verificar
  con evidencia real cómo se anidan/referencian varios `ATOM` entre sí
  para formar un esqueleto completo (pelvis→torso→cuello→cabeza...). Sí
  se logró, en cambio, verificar sólidamente la geometría estática de UN
  clump (posición, normal por vértice, UV, polígonos con normal de cara)
  contra 4 de los 5 archivos, incluyendo un cubo de 6 caras y una pelota
  de 512 triángulos — mucho más robusto que la verificación inicial de
  un único polígono.
- **Los 26 `.bod` reales de `cachedir/`** (confirmado con
  `PendingDrone.java:91` que sí son avatares descargados de
  `AvatarUpgrades/<nombre>.zip`, no animaciones — ver sección BOD más
  abajo) probablemente SÍ contienen articulación real (son más grandes,
  2-10KB vs. los ~750-1050 bytes de los .rwg triviales) — pero usan una
  codificación binaria **completamente distinta**, sin ningún tag ASCII
  reconocible, y no se logró descifrar su estructura con la evidencia y el
  tiempo disponibles esta sesión.

**Conclusión honesta**: lo que sigue de este documento es una
reconstrucción SÓLIDA y VERIFICADA de la geometría de un único
clump/ATOM en formato `.rwg` (posición de vértices + polígonos) — útil y
reutilizable — pero **no constituye una solución completa al problema de
"avatar articulado"**, porque el corpus real no permitió verificar la
jerarquía de huesos con evidencia. Implementarlo IGUAL habría significado
inventar la parte de jerarquía sin evidencia, violando el principio de
verificación del proyecto — se optó por documentar el límite real en vez
de rellenar el hueco con una suposición.

---

## Investigación externa (subagente, resumen)

- **aw-sequence-parser** (Blaxar): formato NO relacionado — magia de
  archivo `[0x7f,0x7f,0x7f,0x79/0x7a]`, sin tags ASCII de 4 letras, es
  para animaciones `.seq` (quaternion por frame), no geometría estática.
  Confirma big-endian (coincide con lo que se ve en los bytes reales de
  `.rwg`), pero nada más aplicable.
- **RenderWare Binary Stream estándar** (el que documentan
  kaitai-struct/gtamods.com, usado por GTA y derivados): usa **IDs
  numéricos de sección little-endian**, NO tags ASCII, y es
  **little-endian** — lo opuesto a lo que se observa en los bytes reales
  de `.rwg` (tags ASCII literales como "CLUM"/"ATOM", big-endian).
  **Evidencia de que el binario de Worlds.com NO es el mismo formato RW
  binario "estándar" documentado para RenderWare 3.x/GTA** — puede ser una
  variante propia de RenderWare 2.x (anterior, sin documentación pública
  conocida) o un formato completamente propio de Worlds Inc.
- **kangworlds.net** y la wiki de Worlds Chat: confirman nombres de joints
  (Pelvis→Torso→Cuello→Cabeza, Cadera→Rodilla→Tobillo,
  Hombro→Codo→Muñeca) — coincide con los nombres EXACTOS encontrados en
  GammaDocs (ver abajo), pero sin detalle de formato binario.

---

## Fuente oficial: `Gamma_Advanced.html` (GammaDocs), sección "Articulated
## Avatars" (documentación real de Worlds Inc., no de terceros)

Hechos confirmados textualmente en la documentación oficial:

- **`.bod` se genera desde `.rwx` con la herramienta `rwxtobod`** (p. ej.
  `rwxtobod amy` → `amy.bod` desde `amy.rwx`). El `.rwx` fuente debe usar Y
  como eje de altura, 1 unidad = 10 metros (convención de ActiveWorlds).
- **Jerarquía de clumps requerida en el `.rwx` fuente**, cada uno
  identificado por un comentario `# nombre` (convención del exportador de
  3DS Max), con letra de código para el "lenguaje de avatar personalizado":
  `P pelvis, B back, N neck, H head, L lfshoulder, M lfelbow, O lfwrist,
  R rtshoulder, U rtelbow, V rtwrist, I lfhip, J lfknee, K lfankle,
  W rthip, X rtknee, Y rtankle, Z tail`.
- **Números de tag** (usados en el lenguaje de nombre de avatar, comando
  `G`): pelvis=1, back=2, neck=3, head=4, rtsternum=5, rtshoulder=6,
  rtelbow=7, rtwrist=8, rtfingers=9, lfsternum=10, lfshoulder=11,
  lfelbow=12, lfwrist=13, lffingers=14, rthip=15, rtknee=16, rtankle=17,
  rttoes=18, lfhip=19, lfknee=20, lfankle=21, lftoes=22, back2=23,
  tail=24, mouth=25, nose=26, lfear=27, rtear=28, back3=29, tail2=30,
  tail3=31, tail4=32.
  - ⚠️ Posible pista sin confirmar: en los `.rwg` reales, el valor `23`
    (=0x17) aparece como constante en TODAS las secciones RALT/TELT/MALT/
    PLST de ambos archivos de prueba — casualmente `back2=23` en esta
    tabla. Podría ser coincidencia (ambos archivos son un solo clump sin
    tag explícito) o podría ser un campo de tag real puesto a un valor por
    defecto. **No se pudo confirmar ni descartar** — ninguno de los 2
    archivos de prueba usa un tag distinto de 23 para comparar.
- **"Todas las matrices de joint deben ser matrices identidad, ya que el
  sistema las sobreescribe internamente al animar"** — coincide EXACTO
  con lo observado: ambos `MATX` de cada `ATOM` en ambos archivos son
  matrices identidad 4x4 (16 floats, ver más abajo).
- El avatar mínimo válido es solo el clump `pelvis` (los demás son
  opcionales, pero no se puede saltar uno intermedio).
- `.bod`, al momento de escribir esta documentación oficial (~2000-2001),
  "no son actualmente cargables por red" — **pero el código Java
  decompilado real confirma que en una versión posterior SÍ lo son**
  (`PendingDrone.java`, ver más abajo) — la doc oficial puede estar
  desactualizada respecto al build real que tenemos, o "cargable por red"
  se refería a una ruta distinta (referencia directa en URL de un mundo)
  frente al mecanismo de "paquete de actualización de avatar" que sí
  existe en el cliente real.

---

## Lo que confirma el cliente Java decompilado (sin parsear el formato él
## mismo — importante)

- `PendingDrone.java` descarga avatares como
  `AvatarUpgrades/<nombre>.zip` desde el upgrade server, extrae el zip, y
  copia cualquier archivo `.bod`/`.seq`/`.dat`/`.cmp`/`.mov` a
  `avatars/`. Confirma que **`.bod` es geometría de avatar real, `.seq` es
  animación — dos cosas distintas**, y que los 26 `.bod` reales de
  `cachedir/` (nombres de caché ofuscados tipo `3.bod`, `33.bod`) sí son
  avatares descargados de verdad.
- **Ninguna clase relacionada con avatares
  (`PosableDroneLoader`/`DroneLoader`/`PosableDrone`/`PosableShape`) tiene
  métodos `native` propios ni parsea el binario `.rwg`/`.bod` en Java** —
  coincide con lo que ya sabíamos de RWX/RenderWare (sección 2 del
  documento maestro): la carga real de geometría 3D pasa por RenderWare
  nativo (`gamma.dll`/DLLs de RenderWare), no por código Java. Esto
  confirma que, igual que con RWX, **no hay ningún atajo en el código
  decompilado** — la única vía es reconstruir el formato desde los bytes.

---

## Formato `.rwg`: estructura de chunks (VERIFICADO con hex dumps reales)

### Contenedor
- Magic: 4 bytes ASCII literal **`"ZZZ["`** (`5A 5A 5A 5B`).
- Luego un campo de 4 bytes big-endian que da la **longitud del bloque de
  cabecera variable** que sigue.
- Bloque de cabecera: 4 bytes constante `13 76 53 42` (igual en ambos
  archivos de prueba — ⚠️ VERIFICAR qué es exactamente: ¿versión? ¿magic
  secundario?) + 4 bytes `00 00 00 01` (constante también, ⚠️ VERIFICAR) +
  una **cadena ASCII con el nombre del objeto**, con padding a ceros
  (`AVATAR.RWG` tiene nombre vacío de 4 bytes; `IDLE.RWG` tiene
  `"idle\0\0\0\0"`, 8 bytes). El tamaño de este campo de nombre =
  `longitud_de_cabecera - 8`.
- A partir de ahí: chunks anidados, cada uno
  `[tag ASCII de 4 bytes][longitud de 4 bytes big-endian = tamaño exacto
  del payload, NO incluye el propio campo de longitud][payload]`.
  **Verificado matemáticamente**: sumando cabecera + cada chunk de nivel
  superior con esta convención, el offset final coincide EXACTO con el
  tamaño real del archivo en ambos archivos de prueba (748 y 1056 bytes).

### Chunks encontrados, en orden, dentro de un `CLUM` (nivel superior)

| Tag | Contenido verificado | Estado |
|---|---|---|
| `RALT` | Un `STRT` con 3 enteros de 4 bytes: `[0, 0, 23]` en ambos archivos | ⚠️ VERIFICAR propósito — solo 12 bytes de datos puramente numéricos, sin texto ni geometría |
| `TELT` | `STRT` de `[?, N, 23]` + datos extra. **Hallazgo**: en IDLE.RWG los datos extra contienen un sub-chunk anidado `STNG` (`53 54 4E 47`) = `[longitud=8]["idle\0\0\0\0"]` — el string **literalmente es "idle", el mismo nombre del objeto** que ya aparece en la cabecera del archivo. Posible tabla de nombres/etiquetas (Texture ELemenT? STring tag?). En AVATAR.RWG (nombre vacío) el STRT de TELT es `[0,0,23]` y no hay datos extra — consistente con "sin nombre → sin STNG". | ⚠️ VERIFICAR significado exacto de TELT, pero el sub-chunk STNG=nombre está bien evidenciado |
| `MALT` | `STRT` de `[?, N, 23]` + datos extra: en IDLE.RWG, 5 floats `[0.969, 0.984, 0.969, 1.0, 0.75]` seguidos de 2 ceros. Podría ser una caja delimitadora/escala o un color — valores en rango [0,1] son sugerentes de color RGB+algo, pero 5 valores no encaja limpio en RGB(A). | ⚠️ VERIFICAR — sin datos suficientes para confirmar |
| `ATOM` | El contenido real: un joint/segmento con transform + geometría | ✅ Estructura interna verificada, ver abajo |
| `PLST` (a veces aparece también fuera, como en AVATAR/IDLE de nivel superior) | Lista de polígonos, ver abajo | ✅ |

El "23" (`0x17`) constante en RALT/TELT/MALT/PLST podría coincidir con el
tag `back2=23` de la tabla oficial de GammaDocs — **coincidencia sin
confirmar**, ver nota arriba.

### `ATOM` (un joint/segmento — lo mejor entendido del formato)

1. **`STRT` propio, 52 bytes = 13 enteros de 4 bytes.** Primeros dos
   valores en ambos archivos: `[1, 4, ...]`. El resto varía. ⚠️ VERIFICAR
   significado exacto de cada campo — se decodificaron como enteros y como
   floats pero ninguna interpretación dio una señal tan clara como la de
   `VLST`/`PLST` (ver abajo). Posible: contador de hijos, flags, tag
   number del joint (relacionado con la tabla oficial de arriba).
2. **Dos bloques `MATX`, cada uno con un `STRT` de 64 bytes = 16 floats =
   una matriz 4x4.** **Verificado: en ambos archivos, ambas matrices son
   la matriz identidad** (`1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1`) —
   coincide EXACTO con la documentación oficial ("todas las matrices de
   joint deben ser identidad, el sistema las sobreescribe al animar").
   Layout de la matriz (row-major vs column-major) **no se pudo
   determinar** con una matriz identidad, que es igual en ambas
   convenciones — ⚠️ VERIFICAR con un archivo real que tenga una matriz
   no-identidad (ninguno de los 2 disponibles la tiene).
3. **`VLST`** (lista de vértices) — **la parte mejor verificada de todo el
   formato**:
   - `STRT` propio de 12 bytes = 3 enteros: `[cuenta_de_vértices,
     bytes_por_vértice, 23]`. **Verificado matemáticamente en ambos
     archivos**: `cuenta × bytes_por_vértice` coincide exacto con el resto
     del payload de `VLST` (8×44=352 en AVATAR, 12×44=528 en IDLE).
   - Cada registro de vértice = **44 bytes = 11 floats big-endian**.
     - **Floats[0:3] = posición (x, y, z)** — verificado con altísima
       confianza: en `AVATAR.RWG` los 8 vértices son exactamente las 8
       esquinas de un cubo usando centinelas `Float.MAX_VALUE`/
       `-Float.MAX_VALUE` (0x7F7FFFFF/0xFF7FFFFF) — un patrón de
       "bounding box sin inicializar", confirma que es un placeholder sin
       geometría real. En `IDLE.RWG` son coordenadas pequeñas y
       coherentes (±0.4, 0/-0.8) formando un plano — dimensiones
       plausibles para un avatar (unidades ~ metros/decímetros).
     - **Floats[3:6) = normal por vértice (nx, ny, nz)** — ✅ resuelto con
       `cube.rwg` (un cubo real de 6 caras/32 vértices): para cada una de
       las 6 caras, los 4 vértices de esa cara comparten el mismo eje
       ±1.0 en esta posición, y coincide exactamente con la normal de
       cara verificada en `PLST` (ver abajo). Antes de tener `cube.rwg`
       esto se había marcado erróneamente como "sin determinar" (con solo
       IDLE.RWG disponible, un único quad, no se podía distinguir "normal"
       de "flag booleano").
     - **Floats[6:8] parecen ser UV de textura** — en `IDLE.RWG` y
       `cube.rwg`, los vértices "duplicados" por cara (patrón clásico de
       "vértice duplicado por costura de UV", igual que se vio en RWX
       esta misma sesión) tienen valores como `0.0039` y `0.9961` en
       estas posiciones — coincide con el patrón típico de coordenadas UV
       en los bordes de una textura (≈0 y ≈1 con un pelín de margen de
       cuantización). **Confianza media-alta, no absoluta.**
     - **Floats[8:11]: sin determinar.** Siempre cero en los 5 archivos
       de prueba disponibles — sin evidencia de qué representan
       (posiblemente reservado, o un campo de skinning que ningún archivo
       de prueba real ejercita porque ninguno tiene más de un joint).
4. **`PLST`** (lista de polígonos) — ✅ **estructura general resuelta y
   verificada contra los 5 archivos reales** (`AVATAR.RWG` con 0
   polígonos, `IDLE.RWG` con 1 quad, `cube.rwg` con 6 quads, `ball.rwg`
   con 512 triángulos, y `table.rwg` con 546 polígonos de tipo mixto):
   - `STRT` propio de 12 bytes = 3 enteros: `[cuenta_de_polígonos,
     campo2, campo3]`. Ninguno de los dos últimos es constante entre
     archivos: `campo2` es 36 en AVATAR/IDLE pero 32 en cube/ball/table;
     `campo3` es 23 en AVATAR/IDLE pero **7** en cube/ball/table (se
     documentó antes como "siempre 23" con solo 2 archivos de evidencia —
     corregido al re-verificar contra los 3 restantes esta sesión). ⚠️
     VERIFICAR su significado exacto (podría relacionarse con el tamaño
     de registro, pero no coincide limpiamente con los bytes reales de
     ningún archivo).
   - **Cada registro de polígono = `[id/flag][vertexCount][vertexCount
     índices 1-based][campos finales]`.** El primer campo se documentó
     inicialmente como "flag, siempre 1" (cierto en AVATAR/IDLE/cube, que
     solo tienen 0/1/6 registros) pero **no es constante**: en
     `ball.rwg` (512 registros) cuenta 1..512, uno por polígono — es
     algún tipo de id/contador por registro, no un booleano. El parser
     (`RwgParser.parsePlst`) ya no lo valida, solo lo descarta.
   - **Los primeros 3 campos finales = normal de cara (nx, ny, nz)** — ✅
     confirmado con altísima confianza en `cube.rwg`: sus 6 registros
     (uno por cara) tienen cada uno un único eje en `~±1.0000863` (no
     exactamente 1.0 — error de redondeo típico de exportación desde 3DS
     Max) y los otros dos ejes en 0, y **los 6 ejes posibles aparecen
     exactamente una vez cada uno** — imposible que sea coincidencia.
     También verificado indirectamente en `ball.rwg` (normales no
     axis-aligned, coherentes con una esfera triangulada) e `IDLE.RWG`
     (normal `(0,0,~1.0)`, coincide con que su único quad mira a +Z).
   - **El número exacto de campos finales VARÍA entre archivos** — 6 en
     `cube.rwg`/`ball.rwg` pero 7 en `IDLE.RWG` (un campo extra de
     relleno sin explicar). El parser (`RwgParser.parsePlst`) lo resuelve
     calculando el tamaño de registro dividiendo el payload total entre
     el número de polígonos — funciona porque cada `PLST` observado hasta
     ahora tiene un `vertexCount` uniforme para todos sus registros.
   - ✅ **`table.rwg` RESUELTO (sesión de avatares articulados,
     2026-09-09)**: la asunción de "tamaño de registro uniforme derivado
     por división" nunca hacía falta — cada registro YA declara su propio
     `vertexCount` en el segundo campo, que se lee directamente sin
     asumir nada. Lo único que hacía falta resolver era la cantidad de
     ints finales ("trailing") tras los índices, que SÍ es constante,
     pero por archivo, no por registro (6 en `cube.rwg`, 6 en `ball.rwg`,
     7 en `IDLE.RWG`). `RwgParser.resolvePlstTrailingCount()` ahora prueba
     candidatos pequeños (0..16) y se queda con el que hace que leer los
     `polyCount` registros — usando el `vertexCount` real de cada uno,
     sin asumir uniformidad — cierre exactamente en el byte final del
     `PLST`. Con esto, `table.rwg` (546 polígonos, mezcla real de
     triángulos y cuadriláteros confirmada byte a byte, p.ej. los
     registros 541-544 tienen 4 índices y el 545 tiene 3) resuelve
     `trailingCount=6` y parsea limpio — verificado además
     renderizando el resultado (`RwgViewer`, ver
     `docs/renders/rwg_table_fixed.png`): una mesa coherente (tapa
     circular + patas cruzadas), no basura geométrica.
   - **Efecto colateral, corrección importante**: el primer campo de cada
     registro de `PLST`, hasta ahora documentado como "`flag`, siempre
     1", **NO es constante** — al re-verificar contra los bytes reales de
     `ball.rwg` (512 registros) resultó ser un contador 1..512, uno por
     polígono, no un booleano. `cube.rwg`/`IDLE.RWG` sí lo tienen fijo en
     1 (con solo 6 y 1 registros respectivamente no bastaba para notar el
     patrón). El parser ya no valida ni depende de este campo — lo lee y
     lo descarta. Significado real: desconocido (¿id de polígono?
     ¿smoothing group?) — no se inventó una interpretación sin evidencia.
   - ✅ **Verificado por renderizado real** (`RwgViewer.java` +
     inspección de píxeles): los 4 índices `[0,1,2,3]` del quad de
     IDLE.RWG están en **orden de rejilla** (0=arriba-izq, 1=arriba-der,
     2=abajo-izq, 3=abajo-der), NO en orden de lazo perimetral. Un
     fan-triangulation ingenuo `(0,1,2)+(0,2,3)` produjo un "chevron"
     cóncavo visiblemente incorrecto; la triangulación correcta para 4
     vértices en este orden es `(0,1,2)+(1,3,2)` (orden de "strip"), que
     sí produjo un rectángulo plano sólido — confirmado por captura de
     pantalla real. ⚠️ VERIFICAR con más quads reales si esta convención
     de orden se mantiene siempre, o si es específica de cómo el
     exportador de 3DS Max (mencionado en GammaDocs) emite quads.
   - ✅ **Verificado además con `cube.rwg` y `ball.rwg` completos**
     (`docs/renders/cube_rwg_3d.png`, `docs/renders/ball_rwg_3d.png`): el
     cubo real renderiza como un cubo 3D reconocible desde un ángulo
     (3 caras visibles, silueta correcta) y la pelota como una esfera
     facetada — ambos usando únicamente los datos que salen del parser
     (posición + índices), sin ningún ajuste manual por archivo.

---

## Formato `.bod`: NO resuelto esta sesión

Confirmado con evidencia (no asumido):
- Magic de 4 bytes **constante e idéntico en los 26 archivos reales**:
  `01 10 01 00`, seguido de 2 bytes más también constantes `00 02` — un
  header fijo de 6 bytes, **completamente distinto** al `"ZZZ["` de
  `.rwg`.
- Sin tags ASCII reconocibles en ningún punto de los archivos
  inspeccionados — no es el mismo esquema de chunks.
- Tras el header, los bytes no siguen ningún patrón de enteros de 32 bits
  ni floats obviamente sensato en los primeros cientos de bytes
  inspeccionados — podría ser una codificación delta/comprimida (con
  sentido dado que `.bod` se distribuye por red, donde el ancho de banda
  importaba en 1999-2004) o un formato de registros de tamaño variable.
- **No se encontró ninguna referencia externa ni lógica en el cliente
  Java decompilado que revele el layout exacto** (ver arriba: la carga
  real ocurre en RenderWare nativo, fuera de nuestro alcance sin
  desensamblar las DLLs).

**Siguiente paso lógico para resolver `.bod`** (no intentado esta sesión,
esfuerzo mayor): desensamblar con Ghidra la función de `gamma.dll` que
lee archivos `.bod` (ya tenemos Ghidra instalado y usado en sesiones
anteriores para `gamma.dll`) — es un trabajo de ingeniería inversa a nivel
de ASM x86, más parecido a lo que se hizo para mapear los métodos
`native`, que a "seguir leyendo bytes con más paciencia".
