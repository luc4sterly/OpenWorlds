# Pipeline de iluminación y materiales del motor (fase 2, sesión de "motor de renderizado")

Todo lo de este documento es sobre `client/src/net/freeworlds/render/`
(`GlLighting.java`, `RwxViewer.java`, `RwgViewer.java`). Regla de alcance
seguida en toda la sesión (fijada por el usuario, no negociable): réplica
fiel del pipeline fijo de RenderWare 2 — sin shaders modernos, sin PBR,
sin ninguna mejora gráfica. Todo lo implementado usa el pipeline de
función fija de OpenGL (`glLight`/`glMaterial`/`glBegin`-`glEnd`), que es
un equivalente period-correct de lo que RW2 hacía, no una modernización.

## Modelo de iluminación — verificado en Java puro, sin necesidad de Ghidra

A diferencia de RWX/RWG/`.cmp`, el modelo de iluminación por defecto de
una sala **SÍ está en el cliente Java decompilado**, sin tocar código
nativo:
`editor/worldsplayer_source_editor-main/source/NET/worlds/scape/Room.java`:

```java
private Point3 lightPosition = new Point3(-1.0F, 1.0F, -1.0F);
private Color lightColor = new Color(255, 255, 255);
```

y `RoomEnvironment.addLight()`:

```java
this.lightid  = Room.addLight(sceneID,  pos.x,  pos.y,  pos.z, r, g, b);
this.lightid2 = Room.addLight(sceneID, -pos.x, -pos.y, -pos.z, r*0.5, g*0.5, b*0.5);
```

**Confirmado, no inventado**: exactamente **2 luces por sala**, no una,
no más — una luz "clave" en la dirección `(-1, 1, -1)` blanca, y una luz
de "relleno" en la dirección exactamente opuesta con la mitad de la
intensidad de color. Implementado en `GlLighting.init()` como
`GL_LIGHT0`/`GL_LIGHT1` direccionales (`w=0`), con esos valores reales.

⚠️ **VERIFICAR** (sin evidencia real encontrada, valores razonables no
confirmados):
- No existe ninguna "luz ambiental" separada en el código — el escalar
  `ambient` de material RWX (`RwxMaterial.ambient`) no tiene contraparte
  de luz ambiental documentada. Se optó por igualar el componente
  `GL_AMBIENT` de cada luz a su propio `GL_DIFFUSE` (ver comentario en
  `GlLighting.setLight()`) en vez de inventar una constante de luz
  ambiental separada.
- El exponente de brillo especular (`GL_SHININESS`) no tiene campo RWX
  equivalente — se usó `8.0f` como valor bajo, no glossy, típico de la
  época, marcado explícitamente como no verificado en el código.

## Pipeline de materiales — verificado con 2 archivos reales distintos

- **Opacidad** (`RwxMaterial.opacity`, ya parseada desde `Opacity` en
  RWX): conectada a alpha blending real (`GL_SRC_ALPHA`/
  `GL_ONE_MINUS_SRC_ALPHA`), no una técnica moderna de order-independent
  transparency.
- **`MaterialModes Double`** (doble cara): **hallazgo nuevo esta
  sesión** — no estaba parseado antes (el comentario original del parser
  decía explícitamente que se ignoraba, correcto para la fase 1 de solo
  geometría). Se encontró uso real en
  `assets/GROUNDZERO/YARD_TABLE.RWX` (`MaterialModes Double`, 6
  ocurrencias) y se implementó: sin él, el culling de caras traseras
  ocultaría el envés del tablero de la mesa; con él, se ve — **verificado
  visualmente** (`docs/renders/table_lit.png`): el envés violeta oscuro
  del tablero es visible desde abajo, algo imposible sin doble cara
  activa.
- **Normales**: RWX no tiene normales por vértice parseadas todavía
  (fuera del alcance de la fase 1); se usa la normal de cara calculada
  por producto cruzado (`GlLighting.faceNormal`), con `glShadeModel(
  GL_FLAT)` — sombreado por faceta, no suavizado, porque no hay datos
  reales de agrupación de suavizado que lo justifiquen. Esto es
  deliberadamente conservador: no inventar suavizado que no se puede
  verificar.

## Verificación real (capturas + histograma de color)

- `docs/renders/basket_lit.png`: mismo objeto que la sesión de fase 2
  anterior (`BASKET.RWX`), antes con color plano único; ahora con
  degradado real. **Histograma de color verificado**: el color base del
  cuerpo (`0x893232`) ya NO aparece como color único — aparecen ≥6 tonos
  distintos derivados de él según la orientación de cada faceta respecto
  a las 2 luces, evidencia de que la iluminación N·L está funcionando
  por faceta, no solo "compila y no revienta".
- `docs/renders/table_lit.png`: confirma `MaterialModes Double`
  funcionando (envés visible, ver arriba).

## RWG: iluminación aplicada + un hallazgo y un artefacto sin resolver

- `RwgVertex` ya traía una normal por vértice REAL parseada del formato
  (`floats[3:6)`, ver `docs/rwg-bod-format-reference.md`) — se usa
  directamente en vez de recalcularla, con una excepción real encontrada
  esta sesión:
- ✅ **Resuelto 2026-09-15** (texto anterior, histórico: "8 vértices
  planos con normal (0,0,0)" y "z-fighting en 2 de 6 caras con bobinado
  inconsistente"). No era z-fighting ni bobinado: `RwgParser` indexaba
  `PLST` contra `VLST[0..]`, pero `VLST[0..7]` es la bounding box del
  clump y los vértices reales empiezan en el registro 8 (RWL21.DLL:
  `RwGetClumpNumVertices` = count−8, `RwGetClumpVertex` → registro n+7).
  El índice mal resuelto duplicaba las caras ±Z (coplanares → las
  bandas), dibujaba 2 caras sobre las esquinas de la bbox (las "normales
  0") y dejaba sin dibujar las ±Y (los "huecos" con culling). Con los
  índices correctos las normales guardadas coinciden con las geométricas
  (3466/3466 polígonos en cube/ball/table/e3/IDLE), los quads son lazos
  convexos (abanico) y el bobinado es consistente. El culling sigue a
  doble cara porque el modo de material de RWG no está decodificado.
  Render: `docs/renders/cube_rwg_bbox_fix_lit.png` / `_wire.png`. De
  paso, `RwgViewer` captura antes del swap (en macOS salía negro).
- `ball.rwg` (512 triángulos, esfera facetada): el patrón tipo
  "bowtie/diamante" grande que cruza la esfera en el render con
  iluminación es consistente con los triángulos-abanico de los polos de
  una esfera UV-triangulada (naturalmente más grandes que los
  triángulos ecuatoriales) vistos con ambas caras activas — una
  explicación plausible respaldada por cómo se construyen habitualmente
  las mallas de esfera, no confirmada al 100% con más evidencia
  adicional por límite de tiempo de esta sesión.

## Cómo probarlo

```
java -cp out:../tools/lwjgl/*.jar net.freeworlds.render.RwxViewer <archivo.rwx> --screenshot out.png [--unlit] [--wireframe]
java -cp out:../tools/lwjgl/*.jar net.freeworlds.render.RwgViewer <archivo.rwg> --screenshot out.png [--wireframe] [--angle N]
java -cp out:../tools/lwjgl/*.jar net.freeworlds.render.BodViewer <archivo.bod> --screenshot out.png [--wireframe] [--unlit] [--angle N]
```

## `WorldViewer`: ventana interactiva GroundZero (2026-09-13)

```
# ventana visible e interactiva (ESC para salir), sala real de groundzero.world
DISPLAY=:100 java -cp out:../tools/lwjgl/*.jar net.freeworlds.render.WorldViewer <archivo.world> <sala> --window
# + captura del primer frame, dejando la ventana abierta
... <archivo.world> <sala> --window --screenshot out.png
# batch sin cambios (ventana oculta, 1 frame): <sala> --screenshot out.png, ALL --screenshot-dir dir, --list-rooms
# cámara interior voladora (W/S volar, A/D strafe, flechas girar/cabecear, E/Q subir/bajar, ESC salir)
... <archivo.world> <sala> --inside [--eye x,y,z] [--look x,y,z] [--up x,y,z] [--screenshot out.png]
```

## Lanzador con log: `tools/run-game.sh` (2026-09-13)

`tools/run-game.sh [sala] [args del WorldViewer...] [--log-dir dir]
[--display :N] [--build] [--no-shot]` — compila si se pide (`--build`),
reutiliza `DISPLAY` si hay X o levanta un Xvfb propio (100-110, con
limpieza al salir), añade `--screenshot` automático salvo `--no-shot`
o modos con salida propia (`ALL`/`--list-rooms`), y guarda todo en
`logs/worldviewer-<sala>-<fecha>.log` (cabecera: fecha, git rev, java,
comando + resumen final con exit code). `logs/` está gitignored.

## Texturas bien: modelo de material de la referencia (2026-09-13)

Dos reglas de `three-rwx-loader` (`RWXLoader.js:531-582`, hechos de
código, no interpretación) que el pipeline violaba y oscurecían toda
superficie texturizada (LizCave a ~5/255 de media):

1. **Texturizada → base blanca** (`tint` nunca se activa en la
   práctica): el `Color` del archivo se ignora con textura, no se
   multiplica. En el corpus real las 297 refs `.cmp` son todas no-`Lit`
   (`Foreshorten`); `Lit` solo existe con `Texture NULL`.
2. **Surface gateada por `Lit`**: sin `Lit`, tripleta default AW 2.2
   `[0.69, 0, 0]`; `brightnessRatio = max(surface)` escala la base en
   ambos casos (con y sin textura).

Implementado en `RwxMaterial` (`textureModes`, `effectiveAmbient/
effectiveDiffuse`, `brightnessRatio()`, `baseColor()`) +
`RwxParser` (caso `texturemodes`) + `GlLighting.applyMaterial`
(misma base escalada a ambiente Y difuso). El ambient de luz se
retunó de 1.0× a **0.15×** por luz (con 1.0× todo clipeaba a blanco
sin sombrear, medido 19.8% en Auditorium): heurística documentada en
`GlLighting`, sin ground truth iluminada del original. Resultado
medido: 2-3× brillo, más colores en las 4 salas de referencia, 0%
clip, 25/25 salas GL 0.

## Z-up + spawn real (2026-09-13)

El cliente es Z-up (`Transform.raise=+Z`, `yaw` sobre Z) y su spawn
está en `worlds.ini` (`Reception@1872,1229,150,yaw125` — formato
confirmado en `Pilot.getURL()`): `WorldViewer` usa Z-up por defecto
(órbita exterior sobre Z, interior con yaw en x/y; `--up 0,1,0`
restaura Y-up). `./tools/run-game.sh` sin args abre la ventana en
ese spawn mirando al kiosko (la dirección del yaw admite dos signos;
se eligió la que muestra contenido, documentado en
`worlds-chat-project.md`).

## Rects: el contenido real de las salas (2026-09-13)

Paredes/suelos/carteles son nodos `Rect` (374 en GroundZero), no
Shapes: plano unitario local **X/Z** (verificado contra far-corners
reales) con UV u/v+offsets y `Material` propio (URL de textura en
v2+). Texturas: `dtex/*.cmp` absolutas (12 en
`assets/.../GroundZero/dtex/`, del servidor vivo) + `tex/*`
relativas (sufijo anim `2h*2v*`); cobertura 42/55 URLs (los 13
`.mov` son otro contenedor — fallback plano). Dibujado: quads con
UV/tiling real, doble cara + `GL_LIGHT_MODEL_TWO_SIDE`, misma
base-blanca/ratio que RWX. Los 147 Rects teal planos son color real
del stream, no default.

## Cobertura total: `.mov` + sufijos anim + BMP (2026-09-13)

- `.mov`: `CmpStage1.decodeMovFrame0` (misma cabecera, tablas
  multi-frame localizadas por firma `field0==64`, solo grupo/frame
  0) + `CmpTexture.loadMov` (índice 255→blanco). Verificado
  byte-exacto vs `cmpview.exe` (`windr1`, `cbirda4` 16384/16384).
- URLs con sufijo de animación (`cbirda42h*2v*`→`cbirda4`,
  `time2h*`→`time`, `winwin12h*2v*`→`winwin1`: un dígito + h/v,
  stem exacto siempre primero) y case-insensitive en Linux.
- `.bmp`→`.cmp` del mismo stem si existe gemelo (`cstgbs3`;
  `pceil2` sin gemelo queda plano, honesto).
- Medido en escena completa: `Texture 47/47` + `Rect 55/55`
  (187 refs) — cero texturas con loader sin cargar. `.mov` con
  contenido verificado en escena (bandera f3 en RV1).
- Abierto: 36 `RectPatch` (material nulo + cadena de versiones
  dudos) — evaluado, no implementado.

Sin `--window` todo sigue igual que antes (ventana oculta,
screenshot de una pasada — verificado md5-idéntico tras el cambio).
Bajo XWayland sin GLX útil (`DISPLAY=:0` en esta máquina) el render
sale negro aunque GL error sea 0 — usar Xvfb (`:100`) para
verificación repetible. Nota honesta: las salas texturizadas se ven
más oscuras que el baseline plano (p. ej. `LizCave` media 132.7 →
14.2, ver `worlds-chat-project.md`) — `GL_MODULATE` apilado, sin
ground truth del cliente original para decir si RW2 hacía lo mismo.

## `.bod`: ensamblado por placeholders + render en bind pose (2026-09-10)

Implementado en `client/src/net/freeworlds/render/BodViewer.java` - era
el punto explícito "What's NOT done yet" de
`docs/bod-format-reference.md`. Regla de alcance respetada: pipeline de
función fija, sin skinning/animación inventada (bind pose), sin
suavizado, sin texturas.

- **Ensamblado (regla oficial, no inventada)**: `RWXTOBOD.PL` dice
  literalmente "Any transform value in a part is moved into a placeholder
  in the parent". Verificado en datos reales antes de implementarlo: los
  16 roots de `tina.bod` tienen `t=(0,0,0)` salvo pelvis, y los bboxes
  por parte son locales (centímetros del origen) - sin resolver
  placeholders todo colapsaría en un punto. Raíz = la parte no
  referenciada por ningún placeholder (pelvis(1) en los 51 archivos
  reales); el origen mundo de cada parte es el del padre más la
  traslación del placeholder que la referencia. Huérfanos e índices
  inválidos se cuentan y reportan, nunca crashean (0/0 en todo el corpus).
- **Material**: `.bod` solo trae RGB plano por clump; `RWXTOBOD.PL` dice
  que ambient/diffuse/specular "are ignored" sin dar mapeo numérico -
  se reutiliza la convención placeholder de `RwgViewer` (ambient 0.3,
  diffuse 0.8, specular 0.1, opacidad 1), marcada ⚠️ VERIFICAR igual que
  allí. Sin transparencia (el formato no la tiene).
- **Normales/culling**: `.bod` no trae normales - normal de cara por
  producto cruzado + `GL_FLAT`, como RWX. Winding sin verificar: ambas
  caras visibles, como RWG.
- **Verificación real**: 51/51 archivos ensamblan limpio
  (`orphans=0 badIndices=0`); `tina.bod` coloca exactamente sus 2350
  triángulos parseados; `docs/renders/bod_tina_avatar.png` (figura con
  pelo rojo, torso, falda negra, zapatos rojos),
  `bod_ogre_avatar.png` (figura voluminosa con hombreras) y
  `bod_robed_avatar.png` (figura con túnica de 8 partes, sin piernas -
  coherente con una túnica) son humanoides upright reconocibles desde
  dos corpus independientes. Histograma de `tina`: 6509 px no-fondo en
  336 tonos desde ~20 colores base - sombreado N·L por faceta activo,
  no color plano.

## `WorldViewer`: pipeline de materiales conectado a texturas reales por
## nombre, sobre la escena `.world` completa (2026-09-11)

Objetivo de esta sesión: que cada objeto RWX de una escena `.world` real
(no geometría de prueba suelta) cargue de verdad la textura `.cmp` que su
propio material referencia, con fallback honesto a color plano cuando no
sea posible - nunca un color inventado ni una textura de relleno.

**Fuente real de las texturas**: `assets/WorldsPlayer/GroundZero/
content.zip` (ya versionado, un zip real de la instalación original de
2001) contiene 159 archivos `.cmp` reales bajo `tex/*.cmp` - la misma
convención de directorio `tex/` que ya usaban los `.rwx` de geometría
extraídos en sesiones anteriores. `WorldViewer.resolveTextureArchive()`
extrae ese zip real (ya trackeado, nada nuevo que versionar) a una caché
de ejecución bajo `/tmp` (no comprometida a git) la primera vez que se
necesita, y `CmpTexture.load(dir, nombre)` se reutiliza tal cual para
decodificar - cero cambios de API necesarios en `CmpTexture` desde este
lado del pipeline.

**Regla de alcance respetada en el filtrado**: `GL_NEAREST`, no
`GL_LINEAR` - no hay evidencia de que RenderWare 2 aplicara filtrado
bilinear, así que se usa la opción conservadora sin inventar suavizado
(también corregido en `RwxViewer`'s demo, que antes usaba `GL_LINEAR`
sin justificación real).

**Cobertura real, contabilizada y reportada, nunca redondeada al alza**
(`WorldViewer.resolveTexture()`/`printTextureCoverage()`): cada
referencia `Texture` no-nula de cada material se cuenta; si
`CmpTexture.load` lanza excepción (archivo `.cmp` real sin las tablas de
Stage 1 capturadas, o - de momento el caso esperado - Stage 1 mismo
todavía no implementado para ese archivo) o el nombre viene con
extensión `.bmp` (sin loader BMP en este pipeline, fuera de alcance esta
sesión), el material se cuenta como "no resuelto" con la razón real, y
sigue dibujándose con su color plano ya verificado - la ruta original,
sin cambios. Nunca se sustituye un material sin textura decodificable
por un color o patrón inventado.

**Verificación de no-regresión**: con 0 texturas aún decodificables
(estado de esta pieza antes de que Stage 1 - línea paralela de esta
misma sesión - esté disponible), el render de `Reception` es **AE=0,
pixel-idéntico** al `docs/renders/world_reception_fixed.png` ya
committeado de una sesión anterior - confirma que conectar el pipeline
de texturas no alteró un solo píxel del camino de fallback existente.

**Cobertura real medida sobre la escena `.world` completa** (25 salas,
`WorldViewer ... ALL --screenshot-dir`): **47 nombres de textura únicos
referenciados, 124 referencias de material en total** entre todos los
objetos realmente colocados por el grafo de escena (no un grep estático
de todos los `.rwx` del directorio, que da 72 - ese número incluye
modelos nunca instanciados en esta escena). Estado de decodificación:
ver la sección de `.cmp` Stage 1 para el resultado real, actualizado
por separado ya que es un frente de trabajo independiente de esta
pieza.

## Reconexión final: Stage 1 completo, texturas reales en la escena
## (2026-09-13)

Con `.cmp` Stage 1 en 159/159 del corpus real (ver
`docs/cmp-texture-format-reference.md`, "Estado final"),
`WorldViewer.resolveTexture()` se cambió de `CmpTexture.load(dir,
nombre)` (el camino legacy que exigía streams pre-capturados a mano,
solo disponibles para 3 archivos tutorial) a
`CmpTexture.loadRaw(archivo.cmp)` (el decodificador Stage 1 real, sin
archivos auxiliares) - un cambio de una sola línea en el punto de
resolución, cero cambios en el resto del pipeline (caché, contabilidad
de cobertura, fallback a color plano, subida a GL).

**Resultado real, medido, no estimado**: renderizando las 25 salas de
`groundzero.world` (`WorldViewer ... ALL --screenshot-dir`), el log
imprime `Texture coverage: 47/47 unique texture names decoded (124
total material references seen)` - **cobertura completa**, de 0/47 a
47/47 en la misma escena real, sin fallback a color plano por textura
faltante en ningún material.

**Confirmado visualmente, no solo por el contador**: capturas nuevas en
`docs/renders/world_reception_textured.png` y
`docs/renders/world_iconviewroom1_textured.png` muestran variación de
color/textura real por superficie (pisos con tono madera/rojizo,
paredes más oscuras) donde antes había un único color plano por
material. Diff de píxeles directo contra el `world_reception_fixed.png`
de la sesión de conexión del pipeline (cuando 0 texturas decodificaban):
4158/786432 píxeles distintos - un cambio real y esperado, no ruido
(la sala es pequeña en cuadro - ver nota de alcance abajo - así que la
mayoría del cuadro sigue siendo fondo/geometría sin textura visible a
esa escala, pero la fracción de píxeles con textura real cambió
exactamente donde se esperaba).

**Fuera de alcance, notado honestamente**: el encuadre/escala de cámara
de estas capturas (la sala aparece pequeña y lejana, ya así en el
`_fixed.png` de referencia de la sesión anterior) es un problema
preexistente de cámara/framing, no relacionado con `.cmp` ni con este
cambio - no se tocó esta sesión.

## Fondo infinito con seguimiento de camara (2026-09-13)

`WorldViewer` dibujaba el `infiniteBackground` de cada sala con su
transform estatico de archivo, como el resto del grafo. La documentacion
oficial (`GammaDocs/Gamma_Overview.html`, "Sky, Ground, and Infinite
Background") define que el fondo infinito es "una habitacion en el
espacio exterior que rodea la habitacion principal" cuya "escala nunca
parece cambiar" - una vista "infinitamente distante", es decir, sin
paralaje al moverse la camara. Con geometria estatica, el fondo tenia
paralaje normal de objeto cercano (verificado: al desplazar el ojo
+500x en Reception, la cobertura de muros de fondo `skyXX` cambiaba de
extension en pantalla).

**Cambio** (`WorldViewer.drawInfiniteBackground`): en modo `--inside`,
el subarbol de fondo se dibuja trasladado por `(ojo - ref)`, donde `ref`
es el ojo del frame 0. En el frame 0 el offset es exactamente 0 -
verificado md5-identico contra el render estatico previo, tanto en
exterior (`Reception` batch) como interior (vista spawn
`1872,1229,150`); al volar, el fondo acompana a la camara (distancia
infinita efectiva). El modo exterior orbita/maniquete conserva la
colocacion estatica verificada antes. `skyColor`/`groundColor` son null
en las 25 salas reales (el cliente no dibuja nada en ese caso, solo
ahorra un draw - segun la misma doc oficial), asi que el color de
borrado oscuro se conserva como fallback documentado, no como color
"real" de cielo.

## Fondo infinito: estatico por defecto, `--infinite-follow` opcional
## (2026-09-13, correccion)

El seguimiento de camara del fondo infinito se habia activado siempre en
`--inside`, pero al caminar se veia al terreno exterior "seguir" al
usuario (reportado como bug — y con razon): el anillo de cielo de
GroundZero esta modelado a medida de la sala (Reception: x -700..2100,
y -1100..1000, z -100..250), no es una cascara infinitamente grande, asi
que al fijarlo a la camara los muros cercanos del decorado se desplazan
con el caminante en vez de quedarse quietos.

**Cambio**: colocacion estatica por defecto (como el resto del mundo);
`--infinite-follow` lo fija a la camara solo si se pide explicito
(aspecto "infinitamente distante", paralaje cero). Frame 0 identico en
ambos modos (offset exactamente 0 — verificado md5-identico al render
estatico previo en vista spawn y exterior, GL error 0).

## Fondo infinito en dos pasadas + avatares `.bod` en sala (2026-09-13,
## el juego corre)

**Fondo (sustituye la version "trasladar por camara viva").** El
`glTranslatef(camEye)` ataba el subarbol a la posicion del ojo en la
misma pasada — en la practica el fondo "seguia" al caminante. Ahora el
fondo se dibuja en SU propia pasada con SU propia camara: posicion fija
en el origen local de la cascara + orientacion de la camara viva
(`Gamma_Procedures.html`: "viewed from a Camera at 0,0,0"; verificado
que el origen cae dentro del anillo: Reception x[-2100,700]
y[-1000,1200]). La sala va en una segunda pasada con la camara viva
(depth limpiado entre pasadas: la sala siempre delante, el fondo es
backdrop). Efecto medido: spawn de Reception con colinas al E/O y cielo
arriba en todas direcciones (`world_spawn_two_pass_bg.png`), nunca en
una esquina y sin tocar la colocacion de archivo. 25/25 salas GL 0.
Consecuencia honesta: sin paralaje de traslacion (la "escala que nunca
parece cambiar" de la doc) — en muros cercanos modelados a medida se
nota fijo al caminar; eso es lo documentado del original.

**Avatares.** Las 6 refs `avatar:Nombre.rwg` (galerias IconViewRoom1a/b/
c/e/f/g) ya se dibujan en bind pose con las 2 luces reales: resolucion
por nombre al `.bod` base oficial del mismo nombre
(`base-avatars/jing/julie/paul/roxanne/simon.bod`; Tre no existe y usa
`aura.bod`, el default real del cliente). Escala global x1000
documentada como heuristica (los `.bod` decodifican a ~0.17 de alto;
el cliente espera ~189 — `Drone.java avatarHeightChangedTo(189.0F)`),
pies en el origen del nodo, +Y bod a +Z mundo. Sin skinning/animacion.
Verificado: Roxanne 2229 tris propios, Tre 588 via aura, 25/25 GL 0
(`world_iconviewroom1a_roxanne.png`,
`world_iconviewroom1g_aura_fallback.png`).

**El juego corre:** `tools/run-game.sh` (sin args = spawn real de
Reception en ventana interior) + `--detach` verificados en `:100`
(ventana, frame 0, ESC/kill limpio).

## Fondo infinito como camara en el origen + bumpers invisibles
## (2026-09-13, revision de cabo a rabo del mapa — fondo SUPERSEDED)

**Fondo: ver la seccion "dos pasadas" de arriba** (sustituye lo de
abajo: el `glTranslatef` por la camara viva ataba el fondo al ojo en
la misma pasada y al caminar se notaba que "seguia"). Auditoria con
numeros (sigue valida): solo 2 de 25 salas tienen `infiniteBackground`
no vacio (Reception 34 Rects, ReceptionView1 33); las otras 23 lo traen
vacio (el autor lo dejo en blanco "para acelerar el render", doc
oficial). Dibujado en coordenadas absolutas con la camara de la sala,
el anillo quedaba a (-2561,-974) del centro en Reception y
(-6253,+1019) en RV1: literalmente tirado en una esquina — por eso la
pasada propia con camara en el origen. Limites honestos: huecos de
cielo donde el autor no puso paneles (sectores sin geometria = vacio,
no se inventa nada).

**Bumpers invisibles (hallazgo de la misma auditoria).** LizCave se veia
llena de cristales teal gigantes: son `Rect942CyanBump` (40), muros de
colision con color teal real #00FCF8 y `flags=2` (bumpable, NO visible;
bit 0 = visible verificado en `WObject.getVisible()` del decompilado).
El parser tiraba los flags y el visor los dibujaba. Ahora `WNode.flags`
guarda el int real y el visor salta hojas invisibles al dibujar y al
encuadrar (hojas solo: nunca se oculta un subarbol por el flag de un
grupo, propagacion nativa no verificada). Validacion cruzada: todo lo
invisible se llama `*Bump` (88 en RV1, 26 en IconViewRoom1, 21
RectPatch en Garden MazeC7b...) y los RectPatch v0 traen flags=0 (confirma
por segunda via que v0 = invisible). Reception tiene 0 invisibles: su
vista spawn es md5-identica antes/despues. LizCave pasa de 48 a 7 objetos
(roca + 5 estalagmitas + cartel): cueva de musgo sin teal.

## Modo juego `--play` (2026-09-14, tercera persona, ya no camara libre)

**`WorldViewer --play`**: el juego en vez del visor. Tercera persona
como el original (`HoloPilot` BEHIND por defecto, modos 3-8 del
decompilado): camara detras de la cabeza (pies+150 = `eyeHeight` real
de `SmoothDriver`/`HoloPilot.loadInit`, dist 220 = WIDESHOT modo 8)
mirando al frente; avatar `aura.bod` (default real del cliente,
`PosableShape.defaultURL`) en bind pose con las 2 luces, pies en el
suelo. Spawn real `worlds.ini RestartAt` (Reception 1872,1229,150
mirando al kiosko). Controles: W/S caminar, A/D strafe, flechas
girar/pitch, ESC salir. `run-game.sh` sin args ya lanza `--play`.

**Suelo**: `floorHeight` como `Room.floorHeight` del original (piso
mas alto <= pies+escalon) sobre Rect/RectPatch visibles en coords
mundo; sin caida libre (el original tampoco la tiene: `SmoothDriver`
mantiene Z=eyeHeight+suelo cada frame). **Colision**: muros = Rects
no-piso + bumpers invisibles como AABB expandidos por radio 30 (medio
ancho del bound box real `setLocalBoundBox(-30,...)` de `HoloPilot`);
movimiento por ejes con slide. Constantes reales documentadas en el
codigo (`PLAY_EYE_HEIGHT/CAM_DIST/WALK_SPEED/RADIUS/STEP`).

**Verificado**: Reception 14 suelos/28 bloqueantes/8 portales, 89
objetos (1 avatar jugador), GL 0 (`world_play_spawn_thirdperson.png`:
Aura de espaldas ante el kiosko texturizado, colinas detras);
IconViewRoom1a 7 objetos (2 avatares: estatua + jugador), GL 0; modo
fly y ALL 25/25 sin regresion (GL 0 en todo).

**Limites honestos**: forward del .bod no verificado (se rota +X local
al yaw — acertó a la primera: Aura mira al kiosko); AABB en vez de
quads finos; portales fase 1 (se anuncian a <150, el `changeRoom` con
farSide es fase 2, `WNode` ni modela destinos todavia); sin
skin/animacion (bind pose, como las estatuas).

## Modo juego: bug del vuelo al cielo encontrado y corregido (2026-09-14)

**Bug real**: al andar, el jugador salia volando (`Player at z=2250`).
Causa raiz con matematica exacta: `floorHeightAt` devolvia su parametro
`z` cuando no habia suelo, y se la llamaba con `z=pies+30` — cada frame
andando sobre vacio sumaba +30 (180+69x30=2250 exactos del log).
Arreglo: el contrato ahora es `floorHeightAt(x,y,pies)` (+STEP dentro,
pies si no hay nada). Verificado con harness headless (`/tmp/WalkTest`:
800 pasos hacia el kiosko con el codigo real por reflexion): antes
180->1890, ahora z clavado + parada por muro.

**Colision de props**: el mobiliario (kiosko) son props `.rwx` sin
Rect — se atravesaban. `collectPlayfield` ahora recoge sus triangulos
en coords mundo (100 en Reception): suelo exacto por plano baricentrico
+ AABB por prop que para si supera pies+STEP (si no, se pisa: escalon
fiel). Efecto colateral bueno: el suelo visual del spawn ES prop (z=0;
el `150` de RestartAt era altura de ojo, no pies). Bumpers invisibles
paran siempre (flag b[6]); empotrado contra muro ya no re-fija suelo
(no mas ratchet). Ventana 20s quieta: pos exacta al milimetro.

**Ventana**: `--play` no activaba `bring_to_front.py` (patron sin
`--play`) y podia abrirse oculta en el escritorio — anadido.
Contadores `Drew/N avatars` ahora por frame (acumulaban la sesion:
"272 avatars" = 1x272 frames).

## Avatar de espaldas + mapa de animacion real (2026-09-14, sin inventar)

**Facing corregido con evidencia** (antes se veia de lado): el forward
anatomico es +Z local del .bod (cara/puntas en +Z, coleta/talones en
-Z — medido en `SPIN.RWX` y en bytes de `aura.bod`;
`tools/gdk-sdk/RWXTOBOD.PL` pasa ejes sin tocar). Como el +Z bod mapea
a +Y mundo, la rotacion es `yaw-90` (algebra). Verificado en captura:
Aura de espaldas, coleta centrada, mirando al kiosko
(`world_play_spawn_thirdperson.png` regenerada).

**Animacion: extraida, no inventada** (ver
`docs/seq-animation-reference.md`): el original tiene DOS sistemas
(`Drone.java:359-364`): articulado (`.bod`+`.seq`+`avatars.dat`,
`DroneAnimator` nativo) y holograma (`.mov` = video de texturas
`LzH2`, `HoloDrone`). Cabecera `.seq` verificada (ver 0x01, nº joints,
nombres, `1.0f` por joint; walk=44 joints mocap LifeForms,
wait=16 Gamma, wave=4 parcial). El key-data por joint SOLO lo entiende
`gamma.dll` — en Java no hay parseo: implementarlo sin Ghidra seria
inventar poses. Siguiente paso real: desensamblar
`DroneAnimator_animate/update` (exports en
`docs/gamma-dll-exports.txt:209-224`).
