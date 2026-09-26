#!/usr/bin/env python3
"""Envuelve con NET.worlds.core.HostPath.of(...) el primer argumento de las
aperturas de fichero del Java decompilado (ver HostPath.java).

Uso: host_paths.py <arbol-pristino> <arbol-de-build>

Solo toca los .java que existen en el arbol pristino (source/ del editor),
reescritos en su copia del arbol de build: el codigo del puente ya abre sus
ficheros con NativeMock.localFile. Es idempotente (no vuelve a envolver un
argumento que ya empieza por HostPath.of) y falla si no encuentra ninguna
llamada, para que un cambio de source/ no lo desactive en silencio.
"""
import os
import re
import sys

WRAP = "NET.worlds.core.HostPath.of("
CALLS = re.compile(
    r"\bnew\s+(?:java\.io\.)?(File|FileInputStream|FileOutputStream|FileReader|FileWriter|RandomAccessFile)\s*\("
    r"|\bnew\s+(?:java\.util\.zip\.)?ZipFile\s*\("
    r"|\bToolkit\.getDefaultToolkit\(\)\.getImage\s*\("
)


def first_arg_span(src, open_paren):
    """(inicio, fin) del primer argumento de la llamada cuyo '(' esta en open_paren."""
    depth = 0
    i = open_paren + 1
    start = i
    in_str = None
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
        elif c in "([{":
            depth += 1
        elif c in ")]}":
            if depth == 0:
                return start, i
            depth -= 1
        elif c == "," and depth == 0:
            return start, i
        i += 1
    raise ValueError("parentesis sin cerrar")


def rewrite(src):
    out = []
    pos = 0
    n = 0
    for m in CALLS.finditer(src):
        if m.start() < pos:
            continue
        open_paren = m.end() - 1
        a, b = first_arg_span(src, open_paren)
        arg = src[a:b]
        if not arg.strip() or arg.strip().startswith(WRAP):
            continue
        out.append(src[pos:a])
        out.append(WRAP + arg.strip() + ")")
        pos = b
        n += 1
    out.append(src[pos:])
    return "".join(out), n


def main():
    pristine, build = sys.argv[1], sys.argv[2]
    total = 0
    files = 0
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
    print("host_paths: %d aperturas de fichero envueltas en %d clases" % (total, files))
    if total == 0:
        sys.exit("host_paths: ninguna llamada encontrada (cambio en source/?)")


if __name__ == "__main__":
    main()
