#!/usr/bin/env python3
import re
import sys
from pathlib import Path

SRC = Path(sys.argv[1])
EXPORTS_FILE = Path(sys.argv[2])

exports = [l.strip() for l in EXPORTS_FILE.read_text().splitlines() if l.strip()]

native_re = re.compile(
    r'^\s*(?:(?:public|private|protected|final|synchronized)\s+)*'
    r'(?:static\s+)?native\s+'
    r'([\w\[\]<>,\s]+?)\s+'
    r'(\w+)\s*\(([^)]*)\)',
    re.MULTILINE,
)
package_re = re.compile(r'^package\s+([\w.]+)\s*;', re.MULTILINE)

rows = []
for java_file in sorted(SRC.rglob("*.java")):
    text = java_file.read_text(errors="replace")
    pkg_m = package_re.search(text)
    pkg = pkg_m.group(1) if pkg_m else ""
    cls = java_file.stem
    for m in native_re.finditer(text):
        ret_type, method, params = m.groups()
        # JNI name mangling: '_' in identifiers becomes '_1', '.' between
        # package/class segments becomes '_'.
        def jni_escape(s):
            return s.replace("_", "_1")
        prefix = "Java_" + "_".join(jni_escape(p) for p in pkg.split(".")) \
            + "_" + jni_escape(cls) + "_" + jni_escape(method)
        matches = [e for e in exports if prefix in e]
        rows.append({
            "class": f"{pkg}.{cls}",
            "method": method,
            "ret": ret_type.strip(),
            "params": params.strip(),
            "prefix": prefix,
            "matches": matches,
        })

matched = [r for r in rows if r["matches"]]
unmatched = [r for r in rows if not r["matches"]]

print(f"Total native declarations found: {len(rows)}")
print(f"Matched against gamma.dll exports: {len(matched)}")
print(f"Unmatched (implemented elsewhere / not exported / mismatched mangling): {len(unmatched)}")
print()

out = []
out.append(f"# Mapeador de métodos `native` — WorldsPlayer client vs. `gamma.dll`\n")
out.append(f"Generado automáticamente cruzando los métodos `native` del código Java\n"
           f"decompilado (`editor/worldsplayer_source_editor-main/source/`) contra la\n"
           f"tabla de exports de `move/bin/gamma.dll` (372 símbolos JNI).\n\n")
out.append(f"- Total declaraciones `native` encontradas: **{len(rows)}**\n")
out.append(f"- Con export JNI correspondiente en `gamma.dll`: **{len(matched)}**\n")
out.append(f"- Sin coincidencia (revisar manualmente — nombre mangled distinto, "
           f"clase interna, o implementado en otra DLL): **{len(unmatched)}**\n\n")
out.append("## ✅ Coinciden con un export de gamma.dll\n\n")
out.append("| Clase | Método | Firma | Export(s) en gamma.dll |\n")
out.append("|---|---|---|---|\n")
for r in matched:
    exp = "<br>".join(f"`{e}`" for e in r["matches"])
    out.append(f"| `{r['class']}` | `{r['method']}` | `{r['ret']} {r['method']}({r['params']})` | {exp} |\n")

out.append("\n## ⚠️ VERIFICAR — sin export directo encontrado en gamma.dll\n\n")
out.append("| Clase | Método | Firma | Prefijo JNI esperado |\n")
out.append("|---|---|---|---|\n")
for r in unmatched:
    out.append(f"| `{r['class']}` | `{r['method']}` | `{r['ret']} {r['method']}({r['params']})` | `{r['prefix']}` |\n")

Path(sys.argv[3]).write_text("".join(out))
print(f"Written to {sys.argv[3]}")
