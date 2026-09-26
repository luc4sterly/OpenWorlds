#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""progress-panel.py - panel de progreso del hito H0 (docs/roadmap.md).

Cuenta marcas de trabajo pendiente (warning ⚠️, VERIFICAR, TODO, FIXME) por
fichero en el arbol del proyecto y genera docs/progress.md: una tabla por
modulo/paquete y una tabla por fichero, con el total y la fecha.

Ambito exacto (pedido explicitamente en la tarea del runner H0):
  - formats/src                                       (recursivo)
  - formats/test                                      (recursivo)
  - editor/worldsplayer_source_editor-main/bridge/      (recursivo; en los
    *.patch SOLO se cuentan lineas anadidas: las que empiezan por un '+'
    literal que no sea la cabecera de fichero '+++')
  - tools/*.py y tools/*.sh                             (solo el nivel
    superior de tools/, sin recorrer subdirectorios - asi no se cuentan
    herramientas de terceros como las de tools/gdk-sdk)

"VERIFICAR"/"TODO"/"FIXME" se buscan como palabra completa (limite \\b) para
no confundir con palabras normales del espanol que las contienen como
subcadena (p.ej. "TODOS", "todo el mundo") - un error real que se detecto
al escribir este script: un grep ingenuo sobre "TODO" contaba comentarios
que simplemente dicen "todos los ficheros". "⚠️" se cuenta como aparicion
del caracter U+26A0 (WARNING SIGN), con o sin el selector de variacion
U+FE0F que normalmente lo acompana.

Sin dependencias externas (solo stdlib). Salida determinista: incluye tanto
en el recorrido de ficheros como en el volcado de cada tabla.

Uso:
  tools/progress-panel.py              escribe docs/progress.md
  tools/progress-panel.py --stdout     tambien vuelca el markdown a stdout
  tools/progress-panel.py --check      no escribe nada; sale con 1 si
                                        docs/progress.md en disco difiere de
                                        lo que se generaria ahora (para
                                        verify-corpus.sh / CI)
"""
import argparse
import datetime
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SELF_PATH = Path(__file__).resolve()

WARN = "⚠️"  # ⚠️ display (con selector de variacion)
WARN_RE = re.compile("⚠️?")  # cuenta el aviso con o sin selector
WORD_RES = [
    ("VERIFICAR", re.compile(r"\bVERIFICAR\b")),
    ("TODO", re.compile(r"\bTODO\b")),
    ("FIXME", re.compile(r"\bFIXME\b")),
]
MARK_NAMES = ["⚠️", "VERIFICAR", "TODO", "FIXME"]


def count_text(text):
    """Cuenta ocurrencias de cada marca en un bloque de texto (varias lineas)."""
    counts = {"⚠️": len(WARN_RE.findall(text))}
    for name, rx in WORD_RES:
        counts[name] = len(rx.findall(text))
    return counts


def zero_counts():
    return {name: 0 for name in MARK_NAMES}


def add_counts(a, b):
    for name in MARK_NAMES:
        a[name] = a.get(name, 0) + b.get(name, 0)
    return a


def total_of(counts):
    return sum(counts.get(name, 0) for name in MARK_NAMES)


def read_text(path):
    try:
        return path.read_text(encoding="utf-8", errors="replace")
    except Exception:
        return ""


def count_file(path):
    """Cuenta marcas en un fichero normal (todo el contenido)."""
    return count_text(read_text(path))


def count_patch(path):
    """Cuenta marcas en un .patch, SOLO en lineas anadidas (+, no +++)."""
    added_lines = []
    for line in read_text(path).splitlines():
        if line.startswith("+++"):
            continue
        if line.startswith("+"):
            added_lines.append(line[1:])
    return count_text("\n".join(added_lines))


# ---------------------------------------------------------------------
# Descubrimiento de ficheros (determinista: todo se ordena por ruta)
# ---------------------------------------------------------------------

def collect_targets():
    """Devuelve lista ordenada de (path_relativo_str, modulo, es_patch)."""
    targets = []

    def add_tree(rel_root, module_of):
        base = ROOT / rel_root
        if not base.is_dir():
            return
        for p in sorted(base.rglob("*")):
            if not p.is_file():
                continue
            rel = p.relative_to(ROOT)
            is_patch = p.suffix == ".patch"
            targets.append((str(rel), module_of(rel), is_patch))

    def formats_src_module(rel):
        # formats/src/net/freeworlds/<pkg>/Archivo.java -> "formats/src/<pkg>"
        parts = rel.parts
        if len(parts) >= 5 and parts[:4] == ("formats", "src", "net", "freeworlds"):
            return "formats/src/" + parts[4]
        return "formats/src/(raiz)"

    def formats_test_module(rel):
        parts = rel.parts
        if len(parts) >= 5 and parts[:4] == ("formats", "test", "net", "freeworlds"):
            return "formats/test/" + parts[4]
        return "formats/test/(raiz)"

    def bridge_module(rel):
        # editor/worldsplayer_source_editor-main/bridge/NET/worlds/<pkg>/X.java
        #   -> "bridge/NET/worlds/<pkg>"
        # editor/worldsplayer_source_editor-main/bridge/*.patch o README.md
        #   -> "bridge/(raiz)"
        parts = rel.parts
        # .../bridge/NET/worlds/<pkg>/...
        try:
            i = parts.index("bridge")
        except ValueError:
            i = -1
        if i >= 0 and len(parts) >= i + 5 and parts[i + 1:i + 3] == ("NET", "worlds"):
            return "bridge/NET/worlds/" + parts[i + 3]
        return "bridge/(raiz)"

    add_tree("formats/src", formats_src_module)
    add_tree("formats/test", formats_test_module)
    add_tree("editor/worldsplayer_source_editor-main/bridge", bridge_module)

    tools_dir = ROOT / "tools"
    if tools_dir.is_dir():
        for p in sorted(tools_dir.iterdir()):
            if not (p.is_file() and p.suffix in (".py", ".sh")):
                continue
            if p.resolve() == SELF_PATH:
                # Excepcion deliberada: este propio fichero define y explica
                # en su docstring/codigo las 4 marcas que busca (los
                # literales "TODO", "FIXME", "VERIFICAR", el emoji ⚠️ y sus
                # regex), asi que contarlo daria un falso "44 marcas
                # pendientes" que no es trabajo real sin hacer, solo el
                # vocabulario que el propio contador necesita mencionar.
                continue
            rel = p.relative_to(ROOT)
            targets.append((str(rel), "tools", False))

    targets.sort(key=lambda t: t[0])
    return targets


# ---------------------------------------------------------------------
# Generacion del markdown
# ---------------------------------------------------------------------

def build_report():
    targets = collect_targets()

    per_file = []  # (rel, module, counts)
    per_module = {}  # module -> counts
    grand = zero_counts()

    for rel, module, is_patch in targets:
        path = ROOT / rel
        counts = count_patch(path) if is_patch else count_file(path)
        per_file.append((rel, module, counts))
        per_module[module] = add_counts(per_module.get(module, zero_counts()), counts)
        add_counts(grand, counts)

    lines = []
    today = datetime.date.today().isoformat()
    lines.append("# Panel de progreso - marcas pendientes")
    lines.append("")
    lines.append(
        "Generado por `tools/progress-panel.py` (hito H0, `docs/roadmap.md`). "
        "Cuenta apariciones de ⚠️ / `VERIFICAR` / `TODO` / `FIXME` (palabra "
        "completa para estas tres ultimas) en `formats/src`, `formats/test`, "
        "`editor/worldsplayer_source_editor-main/bridge/` (en `*.patch` solo "
        "lineas anadidas) y `tools/*.py`/`tools/*.sh` (solo el nivel superior "
        "de `tools/`). No mide gravedad ni prioridad, solo cuenta - la lista "
        "real esta en el codigo, este panel es un indice, no un sustituto."
    )
    lines.append("")
    lines.append(f"**Fecha**: {today}")
    lines.append(f"**Total**: {total_of(grand)} marcas en {len(per_file)} ficheros "
                  f"({sum(1 for _, _, c in per_file if total_of(c) > 0)} con al menos una)")
    lines.append("")

    lines.append("## Por modulo/paquete")
    lines.append("")
    lines.append("| Modulo | ⚠️ | VERIFICAR | TODO | FIXME | Total |")
    lines.append("|---|---|---|---|---|---|")
    for module in sorted(per_module.keys()):
        c = per_module[module]
        lines.append(
            f"| `{module}` | {c['⚠️']} | {c['VERIFICAR']} | {c['TODO']} | {c['FIXME']} | {total_of(c)} |"
        )
    lines.append(
        f"| **Total** | **{grand['⚠️']}** | **{grand['VERIFICAR']}** | "
        f"**{grand['TODO']}** | **{grand['FIXME']}** | **{total_of(grand)}** |"
    )
    lines.append("")

    lines.append("## Por fichero (solo los que tienen al menos una marca)")
    lines.append("")
    lines.append("| Fichero | ⚠️ | VERIFICAR | TODO | FIXME | Total |")
    lines.append("|---|---|---|---|---|---|")
    for rel, module, c in per_file:
        t = total_of(c)
        if t == 0:
            continue
        lines.append(f"| `{rel}` | {c['⚠️']} | {c['VERIFICAR']} | {c['TODO']} | {c['FIXME']} | {t} |")
    lines.append("")

    return "\n".join(lines) + "\n"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--stdout", action="store_true", help="tambien volcar el markdown a stdout")
    ap.add_argument("--check", action="store_true",
                     help="no escribir docs/progress.md; salir con 1 si difiere de lo ya escrito")
    args = ap.parse_args()

    report = build_report()
    out_path = ROOT / "docs" / "progress.md"

    if args.check:
        current = out_path.read_text(encoding="utf-8") if out_path.is_file() else None
        # La linea de fecha cambia cada dia sin ser una regresion real:
        # comparar ignorando esa unica linea.
        def strip_date(s):
            return "\n".join(l for l in s.splitlines() if not l.startswith("**Fecha**:"))
        if current is None or strip_date(current) != strip_date(report):
            print("docs/progress.md esta desactualizado respecto al arbol actual "
                  "(o no existe) - ejecuta tools/progress-panel.py", file=sys.stderr)
            sys.exit(1)
        print("docs/progress.md al dia")
        sys.exit(0)

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(report, encoding="utf-8")
    print(f"escrito {out_path}")
    if args.stdout:
        print()
        print(report)


if __name__ == "__main__":
    main()
