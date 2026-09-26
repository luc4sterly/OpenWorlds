#!/usr/bin/env python3
"""Fuentes del cliente de 2004 con las metricas de entonces (ver
bridge/NET/worlds/core/NativeUiFonts.java).

Uso: ui_fonts.py <arbol-pristino> <arbol-de-build>

- Cada `new Font(nombre, estilo, tamano)` (3 argumentos) de los .java del
  arbol pristino pasa a `NET.worlds.core.NativeUiFonts.font(...)`.
- GammaFrame recibe la fuente por defecto de AWT del JRE 1.4 (Dialog 12, que
  su font.properties resolvia a Arial): la heredan las etiquetas sin fuente
  propia, como la barra de estado.
Falla si no encuentra nada que cambiar, para que un cambio de source/ no lo
desactive en silencio.
"""
import os
import re
import sys

CALL = re.compile(r"\bnew\s+(?:java\.awt\.)?Font\s*\(")
WRAP = "NET.worlds.core.NativeUiFonts.font("


def args_end(src, open_paren):
    """(indice del ')' que cierra, numero de argumentos de primer nivel)."""
    depth = 0
    i = open_paren + 1
    n = 1
    in_str = None
    empty = True
    while i < len(src):
        c = src[i]
        if in_str:
            if c == "\\":
                i += 2
                continue
            if c == in_str:
                in_str = None
        elif c in "\"'":
            in_str = c
            empty = False
        elif c in "([{":
            depth += 1
            empty = False
        elif c in ")]}":
            if depth == 0:
                return i, (0 if empty else n)
            depth -= 1
        elif c == "," and depth == 0:
            n += 1
        elif not c.isspace():
            empty = False
        i += 1
    raise ValueError("parentesis sin cerrar")


def rewrite(src):
    out, pos, n = [], 0, 0
    for m in CALL.finditer(src):
        if m.start() < pos:
            continue
        end, argc = args_end(src, m.end() - 1)
        if argc != 3:
            continue
        out.append(src[pos:m.start()])
        out.append(WRAP)
        pos = m.end()
        n += 1
    out.append(src[pos:])
    return "".join(out), n


def main():
    pristine, build = sys.argv[1], sys.argv[2]
    total = files = 0
    for root, _, names in os.walk(pristine):
        for name in names:
            if not name.endswith(".java"):
                continue
            rel = os.path.relpath(os.path.join(root, name), pristine)
            target = os.path.join(build, rel)
            if not os.path.exists(target):
                continue
            with open(target, encoding="utf-8") as f:
                src = f.read()
            new, n = rewrite(src)
            if n:
                with open(target, "w", encoding="utf-8") as f:
                    f.write(new)
                total += n
                files += 1
    frame = os.path.join(build, "NET/worlds/console/GammaFrame.java")
    with open(frame, encoding="utf-8") as f:
        src = f.read()
    old = "   public GammaFrame() {\n      super(getDefaultTitle());\n   }\n"
    if old not in src:
        sys.exit("ui_fonts: el constructor de GammaFrame ha cambiado")
    src = src.replace(old, "   public GammaFrame() {\n      super(getDefaultTitle());\n"
                      "      this.setFont(NET.worlds.core.NativeUiFonts.windowFont());\n   }\n", 1)
    with open(frame, "w", encoding="utf-8") as f:
        f.write(src)
    print("ui_fonts: %d fuentes en %d clases + fuente por defecto de GammaFrame" % (total, files))
    if total == 0:
        sys.exit("ui_fonts: ninguna llamada encontrada (cambio en source/?)")


if __name__ == "__main__":
    main()
