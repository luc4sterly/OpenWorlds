#!/usr/bin/env python3
"""Wraps in NET.worlds.core.HostPath.of(...) the first argument of the
file opens of the decompiled Java (see HostPath.java).

Usage: host_paths.py <pristine-tree> <build-tree>

It only touches the .java files that exist in the pristine tree (the
editor's source/), rewritten in their copy in the build tree: the bridge's
code already opens its files with NativeMock.localFile. It is idempotent (it
does not wrap again an argument that already starts with HostPath.of) and it
fails if it finds no call, so that a change in source/ cannot turn it off silently.
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
    """(start, end) of the first argument of the call whose '(' is at open_paren."""
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
    raise ValueError("unclosed parenthesis")


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
    print("host_paths: %d file opens wrapped in %d classes" % (total, files))
    if total == 0:
        sys.exit("host_paths: no call found (a change in source/?)")


if __name__ == "__main__":
    main()
