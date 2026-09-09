# Referencia del formato RWX, verificada contra three-rwx-loader

Todo lo de este documento viene de leer directamente
`tools/rwx-harness/node_modules/three-rwx-loader/src/RWXLoader.js`
(instalado vía npm, no vendorizado) — no de la wiki de Active Worlds ni de
suposiciones. Donde el comportamiento real sorprende o contradice lo que
uno esperaría, se explica con evidencia (número de línea, fragmento de
código). Implementado en `client/src/net/freeworlds/rwx/` y verificado con
`tools/rwx-harness/compare.py` contra los 118 archivos `.rwx` reales del
proyecto: **118/118 OK** (ver `docs/rwx-parser-progress.md`).

**Nota sobre este documento**: un primer intento de generarlo con un
subagente de solo lectura se interrumpió a medio camino (se desvió
construyendo el arnés de comparación, que sí quedó terminado y funcional,
pero nunca escribió este archivo). Se completó leyendo el código fuente
directamente en el hilo principal, dado que es la lógica central del
parser (fuera del alcance de delegar, según las instrucciones del
proyecto).

---

## 0. Hallazgo estructural más importante: scoping por clump

Antes de leer las tablas de comandos, esto es lo que hace que la mayoría
de los bugs iniciales del parser desaparecieran de golpe:

- **`ModelBegin`/`ModelEnd` NO existen para el parser.** No hay ninguna
  regex que los reconozca (`this.clumpbeginRegex = /^ *(clumpbegin).*$/i` —
  nada de "model"). Son no-ops puros. El verdadero establecimiento de
  ámbito lo hace el primer `ClumpBegin` inmediatamente dentro.
- **Los índices de vértice de `Triangle`/`Quad`/`Polygon` son relativos a
  un buffer de vértices *por clump*, no a una lista global del archivo
  entero.** `ClumpBegin` limpia el buffer (`clearGeometry()`, línea 596) Y
  `ClumpEnd` lo vuelve a limpiar. Si un clump padre declara `Vertex` antes
  Y después de un clump hijo anidado, los `Triangle` de "después" indexan
  desde 0 otra vez — no continúan donde se quedó el padre.
- **El material también tiene ámbito de clump**: `ClumpBegin` clona el
  material actual y lo apila (`pushCurrentMaterial`, línea 1277);
  `ClumpEnd` lo restaura (`popCurrentMaterial`, línea 1285). Un `Color`
  dentro de un clump hijo no se filtra a los hermanos siguientes.
- **La transformación también tiene ámbito de clump, pero de forma
  distinta a `TransformBegin`/`TransformEnd`**: `ClumpBegin` congela lo que
  se había acumulado como la "base" de este clump y **resetea el
  acumulador local a identidad** para lo declarado dentro
  (`pushCurrentGroup`, línea 1258); `ClumpEnd` restaura el acumulador local
  a lo que era justo antes del reset, descartando lo que el clump hijo hizo
  con él (`popCurrentGroup`, línea 1270). `TransformBegin`/`TransformEnd`
  en cambio solo guardan/restauran sin resetear a identidad
  (`saveCurrentTransform`/`loadCurrentTransform`, líneas 1292-1298).

Implementado en `RwxParser.java` como: un `groupWorld` (transform "mundo"
del clump que envuelve al actual) + una pila de saves; un
`currentTransform` LOCAL al clump actual (se resetea a identidad en cada
`ClumpBegin`) + una pila separada para `TransformBegin`/`TransformEnd`. El
vértice horneado en el momento de `Vertex`/`VertexExt` es
`groupWorld × currentTransform × posición-cruda` — evaluado
inmediatamente, no diferido.

---

## Batch (a): geometría estática básica

### `ClumpBegin` / `ClumpEnd`
Ver sección 0. Además: la primera vez que se ve un `ClumpBegin` en el
archivo, three-rwx-loader lo marca como "la raíz real de la topología"
(línea 2269) — detalle de nomenclatura interna, sin efecto en geometría.

### `Vertex x y z [UV u v]` / `VertexExt` (mismo regex, mismo tratamiento)
- Se transforma **inmediatamente** con `currentTransform` (línea 2542:
  `tmpVertex.applyMatrix4(ctx.currentTransform)`) y se añade al buffer del
  clump actual — no se difiere al momento de emitir el triángulo.
- UV: si no hay `UV u v`, se usa `(0, 0)`. Si hay, la V se invierte:
  `1 - v` (línea 2555). No afecta la comparación de geometría/posición,
  sí afectaría a un renderer real con texturas.
- ⚠️ **VERIFICAR**: no se comprobó si `VertexExt` (vs `Vertex` a secas)
  tiene algún campo adicional real en archivos de este proyecto — en los
  118 de prueba, `VertexExt` se comporta idéntico a `Vertex` según el
  regex compartido (`this.vertexRegex` cubre ambos nombres).

### `Triangle a b c [tag N]`
- Índices 1-based en el archivo → 0-based internamente (línea 2406:
  `parseInt(entry) - 1`).
- El parámetro `tag` opcional se usa para un mecanismo de "letreros"
  (`signTag`/`setMaterialRatio`) ajeno a geometría pura — no implementado
  en el parser Java, no afecta la comparación de vértices/caras.

### `Quad a b c d [tag N]`
- **NO siempre corta por la diagonal A-C.** Corta por la diagonal más
  **corta**: `cutAC = distSq(A,C) > distSq(B,D)` (línea 772) — es decir, si
  A-C es más larga que B-D, corta por B-D en su lugar. Con `cutAC`:
  triángulos `(a,b,c)` y `(a,c,d)`; si no: `(a,b,d)` y `(b,c,d)`.
- Caso especial NO implementado en el parser Java (⚠️ fuera de alcance por
  ahora, no aparece en los 118 archivos de prueba): si
  `GeometrySampling == WIREFRAME`, el quad se renderiza como solo los
  bordes exteriores (líneas 732-754), lógica de renderizado, no de
  geometría de relleno.
- Caso especial NO implementado (⚠️ igual, no aparece en el corpus):
  `correctInvalidNormals` — si está activado y el corte elegido produciría
  normales inválidas, duplica los 4 vértices y usa esas copias en vez de
  los índices originales (líneas 778-814). Requeriría calcular normales
  reales, que el parser Java actual no calcula (solo posiciones).

### `Polygon n v1 v2 ... vn [tag N]`
- **El orden de los índices se invierte antes de triangular en abanico**:
  `polyIDs.unshift(parseInt(id) - 1)` en un bucle ascendente (línea 2508) —
  como `unshift` inserta al principio, el resultado queda en orden
  inverso al del archivo.
- Fuerza `LightSampling.FACET` para el material durante la emisión
  (línea 830) — efecto de iluminación, no de geometría.
- No aparece en los 118 archivos de prueba; implementado en el parser Java
  seguido de la reversión de orden documentada arriba, pero **sin verificar
  contra un archivo real** — ⚠️ VERIFICAR si aparece un `.rwx` con
  `Polygon` en el futuro.

---

## Batch (b): materiales y texturas

### `Color r g b`
Set directo de `material.color = [r,g,b]` (línea 2579) — **no** se mezcla
con `Ambient`/`Diffuse`/`Specular`, son campos completamente separados.

### `Surface a d s`
Set de los TRES coeficientes de golpe: `material.surface = [a,d,s]`
(ambient, diffuse, specular, en ese orden — línea 2727).

### `Ambient a` / `Diffuse d` / `Specular s`
Cada uno pisa solo su propia posición dentro de `material.surface[0/1/2]`
(líneas 2735-2751) — no tocan `color` ni las otras dos posiciones.

### `Opacity o`
Set directo de `material.opacity`.

### `Texture nombre [máscara]`
- Solo se procesa si `this.enableTextures` está activo (default `true` en
  el loader real, línea 1988) — **pero el arnés de comparación lo
  desactiva a propósito**, ver el aviso grande más abajo.
- `Texture NULL` (case-insensitive) limpia la textura.

### ⚠️ Hallazgo importante: comparar materiales de tres-rwx-loader en este
### entorno (Node headless, sin archivos de imagen reales) NO es fiable

Con `enableTextures` activo (el default), cargar cualquier archivo de
nuestro corpus produce el mismo material gris plano `d8d8d8` sin textura
en **todos** los triángulos, sin importar lo que declare `Color`/`Texture`
en el `.rwx` — confirmado inspeccionando directamente los objetos
`THREE.Material` resultantes (no solo el JSON del arnés), en archivos con
y sin `Texture`, con distintos valores de `Color`. La causa más probable:
el corpus solo tiene texturas en formato `.cmp` (propio de Worlds), no
`.jpg` (`textureExtension` por defecto del loader) ni ningún formato que
el pipeline de carga headless pueda resolver, y el fallo de carga
contamina también el color base, no solo el mapa.

**Mitigación aplicada**: `tools/rwx-harness/extract.mjs` llama a
`loader.setEnableTextures(false)` para evitar la contaminación — pero con
esto el nombre de textura JAMÁS se registra en el lado de referencia
(mientras que el parser Java sí lo hace correctamente), así que **el campo
`map`/`textureName` no es comparable entre los dos lados con esta
configuración**. Además, incluso con texturas desactivadas, el color en
hex que produce `THREE.Color.getHexString()` **no coincide** con una
conversión directa `round(canal*255)` — sospecha fuerte de conversión
linear↔sRGB interna de `THREE.Color` (confirmado con una prueba aislada:
`new THREE.Color(0.537255, 0.196078, 0.196078).getHexString()` da
`"c27a7a"`, no `"893232"` como daría una conversión directa; y el valor que
de verdad sale del loader real es un TERCER valor distinto, `"732828"` —
no se identificó la fórmula exacta).

**Decisión tomada**: `tools/rwx-harness/compare.py` reporta el conteo de
materiales como **nota informativa, no como criterio de OK/DIFERENCIAS**
— la comparación autoritativa es geometría (vértices/triángulos), que sí
es 100% verificable y da 118/118 OK. ⚠️ **VERIFICAR pendiente**: la fórmula
exacta de conversión de color de `THREE.Color`, si en el futuro hace falta
verificar colores exactos (por ejemplo cuando el renderer LWJGL necesite
pintar con el color correcto).

### Comandos de material reconocidos por el parser pero SIN efecto de
### geometría verificado más allá de guardar el campo (no se profundizó,
### bajo impacto para fase 1): `MaterialModes`, `TextureModes`,
### `GeometrySampling`, `LightSampling`, `CollisionEnabled`. Todos tienen
### regex propia en el loader real pero solo mutan flags de
### renderizado/colisión, no posiciones — confirmado por lectura del
### código (no se testearon exhaustivamente contra el corpus real).

---

## Batch (c): transformaciones

### `Identity`
`currentTransform.identity()` — reset absoluto (línea 2599).

### `Transform` (16 valores)
- **Set absoluto**, no multiplicación: `currentTransform.fromArray(tprops)`
  (línea 2623).
- Los 16 valores se leen en **orden column-major**, exactamente como
  `THREE.Matrix4.fromArray` — **no** row-major. Ver la nota de convenciones
  más abajo, es la fuente de bugs más probable si se reimplementa esto sin
  verificar.
- ⚠️ **Quirk confirmado del cliente AW/Worlds** (comentario explícito en el
  código fuente, línea 2615): si el último valor (posición 15, esquina
  inferior derecha en column-major) es `0`, se fuerza a `1`. Replicado tal
  cual en `RwxParser.parseTransformMatrix`.

### `Translate x y z` / `Scale x y z`
Post-multiplican: `currentTransform.multiply(M)` (líneas 2646, 2710) — es
decir, `currentTransform = currentTransform * M`.

### `Rotate x y z angle`
**No es una rotación de eje arbitrario.** Son hasta TRES rotaciones
independientes alrededor de los ejes cardinales X, Y, Z (en ese orden),
cada una aplicada solo si su coeficiente es no-cero, con ángulo
`coeficiente × angle` grados (líneas 2668-2687):
```
if (x != 0) currentTransform *= RotationX(x * angle grados)
if (y != 0) currentTransform *= RotationY(y * angle grados)
if (z != 0) currentTransform *= RotationZ(z * angle grados)
```
Esto es fácil de malinterpretar como "eje arbitrario normalizado +
fórmula de Rodrigues" (así lo implementé al principio, incorrectamente,
antes de leer el código fuente) — no lo es. No aparece ningún `Rotate` en
el corpus de 118 archivos de prueba (todos usan `Transform` con matriz
cruda), así que esto está implementado pero **sin verificación empírica
contra un archivo real** — ⚠️ VERIFICAR si aparece uno.

### Convención de matrices: column-major, `M × v`

Todo el código de `three-rwx-loader` usa las convenciones de `THREE.js`:
almacenamiento column-major (`e[0..3]` = columna 0, etc.), `a.multiply(b)`
significa `a = a * b`, y un punto se transforma como `v' = M * v` (vector
columna). `client/src/net/freeworlds/rwx/RwxMatrix4.java` replica esto
exactamente — la primera versión del parser usaba row-major con
`v' = v * M` (convención opuesta) y producía geometría sutilmente
incorrecta en archivos con transformaciones no-triviales, sin dar ningún
error de compilación ni excepción — solo números ligeramente distintos.
Detectado gracias al arnés de comparación, no habría sido obvio a simple
vista.

---

## Batch (d): jerarquía de clumps/proto

### `ProtoBegin` / `ProtoEnd` / `ProtoInstance`
Reconocidos por el loader real (líneas 2310-2358, mecanismo de plantillas
reutilizables con `ctx.rwxPrototypes`), pero **no aparecen en ningún
archivo de los 118 de prueba** de este proyecto. **No implementado en el
parser Java** — ⚠️ VERIFICAR y añadir si se necesitan modelos de otra
fuente (avatares `.rwg`/`.bod` u otros mundos) que sí los usen.

### Comandos con regex propia en el loader pero que además NO alcanzaron
### el corpus de prueba: (ninguno más relevante a jerarquía — `Tag` es el
### único que aparece con frecuencia, ver abajo).

### `Tag N`
Solo mete `N` en `userData.rwx.tag` del grupo actual (línea 3001) —
metadata pura, sin efecto en geometría ni jerarquía real.

---

## Comandos que NO reconoce three-rwx-loader (verificado: no existe regex
## para ellos en todo el archivo) — no-ops puros, confirmado que aparecen
## profusamente en el corpus real sin efecto alguno en la geometría final:

- `ModelBegin` / `ModelEnd` (section 0 — el hallazgo más importante)
- `JointTransformBegin` / `JointTransformEnd` / `IdentityJoint`
- `Hints` / `AddHint`

Los 4 últimos aparecen 72+40+336 veces combinadas en el corpus (avatares y
props con huesos/joints) y **no hacen absolutamente nada** en
three-rwx-loader. El parser Java los deja caer al `default:` (ignorar) —
comportamiento verificado como correcto, no por omisión accidental.

---

## Metodología de verificación (arnés)

- `tools/rwx-harness/extract.mjs`: parsea con three-rwx-loader real
  (`setFlatten(false)`, `setEnableTextures(false)` — ver Batch (b)),
  aplana la jerarquía de grupos multiplicando matrices manualmente
  (`walk()`), excluye el grupo `rwx-scale-group` que el loader añade con
  una escala fija de 10x (convención de "decámetro" de Active Worlds,
  líneas 2233-2239 del loader — **no** viene del archivo `.rwx`, la añade
  el loader siempre) para comparar en las mismas unidades "crudas" que un
  parser que no aplique esa escala.
- `client/src/net/freeworlds/rwx/RwxExtractMain.java`: mismo formato JSON
  de salida desde el parser Java.
- `tools/rwx-harness/compare.py`: corre ambos, reordena los triángulos de
  cada lado con una clave numérica calculada en Python (no confía en el
  orden interno de cada lado — ver el comentario grande en
  `numeric_sort_key()`, fue la causa de falsos positivos masivos hasta que
  se corrigió), compara posición por vértice con tolerancia `1e-3`, y
  escribe `docs/rwx-parser-progress.md`.
- **Resultado final: 118/118 archivos OK** en geometría (vértices y
  triángulos). Material es informativo únicamente (ver Batch (b)).
