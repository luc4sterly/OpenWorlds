# Panel de progreso - marcas pendientes

Generado por `tools/progress-panel.py` (hito H0, `docs/roadmap.md`). Cuenta apariciones de ⚠️ / `VERIFICAR` / `TODO` / `FIXME` (palabra completa para estas tres ultimas) en `client/src`, `client/test`, `editor/worldsplayer_source_editor-main/bridge/` (en `*.patch` solo lineas anadidas) y `tools/*.py`/`tools/*.sh` (solo el nivel superior de `tools/`). No mide gravedad ni prioridad, solo cuenta - la lista real esta en el codigo, este panel es un indice, no un sustituto.

**Fecha**: 2026-09-26
**Total**: 103 marcas en 158 ficheros (38 con al menos una)

## Por modulo/paquete

| Modulo | ⚠️ | VERIFICAR | TODO | FIXME | Total |
|---|---|---|---|---|---|
| `bridge/(raiz)` | 3 | 0 | 0 | 0 | 3 |
| `bridge/NET/worlds/core` | 41 | 18 | 0 | 0 | 59 |
| `client/src/avatar` | 4 | 2 | 0 | 0 | 6 |
| `client/src/bod` | 0 | 0 | 0 | 0 | 0 |
| `client/src/cmp` | 0 | 0 | 0 | 0 | 0 |
| `client/src/render` | 9 | 9 | 0 | 0 | 18 |
| `client/src/rwg` | 8 | 4 | 0 | 0 | 12 |
| `client/src/rwx` | 0 | 0 | 0 | 0 | 0 |
| `client/src/world` | 1 | 1 | 0 | 0 | 2 |
| `client/test/(raiz)` | 0 | 0 | 0 | 0 | 0 |
| `client/test/avatar` | 0 | 0 | 0 | 0 | 0 |
| `client/test/bod` | 0 | 0 | 0 | 0 | 0 |
| `client/test/cmp` | 0 | 0 | 0 | 0 | 0 |
| `client/test/corpus` | 0 | 0 | 0 | 0 | 0 |
| `client/test/rwg` | 0 | 0 | 0 | 0 | 0 |
| `client/test/world` | 0 | 0 | 0 | 0 | 0 |
| `tools` | 3 | 0 | 0 | 0 | 3 |
| **Total** | **69** | **34** | **0** | **0** | **103** |

## Por fichero (solo los que tienen al menos una marca)

| Fichero | ⚠️ | VERIFICAR | TODO | FIXME | Total |
|---|---|---|---|---|---|
| `client/src/net/freeworlds/avatar/AnimRegistry.java` | 1 | 0 | 0 | 0 | 1 |
| `client/src/net/freeworlds/avatar/AvatarRig.java` | 3 | 2 | 0 | 0 | 5 |
| `client/src/net/freeworlds/render/BodViewer.java` | 2 | 2 | 0 | 0 | 4 |
| `client/src/net/freeworlds/render/GlLighting.java` | 2 | 3 | 0 | 0 | 5 |
| `client/src/net/freeworlds/render/RwgViewer.java` | 3 | 2 | 0 | 0 | 5 |
| `client/src/net/freeworlds/render/WorldViewer.java` | 2 | 2 | 0 | 0 | 4 |
| `client/src/net/freeworlds/rwg/RwgAtom.java` | 3 | 2 | 0 | 0 | 5 |
| `client/src/net/freeworlds/rwg/RwgParser.java` | 2 | 0 | 0 | 0 | 2 |
| `client/src/net/freeworlds/rwg/RwgPolygon.java` | 1 | 1 | 0 | 0 | 2 |
| `client/src/net/freeworlds/rwg/RwgRaster.java` | 1 | 0 | 0 | 0 | 1 |
| `client/src/net/freeworlds/rwg/RwgVertex.java` | 1 | 1 | 0 | 0 | 2 |
| `client/src/net/freeworlds/world/WorldRestorer.java` | 1 | 1 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/AnimAnimator.java` | 1 | 0 | 0 | 0 | 1 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/AnimRegistry.java` | 1 | 0 | 0 | 0 | 1 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/AnimSeqCache.java` | 1 | 1 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeAnimator.java` | 1 | 1 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeCamera.java` | 6 | 2 | 0 | 0 | 8 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeMediaUrl.java` | 1 | 0 | 0 | 0 | 1 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeScene.java` | 1 | 1 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeShapes.java` | 4 | 1 | 0 | 0 | 5 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeSysCom.java` | 1 | 1 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeSysInfo.java` | 1 | 1 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeSysProcess.java` | 1 | 1 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeSysRegistry.java` | 2 | 2 | 0 | 0 | 4 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeSysVehicle.java` | 1 | 1 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeTextures.java` | 3 | 3 | 0 | 0 | 6 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeUiConsole.java` | 2 | 1 | 0 | 0 | 3 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeUiCursor.java` | 4 | 0 | 0 | 0 | 4 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeUiFileDialog.java` | 2 | 0 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeUiImage.java` | 2 | 1 | 0 | 0 | 3 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeUiOverlay.java` | 1 | 0 | 0 | 0 | 1 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeUiStartup.java` | 2 | 0 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeWindows.java` | 1 | 0 | 0 | 0 | 1 |
| `editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/RwxReader.java` | 2 | 1 | 0 | 0 | 3 |
| `editor/worldsplayer_source_editor-main/bridge/README.md` | 2 | 0 | 0 | 0 | 2 |
| `editor/worldsplayer_source_editor-main/bridge/test/TexStringCheck.java` | 1 | 0 | 0 | 0 | 1 |
| `tools/jni_mock.py` | 1 | 0 | 0 | 0 | 1 |
| `tools/native_mapper.py` | 2 | 0 | 0 | 0 | 2 |

