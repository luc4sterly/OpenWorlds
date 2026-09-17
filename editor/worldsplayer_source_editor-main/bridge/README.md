# Puente portable gamma.dll / RenderWare 2.1

Permite que el cliente **original** decompilado (`NET.worlds.console.Gamma`,
Java de `lib/gammacls.zip`) arranque en macOS/Linux sin `gamma.dll` ni
`RWL21.DLL`. No es un motor nuevo: cada cuerpo nativo es la traducción de
lo que hace el C decompilado de `gamma.dll`
(`decompiled-native/gamma_dll/`) y, por debajo, de lo que hacen las
funciones de RenderWare 2.1 según el desensamblado de `RWL21.DLL`. Las
direcciones de evidencia están en los comentarios de cada método.

## Uso

```bash
editor/worldsplayer_source_editor-main/build_gamma.sh
```

```bash
editor/worldsplayer_source_editor-main/run_gamma.sh
```

`build_gamma.sh` copia `source/` (pristino) a `editor/.build-gamma/`
(ignorado por git), aplica `apply_mock.sh` (stubs + este puente) y compila
con `javac --release 8` (747 clases). `run_gamma.sh [DIR]` copia
`assets/WorldsPlayer` a un directorio de trabajo (por defecto
`$TMPDIR/freeworlds-gamma`) y arranca el `main` real desde ahí.

## Estado verificado (2026-09-17)

Arranca y se queda en el bucle principal real (`Main.mainLoop`): carga
caché, tablas, avatar y sala; abre la `GammaFrame` AWT; construye la escena
RenderWare de la sala (clumps, superficies, subpolígonos, materiales, luces)
y renderiza frames sin excepciones. Probado 40–60 s seguidos (~2 M de
frames), `jstack` confirma el hilo en `Main.mainLoop`.

**Todavía no se ve nada en pantalla**: `Camera.renderScene` y las texturas
(`Texture`, `FileTexture`, `ScapePicTexture`, `ScapePicMovie`) siguen siendo
stubs de log. Tampoco hay sonido, vídeo ni ActiveX. El bucle no está
limitado (el original lo frenaba el render de RenderWare).

## Qué contiene

| Fichero | Traduce |
|---|---|
| `NET/worlds/core/NativeRw.java` | Matrices RW 2.1: multiplicación (0x1005118c), modos 1/2/3 (0x1001c500), `RwRotateMatrix` (0x1001de70→0x1001cb20), `RwScaleMatrix`, `RwTranslateMatrix`, `RwInvertMatrix` afín por adjunta (0x1001dbc0), `RwOrthoNormalizeMatrix` (0x1001c150), `RwQueryRotateMatrix` (0x1001e060), `RwTransformPoint/Vector` |
| `NET/worlds/core/NativeScene.java` | Clumps, escenas, luces y materiales de RWL21 (crear, vértices base 1, polígonos, jerarquía, LTM, bbox mundo/local, tags, estado ON=2/OFF=1, escena por defecto) y los wrappers de gamma.dll que añaden lógica (`FUN_00417ac0`, `FUN_00418820/860` y sus callbacks, `FUN_00417950/a10`, `FUN_00419000`, `Surface.addSubPolys` 0x004206d0) |
| `NET/worlds/core/NativeWindows.java` | `Window.findWindow`, ventanas hijas, estado y tamaño, sobre las ventanas AWT del propio proceso |
| `NET/worlds/core/NativeAssert.java` | Aserción nativa `FUN_00402800`: mismo mensaje y `exit(41)` (sin el MessageBox modal) |
| `natives.patch` | Cuerpos de los stubs de `Transform`, `Point3Temp`, `WObject`, `Surface`, `Room`, `RoomEnvironment`, `Material`, `Window` y `ActiveX` (camino de error real con el mensaje literal de gamma.dll), `NativeMock` con log acotado, y la corrección de `Room` de abajo |

## Error de decompilación encontrado

`Room` llamaba a `super.add(this.environment)`, que Java resuelve como
`WObject.add(WObject)` y mete el entorno dos veces en la escena (aserción
en `RoomEnvironment.addLight`). El bytecode original llama a
`WObject.add(SuperRoot)`. Para comprobar que no hay más casos así se
comparan los destinos de todas las llamadas de las 736 clases originales
con los recompilados (`tools/bytecode-call-diff.py`): quedan 55 métodos con
diferencias, todas inocuas (receptores más estrechos, `close()` de
try-with-resources, la propia capa de mocks), salvo esta.

## ⚠️ Pendiente de verificar

- `RwDestroyScene`: se asume que destruye sus clumps y luces (no extraído).
- `FUN_00419000`: el material recibe texture modes 2, o 6 si
  `DAT_00489578 != 0`; no se ha comprobado quién pone ese flag (se usa 2).
- `RwSetClumpVertexUV` rechaza UV fuera del rango del driver; el máximo no
  está extraído y aquí no se limita.
- `RwGetClumpVertex` con índices -7..0 (esquinas internas de la bbox) no se
  replica.
