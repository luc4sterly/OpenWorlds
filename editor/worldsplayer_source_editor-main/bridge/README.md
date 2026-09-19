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

Consola: la traza `[NATIVE-MOCK]` es opt-in (`JAVA_OPTS=-Dfreeworlds.nativeLog=true`)
y cada textura que no carga se avisa una sola vez.

`-Dfreeworlds.dumpWindow=DIR` vuelca el árbol de componentes AWT de la
ventana entera (clase, texto y límites) en los segundos 12/20/30/40, para
revisar la maquetación de la UI sin poder capturar la pantalla. El PNG que
intenta con `printAll` sale negro en macOS —la UI son componentes AWT
pesados que pinta el peer nativo— así que solo se escribe si no lo está.

Diagnóstico (desactivado por defecto): `JAVA_OPTS` con
`-Dfreeworlds.dumpFrames=DIR` guarda los frames 1, 10, 100, 1000… de cada
cámara como PNG (o, con `-Dfreeworlds.dumpSeconds=S1,S2`, el primer frame
tras cada segundo), y `-Dfreeworlds.scriptKeys=MS:KEYCODE:HOLD_MS,...`
inyecta pulsaciones AWT sintéticas en el canvas. La captura de pantalla de
macOS no tiene permiso en esta máquina.

## Estado verificado (2026-09-18)

- `home:GroundZero/groundzero.world` entra en GroundZero y lo dibuja con
  su geometría y sus texturas: salas metálicas, suelos de rejilla,
  carteles, y los portales muestran la sala contigua y varias encadenadas.
- Build limpia de 796 clases; estable 45–60 s, `jstack` en `Main.mainLoop`,
  sin procesos huérfanos.
- Entrada verificada inyectando pulsaciones AWT: el piloto avanza y gira.

Red: `run_gamma.sh` levanta `tools/local-upgrade-server.py` y apunta
`upgradeServer` de la copia temporal a `127.0.0.1` (el host original ya no
existe; lo que no hay responde 404 al instante). `build_gamma.sh` parchea
`Cache`/`CacheEntry` para que el `cache.index` de 2004 cargue en macOS
(separador de ruta y `localName` de Windows) y las entradas ya cacheadas no
se refresquen contra el servidor. Con eso las texturas de avatar cacheadas
(`mfa`, `cmalea`, `pengo`, `mia`...) salen de `cachedir/`; faltan las que
nunca estuvieron en la cache original (`cfemaleb`, `cfemaleba`, `cfemalec`,
`cfc`, `fga`, `fja`, `mga`): las nombra `permittedList` de `tables.dat` para
Julie, Roxanne y Simon, cuyas galerias (`IconViewRoom1a/b/f`) se dibujan por
portales; ver `worlds-chat-project.md` (2026-09-18). El servidor local sirve
tambien `base-avatars/` (los `.bod` de esos avatares si estan).

Sigue sin: avatares completos (faltan esas texturas), superficies
web, resaltado, `Shape.convertSpecial`, sonido y vídeo.

## Qué contiene

| Fichero | Traduce |
|---|---|
| `NET/worlds/core/NativeRw.java` | Matrices RW 2.1: multiplicación (0x1005118c), modos 1/2/3 (0x1001c500), `RwRotateMatrix` (0x1001de70→0x1001cb20), `RwScaleMatrix`, `RwTranslateMatrix`, `RwInvertMatrix` afín por adjunta (0x1001dbc0), `RwOrthoNormalizeMatrix` (0x1001c150), `RwQueryRotateMatrix` (0x1001e060), `RwTransformPoint/Vector` |
| `NET/worlds/core/NativeScene.java` | Clumps, escenas, luces y materiales de RWL21 (vértices base 1, polígonos, jerarquía, LTM, bbox mundo/local, tags, estado ON=2/OFF=1, escena por defecto) y los wrappers de gamma.dll con lógica propia (`FUN_00417ac0`, `FUN_00418820/860` y sus callbacks, `FUN_00417950/a10`, `FUN_00419000`, `Surface.addSubPolys` 0x004206d0) |
| `NET/worlds/core/NativeCamera.java` | Cámaras y render por software del driver de 16 bits (`RWDL6D21`): caché por ventana (0x00415fb0), `RwTransformCamera` con ortonormalización y det>0.9, proyección y recorte de RWL21 (0x10009dd0), culling por área en pantalla (0x10051000), iluminación ambiente/difusa/especular por faceta o vértice y paso a 5-6-5 (driver 0x1000d230/0x10019920), texel 0 transparente, opacidad como "screen door", horizonte (0x00417dc0), marca de resaltado (0x00417c40), picking |
| `NET/worlds/core/NativeTextures.java` | Texturas 128×128 5-6-5 (`FUN_0041a150` elige 16 bits), diccionario por nombre con cuenta de referencias (0x004183e0/0x00418430/0x00418370), paleta con clave de transparencia (0x00422b30), `FileTexture` |
| `NET/worlds/core/ScapePic.java` | Cabecera ScapePic (0x00442750) sobre `client/src/net/freeworlds/cmp/CmpFrames` (todos los frames de `.mov` por la tabla de frames) |
| `NET/worlds/core/NativeWindows.java` | Ventanas: la hija de render es el `RenderCanvas` AWT real (0x0040e3f0), instancia de ventana con tamaño de render (0x0040f250/0x0040d950) |
| `NET/worlds/core/RwxReader.java` | El intérprete de scripts `.rwx` de RWL21 (`RwReadShape` 0x10009bf0, bucle 0x100163e0) mandato a mandato: pilas de CTM, joint y material con copia al entrar en un bloque, `ClumpBegin` congelando la CTM (0x1000f560), `ClumpEnd` fusionando la geometría y re-colgando los nietos (0x1000f980), vértices con la CTM interna aplicada (0x10010270), índices base 1 por clump, `Tag`/`Hints`/`AxisAlignment`, `Proto`/`Include` y el estado de material completo |
| `NET/worlds/core/NativeShapes.java` | Lo que `ShapeLoader` recibe de RenderWare: el `.rwx` por `RwxReader`, `RwReadStreamChunk(CLUM)` de un `.rwg` (0x0041e630) y los cuerpos `.bod` (0x0041e440) con su tabla de partes y las etiquetas de hueco con bit 0x8000000 |
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

- **Orden de dibujo**: RW recorre un BSP de clumps de atrás a adelante
  (0x1002cae0) y, dentro de cada clump, un árbol de ordenación de
  polígonos (0x10033750) que sólo usa z-buffer en los tramos conflictivos.
  Aquí se usa z-buffer en todo, que da la oclusión correcta pero no es esa
  traducción; el árbol de ordenación está pendiente. **Ya no falta el
  binario**: ambas funciones están en `decompiled-native/rwl21_dll`
  (2026-09-19). Leído por encima, `0x10033750` construye el árbol UNA vez
  por clump (particiona por plano y agrupa tiradas por material), no por
  frame; con z-buffer la oclusión ya sale bien, así que traducirlo
  cambiaría sobre todo el reparto del z-fighting entre coplanares.
- Del rasterizador sí se sigue el driver de 16 bits: regla de relleno
  `floor(xIzq)..floor(xDer)-1` sin muestreo al centro, Gouraud afín en
  pantalla, sombreado plano en los polígonos texturizados, texel 0
  transparente y el patrón ordenado 8×8 de la translucidez
  (0x10079240/0x10079280). Pendiente: la división de perspectiva por
  tramos de 16 píxeles (aquí es por píxel) y las tablas de color del
  driver.
- ~~Normales de vértice, signo de la normal de polígono~~: **extraídos ya**
  de `RWL21.DLL` (2026-09-19, ver `decompiled-native/rwl21_dll`) y
  corregidos en `NativeCamera`:
  - normal de polígono = suma de productos vectoriales en abanico desde el
    primer vértice, `cross(v[i]-v[0], v[i+1]-v[0])`, normalizada
    (`0x10001100`). Antes era la fórmula de Newell, que coincide en un
    polígono plano pero no en un cuadrilátero alabeado.
  - normal de vértice = suma **sin ponderar** de las normales de las caras
    adyacentes, normalizada (`0x10041df0` vía
    `RwCalculateClumpVertexNormal 0x10031a60`); si la suma se cancela
    exactamente (`<= 0.0f`, leído en `_DAT_100522e8` del binario), RW cae a
    la normal de la **primera** cara adyacente. El puente dejaba un vector
    cero, que apagaba la luz en ese vértice. Medido en Reception: 0 casos
    degenerados, así que es fidelidad sin cambio visible allí.
- Regla de relleno, espacio de interpolación de Gouraud, patrón de la
  opacidad y dithering de texturas: no extraídos.
- `StretchBlt(HALFTONE)` de las texturas de tamaño distinto de 128 (solo
  `windr3.mov`): promedio por cajas.
- `RwReadTexture` (FileTexture): reescalado y formatos no extraídos.
- `RwDestroyScene`: se asume que destruye sus clumps y luces.
- `RwSetClumpVertexUV` rechaza UV fuera del rango del driver; aquí no.
- `Window.install` devuelve 0 como hInstance.
- Del `.rwg` no se decodifican aún sus tablas de material y textura
  (MALT/TELT), así que esas formas salen con el material por defecto.
- Las texturas de una forma se buscan en el diccionario por nombre de
  fichero; RWL21 las lee él mismo desde la ruta de la forma.
- Entrada: tabla AWT→VK de Win32 para las teclas cuyo código difiere; la
  auto-repetición se detecta por "ya pulsada" (AWT no da el bit 30 de
  lParam); `QueryPerformanceCounter` es `System.nanoTime` con frecuencia 1e9.
