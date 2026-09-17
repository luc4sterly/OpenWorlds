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
editor/worldsplayer_source_editor-main/run_gamma.sh home:GroundZero/groundzero.world
```

`build_gamma.sh` copia `source/` (pristino) a `editor/.build-gamma/`
(ignorado por git), aplica `apply_mock.sh` (stubs + este puente) y compila
con `javac --release 8` (769 clases, incluido el decodificador `.cmp` de
`client/`). `run_gamma.sh [URL]` copia `assets/WorldsPlayer` a un
directorio de trabajo (`$FREEWORLDS_GAMMA_DIR`, por defecto
`$TMPDIR/freeworlds-gamma`) y arranca el `main` real; la URL opcional es el
argumento de mundo del propio `Gamma.main` (sin ella arranca en
`home:NewWorld.world`, como el original antes del login).

Diagnóstico (desactivado por defecto): `JAVA_OPTS` con
`-Dfreeworlds.dumpFrames=DIR` guarda los frames 1, 10, 100, 1000… de cada
cámara como PNG (o, con `-Dfreeworlds.dumpSeconds=S1,S2`, el primer frame
tras cada segundo), y `-Dfreeworlds.scriptKeys=MS:KEYCODE:HOLD_MS,...`
inyecta pulsaciones AWT sintéticas en el canvas. La captura de pantalla de
macOS no tiene permiso en esta máquina.

## Estado verificado (2026-09-17)

- `home:GroundZero/groundzero.world`: entra en GroundZero y lo dibuja con
  su geometría real (una sala llega a 7.173 polígonos, 1.581 dibujados en
  un frame) y sus texturas; los portales muestran la sala contigua y
  varias encadenadas al fondo.
- Sin URL arranca como el original en `NewWorld.world`, y la segunda
  cámara (132×130) muestra el banner texturizado `adworlds.cmp`.
- Entrada: flecha arriba mantenida hace avanzar al piloto hasta la pared y
  flecha izquierda lo gira (verificado inyectando pulsaciones AWT).
- Build limpia de 789 clases; estable 45–60 s, `jstack` en `Main.mainLoop`,
  sin procesos huérfanos, y frames idénticos byte a byte entre dos builds.

Sigue sin: avatares (`.bod` de `ShapeLoader.loadBodFile` y `DroneAnimator`;
además sus texturas se descargaban de servidores que ya no responden: 112
fallos por sesión), superficies web (`TextureSurface`, `IEWebControl`),
resaltado (`updateHighlight`), la conversión de clumps "especiales" de un
`.rwx` (`Shape.convertSpecial`), sonido y vídeo.

## Qué contiene

| Fichero | Traduce |
|---|---|
| `NET/worlds/core/NativeRw.java` | Matrices RW 2.1: multiplicación (0x1005118c), modos 1/2/3 (0x1001c500), `RwRotateMatrix` (0x1001de70→0x1001cb20), `RwScaleMatrix`, `RwTranslateMatrix`, `RwInvertMatrix` afín por adjunta (0x1001dbc0), `RwOrthoNormalizeMatrix` (0x1001c150), `RwQueryRotateMatrix` (0x1001e060), `RwTransformPoint/Vector` |
| `NET/worlds/core/NativeScene.java` | Clumps, escenas, luces y materiales de RWL21 (vértices base 1, polígonos, jerarquía, LTM, bbox mundo/local, tags, estado ON=2/OFF=1, escena por defecto) y los wrappers de gamma.dll con lógica propia (`FUN_00417ac0`, `FUN_00418820/860` y sus callbacks, `FUN_00417950/a10`, `FUN_00419000`, `Surface.addSubPolys` 0x004206d0) |
| `NET/worlds/core/NativeCamera.java` | Cámaras y render por software del driver de 16 bits (`RWDL6D21`): caché por ventana (0x00415fb0), `RwTransformCamera` con ortonormalización y det>0.9, proyección y recorte de RWL21 (0x10009dd0), culling por área en pantalla (0x10051000), iluminación ambiente/difusa/especular por faceta o vértice y paso a 5-6-5 (driver 0x1000d230/0x10019920), texel 0 transparente, opacidad como "screen door", horizonte (0x00417dc0), marca de resaltado (0x00417c40), picking |
| `NET/worlds/core/NativeTextures.java` | Texturas 128×128 5-6-5 (`FUN_0041a150` elige 16 bits), diccionario por nombre con cuenta de referencias (0x004183e0/0x00418430/0x00418370), paleta con clave de transparencia (0x00422b30), `FileTexture` |
| `NET/worlds/core/ScapePic.java` | Cabecera ScapePic (0x00442750) sobre `client/src/net/freeworlds/cmp/CmpFrames` (todos los frames de `.mov` por la tabla de frames) |
| `NET/worlds/core/NativeWindows.java` | Ventanas: la hija de render es el `RenderCanvas` AWT real (0x0040e3f0), instancia de ventana con tamaño de render (0x0040f250/0x0040d950) |
| `NET/worlds/core/NativeShapes.java` | `RwReadShape` de un `.rwx` (0x0041ce20) y `RwReadStreamChunk(CLUM)` de un `.rwg` (0x0041e630) sobre los parsers verificados de `client/src/net/freeworlds/rwx` y `rwg`: vértices con UV, un polígono por triángulo y un material RW por material del script |
| `NET/worlds/core/NativeSystem.java` | `GlobalMemoryStatus` de `StatMemNode.updateMemoryStatus` (0x0040a360) |
| `NET/worlds/core/NativeInput.java` | Entrada: el WndProc de gamma.dll (0x0040c970, teclas/botones 0x0040c440, movimiento/delta 0x0040c2c0) sobre los eventos AWT del canvas, cola nativa con fusión de movimientos (0x00416940/0x00416b00), teclas pulsadas liberadas al perder foco o soltar el último botón, modo delta y cursor oculto (0x0040c6a0/0x0040c780/0x0040e670); reloj `GetTickCount` y `Std.getTimeZero` (0x00403e6a) |
| `NET/worlds/core/NativeAssert.java` | Aserción nativa `FUN_00402800`: mismo mensaje y `exit(41)` (sin el MessageBox modal) |
| `natives.patch` | Cuerpos de los stubs de `Transform`, `Point3Temp`, `WObject`, `Surface`, `Room`, `RoomEnvironment`, `Material`, `Camera` (`renderScene` 0x00415190 y el pase de sala 0x00414aa0), `Texture`, `FileTexture`, `ScapePicTexture`, `ScapePicMovie`, `EventQueue`, `Window`, `ActiveX`, y los de `Std` (reloj, `instanceOf`, `byteArraysEqual`, `getenv`, `exit(42)`, versión 1900 y cadenas de build literales de gamma.dll); `NativeMock` con log acotado y `localFile`; `Archive` abre ficheros y `content.zip` a través de `localFile` (la unidad sintética `u:` del parche de `URL`); `PolledDialog` usa `isDisplayable()` en lugar de `getPeer()` (eliminado tras Java 8; un barrido por reflexión de las 934 llamadas al JDK no encuentra más casos); y la corrección de `Room` de abajo |

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
- Formas: el `.rwx` se carga aplanado en un solo clump, mientras que el
  original conserva la jerarquía de `ClumpBegin`/`Tag` (de ahí que
  `Shape.extractSubclump` no encuentre subclumps). Del `.rwg` no se
  decodifican aún sus tablas de material y textura.
- Las texturas de una forma se buscan en el diccionario por nombre de
  fichero; RWL21 las lee él mismo desde la ruta de la forma.
- Entrada: tabla AWT→VK de Win32 para las teclas cuyo código difiere; la
  auto-repetición se detecta por "ya pulsada" (AWT no da el bit 30 de
  lParam); `QueryPerformanceCounter` es `System.nanoTime` con frecuencia 1e9.
