# Desarrollo en macOS

Guía para seguir el desarrollo de FreeWorlds en un Mac (Intel o Apple Silicon).
El repo ya está subido a Codeberg: `git@codeberg.org:JoseAntonio/FreeWorlds.git`.

**Sin Homebrew**: Homebrew ya no soporta Macs Intel, así que el setup no lo
usa. El JDK se descarga portable dentro del repo, en un directorio
gitignored, sin `sudo`.

## 1. Clonar

```bash
git clone git@codeberg.org:JoseAntonio/FreeWorlds.git
cd FreeWorlds
```

> HTTPS alternativo: `https://codeberg.org/JoseAntonio/FreeWorlds.git`

## 2. Setup automático

Requisito previo: Command Line Tools (traen `git` y `python3`). Si faltan:
`xcode-select --install`.

```bash
tools/setup-macos.sh
```

Hace, en orden (idempotente):

1. Comprueba `python3` (Command Line Tools).
2. Descarga **JDK 25 Temurin** (tar.gz de `api.adoptium.net`, arquitectura
   del Mac) a `tools/jdk/`, verificando el SHA-256 que publica Adoptium.
3. Compila los lectores de `formats/src` → `formats/out/` y el cliente
   original con el puente (`build_gamma.sh` → `editor/.build-gamma/out`).

## 3. Jugar / desarrollar

Para jugar, el paquete con el lanzador:

```bash
tools/build-dist.sh                              # build/dist/FreeWorlds (+ .zip portable)
open build/dist/FreeWorlds/FreeWorlds.command    # o doble clic en Finder
tools/build-dist.sh --app-image                  # además FreeWorlds.app con su propio Java
```

O el de cada push en GitHub (Artifacts de la CI; `FreeWorlds-<ver>-macOS-X64`
en un Mac Intel).

Para diagnóstico, el cliente original directo (admite `JAVA_OPTS`, ver
`editor/worldsplayer_source_editor-main/bridge/README.md`):

```bash
editor/worldsplayer_source_editor-main/run_gamma.sh home:GroundZero/groundzero.world
```

Verificación (todo con el JDK de `tools/jdk`):

```bash
tools/run-checks.sh      # los *Check de formats/test y bridge/test
tools/verify-corpus.sh   # .seq 231, .bod 51, .cmp 159, .mov 52 y luego run-checks

# .seq: parsea todo el corpus y resume version/joints/extras
java -cp formats/out net.freeworlds.bod.SeqExtractMain -q \
  assets/gammatutorial-samples/base-avatars/*.seq assets/WorldsPlayer/cachedir/*.seq

# .bod / .rwg: resumen estructural
java -cp formats/out net.freeworlds.bod.BodExtractMain  assets/gammatutorial-samples/base-avatars/*.bod
java -cp formats/out net.freeworlds.rwg.RwgExtractMain  assets/gammatutorial-samples/cube.rwg
```

Notas macOS:

- **JDK portable**: `build_gamma.sh`, `run_gamma.sh` y los scripts de
  `tools/` ponen `tools/jdk/Contents/Home/bin` por delante si existe
  (`/usr/bin/java` en macOS es un stub que falla sin JDK instalado).
- **`bring_to_front.py`** es X11-only y no hace falta en Mac.
- `tools/run-original.sh` (cliente 2004 bajo Wine) **no funciona en Mac
  modernos** (x86 Win32 + `gamma.dll`): Wine vanilla no corre eso en Apple
  Silicon. El script lo dice y sale con código 2 salvo `--force-macos` con
  tu Wine (CrossOver/Whisky/Parallels) ya configurado. En Mac se juega con
  el lanzador (o `run_gamma.sh`): el mismo cliente con el puente portable,
  sin Wine.

## 4. Qué NO se versiona (ya en `.gitignore`)

| Ruta | Por qué |
|---|---|
| `tools/jdk/` | JDK portable por arquitectura |
| `formats/out/`, `editor/.build-gamma/`, `build/`, `analysis/` | generados |
| `.DS_Store`, `._*`, etc. | ruido Finder/macOS |

Siguen ignorados, por si quedan de antes del 2026-09-26, `tools/lwjgl/`,
`tools/node*/`, `tools/rwx-harness/`, `client/` y `logs/`: son restos del
motor nuevo, ya quitado, y se pueden borrar a mano.

## 5. Requisitos manuales (si no usas el script)

- JDK 17+ (probado con 25): tar.gz de Temurin desde
  `https://adoptium.net/temurin/releases/` (macOS, x64 o aarch64),
  descomprimido en `tools/jdk/` (debe quedar `tools/jdk/Contents/Home/bin/java`)
- Compilar: `bash editor/worldsplayer_source_editor-main/build_gamma.sh`
  (usa `python3` y `patch`, que ya trae macOS)
- Jugar: `editor/worldsplayer_source_editor-main/run_gamma.sh home:GroundZero/groundzero.world`,
  o el paquete de `tools/build-dist.sh`
