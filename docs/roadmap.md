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

## 2. Hitos

Tamaños: **S** ≈ 1 sesión · **M** ≈ 2–4 sesiones · **L** = más.

Orden recomendado: **H0 → H2 → H1 (H3 en paralelo, es independiente) → H4 → H5 → H6.**
H2 va antes que H1 porque cierra el abierto nº 1 con evidencia del
binario, mientras que H1 está en parte bloqueado por capturas (sección 3).

### H0 — Suelo firme (S)

- [ ] Commitear o descartar el diff de la auditoría de texturas.
- [ ] `tools/verify-corpus.sh` (compatible con bash 3.2): un solo comando
      que vuelve a ejecutar los recuentos ✅ y falla si alguno cambia.
      Cubre RWX 118, `.world` 25/578/103, `.seq` 231, `.bod` 51, `.cmp` 159,
      `.mov` 52 y los avatares 146/148.
- [ ] Panel de progreso (la herramienta nº 2 de
      `worlds-chat-project.md`, que nunca se construyó): contar
      ⚠️/VERIFICAR/TODO por fichero y generar `docs/progress.md`. Hoy hay 33
      marcas entre `client/` y el puente.
- [ ] Node para macOS x64 en `tools/node-macos/` (tarball oficial, sin
      Homebrew). Con eso vuelve a correr el arnés RWX contra
      `three-rwx-loader`. `tools/rwx-harness/node_modules` no tiene módulos
      nativos `.node`, así que basta con cambiar el binario.
- [ ] Actualizar CLAUDE.md con los puntos 1–3 y 8 de la sección 0.

**Hecho cuando** `verify-corpus.sh` pase en limpio en este Mac.

### H2 — Avatares vivos: `DroneAnimator` (M) ← abierto nº 1

- [ ] Traducir los 16 nativos de `DroneAnimator` desde
      `decompiled-native/gamma_dll/`: `init`, `loadconfig`, `getnameindex`,
      `getindexgeom`, `prepFigure`, `addtype`/`deltype`,
      `CreateRep`/`DestroyRep`, `moveto`/`moveby`, `update`, `animate`,
      `getAnimationTime`, `getActionList` y `endanimations`. Además,
      `PendingCacheDrone.notifySeqLoaded`/`nativeInit`/`nativeDestroy`.
- [ ] Reusar el decodificador `.seq` de `client/` (231/231), igual que el
      puente ya reusa `CmpFrames`.
- [ ] Escribir en `docs/seq-animation-reference.md`, con direcciones, la
      regla real de walk/wait, la sincronía con la velocidad y la mezcla de
      250.
- [ ] Casos de prueba calculados a mano: dada una serie de `moveto` con sus
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
- [ ] Orden de dibujo: sustituir el z-buffer global por el recorrido BSP
      `0x1002cae0` más el árbol por clump `0x10033750` de RWL21.
- [ ] Perspectiva por tramos de 16 px y pendientes con la tabla de
      recíprocos `DAT_10079214` (RWDL6D21). Hoy se hace por píxel y en coma
      flotante.
- [ ] Extraer el espacio de interpolación de Gouraud y el dithering de
      texturas.
- [ ] Texturas que no son de 128×128: `StretchBlt(HALFTONE)` y
      `RwReadTexture`, que hoy se resuelven con un promedio por cajas. Sigue
      la auditoría que está sin commitear.
- [ ] `.rwg`: decodificar las tablas MALT/TELT. Hoy esas formas salen con
      el material por defecto. Beneficia también a B.
- [ ] `StringTexture` (2 nativos): rótulos y nametags (`NametagDrone`).
- [ ] Menores del README: UV fuera del rango del driver, `RwDestroyScene`,
      `Shape.convertSpecial` y resaltado.

**Hecho cuando** haya un diff de píxeles contra la referencia de Wine en al
menos 3 salas, con cada diferencia explicada.

### H3 — Red con sesión, en local (M)

- [ ] Instalar Rust con rustup en el home (`x86_64-apple-darwin`, la
      toolchain de `server/whirl/rust-toolchain.toml`) y compilar whirl.
      **Sin tocar su código.** Si hiciera falta algún ajuste, va en un
      parche aparte y documentado.
- [ ] Apuntar el original bajo el puente a whirl, en la copia temporal de
      `worlds.ini`, igual que ya se hace con `upgradeServer`.
- [ ] Probar con dos instancias: login, entrar en una sala, verse, chatear
      y lista de amigos.
- [ ] Login real contra `worlds.worlio.com`: **hace falta que registres una
      cuenta** (ver `docs/net-real-account-login-requisitos.md`). Queda
      como verificación final y ya no bloquea nada.

**Hecho cuando** dos clientes originales en este Mac se vean moverse (con
H2) y chateen a través de whirl.

### H4 — Que el cliente propio alcance al original (M–L)

- [ ] Pasar `CmpTexture` a `CmpFrames`, lo que arregla el último frame y el
      ancho/alto de `windr3`. Añadir el `.mov` animado con la cadencia de
      `ScapePicMovie`.
- [ ] Llevar animación y texturas de avatar a `WorldViewer` (hoy solo están
      en `BodViewer`), con la regla que salga de H2.
- [ ] Portales:
      - el signo del yaw de llegada: `getYaw` ya está traducido en
        `NativeRw` con las constantes del binario, así que se puede cerrar
        con eso;
      - los 2 portales a otros `.world`;
      - averiguar por qué no se cruzan los 31 portales restantes de 87.
- [ ] Usar el handshake/login de `tools/net-probe` como capa de red de B,
      contra whirl.
- [ ] Decidir si B emula la rampa de iluminación del driver (más
      fidelidad) o se queda en función fija.
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

- [ ] Linux: correr A en la máquina Linux sin Wine. Debería bastar con el
      JDK; ⚠️ VERIFICAR lo que haya específico de macOS en
      `build_gamma.sh`/`run_gamma.sh`.
- [ ] OpenBSD: A con el OpenJDK de ports (⚠️ VERIFICAR versión y AWT). B
      depende de LWJGL (⚠️ VERIFICAR si soporta OpenBSD oficialmente).
- [ ] macOS Apple Silicon: JDK arm64 para A y LWJGL arm64 para B.
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

## 4. Menores y aparcados

- `csq` sin ejemplar propio.
- Starbright World sin investigar.
- Repos de Wirlaburla en 404.
- Comparador de versiones del `.jar` (herramienta nº 5).
