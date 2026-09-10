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
- ⚠️ **Hallazgo**: en `cube.rwg`, los 8 vértices "planos" (sin UV, ya
  documentados) tienen normal parseada `(0,0,0)` — un valor de relleno
  sin sentido geométrico, no una dirección real — y 2 de las 6 caras del
  cubo los referencian. Alimentar una normal de longitud cero a
  `GL_NORMALIZE` es comportamiento indefinido en OpenGL. Se implementó
  un fallback: si la normal parseada tiene longitud ~0, se usa la normal
  de cara calculada por producto cruzado para esa cara (mismo mecanismo
  que RWX). Documentado en el código (`RwgViewer.drawTriangles`).
- ⚠️ **Artefacto sin resolver**: aun con ese fallback, `cube.rwg`
  muestra un patrón tipo z-fighting (bandas finas) en 2 de sus 6 caras
  al renderizarlo con las 2 caras visibles (culling desactivado, ver
  abajo). Se probó activar backface culling como diagnóstico: el
  resultado fue PEOR (huecos reales, triángulos incorrectos ocultos),
  lo que demuestra que **el sentido de bobinado (winding) no es
  consistente entre caras en los datos reales** — no se pudo determinar
  la convención correcta con la evidencia y el tiempo disponibles. Se
  mantuvo la decisión original (ambas caras visibles) por ser la que
  menos oculta geometría real, y el hallazgo queda documentado en vez de
  forzarse una "solución" sin evidencia. La geometría de posición en sí
  (ya verificada en la sesión anterior con captura de pantalla limpia
  sin iluminación) no se ve afectada — es puramente un artefacto de
  sombreado en 2 de 6 caras.
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
