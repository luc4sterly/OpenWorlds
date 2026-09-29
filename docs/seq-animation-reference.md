# Animación de avatares: formato `.seq`/`.mov` y cómo lo reproduce el original

> Estado (2026-09-15): **formato `.seq` completo, traducido del C
> decompilado de `gamma.dll` y verificado sobre el corpus real**:
> `SeqParser` consume 231/231 archivos enteros (`SeqExtractMain`).
> Actualización 2026-09-23: la reproducción de `DroneAnimator` (elección
> de secuencia, mezclas, aplicación a joints) está traducida en el puente
> del cliente original; ver sección 7.
>
> 2026-09-26: el motor nuevo (`client/`, con `BodViewer`, `WorldViewer` y
> su copia de esta regla) se quitó del repositorio; lo que se cita de él
> abajo, capturas de `docs/renders/` incluidas, está en el historial de git
> hasta el commit `8cd795d`. `SeqParser` y `SeqSampler` siguen en
> `formats/`, porque los usa el puente.
>
> Corrección de auditoría: el commit `bcd60fd5` afirmaba "leftover=0",
> pero su `SeqParser` fallaba en 231/231 archivos (leía un `u16`
> "checksum" que no existe en el archivo). Corregido y re-verificado.

## 1. Dos sistemas distintos (verificado en `Drone.java:359-364`)

- **Articulado** (Axel, Aura…): `.bod` + `.seq` + `avatars.dat`.
  `PosableDrone` → `PosableShape` → `DroneAnimator.animate/update`
  (blending en nativo).
- **Holograma** (`avatar:*.mov`): `.mov` = película de texturas
  ScapePic (magic `LzH2`, igual que `.cmp`), NO esquelético.
  `HoloDrone` → `Hologram` → `ScapePicMovie` (nativo). Frames de
  imagen, nunca joints.

## 2. Formato `.seq` (verificado: C + bytes + 231/231)

El cargador es `FUN_00436d50`: si el primer byte es `0x7f` salta a la
variante big-endian `FUN_00436610`; si no, formato v1.

### v1 (little-endian, deltas empaquetados) — 194 archivos

```
u8   version            (0x01 en todo el corpus; el original no la comprueba)
u8   nJoints            (0 = error)
u8   len + figura       (FUN_0042f3b0, sin NUL)
u16  K                  nº de keyframes
u8[K] diccionario       delta de tiempo por key; tiempo_i = suma(dict[0..i])
nJoints × { u8 len + nombre ; track 0x10 }
u8   nExtra ; nExtra × track (índice 3 → 0x10, el resto → 4)
```

- **No hay checksum en el archivo**: la suma de los K bytes se calcula en
  memoria y se guarda (short) en `+0x214` — es la duración total.
- Track 0x10 (`FUN_00437550`): 4 floats LE base, en el orden del archivo
  (objeto de 4 componentes `FUN_00428fe0`), + (K-1) × 3 bytes = 4 índices
  de 6 bits; cada uno: 5 bits de magnitud en el codebook `CB32` + signo
  (`>0x1f` = negativo), sumados acumulativamente.
- Track 4: 1 float base + (K-1) × 1 byte (7 bits en `CB128` + signo).
- Codebooks en `gamma.dll` (offset de fichero `0x729c0` = CB32,
  `0x72a40` = CB128): idénticos bit a bit a los de `SeqParser`.
- Ejemplo cuadrado a mano, `axelwave.seq` (265 B): `01 04 06 "harold"`,
  K=13, 13 bytes de diccionario, 4 joints (`back`, `lfshoulder`,
  `lfelbow`, `lfwrist`) × (nombre + 16 B + 36 B), `nExtra=0` → 265 exactos.
- Primer valor de muchos joints = `(1,0,0,0)`. Junto con la variante
  0x7f, que guarda los tracks de 3 floats como `(0,a,b,c)`, apunta a que
  el primer componente es la parte real del cuaternión. ⚠️ VERIFICAR en
  el código que consume el track (aún no leído).
- 4 joints reales con base `(0,0,0,0)` (`common_g1_no`: pelvis/rthip/
  lfhip; `common_g3_spin`: head): dato del archivo, no error de parseo.

### Variante `0x7f7f7f7a` (big-endian, sin empaquetar) — 37 archivos de `cachedir`

```
u8[4] 7f 7f 7f 7a
u16  duración           (→ +0x214; < 1 = error)
u32  nJoints            (≤ 0 = error)
u16 len + figura        (el NUL va dentro de la longitud)
u16 len + joint raíz    (→ +0x114)
nJoints × { u16 len + nombre ; track }
u32  nExtra ; nExtra × track
track (FUN_004364e0 / FUN_00436260):
  u32 sizeFlag (4 | 0xc | 0x10) ; u32 nKeys ;
  nKeys × { u32 tiempo ; 1 | 3 | 4 floats }   (0xc se guarda como (0,a,b,c))
```

Figuras vistas: `SeqBed-Aura`, `pose53_a/b`, `male`, `slim`, `breaker`
(raíz `Box01`), `male` con raíz `Cube`… — exportadas de otra herramienta
(nombres tipo 3ds Max), no del rig Gamma clásico.

### Rigs observados

- 16 joints (rig Gamma clásico), 44 joints (mocap LifeForms con
  `lumbar_*`/`thorax_*`/`cervical_*`, p. ej. `axelwalk`), parciales de 3-4
  joints (`axelwave`: solo brazo izquierdo). Histograma completo en la
  salida de `SeqExtractMain`.
- `axelwait.seq` es byte-idéntico a `axelendwave.seq` (causa sin verificar).

Reproducir: `java -cp formats/out net.openworlds.bod.SeqExtractMain -q
assets/gammatutorial-samples/base-avatars/*.seq assets/WorldsPlayer/cachedir/*.seq`.

## 3. Registro `avatars.dat` / `45.dat` (texto, `# animation registry version 0.3`)

Bloques `avatar name=X geometry=Y.rwx beginimp{walk=… wait=… endwait=…}
beginexp{wave=… yes=… dance=…}`. Los valores son nombres SIN extensión
(`walk=achoowalk`); el cliente añade `avatars\<nombre>.seq`
(`PendingCacheDrone.java:34`). El Java NO elige `.seq` por estado: el
nativo resuelve implícitos (`walk/wait`, en `update`) y explícitos
(`*gesto*` en chat → `Pilot` → `PosableDrone/PosableShape.animate` →
`DroneAnimator.animate` con `getAnimationTime` como duración).

## 4. Tabla tag→joint (única fuente oficial: `tools/gdk-sdk/RWXTOBOD.PL:150-183`)

`pelvis=1, back=2, neck=3, head=4, rtshoulder=6… lfankle=21…` (misma en
`Avatar building text.txt:430-493`). Los `.seq` Gamma usan esos nombres;
los mocap (44) son incompatibles con la tabla 1-32 — el retarget
nativo NO está verificado. `SeqFile.java` solo pasa la ruta al nativo
(`notifySeqLoaded`); `DroneAnimator` (15 métodos, todo nativo
confirmado en `docs/native-methods-map.md:231-246`) hace el resto.

## 5. Reproducción en `gamma.dll` (C decompilado, verificado 2026-09-15)

93 funciones de `gamma.dll` son `EnterCriticalSection` + una sola llamada
`Rw*` (p. ej. `FUN_00418a50` = `RwRotateMatrix`, `FUN_00419950` =
`RwPushScratchMatrix`), lo que hace legible la cadena de animación.

- **Cadena JNI**: `DroneAnimator.update` → `FUN_00435520` →
  `FUN_00433710` (despacho por vtable C++); `animate` → `FUN_004355a0`
  (busca la acción por nombre con `FUN_00433e90` y arranca con
  `FUN_00432d10`); `getAnimationTime` → `FUN_00435630` → `FUN_00432be0`
  (devuelve `seg + ms/1000`, `DAT_00472020` = 1000); `prepFigure` →
  `FUN_00434f00`. Java: `PosableShape.handle(FrameEvent)` llama a
  `moveto(x,y,z,-yaw,t-1)` + `update(null, this, Std.getRealTime(),
  scaleX, distancia>700)` cada frame (`PosableShape.java:1235-1238`).
- **Muestreo de un track** (`FUN_00435a10` → `FUN_00435ab0` /
  `FUN_00435b20`): índice = último key con tiempo ≤ t (0 si t < primero);
  en el último key o en t exacto → valor del key; si no, `f = (t-t0)/(t1-t0)`
  (con `dt` short; `dt<1` → key 0) limitado a [0,1] e interpolación
  **lineal por componentes + normalización** (nlerp: `FUN_004271c0` +
  `FUN_00426f40`, normaliza solo si |q|²>1e-5), no slerp; escalares y
  vectores lineales. Sin keys → identidad. Sin bucle en el muestreo.
  Traducido en `formats/src/net/openworlds/bod/SeqSampler.java`.
- **Cuaternión**: objeto (vptr, w, x, y, z). Identidad `FUN_00428f10` =
  (1,0,0,0); eje-ángulo `FUN_00428f40` guarda `cos(a/2)` en +4; producto de
  Hamilton `FUN_004272c0`; a matriz `FUN_00427040` (4×4 fila-mayor,
  s = 2/|q|²). → **el primer float de cada key es w** (resuelve el ⚠️ de la
  sección 2).
- **Pose** (`FUN_00438300`): extras 0..2 = traslación de raíz; extra 3 =
  rotación de raíz; cada joint 0x10 → entrada (clave = id interno del
  nombre, cuaternión con **x e y negados** por `FUN_004290c0`,
  `DAT_00473440` = −1). La z de la raíz se niega o se anula según un flag
  (`DAT_00475fec` = −1) cuyo llamador aún no está localizado ⚠️.
- **Nombre → tag**: tabla propia de 30 nombres en `gamma.dll` (strings en
  fileoff `0x71314`, punteros en `0x71420`, registrada por
  `FUN_004298b0`), comparación exacta con `strcmp` (`FUN_0044d730`).
  Tags 1..22 = mismos nombres que `RWXTOBOD.PL`; 23..30 = `neck2`, `tail`,
  `tail2`, `tail3`, `tail4`, `obj`, `obj2`, `obj3` (en `RWXTOBOD.PL` el
  23 es `back2`, etc.). No hay cadenas `lumbar`/`thorax`/`cervical` en la
  DLL: **los joints mocap sin nombre en la tabla se ignoran; no existe un
  retarget 44→16, solo coincidencia de nombres** (`common_walk` aplica 22
  de sus 44 tracks).
- **Aplicación** (`FUN_00434470`): para cada tag 1..30,
  `RwFindTaggedClump(figura, tag)` + `RwTransformClumpJoint(clump,
  matriz_del_cuaternión, 1)`; tag sin track → identidad. La traslación de
  raíz × 0.1 (`DAT_00475490`) se escribe en la fila 3 de la matriz de
  modelado del primer hijo de la figura, multiplicada por su diagonal
  (`FUN_00431990`, `RwTransformClump(…, 1)`). La rotación de raíz (extra 3)
  se calcula pero no se aplica ahí.
- **Composición en RenderWare 2.1** (desensamblado de `RWL21.DLL`,
  verificado): convención vector fila con traslación en la fila 3;
  **`LTM_hijo = Joint · Modelado · LTM_padre`** (`0x10004747`: tmp =
  M(+0xEC)·LTM_padre; `0x10004788`: LTM = J(+0x130)·tmp; sin padre LTM =
  J·M). Modos de `RwTransformClump`/`ClumpJoint`/`Matrix`/`RotateMatrix`
  (rutina común `0x1001c500`): **1 = sustituir**, **2 = X·destino**
  (pre-concatenar, en espacio local), **3 = destino·X** (post). La LTM se
  cachea y se invalida al transformar o reenganchar. `RwGetClumpMatrix`
  devuelve solo el modelado (+0xEC).
- **Figura** (`ShapeLoader.loadBodFile` carga UNA parte por llamada →
  `FUN_0041e240` → `FUN_0041d950`): cada parte = clump con
  `RwSetClumpTag(tag)` y su traslación en la **matriz de modelado**;
  placeholder = clump hijo con tag `0x8000000|tag` y su traslación. El
  `WObject.addChildToClump` nativo cuelga cada parte del placeholder con
  su tag (si no lo hay, del padre). Por eso `RwFindTaggedClump` solo
  encuentra partes y cada rotación pivota en el origen de su parte.
- **`prepFigure`** (`FUN_00434f00`): matriz de joint de la figura =
  `RwRotateMatrix(eje (0,1,1), 180°)` (Y-up del `.bod` → Z-up del mundo) +
  `RwScaleMatrix(1000)`; mueve la traslación del primer hijo (pelvis) a esa
  matriz y la pone a 0 en la pelvis (por eso la traslación de raíz del
  `.seq` puede sustituirla), y recoloca por el COG (solo z si
  `COG=false`). Da evidencia al ×1000 y +Y→+Z que `WorldViewer` usaba como
  heurística.
- **Tiempo y bucle** (resuelto el 2026-09-16, tras recuperar con Ghidra las
  funciones que solo se alcanzan por vtable): el reproductor guarda la
  secuencia en `+0xc`, el **tiempo actual como short en `+0x14`**, el
  tiempo transcurrido en `+0x18` y la duración en segundos en `+0x1c`
  (`FUN_0043b490`: `duracion_keys · 1/30`, `DAT_00476ec0`). Las dos
  variantes de avance — `FUN_0043b950` (tiempo {seg,ms}) y `FUN_0043b5f0`
  (segundos en float) — coinciden en la regla:

  ```
  t = trunc(segundos * 30)                      // DAT_00476ec8 = 30.0
  si t > duracion:  modo 2 -> t % (duracion + 1)   // bucle
                    modo 1 -> duracion              // se queda en el ultimo key
                    otro   -> la reproduccion termina
  ```

  Es decir, **los keys van a 30 por segundo exactos** (coherente con
  `common_walk` = 42 keys = ciclo de 1,4 s). Traducido en
  `SeqSampler.keyTime`. ⚠️ Corrección 2026-09-23: el paso a entero
  **trunca**, no redondea: antes del `fistpl` las dos funciones ponen la
  palabra de control en "chop" (`orb $0xc` en 0x43b9c0 y 0x43b70f);
  `SeqSampler.keyTime` usa `Math.round` y da un key de más en la mitad
  superior de cada 1/30 s. El puente usa el truncado
  (`AnimGraph.TimeDriver`/`DistanceDriver`). Las dos funciones que sacan la pose
  (`FUN_0043b770`, `FUN_0043baa0`) se diferencian solo en el flag que
  anula o conserva la z de la traslación de raíz — el `param_3` que antes
  quedaba ⚠️.
- **Controlador**: reconstruido el 2026-09-23, ver la sección 7
  ("Selección de secuencia en el cliente"). La mezcla de 0xfa son 250
  **ms** (`{0 s, 250 ms}`) y la curva `clamp(8·r·(1−r), 0, 1)`
  (`FUN_0043ab30`) es la de los **explícitos**, no la del cambio de
  implícito (que es lineal, `FUN_0043a540`).

## 6. Qué falta para animación real (siguiente paso)

1. ~~Decoder del key-data `.seq`~~ ✅ (sección 2). ~~Muestreo, orden del
   cuaternión, nombre→tag, retarget~~ ✅ (sección 5). ~~Fórmula de la LTM
   y pre/post de RenderWare 2.1~~ ✅ (sección 5). ~~Aplicar la pose a un
   `.bod`~~ ✅ `BodViewer --seq <f.seq> --frame T` (ver abajo).
2. ~~**Controlador**~~ ✅ (sección 7): elección `walk`/`wait`/`endwait`,
   sincronía con la distancia recorrida, mezclas y bucle, traducidos en el
   puente (`bridge/NET/worlds/core/Anim*.java`, `NativeAnimator.java`).
3. ~~Flag de la z de la traslación de raíz~~ ✅: los drivers por tiempo
   (wait, gestos) la conservan negada; los de distancia (walk) la anulan.
4. `.mov` como vídeo de texturas (hoy solo frame 0). Menor: `csq` (citado
   en GDK, sin ejemplar).

## 6.1. Verificación de la pose (2026-09-15, macOS)

`BodViewer --seq f.seq --frame T [--keep-root-z]` aplica la pose. Sin
`--seq` el resultado es idéntico bit a bit al anterior (md5 igual en
`aura`, `tina`, `ogre`, `death`, `axel`; `orphans=0 badIndices=0`), así
que el cambio de LTM no introduce regresión en bind pose.

Con pose, verificación **anatómica** (no hay comparación píxel a píxel
con el original: el cliente de 2004 necesita Wine y este Mac no lo
tiene):

- `aura.bod` + `common_walk.seq`: frame 0 y frame 21 (medio ciclo) dan
  piernas y brazos en oposición y con las fases invertidas entre sí —
  `docs/renders/bod_aura_common_walk_f0.png` y `_f21.png`. Aplica 22 de
  los 44 tracks (los mocap sin nombre de tag se ignoran, sección 5).
- `axel.bod` + `axelwave.seq` (4 tracks: `back`, `lfshoulder`,
  `lfelbow`, `lfwrist`): en el frame 80 levanta el brazo **izquierdo**,
  el que animan esos tracks — `docs/renders/bod_axel_axelwave_f80.png`.
  Con el signo de x/y o la convención de matriz equivocados el brazo
  saldría hacia atrás, dentro del cuerpo o en el lado contrario.
- `aura.bod` + `common_a_wait.seq`: frame 0 es exactamente la bind pose
  (todos los cuaterniones identidad) y hacia el frame 144 hay
  microdesplazamientos de respiración —
  `docs/renders/bod_aura_common_a_wait_f144.png`.

## 6. Forward del `.bod` (verificado)

Cara y puntas de pies en **+Z local** (Y-up), coleta/talones en −Z:
`SPIN.RWX` (cabeza −0.006/+0.043, pie −0.005/+0.059) + bytes de
`aura.bod` (coleta −Z, cara +Z); `RWXTOBOD.PL:7,21-25,799-806` pasa ejes
sin tocar. El +Z bod mapea a +Y mundo → rotación `yaw−90°` (álgebra).
GammaDocs confirma Y-up/X-ancho (`Avatar building text.txt:240,402-405`).

## 7. Selección de secuencia en el cliente (DroneAnimator)

Traducido el 2026-09-23 del motor de animación de `gamma.dll`
(0x0042b000–0x0043c500) en el puente (`bridge/NET/worlds/core/`:
`AnimRegistry`, `AnimSeqCache`, `AnimGraph`, `AnimPose`, `AnimAnimator`,
`AnimMotion`, `NativeAnimator`; nativos enganchados por
`bridge/natives-animator.patch`). Comprobaciones: `bridge/test/Animator*Check.java`.

### 7.1 Qué decide Java y qué decide el nativo

Java (`PosableShape.handle(FrameEvent)`, `PosableShape.java:1219`) solo
informa: cada frame, si el avatar está a menos de 900 de la cámara
(`closestView`, que calcula `prerender` con `inCamSpace`), llama a
`moveto(tipo, (short)x, (short)y, (short)z, (short)-yaw, t-1)` y a
`update(null, this, t, scaleX, lejos>700)`. Los gestos llegan por
`animate(tipo, nombre, t)` (chat `*gesto*`, `Pilot`, `PosableAction`...),
cuya duración (`getAnimationTime`) usa `PosableShape` para encadenar
secuencias con `&`. **Todo lo demás lo decide el nativo**: qué implícito
toca, a qué ritmo avanza y cómo se mezcla. `lejos` no se usa (llega a
`FUN_00433710`, que hace `ret 0x14` sin leer `0x18(%ebp)`).

### 7.2 Registro (`avatars.dat`)

`loadconfig` (FUN_00434b70) vacía el registro y analiza el texto
(`Archive.readTextFile`, sin CR). Cabecera de 32 caracteres → gramática
0.3 (FUN_0042cda0) o 0.2 (FUN_0042d840, con un tipo fijo `cy`). El
escáner es un flex (FUN_0042a4c0) con tablas en el binario; de ellas
salen estas reglas: `#…\n` y blancos se saltan; el número es **un solo
dígito** (`version 3`); identificador `[A-Za-z0-9_][A-Za-z0-9_.-]*`
(`123`, `2v` y `Skating-1` son identificadores). Las claves de acción se
pasan a minúsculas (FUN_004280b0); secuencias y atributos no.
`getnameindex` compara el atributo `name` sin mayúsculas
(FUN_004508c0); el índice es el orden del fichero.

### 7.3 Los cinco implícitos y la máquina de estados

Tabla de implícitos (0x475288, 12 bytes: nombre, arg1, arg2):

| idx | nombre | avanza por | al terminar |
|---|---|---|---|
| 1 | (ninguno) | — | pipe vacío = pose de reposo |
| 2 | (ninguno) | — | pipe vacío |
| 3 | `walk` | distancia (arg1 0) | bucle (arg2 2) |
| 4 | `wait` | tiempo (arg1 1) | se queda en el último key (1) |
| 5 | `endwait` | tiempo | último key |
| 6–9 | `run`, `fly`, `hover`, `sit` | 0/0/1/1 | bucle — ningún estado los elige |

`moveto`/`moveby` (FUN_004351b0/FUN_004352f0) pasan posición y
orientación (eje Z, `yaw·π/180`) a FUN_00434670, que clasifica el
movimiento con la tabla `{3,3,2,1}` (DAT_004754e0): **3** si cambió la
posición (igualdad exacta de los `short`), **2** si solo cambió la
orientación (`|dot(q,q') − 1| ≥ 0.0005`, unos 3,6°), **1** si nada:

```
estado 1 (recién llegado): gira -> 2, anda -> 3, 10 s quieto -> 4
estado 2 (girando):        quieto -> 1, anda -> 3
estado 3 (walk):           quieto -> 4 (directo a wait), gira -> 2
estado 4 (wait):           gira -> 2, anda -> 3, 30 s -> 5
estado 5 (endwait):        gira -> 2, anda -> 3, 10 s -> 4
```

Los plazos son `{10,0}`, `{30,0}`, `{10,0}` desde el último cambio (hora
de `moveto`, comparación `<=` sin signo). El primer `moveto` fija el
estado 1. El índice elegido se busca por nombre entre los implícitos del
tipo; si el avatar no tiene esa clave, pipe vacío.

### 7.4 Sincronía con la velocidad

El walk (driver por distancia, 0x476ff4) no avanza con el reloj sino con
la distancia recorrida: `FUN_00431440` guarda la parte horizontal del
desplazamiento entre dos posiciones (se quita la componente Z) con signo
(negativa si en el sistema del avatar la `y` es `<= 0`: andar hacia atrás
recorre el walk al revés). `update` (FUN_00435520) calcula
`escala = 10 / (scaleX · m00 · 1000)` con `m00` de la matriz de modelado
de la pelvis (primer hijo de la figura) y avanza el driver
`cantidad = distancia · |escala|` "segundos" de secuencia; key =
`trunc(acumulado · 30)`, en bucle con `fmod` (negativos se envuelven).
Con la escala del `.bod` (1000 de `prepFigure`, pelvis 1): 100 unidades
de mundo = 1 s de walk = 30 keys. Los demás implícitos y los gestos
avanzan con el dt real (`update` − `update` anterior).

### 7.5 Mezclas

- Cambio de implícito (FUN_00432d10 → `shiftto`, 0x476e14): de lo que
  hubiera a la secuencia nueva en **{0 s, 250 ms}** (0xfa), peso lineal
  `clamp(t/250 ms, 0, 1)` (FUN_0043a540); joints que solo están en una de
  las dos se mezclan con la identidad.
- Gesto (`animate` → `overlay`, 0x476df8): encima del implícito durante
  la duración del `.seq` (`floor(keys·(1/30f))` s + ms, FUN_00427a50); peso
  `clamp(8x(1−x), 0, 1)` con `x = t/duración` (FUN_0043ab30: sube en el
  primer 14,6 % y baja en el último); **solo los joints del gesto**: el
  resto sigue con el implícito (tabla 0x4771fc copia A). Con
  `override.ini [Runtime] NoImpChange=1` el peso es 1 y no hay changeimp.
- Interpolación (FUN_00439450): nlerp con cambio de hemisferio.
- `beginchangeimp` (FUN_004330a0): al lanzar un gesto con bloque, sus
  pares sustituyen las secuencias de los implícitos del animador (p. ej.
  `chairsit` → `wait=lgSeated`), efectivas en el siguiente cambio de
  implícito. Las secuencias que solo aparecen en esos bloques
  (`willendwait`, `willwalk` en 45.dat) no las registra `addtype`
  (FUN_0042b160 solo recorre implícitos y explícitos) y por tanto nunca se
  cargan: pose de reposo. Error del original: una clave de changeimp que
  no esté entre los implícitos escribe una posición más allá del vector
  (compara con el final de la lista de explícitos, 0x433378).

### 7.6 Tiempo, bucle y lo que devuelven `animate`/`getAnimationTime`

- Driver por tiempo (0x476fdc): `key = trunc((s + ms/1000)·30)`; si
  `key > duración`: bucle `key % (duración+1)` (modo 2), último key (1) o
  termina (0, los gestos). Driver vacío (sin `.seq`): dura {10000 s}.
- `animate` y `getAnimationTime` devuelven `s + ms/1000` de la duración
  del gesto (p. ej. `axelwave`, 142 keys → 4.733); 0.0 si el nombre no
  está (DAT_00475524). Un gesto sin `.seq` cargable dura **10000 s**.
  El tiempo que recibe `animate` no se usa.
- Carga: `addtype` registra las secuencias del tipo en la caché
  (`./avatars\NOMBRE.seq`); se piden a Java (`PendingCacheDrone.
  downloadSeqFile`) de forma **síncrona la primera vez que hacen falta**
  (FUN_0042fc90) o asíncrona si otro tipo ya las compartía.

### 7.7 Aplicación de la pose y `prepFigure`

FUN_00434470: tags 1..30 (ids 3..32 por FUN_004298b0) en orden;
`RwFindTaggedClump` + `RwTransformClumpJoint(sustituir)`; tag sin entrada
→ identidad; la traslación de raíz (extras 0–2) ×0.1 va a la fila 3 del
modelado de la pelvis multiplicada por su diagonal; la rotación de raíz
(extra 3) no se aplica. `prepFigure` (FUN_00434f00) = sección 5, más: el
punto que se recoloca es (centro x, centro y, z mínima) de la caja del
árbol en el mundo (FUN_00418900); con COG = false solo la z (pies en el
suelo).

### 7.8 Verificado y pendiente

- `AnimatorRegistryCheck` (45.dat, 221 tipos), `AnimatorPlaybackCheck`
  (duraciones, keys, mezclas, bucle, hold) y `AnimatorMotionCheck`
  (estados a 1000/10999/11000/40999/41000/51000 ms, walk 100 u → key 30,
  atrás → 15, escala de la pelvis, pose en el joint, `prepFigure`).
- En juego (GroundZero, `IconViewRoom1a`): `addtype`, `prepFigure`,
  `moveto`/`update` corren y las figuras quedan de pie a escala. Las
  estatuas de las galerías **giran** (~70°/s), así que el C las mantiene
  en los estados 1/2 (sin secuencia): no llegan a `wait`. ⚠️ Para verlas
  animarse en el puente hace falta además (fuera de estos ficheros)
  `WObject.nativeInCamSpace` (0x00413910; hoy stub que devuelve `z = 0`,
  así que `closestView` nunca baja de 900) y que `RwReadStreamChunk` de
  un `.rwg` sin vértices (`avatar.rwg`) devuelva un clump vacío en vez de
  0 (si no, el `PosableShape` nunca está `isFullyLoaded` y no crea el
  animador).
- ⚠️ Precisión: las operaciones se hacen en `double` suponiendo la palabra
  de control x87 0x027F del JVM (53 bits, redondeo al par); solo afecta a
  empates exactos.
- ⚠️ El `catch` de los errores de sintaxis de `avatars.dat` (throw de C++)
  no está localizado: el puente avisa y conserva los tipos leídos.

### 7.9 `SeqSampler.keyTime`

`SeqSampler.keyTime` (en `formats/`) trunca como los drivers (`fistp` en
chop, 0x43b9c0). El motor nuevo llegó a tener una copia de toda esta regla
(`client/src/net/openworlds/avatar/`, 2026-09-25); se quitó con él el
2026-09-26 y está en el historial de git hasta el commit `8cd795d`.
