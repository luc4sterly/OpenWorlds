# Lenguaje de nombre de avatar (`avatar:<base>.0<programa>.rwg`)

Reconstruido del Java decompilado del cliente,
`editor/worldsplayer_source_editor-main/source/NET/worlds/scape/PosableShape.java`
(abreviado `PS`). El cliente original lo ejecuta con su propio
`PosableShape`. La traducción a Java de este documento
(`client/src/net/freeworlds/avatar/`, con `AvatarNameMain --todos`) era del
motor nuevo y se quitó con él el 2026-09-26: está en el historial de git
hasta el commit `8cd795d`.

## Origen de las tablas

`permittedList`, `faceList`, `humanList`, etc. salen de `tables/tables.dat`
(`ServerTableManager.java:99-245`): `int32` big-endian con la longitud +
payload con XOR encadenado sobre el cifrado (`dec[i]=enc[i]^enc[i-1]`) →
texto UTF-8 con bloques `private static String[] <n> = {...};`.
`assets/WorldsPlayer/tables/tables.dat`: VERSION 2, 12 tablas,
permittedList 296 entradas (148 pares).

## Cabecera (`createSubparts`, PS:1054-1090)

- `avatar:<base>.rwg` (tras el punto no hay `0`): se busca `<base>` en
  `permittedHash` (PS:1324-1335) y se sustituye por el nombre codificado;
  si no está, no hay programa: 17 limbs por defecto de `<base>.bod`.
- `avatar:<base>.0<programa>.rwg`: el programa va en la propia URL.
- Otra cosa: base `aura`, sin programa.

## Fase 1: `findStarts` (PS:636-687)

Recorre el programa entero. Cada mayúscula en posición de limb anota
`starts[letra]` (la última aparición gana). Dentro de la limb:

| token | efecto en findStarts |
|---|---|
| `G` int nombre | se salta |
| `S` c c c | se salta (3 chars) |
| `Q` | no-op |
| `D` c | se salta (1 char) |
| `A` nombre | se salta |
| `T` int nombre | **material textura** → paleta; nombre vacío hereda el último (inicialmente `<base>`) |
| `C` `_`L / `C` b64 b64 b64 | **material color** → paleta |
| `[a-z0-9]` | se salta |
| otra mayúscula | fin de limb, empieza otra |
| otro carácter | trunca el programa ahí |

Cada `T`/`C` se reescribe en la cadena como `Q<'a'+índice>` (PS:646-661):
la paleta es **global y en orden de aparición**, y las minúsculas sueltas
del nombre original son índices de esa paleta.

- Textura (`scanTexture`, PS:248-258): `n<=0` → `avatar:<x>.cmp`;
  `n>0` → `avatar:<x><n>s*.mov`. `Material.calcRes/loadTextures`
  (Material.java:265-325) interpreta `<n>s*` como subimagen `n-1` del
  fichero `<x>.mov`.
- Color (`readColor`, PS:294-315): `_`+letra → `colorTable[letra-'A']`
  (PS:37-65, 26 colores); fuera de rango (p.ej. `C__`) → `origMat`, que
  `getLimb` no aplica (se queda el color del `.bod`). Si no, RGB =
  `4*base64(c)` por componente, base64 = `-0-9a-zA-Z+` (PS:69).

## Fase 2: 17 limbs (`getLimb`, PS:355-470; tabla PS:1094-1110)

| letra | tag | padre | | letra | tag | padre |
|---|---|---|---|---|---|---|
| P | 01 | (figura) | | R | 06 | B |
| B | 02 | P | | U | 07 | R |
| N | 03 | B | | V | 08 | U |
| H | 04 | N | | I | 19 | P |
| L | 11 | B | | J | 20 | I |
| M | 12 | L | | K | 21 | J |
| O | 13 | M | | W | 15 | P |
| Z | 24 | P | | X | 16 | W |
| | | | | Y | 17 | X |

`A C D E F G Q S T` nunca se instancian: `E` es, en 147/148 nombres, el
bloque donde se declara la paleta.

Cada limb: URL `avatar:<base><tag 2 dígitos>.bod` (PS:361). La raíz usa
`<base>`; el resto hereda la base del `.bod` del padre (`Shape.getBodBase`,
Shape.java:270). El fichero real es `<base>.bod` y el tag es el número de
parte (`Shape.addRwChildren/getBodPartNum`, Shape.java:276-313).
Tokens dentro de la limb (sobre la cadena reescrita):

| token | efecto |
|---|---|
| `G` n nombre | nodo actual → `avatar:<nombre><n o tag>.bod`; nombre vacío → **se descarta la limb** (y sus hijos pierden la base) |
| `S` x y z | escala por eje: `a..z` → `1-(k)*0.025615385`, `A..Z` → inversa, otro → 1; `SZZZ` desactiva prepFigure (PS:386-393) |
| `Q` | no-op |
| `D` c | retardo += `1000*(1.0932^b64(c) - 0.9)` ms |
| `A` nombre | nombre de animación |
| `[a-z]` | material de paleta para el nodo actual; si ya había uno, se programan cambios temporizados (retardo por defecto 50 ms) → expresiones faciales (PS:410-433, 472-492) |
| dígitos | nuevo `SubclumpShape` `system:subclump<n - subclumps ya creados>` (relativo porque `extractSubclump` va sacando partes, Shape.java:286-301) |
| otra mayúscula | fin de limb |
| `T`/`C` residuales | "Illegal av" / assert (no pasa en el corpus) |

Ejemplo `willy`: `C__`×6 (origMat en todo el cuerpo) y la cabeza
`HDgT2willyT3T2T1`: cara `willy.mov` subimagen 0 en reposo con parpadeo
2-3-2-1 cada 3648 ms (+50 ms por fotograma).
`avatar:aura.0PG.rwg` (URL por defecto): `G` sin nombre descarta la raíz
y, en cascada, todas las limbs → figura vacía.

## Verificación sobre el corpus (permittedList, 148 nombres)

- 146/148 sin anomalías; 0 excepciones. Las 2 anomalías son erratas
  reales de la tabla, reproducidas tal como las trata el cliente:
  - `achoo`: espacio tras `T4achoo` → `findStarts` trunca; el avatar
    queda sin materiales en sus limbs.
  - `tas`: `Lh`/`Mh` referencian el material 7 con una paleta de 7
    (a..g) → `getMat` devuelve null y no se aplica.
- Limbs instanciadas: 2514/2516; `craig` U y V descartadas (`G` sin
  nombre en `RGUGVG`; la R posterior sobrescribe el arranque de R).
- Paleta: 2132 materiales; 387 colores `origMat`.
- Texturas referenciadas (ficheros distintos): 210; en el repo 14
  (`aggie aura axel barbra chloe death dude john monster ogre shanubia
  sonya tina willy .mov`, todas en base-avatars); faltan 196.
- `.bod` referenciados: 141; en el repo 25 (los de base-avatars);
  faltan 116.
- `cachedir/` no se puede atribuir por nombre: faltan `cache.index`,
  así que los ficheros numerados no cuentan como presentes.

## Límites

- Subimagen `n-1` de un `.mov`: `CmpFrames` decodifica todos los
  fotogramas por la tabla de frames de gamma.dll (2026-09-25); antes solo
  el 0 (`CmpStage1.decodeMovFrame0`). Probado 128×128 en willy/aura/tina.
- `faceList`/`getFace` y `humanList`/`getHuman` los usan `WearWall` y
  `AvMenu` (personalización) y la sustitución por humano; no los usa
  `createSubparts`, así que no afectan a la geometría/material del nombre.
- Que la parte N del `.bod` y su UV encajen con la subimagen resuelta solo
  se vio en `willy`, con el visor del motor nuevo (2026-09-16, ya
  retirado): la cara cae derecha y en la parte frontal de la cabeza.
  `ogre` pide la subimagen 3 de su `.mov` en 10 partes.
- ⚠️ Con textura el cliente pone `colorTable[3]` como color base; si
  RenderWare 2 tiñe la textura con él no está verificado.
