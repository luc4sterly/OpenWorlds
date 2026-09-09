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
   trabajo de portabilidad de la fase 4 del roadmap (sección 5). ✅
   **Investigado y parcheado (2026-09-09)** — ver el bloque siguiente.

**La excepción ocurre dentro de `NET.worlds.network.NetUpdate.<clinit>`**,
justo cuando el cliente está calculando la URL del servidor de upgrade —
o sea, llegamos literalmente al borde de la lógica de conexión de red antes
de morir.

### ✅ Asunción de ruta Windows investigada y portada (2026-09-09)

Antes de tocar nada: `currentDir` solo se usa en **3 sitios** de
`URL.java`, los tres con la misma estructura `<letra-de-unidad>:/...`:

1. El propio assert de la sección 4 (`static {}`, línea 557).
2. `validateFile()` — usa `currentDir.substring(0, 2)` (los 2 primeros
   caracteres, "unidad + `:`") como prefijo por defecto cuando resuelve una
   ruta absoluta (`/algo`) o relativa sin unidad explícita.
3. `normalize()` — tiene dos asserts más (`var0.indexOf(58, 5) == 6` y
   `var0.charAt(7) == '/'`) que dependen de que el resultado de
   `validateFile()` tenga exactamente ese formato de 1 carácter + `:` + `/`.

**No hay separadores `\` reales en ningún otro punto de la clase** (el
único `.replace('\\', '/')` es la normalización de entrada, ya hecha antes
de todo esto). El único `new File(...)` real de la clase, en
`searchPath()`, construye la ruta con `File.separator` (ya portable) por un
camino que **no** toca `_url`/`currentDir` para nada — o sea, el problema
está genuinamente contenido a estos 3 sitios.

**Parche mínimo aplicado**: en vez de tocar los asserts o la lógica de
`validateFile()`/`normalize()` (usada en todos lados), se sintetiza una
"unidad" falsa de un solo carácter (`u:`, de "Unix") cuando `user.dir` no
tiene ya forma de ruta Windows — `normalizeCurrentDir()` en `URL.java`,
reaplicado automáticamente por `apply_mock.sh`. Con esto,
`/home/lucas/FreeWorlds/...` se convierte en `u:/home/lucas/FreeWorlds/...`,
que cumple exactamente la misma forma `<1 char>:/...` que el código ya
espera en los 3 sitios — cero cambios en la lógica de parseo. **No afecta
Windows real**: si `user.dir` ya tiene pinta de ruta Windows, la función
lo devuelve sin tocar.

**Resultado**: el cliente pasó de largo `NetUpdate.<clinit>`/`URL.<clinit>`
sin más caídas de portabilidad, completó un **ciclo entero de arranque y
apagado limpio** (exit code 0, sin colgarse, log de 184 líneas en
`docs/xvfb-runtime-trace.log` — antes eran 49). Config real cargada
(`worlds.ini` simulado por el mock), locale detectado (`es_ES`), intentó
leer `redir.txt` (no existe, manejado con gracia), inicializó la caché,
intentó cargar el mundo por defecto `newworld.world`...

**Hallazgo relacionado, NO parcheado (fuera de alcance esta vez)**: al
inicializar la caché, `Cache.java:23` hace exactamente el problema inverso
— `Gamma.earlyURLUnalias("home:cachedir/").replace('/', '\\')` — convierte
la ruta YA correcta de vuelta a backslashes antes de abrir el archivo con
`FileInputStream`, lo que en Linux produce un nombre de archivo literal
absurdo (`\home\lucas\...\cachedir\cache.index`, con barras invertidas como
caracteres normales, no separadores). No es fatal — el cliente lo captura y
sigue ("Flushing cache index.") — pero hay **4 sitios más** con el mismo
patrón `.replace('/', '\\')`: `EditMusicDialog.java:39`, `ASFThread.java:26`,
`Shaper.java:141`, y el propio `Cache.java:23`. Ninguno bloqueó esta
ejecución, así que se documentan como ⚠️ VERIFICAR para una pasada de
portabilidad futura, no se tocaron (no era lo que se pidió esta vez).

### ✅ Sesión 2026-09-09 (continuación): 6 paredes más, cliente llega a red real y descarga con éxito

Sesión larga y autónoma, empujando desde el assert de `Cursor.java:212`
hasta el objetivo final (conexión de red real). Cada pared se investigó
con evidencia antes de tocarla, siguiendo el mismo criterio que las
sesiones anteriores. Commits en orden: `6c503ba`, `645c3d3`, `f563a6b`,
`4ffac8c`, `f1e53e1`, `618af6f`.

1. **`FastDataInput` mock "inteligente"** (retomado de la sesión previa,
   commiteado ahora) — contrato investigado a fondo antes de escribir nada:
   `implements DataInput`, todo el método surface son los primitivos de esa
   interfaz (sin seek/random-access en ningún lado), y
   `protocol/LibreWorlds-wiki-master/Persister-(.world-etc.)-format.md`
   (documentación de terceros, independiente) confirma que el formato en
   disco **es** el wire format de `java.io.DataInput`, no una aproximación.
   Implementado envolviendo un `DataInputStream` real. `NewWorld.world`
   confirmado presente en `assets/WorldsPlayer/` (no asumido — verificado
   con `find`) y cargó con éxito por primera vez.
2. **`Cursor.java:212`** — investigado: NO es una pared de portabilidad
   Windows como las anteriores. `defaultCursor = retrieveSystemCursor(...)`
   viene de `loadSystemCursor("IDC_ARROW")`, un `native` que devuelve un
   handle Win32 — la política genérica del mock (`int` → `0`) choca con la
   convención de este código de que `0` significa "falló". Mismo problema
   en `loadCursor()`. Fix: devolver `1` en vez de `0` para esos dos.
3. **Bug real del decompilador, no portabilidad**: `PosableShape.<clinit>`
   reventó con `ArrayIndexOutOfBoundsException: Index -128` — un contador
   de loop declarado `byte` desborda a los 127 elementos y sigue en
   negativo. Se buscó el mismo patrón (`for (byte `) en todo el árbol: **11
   apariciones en 8 archivos**, todas verificadas una por una (el contador
   solo se usa para indexar, nunca se guarda como `byte`) antes de
   arreglarlas todas en lote.
4. **Heurístico generalizado en `jni_mock.py`**: `Transform.scale(float,
   float,float)` (native, mockeado a `null`) se usa en cadenas fluidas
   (`var1.scale(x).raise(y)`) — el `null` rompe la SIGUIENTE llamada de la
   cadena, no esta, lo que lo hacía fácil de pasar por alto. Se generalizó
   la regla: cuando un `native` no estático devuelve exactamente el tipo de
   su propia clase, el mock devuelve `this` — verificado contra call sites
   reales antes de generalizar. 28 métodos afectados tras reaplicar.
5. **`IniFile` mock "inteligente"** — el hallazgo clave de la sesión:
   contrato pequeño (2 getters, 2 setters) sobre archivos con el formato
   INI clásico ya visto literalmente en `worlds.ini`/`override.ini` reales.
   Implementado con un parser INI real. **Esto reveló la razón real de por
   qué nunca se veía un intento de conexión**: `World.setWorldServerURL()`
   solo llama a `Console.load()` con una URL real si `this.isMultiuser` es
   `true`, y sin leer el `worlds.ini` real el cliente nunca podía ver
   `RestartAt=home:GroundZero/GroundZero.world` — siempre caía al
   `NewWorld.world` de un solo jugador, que no tiene servidor y por lo
   tanto nunca intenta conectar. No era un hueco del mock — era el mock
   anterior de `IniFile` (genérico, sin leer archivo real).
6. **DNS real en `DNSLookup.gethostbyname`** — contrato trivial (`String →
   String[]` de IPs), implementado con `InetAddress.getAllByName()` real.

**Resultado final, verificado con evidencia dura, no logs de texto**: con
`worlds.ini` real ahora leído, el cliente pide `upgradeServer=
http://us1.worlds.net/3DCDup` y bajo Xvfb **completa una descarga HTTP real
y exitosa**. `getent hosts us1.worlds.net` resuelve a una IP real y viva
(`172.237.126.108`, DNS inverso `file.libreworlds.org` — **no** el dominio
muerto que se asumía en la sección 1), y se inspeccionaron directamente los
archivos que el cliente escribió en su caché local tras la descarga:
`cachedir/1.dat` abre con la cabecera real de `actions.dat` ("VERSION 2 //
This file defines global actions that may be performed by avatars...");
otros dos archivos son listas reales de idiomas/fuentes con códigos de
locale (`ja_JP 210673`, `es_ES 208280`, etc.). **`us1.worlds.net` está vivo
y sirviendo contenido real** — aparentemente mantenido o reflejado por la
comunidad LibreWorlds, no simplemente muerto como se asumía.

El hilo principal del cliente completa su secuencia de arranque local y
llama a `System.exit(0)` en bien menos de un segundo — las descargas de
caché corren en hilos daemon asíncronos (`NetCacheThreads=2`) que no
alcanzan a reportar resultado por log antes de que la JVM termine, así que
no hay una línea explícita de "conexión exitosa" en
`docs/xvfb-runtime-trace.log` — pero los archivos reales en disco son
evidencia más fuerte que cualquier línea de log.

**Punto de parada de esta sesión** (según lo pedido): llegar más lejos
(un flujo de login explícito, esperar a los hilos de caché asíncronos)
exigiría tocar el control de flujo de `Gamma.java` o el modelo de hilos de
`Cache`/`NetUpdate` — código real de red/flujo del cliente, ya no un mock
de nativos ni un fix de portabilidad menor. Se para aquí para que el
usuario decida el siguiente paso.

### Direcciones de servidor por defecto (pregunta 4)

Sin necesitar que el cliente llegue más lejos, esto ya se puede sacar por
análisis estático + la config real que aportó el usuario:

- **`assets/WorldsPlayer/worlds.ini`** (la instalación real de 2026, tal
  como la dejó el usuario): `upgradeServer=http://us1.worlds.net/3DCDup`.
  ⚠️ **Actualización (2026-09-09): este subdominio concreto NO está muerto**
  — `us1.worlds.net` resuelve a una IP real y viva
  (`172.237.126.108`/`file.libreworlds.org`) y sirve contenido real y
  descargable (confirmado, no asumido — ver el bloque de esta sesión más
  abajo). La sección 1 sigue siendo correcta sobre los dominios apex
  `worlds.com`/`worlds.net` (página de aparcamiento), pero al menos este
  subdominio de infraestructura parece mantenido o reflejado por la
  comunidad LibreWorlds.
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

### ✅ Fase 1 (parser RWX) completa y Fase 2 (renderizador) arrancada (2026-09-09)

Sesión larga y autónoma. Resultado: **118/118 archivos `.rwx` reales del
proyecto parsean idéntico** (posición de vértices/triángulos) a
`three-rwx-loader` (la referencia JS), y hay una ventana LWJGL pintando esa
geometría en pantalla de verdad (evidencia en `docs/renders/`, no solo "no
crashea"). Todo el trabajo nuevo vive en `client/src/net/freeworlds/`
(paquete nuevo, deliberadamente separado de `NET.worlds.*` que es el
código decompilado original) y `tools/rwx-harness/`.

**Antes de escribir el parser**: se montó primero el arnés de comparación
(herramienta #3 de la sección 7) — `tools/rwx-harness/extract.mjs` corre
`three-rwx-loader` real (headless vía `jsdom`, instalado con npm, no
vendorizado) y `client/.../RwxExtractMain.java` corre el parser nuevo;
ambos emiten el mismo JSON canónico y `tools/rwx-harness/compare.py` los
diffea, escribiendo `docs/rwx-parser-progress.md` como fuente de verdad
real (no asumida) del estado archivo por archivo. Los 118 `.rwx` de
prueba son los reales del proyecto (`assets/GROUNDZERO/` +
`assets/WorldsPlayer/GroundZero/tex/`) — no se inventó contenido de
prueba.

**El propio arnés tuvo 2 bugs que causaron falsos positivos masivos**
antes de corregirse (documentados en `tools/rwx-harness/compare.py`):
confiar en el orden de cada lado ordenado por texto (JS escribe `"7e-05"`,
Java escribe `"7.0E-5"` — un simple sort lexicográfico los desincroniza en
silencio aunque el contenido sea idéntico) y ordenar con más precisión
que la tolerancia de comparación (float vs. double puede intercambiar dos
claves de sort adyacentes). Los dos se corrigieron reordenando con una
clave numérica calculada en Python. Antes de corregirlos, el marcador
mostraba solo 70/118 OK — la mayoría de esas "diferencias" no eran bugs
del parser en absoluto.

**Un subagente (fork) se lanzó primero para escribir
`docs/rwx-format-reference.md`** leyendo el código de `three-rwx-loader` —
se interrumpió a medio camino (se desvió construyendo el arnés en vez de
documentar, trabajo útil pero no el encargo) y nunca escribió el
documento. Se completó leyendo el código fuente directamente en el hilo
principal (la lógica del parser está explícitamente fuera de lo que se
delega, según las instrucciones de esta sesión).

**Hallazgos no obvios, verificados línea por línea contra el código
fuente real (no la wiki de Active Worlds, no suposiciones)** — ver
`docs/rwx-format-reference.md` para el detalle completo con número de
línea:
- `ModelBegin`/`ModelEnd` **no existen** para `three-rwx-loader` — ninguna
  regex los reconoce, son no-ops puros. Solo `ClumpBegin`/`ClumpEnd`
  importan.
- Los índices de vértice de `Triangle`/`Quad` son relativos a un buffer
  **por clump** que se limpia en `ClumpBegin` Y en `ClumpEnd` — no una
  lista global del archivo.
- `Transform` (16 valores) es un **set absoluto**, column-major (igual que
  `THREE.Matrix4`, `v'=M×v`) — no una multiplicación como
  `Translate`/`Scale`. La primera versión del parser usaba row-major con
  `v'=v×M` (convención contraria) y daba geometría sutilmente mal en
  archivos con transformaciones no triviales, sin ningún error — solo
  números ligeramente distintos. Lo detectó el arnés, no habría sido
  obvio a ojo.
- `ClumpBegin` congela la transformación acumulada como base del clump y
  **resetea el acumulador local a identidad**; `ClumpEnd` restaura el
  acumulador a lo que era justo antes del reset. El material tiene el
  mismo scoping (clon apilado/restaurado por clump).
- `Rotate x y z angle` **no es una rotación de eje arbitrario** — son
  hasta 3 rotaciones independientes por eje cardinal (X, Y, Z en ese
  orden), cada una solo si su coeficiente es no-cero, por
  `coeficiente × angle` grados. Muy fácil de malinterpretar (así lo
  implementé al principio, antes de leer el código).
- `Quad` corta por la diagonal más **corta**, no siempre A-C.
- **Comparar materiales/colores no es fiable en este entorno**: sin
  archivos de textura reales (el corpus solo tiene `.cmp`, no `.jpg`), la
  carga de textura falla y **contamina también el color base** — todos
  los triángulos salen gris plano `d8d8d8` en la referencia JS,
  independientemente de lo que declare el archivo. Con
  `setEnableTextures(false)` se evita la contaminación pero entonces el
  nombre de textura nunca se registra, y el hex de `THREE.Color` no
  coincide con una conversión directa `canal×255` (sospecha de
  conversión linear↔sRGB, fórmula exacta ⚠️ VERIFICAR, no identificada).
  **Decisión**: el material es una nota informativa en `compare.py`, no
  un criterio de OK/DIFERENCIAS — la geometría (100% verificable) es la
  comparación autoritativa.

**Sin implementar / ⚠️ VERIFICAR, no aparecen en el corpus de 118
archivos así que no se pudieron verificar empíricamente**: `Polygon`
(implementado con la reversión de orden documentada en el código fuente,
pero sin un archivo real que lo ejercite), `ProtoBegin`/`ProtoEnd`/
`ProtoInstance` (no implementado en absoluto), el caso especial de `Quad`
en modo wireframe y la corrección de normales inválidas de
`correctInvalidNormals`. `JointTransformBegin`/`JointTransformEnd`/
`IdentityJoint`/`Hints`/`AddHint` sí aparecen mucho en el corpus (72+40+336
veces) y están **verificados como no-ops reales** (tampoco los reconoce
`three-rwx-loader`).

**Renderizador (fase 2)**: `client/src/net/freeworlds/render/RwxViewer.java`
— ventana LWJGL/GLFW, pipeline de función fija (`glBegin`/`glVertex`, sin
shaders/VBOs todavía), color plano por triángulo desde el material
parseado (sin texturas ni luz), cámara que encuadra automáticamente según
el bounding box del modelo, auto-rotación lenta. Verificado con evidencia
real de píxeles (no solo "compila y no revienta"): se renderizó
`BASKET.RWX` y se inspeccionó el histograma de color del PNG resultante —
contiene exactamente los dos colores de material que declara el archivo
(`0x893232` cuerpo, `0x338d2d` asa), no solo el color de fondo.

**Detalle de entorno encontrado y arreglado**: esta máquina es una sesión
de escritorio Wayland real (`WAYLAND_DISPLAY` seteada) aunque se renderiza
contra un Xvfb X11 separado para pruebas — GLFW auto-detecta y prefiere
Wayland cuando ve esa variable, y falla directamente ahí (no hay
compositor real escuchando para este proceso). Arreglado con
`glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11)` explícito en el código,
en vez de depender de desactivar la variable de entorno en cada
invocación.

**Herramientas nuevas de esta sesión** (todas descargadas/instaladas
localmente, no requieren privilegios de sistema, todas gitignored):
`tools/node/` (Node.js portable v26.8.1, sin `apt`/`dnf`), `tools/lwjgl/`
(LWJGL 3.4.3 desde Maven Central — módulos `core`/`glfw`/`opengl` +
natives de Linux), `tools/rwx-harness/node_modules/` (`three-rwx-loader` +
`three` + `jsdom` vía npm).

**Commits de esta sesión**: `10840fe` (parser + arnés), `caf1ccb`
(renderizador).

**Siguiente paso lógico**: dos caminos razonables, a elegir con el
usuario — (a) seguir en fase 1 y encarar el parser binario RWG/BOD
(avatares articulados, más complejo, formato binario sin biblioteca de
referencia JS conocida — habría que documentarlo desde cero o buscar otra
referencia), o (b) profundizar la fase 2: texturas reales (cargar los
`.cmp`/`.bmp` del proyecto, no soportados por `three-rwx-loader` tampoco,
así que aquí sí haría falta documentar el formato `.cmp` desde cero),
iluminación básica difusa/ambiente/especular ya parseada y disponible en
`RwxMaterial`, y sustituir el pipeline de función fija por uno moderno
(shaders + VBOs) antes de que crezca más.

---

### 🟡 Regla de alcance permanente fijada (2026-09-09): réplica fiel, no mejora

El usuario fijó explícitamente, "de ahora en adelante y para siempre en
este proyecto" (ver sección 1): el objetivo es el juego ORIGINAL
decompilado y porteado — una réplica fiel, nada nuevo, nada mejorado.
RWG/BOD (avatares) SÍ están en alcance (eran parte del cliente original).
Texturas e iluminación deben verse EXACTAMENTE como el RenderWare 2
original (simple, sin filtrado moderno) — nunca shaders modernos, PBR, ni
ninguna mejora gráfica. **Regla dura permanente**: si en algún momento hay
duda entre "fidelidad necesaria" y "mejora fuera de alcance", PARAR y
preguntar al usuario — nunca decidir unilateralmente a favor de "más
bonito".

### 🟡 Parser RWG (avatares) — investigación desde bytes reales + implementación parcial (2026-09-09)

**Corpus real usado (no inventado)**: al empezar solo había 2 archivos
`.rwg` reales (`assets/FIRST/{AVATAR,IDLE}.RWG`, ambos degenerados —
AVATAR.RWG es una caja placeholder vacía con centinelas `Float.MAX_VALUE`,
IDLE.RWG un solo quad plano); a mitad de sesión aparecieron 3 más dentro
de `GammaDocs.zip` (aportado por el usuario, carpeta `GammaTutorial/tex/`
— movidos a `assets/gammatutorial-samples/` porque son datos binarios de
formato real, no documentación, así que sí están versionados a
diferencia del resto de GammaDocs): `cube.rwg` — un cubo real de 6 caras,
`ball.rwg` — una pelota de 512 triángulos, y `table.rwg` — una mesa de
546 polígonos mixtos. **Los 5 `.rwg` reales
tienen exactamente un solo joint/`ATOM` cada uno** (verificado
programáticamente) — ninguno es un avatar articulado de verdad, son
props/placeholders de un solo clump. La jerarquía real de huesos de un
avatar articulado (pelvis→torso→cuello→cabeza...) **sigue sin poder
verificarse con evidencia real** — límite honesto del corpus disponible,
documentado explícitamente en vez de inventado. Además hay 26 `.bod`
reales en `assets/WorldsPlayer/cachedir/` (avatares de verdad descargados
por red en una sesión anterior, confirmado vía `PendingDrone.java`) pero
usan una codificación binaria totalmente distinta (sin tags ASCII) que
**no se logró descifrar** esta sesión.

Con los 3 archivos nuevos, la hipótesis inicial de `PLST` (basada en un
único polígono de IDLE.RWG) **se rompió y se corrigió con evidencia
real**: `cube.rwg` reveló que cada polígono lleva una normal de cara
`(nx,ny,nz)` (los 6 ejes ±X/±Y/±Z aparecen exactamente una vez en las 6
caras del cubo — imposible que sea casualidad) y que los campos de
vértice antes marcados "sin determinar" son en realidad la normal por
vértice. El cubo y la pelota se renderizaron con éxito y se ven
correctos a simple vista (`docs/renders/{cube,ball}_rwg_3d.png`);
`table.rwg` quedó sin resolver porque mezcla triángulos y cuadriláteros
en el mismo `PLST`, rompiendo la asunción de tamaño de registro uniforme
— documentado como límite conocido, no forzado.

**Investigación externa**: confirmado que no existe ninguna biblioteca ni
documentación pública que describa este formato binario exacto —
`aw-sequence-parser` (Active Worlds) es un formato no relacionado (`.seq`
de animación, magic bytes distintos), y el "RenderWare Binary Stream"
estándar documentado (usado por GTA) es little-endian con IDs numéricos,
estructuralmente distinto del esquema de tags ASCII big-endian real
observado aquí. La fuente más valiosa fue `Gamma_Advanced.html`
(documentación oficial de Worlds Inc. aportada por el usuario esta
sesión como parte de `GammaDocs.zip` — ver sección 3.4 para los mirrors
públicos; el zip completo NO se versionó en el repo, ver nota de higiene
más abajo), que confirma la lista de nombres/números de tag de joints y
la convención de que las matrices de joint deben ser siempre identidad —
esto último coincide EXACTO con lo observado en bytes reales.

**Nota de higiene de repo (2026-09-09, post-sesión)**: el commit inicial
de esta sub-sesión (`e591395`) había copiado el `GammaDocs.zip` completo
al repo (127 archivos, 5.8MB) en vez de quedarse solo con lo citado
arriba. Se corrigió: el HTML completo se sacó del repo (queda solo local,
no versionado — los hechos citados aquí ya están parafraseados con
atribución, así que no hace falta el HTML para verificarlos; los mirrors
públicos de la sección 3.4 son la referencia si hiciera falta consultarlo
de nuevo), y los 4 archivos de corpus binario real que sí hacían falta
(`cube.rwg`, `ball.rwg`, `table.rwg`, `table.rwx`) se movieron a
`assets/gammatutorial-samples/`. El commit se separó en piezas más
pequeñas y revisables (parser / renderer+capturas / docs+corpus) — ver
`git log` para el detalle exacto en vez de duplicarlo aquí.

**Lo verificado e implementado** (`client/src/net/freeworlds/rwg/`,
`docs/rwg-bod-format-reference.md`): contenedor de chunks
`[tag ASCII][longitud big-endian=tamaño de payload][payload]` verificado
byte-exacto contra los 2 archivos reales; estructura `CLUM`→`ATOM`→
`MATX`(x2, identidad)+`VLST`(vértices)+`PLST`(polígonos); layout de
vértice de 44 bytes/11 floats con posición (alta confianza) y UV
(confianza media) identificados; un polígono real decodificado y
**renderizado con éxito** (`RwgViewer.java`, captura de pantalla real
verificada por píxeles) — en el proceso se descubrió que el orden de
índices de un quad es de rejilla (TL,TR,BL,BR), no de lazo perimetral (un
fan-triangulation ingenuo dio una forma cóncava incorrecta, corregido).

**Lo que queda ⚠️ VERIFICAR / sin resolver**: la mayoría de campos del
header de 52 bytes de `ATOM`; el propósito exacto de `RALT`/`TELT`/`MALT`
(aunque se encontró que `TELT` contiene un sub-chunk `STNG` con el nombre
del objeto como string); los campos 3-5 y 8-10 del vértice de 44 bytes;
si la jerarquía de múltiples joints anida `ATOM` dentro de `ATOM` o los
enumera como hermanos (sin evidencia real de ningún tipo); y el formato
`.bod` completo (solo se confirmó un prefijo mágico constante de 6 bytes).

**Siguiente paso lógico**: para desbloquear la jerarquía de joints y
`.bod` de verdad haría falta desensamblar con Ghidra la función de
`gamma.dll` que lee `.bod` (mismo nivel de esfuerzo que el mapeo de
métodos `native` de sesiones anteriores) — no es "seguir leyendo bytes
con más paciencia", el corpus real disponible se agotó. Alternativa más
barata: seguir buscando si existe algún archivo `.rwg`/`.bod` real con
más de un joint en otras copias del cliente o en la comunidad
(LibreWorlds/kangworlds) antes de invertir en desensamblado.

---

### 🟡 Higiene de repo (2026-09-09, entre sesiones): commits separados + push

Antes de continuar con el motor, se limpió el estado del repo (pedido
explícito del usuario, ver hallazgos completos en el bloque de "higiene
de repo" más arriba de esta misma sección): `cachedir/{.LOG,.lst,
cache.index}` dejados de trackear (ruido de bookkeeping de descargas, no
geometría — los `.bod`/`.seq`/`.mov`/`.cmp` reales SÍ siguen
versionados), `GammaDocs/` completo sacado del repo (127 archivos,
5.8MB, la mayoría nunca citados — solo se necesitaban 4 archivos de
corpus binario real, movidos a `assets/gammatutorial-samples/`, y el
texto de `Gamma_Advanced.html` ya estaba parafraseado con atribución en
`docs/`), y el commit original de la sesión RWG se separó en 3 piezas
revisables (parser / renderer+capturas / docs+corpus). Con `origin/main`
14 commits por detrás, se hizo push de todo (autenticación SSH
configurada por el usuario a mitad de sesión).

### 🟡 Motor de renderizado — texturas investigadas, iluminación y
### materiales implementados y verificados, escena multi-objeto (2026-09-09)

Regla de alcance reafirmada al empezar esta sesión, permanente para el
resto del proyecto: réplica fiel del pipeline fijo de RenderWare 2 — sin
shaders modernos, sin PBR, sin mejoras gráficas de ningún tipo. Todo lo
de abajo usa `glLight`/`glMaterial`/`glBegin`-`glEnd` (pipeline de
función fija real, no una reinterpretación moderna).

**1. Texturas `.cmp`/`.mov` ("ScapePic") — investigadas a fondo,
NO resueltas del todo, documentado el límite real**
(`docs/cmp-texture-format-reference.md`). Desensamblado real con Ghidra
(mismo binario `gamma.dll` de sesiones anteriores) hasta identificar que
el núcleo de compresión (función interna llamada literalmente
`huffdcod`) es estructuralmente idéntico, variable por variable, al
algoritmo público y bien documentado `make_table()` de la familia LHA/LZH
de Okumura/Yoshizaki — pero el bucle real que consume el bitstream
comprimido (la pieza que convertiría las tablas Huffman ya construidas
en píxeles reales) no se llegó a ubicar. Corroborado con investigación
externa: `github.com/vanjac/zoomscape-info` documenta el mismo header
`LzH2` y también lo marca como "unknown compression scheme" — nadie más
lo ha resuelto públicamente tampoco. Decisión de alcance: no forzar el
resto del desensamblado (esfuerzo del mismo orden que `.bod`) a costa del
resto de la sesión; el pipeline de materiales usa el color/opacidad de
material YA verificado, sin renderizar ninguna textura ni inventar
píxeles.

**2. Iluminación — modelo real encontrado en Java puro, sin necesitar
Ghidra**: `NET.worlds.scape.Room.java` tiene los valores por defecto
reales (`lightPosition = (-1,1,-1)`, `lightColor = blanco`) y
`RoomEnvironment.addLight()` confirma **exactamente 2 luces por sala**
— una "clave" y una "de relleno" en la dirección opuesta a mitad de
intensidad. Implementado en `GlLighting.java`, verificado con captura +
histograma de color: el color plano único de `BASKET.RWX` (sesión
anterior) ahora muestra ≥6 tonos reales según la orientación de cada
faceta (`docs/renders/basket_lit.png`).

**3. Pipeline de materiales — verificado con 2 archivos reales
distintos**: opacidad conectada a alpha blending real; `MaterialModes
Double` (hallazgo nuevo, uso real confirmado en
`assets/GROUNDZERO/YARD_TABLE.RWX`) conectado a culling de doble cara —
verificado visualmente: el envés de la mesa es visible desde abajo, algo
imposible sin doble cara activa (`docs/renders/table_lit.png`).

**4. RWG con iluminación**: usa la normal real por vértice ya parseada
del formato (no recalculada). Se encontró y corrigió un problema real de
datos (`cube.rwg`: los 8 vértices "planos" sin UV tienen normal
`(0,0,0)`, un valor de relleno que rompe `GL_NORMALIZE` — se añadió un
fallback a la normal de cara calculada). Queda ⚠️ un artefacto sin
resolver: 2 de las 6 caras del cubo muestran un patrón tipo z-fighting;
se probó activar backface culling como diagnóstico y empeoró (huecos),
confirmando que el sentido de bobinado no es consistente entre caras en
los datos reales — documentado, no forzado (`docs/render-pipeline-reference.md`).

**5. Escena multi-objeto** (paso 4, "si el tiempo lo permite" — sí
alcanzó): `RwxSceneViewer.java` carga y renderiza juntos 6 objetos reales
de `assets/GROUNDZERO/` (cesta, lata, botella, pinzas, cactus, parrilla),
en una rejilla dimensionada por sus propias cajas delimitadoras reales
— verificado por captura, los 6 se ven correctamente iluminados,
posicionados y sin solaparse (`docs/renders/scene_multi_object.png`).

**Commits de esta sesión**: `a3d801d` (investigación `.cmp`), `bcabf31`
(iluminación + materiales), `2aa35c0` (escena multi-objeto), más 4
commits de higiene de repo antes de empezar (`f66f9dc`, `de059b0`,
`7066c30`, `b3c4608`). Todo empujado a `origin/main`.

**Siguiente paso lógico**: dos caminos razonables — (a) retomar RWG/BOD
multi-joint o el resto del descompresor `.cmp` (ambos necesitan
desensamblado dedicado con Ghidra, mismo orden de esfuerzo), o (b)
seguir profundizando el motor: sustituir el pipeline de función fija por
VBOs/shaders **que repliquen exactamente** el mismo resultado visual (una
optimización de rendimiento, no una mejora gráfica — dentro de alcance
si se hace con cuidado), resolver el artefacto de winding de RWG, o
intentar cargar una escena desde un `.world` real en vez de archivos
`.rwx` sueltos.

---

### 🟡 `.cmp`/`.mov` — bucle de descompresión localizado con precisión,
### aún sin claridad suficiente para implementar (2026-09-09, sesión 2)

Retomada exactamente donde quedó la sesión anterior (regla de alcance
reafirmada: los píxeles descomprimidos deben verse EXACTAMENTE como el
original, sin filtrado/upscaling — no aplica todavía porque no hay
píxeles reales que mostrar, ver abajo). Se volvió a `gamma.dll` con
Ghidra y se llegó mucho más lejos que la sesión anterior:

- **Función exacta localizada**: `FUN_00442bc0` (= `getScanline(fila,
  bufferDestino, stride)`) llama a `FUN_00426af0` (decodificador Huffman
  a nivel de bit, patrón clásico `decode_c()` de LHA) y luego a
  `FUN_00457d88` — esta última SÍ es la función que reconstruye píxeles
  de verdad, la pieza que faltaba la sesión anterior.
- **Formato de píxel confirmado con evidencia real**: 8 bits por píxel,
  paleta indexada, filas alineadas a 4 bytes, escritura con stride
  negativo (bottom-up, típico de un `HBITMAP`/DIB de Windows — coincide
  con el uso real de `CreateCompatibleDC`/`HBITMAP` ya visto en sesiones
  anteriores).
- **Tabla de predictores 2D extraída directamente del binario**
  (`docs/gamma-dll-cmp-evidence/predictor-offset-tables.txt`, ~50 pares
  reales `(desplazamiento_fila, desplazamiento_columna)`): revela que el
  algoritmo es un **predictor causal 2D** (cada símbolo Huffman
  selecciona un vecino ya decodificado y copia su valor — más parecido a
  los filtros de PNG/JPEG-LS) y NO LZSS de ventana genérica como se había
  supuesto la sesión anterior — corrección real basada en evidencia, no
  solo una hipótesis inicial confirmada.
- **Los 256 punteros de función indirectos que parecían sugerir 256
  rutinas complejas distintas resultaron ser triviales** una vez
  desensamblados: cada uno solo reordena/replica un byte en distintas
  posiciones de registro — el truco manual de los 90 para rellenar
  tramos de píxeles repetidos 4 bytes a la vez. Sin complejidad
  algorítmica real ahí.

**No se implementó el decoder**: la aritmética de acarreo exacta
(`CARRY4`) y el propósito de la escritura simultánea de dos filas dentro
de `FUN_00457d88` no se terminaron de entender con la claridad necesaria
para traducir bit a bit con confianza. Siguiendo la instrucción explícita
del usuario de no forzar una implementación a medias ni arriesgar píxeles
inventados con apariencia plausible pero incorrecta, se paró aquí y se
documentó todo con evidencia real (`docs/cmp-texture-format-reference.md`,
sección "Sesión 2"). Los pasos 3-5 del plan de esta sesión (implementar,
verificar contra un `.cmp` real, conectar con el pipeline de materiales)
no se alcanzaron como consecuencia directa de esta decisión honesta, no
por falta de esfuerzo — se hicieron 3 rondas de desensamblado con Ghidra
esta sesión (bucle final, tabla de predictores, tabla de 256 punteros).

**Siguiente paso lógico**: trazar la ejecución de `FUN_00457d88` paso a
paso con un depurador contra `gamma.dll` corriendo bajo Wine (en vez de
solo leer pseudocódigo estático de Ghidra) para resolver la ambigüedad
de bits/doble fila; una vez claro, la implementación en Java del
predictor causal 2D ya identificado debería ser relativamente directa.

---

### 🟢 `.world` — parser completo, conectado al motor, escena real
### renderizada (2026-09-09)

Sesión con el mismo espíritu que RWX/RWG: buscar el archivo real primero
(confirmado: `GroundZero.world`, 205.759 bytes, 3 copias idénticas,
mundo por defecto según `worlds.ini`), investigar el formato con la
mejor evidencia disponible, implementar, y verificar con datos reales —
en este caso con una ventaja enorme sobre RWX/RWG/`.cmp`: **el propio
mecanismo de serialización SÍ está completo en el Java decompilado**, no
hace falta tocar nada nativo.

- **Formato investigado y documentado** (`docs/world-format-reference.md`):
  no es un binario ad-hoc, es el protocolo genérico "Persister" del
  cliente (`Saver`/`Restorer`), verificado byte a byte contra la
  cabecera real (`"PERSISTER Worlds, Inc."` + versión 7) y contra ~30
  clases reales del código fuente (`SuperRoot`, `Transform`, `WObject`,
  `Shape`, `Room`, `RoomEnvironment`, `Rect`, `Portal`, `Material`,
  `Point3`, más las familias `Action`/`Sensor`). Posición/rotación/escala
  de cada objeto se guardan como una matriz 4×4 completa de 16 floats
  (el "guts" nativo de RenderWare), reutilizando directamente la
  infraestructura de matrices ya existente de RWX.
- **Parser implementado y verificado end-to-end**
  (`client/src/net/freeworlds/world/WorldRestorer.java`): parsea el
  archivo real completo, sin errores, hasta el marcador real
  `END PERSISTER` — 25 salas, 578 nodos, 103 objetos con geometría real
  (50 archivos `.rwx`/`.rwg` únicos, todos verificados contra archivos
  reales en disco). Se encontraron y corrigieron 4 bugs reales durante
  la implementación (documentados con evidencia byte a byte en el doc):
  la distinción entre `Material.restore()` (con booleano previo) y un
  `var1.restore()` directo (sin él) mal aplicada en 3 sitios distintos;
  `WObject` apareciendo como clase concreta instanciable, no solo como
  superclase; y la cadena de herencia de `SendURLAction`/`DialogAction`
  invertida.
- **Conectado al motor de renderizado**
  (`client/src/net/freeworlds/render/WorldViewer.java`): carga una sala
  real, resuelve las URLs de geometría contra archivos reales en disco,
  y dibuja el árbol completo con el pipeline de iluminación/materiales
  ya existente. **Hallazgo real crítico**: la matriz de 16 floats leída
  del archivo no es una matriz afín válida tal cual — su float número 16
  (que debería ser 1.0 siempre) vale literalmente 0.0 en todos los
  objetos reales inspeccionados, colapsando la coordenada homogénea y
  dejando la pantalla completamente negra pese a que la geometría se
  enviaba a OpenGL sin errores. Diagnosticado por eliminación metódica
  (se descartaron iluminación, culling y precisión de profundidad antes
  de encontrar la causa real proyectando un vértice a mano en Python) y
  corregido forzando ese valor a 1.0.
- **Verificado con evidencia visual real**: `Reception` muestra un
  hexágono limpio y reconocible (el panel de techo real
  `hubceil1c.rwx`) más los bordes delgados de `frame.rwx` (ya verificado
  por separado que es geometría genuinamente delgada, no un error);
  `IconViewRoom1` muestra una fila de postes decorativos correctamente
  espaciados, sin superposiciones absurdas — capturas en
  `docs/renders/world_*.png`.
- **Rendimiento**: 7148 triángulos / 56 objetos en modo inmediato
  (`glBegin`/`glVertex`, sin VBOs) renderizan en una fracción trivial de
  los ~4 segundos totales de ejecución (dominados por arranque de
  JVM/GLFW/X11 y carga de 28 archivos RWX, no por el dibujo en sí) — no
  hace falta optimizar a esta escala.

### ✅ Sesión 2 (2026-09-09): el bug del bloque 3×3 resuelto — no era la
### convención, eran bytes de relleno sin inicializar

La sala compleja (`ReceptionView1`) que quedó rota al final de la
sesión anterior se investigó volviendo al código Java real (no
adivinando convenciones matemáticas). Dos hallazgos en
`Transform.java` que antes no se habían mirado:
`Transform.printGuts()` (un método de depuración real, no nativo)
confirma almacenamiento **row-major** (`índice = fila×4+columna`);
`Transform.worldVecToObjectVec()` usa `punto.vectorTimes(matriz)` —
confirma que el vector se multiplica a la izquierda (`v' = v·M`, no
`v' = M·v`). Con esa evidencia, la deducción matemática muestra que
**no hace falta transponer nada** para pasar los 16 floats crudos a
`glMultMatrixf` — lo cual explica por qué transponer (sesión anterior)
empeoró las cosas: aplicaba la convención equivocada.

La causa real de `ReceptionView1` resultó ser otra: los índices 3, 7 y
11 de la matriz (que en cualquier matriz afín válida deben ser
siempre `0.0`) contenían basura numérica consistente por objeto (no
ruido aleatorio — un objeto compartido entre `Reception` y
`ReceptionView1` mostraba exactamente los mismos valores basura en
ambas salas). Un escaneo automático confirmó por qué unas salas se
veían bien y otra no: `IconViewRoom1` tenía 0 objetos afectados,
`Reception` 1 (pequeño, casi invisible), `ReceptionView1` más de 15.
Interpretación más plausible: el "guts" nativo de RenderWare es en
realidad una matriz afín compacta de 4×3, ampliada a 16 floats para el
formato de guardado Java, con la columna de relleno serializada
directamente desde memoria nativa sin inicializar — el renderizador
real nunca la leía. Arreglo: forzar también esos 3 índices a `0.0`
(sumado al índice 15→`1.0` ya corregido antes).

**Verificado antes/después en las 3 salas** (`docs/renders/world_*_fixed.png`):
`IconViewRoom1` queda idéntico (el arreglo es quirúrgico); `Reception`
gana un objeto pequeño correctamente posicionado que antes tenía datos
basura; `ReceptionView1` pasa de triángulos gigantes degenerados a
objetos reales reconocibles — y verificado con datos, no solo
visualmente: las posiciones mundiales de los 56 objetos tienen sentido
geográfico real (mobiliario de picnic agrupado, cactus/rocas dispersos,
un camino, paredes de un edificio) en una zona exterior genuinamente
extensa, no un artefacto.

**Siguiente paso lógico**: retomar `.cmp`/RWG multi-joint, que siguen
pendientes de sesiones anteriores; o seguir explorando más salas del
`.world` real para ver si aparece algún otro caso no cubierto por estos
dos arreglos de matriz.

---

## 5. Roadmap por fases

**Orden de módulos: networking → renderer → UI**

| Fase | Contenido | Dificultad | Tiempo estimado |
|---|---|---|---|
| 0 — Reconocimiento | Decompilar con `worldsplayer_source_editor`, `grep -r "native"` para mapear todos los métodos nativos, identificar DLLs cargadas | 🟢 Baja-media | 1–3 semanas |
| 1 — Parsers de formato | ✅ **RWX (estático) HECHO (2026-09-09)** — 118/118 archivos reales verificados contra `three-rwx-loader`, ver sección 4. 🟡 **RWG parcial (2026-09-09)** — parser Java del contenedor de chunks y de un único ATOM (posición/UV de vértices + polígonos) verificado contra los 2 únicos `.rwg` reales disponibles y renderizado; jerarquía real de múltiples joints **NO verificada** (el corpus real no la demuestra) y `.bod` (formato binario de red, usado por los 26 avatares reales en caché) sigue sin descifrar — ver `docs/rwg-bod-format-reference.md`. ✅ **`.world` HECHO (2026-09-09)** — parser completo del protocolo de persistencia del cliente, verificado end-to-end contra un archivo real de 205KB (25 salas, 578 nodos, 103 objetos con geometría real) — ver `docs/world-format-reference.md` | 🟡 RWX fácil / RWG-BOD medio-alto (sin corpus real suficiente) / `.world` fácil (Java puro, sin nativo) | 2–6 semanas |
| 2 — Renderizador | 🟡 **Profundizado (2026-09-09)** — iluminación (2 luces, verificada en Java real) y pipeline de materiales (opacidad, doble cara) implementados y verificados por píxel/histograma sobre pipeline de función fija; escena multi-objeto probada. Texturas `.cmp`: bucle de descompresión localizado con precisión (función exacta, formato de píxel, tabla de predictores 2D reales extraída del binario) pero el decoder de píxeles sigue sin completarse — requiere depuración paso a paso, no solo lectura estática — ver `docs/cmp-texture-format-reference.md` y `docs/render-pipeline-reference.md` | 🔴 Alta (sin SDK de RW2 al que recurrir; `.cmp` requiere depuración dedicada) | 2–6 meses |
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
4. ✅ **HECHO Y EXTENDIDO (2026-09-09)** — **Bridge JNI "mock"** — stub que
   implementa los métodos `native` con logging en vez de lógica real, para
   poder arrancar el cliente y probar networking/UI sin esperar a tener el
   renderizador completo. Extendido con mocks "inteligentes" con I/O real
   para `FastDataInput` (lectura binaria de disco), `IniFile` (lectura real
   de `.ini`) y `DNSLookup` (DNS real) — el cliente llegó a completar una
   descarga de red real y exitosa. Ver sección 4 para el detalle completo
   y todas las paredes encontradas por el camino (headless/AWT,
   `libnet.so`, rutas Windows, handles nativos, bug del decompilador,
   builders fluidos).
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
- ✅ **RESUELTO (2026-09-09)**: probado con Xvfb, la asunción de ruta
  Windows de `URL.java` portada, y **el objetivo final se alcanzó y se
  superó**: con los mocks "inteligentes" de `FastDataInput`/`IniFile`/
  `DNSLookup` (sección 4), el cliente lee la config real, resuelve DNS de
  verdad, y **descarga contenido real con éxito** desde
  `us1.worlds.net` — que además resultó estar vivo (aparentemente
  mantenido por LibreWorlds), no muerto como se asumía. Ver la sección 4
  ("Sesión 2026-09-09 (continuación)") para las 6 paredes encontradas y el
  detalle completo de la evidencia.
- **Nuevo (2026-09-09)**: llegar más lejos (login explícito, ver el
  resultado de las descargas de caché asíncronas en vivo) exige tocar el
  control de flujo de `Gamma.java` o el modelo de hilos de
  `Cache`/`NetUpdate` — ya no es un mock de nativos ni portabilidad menor.
  Es la decisión que le toca al usuario para la próxima sesión: ¿seguir
  empujando el cliente mockeado más adentro del flujo de red/login, o
  pivotar hacia el parser RWX (fase 1 del roadmap, sección 5) ahora que el
  reconocimiento del terreno (nativos, portabilidad, arranque) está
  esencialmente completo?
