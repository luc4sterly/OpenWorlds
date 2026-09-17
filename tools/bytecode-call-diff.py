#!/usr/bin/env python3
"""Compara, metodo a metodo, los destinos de invoke* entre el bytecode
original (lib/gammacls.zip) y el recompilado desde el Java decompilado.

Detecta errores de decompilacion que compilan pero llaman a OTRO metodo
(p. ej. una sobrecarga distinta), que es justo lo que un test de
compilacion no ve. Normaliza diferencias inocuas del compilador moderno
(StringBuffer->StringBuilder, Debug.assert->assert_, accesores sinteticos).

Uso:
  javap -c -p -classpath ORIG  <clases> > orig.javap
  javap -c -p -classpath NUEVO <clases> > new.javap
  tools/bytecode-call-diff.py orig.javap new.javap
Las diferencias que quedan hay que revisarlas a mano: la mayoria son
receptores mas estrechos, cierres de try-with-resources o la propia capa
de mocks; las que cambian de sobrecarga son errores reales.
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
                print("   solo original:", dict(oc - nc))
                print("   solo nuevo   :", dict(nc - oc))
    print(count, "metodos con diferencias", file=sys.stderr)


if __name__ == "__main__":
    main()
