# Desarrollo en macOS

Guía para seguir el desarrollo de FreeWorlds en un Mac (Apple Silicon u Intel).
El repo ya está subido a Codeberg: `git@codeberg.org:JoseAntonio/FreeWorlds.git`.

## 1. Clonar

```bash
git clone git@codeberg.org:JoseAntonio/FreeWorlds.git
cd FreeWorlds
```

> HTTPS alternativo: `https://codeberg.org/JoseAntonio/FreeWorlds.git`

## 2. Setup automático

```bash
tools/setup-macos.sh
```

Hace, en orden (idempotente):

1. Instala Homebrew si falta, más JDK 25 (Temurin), `node`, `python3`.
2. Descarga **LWJGL 3.4.3** con natives **macOS x64 + arm64** a `tools/lwjgl/`
   (ese directorio está gitignored a propósito: en Linux lleva
   `natives-linux`, en Mac `natives-macos*`; `run-game.sh` usa el wildcard
   `tools/lwjgl/*` y funciona en ambos sin cambios).
3. `npm install` en `tools/rwx-harness/` con el node del sistema
   (**no** `tools/node/`, que es un binario Linux ELF también gitignored).
4. Compila `client/src` → `client/out/` (gitignored) y corre la sonda
   `WorldViewer --list-rooms` como verificación.

## 3. Jugar / desarrollar

```bash
tools/run-game.sh                  # ventana GroundZero (spawn real Reception)
tools/run-game.sh LizCave --inside
tools/run-game.sh Reception --screenshot /tmp/r.png   # batch sin ventana
tools/run-game.sh --build          # recompila antes de lanzar
```

Notas macOS:

- **Sin X11/Xvfb**: en Mac, GLFW abre ventana nativa Cocoa. `run-game.sh`
  detecta `Darwin` (`uname -s`) y salta todo el bloque Xvfb/`DISPLAY`.
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
| `tools/lwjgl/` | natives por SO (linux vs macos) |
| `tools/node/` | binario Linux ELF |
| `tools/rwx-harness/node_modules/` | `npm install` local |
| `client/out/`, `editor/.../out/`, `analysis/` | generados |
| `logs/` | evidencia local de ejecución |
| `.DS_Store`, `._*`, etc. | ruido Finder/macOS |

## 5. Requisitos manuales (si no usas el script)

- JDK 17+ (probado con 25): `brew install --cask temurin`
- node LTS + `python3`: `brew install node python3`
- LWJGL 3.4.3 (`lwjgl`, `lwjgl-glfw`, `lwjgl-opengl` + `natives-macos` y
  `natives-macos-arm64`) desde Maven Central a `tools/lwjgl/`
- Compilar: `javac -cp "tools/lwjgl/*" -d client/out $(find client/src -name "*.java")`
- Lanzar: `java -XstartOnFirstThread -cp "client/out:tools/lwjgl/*"
  net.freeworlds.render.WorldViewer assets/WorldsPlayer/GroundZero/groundzero.world Reception --play`
