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

## 5. Qué falta para animación real (siguiente paso)

1. ~~Decoder del key-data `.seq`~~ ✅ hecho y verificado (sección 2).
2. Reproducción nativa: `DroneAnimator_update` → `FUN_00435520` →
   `FUN_00433710` (despacho por vtable C++, blending/avance de tiempo) y
   `DroneAnimator_animate` → `FUN_004355a0`, `getAnimationTime` →
   `FUN_00435630`, `prepFigure` → `FUN_00434f00`. Hay que reconstruir
   interpolación entre keys, orden de componentes del cuaternión, qué son
   los 3-4 tracks extra (candidatos: traslación/rotación de raíz, sin
   verificar) y cómo se aplica a los joints del `.bod`.
3. Retarget mocap→Gamma (44→16).
4. `.mov` como vídeo de texturas (hoy solo frame 0).
5. Menores: `csq` (citado en GDK, sin ejemplar).

## 6. Forward del `.bod` (verificado, aplicado en `WorldViewer --play`)

Cara y puntas de pies en **+Z local** (Y-up), coleta/talones en −Z:
`SPIN.RWX` (cabeza −0.006/+0.043, pie −0.005/+0.059) + bytes de
`aura.bod` (coleta −Z, cara +Z); `RWXTOBOD.PL:7,21-25,799-806` pasa ejes
sin tocar. El +Z bod mapea a +Y mundo → rotación `yaw−90°` (álgebra).
GammaDocs confirma Y-up/X-ancho (`Avatar building text.txt:240,402-405`).
