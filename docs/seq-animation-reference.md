# Animación de avatares: formato `.seq`/`.mov` y cómo lo reproduce el original

> Estado (2026-09-15): **formato `.seq` completo, traducido del C
> decompilado de `gamma.dll` y verificado sobre el corpus real**:
> `SeqParser` consume 231/231 archivos enteros (`SeqExtractMain`). La
> REPRODUCCIÓN (blending/interpolación/aplicación a joints) sigue en
> `DroneAnimator` nativo y NO está implementada: sin ella no se anima
> nada en el motor (regla del proyecto: no inventar poses).
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

Reproducir: `java -cp client/out net.freeworlds.bod.SeqExtractMain -q
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
  Traducido en `client/src/net/freeworlds/bod/SeqSampler.java`.
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
- **Tiempo**: los keys van en **1/30 s** — constante `DAT_00476ec0` = 1/30
  en el constructor del reproductor (`FUN_0043b490`), coherente con los
  datos (`common_walk` = 42 unidades = ciclo de 1,4 s). ⚠️ La conversión
  exacta desde `Std.getRealTime()` (ms), el bucle y la sincronía con la
  velocidad (`update` usa `10 / (scaleX · m00 · 1000)`) están tras el
  despacho por vtable de `FUN_00433710`, sin reconstruir.
- **Transiciones**: `FUN_00432d10` crea una mezcla con constante 0xfa
  (250; unidad sin verificar) y `FUN_00439450` interpola entre poses (nlerp
  con inversión de hemisferio `FUN_004292a0`); la curva de cambio
  implícito `FUN_0043ab30` = `clamp(8·r·(1−r), 0, 1)`, desactivable con
  `override.ini [Runtime] NoImpChange=1`.

## 6. Qué falta para animación real (siguiente paso)

1. ~~Decoder del key-data `.seq`~~ ✅ (sección 2). ~~Muestreo, orden del
   cuaternión, nombre→tag, retarget~~ ✅ (sección 5). ~~Fórmula de la LTM
   y pre/post de RenderWare 2.1~~ ✅ (sección 5). ~~Aplicar la pose a un
   `.bod`~~ ✅ `BodViewer --seq <f.seq> --frame T` (ver abajo).
2. **Controlador** (lo que falta para animar de verdad en el motor):
   tiempo real (ms de `Std.getRealTime()`) → t de key, bucle al final de
   la secuencia, elección implícita `walk`/`wait` según movimiento,
   sincronía con la velocidad (`update` usa `10 / (scaleX · m00 · 1000)`)
   y transiciones de 250. Todo eso vive tras el despacho por vtable de
   `FUN_00433710`, sin reconstruir. Hasta tenerlo, `WorldViewer` sigue
   dibujando los avatares en bind pose: poner un bucle "a ojo" sería
   inventar.
3. Flag de la z de la traslación de raíz (`FUN_00438300` param_3) —
   irrelevante en `wait` (extras a 0), afecta a `walk`.
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

## 6. Forward del `.bod` (verificado, aplicado en `WorldViewer --play`)

Cara y puntas de pies en **+Z local** (Y-up), coleta/talones en −Z:
`SPIN.RWX` (cabeza −0.006/+0.043, pie −0.005/+0.059) + bytes de
`aura.bod` (coleta −Z, cara +Z); `RWXTOBOD.PL:7,21-25,799-806` pasa ejes
sin tocar. El +Z bod mapea a +Y mundo → rotación `yaw−90°` (álgebra).
GammaDocs confirma Y-up/X-ancho (`Avatar building text.txt:240,402-405`).
