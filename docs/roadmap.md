# Hoja de ruta — FreeWorlds

Preparada el 2026-09-22 a partir del árbol real en `89d4548`, más el diff
sin commitear de `NativeCamera`/`NativeTextures`. Lo que no se ha podido
comprobar en esta revisión va marcado ⚠️ VERIFICAR.

## 0. Qué cambia respecto a CLAUDE.md

1. **Los frames > 0 de `.mov` ya se decodifican, pero solo en el puente.**
   `CmpFrames` (commit `496f102`) decodifica todos los frames y
   `bridge/NET/worlds/core/ScapePic.java:27` lo usa. El cliente propio sigue
   en `CmpStage1.decodeMovFrame0` (`client/.../cmp/CmpTexture.java:144`),
   con los dos errores que documenta ese commit: en `cave`/`cbirda4`/`club…`
   coge el **último** frame, y en `windr3` intercambia ancho y alto.
2. **La animación de avatares del original pasa por `DroneAnimator`, y no
   está en el puente.** Sus 16 nativos están todos exportados por gamma.dll
   (`docs/gamma-dll-exports.txt`) y decompilados
   (`decompiled-native/gamma_dll/004165c0_…animate…`, `00416530_…moveto…`,
   …). La parte Java que los llama ya corre: `PosableShape.java:1180`
   (`animate`), `:1237` (`moveto`), `PendingDrone.java:192` (`loadconfig`
   de `avatars.dat`). O sea, el abierto nº 1 ("qué secuencia elige el
   cliente") se resuelve **traduciendo esos nativos**, no deduciéndolo.
3. **"UI 0 %" solo vale para el cliente propio.** Bajo el puente, la UI AWT
   del original ya se monta: `-Dfreeworlds.dumpWindow` muestra
   `FriendsListPart`, `MapPart`, chat de 280×100 y campo de entrada. Lo que
   falta ahí son nativos concretos (tabla de H5) y un servidor con el que
   hablar.
4. **`server/whirl` no comprueba la contraseña.** `distributor.rs:78-83`
   solo lee `VAR_USERNAME` del `SessInit`. Si lo compilamos en local (Rust
   fijado a `nightly-2024-06-03`, SQLite incluido en la build, instalable
   con rustup sin Homebrew), podemos probar el flujo con sesión (chat,
   amigos, salas, varios clientes) sin la cuenta real. ⚠️ VERIFICAR que el
   cliente acepta el tipo de servidor que anuncia whirl: el primario
   responde `#15=1`, lo que lleva a `UserServer`.
5. **El `Light.setLightTransform` que falta en el puente no afecta a nada:**
   `lightID` nunca se asigna en el Java decompilado. La luz de sala va por
   `Room.addLight`/`setLightPosition`, que sí están traducidos.
6. **Hay trabajo sin commitear:** la auditoría de texturas
   (`-Dfreeworlds.matStats` vuelca ahora el inventario del diccionario y
   las texturas que no son de 128×128; `-Dfreeworlds.fps` da el % de píxeles
   con textura). Está ligada al ⚠️ `StretchBlt(HALFTONE)` del puente.
7. **No hay runner de regresión.** Las cifras ✅ (118 / 25-578-103 / 231 /
   51 / 159 / 52) se volvieron a ejecutar a mano en la auditoría del
   2026-09-15. No hay tests automáticos; lo único parecido son los
   `RunTest4b*.java` del decodificador `.cmp`.
8. **`.git` ocupa ahora 82 MB.** La purga de historia que quedaba pendiente
   ya no hace falta.

## 1. La decisión estratégica (te toca a ti)

En el repo hay dos clientes vivos:

- **A. El original + el puente** (`editor/worldsplayer_source_editor-main/bridge/`):
  el Java de 2004 con los nativos traducidos del C decompilado. La
  fidelidad viene dada por construcción. El rasterizador es por software y
  en Java puro, sin LWJGL.
- **B. La reimplementación** (`client/src/net/freeworlds/`): parsers
  propios más LWJGL con OpenGL de función fija.

**Recomendación: A como línea principal a corto plazo y como oráculo; B
como destino del porteo.**

- A ya tiene la lógica de juego, la UI y la red del original. Cada nativo
  traducido cierra un hueco y se puede verificar contra el C.
- A es Java + AWT puro, así que en principio corre en Linux y OpenBSD sin
  Wine ni LWJGL (⚠️ VERIFICAR en cada sistema).
- B sigue haciendo falta para PSVita (allí no hay JVM práctica, ⚠️
  VERIFICAR) y para tener un motor moderno. Lo que A confirme, se porta a B.

**El primer hito con sentido de preservación** es este: el cliente de 2004,
sin Windows ni Wine, dibujando, con avatares animados y chat contra un
servidor local. Eso es H1 + H2 + H3.

Queda abierta para la fase 5 una segunda pregunta: en qué lenguaje se
escribe el motor final (Java para escritorio, o C/SDL2 para la Vita). No
bloquea nada hasta H6.

## 1b. Estado a 2026-09-26

Todo lo marcado [x] está fusionado en `main` y verificado:
`tools/verify-corpus.sh` sin fallos y `tools/run-checks.sh` 37/37. El
coordinador comprobó en el ensamblador la afirmación clave de cada rama
antes de fusionarla (constantes y direcciones citadas en cada merge).
[~] = hecho en parte, con la causa anotada.

| Hito | Estado | Lo que queda |
|---|---|---|
| H0 | ✅ | — |
| H1 | 🟢 casi | BSP de clumps de escena y z-buffer de 16 bits por grupo (documentado en ASM, sin traducir); rasterizadores translúcido y Gouraud texturizado; referencia de píxel bajo Wine y la captura del fallo visual (dependen de ti) |
| H2 | ✅ regla / 🟡 en juego | el animador recibe `moveto`/`update` en GroundZero, pero allí solo hay estatuas que giran (estados 1/2, sin secuencia): falta ver un drone andando |
| H3 | 🟡 | login + misma sala + chat entre dos clientes contra whirl ✅; **no se ven** porque whirl no manda APPRACTR (`hub.rs:246` comentado, no se toca whirl); cuenta real pendiente |
| H4 | ✅ lo previsto | CmpFrames, `.mov` como celdas + `AnimateAction`, portales 53/87 como el original, animación en `WorldViewer --play`. Quedan la red en el cliente propio, COG=true, LOD/MoveAction y la decisión de la rampa de iluminación |
| H5 | ✅ en el original | UI, sistema/COM y sonido/web traducidos; chat con Intro. En el cliente propio, sin empezar |
| H6 | ⬜ | no se puede hacer en esta máquina (sin Linux, OpenBSD ni Vita) |

Hallazgos que corrigen lo que se creía:
- Un `.mov` no es una película: sus frames son celdas de un Material.
- El escalado de texturas es COLORONCOLOR, no HALFTONE (0x422682).
- El C de Ghidra de `Surface.addSubPolys` está mal (x/u de los vértices 1-2).
- El key de animación se trunca, no se redondea.
- La cabecera `.rwg` es la lista de texturas, y el "id/flag" de PLST es el
  índice de material.
- `cube.rwg` no lo carga RW 2.1.
- La build del puente estaba rota desde el merge `71648da`.

Decisiones que te tocan:
- Parchear o no la carrera `_connectThread` del cliente de 2004 (cuelga
  unas 4 de cada 27 conexiones contra un servidor local).
- Corregir o no el fallo del original en `setDIBPixelInts`.
- El lenguaje del motor final para la fase 5.

## 1c. Sesión de empaquetado (2026-09-26)

Encargo: menús que no salían, lag, fallos visuales, revisar el motor,
builds empaquetadas en GitHub (sin depender de los scripts de arranque) y
aprovisionar la máquina. Hecho en un contenedor Linux x64 de Claude Code
en la web, sin Wine: el cliente original bajo el puente corre igual que en
el Mac (xvfb para la ventana). Verificado al cerrar: `verify-corpus.sh` sin
fallos y `run-checks.sh` 38/38.

| Frente | Estado | Evidencia / lo que queda |
|---|---|---|
| Menús del original fuera de Windows | ✅ | el panel de botones (Help, Options, Teleport, Quit, mapa…) salía negro en macOS y Linux: el cliente abre rutas `u:/…` en minúsculas (parche de `URL`) con `Toolkit.getImage`/`java.io.File`, que solo existen en Windows. `HostPath` + `bridge/host_paths.py` las resuelven en la copia de build (151 aperturas en 50 clases; `source/` intacto). También arregla la lectura de `redir.txt` |
| Ventana negra al arrancar | ✅ | `Std.initSyncTime` abría un `Socket` sin timeout a time.worlds.net:37 dentro del hilo de render (negro hasta el timeout de TCP). Ahora la base sale del reloj local con la misma resta del bytecode (`ldc2_w -1141367296l; lsub`) y el servidor se consulta en otro hilo con 2 s de timeout |
| Fuentes | ✅ | las del JRE 1.4 (`font.properties`: Arial, Times New Roman, Courier New) o sus sustitutos métricos (Liberation); arregla textos cortados ("Jse arrow keys") |
| Lag del rasterizador del puente | ✅ | lista de triángulos diferida + franjas en varios hilos con el mismo orden de escritura por píxel. 1172×848: 13,5 → 4,7 ms (4 hilos); el cliente pasa de ~25 a ~53 fps. `RasterGoldenCheck`: 18 vistas con CRC idéntico al motor anterior |
| Motor nuevo: aparecer y mirar | ✅ | `defaultPosition`/orientación de cada Room (lo que usa `TeleportAction`); Reception por su `RestartAt`. Comparado con las trazas de cámara del puente |
| Motor nuevo: cámara | ✅ | BEHIND del `HoloPilot` (140 detrás, −10°) con choque contra paredes: ya no atraviesa edificios |
| Motor nuevo: portales | 🟢 | se ve la sala de al lado a través del portal, con el algoritmo de `Camera.rwRenderRoom`/`Portal.rwPrerender` (cara hacia la cámara 0x0041b3b0, rectángulo en pantalla, `_p2pxform`, sin borrar color, profundidad ≤ 3 frente a 10 del original). Cámaras de ChatHall y ReceptionView1 iguales al decimal que en el puente. **Faltan los espejos** (flag bit 2) |
| Motor nuevo: `Rect` de una cara | ✅ | regla del driver `!front && (modes & 0x80) == 0` → descartado; los edificios ya no tapan el paisaje de los portales |
| Motor nuevo: menú y HUD | ✅ | ESC: Continuar / Ir a otra sala (las 25) / FPS / Ayuda / Salir |
| Motor nuevo: luz | ✅ | `DriverLight`: la del driver traducida en el puente (dos luces por sala en el espacio de cada objeto, `I = 31 amb + Σ 31 lc (dif d + spec S(d))`, rampa que por encima de 0,75 aclara hacia blanco; texturas auto-iluminadas tal cual). Antes: luces de GL pegadas a la cámara y nunca por encima del color → mucho más oscuro. Columna de color de Reception igual al puente a ±15/255 (casi todo a ±6) |
| Motor nuevo: superficies | ✅ | UVs de `Rect.addRwChildren` (97 paredes desplazadas), celdas de `addSubPolys` con espejado, `RectPatch` de 4 triángulos, vallas `Billboard` (`adworlds.cmp` en cada celda), texturas `ScapePicTexture`, portales a 11 niveles |
| Puente: matrices | ✅ | producto afín como RWL21 (0x1005118c): lo que cuelga de un `WObject` contenedor caía en el origen (soporte del Auditorium, puerta en iris) |
| Paquete | ✅ | `launcher/` (ventana, menú de terminal `--tui`, CLI) + `tools/build-dist.sh`: portable (.zip, Java 17+) y app con Java incluido (jlink + jpackage). Copia de la instalación en la carpeta de datos del usuario; servidor de actualización local en Java |
| CI | ✅ | cada push: checks, corpus, apps de Linux, macOS Intel, macOS Apple Silicon y Windows, y en cada una la prueba de humo del original empaquetado (tiene que dibujar; obligatoria). Ejecución #5: GroundZero en los cuatro con la cámara en (230,180,170), 62 fps en ARM y 102 en Windows; con un tag `v*`, release |
| Aprovisionamiento | ✅ | `tools/setup-linux.sh` (idempotente) y el hook `SessionStart` de la web |

Lo nuevo que queda:
- **`cache.index`** no estaba versionado (`.gitignore`): sin él, el clon
  limpio, la CI y los paquetes no encuentran los avatares cacheados de
  2004. Solo está en tu Mac: `git add -f assets/WorldsPlayer/cachedir/cache.index`.
- Probar las apps a mano en máquinas reales (Gatekeeper con firma ad hoc,
  SmartScreen en Windows): la CI solo prueba que arrancan y dibujan.
- Motor nuevo: portales espejo, la rampa de iluminación del driver (se ve
  más oscuro que el original) y el avatar del piloto (el original usa el de
  `worlds.ini`).

## 2. Hitos

Tamaños: **S** ≈ 1 sesión · **M** ≈ 2–4 sesiones · **L** = más.

Orden recomendado: **H0 → H2 → H1 (H3 en paralelo, es independiente) → H4 → H5 → H6.**
H2 va antes que H1 porque cierra el abierto nº 1 con evidencia del
binario, mientras que H1 está en parte bloqueado por capturas (sección 3).

### H0 — Suelo firme (S)

- [x] Commitear o descartar el diff de la auditoría de texturas.
- [x] `tools/verify-corpus.sh` (compatible con bash 3.2): un solo comando
      que vuelve a ejecutar los recuentos ✅ y falla si alguno cambia.
      Cubre RWX 118, `.world` 25/578/103, `.seq` 231, `.bod` 51, `.cmp` 159,
      `.mov` 52 y los avatares 146/148.
- [x] Panel de progreso (la herramienta nº 2 de
      `worlds-chat-project.md`, que nunca se construyó): contar
      ⚠️/VERIFICAR/TODO por fichero y generar `docs/progress.md`. Hoy hay 33
      marcas entre `client/` y el puente.
- [x] Node para macOS x64 en `tools/node-macos/` (tarball oficial, sin
      Homebrew). Con eso vuelve a correr el arnés RWX contra
      `three-rwx-loader`. `tools/rwx-harness/node_modules` no tiene módulos
      nativos `.node`, así que basta con cambiar el binario.
- [x] Actualizar CLAUDE.md con los puntos 1–3 y 8 de la sección 0.

**Hecho cuando** `verify-corpus.sh` pase en limpio en este Mac.

### H2 — Avatares vivos: `DroneAnimator` (M) ← abierto nº 1

- [x] Traducir los 16 nativos de `DroneAnimator` desde
      `decompiled-native/gamma_dll/`: `init`, `loadconfig`, `getnameindex`,
      `getindexgeom`, `prepFigure`, `addtype`/`deltype`,
      `CreateRep`/`DestroyRep`, `moveto`/`moveby`, `update`, `animate`,
      `getAnimationTime`, `getActionList` y `endanimations`. Además,
      `PendingCacheDrone.notifySeqLoaded`/`nativeInit`/`nativeDestroy`.
- [x] Reusar el decodificador `.seq` de `client/` (231/231), igual que el
      puente ya reusa `CmpFrames`.
- [x] Escribir en `docs/seq-animation-reference.md`, con direcciones, la
      regla real de walk/wait, la sincronía con la velocidad y la mezcla de
      250.
- [x] Casos de prueba calculados a mano: dada una serie de `moveto` con sus
      tiempos, qué acción y qué frame salen.

**Hecho cuando**, en GroundZero y bajo el puente, un drone y el piloto
anden y se paren con la secuencia que dicta el C, y la regla esté escrita.

### H1 — Que el original dibuje fiel (M)

Los pendientes vienen de `bridge/README.md`, sección "⚠️ Pendiente de
verificar":

- [ ] Reproducir el fallo visual que reportaste. Hace falta una **captura**,
      o dar permiso de Grabación de pantalla al terminal/java, o pillar el
      momento con `-Dfreeworlds.dumpRange`.
- [ ] **Referencia de píxel.** Capturar Reception y GroundZero con el
      original bajo Wine en la máquina Linux/WSL2 (`tools/run-original.sh`),
      desde la misma posición de cámara (`-Dfreeworlds.fps` ya imprime
      posición y dirección), y compararlas con el puente. Sin esto, "fiel"
      es opinión.
- [x] Orden de dibujo: sustituir el z-buffer global por el recorrido BSP
      `0x1002cae0` más el árbol por clump `0x10033750` de RWL21.
- [x] Perspectiva por tramos de 16 px y pendientes con la tabla de
      recíprocos `DAT_10079214` (RWDL6D21). Hoy se hace por píxel y en coma
      flotante.
- [x] Extraer el espacio de interpolación de Gouraud y el dithering de
      texturas.
- [x] Texturas que no son de 128×128: `StretchBlt(HALFTONE)` y
      `RwReadTexture`, que hoy se resuelven con un promedio por cajas. Sigue
      la auditoría que está sin commitear.
- [x] `.rwg`: decodificar las tablas MALT/TELT. Hoy esas formas salen con
      el material por defecto. Beneficia también a B.
- [x] `StringTexture` (2 nativos): rótulos y nametags (`NametagDrone`).
- [x] Menores del README: UV fuera del rango del driver, `RwDestroyScene`,
      `Shape.convertSpecial` y resaltado.

**Hecho cuando** haya un diff de píxeles contra la referencia de Wine en al
menos 3 salas, con cada diferencia explicada.

### H3 — Red con sesión, en local (M)

- [x] Instalar Rust con rustup en el home (`x86_64-apple-darwin`, la
      toolchain de `server/whirl/rust-toolchain.toml`) y compilar whirl.
      **Sin tocar su código.** Si hiciera falta algún ajuste, va en un
      parche aparte y documentado.
- [x] Apuntar el original bajo el puente a whirl, en la copia temporal de
      `worlds.ini`, igual que ya se hace con `upgradeServer`.
- [~] Probar con dos instancias: login, entrar en una sala, verse, chatear
      y lista de amigos.
- [ ] Login real contra `worlds.worlio.com`: **hace falta que registres una
      cuenta** (ver `docs/net-real-account-login-requisitos.md`). Queda
      como verificación final y ya no bloquea nada.

**Hecho cuando** dos clientes originales en este Mac se vean moverse (con
H2) y chateen a través de whirl.

### H4 — Que el cliente propio alcance al original (M–L)

- [x] Pasar `CmpTexture` a `CmpFrames`, lo que arregla el último frame y el
      ancho/alto de `windr3`. Añadir el `.mov` animado con la cadencia de
      `ScapePicMovie`.
- [x] Llevar animación y texturas de avatar a `WorldViewer` (hoy solo están
      en `BodViewer`), con la regla que salga de H2.
- [x] Portales:
      - el signo del yaw de llegada: `getYaw` ya está traducido en
        `NativeRw` con las constantes del binario, así que se puede cerrar
        con eso;
      - los 2 portales a otros `.world`;
      - averiguar por qué no se cruzan los 31 portales restantes de 87.
- [ ] Usar el handshake/login de `tools/net-probe` como capa de red de B,
      contra whirl.
- [x] B emula la luz y la rampa del driver (`DriverLight`, §1c), en
      función fija con `GL_COLOR_SUM`; solo la textura iluminada pierde
      los escalones de 5 bits.
- ⚠️ El `.rwg` con varios joints sigue sin un corpus que lo confirme: no
  inventar.

### H5 — UI y periféricos, fase 4 (L)

Hay 41 ficheros con nativos fuera del puente. `FastDataInput`, `IniFile` y
`DNSLookup` ya tienen mock con E/S real, `DroneAnimator` va en H2,
`StringTexture` en H1 y `Light` es inocuo. Quedan:

| Grupo | Clases (nº de nativos) | Propuesta |
|---|---|---|
| Cursor, overlay y menús | `Cursor` 6, `RenderCanvasOverlay` 3, `RightMenu` 6, `Console` 3, `FileSysDialog` 1, `Startup` 3 | traducir |
| Sonido | `WavSoundPlayer` 4, `MCISoundPlayer` 6, `ASFSoundPlayer` 1, `DirectShow` 9, `CDPlayerAction` 14 | `javax.sound` para WAV/MIDI; el resto, stub documentado |
| Web embebida | `IEWebControlImp` 12, `IWebBrowserApp` 5, `WebBrowser` 3, `TextureSurface` 6, `DDEMLClass` 5, `sendURL` 3, `SendURLAction` 1, `NSProtocolHandler` 1 | abrir en el navegador del sistema; superficies web ⚠️ decidir |
| Sistema y COM | `RegKey` 9, `SystemInfo` 10, `IUnknown` 4, `IDispatch` 1, `IClassFactory` 2, `INetscapeRegistry` 2 | mock con valores fijos documentados |
| Otros | `VehicleShape` 10, `ImageConverter` 6, `ScapePicImage` 3, `ScapePicCanvas` 1, `Restorer` 1, `Pilot` 1, `RenderWare` 2, `NetUpdate` 1, `VoiceChat` 1 | según aparezcan en uso |

- [ ] En B: chat, amigos, mapa y menús, usando A como especificación.

### H6 — Portabilidad, fase 5 (L)

- [x] Linux: A corre en Linux x64 sin Wine (contenedor de la web y CI,
      con Xvfb; §1c). Lo específico de macOS era de rutas (`HostPath`) y
      fuentes (`NativeUiFonts`), no de `build_gamma.sh`. B también corre
      (LWJGL con los natives de Linux).
- [ ] OpenBSD: A con el OpenJDK de ports (⚠️ VERIFICAR versión y AWT). B
      depende de LWJGL (⚠️ VERIFICAR si soporta OpenBSD oficialmente).
- [~] macOS Apple Silicon: la CI genera la app arm64 (Java arm64 del
      runner `macos-15` + LWJGL `natives-macos-arm64`); ⚠️ VERIFICAR en una
      máquina real.
- [~] Windows: la CI genera la app x64 (carpeta con `FreeWorlds.exe`); el
      puente no hace nada con las rutas en Windows (`HostPath`). ⚠️
      VERIFICAR en una máquina real.
- [ ] PSVita: exige un motor nativo (C + SDL2/vitaGL, ⚠️ VERIFICAR). Hay que
      decidirlo antes de empezar (sección 1).

## 3. Lo que depende de ti

1. Una captura del fallo visual, o permiso de Grabación de pantalla (H1).
2. Capturas de referencia en la máquina Linux con Wine (H1).
3. Una cuenta registrada en `worlds.worlio.com/register`, cuando lleguemos
   a H3.
4. La decisión A/B y el lenguaje del motor final (sección 1).
5. Buscar fuera (Wayback, archivos) los 7 `.mov` de Julie, Roxanne y Simon:
   `cfemaleb`, `cfemaleba`, `cfemalec`, `cfc`, `fga`, `fja` y `mga`. Y el
   vestuario perdido: 196 de 210 texturas y 116 de 141 `.bod`. Bastaría con
   dejarlos en `assets/gammatutorial-samples/base-avatars/`.
6. Subir `assets/WorldsPlayer/cachedir/cache.index` desde tu Mac (§1c): no
   hay otra copia en el repo ni en la CI.
7. Probar las apps de la CI (artefactos de cada ejecución en GitHub
   Actions) en tu Mac Intel y, si puedes, en Windows y un Mac ARM.

## 4. Menores y aparcados

- `csq` sin ejemplar propio.
- Starbright World sin investigar.
- Repos de Wirlaburla en 404.
- Comparador de versiones del `.jar` (herramienta nº 5).
