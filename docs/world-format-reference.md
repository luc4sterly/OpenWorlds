# Referencia del formato `.world`, reconstruida desde el código Java real del cliente

> **2026-09-26:** el motor nuevo se quitó del repositorio y con él su
> lector de `.world` (`WorldRestorer` y compañía), `WorldViewer`, sus checks
> y las capturas de `docs/renders/`. Lo que este documento cuenta del
> formato sigue valiendo; el código y las capturas que se citan abajo están
> en el historial de git, hasta el commit `8cd795d`. El cliente original
> lee los `.world` con su propio `Restorer`.

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

**Implementado y verificado end-to-end** (con el lector del motor nuevo,
`client/src/net/freeworlds/world/WorldRestorer.java`, hoy en el historial
de git): parsea `assets/GROUNDZERO/GROUNDZERO.WORLD` (un
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
parsean correctamente para mantener el stream sincronizado. Desde
2026-09-22 se conservan las que mueven texturas (ver "Acciones que cambian
texturas" abajo); el resto de campos (teleports, clicks, movimientos) no
se modela.

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

### Sesión 2 (2026-09-09): la convención real del bloque 3×3, leída del
### código fuente — no adivinada

El estado anterior dejaba `ReceptionView1` con geometría gravemente
degenerada, y la hipótesis de "transponer el bloque 3×3" ya se había
probado y descartado (empeoraba `Reception`). Esta sesión, siguiendo
instrucción explícita del usuario, se volvió al código Java real en vez
de seguir probando convenciones matemáticas "razonables" a ciegas.

**Evidencia real, no matemática abstracta**, encontrada en
`Transform.java`:

1. **`Transform.printGuts()`** (método de depuración real, NO nativo —
   a diferencia de `getGuts`/`setGuts`) imprime los 16 floats así:
   ```java
   for (int var8 = 0; var8 < 4; var8++) {      // var8 = fila
      for (int var5 = 0; var5 < 4; var5++) {   // var5 = columna
         String var6 = var2[var8 * 4 + var5];  // índice = fila*4 + columna
   ```
   Esto confirma **almacenamiento row-major**: `matrix[fila*4+columna]`
   — NO column-major como se había asumido sin verificar.
2. **`Transform.worldVecToObjectVec()`** (línea 285): 
   ```java
   Point3Temp var3 = Point3Temp.make(var1).vectorTimes(var2)...
   ```
   Un `Point3Temp` (el vector/punto) es el receptor de `.vectorTimes()`,
   y el `Transform` (la matriz) es el argumento — es decir, **el vector
   se multiplica a la izquierda: `v' = v · M`** (convención de vector
   fila), no `v' = M · v` (convención de vector columna, la que asume
   OpenGL/`glMultMatrixf` por defecto).

**Deducción matemática a partir de esta evidencia** (no una convención
elegida a priori): con `M` almacenada row-major como
`matrix[fila*4+columna]` y usada como `v' = v·M`, el array column-major
que espera `glMultMatrixf` para producir el mismo resultado (`v' = G·v`)
es `G = M^T`. Escribiendo el almacenamiento column-major de `M^T`:
`Garray[columna*4+fila] = M^T[fila][columna] = M[columna][fila] =
matrix[columna*4+fila]` — **exactamente el mismo índice que el array
crudo ya tiene**. Es decir: **no hace falta transponer nada** — pasar
los 16 floats tal cual a `glMultMatrixf` ya implementa correctamente la
semántica real `v·M` del cliente. Esto explica por qué transponer (sesión
anterior) empeoró las cosas: habría aplicado `v' = M·v`, la convención
equivocada.

### La causa real de `ReceptionView1`: no era la convención, eran bytes
### de relleno sin inicializar

Con la convención ya confirmada como correcta (sin transponer), se
comparó cada matriz real de `ReceptionView1` contra los únicos valores
matemáticamente válidos que una matriz afín puede tener fuera del
bloque de rotación/escala y traslación: los índices 3, 7 y 11 (última
columna de las filas 0-2) deben ser siempre `0.0`, y el índice 15
(esquina inferior derecha) debe ser siempre `1.0`.

**Hallazgo**: en TODO objeto problemático, esos 4 índices contienen
basura numérica — ni ceros ni ruido aleatorio, sino valores consistentes
por objeto (float denormalizado minúsculo en el índice 3, un float
enorme como `1.3E10` en el índice 7, un float "razonable pero falso"
como `0.125` en el índice 11). Un objeto compartido
(`WObLOGO`/`Rect843cy`, presente en `Reception` y `ReceptionView1` con
datos idénticos, confirmando que no es ruido de lectura) mostró
exactamente: `matrix[3]=1.0021795E-38, matrix[7]=1.3061306E10,
matrix[11]=0.125, matrix[15]=0.0`.

**Por qué solo afectaba a algunas salas**: escaneando las 3 salas de
prueba con un detector automático de valores fuera de rango, `Reception`
tenía exactamente 1 objeto afectado (pequeño, casi oculto),
`IconViewRoom1` tenía 0, y `ReceptionView1` tenía más de 15 — coincide
exactamente con por qué esas salas se veían bien y esta no.

**Interpretación más plausible (⚠️ el motivo último sigue sin
confirmarse a nivel de desensamblado nativo, pero el patrón es
inequívoco)**: la representación nativa "guts" de RenderWare
probablemente es en realidad una matriz afín compacta de 4×3 (rotación/
escala 3×3 + traslación 3×1), ampliada a 16 floats por conveniencia del
formato de guardado Java — y esa columna de relleno se serializó
directamente desde lo que hubiera en memoria nativa en ese momento, sin
inicializarse a cero. El renderizador nativo real, usando internamente
una matriz 4×3, nunca leía esa columna — así que forzarla a los únicos
valores matemáticamente válidos (`[0,0,0,1]`) reproduce el
comportamiento real del cliente original, en vez de confiar en bytes
que el propio cliente nunca usó.

**Arreglo aplicado** (`WorldRestorer.fixMatrix()`): además de forzar el
índice 15 a `1.0` (ya hecho la sesión anterior), ahora también se fuerzan
los índices 3, 7 y 11 a `0.0`. Sin transponer nada — la deducción de
arriba confirma que no hace falta.

### Verificación antes/después (mismas 3 salas, capturas reales)

- **`IconViewRoom1`** (`docs/renders/world_iconviewroom1_fixed.png`,
  0 objetos afectados por el bug): **idéntico** al render anterior — el
  arreglo es quirúrgico, no toca datos que ya eran válidos.
- **`Reception`** (`docs/renders/world_reception_fixed.png`, 1 objeto
  afectado): el hexágono y las líneas de `frame.rwx` siguen igual de
  reconocibles que antes, y ahora aparece además un pequeño cuadrilátero
  rojizo correctamente posicionado cerca del centro — el objeto que
  antes tenía datos basura (`Rect843cy`) y que antes se proyectaba fuera
  de cualquier posición razonable.
- **`ReceptionView1`** (antes: `docs/renders/world_receptionview1_anomaly.png`,
  después: `docs/renders/world_receptionview1_fixed.png`) — cambio
  drástico: los triángulos gigantes degenerados desaparecen por
  completo, sustituidos por objetos reales reconocibles (un panel, unas
  formas pequeñas, una figura delgada). Verificado además con datos: se
  volcó la posición mundial real de los 56 objetos, y el resultado tiene
  sentido geográfico — un cúmulo de mobiliario de picnic
  (`grill`/`yard_table`/`cokecan`/`bottle1`/`umbrella`/`steak`/`fork`,
  todos entre las coordenadas ~(100-400, -2000, 300-400)), cactus y rocas
  dispersos por una zona exterior grande, un camino (`road_01.rwx`) en
  el borde, y paredes/techo de un edificio (`sideh*`/`roof.rwx`) — la
  caja delimitadora sigue siendo grande (~38.600 unidades de ancho) pero
  **es real**: es una escena exterior genuinamente extensa, no un
  artefacto.

**Conclusión**: el bug de `ReceptionView1` no era la convención
matemática del bloque 3×3 (esa ya estaba bien implementada, confirmado
ahora con evidencia del código fuente real en vez de solo por
descarte), sino 4 bytes de relleno sin inicializar en el propio formato
de guardado del cliente original, que había que reconocer y descartar
explícitamente. El pipeline `.world` → geometría real posicionada →
render queda verificado en las 3 salas de prueba, incluyendo la que
antes fallaba.

### `Portal` v8/9: conectividad real (2026-09-16)

Confirmado en GroundZero (version 9, `WORLD_DEBUG=1`): tras
`farSideIsPortal` y `allowDownload` se lee `farSidePortalName` (string),
`farSidePortal` (**referencia de objeto** via `restoreMaybeNull`: resuelve
por identidad, no por nombre; `Restorer.java:165-175`, `Portal.java:689`),
`farSideWorld`, `farSideRoomName` y `farx/fary/farz/fartheta`. Esos 4
floats solo cuentan cuando `farSideIsPortal=false`: en las conexiones
portal-a-portal valen 0.0 en el archivo porque el cliente los recalcula en
`postRestore()` → `recomputeFarPosition()` (`Portal.java:711-722`,
`220-240`). `WorldRestorer.readPortal` ya no los descarta; el stream se
sigue consumiendo igual (578 nodos, `END PERSISTER` intacto). De los 87
portales de GroundZero, 56 resuelven dentro del mundo, 2 apuntan a otro
`.world` y 29 estan desconectados en el propio dato.

### Acciones que cambian texturas (2026-09-22)

`WorldRestorer` guarda ahora, en vez de descartarlos:

- `WObject.eventHandlers` y `WObject.actions` (`WNode.handlers`/`actions`),
  en el orden real de `WObject.restoreWObjectState`: contents, handlers,
  actions (la versión 0 no guarda actions; **la 1 sí**, y el parser la
  saltaba: arreglado, aunque GroundZero no usa esas versiones).
- `Sensor.actions` (en `WNode.actions` del sensor), `SequenceAction`
  (componentes, `loopCount`, `loopInfinite`; en v0/v1 un `loopCount`
  negativo es infinito), `WaitAction.duration` y los campos de
  `AnimateAction` (`cycleTime` ms, `cycles`, `infiniteLoop`, `frameList`;
  en v0/v1 `cycleTime` viene como float y `infiniteLoop = cycles == 0`).

Qué hay en GroundZero (dueño = el objeto en cuya lista de acciones está):

| Sala | Dueño | Disparo | Materiales | Cadencia |
|---|---|---|---|---|
| ReceptionView1 | 2× `Rect840Flag2` | StartupSensor | `f12h*.mov` … `f82h*.mov` | 8 en 1000 ms, bucle |
| IconViewRoom1 | `Rect840` | StartupSensor | `drs12v*.mov`, `drs52v*.mov` | 2 en 6000 ms, bucle |
| AvatarEnter | 4 Rects (suelo, techo, 2 muros) | StartupSensor | `avflr1/2/3/2.cmp` | 4 en 1000 ms, bucle |
| Reception | 4 kioscos `Rect84cyan1..4` | StartupSensor → SequenceAction infinita | `knews*`/`kevent*`/`kstore*.cmp` | Wait 1 s + Animate (5 en 500 ms, 1 ciclo) … |

En el original el StartupSensor dispara en el primer frame de la sala y
las acciones vivas se llaman una vez por frame (`RunningActionHandler`).
En `ReceptionView1` el StartupSensor lanza además 8 `MoveAction` (pájaros,
avión y logo) que no cambian texturas.

### Celdas de un Rect: `Surface.addSubPolys` (gamma.dll `0x004206d0`)

Con un material de varias texturas (`Nh*`/`Nv*`, ver
`docs/cmp-texture-format-reference.md`) el Rect no es un cuadrilátero sino
una rejilla de celdas. Lo que dice el binario, que **no** es lo que dice el
C de Ghidra de esa función:

- El C lee los vértices 1, 2 y 4 sobre las mismas variables locales y
  parece usar solo el 1 y el 4 para todo. En el desensamblado,
  `0x00420768-0x00420794` guarda `x2-x1` y `u2-u1` en `[ebp-0x8c]` y
  `[ebp-0x88]` **antes** de leer el vértice 4, y `0x00420b0c-0x00420b1a`
  divide `x2-x1` entre `hRes*(u2-u1)`; `z` y `v` sí salen de los vértices
  1 y 4 (`0x00420b00-0x00420b0b`). En un Rect (vértices de
  `Rect.addRwChildren`: 1 = (0,0,0), 2 = (1,0,0), 4 = (0,0,1)) usar el
  vértice 4 para x/u da 0/0 y ninguna celda.
- Las celdas inicial y final se redondean con `frndint` bajo dos palabras
  de control distintas: `0x00480a7c` = `0x077f` (hacia −∞) para uMin/vMin
  y `0x00480a78` = `0x0b7f` (hacia +∞) para uMax/vMax.
- Dentro de cada bloque se recorre la fila de celdas de abajo arriba y de
  izquierda a derecha (salvo volteo, flags `0x100000`/`0x80000`, que
  alterna de bloque en bloque), y el polígono *i* lleva el material
  *i* mod *hRes·vRes*.

En el puente: `NativeScene.addSubPolys`, con casos a mano en
`bridge/test/SubPolysCheck.java`.

### Portales: estado, cruce y llegada, como el original (2026-09-22)

Corrige la sección de 2026-09-16 ("56 resuelven… 29 desconectados"):

- **Cruzables = estado 2 y bumpables: 53/87.** El estado sale de
  `Portal.postRestore` → `newFarSide` (con referencia al portal lejano) o
  `reset()`/`findFarSidePortal` (sin ella). `WObject.detectBump` solo mira
  objetos con `flags` bit 1 (`getBumpable`): los 3 espejos
  autoconectados (`WestPortal1AuditoriumHall`, `EastPortal2AuditoriumHall`,
  `EastPortalReflection`, flags `0x5`) no son bumpables y el original nunca
  los cruza; el visor antes sí (contaba 56).
- **Los 31 que no cruzan, por causa**:
  29 sin `farSideRoomName` (`reset()` los deja en −1: 14
  `WestPortalNNTrigger` de ReceptionView1 y 6 `EastPortal1Patch*Trigger`
  de Garden MazeC7b, invisibles y bumpables, que solo disparan acciones;
  y 9 extremos de portales de un solo sentido: `EastPortal1..3ReceptionView2`,
  `EastPortal2..6ReceptionView1`, `WestPortal2Garden MazeC7b`); 2 a otro
  `.world` (`UserHomePortal` → `home:AvatarGallery/avatar.world`,
  `WestPortal1DcnEnter` → `rel:home:Dcn/dcn.world`), que no están en el
  corpus (ni en `assets/` ni en `cachedir/`): el original los cargaría o
  los descargaría (`World.load` → `loadedURLSelf`, `NetUpdate.loadWorld`).
- **Detección**: `PassthroughBumpCalc` corta el camino del piloto contra
  el borde inferior del portal (posición + `(1,0,1)·M`, en x/y) con
  `BumpEventTemp.isCollision`, que solo acepta un sentido (camino a la
  izquierda del borde = hacia +Y local).
- **Llegada**: `_p2pxform` de `Portal.setTransform` (gamma.dll
  `0x0041b170`) = inversa(LTM sin la escala propia) · [espejo: −columna x]
  · `Rz(fartheta)` · `T(farx,fary,farz)`, con `recomputeFarPosition`
  (posición propia del portal lejano + `(1,0,1)·M` en x/y salvo espejo;
  `fartheta = (−getYaw + 180) % 360`) y `getYaw` de gamma.dll
  `0x00425440`. El piloto entero se multiplica por esa matriz: la
  posición de corte (+0.2) y, como vectores, el resto del camino y el
  avance. Antes el visor ponía al jugador en `farx/fary` (la esquina
  lejana del portal, fuera cual fuera el punto de cruce: cambia en 53/53)
  con un rumbo deducido que discrepa del real en 40/53 portales
  (típicamente 180°, mirando al portal del que se sale).
- Comprobación: los 44 pares de ida y vuelta dan `p2p·p2p' = I` (error
  máximo 1.2e-4), lo que no pasaría con el signo de `getYaw` al revés.
