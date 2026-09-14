# Animación de avatares: formato `.seq`/`.mov` y cómo lo reproduce el original

> Estado: cabecera y registro VERIFICADOS con bytes + código real. El
> key-data de cada joint lo decodifica `gamma.dll` (`DroneAnimator`,
> nativo) — en Java no hay ni una línea de parseo. Reproducir poses sin
> ese decoder sería inventar: NO se hace (regla del proyecto).

## 1. Dos sistemas distintos (verificado en `Drone.java:359-364`)

- **Articulado** (Axel, Aura…): `.bod` + `.seq` + `avatars.dat`.
  `PosableDrone` → `PosableShape` → `DroneAnimator.animate/update`
  (blending en nativo).
- **Holograma** (`avatar:*.mov`): `.mov` = película de texturas
  ScapePic (magic `LzH2`, igual que `.cmp`), NO esquelético.
  `HoloDrone` → `Hologram` → `ScapePicMovie` (nativo). Frames de
  imagen, nunca joints.

## 2. `.seq`: bytes reales (corpus `assets/gammatutorial-samples/base-avatars/`)

```
axelwait.seq (3823 B): 01 10 04 "axel" 3f 00 01 0f 23 …
axelwalk.seq (5717 B): 01 2c 06 "pelvis" 22 00 01 01 01 …
axelwave.seq (265 B):  01 04 06 "harold" 0d 00 01 …
```

- `byte[0]` = versión `0x01` (4/4 inspeccionados).
- `byte[1]` = nº de joints: 16/44/4 — verificado 3/3 contra los
  nombres extraídos (wait: rig Gamma clásico 16; walk: rig mocap
  LifeForms 44 con `lumbar_*/thorax_*/cervical_*`; wave: parcial de 4,
  solo brazo izquierdo).
- Por joint: `[u8 len][nombre][00][float LE 1.0 solapando el NUL]
  [key-data opaco]`. Nombres + `1.0f` verificados (16/16, 4/4);
  **layout del key-data (quats/Euler, fps, loop, interpolación): NO
  verificado**.
- `axelwait.seq` byte-idéntico a `axelendwave.seq` (causa sin verificar).
- `axelwalk` vs `barbrawalk`: mismo tamaño, difieren desde byte 177
  (mismo rig, distinta performance).
- Tamaño ∝ frames × joints (evidencia a favor, fórmula sin verificar).

## 3. Registro `avatars.dat` / `45.dat` (texto, `# animation registry version 0.3`)

Bloques `avatar name=X geometry=Y.rwx beginimp{walk=… wait=… endwait=…}
beginexp{wave=… yes=… dance=…}`. El cliente añade `avatars\<nombre>.seq`
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

1. Decoder del key-data `.seq` vía Ghidra sobre `gamma.dll`
   (`DroneAnimator_animate/update/getAnimationTime`, exports en
   `docs/gamma-dll-exports.txt:209-224`) — mismo orden de esfuerzo que
   `.cmp`/`.bod`.
2. Retarget mocap→Gamma (44→16).
3. `.mov` como vídeo de texturas (bucle LZSS pendiente,
   `docs/cmp-texture-format-reference.md`).
4. Menores: byte `3f 00` tras nombre de figura, tabla del header `.seq`,
   `csq` (citado en GDK, sin ejemplar).

## 6. Forward del `.bod` (verificado, aplicado en `WorldViewer --play`)

Cara y puntas de pies en **+Z local** (Y-up), coleta/talones en −Z:
`SPIN.RWX` (cabeza −0.006/+0.043, pie −0.005/+0.059) + bytes de
`aura.bod` (coleta −Z, cara +Z); `RWXTOBOD.PL:7,21-25,799-806` pasa ejes
sin tocar. El +Z bod mapea a +Y mundo → rotación `yaw−90°` (álgebra).
GammaDocs confirma Y-up/X-ancho (`Avatar building text.txt:240,402-405`).
