#!/usr/bin/env python3
"""Compares, method by method, the invoke* targets between the original
bytecode (lib/gammacls.zip) and the one recompiled from the decompiled Java.

It catches decompilation errors that compile but call ANOTHER method (e.g.
a different overload), which is exactly what a compilation test cannot
see. It normalizes harmless differences from the modern compiler
(StringBuffer->StringBuilder, Debug.assert->assert_, synthetic accessors).

Usage:
  javap -c -p -classpath ORIG <classes> > orig.javap
  javap -c -p -classpath NEW  <classes> > new.javap
  tools/bytecode-call-diff.py orig.javap new.javap
The differences that remain have to be reviewed by hand: most are narrower
receivers, try-with-resources closes or the mock layer itself; the ones
that switch overloads are real errors.
"""
import collections
import re
import sys


def parse(fn):
    res = collections.defaultdict(lambda: collections.defaultdict(list))
    cls = meth = None
    for line in open(fn, errors="replace"):
        m = re.match(r'^(?:public |final |abstract |private |protected |static |synchronized |strictfp )*(?:class|interface) (\S+)', line)
        if m:
            cls = m.group(1)
            continue
        if line.startswith("  ") and not line.startswith("    ") and line.rstrip().endswith(";"):
            meth = line.strip()
            continue
        m = re.search(r'invoke(\w+) .*// (?:Interface)?Method (\S+)', line)
        if m and cls and meth:
            t = m.group(2).replace("StringBuffer", "StringBuilder").replace("Debug.assert:", "Debug.assert_:")
            if "access$" in t or "Native" in t:
                continue
            res[cls][meth].append(t)
    return res


def main():
    o, n = parse(sys.argv[1]), parse(sys.argv[2])
    count = 0
    for c in o:
        for mth, calls in o[c].items():
            if mth not in n[c]:
                continue
            oc, nc = collections.Counter(calls), collections.Counter(n[c][mth])
            if oc != nc:
                count += 1
                print(c, "|", mth)
                print("   original only:", dict(oc - nc))
                print("   new only     :", dict(nc - oc))
    print(count, "methods with differences", file=sys.stderr)


if __name__ == "__main__":
    main()
