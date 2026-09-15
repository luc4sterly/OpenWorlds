# Desarrollo en macOS

Guía para seguir el desarrollo de FreeWorlds en un Mac (Intel o Apple Silicon).
El repo ya está subido a Codeberg: `git@codeberg.org:JoseAntonio/FreeWorlds.git`.

**Sin Homebrew**: Homebrew ya no soporta Macs Intel, así que el setup no lo
usa. Todo lo externo (JDK, LWJGL) se descarga portable dentro del repo, en
directorios gitignored, sin `sudo`.

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
3. Descarga **LWJGL 3.4.3** (`lwjgl`, `lwjgl-glfw`, `lwjgl-opengl` + natives
   de la arquitectura: `natives-macos` en Intel, `natives-macos-arm64` en
   Apple Silicon) a `tools/lwjgl/`, verificando el `.sha1` de Maven Central.
   Si el directorio viene de Linux con `natives-linux`, se quedan inertes.
4. Compila `client/src` → `client/out/` y corre la sonda
   `WorldViewer --list-rooms` como verificación.

`node` no se instala: solo lo usa el harness RWX (`tools/rwx-harness`, ya
118/118) y no hace falta para jugar.

## 3. Jugar / desarrollar

```bash
tools/run-game.sh                  # ventana GroundZero (spawn real Reception)
tools/run-game.sh LizCave --inside
tools/run-game.sh Reception --screenshot /tmp/r.png   # batch sin ventana
tools/run-game.sh --build          # recompila antes de lanzar
```

Notas macOS:

- **JDK portable**: `run-game.sh` e `install-launcher.sh` ponen
  `tools/jdk/Contents/Home/bin` por delante del `PATH` si existe
  (`/usr/bin/java` en macOS es un stub que falla sin JDK instalado).
- **Sin X11/Xvfb**: en Mac, GLFW abre ventana nativa Cocoa. `run-game.sh`
  detecta `Darwin` (`uname -s`) y salta todo el bloque Xvfb/`DISPLAY`; los
  visores solo fuerzan el backend X11 de GLFW en Linux
  (`GlUtil.forceX11OnLinux`).
- **`-XstartOnFirstThread`**: obligatorio para GLFW en macOS; `run-game.sh`
  ya lo añade solo en Darwin, no hace falta ponerlo a mano.
- **`bring_to_front.py`** es X11-only y se omite en Mac (Cocoa trae su
  ventana al frente sola).
- `tools/install-launcher.sh` es Linux (`.desktop`); en Mac imprime el
  comando equivalente y sigue con build+sonda.
- `tools/run-original.sh` (cliente 2004 bajo Wine) **no funciona en Mac
  modernos** (x86 Win32 + `gamma.dll`): Wine vanilla no corre eso en Apple
  Silicon. El script lo dice y sale con código 2 salvo `--force-macos` con
  tu Wine (CrossOver/Whisky/Parallels) ya configurado. El camino principal
  en Mac es `run-game.sh`.

## 4. Qué NO se versiona (ya en `.gitignore`)

| Ruta | Por qué |
|---|---|
| `tools/jdk/` | JDK portable por arquitectura |
| `tools/lwjgl/` | natives por SO (linux vs macos) |
| `tools/node/` | binario Linux ELF |
| `tools/rwx-harness/node_modules/` | `npm install` local |
| `client/out/`, `editor/.../out/`, `analysis/` | generados |
| `logs/` | evidencia local de ejecución |
| `.DS_Store`, `._*`, etc. | ruido Finder/macOS |

## 5. Requisitos manuales (si no usas el script)

- JDK 17+ (probado con 25): tar.gz de Temurin desde
  `https://adoptium.net/temurin/releases/` (macOS, x64 o aarch64),
  descomprimido en `tools/jdk/` (debe quedar `tools/jdk/Contents/Home/bin/java`)
- LWJGL 3.4.3 (`lwjgl`, `lwjgl-glfw`, `lwjgl-opengl` + `natives-macos` en
  Intel o `natives-macos-arm64` en Apple Silicon) desde Maven Central a
  `tools/lwjgl/`
- Compilar: `tools/jdk/Contents/Home/bin/javac -cp "tools/lwjgl/*" -d client/out $(find client/src -name "*.java")`
- Lanzar: `tools/jdk/Contents/Home/bin/java -XstartOnFirstThread -cp "client/out:tools/lwjgl/*"
  net.freeworlds.render.WorldViewer assets/WorldsPlayer/GroundZero/groundzero.world Reception --play`
