# Jerarquía de joints en RWX (avatares articulados), reconstruida desde bytes reales

⚠️ **Esto es RWX (texto), no `.rwg`/`.bod`.** La búsqueda de esta sesión
partió de la instrucción de avanzar en avatares multi-joint reales. Tras
confirmar (ver `docs/rwg-bod-format-reference.md`) que ninguno de los 5
`.rwg` reales del proyecto tiene más de un `ATOM`, y que el cliente Java
decompilado no expone ninguna estructura de huesos visible (todo lo
articulado vive en `gamma.dll`, nativo, no descifrado), se encontró la
única pieza de evidencia real disponible por otra vía: el registro de
animación real (`assets/WorldsPlayer/cachedir/45.dat`, "animation registry
version 0.3") confirma que los avatares de red reales (p.ej. "Achoo",
"Aggie") declaran `geometry=<nombre>.rwx` — el formato FUENTE de un avatar
es RWX texto, no `.rwg` (que solo aparece en el proyecto como formato local
trivial para `AVATAR.RWG`/`IDLE.RWG`, ambos placeholders de un solo clump).
Buscando por convención de nombres de joints (`pelvis`, `lfshoulder`,
`rthip`, `lfelbow`...) en los 119 `.rwx` reales del proyecto
(`grep -liE "pelvis|lfshoulder|rthip|lfelbow"`), apareció exactamente un
archivo: **`assets/GROUNDZERO/SPIN.RWX`** (con copia idéntica en
`assets/WorldsPlayer/GroundZero/tex/spin.rwx`) — ya presente en el proyecto
y usado en una sesión anterior como prop decorativo genérico, sin saber que
era un rig articulado real.

## El archivo: `SPIN.RWX`, 19 clumps nombrados, jerarquía real verificada

Formato: RWX texto estándar, el mismo ya verificado 118/118 contra
`three-rwx-loader` en la sesión 1 (`docs/rwx-format-reference.md`) — no
hace falta ningún parser nuevo para la geometría en sí, solo preservar la
jerarquía de `ClumpBegin`/`ClumpEnd` que el parser existente
(`RwxParser.java`) descarta al aplanar todo a un único mesh.

Convención de nombres: cada joint tiene un comentario `# nombre` justo
antes de su bloque `TransformBegin`/`Transform`/`ClumpBegin`. Los 19
nombres encontrados coinciden EXACTAMENTE con la tabla oficial de
GammaDocs (`Gamma_Advanced.html`, sección "Articulated Avatars" — ver
`docs/rwg-bod-format-reference.md` para la cita completa): pelvis, back,
neck, head, lfshoulder/lfelbow/lfwrist, rtshoulder/rtelbow/rtwrist,
lfhip/lfknee/lfankle, rthip/rtknee/rtankle, lffingers, rtfingers.

Árbol real (reconstruido y verificado programáticamente — ver
`RwxSkeletonDumpMain`, sección siguiente):

```
pelvis  [v=139 t=260]
  lfhip  [v=30 t=47]
    lfknee  [v=30 t=48]
      lfankle  [v=51 t=86]
  rthip  [v=30 t=47]
    rtknee  [v=30 t=48]
      rtankle  [v=51 t=86]
  lffingers  [v=36 t=60]
    rtfingers  [v=19 t=30]
  back  [v=46 t=80]
    neck  [v=48 t=84]
      head  [v=77 t=138]
    lfshoulder  [v=29 t=49]
      lfelbow  [v=14 t=24]
        lfwrist  [v=14 t=24]
    rtshoulder  [v=26 t=42]
      rtelbow  [v=14 t=24]
        rtwrist  [v=14 t=24]
```

(`v`/`t` = vértices/triángulos propios de ESE clump, en su marco local —
no acumulados de hijos.)

**Nota real, no "corregida"**: `rtfingers` anida como HIJO de `lffingers`
en los bytes reales (su `ClumpBegin`/`ClumpEnd` cae enteramente dentro del
rango de `lffingers`), algo anatómicamente inesperado (uno esperaría que
ambos fueran hermanos bajo `pelvis`, o que cada uno colgara de su propia
muñeca). Se dejó tal cual — es lo que dicen los bytes reales, no se
"arregló" para que pareciera más sensato. 18 nodos en total (no 19 —
GammaDocs lista 17 códigos de letra única incluyendo `tail`, que este
archivo no usa; a cambio tiene `lffingers`/`rtfingers`, que GammaDocs sí
lista en su tabla de tags numéricos pero no en la de códigos de letra).

Evidencia cruda (números de línea reales, `grep -n`):

```
3:    # pelvis
8:        ClumpBegin
759:                ClumpBegin      # lfhip (comment at 754)
855:                        ClumpBegin   # lfknee (850)
952:                                ClumpBegin  # lfankle (947)
1157-1161: ClumpEnd x3 (closes lfankle/lfknee/lfhip)
1163:            # rthip
1168-1570: análogo a lfhip (rtknee 1259/1264, rtankle 1356/1361)
1572:            # lffingers  →  1577 ClumpBegin
1795:                # rtfingers  →  1800 ClumpBegin  (anidado DENTRO de lffingers, cierra en 1935, antes de que lffingers cierre en 1937)
1939:        # back  →  1944 ClumpBegin
2156:            # neck  →  2161 ClumpBegin
2739:                # head  →  2744 ClumpBegin, cierra 3288, neck cierra 3290
3292:            # lfshoulder → 3297 ClumpBegin
3389:                # lfelbow → 3394 ClumpBegin
3446:                    # lfwrist → 3451 ClumpBegin, cierra 3503, lfelbow cierra 3505, lfshoulder cierra 3507
3509:            # rtshoulder → 3514 ClumpBegin (análogo: rtelbow 3596/3601, rtwrist 3653/3658)
3718: ClumpEnd (pelvis)
```

## Parser: `RwxSkeletonParser`/`RwxJoint` (nuevo, no toca `RwxParser`)

`RwxParser.java` (el parser aplanado, 118/118 verificado) no se modificó
— sigue produciendo exactamente el mismo `RwxModel` de antes. En su lugar
se añadió un parser hermano, `RwxSkeletonParser` (+ `RwxJoint` como nodo
de salida), que reutiliza EXACTAMENTE las mismas reglas de
transform/clump/material (copiadas literalmente del comportamiento ya
verificado — ver el javadoc de clase de ambos archivos) pero en vez de
aplanar todo a un mesh único en espacio raíz, produce un árbol:

- Cada `RwxJoint` tiene: `name` (del comentario `# nombre` que precede a
  su `ClumpBegin` — capturado ANTES de que el bucle de líneas descarte los
  comentarios, ya que ahí es exactamente donde el parser aplanado los tira),
  `localTransform` (la matriz que `ClumpBegin` "congela" para ese clump,
  relativa al padre — el mismo valor que el parser aplanado usa para
  `groupWorld`, pero SIN componerlo con la cadena de padres), y su propia
  geometría (`vertices`/`triangles`) en su marco local.
- Un detalle real replicado con cuidado: el buffer de índices de vértice
  de RWX se reinicia tanto en `ClumpBegin` COMO en `ClumpEnd` (comportamiento
  ya documentado y verificado en `RwxParser`) — es decir, un mismo clump
  puede tener geometría "antes" y "después" de un hijo anidado, con
  índices de archivo que se reinician a 1 en cada segmento aunque el
  clump sea el mismo. `RwxSkeletonParser` reproduce esto exactamente
  (mapa de índice-local-de-segmento → índice-persistente-del-joint), no
  solo el caso simple de un único segmento por clump.

### Verificación (no solo "compila y no explota")

1. **Estructura**: `RwxSkeletonDumpMain` sobre `SPIN.RWX` reproduce
   EXACTAMENTE el árbol de 18 nodos reconstruido a mano arriba (mismos
   nombres, mismo anidamiento, incluyendo la anomalía real
   `rtfingers`-dentro-de-`lffingers`), sin warnings.
2. **Geometría — coincidencia byte a byte con el parser ya verificado**:
   se comparó, para los 119 archivos `.rwx` reales del proyecto (no solo
   `SPIN.RWX`), el conjunto de puntos únicos en espacio mundo producidos
   por (a) `RwxParser` (aplanado, ya verificado 118/118 contra
   `three-rwx-loader`) y (b) recorrer el árbol de `RwxSkeletonParser`
   componiendo `world = padre.world × joint.localTransform` y aplicando
   eso a los vértices locales de cada joint. **Los 119 archivos dan
   conjuntos de puntos idénticos** (0 discrepancias) — evidencia fuerte
   de que la jerarquía capturada es matemáticamente equivalente a la
   geometría ya verificada, no una reconstrucción aproximada.
   Adicionalmente, el conteo de triángulos coincide exacto (1201 en
   ambos caminos para `SPIN.RWX`); el conteo de vértices difiere (3603
   aplanado vs. 698 en árbol) solo porque `RwxModel.addVertex` duplica un
   vértice por cada uso en un triángulo (sin deduplicar) mientras que el
   árbol guarda cada vértice local una sola vez — comportamiento
   esperado, no un error.
3. **Visual**: `SPIN.RWX` renderizado con el `RwxViewer` existente (que
   usa el parser aplanado — geometría ya probada idéntica al árbol, ver
   punto 2) produce una figura articulada coherente, no basura
   geométrica: piernas con pies, cadera, torso, cabeza, sin triángulos
   degenerados. Ver `docs/renders/rwx_spin_avatar.png`.

### Qué NO resuelve esto (límites honestos)

- **`.bod`, el formato real de transporte de red, sigue sin descifrar.**
  El pipeline documentado en GammaDocs es `.rwx` fuente → herramienta
  `rwxtobod` → `.bod` compilado. Este trabajo verifica el lado FUENTE
  (`.rwx` con jerarquía de joints), no el binario comprimido que el
  cliente realmente descarga y anima (`PendingDrone.java` confirmado en
  sesión anterior). Seguiría haciendo falta Ghidra sobre `gamma.dll` para
  eso, igual que con `.cmp`.
- **No hay animación real reconstruida** — solo la geometría estática en
  bind pose (la pose en la que `SPIN.RWX` fue exportado). No se inventó
  ningún sistema de animación/huesos adicional: por la regla de alcance
  de esta sesión (los avatares deben verse/comportarse EXACTAMENTE como
  el original, nada de sistemas mejorados), este trabajo se limita a
  extraer la jerarquía que el propio archivo YA contiene.
- **`SPIN.RWX` es un único ejemplar** — no se verificó que TODOS los
  avatares reales usen esta misma convención de 19 nombres (aunque
  GammaDocs la documenta como estándar del pipeline oficial, así que es
  razonable asumirlo para cualquier avatar exportado con el mismo
  proceso).

## Archivos

- `client/src/net/freeworlds/rwx/RwxJoint.java` — nodo del árbol (nombre,
  transform local, geometría local, hijos).
- `client/src/net/freeworlds/rwx/RwxSkeletonParser.java` — parser
  hermano de `RwxParser`, mismo comportamiento de transform/clump/material,
  produce el árbol en vez de aplanar.
- `client/src/net/freeworlds/rwx/RwxSkeletonDumpMain.java` — CLI de
  verificación (`java -cp out net.freeworlds.rwx.RwxSkeletonDumpMain
  <file.rwx>`), imprime el árbol indentado con conteos de vértices/
  triángulos por joint.
