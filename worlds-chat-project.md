# Worlds Chat — Preservación e Ingeniería Inversa

> Documento maestro del proyecto. Pensado para que Claude Code (o cualquier
> colaborador nuevo) pueda arrancar sin necesitar más contexto que este archivo.

---

## 1. Qué es esto y por qué

**Worlds Chat / WorldsPlayer** (Worlds.com) fue uno de los primeros clientes de
chat social 3D/VR, de mediados de los años 90 (empresa: Worlds Inc., nacida de
una escisión de Knowledge Adventure Worlds). Los dominios oficiales
(`worlds.com`, `worlds.net`) expiraron alrededor de octubre de 2025 y ahora
muestran una página de aparcamiento. El software original está en riesgo real
de perderse si nadie lo preserva.

**Objetivo del proyecto:**
1. Decompilar el cliente Java original (`worlds.jar` / `gammacls.zip`)
2. Documentarlo y hacerlo open source
3. Portarlo a plataformas modernas — objetivo final: **Linux / OpenBSD**, con
   stack **SDL2/OpenGL**
4. Sustituir las dependencias nativas de Windows (motor gráfico RenderWare vía
   JNI) por una implementación portable equivalente

**Alcance actual: solo el cliente.** El protocolo de red ya está documentado
por terceros y ya existe un servidor open source (`whirl`, ver sección 3). No
hace falta reinventar el servidor.

---

## 2. Contexto técnico del cliente

- El cliente (`worlds.jar`) hay que decompilarlo uno mismo — **no existe
  ninguna versión pre-decompilada publicada** en ningún repo público.
- Usa una versión modificada de **RenderWare 2** (motor gráfico de Criterion
  Software) para el renderizado 3D, accedido vía **JNI** desde Java a DLLs de
  Windows. Esto es lo que obliga a usar Wine en Linux hoy en día.
  - Confirmado por dos fuentes independientes: tutorial de kangworlds.net y el
    repo `Sgeo/rwg_to_rwx`, que distingue explícitamente entre **RenderWare
    2.0** (Worlds antiguo) y **RenderWare 2.1** ("modern WorldsPlayer" — la
    versión probablemente relevante para nosotros).
  - **Pendiente de confirmar con evidencia directa**: correr
    `strings *.dll | grep -i "renderware\|criterion"` sobre las DLLs reales de
    la instalación para sacar la versión exacta, en vez de fiarnos solo de
    fuentes de fans.
- **No existe SDK ni fuente de RenderWare 2 preservado en ningún sitio.** Solo
  hay abundante material de RenderWare 3.x (el de GTA), que es un formato
  binario **incompatible** con RWX — no sirve como atajo directo.
- Formatos de archivo propios:
  - **RWX** — geometría estática. Texto ASCII plano, ejecutado como un script
    (comandos tipo `ClumpBegin`/`ClumpEnd`, `ModelBegin`/`ModelEnd`, etc.). El
    intérprete ignora comandos que no reconoce. Sin shaders ni normal maps:
    solo textura de color (albedo), luz difusa/especular monodireccional muy
    básica, ambiente simple, y transparencia limitada.
  - **RWG / BOD** — avatares articulados (con jerarquía de huesos/joints).
    Formato **binario**, más complejo. Empezar por RWX, dejar esto para
    después.
  - Avatares custom: texturas **BMP de 24-bit**, extensiones válidas `.rwg` /
    `.bod`.
- **WorldsPlayer no soporta SSL/TLS** — todo el tráfico (incluido el que
  reimplementemos) tiene que ir por HTTP plano.
- Worlds Chat original (antes de RenderWare) usaba un motor propio más
  primitivo llamado **Accomplish**. No es relevante para la versión moderna
  del cliente, pero es dato histórico útil si aparecen referencias a él en el
  código decompilado.

---

## 3. Mapa completo del ecosistema (todo lo encontrado)

### 3.1 Whirlsplash (github.com/Whirlsplash) — el más útil y activo

| Repo | Qué es | Estado | Por qué importa |
|---|---|---|---|
| `worldsplayer_source_editor` | Decompila/edita/recompila WorldsPlayer en Linux (Make + Vineflower + Java 6) | ✅ Activo | **Esta es la herramienta con la que arrancamos el proyecto.** |
| `whirl` | Servidor WorldServer open source, en Rust | ✅ Activo (marzo 2026), 12★ | Protocolo de red ya resuelto — no hace falta escribir servidor propio |
| `LibreWorlds` (a.k.a. `OpenWorlds`) | Ingeniería inversa del protocolo, cliente multiplataforma desde cero | ❌ Archivado 2017–2021 | Se quedó en documentación del protocolo, nunca terminó el cliente gráfico. Útil como referencia histórica |
| `LibreWorlds-wiki` | Wiki asociada al repo anterior | ❌ Archivado | Documentación del protocolo |
| `terra` | Framework de bots ("Structured bots for Worlds") | 🚧 Preview muy temprana, 2 commits | Reestructuración de `munch` |
| `munch` | Bot en Go con integración Discord | — | Otra implementación independiente del protocolo (en Go), útil para validar cruzado |
| `frontend` | Panel web de gestión/estadísticas de servidor + bot Discord | — | Secundario |
| `worldsy` | Cliente de Discord Rich Presence para Worlds (Python) | — | Secundario, curiosidad |
| `cloworlds`, `node-worlds`, `deno_worlds` | Librerías cliente en Clojure, Node.js, Deno | ❌ Archivadas | Implementaciones de referencia del protocolo en varios lenguajes |
| `assets` | Recursos gráficos compartidos | — | Secundario |

Documentación general del ecosistema Whirlsplash centralizada en
`whirlsplash.org` (incluye una página de recursos que enlaza también a GammaDocs).

### 3.2 Ecosistema de Blaxar (Julien Bardagi) — el más útil para renderizado

| Repo | Qué es | Lenguaje |
|---|---|---|
| `three-rwx-loader` | **Parser + renderer de RWX completo y funcional**, con soporte de texturas y máscaras | JavaScript (three.js/WebGL) |
| `WideWorlds` | Cliente + servidor web completo, estilo Active Worlds ("Metaverse accesible desde tu navegador, siguiendo los pasos de Active Worlds") — backend Node.js/HTTP+WS, frontend Vue.js, SQLite3, importador de dumps de mundos AW | JavaScript |
| `rwx2blender` | Add-on de Blender para importar RWX | Python |
| `aw-sequence-parser` | Parser de animaciones/secuencias de avatares de Active Worlds | JavaScript |

⚠️ **Nota importante**: no existe ningún parser RWX ya hecho en **Java**. Todo
lo reutilizable de Blaxar está en JavaScript — hay que **traducir la lógica**,
no copiar-pegar código directamente.

### 3.3 Otras herramientas sueltas

- **`Bloyteg/RWXViewer`** — visor web de archivos RWX para ActiveWorlds/Virtual
  Paradise. Apache 2.0.
- **`adamaig/blender_rwx_importer`** — otro importador RWX a Blender (más
  antiguo, Blender 2.49).
- **`Sgeo/rwg_to_rwx`** — conversor RWG→RWX, confirma la distinción entre
  RenderWare 2.0 y 2.1 en distintas versiones de WorldsPlayer.

### 3.4 Documentación

- **GammaDocs** — documentación **OFICIAL de Worlds Inc.** para
  desarrolladores, preservada:
  - Internet Archive: `archive.org/details/gammadocs`
  - Espejo en Worlio: `files.worlio.com/files/WorldsPlayer/guides/GammaDocs/`
  - Wayback Machine: copias de `dev.worlds.net/private/GammaDocs/`
  - Contenido: `WorldServer.html` (arquitectura del servidor: RoomServer,
    UserServer — para sysadmins con conocimientos de Unix/Oracle/Web),
    `Gamma_Overview.html`, `Gamma_Procedures.html`, `Gamma_Advanced.html`
    (instalación del Shaper, empaquetado de mundos)
- **`kangworlds.net`** (de bonkmaykr, webmaster de Worlio) — tutoriales de
  creación de avatares RWX/RWG, compresión de texturas, y una página
  *"Creating a WorldsPlayer Interface"* basada explícitamente en documentación
  oficial de Worlds Inc.
- **Wiki de Active Worlds** (`wiki.activeworlds.com`) — documentación completa
  de todos los comandos del script RWX, incluidas extensiones propias de AW
  (prefijo `#!`)
- **Worlds Chat Wiki** — dos espejos de comunidad:
  - `worldschat.fandom.com`
  - `worldschat.miraheze.org`
  - Contenido útil: página "Avatars" (BMP 24-bit, sin SSL/TLS, extensiones
    `.rwg`/`.bod`), página "Worlds Chat" (genealogía compartida con Active
    Worlds y **Starbright World** — posible tercer proyecto hermano, sin
    investigar aún)

### 3.5 Comunidad y servidores vivos hoy

- **WorlioWorlds** (`worlds.worlio.com`) — servidor revival gratuito,
  ~8 usuarios online / 116 registrados. Requiere editar `override.ini`
  (`WorldServer`, `UpgradeServer`, `ScriptServer` → dominios de Worlio),
  registro por web.
- **Worlio** (`worlio.com`) — proyecto general de preservación de "Web 1.0"
  (foro, archivo, Jabber/XMPP, Mumble, IRC, radio). Organización detrás:
  **Canithesis Interactive** (de bonkmaykr).
  - 13 mayo 2025: **Wirlaburla dejó el puesto de webmaster** de Worlio tras
    años de rumores/acoso de un miembro rival de la comunidad de Worlds.
    Desarrollo de todos los proyectos de Worlio quedó congelado desde
    entonces (explica los 404 en repos que antes vivían en `git.worlio.com`).
    Worlio pasó a ser propiedad de Canithesis Interactive GP.
- **LibreWorlds** (`libreworlds.org`) — comunidad/servidor de prueba activo,
  Discord propio, infraestructura gestionada por **Electric Jungle** (colectivo
  que da hosting/soporte best-effort a varios proyectos).
- **OMEGA** — mod de cliente hecho por Wirla, reescritura de "Worlds+".
  Compatible desde la build 1890 en adelante. Se instala reemplazando
  `gammacls.zip`/`worlds.jar` en la carpeta `lib` del cliente. Código fuente
  no publicado públicamente (se distribuye como ZIP compilado).
  - Wirlaburla sí tiene repos públicos en su propia instancia Gitea
    (`wirlaburla.com/git`), incluyendo `Worlds-Organizer` (herramienta Java
    para organizar archivos/recursos de WorldsPlayer, con un
    `IMGTranscoder.java` para transcodificar imágenes).
  - ⚠️ Enlaces a `git.worlio.com` / `git.canithesis.org` con repos específicos
    de Wirlaburla (`WorldsMods`, `P3NG0`, `WorldsTerminal`) dieron 404 al
    intentar acceder — puede que se hayan movido, renombrado, o no
    sobrevivido la migración. Revisar manualmente en el navegador si hace
    falta, el buscador no pudo confirmar su estado actual.

---

## 4. Herramientas y entorno de trabajo

- **Hardware**: Xeon 28 núcleos LGA2011, GTX 1060 6GB, 16GB RAM + zram/swap
- **WSL2** — entorno principal de trabajo
  - ⚠️ Si el repo se clona en el filesystem de Windows, aparece un error de
    fin de línea CRLF (`env: $'bash\r'`) al ejecutar `bin/decompile`. Fix:
    `dos2unix bin/decompile` (y cualquier otro script bash del repo si da el
    mismo error)
- **Decompilación**: `worldsplayer_source_editor`
  - Requiere: **Java 6** (JDK, del Oracle Java Archive — ya no se distribuye
    normalmente), **Vineflower** (decompilador, debe estar en el `PATH`), y
    el propio `worlds.jar` original
  - Flujo:
    ```bash
    # Decompilar
    WORLDSPLAYER_JAR=/ruta/a/worlds.jar make decompile
    # → vuelca las fuentes en /source

    # Editar libremente en /source

    # Recompilar
    JAVAC=/ruta/al/compilador/java6 make compile
    # → genera out/worlds.jar

    # Instalar directo en el cliente (opcional)
    WORLDSPLAYER_JAR=/ruta/a/worlds.jar make install
    ```
  - Trae parches de ejemplo en `patches/optional/`: `free_vip.patch`,
    `bypass_assert_fail_exit.patch`
- **Análisis binario**: Ghidra (disassembly/decompilación de las DLLs
  nativas), IDA Free (cross-reference de ASM)
- **Inferencia local (Ollama)**: Qwen 2.5/3 7B o DeepSeek distillates —
  **solo para tareas mecánicas de bajo riesgo** (renombrado masivo,
  clasificación de patrones, formateo). Nunca para interpretación de lógica
  compleja, reconstrucción de structs, o mapeo de protocolo — ahí los errores
  se propagan en silencio.
- **Claude Code** — copiloto para interpretar pseudo-C, reconstruir structs, y
  mapear la documentación del protocolo contra el código decompilado. El
  agente debe leer los archivos exportados directamente del disco, no que
  se le pase código copiado a mano.

### Groundwork ya hecho
- `.jar` objetivo localizado: extraído de un instalador Wise Installation
  System de 2004. `GAMMACLS.ZIP` dentro del paquete `FIRST` contiene las
  clases Java bajo `NET.worlds.{br, console, core, network, scape}` —
  confirmado como el código del cliente WorldsPlayer. Plan: copiarlo como
  `worlds.jar` para el Makefile.
- **✅ HECHO (2026-09-08)**: `GAMMACLS.ZIP` extraído de `assets/FIRST.EXE`
  (que es un ZIP SFX legible directamente con `zipfile`/`unzip`, sin
  necesitar Wine) y copiado a `assets/worlds.jar`. Vineflower 1.12.0
  descargado en `tools/vineflower.jar` con un shim ejecutable en
  `tools/vineflower` (solo hace falta un JVM moderno para *decompilar* —
  Java 6 solo es necesario para *recompilar* con `make compile`).
  `make decompile` corrido con éxito en `editor/worldsplayer_source_editor-main`
  → **722 archivos `.java` en `editor/worldsplayer_source_editor-main/source/`**
  (paquete real: `NET.worlds.*`, con NET en mayúsculas). Los patches del
  editor (`patches/fix_compilation_errors.patch`) **no aplicaron limpio**
  (probablemente por diferencia de versión de Vineflower vs. la que usó el
  autor del tool) — pendiente de resolver antes de intentar `make compile`.
  Reconocimiento rápido: 64 métodos `native` detectados con grep simple
  (`GetDiskFreeSpace`, `GetTotalPhysicalMemory`, `instanceOf`, `getBuildInfo`,
  etc.) — punto de partida real para la herramienta #1 (sección 7).

### ⚠️ Hallazgo crítico (2026-09-08): el scaffold previo apuntaba al binario equivocado
Antes de esta sesión, alguien (sesión anterior de Claude Code, a juzgar por el
`README.md` recuperado del commit inicial) había reverseado `Worlds1900.exe`
con Ghidra + IDA (`Worlds1900.exe.{asm,c,gzf,i64,map}`) y había montado un
wrapper CMake/C (`src/`, `include/`, `build/`) asumiendo que era el cliente
WorldsPlayer.

**`Worlds1900.exe` NO es el cliente — es el stub del instalador Wise.**
Confirmado con `strings Worlds1900.exe`: contiene literalmente `"WiseMain"`,
`"WISE0001.DLL"`, `"Windows Self-Installing Executable"`, `"GLBSInstall"`. Las
funciones decompiladas (`FUN_00401177`, `FUN_00401583`, `FUN_00401810`, etc.)
son el algoritmo Huffman/LZ de descompresión del instalador (mismo motor que
extrae `FIRST.EXE`), no lógica del cliente 3D. Todo ese trabajo era válido
como ingeniería inversa del instalador, pero no aportaba nada al objetivo real
del proyecto (el cliente Java + JNI/RenderWare).

Ese scaffold se movió a `legacy/installer-reversing/` para no estorbar,
conservando el trabajo por si algún día interesa (p. ej. para extraer más
paquetes empotrados en otros instaladores Wise sin depender de Python/zipfile).
**El objetivo real a decompilar es `assets/worlds.jar` (ex `GAMMACLS.ZIP`) vía
`editor/worldsplayer_source_editor-main`, no ningún `.exe` nativo.**

### ✅ Ciclo completo decompile → fix → recompile verificado (2026-09-08)
El pedido explícito fue "decompilar el juego", así que until el final: el
código decompilado (722 `.java`) **no compilaba** con ningún JDK moderno
(`javac --release 8`, el `-source 1.6` del `Makefile` original ya ni siquiera
existe en JDKs actuales). Se arregló en la copia de trabajo
(`editor/worldsplayer_source_editor-main/source/`, commit `e719a84` en su
repo git anidado) y se regeneró `patches/fix_compilation_errors.patch` a
partir del diff real (el patch viejo del tool, escrito para otra versión de
Vineflower, ya no aplicaba limpio). Categorías de arreglos, de más a menos
frecuente:

1. **`assert`/`enum` como identificador** — el código es de ~2000-2001,
   antes de que Java 1.4 (`assert`, 2002) y 1.5 (`enum`, 2004) reservaran esas
   palabras. `Debug.assert(...)` → `Debug.assert_(...)` (114 call sites, 91
   archivos) y `Property enum()` → `enum_()`.
2. **Campos sintéticos `this$0`/`val$X` y bridges `access$NNN` no
   reconstruidos por Vineflower** en 14 clases anónimas/internas
   (`MCISoundPlayer$1-4`, `DefaultConsole$1-3`, `TradeDialog$1-2`, etc.) —
   Vineflower emitió el uso pero no la declaración. Se dedujeron los tipos
   por el contexto (parámetro del constructor) y, para los `access$NNN`, por
   la firma de uso en el call site cruzada contra los miembros `private` de
   la clase contenedora (ver `MCISoundPlayer.java`, `LogFile.java`,
   `ActionsPart.java`).
3. **Idioma pre-1.5 de `Foo.class` no colapsado** (`class$NET$worlds$...
   == null ? (class$... = class$("...")) : class$...`) en `WObject.java` (6
   ocurrencias) — reemplazado por el literal `.class` directo.
4. **Pérdidas de tipo del decompilador** (`Object`↔`String`,
   `WObject`↔`Surface`, `Persister`↔`Persister[]`, unboxing de `Integer`
   faltante en `+=`/`-=`) — en `DefaultConsole.java` se verificó con
   evidencia dura (`javap -c -p` sobre el `.class` original en
   `assets/worlds.jar`, no una suposición) que el bug real era el tipo
   declarado de la variable, no la expresión de construcción.
5. `sun.misc.BASE64Encoder` (eliminado del JDK hace años) → `java.util.Base64`.

**Resultado: 0 errores de compilación.** `jar` empaquetado en
`editor/worldsplayer_source_editor-main/out/worlds.jar` (no versionado,
regenerable — ver `.gitignore`), 736 clases, 1.3MB. Verificación de que el
recompilado es funcionalmente fiel: corre en un JVM real
(`java -cp out/worlds.jar NET.worlds.console.Gamma`), imprime su propio
banner de arranque, y falla exactamente donde se espera —
`UnsatisfiedLinkError` al intentar `System.load("gamma.dll")` porque es un
DLL de Windows x86 corriendo en Linux sin Wine. Es la prueba de que el
puente JNI hacia RenderWare (sección 2, herramienta #1 de la sección 7) está
intacto y es el próximo punto de ataque real para la fase 2 (renderer
portable).

### ✅ Herramienta #1 construida (2026-09-08): mapeador de métodos `native`
El usuario aportó `assets/WorldsPlayer/` — el árbol **real de una instalación
ya hecha** del cliente (no solo el paquete del instalador): `bin/` con todas
las DLLs nativas (incluidas las de RenderWare y `gamma.dll`, el puente JNI
real), `lib/gammacls.zip` + `rt.jar` (JRE de Sun 1.4.2_05 completo), logs
reales de ejecución (`Gamma.Log`, `GroundZero.log`) y config (`worlds.ini`,
`override.ini`). De los logs reales: el cliente se lanza con
`java.class.path=.;lib\gammacls.zip` y
`sun.boot.class.path=lib\i18ncls.zip;lib\rt.jar`, y el servidor original al
que intentaba conectar tras el arranque es `www.3dcd.com:6650` (muerto hoy,
como se esperaba).

También trajo Ghidra 12.1.3 (headless, `analyzeHeadless` funciona con el
Java 25 del sistema — el mínimo que pide Ghidra es Java 21). Con eso:

1. Analicé `gamma.dll` con `analyzeHeadless` (proyecto en `analysis/`, no
   versionado — regenerable, ver `.gitignore`).
2. Parseé la tabla de exports de `gamma.dll` y `RWL21.DLL` a mano (script
   Python sin dependencias — `objdump -T`/`pip` no estaban disponibles o no
   funcionaban con estos PE32 antiguos) → **372 exports JNI en `gamma.dll`**,
   volcados en `docs/gamma-dll-exports.txt`.
3. Escribí un script que recorre los 722 `.java` decompilados, extrae cada
   declaración `native`, calcula el símbolo JNI esperado (con el mangling
   real de guiones bajos `_` → `_1`) y lo cruza contra los exports reales →
   **`docs/native-methods-map.md`**.

**Resultado inicial de esta sesión: 360 declaraciones `native` encontradas,
358 casan con un export real de `gamma.dll`.** (Números corregidos al día
siguiente — ver el bloque de 2026-09-09 más abajo: la regex tenía un bug de
modificadores y se saltaba 5 declaraciones reales; el total correcto es 365.)
Esto confirma con evidencia dura que `gamma.dll` es *el* puente JNI del
cliente — no hay que buscar la implementación nativa en ningún otro sitio.

**Reorganización de archivos de esta sesión:**
- `move/` (aportado por el usuario) → `assets/WorldsPlayer/`.
- `tools/vineflower.jar` + shim `tools/vineflower` (descargado de GitHub,
  release 1.12.0) — hace falta para repetir `make decompile`.
- `.gitignore` nuevo: excluye la instalación de Ghidra (~1.4GB, herramienta
  externa reinstalable) y `analysis/` (proyecto Ghidra, regenerable).

### ✅ Los 2 métodos sin mapear investigados + Bridge JNI mock construido (2026-09-09)

**1) Investigación de los 2 `native` sin export en `gamma.dll`** (con
evidencia real, no suposición — ver `docs/native-methods-map.md` para el
detalle completo):

- De paso se encontró un bug en la regex del mapeador: solo aceptaba
  `static` en una posición fija antes de `native`, y se saltaba
  declaraciones con orden distinto (`public static final native`, `public
  static synchronized native`). Corregido → el total real de declaraciones
  `native` es **365**, no 360.
- **`sendURL.silent_get`** — ✅ resuelto, era un falso negativo del script:
  el export existe (`?Java_NET_worlds_scape_sendURL_silent_get@@YGJ...`)
  pero con mangling **C++ de MSVC**, no el `_Java_...@N` estándar con escape
  `_`→`_1` que usa la mayoría. El mapeador ya prueba ambas formas.
- **`PendingCacheDrone.nativeDestroy`** — ⚠️ confirmado código muerto: 0
  exports posibles en `gamma.dll` bajo ningún mangling, y 0 llamadas en los
  722 archivos decompilados (comparar con `nativeInit()`, que sí se llama
  desde el `static {}` de la misma clase).
- **`Console.getVolumeInfo`** — ⚠️ mismo patrón: existe un gemelo
  `Startup.getVolumeInfo()` que sí está exportado y sí se usa desde
  `LoginWizard.java:702`; la versión de `Console` es un duplicado obsoleto,
  0 llamadas, sin export propio.
- **Resultado final: 365 declaraciones, 363 (99.5%) mapeadas contra
  `gamma.dll`, 2 confirmadas como código muerto** (no bloquean nada).

**2) Bridge JNI mock (herramienta #4, sección 7)** — implementado con
`tools/jni_mock.py`:
- Reemplaza cada método `native` por un cuerpo que llama a
  `NET.worlds.core.NativeMock.log(clase, método, args)` (clase nueva) y
  devuelve un valor por defecto. Política de defaults (documentada en el
  propio script, no es "la verdad", es una elección para maximizar cuánto
  avanza el cliente): `boolean`→`true` (para pasar los guards `if
  (!check()) exit/bail` de arranque en vez de cortar en el primero),
  numéricos→`0`, referencias→`null` **salvo** que el último parámetro sea
  del mismo tipo que el retorno (patrón `getIniString(key, default)`), en
  cuyo caso se devuelve ese parámetro — evita `NullPointerException` en
  cascada por defaults que en realidad el propio cliente ya sabía resolver.
- También se envolvieron en `try/catch` los 2 `System.load(...)` de
  `Gamma.java` (arranque principal + `dllLoad()`), que si no abortarían el
  proceso entero al no encontrar la DLL de Windows.
- Genera además `docs/native-methods-callers.md`: qué clase llama a cada
  `native`, útil para saber qué ruta de código dispara cada stub. ⚠️
  **Limitación documentada en el propio archivo**: es grep por texto, no
  entiende polimorfismo/reflection — 167/365 salen como "sin llamadas
  encontradas" y **eso no significa código muerto**, salvo los 2 casos de
  arriba que sí se verificaron aparte cruzando contra `gamma.dll`.
- Todo el flujo (regenerar `source/` limpio → aplicar el mock → recompilar)
  quedó en `editor/worldsplayer_source_editor-main/apply_mock.sh`, para no
  tener que rehacerlo a mano cada vez (el `source/` decompilado no se
  versiona — ver `.gitignore` — así que hay que re-generarlo y re-mockear en
  cada sesión nueva antes de poder correr el cliente).

**Resultado en runtime** (headless, `java -cp out/worlds-mock.jar
NET.worlds.console.Gamma`, log completo en
`docs/jni-mock-runtime-trace.log`): el cliente **arranca de verdad sin
ninguna DLL de Windows** — pasa el check de instancia única
(`Startup.synchronizeStartup`), carga `worlds.ini`, resuelve el
`ResourceBundle` de mensajes (detectó locale `es_ES` del sistema) — y llega
hasta la construcción de la `MenuBar` real de Swing/AWT en
`Console.<clinit>`, donde revienta con `java.awt.HeadlessException`. **Este
ya no es un problema de mocking de nativos — es que no hay servidor X en
esta máquina.**

### ✅ Probado con Xvfb (2026-09-09) — dos hallazgos más, ninguno del bridge JNI

Con Xvfb (`Xvfb :99 -screen 0 1024x768x24`, `DISPLAY=:99`) el cliente pasó el
punto de `HeadlessException` y llegó bastante más lejos, hasta topar con dos
problemas reales — ninguno de los dos es un hueco del mock, los dos están
aislados y confirmados con evidencia, no supuestos:

1. **Colisión de `libnet.so`** — `Gamma.main()` llama a
   `System.loadLibrary("net")` (pensado para cargar el `net.dll` legacy del
   JRE de 2004, ver `assets/WorldsPlayer/bin/net.dll`). En cualquier JDK
   moderno, "net" colisiona con el `libnet.so` **propio del JDK** (su
   librería de networking interna): la carga inicial "tiene éxito" pero
   queda registrada bajo el classloader de la app; más tarde, cuando Swing
   necesita la misma librería vía NIO para leer la config de fuentes, la
   pide el *bootstrap* classloader y el JVM revienta con
   `UnsatisfiedLinkError: ... already loaded in another classloader`.
   **Aislado con un reproducer mínimo de 10 líneas** (`System.loadLibrary
   ("net")` + tocar un `JPasswordField`, sin nada del cliente real) — el
   error es idéntico byte a byte. Arreglado: `apply_mock.sh` ahora salta esa
   llamada específica (no hacía nada útil fuera de Windows real de todos
   modos).
2. **Asunción de ruta estilo Windows en `NET.worlds.network.URL`** —
   `currentDir = System.getProperty("user.dir").replace('\\', '/')` seguido
   de `Debug.dAssert(currentDir.charAt(1) == ':' || currentDir.startsWith
   ("//"))` en el bloque `static {}` de `URL.java:557`. En Windows
   `user.dir` es del tipo `C:\...` (pasa el assert); en Linux es
   `/home/...` y la aserción falla siempre. **Esto es lógica real del
   cliente, no un método `native`** — está fuera del alcance de la
   herramienta #4 (que solo mockea `native`s) y entra de lleno en el
   trabajo de portabilidad de la fase 4 del roadmap (sección 5). No se
   parcheó esta vez — es la primera pared de portabilidad real encontrada,
   y merece su propio análisis (¿cuántos otros sitios asumen rutas
   Windows?) antes de tocarla.

**La excepción ocurre dentro de `NET.worlds.network.NetUpdate.<clinit>`**,
justo cuando el cliente está calculando la URL del servidor de upgrade —
o sea, llegamos literalmente al borde de la lógica de conexión de red antes
de morir. Log completo en `docs/xvfb-runtime-trace.log`.

### Direcciones de servidor por defecto (pregunta 4)

Sin necesitar que el cliente llegue más lejos, esto ya se puede sacar por
análisis estático + la config real que aportó el usuario:

- **`assets/WorldsPlayer/worlds.ini`** (la instalación real de 2026, tal
  como la dejó el usuario): `upgradeServer=http://us1.worlds.net/3DCDup`
  — el dominio oficial, muerto desde octubre 2025 (sección 1).
- **Hardcodeado en el `.java` decompilado** (`Galaxy.java:678-679`): si el
  host del server resuelto es literalmente `www.3dcd.com:6650`, el cliente
  tiene un fallback a la IP fija `209.67.68.214:6650` (probablemente un
  workaround de Worlds Inc. para cuando el DNS de 3dcd.com fallaba). También
  aparecen `www.3dcd.com:25` (SMTP, no es el juego) y `time.worlds.net`
  (sync de hora, tampoco es el juego). Esto coincide exactamente con lo que
  ya se había visto en un log real de ejecución (`Gamma.Log`, sesión
  anterior): `AutoServer(www.3dcd.com:6650): lastError=VarErrorException`.
- **Para probar contra `whirl` o WorlioWorlds**: hay que editar
  `upgradeServer` en `worlds.ini` (y probablemente `WorldServer`/
  `ScriptServer` en `override.ini`, como ya hace WorlioWorlds según la
  sección 3.5) para que apunten al servidor de prueba en vez de a
  `worlds.net`/`3dcd.com`. El puerto por defecto observado (`6650`) es un
  buen punto de partida para comparar contra el puerto que escucha `whirl`.

---

## 5. Roadmap por fases

**Orden de módulos: networking → renderer → UI**

| Fase | Contenido | Dificultad | Tiempo estimado |
|---|---|---|---|
| 0 — Reconocimiento | Decompilar con `worldsplayer_source_editor`, `grep -r "native"` para mapear todos los métodos nativos, identificar DLLs cargadas | 🟢 Baja-media | 1–3 semanas |
| 1 — Parsers de formato | Parser RWX (Java, basado en la lógica de `three-rwx-loader`) primero; RWG/BOD (binario, avatares articulados) después | 🟡 RWX fácil / RWG-BOD medio | 2–6 semanas |
| 2 — Renderizador | Sustituir las llamadas JNI por implementación portable — recomendado: Java puro + **LWJGL** (bindings OpenGL), replicando el pipeline simple de RenderWare 2 (sin shaders, solo difusa/especular/ambiente básicas) | 🔴 Alta (sin SDK de RW2 al que recurrir) | 2–6 meses |
| 3 — Red | Ya resuelto en gran parte — protocolo documentado por LibreWorlds/Xyem, implementado en `whirl` (Rust) y `munch` (Go) como referencias cruzadas | 🟢 Baja | Incluido en fase 0-1 |
| 4 — Integración y UI | Chat, lista de amigos, mapa, menús, compatibilidad de comportamiento con el original | 🟡 Media (sin atajos, trabajo de descubrimiento línea a línea) | 1–3 meses |
| 5 — Porteo a OpenBSD | Una vez quitadas las dependencias nativas de Windows, evaluar viabilidad real en OpenBSD (Wine no está soportado oficialmente ahí — Mesa/OpenGL nativo es el camino) | 🔴 Alta | Posterior al resto |

**Estimaciones totales (revisadas tras la investigación, dedicación
part-time):**

| Objetivo | Estimación |
|---|---|
| MVP (conectar, chat de texto, sin 3D) | 2–3 semanas |
| Cliente funcional con renderizado básico | 2–4 meses |
| Réplica fiel completa | 6–10 meses |

---

## 6. Principios de verificación (no negociables)

1. **Nunca aceptar un mapeo de direcciones/funciones sin evidencia a nivel
   ASM** (`mov [address], eax` o equivalente). Los agentes de IA han cometido
   errores como direcciones duplicadas cuando no se les exige este nivel de
   prueba.
2. **Claude es copiloto, no agente autónomo.** El cuello de botella real es la
   verificación humana del comportamiento decompilado contra el binario
   original — no la velocidad de generación de código. Cada sesión debe ser
   acotada a un módulo concreto.
3. **Lotes grandes con autoauditoría**, no función por función. Usar etiquetas
   de confianza (⚠️ VERIFICAR) en las secciones dudosas en vez de checkpoints
   manuales constantes.
4. El objetivo final es **reimplementación funcional**, no solo documentación
   — cada función verificada debe reescribirse como código testeable, con
   casos de prueba calculados a mano.

---

## 7. Herramientas a construir (para acelerar el proceso)

Orden de prioridad recomendado:

### Prioridad alta
1. **Mapeador de métodos `native`** — recorre el código decompilado,
   extrae cada método `native` (clase, firma, tipo de retorno) y lo cruza
   contra los símbolos exportados de las DLLs reales (`objdump -T` / `nm`).
   Salida: tabla "qué hay que reimplementar" + "qué sabemos ya por su firma".
2. **Panel de progreso por módulo** — script que escanea el código en busca
   de las etiquetas ⚠️ VERIFICAR y genera un dashboard (Markdown o JSON) con
   funciones verificadas vs. pendientes vs. dudosas, por clase/módulo.
3. **Arnés de pruebas RWX Java vs. JS** — parsea el mismo `.rwx` con el
   parser Java en construcción y con `three-rwx-loader` (vía Node headless),
   compara la geometría resultante (vértices, caras, materiales)
   automáticamente.

### Prioridad media
4. ✅ **HECHO (2026-09-09)** — **Bridge JNI "mock"** — stub que implementa
   los métodos `native` con logging en vez de lógica real, para poder
   arrancar el cliente y probar networking/UI sin esperar a tener el
   renderizador completo. Ver sección 4 para el resultado y el hallazgo del
   límite real (headless/AWT, no las DLLs).
5. **Comparador de versiones del `.jar`** — diff automatizado entre distintas
   builds decompiladas (si se consiguen), para distinguir bugs de
   comportamiento intencional a lo largo del tiempo.

### Prioridad baja
6. **Convertidor batch RWX → OBJ** para revisión visual rápida en Blender de
   muchos archivos a la vez, mientras el renderizador propio no existe.
7. **Generador de documentación de structs** — a partir de patrones
   repetitivos de getters/setters, generar tablas de estructura
   automáticamente. Tarea mecánica, apta para Ollama local, no para Claude.

---

## 8. Instrucciones para Claude Code

Si estás retomando este proyecto como Claude Code, este es el orden de
arranque. **El paso 0 es obligatorio y va antes que nada más** — no
decompiles, no escribas código, no toques nada hasta haberlo hecho.

### Paso 0 — Reconocimiento del repo (SIEMPRE primero)
Antes de cualquier otra acción, **revisa el árbol de directorios completo**
del repo `worldsplayer_source_editor` (y de `/source` si ya existe de una
sesión anterior). Usa un listado recursivo (`tree` o equivalente) para
entender:
- Qué scripts hay en `bin/` y qué hace cada uno
- Estructura del `Makefile` (targets disponibles más allá de `decompile`,
  `compile`, `install`)
- Si `/source` ya existe de un decompile previo (no lo repitas si no hace
  falta — ahorra tiempo y tokens)
- Si hay `patches/`, `docs/`, `CLAUDE.md`, `README` u otros archivos de
  contexto que no estén ya reflejados en este documento

No asumas la estructura por lo que dice este documento — el repo puede haber
cambiado desde que se escribió. **Reporta primero, actúa después.**

### Paso 1 en adelante
1. **Verifica el entorno**: confirma que Java 6 y Vineflower están
   disponibles, y que no hay pendiente el fix de `dos2unix` sobre
   `bin/decompile` (ver sección 4).
2. **Ejecuta el decompile** (si no existe ya de una sesión anterior):
   `WORLDSPLAYER_JAR=<ruta> make decompile` y revisa que `/source` se pobló
   correctamente.
3. **Construye primero la herramienta #1 (mapeador de nativos)** de la
   sección 7 y córrela sobre el resultado. Esto da el mapa real de trabajo
   pendiente — no asumas nada de este documento como sustituto de mirar el
   código real.
4. **Prioriza el parser RWX** (sección 5, fase 1) usando `three-rwx-loader`
   como referencia de lógica — está en `github.com/Blaxar/three-rwx-loader`.
5. **Antes de aceptar cualquier mapeo de dirección o interpretación de
   struct como "confirmado"**, exige evidencia ASM (sección 6, principio 1).
   Marca lo dudoso con ⚠️ VERIFICAR en vez de asumir.
6. **No escribas el servidor desde cero** — usa `whirl` (Rust,
   `github.com/Whirlsplash/whirl`) como referencia o directamente como
   servidor de pruebas.
7. **Trabaja en lotes por módulo**, no función por función, y presenta
   resúmenes con las secciones marcadas ⚠️ VERIFICAR para que el humano
   revise antes de dar nada por bueno.
8. **Nunca uses el LLM local (Ollama) para lógica compleja** — solo para
   renombrado masivo, clasificación o formateo mecánico.

---

## 9. Estrategia de subagentes (para avanzar rápido sin gastar tokens de más)

Los subagentes de Claude Code son instancias separadas, con su propio
contexto, que hacen el trabajo "ruidoso" (leer muchos archivos, explorar,
correr comandos) de forma aislada y devuelven solo la conclusión al hilo
principal. Son potentes, pero **cada uno multiplica el consumo de tokens**
(varias veces más que una sesión normal) — así que hay que usarlos con
criterio, no por sistema.

### Regla general: delegar cuando el ruido es grande y la conclusión es pequeña
Si una tarea implica leer muchos archivos pero el resultado final cabe en
una tabla o un párrafo, es candidata a subagente. Si la tarea necesita
ida y vuelta constante con el humano, o construye sobre contexto que el
hilo principal ya tiene fresco, **mejor NO delegar** — es más caro y más
lento que hacerlo directo.

### Cuándo SÍ usar subagentes en este proyecto
- **Exploración paralela del código decompilado**: repartir `/source` en
  varios subagentes (uno por paquete: `net.worlds.br`, `net.worlds.console`,
  `net.worlds.core`, `net.worlds.network`, `net.worlds.scape`), cada uno con
  la tarea acotada de listar métodos `native`, clases sospechosas de tocar
  red/render/UI, y devolver solo un resumen tabulado. Ejemplo de prompt:
  ```
  Lanza 5 subagentes en paralelo, uno por cada paquete de /source
  (net.worlds.br, net.worlds.console, net.worlds.core, net.worlds.network,
  net.worlds.scape). Cada uno debe: listar métodos "native" con su firma,
  identificar las 3 clases más grandes del paquete, y devolver solo una
  tabla markdown de menos de 30 líneas. No me devuelvas código completo.
  ```
- **Búsqueda de patrones repetitivos** (getters/setters para documentación
  de structs, la herramienta #7 de la sección 7): tarea mecánica, ideal para
  un subagente con modelo barato (Haiku) en vez de gastar el modelo principal
  en ello.
- **Verificación cruzada** (herramienta #3, arnés RWX Java vs. JS): un
  subagente corre el parser JS de referencia sobre un lote de archivos
  `.rwx`, otro corre el parser Java en construcción, un tercero compara
  resultados — trabajo aislable y paralelizable por naturaleza.
- **Búsquedas de documentación externa** (repasar GammaDocs, la wiki de
  Active Worlds, etc. buscando un dato concreto): delega la lectura completa
  a un subagente y que solo te traiga el dato exacto, no el documento entero.

### Cuándo NO usar subagentes
- Al **interpretar lógica compleja o reconstruir structs** — esto necesita
  el contexto completo y el criterio del modelo principal en vivo, con el
  humano pudiendo interrumpir y corregir sobre la marcha. Delegarlo a un
  subagente aislado pierde justo el control fino que exige el principio de
  verificación de la sección 6.
- Para **cambios pequeños y puntuales** (arreglar un import, renombrar una
  variable) — el coste de arrancar un subagente (context en frío) es mayor
  que hacerlo directo.
- Cuando el resultado necesita **varias rondas de refinamiento con el
  humano** — cada vuelta a un subagente reinicia su contexto, así que es más
  caro que mantener la conversación en el hilo principal.

### Tácticas concretas para adelantar el proyecto ahorrando tokens
1. **Modelo según la tarea**: si defines subagentes personalizados
   (`/agents`), asigna Haiku a exploración/clasificación mecánica, Sonnet a
   implementación estándar, y reserva Opus solo para el razonamiento más
   difícil (p. ej. reconstruir el pipeline de renderizado). No uses el
   modelo más caro para tareas de listar archivos.
2. **Acota SIEMPRE el output del subagente**: pide explícitamente "máximo
   N líneas", "solo tabla, sin código", "no me repitas el archivo completo".
   Un subagente sin límite de salida devuelve toneladas de texto que luego
   infla el contexto del hilo principal igualmente.
3. **No repitas el decompile ni relecturas completas de `/source`** entre
   sesiones — por eso el Paso 0 exige comprobar primero si el trabajo ya
   está hecho.
4. **Paraleliza por módulo, no por función** — 5 subagentes (uno por paquete
   Java) es rentable; 50 subagentes (uno por función) es ruido y coste sin
   beneficio proporcional.
5. **Guarda las conclusiones de cada subagente en archivos** (p. ej.
   `docs/native-methods-map.md`, `docs/verificado/<modulo>.md`) en vez de
   solo en el chat — así la siguiente sesión (o el siguiente subagente) lee
   el archivo en vez de tener que volver a explorar el código desde cero.
6. **Usa subagentes de solo lectura para el reconocimiento inicial** (sin
   permiso de escritura) — así no hay riesgo de que toquen código mientras
   solo están explorando, y puedes lanzarlos con más confianza en paralelo.

---

## 10. Cabos sueltos / preguntas abiertas

- ✅ **RESUELTO (2026-09-08)**: es **RenderWare 2.1**. Confirmado por el
  propio nombre de las DLLs reales del cliente instalado
  (`assets/WorldsPlayer/bin/RWL21.DLL`, `RWDL6D21.DLL`, `RWDL8D21.DLL`,
  `RWDLDD21.DLL`, `rwdlmd21.dll` — sufijo `21`) y por sus tablas de exports
  (parseadas a mano con un script Python de ~70 líneas, sin dependencias,
  porque `objdump -T` no entiende bien el formato de export de estos PE32 de
  2000-2004; ver `docs/renderware21-api-exports.txt`). Bonus inesperado:
  **`RWL21.DLL` exporta las 577 funciones de la API completa de RenderWare
  2.1 con nombres legibles sin mangling** (`RwCreateClump`, `RwClumpBegin`,
  `RwAddLightToScene`, etc.) — no es el SDK ni la documentación, pero es un
  sustituto parcial nada despreciable dado que "no existe SDK de RW2
  preservado en ningún sitio" (sección 2). Cada driver (`RWDL*D21.DLL`)
  expone un único símbolo `_rwdev` (patrón estándar de RenderWare: cada
  driver registra su tabla de funciones a través de ese único entry point).
- Repos de Wirlaburla en `git.canithesis.org` (`WorldsMods`, `P3NG0`,
  `WorldsTerminal`) dan 404 — confirmar manualmente si siguen vivos en algún
  sitio o si el código se perdió.
- **Starbright World** — mencionado como posible tercer proyecto hermano de
  Worlds Chat y Active Worlds, desarrollado en paralelo por Worlds Inc. Sin
  investigar todavía, podría tener recursos reutilizables.
- Decidir con más información real (tras la fase 0) si el camino de
  renderizado será Java+LWJGL puro, o si compensa más seguir el modelo de
  `WideWorlds` (cliente web con three.js) en vez de un cliente nativo.
- ✅ **RESUELTO (2026-09-09)**: probado con Xvfb (el usuario lo instaló).
  Pasó de largo el punto de `HeadlessException` y llegó hasta
  `NetUpdate.<clinit>` (cálculo de la URL del servidor de upgrade) antes de
  morir por una aserción de ruta estilo Windows en `URL.java` — ver el
  detalle completo en la sección 4 ("Probado con Xvfb"). **Siguiente paso
  real**: portar esa asunción de ruta (y buscar cuántas más hay del mismo
  tipo) para que el cliente llegue de verdad a intentar una conexión de red
  contra un servidor configurado a mano (`whirl` / WorlioWorlds).
