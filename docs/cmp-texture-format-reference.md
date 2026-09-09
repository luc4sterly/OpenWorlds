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

## Conclusión y siguiente paso concreto

⚠️ **`.cmp` queda sin resolver por completo esta sesión**, con una base
de evidencia mucho más sólida que al empezar (antes: solo un magic byte
sin interpretar; ahora: algoritmo identificado con precisión razonable,
cadena de llamadas completa hasta el punto exacto donde falta la pieza
final). El siguiente paso concreto para una sesión futura dedicada:

1. Desensamblar el/los callee(s) de `FUN_00442750` que consumen las
   tablas Huffman ya construidas (buscar referencias a
   `param_1[0x11+i]`, los 4 punteros a tabla Huffman guardados en el
   objeto, más adelante en el flujo de `ScapePicTexture_makeTexture`/
   `FUN_00422b30`, que sí se desensambló esta sesión y muestra el
   consumo final vía `FUN_00443180`/`FUN_00442bc0` — con más profundidad
   ahí probablemente esté el LZSS real).
2. Cross-verificar cualquier hipótesis de bit-stream contra la
   especificación PÚBLICA de LHA/LZH (Okumura/Yoshizaki, de dominio
   público, múltiples reimplementaciones en C disponibles) dado el
   fuerte parecido estructural ya confirmado — no partir de cero.
3. Verificar byte a byte contra los 17 archivos reales del proyecto
   (mismo corpus que esta sesión), decodificando al menos un `.cmp`
   pequeño (`ADWORLDS.CMP`, 1637 bytes) hasta obtener dimensiones+píxeles
   plausibles, y comparrécurrentemente contra lo que se sepa del
   material RWX que lo referencia (nombre/tamaño esperado).
