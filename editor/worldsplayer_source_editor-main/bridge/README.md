# Puente portable gamma.dll / RenderWare 2.1

Permite que el cliente **original** decompilado (`NET.worlds.console.Gamma`,
Java de `lib/gammacls.zip`) arranque en macOS/Linux sin `gamma.dll` ni
`RWL21.DLL`. No es un motor nuevo: cada cuerpo nativo es la traducción de
lo que hace el C decompilado de `gamma.dll`
(`decompiled-native/gamma_dll/`) y, por debajo, de lo que hacen las
funciones de RenderWare 2.1 según el desensamblado de `RWL21.DLL`. Las
direcciones de evidencia están en los comentarios de cada método.

## Uso

Para jugar, el paquete (`tools/build-dist.sh` o los artefactos de la CI):
su lanzador prepara una copia de la instalación en la carpeta de datos del
usuario, levanta el servidor local de actualización y arranca `Gamma` con
el Java del paquete (ver `launcher/`). Para desarrollar y diagnosticar:

```bash
editor/worldsplayer_source_editor-main/build_gamma.sh
```

```bash
editor/worldsplayer_source_editor-main/run_gamma.sh home:GroundZero/groundzero.world
```

`build_gamma.sh` copia `source/` (pristino) a `editor/.build-gamma/`
(ignorado por git), aplica `apply_mock.sh` (stubs + este puente), las
adaptaciones de plataforma de `build_gamma.sh` (caché de 2004, `Std.initSyncTime`,
`host_paths.py` y `ui_fonts.py`, ver abajo) y compila
con `javac --release 8` (~900 clases, incluidos los decodificadores `.cmp`,
`.rwg` y `.bod`/`.seq` de `client/`). Tras `natives.patch` se aplican los
`natives-<subsistema>.patch` por orden de nombre (animator, media, system,
text, ui). Si `javac` falla, `build_gamma.sh` sale con 1. `run_gamma.sh [URL]` copia `assets/WorldsPlayer` a un
directorio de trabajo (`$FREEWORLDS_GAMMA_DIR`, por defecto
`$TMPDIR/freeworlds-gamma`) y arranca el `main` real; la URL opcional es el
argumento de mundo del propio `Gamma.main` (sin ella arranca en
`home:NewWorld.world`, como el original antes del login).

Consola: la traza `[NATIVE-MOCK]` es opt-in (`JAVA_OPTS=-Dfreeworlds.nativeLog=true`)
y cada textura que no carga se avisa una sola vez. El cliente de 2004 manda
su salida a `Gamma.Log.open` (`LogFile=` de `worlds.ini`); `run_gamma.sh`
vacía esa clave en la copia de trabajo para que la salida quede en la
terminal, y `FREEWORLDS_GAMMA_LOG=1` conserva el log original.

Otras opciones: `-Dfreeworlds.animLog=1` (DroneAnimator), `-Dfreeworlds.mute=1`
(sin abrir audio; misma lógica y tiempos), `-Dfreeworlds.openUrls=1` (abrir en
el navegador del sistema las URLs que el usuario pide con un clic; por
defecto solo se registran), `-Dfreeworlds.typeChat=MS:texto` /
`-Dfreeworlds.typePassword=MS:[x]texto` (teclear como una persona),
`-Dfreeworlds.registry=FICHERO` (registro de Windows portable, REGEDIT4) y
`-Dfreeworlds.volumeSerial=0x…` (serie de volumen para descifrar una
contraseña guardada en otro disco). Red con sesión contra un whirl local:
`FREEWORLDS_SERVER=127.0.0.1:6650` (+ `FREEWORLDS_USER`, `FREEWORLDS_LOGIN`,
`FREEWORLDS_CHAT`, `FREEWORLDS_NETDEBUG`); ver `docs/net-local-whirl.md`.

Comprobaciones: `bridge/test/*Check.java` (casos calculados a mano, uno por
subsistema) se ejecutan con `tools/run-checks.sh`, que reconstruye el puente
si su build es anterior a los cambios.

`-Dfreeworlds.dumpWindow=DIR` vuelca el árbol de componentes AWT de la
ventana entera (clase, texto y límites) en los segundos 12/20/30/40, para
revisar la maquetación de la UI sin poder capturar la pantalla. El PNG que
intenta con `printAll` sale negro en macOS —la UI son componentes AWT
pesados que pinta el peer nativo— así que solo se escribe si no lo está.

Diagnóstico (desactivado por defecto): `JAVA_OPTS` con
`-Dfreeworlds.dumpFrames=DIR` guarda los frames 1, 10, 100, 1000… de cada
cámara como PNG (o, con `-Dfreeworlds.dumpSeconds=S1,S2`, el primer frame
tras cada segundo; o, con `-Dfreeworlds.dumpRange=SEG:N`, N frames
**consecutivos** desde el segundo SEG, que es lo que hace falta para mirar
un giro), y `-Dfreeworlds.scriptKeys=MS:KEYCODE:HOLD_MS,...`
inyecta pulsaciones AWT sintéticas en el canvas. La captura de pantalla de
macOS no tiene permiso en esta máquina.

Para saber **qué objeto pinta qué**: `-Dfreeworlds.matStats=SEG` lista, una
vez por segundo y sala, los materiales visibles ordenados por píxeles
dibujados, con su color 565, si la textura está puesta y resuelta, y el
`WObject` dueño; `-Dfreeworlds.probePixel=X,Y` dice quién se queda con ese
píxel; `-Dfreeworlds.traceTextures=1` traza cada `RwSetMaterialTexture`; y
`-Dfreeworlds.fps=1` imprime los frames por segundo de la cámara principal,
su posición y su dirección, más la cobertura (píxeles escritos por frame
frente al tamaño del raster: por encima del 100 % hay sobredibujado).

⚠️ Al leer `matStats`: el color que sale es el **color base del material**,
no el del píxel. Los `Rect` del mundo llevan su textura puesta por el
cliente (`Material.nativeSetTexture`), no por el script de la forma, así
que su nombre de textura del `.rwx` es nulo aunque estén texturizados —
medido: en GroundZero **todos** los materiales visibles salen "CON
textura".

## Estado verificado (2026-09-26)

- `home:GroundZero/groundzero.world` entra en GroundZero y lo dibuja con
  su geometría y sus texturas, con el rasterizador del driver (triángulos en
  abanico, tabla de recíprocos, perspectiva cada 16 px) y los `Rect` de
  celdas (`2h*2v*`) que antes no salían.
- Las 6 figuras de las galerías (`avatar.rwg`, clump vacío válido) crean su
  DroneAnimator, reciben `prepFigure` y `moveto`/`update`
  (`-Dfreeworlds.animLog=1`). Giran, y el C las deja en los estados 1/2,
  que no tienen secuencia.
- Contra un whirl local: login, dos clientes en la misma sala y chat
  tecleado con Intro que llega al otro. No se ven: whirl no manda
  APPRACTR (`hub.rs:246`, comentado).
- El cliente escribe su `Gamma.Log` de 2004 con `FREEWORLDS_GAMMA_LOG=1`,
  con el informe de `SystemInfo.Record`.
- `tools/run-checks.sh`: 40/40 (con `RasterGoldenCheck` y `MatrixAffineCheck`); las excepciones
  que salen en GroundZero (`WorldScriptGroundZero` y
  `NoWebControlException` de los carteles) son el camino del propio
  cliente. Corrección del 2026-09-26: el error de `redir.txt` que salía
  aquí **no** era del original (su `Gamma.Log` no lo tiene): era la ruta
  `u:/...` en minúsculas, arreglada con `HostPath`.

### Añadido el 2026-09-26 (sesión de empaquetado)

- **Menús de la ventana visibles.** `ImageCanvas.loadLocalImage` hacía
  `Toolkit.getImage("u:/.../rtpanel.gif")`: en Windows valía, aquí el
  fichero no existe y los `ImageButtons` (Help, Options, WorldsMail,
  Teleport, Actions, VIP, Quit, Universe Map...), el mapa y la lista de
  amigos salían negros. `HostPath.of` (con `host_paths.py`, 151 llamadas en
  50 clases del código pristino) quita la unidad sintética y resuelve sin
  mayúsculas en cada `new File/FileInputStream/.../ZipFile` y
  `Toolkit.getImage`. En Windows no hace nada.
- **Sin bloqueo al arrancar.** El primer `Std.getSynchronizedTime()` (lo
  pide `BlackBox.postrender` en cada frame) abría un `Socket` sin timeout
  a `time.worlds.net:37` dentro del hilo de render: ventana negra hasta el
  timeout de TCP (75 s en macOS). La base sale ahora del reloj del sistema
  con la misma resta del bytecode (`ldc2_w -1141367296l; lsub`: el
  `100*365*86400` desbordado del original, origen 1999-12-08) y el
  servidor, si respondiera, la corrige desde otro hilo con timeouts de 2 s.
- **Fuentes con las métricas de 2004** (`NativeUiFonts`, `ui_fonts.py`):
  el `font.properties` del JRE 1.4 de la instalación resolvía `dialog` y
  `sansserif` a Arial; un JDK moderno usa DejaVu/Lucida, más anchas, y la
  barra de estado decía "Jse arrow keys". Se usa Arial si está (macOS,
  Windows) o una de métricas iguales (Liberation/Arimo en Linux).
  `-Dfreeworlds.modernFonts=true` vuelve a las del JDK.
- **Rasterizador por franjas** (`NativeCamera.rasterize`): la pasada de
  clumps graba los triángulos (en el orden del driver) y se dibujan por
  bandas horizontales en `-Dfreeworlds.rasterThreads` hilos (por defecto
  los procesadores, máximo 8). Cada banda recorre toda la lista y un
  triángulo solo escribe sus filas, así que cada píxel recibe las mismas
  escrituras en el mismo orden: `RasterGoldenCheck` compara el CRC de 18
  vistas de una escena de 56 formas reales con el motor anterior (idéntico
  con 1, 2, 4 y 8 hilos). Además: recorte sin asignaciones, spans que solo
  interpolan lo que usa el camino del píxel y volcado a pantalla por tabla
  565→RGB (el `drawImage` de la imagen 565 iba por el bucle genérico de
  Java2D). GroundZero a 1172×848: 25 → ~53 fps; a 468×272: 72 → ~90.
- **Producto de matrices afín** (`NativeRw.mul/mulInto`): RWL21 multiplica
  solo el 3×3 más la fila de traslación (`RwMultiplyMatrix` 0x1001db10 →
  0x1005118c) y no toca la cuarta columna; el puente hacía un 4×4 completo.
  Los `Transform` del `.world` traen ahí datos internos de RW (p. ej.
  `m[15] = 2e-37`), así que un hijo perdía la traslación del padre y todo
  lo que cuelga de un `WObject` contenedor (30 en GroundZero) se dibujaba
  en el origen de la sala: faltaban el soporte con cuerdas del Auditorium
  y la puerta en iris de IconViewRoom1Enter (se ve desde AvatarEnter y
  desde la puerta "Avatar Gallery" de Reception). Mismo orden de sumas:
  con matrices limpias, bit a bit igual (`MatrixAffineCheck`,
  `RasterGoldenCheck`).
- `-Dfreeworlds.dumpScene=SEG` (y `dumpSceneMatrices`): vuelca el árbol de
  clumps de cada escena (objeto, estado, polígonos, posición en el mundo).
- **Material de las partes `.bod`** (`NativeShapes.buildBod`): gamma.dll
  FUN_0041d950 hace `RwPushCurrentMaterial`,
  `RwSetMaterialSurface(0.32, 0.55, 0.0)` (los floats de `DAT_00470ac4`,
  `DAT_00470ac0` y `DAT_00470abc` leídos del `.data` de gamma.dll: la
  misma superficie que `PosableShape`), el color de la parte y
  `FUN_00417a10` (`RwSetMaterialLightSampling(2)` +
  `RwAddTextureModeToMaterial(1)`): liso, con luz por vértice. Aquí era
  (0.75, 0, 0) y facetado, y las estatuas y drones salían planos, sin
  sombreado.

Red: `run_gamma.sh` levanta `tools/local-upgrade-server.py` y apunta
`upgradeServer` de la copia temporal a `127.0.0.1` (el host original ya no
existe; lo que no hay responde 404 al instante). `build_gamma.sh` parchea
`Cache`/`CacheEntry` para que el `cache.index` de 2004 cargue en macOS
(separador de ruta y `localName` de Windows) y las entradas ya cacheadas no
se refresquen contra el servidor. Faltan, y no están en ningún sitio, las
texturas `cfemaleb`, `cfemaleba`, `cfemalec`, `cfc`, `fga`, `fja` y `mga` de
Julie, Roxanne y Simon (`docs/worlds-chat-project.md`, 2026-09-18).

## Qué contiene

| Fichero | Traduce |
|---|---|
| `NET/worlds/core/NativeRw.java` | Matrices RW 2.1: multiplicación (0x1005118c), modos 1/2/3 (0x1001c500), `RwRotateMatrix` (0x1001de70→0x1001cb20), `RwScaleMatrix`, `RwTranslateMatrix`, `RwInvertMatrix` afín por adjunta (0x1001dbc0), `RwOrthoNormalizeMatrix` (0x1001c150), `RwQueryRotateMatrix` (0x1001e060), `RwTransformPoint/Vector` |
| `NET/worlds/core/NativeScene.java` | Clumps, escenas, luces y materiales de RWL21 (vértices base 1, polígonos, jerarquía, LTM, bbox mundo/local, tags, estado ON=2/OFF=1, escena por defecto) y los wrappers de gamma.dll con lógica propia (`FUN_00417ac0`, `FUN_00418820/860` y sus callbacks, `FUN_00417950/a10`, `FUN_00419000`, `Surface.addSubPolys` 0x004206d0) |
| `NET/worlds/core/NativeCamera.java` | Cámaras y render por software del driver de 16 bits (`RWDL6D21`): caché por ventana (0x00415fb0), `RwTransformCamera` con ortonormalización y det>0.9, proyección y recorte de RWL21 (0x10009dd0), culling por área en pantalla (0x10051000), iluminación ambiente/difusa/especular por faceta o vértice y paso a 5-6-5 (driver 0x1000d230/0x10019920), texel 0 transparente, opacidad como "screen door", horizonte (0x00417dc0), marca de resaltado (0x00417c40), picking. Triángulos del driver (vértices a la rejilla, pendientes con la tabla de recíprocos 0x1000a008, avance antes de pintar, abanico del último al primero), tramo texturizado 0x1002cbb0 con perspectiva cada 16 px y u/v empaquetados, Gouraud en espacio de color con tramado de G (0x1006a340), árbol de ordenación por clump 0x10033750 y modos de hints (0x10033600: más de 1000 polígonos → editable), rango de UV 0..256 (0x10017de0), `RwDestroyScene` (0x100306b0), `WObject.nativeInCamSpace` (0x00413910) |
| `NET/worlds/core/NativeTextures.java` | Texturas: StretchBlt COLORONCOLOR (modo 3, 0x422682 → `GDI32!SetStretchBltMode` por la IAT 0x487814) a 128×128 5-6-5 (FUN_004222b0) con la paleta de FUN_00422b30; diccionario de RW (nombre base 0x10043e80, comparación 0x10043f20, duplicados rechazados) con la cuenta de gamma.dll (0x004183e0/0x00418370); `RwReadTexture`: BMP/RAS (0x10021620/0x10021da0), reescalado por área a 128 o 16 (0x10042f30), conversión del driver (0x10007a80, negro → 1); `RwGetNamedTexture` con la ruta ".;.." y .ras/.tex/.env/.bmp/.rle; `StringTexture` (0x00424af0/0x00424870) |
| `NET/worlds/core/ScapePic.java` | Cabecera ScapePic (0x00442750) sobre `client/src/net/freeworlds/cmp/CmpFrames` (todos los frames de `.mov` por la tabla de frames) |
| `NET/worlds/core/NativeWindows.java` | Ventanas: la hija de render es el `RenderCanvas` AWT real (0x0040e3f0), instancia de ventana con tamaño de render (0x0040f250/0x0040d950) |
| `NET/worlds/core/RwxReader.java` | El intérprete de scripts `.rwx` de RWL21 (`RwReadShape` 0x10009bf0, bucle 0x100163e0) mandato a mandato: pilas de CTM, joint y material con copia al entrar en un bloque, `ClumpBegin` congelando la CTM (0x1000f560), `ClumpEnd` fusionando la geometría y re-colgando los nietos (0x1000f980), vértices con la CTM interna aplicada (0x10010270), índices base 1 por clump, `Tag`/`Hints`/`AxisAlignment`, `Proto`/`Include` y el estado de material completo; `Texture`/`TextureExt` resuelve con `RwGetNamedTexture` al leer (0x10014b00) y si no hay textura la forma entera da 0 |
| `NET/worlds/core/NativeShapes.java` | Lo que `ShapeLoader` recibe de RenderWare: el `.rwx` por `RwxReader` + callback 0x004187e0 (tag < 0x4000000 → hints 2, si no OFF); barridos previos de texturas de `loadTextFile` (0x0041cba0) y de la cabecera `.rwg` (FUN_0041c970); `RwReadStreamChunk(CLUM)` (0x10039e40, leído en ASM) con TELT (diccionario/ruta de formas, error 0x5e), materiales de MALT, PLST con material y tag, ATOM con estado/ejes/matrices/hijos (ATOM vacío = clump válido); cuerpos `.bod` (0x0041e440); `Shape.convertSpecial` (0x0041f1b0 → `TwoWayPortal`/`Rect`) |
| `NET/worlds/core/NativeSystem.java` | `GlobalMemoryStatus` de `StatMemNode.updateMemoryStatus` (0x0040a360) |
| `NET/worlds/core/NativeInput.java` | Entrada: el WndProc de gamma.dll (0x0040c970, teclas/botones 0x0040c440, movimiento/delta 0x0040c2c0) sobre los eventos AWT del canvas, cola nativa con fusión de movimientos (0x00416940/0x00416b00), teclas pulsadas liberadas al perder foco o soltar el último botón, modo delta y cursor oculto (0x0040c6a0/0x0040c780/0x0040e670); reloj `GetTickCount` y `Std.getTimeZero` (0x00403e6a) |
| `NET/worlds/core/NativeAnimator.java` + `Anim*.java`, `natives-animator.patch` | `DroneAnimator` y `PendingCacheDrone` de gamma.dll: registro `avatars.dat` (flex FUN_0042a4c0, FUN_0042cb90), caché de `.seq` y descargas (FUN_0042ffd0/0042fc90, 0x44bda0), drivers por tiempo y por distancia (key truncado: RC chop en 0x43b9c0), mezcla de implícitos de 250 ms ({0, 0xfa} en FUN_00432d10) y de gestos 8x(1−x), máquina walk/wait/endwait (FUN_00434670), `update` (FUN_00435520/00433710), aplicación de la pose (FUN_00434470) y `prepFigure` (FUN_00434f00). Regla escrita en `docs/seq-animation-reference.md` §7 |
| `NET/worlds/core/NativeUi*.java`, `natives-ui.patch` | Adaptación de plataforma (no es de gamma.dll): devuelve el modelo de eventos 1.0 a los `TextField`/`TextArea`, cuyo peer ligero (JDK ≥ 9, macOS) pone `newEventsOnly`, con las reglas de `AWTEvent.convertToOld`: el chat funciona con Intro. `Console.encrypt/decrypt` (0x0040b7f0/0x0040bb00); serie de volumen e instancia única de `Startup` (0x00409e70/80, 0x004098b0 + FUN_00409ce0, enganchada a `Window.install`); `Cursor` (tabla IDC de 0x0046e81c, `.cur`, aplicado por `Window.setCursor`); `RightMenu`, `FileSysDialog`, `RenderCanvasOverlay`, `ImageConverter`, `ScapePicImage`/`ScapePicCanvas` |
| `NET/worlds/core/NativeSys*.java`, `natives-system.patch` | `RegKey` sobre un registro portable REGEDIT4 (0x00402360-0x00402770); `SystemInfo` con la aritmética y las cadenas del binario (0x00442020-0x00442470); COM fuera de Windows: `getPtr`, la fábrica de clases propia de gamma.dll y las ramas de fallo de ole32 con sus mensajes literales (0x0040ab80-0x0040b450, 0x00441f30); `VehicleShape` (0x0043f4c0-0x0043f580); `CreateProcSpecial` (0x00404740); `Restorer.makeArray` (0x0041a8d0); `get3DHardware*` = false (0x0043c4f0/510); `Pilot.nativeInit`; `VoiceChat.terminateVC` |
| `NET/worlds/core/NativeMedia*.java`, `ImaAdpcmWav.java`, `natives-media.patch` | Sonido: `PlaySound` y `waveOutSetVolume` de `WavSoundPlayer` (0x00420120..0x00420200; 65535.0f en 0x4711f8), MCI waveaudio/sequencer de `MCISoundPlayer` (0x0041f780..0x0041fe40), ASF sin `playfile.exe` (0x0041f670), flags `disableWav/MIDI/ASF` (0x00420260/0x00420030); salida por javax.sound y WAV IMA ADPCM. DirectShow y CD por su camino de fallo (0x0043f180..0x0043f450, 0x004153e0..0x00415ea0). IE embebido (`nativeInit` → false), `WebBrowser`/`IWebBrowserApp` (IOException), DDE, `TextureSurface`; `launchViaRegistry`/`sendURL` registran la URL |
| `natives-text.patch` | `StringTexture.makeStringTexture` → `NativeTextures.makeStringTexture` |
| `NET/worlds/core/NativeAssert.java` | Aserción nativa `FUN_00402800`: mismo mensaje y `exit(41)` (sin el MessageBox modal) |
| `NET/worlds/core/HostPath.java`, `host_paths.py` | Plataforma: rutas `u:/...` del cliente a ficheros reales en cada apertura de fichero y `Toolkit.getImage` |
| `NET/worlds/core/NativeUiFonts.java`, `ui_fonts.py` | Plataforma: `new Font(...)` y la fuente por defecto de `GammaFrame` con las fuentes del `font.properties` de 2004 (o de métricas iguales) |
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

Render:
- **BSP de clumps de escena** (RWL21 0x1002d170, recorrido 0x1002cae0):
  leído en ASM y sin traducir; es incremental y su resultado depende del
  historial de operaciones. Lo que se sabe:
  - Cada clump es un nodo (0x1002c120). Se ordenan por diagonal² (qsort de
    MSVC 0x10045270, comparador 0x1002f0f0) y se insertan del mayor al menor.
  - Los planos salen de 0x1002dde0, con un margen de -0.01f.
  - Lo que no se separa forma listas tipo 2 y conflictos 0x10.
  - Un clump que se mueve se retira y se reinserta.
  - El recorrido forma grupos con un z-buffer de 16 bits propio
    (0x10069650, `RwDeviceControl(7)`).

  El puente mantiene un z-buffer global de 1/Z y el árbol por clump; la
  información de "z solo en los tramos con conflicto" está calculada pero
  sin usar.
- Rasterizadores sin traducir: translúcidos (0x1001a860, 0x10027de0/0x1006a440)
  y Gouraud texturizado (0x1002ffc0). Tampoco se ha comprobado el efecto del
  bit 8 de textura "nativa".
- Orden exacto de las operaciones x87 en 0x10069650 y precisión de la FPU
  (el puente supone 53 bits); interpolación de UV fijas en el recortador.
- `NativeScene` no guarda la normal de cara de PLST, los 3 reales de la
  bandera 4 ni la normal de vértice sin normalizar (diferencia de 1e-4 en el
  corpus).

Texturas:
- StretchBlt es COLORONCOLOR, no HALFTONE. Qué píxel de origen elige gdi32
  y cómo convierte el color a 5-6-5 no está en nuestros binarios. El
  puente usa `d*s/D` y descarta los bits bajos; solo una captura en Windows
  lo resuelve.
- Glifos de `StringTexture`: Java2D sin suavizado, no GDI (MS Gothic no está
  en este Mac).

Formas:
- `.rwg`: RALT/RAST y ATOM con hijos se leen según el binario, pero no hay
  ninguna muestra real; RAST no se convierte (0 si una TELT lo usa).
  `cube.rwg` no carga en RW 2.1 (TELT de 16 bytes); falta confirmarlo bajo Wine.
- La máscara de `Texture … mask` no está traducida (se ignora).
- `RwxReader` acepta mandatos desconocidos, cuando RW falla con error 4, y
  le faltan `block`, `cylinder`, `cone`, `disc`, `sphere`, `hemisphere`,
  `trace` y `texture*state` (tabla 0x1005a260).

Animación:
- No se ha visto un avatar andando o en wait dentro de GroundZero: las
  estatuas giran (~70°/s) y se quedan en los estados 1/2. Hace falta un
  drone por red (whirl no los manda) o un mundo con un avatar que no gire.
- El catch de los errores de sintaxis de `avatars.dat` (throw de C++) no
  está localizado.

UI, sistema y medios:
- La contraseña guardada en 2004 solo se descifra con
  `-Dfreeworlds.volumeSerial`: la serie de volumen de aquí es `unix:dev`.
- `setDIBPixelInts` reproduce un fallo del original: direcciona en bytes,
  así que un JPEG de color directo queda en el primer cuarto de la textura.
  Falta decidir si se corrige.
- Cursores sin equivalente en AWT: APPSTARTING, NO y UPARROW; los `.ani`
  no se decodifican.
- `FileSysDialog`: AWT no tiene lista de filtros ni `lpstrDefExt`.
- Comportamientos que solo se pueden comprobar en Windows:
  - `CoRevokeClassObject` con una cookie desconocida;
  - `advapi32` con componentes vacíos o creando bajo KEY_READ;
  - el límite de 2 GB de `GetDiskFreeSpace` en Win9x;
  - la separación de argumentos de `CommandLineToArgvW`.
- Curva de volumen de waveOut (aquí lineal); `SND_PURGE` con nombre; textos
  de `mciGetErrorString`; el decodificador IMA ADPCM no está comparado
  muestra a muestra con `imaadp32.acm`.
- El candado de URLs (`-Dfreeworlds.openUrls` + origen de usuario) es un
  criterio del puente, no del binario.

Red:
- Carrera `_connectThread` del cliente de 2004 (verificada en el bytecode:
  `WSConnecting` arranca sus hilos antes de que `state_Initializing` asigne
  el campo). Contra un servidor local cuelga unas 4 de cada 27 conexiones;
  `run-whirl-duo.sh` reintenta. No se parchea: sería cambiar el
  comportamiento original.

Entrada:
- Tabla AWT→VK de Win32 para las teclas cuyo código difiere; la
  auto-repetición se detecta por "ya pulsada" (AWT no da el bit 30 de
  lParam); `QueryPerformanceCounter` es `System.nanoTime` con frecuencia 1e9.
- `Window.install` devuelve 0 como hInstance.
