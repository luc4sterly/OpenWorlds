# FreeWorlds

Preservación e ingeniería inversa de **Worlds Chat / WorldsPlayer** (Worlds
Inc., mediados de los 90), uno de los primeros clientes de chat social 3D.
`worlds.com`/`worlds.net` expiraron en 2025; el software original está en
riesgo real de perderse.

**Historial completo sesión por sesión** (cómo se llegó a cada conclusión,
con toda la evidencia): [`docs/worlds-chat-project.md`](docs/worlds-chat-project.md).
Este archivo es el estado actual condensado — empieza aquí, profundiza allá
solo si necesitas la evidencia cruda de un hallazgo concreto.

## Objetivo y alcance

1. Decompilar el cliente Java original (`worlds.jar` / `gammacls.zip`) y
   documentarlo en abierto.
2. Reimplementar desde cero el motor gráfico nativo (RenderWare 2.1 vía JNI)
   para poder portar el cliente a plataformas modernas — objetivo final:
   Linux / OpenBSD / PSVita / macOS, stack SDL2/OpenGL.
3. **Solo el cliente.** El protocolo de red ya está documentado por terceros
   (`protocol/LibreWorlds-wiki-master/`) y ya existe un servidor open source
   vendorizado en `server/whirl` (Rust). No reinventar el servidor.

## Contexto técnico no negociable

- El motor 3D es **RenderWare 2.1** de Criterion Software, accedido por JNI
  desde Java a DLLs de Windows (de ahí Wine en Linux). Confirmado por los
  nombres/exports reales de las DLLs (`docs/renderware21-api-exports.txt`).
  **No existe SDK ni fuente de RenderWare 2 preservado en ningún sitio** —
  todo lo que se sabe de su API sale de decompilar los binarios reales.
- Formatos propios:
  - **`.rwx`** — geometría estática, texto ASCII interpretado como script
    (`ClumpBegin`/`ModelBegin`/...). Sin shaders/normal maps: solo albedo,
    difusa/especular monodireccional básica, ambiente simple.
  - **`.rwg` / `.bod`** — avatares articulados (binario, jerarquía de
    joints). Más complejos que RWX.
  - **`.world`** — escenas/persistencia (salas, nodos, objetos).
  - **`.seq`** — animación de avatares. **`.cmp`/`.mov`** — texturas
    comprimidas propias.
- **Sin SSL/TLS** — todo el tráfico de red va por HTTP plano.
- Motor previo (pre-RenderWare) llamado **Accomplish**: solo relevante si
  aparecen referencias históricas en el código decompilado.

## Layout del repo

```
client/src/net/freeworlds/   reimplementación Java desde cero (parsers + renderer LWJGL)
  avatar/ bod/ cmp/ render/ rwg/ rwx/ world/    un paquete por formato/subsistema
launcher/src/net/freeworlds/launcher/   lanzador del paquete (ventana, menú de terminal, CLI): arranca los dos clientes
.github/workflows/build.yml   CI: build + checks + corpus + prueba de humo; apps macOS/Windows/Linux; release con tags v*
.claude/hooks/session-start.sh   aprovisiona cada sesión de Claude Code en la web (llama a tools/setup-linux.sh)
editor/worldsplayer_source_editor-main/   herramienta de Whirlsplash: decompila/edita/recompila el .jar original
  source/                      722 .java decompilados (Vineflower), NET.worlds.* — pristino, no tocar
  bridge/                      puente JNI portable que sustituye gamma.dll/RenderWare (macOS, sin Wine)
decompiled-native/            salida de Ghidra de las 3 DLLs nativas (ver tabla abajo) — texto versionable, no build
legacy/installer-reversing/   falso comienzo: Worlds1900.exe es el STUB DEL INSTALADOR, no el cliente (ver abajo)
protocol/LibreWorlds-wiki-master/   wiki de terceros con el protocolo de red ya documentado
server/whirl/                 servidor de referencia (Rust, de terceros) — no escribir uno propio
assets/                       corpus de test verificado (cliente instalado, avatares, samples) — SÍ versionado a propósito
docs/                         referencia por formato + evidencia; ver "Referencias" abajo
tools/                        scripts de aprovisionamiento y utilidades (ver tabla abajo)
analysis/                     proyecto Ghidra de gamma.dll — gitignored, regenerable
build/                        salida de tools/build-dist.sh (paquetes) — gitignored
```

`legacy/installer-reversing/` existe porque una sesión anterior decompiló
`Worlds1900.exe` asumiendo que era el cliente; en realidad es el stub Wise
del instalador (confirmado por strings: `WiseMain`, `WISE0001.DLL`). Se dejó
el trabajo por si sirve para extraer otros instaladores Wise. El objetivo
real siempre fue `assets/worlds.jar` (ex `GAMMACLS.ZIP`).

## Estado actual por subsistema

| Subsistema | Estado | Nota |
|---|---|---|
| `.rwx` (geometría estática) | ✅ Completo | 118/118 verificados contra `three-rwx-loader` (reproducible en este Mac con `tools/verify-corpus.sh`) |
| `.world` (escenas) | ✅ Completo | verificado end-to-end: 25 salas / 578 nodos / 103 objetos reales |
| `.seq` (animación) | ✅ Completo | 231/231; `SeqSampler.keyTime` trunca como el `fistp` en chop de gamma.dll (0x43b9c0) |
| `.bod` (avatar, formato de red) | ✅ Completo | resuelto traduciendo el encoder oficial `RWXTOBOD.PL`, 51/51 |
| `.cmp` / `.mov` (texturas) | ✅ Completo | 159/159 y 52/52 por `CmpFrames` (tabla de frames de gamma.dll). Los frames de un `.mov` son **celdas de Material** (`Nh*`/`Nv*`/`Ns*`), no una película; lo que cambia con el tiempo es el Material entero vía `AnimateAction`. La ruta vieja mostraba el último frame |
| `.rwg` (avatar, geometría) | 🟢 Casi completo | lector traducido de RWL21 (TELT/MALT/RALT/ATOM/VLST/PLST, desde ASM); 5/6 del corpus (`cube.rwg` no carga ni en RW 2.1); ATOM con hijos y RAST leídos según el binario, sin muestra real |
| Lenguaje de nombre de avatar | ✅ Completo | 146/148 avatares limpios; **corpus de vestuario mayormente perdido** (solo 14/210 texturas y 25/141 `.bod` sobreviven localmente — no recuperable sin el asset original) |
| Animación (DroneAnimator) | ✅ Regla cerrada | 16+2 nativos traducidos (walk/wait/endwait, sincronía con la distancia, mezclas de 250 ms y de gestos); en el puente y en el cliente propio (`WorldViewer --play`). Sin ver aún un avatar animarse en el original: las estatuas de GroundZero giran |
| Renderizador propio (Java + LWJGL) | 🟢 ~95% | portales 53/87 como el original (`_p2pxform` 0x0041b170 + `getYaw` 0x00425440; los 34 restantes tampoco se cruzan en el original, causa en `--list-portals`); **salas vistas a través de los portales** (pase de portal de gamma.dll, cámara igual al decimal que en el puente; espejos aún no); `Rect` de una cara como el driver; spawn y cámara BEHIND (140, −10°, con colisión) como el original; menú de pausa (ESC), HUD y viaje entre salas; texturas animadas; avatares animados |
| Cliente original bajo puente portable (macOS, Linux; Windows en CI) | 🟢 dibuja y se usa | GroundZero con el rasterizador del driver RWDL6D21, **por franjas en varios hilos e idéntico al píxel** (`RasterGoldenCheck`; 1172×848: 25 → ~53 fps); menús de la ventana visibles (rutas `u:/` resueltas por `HostPath`), fuentes con métricas de Arial como el JRE de 2004, sin bloqueo al arrancar (time.worlds.net); UI, sonido, sistema y COM traducidos; chat con Intro. Falta el BSP de escena (documentado en ASM) |
| Red / protocolo | 🟢 ~75% | guest real contra `worlds.worlio.com`; en local contra `server/whirl`: login, misma sala y chat entre dos clientes originales. No se ven (whirl no manda APPRACTR). Falta una cuenta registrada para el primario |
| UI (chat, amigos, mapa, menús) | 🟢 en el original | la UI AWT de 2004 corre bajo el puente (panel Help/Options/Teleport/Actions/VIP, amigos, chat, mapa del universo, menú contextual, cursores); 🟡 en el cliente propio: menú de pausa y HUD, sin chat/amigos |
| Paquete y CI | ✅ | `tools/build-dist.sh`: portable (.zip, Java 17+) y app con su Java (jlink + jpackage) para macOS Intel/ARM, Windows y Linux; lanzador con ventana, menú de terminal y CLI. `.github/workflows/build.yml` lo hace en cada push |
| Porteo OpenBSD / PSVita | ⬜ 0% | fase 5 — hoy solo hay porteo a macOS Intel |

Estado detallado del puente, con lo pendiente: `editor/worldsplayer_source_editor-main/bridge/README.md`.
Hoja de ruta con lo hecho y lo que queda: `docs/roadmap.md`.

### Nativo decompilado (`decompiled-native/`)

| Binario | Funciones | Qué es |
|---|---|---|
| `gamma_dll/` | 2537, 0 fallos | puente JNI + códecs nativos (`.seq`/`.cmp`/`.mov`) |
| `rwl21_dll/` | 1131, 0 fallos (795 con nombre real de la API) | el motor RenderWare 2.1 en sí |
| `rwdl6d21_dll/` | 385, 0 fallos | driver/rasterizador de software de 16 bits |

Todo regenerable desde `assets/WorldsPlayer/bin/*.dll` vía
`tools/ghidra-scripts/*.java` + `analyzeHeadless` (detalle en
`decompiled-native/README.md`); el proyecto Ghidra en sí vive en
`/analysis/` (gitignored).

## Entorno de desarrollo

**Máquina actual: macOS 15.7 Intel (i5-7360U, 8 GB), sin Homebrew (no soporta
Intel), sin Wine.** Node portable oficial en `tools/node-macos/` (gitignored)
y Rust con rustup en `~/.cargo` (no en el PATH; toolchain `nightly-2024-06-03`
de whirl). bash del sistema es 3.2 —
los scripts deben ser compatibles (p. ej. arrays vacíos bajo `set -u` fallan
en 3.2, hay que evitarlos).

- `tools/setup-macos.sh` — instala un JDK Temurin portable en `tools/jdk/`
  (gitignored). Ejecutar primero en una máquina nueva.
- `tools/run-game.sh` — lanza el renderizador/cliente propio
  (`client/src/net/freeworlds`), recoge el JDK portable solo.
- `tools/run-original.sh` — lanza el cliente **original** de 2004 bajo
  **Wine**. Solo funciona en Linux/WSL2 (histórico) — no disponible en este
  Mac.
- `tools/install-launcher.sh` — instala lanzador de doble-clic + icono.

Entorno Linux/WSL2 histórico (otra máquina): Xeon 28 núcleos, GTX 1060,
sigue siendo válido ahí. Detalle completo en `docs/setup-macos.md`.

**Nube (Claude Code en la web) y Linux:** `tools/setup-linux.sh` deja la
máquina lista (xvfb, patch, zip, fonts-liberation; JDK 17+; LWJGL en
`tools/lwjgl`; `npm install` del arnés RWX; compila `client/` y el puente).
`.claude/hooks/session-start.sh` lo ejecuta al empezar cada sesión en la
web. Sin pantalla: `xvfb-run -a` o un `Xvfb :99` propio.

**Paquetes para probar sin scripts:** `tools/build-dist.sh [--app-image]`
en local, o los *Artifacts* de cada ejecución de la CI en GitHub
(`FreeWorlds-<ver>-macOS-X64` es el de este Mac). El lanzador
(`FreeWorlds`, ventana o `--tui`) sustituye a `run_gamma.sh`/`run-game.sh`
para jugar; los scripts siguen para el diagnóstico con `JAVA_OPTS`.

## Herramientas (`tools/`)

| Script/dir | Para qué |
|---|---|
| `build-dist.sh` | paquete portable y, con `--app-image`, la app nativa con su Java (jlink + jpackage) de este sistema; lo usa la CI |
| `setup-linux.sh`, `fetch-lwjgl.sh` | aprovisionar Linux/la nube (lo llama el hook de sesión); LWJGL de Maven Central con SHA-1 y reintentos |
| `dist-README.txt`, `icons/` | README que va dentro del paquete; icono propio (no el de Worlds.com) |
| `native_mapper.py` | cruza métodos `native` del Java decompilado contra los exports reales de las DLLs |
| `jni_mock.py` + `gamma-dll-debug-harness/` | bridge JNI mock con logging, para arrancar el cliente sin renderer completo |
| `verify-corpus.sh` | regresión en un comando: compila `client/` y reejecuta RWX 118/118 (+118/118 contra `three-rwx-loader` con `tools/node-macos`), `.world` 25/578/103, `.seq` 231, `.bod` 51, `.cmp` 159, `.mov` 52, avatares 146/148; sale ≠0 si algo cambia (~6 min) |
| `run-checks.sh` | ejecuta todos los `*Check.java` de `client/test/**` y `bridge/test/` (reconstruye el puente si su build es vieja); 38 hoy, incluido `RasterGoldenCheck` (CRC de 18 vistas del rasterizador) |
| `progress-panel.py` | cuenta marcas ⚠️/VERIFICAR/TODO/FIXME por módulo y fichero → `docs/progress.md` |
| `rwx-harness/` | compara geometría RWX: parser Java propio vs. `three-rwx-loader` (JS), con `tools/node-macos` en macOS |
| `run-whirl.sh`, `net-probe/run-whirl-duo.sh` | whirl local (solo 127.0.0.1) y la prueba de dos clientes originales contra él (`docs/net-local-whirl.md`) |
| `net-probe/` | sondas de red reales contra servidores Worlio (handshake, login guest) |
| `ghidra-scripts/` | `ExportAllDecompiled.java`, `ScanVtablesAndExport.java` — regeneran `decompiled-native/` |
| `local-upgrade-server.py` | servidor HTTP local que sirve `assets/WorldsPlayer` para correr el cliente original sin red real (el lanzador lleva su versión en Java: `UpgradeServer`) |
| `rwg-explore/`, `gdk-sdk/` | exploración de `.rwg` y herramientas oficiales de avatar recuperadas de GammaTutorial |
| `bring_to_front.py`, `bytecode-call-diff.py`, `pe_exports.py` | utilidades puntuales |

## Principios de verificación (no negociables)

1. **Nunca aceptar un mapeo de direcciones/funciones sin evidencia a nivel
   ASM.** Los agentes de IA han cometido errores (direcciones duplicadas,
   etc.) cuando no se exige este nivel de prueba.
2. **Claude es copiloto, no agente autónomo.** El cuello de botella es la
   verificación humana del comportamiento decompilado contra el binario
   original, no la velocidad de generación de código.
3. **Lotes grandes con autoauditoría**, no función por función. Etiquetas
   ⚠️ VERIFICAR en lo dudoso, en vez de checkpoints manuales constantes.
4. El objetivo es **reimplementación funcional verificada**, no solo
   documentación — cada función confirmada se reescribe como código
   testeable, con casos de prueba calculados a mano.

## Cómo trabajar aquí

**Paso 0, siempre primero:** reconoce el árbol real antes de tocar nada —
no asumas que este documento sigue describiendo el repo exacto (puede haber
cambiado). Reporta primero, actúa después.

- Trabaja por módulo/formato, no función por función; presenta resúmenes
  con lo marcado ⚠️ VERIFICAR para que el humano audite antes de dar nada
  por bueno.
- No reescribas el servidor — usa `server/whirl` como referencia o directo
  como servidor de pruebas.
- LLM local (Ollama) solo para tareas mecánicas de bajo riesgo (renombrado
  masivo, clasificación). Nunca para interpretar lógica compleja o mapear
  protocolo.
- **Subagentes**: úsalos cuando la tarea implica leer mucho pero la
  conclusión cabe en una tabla corta (exploración paralela de `/source` por
  paquete, verificación cruzada RWX Java-vs-JS, búsquedas puntuales en
  documentación externa). Acota siempre el output ("máximo N líneas", "solo
  tabla"). **No los uses** para interpretar lógica compleja/reconstruir
  structs (pierde el control fino que exige la verificación) ni para
  cambios triviales puntuales.

## Abierto ahora mismo

Por orden de lo que desbloquean (detalle en `docs/roadmap.md`):

0. **`assets/WorldsPlayer/cachedir/cache.index` no está en git** (estaba en
   `.gitignore` como "bookkeeping"): sin él, en un clon limpio, en la CI y en
   los paquetes el cliente original no encuentra los avatares cacheados de
   2004 (las estatuas de GroundZero salen sin textura). Solo existe en el Mac
   del usuario: `git add -f assets/WorldsPlayer/cachedir/cache.index`. Ya no
   está ignorado; `build-dist.sh` avisa si falta.
1. **Ver avatares animándose en el original**: la regla está traducida y
   el animador recibe `moveto`/`update`, pero en GroundZero solo hay
   estatuas que giran. Hace falta un drone por red, y whirl no los manda
   (APPRACTR comentado en `hub.rs`).
2. **Login con cuenta real** en el servidor primario: bloqueado por
   necesitar una cuenta humana registrada en `worlds.worlio.com/register`.
   Con ella se probaría también ver a otros usuarios.
3. **BSP de clumps de escena** de RWL21 (0x1002d170 / 0x1002cae0) y el
   z-buffer de 16 bits por grupo: documentado en ASM, sin traducir.
4. **Referencia de píxel**: capturas del original bajo Wine (máquina
   Linux) para comparar el puente, y la captura del fallo visual que se
   reportó.
5. Decisiones abiertas: parchear la carrera `_connectThread` del cliente de
   2004; corregir o no el fallo de `setDIBPixelInts`; lenguaje del motor
   final para la fase 5.
6. Fase 5 (OpenBSD/PSVita) y la UI del cliente propio (chat, amigos,
   mapa): sin empezar. En el motor propio faltan además los portales
   espejo (flags bit 2), la rampa de iluminación del driver (se ve más
   oscuro que el original) y el avatar por defecto del piloto (el original
   usa el de `worlds.ini`, el visor `aura`).
7. Probar las apps de la CI en máquinas reales: la de macOS está firmada ad
   hoc (Gatekeeper: "Abrir igualmente" o `xattr -dr com.apple.quarantine`).
   En la CI el original empaquetado ya dibuja GroundZero en los cuatro
   runners (Linux, macOS Intel y ARM, Windows; prueba de humo obligatoria),
   pero nadie ha abierto aún la app a mano fuera de la CI.
8. Menores: `csq` sin ejemplar propio, Starbright World sin investigar, los
   7 `.mov` perdidos de Julie/Roxanne/Simon.

**No reproducible en el Mac actual** (no es lo mismo que "roto"): ground
truth `.cmp` contra `cmpview.exe` y el cliente original bajo Wine (requieren
Windows/Wine).

## Referencias

Documentación técnica por formato, generada y verificada contra el corpus
real — la fuente de verdad para cada formato, no el historial de cómo se
llegó ahí:

- `docs/rwx-format-reference.md`, `docs/rwg-bod-format-reference.md`,
  `docs/world-format-reference.md`, `docs/seq-animation-reference.md`,
  `docs/cmp-texture-format-reference.md` — formatos de archivo
- `docs/render-pipeline-reference.md`, `docs/rwx-avatar-hierarchy-reference.md`
  — renderer
- `docs/native-methods-map.md`, `docs/native-methods-callers.md`,
  `docs/renderware21-api-exports.txt`, `docs/gamma-dll-exports.txt` —
  puente nativo/JNI
- `docs/avatar-name-language.md`, `docs/net-real-account-login-requisitos.md`
  — avatares y red
- `docs/setup-macos.md` — detalle del entorno macOS
- `docs/renders/` — capturas de progreso por hito
- `docs/gamma-dll-cmp-evidence/`, `docs/*.log`, `docs/*-trace*.txt` —
  evidencia cruda (trazas reales, dumps) citada desde el código y desde
  `docs/worlds-chat-project.md`; no son documentación de lectura, son
  la prueba detrás de decisiones concretas
- **`docs/worlds-chat-project.md`** — historial completo sesión por sesión
  desde el inicio del proyecto (2026-09-08 en adelante). Consúltalo cuando
  necesites el *por qué* completo de una decisión no obvia; varios
  comentarios en el código lo citan directamente por sección.
