# Referencia del formato `.cmp`/`.mov` (texturas "ScapePic"), investigación desde bytes + desensamblado real

## Resumen ejecutivo

`.cmp`/`.mov` son las texturas comprimidas de WorldsPlayer ("ScapePic",
nombre interno confirmado por las clases `NET.worlds.scape.ScapePicTexture`
y `NET.worlds.console.ScapePicImage` del cliente decompilado). **La
descompresión ocurre enteramente en `gamma.dll` (nativo), no en Java** —
igual que RWX/RWG. A diferencia de RWG, esta sesión SÍ desensambló el
código real con Ghidra (mismo binario/herramienta usada en sesiones
anteriores para mapear métodos `native`) y encontró evidencia fuerte:

- El contenedor usa un esquema de compresión **Huffman canónico +
  probable LZSS**, con una función interna literalmente llamada
  `huffdcod` (nombre de módulo fuente incrustado como string de
  aserción — "Huffman decode") cuyo algoritmo de construcción de tabla
  (`FUN_004266f0`/`FUN_00426820` en las direcciones desensambladas)
  coincide **estructuralmente, variable por variable**, con la función
  pública y bien documentada `make_table()` de la familia de algoritmos
  LHA/LZH de Okumura/Yoshizaki (Huffman canónico: cuenta de frecuencias
  por longitud de código de 0 a 8 bits, tabla de offsets acumulados
  `start[i+1] = (count[i]+start[i])*2`, expansión de tabla de búsqueda
  por prefijo).
- **NO es, sin embargo, una variante públicamente documentada bajo el
  nombre "LzH2"** — confirmado por investigación externa (ver abajo):
  nadie ha publicado un decoder ni una especificación para esta variante
  exacta. Es plausible que Worlds Inc. haya adaptado/derivado el
  algoritmo público de LHA (que era ampliamente reutilizado en 1994-1997)
  para su propia herramienta interna "ScapePic", cambiando el magic tag.
- **El bucle real de descompresión LZSS (que consume el bitstream
  comprimido usando las tablas Huffman ya construidas) NO se llegó a
  desensamblar/entender esta sesión** — es la pieza que falta para un
  decoder completo. Ver "Siguiente paso" al final.

**Decisión de alcance tomada esta sesión**: en vez de invertir el resto
de la sesión en terminar la ingeniería inversa completa del decoder de
píxeles (un esfuerzo del mismo orden que el desensamblado de `.bod`,
que el propio usuario pidió posponer en la sesión anterior), se documentó
la evidencia real encontrada hasta el límite razonable de tiempo, y el
resto de la sesión (iluminación, pipeline de materiales, escena) se
implementó usando el color/opacidad de material YA verificado (RWX/RWG
parseado), **sin renderizar ninguna textura y sin inventar píxeles** —
ver `docs/renders/` para la evidencia de que esto se hizo con un
fallback de color plano explícito, no con una textura inventada.

---

## Corpus real usado

17 archivos `.cmp` reales del proyecto (`assets/FIRST/*.CMP`,
`assets/WorldsPlayer/*.cmp`, `assets/WorldsPlayer/cachedir/*.cmp` — estos
últimos, igual que los `.bod`, son contenido real descargado de un
servidor en una sesión anterior, no inventado). Tamaños entre 1637 y
10973 bytes.

## Estructura de cabecera (hex dump real, confirmada byte a byte)

Los primeros 16 bytes son idénticos en su forma en los 6 archivos
inspeccionados (`ADWORLDS.CMP`, `IDLE.CMP`, `ADFRAME.CMP`,
`cachedir/47.cmp`, `48.cmp`, `49.cmp`):

```
4c 7a 48 32 | XX | 80 80 00 80 00 | YY YY | ZZ | 29 ?? ...
"L  z  H  2"  modo   (constante)     ?      ?
```

- **Magic de 4 bytes**: `"LzH2"` (`4C 7A 48 32`) — confirmado constante
  en los 17 archivos.
- **Byte 4 ("modo")**: `0x02` en la mayoría de archivos, `0x06` en
  `IDLE.CMP`/`idle.cmp`. ⚠️ VERIFICAR significado exacto — posible
  variante de compresión o profundidad de color distinta.
- **Bytes 5-9**: `80 80 00 80 00`, constantes en TODOS los archivos
  inspeccionados. ⚠️ VERIFICAR — no se determinó su significado
  (posiblemente parte de la propia tabla de códigos Huffman inicial, no
  un campo de cabecera "plano" — ver más abajo, el análisis de
  `FUN_00442750` sugiere que la cabecera "plana" es mucho más corta de
  lo que parece a simple vista y estos bytes ya forman parte de
  estructuras internas del formato, ya con floats/flags empaquetados).
- El resto de bytes 10 en adelante varía por archivo y aparenta ser ya
  parte del stream comprimido/tablas de código — **no se completó la
  separación exacta entre "cabecera" y "datos comprimidos"**.

## Evidencia oficial/comunitaria externa (subagente de investigación)

- **`github.com/vanjac/zoomscape-info`** (wiki, página "Images"):
  documenta el mismo header `LzH2`, la misma lista de extensiones
  relacionadas (`.CMP`/`.CMS`/`.CMX`/`.IMG`/`.IMS`/`.IM2`/`.IM5`/`.OVL`),
  e incluye una copia del binario original `T.EXE` ("ScapePic") — la
  herramienta de inspección/descompresión de época. **El propio wiki
  marca el esquema de compresión como "unknown"** — confirma que nadie
  más lo ha resuelto públicamente tampoco.
- **`community.worlio.com/forum/12/thread/81`** ("Figuring out the
  CMP/MOV format"): confirma independientemente los mismos bytes mágicos
  `4C 7A 48 32`, sugiere que el 5º byte es una bandera de
  versión/tipo-de-compresión, y describe el formato como multi-frame
  (animaciones, avatares rotables) — `.cmp` y `.mov` son el mismo
  contenedor con extensión distinta.
- **`kangworlds.net/tutorials/cmp`**: tutorial práctico (no a nivel de
  bytes) sobre `COMPIMG` (herramienta del SDK "Accomplish") para generar
  `.cmp`/`.mov` — confirma que es paleta indexada, basado conceptualmente
  en BMP/Sun RAS, sin especificación binaria.
- **No existe ningún decoder de código abierto** para este formato en
  ningún lenguaje (confirmado por búsqueda) — a diferencia de RWX
  (`three-rwx-loader`), aquí no hay ningún atajo de biblioteca externa.
  Posible pista de "ZoomScape" como producto hermano (mismo tag `LzH2`,
  mismo nombre "ScapePic") — **sin confirmar** que compartan código real
  con Worlds Inc., solo indicios de búsqueda.

## Evidencia del desensamblado real (Ghidra, `gamma.dll`)

Cadena de llamadas confirmada desde el punto de entrada JNI hasta el
núcleo Huffman (direcciones reales del binario, build de
`assets/WorldsPlayer/bin/gamma.dll`):

```
Java_NET_worlds_console_ScapePicImage_loadImage@12  (0x004103e0)  [entry point JNI]
  -> FUN_00442fd0 (0x00442fd0)      [construye el objeto imagen]
       -> FUN_004425f0 (0x004425f0) [inicializa campos, delega si header OK]
            -> FUN_00442750 (0x00442750)  [lee y valida la cabecera "plana"
                                            (0x22=34 bytes), luego 5 tablas]
                 -> FUN_004269c0 x4  (una por "canal"/tabla, índices 0-3)
                      -> FUN_00426930  ["huffdcod" - construye tabla Huffman]
                           -> FUN_00426640   [desempaqueta longitudes de código
                                              de 4 bits por símbolo, remapeadas
                                              por una tabla de permutación fija]
                           -> FUN_004266f0   [== make_table() de LHA: cuenta
                                              frecuencias por longitud (0-8),
                                              asigna códigos canónicos]
                           -> FUN_00426820   [== fase de expansión de make_table:
                                              rellena la tabla de búsqueda por
                                              prefijo con el símbolo hoja]
                 -> FUN_0044df50 (tabla índice 4: memcpy directo, SIN Huffman -
                                  probablemente la paleta de color o los
                                  offsets de fila, sin comprimir)
```

- **Confirmado**: 4 de las 5 "tablas" internas se construyen con Huffman
  canónico (una tabla de código distinta por tabla — patrón típico de
  compresión de imagen por planos: probablemente 3 planos de color +
  1 plano de "excepciones"/máscara, o splits run-length/posición al
  estilo LZSS clásico), la 5ª es un bloque sin comprimir copiado tal
  cual.
- **Confirmado**: cada tabla usa un "patrón" de longitudes de tabla de
  código FIJO según su índice (`FUN_00442590`: índice 0 → 81 bytes de
  patrón, índice 1 → 49 bytes, índice 3 → 22 bytes) — esto es exactamente
  el truco clásico de LHA de tener alfabetos de tamaño fijo conocido para
  cada tipo de tabla (p.ej. tabla de longitudes de código en sí, tabla de
  posiciones/distancias) en vez de codificar el tamaño del alfabeto en el
  archivo.
- **NO completado**: el bucle que, una vez construidas las tablas Huffman,
  realmente decodifica el bitstream comprimido en símbolos y los expande
  en píxeles (probablemente una función tipo `decode_c`/`decode_p` de LHA,
  con ventana deslizante LZSS) no se llegó a ubicar/desensamblar. Sin
  esa pieza no se puede producir un decoder Java funcional — construir
  solo las tablas sin poder consumir el bitstream no permite extraer
  ningún píxel real todavía.

## Sesión 2 (continuación, 2026-09-09): se localizó el bucle final — sigue
## sin ser suficientemente claro para implementar con confianza

Retomando exactamente donde quedó la sesión anterior, se volvió a
`gamma.dll` con Ghidra y se persiguió la cadena de llamadas más allá de
`FUN_00442750` (que solo construye las tablas Huffman) hasta encontrar
**la función que de verdad decodifica una fila de píxeles y la escribe
en el buffer de imagen**: `FUN_00442bc0` (invocada como
`this->getScanline(rowIndex, destBuffer, stride)` desde
`FUN_00443180`/`ScapePicTexture_makeTexture`). Su interior:

1. Llama a `FUN_00426af0` — el decodificador Huffman a nivel de bit real
   (registro de desplazamiento, tabla de 256 entradas, exactamente el
   patrón clásico `decode_c()` de LHA) — para producir hasta 5 "canales"
   de símbolos decodificados por fila.
2. Llama a `FUN_00457d88` — la función que **de verdad reconstruye los
   píxeles** a partir de esos símbolos y los escribe en el buffer final.
   Esta SÍ es la pieza que faltaba la sesión anterior.

**Hallazgos concretos y verificables dentro de `FUN_00457d88` y su
contexto** (no especulación — datos reales extraídos del binario):

- **Formato de píxel confirmado: 8 bits por píxel, paleta indexada**,
  con el ancho de fila redondeado a múltiplos de 4 bytes (`(width+3)/4`
  DWORDs por fila) — coincide exactamente con lo que ya había reportado
  la comunidad (`kangworlds.net/tutorials/cmp`: "indexed palette, based
  on BMP") pero ahora confirmado a nivel de código real, no solo de
  tutorial de usuario.
- **Filas escritas con stride negativo** (`param_5 = -stride`) — convención
  bottom-up típica de un `HBITMAP`/DIB de Windows (coincide con que la
  función que arma el bitmap final, `FUN_00422260`/`FUN_00422150`, usa
  literalmente `CreateCompatibleDC`/`HBITMAP` de la API de Windows).
- **Tabla de predictores espaciales extraída directamente del binario**
  (no inferida): en `0x478e98`-`0x478f5f` hay una tabla real de pares
  `(desplazamiento_fila, desplazamiento_columna)` — ej. `(0,-6)`,
  `(0,-5)`... `(0,-2)`, `(-4,0)`, `(-4,1)`... `(-4,6)`, `(-4,-6)`...
  formando una ventana causal de ~50 posiciones candidatas dentro de las
  últimas ~4-6 filas y ±6 columnas. Combinada en tiempo real con el
  stride real de la imagen (`offset = colDelta - stride*rowDelta`) para
  obtener un desplazamiento de bytes concreto. **Esto revela que el
  algoritmo real no es LZSS con offsets arbitrarios de una ventana
  deslizante genérica, sino un predictor 2D de vecinos causales**: cada
  símbolo Huffman-decodificado selecciona uno de esos ~50 vecinos ya
  decodificados y copia su valor de píxel — mucho más parecido a los
  filtros predictivos de PNG/JPEG-LS que a LZSS clásico. Esto corrige
  la hipótesis "LZSS" de la sesión anterior con evidencia real.
- **La tabla de 256 punteros a función indirectos** (`PTR_LAB_00483844`,
  invocada una vez por símbolo) que en un primer vistazo parecía sugerir
  256 rutinas de reconstrucción distintas (complejidad temida) **resultó
  ser trivial una vez desensamblada**: cada una de las 256 entradas es
  una función de 5-7 instrucciones que solo reordena/replica el byte de
  entrada en distintas combinaciones de registros de 8/16/32 bits — es
  el truco manual clásico de los años 90 para "rellenar 4 bytes a la vez
  con el mismo valor, con distintos desplazamientos de alineación", usado
  para acelerar el relleno de tramos (runs) de píxeles repetidos. **No
  aporta complejidad algorítmica real** — en Java equivale trivialmente a
  un bucle de relleno normal, sin necesidad de replicar el truco de
  registros de x86.

**Por qué NO se implementó igualmente, siguiendo la instrucción
explícita del usuario de no forzar nada a medias**: aunque el `qué`
(predictor causal 2D + relleno de tramos) ya está razonablemente claro,
el `cómo exacto` de `FUN_00457d88` sigue sin estarlo lo suficiente para
confiar en una traducción bit-exacta: usa aritmética de acarreo
(`CARRY4`) sobre un par de acumuladores empaquetados que llevan a la vez
un contador de repetición y un registro de desplazamiento de bits, y
escribe DOS filas de salida simultáneamente por cada símbolo consumido
(offset `_DAT_00482d05` aparte del principal) — el motivo de ese
"doblado" de filas no se terminó de entender. Implementar sin esa
claridad arriesgaría exactamente lo que se pidió evitar: producir
píxeles con aspecto plausible pero incorrectos, presentados como
verificados sin serlo. Se decidió parar aquí y documentar, no adivinar.

## Sesión de depuración dinámica (2026-09-10): entorno real construido y
## verificado, pero un bloqueo de infraestructura (no del algoritmo) impidió
## llegar al decoder de píxeles

Objetivo de esta sesión: resolver la ambigüedad real pendiente (aritmética
de acarreo + escritura de doble fila en `FUN_00457d88`) mediante
depuración dinámica de verdad — no más análisis estático — ejecutando
`gamma.dll` bajo Wine, paso a paso, con valores reales de registros y
memoria.

### Entorno de depuración: construido y verificado, funciona

Herramienta elegida: **Wine 11.0 (Staging) + `winedbg --gdb`** (proxy que
lanza el proceso bajo Wine y conecta un `gdb` real vía protocolo remoto),
con scripting Python embebido en gdb para automatizar lo que la
interacción manual no podía. Documentado en detalle, con el código
reutilizable, en `tools/gamma-dll-debug-harness/README.md`. Piezas clave:

- **Arnés Java mínimo, de sala limpia** (`tools/gamma-dll-debug-harness/`):
  en vez de levantar el cliente completo (que necesita red/servidor real),
  se escribieron clases Java mínimas que declaran únicamente los métodos
  `native` con la firma exacta (`NET.worlds.console.ScapePicImage.
  loadImage(String)`, `NET.worlds.scape.ScapePicTexture.makeTexture(String,
  String)` — firmas confirmadas con `javap` contra las clases REALES de
  `assets/worlds.jar`, no supuestas) y las invocan directamente. Estas
  clases se ejecutan bajo el propio JRE de época incluido en el proyecto
  (`assets/WorldsPlayer/bin/java.exe`, Java 1.4.2_05) — mismo binario que
  el cliente real habría usado. Truco necesario: `javac` moderno no puede
  emitir bytecode tan antiguo (mínimo `--release 8`, classfile 52, que
  1.4.2 rechaza), así que se compila con `--release 8` y se parchea a mano
  el byte de versión mayor del `.class` (52→48) — seguro porque el código
  fuente es deliberadamente trivial (sin generics, sin concatenación de
  strings con `+`, sin autoboxing — nada que dependa de clases de runtime
  posteriores a 1.4).
- **Confirmado real, con ejecución en vivo**: un breakpoint en
  `FUN_00442750` (el validador de cabecera ya localizado por análisis
  estático) SÍ se alcanza al invocar `loadImage()` con un `.cmp` real, y
  un volcado instrucción-a-instrucción con valores reales de registros
  muestra la función abriendo y leyendo el archivo de verdad (`ReadFile`
  real contra los bytes reales del `.cmp`) — la primera confirmación en
  vivo (no solo estática) de que el código identificado en sesiones
  anteriores es efectivamente el que procesa estos archivos.
- **Corrección metodológica real encontrada**: los nombres de símbolo que
  `gdb`/`winedbg` muestran para direcciones de `gamma.dll` **no son
  fiables** — la misma dirección que Ghidra (recién reabierto sobre el
  binario exacto, `analysis/GammaDLL.gpr`, para verificar) confirma como
  `FUN_00442750` (una función interna real) aparecía en `gdb` etiquetada
  como `_Java_NET_worlds_core_SystemInfo_GetProcessorType@8+736` — un
  export completamente distinto y no relacionado. La aritmética de
  direcciones (`base_runtime - ImageBase_preferido + VA_estática`) es
  correcta y reproducible entre ejecuciones (`gamma.dll` carga siempre en
  `0x03A40000` en este entorno); lo que no hay que hacer es fiarse de la
  etiqueta que `gdb` imprime — hay que verificar contra Ghidra directamente.

### El bloqueo real: no es el algoritmo, es la ventana/dispositivo gráfico

`loadImage()` con `IDLE.CMP` (modo `0x06`, atípico) vuelve rápido con
`width=height=hDIB=0` — evidencia de que ese modo toma una rama de salida
temprana, no de que el decoder falle. Con un archivo "normal" (modo
`0x02`, `ADWORLDS.CMP` — exactamente el tipo de archivo simple que se
pidió probar primero) y también con `ScapePicTexture.makeTexture()` (la
función que, según la documentación de sesiones anteriores, es la que de
verdad invoca `getScanline`/`FUN_00442bc0`), la ejecución real SÍ avanza
más allá del parseo de cabecera — pero antes de llegar a
`FUN_00442bc0`/`FUN_00457d88` entra en la inicialización de un dispositivo
DirectDraw/OpenGL y una ventana real, que en este entorno concreto (Wine
bajo Xwayland sandboxed, sin aceleración gráfica real) **se cuelga
indefinidamente** — confirmado repetidas veces, con y sin depurador
adjunto, con timeouts de hasta 150 segundos, con evidencia de bytes reales
(`err:clipboard:convert_selection Timed out waiting for SelectionNotify
event`, `libEGL warning: egl: failed to create dri2 screen`, y una
interrupción asíncrona durante el cuelgue que mostró un hilo esperando una
sección crítica del propio cargador de Wine bloqueada por otro hilo — un
patrón de contención de arranque de dispositivo/ventana bajo Wine, no un
bucle infinito dentro de la lógica de `gamma.dll` en sí). Se probaron
mitigaciones razonables (matar `wineserver` residual de ejecuciones
previas interrumpidas, modo de escritorio virtual de Wine
`explorer /desktop=...`) sin éxito dentro del tiempo disponible de esta
sesión.

**Conclusión honesta**: la ambigüedad original (aritmética de acarreo +
escritura de doble fila en `FUN_00457d88`) **sigue sin resolverse** —
no por falta de intentarlo con evidencia de ejecución real, sino porque
este entorno concreto no permite llegar tan lejos en la ejecución real del
decoder. No se implementó el decoder en Java (habría significado inventar
la parte no verificada, exactamente lo que se pidió evitar), y por lo
tanto tampoco se conectó ningún decoder al pipeline de materiales del
motor — no hay nada real que conectar todavía.

### Siguiente paso concreto para una futura sesión

1. Repetir el arnés de `tools/gamma-dll-debug-harness/` en un entorno con
   acceso real a GPU/DRI o con un gestor de ventanas real disponible — el
   propio README documenta el bloqueo exacto para no tener que
   redescubrirlo. Si el cuelgue desaparece ahí, el resto del plan original
   (single-step por `FUN_00442bc0`/`FUN_00457d88` con valores reales) sigue
   siendo el camino correcto y ahora hay un entorno de depuración ya
   verificado y funcional para hacerlo, en vez de partir de cero.
2. Alternativa si el bloqueo persiste: investigar si existe alguna forma
   de invocar `FUN_00442bc0`/`FUN_00457d88` sin pasar por la creación real
   de dispositivo/ventana (p.ej. llamando las funciones internas
   directamente desde `gdb` con un objeto `this` construido a mano una vez
   se conozca su layout con más precisión) — no intentado esta sesión por
   el riesgo de invertir mucho tiempo en una reconstrucción de layout sin
   evidencia suficiente.
3. Una vez con eso claro, implementar en Java el predictor causal 2D ya
   identificado (copiar valor de uno de los ~50 vecinos de la tabla real
   extraída, o repetir un literal N veces) y verificar dimensiones +
   tamaño de salida esperado antes de aceptar cualquier píxel como bueno.
4. Verificar contra los 17 archivos `.cmp` reales del proyecto y, si
   aparece, contra el material RWX que los referencia.

---

## Sesión de desbloqueo (2026-09-10): Xvfb desbloquea el cuelgue de
## ventana/dispositivo — ambigüedad de acarreo y doble fila RESUELTAS con
## ejecución real

Punto de partida: la sesión anterior construyó un entorno de depuración
dinámica real (Wine + `winedbg --gdb`) pero se bloqueó porque cualquier
camino de ejecución que pasara del parseo de cabecera hacia el decoder de
píxeles disparaba creación de ventana/dispositivo DirectDraw/OpenGL, que
se colgaba indefinidamente en el sandbox (sin X real, sin gestor de
ventanas).

### El desbloqueo: Xvfb solo, sin gestor de ventanas

Se arrancó `Xvfb :99 -screen 0 1024x768x24` (mismo patrón que la sesión
del `HeadlessException` de Swing, varias sesiones atrás) y se exportó
`DISPLAY=:99` para Wine. **Esto solo bastó** — no hizo falta ningún
gestor de ventanas (`fluxbox`/`openbox`/etc. no están instalados en este
entorno y no se pudieron instalar por falta de `sudo`, pero no hicieron
falta). Con `ScapePicImage.loadImage()` sobre un archivo "normal"
(`ADWORLDS.CMP`, modo `0x02`, el tipo de archivo simple pedido) el
proceso ya no se cuelga: termina limpio (`EXIT 0`) y devuelve
**`width=128, height=128, hDIB=0x0309004D`** — la primera decodificación
real y exitosa obtenida en todas las sesiones de este proyecto sobre
`.cmp`. (El arnés `ScapePicTexture.makeTexture()` de la sesión anterior sí
sigue fallando bajo Xvfb, pero con un error DISTINTO y no relacionado con
ventanas — `Assertion failed: line 98 in file nScapePicTexture` durante
`nativeInit()`, consistente con que el arnés minimalista de esa clase no
replica todos los campos que el código nativo espera; irrelevante para
esta sesión porque `loadImage()` solo, sin `makeTexture()`, ya alcanza y
ejecuta el decoder de píxeles real.)

Con el entorno desbloqueado, un breakpoint puesto en `FUN_00442750`
(validador de cabecera), `FUN_00442bc0` (`getScanline`) y `FUN_00457d88`
(reconstructor de píxeles) — las tres direcciones ya identificadas por
sesiones anteriores — **se alcanzan las tres, en orden, durante una sola
llamada a `loadImage()`** (no hace falta `ScapePicTexture.makeTexture()`
después de todo). Direcciones runtime confirmadas otra vez estables
(`gamma.dll` sigue cargando siempre en `0x03A40000` en este entorno):
`0x03A82750`, `0x03A82BC0`, `0x03A97D88`.

### Ambigüedad #1 resuelta: "aritmética de acarreo" = lectura de bits
### MSB-primero, no aritmética multi-precisión

Traza real de 900 instrucciones (single-step completo, con EFLAGS y los
8 registros generales en cada paso) capturada desde la entrada de
`FUN_00457d88`. **Cero instrucciones `ADC`/`SBB` reales aparecen en la
traza** — lo que Ghidra marcaba como `CARRY4` en su pseudocódigo resulta
ser el patrón clásico de "leer un bit a la vez de un registro de
desplazamiento" mediante `add %edx,%edx` (equivalente a `shl $1,%edx`)
seguido de `jb`/`jae`/`je` sobre el flag de acarreo resultante — el bit
que "se cae" de la posición 31 al desplazar queda en `CF`, y el código
lo usa para caminar un árbol de Huffman de 2-3 niveles mediante saltos
condicionales encadenados (no una tabla de búsqueda por prefijo en esta
parte — la tabla de búsqueda de LHA ya identificada sirve para otra
etapa). Antes de este bucle, el registro de 32 bits recién leído del
stream se pasa por `rol $0x10,%edx` (intercambia las dos mitades de 16
bits) — corrección de orden de bytes necesaria para que la extracción de
bits MSB-primero funcione sobre una palabra leída en little-endian.
**No hay ninguna aritmética de acarreo multi-palabra real** — la
ambigüedad original queda resuelta: es el lector de bits canónico de
LHA/Huffman ya documentado en sesiones anteriores, aplicado aquí con
total literalidad.

### Ambigüedad #2 resuelta: la "escritura de doble fila" es una
### duplicación vertical deliberada de 2 filas por símbolo

Evidencia real, dirección por dirección, de AMBOS caminos de símbolo que
escriben píxeles (relleno de "run" y copia por predictor):

```
; relleno (run-fill), tras obtener un valor de 4 bytes ya replicado
; (dx=cx=bx=ax, vía el manejador de reparto trivial de PTR_LAB_00483844)
mov %dx,(%edi)           ; escribe 2 bytes en la fila ACTUAL
mov %cx,0x2(%edi)        ; escribe 2 bytes más en la fila ACTUAL (4 en total)
add DAT_3ac2d05,%edi     ; edi += stride  (DAT_3ac2d05 = -128 para esta imagen)
mov %bx,(%edi)           ; escribe 2 bytes en la OTRA fila (edi+stride)
mov %ax,0x2(%edi)        ; escribe 2 bytes más en la OTRA fila (4 en total)
sub DAT_3ac2d05,%edi     ; edi -= stride  (vuelve a la fila actual)
```

```
; copia por predictor 2D (tabla en 0x3ac2d0d, ver más abajo)
mov 0x3ac2d0d(,%ebx,4),%ebx  ; ebx = tabla[índice] = desplazamiento de bytes del vecino
mov (%ebx,%edi,1),%eax        ; lee 4 bytes del vecino predicho
mov %eax,(%edi)                ; los escribe en la fila ACTUAL
rol $0x8,%eax
mov %al,(%esi)                  ; 1 byte al buffer de salida de "paleta" (esi)
add DAT_3ac2d05,%edi            ; edi += stride
mov (%edi,%ebx,1),%eax          ; lee 4 bytes del vecino, esta vez relativo a la OTRA fila
mov %eax,(%edi)                  ; los escribe en la OTRA fila
sub DAT_3ac2d05,%edi              ; vuelve a la fila actual
rol $0x8,%eax
mov %al,0x1(%esi)                   ; siguiente byte de salida
```

**Confirmado con evidencia real: cada símbolo (relleno o copia por
predictor) escribe el mismo bloque de 4 bytes en DOS filas separadas por
exactamente un `stride`** — no es limpieza de un buffer de scratch ni un
efecto colateral accidental; es la operación central del símbolo. Dado
que el stride es negativo (DIB "bottom-up") y todo el resto de la
evidencia (tabla de predictores con desplazamientos de fila hasta -4,
más abajo) indica que la imagen se decodifica en el sentido estándar
top-to-bottom mientras el buffer físico crece hacia direcciones más
bajas, la interpretación más consistente es que **cada símbolo pinta un
bloque de 4×2 píxeles (4 de ancho, 2 filas de alto) con el mismo valor
de una sola vez** — una optimización de compresión deliberada que
explota la coherencia vertical típica de texturas de superficies lisas,
no una construcción auxiliar. (Alternativa no descartada del todo: que
sea una pre-siembra de la fila siguiente antes de decodificarla — en
cualquier caso, el hecho verificado y relevante para implementar el
decoder es el MISMO: escribir el bloque en `edi` y en `edi±stride` a la
vez.)

### Bonus: la tabla de predictores en runtime coincide EXACTA con la
### tabla estática ya extraída, con la fórmula de conversión corregida

Se volcó la tabla real que `FUN_00457d88` usa en `0x3ac2d0d` (24 dwords,
memoria en vivo, no inferida):

```
0x3ac2d0d: 0x00000000 0xfffffffa 0xfffffffb 0xfffffffc
0x3ac2d1d: 0xfffffffd 0xfffffffe 0x00000200 0x00000201
0x3ac2d2d: 0x00000202 0x00000203 0x00000204 0x00000205
0x3ac2d3d: 0x00000206 0x000001fa 0x000001fb 0x000001fc
0x3ac2d4d: 0x000001fd 0x000001fe 0x000001ff 0x00000180
0x3ac2d5d: 0x00000181 0x00000182 0x00000183 0x00000184
```

Comparado contra la tabla estática de `(desplazamiento_fila,
desplazamiento_columna)` ya extraída de `0x478e98` en una sesión anterior
(`docs/gamma-dll-cmp-evidence/predictor-offset-tables.txt`), **cada
entrada coincide exactamente** con la fórmula
`offset = colDelta + stride·rowDelta` (con `stride=-128` para esta
imagen) — por ejemplo `(0,-6)→-6`, `(-4,0)→0+(-128)·(-4)=512=0x200`,
`(-4,6)→6+512=518=0x206`, `(-4,-6)→-6+512=506=0x1FA`. **Corrección real
frente a la sesión anterior**: la fórmula tentativa documentada entonces
era `offset = colDelta - stride·rowDelta` (con un signo negativo) — la
ejecución real confirma que es `colDelta + stride·rowDelta` (sin negar).
Esto conecta de forma sólida, con evidencia de dos sesiones distintas
(extracción estática de la tabla + uso real en ejecución), el mecanismo
de predicción 2D documentado desde el principio.

### Ground truth real capturado: fila 0 decodificada, byte a byte

Se volcó la fila de salida real (128 bytes, apuntada por `esi` =
`0xc(%ebp)`) justo al retornar de la ÚNICA llamada real a `FUN_00457d88`
durante un `loadImage()` de `ADWORLDS.CMP` (128×128): **los 128 bytes
son `0xAD` constante** — coincide exactamente con el patrón
`0xadadadad` visto repetido por todo el resto de la traza (el valor
replicado por el manejador de reparto trivial), confirmando de forma
cruzada que esta fila se decodificó enteramente por el camino de
"relleno" (run-fill). Guardado como evidencia cruda en
`docs/gamma-dll-cmp-evidence/adworlds-row0-dump.txt` para verificar
contra una futura reimplementación en Java.

### Corrección real importante: `FUN_00457d88` se invoca UNA sola vez
### por `loadImage()`, no una vez por fila

Con los 3 breakpoints (`FUN_00442750`, `FUN_00442bc0`/`getScanline`,
`FUN_00457d88`) armados, los tres se alcanzan **exactamente una vez cada
uno** durante todo un `loadImage()` completo — el proceso termina
normalmente sin volver a golpear ninguno, incluso para una imagen de 128
filas. Esto corrige la asunción inicial de esta sesión ("una llamada =
una fila decodificada por `ch`, contador de grupos de 4 píxeles"): con
`ch=32` y ancho=128 (`128/4=32`), esa aritmética SÍ encaja para una sola
fila, pero la evidencia de una única invocación total apuntaba a que, o
bien (a) esta llamada decodifica la imagen COMPLETA en un bucle externo
más allá de las 900 instrucciones trazadas, o bien (b) `loadImage()` en
sí solo materializa una fila representativa y el resto se decodifica más
tarde vía `makeTexture()`.

**Resuelto a favor de (a), con evidencia adicional**: se extendió la
traza a 6000 instrucciones (solo registrando el PC en cada paso, sin
volcar registros completos, para mantenerla manejable), comprobando en
cada paso si `ESP` volvía a subir por encima de su valor de entrada (lo
que indicaría un `ret` real de vuelta al llamador) y si el `PC` volvía a
`0x03A97D88` (una reentrada real a la función). **Ninguna de las dos
cosas ocurrió en 6000 instrucciones** — la ejecución sigue dentro de la
función (`PC` final `0x03a97e31`, dentro del mismo rango de direcciones
ya visto). Dado que decodificar una sola fila de 128 píxeles a ~4 por
símbolo con ~20-30 instrucciones por símbolo encajaría en unas 700-900
instrucciones (justo donde se cortó la primera traza), y aun así a las
6000 sigue sin retornar, la explicación mucho más consistente es que
**una sola llamada a `FUN_00457d88` decodifica la imagen COMPLETA
(las 128 filas), no una fila suelta** — coherente con que `getScanline`
solo necesite invocar al decoder una vez y luego sirva cada fila
posterior devolviendo punteros al buffer ya completamente decodificado.
No se llegó a presenciar el `ret` real (habría hecho falta trazar
decenas de miles de instrucciones más, coste no justificado para esta
sesión), así que esto queda como una inferencia fuerte respaldada por
evidencia negativa real (ausencia de retorno/reentrada en 6000 pasos),
no como observación directa del `ret`.

### Qué queda genuinamente sin verificar

- El significado exacto del byte centinela `0x24` (36 decimal) que
  provoca una salida temprana de la rama de "control byte" no se
  investigó más allá de confirmar que existe.
- El espacio completo de símbolos del árbol de Huffman interno (solo se
  trazaron las ramas que esta fila concreta, toda plana, llegó a
  ejercitar — un archivo con más variación de píxeles ejercitaría más
  ramas y podría revelar comportamiento no visto aquí).
- Un decoder Java todavía no se implementó ni se verificó contra el
  ground truth real capturado — dado que las dos ambigüedades
  específicas que motivaron esta sesión (aritmética de acarreo, doble
  fila) SÍ están resueltas, y la granularidad de llamada también quedó
  razonablemente aclarada (una llamada decodifica la imagen completa),
  pero el espacio de símbolos completo del árbol de Huffman NO — solo se
  ejercitaron las ramas que una fila totalmente plana llegó a tocar —
  implementar ahora arriesgaría exactamente lo que el proyecto prohíbe:
  producir píxeles con aspecto plausible pero no verificados. Próximo
  paso concreto y honesto para una futura sesión: trazar 2-3 archivos
  `.cmp` reales adicionales con contenido no plano (para ejercitar más
  ramas del árbol de símbolos, incluyendo el camino de copia por
  predictor 2D y el byte centinela `0x24`) antes de escribir el decoder.

**Conclusión**: las dos ambigüedades que motivaron toda la investigación
dinámica de esta sesión y la anterior — aritmética de acarreo y
propósito de la escritura de doble fila — están **resueltas con
evidencia de ejecución real**, no solo hipótesis. Lo que falta para un
decoder Java completo es trabajo de implementación y verificación
adicional (no ambigüedad de diseño), documentado arriba como próximos
pasos concretos.

---

## Sesión de cierre (2026-09-10, continuación): árbol de símbolos ampliado
## con archivos reales variados, `0x24` resuelto, decoder Java implementado
## y parcialmente verificado — NO conectado al pipeline todavía

Objetivo: cerrar el descompresor `.cmp` ejercitando el árbol de símbolos
completo (no solo el caso trivial de fila plana de la sesión anterior),
implementar el decoder en Java, y verificarlo byte a byte contra
`gamma.dll` real antes de conectarlo al pipeline de materiales.

### Corpus real variado localizado y confirmado no-plano

De los 13 `.cmp` reales únicos del proyecto, se calculó la entropía de
Shannon de cada uno como filtro barato antes de gastar ciclos de
depuración: `ADWORLDS.CMP` (la fila ya analizada) tiene entropía 5.0,
muy por debajo del resto (7.0-7.8), confirmando que era un caso
degenerado. Se seleccionaron `4i.cmp`, `4h.cmp`, `48.cmp`, `4a.cmp` y
`ADFRAME.CMP` (entropía 7.4-7.8) como candidatos reales no planos; los 5
decodifican con éxito bajo Xvfb (128×128, `hDIB` real). Se volcó la fila 0
real de `4i.cmp` y resultó genuinamente variada (9+ valores de byte
distintos en 16 bytes, contra el `0xAD` constante de `ADWORLDS.CMP`) —
corpus válido para ejercitar ramas nuevas del árbol de símbolos.

### Corrección real importante: la granularidad de llamada de sesiones
### anteriores era incorrecta — `ch` produce exactamente `ch×2` bytes,
### no una fila ni la imagen completa

La sesión anterior, al no ver un `ret` ni una reentrada en 6000
instrucciones trazadas, infirió que una sola llamada a `FUN_00457d88`
decodifica la imagen COMPLETA. Verificación real esta sesión (poniendo un
breakpoint en la dirección de retorno real, calculada desde `*esp` al
entrar a la función, en vez de asumir) muestra que **una llamada produce
exactamente `ch×2` bytes de salida real** (`ch=32` en todos los archivos
probados ⇒ 64 bytes = medio ancho de fila para una imagen de 128px) — ni
una fila completa ni la imagen entera. Sesiones futuras que necesiten la
imagen completa seguirán necesitando resolver `ScapePicTexture.
makeTexture()` (ver más abajo) o entender cómo `getScanline` compone
varias llamadas.

### Espacio de símbolos completo, mapeado con evidencia real (viva y
### estática)

Con el archivo variado (`4i.cmp`), una traza de 4000 instrucciones reveló
**236 direcciones nuevas** nunca vistas en la traza plana de la sesión
anterior. Analizadas con registros completos, revelan la estructura
completa del árbol binario superior (2 bits reales, no 3 — el tercer
salto que parecía un nivel adicional en realidad reevalúa el MISMO
resultado de un único `add edx,edx`, leyendo el flag de acarreo y el
flag de cero por separado):

- **bit1=0** → copia de predictor de 4 bytes (un índice, ya documentado
  antes).
- **bit1=1, bit2=0** → **copia de predictor DUAL de 2 bytes** (nueva):
  dos índices independientes, uno por mitad de 2 píxeles del grupo de 4,
  cada uno con su propia escritura de doble fila.
- **bit1=1, bit2=1** → **rama de "byte de control"** (antes solo se había
  visto el caso trivial de relleno de la fila plana): un byte de control
  determina, según sus 3 bits bajos y los bits 3+, entre un par literal
  directo, una referencia hacia atrás (`lookback`) dentro de la propia
  fila de salida ya escrita, o una combinación de ambos.

**El byte centinela `0x24` (36 decimal) — buscado activamente, nunca
apareció en vivo en los archivos probados (0 coincidencias en 58
comparaciones reales), pero se resolvió con desensamblado estático
fresco de Ghidra** de la dirección de destino (`0x00457fb0`): **NO es un
marcador de fin de stream** como se sospechaba — es una **ruta de escape
de literal crudo de 8 bytes**: lee 8 bytes directamente del stream de
literales y los escribe como dos bloques de 4 bytes (uno por fila,
mismo patrón de doble escritura que todo lo demás), sin pasar por la
tabla de predictores en absoluto. Coherente con el resto del diseño: un
mecanismo de escape genérico para contenido que no encaja en ningún
patrón de predicción/relleno.

**Hallazgo real no anticipado, encontrado depurando el primer intento de
verificación fallido**: cada iteración de la rama "byte de control" que
NO es `0x24` **también** consume, sin excepción, un byte del stream de
índice de relleno (el mismo stream usado por el camino de relleno plano
de la sesión anterior) y hace una escritura de difusión adicional (4
copias del byte que acabó en la salida de esta iteración) hacia el
historial — con el mismo patrón de doble fila que todo lo demás. Esto no
se había documentado antes porque en el archivo plano de la sesión
anterior era indistinguible de "no hacer nada" (el valor de difusión
coincidía con el valor ya presente). Se encontró solo al verificar contra
un archivo real con variación, cuando el decoder Java fallaba en TODOS
los bytes hasta corregir esto.

### Decoder Java implementado y verificado — parcialmente

`tools/gamma-dll-debug-harness/cmp-stage2-decoder/CmpStage2.java`
implementa la Etapa 2 completa (símbolos ya decodificados por Huffman →
píxeles reales) con toda la estructura de arriba. Verificado contra datos
reales extraídos en vivo (streams + ventana de historial + salida real,
todo del MISMO proceso en una sola ejecución, para evitar comparar entre
ejecuciones distintas — un error real cometido y corregido durante esta
sesión):

- **`adworlds.cmp`**: 34/64 bytes exactos. Los 30 restantes son un único
  bloque contiguo, y cada uno corresponde a una lectura de predictor con
  desplazamiento >250 bytes hacia adelante — más allá de lo que un volcado
  de memoria único puede capturar de forma fiable (el proceso real puede
  seguir leyendo ahí sin fallar, probablemente por páginas comprometidas
  de forma perezosa a medida que se escribe cerca; un volcado estático
  de Python en un solo instante no puede reproducir eso). Limitación de
  captura de datos, no evidencia de error de diseño — en este archivo
  totalmente plano, CADA uno de esos bytes debería ser `0xAD` igual que
  el resto, y el decoder los produce mal únicamamente porque mi
  relleno-con-ceros ocupa el lugar de datos reales que no pude capturar.
- **`4i.cmp`**: 55/64 bytes exactos. Los 9 restantes (posiciones 41-49)
  se investigaron a fondo: la secuencia EXACTA de bytes de control y el
  consumo de posición de stream de literales se verificaron, iteración
  por iteración, contra una traza en vivo (26 iteraciones de "byte de
  control" comparadas una a una, coincidencia perfecta), y el byte
  literal específico que el decoder lee se confirmó en memoria viva en
  la posición correcta — y aun así, el "ground truth" capturado para esas
  posiciones concretas no coincide. No resuelto antes de que se agotara
  el tiempo de esta sesión. Ver el método de captura de "ground truth" en
  `tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md` — lo más
  probable, dado lo demás verificado independientemente, es un problema
  del propio método de captura, no del algoritmo, pero **no está
  demostrado** y se documenta honestamente como abierto.

### `ScapePicTexture.makeTexture()` — progreso real, sigue bloqueado

Se intentó de nuevo destrabar `makeTexture()` (necesario para decodificar
una imagen completa, no solo 64 bytes) replicando con más fidelidad la
jerarquía real de clases (`Texture` con `textureID`/`refs`/`classCookie`,
`ScapePicMovie` con el tipo exacto). Esto SÍ avanzó el punto de fallo (de
un `Assertion failed: line 98` a `line 99`, y finalmente a un
`EXCEPTION_ACCESS_VIOLATION` real — más profundo en el código real que
antes) pero no se resolvió del todo. No se investigó más allá por límite
de tiempo de la sesión.

### Por qué NO se conectó nada al pipeline de materiales esta sesión

Siguiendo la regla explícita del proyecto (nunca píxeles con aspecto
plausible pero sin verificar), y dado que NINGÚN archivo real alcanzó
verificación 100% byte-exacta (34/64 y 55/64, no 64/64), **no se conectó
el decoder al pipeline de renderizado**. Habría sido fácil mostrar "algo"
en pantalla, pero no se puede afirmar honestamente que sea la textura
real hasta que la verificación sea completa. Próximo paso concreto y
priorizado para una futura sesión: (1) mejorar el método de captura de
ground truth (breakpoints reales en cada instrucción de escritura en vez
de sondeo de `$pc` en cada `stepi` — más rápido y más fiable), (2)
resolver el gap de 9 bytes de `4i.cmp` con datos más limpios, (3) una vez
100% verificado en 2-3 archivos, conectar al pipeline y verificar por
histograma de color que aparecen patrones de textura reales.

---

## Sesión Stage 1 (2026-09-11): decodificador Huffman de verdad
## desensamblado con evidencia real — arquitectura completa entendida,
## el encadenado exacto entre "filas" sigue sin cerrar (NO funcional aún)

Objetivo: implementar el Stage 1 real (bytes `.cmp` crudos → los 5
streams de símbolos que `CmpStage2` ya consume byte-exacto), motivado
por la necesidad de decodificar texturas reales de `GroundZero` (159
archivos `.cmp` oficiales sin ninguna captura de streams previa — sin
Stage 1, ninguno de ellos es decodificable). **No se cerró del todo**,
pero se desensambló con evidencia real (Ghidra/`llvm-objdump`, sin
adivinar) una cadena mucho más larga de lo que había antes, incluyendo
**el decodificador de bits real completo**, y se documenta todo aquí con
precisión byte a byte para que una sesión futura no tenga que repetir
este trabajo.

### Cabecera de 34 bytes — layout completo, verificado contra los 3
### archivos reales conocidos

`FUN_00442750` (offset runtime confirmado, `0x03A82750` en este
entorno) lee y valida 34 bytes (`0x22`) así:

```
[0..3]   "LzH2" (magic, comparado con memcmp contra 0x479324)
[4]      "modo" (0x02 en los 3 archivos de prueba)
[5]      flags: bit7 debe ser 1; bits 2,3,4,6 deben ser 0; bits 0,1,5 libres
           (bit0=1 en test4b, 0 en rustwood/sball — candidato fuerte a ser
           el flag "orientation" que `CmpTexture.java` ya vota por archivo
           como `orient`, sin conocer su origen — esta sesión lo localiza
           en la cabecera, sin conectarlo todavía)
[6..7]   W (u16 LE)          -- ya usado por CmpTexture.java
[8..9]   H (u16 LE)          -- ya usado por CmpTexture.java
[10..18] sin decodificar (9 bytes, varían por archivo)
[19]     debe ser 0 (verificado en los 3 archivos)
[20..31] sin decodificar (12 bytes)
[32..33] payload size = fileSize - 34 (u16 LE) — **verificado exacto en
           los 3 archivos**: test4b 364, rustwood 6539, sball 3954,
           cada uno = tamaño total del archivo menos 34.
```

### Las 3 tablas de permutación de alfabeto fijo — extraídas byte a byte
### directamente del binario (no de memoria de sesiones anteriores)

`FUN_00442590(tableIndex, flag, &out)` es un switch de 4 vías (jump
table real en VA `0x4792e8`, leído directamente del archivo):

- índice 0 → 81 bytes en VA `0x47927c`:
  `555657595a5b5d5e5f656667696a6b6d6e6f757677797a7b7d7e7f959697999a9b9d9e9fa5a6a7a9aaabadaeafb5b6b7b9babbbdbebfd5d6d7d9dadbdddedfe5e6e7e9eaebedeeeff5f6f7f9fafbfdfeff`
  (permutación real, no secuencial)
- índice 1 → 49 bytes en VA `0x479028`:
  `0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f3031`
  (secuencial 1..49 — de facto identidad)
- índice 2 → **degenerado**: el jump table apunta al mismo caso "fuera
  de rango" que índice≥4 (`eax=0`, `*out` queda en 0 sin escribir) — el
  canal de índice 2 no tiene tabla de permutación ni alfabeto fijo en
  absoluto. Significado real NO resuelto (ver más abajo).
- índice 3 → 22 bytes en VA `0x4792d0`:
  `0001020304080a0b0c1011131418191a1c2021222324`

### El bucle de 5 canales en `getScanline` (`FUN_00442bc0`) — mapeo
### canal↔stream confirmado por desensamblado, no supuesto

Desensamblado completo de `0x442e63`-`0x442f5b`: por cada "grupo"
(llamado una vez antes de cada llamada a Stage 2, `FUN_00457d88`), lee
un puntero `dec` de una estructura pequeña y, para `edi=0..4`, si
`dec_orig[2+edi*2]` (u16) es no-cero, llama
`FUN_00426af0(this=tableHandle, compressedPtr, outputPtr, wantedLen)` —
y **el resultado se guarda en un array local `[-0x28(ebp)+edi*4]` que
es literalmente el mismo puntero (`structptr`) que luego se pasa como
5º argumento a `FUN_00457d88`/Stage 2** — confirma con desensamblado
real (no solo con `cmp_capture.py`, que ya lo había hallado
empíricamente) el orden de canales: `edi=0→bits, 1→streamA,
2→streamFillIdx, 3→streamCtrl, 4→streamLit`. **El canal 4 (`lit`) usa
copia directa** (no pasa por `FUN_00426af0`), consistente con "1 de 5
sin Huffman".

**Implicación intrigante, no resuelta**: el canal 2 (`streamFillIdx`)
es exactamente el que tiene alfabeto degenerado (índice 2, sin
permutación) según `FUN_00442590` — pero `streamFillIdx` SÍ tiene
contenido real variado en los archivos verificados (es la máscara de 8
bits que elige `al`/`ah` por carril, documentada en
`cmp-stage2-decoder/README.md`). O el "degenerado" no significa "vacío"
sino "usa longitudes de código de 1 byte sin permutar" (una
interpretación alternativa de `FUN_00426640` no descartada), o el mapeo
canal↔índice-de-alfabeto no es 1:1 con el mapeo canal↔stream-de-salida
que se acaba de confirmar arriba — **abierto, marcado explícitamente
para no inventar una explicación**.

### El decodificador de bits real, `FUN_00426af0` — desensamblado
### completo, algoritmo simple y ahora entendido con confianza alta

Contrario a lo asumido en sesiones anteriores ("árbol de Huffman de 2-3
niveles"), el desensamblado real (VA `0x426af0`-`0x426bae`) muestra que
**todos los códigos tienen longitud ≤ 8 bits** — no hace falta caminar
ningún árbol, es una tabla de búsqueda directa de 256 entradas:

```
tabla: 512 bytes por canal = [0..255]=símbolo, [256..511]=longitud_de_código
ventana = (byte[pos]<<8) | byte[pos+1]; pos += 2   # primera carga, 16 bits
bitsDisponibles = 8   # contador con signo (ch, 1 byte)
para cada uno de los `wantedLen` bytes de salida:
    idx = (ventana >> 8) & 0xFF          # top byte de la ventana de 32 bits
    símbolo = tabla[idx]; longitud = tabla[256+idx]
    emitir(símbolo)
    bitsViejos = bitsDisponibles
    bitsDisponibles -= longitud
    si bitsDisponibles < 0:              # hace falta recargar
        ventana <<= bitsViejos            # consume los bits que SÍ había
        nuevoByte = byte[pos++]
        ventana = (ventana & ~0xFF) | nuevoByte   # solo el byte bajo
        faltante = longitud - bitsViejos
        bitsDisponibles += 8
        ventana <<= faltante               # alinea el byte nuevo
    si_no:
        ventana <<= longitud
devuelve: pos_final - pos_inicial   # bytes consumidos del stream comprimido
```

Esto reproduce exactamente el truco clásico LHA/LZH de acumulador de 32
bits con recarga de 1 byte bajo demanda — pero SIN camino de "código
largo" en absoluto (a diferencia de LHA genérico, que sí necesita
manejar códigos >8 bits con una tabla de desbordamiento). Coincide con
"cuenta de frecuencias por longitud 0-8" ya documentado.

### Construcción de tabla (`FUN_00426640`/`FUN_004266f0`/`FUN_00426820`)
### — reconocida como `make_table()` de LHA, PARCIALMENTE portada, con
### un caso degenerado sin verificar

`FUN_00426640` desempaqueta nibbles de 4 bits (2 por byte de entrada,
uno por símbolo del alfabeto REDUCIDO de tamaño 81/49/22) y los
dispersa en un array de 256 longitudes usando la tabla de permutación
como índice destino — confirmado por desensamblado línea a línea.
`FUN_004266f0` reconocida con alta confianza como el `make_table()`
canónico de LHA (cuenta frecuencias por longitud, calcula
`start[l+1]=(count[l]+start[l])·2`, asigna códigos en una 2ª pasada) —
**con un caso especial degenerado** (`if sum<=1: return early`) cuyo
comportamiento exacto en la fase de expansión (`FUN_00426820`) sólo se
desensambló parcialmente: hay una rama "simple" (`[ebp+0xc]<=1`) que
rellena la tabla de símbolos entera con el valor `0` — pero el caso
GENERAL (>1 símbolo real) de `FUN_00426820`, que expande los códigos
canónicos asignados en la tabla directa de 256 entradas, **se
implementó siguiendo el patrón LHA de libro de texto (rellenar
`2^(8-longitud)` ranuras consecutivas desde el código alineado a 8
bits), no una traducción literal instrucción a instrucción del
desensamblado** — riesgo real de estar sutilmente equivocado.

### Intento de implementación Java: NO funcional todavía — el "avance
### entre grupos" del bucle externo es la pieza que falla

Con todo lo anterior, un prototipo en Java (no incluido en el repo,
vivió en `/tmp` durante esta sesión) construyó las 4 tablas Huffman
correctamente (el conteo de bytes consumidos para desempaquetar las
longitudes — 41+25+0+11=77 bytes — coincide exacto con lo esperado para
alfabetos 81/49/0/22), pero el bucle externo que debería leer, grupo a
grupo, 5 campos de longitud (u16) y decodificar cada canal, **diverge
después de 3-4 grupos**: los primeros grupos leen longitud 0 en los 5
canales (plausible para un archivo casi todo plano como `test4b.cmp`,
pero no verificado como correcto), y hacia el grupo 3-5 aparecen
longitudes que exceden el presupuesto total de bytes del archivo
(`lit=252` cuando sólo quedan ~287 bytes en todo el payload para
`outer=16` grupos) — señal clara de que el avance de puntero entre
grupos (asumido `+0x10=16` bytes, tomado literal del desensamblado de
`getScanline`) y/o la posición exacta de los 5 campos de longitud
dentro de esa estructura de 16 bytes **no está bien modelada todavía**
— quedan 6 de los 16 bytes por grupo sin explicar (posiblemente más
metadatos, o el conteo `outer=H/2` no es el número real de grupos).

### Qué queda para la próxima sesión, con evidencia ya en mano

1. Trazar en vivo (winedbg/gdb, entorno ya probado y funcional esta
   sesión: `Xvfb` + `wineserver -k` + `winedbg --gdb` con breakpoints
   temporales en la dirección de retorno, NO usar `finish` — no se
   comporta como en gdb nativo bajo el proxy de winedbg, confirmado
   esta sesión) un breakpoint en el TOPE del bucle externo de
   `getScanline` (`0x442e05`/`0x442fab` en runtime, delta variable —
   ver la nota de "gamma.dll's load base is NOT fixed" en el README del
   harness) para capturar en vivo cuántos grupos se ejecutan de verdad
   y qué contiene exactamente cada bloque de 16 bytes (los 2 campos u16
   ya identificados en offsets 0 y 0xc de `dec_orig`, además de los 5
   de longitud en offsets 2-11 — falta decodificar offsets 12-15 y
   confirmar los 0/0xc).
2. Verificar `FUN_00426820`'s caso general con desensamblado línea a
   línea completo (esta sesión sólo lo leyó parcialmente) en vez de la
   implementación de libro de texto usada en el prototipo.
3. Resolver la anomalía del canal 2 (`streamFillIdx`) con alfabeto
   degenerado — probablemente necesita trazarse en vivo para ver qué
   construye realmente `FUN_00426930` cuando `alphabetSize=0`.
4. Una vez el prototipo decodifique `test4b.cmp` byte-exacto contra
   `assets/gammatutorial-samples/test4b.cmp` (comparando contra sus
   streams ya verificados en `tools/gamma-dll-debug-harness/
   cmp-stage2-decoder/test4b_stream_*.bin`), repetir contra
   `rustwood.cmp`/`sball.cmp`, y sólo entonces intentar los 159
   archivos reales de `assets/WorldsPlayer/GroundZero/content.zip`.

**Nada de esto se conecta al pipeline de materiales** — ni un solo byte
de las 159 texturas reales de GroundZero se decodificó esta sesión; el
prototipo no llegó a producir salida verificable contra ningún archivo
conocido. Documentado honestamente como investigación real pero
incompleta, no como progreso funcional.

### Ronda 2 (2026-09-11, la misma sesión continuada): el bucle externo
### tiene UN SOLO grupo, no 16 — y se descubre un problema arquitectónico
### más profundo (lector de stream con buffer, no un puntero plano al
### archivo)

Trazado en vivo (`winedbg`/`gdb`, breakpoint auto-continuo en
`0x442e66` — justo DESPUÉS de que `eax` cargue el puntero `dec_orig`,
no en `0x442e63` como en el primer intento, que capturaba el valor
VIEJO de `eax` antes de la propia instrucción de carga) contra
`test4b.cmp`:

**Hallazgo 1 — sólo hay UN grupo, no `h/2=16`**: el breakpoint (que
auto-continúa, así que habría capturado cualquier repetición real) sólo
disparó **una vez** en todo el `loadImage()`. El contenido real de esos
16 bytes fue `10 00 20 00 7c 00 04 00 04 00 05 00 00 00 00 00` —
interpretados con el layout ya conocido (offset 0 y 0xc = campos sin
identificar, offsets 2-11 = 5 longitudes u16): `bits=32 streamA=124
streamFillIdx=4 streamCtrl=4 streamLit=5`. **Confirmación cruzada
fuerte, no coincidencia**: `streamA=124` y `streamCtrl=4` coinciden
EXACTO con el censo de ramas ya establecido independientemente en una
sesión `.cmp` anterior para este mismo archivo ("real: 124 SINGLE + 4
CTRL + 0 DUAL") — SINGLE consume un índice de `streamA` por iteración,
CTRL un byte de `streamCtrl` — validando que la interpretación semántica
de estos 5 campos es correcta. Esto también resuelve una duda antigua
de sesiones `.cmp` anteriores ("¿por qué sólo una llamada real a
`FUN_00457d88`?"): `FUN_00457d88` recibe TODOS los datos de canal de
una vez (un solo grupo cubre la imagen entera) y loopea internamente
sus `outer` pases usando ese buffer ya completo — no hace falta más de
una llamada.

**Hallazgo 2 — el mapeo dirección-de-memoria→offset-de-archivo NO es
lineal, arquitectura más compleja de lo asumido**: buscando el
contenido exacto de esos 16 bytes dentro del propio archivo
`test4b.cmp`, aparece en el **offset 359** (de 398 totales) —
confirmando que el grupo SÍ vive en algún lugar correlacionable con el
archivo real. Pero al intentar la MISMA correlación para los punteros
usados en la construcción de las tablas Huffman (capturados con un
breakpoint en `FUN_00426640` y en el sitio de llamada a `FUN_004269c0`
dentro del bucle de `FUN_00442750`), **los offsets calculados dan
negativos** (usando `fileBase = addr_grupo - 359` como referencia) —
es decir, esos punteros NO caen dentro del mismo espacio de direcciones
lineal que el puntero del grupo. Esto indica que **los datos
comprimidos no se leen como un buffer plano mapeado 1:1 con el
archivo** — la cadena de llamadas ya documentada (`FUN_00442750` llama
a `0x42f460`, identificado en sesiones anteriores como un
`ReadBytes(readerObject, dest, size)`, no un simple `memcpy`) confirma
que hay un **objeto lector de stream con su propio buffer interno**
(probablemente `ReadFile` de Win32 con buffering), y las distintas
fases (construcción de tablas, luego decodificación de canales) leen a
través de ese lector, no de un array plano — así que "posición X en el
puntero visto en memoria" y "offset X en el archivo" sólo coinciden
quiere por casualidad de contenido (como con el grupo, encontrado por
búsqueda de contenido, no por aritmética de punteros).

**Implicación honesta**: mi modelo de "un `pos` que avanza linealmente
sobre los bytes del archivo, consumido tanto por la construcción de
tablas como por la decodificación de canales" (usado en el prototipo
Java de la ronda 1) es **estructuralmente incorrecto** — no es sólo un
offset mal calculado, es una arquitectura de lectura por stream con
buffer que no se ha investigado todavía. Cerrar esto de verdad requiere
entender el objeto lector (`0x42f460` y su contraparte de refill/buffer
interno) antes de poder traducir "cuántos bytes consumió esta fase" en
"dónde sigue el archivo" de forma fiable — no es una corrección menor
de offsets, es una pieza nueva de ingeniería inversa.

**Qué SÍ queda genuinamente ganado esta ronda**: el mapeo semántico de
los 5 campos de longitud por grupo (con evidencia cruzada real e
independiente para 2 de los 5: `streamA` y `streamCtrl`), y la
confirmación de que sólo hay un grupo por imagen (no un grupo por par
de filas) — ambos hechos reales y útiles para la próxima sesión,
aunque el objeto lector de stream siga sin desensamblarse.

**No se intentó** verificar `FUN_00426820` en detalle ni decodificar
ningún archivo real de GroundZero — el hallazgo del lector de stream
volvió esos pasos prematuros (siguiendo la instrucción explícita de no
perseguir el canal 2 degenerado especulativamente antes de resolver lo
anterior). Próximo paso concreto y acotado: desensamblar `0x42f460` (el
lector) y su mecanismo de buffer/refill, con trazado en vivo del valor
real de posición-de-archivo que mantiene internamente, ANTES de
retomar la traducción puntero→offset.

## Sesión Stage 1 real (2026-09-12): el "lector con buffer" era un
## espejismo, Stage 1 implementado de verdad — 4/5 streams byte-exactos,
## paleta embebida descubierta, un bug de mapeo de color sin resolver

Objetivo de la sesión: resolver el bloqueo del "lector de stream con
buffer" (encontrado la sesión anterior) y conseguir que Stage 1 funcione
contra archivos reales del juego, no solo los 3 de prueba. Se construyó
primero un arnés de verificación contra el corpus real completo (ver
`docs/cmp-stage1-coverage.md`), y luego se resolvió el bloqueo con 3
subagentes de solo lectura en paralelo.

### El "lector de stream con buffer" no existe — era una comparación entre
### punteros de dos allocaciones de heap distintas

Tres subagentes de solo lectura, cada uno investigando una hipótesis
distinta (estructura/inicialización del lector; mecanismo de refill;
comparación cruzada entre los 3 archivos conocidos), confirmaron de forma
independiente y consistente:

- `FUN_0042f460` es literalmente `std::istream::read(buf, count)` de
  MSVC/Dinkumware — sin complejidad de buffering propia más allá de lo que
  ya hace la streambuf estándar. No hace falta modelar ningún objeto lector
  especial.
- Para `test4b.cmp` (398 bytes) hay exactamente 3 llamadas de lectura,
  verificadas en vivo byte a byte: 34 bytes (cabecera, offset archivo
  `[0,34)`), 325 bytes (región de construcción de tablas, `[34,359)`), y 39
  bytes (región del grupo, `[359,398)`) — contiguas, sin huecos, sin
  solapamiento.
- La "paradoja del offset negativo" de la sesión anterior (punteros de
  construcción de tablas no correlacionaban linealmente con el puntero del
  grupo) se explica completamente: son dos allocaciones de heap
  DIFERENTES (la región de 325 bytes va a un buffer, la región de 39 bytes
  del grupo a otro) — nunca hubo un lector con ventana compleja, solo se
  estaban restando punteros de memoria no relacionados.

### Cabecera de 34 bytes — 2 campos nuevos decodificados con evidencia real

```
[28..29] tableRegionSize (u16 LE) — tamaño exacto de la 2ª lectura
           (325 para test4b, 34+325=359 coincide exacto con el offset de
           grupo ya conocido por búsqueda de contenido)
[30..31] groupRegionSize (u16 LE) — tamaño exacto de la 3ª lectura (39
           para test4b); tableRegionSize+groupRegionSize == payloadSize
           siempre, verificado exacto
[14..18] 5 bytes, uno por canal (0=bits,1=streamA,2=streamFillIdx,
           3=streamCtrl,4=streamLit): byteLen exacto que ese canal
           consume durante la construcción de su tabla Huffman en la
           región de tablas — verificado exacto contra captura en vivo
           (28,16,1,7,32 para test4b)
```

### El "lector con buffer" desapareció, pero apareció un preámbulo de
### verdad: una paleta de color embebida, nunca antes decodificada

Antes de las 4 construcciones de tabla Huffman, la región de tablas tiene
un preámbulo (239 de 325 bytes para test4b) que se pensaba de ~7 bytes en
sesiones anteriores. Desensamblado real de `FUN_00442750` (el tramo entre
la 2ª lectura y el bucle de construcción de tablas) revela que es una
**paleta de color embebida**, decodificada por `FUN_004426b0`:

```
count = header[12] (si es 0, 256)   -- 64 para test4b
para cada una de las `count` entradas:
    para cada uno de los 3 componentes (R,G,B en ese orden):
        leer 6 bits del stream (MSB primero, acumulador de 1 byte con
        refill por byte, igual mecanismo que FUN_00426af0 pero para 1
        bit en vez de código completo)
        componente = valor_6_bits << 2   (escala 6→8 bits)
    escribir 3 bytes reales + 1 byte nulo de relleno (no cuenta para el
    stream de bits, es solo el layout de memoria de gamma.dll)
```

Verificado bit a bit a mano contra los bytes crudos del archivo (no solo
con el propio código): las 4 entradas reales de test4b (58→verde,
60→rojo, 62→amarillo, 63→azul) coinciden exactamente extrayendo los bits
manualmente con Python, confirmando que la extracción de bits es 100%
correcta contra el archivo real — el problema (ver más abajo) no está en
esta extracción.

Después de la paleta, el cursor avanza condicionalmente según bits del
byte de **modo** (offset 4, no flags) y del byte de **flags** (offset 5):

```
cursor = bytesConsumidos_por_paleta
si (modo & 0x02) == 0: cursor += count
si header[13] != 0: cursor += floor((header[13]*18+7)/8)
si (flags & 0x01) != 0: cursor += floor(count/2) + count - 1
si (modo & 0x08) != 0: cursor += 4
si (modo & 0x80) != 0: groupCount = u16(cursor); cursor += 14
si_no: groupCount = 1   (siempre el caso en los 3 archivos conocidos)
```

Para test4b: bit1 de modo=1 (no suma), header[13]=0 (no suma), bit0 de
flags=1 (suma 95), bit3/bit7 de modo=0 (no suma) → cursor=144+95=239,
exacto.

### Las 4 tablas Huffman — algoritmo completo verificado con datos reales,
### 2 bugs de implementación encontrados y corregidos

`FUN_00426640` (desempaquetado de nibbles) desensamblado instrucción a
instrucción: `effectiveCount = min(alphabetSize, 2*byteLen)` nibbles se
leen (NO siempre `alphabetSize` nibbles como se asumía) — los símbolos del
alfabeto reducido que quedan fuera de `effectiveCount` simplemente
conservan longitud 0 (sin código). Confirmado exacto contra los 4
`byteLen` reales de test4b.

`FUN_004266f0`/`FUN_00426820` (asignación canónica + expansión a tabla
directa de 256 entradas) — 2 bugs reales encontrados esta sesión al
implementar en Java, ambos con síntomas claros:

1. **Off-by-one en el array `start[]`**: `start[1] = 0` directamente (no
   derivado de `count[0]`, que nunca participa — los símbolos de longitud
   0 no tienen código). La implementación inicial calculaba
   `start[1] = count[0]*2`, produciendo códigos que desbordaban la tabla
   de 256 entradas (`ArrayIndexOutOfBoundsException` inmediato al
   probar).
2. **Longitud incorrecta en el caso degenerado** (un solo símbolo real):
   la implementación inicial ponía `length=0` para todas las 256 entradas
   de la tabla degenerada — pero la longitud real debe ser la del ÚNICO
   símbolo real (ej. 1 bit), no 0. El síntoma fue invisible en el canal
   degenerado mismo (`streamFillIdx`, que da el símbolo constante 0 sin
   importar cuántos bits se consuman), pero desincronizaba el cursor de
   bits COMPARTIDO para el siguiente canal (`streamCtrl`), que entonces
   fallaba con síntomas que parecían un problema de alineación de bits.

### El decodificador de bits necesita estado COMPARTIDO entre canales

Confirmado empíricamente (no solo por lectura de la documentación previa,
que era ambigua sobre esto): la ventana de 16 bits y el contador de bits
disponibles de `FUN_00426af0` deben persistir entre las 5 llamadas por
canal dentro de un grupo — SOLO el primer canal (`bits`) hace la carga
fresca inicial de 16 bits; los canales 2-5 continúan desde donde el
anterior dejó el estado (incluidos bits sueltos a mitad de byte). Probado
explícitamente contra ambos modelos (recarga fresca por canal vs.
continuación compartida) — solo el modelo compartido reproduce
`streamA` (124 símbolos, con muchos refills reales) byte a byte exacto.

### El misterio del "alfabeto degenerado" del canal 2 — resuelto

Confirmado por desensamblado estático completo (subagente de solo
lectura): NO es un canal vacío. `FUN_004269c0` comprueba
`permTablePtr==0 || alphabetSize==0` y en ese caso sintetiza una
permutación identidad de 256 símbolos (`0,1,2,...,255`) y fuerza
`alphabetSize=256` ANTES de construir la tabla — así que el canal 2
(`streamFillIdx`) se codifica con Huffman sobre el alfabeto COMPLETO de
256 bytes en vez de uno de los 3 alfabetos reducidos (81/49/22), lo cual
encaja perfectamente con que sea el único canal que necesita representar
cualquier valor de byte (la máscara de selección de carril al/ah), no un
opcode/escape de un conjunto pequeño y cerrado.

### Verificado byte a byte contra los streams ya capturados de test4b.cmp

`bits`, `streamA`, `streamFillIdx`, `streamCtrl`: **0 discrepancias**,
byte exacto contra `tools/gamma-dll-debug-harness/cmp-stage2-decoder/
test4b_stream_*.bin` (captura en vivo de sesiones anteriores, ground
truth independiente). `streamLit` (canal 4, el mecanismo de escape
literal, poco usado): muy cerca pero NO exacto — ver limitación abajo.

### Dos limitaciones honestas, documentadas explícitamente en el código
### (`CmpStage1.java`), NO resueltas esta sesión

1. **`streamLit` (canal 4)**: el mecanismo real de construcción de su
   tabla usa `FUN_0044df50` (un memcpy plano de 32 bytes), no
   `FUN_004269c0` como los canales 0-3 — tratarlo igual que el caso
   degenerado del canal 2 (alfabeto identidad de 256) da una salida MUY
   cercana a la real (los mismos 4 valores de símbolo, mismas longitudes
   de código) pero rotada exactamente una posición de código respecto al
   valor esperado. Se probaron varias hipótesis (recarga fresca en vez de
   continuar; intercambiar el orden con `ctrl`; tabla de índice directo de
   5 bits) sin éxito — queda abierto.
2. **Mapeo de índice de píxel decodificado → entrada de paleta**: la
   extracción de bits de la paleta embebida se verificó 100% exacta
   contra los bytes crudos del archivo (a mano, con Python, byte a byte),
   y las regiones espaciales de la imagen decodifican perfectamente
   (prueba independiente de que los streams de símbolos son correctos) —
   pero el color final asignado a cada índice sale ROTADO entre las 4
   entradas reales usadas (58,60,62,63 para test4b): el índice 58
   necesita mostrar rojo pero `palette[58]` contiene verde (que
   pertenece a otro índice). Se probaron varias hipótesis de
   transformación (desplazamiento uniforme de índice, XOR, resta, orden
   de lectura invertido, reordenación de componentes R/G/B) — ninguna
   explica la rotación exacta observada. Documentado en detalle en el
   comentario `KNOWN LIMITATION` de `CmpStage1.java`, no oculto.

### `CmpTexture.loadRaw(File)` — integración real, sin regresión

Se añadió `CmpTexture.loadRaw(File cmpFile)`, que decodifica un `.cmp`
real usando `CmpStage1` y reutiliza el pipeline YA VERIFICADO de
`CmpStage2` (el mismo código que `load()` ya usaba con streams
precapturados). El path original `load()` (streams precapturados +
`palette.txt` a mano) se probó sin cambios contra `sball.cmp` — sigue
funcionando exacto, cero regresión.

### Verificación contra el corpus real (criterio de cierre de esta sesión)

Ver `docs/cmp-stage1-coverage.md` para el resultado numérico completo
contra los 159 archivos reales de `content.zip` usando `loadRaw()` — dado
el bug de mapeo de paleta sin resolver arriba, se espera que la mayoría
de archivos NO decodifiquen a píxeles correctos todavía, pero el corpus
completo se corrió igualmente para tener el número real, no una
estimación.

## Continuación (misma sesión, 2026-09-12): la paleta SÍ era correcta —
## el bug real estaba en `streamLit`; `test4b.cmp` ya decodifica
## píxel-exacto de punta a punta

El "bug de mapeo de paleta" de la sección anterior era un diagnóstico
equivocado. Lo real:

1. **La paleta (lectura secuencial directa, `palette[i]` = i-ésima
   entrada leída, sin desplazamiento) era correcta desde el principio.**
   Verificado de dos formas independientes: extracción manual bit a bit
   contra `test4b.cmp`, y comparación índice por índice contra el
   `sball.palette.txt` ya votado a mano (16/16 entradas coinciden
   exactas con indexación de identidad simple). Un intento de "+1"
   dentro de esta misma sesión fue un callejón sin salida — coincidía
   por poco con la evidencia dispersa de test4b pero no con la evidencia
   densa de sball.
2. **El bug real estaba en el canal 4 (`streamLit`)**: desensamblado
   completo de `FUN_0044df50` (el "memcpy" de 32 bytes) y su llamador
   diferido `FUN_00442bc0`/`FUN_00442bee` confirma que el canal 4 usa
   MECÁNICAMENTE el mismo camino que el canal 2 (`FUN_004269c0` con
   `permTablePtr=0`, `alphabetSize=0` → alfabeto identidad de 256), solo
   que la construcción de tabla ocurre de forma diferida. Con eso
   establecido, una búsqueda por fuerza bruta (deslizar la ventana de
   símbolos decodificados contra el píxel real de `test4b.bmp`, probando
   también las 4 combinaciones de orientación) encontró una única
   respuesta con 0 diferencias: **descartar el primer símbolo decodificado
   del canal LIT** (decodificar `wanted[4]+1` símbolos, quedarse con los
   últimos `wanted[4]`). Confirmado como la ÚNICA combinación con 0
   diferencias entre todos los desplazamientos y orientaciones probados,
   no una coincidencia.
3. **Este arreglo NO generaliza**: la misma búsqueda por fuerza bruta
   contra `sball.cmp` (alfabeto LIT mucho más rico — `byteLen[4]=128`
   contra los 32 de test4b) nunca llega a 0 diferencias en ningún
   desplazamiento 0-6 ni orientación (mejor resultado: ~74% de píxeles
   todavía incorrectos). El mecanismo real para alfabetos ricos sigue sin
   resolverse — ver investigación en curso abajo. Es posible que el canal
   2 (`streamFillIdx`) tenga el mismo bug latente para alfabetos ricos
   (para `sball.cmp` también tiene `byteLen[2]=128`), nunca antes puesto a
   prueba porque en `test4b.cmp` ese canal es degenerado.
4. **Orientación (`pass0Top`) también estaba mal derivada**: la sesión
   anterior la ligó al bit 0 de `flags`, ajuste hecho contra el decode de
   LIT todavía roto. Con LIT arreglado, `test4b.cmp` necesita
   `pass0Top=false` (lo opuesto de lo que ese bit daría) — igual que
   `sball.cmp`. Ninguno de los 2 casos conocidos correlaciona con ese bit
   bajo el entendimiento correcto, así que `CmpTexture.loadRaw` lo fija a
   `false` por ahora, pendiente de más ejemplos reales.

**Resultado verificado**: `test4b.cmp` decodifica byte-exacto (0/3072
bytes, 0/1024 píxeles) de punta a punta contra el render real de
`cmpview.exe`, a través del pipeline completo `loadRaw()` — sin streams
precapturados, sin `palette.txt` a mano. `sball.cmp` y alfabetos LIT
ricos en general quedan sin resolver — no se reclama cierre de corpus
todavía; investigación activa vía trazado en vivo contra `sball.cmp` en
curso al momento de escribir esto.

También se corrigió el harness de cobertura: `compare -metric AE` de
ImageMagick daba valores imposibles en este entorno (4.4e7 "píxeles"
distintos para una imagen de 1024 píxeles) — reemplazado por comparación
directa de bytes en Python en `cmp_stage1_coverage.py`, que sí da
números confiables (confirmado: `test4b.cmp` reporta 0/1024 a través del
harness, coincidiendo con la verificación independiente).

## Continuación (misma sesión): baseline real del corpus (7/159) señala
## la causa raíz, subagente de trazado en vivo la encuentra — 2 bugs
## reales, `sball.cmp` también byte-exacto

Con `test4b.cmp` cerrado, se corrió el corpus completo de 159 archivos
reales de `content.zip` como baseline real (no estimado): **7/159 OK,
152 FAIL** (de los cuales solo 2 son excepciones/crashes —
`roofb.cmp` y `vendside2.cmp`, `ArrayIndexOutOfBoundsException`, sin
investigar todavía; el resto decodifica sin fallar pero con píxeles
incorrectos). `groupCount` fue 1 para los 159 archivos — el camino
`mode&0x80` (múltiples grupos) sigue sin ejercitarse por ningún archivo
real conocido.

Cruce de los campos de cabecera de los 7 archivos que SÍ pasaron contra
una muestra de 8 que fallaron reveló el patrón real: los 7 que pasan
tienen `streamFillIdx` (canal 2) degenerado (`byteLen=1`, igual que
`test4b.cmp`); los 8 que fallan tienen `streamFillIdx` RICO
(`byteLen≈127-128`, igual que `sball.cmp`) — independientemente del
`byteLen` de `streamLit` (canal 4), que es 128 en ambos grupos. Esto
apuntaba a un bug latente en el canal 2 para alfabetos ricos, no
(solo) en el canal 4 como se pensaba.

Un subagente de trazado en vivo (gdb + wine, mismo método que
`cmp_capture_stage1.py`) confirmó y resolvió esto con capturas reales de
memoria de `gamma.dll` contra `sball.cmp`, encontrando **2 bugs reales**
(no el parche "+1" anterior, que quedó superado):

1. **La tabla de longitudes debe indexarse por VALOR DE SÍMBOLO, no por
   la ranura de la ventana de lookup.** Captura en vivo de la tabla real
   de 512 bytes (`[obj+4]`, 256 bytes símbolo + 256 bytes longitud) para
   los 5 canales de `sball.cmp` confirma que la mitad de longitudes solo
   tiene valores no-cero en los índices que son VALORES DE SÍMBOLO real
   (ej. `table[256+0x55]=4` para el primer símbolo real de PERM0), nunca
   en las muchas ranuras que aliasan a ese símbolo. Desensamblado real de
   `FUN_00426af0` (`0x426b74-0x426b7b`) explica por qué: `mov bl,[ebx]`
   carga el símbolo en BL — el byte bajo de EBX, que es el puntero de
   tabla alineado a 256 bytes OR'd con el índice de lookup — así que esa
   misma instrucción MUTA el byte bajo de EBX al valor del símbolo, y la
   instrucción siguiente `mov cl,[ebx+0x100]` termina leyendo
   `length[symbol]`, no `length[lookupIndex]`. Invisible contra
   `test4b.cmp` (cuyos alfabetos reales son degenerados o lo bastante
   pequeños para que ranura==símbolo en los códigos realmente usados)
   pero rompía cualquier archivo real con alfabeto más rico — exactamente
   la correlación con `streamFillIdx` encontrada en el baseline del
   corpus.
2. **La transición de bits entre canales está condicionada por el bit 0
   de `flags`, no es siempre "continuar a mitad de byte":** con
   `flags&1==1` (`test4b.cmp`) cada canal continúa la ventana del canal
   anterior exactamente (el modelo `BitCursor` "primed" original, sin
   cambios). Con `flags&1==0` (`sball.cmp`) el llamador real de
   `gamma.dll` en cambio realinea a byte completo antes de cada canal
   siguiente (retrocede 1 byte, recarga fresca de 16 bits). Confirmado en
   ambos sentidos contra captura en vivo: aplicar el realineado a
   `test4b.cmp` rompe `ctrl`/`lit`; no aplicarlo a `sball.cmp` deja
   `streamA`/`fillIdx`/`ctrl` 50-97% incorrectos.

Con ambos bugs corregidos, la peculiaridad de "símbolo extra al
principio" del canal LIT (documentada como limitación honesta antes) se
convierte en una constante limpia y verificada: **1 símbolo extra en
modo continuación, 2 en modo realineado** — encontrado por búsqueda de
fuerza bruta contra ground truth capturado en vivo para ambos archivos,
no explicado mecanísticamente todavía (no se identificó la lectura extra
correspondiente en el desensamblado de `FUN_00442750`), pero exacto y
reproducible en ambos casos.

**Resultado verificado**: `sball.cmp` ahora decodifica byte-exacto en
los 5 streams de símbolos (bits 0/512, streamA 0/1940, fillIdx 0/593,
ctrl 0/593, lit 0/997 discrepancias) contra ground truth capturado en
vivo, y píxel-exacto de punta a punta contra el render real de
`cmpview.exe` — igual que `test4b.cmp`. Alcance de la verificación: 2
archivos (uno por cada valor de `flags` bit 0), con alta confianza por
estar basado en desensamblado y coincidir exacto con volcados de
memoria reales, pero pendiente de correr contra el corpus completo antes
de reclamar cierre — ver `docs/cmp-stage1-coverage.md` para el número
real actualizado.
