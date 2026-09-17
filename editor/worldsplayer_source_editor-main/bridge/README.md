# Puente portable gamma.dll / RenderWare 2.1

Permite que el cliente **original** decompilado (`NET.worlds.console.Gamma`,
Java de `lib/gammacls.zip`) arranque en macOS/Linux sin `gamma.dll` ni
`RWL21.DLL`. No es un motor nuevo: cada cuerpo nativo es la traducción de
lo que hace el C decompilado de `gamma.dll`
(`decompiled-native/gamma_dll/`) y, por debajo, de lo que hacen las
funciones de RenderWare 2.1 según el desensamblado de `RWL21.DLL`. Las
direcciones de evidencia están en los comentarios de cada método.

## Uso

```bash
editor/worldsplayer_source_editor-main/build_gamma.sh
```

```bash
editor/worldsplayer_source_editor-main/run_gamma.sh
```

`build_gamma.sh` copia `source/` (pristino) a `editor/.build-gamma/`
(ignorado por git), aplica `apply_mock.sh` (stubs + este puente) y compila
con `javac --release 8` (763 clases, incluido el decodificador `.cmp` de `client/`). `run_gamma.sh [DIR]` copia
`assets/WorldsPlayer` a un directorio de trabajo (por defecto
`$TMPDIR/freeworlds-gamma`) y arranca el `main` real desde ahí.

## Estado verificado (2026-09-17)

Arranca, se queda en el bucle principal real (`Main.mainLoop`) y **dibuja**:
la vista principal (468×244) muestra la sala inicial de `NewWorld.world`
en perspectiva y la segunda cámara (132×130) el banner texturizado
`adworlds.cmp`. Build limpia de 763 clases; dos ejecuciones (scratch y
`build_gamma.sh`) dan frames PNG idénticos byte a byte. Probado 40–60 s
sin excepciones.

Diagnóstico: `JAVA_OPTS=-Dfreeworlds.dumpFrames=DIR run_gamma.sh` guarda
los frames 1, 10, 100, 1000… de cada cámara (la captura de pantalla de
macOS no tiene permiso en esta máquina).

Sigue sin: sonido, vídeo, ActiveX, carga de formas `.rwx` por
`ShapeLoader`, avatares animados (`DroneAnimator`) y el resaltado de
objetos (`updateHighlight`). La sala es la de arranque: GroundZero llega
tras login/teleport. El bucle va sin freno.

## Qué contiene

| Fichero | Traduce |
|---|---|
| `NET/worlds/core/NativeRw.java` | Matrices RW 2.1: multiplicación (0x1005118c), modos 1/2/3 (0x1001c500), `RwRotateMatrix` (0x1001de70→0x1001cb20), `RwScaleMatrix`, `RwTranslateMatrix`, `RwInvertMatrix` afín por adjunta (0x1001dbc0), `RwOrthoNormalizeMatrix` (0x1001c150), `RwQueryRotateMatrix` (0x1001e060), `RwTransformPoint/Vector` |
| `NET/worlds/core/NativeScene.java` | Clumps, escenas, luces y materiales de RWL21 (vértices base 1, polígonos, jerarquía, LTM, bbox mundo/local, tags, estado ON=2/OFF=1, escena por defecto) y los wrappers de gamma.dll con lógica propia (`FUN_00417ac0`, `FUN_00418820/860` y sus callbacks, `FUN_00417950/a10`, `FUN_00419000`, `Surface.addSubPolys` 0x004206d0) |
| `NET/worlds/core/NativeCamera.java` | Cámaras y render por software del driver de 16 bits (`RWDL6D21`): caché por ventana (0x00415fb0), `RwTransformCamera` con ortonormalización y det>0.9, proyección y recorte de RWL21 (0x10009dd0), culling por área en pantalla (0x10051000), iluminación ambiente/difusa/especular por faceta o vértice y paso a 5-6-5 (driver 0x1000d230/0x10019920), texel 0 transparente, opacidad como "screen door", horizonte (0x00417dc0), marca de resaltado (0x00417c40), picking |
| `NET/worlds/core/NativeTextures.java` | Texturas 128×128 5-6-5 (`FUN_0041a150` elige 16 bits), diccionario por nombre con cuenta de referencias (0x004183e0/0x00418430/0x00418370), paleta con clave de transparencia (0x00422b30), `FileTexture` |
| `NET/worlds/core/ScapePic.java` | Cabecera ScapePic (0x00442750) sobre `client/src/net/freeworlds/cmp/CmpFrames` (todos los frames de `.mov` por la tabla de frames) |
| `NET/worlds/core/NativeWindows.java` | Ventanas: la hija de render es el `RenderCanvas` AWT real (0x0040e3f0), instancia de ventana con tamaño de render (0x0040f250/0x0040d950) |
| `NET/worlds/core/NativeAssert.java` | Aserción nativa `FUN_00402800`: mismo mensaje y `exit(41)` (sin el MessageBox modal) |
| `natives.patch` | Cuerpos de los stubs de `Transform`, `Point3Temp`, `WObject`, `Surface`, `Room`, `RoomEnvironment`, `Material`, `Camera` (`renderScene` 0x00415190 y el pase de sala 0x00414aa0), `Texture`, `FileTexture`, `ScapePicTexture`, `ScapePicMovie`, `Window`, `ActiveX`; `NativeMock` con log acotado y `localFile`; `Archive` abre ficheros y `content.zip` a través de `localFile` (la unidad sintética `u:` del parche de `URL`); y la corrección de `Room` de abajo |

## Error de decompilación encontrado

`Room` llamaba a `super.add(this.environment)`, que Java resuelve como
`WObject.add(WObject)` y mete el entorno dos veces en la escena (aserción
en `RoomEnvironment.addLight`). El bytecode original llama a
`WObject.add(SuperRoot)`. Para comprobar que no hay más casos así se
comparan los destinos de todas las llamadas de las 736 clases originales
con los recompilados (`tools/bytecode-call-diff.py`): quedan 55 métodos con
diferencias, todas inocuas (receptores más estrechos, `close()` de
try-with-resources, la propia capa de mocks), salvo esta.

## ⚠️ Pendiente de verificar

- **Orden de dibujo**: RW ordena clumps con un BSP y polígonos con un
  árbol por clump (0x10033750, sin extraer); aquí cada pase usa un
  z-buffer propio, que es lo que esos órdenes aproximan.
- Normales de vértice (media de las caras adyacentes), signo de la normal
  de polígono, regla de relleno, espacio de interpolación de Gouraud,
  patrón de la opacidad y dithering de texturas: no extraídos.
- `StretchBlt(HALFTONE)` de las texturas de tamaño distinto de 128 (solo
  `windr3.mov`): promedio por cajas.
- `RwReadTexture` (FileTexture): reescalado y formatos no extraídos.
- `RwDestroyScene`: se asume que destruye sus clumps y luces.
- `RwSetClumpVertexUV` rechaza UV fuera del rango del driver; aquí no.
- `Window.install` devuelve 0 como hInstance.
