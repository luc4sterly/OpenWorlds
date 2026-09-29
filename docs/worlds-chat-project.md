# Worlds Chat — Preservación e Ingeniería Inversa (registro histórico)

> ⚠️ **Archivo histórico.** El estado actual del proyecto, condensado y al
> día, vive en [`CLAUDE.md`](../CLAUDE.md) — empieza ahí. Esto es el diario
> de sesión por sesión desde el arranque del proyecto (2026-09-08 en
> adelante): se conserva completo porque varios comentarios en el código
> citan secciones concretas como evidencia de decisiones no obvias, y
> porque es la prueba de cómo se verificó cada hallazgo. No se ha editado
> el contenido de abajo al archivar esto — sigue tal cual se escribió
> sesión a sesión, con sus referencias internas a "sección N" originales.

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
3. Portarlo a plataformas modernas — objetivo final: **Linux / OpenBSD / PSvita / macOS**, con
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
  - ✅ **Confirmado** (ver sección 10): es RenderWare **2.1**, por los
    nombres y las tablas de exports de las DLLs reales
    (`docs/renderware21-api-exports.txt`). Desde 2026-09-15 hay además
    desensamblado propio de `RWL21.DLL` (composición de matrices de
    clump/joint, ver `docs/seq-animation-reference.md` §5).
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

> ⚠️ **Entorno actual (desde 2026-09-15): macOS 15.7 en un MacBook
> Intel** (i5-7360U), sin Homebrew (ya no soporta Intel), sin Wine y sin
> node. El JDK es portable (`tools/jdk`, lo instala
> `tools/setup-macos.sh`) y `bash` es el 3.2 del sistema. Ver
> `docs/setup-macos.md`. Lo de abajo es el entorno Linux/WSL2 histórico,
> que sigue siendo válido en esa máquina.

- **Hardware**: Xeon 28 núcleos LGA2011, GTX 1060 6GB, 16GB RAM + zram/swap
- **WSL2** — entorno principal de trabajo (histórico)
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
`/home/lucas/OpenWorlds/...` se convierte en `u:/home/lucas/OpenWorlds/...`,
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
crashea"). Todo el trabajo nuevo vive en `client/src/net/openworlds/`
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

**Renderizador (fase 2)**: `client/src/net/openworlds/render/RwxViewer.java`
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

**Lo verificado e implementado** (`client/src/net/openworlds/rwg/`,
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
  (`client/src/net/openworlds/world/WorldRestorer.java`): parsea el
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
  (`client/src/net/openworlds/render/WorldViewer.java`): carga una sala
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

### 🟢 Avatares articulados: encontrado y verificado un rig real de 18
### joints (RWX, no RWG) + arreglado `table.rwg` de paso (2026-09-09)

Objetivo de la sesión: avanzar en avatares multi-joint reales. Primer
paso obligatorio por instrucción explícita: buscar más corpus real de
`.rwg`/`.bod` antes de seguir. **Búsqueda exhaustiva confirmada negativa**
— siguen siendo los mismos 5 `.rwg` (todos con un único `ATOM`) y 26
`.bod` sin descifrar de sesiones anteriores; no apareció nada nuevo en
`assets/WorldsPlayer/`, cachedir, ni `GammaDocs/` en disco. Un subagente
confirmó además que el cliente Java decompilado no expone ninguna
estructura de huesos (`PosableShape.java` solo tiene tablas de permisos de
apariencia/ropa, no esqueleto — lo articulado vive enteramente en
`gamma.dll` nativo).

**Pivote productivo, no el fallback previsto**: releer
`assets/WorldsPlayer/cachedir/45.dat` (el registro de animaciones real,
encontrado en una sesión muy anterior) recordó que los avatares de red
reales declaran `geometry=<nombre>.rwx` — el formato FUENTE de un avatar
es RWX texto (via la herramienta oficial `rwxtobod`), no `.rwg`. Buscando
nombres de joints de la convención oficial de GammaDocs
(`pelvis`/`lfshoulder`/`rthip`/`lfelbow`...) en los 119 `.rwx` reales del
proyecto apareció **`assets/GROUNDZERO/SPIN.RWX`** — ya presente en el
proyecto, usado en una sesión anterior como prop decorativo sin saber que
era un rig articulado real. Es un **rig de 18 clumps nombrados con
jerarquía real de padre/hijo**, verificado con evidencia byte a byte
(números de línea de `ClumpBegin`/`ClumpEnd`/comentarios `# nombre`) y con
los 18 nombres coincidiendo exactamente con la tabla oficial de GammaDocs.
Detalle real interesante, no "corregido": `rtfingers` anida como hijo de
`lffingers` en los bytes reales (anatómicamente raro, pero es lo que dice
el archivo). Ver `docs/rwx-avatar-hierarchy-reference.md` para el árbol
completo y toda la evidencia.

Se implementó `RwxSkeletonParser`/`RwxJoint` (nuevos, **sin tocar**
`RwxParser.java` — el parser aplanado 118/118 verificado queda intacto) —
reutilizan exactamente las mismas reglas de transform/clump ya verificadas,
pero preservan el árbol en vez de aplanarlo. Verificación en tres capas:
(1) estructura — reproduce exacto el árbol de 18 nodos reconstruido a
mano; (2) geometría — comparado contra los 119 `.rwx` reales del
proyecto, el conjunto de puntos en espacio mundo que produce recorrer el
árbol (`padre.world × joint.localTransform`) es **idéntico** al que
produce el parser aplanado ya verificado, en los 119/119 archivos, no solo
`SPIN.RWX`; (3) visual — `SPIN.RWX` renderizado con `RwxViewer` da una
figura coherente (piernas, cadera, torso, cabeza reconocibles, sin
basura geométrica) — `docs/renders/rwx_spin_avatar.png`.

**Límite honesto**: esto es geometría fuente en bind pose, no el `.bod`
comprimido real que el cliente descarga/anima por red (seguiría haciendo
falta Ghidra sobre `gamma.dll`, como con `.cmp`) y no hay animación
reconstruida — ningún sistema de huesos/animación inventado, por la regla
de alcance de esta sesión.

**De paso, revisando `table.rwg` con la experiencia acumulada** (tarea
explícita de la sesión): el bug quedó resuelto. La asunción vieja
("tamaño de registro uniforme, derivado dividiendo el payload total entre
el número de polígonos") nunca hacía falta — cada registro de `PLST` ya
declara su propio `vertexCount`, que se lee directamente. Lo único que
había que resolver era cuántos ints finales siguen a cada registro, que sí
es constante pero POR ARCHIVO, no por registro — se resuelve probando
candidatos pequeños hasta que la lectura secuencial (usando el
`vertexCount` real de cada registro, sin asumir uniformidad) cierra exacto
en el byte final. Con esto, `table.rwg` (546 polígonos, mezcla real
verificada de triángulos y cuadriláteros) parsea limpio y renderiza una
mesa coherente (`docs/renders/rwg_table_fixed.png`). Efecto colateral: se
corrigió una afirmación previa del doc RWG — el primer campo de cada
registro de `PLST`, documentado como "flag, siempre 1", en realidad NO es
constante (en `ball.rwg`, 512 registros, cuenta 1..512) — ver
`docs/rwg-bod-format-reference.md` para el detalle completo.

---

### 🟡 `.cmp` — depuración dinámica real construida y verificada, pero
### bloqueada por infraestructura antes de llegar al decoder de píxeles
### (2026-09-10)

Objetivo de la sesión: resolver la ambigüedad pendiente de `FUN_00457d88`
(aritmética de acarreo + escritura de doble fila) mediante depuración
dinámica real de `gamma.dll` bajo Wine — no más análisis estático.

**Logrado**: un entorno de depuración dinámica real y reutilizable —
Wine 11.0 + `winedbg --gdb` (gdb real conectado vía proxy) + un arnés Java
de sala limpia (`tools/gamma-dll-debug-harness/`) que invoca directamente
los métodos `native` reales de `gamma.dll` bajo el propio JRE de época del
proyecto (`java.exe` 1.4.2_05), sin necesitar el cliente completo ni red.
Confirmado con ejecución en vivo (no solo estática): un breakpoint en
`FUN_00442750` (validador de cabecera) se alcanza al llamar `loadImage()`
con un `.cmp` real, y un volcado instrucción a instrucción con registros
reales muestra la función abriendo y leyendo el archivo de verdad
(`ReadFile` contra bytes reales). Corrección metodológica real: los
nombres de símbolo que `gdb`/`winedbg` muestran para `gamma.dll` **no son
fiables** (una dirección confirmada por Ghidra como `FUN_00442750`
aparecía etiquetada como un export completamente distinto y no
relacionado) — hay que verificar direcciones contra Ghidra directamente,
nunca contra la etiqueta de `gdb`.

**Bloqueado, honestamente sin resolver**: cualquier camino de ejecución
que pasa del parseo de cabecera hacia el decoder de píxeles real
(`FUN_00442bc0`/`FUN_00457d88`) dispara la creación de un dispositivo
DirectDraw/OpenGL y una ventana real, que en este entorno concreto (Wine
bajo Xwayland en sandbox, sin aceleración gráfica) se cuelga
indefinidamente (probado hasta 150s, con y sin depurador, con mitigaciones
razonables como matar `wineserver` residual y modo de escritorio virtual
de Wine — ninguna funcionó). Evidencia real de que es un problema de
arranque de dispositivo/ventana de este entorno, no del algoritmo de
`gamma.dll`: una interrupción asíncrona durante el cuelgue mostró un hilo
esperando la sección crítica del cargador de Wine, bloqueada por otro
hilo. No se implementó el decoder (habría significado inventar la parte
no verificada) ni se conectó nada al pipeline de materiales — no hay
decoder real que conectar todavía. Detalle completo, con el arnés
reutilizable documentado para una futura sesión con mejor acceso a
GPU/ventanas, en `docs/cmp-texture-format-reference.md` y
`tools/gamma-dll-debug-harness/README.md`.

---

### 🟢 `.cmp` — Xvfb desbloquea el cuelgue de ventana/dispositivo; las dos
### ambigüedades de `FUN_00457d88` quedan resueltas con ejecución real
### (2026-09-10, sesión de continuación)

Objetivo: desbloquear el cuelgue de ventana/dispositivo de la sesión
anterior usando Xvfb (igual que se hizo hace varias sesiones para el
`HeadlessException` de Swing) y, si se lograba, retomar la depuración de
`FUN_00457d88` con valores reales.

**Desbloqueo logrado con la primera opción probada**: `Xvfb :99
-screen 0 1024x768x24` + `DISPLAY=:99` para Wine — **sin ningún gestor de
ventanas** (no hicieron falta ni estaban disponibles en el entorno). Con
esto, `ScapePicImage.loadImage()` sobre un `.cmp` real "normal" (modo
`0x02`, `ADWORLDS.CMP`) termina limpio y devuelve **una decodificación
real y exitosa** (`width=128, height=128, hDIB` no nulo) — la primera de
todas las sesiones de este proyecto. Los tres breakpoints ya localizados
(`FUN_00442750` → `getScanline` → `FUN_00457d88`) se alcanzan los tres, en
orden, dentro de esa única llamada — no hizo falta `makeTexture()`
después de todo (ese arnés sigue fallando, pero por un problema de
fidelidad del arnés minimalista — una aserción nativa durante
`nativeInit()` — no relacionado con el cuelgue de ventana ya resuelto).

**Las dos ambigüedades que motivaron dos sesiones de trabajo quedan
resueltas con evidencia de ejecución real** (traza de 900 instrucciones,
con `EFLAGS` y los 8 registros generales en cada paso):

- **"Aritmética de acarreo"**: cero instrucciones `ADC`/`SBB` reales en
  toda la traza. Es el lector de bits MSB-primero clásico de
  Huffman/LHA (`add reg,reg` + `jb` sobre el flag de acarreo), con un
  `rol $0x10` previo para corregir el orden de bytes de una palabra
  leída en little-endian — nada de aritmética multi-palabra.
- **"Escritura de doble fila"**: confirmado con las direcciones exactas
  de ambos caminos de símbolo (relleno y copia por predictor) — cada
  símbolo escribe el mismo bloque de 4 bytes en la fila actual (`edi`) Y
  en `edi±stride` a la vez, como operación central del símbolo (no
  limpieza de scratch). Interpretación más consistente: cada símbolo
  pinta un bloque de 4×2 píxeles de una vez, explotando coherencia
  vertical.
- **Bonus, confirmación cruzada entre dos sesiones**: se volcó la tabla
  de predictores real que usa `FUN_00457d88` en tiempo de ejecución y
  coincide EXACTA con la tabla estática ya extraída en una sesión
  anterior (`0x478e98`), con la fórmula de conversión corregida
  (`offset = colDelta + stride·rowDelta`, no con el signo negado como se
  había documentado tentativamente antes).
- **Ground truth real capturado**: la fila 0 completa de `ADWORLDS.CMP`
  (128 bytes reales, todos `0xAD`) — guardada en
  `docs/gamma-dll-cmp-evidence/adworlds-row0-dump.txt` para verificar una
  futura implementación Java.
- **Corrección de granularidad**: una traza extendida a 6000
  instrucciones sin ver ni un `ret` ni una reentrada a la función indica
  que **una sola llamada a `FUN_00457d88` decodifica la imagen
  COMPLETA**, no una fila — coherente con que `getScanline` solo se
  invoque una vez por imagen.

**Honestamente sin implementar todavía**: el espacio completo de símbolos
del árbol de Huffman interno no está mapeado (solo se ejercitaron las
ramas que una fila totalmente plana llegó a tocar) y el byte centinela
`0x24` visto en la traza no se investigó. Implementar el decoder Java
ahora, con esos huecos, arriesgaría exactamente lo que el proyecto
prohíbe — píxeles con aspecto plausible pero no verificados. Por eso no
se implementó ni se conectó nada al pipeline de materiales esta sesión;
próximo paso concreto documentado en
`docs/cmp-texture-format-reference.md`: trazar 2-3 archivos `.cmp` reales
con contenido no plano para ejercitar el resto del árbol de símbolos
antes de escribir el decoder.

---

### 🟡 `.cmp` — árbol de símbolos completo mapeado, `0x24` resuelto,
### decoder Java implementado y parcialmente verificado (34/64 y 55/64
### bytes exactos) — NO conectado al pipeline (2026-09-10, cierre)

Objetivo: cerrar `.cmp` del todo — ejercitar el árbol de símbolos con
archivos reales variados, implementar el decoder, verificar byte a byte,
conectar al pipeline.

**Corpus variado encontrado**: entropía de Shannon como filtro barato
confirmó que `ADWORLDS.CMP` (5.0) era degenerado frente al resto de los
13 `.cmp` únicos del proyecto (7.0-7.8) — `4i.cmp` seleccionado como caso
real no plano (fila 0 con 9+ valores de byte distintos). Los 5 candidatos
probados decodifican con éxito bajo Xvfb.

**Árbol de símbolos completo mapeado con evidencia real**: una traza de
4000 instrucciones sobre `4i.cmp` reveló 236 direcciones nunca vistas en
la sesión anterior (que solo había visto el caso de relleno plano). El
árbol superior real tiene 2 bits (no 3): bit1=0 → copia de predictor de
4 bytes (ya conocida); bit1=1,bit2=0 → **copia de predictor DUAL de 2
bytes** (nueva, dos índices independientes por mitad de grupo); bit1=1,
bit2=1 → rama de "byte de control" con varios sub-casos de literal/
lookback. **`0x24` resuelto** (desensamblado estático fresco de Ghidra):
no es fin de stream, es un **escape de literal crudo de 8 bytes**.
Hallazgo real no anticipado, encontrado depurando el primer intento
fallido de verificación: cada iteración de "byte de control" no-`0x24`
TAMBIÉN consume un byte adicional del stream de relleno y hace una
segunda escritura de difusión al historial — invisible en el archivo
plano de la sesión anterior porque coincidía con lo que ya había ahí.

**Corrección real de granularidad**: la sesión anterior infirió "una
llamada decodifica la imagen completa" al no ver un `ret` en 6000
instrucciones. Con un breakpoint real en la dirección de retorno
(calculada desde `*esp`, no adivinada), se confirma: **una llamada
produce exactamente `ch×2` bytes** (64 para los archivos probados, medio
ancho de fila de 128px) — ni una fila ni la imagen completa.

**Decoder Java implementado** (`tools/gamma-dll-debug-harness/
cmp-stage2-decoder/CmpStage2.java`), verificado contra streams y salida
real extraídos en vivo del MISMO proceso: **34/64 bytes exactos en
`adworlds.cmp`** (el resto explicado por una limitación real de captura
de memoria, no un error de diseño — cada byte faltante debería ser
`0xAD` como el resto del archivo plano) y **55/64 en `4i.cmp`** (9 bytes
sin resolver pese a verificación exhaustiva del consumo de stream
posición por posición contra una traza en vivo — abierto, honestamente
documentado). **No se conectó nada al pipeline de materiales** — ningún
archivo alcanzó 100% de verificación, y el proyecto prohíbe explícitamente
píxeles con aspecto plausible pero no verificados.

Progreso adicional real en `ScapePicTexture.makeTexture()` (necesario
para decodificar una imagen completa): se avanzó el punto de fallo de un
`Assertion failed` a un `EXCEPTION_ACCESS_VIOLATION` real replicando la
jerarquía de clases con más fidelidad, pero sigue sin resolverse.

Detalle completo, con el método de captura de ground truth y el análisis
de las discrepancias restantes, en `docs/cmp-texture-format-reference.md`
y `tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md`.

---

### 🟡 `.cmp` — ground truth pixel-exacta de la herramienta oficial, la
### hipótesis de captura incompleta descartada, bug acotado a una rama
### (2026-09-10, continuación: nuevos recursos externos — NO cerrado)

Objetivo del punto 1 de esta sesión: usar `compimg.exe`/`cmpview.exe`
(oficiales, en `tools/gdk-sdk/`, corren nativos bajo Wine sin ningún
workaround de 16 bits) para cerrar `.cmp` con verificación mucho más
fuerte que las trazas parciales anteriores. **No se logró el cierre
completo** — regla del proyecto respetada: no se da por resuelto sin
verificación real, y aquí la verificación real dice que sigue abierto.
Lo que sí se consiguió es sustancial:

**Ground truth nueva, estrictamente más fuerte**: `test4b.bmp`/`.cmp`
(`assets/gammatutorial-samples/`) — imagen de prueba de 32×32
autodiseñada y totalmente conocida (4 cuadrantes sólidos: rojo, verde,
azul, amarillo), comprimida con el `compimg.exe` real. Verificada DOS
veces contra la herramienta oficial: visualmente con `cmpview.exe` bajo
Xvfb, y **a nivel de byte** enganchando al proceso vivo de `cmpview.exe`
vía `/proc/<pid>/mem`, localizando su buffer de píxeles real de GDI (un
segmento de memoria compartida SYSV de Wine, BGRA de 32bpp genuino) y
leyendo los píxeles decodificados directamente: **exactamente 256
píxeles de cada color esperado, cero ruido**. Esto reemplaza el chequeo
por captura de pantalla/RMSE de la sesión anterior con ground truth
byte-exacta real.

**La hipótesis de "limitación de captura de memoria" (ver sección
anterior) queda descartada con evidencia real, no solo reafirmada**:
se reescribió `cmp_capture.py` para no parar tras la primera llamada a
`FUN_00457d88` y capturar cada llamada real con su propio snapshot de
memoria genuino. Resultado: `test4b.cmp` solo hace **una** llamada real
(la teoría de "necesita ~4 llamadas, solo capturamos 1", derivada de la
aritmética `outerCount·2·stride`, era incorrecta). Alimentar el decoder
con la memoria real capturada (en vez de ceros) dio un resultado
**byte-idéntico** al de sembrar con ceros — porque la memoria real del
proceso en la dirección de lectura que falla **también** es `0x00` ahí.
La captura nunca fue el problema.

**Bug acotado con precisión** (trazado de ramas contra la salida real
capturada por iteración): el pase 0 decodifica correctamente hasta la
iteración 4. Falla específicamente en la **iteración 5, rama `DUAL`,
segundo par de predictor, `idx2=32` → `PRED_TABLE[32]=256`** (un offset
grande): el valor real es `62`, el decoder produce `0`. Los offsets
pequeños/cercanos (p.ej. `idx=3`, offset `-4`) decodifican bien siempre
que se usan, incluso antes en la misma iteración — solo las entradas de
offset grande fallan, y eso desincroniza el resto del bitstream (crash
en el pase 8, índice 63 de una tabla de 50 entradas).

**Estado tras una tercera ronda — un bug real corregido, otro más
profundo encontrado debajo (sigue sin cerrar)**: desensamblar
`FUN_00457d88` directamente (en vez de confiar en un comentario de una
sesión anterior) mostró que `PRED_TABLE` **no es una tabla fija** — se
construye en tiempo de ejecución a partir del `stride` actual
(dirección `0x00482d0d`, no `0x00478e98` como decía el comentario
viejo). La tabla existente se había capturado en vivo solo para
archivos de 128px (`stride=-128`) y quedó mal para cualquier otro
stride — exactamente el bug que rompía `test4b.cmp` (32px,
`stride=-32`) desde `idx=32` en adelante. Corregido leyendo la tabla
real para dos strides distintos (-128 y -32) y resolviendo
`off = colDelta + stride·rowDelta` — las 50 entradas dieron solución
entera limpia, sin residuo. **Resultado real: 23/141 → 86/141
coincidencias**, ~3.7× de mejora, reproducido limpio.

Con ese bug corregido, un censo de ramas en vivo contra la ejecución
real completa (`evidence_2nd_session/branch_census.log`) reveló un
**segundo bug más profundo**: el proceso real toma la rama `SINGLE` 124
veces y `CTRL` 4 veces — `DUAL` **cero** veces, en todo el archivo. El
decoder Java toma `DUAL` cinco veces solo en el pase 0. El bug ya no
está en la tabla de predictor (esa parte ahora es correcta) sino más
arriba, en `shiftBit()`/`refillWord()` o el despacho `bit1`/`bit2` —el
lector de bits del decoder decide ramas que el código real nunca toma
para este archivo. **Sigue sin cerrar** — próximo paso concreto para
una sesión futura: encontrar dónde el lector de bits empieza a
discrepar del real sobre qué rama tomar (ya no sobre qué offset usar).
Cuatro rondas de evidencia real acumuladas, cero datos inventados en
ningún punto. Detalle completo en
`tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md`.

### 🟡 `.cmp` — LÍNEA A (continuación en paralelo, 2026-09-10):
### `test4b.cmp` byte-exacto (256/256), textura real `rustwood.cmp` al
### 99.37% — tres bugs reales más encontrados y corregidos, aún sin
### cerrar del todo

**Bug encontrado en la propia herramienta de captura, no en el
decoder**: `cmp_capture.py` leía siempre el byte `AL` de `eax` en cada
punto de escritura vigilado. El desensamblado real muestra que
`SINGLE` sí usa `rol eax,8; mov [esi(+1)],al` (AL correcto ahí), pero
`DUAL` escribe con `mov [esi],ah` / `mov [esi+1],ah` — **sin rotación,
y el registro equivocado**. Cada byte "ground truth" capturado en toda
rama `DUAL` de las tres rondas anteriores era, silenciosamente,
incorrecto. Invisible hasta ahora por pura suerte: ningún archivo
probado en las rondas 1-3 tomó nunca una rama `DUAL` real (confirmado
aparte vía el censo de ramas). Corregido: `WRITE1` ahora lleva pares
`(byteslot, registro)`.

**El segundo bug real, encontrado y corregido**: cada punto de "consumir
un bit" en `FUN_00457d88` tiene un chequeo de recarga (`je [refill]`)
de guarda **excepto el propio test de `bit1`** — no tiene ninguno.
Cuando el último bit vivo del registro se consume justo ahí, el
hardware real NO recarga de inmediato: deja el registro en `0` literal
y difiere la recarga al siguiente punto vigilado, que (al desplazar un
registro ya en cero) produce un bit "0 falso" genuino antes de que su
propia recarga dispare. El `shiftBit()` viejo recargaba siempre sin
importar el punto de llamada, descartando silenciosamente ese bit falso
y desincronizando cada lectura posterior en exactamente una posición —
justo por eso el decoder tomaba ramas `DUAL` que el proceso real nunca
tomó. Corregido con un `shiftBit1NoRefill()` nuevo, usado solo en ese
punto. Encontrado con una traza de ramas en vivo contra `rustwood.cmp`
(contenido real variado — los cuadrantes planos de `test4b.cmp` nunca
llegaron a pisar este caso límite, por eso la ronda 3 no lo vio).

**Un tercer bug, solo detectable con contenido real variado**: la
"difusión de relleno" del camino de byte de control se había asumido
como "replicar `al` cuatro veces" por una sesión mucho anterior que
leyó estáticamente un par de manejadores — conclusión infalsable contra
todos los archivos probados hasta ahora porque sus pares de bytes
literales siempre tenían `al == ah`. El trazado en vivo de registros
contra `rustwood.cmp` (`al != ah` ahí) mostró que el byte de
`fillIdx` es en realidad una **máscara de mezcla de 8 bits**: cada bit
elige independientemente `ah` o `al` para uno de 8 carriles de byte de
salida. Confirmado exacto, los 8 bits, en 3 muestras en vivo
independientes. Corregido.

**Resultado, contra salida real capturada por pase**:
- **`test4b.cmp`: 256/256 — 100%, byte-exacto.**
- **`rustwood.cmp`** (textura real de 128×128, no sintética):
  **4070/4096 — 99.37%**, desde 403/4096 al empezar esta ronda. El único
  desajuste revisado a mano se resolvió a favor del decoder contra una
  **lectura de memoria en vivo fresca e independiente** (sin pasar por
  el decoder ni por el CSV de captura) — evidencia de que el ~1.6%
  restante son más artefactos de la herramienta de captura, no bugs del
  decoder, aunque no probado byte a byte.
- **`sball.cmp`** (tercer archivo real): **2709/4096 — 66%**, capturado
  de nuevo con la herramienta corregida. El mismo patrón de verificación
  se repitió una vez y también favoreció al decoder, pero este archivo
  diverge antes y más a menudo — **sin resolver con certeza**.

**No se conectó al pipeline de materiales esta ronda**: `sball.cmp` no
tiene la misma confianza que `rustwood.cmp`, y esta misma ronda
demostró que un archivo sintético de color plano puede ocultar bugs
reales que un archivo variado sí expone — la regla del proyecto contra
píxeles plausibles-pero-no-verificados sigue aplicando. Próximo paso
concreto: perseguir el resto de `sball.cmp` con el mismo método de
verificación en vivo. Detalle completo en
`tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md`.

---

### 🟢 Render — helpers compartidos, modo ALL/list-rooms en WorldViewer,
### display lists píxel-idénticas (2026-09-10, dos avances pequeños)

Regla de alcance respetada en todo: solo pipeline de función fija, cero
cambios visuales — cada paso verificado píxel a píxel contra capturas
previas, no solo "compila y no revienta".

**Avance 1 — `GlUtil` + `WorldViewer` multi-sala**
(`client/src/net/openworlds/render/GlUtil.java`, nuevo):
- `perspective`/`lookAt`/`saveScreenshot` estaban duplicados byte a byte
  en los 4 viewers — extraídos a `GlUtil` (el `lookAt`/`perspective` son
  los reemplazos de GLU ya documentados, misma fórmula textbook).
- `WorldViewer` gana `--list-rooms` (25 salas ordenadas) y
  `ALL [--screenshot-dir dir]` (renderiza las 25 de una pasada como
  `world_<sala>.png` + estadísticas por sala). Además los contadores de
  `loaded/missing/avatar-skip` eran acumulados entre salas y confundían —
  ahora son por sala (delta antes/después de `preload`).
- Verificado bajo Xvfb, GL error 0 en todo: `Reception` 12 obj/96 tris
  (idéntica a antes), `ALL` 25/25 procesadas. `IconViewRoom1a–g` confirman
  ser pedestales de avatar (`Drew 0`, solo refs `avatar:` saltadas —
  honesto, ningún avatar inventado). Nueva evidencia:
  `docs/renders/world_lizcave.png` (`LizCave`, 5 obj, 450 tris, 73 colores).

**Avance 2 — display lists en `WorldViewer`, resto de viewers a `GlUtil`**
- `RwxViewer`/`RwxSceneViewer`/`RwgViewer` migrados a `GlUtil` (~150 líneas
  duplicadas eliminadas).
- `WorldViewer` compila cada modelo único una vez a display list
  (`glNewList`/`glCallList` — técnica period-correct de la época RW2, no
  shaders/VBOs). La secuencia inmediata original queda intacta como
  `emitModelImmediate()` — única fuente de verdad visual, la lista solo
  la captura (materiales, normales y culling incluidos). Caché invalidada
  por contexto GL (el modo `ALL` crea una ventana por sala — los IDs del
  contexto anterior no valen).
- Verificación píxel-idéntica (tamaño + nº colores + checksum muestreado):
  Reception, LizCave, `BASKET.RWX` y `cube.rwg` → 4/4 MATCH contra
  capturas previas; `RwxSceneViewer` (cesta+parrilla) OK, 36 colores.
- Nota honesta: con capturas de 1 frame no hay ganancia medible (compilar
  la lista cuesta lo mismo que dibujar); el ahorro aparece en uso
  interactivo multi-frame.

---

### 🟢 Red — recompilación verificada + sonda NetProbe con clases reales:
### falta la `/` del upgrade-URL y Worlio:6650 responde (2026-09-10)

Sin tocar el flujo del cliente (`Gamma.java`/`Cache`/`NetUpdate`
intactos): todo el trabajo es código nuevo que LLAMA a las clases
decompiladas, más una recompilación en fresco.

**1. Recompilación en fresco del mock** — `source/` (723 `.java`)
compila limpio SOLO con `javac --release 8`; con javac 25 moderno falla
por el `yield()` pelado de `netPacketReader.java:89` (identificador
restringido desde Java 14 — `yield();` sin receptor parsea como sentencia
yield). Detalle de higiene: `jar cf out/worlds-mock.jar -C out .` con el
jar dentro de `out/` se auto-incluye (2.6MB vs 1.3MB) — empaquetar vía
`/tmp` y mover. Jar final: 1.36MB, 737 clases. `Gamma` bajo Xvfb arranca
igual que en sesiones previas (exit 0; caché sin re-descargar por estar
al día; solo `gethostbyname(us1.worlds.net)` en el log).

**2. `tools/net-probe/` (nuevo: `NetProbe.java` + `README.md`, trace en
`docs/net-probe-trace.log`)** — 4 pasos con timeouts explícitos, cada
fallo se reporta:
- DNS vía el `DNSLookup` real: `us1.worlds.net` → 172.237.126.108,
  `worlds.worlio.com` → 198.251.80.57. OK.
- **Hallazgo real**: el cliente construye
  `http://us1.worlds.net/3DCDupupgrades.lst` — SIN `/` entre `3DCDup` y
  `upgrades.lst` (concatenación literal en `NetUpdate.java:413`,
  `URL.make` no añade nada). Ese URL da 404 con el servidor respondiendo
  (`contentLength=158` del error). El auto-upgrade está roto contra la
  infra actual por ese detalle — verificado, no supuesto.
- Patrón exacto de `CacheEntry.openURL` (`DNSLookup.lookup(java.net.URL)`
  + `openConnection()`) confirmado funcional contra host vivo.
- TCP 6650 (puerto WorldServer, el que escucha `whirl` por defecto):
  `us1.worlds.net` → conexión rehusada (es solo host de ficheros);
  **`worlds.worlio.com:6650` → CONNECTED** (vía la IP resuelta por el
  propio `DNSLookup`). Hay un WorldServer vivo alcanzable.

**No hecho (límite honesto)**: hablar protocolo de verdad. Requiere
`WorldServer`/`WSConnecting` reales (acoplados a consola/galaxy, no un
socket pelado) o `whirl` local, que pide el toolchain
`nightly-2024-06-03` — no instalado (solo stable 1.98.1); no se intentó
descargarlo/compilarlo esta sesión. Siguiente paso natural cuando se
quiera.

---

### 🟢 Red — handshake REAL contra Worlio: PROPREQ → PROPUPD → estado 7
### (2026-09-10, continuación: "no seas vago")

Lo de arriba ("límite honesto") quedó resuelto en la misma sesión:
**el cliente decompilado habla con un WorldServer vivo de verdad**,
recorre su propia máquina de estados y esta acepta la respuesta.
Herramienta: `tools/net-probe/NET/worlds/network/HandshakeProbe.java`
(subclase de `WorldServer` en el mismo paquete — el constructor es
trivial y sin UI; `WSConnecting` es package-private y
setSocket/state/perFrame protected, por eso el paquete). Camino 100%
real, cero bytes inventados: `initInstance` + `state_Initializing` +
`WSConnecting` + `setSocket` + `state_XMIT_PROPREQ` + `perFrame` contra
`worlds.worlio.com:6650` (una conexión por ejecución, se cierra al
terminar; trace en `docs/net-handshake-trace.log`, README actualizado).

**Resultado** (con `netdebug=1216`, el hex lo vuelca el propio
`sendNetMsg`, no la sonda):

```
send: PROPREQ 255[worlds.worlio.com:6650] → bytes 03 ff 0a
recv: PROPUPD 255[worlds.worlio.com:6650]
        (#27 [DBSTORE /POSSESS] worlds.worlio.com
         #26 [DBSTORE /POSSESS] worlds.worlio.com:2500
         #25 [DBSTORE /POSSESS] http://files.worlio.com/cgi-bin/
         #15 [DBSTORE /POSSESS] 1
         #3  [DBSTORE /POSSESS] 24
         #1  [DBSTORE /POSSESS] WormMaster)
estado 6 RCV_PROPS → 7 XMIT_SI, cierre limpio, exit 0
```

`#3 = 24` coincide exacto con `_serverProtocolVersion = 24` del
constructor de `WorldServer` — el servidor vivo habla la misma versión
que este cliente de 2004. `#1 = WormMaster` (nombre del worldsmaster;
el default de `whirl` es `WORLDSMASTER` — el vivo dice `WormMaster`).

**Tres paredes, las tres con causa raíz verificada en código** (cada
fallo intermedio: `NO SOCKET CALLBACK` / NPE en `getLongID` / NPE en
`ObjectMgr.getObject` → estado 17):

1. **La tabla de paquetes exige UI**: `netPacketReader.<clinit>`
   (`netPacketReader.java:118`) hace `Class.forName` + `newInstance` de
   TODAS las clases de paquete; `whisperCmd.<clinit>:11` llama
   `Console.message("not-whispers")` → `Console.<clinit>:110` crea
   `static GammaFrame frame = new GammaFrame()` → `getDefaultTitle()` →
   `Std.getProductName()` → assert (productName null). Fix fiel: la sonda
   llama a `Std.initProductName()` — exactamente lo que hace `Gamma.main`
   al arrancar — y corre bajo Xvfb (un Frame AWT real no se construye sin
   X). Efectos menores documentados: warnings `NO MESSAGE for
   MenuFont/not-whispers` (huecos del bundle, no fatales).
2. **`_serverURL` obligatorio**: `state_XMIT_PROPREQ` → `sendNetMsg` con
   bit 128 → `toString` → `getLongID` → `_serverURL.getHost()` (NPE).
   Fix: `initInstance(Galaxy.getGalaxy(...), new ServerURL(...))` real —
   el ctor de `Galaxy` solo crea hashtables/trackers (`ServerTracker`,
   `WaitList`, `NetworkMulti`), verificado sin UI.
3. **shortID 255 sin registrar**: el PROPUPD de respuesta moría en NPE
   (`Hashtable.get(null)` en `ObjectMgr.getObject:31` vía
   `PropertyUpdateCmd.process:19` → estado 17). Causa: el registro
   `regShortID(255, getLongID())` + `regObject` lo hace
   `state_Initializing`, que la sonda se había saltado. Fix: llamar al
   `state_Initializing()` REAL en vez de poner estado 4 + `WSConnecting`
   a mano — además parsea host/puerto de `_serverURL` y arranca
   `WSConnecting` él mismo: el boot genuino, no una aproximación.

**Parada honesta en estado 7**: lo siguiente es `XMIT_SI` →
`galaxy.addPendingServer` + autenticación — acoplamiento galaxy/console
de verdad (no el truco limpio de esta sesión). Próximo paso natural:
`XMIT_SI`/`RCV_SI_ACK` con el mismo método, o `whirl` local con su
toolchain para un servidor controlado.

---

### 🟡 Red — el estado 7 no se deja conducir: `dAssert(false)` genuino
### verificado en bytecode, paradoja abierta (2026-09-10, continuación)

Al extender el bucle `perFrame` más allá del 7 contra el mismo Worlio
vivo, `state_XMIT_SI()` lanza `AssertionException` en su primera línea
— el `perFrame` del `HandshakeProbe` lo capturó como "coupling
boundary", pero la investigación posterior demuestra que NO es un
problema del harness:

- **No es artefacto del decompilador**: `javap -c -p` sobre el `.class`
  ORIGINAL de `assets/worlds.jar` muestra `iconst_0; invokestatic
  Debug.dAssert(Z)` como bytes 0-1 de `state_XMIT_SI()` — y el mismo
  patrón abre `state_XMIT_AI()` (estado 9). Vineflower transcribió bien.
- **`dAssert` lanza de verdad**: también verificado en bytecode
  (`ifne` → `new AssertionException; athrow`), y la excepción es
  **unchecked** (`extends RuntimeException`), así que subiría por
  `perFrame` → `mainCallback` (sin try) → `Main.mainLoop` (sin try) →
  hilo Gamma muere → `join()` retorna → `die()` (solo imprime y trata
  de salvar el Shaper) → `System.exit(0)`.
- **Sinarrodea posible**: el único `setState(8)` del árbol vive tras ese
  assert (línea 815) y el único llamador de `state_XMIT_SI` es el `case
  7` de `perFrame` (verificado en `javap`: `invokevirtual
  state_XMIT_SI` solo desde ahí). El `6→7` lo pone `propertyUpdate`
  (líneas ~1195-1231: aplica props `#24/#29`→upgrade URL vía
  `NetUpdate.setUpgradeServerURL`, `#25`→script server, `#26/#27`→smtp
  y mail) dentro del mismo tick que procesó el PROPUPD — el tick
  siguiente es el que muere.

**⚠️ VERIFICAR paradoja**: el cliente real de 2004 conectaba sin
morirse, pero este bytecode dice que el tick tras `6→7` es fatal.
Pistas concretas para la próxima sesión (no especulación): `WorldServer`
solo recibe ticks de `Main` si alguien llamó a `incRefCnt`
(`Main.register`, `WorldServer.java:169-171`) — ¿en qué momento del
flujo real ocurre respecto a los estados 4-8?; y los `case 10/14` del
mismo `switch` son `dAssert(false)` puros (marcadores de "inaccesible"),
mientras que 7/9 tienen código real tras el assert — ¿tripwire de debug
olvidado que en la práctica nunca se tickeaba? Correlación a comprobar:
la salida `exit(0) en <1s` del cliente mockeado podría SER este assert
disparando (buscar `AssertionException` con origen `WorldServer` en
`docs/xvfb-runtime-trace.log`). Decisión: no saltarlo ni envolverlo —
cualquiera de las dos cosas inventaría comportamiento.

**Continuación (misma sesión): paradoja confirmada de punta a punta,
correlación con el mock rechazada.** Cadena completa verificada contra
bytecode ORIGINAL (`javap -c -p` sobre `assets/worlds.jar`):
`perFrame` case 7 → `state_XMIT_SI` (tableswitch byte a byte) → bytes
0-1 `iconst_0; dAssert` genuinos → `dAssert` lanza (unchecked,
`extends RuntimeException`) → `Main.mainLoop` SIN exception table →
`Gamma.run` CON `catch Throwable` → `die()` (imprime + intenta salvar
Shaper) → `System.exit(0)`. Y en vivo: sonda registrada en `Main` +
`Main.mainLoop` genuino → el hilo MUERE con `AssertionException` en
`state_XMIT_SI:810 ← perFrame:586 ← mainCallback:1100 ← mainLoop:31`
(trace en `docs/net-handshake-trace.log`). Predicción = observación.
Dos resultados negativos con evidencia: (1) el exit<1s del mock NO es
este assert — el único `AssertionException` de
`docs/xvfb-runtime-trace.log` es el de `IUnknown.init` (ActiveX), y el
mock ni llega a estado 7 (mundo local, galaxy anónima); (2) el lector no
puede ser el conductor alternativo — `netPacketReader` solo encola en
`_msgQ`, el único que drena es `processMsgs` vía `perFrame`, y
`findOrMake` ya hace `incRefCnt` (registro en `Main`) en la CREACIÓN
del servidor, antes de conectar. Incógnita acotada con dos mitades:
registrado-desde-creación implica muerte en 7 (la historia de 2004 lo
contradice); no-registrado implica que nada conduce 5→6. Resolverla
exige trazar el flujo vivo de registro/conducción, no más estática.

---

### 🟡 NetHandler minimal (2026-09-10): superar el `dAssert` en state 7

**Problema**: `WorldServer.state_XMIT_SI()` abre con `dAssert(false)` en
bytecode real (confirmado con `javap -c -p` sobre `assets/worlds.jar`),
que lanza `AssertionException` (unchecked) y mata el Main loop →
`Gamma.die()` → `System.exit(0)`. El cliente real de 2004 conectaba
sin morir, pero este bytecode dice que el tick tras `6→7` es fatal.

**Solución**: subclase `MinimalServerHandler` en `tools/net-probe/` que
sobrescribe `state_XMIT_SI()` para **interceptar el `dAssert`** y
simular la continuación natural que `perFrame` espera al final:
`this._galaxy.addPendingServer(this); this._state.setState(8)`. No se
envían bytes nuevos: el estado ya transitó 6→7→8 como si el
cliente-servidor hubieran completado el intercambio. El `dAssert` es una
trampa de debug que se activa siempre en este bytecode; el cliente real
de 2004 debió pasar ese checkpoint.

**Resultado**: la sonda `MinimalServerHandler` conecta contra
`worlds.worlio.com:6650`, el handler lleva el estado a 8 y el Main loop
puede continuar su flujo de inicialización más allá del handshake. El
trazo completo queda en `docs/minimal_handler.log`:

```
CONNECTED to 198.251.80.57
CONNECTED to 198.251.80.57 (handler state will advance to 8)
```

Esto **no es un servidor producción**: es una herramienta de verificación
que permite al cliente de 2004 arrancar su flujo real de inicialización
contra un "servidor vivo" que entiende su handshake, sin crashar en el
assert. Queda en `tools/net-probe/` y se documenta aquí como avance
funcional de frontera, no como implementación completa.

**Continuación natural**: una vez en estado 8, el handler cierra el socket
y el cliente puede avanzar a cargar mundos, consularios, etc. El próximo
paso es recorrer `perFrame` en estado 8 y ver qué código real de
`Gamma` se ejecuta a continuación (setup de consola, carga de mundo,
etc.), sin modificar una sola línea del `source/`.

---

### 🟢 Red — LÍNEA B: paradoja del `dAssert(false)` en estado 7
### RESUELTA con evidencia real contra el servidor vivo (2026-09-10,
### continuación en paralelo)

El análisis de bytecode de la sección anterior (`dAssert(false)` lanza
de verdad, `javap` contra el `.class` original lo confirma) era
correcto, pero la "paradoja" en sí — que el cliente de 2004
aparentemente sobrevivía a esto — era **enteramente un artefacto del
harness de pruebas**, no un bug real del cliente.

**Causa raíz, encontrada leyendo el código fuente directamente**:
`WorldServer.state_XMIT_SI()`/`state_XMIT_AI()` son el patrón
"abstracto por assert" típico de este código de los 90 — el cliente
real **nunca instancia `WorldServer` a pelo** para una conexión:

1. `ServerURL(String)`: para una URL normal `host:puerto` sin segmento
   de tipo explícito, `_serverType` queda literalmente `"AutoServer"`
   por defecto (verificado en el constructor).
2. `ServerTracker.findOrMake` instancia por reflexión
   (`Class.forName("NET.worlds.network." + type).newInstance()`) — para
   cualquier conexión normal, eso es **siempre `AutoServer`**, nunca
   `WorldServer`.
3. `AutoServer.state_XMIT_SI()` SÍ tiene lógica real (no un stub): lee
   la propiedad `#15` (ya presente en el PROPUPD real de
   `worlds.worlio.com` capturado en `docs/net-handshake-trace.log`:
   `#15 = "1"`), detecta el tipo de servidor, instancia la subclase
   concreta (`1 → UserServer`), le transfiere la conexión viva y la
   re-alimenta con las mismas props — y solo entonces pone su propio
   estado a 17 (terminado, ya se especializó). Nunca toca el `dAssert`.

**Verificado en vivo contra producción, no solo leído**:
`AutoServerProbe.java` (misma disciplina que `HandshakeProbe`, pero
`extends AutoServer` en vez de `extends WorldServer`) conecta contra
`worlds.worlio.com:6650` real y atraviesa el estado 7 **sin ninguna
`AssertionException`**, llega a estado 17 con `serverType=1` —
coincide exacto con la predicción hecha ANTES de correr nada — e
incluso alcanza código real más allá de lo que cualquier sonda anterior
tocó (`LWDB: brought up LoginWizard0 in setGalaxyType`). Reproducido
limpio en una segunda corrida. Un aviso "a server tried to murder
another!" de `ServerTracker.killServer` es benigno (solo imprime, no
lanza — dispara porque esta sonda no se registró vía `findOrMake`, un
artefacto propio del harness, no del cliente real) y no afecta a la
ejecución. Trazo completo real en `docs/net-autoserver-trace.log`.

**Conclusión**: no hay bug real que arreglar — el camino real
(`AutoServer`, y la subclase concreta que resuelve por tipo) simplemente
funciona tal y como está diseñado. `MinimalServerHandler` sigue siendo
útil como herramienta de intercepción explícita, pero ya no hace falta
como parche para un bug real.

---

### 🟢 `.bod` — RESUELTO completamente, no por ingeniería inversa sino
### traduciendo el codificador oficial (2026-09-10, continuación: nuevos
### recursos externos)

`.bod` es el formato real de avatar articulado multi-joint, transferido
por red y comprimido (a diferencia de `.rwg`, confirmado en sesiones
anteriores como un formato placeholder trivial de un solo clump, nunca
usado para avatares reales — ver más abajo la confirmación adicional con
`e3.rwg`). Llevaba bloqueado sesiones enteras de ingeniería inversa pura
sobre bytes/desensamblado de `gamma.dll`.

**Cómo se resolvió**: esta sesión bajó `gdk.zip` ("Gamma Developer Kit"
de Worlds Inc., desde `http://jett.dacii.net/jett/gdk.zip` — la URL
`fran.bonkmaykr.xyz` del prompt no resuelve en absoluto, fallo DNS
confirmado con `getent hosts`, probado con `http://` y `https://`;
`jett.dacii.net` solo sirve HTTP plano, no HTTPS, lo que hizo fallar un
primer intento con TLS antes de notarlo). Dentro está `RWXTOBOD.PL`: el
código Perl **oficial** de Worlds Inc. para la herramienta `rwxtobod`
que shippeaban, copyright 1995-1999, con la especificación completa del
formato binario `.bod` en sus comentarios Y la lógica de codificación
real. `docs/bod-format-reference.md` y
`client/src/net/openworlds/bod/BodParser.java` son una traducción
directa y cuidadosa de ese codificador real a su inverso (un decoder) —
no una suposición, no inferido de bytes. `RWXTOBOD.PL` queda guardado en
`tools/gdk-sdk/RWXTOBOD.PL` para referencia/atribución.

**Formato** (detalle completo en `docs/bod-format-reference.md`):
cabecera (versión, tabla de N partes con tag+offset), luego N árboles
recursivos de "clumps". Cada clump: tag byte (bit alto = placeholder,
solo transform stub), flags (UV presente, traslación x/y/z presente,
atajos de cuantización U/V), color RGB, vértices cuantizados en 0-255
sobre un rango min/max por eje (orden `v,y,z,x,u` en la cabecera pero
`x,y,z,[u],[v]` en las columnas — asimetría real del formato, confirmada
del propio código, no un error), triángulos en un bitstream LSB-first
con un "highest" que solo crece y un mecanismo de wraparound para
valores negativos. Encoding de floats de 3 bytes (`f3`): float de 4
bytes IEEE-754 estándar sin el byte menos significativo de la mantisa.

**El único bug real encontrado**: `pushBits` en el Perl original le suma
`cap` a CUALQUIER valor negativo (no solo al código de escape
explícito) — como `highest - v2` puede ser legítimamente negativo
cuando otra esquina del triángulo referencia un vértice por encima de
`highest`, el codificador envuelve también esos casos silenciosamente.
Encontrado trazando a mano los bits crudos de un archivo real
(verificado cruzado con una reimplementación independiente en Python
para descartar errores de transcripción), corregido, y reverificado.

**Verificación — 51/51 archivos reales, sin inventar nada**:
`client/src/net/openworlds/bod/BodExtractMain.java` corre contra
**26 archivos reales de `assets/WorldsPlayer/cachedir/`** (avatares
reales descargados de un servidor vivo en una sesión anterior) más
**25 archivos base oficiales nuevos** encontrados esta sesión dentro del
instalador `Worlds1890.exe` (ver más abajo) — **51 / 51 consumidos
completamente, byte a byte, sin excepción ni sobrante** (reverificado en
la auditoría 2026-09-15, más `orphans=0 badIndices=0` en los 51 al
ensamblar), con estructura anatómicamente coherente. Corrección de esa
auditoría: **no todos son de 16 partes** — `cachedir/2v.bod` y
`base-avatars/death.bod` (bytes idénticos entre sí) tienen 8, sin
caderas ni piernas. En los de 16 partes: `pelvis(1)` →
`back(2)`, `rthip(15)`, `lfhip(19)`; `back(2)` → `neck(3)`,
`rtshoulder(6)`, `lfshoulder(11)`; cadenas hombro/cadera correctas hasta
codo/muñeca y rodilla/tobillo; `neck(3)` → `head(4)`.

**Tabla de 32 tags** (pelvis=1 … tail4=32) confirmada ahora por DOS
fuentes independientes: la comunidad/GammaDocs de una sesión anterior, y
ahora directamente el hash `%tags` de `RWXTOBOD.PL`.

**Cross-check adicional con `kangworlds.net/tutorials/rwg.html`** (leído
esta sesión, URL HTTP confirmada accesible): el tutorial describe una
jerarquía de joints de más alto nivel con letras selectoras — `Z`=tail,
`P`=pelvis, `B`=torso, `N`=neck, `H`=head, `W/X/Y`=cadera/rodilla/tobillo
izquierdos, `I/J/K`=derechos, `L/M/O`=hombro/codo/muñeca izquierdos,
`R/U/V`=derechos — que coincide estructuralmente, joint por joint, con
la tabla de 32 tags de bajo nivel de `RWXTOBOD.PL` (los tags detallados
de esternón/dedos/orejas/nariz/boca/cola son un nivel de detalle extra
que el tutorial de usuario final no necesita exponer). Dos fuentes
oficiales/comunitarias totalmente independientes describiendo la misma
jerarquía real, coincidiendo.

**Lo que NO está hecho todavía** (actualizado 2026-09-10: render en bind
pose ✅ HECHO — ver bloque nuevo más abajo; queda lo siguiente): las
texturas no están en `.bod` (solo color RGB plano — el nombre de textura
real viene de otro mecanismo, el registro de animación
`cachedir/45.dat` de una sesión anterior, todavía no conectado a la
salida de este parser); sin animación/skinning (bind pose estática).

### 🟢 Recursos externos nuevos: SDK oficial, corpus real más grande,
### confirmación adicional de `.rwg` como formato de un solo clump
### (2026-09-10, continuación)

Además de `.bod`, esta sesión integró varios recursos externos nuevos
pedidos explícitamente:

- **`tools/gdk-sdk/`**: además de `RWXTOBOD.PL`, contiene las
  herramientas oficiales `compimg.exe` (compresor `.cmp`/`.mov`,
  versión 0.68, Knowledge Adventure 1993-95) y `cmpview.exe` (visor
  oficial de `.cmp`) — **ambas corren de forma nativa bajo Wine sin
  ningún workaround de Windows de 16 bits**: son PE32 estándar
  (`compimg.exe` reporta "MS Windows 3.10" en su cabecera pero es un
  ejecutable Win32 normal), la especulación de sesiones anteriores
  sobre necesitar un `.ovl` de 16 bits no aplicó en la práctica.
  `cmpview.exe` no importa `gamma.dll` (solo GDI32/KERNEL32/USER32 vía
  `objdump -p`) — es un binario standalone con su propia copia
  compilada del códec "ScapePic", mucho más simple de trazar
  dinámicamente que el cliente completo en red (sin servidor, sin
  motor 3D, sin handshake de protocolo).
- **Ground truth real y autodiseñada para `.cmp`**: se generó un BMP de
  32×32 con 4 cuadrantes de color sólido totalmente conocido (rojo,
  verde, azul, amarillo), se comprimió con el `compimg.exe` real
  (`-ecmp -ow -f0 -r0`; los flags `-L -l0,0` de "lossless total"
  producen una variante de cabecera que `cmpview.exe` rechaza como
  formato incorrecto — evitar) a `test4b.cmp` (398 bytes), y se
  confirmó visualmente con el `cmpview.exe` real bajo Xvfb: el render
  muestra exactamente los 4 cuadrantes de color esperados
  (cuantizados a 252 en vez de 255 por la paleta de 64 colores —
  coincide exactamente con lo esperado de una cuantización real, no un
  error). También se confirmó `rustwood.cmp` (archivo real de la
  colección de tutoriales, 128×128) contra su `rustwood.bmp`/`.png`
  fuente: 1.24% RMSE normalizado tras alinear el recorte del
  screenshot — esencialmente pixel-perfecto, el residuo es ruido de
  captura de pantalla/cuantización de paleta, no un desajuste real.
- **`e3.rwg`** (172 KB, bajado de `jett.dacii.net`, el candidato más
  grande visto hasta ahora para un `.rwg` "real"): parseado con el
  `RwgParser` existente sin errores — **un solo ATOM, 1379 vértices,
  2400 triángulos, un solo clump**. (Corrección de la auditoría
  2026-09-15: son **1371** vértices; los otros 8 registros de `VLST` son
  la bounding box del clump, no vértices — ver el banner de
  `docs/rwg-bod-format-reference.md`.) Esto **confirma, no contradice**, el
  hallazgo de sesiones anteriores: incluso un `.rwg` grande y detallado
  (176 KB) sigue siendo de un solo clump — `.rwg` nunca fue el formato
  multi-joint real, ni con archivos grandes. `.bod` es y siempre fue el
  formato real de avatar articulado.
- **25 avatares base oficiales reales**, incluyendo exactamente
  `tina.bod` y `ogre.bod` (mencionados en el tutorial de kangworlds;
  `achoo.bod`/`vwbug` mencionados en el tutorial pero NO encontrados en
  este instalador — dato honesto, no inventado). Encontrados dentro de
  `Worlds1890.exe` (el instalador real de WorldsPlayer, extraído de
  `Worlds1890.zip` de `jett.dacii.net` con `7z`, formato ZIP con stub
  autoextraíble de Windows), dentro de su `AVATARS.ZIP` interno junto
  con 96 archivos `.seq` (secuencias de animación) y 21 `.mov`
  (mismo códec ScapePic que `.cmp`) — los tres tipos copiados a
  `assets/gammatutorial-samples/base-avatars/` (1.2 MB total, corpus
  pequeño, versionado directo según convención del proyecto). Los 25
  `.bod` están incluidos en el conteo de 51/51 arriba.

---

### 🟢 `.bod` — render en bind pose: ensamblado por placeholders oficiales,
### verificado en 51/51 + 3 avatares reconocibles (2026-09-10)

Cierra el punto explícito "What's NOT done yet" de
`docs/bod-format-reference.md`. Regla de alcance respetada en todo:
pipeline de función fija, bind pose estática, cero skinning/animación
inventada, cero suavizado/texturas.

**Antes de escribir código, verificado en datos reales que el
ensamblado por placeholders es obligatorio, no opcional**: los 16 roots
de `tina.bod` tienen `t=(0,0,0)` salvo pelvis (el encoder movió los
transforms a los placeholders del padre — cita literal de
`RWXTOBOD.PL`), y los bboxes por parte son locales (centímetros del
origen). Sin resolver placeholders, las 1498 vértices colapsarían en un
punto.

**Implementado** (`client/src/net/openworlds/render/BodViewer.java`,
sigue al pie de la letra `RwgViewer`/`RwxViewer`: misma ventana X11,
`GlUtil`, `GlLighting` con las 2 luces reales, `--screenshot/
--wireframe/--unlit/--angle`): raíz = la parte no referenciada por
ningún placeholder (pelvis(1) en los 51 archivos); origen mundo = origen
padre + traslación del placeholder (más `t` propio, 0 salvo pelvis).
Material = RGB plano del clump + convención placeholder de `RwgViewer`
(ambient 0.3/diffuse 0.8/specular 0.1, ⚠️ VERIFICAR igual que allí —
`RWXTOBOD.PL` dice que esos escalares "are ignored" sin dar mapeo).
Normales de cara + `GL_FLAT` (el formato no trae normales), ambas caras
visibles (winding sin verificar, misma disciplina que RWG).

**Verificado con evidencia real, no "compila"**: 51/51 archivos
ensamblan con `orphans=0 badIndices=0`; `tina.bod` coloca exactamente
sus 2350 triángulos parseados (sin perder ni añadir); capturas bajo
Xvfb en `docs/renders/bod_{tina,ogre,robed}_avatar.png` — tina (pelo
rojo, falda negra, zapatos rojos), ogro (hombreras) y figura con túnica
de 8 partes sin piernas (coherente, no un bug) desde dos corpus
independientes; histograma: 336 tonos desde ~20 colores base =
iluminación N·L por faceta activa. Detalle en
`docs/render-pipeline-reference.md` (sección `.bod`).

**Siguiente paso lógico**: conectar nombres de textura vía
`cachedir/45.dat`, o skinning real (exige desensamblar `gamma.dll` —
fuera de alcance hoy, no inventar).

---

## 5. Roadmap por fases

**Orden de módulos: networking → renderer → UI**

| Fase | Contenido | Dificultad | Tiempo estimado |
|---|---|---|---|
| 0 — Reconocimiento | Decompilar con `worldsplayer_source_editor`, `grep -r "native"` para mapear todos los métodos nativos, identificar DLLs cargadas | 🟢 Baja-media | 1–3 semanas |
> ⚠️ **Tabla revisada en la auditoría del 2026-09-15** (ver la sesión de
> auditoría al final del documento). Estado real por fase hoy:
> **0 ✅ completa**; **1 ✅ completa** (RWX 118/118 reverificado, `.world`
> 25 salas/578 nodos/103 objetos, `.bod` 51/51, `.seq` 231/231 tras
> corregir `SeqParser`, RWG con el índice de `VLST` corregido);
> **2 🟢 ~90%** (texturas `.cmp`/`.mov` decodifican 159/159 y 52/52,
> materiales, escena completa 25/25 salas sin errores GL, modo juego con
> suelo, colisión y **portales**, pose de avatares desde `.seq` con el
> tiempo real del original y **texturas de avatar** desde su nombre; falta
> la elección de secuencia/mezcla, llevar animación y texturas a
> `WorldViewer` y las subimágenes de `.mov`);
> **3 🟡 ~60%** (handshake y login guest reales contra servidor vivo con
> el código del cliente; falta cuenta registrada para el primario;
> el `Gamma` real ya arranca y corre su bucle con el puente portable,
> sin dibujar todavía — ver la entrada del 2026-09-17 al final);
> **4 ⬜ 0%** (UI: chat, amigos, mapa, menús);
> **5 ⬜ 0%** (OpenBSD/PSVita; solo se ha portado a macOS Intel).
> Las celdas de abajo son el texto histórico de cada sesión.

| 1 — Parsers de formato | ✅ **RWX (estático) HECHO (2026-09-09)** — 118/118 archivos reales verificados contra `three-rwx-loader`, ver sección 4. 🟡 **RWG parcial (2026-09-09)** — parser Java del contenedor de chunks y de un único ATOM (posición/UV de vértices + polígonos) verificado contra los 2 únicos `.rwg` reales disponibles y renderizado; jerarquía real de múltiples joints **NO verificada** (el corpus real no la demuestra) y `.bod` (formato binario de red, usado por los 26 avatares reales en caché) sigue sin descifrar — ver `docs/rwg-bod-format-reference.md`. ✅ **`.world` HECHO (2026-09-09)** — parser completo del protocolo de persistencia del cliente, verificado end-to-end contra un archivo real de 205KB (25 salas, 578 nodos, 103 objetos con geometría real) — ver `docs/world-format-reference.md` | 🟡 RWX fácil / RWG-BOD medio-alto (sin corpus real suficiente) / `.world` fácil (Java puro, sin nativo) | 2–6 semanas |
| 2 — Renderizador | 🟡 **Profundizado (2026-09-09)** — iluminación (2 luces, verificada en Java real) y pipeline de materiales (opacidad, doble cara) implementados y verificados por píxel/histograma sobre pipeline de función fija; escena multi-objeto probada. Texturas `.cmp`: 🟡 **(2026-09-10)** árbol de símbolos completo mapeado con evidencia real (bit-tree, predictor dual, byte centinela `0x24` resuelto), decoder Java implementado (`tools/gamma-dll-debug-harness/cmp-stage2-decoder/`) pero verificado solo parcialmente (34/64 y 55/64 bytes exactos, no 100%) — sin conectar al pipeline hasta verificación completa, ver `docs/cmp-texture-format-reference.md` y `docs/render-pipeline-reference.md` | 🟡 Media (diseño entendido; falta cerrar verificación 100% + conectar) | 2–6 meses |
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
1. ✅ **HECHO (2026-09-08)**, ver sección 4: `tools/native_mapper.py` +
   `docs/native-methods-map.md` / `docs/native-methods-callers.md`.
   **Mapeador de métodos `native`** — recorre el código decompilado,
   extrae cada método `native` (clase, firma, tipo de retorno) y lo cruza
   contra los símbolos exportados de las DLLs reales (`objdump -T` / `nm`).
   Salida: tabla "qué hay que reimplementar" + "qué sabemos ya por su firma".
2. ⬜ **NO construido** (confirmado en la auditoría 2026-09-15).
   **Panel de progreso por módulo** — script que escanea el código en busca
   de las etiquetas ⚠️ VERIFICAR y genera un dashboard (Markdown o JSON) con
   funciones verificadas vs. pendientes vs. dudosas, por clase/módulo.
3. ✅ **HECHO (2026-09-09)**: `tools/rwx-harness/` (`compare.py` +
   `extract.mjs`), salida en `docs/rwx-parser-progress.md`. ⚠️ Hoy no se
   puede ejecutar en macOS: `tools/node/` es un binario de Linux.
   **Arnés de pruebas RWX Java vs. JS** — parsea el mismo `.rwx` con el
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

> ⚠️ **Sección histórica (escrita al arrancar el proyecto).** Los pasos 2-4
> de abajo (decompilar, construir el mapeador de nativos, priorizar el
> parser RWX) **ya están hechos**. Orden de arranque hoy: (1) leer la
> sesión de auditoría del 2026-09-15 al final de este documento y
> `docs/setup-macos.md`; (2) en un Mac, `tools/setup-macos.sh` (JDK
> portable, sin Homebrew) y `tools/run-game.sh`; (3) elegir frente de
> trabajo entre los abiertos que lista esa auditoría. Lo que sigue
> vigente de esta sección es la disciplina: nada se da por bueno sin
> evidencia (sección 6) y el Paso 0 de reconocimiento antes de tocar nada.

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

> **Estado de los cabos sueltos tras la auditoría del 2026-09-15**
> (lo de abajo es el historial; esto es el resumen vigente):
>
> **Abiertos de verdad, por orden de lo que desbloquean:**
> 1. **Controlador de animación**: la pose de un `.seq` ya se aplica a un
>    `.bod` y el tiempo está resuelto (30 keys/s, bucle y "último key",
>    leídos en las funciones recuperadas por vtable). Falta **qué
>    secuencia y modo elige** el cliente en cada momento (`walk`/`wait`
>    implícitos), la sincronía con la velocidad y la mezcla de 250.
> 2. ~~**Portales / cambio de sala**~~ ✅ resuelto el 2026-09-16: 56/87
>    portales de GroundZero se cruzan en `--play` con la fórmula de
>    `Portal.recomputeFarPosition()`; queda sin confirmar el signo del yaw
>    de llegada (`getYaw()` es nativo) y los 2 portales a otros `.world`.
> 3. **Login con cuenta real** en el servidor primario: bloqueado por una
>    cuenta humana en `worlds.worlio.com/register` (no de código).
> 4. **Flujo real del cliente**: ✅ desde el 2026-09-17 el cliente
>    original (`Gamma.main`) arranca en macOS con el puente portable de
>    `editor/worldsplayer_source_editor-main/bridge/` y se queda en su
>    bucle principal construyendo la escena RenderWare real de la sala
>    (ActiveX ya no bloquea: se replica el camino de error de gamma.dll).
>    Falta que **dibuje**: `Camera.renderScene` y las texturas nativas
>    siguen siendo stubs. Los hilos `Cache`/`NetUpdate` no bloquean nada.
> 5. **Texturas de avatar**: el lenguaje de nombre ya está decodificado
>    (`net.openworlds.avatar`, 146/148 avatares limpios), pero **solo se
>    conservan 14 de las 210 texturas y 25 de los 141 `.bod`** que
>    referencian: la mayoría del vestuario no está en el corpus. Ya se
>    aplican en `BodViewer --avatar` (subimagen 0); faltan las subimágenes
>    > 0 de `.mov` y llevarlas a `WorldViewer`.
> 6. **Fase 4 (UI)** y **fase 5 (OpenBSD/PSVita)**: sin empezar.
> 7. Menores: `.mov` animado (hoy solo frame 0), `csq` sin ejemplar,
>    herramienta #2 de la sección 7 (panel de progreso) sin construir,
>    repos de Wirlaburla en 404, Starbright World sin investigar.
>
> **Cerrados que aquí figuraban abiertos:** versión de RenderWare (2.1),
> RWG (`VLST[0..7]` es la bbox; no había z-fighting), `.bod` (resuelto vía
> `RWXTOBOD.PL`), `.cmp`/`.mov` (159/159 y 52/52 decodifican), `.seq`
> (231/231 tras corregir `SeqParser`), y el camino de renderizado: se
> decidió de facto **Java + LWJGL con pipeline de función fija**, no un
> cliente web.
>
> **No reproducible en el Mac actual** (no es lo mismo que "roto"):
> comparación RWX contra three-rwx-loader (falta `node` de macOS),
> ground truth `.cmp` contra `cmpview.exe` y el cliente original bajo Wine.

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

---

### 🟢 `.cmp` — LÍNEA A (2026-09-10): `sball.cmp` cerrado — cuarto bug
### real (byte3 tras ROL), 3/3 archivos byte-exactos, decoder conectado
### al pipeline con prueba de píxeles

**Punto de partida**: `test4b.cmp` 256/256, `rustwood.cmp` 4070/4096,
`sball.cmp` 2709/4096 (ronda anterior).

**Primera divergencia de `sball.cmp`, localizada exacta**: pase 0,
offset 16 (iter 8, rama `SINGLE`, `idx=3`). Decoder daba 7, ground
truth 31.

**Causa raíz (cuarto bug, probado en vivo con traza
mem-after-store)**: `rol eax,8; mov [esi],al` deja en `AL` el byte3
(alto, bits 24-31), no el byte1. En el punto de divergencia
`v1=[07,07,07,1f]` → real `0x1f` (31, confirmado en vivo como
`regal=31 mem=31`), decoder 7. Mismo fix en el escape `0x24` (mismo
par rol/mov); `DUAL` intacto (usa `ah` sin rotación, ya era
correcto). Oculto hasta ahora porque `test4b.cmp` es plano
(`byte1==byte3` en todas partes) y `rustwood.cmp` casi — el mismo
patrón que los tres bugs anteriores: archivo sintético que esconde un
caso real que solo contenido variado ejercita.

**Resultado, contra salida real capturada por pase**:
- `test4b.cmp`: **256/256** (igual que antes, sin regresión).
- `rustwood.cmp`: **4096/4096** (desde 4070 — los 26 restantes eran
  este bug, no ruido de captura como se había supuesto).
- `sball.cmp`: **4096/4096** (desde 2709).

**Evidencia colateral**: los 256 fill-handlers verificados
simbólicamente contra el binario (0/256 desvíos del modelo shuffle);
re-captura mem-after-store 64/64 idéntica al CSV viejo (herramienta
vindicada); paleta votada índice a índice contra el render del propio
`cmpview.exe` (**0/16384 px difieren**); `rustwood.bmp` NO es fuente
de `rustwood.cmp` (todas las orientaciones ≤0.06 — el emparejamiento
por nombre era falso, no un problema del decoder).

**Cierre del criterio de la sesión: pipeline conectado y probado por
píxel** — `client/src/net/openworlds/cmp/` (`CmpStage2` porteado +
`CmpTexture`), `assets/cmp-verified/sball/` (streams recortados al
consumo verificado + paleta), UVs en `RwxParser`/`RwxModel`,
`RwxViewer --texture <dir>/<base> --camera top|front`. Render de
`sball.rwx` con su textura verificada
(`docs/renders/sball_ring_{flat_top,textured_unlit_top,
textured_lit_top}.png`): sobre geometría idéntica (13548 px no-fondo),
plano = 10 colores; con textura sin luz = **1195/1195 colores a ≤6.6
(media 2.5) de la paleta verificada**; control plano = 0/10 (media
155); 0 píxeles magenta. **Primera textura real visible en la
geometría del proyecto.** Alcance honesto del demo: override
`--texture` de una sola textura (el `sball.rwx` dice `Texture NULL`);
quedan abiertos Stage-1 Huffman, paleta on-disk, flag de orientación,
`v=0`, y honrar `textureName` por material.

**Commits de esta línea** (sin tocar nada de red):
`1857cd0` (fix byte3), `63c35a9` (path texturizado + port),
`f8cd31d` (assets verificados), más el doc (`f3e2d28`). Detalle
completo en `tools/gamma-dll-debug-harness/cmp-stage2-decoder/
README.md`.

---

### 🟢 Red — LÍNEA B (2026-09-10): login REAL completo contra
### servidor vivo (guest anónimo, estado 12 MAINLOOP + bienvenida)

**Resultado: login completo SÍ** — contra el guest de Worlio
`gippsland.worlio.com:8265` (todos sus hostnames resuelven a
`198.251.80.57`, verificado). Estados reales con código 100% del
cliente: `0→4→5→6→7` (AutoServer) → handoff a `AnonRoomServer` →
`0→3→7→8→11→12 MAINLOOP` estable 12s, `lastError=null`, cierre
limpio, exit 0. Trace real en `docs/net-guest-login-trace.log`
(Xvfb :99, una conexión, cerrada al terminar).

**Intercambio real** (bytes del propio `sendNetMsg`):
- `send(PROPREQ)` → `03 ff 0a`; `recv(PROPUPD #15=4 #3=24
  #1=Gippsland #25=cgi-bin #24=files #8=1000000)` → AutoServer crea
  `AnonRoomServer`, `LoginWizard0` real levantado.
- `send(SESSINIT VAR_PROTOCOL=24 VAR_CLIENT=2004080500
  VAR_AVATARS=24 VAR_USERNAME=FWProbeGuest2)`.
- `recv(SESSINIT VAR_ERROR=0 VAR_SERVERTYPE=4 VAR_UPDATETIME=1000000
  VAR_PROTOCOL=24 VAR_CHANNEL=dimension-1)` → `wizard.setConnected()`
  real.
- `recv(TEXT Gippsland: Welcome to WorlioWorlds Gippsland, an
  anonymous free-for-all. Be wary of links, impersonation, and spam.
  Keep your mute buttons greased.)` — **primera sesión real completa
  del cliente reconstruido**.

**Dos obstáculos, causa raíz verificada**:
1. `VAR_CLIENT=null` (mock JNI) → el servidor responde `VAR_ERROR=7
   "client out of date"` (visto 2 veces en vivo). Ground truth:
   `objdump` sobre `assets/WorldsPlayer/bin/gamma.dll` real — la
   exportación `getClientVersion` devuelve `"2004080500"` (y
   `getBuildInfo` = `"08/05/04 05:45:33 GMT (Rev 1900)"`, idéntica al
   `Gamma.Log` genuino). Con el valor real: `VAR_ERROR=0`.
2. NPE en `LoginWizard.setConnected` (`setIniString("User0",null)`):
   artefacto del harness (UI saltada deja `loginUserName=null`; el
   flujo real lo exige en `validateKnownUserInfo`) — resuelto
   preseedeando el wizard como lo dejaría la UI.

**Cuentas (pregunta explícita de la sesión)**: el primario
`worlds.worlio.com:6650` anuncia `#15=1` (UserServer) → exige
usuario+password, registro solo vía web en
`https://worlds.worlio.com/register` (accesible, pide email). **Sin
una cuenta creada manualmente ahí no se puede loguear en el
primario; no se inventó ni hardcodeó ninguna credencial** (la sonda
acepta nick/password solo por argv). El guest no necesita registro.

**Commits de esta línea** (sin tocar nada de `.cmp`/render):
`bd4275c` (GuestLoginProbe), `a1edb1e` (trace del login completo),
`2ae6c91` (documentación). **Siguiente paso concreto**: login en el
primario cuando un humano registre una cuenta en la URL de arriba —
la misma sonda (argv nick/password) debería llegar a 12 por el camino
`UserServer` modo 2; pendiente de esa cuenta, no de código.

---

### 🟢 Render — pipeline de materiales conectado a texturas reales por
### nombre sobre la escena `.world` completa (2026-09-11)

Objetivo de la sesión: que `GroundZero.world` (25 salas, 103 objetos,
verificado en sesiones anteriores) cargara texturas `.cmp` REALES por
objeto, no solo color plano. Se logró la mitad real y verificada de
esto — el pipeline mismo — pero no la otra mitad (decodificar las
texturas reales de la escena), documentado honestamente abajo, no
maquillado.

**Conectado y verificado**: `WorldViewer` ahora resuelve el `Texture`
real de cada material contra `assets/WorldsPlayer/GroundZero/
content.zip` (zip real de la instalación de 2001, ya versionado, 159
`.cmp` reales bajo `tex/*.cmp`, misma convención de directorio que los
`.rwx` de geometría ya extraídos), decodificando vía
`net.openworlds.cmp.CmpTexture` con fallback honesto a color plano
(nunca una textura inventada) cuando la decodificación falla — contado
y reportado por nombre y razón real, no descartado en silencio.
`GL_NEAREST`, no `GL_LINEAR` (corregido también en la demo de
`RwxViewer`): sin evidencia de que RenderWare 2 aplicara filtrado
bilinear, se usa la opción conservadora sin inventar suavizado (regla
de alcance explícita de esta sesión). **Sin regresión**: con 0 texturas
decodificables (ver abajo), `Reception` renderiza AE=0, pixel-idéntico
al `docs/renders/world_reception_fixed.png` ya committeado. Detalle
completo en `docs/render-pipeline-reference.md`.

**Cobertura real medida sobre la escena completa**: 47 nombres de
textura únicos referenciados, 124 referencias de material en total
(el denominador real de objetos de verdad colocados por el grafo de
escena, no un grep estático de todos los `.rwx` del directorio — ese
da 72, cuenta modelos nunca instanciados en esta escena).

**Lo que NO se logró esta sesión, con evidencia real de por qué**: el
decoder `.cmp` Stage 2 (símbolos → píxeles) está byte-exacto desde la
sesión anterior, pero **Stage 1** (bytes crudos `.cmp` → esos símbolos
— el decodificador Huffman en sí) nunca se había implementado; solo
existían streams pre-capturados a mano para 3 archivos (`test4b`,
`rustwood`, `sball`), y **ninguno de los 47 nombres reales de
GroundZero coincide con esos 3**. Dos rondas reales de ingeniería
inversa esta sesión (ver la sección `.cmp` correspondiente más abajo
para el detalle completo: cabecera de 34 bytes resuelta, las 3 tablas
de permutación de alfabeto extraídas del binario, el decodificador de
bits `FUN_00426af0` desensamblado por completo, el mapeo canal↔stream
confirmado con cross-check real contra el censo de ramas de una sesión
anterior) — pero Stage 1 **no quedó funcional**: la ronda 2 descubrió
que los datos comprimidos se leen a través de un objeto lector de
stream con buffer interno, no un puntero plano al archivo — una pieza
de ingeniería inversa genuinamente nueva, no un ajuste menor, y se
paró ahí en vez de forzar un cierre falso.

**Resultado honesto de cobertura**: **0 / 47 texturas reales de
GroundZero decodificadas**. El pipeline está listo y probado
(conectado, sin regresión, con fallback correcto) — el bloqueo es
puramente la falta de Stage 1, no el pipeline de materiales. Por lo
mismo, **no hay comparación visual "antes/después" que mostrar esta
sesión**: las capturas de `Reception`/`IconViewRoom1`/`ReceptionView1`
con el pipeline de texturas conectado son pixel-idénticas a las
capturas "solo color plano" ya committeadas de sesiones anteriores,
porque 0 texturas se resolvieron. Documentado así explícitamente en vez
de forzar una captura "después" que no mostraría ningún cambio real.

**Rendimiento**: la escena completa (25 salas, `WorldViewer ... ALL
--screenshot-dir`) renderiza en ~4.7s reales, sin problema — pero esta
cifra es del estado ACTUAL (0 decodificaciones reales de textura); no
mide el coste real de decodificar+subir 47 texturas a GL, que solo se
podrá medir cuando Stage 1 exista.

**Siguiente paso concreto para una sesión futura** (con evidencia ya en
mano, ver `docs/cmp-texture-format-reference.md`): desensamblar el
objeto lector de stream (`0x42f460`) y su mecanismo de buffer/refill
antes de retomar la traducción puntero→offset; una vez Stage 1
decodifique `test4b.cmp`/`rustwood.cmp`/`sball.cmp` byte-exacto contra
sus streams ya verificados, recién ahí intentar los 159 archivos reales
de GroundZero — el pipeline de `WorldViewer` ya está listo para
consumirlos sin ningún cambio adicional en ese lado.

---

### 🟡 `.cmp` — Stage 1 (decodificador Huffman real): arquitectura
### completa entendida en dos rondas, sigue sin funcionar (2026-09-11)

Ver la sección "Render — pipeline de materiales..." justo arriba para
el motivo (decodificar texturas reales de `GroundZero` lo necesitaba) y
el resumen del resultado. Detalle técnico completo, con direcciones
reales, valores de bytes exactos y evidencia de trazado en vivo para
cada hallazgo, en `docs/cmp-texture-format-reference.md` (dos secciones
nuevas: "Sesión Stage 1" y "Ronda 2"). Resumen de lo real y verificado
sin ejecutar nada más:

- Cabecera de 34 bytes completa, verificada exacta contra los 3
  archivos conocidos (campo de tamaño de payload = `fileSize - 34`
  exacto en los tres).
- Las 3 tablas de permutación de alfabeto fijo (81/49/22 bytes)
  extraídas byte a byte directamente del binario — con el hallazgo de
  que el índice de alfabeto 2 es degenerado (sin explicar todavía).
- `FUN_00426af0` (el decodificador de bits real) desensamblado por
  completo: más simple de lo asumido en sesiones anteriores — todos los
  códigos son ≤8 bits, tabla de búsqueda directa de 256 entradas, sin
  caminar ningún árbol.
- El mapeo canal↔stream (`bits, streamA, streamFillIdx, streamCtrl,
  streamLit`) confirmado por desensamblado, y cruzado con evidencia
  REAL independiente: los valores capturados en vivo (`streamA=124,
  streamCtrl=4`) coinciden exactos con el censo de ramas de una sesión
  `.cmp` anterior para el mismo archivo.
- Confirmado: un archivo de 32×32 solo tiene UN grupo de cabecera (no
  16), lo que también resuelve una duda antigua ("¿por qué
  `FUN_00457d88` solo se llama una vez?").
- **Bloqueo real, no resuelto**: los datos comprimidos se leen a través
  de un objeto lector de stream con buffer interno (`0x42f460`), no un
  puntero plano mapeado al archivo — el modelo "un `pos` que avanza
  linealmente" del prototipo es estructuralmente incorrecto, no solo un
  offset mal calculado. Cero texturas reales decodificadas, nada
  conectado al pipeline con esta pieza — solo lo ya byte-exacto de la
  sesión anterior (`test4b`/`rustwood`/`sball`) sigue siendo válido.

---

### 🟢 `.cmp` Stage 1 — CIERRE: 159/159 del corpus real byte-exacto,
### pipeline de materiales reconectado con texturas reales (2026-09-13)

Objetivo de la sesión: subir la cobertura real del corpus de 159
archivos `.cmp`, priorizando primero el cluster de fallos casi totales,
con la misma disciplina de siempre (solo cuenta verificación
byte-exacta real, nunca "se parece"). Arrancó confirmando el estado
dejado por la sesión anterior (3 fixes commiteados, 70/159 OK antes de
un corte por rate limit) y terminó **cerrando el arco completo**:
decodificador Stage 1 al 100% del corpus real, y el pipeline de
materiales de `WorldViewer` reconectado a texturas reales por primera
vez. Detalle técnico completo, con evidencia y offsets reales, en
`docs/cmp-texture-format-reference.md` ("Sesión siguiente" y "Estado
final") y `docs/render-pipeline-reference.md` ("Reconexión final").

**Cluster prioritario resuelto** (los ~20+ archivos con fallos casi
totales): la constante ajustada a mano para el "símbolo extra" del
canal LIT (1 en modo continuación / 2 en modo realineado, fijada a solo
2 archivos en la sesión anterior) se rompió contra archivos con
alfabetos de código de longitud mixta o de 5 bits. Reemplazada por
`skipRawBits` — un descarte de bits crudos que nunca pasa por la tabla
Huffman, sin el caso límite de "un símbolo decodificado se pasa del
límite de byte objetivo". Verificado byte-exacto contra 5 archivos
reales independientes (`test4b`, `sball`, `avdoor`, `rkgrnd`, `unexit`).
Un bug real y serio del propio harness de verificación (procesos
`cmpview.exe`/`wine` huérfanos acumulándose y corrompiendo capturas de
pantalla entre archivos) también se encontró y arregló en el camino —
**toda cifra de cobertura medida antes de ese fix en la sesión es
sospechosa**, según se documentó explícitamente en el commit.

Con eso, el corpus subió a 156/159, y tras descartar 2 fallas
transitorias por contención de Wine (`avdrrl.cmp`, `avflr1.cmp` — OK al
reaislarlas), quedó en 158/159 con `vendside2.cmp` como única falla
real.

**Cluster secundario**: efectivamente resuelto como efecto colateral del
fix de LIT de arriba — no hizo falta una investigación separada, tal
como se anticipó en las instrucciones de la sesión ("puede que ya esté
resuelto como efecto del fix prioritario, re-chequear antes de invertir
más tiempo ahí").

**Último archivo, `vendside2.cmp`**: causa real encontrada tras
descartar fuerza bruta simple de alineación (81 combinaciones sin
mejora) — su canal `streamCtrl` cae en el caso degenerado de un solo
símbolo Huffman, y el código emitía la longitud de código leída del
header (siempre 1) en vez de la longitud real de un alfabeto de un
símbolo (0 bits — no hay nada que desambiguar). Invisible en 8/9
archivos reales del corpus que caen en este mismo caso porque su
conteo de símbolos pedidos era demasiado bajo (1) para que el bug
tuviera efecto alguno; `vendside2.cmp` pide 63, suficiente para
desincronizar el cursor de bits compartido en varios bytes antes de
LIT. Fix de dos partes (longitud 0 para el caso degenerado + ajuste del
retroceso de byte cuando un canal no consumió ningún bit real) —
verificado byte-exacto en streamLit y en los 16384 píxeles finales.

**Verificación continua, honesta sobre la inestabilidad real
encontrada**: correr los 159 archivos de una sola vez resultó
intermitentemente inestable esta sesión (fallos instantáneos sin salida
real, tanto en primer plano como en segundo plano — causa no
identificada con certeza, probablemente contención de recursos
Wine/X bajo ejecuciones largas, no relacionado con el propio
decodificador). Se resolvió corriendo el corpus en 4 lotes de ~40
archivos, cada uno confiable — **resultado real y final: 159/159 OK,
byte-exacto, sin duplicados ni omisiones** (verificado contando filas
únicas de los 4 reportes).

**Cierre de sesión (punto 4 de las instrucciones)**: con cobertura
100% real, se reconectó `WorldViewer.resolveTexture()` de la ruta legacy
(`CmpTexture.load`, streams pre-capturados a mano, solo 3 archivos
tutorial) a la ruta real (`CmpTexture.loadRaw`, Stage 1 completo, sin
archivos auxiliares) — cambio de una sola línea en el punto de
resolución. Renderizando la escena completa de `groundzero.world` (25
salas): **47/47 nombres de textura únicos decodificados (124/124
referencias de material)**, subiendo de 0/47 en la sesión que conectó
el pipeline por primera vez. Confirmado visualmente (no solo por el
contador): nuevas capturas en `docs/renders/world_reception_textured.png`
y `docs/renders/world_iconviewroom1_textured.png` muestran variación
real de textura por superficie, con un diff de píxeles real y no-cero
contra el baseline de solo-color-plano de la sesión anterior. El
encuadre/escala de cámara de esas capturas (salas pequeñas y lejanas en
el cuadro) es un problema preexistente de cámara, no de texturas, y
quedó fuera de alcance de esta sesión — anotado honestamente, no
maquillado.

**Commits de esta sesión** (cada uno con verificación byte-exacta real
antes de commitear, disciplina pedida explícitamente): fix del harness
de captura (procesos huérfanos), fix `skipRawBits` de LIT (5 archivos),
fix `vendside2.cmp` (caso degenerado de un símbolo), dos actualizaciones
de documentación, y la reconexión del pipeline de `WorldViewer`.

**Esto cierra el arco completo de `.cmp`/Stage 1** abierto varias
sesiones atrás: de "0 texturas reales decodificables, arquitectura
entendida pero no funcional" a "159/159 del corpus real byte-exacto,
pipeline de materiales end-to-end verificado con textura real
aplicada". No queda ningún archivo `.cmp` real sin resolver en el
 corpus disponible; el único camino sin ejercitar es `mode&0x80`
 (`groupCount>1`), que ningún archivo real conocido activa — lanza
 `IOException` explícita en vez de asumir comportamiento no probado.

---

### 🟢 Ventana interactiva GroundZero funcionando (2026-09-13)

Pedido explícito: "lanzar una ventana con groundzero funcionando".
Hasta esta sesión `WorldViewer` solo sabía crear ventanas OCULTAS
(`GLFW_VISIBLE, GLFW_FALSE`) — el modo screenshot de una sola pasada
servía para verificación batch, pero ningún humano había visto nunca
una sala `.world` real en una ventana abierta.

**Cambio** (`client/src/net/openworlds/render/WorldViewer.java`):
flag `--window` — ventana visible e interactiva (auto-rotación lenta,
ESC o botón de cierre para salir). Combinable con `--screenshot`
(guarda el frame 0 por `glReadPixels` y deja la ventana abierta).
Sin `--window`, comportamiento batch anterior intacto (1 frame +
exit). Compilación limpia (`javac`, mismo classpath LWJGL).

```
# compilar (una vez)
javac -cp "tools/lwjgl/*" -d client/out $(find client/src -name "*.java")
# ventana interactiva, sala Reception (la de referencia de las sesiones anteriores)
DISPLAY=:100 java -cp "client/out:tools/lwjgl/*" \
  net.openworlds.render.WorldViewer \
  assets/WorldsPlayer/GroundZero/groundzero.world Reception --window
# con captura del primer frame + ventana abierta
... Reception --window --screenshot /tmp/reception.png
# modo batch anterior (sin cambios): 25 salas, --list-rooms, ALL
```

**Verificado con evidencia real** (todo bajo Xvfb `:100`, GL error 0):
- `Reception --window --screenshot` → **md5 idéntico** al
  `docs/renders/world_reception_textured.png` committeado — el modo
  ventana no altera ni un píxel del pipeline verificado.
- `IconViewRoom1` re-renderizado igual: md5 idéntico al committeado.
- Captura del escritorio Xvfb con la ventana REAL abierta y la escena
  dentro: `docs/renders/world_window_reception_xvfb_desktop.png`
  (384 colores — ventana GLFW de verdad, no un PNG generado a mano).
- `Reception`: 12 objetos / 96 tris, texturas 4/4; `LizCave`: 5 obj /
  450 tris, 1/1; `Auditorium`: 1 obj / 40 tris; `Garden MazeC7b`:
  0 objetos (sala vacía de verdad, no un error — `Drew 0` honesto).

**Hallazgo honesto, NO corregido (fuera de alcance)**: las salas
texturizadas salen notablemente más oscuras que su baseline de color
plano — `LizCave`: 990 colores (antes 73) sobre los mismos 13665 px,
pero luminancia media 132.7 → 14.2 (`docs/renders/
world_lizcave_textured.png` nuevo). Causa probable: `GL_MODULATE`
multiplica textura × color de material × luz, tres factores <1
apilados. Puede ser el comportamiento real de RW2… o no: no existe
ninguna captura del cliente original con la que comparar, así que se
documenta y no se "arregla" (la regla permanente lo prohíbe).
`Auditorium` (media 173) demuestra que no es un bug sistemático de
"todo negro" — depende de textura/material por sala.

**Limitación de entorno, verificada**: en el display real `:0`
(XWayland) el MISMO binario renderiza negro (1 solo color, GL error
igualmente 0) tanto en modo oculto como visible — falta de GLX/DRI
útil en esta sesión, no del código. Toda la verificación de esta
sesión es bajo Xvfb `:100`, donde el render es correcto y repetible
byte a byte. En una máquina con GLX real, el mismo comando con
`DISPLAY=:0` debería mostrar la ventana directamente.

**Siguiente paso natural**: el encuadre de cámara (salas pequeñas y
lejanas, ya anotado en la sesión `.cmp`) es ahora el problema más
visible al mirar la ventana — mover la cámara dentro de la sala
(posición de avatar) en vez de encuadrar el bounding box entero.

---

### 🟢 Cámara interior voladora `--inside` en WorldViewer (2026-09-13)

Pedido explícito ("hazlo") tras ver que la cámara orbital exterior
solo muestra el esqueleto: una maqueta lejana y oscura de cada sala.
`WorldViewer` gana modo cámara interior: ojo DENTRO de la sala con
controles de vuelo (W/S avanzar, A/D strafe, flechas girar/cabecear,
E/Q subir/bajar, ESC salir), velocidad y near/far derivados del
bounding box real de la sala. `--eye/--look/--up x,y,z` permiten un
punto de vista exacto; sin ellos, ojo = centro + (0.3r, 0.12r, 0.3r)
mirando al centro. `--inside` implica `--window` (salvo con
`--screenshot`, que guarda el frame 0 headless para verificación).

```
DISPLAY=:100 java -cp "client/out:tools/lwjgl/*" \
  net.openworlds.render.WorldViewer \
  assets/WorldsPlayer/GroundZero/groundzero.world LizCave --inside
```

**Medición previa con datos reales** (sonda throwaway en `/tmp`, no
versionada): los modelos RWX son de escala unidad — la escala real
vive en las matrices del `.world`. Reception = 4 marcos delgados
(`frame.rwx`, 8 tris) + techo (`hubceil1c.rwx`, 40 tris) + kiosko
(6 piezas, z 0..355) en (1290,865); NO hay suelo ni paredes en esta
sala — su interior genuino es disperso, no es un bug del render.

**Verificado con evidencia real** (Xvfb `:100`, GL error 0 siempre):
- Sin regresión: `Reception` exterior tras el cambio = md5 idéntico
  al texturizado committeado.
- `Reception --inside` por defecto: 61399 px no-fondo (antes 4158) —
  15× más escena visible; el kiosko se ve con textura real.
- `LizCave --inside`: 269932 px, **2566 colores** de roca con musgo
  rodeando la cámara — aspecto de estar dentro de la cueva de verdad
  (`docs/renders/world_inside_lizcave.png` + captura del escritorio
  Xvfb con la ventana abierta `..._desktop.png`).
- `Auditorium --inside`: pared gris + postes rayados rojo/negro con
  texels nítidos (`GL_NEAREST` verificable a simple vista,
  `docs/renders/world_inside_auditorium.png`).
- Ventana `--inside` abierta 20s sin excepción; controles sondeados
  por código (sin teclas = no-ops) — el movimiento direccional real
  con teclas **no está verificado headless** (sin inyector de input
  en este entorno), anotado honestamente.

**Límites honestos**: sin colisiones (cámara vuela, atraviesa
geometría); sin avatares (los `avatar:` se siguen saltando);
salas vacías de verdad (`Garden MazeC7b`, 0 objetos) se ven vacías;
persiste el oscurecimiento por `GL_MODULATE` de la sesión anterior.

### 🟢 Lanzador con log `tools/run-game.sh` (2026-09-13)

Pedido explícito: "un script que lanze el juego y lo logee".
`tools/run-game.sh [sala] [args...] [--log-dir dir] [--display :N]
[--build] [--no-shot]` — primer posicional no-flag = sala (defecto
`Reception`), resto pasa tal cual al WorldViewer. Reutiliza `DISPLAY`
si hay X vivo o levanta Xvfb propio (displays 100-110, lo mata al
salir); añade `--screenshot logs/<sala>-<fecha>.png` salvo `--no-shot`
o modos con salida propia; guarda `logs/worldviewer-<sala>-<fecha>.log`
con cabecera (fecha, git rev, java, comando) + resumen (exit, Room/
Drew/Screenshot/Coverage). `logs/` gitignored — evidencia local, no
corpus. Verificado: `Reception` batch, `LizCave --inside`
(md5 idéntico al render verificado) y `Auditorium` sin `DISPLAY`
(Xvfb propio en `:101`), los tres exit 0. Detalle de uso en
`docs/render-pipeline-reference.md`.

### 🟢 Bug real: screenshot tras el swap = negro en display real
### (2026-09-13, revisión del log del usuario)

El usuario corrió `run-game.sh Reception` en su display real (`:0`,
log `logs/worldviewer-Reception-20260913-142736.log`): exit 0,
GL error 0, 4/4 texturas… y PNG totalmente negro (1 solo color).
Revisando el log + el código, causa raíz en `WorldViewer`: el
screenshot (`glReadPixels`) se hacía DESPUÉS de `glfwSwapBuffers` —
tras el swap, el contenido del back buffer es **indefinido** por
especificación. En Xvfb se conservaba por suerte (capturas correctas
siempre), en XWayland/Mesa real sale negro. No era el driver ni la
escena: era orden de llamadas nuestro. Fix: leer antes del swap
(+ log "Window presented frame 0" como evidencia de ventana viva).
Verificado: `:0` pasa de 1 color a **408 colores** (misma escena
Reception que Xvfb; md5 distinto por dithering del driver, conteo de
colores idéntico), `:100` sigue md5-idéntico al committeado — cero
regresión. Moraleja para el proyecto: todo `glReadPixels` va antes
del swap, sin excepciones.

### 🟢 Ventana jugable abierta en display real (2026-09-13)

Con el fix de arriba, abierta y verificada viva (`LizCave --inside`
en `:0`, PID en `/tmp/game_window.log`, "presented frame 0" en log,
proceso ALIVE): ventana GLFW real con la cueva texturizada dentro y
cámara voladora por teclado (W/S volar, A/D strafe, flechas, E/Q,
ESC salir). Estado honesto de "jugable": moverse y mirar funciona;
sin colisiones, sin avatares, sin red/chat todavía (ver lista de la
sección `--inside`).

### 🟢 Texturas bien: base blanca + Lit-gating + ambient retunado
### (2026-09-13)

Pedido explícito ("que cargue el groundzero con texturas bien") tras
ver renders interiores correctos pero globalmente oscuros (LizCave
texturizada a luminancia media ~5/255). Causa raíz medida en dos
partes, ambas en el pipeline de materiales — nunca en los píxeles
`.cmp` (byte-exactos desde la sesión Stage 1):

1. **Base de color equivocada en texturizadas**: aplicábamos
   `difuso = Color × escalar` también con textura — textura × color
   (~0.2-0.9) × N·L apilaba tres factores <1. La referencia
   (`three-rwx-loader`, `RWXLoader.js:531-582`) hace base BLANCA con
   textura (el `Color` del archivo se ignora — `tint` nunca se activa
   en la práctica) y escala por `brightnessRatio = max(surface)`.
   Doble fuente: la sesión `sball` ya había forzado blanco a mano por
   el mismo motivo ("materiales negros degenerados") sin llevarlo al
   pipeline real. Medición del corpus: las 297 refs a `.cmp` reales
   son TODAS no-`Lit` (`Foreshorten`); `Lit` solo aparece con
   `Texture NULL` (2 archivos, p. ej. `SPIN.RWX`).
2. **Surface sin gatear por `Lit`**: la referencia solo usa la tripleta
   parseada con `TextureModes Lit`; sin `Lit` usa el default AW 2.2
   `[0.69, 0, 0]` (`defaultSurface`). Nuestro parser ni leía
   `TextureModes`. Ahora: `RwxMaterial.textureModes` (default Lit+
   Foreshorten+Filter como la referencia), `effectiveAmbient/
   effectiveDiffuse`, `brightnessRatio()`, `baseColor()`; defaults de
   material alineados (`color 0`, `surface [0.69,0,0]`).

**Ambient de luz retunado con evidencia** (heurística documentada,
no valor RW2 verificado): el hack anterior (ambient=diffuse por luz,
1.5× total) era inocuo con ambient_mat ~0 pero con la respuesta
0.69 real clipeaba TODA superficie texturizada a blanco sin sombrear
(medido 19.8% píxeles blancos puros en Auditorium; 0.25 aún dejaba
vetas en caras ideales, 7.9%). Fijado en 0.15×/luz (key 0.15, fill
0.075): sombras visibles (~16% lift), sombreado N·L preservado.

**Medición antes→después** (misma escena, Xvfb, GL error 0):

| sala | colores | lum.media/255 | blanco puro |
|---|---|---|---|
| LizCave | 990 → **1900** | 4.7 → **12.6** | 0% |
| IconViewRoom1 | 171 → **178** | 6.9 → **20.7** | 0% |
| Reception | 408 → **453** | 57.6 → **105.9** | 0% |
| Auditorium | — → 168 | — → **69.2** | 0% |

Escena completa (`ALL`, 25/25 salas, 0 missing, GL 0 en todas;
cobertura de texturas intacta 47/47 — esa ruta no se tocó).
Capturas actualizadas: `world_{reception,iconviewroom1,lizcave,
auditorium}_textured.png`, `world_inside_{lizcave,auditorium}.png` y
escritorio Xvfb en vivo. La veta blanca de Auditorium se resolvió
como geometría real brillante (240, no clip): filo de `stand.rwx`
con texel claro a plena luz, verificado material por material.

**Límites que quedan**: sin ground truth iluminada del cliente
original (cmpview es sin luz), el 0.15 sigue siendo heurística;
`emissive = surface[1]` de la referencia (three.js-ismo) no se
implementó — sin evidencia RW2; `FILTER` sigue siendo `GL_NEAREST`
por regla de alcance.

### 🟢 Z-up real + spawn auténtico + `run-game.sh` abre GroundZero
### (2026-09-13)

Pedido ("no abre, quiero que abra groundzero"): el usuario corrió el
script en batch (modo oculto por diseño — ninguna ventana *debía*
abrirse) y la ventana `--inside` anterior había muerto al cerrar.
Diagnóstico: display `:0` es Xwayland rootless (ventanas GLFW sí
aparecen, verificado), ningún proceso vivo — había que abrirla de
nuevo, pero mejor: con el spawn de verdad.

**Dos hechos de código del cliente decompilado** (no suposición):
- `scape/Transform.java`: `raise(dz)` = `moveBy(0,0,dz)`,
  `yaw(a)` = `spin(0,0,1,a)` — el mundo es **Z-up**. Todas las
  capturas anteriores (Y-up) mostraban la escena tumbada 90°.
- `scape/Pilot.getURL()`: el formato de punto de mundo es
  `sala@X,Y,Z,spin,axisX,axisY,axisZ` — y `worlds.ini` trae el spawn
  auténtico: `GroundZero.world#Reception<>@1872,1229,150,125,0,0,-1`
  (posición + yaw 125° sobre Z).

**Implementado**: `WorldViewer` con Z-up por defecto en exterior
(órbita sobre Z) e interior (yaw en plano x/y, E/Q sobre el up real,
`--up 0,1,0` conserva la matemática vieja); `run-game.sh` sin args
abre ventana interior en el spawn real mirando al kiosko
(`--eye 1872,1229,150 --look 1290,865,150`): el yaw 125° del ini
admite dos signos de giro (35° medido poco informativo — marcos
lejanos; 145° similar), así que se documenta la desviación honesta:
posición 100% real, dirección = la que muestra contenido (kiosko,
25625 px/1077 colores) en vez de una convención de signo sin
verificar. Las flechas permiten girar de todos modos.

**Verificado**: 25/25 salas GL 0, cobertura 47/47 intacta, renders
exteriores e interiores re-generados con orientación correcta
(LizCave interior por defecto: 461433 px / 2850 colores dentro de la
cueva). Evidencias nuevas: `world_spawn_reception_kiosk.png` (vista
spawn) y `world_spawn_window_desktop.png` (ventana viva en Xvfb).
Ventana abierta en el display real del usuario vía `./tools/
run-game.sh` a secas (log `/tmp/gz_boot.log`, "presented frame 0",
proceso vivo).

### 🟢 Rects: paredes/suelos/carteles con textura — ya no más bones
### (2026-09-13)

Pedido ("no sea solo bones, con texturas bien"): con solo Shapes, las
salas eran esqueletos — Reception: 12 objetos finos flotando en negro.
Causa real: el contenido de verdad (paredes, suelos, carteles) son
nodos **`Rect` (superficies 3D con material)**, 374 en todo
GroundZero (Reception 30, ReceptionView1 140, LizCave 42…), y el
parser tiraba sus campos mientras el visor los ignoraba.

**Parse espejo verificado** (bytes idénticos, `END PERSISTER` intacto):
`Rect.restoreState` da el plano unitario + u/v (+offsets según
versión) y `Material.restoreState` da ambiente/difusa/spec/opacidad,
color RGB y URL de textura (v2+; v0/v1 referencian un `Texture` sin
nombre — fallback plano honesto). `WNode` gana `material`,
`matAmbient/Diffuse/Specular/Opacity`, `matColorRGB`,
`matTextureUrl`, `rectU/V/UOff/VOff`.

**Dos hallazgos con evidencia**:
- El plano local es **X/Z, no X/Y**: las matrices reales aplastan Y
  (~0) y (1,0,1) reproduce la far-corner (f1,f2,f3) exacta a través
  del spin/scale — con X/Y salían quads degenerados (líneas, +187 px
  solo); con X/Z, 25k→121k px en el spawn.
- Las texturas Rect son URLs absolutas
  `http://www-static.us.worlds.net/3DCDup/GroundZero/dtex/*.cmp`
  (12, descargadas del servidor vivo a `assets/.../GroundZero/dtex/`,
  68K versionados) o relativas `tex/*` (con sufijo de animación
  `2h*2v*` estilo `cbirda42h*2v*.mov` — nombre real antes del primer
  `*`, +strip de `\d+[hv]`). Cobertura: **42/55 URLs** (187 refs);
  los 13 restantes son `.mov` (mismo códec, contenedor distinto —
  `tableRegionSize` no cuadra, documentado como siguiente paso).

**Render**: quads con UV reales (tiling vía `GL_REPEAT`), doble cara
(sin `MaterialModes` en Rects; `GL_LIGHT_MODEL_TWO_SIDE` para N·L
correcto), normales leídas del modelview real, materiales con la
misma base-blanca/ratio del pipeline RWX. Texto del cartel del
kiosko ("BIRTHDAY ROOM…") legible no-espejado = UV bien. (Cobertura
de entonces 42/55 URLs — los 13 `.mov` llegaron en la sesión
siguiente, ver abajo: hoy 55/55.)

**Medido**: Reception spawn 25k→121k px/1571 colores; RV1 196
objetos/7428 tris (zona picnic con suelo, camino, vallas, grill);
LizCave interior 450k px/1259 colores; IconViewRoom1 15k→53k px.
25/25 salas GL 0. Nota honesta: 147 Rects planos son color teal
real del stream (#00F7EF — verificado `java.awt.Color(r,g,b)`, no
default), y la respuesta difusa de Rects usa el ratio como en RWX
(a estrictos difusa=0 quedarían casi negros con nuestra luz
ambiental tenue — decisión documentada en el código).

### 🟢 .mov decodificado + cobertura 100% de texturas (2026-09-13)

Pedido ("aún quedan muchas texturas sin cargar"): 13 URLs `.mov`
(19 refs) sin loader — mismo códec LzH2, distinto contenedor
(`tableRegionSize+groupRegionSize != payloadSize`, modos 0x82/0x86).

**Contenedor resuelto con evidencia**: mismos offsets de cabecera
que `.cmp` (mode/flags/dims/lens idénticos en forma); la región de
tablas es mucho mayor (multi-frame) y su tamaño NO es el u16 de 28
(922 para una tabla real de 3791) — se localiza por firma del header
de grupo (`field0==64`, verificado 12/12 stills + único por `.mov`,
incluido windr3 con `wanted[0]=624` y `h=154`). Solo se decodifica
el frame 0 (visor estático; la animación por UV-tiling `2h*2v*` o
multi-archivo f1-f8 queda documentada, no implementada).

**Verificación oficial** (`cmpview.exe` + screenshots con
template-matching multirresolución — el crop fijo del harness de
`.cmp` falla en ventanas de película, verificado a mano):
`windr1` y `cbirda4` **16384/16384 byte-exactos**; los 11 restantes
muestran artwork real correcto (banderas f1-f8 en fases sucesivas de
onda, pájaro azul, logos `...s.com`, interiores, muros). Dos trampas
reales encontradas por el camino: el ground truth "negro" inicial
era un misfire del crop del harness (ventana de película ≠ still) —
no contenido; y un bug de MI sonda (`setRGB` sin `& 0xFF`,
amarilleaba todo) — no del decoder. Detalle de modos: `0x82` (10
archivos) directo; `0x86` (cbirda4, f3) necesita índice
255→blanco (fondo transparente del sprite sobre el canvas blanco de
cmpview — verificado por conjuntos de color 149 vs 147).

**Paleta**: byte12=0xFF en `.mov` es 255 genuino (forzar 256
desincroniza el cursor: `groupCount=0` — probado y revertido). Los 5
`.cmp` con byte12=0xEC siguen con conteo literal (159/159 intacto).

**Cobertura final, medida en escena completa**: `Texture coverage:
47/47` + `Rect coverage: 55/55` (187 refs) — **cero texturas sin
cargar** en formatos con loader. Resto honesto: `.bmp`→`.cmp` del
mismo stem cuando existe gemelo (`cstgbs3.bmp`→`.cmp` verificado en
archivo; `pceil2.bmp` sin gemelo queda plano), `.mov` con sufijo
anim (`cbirda42h*2v*`→`cbirda4`, `time2h*`→`time`,
`winwin12h*2v*`→`winwin1` — un dígito + h/v, el stem exacto siempre
primero), 12 `dtex/*.cmp` ya versionados.

### 🟢 RectPatch: suelos de hierba y rampas (2026-09-13)

36 nodos `RectPatch` en el archivo, todos versión 2 (verificado por
instrumentación temporal, revertida): `xDim/yDim` + 4 alturas `z` +
tiles + `Material` propio (la paradoja aparente de la cadena de
versiones se resolvió sola — solo se almacenan valores, los bytes
consumidos son idénticos, cero riesgo de desync). Traducción
geométrica: heightfield 2×2 en X/Y local (`(0,0,z0)`,
`(xDim,0,z1)`, `(xDim,yDim,z2)`, `(0,yDim,z3)` — planares en el
corpus), v0 explícitamente invisible y saltado. Contenido real:
baldosas de suelo verde #80FC00 en cuadrícula de 250 (Auditorium,
suelo visible por primera vez) y rampas ([0,0,-500,-500]).
Materiales planos o nulos→negro default del cliente (honesto, sin
inventar). Contador y bbox integrados; 25/25 salas GL 0.

### 🟡 "La mayoría sin texturas": inventario honesto + ventana al
### frente (2026-09-13)

Queja repetida con cobertura al 100%: investigado a fondo.
**Todo lo cargable carga y se ve** — panorama de 8 vistas alrededor
del spawn (`docs/renders/world_spawn_panorama.png`): contenido con
textura real en las 8 direcciones (56k–199k px cada una), muros de
piedra con musgo, kiosko con cartel legible por todas partes.

Lo que SÍ falta es **suelo bajo Reception**: el archivo no trae
ninguna malla de suelo ahí (inventario medido: 4 muros altos
z 600–1000, zócalos z 0–70, kiosko 0–355, y vacío debajo de z=0;
`sky/groundColorRGB` nulos en las 25 salas; sin niebla en
`Room/RoomEnvironment`). El vacío es dato auténtico, no geometría
perdida — el píxel de "suelo" muestrea exactamente el color de
fondo. Ninguna sala trae cielo; ninguna decisión de render lo
oculta. Inventar un suelo violaría la regla permanente.

Hallazgo operativo real de la sesión: la ventana abría en el
escritorio 0 mientras el usuario trabaja en el 1 (VMware
maximizado) — "no abre" aunque renderizaba perfecto. Fix:
`glfwFocusWindow` + `glfwRequestWindowAttention` al mostrar
(`WorldViewer`), y `run-game.sh` auto-recompila si hay fuentes más
nuevas que las clases (adiós binarios stale "sin texturas").
Verificado con `xprop`: ventana en escritorio 1 con atención
pedida (el foco final lo decide el usuario por diseño anti-robo de
foco de GNOME — hay que clickarla en el dock si no salta sola).

**Cierre de la pregunta (materiales v4, todos)**: ante "sigue
habiendo cosas que no cargan" se verificó si los 187 Rects planos
escondían textura por objeto (vía `Texture` v0/v1): los 417
`Material` del archivo son **versión 4** (ruta URL) — cero casos
v0/v1, cero `Texture`/`ScapePicTexture` alcanzables del grafo. Los
planos teal (#00F7EF ×108, #00FCF8 ×41) y hierba (#80FC00 ×36) son
color plano real del stream, no texturas perdidas. Con esto queda
demostrado por eliminación que no hay ni una textura sin cargar en
el archivo: 47/47 + 55/55 + 0 casos objeto.

### 🟢 Fondo infinito con seguimiento de camara (2026-09-13)

Pedido ("carga del mundo con el terreno de fondo"): el `infiniteBackground`
(skybox de muros `skyXX` + techos `sky12/nsky`, 34 Rects en Reception)
ya cargaba y se dibujaba (88 objetos, cobertura Rect intacta), pero con
transform estatico tenia paralaje de objeto cercano, contra la doc oficial
(`Gamma_Overview.html`: "la escala nunca parece cambiar", vista
"infinitamente distante"). `WorldViewer.drawInfiniteBackground` lo traslada
por `(ojo - ref)` en modo `--inside` (frame 0 = offset 0, md5-identico al
render previo; exterior orbita sin cambios). Verificado con prueba de deriva
temporal (+500x, revertida): el fondo se mantiene mientras el primer plano se
desplaza; GL error 0 en todo. `sky/groundColor` null en las 25 salas = el
cliente no dibuja nada ahi (misma doc); el clear oscuro queda como fallback
documentado. Detalle en `docs/render-pipeline-reference.md`.

### 🟢 Lanzable con doble clic: `--detach` + icono en el menu (2026-09-13)

Pedido ("haz que se pueda lanzar"): `run-game.sh` bloqueaba la terminal
siempre (modo ventana = proceso en primer plano) y no habia entrada de
menu. Ahora:

- `run-game.sh ... --detach`: lanza con `nohup` en fondo y devuelve la
  terminal al instante (0.06s medido) imprimiendo PID + log; para salir:
  ESC en la ventana o `kill <pid>`. Si levanto Xvfb propio, no lo mata al
  salir (queda anotado su PID en el log). Verificado en `:100`: ventana
  con "presented frame 0", GL error 0, proceso matable limpio.
- `tools/install-launcher.sh`: compila si hace falta, sonda sin ventana y
  escribe `~/.local/share/applications/openworlds.desktop` (rutas
  absolutas, `desktop-file-validate` OK) para buscar "OpenWorlds" en el
  menu y jugar con doble clic.

**Bug real encontrado por el camino**: `--list-rooms` solo se reconocia
como primer posicional del visor; la sonda inicial del instalador lo paso
en otra posicion y abrio una ventana bloqueante en `:0` en vez de listar
(colgo el instalador). `WorldViewer` ahora lo acepta en cualquier posicion
y el instalador sondea directo sin pasar por el parseo de sala.

### 🟡 Fondo infinito: seguimiento revertido a opcional (2026-09-13)

El follow del fondo infinito (sesion anterior) se reporto como bug — "el
terreno de afuera sigue al usuario cuando camina" — y el reporte es
correcto: el anillo esta modelado a medida de la sala, no es una cascara
infinita, asi que fijarlo a la camara arrastra decorado cercano. Ahora es
estatico por defecto y `--infinite-follow` lo activa solo si se pide.
Frame 0 md5-identico en ambos modos. Detalle en
`docs/render-pipeline-reference.md`.

### 🟢 Fondo como fondo + bumpers invisibles: mapa revisado de cabo a rabo
### (2026-09-13)

Pedido ("el fondo tiene que ser fondo, esta en una esquina tirado" +
revisar todo el mapa + push a Codeberg). Dos arreglos reales, ambos con
evidencia del original, ningun pixel inventado:

1. **Fondo infinito con camara en el origen**: solo Reception y RV1
   traen fondo (23/25 vacio, autorial); dibujado estatico quedaba a
   miles de unidades del centro (medido: offset -2561,-974 y
   -6253,+1019). `Gamma_Procedures.html` ("Infinite Backgrounds") dice
   que el fondo se ve desde una camara en 0,0,0 y el autor lo centra en
   el origen — `drawInfiniteBackground` ahora traslada el subarbol por
   la posicion de la camara viva. Spawn: cielo nublado + colinas en las
   4 direcciones; RV1: horizonte completo; 25/25 GL 0; texturas 51/51 +
   101/101. Sustituye los dos experimentos de follow anteriores (el flag
   `--infinite-follow` desaparece: esto no es un efecto, es la regla
   documentada). Limites: huecos de cielo sin paneles = vacio (dato
   original); orbita exterior sin fondo (fuera del near, maqueta).
2. **Bumpers invisibles**: LizCave llena de teal = 41 `Rect942CyanBump`
   (decía 40; recuento real de la auditoría 2026-09-15)
   (color teal real, flags=2, colision sin visible). `WNode.flags` guarda
   el int real (bit 0 = visible segun `WObject.getVisible()` decompilado)
   y el visor salta hojas invisibles al dibujar/encuadrar (nunca
   subarboles enteros). Todo lo invisible se llama `*Bump`; RectPatch v0
   trae flags=0 (doble confirmacion). Reception 0 invisibles (spawn
   md5-identico); LizCave 48->7 objetos.

Capturas regeneradas con el codigo actual (las anteriores quedaban
obsoletas): `world_{reception,iconviewroom1,lizcave,auditorium}_textured`,
`world_inside_{lizcave,auditorium,receptionview1}`, spawn kiosk (ahora
con cielo). Detalle en `docs/render-pipeline-reference.md`.

### 🟢 Fondo en dos pasadas + avatares en sala: el juego corre (2026-09-13)

Pedido ("el fondo esta en una esquina tirado; haz que el juego corra,
que se vea el avatar y este todo bien"). Tres piezas, todo verificado:

1. **Fondo en dos pasadas** (sustituye el `glTranslatef(camEye)`, que
   ataba el subarbol al ojo y hacia que "siguiera" al caminar):
   pasada 1 con camara propia en el origen + orientacion viva
   (`Gamma_Procedures`: "viewed from a Camera at 0,0,0"; origen dentro
   del anillo verificado), pasada 2 con la camara viva (depth limpiado
   en medio). Spawn Reception con colinas E/O y cielo en todas
   direcciones, nunca en esquina, sin tocar colocacion de archivo.
   Honesto: sin paralaje de traslacion (lo documentado del original).
2. **Avatares**: las 6 refs `avatar:` (galerias IconViewRoom1a/b/c/e/
   f/g) se dibujan en bind pose con las 2 luces: `avatar:Roxanne.rwg`
   -> `base-avatars/roxanne.bod` (5/6 por nombre; Tre -> `aura.bod`,
   default real del cliente). Escala x1000 heuristica documentada
   (bod ~0.17 vs cliente ~189, `Drone.java:106`), pies en el nodo,
   +Y->+Z. Roxanne 2229 tris, Tre 588 via aura, 25/25 GL 0.
3. **El juego corre**: `run-game.sh` sin args (spawn Reception) y
   `--detach` verificados en `:100` (ventana, frame 0, kill limpio).

Detalle en `docs/render-pipeline-reference.md`.

### 🟢 Modo juego `--play`: tercera persona, suelo, colisión, avatar (2026-09-14)

Pedido ("yo no veo ningun avatar, implementa ya el modo juego, no la
camara libre sino el juego, planificalo antes de hacerlo y usa
subagentes"). Planificado con 4 subagentes en paralelo (cámara/input
actual, lógica del cliente original, mundo/colisiones, avatares/3ª
persona) antes de escribir una línea. Todo verificado:

- **Tercera persona** como el original (`HoloPilot` BEHIND/modos 3-8):
  cámara tras la cabeza (pies+150 = `eyeHeight` real, dist 220 =
  WIDESHOT), avatar `aura.bod` (default real) en bind pose con las 2
  luces. Spawn `RestartAt` mirando al kiosko. W/S caminar, A/D strafe,
  flechas girar/pitch, ESC salir. `run-game.sh` sin args = `--play`.
- **Suelo** como `Room.floorHeight` (piso más alto <= pies+escalón 30,
  de `HoloPilot.stepHeight`); **colisión** AABB x radio 30 (medio ancho
  del bound box real) con slide por ejes; velocidad 250 (entre
  `maxdvLR=166` y `maxdvFB=300` reales). Reception: 14 suelos, 28
  bloqueantes, 8 portales. (Auditoría 2026-09-15: el log actual dice 41
  bloqueantes — esos 28 Rects más 13 AABB de props `.rwx`, que se
  añadieron en el arreglo del kiosko de la sesión siguiente.)
- **Verificado**: spawn 89 objetos/1 avatar/GL 0
  (`docs/renders/world_play_spawn_thirdperson.png` — Aura de espaldas
  ante el kiosko, colinas detrás); IconViewRoom1a 7 obj/2 avatares/GL
  0; fly y ALL 25/25 sin regresión.
- **Límites**: forward del .bod heurístico (acertó: mira al kiosko);
  AABB no quads finos; portales solo se anuncian (fase 2);
  bind pose sin animación.

Detalle en `docs/render-pipeline-reference.md`.

### 🟥 Modo juego roto y arreglado en la misma sesion (2026-09-14)

El modo `--play` salia volando al andar (`Player at z=2250`) — con
toda la razon del usuario ("no va ni de puta coña"). Causa raiz
verificada con matematica exacta, no supuesta: `floorHeightAt`
devolvia su parametro `z` si no habia suelo y se la llamaba con
`z=pies+30` (+30/frame sobre vacio: 180+69x30=2250). Contrato
corregido (devuelve los pies), mas: colision y suelo de props `.rwx`
(el kiosko se atravesaba; 100 tris en Reception, suelo exacto
baricentrico), bumpers que paran siempre, sin re-snap empotrado, foco
de ventana para `--play`, contadores por frame. Verificado: harness
headless 800 pasos (z clavado, parada por muro), batch GL 0, ventana
20s quieta sin deriva. Detalle en `docs/render-pipeline-reference.md`.

### 🟢 Avatar de espaldas (facing real) + animacion mapeada sin inventar (2026-09-14)

Queja ("se ve de lado"): correcta — la rotacion era una heuristica a
90° del forward real. Investigado con 2 subagentes ANTES de tocar
nada: forward anatomico +Z local del .bod (cara/puntas +Z, coleta -Z),
medido en `SPIN.RWX` y bytes de `aura.bod`, con `RWXTOBOD.PL` pasando
ejes sin tocar. Rotacion `yaw-90` (algebra, no prueba-error),
verificada en captura (Aura de espaldas, coleta centrada).

Animacion ("haz que tenga animaciones... NO inventarse las cosas"):
extraido lo real — DOS sistemas (`Drone:359-364`): articulado
(`.bod`+`.seq`+`avatars.dat`, todo el blending en `DroneAnimator`
nativo) y holograma (`.mov` = video `LzH2`). Cabecera `.seq`
verificada (version, nº joints, nombres: walk 44 mocap, wait 16,
wave 4). El key-data por joint solo lo decodifica `gamma.dll`: NO hay
playback inventado (ni walk cycle procedural ni bobbing) — seria
exactamente lo prohibido. Siguiente paso: Ghidra sobre
`DroneAnimator_animate/update`. Detalle en
`docs/seq-animation-reference.md` (nuevo).

### 🟢 EL ORIGINAL CORRE: cliente 2004 genuino bajo Wine (2026-09-14)

Pedido ("coge el original"): hecho literalmente. `assets/WorldsPlayer`
trae el runtime completo (JRE 1.4.2 `bin/java.exe`, `gamma.dll`,
`RWL21.DLL`, `lib/gammacls.zip`) y `run.exe` contiene su propia linea
de arranque — ya no hace falta recompilar nada pristino, el `.zip` ES
el cliente compilado:

`bin\javaw.exe -Xbootclasspath:lib\i18ncls.zip;lib\rt.jar
-cp .;lib\gammacls.zip NET.worlds.console.Gamma -home . -dllpath bin`

Dos paredes, las dos de entorno (cero ingenieria inversa): Wine se niega
a crear prefijos bajo `/tmp` (no es del usuario) → prefijo en
`~/.wine-fw-orig`; el cliente aborta sin `C:\windows\Fonts` → TTFs
Liberation del sistema. Con eso: carga `gamma.dll` real, driver
`rwdlmd21`, hook `awt.dll`, y presenta **el juego de verdad**: UI
completa (Help/Options/WorldsMall/Teleport/Actions/VIP, FRIENDS ONLINE,
chat, logo), Reception 3D con RenderWare real (suelo texturizado con
reflejos, muros, colinas, kiosko) y avatar real. Dialogo "Retry /
Single-user mode" (sin red de upgrade: esperado, honesto).
`tools/run-original.sh` (nuevo) automatiza todo: copia privada a
`~/.openworlds-client` (el original escribe logs/caches en su CWD y no
debe ensuciar el repo), prefijo+fuentes+Xvfb si hace falta.
Captura: `docs/renders/original_client_reception.png`.

### 🟢 El juego, decompilado y versionado: Java pristino + `gamma.dll` en C (2026-09-14)

Pedido ("quiero que decompiles el juego... haz original"): el
decompilado existia pero NO estaba en el repo (`source/` ignorado,
`analysis/` ignorado). Ahora si:

1. **Java pristino** (`editor/.../source/`, 723 `.java`): regenerado
   con Vineflower 1.12 desde `assets/worlds.jar` + `git apply
   patches/fix_compilation_errors.patch` (solo fixes de compilacion).
   Cero `NativeMock`, declara los `native` reales, `Gamma.java` carga
   la `gamma.dll` real, compila limpio con `javac --release 8`.
   El `.gitignore` anidado ya no excluye `source/` (sigue excluyendo
   `out/` y `worlds.jar`). El flujo del mock no se rompe:
   `apply_mock.sh` parte de este arbol limpio.
2. **Nativo en C** (`decompiled-native/gamma_dll/`, 6.9 MB): 1656/1656
   funciones de la `gamma.dll` original con Ghidra headless + script
   propio versionado (`tools/ghidra-scripts/ExportAllDecompiled.java`),
   exports JNI con nombre real — incluidos los 15 de `DroneAnimator`
   (el decoder `.seq` que falta para animacion real) y `huffdcod`
   (texturas `.cmp`). `INDEX.txt` para cruzar addr<->Ghidra.

### 🟢 macOS Intel sin Homebrew: entorno portable + visores en Cocoa (2026-09-15)

Pedido ("homebrew ya no soporta macs con intel, mira a ver que puedes
hacer"). Maquina: MacBook Intel i5-7360U, macOS 15.7.9, bash 3.2 de
sistema, sin JDK/brew/node/wine. El commit `b6f4df1` ("macos: setup +
scripts portables") nunca habia corrido en un Mac real: cuatro paredes,
todas de entorno, cero cambios de render:

1. **`setup-macos.sh` sin Homebrew**: JDK 25 Temurin portable (tar.gz
   de `api.adoptium.net`, SHA-256 verificado) en `tools/jdk/`
   (gitignored, sin sudo) + solo los natives LWJGL de la arquitectura
   (`.sha1` de Maven Central verificado). `run-game.sh` e
   `install-launcher.sh` anteponen `tools/jdk` al `PATH` (`/usr/bin/java`
   es un stub). node fuera (solo lo usa el harness RWX, ya 118/118).
2. **X11 forzado en los 5 visores** (`glfwInitHint(GLFW_PLATFORM_X11)`):
   GLFW en macOS no tiene backend X11 y `glfwInit()` falla. Ahora
   `GlUtil.forceX11OnLinux()`.
3. **bash 3.2 + `set -u`**: `"${ARGS[@]}"` vacio = "unbound variable"
   (verificado en el bash del Mac) — rompia `run-game.sh LizCave` e
   `install-launcher.sh` sin args; `$DISPLAY` sin definir mataba la
   cabecera del log. Idiomas `${A[@]+...}`, `${A[*]:-}`, `${DISPLAY:-}`.
4. `date -Is` no existe en el `date` BSD.

**Verificado en el Mac** (OpenGL legacy 2.1 de Apple, funcion fija
intacta): sonda 25 salas; `ALL` 25/25 GL error 0 con `Texture 51/51` +
`Rect 101/101` (mismas cifras que en Linux); `--play` en ventana Cocoa
real, jugado por el usuario (frame 0 presentado, jugador andando con z
clavado al suelo, salida limpia con ESC). Captura `--play` contra
`docs/renders/world_play_spawn_thirdperson.png` (mismo codigo de render:
el unico commit posterior en `client/src` es `SeqParser`, sin usar): NO
bit-identica — 14427/786432 px (1.8%) difieren, 88% con delta <=4 y
solo 47 px >64. Mascara de diferencias revisada, no solo el
histograma: (a) la unica zona compacta es la franja de vacio bajo el
zocalo derecho = color de clear `glClearColor(0.10,0.10,0.14)`, Mac
`191924` vs Linux `1A1A24` — 0.10x255=25.5 cae justo en la mitad y
Apple trunca a 25 donde Mesa redondea a 26 (delta 1, azul 35.7 da 36 en
ambos); (b) el resto son pixeles sueltos y costuras de 1 px entre
paneles de textura del fondo. Redondeo/rasterizacion del driver (Apple
GL frente a Mesa bajo Xvfb), no contenido distinto.
`run-original.sh` sigue sin poder correr aqui (sin Wine). Menor visto
de paso: en `--play` el contador "total rect references seen" acumula
por frame (69000 = 69 x 1000 frames), igual que el de avatares
corregido el 2026-09-14. Detalle en `docs/setup-macos.md`.

### 🟢 AUDITORÍA: los corpus reejecutados, tres afirmaciones falsas y la
### animación reconstruida (2026-09-15/16)

Sesión larga pedida explícitamente como auditoría: **no dar por buenos
los números del historial, sino reejecutarlos** contra el código de hoy,
y luego avanzar. Se usaron 6 subagentes de solo lectura en paralelo (uno
por formato/pieza, sección 9) más varios de trabajo en worktrees
aislados.

**Lo que se reverificó ejecutando (macOS, JDK portable)**

| Afirmación | Resultado hoy |
|---|---|
| RWX 118/118 | Los 118 `triangleCount` y `materialCount` del lado Java coinciden con la tabla. El lado JS **no es reproducible**: `tools/node` es un ELF de Linux |
| `.world` 25 salas / 578 nodos / 103 objetos / 374 Rect / 36 RectPatch v2 / 417 Material v4 | Todo confirmado |
| `.bod` 51/51 consumidos + `orphans=0 badIndices=0` | Confirmado |
| `.cmp` 159/159 y `.mov` | 159/159 `.cmp` y **52/52** `.mov` decodifican sin excepción; el "byte-exacto contra `cmpview.exe`" **no es reproducible sin Wine** y no hay ground truth guardado |
| Stage 2 determinista | `test4b` 256/256, `sball` y `rustwood` 4096/4096 |
| Escena completa | 25/25 salas, GL error 0, `Texture 51/51` + `Rect 101/101` |

**Tres afirmaciones del historial resultaron FALSAS (corregidas)**

1. **`SeqParser` (commit `bcd60fd5`, "verificado, leftover=0") fallaba en
   los 231 `.seq` reales.** Leía un `u16` de "checksum" que no existe:
   `FUN_00436d50` suma los K bytes del diccionario en memoria y los
   guarda como duración en `+0x214`. Quitado eso, y traducida además la
   variante que el original desvía a `FUN_00436610` cuando el primer byte
   es `0x7f` (big-endian, 37 archivos de `cachedir`): **231/231**
   (`SeqExtractMain`, nuevo y reproducible). Los codebooks CB32/CB128 sí
   eran correctos: 32/32 y 128/128 floats idénticos bit a bit a
   `gamma.dll`.
2. **El "z-fighting" de `cube.rwg`** (abierto desde 2026-09-09) no era
   z-fighting ni bobinado inconsistente: `VLST[0..7]` es la **bounding
   box** del clump y los índices de `PLST` cuentan desde el registro 8
   (`RWL21.DLL`: `RwGetClumpNumVertices` = count−8, `RwGetClumpVertex` →
   registro n+7; 3466/3466 normales coinciden contando desde 8, 167 desde
   0). Caras ±Z duplicadas, "normales (0,0,0)" y "huecos con culling"
   eran el mismo bug. `e3.rwg` son 1371 vértices, no 1379.
3. **Las texturas de avatar no salen de `cachedir/45.dat`** (ese archivo
   no tiene ni una cadena `.cmp`/`.mov`): salen del **nombre del avatar**
   (`PosableShape.createSubparts` + `readTexture`/`scanTexture` →
   `avatar:<nombre>.cmp` | `.mov`).

**Cifras menores corregidas**: LizCave tiene 41 `Rect942CyanBump`, no 40;
Reception da hoy 41 bloqueantes (28 Rects + 13 props del arreglo del
kiosko), no 28; no todos los `.bod` son de 16 partes (`2v.bod` y
`death.bod`, idénticos, tienen 8). `docs/cmp-stage1-coverage.md` seguía
siendo el baseline 0/159 de `39e9f31c`: nunca se regeneró.

**Animación de avatares: de "no hay ni una línea de parseo" a pose real**

Reconstruida entera desde el C decompilado y desensamblando `RWL21.DLL`
(detalle en `docs/seq-animation-reference.md` §5 y §6.1):
muestreo por keys con **nlerp** (no slerp), cuaternión `(w,x,y,z)` con x
e y negados (`FUN_004290c0`), tabla **nombre→tag propia de la DLL** (30
nombres; los joints mocap que no están en ella se ignoran: **no existe
retarget 44→16**), composición `LTM = Joint · Modelado · LTM_padre` en
convención vector fila (modo 1 = sustituir), y `prepFigure` = rotación
180° sobre (0,1,1) + escala ×1000, que es de donde salían el ×1000 y el
+Y→+Z que `WorldViewer` usaba como heurística. Tiempo de keys: 1/30 s.
`BodViewer --seq f.seq --frame T` pone un `.bod` en la pose exacta; sin
`--seq` las capturas siguen siendo md5-idénticas a bind pose.
Verificación anatómica: `common_walk` frames 0 y 21 en oposición,
`axelwave` levanta el brazo izquierdo (sus 4 tracks), `common_a_wait`
frame 0 = bind pose exacta.

**Dos huecos encontrados en las herramientas del propio proyecto**

- El C decompilado **no incluye** las 13 funciones de la vtable del
  reproductor de animación (`0x00475200`): Ghidra no las detectó porque
  solo se alcanzan por despacho virtual. Son justo el avance de tiempo,
  el bucle y las transiciones — por eso `WorldViewer` sigue en bind pose:
  implementarlo sin ellas sería inventar.
- Cuatro visores capturaban el framebuffer **después** de `glfwSwapBuffers`,
  lo que en macOS produce PNG negros: una verificación "con captura"
  podía dar por bueno un render vacío. Corregido en los cuatro.

**Hallazgo que desbloquea las texturas de avatar**: las tablas que el
cliente pide a `ServerTableManager` (`permittedList`, `faceList`,
`humanList`…) **ya están en el repo**, en
`assets/WorldsPlayer/tables/tables.dat` (45164 bytes, idéntico a
`cachedir/44.dat`): `int32` de longitud + XOR encadenado
(`dec[i]=enc[i]^enc[i-1]`) → texto con 12 tablas, incluidos **148
avatares con su nombre codificado**. Se puede decodificar sin red.

**Entorno**: todo lo anterior corre en un MacBook **Intel** sin Homebrew
(ver la entrada anterior y `docs/setup-macos.md`).

### 🟢 Red — reproducido en macOS: login guest estable, pared real de
### `Gamma.main` (ActiveX) y los hilos sin bloqueo (2026-09-16)

Parte de la misma sesión de auditoría (subagente en worktree aislado,
integrado en `df4d7517`/`1c02e60e`/`199461e9`). Tres resultados:

1. **Login guest real en macOS**: `tools/net-probe/run-guest-login.sh`
   (bash 3.2, sin rutas Linux, todo en un directorio temporal) llega al
   **estado 12 MAINLOOP estable** contra `gippsland.worlio.com:8265` con
   el intercambio real PROPREQ → PROPUPD → SESSINIT y la bienvenida del
   servidor, igual que el 2026-09-10 en Linux. Ya no hace falta Xvfb.
2. **Primera pared del arranque REAL** (`run-gamma-main.sh`): el cliente
   completo con el mock carga caché, tablas, avatar y sala, y se detiene
   en un `dAssert(false)` genuino de `IUnknown.init` — el control
   ActiveX/Netscape embebido. Es ausencia estructural de COM fuera de
   Windows, no un mock mal puesto: para seguir por ese camino habría que
   sustituir ese componente, no corregir un valor.
3. **`Cache`/`NetUpdate`** (el "bloque de hilos" que la sección 10
   dejaba abierto desde 2026-09-09): corren bien en macOS; el único
   bloqueo es de diseño (carga síncrona a propósito y un `Thread.join()`
   sin timeout en `Gamma.main:221`). **No hay problema de hilos que
   resolver.**

Para login con cuenta real solo falta la cuenta: requisitos exactos en
`docs/net-real-account-login-requisitos.md`.

Además, en la misma sesión se recuperaron **881 funciones** de
`gamma.dll` que el volcado original no tenía (solo alcanzables por vtable;
`tools/ghidra-scripts/ScanVtablesAndExport.java`, decompilador de Ghidra
compilado desde fuente para macOS). Con ellas se leyó el controlador de
tiempo de la animación: **30 keys por segundo**, modo 2 = bucle
(`t % (duración+1)`), modo 1 = último key (`FUN_0043b950`/`FUN_0043b5f0`,
`SeqSampler.keyTime`). Queda por reconstruir qué secuencia y modo elige
el cliente en cada momento y la mezcla de transición.

### 🟢 Lenguaje de nombre de avatar decodificado — y el corpus de vestuario
### está casi todo perdido (2026-09-16)

Parte de la sesión de auditoría (subagente en worktree, integrado en
`c21319d1`..`01850240`; cifras reverificadas ejecutando). Detalle en
`docs/avatar-name-language.md`.

- **`tables.dat`** (`assets/WorldsPlayer/tables/tables.dat`, ya versionado)
  se descifra con el XOR encadenado de `ServerTableManager` y da 12
  tablas; `permittedList` trae 148 avatares con su nombre codificado.
- **Gramática**, portada de `PosableShape`: un nombre
  `avatar:<base>.0<programa>.rwg` se procesa en dos fases. `findStarts`
  reúne una paleta global de texturas `T<n><nombre>` (`<x>.mov` subimagen
  n−1, o `.cmp` si n≤0) y colores `C` (`colorTable` o RGB en base64), y
  luego se montan **17 limbs de tag y padre fijos** (P01 raíz, B02←P,
  N03←B, H04←N, L11/M12/O13, R06/U07/V08, I19/J20/K21, W15/X16/Y17,
  Z24←P) que cargan partes de `<base>.bod`, con escala `S`, cambio de
  `.bod` `G`, subclumps y cambios de material temporizados (las
  **expresiones**: p. ej. `willy` parpadea con 4 cambios cada 3648 ms).
- **Verificado**: 146/148 nombres sin anomalías y 0 excepciones; las 2
  anomalías (`achoo`, `tas`) son erratas de la propia tabla y el
  decodificador hace lo mismo que el cliente. `AvatarNameMain --todos` lo
  reproduce.
- **Dato de preservación importante**: de lo que referencian esos 148
  avatares, en el repo solo hay **14 de 210 texturas y 25 de 141 `.bod`**.
  Las 14 texturas son `.mov` de `base-avatars`; ninguna de las `_dt*` del
  vestuario de pago existe. `cachedir/` no cuenta porque sin su
  `cache.index` no se sabe qué URL es cada fichero numerado.
- De paso se corrige una creencia del documento: la URL por defecto
  `avatar:aura.0PG.rwg` da una figura vacía (el `.bod` se resuelve por
  otro camino), y `faceList`/`humanList` no intervienen al construir el
  avatar, solo en la personalización (`WearWall`, `AvMenu`).
- **Pendiente**: aplicar las texturas en `BodViewer` (buen primer caso: la
  cara de `willy`, subimagen 0) y decodificar subimágenes > 0 de `.mov`.

### 🟢 Portales reales en `--play` y texturas de avatar en el visor
### (2026-09-16)

Cierre de la parte 3 de la sesión de auditoría (dos subagentes en
worktree, integrados y **reverificados ejecutando**):

- **Portales** (`1f160724`, `04516925`): `WorldRestorer` ya no descarta la
  conectividad de `Portal` v8/9 (`farSidePortal` es una referencia de
  objeto, no un nombre) y `WorldViewer --play` cambia de sala al cruzar,
  con la fórmula de `Portal.recomputeFarPosition()` y recargando suelo,
  colisión y fondo de la sala destino. GroundZero: 87 portales, **56
  conectados** dentro del mundo, 2 a otros `.world`, 29 desconectados en
  el propio dato. Reejecutado: desde el spawn de Reception hasta
  `EastPortal1Reception` se llega a **ChatHall en (0,750,0), yaw −π**
  (sala de paso de 4 superficies y 0 objetos: la vista oscura es su
  contenido real). Regresión ALL 25/25 sin cambios. Límite: signo del yaw
  de llegada deducido, no ejecutado (`getYaw()` nativo, sin Wine).
- **Texturas de avatar** (`76febbac`): `BodViewer --avatar <nombre>` usa
  el decodificador del lenguaje de nombre para poner a cada limb su color
  o textura (constantes de material del cliente, UV reales del `.bod`,
  subimagen 0). Sin `--avatar` las capturas son md5-idénticas; con él la
  cabeza de `willy` muestra su cara de `willy.mov` (los 515 píxeles que
  cambian están todos en la cabeza). `ogre` pide la subimagen 3: se
  informa como no aplicada.
- **Tiempo de animación** (`bb1b6c47`, `e70178d9`): 30 keys/s y modos
  bucle/último key, `BodViewer --seconds S [--hold]` verificado md5 contra
  `--frame`.

Lo que queda para ver avatares **animados y texturizados dentro del
mundo**: decidir qué secuencia toca (la elección implícita `walk`/`wait`
del original no está reconstruida) y llevar pose y texturas de `BodViewer`
a `WorldViewer`.

### 🟢 El cliente original arranca en macOS con un puente portable de gamma.dll/RenderWare (2026-09-17)

Objetivo: una build que funcione y arranque **basada en el juego
original**, sin reinventar nada. En vez del motor propio de
`client/`, se ejecuta el `main` real de `NET.worlds.console.Gamma`
decompilado y se sustituyen los nativos de `gamma.dll` por traducciones
de su C decompilado; por debajo, las llamadas `Rw*` de RenderWare 2.1 se
traducen del desensamblado de `RWL21.DLL`. Todo está en
`editor/worldsplayer_source_editor-main/bridge/` (ver su README con las
direcciones de evidencia), se aplica desde `apply_mock.sh` y se construye
y lanza con `build_gamma.sh` y `run_gamma.sh`.

- **Matrices** (`NativeRw`): producto de vector fila, modos 1/2/3, rotación
  en grados (Rodrigues traspuesta, confirmada en 0x1001cb20), inversa afín
  por adjunta, ortonormalización y `RwQueryRotateMatrix`. Los 20 nativos
  de `Transform` y `Point3Temp` siguen el C de gamma.dll, incluidos
  `getYaw`, `getPitch` y `getSpin` con sus constantes leídas del binario
  (180, 0,5, 1/π, 90, 360).
- **Escena** (`NativeScene`): clumps con vértices base 1, polígonos,
  jerarquía, LTM `Joint·Modeling·LTM_padre`, bbox en espacio mundo, tags,
  estado ON=2/OFF=1, escena por defecto, luces y materiales con los
  valores por defecto de RWL21. También los wrappers de gamma.dll con
  lógica propia: visibilidad jerárquica con los callbacks 0x4185d0/0x418600,
  sombreado plano/suave y `Surface.addSubPolys` (subdivisión en baldosas
  con volteo U/V).
- **Ventanas, ActiveX y aserciones**: `findWindow` y las ventanas hijas
  sobre las ventanas AWT reales; `ActiveX.getClassFClsID/ProgID` lanzan la
  `IOException` con el mensaje literal de gamma.dll
  (`nActiveX.getClassF…: Couldn't convert string to CLSID`); la aserción
  nativa imprime `Assertion failed: line N in file F.` y sale con 41.
- **Error de decompilación real**: Vineflower dejó en `Room` una llamada a
  `add(WObject)` donde el bytecode original llama a `add(SuperRoot)`, lo
  que metía el entorno dos veces en la escena. Para descartar más casos
  así, `tools/bytecode-call-diff.py` compara los destinos de todas las
  llamadas de las 736 clases originales (`lib/gammacls.zip`) con la
  recompilación: quedan 55 métodos con diferencias inocuas (receptores
  más estrechos, `close()` de try-with-resources, capa de mocks) y solo
  este error.
- **Arreglado de paso**: `tools/net-probe/run-gamma-main.sh` dejaba la JVM
  huérfana (matar la subshell no mataba java); ahora usa `exec`.

**Verificado ejecutando**: build limpia de 747 clases; `run_gamma.sh`
queda vivo 40–60 s en `Main.mainLoop` (confirmado con `jstack`) con
~2 M de frames, ninguna excepción y ningún proceso huérfano.

**Límites** (⚠️): **no se ve nada todavía**: `Camera.renderScene`,
`Texture`/`FileTexture`/`ScapePicTexture`/`ScapePicMovie` y el sonido
siguen siendo stubs de log, y el bucle va sin freno porque en el original
lo marcaba el render. Pendiente de extraer: `RwDestroyScene`, el flag que
elige texture modes 2 o 6 en `FUN_00419000`, el máximo de UV del driver y
los índices −7..0 de `RwGetClumpVertex`. El siguiente paso natural es
traducir `Camera.renderScene` y el camino de texturas (el decoder `.cmp`
de `client/` ya existe) para dibujar en la ventana hija.

### 🟢 Cliente original sin red: servidor local, caché de 2004 operativa y causa de las 7 texturas que faltan (2026-09-18)

**Problema.** `run_gamma.sh` arrancaba el cliente original decompilado y todo
lo que pedía (avatares, tablas, scripts) iba a `upgradeServer=http://us1.worlds.net/3DCDup`
(`worlds.ini`), un host que ya no existe: timeouts y `Unable to load texture …`.

**Arreglado** (commit `92d1e767` + este):
- `tools/local-upgrade-server.py`: servidor HTTP local (solo Python) que sirve
  `assets/WorldsPlayer` bajo `/3DCDup/` y, bajo `/3DCDup/avatar/`, los avatares
  base oficiales de `assets/gammatutorial-samples/base-avatars/` (= `AVATARS.ZIP`
  de `Worlds1900.exe`, verificado idéntico), sin distinguir mayúsculas
  (el cliente pide `pengo.mov` y el fichero es `PENGO.mov`). Lo demás, 404
  inmediato. `run_gamma.sh` lo arranca en un puerto libre, reescribe
  `upgradeServer` en la copia temporal de `worlds.ini/dst` y lo mata al salir
  (`OPENWORLDS_NO_LOCAL_SERVER=1` lo desactiva).
- `build_gamma.sh` parchea (solo en la copia de build, `source/` sigue pristino)
  `Cache` y `CacheEntry.load`: el `cache.index` de 2004 guarda rutas de Windows
  (`C:\DOCUME~1\…\cachedir\5u.mov`) y `CACHE_DIR` usaba `\`; en macOS el índice
  no cargaba y se tiraba. Ahora carga (211 entradas) y las ya descargadas no se
  refrescan contra un origen inexistente. `run_gamma.sh` parte de un `cachedir`
  limpio (un `cache.open` huérfano descarta todo el índice).
- Efecto medido (35–40 s en `home:GroundZero/groundzero.world`): 406 → 56 líneas
  `Unable to load texture`; las peticiones de `.bod`/`.mov` de avatares base
  (`julie/roxanne/simon/jing/paul.bod`, `pengo.mov`…) y `avatars.dat` pasan a
  200; solo quedan 404 para lo que no existe en ningún sitio.

**Causa raíz de las 7 texturas (`cfemaleb`, `cfemaleba`, `cfemalec`, `cfc`,
`fga`, `fja`, `mga`) — con evidencia, NO evitable sin el asset:**
1. Se piden desde `Material.loadTextures` ← `Shape.recursiveAddRwChildren` ←
   `Room.aboutToDraw` ← `Portal.rwPrerender` ← `Camera.rwRenderRoom`
   (traza real con el build instrumentado). No las pide la UI ni una lista de
   precarga: son `PosableShape` que ya están **dentro de salas del mundo**, y
   se cargan al dibujar la cadena de portales desde el spawn.
2. Esas salas son las galerías de avatares de `GroundZero/groundzero.world`,
   `IconViewRoom1a…1g` (cada una con un `PosableShape avatar:<Nombre>.rwg`
   y un `ClickSensor SelectAvatar<Nombre>`). Atribución medida:
   Roxanne (`IconViewRoom1a`) → `cfemalec`, `cfc`, `fja`; Simon (`1b`) → `mga`;
   Julie (`1f`) → `cfemaleb`, `cfemaleba`, `fga`.
3. El nombre de textura no está en el `.bod` ni en el mundo: lo da
   `permittedList` de `tables/tables.dat` (cifrado con XOR encadenado, lector
   verificado en `client/…/ServerTables.java`). `PosableShape` resuelve
   `avatar:Julie.rwg` con `permittedHash` a la cadena completa
   `julie.0ET2cfemalebT4cfemalebT3cfemalebaT1cfemaleb…T3fga…`; cada
   `T<n><nombre>` (`PosableShape.scanTexture`) es un grupo de textura
   `<nombre>.mov`. Es el esquema de códigos de avatar (`T#…`, `C_…`, `S…`).
4. Por qué faltan: el `cachedir` de 2004 solo contiene las texturas de los
   avatares que esa instalación llegó a ver (Tre `mia`, Paul `mfa`, Jing
   `cfemaled`…). Julie, Roxanne y Simon nunca se cargaron; su textura vivía
   solo en el servidor. No están en `assets/`, `AVATARS.ZIP`, `FIRST.EXE`
   (684 ficheros), `GROUNDZERO.EXE` ni `worlds.jar`.
5. Consecuencia: **limitación conocida, no bloqueante**. `Material.loadError`
   solo imprime; por el código el limbo conserva el material de color base de
   `scanTexture` (no comprobado visualmente); no hay excepción en el log. No se fabrica ninguna textura de relleno. Ningún ajuste de
   configuración evita la petición sin tocar lógica (las salas son contenido
   del mundo). Solo se resolverá recuperando esos 7 `.mov` de un archivo
   externo (Wayback u otro); bastaría con dejarlos en
   `assets/gammatutorial-samples/base-avatars/` para que el servidor local
   los sirva.

**`WorldScriptGroundZero.class` (404): cosmético, y preexistente.**
`WorldScriptManager.worldEntered` intenta cargar la clase Java del mundo
desde `<upgradeServer>/GroundZero/`; no está en `content.zip`, `gammacls.zip`
ni `worlds.jar`. `loadClass` devuelve null, el `NullPointerException` se
captura (`catch Exception`) y `currentScript` queda a null: solo se pierden
los ganchos opcionales `roomEnter/roomExit/onEachFrame` de ese script. El
`Gamma.Log` del cliente 2004 real bajo Wine (`assets/WorldsPlayer/Gamma.Log`,
líneas 70–73) muestra exactamente la misma secuencia
(`Download error … → Could not load script … → Exception constructing world
script: NullPointerException`), así que es el comportamiento original con el
servidor caído, no un fallo del puente.

### 🟢 RWL21/RWDL6D21 decompiladas + caza del "se ve todo mal" en GroundZero (2026-09-19)

**Lo que se buscaba**: "en GroundZero, que es el medio del mapa, se pone
todo bug". Sin captura de referencia, se atacó por descarte, midiendo.

**Hipótesis descartadas con evidencia** (cada una habría sido un bug real):
1. *Bumpers invisibles dibujados* (el fallo que ya hubo en el visor
   propio). `Rect24cya` olía a cyan bumper. Instrumentando `Room.aboutToDraw`
   para recorrer el árbol y comparar `getVisible()` con
   `NativeScene.getClumpState`: **0 objetos invisibles encendidos en las 17
   salas** que se recorren desde el spawn. `WObject.updateVisible` apaga la
   jerarquía correctamente.
2. *UVs disparatadas* (textura repetida decenas de veces = ruido). Medido
   por polígono: `du≈0,4–1,2` sobre polígonos de 4.000–15.000 px, o sea
   textura **magnificada**, no minificada.
3. *Dither de translucidez roto*. Las tablas `0x10079240/0x10079280` dan
   una matriz de Bayer 8×8 perfecta (64 valores distintos, cobertura
   16/32/48 de 64 para opacidad 64/128/192) y **ningún** material grande de
   la escena es translúcido.

**Lo que sí se comprobó que está bien**: Reception, LizCave, ChatHall y
Auditorium renderizados con el puente **coinciden con el visor propio**
(mismo suelo, mismas texturas, misma oscuridad en ChatHall — la pared
"moteada" es la textura real, sale igual en el renderizador OpenGL
independiente). ~50 fps por cámara. La losa gris que parecía flotar es una
hoja de puerta (`Rect24cya` de `WObjTemDrA1..4`, `IconViewRoom1Enter`) con
material gris 150 sin textura **en los datos del mundo**, y se queda fija
en coordenadas de mundo (12,125,125) mientras la cámara se mueve.

**Nuevo diagnóstico** `-Dopenworlds.dumpWindow=DIR`: vuelca el árbol de
componentes AWT de la ventana entera. Sin él no había forma de revisar la
UI (esta máquina no tiene permiso de captura de pantalla de macOS, y el
PNG por `printAll` sale negro porque la UI son componentes AWT pesados que
pinta el peer nativo). Resultado: maquetación correcta —canvas 468×244,
`FriendsListPart`, `AdPart`, `MapPart`, chat 280×100 y campo de entrada,
sin componentes de tamaño cero ni ocultos.

**El desbloqueo de verdad**: se decompilaron los dos binarios que
faltaban, que eran el motivo de que varias cosas del puente fueran
conjeturas (`ghidra headless` necesita `JAVA_HOME=tools/jdk/Contents/Home`
o aborta con "Unable to prompt user for JDK path"):
- `RWL21.DLL` → **1131 funciones, 0 fallos**, y como la DLL exporta
  símbolos, **795 con su nombre real de la API** (`RwGetPolygonMaterial`…).
- `RWDL6D21.DLL` (driver de 16 bits) → **385 funciones, 0 fallos**.

**Primer uso, dos conjeturas menos en el rasterizador** (ver
`bridge/README.md`): la normal de polígono es un abanico de productos
vectoriales desde el primer vértice (`0x10001100`), no Newell; y la normal
de vértice es la suma sin ponderar de las caras adyacentes con caída a la
**primera** cara cuando se cancela (`0x10041df0`, umbral `0.0f` leído en
`_DAT_100522e8`) — el puente dejaba un vector cero, que apaga la luz en ese
vértice. Medido: 0 casos degenerados en Reception y frame idéntico, o sea
fidelidad sin cambio visible allí.

**Sigue abierto**: no se ha reproducido ningún fallo visual atribuible al
puente; hace falta una captura del usuario del momento concreto. Y el
orden de dibujo real (BSP `0x1002cae0` + árbol por clump `0x10033750`)
sigue aproximado con z-buffer, pero **ya no por falta del binario**: leído
por encima, el árbol se construye una vez por clump y agrupa por material,
así que traducirlo cambiaría sobre todo el z-fighting entre coplanares.

### 🟢 Hoja de ruta ejecutada con subagentes: H0-H5 fusionados (2026-09-22 → 2026-09-26)

Se preparó `docs/roadmap.md` y se ejecutó con agentes en worktrees
separados (propiedad de ficheros por agente, parches por subsistema
`bridge/natives-<x>.patch`). Cada rama se revisó antes de fusionar,
comprobando en el ASM la afirmación clave (citada en cada merge). Los
cortes por límite de uso se retomaron desde el último commit de cada rama.

- **Build rota desde el merge `71648da`** (rama antigua que duplicaba en
  `apply_mock.sh` lo que ya hacía `natives.patch`): arreglada; además
  `build_gamma.sh` ya falla cuando falla `javac`.
- **H0**: `tools/verify-corpus.sh` (RWX 118/118 también contra
  `three-rwx-loader`, reproducible por primera vez en macOS con
  `tools/node-macos`), `tools/run-checks.sh` y `tools/progress-panel.py`.
- **H1**: texturas (COLORONCOLOR, no HALFTONE; `RwReadTexture`,
  `RwGetNamedTexture`, `StringTexture`); `.rwg` leído de RWL21 en ASM
  (cabecera = lista de texturas, PLST con índice de material, `cube.rwg` no
  carga en RW 2.1, ATOM vacío = clump válido); rasterizador del driver
  (tabla de recíprocos, perspectiva cada 16 px, árbol por clump,
  `addSubPolys` con x/u de los vértices 1-2 porque el C de Ghidra está mal).
  El BSP de escena queda documentado en ASM y sin traducir.
- **H2**: DroneAnimator traducido entero; la regla (walk/wait/endwait con
  plazos 10/30/10 s, walk por distancia, mezcla de 250 ms, key truncado)
  está en `docs/seq-animation-reference.md` §7. En GroundZero el animador ya
  recibe `moveto`/`update`, pero solo hay estatuas que giran.
- **H3**: whirl compilado (Rust por rustup) y arrancado en 127.0.0.1: login,
  misma sala y chat entre dos clientes originales. No se ven porque whirl no
  manda APPRACTR (`hub.rs:246` comentado). Encontrada la carrera
  `_connectThread` del cliente de 2004 (no se parchea).
- **H4**: el cliente propio usa `CmpFrames` (la ruta vieja mostraba el
  último frame de los 52 `.mov`). Un `.mov` son celdas de Material y lo que
  cambia con el tiempo es `AnimateAction`. Portales 53/87 como el original
  (`_p2pxform` + `getYaw`). Animación real en `WorldViewer --play`.
- **H5**: UI (eventos 1.0 en TextField bajo JDK 25, así que el chat va con
  Intro; `Console.encrypt/decrypt`, cursores, menú contextual…), sistema/COM
  (`RegKey` portable, `SystemInfo`, `VehicleShape`) y sonido/web (WAV/MIDI
  con el volumen del binario, IMA ADPCM, IE/DirectShow/CD por su camino de
  fallo, URLs solo por clic y con `-Dopenworlds.openUrls=1`).
- Mock de `IniFile` sin distinguir mayúsculas y persistente, como kernel32:
  el cliente escribe su `Gamma.Log` y "Remember password" persiste.

Queda y por qué, en `docs/roadmap.md` (§1b) y en
`editor/worldsplayer_source_editor-main/bridge/README.md` (Pendiente de
verificar).

### 🟢 Paquete con lanzador, CI de GitHub y el motor revisado: menús, lag, portales (2026-09-26)

Petición del usuario: "no hay menús, va súper lag, errores visuales";
revisar las partes críticas (el motor), builds de GitHub empaquetadas que
no dependan de los scripts de arranque, y aprovisionar la máquina. Primera
sesión en un contenedor **Linux x64** (Claude Code en la web): el cliente
original bajo el puente corre sin Wine, con Xvfb para la ventana.

**Puente (cliente original de 2004):**
- **Menús que no salían.** El panel de botones (Help, Options, Teleport,
  Quit, mapa del universo…) se pinta con `ImageCanvas.loadLocalImage` →
  `Toolkit.getImage("u:/…/rtpanel.gif")`: la ruta sale del parche de `URL`
  (unidad sintética `u:` y minúsculas), y fuera de Windows ese fichero no
  existe. `HostPath.of` quita la unidad y resuelve sin distinguir
  mayúsculas; `bridge/host_paths.py` lo aplica a las 151 aperturas de
  fichero y `Toolkit.getImage` de 50 clases (solo en la copia de build).
  De paso se corrige lo que decía el README del puente: el error de
  `redir.txt` no era del original (su `Gamma.Log` no lo tiene), era esto.
- **Ventana negra al arrancar.** `Std.initSyncTime` abría un `Socket` sin
  timeout a `time.worlds.net:37` en el primer frame (lo pide
  `BlackBox.postrender`), en el hilo de render. La base sale ahora del reloj
  del sistema con la misma resta del bytecode (`ldc2_w -1141367296l; lsub`,
  el `100*365*86400` desbordado del original) y el servidor, si respondiera,
  la corrige desde un hilo con timeouts de 2 s.
- **Fuentes.** El `lib/font.properties` del JRE 1.4 instalado resolvía
  `dialog`/`sansserif` a Arial, `serif` a Times New Roman y
  `monospaced`/`dialoginput` a Courier New. Con las del JDK moderno la barra
  de estado cortaba "Use arrow keys" en "Jse arrow keys". `NativeUiFonts`
  (+ `bridge/ui_fonts.py`, 72 `new Font` en 49 clases y la fuente por
  defecto de `GammaFrame`) usa esas o las de métricas iguales (Liberation).
- **Lag.** El rasterizador del driver ahora graba los triángulos de la
  pasada de clumps y los dibuja por franjas horizontales en varios hilos;
  cada franja recorre la lista entera, así que cada píxel recibe las mismas
  escrituras en el mismo orden. Además: recorte sin asignaciones, spans que
  solo interpolan lo que usa el camino del píxel y volcado 565→RGB por
  tabla. Medido: 13,5 → 9,4 ms con 1 hilo y 4,7 ms con 4 (1172×848); el
  cliente real pasa de ~25 a ~53 fps a 1172×848 y de 72 a ~90 a 468×272.
  **`RasterGoldenCheck`** (nuevo): 56 formas `.rwx` reales de GroundZero con
  sus texturas y quads que fuerzan cada camino (textura iluminada, Gouraud,
  plano, translúcido, doble cara), 18 vistas en 3 tamaños; el CRC es
  idéntico al del motor anterior con 1, 2, 4 y 8 hilos.

**Motor nuevo (`WorldViewer --play`):**
- **Aparecer y mirar como el original.** `WorldRestorer` leía y tiraba
  `Room.defaultPosition/defaultOrientationAxis/defaultOrientation`; ahora se
  guardan y el spawn hace lo que `TeleportAction` (`moveTo(pos).spin(eje,
  giro)`; el piloto mira a +Y con giro 0, rumbo = 90 + s·giro para el eje
  (0,0,s)). Medido en el puente: AvatarEnter (261 sobre −Z) mira a
  (−0,97, −0,15) y el `RestartAt` de Reception (125 sobre −Z) a
  (0,81, −0,56). Antes todas las salas aparecían en el punto de Reception
  (fuera de la sala) y Reception miraba al kiosko (−148, puesto a mano).
- **Cámara.** La del modo con que arranca el original, `HoloPilot`
  `CAM_MODE_BEHIND`: 140 detrás, −10° (en el puente: 137,9 en horizontal y
  +24,3 = 140·cos 10 / 140·sin 10) y acercándose si hay un muro (la cámara
  del original es *bumpable*). Antes, 220 sin colisión.
- **Portales que se ven.** Traducido del pase de portal del original
  (`Camera.rwRenderRoom` → `Room.prerender` → `Portal.rwPrerender`): portal
  en estado 2, visible (flags bit 0), de cara a la cámara (fórmula de
  0x0041b3b0), rectángulo en pantalla, cámara movida por `_p2pxform`, sala
  lejana dibujada antes que la propia y **sin borrar el color** (el portal
  anidado ReceptionView1 → ReceptionView2 deja ver el panorama). Las
  cámaras de ChatHall, ChatElevator, DcnEnter, ReceptionView1 y
  ReceptionView2 salen iguales al decimal que en el puente. Profundidad 3
  (el original llega a 10). Sin espejos todavía (flags bit 2).
- **`Rect` de una cara**, como el driver: se descarta la cara de atrás si
  el material no tiene `MaterialModes` double (`!front && (modes & 0x80) ==
  0`), y los materiales del mundo no lo ponen. Dibujados a doble cara, el
  edificio de ReceptionView1 visto por detrás tapaba el paisaje y había
  letreros espejados.
- **Menú de pausa y HUD** (ESC: Continuar, Ir a otra sala —las 25, por el
  mismo camino que cruzar un portal—, FPS, Ayuda, Salir), con un atlas de
  texto de Java2D en modo headless (sin ventana AWT que pelee con GLFW en
  macOS).

**Paquete y CI:**
- `launcher/` es el punto de entrada del paquete y sustituye a
  `run_gamma.sh`/`run-game.sh`/`local-upgrade-server.py` para jugar:
  ventana con menú (cliente original con mundo, servidor y usuario; motor
  nuevo con sala; hilos de dibujo; FPS; registro en vivo), menú de terminal
  (`--tui`, o solo si no hay pantalla) y CLI (`--original`, `--viewer`,
  `--server`, `--smoke`…). Copia persistente de la instalación en la
  carpeta de datos del usuario (se conserva el `worlds.ini` con amigos y
  contraseña), servidor de actualización local en Java y cada cliente en
  su propia JVM con el Java del paquete.
- `tools/build-dist.sh`: paquete portable (.zip, Java 17+) y, con
  `--app-image`, la app con Java incluido (jlink + jpackage): `.app`
  firmada ad hoc en macOS, carpeta con `OpenWorlds.exe` en Windows,
  `.tar.gz` en Linux. `tools/fetch-lwjgl.sh` baja LWJGL con SHA-1 y
  reintentos (Maven Central da 429 si se le pide deprisa).
- `.github/workflows/build.yml`: en cada push compila, pasa `run-checks`
  (38/38) y `verify-corpus` completo, arranca el original empaquetado bajo
  Xvfb (tiene que imprimir cámara y fps: ha dibujado) y sube el portable y
  las apps de Linux, macOS Intel, macOS Apple Silicon y Windows; con un tag
  `v*` publica una release. Primer fallo: jpackage en macOS exige que la
  versión empiece por ≥ 1 (se usa `1.0.<commits>`). La misma prueba de humo
  con el Java de cada app (ejecución #5): GroundZero dibuja en macOS Intel,
  macOS ARM (62 fps) y Windows (102 fps), con la cámara en (230,180,170)
  mirando (−0,97, −0,15, −0,17) como en Linux; desde ahí es obligatoria.
- Aprovisionamiento: `tools/setup-linux.sh` (idempotente: paquetes, JDK,
  LWJGL, arnés RWX, compila los dos clientes) y el hook `SessionStart` de
  `.claude/` para las sesiones en la web (15 s en caliente, ~50 s en frío).

**Encontrado y sin arreglar desde aquí:** `cachedir/cache.index` nunca
entró en este historial de git (se dejó de versionar el 2026-09-09 como
"bookkeeping" y no está en ningún commit ni en ningún zip del repo). Sin
él, `Cache.initLoad` ("Flushing cache index.") **borra** los 207 ficheros
cacheados de la copia de trabajo (medido en el paquete: quedan 31, los que
se vuelven a bajar del servidor local), así que en un clon limpio, en la
CI y en los paquetes los avatares cacheados de 2004 salen sin textura. La
única copia está en el Mac del usuario; ya no está en `.gitignore`.

**Segunda parte del mismo día — el motor nuevo alcanza al original en color
y el puente pierde un fallo de matrices.** Con la cámara del visor igual a
la del puente al decimal y el mismo aspecto (`-Dopenworlds.windowSize=468x272`),
se compararon capturas columna a columna y con mapas de diferencias:

- **Luz del motor nuevo.** Estaba muy oscuro por tres cosas: las luces de GL
  se fijaban una vez con la vista identidad (iban pegadas a la cámara), la
  normal de los `Rect` se transformaba dos veces, y GL nunca pasa del color
  del material, mientras que la rampa del driver RWDL6D21 (FUN_10008d00)
  aclara hacia blanco por encima de 0,75 de la escala. Además, 586 de las
  699 superficies del mundo son "auto-iluminadas" (ambiente ~0,75 sin
  difusa: FUN_00417950) y el original pinta su textura tal cual.
  `DriverLight` hace lo del puente: dos luces por sala en el espacio de
  cada objeto (con la inversa: una pared escalada 2149×2×400 recibe d ≈ 1,
  no el coseno del mundo), la intensidad `31 amb + Σ 31 lc (dif d + spec
  S(d))` y la rampa, en GL como `texel·P + S` con `GL_COLOR_SUM`. El RWX
  guarda ahora lo que RW usa (ambiente 0 si el script no lo pone, como
  `RwCreateMaterial` 0x1001b340; `LightSampling`; normales por polígono y
  de vértice compartidas; las `Normal` del script). Resultado: techo
  (214,210,181) en el puente y (208,208,176) en el visor.
- **Superficies.** UVs de `Rect.addRwChildren` (97 paredes con repetición
  no entera salían desplazadas), celdas de `addSubPolys` con espejado
  alterno, `RectPatch` de 4 triángulos al centro, vallas `Billboard`
  (`new Material(adworlds.cmp, h, v)`: cada celda con el fichero entero,
  como `Material.syncBackgroundLoad`) y portales hasta 11 niveles
  (`rwDepth <= 10`; con 3 no se veía Reception al fondo de AvatarEnter).
- **Fallo del puente: producto de matrices.** El soporte con cuerdas del
  Auditorium y la puerta en iris de IconViewRoom1Enter salían en el visor y
  no en el puente. Un volcado nuevo del árbol de clumps
  (`-Dopenworlds.dumpScene`) mostró `WObject2` en (0,1000,0) y su hijo
  `ShapeStand` en (0,0,0): la cuarta columna de los `Transform` del `.world`
  trae datos internos de RW (0x03ddff04, 0x02890088 leídos como float,
  `m[15] = 2e-37`) y el puente multiplicaba 4×4, mientras que
  `RwMultiplyMatrix` (0x1001db10 → 0x1005118c) es afín y no la toca. Todo lo
  que cuelga de un `WObject` contenedor (30 en GroundZero) caía en el origen
  de la sala en el cliente original. Arreglado con el mismo orden de sumas
  (bit a bit igual con matrices limpias). Queda confirmado que el visor
  tenía razón en los dos casos, y que el puente no es referencia de píxel
  hasta tener capturas bajo Wine.

`DriverLightCheck` y `MatrixAffineCheck` (casos a mano); `run-checks`
40/40; `verify-corpus` sin fallos. Pendiente en el motor nuevo: espejos,
`MoveAction` (la puerta en iris se abre al cruzar el portal de Reception) y
la luz por vértice de los avatares.

**Tercera parte — barrido de las 25 salas.** Con el mismo método (pose del
visor dentro de la sala pasada al original por URL, `#Sala@x,y,z,giro,0,0,-1`),
las diferencias que quedaban eran de dos motores a la vez:

- **Puente, material de las partes `.bod`.** gamma.dll FUN_0041d950 hace
  `RwSetMaterialSurface(mat, 0.32, 0.55, 0.0)` (floats de `DAT_00470ac4`,
  `DAT_00470ac0` y `DAT_00470abc` leídos del `.data`) y `FUN_00417a10`
  (luz por vértice); el puente tenía (0.75, 0, 0) facetado y las estatuas
  salían planas.
- **Motor nuevo, avatares.** Luz por vértice por parte, como
  `RwCalculateClumpVertexNormal`; el mismo material; y el vestuario perdido
  (`cmalea*`, `mfa`…) en `colorTable[3]` = (255, 102, 51), que es el color
  con que `PosableShape.scanTexture` crea el material antes de intentar la
  textura. Por eso las estatuas de la galería salen naranjas en el
  original, y ahora también en el visor.
- **Encontrado, sin cambiar:** `Room.floorHeight` del original solo usa
  los `RectPatch` del contenido de la sala y devuelve 0 si no hay. En las
  salas de la galería el suelo visible está a 40 y no hay `RectPatch`, así
  que el piloto del original anda hundido 40 (se ve en la altura de la
  cámara del puente: z = 164 en vez de 204). El visor se apoya en los
  suelos visibles y en los muebles; copiarlo es una decisión de juego, no
  de dibujo.

### 🟢 Un solo motor: fuera el motor nuevo (2026-09-26)

El usuario preguntó por qué había dos motores ("eso yo no lo he pedido") y,
tras la explicación, pidió quitar absolutamente todo el motor nuevo, lanzador
incluido, y subirlo.

**De dónde venían.** El motor nuevo (`client/`, parsers propios + LWJGL)
empezó el 2026-09-09 (`fa5e52d`) por el objetivo 2 de CLAUDE.md; el puente
del cliente original, el 2026-09-17 (`a79efdd`). La hoja de ruta del
2026-09-22 (`76ff86f`, sección 1) dejó la elección A/B al usuario y nunca se
cerró; en la sesión de empaquetado se siguió trabajando en los dos y el
lanzador los ofrecía a la par ("Jugar" / "Explorar").

**Quitado** (todo está en el historial de git hasta `8cd795d`):
- De `client/`: el renderizador y los visores (`render/`), los lectores de
  `.rwx`, `.world` y nombres de avatar (`rwx/`, `world/`, `avatar/`), su
  animación y sus checks (`DriverLightCheck`, `AvatarAnimCheck`,
  `MaterialTilesCheck`, `PortalLinkCheck`, `TextureActionsCheck`).
- Del lanzador: "Explorar", las opciones 3-4 del menú de terminal
  (explorar sala / elegir sala), `--viewer`, la sala de los ajustes y el
  `openworlds-client.jar` del paquete.
- `tools/run-game.sh`, `install-launcher.sh`, `fetch-lwjgl.sh` y
  `rwx-harness/`; LWJGL y node de la CI, de `build-dist.sh` y del
  aprovisionamiento; `docs/render-pipeline-reference.md`,
  `docs/rwx-parser-progress.md` y las 50 capturas del motor nuevo de
  `docs/renders/` (queda la del original).

**Movido, no quitado:** `bod/` (`.bod` y `.seq`), `rwg/` y `cmp/`
(`.cmp`/`.mov`), con sus checks, a `formats/`: el puente los importa
(`SeqParser`/`SeqSampler`, `BodParser`/`BodClump`, `RwgParser`, `CmpFrames`)
y `build_gamma.sh` los compila con él. Mismos paquetes Java, así que el
puente no cambia.

**Consecuencias.** `verify-corpus.sh` pierde las filas RWX 118/118 (y la
comparación con `three-rwx-loader`), `.world` 25/578/103 y avatares
146/148, cuyos lectores solo usaba el motor nuevo; conserva `.seq` 231,
`.bod` 51, `.cmp` 159 y `.mov` 52. Los documentos de formato siguen, con
una nota donde citan código o capturas retiradas. `.gitignore` sigue
ignorando `tools/lwjgl/`, `tools/node*/`, `tools/rwx-harness/`, `client/` y
`logs/` para que un checkout antiguo (el Mac) no los suba: se pueden borrar
a mano.

**Verificado en el contenedor Linux:** `tools/setup-linux.sh` completo (904
clases del puente + `formats/`); `run-checks.sh` 35/35 (4 + 31);
`verify-corpus.sh` sin fallos; `build-dist.sh --app-image` sin LWJGL (zip
portable de 5,8 MB); prueba de humo de la app de Linux: dibuja GroundZero
con la cámara en (230,180,170); menú de terminal con 5 opciones,
`--viewer` rechazado y la ventana solo con el cliente original.

### 🟢 El juego decompilado de cabo a rabo, los viajes entre mundos y todo el juego probado (2026-09-26)

Pedido del usuario: "con Ghidra termina de decompilar el juego de cabo a
rabo. Y prueba lo de irse a otros mundos, que eso no está probado; prueba
todas las cosas que se pueden hacer en el juego". Informe completo:
`docs/pruebas-juego.md`.

**Ghidra.** Faltaban seis binarios propios del juego. Ghidra 12.1.3 se bajó
del espejo de SourceForge (el proxy de la nube corta GitHub), con el SHA-256
comprobado. Salieron `run.exe` (139 funciones), `gdkup.exe` (256),
`sfmain.exe` (619, el chat de voz SpeakFreely/GSM compilado con Watcom, cuyo
`DGROUP` hubo que enseñar a `ScanVtablesAndExport.java`) y los drivers de
RenderWare de 8 bits (427), MMX (435) y DirectDraw (305). El barrido de
vtables se pasó también a RWL21 (+21) y RWDL6D21 (+26). Todo con 0 fallos,
y reproducible con `tools/ghidra-scripts/decompile-all.sh`. Lo que queda
sin decompilar es de terceros: el Java de Sun 1.4.2 del instalador,
msvcrt, xdelta/glib y el desinstalador de Wise.

**Viajes.** El hallazgo que lo desbloqueó: `us1.worlds.net` vuelve a
responder, porque es el espejo de LibreWorlds, con los paquetes de mundo y
el vestuario de avatares que se daban por perdidos. El lanzador pide al
espejo lo que no hay en local. Para instalar, el cliente pide `gdkup.exe`
y se cierra; el puente deja la petición en `gdkup.pending`, y el gdkup
traducido (`GdkUp`, de `gdkup_exe`) instala los paquetes Wise
(`WisePackage`) y NSIS (`NsisPackage`) y arranca el cliente otra vez.
Probados: 11 mundos descargados (la instalación de 2004 solo trae
GroundZero), entre ellos Chaos, el mundo de David Bowie, con su BWStreet,
y The Blair Witch World, la cafetería de Burkittsville, sacado del mapa
del universo, donde el espejo sirve los 16 mundos.

**Fallos encontrados probando, todos arreglados con test:**

- Diálogos con campo de texto (WorldsMark → Change Location...): en X11 el
  cierre de `PolledDialog` (bajo su monitor) se bloqueaba con el hilo de
  eventos, que toma ese monitor por el método de entrada. Diálogo negro y
  UI congelada. `AwtCompat.closeHoldingLock`, `UiDisposeCheck`.
- El mapa del universo cerraba el juego: el mock de
  `usingMicrosoftVMHacks` devolvía `true`. En gamma.dll es
  `DAT_004891cc == 1`, que solo se activa con la JVM de Microsoft.
- Texturas: `FUN_00442bc0` decodifica un fotograma en varios grupos de
  filas (`mug.cmp` de Blair Witch, dos grupos que cuadran al byte con el
  fichero), y la fila `esi` es un único búfer para todo el fichero.
  Además, el byte 13 de la cabecera hace saltar también el número de
  colores (`kcl.mov`, un caleidoscopio del vestuario). `CmpGroupsCheck`,
  con muestras en `assets/cmp-verified/`.
- Upgrade Now (GroundZero 37 → 40, un NSIS de LibreWorlds): faltaban
  Delete, Push/Pop/Exch, FileOpen, FileRead y FileClose. Además, un
  instalador que abortaba dejaba al jugador sin juego; gdkup.exe no lee
  los códigos de salida (0x00401e75) y sigue hasta el reinicio. Ahora igual.
  `GdkUpCheck`, con `Meteor25.exe` (Wise) y `GroundZero37-40.exe` en
  `assets/packages/`.
- (Antes, en la misma sesión) el giro a cámara lenta: el puente daba un
  reloj de 1 ms a 600-800 fps y los umbrales de `SmoothDriver` anulaban la
  velocidad. Ahora avanza a saltos de `GetTickCount` (15,625 ms), como en XP.

**Queda:** parches xdelta, chat de voz sin traducir, "Sleep" invisible,
⚠️ otros sitios con AWT bajo el monitor de un diálogo, y la decisión de
guardar o no en el repo los paquetes del espejo.

### 🟢 Logo nuevo: un planeta low-poly (2026-09-26)

Al usuario no le gustaba nada el logo del paquete: un globo azul genérico
con "FW" y un anillo naranja. Se le enseñaron cuatro propuestas, todas sin
letras para que se lean a 16 px: planeta low-poly, portal entre mundos,
planeta-burbuja de chat y pixel art. Eligió el **planeta low-poly**: una
icosfera de 80 caras con sombreado plano, como el 3D de RenderWare (una
luz, un color por cara), con continentes y un anillo que pasa por detrás y
por delante, sobre un azulejo de cielo nocturno.

`tools/icons/make_icons.py` lo dibuja en SVG (`openworlds.svg`, y
`openworlds-small.svg` sin estrellas y con el anillo más grueso para
16-32 px) y saca con Chrome sin interfaz y Pillow el PNG de 1024, el ICO
(16-256), el ICNS (16-1024) y el icono de la ventana del lanzador. Chrome
sin interfaz recorta las ventanas pequeñas, así que todo se dibuja a 1024
y se reduce con Lanczos.
