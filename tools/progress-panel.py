#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""progress-panel.py - progress panel of milestone H0 (docs/roadmap.md).

Counts pending-work markers (warning ⚠️, VERIFY, TODO, FIXME) per file in
the project tree and generates docs/progress.md: one table per
module/package and one table per file, with the total and the date.

Exact scope (explicitly requested in the H0 runner task):
  - formats/src                                       (recursive)
  - formats/test                                      (recursive)
  - editor/worldsplayer_source_editor-main/bridge/      (recursive; in the
    *.patch files ONLY added lines are counted: those starting with a
    literal '+' that is not the '+++' file header)
  - tools/*.py and tools/*.sh                           (only the top level
    of tools/, without walking subdirectories - so third-party tools such
    as those in tools/gdk-sdk are not counted)

"VERIFY"/"TODO"/"FIXME" are matched as whole words (\\b boundary) so that
ordinary words containing them as a substring are not counted - a real bug
found while writing this script, back when the project was written in
Spanish: a naive grep for "TODO" also counted every "TODOS"/"todos" ("all")
in the comments. The marker was spelled "VERIFICAR" in those days; that
legacy spelling is still counted under VERIFY, so an untranslated marker
does not silently drop out of the panel. "⚠️" is counted as an occurrence of the character
U+26A0 (WARNING SIGN), with or without the variation selector U+FE0F that
usually comes with it.

No external dependencies (stdlib only). Deterministic output: everything is
sorted, both when walking the files and when dumping each table.

Usage:
  tools/progress-panel.py              writes docs/progress.md
  tools/progress-panel.py --stdout     also dumps the markdown to stdout
  tools/progress-panel.py --check      writes nothing; exits with 1 if
                                        docs/progress.md on disk differs
                                        from what would be generated now
                                        (for verify-corpus.sh / CI)
"""
import argparse
import datetime
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SELF_PATH = Path(__file__).resolve()

WARN = "⚠️"  # ⚠️ display (with the variation selector)
WARN_RE = re.compile("⚠️?")  # counts the warning with or without the selector
WORD_RES = [
    # VERIFICAR: the marker's legacy Spanish spelling (see the docstring)
    ("VERIFY", re.compile(r"\b(?:VERIFY|VERIFICAR)\b")),
    ("TODO", re.compile(r"\bTODO\b")),
    ("FIXME", re.compile(r"\bFIXME\b")),
]
MARK_NAMES = ["⚠️", "VERIFY", "TODO", "FIXME"]


def count_text(text):
    """Counts the occurrences of each marker in a block of text (several lines)."""
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
    """Counts markers in a regular file (the whole content)."""
    return count_text(read_text(path))


def count_patch(path):
    """Counts markers in a .patch, ONLY in added lines (+, not +++)."""
    added_lines = []
    for line in read_text(path).splitlines():
        if line.startswith("+++"):
            continue
        if line.startswith("+"):
            added_lines.append(line[1:])
    return count_text("\n".join(added_lines))


# ---------------------------------------------------------------------
# File discovery (deterministic: everything is sorted by path)
# ---------------------------------------------------------------------

def collect_targets():
    """Returns a sorted list of (relative_path_str, module, is_patch)."""
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
        # formats/src/net/openworlds/<pkg>/File.java -> "formats/src/<pkg>"
        parts = rel.parts
        if len(parts) >= 5 and parts[:4] == ("formats", "src", "net", "openworlds"):
            return "formats/src/" + parts[4]
        return "formats/src/(root)"

    def formats_test_module(rel):
        parts = rel.parts
        if len(parts) >= 5 and parts[:4] == ("formats", "test", "net", "openworlds"):
            return "formats/test/" + parts[4]
        return "formats/test/(root)"

    def bridge_module(rel):
        # editor/worldsplayer_source_editor-main/bridge/NET/worlds/<pkg>/X.java
        #   -> "bridge/NET/worlds/<pkg>"
        # editor/worldsplayer_source_editor-main/bridge/*.patch or README.md
        #   -> "bridge/(root)"
        parts = rel.parts
        # .../bridge/NET/worlds/<pkg>/...
        try:
            i = parts.index("bridge")
        except ValueError:
            i = -1
        if i >= 0 and len(parts) >= i + 5 and parts[i + 1:i + 3] == ("NET", "worlds"):
            return "bridge/NET/worlds/" + parts[i + 3]
        return "bridge/(root)"

    add_tree("formats/src", formats_src_module)
    add_tree("formats/test", formats_test_module)
    add_tree("editor/worldsplayer_source_editor-main/bridge", bridge_module)

    tools_dir = ROOT / "tools"
    if tools_dir.is_dir():
        for p in sorted(tools_dir.iterdir()):
            if not (p.is_file() and p.suffix in (".py", ".sh")):
                continue
            if p.resolve() == SELF_PATH:
                # Deliberate exception: this very file defines and explains
                # in its docstring/code the 4 markers it looks for (the
                # literals "TODO", "FIXME", "VERIFY", the ⚠️ emoji and
                # their regexes), so counting it would give a false "44
                # pending markers" that is not real unfinished work, only
                # the vocabulary the counter itself needs to mention.
                continue
            rel = p.relative_to(ROOT)
            targets.append((str(rel), "tools", False))

    targets.sort(key=lambda t: t[0])
    return targets


# ---------------------------------------------------------------------
# Markdown generation
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
    lines.append("# Progress panel - pending markers")
    lines.append("")
    lines.append(
        "Generated by `tools/progress-panel.py` (milestone H0, `docs/roadmap.md`). "
        "Counts occurrences of ⚠️ / `VERIFY` / `TODO` / `FIXME` (whole word "
        "for the last three) in `formats/src`, `formats/test`, "
        "`editor/worldsplayer_source_editor-main/bridge/` (in `*.patch` only "
        "added lines) and `tools/*.py`/`tools/*.sh` (only the top level of "
        "`tools/`). It does not measure severity or priority, it only counts - "
        "the real list is in the code, this panel is an index, not a substitute."
    )
    lines.append("")
    lines.append(f"**Date**: {today}")
    lines.append(f"**Total**: {total_of(grand)} markers in {len(per_file)} files "
                  f"({sum(1 for _, _, c in per_file if total_of(c) > 0)} with at least one)")
    lines.append("")

    lines.append("## By module/package")
    lines.append("")
    lines.append("| Module | ⚠️ | VERIFY | TODO | FIXME | Total |")
    lines.append("|---|---|---|---|---|---|")
    for module in sorted(per_module.keys()):
        c = per_module[module]
        lines.append(
            f"| `{module}` | {c['⚠️']} | {c['VERIFY']} | {c['TODO']} | {c['FIXME']} | {total_of(c)} |"
        )
    lines.append(
        f"| **Total** | **{grand['⚠️']}** | **{grand['VERIFY']}** | "
        f"**{grand['TODO']}** | **{grand['FIXME']}** | **{total_of(grand)}** |"
    )
    lines.append("")

    lines.append("## By file (only those with at least one marker)")
    lines.append("")
    lines.append("| File | ⚠️ | VERIFY | TODO | FIXME | Total |")
    lines.append("|---|---|---|---|---|---|")
    for rel, module, c in per_file:
        t = total_of(c)
        if t == 0:
            continue
        lines.append(f"| `{rel}` | {c['⚠️']} | {c['VERIFY']} | {c['TODO']} | {c['FIXME']} | {t} |")
    lines.append("")

    return "\n".join(lines) + "\n"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--stdout", action="store_true", help="also dump the markdown to stdout")
    ap.add_argument("--check", action="store_true",
                     help="don't write docs/progress.md; exit with 1 if it differs from what is on disk")
    args = ap.parse_args()

    report = build_report()
    out_path = ROOT / "docs" / "progress.md"

    if args.check:
        current = out_path.read_text(encoding="utf-8") if out_path.is_file() else None
        # The date line changes every day without being a real regression:
        # compare ignoring that one line.
        def strip_date(s):
            return "\n".join(l for l in s.splitlines() if not l.startswith("**Date**:"))
        if current is None or strip_date(current) != strip_date(report):
            print("docs/progress.md is out of date with the current tree "
                  "(or missing) - run tools/progress-panel.py", file=sys.stderr)
            sys.exit(1)
        print("docs/progress.md is up to date")
        sys.exit(0)

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(report, encoding="utf-8")
    print(f"wrote {out_path}")
    if args.stdout:
        print()
        print(report)


if __name__ == "__main__":
    main()
