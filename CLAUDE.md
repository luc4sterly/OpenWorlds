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
   Linux / OpenBSD / PSVita / macOS. Se hace en el **puente portable**
   (`editor/worldsplayer_source_editor-main/bridge/`), que traduce a Java
   gamma.dll, RWL21 y RWDL6D21 para que el cliente original corra tal cual.
   **Un solo motor** (decisión del usuario, 2026-09-26): el motor nuevo
   aparte (`client/`, parsers propios + LWJGL) se quitó del repo. No crear
   otro sin que lo pida.
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
formats/src/net/freeworlds/   lectores verificados que usa el puente: bod/ (.bod y .seq), rwg/, cmp/ (.cmp y .mov)
launcher/src/net/freeworlds/launcher/   lanzador del paquete (ventana, menú de terminal, CLI): arranca el cliente original
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
| `.rwx` (geometría estática) | ✅ Completo | el original lo lee con `bridge/.../RwxReader` (traducido de RWL21); formato en `docs/rwx-format-reference.md`. El lector propio verificado 118/118 contra `three-rwx-loader` se quitó con el motor nuevo (historial de git, `8cd795d`) |
| `.world` (escenas) | ✅ Completo | el original lo lee con su propio `Restorer`; formato en `docs/world-format-reference.md` (25 salas / 578 nodos / 103 objetos, medido con el lector propio, quitado con el motor nuevo) |
| `.seq` (animación) | ✅ Completo | 231/231; `SeqSampler.keyTime` trunca como el `fistp` en chop de gamma.dll (0x43b9c0) |
| `.bod` (avatar, formato de red) | ✅ Completo | resuelto traduciendo el encoder oficial `RWXTOBOD.PL`, 51/51 |
| `.cmp` / `.mov` (texturas) | ✅ Completo | 159/159 y 52/52 por `CmpFrames` (tabla de frames de gamma.dll); fotogramas de varios grupos de filas (FUN_00442bc0, `mug.cmp` de Blair Witch) y byte 13 de la cabecera (`kcl.mov`), muestras en `assets/cmp-verified/`. Los frames de un `.mov` son **celdas de Material** (`Nh*`/`Nv*`/`Ns*`), no una película; lo que cambia con el tiempo es el Material entero vía `AnimateAction`. La ruta vieja mostraba el último frame |
| `.rwg` (avatar, geometría) | 🟢 Casi completo | lector traducido de RWL21 (TELT/MALT/RALT/ATOM/VLST/PLST, desde ASM); 5/6 del corpus (`cube.rwg` no carga ni en RW 2.1); ATOM con hijos y RAST leídos según el binario, sin muestra real |
| Lenguaje de nombre de avatar | ✅ Documentado | lo ejecuta `PosableShape` del original; `docs/avatar-name-language.md` (146/148 limpios, medido con el decodificador propio, quitado con el motor nuevo); **corpus de vestuario mayormente perdido** (solo 14/210 texturas y 25/141 `.bod` sobreviven localmente — no recuperable sin el asset original) |
| Animación (DroneAnimator) | ✅ Regla cerrada | 16+2 nativos traducidos (walk/wait/endwait, sincronía con la distancia, mezclas de 250 ms y de gestos) en el puente. Sin ver aún un avatar animarse en el original: las estatuas de GroundZero giran |
| Mundos e instalador | ✅ probado | 12 mundos visitados en el original; la instalación de 2004 solo trae GroundZero, y los otros 11 se descargaron e instalaron desde el espejo (`us1.worlds.net`, hoy LibreWorlds): Wise y NSIS por el gdkup en Java (`GdkUp`, `WisePackage`, `NsisPackage`) con reinicio `world:restart`; GroundZero 37 → 40 por Upgrade Now; el mapa del universo ofrece 16 mundos, todos en el espejo (Blair Witch, Yankees, WWF, Aerosmith, Hanson, Bowie...). Informe: `docs/pruebas-juego.md` |
| Cliente original bajo puente portable (macOS, Linux; Windows en CI) | 🟢 dibuja y se usa | GroundZero con el rasterizador del driver RWDL6D21, **por franjas en varios hilos e idéntico al píxel** (`RasterGoldenCheck`; 1172×848: 25 → ~53 fps); producto de matrices afín como RWL21 (antes lo que cuelga de un `WObject` caía en el origen de la sala) y material de las partes `.bod` del binario (0.32/0.55/0, liso: las estatuas ya tienen sombreado); menús de la ventana visibles (rutas `u:/` resueltas por `HostPath`), fuentes con métricas de Arial como el JRE de 2004, sin bloqueo al arrancar (time.worlds.net); UI, sonido, sistema y COM traducidos; chat con Intro; reloj a saltos de `GetTickCount` (girar ya no va a cámara lenta); cierre de diálogos sin el bloqueo de X11 (`AwtCompat`). Falta el BSP de escena (documentado en ASM) |
| Red / protocolo | 🟢 ~75% | guest real contra `worlds.worlio.com`; en local contra `server/whirl`: login, misma sala y chat entre dos clientes originales. No se ven (whirl no manda APPRACTR). Falta una cuenta registrada para el primario |
| UI (chat, amigos, mapa, menús) | 🟢 en el original | la UI AWT de 2004 corre bajo el puente y se probó entera (`docs/pruebas-juego.md`): Help/Options/WorldsMail/WorldsMark/Teleport/Actions/VIP, amigos, chat, correo, mapa del universo, menú contextual, cursores |
| Paquete y CI | ✅ | `tools/build-dist.sh`: portable (.zip, Java 17+) y app con su Java (jlink + jpackage) para macOS Intel/ARM, Windows y Linux; lanzador con ventana, menú de terminal y CLI. `.github/workflows/build.yml` lo hace en cada push |
| Porteo OpenBSD / PSVita | ⬜ 0% | fase 5. Ojo: el cliente original es Java con UI AWT, y en la PSVita no hay Java |

Estado detallado del puente, con lo pendiente: `editor/worldsplayer_source_editor-main/bridge/README.md`.
Hoja de ruta con lo hecho y lo que queda: `docs/roadmap.md`.

### Nativo decompilado (`decompiled-native/`)

Todos los binarios propios del juego, 0 fallos (los demás son del Java
de Sun 1.4.2 que traía el instalador, msvcrt, xdelta/glib y el
desinstalador de Wise: lista y motivo en `decompiled-native/README.md`):

| Binario | Funciones | Qué es |
|---|---|---|
| `gamma_dll/` | 2537 | puente JNI + códecs nativos (`.seq`/`.cmp`/`.mov`) |
| `rwl21_dll/` | 1152 (795 con nombre real de la API) | el motor RenderWare 2.1 en sí |
| `rwdl6d21_dll/` | 411 | driver/rasterizador de software de 16 bits (el que traduce el puente) |
| `rwdl8d21_dll/`, `rwdlmd21_dll/`, `rwdldd21_dll/` | 427, 435, 305 | drivers de 8 bits, MMX y DirectDraw |
| `run_exe/` | 139 | lanzador de 2004 (`run.exe world:restart`) |
| `gdkup_exe/` | 256 | el actualizador; traducido en `bridge/.../GdkUp.java` |
| `sfmain_exe/` | 619 | chat de voz (SpeakFreely + GSM, Watcom); sin traducir |

Regenerable con `tools/ghidra-scripts/decompile-all.sh` (Ghidra 12.1.3
headless, `ExportAllDecompiled.java` + `ScanVtablesAndExport.java`); el
proyecto Ghidra vive fuera del repo.

## Entorno de desarrollo

**Máquina actual: macOS 15.7 Intel (i5-7360U, 8 GB), sin Homebrew (no soporta
Intel), sin Wine.** Rust con rustup en `~/.cargo` (no en el PATH; toolchain `nightly-2024-06-03`
de whirl). bash del sistema es 3.2 —
los scripts deben ser compatibles (p. ej. arrays vacíos bajo `set -u` fallan
en 3.2, hay que evitarlos).

- `tools/setup-macos.sh` — instala un JDK Temurin portable en `tools/jdk/`
  (gitignored). Ejecutar primero en una máquina nueva.
- `tools/run-original.sh` — lanza el cliente **original** de 2004 bajo
  **Wine**. Solo funciona en Linux/WSL2 (histórico) — no disponible en este
  Mac.

Entorno Linux/WSL2 histórico (otra máquina): Xeon 28 núcleos, GTX 1060,
sigue siendo válido ahí. Detalle completo en `docs/setup-macos.md`.

**Nube (Claude Code en la web) y Linux:** `tools/setup-linux.sh` deja la
máquina lista (xvfb, patch, zip, fonts-liberation; JDK 17+; compila
`formats/` y el puente).
`.claude/hooks/session-start.sh` lo ejecuta al empezar cada sesión en la
web. Sin pantalla: `xvfb-run -a` o un `Xvfb :99` propio.

**Paquetes para probar sin scripts:** `tools/build-dist.sh [--app-image]`
en local, o los *Artifacts* de cada ejecución de la CI en GitHub
(`FreeWorlds-<ver>-macOS-X64` es el de este Mac). El lanzador
(`FreeWorlds`, ventana o `--tui`) sustituye a `run_gamma.sh` para jugar;
el script sigue para el diagnóstico con `JAVA_OPTS`.

## Herramientas (`tools/`)

| Script/dir | Para qué |
|---|---|
| `build-dist.sh` | paquete portable y, con `--app-image`, la app nativa con su Java (jlink + jpackage) de este sistema; lo usa la CI |
| `setup-linux.sh`, `setup-macos.sh` | aprovisionar Linux/la nube (el primero lo llama el hook de sesión) o un Mac: JDK, paquetes, compilar `formats/` y el puente |
| `dist-README.txt`, `icons/` | README que va dentro del paquete; icono propio, no el de Worlds.com: un planeta low-poly con anillo (`icons/make_icons.py` lo dibuja en SVG y saca el PNG, el ICO, el ICNS y el del lanzador) |
| `native_mapper.py` | cruza métodos `native` del Java decompilado contra los exports reales de las DLLs |
| `jni_mock.py` + `gamma-dll-debug-harness/` | bridge JNI mock con logging, para arrancar el cliente sin renderer completo |
| `verify-corpus.sh` | regresión en un comando: compila `formats/` y reejecuta `.seq` 231, `.bod` 51, `.cmp` 159 y `.mov` 52 sobre el corpus real, luego `run-checks.sh`; sale ≠0 si algo cambia |
| `run-checks.sh` | ejecuta todos los `*Check.java` de `formats/test/**` y `bridge/test/` (reconstruye el puente si su build es vieja); 38 hoy (5 + 33), incluidos `RasterGoldenCheck` (CRC de 18 vistas del rasterizador), `MatrixAffineCheck`, `GdkUpCheck` (instala `assets/packages/`) y `UiDisposeCheck` (necesita pantalla: la CI lo pasa bajo `xvfb-run`) |
| `progress-panel.py` | cuenta marcas ⚠️/VERIFICAR/TODO/FIXME por módulo y fichero → `docs/progress.md` |
| `run-whirl.sh`, `net-probe/run-whirl-duo.sh` | whirl local (solo 127.0.0.1) y la prueba de dos clientes originales contra él (`docs/net-local-whirl.md`) |
| `net-probe/` | sondas de red reales contra servidores Worlio (handshake, login guest) |
| `ghidra-scripts/` | `ExportAllDecompiled.java`, `ScanVtablesAndExport.java` y `decompile-all.sh` — regeneran `decompiled-native/` |
| `local-upgrade-server.py` | servidor HTTP local que sirve `assets/WorldsPlayer` al cliente original y, con `--mirror`, pide lo que falte al espejo (`run_gamma.sh` lo usa así; el lanzador lleva su versión en Java: `UpgradeServer`) |
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
  paquete, búsquedas puntuales en documentación externa). Acota siempre el output ("máximo N líneas", "solo
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
6. Fase 5 (OpenBSD/PSVita): sin empezar.
7. Probar las apps de la CI en máquinas reales: la de macOS está firmada ad
   hoc (Gatekeeper: "Abrir igualmente" o `xattr -dr com.apple.quarantine`).
   En la CI el original empaquetado ya dibuja GroundZero en los cuatro
   runners (Linux, macOS Intel y ARM, Windows; prueba de humo obligatoria),
   pero nadie ha abierto aún la app a mano fuera de la CI.
8. Menores: `csq` sin ejemplar propio, Starbright World sin investigar, los
   7 `.mov` perdidos de Julie/Roxanne/Simon (**ojo**: el espejo sirve
   `avatar/cfemaleb.mov`, `cfc.mov`, `fga.mov`... revisar si son esos).
9. De las pruebas del juego (`docs/pruebas-juego.md`): parches xdelta de los
   mundos viejos sin aplicar; chat de voz (`sfmain.exe`) sin traducir; el
   gesto "Sleep" no se ve en el pingüino; ⚠️ otros sitios donde el código de
   2004 toca AWT con el monitor de un diálogo tomado (primera
   `mainCallback`, `activeCallback` de `LoginWizard`) podrían bloquearse en
   X11 como el cierre (sin caso visto). **Decisión abierta:** guardar en el
   repo los paquetes de mundo del espejo (hoy solo hay dos, para los tests,
   en `assets/packages/`).

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
- `docs/rwx-avatar-hierarchy-reference.md` — jerarquía de joints en RWX
- `docs/native-methods-map.md`, `docs/native-methods-callers.md`,
  `docs/renderware21-api-exports.txt`, `docs/gamma-dll-exports.txt` —
  puente nativo/JNI
- `docs/avatar-name-language.md`, `docs/net-real-account-login-requisitos.md`
  — avatares y red
- `docs/pruebas-juego.md` — todo lo que se probó en el juego (mundos,
  menús, instalación de mundos) con los fallos arreglados y lo abierto
- `docs/setup-macos.md` — detalle del entorno macOS
- `docs/renders/` — capturas (la del cliente original; las del motor nuevo
  están en el historial de git, hasta `8cd795d`)
- `docs/gamma-dll-cmp-evidence/`, `docs/*.log`, `docs/*-trace*.txt` —
  evidencia cruda (trazas reales, dumps) citada desde el código y desde
  `docs/worlds-chat-project.md`; no son documentación de lectura, son
  la prueba detrás de decisiones concretas
- **`docs/worlds-chat-project.md`** — historial completo sesión por sesión
  desde el inicio del proyecto (2026-09-08 en adelante). Consúltalo cuando
  necesites el *por qué* completo de una decisión no obvia; varios
  comentarios en el código lo citan directamente por sección.
