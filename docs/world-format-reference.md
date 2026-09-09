# Referencia del formato `.world`, reconstruida desde el código Java real del cliente

## Resumen ejecutivo

A diferencia de RWX/RWG/`.cmp`, `.world` **no es un formato binario propio
con estructura ad-hoc** — es la serialización del propio grafo de objetos
Java del cliente, usando un mecanismo de persistencia genérico
("Persister"/`Saver`/`Restorer`) que SÍ está completamente implementado en
Java puro y decompilado (`NET.worlds.scape.{Saver,Restorer,SuperRoot,
Transform,WObject,Shape,World,Room,...}`) — no hace falta desensamblar
nada nativo para este formato, a diferencia de RWX/RWG/`.cmp`. Es, con
diferencia, la fuente de evidencia más fiable de todo el proyecto: el
propio código que escribe y lee el formato está ahí, completo.

**Implementado y verificado end-to-end**: `client/src/net/freeworlds/world/
WorldRestorer.java` parsea `assets/GROUNDZERO/GROUNDZERO.WORLD` (un
archivo real de 205.759 bytes) **completo, sin errores, hasta el
marcador `END PERSISTER`** — 25 salas reales, 578 nodos en el grafo de
objetos, 103 objetos `Shape`/`PosableShape` con referencia real a
geometría (50 archivos `.rwx`/`.rwg` únicos, todos verificados contra
archivos reales en `assets/GROUNDZERO/`).

## Contenedor: el protocolo genérico `Persister`

Verificado byte a byte contra la cabecera real del archivo:

```
[bool isNull=false][UTF "PERSISTER Worlds, Inc."]   <- cabecera fija
[int version]                                        <- 7 en el archivo real
... N llamadas a restore() ...
[bool isNull=false][UTF "END PERSISTER"]             <- cola fija
```

Cada `restore()` (el método genérico que lee CUALQUIER objeto
persistido, desde `World` hasta un simple `Point3`) sigue este patrón:

```
[int objectId]
  si objectId ya visto: usar el objeto cacheado, NO leer nada más
  si no:
    [int classId]
      si classId ya visto: usar el nombre de clase cacheado
      si no: [UTF nombre de clase completo, ej. "NET.worlds.scape.Room"]
    ... los campos propios de esa clase, ver abajo ...
```

**Detalle crítico, fácil de pasar por alto** (verificado en
`Restorer.restoreVersion()`): el número de versión de cada clase se lee
del stream **solo la primera vez que esa clase aparece**, y se
**cachea para el resto del archivo entero** (indexado por un "cookie"
que en el cliente real es un campo estático por clase). Esto significa
que si `WObject` usa versión 10 la primera vez, TODOS los objetos
`WObject`-derivados del archivo (`Room`, `Rect`, `Shape`, ...) comparten
esa misma versión 10 — no se puede asumir que cada objeto lleva su
propio número de versión en el stream.

## Cadena de herencia y campos — verificados contra el código fuente real

Cada clase de Java corresponde a un método `restoreState()` con un
`switch` sobre su propio número de versión, casi siempre terminando en
`super.restoreState(var1)` para delegar a la clase padre. La cadena
espacial relevante para geometría es:

```
SuperRoot   (nombre — un String)
  └─ Transform  (escala x/y/z + matriz 4x4 de 16 floats = "guts", nativo)
      └─ WObject  (flags, hijos "contents" [recursivo], handlers, actions,
                    bumpCalc, sharer, tooltip, mouseOver)
          ├─ Shape       (+ URL de geometría .rwx/.rwg)
          │   └─ PosableShape  (+ bool COG — avatares posables)
          ├─ Surface     (+ Material)
          │   └─ Rect    (+ u,v,uOff,vOff — coordenadas de textura)
          │       ├─ Portal       (+ destino de teleport)
          │       └─ WebPageWall  (+ URL de página web incrustada)
          ├─ RoomEnvironment  (el contenido 3D visible real de una sala)
          └─ Room        (+ colores cielo/suelo, posición por defecto,
                            posición/color de luz, entorno, teleport)
              └─ WrStaircase  (+ 1 float extra, sin versión propia)
```

**Posición/rotación/escala**: cada objeto `Transform`-derivado guarda su
transformación como una **matriz 4x4 completa de 16 floats** (el
`float[] guts` nativo de RenderWare), no como posición+rotación+escala
por separado — coincide exactamente con `RwxMatrix4` ya usado para RWX,
reutilizado directamente en vez de crear una clase nueva.

**Iluminación** (verificado en sesión anterior, `Room.java`): posición y
color de luz de cada sala son campos explícitos del propio `Room`
(`lightPosition`, `lightColor` — un `Point3` y un RGB `int`), leídos
igual que el resto — no hace falta ninguna suposición nueva, el motor de
iluminación de 2 luces (sesión anterior) puede alimentarse directamente
de estos valores reales por sala en vez del valor por defecto fijo.

## Bugs reales encontrados y corregidos durante la implementación

Todos encontrados por desincronización del stream (una excepción de
formato UTF inválido, o una clase "no reconocida" con nombre corrupto) y
diagnosticados **comparando byte a byte contra el archivo real** — nunca
"parece que funciona" sin evidencia:

1. **`Surface.restoreState` case 1**: el código real usa
   `(Material)var1.restore()` — una llamada DIRECTA, sin el booleano
   "puede ser null" previo. El case 0, en cambio, usa el helper estático
   `Material.restore(var1)`, que SÍ internamente hace
   `restoreMaybeNull()`. Confundir ambos (usar `restoreMaybeNull()` en
   el case 1) desincronizaba el stream por exactamente 1 byte — el bug
   más difícil de encontrar de la sesión, diagnosticado comparando
   offsets reales calculados con una búsqueda literal del string de
   clase `"NET.worlds.scape.Material"` en el archivo. El mismo patrón
   (`Material.restore()` vs `(Material)var1.restore()`) se repetía, mal,
   en `RectPatch` y `Portal` — corregido en los tres sitios.
2. **`NET.worlds.scape.WObject` aparece directamente como clase
   instanciable** en contenido real (ej. `"WObVendMachine1"`, un nodo
   organizativo que agrupa varias piezas de una máquina expendedora) —
   no solo como superclase abstracta de otras. Sin un caso explícito
   para esta clase, el parser fallaba con "clase no reconocida".
3. **`SendURLAction` extiende `DialogAction`, no `Action`
   directamente** — sus casos de versión 6-9 llaman a
   `super.restoreState(var1)`, que en la cadena de herencia real de
   ESTA clase es `DialogAction.restoreState()` (con sus propios 2
   booleanos `showDialog`/`cancelOnly`), mientras que sus casos 3-5 usan
   el método especial `dialogActionSkipRestore()` que SÍ salta
   directamente a `Action` sin esos 2 booleanos. Había implementado
   ambos casos al revés.
4. **`Billboard.restoreState` case 3 le faltaba el campo final
   `isAdBanner`** (un booleano) — mi primera transcripción asumió
   (incorrectamente) que los campos se acumulaban igual que en
   `WebPageWall`, sin verificar el case 3 completo de `Billboard` por
   separado.

## Verificación realizada (sin referencia externa — es el único parser
## que existe para este formato exacto de este cliente)

- El archivo completo parsea de principio a fin sin ninguna excepción,
  llegando al marcador `END PERSISTER` real.
- 25 nombres de sala extraídos (`ChatHall`, `Reception`, `AvatarEnter`,
  `IconViewRoom1`...) verificados como presentes literalmente en los
  bytes del archivo real (búsqueda directa, no solo "el parser dice que
  sí").
- 103 objetos con URL de geometría, 50 nombres de archivo `.rwx`/`.rwg`
  únicos, verificados contra archivos reales existentes en
  `assets/GROUNDZERO/` (`FRAME.RWX`, `KIOSKBASE.RWX`, `POST1A.RWX`,
  `KEDGE.RWX`, `EARCH.RWX`, ...).
- Referencias de avatar (`avatar:Tre.rwg`, `avatar:Julie.rwg`...) usando
  un esquema de URL especial `avatar:` — consistente con el mecanismo de
  avatares ya documentado en `docs/rwg-bod-format-reference.md`.

## Lo que queda sin cubrir (fuera del alcance de "posición + geometría")

Las clases `Action`/`Sensor` (18 de las 33 clases del grafo real) se
parsean correctamente para mantener el stream sincronizado, pero sus
campos no se modelan específicamente en `WNode` — no hace falta para
renderizar la escena, solo para la interactividad (teleports, clicks,
animaciones), que está fuera del alcance de esta sesión.

---

## Conexión con el motor de renderizado: `WorldViewer.java`

`client/src/net/freeworlds/render/WorldViewer.java` carga un `.world`
real, resuelve cada URL de geometría contra archivos reales en disco
(relativos al directorio del propio `.world`, con búsqueda insensible a
mayúsculas porque las URLs del archivo no siempre coinciden con el
nombre real — ej. `"tex/frame.rwx"` en el archivo vs `Frame.rwx` real en
disco), y dibuja el árbol completo de una sala con el pipeline de
iluminación/materiales ya existente (`GlLighting`, verificado en
sesiones anteriores).

### Hallazgo real, crítico: la matriz de transformación de 16 floats no
### es una matriz afín válida tal cual viene en el archivo

Al intentar dibujar la primera sala real (`Reception`, `groundzero.world`
real), la pantalla salía **completamente negra** — 96 triángulos reales
enviados a OpenGL, sin ningún error de GL, pero nada visible. Diagnosticado
paso a paso, sin asumir nada:

1. Se descartó iluminación (probado con `GL_LIGHTING` desactivado y color
   blanco fijo — seguía en negro).
2. Se descartó culling de caras traseras (probado con
   `glDisable(GL_CULL_FACE)` global — seguía en negro).
3. Se descartó precisión de profundidad (el near/far plane se ajustó al
   tamaño real de la escena — seguía en negro).
4. **Proyectando a mano, en Python, un vértice real a través de la
   cámara+proyección exacta usada**, se encontró que la coordenada Z en
   espacio de recorte (NDC) caía en `0.9999991` — pegada al plano
   lejano, consistente con que la componente homogénea "w" de la matriz
   estuviera colapsando a 0 en vez de mantenerse en 1.
5. Volcando la matriz completa de 16 floats de un objeto real (no solo
   la traslación), se confirmó: **el float número 16 (el que en toda
   matriz afín válida debe ser 1.0) vale literalmente `0.0` en TODOS los
   objetos reales inspeccionados** — no es ruido aleatorio, es
   consistente. La traslación (floats 13-15) siempre tenía valores
   reales y coherentes con la posición esperada del objeto.

**Conclusión (⚠️ VERIFICAR el motivo exacto, pero el arreglo está
verificado empíricamente)**: la representación nativa "guts" de
`Transform` de RenderWare aparentemente no se molesta en escribir ese
valor redundante — dejarlo en 0 colapsa el cálculo homogéneo de
cualquier consumidor OpenGL estándar. Forzar el float 16 a `1.0` al leer
la matriz (`WorldRestorer.fixMatrix()`) resolvió por completo la
pantalla en negro — de 0 objetos visibles a geometría real reconocible.

### Estado de verificación por sala (evidencia honesta, no todo funciona
### igual de bien)

- **`Reception`** (`docs/renders/world_reception.png`): con el arreglo
  del float 16, se ve un hexágono limpio y reconocible (la geometría
  real `ShapeCeiling`/`hubceil1c.rwx`, un panel de techo hexagonal —
  nombre y forma coinciden) más varias líneas finas correspondientes a
  objetos `frame.rwx` — que YA se había verificado por separado
  (`RwxViewer` en solitario) que son geometría genuinamente delgada
  (bordes de marco), no un error de renderizado.
- **`IconViewRoom1`** (`docs/renders/world_iconviewroom1.png`, 16
  objetos, caja delimitadora real de 1000×500×435 unidades — coherente
  con una sala pequeña): se ve una **fila de postes evenly-spaced**,
  colores alternos, tamaños similares — exactamente la disposición
  esperada de una fila decorativa de postes (`post1a`/`post1b`/`post1c`
  RWX ya conocidos), sin superposiciones absurdas.
- ⚠️ **`ReceptionView1`** (`docs/renders/world_receptionview1_anomaly.png`,
  56 objetos): la caja delimitadora real sale desproporcionadamente
  grande (~38.600 × 42.300 unidades, 10-40x más grande que las otras
  salas comparables) y el render muestra triángulos gigantes,
  degenerados, radiando desde un punto — **evidencia clara de que el
  arreglo del float 16 no es suficiente para todos los casos**. Se probó
  además transponer el bloque 3×3 de rotación/escala de la matriz (otra
  hipótesis razonable dado que el float 16 sugiere una posible
  convención row-major vs column-major) — el resultado fue **peor**
  (`Reception` pasó de mostrar un hexágono reconocible a líneas
  degeneradas), así que esa hipótesis se descartó explícitamente en el
  código, no se dejó a medias.

**Conclusión honesta**: el pipeline `.world` → geometría real
posicionada → render funciona y está verificado para casos con
transformaciones simples (ejes alineados, sin rotación compleja) — dos
salas reales completas lo confirman con evidencia visual coherente. Para
objetos con rotaciones más complejas (aparentes en `ReceptionView1`) la
convención exacta del bloque 3×3 de la matriz de RenderWare sigue sin
resolverse — marcado ⚠️ VERIFICAR, no forzado con una solución sin
evidencia. Siguiente paso lógico: conseguir un objeto de prueba con una
rotación simple y conocida (ej. 90° en un solo eje) para aislar la
convención exacta sin la complejidad de una sala real completa.
