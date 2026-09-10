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
