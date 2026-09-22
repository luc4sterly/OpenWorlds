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
```

`legacy/installer-reversing/` existe porque una sesión anterior decompiló
`Worlds1900.exe` asumiendo que era el cliente; en realidad es el stub Wise
del instalador (confirmado por strings: `WiseMain`, `WISE0001.DLL`). Se dejó
el trabajo por si sirve para extraer otros instaladores Wise. El objetivo
real siempre fue `assets/worlds.jar` (ex `GAMMACLS.ZIP`).

## Estado actual por subsistema

| Subsistema | Estado | Nota |
|---|---|---|
| `.rwx` (geometría estática) | ✅ Completo | 118/118 verificados contra `three-rwx-loader` |
| `.world` (escenas) | ✅ Completo | verificado end-to-end: 25 salas / 578 nodos / 103 objetos reales |
| `.seq` (animación) | ✅ Completo | 231/231 tras corregir `SeqParser` |
| `.bod` (avatar, formato de red) | ✅ Completo | resuelto traduciendo el encoder oficial `RWXTOBOD.PL`, 51/51 |
| `.cmp` / `.mov` (texturas) | ✅ Completo | 159/159 y 52/52 byte-exactos, conectado al pipeline; solo subimagen 0 de `.mov` (falta animado) |
| `.rwg` (avatar, geometría) | 🟡 Parcial | ATOM único verificado (2/2 muestras reales); jerarquía multi-joint sin corpus real que la confirme |
| Lenguaje de nombre de avatar | ✅ Completo | 146/148 avatares limpios; **corpus de vestuario mayormente perdido** (solo 14/210 texturas y 25/141 `.bod` sobreviven localmente — no recuperable sin el asset original) |
| Renderizador (Java + LWJGL) | 🟢 ~90% | iluminación y materiales verificados por píxel; portales 56/87 en GroundZero (`Portal.recomputeFarPosition`); rasterizador recién ajustado contra RWL21/RWDL6D21 reales (ver abajo) |
| Red / protocolo | 🟡 ~60% | handshake + login guest reales contra `worlds.worlio.com` (estado 12 MAINLOOP); falta cuenta registrada para el login primario |
| Cliente original bajo puente portable (macOS) | 🟢 arranca y corre | `Gamma.main` llega al bucle principal construyendo la escena RenderWare real; **dibujar sigue en progreso** |
| UI (chat, amigos, mapa, menús) | ⬜ 0% | fase 4, sin empezar |
| Porteo OpenBSD / PSVita | ⬜ 0% | fase 5 — hoy solo hay porteo a macOS Intel |

**Rasterizador (última sesión):** tres piezas que el puente portable
resolvía "a ojo" ahora traducen el binario real de `RWDL6D21.DLL`:
iluminación por píxel vía tabla (no fórmula inventada), relleno de polígono
como abanico de triángulos desde el vértice 0 (no scanline izq-der), y
normales/LTM cacheadas en vez de recalculadas por frame. FPS en GroundZero:
31-33 → 47-48. Diagnósticos nuevos: `-Dfreeworlds.matStats`,
`-Dfreeworlds.traceTextures`, `-Dfreeworlds.probePixel`, `-Dfreeworlds.fps`,
`-Dfreeworlds.dumpRange`, `-Dfreeworlds.dumpWindow`.

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

**Máquina actual: macOS 15.7 Intel (i5-7360U), sin Homebrew (no soporta
Intel), sin Wine, sin node del sistema.** bash del sistema es 3.2 —
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

## Herramientas (`tools/`)

| Script/dir | Para qué |
|---|---|
| `native_mapper.py` | cruza métodos `native` del Java decompilado contra los exports reales de las DLLs |
| `jni_mock.py` + `gamma-dll-debug-harness/` | bridge JNI mock con logging, para arrancar el cliente sin renderer completo |
| `rwx-harness/` | compara geometría RWX: parser Java propio vs. `three-rwx-loader` (JS). ⚠️ necesita `node`, hoy solo hay build Linux en `tools/node/` (gitignored) — no corre en este Mac |
| `net-probe/` | sondas de red reales contra servidores Worlio (handshake, login guest) |
| `ghidra-scripts/` | `ExportAllDecompiled.java`, `ScanVtablesAndExport.java` — regeneran `decompiled-native/` |
| `local-upgrade-server.py` | servidor HTTP local que sirve `assets/WorldsPlayer` para correr el cliente original sin red real |
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

Por orden de lo que desbloquean:

1. **Selección de secuencia de animación**: qué `.seq`/modo elige el
   cliente en cada momento (`walk`/`wait` implícitos), sincronía con
   velocidad y mezcla.
2. **Login con cuenta real** en el servidor primario: bloqueado por
   necesitar una cuenta humana registrada en `worlds.worlio.com/register`.
3. **Dibujo del cliente original bajo el puente portable**: llega al bucle
   principal; falta reproducir un fallo visual concreto reportado por el
   usuario (sin captura de referencia todavía) y terminar de trasladar el
   orden de dibujo real (BSP + árbol por clump) en vez de aproximarlo con
   z-buffer.
4. **Texturas de avatar**: faltan las subimágenes >0 de `.mov` y llevar
   animación+texturas a `WorldViewer` (hoy solo en `BodViewer`).
5. Fase 4 (UI) y fase 5 (OpenBSD/PSVita): sin empezar.
6. Menores: `.mov` animado (hoy solo frame 0), `csq` sin ejemplar propio,
   Starbright World (posible tercer proyecto hermano de Worlds/Active
   Worlds) sin investigar.

**No reproducible en el Mac actual** (no es lo mismo que "roto"): arnés RWX
vs. `three-rwx-loader` (falta `node` de macOS), ground truth `.cmp` contra
`cmpview.exe` y el cliente original bajo Wine (ambos requieren Windows/Wine).

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
