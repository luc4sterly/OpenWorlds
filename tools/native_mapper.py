#!/usr/bin/env python3
import re
import sys
from pathlib import Path

SRC = Path(sys.argv[1])
EXPORTS_FILE = Path(sys.argv[2])

exports = [l.strip() for l in EXPORTS_FILE.read_text().splitlines() if l.strip()]

native_re = re.compile(
    # Modifiers can appear in any order (e.g. "public static final native",
    # "public static synchronized native") - earlier versions of this regex
    # only allowed a single fixed "static" slot and missed 5 real
    # declarations as a result. Allow any repeated combination.
    r'^\s*(?:(?:public|private|protected|static|final|synchronized)\s+)*'
    r'native\s+'
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
        # package/class segments becomes '_'. Most exports in gamma.dll are
        # plain C (__stdcall, "_Name@N") and follow this escaping. A handful
        # are C++-mangled ("?Name@@YG...@Z") where the *literal* JNI function
        # name (unescaped) was wrapped as a C++ identifier by MSVC, so the
        # '_1' substitution never happened for those - check both forms.
        def jni_escape(s):
            return s.replace("_", "_1")
        prefix_escaped = "Java_" + "_".join(jni_escape(p) for p in pkg.split(".")) \
            + "_" + jni_escape(cls) + "_" + jni_escape(method)
        prefix_plain = "Java_" + "_".join(pkg.split(".")) + "_" + cls + "_" + method
        matches = [e for e in exports if prefix_escaped in e]
        match_kind = "JNI-escaped (_1)" if matches else None
        if not matches:
            matches = [e for e in exports if prefix_plain in e]
            match_kind = "C++ mangled, unescaped" if matches else None
        rows.append({
            "class": f"{pkg}.{cls}",
            "method": method,
            "ret": ret_type.strip(),
            "params": params.strip(),
            "prefix": prefix_escaped,
            "matches": matches,
            "match_kind": match_kind,
        })

matched = [r for r in rows if r["matches"]]
unmatched = [r for r in rows if not r["matches"]]

# For anything still unmatched, check whether it's ever called from the
# decompiled source at all - a strong signal of dead/unused code rather
# than a real reverse-engineering gap. Scope the search to either
# "ClassName.method(" (qualified, from anywhere) or a bare "method(" call
# inside the *declaring* class's own file (unqualified self-call), so
# same-named natives on unrelated classes don't produce false positives.
for r in unmatched:
    cls_short = r["class"].rsplit(".", 1)[-1]
    file_path = next(SRC.rglob(f"{cls_short}.java"), None)
    own_text = file_path.read_text(errors="replace") if file_path else ""
    own_calls = len(re.findall(
        r'(?<!native\s)(?<!void\s)\b' + re.escape(r["method"]) + r'\s*\(', own_text
    )) - 1  # minus the declaration itself
    qualified_pattern = re.compile(
        re.escape(cls_short) + r'\.' + re.escape(r["method"]) + r'\s*\('
    )
    qualified_calls = 0
    for f in SRC.rglob("*.java"):
        if f == file_path:
            continue
        qualified_calls += len(qualified_pattern.findall(f.read_text(errors="replace")))
    r["call_sites_excl_decl"] = max(own_calls, 0) + qualified_calls

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
out.append(f"- Sin coincidencia: **{len(unmatched)}**\n\n")

out.append(
    "## Investigación de los métodos originalmente sin mapear (2026-09-08)\n\n"
    "La primera pasada del mapeador (heurística simple: JNI escapa `_` como "
    "`_1` en el nombre exportado, y una regex de modificadores que solo "
    "aceptaba `static` en una posición fija) dejó 2 de 360 sin match, y de "
    "paso se saltó 5 declaraciones reales por tener modificadores en otro "
    "orden (`static final native`, `static synchronized native`). Con la "
    "regex corregida el total real es **365**, de las cuales quedan **2** "
    "sin mapear. Investigados con evidencia real, no suposición:\n\n"
    "1. **`NET.worlds.scape.sendURL.silent_get`** — ✅ **RESUELTO, era un "
    "falso negativo del script.** El símbolo sí existe en `gamma.dll`:\n"
    "   ```\n"
    "   ?Java_NET_worlds_scape_sendURL_silent_get@@YGJPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z\n"
    "   ```\n"
    "   `gamma.dll` mezcla dos convenciones de export: la mayoría son "
    "funciones `extern \"C\" __stdcall` (`_Java_...@N`, siguiendo el escape "
    "JNI estándar `_`→`_1`), pero un puñado se exportaron con mangling C++ "
    "de MSVC (`?Java_...@@YG...@Z`), donde el nombre JNI se envolvió como "
    "identificador C++ **sin** aplicar el escape `_1`. El script ya se "
    "actualizó para probar ambas formas (columna *Mangling* en la tabla de "
    "abajo).\n\n"
    "2. **`NET.worlds.scape.PendingCacheDrone.nativeDestroy`** — ⚠️ "
    "**confirmado código muerto, no una laguna de ingeniería inversa.** "
    "Evidencia:\n"
    "   - No aparece en ningún export de `gamma.dll` bajo ninguna de las dos "
    "convenciones (`grep -i destroy` sobre las 372 entradas no lo encuentra; "
    "sí aparecen `PendingCacheDrone_nativeInit` y "
    "`PendingCacheDrone_notifySeqLoaded`, las otras dos natives de la misma "
    "clase).\n"
    "   - **0 call sites** en los 722 archivos decompilados — ni "
    "`nativeDestroy()` dentro de la propia clase, ni "
    "`PendingCacheDrone.nativeDestroy()` desde ninguna otra. Compárese con "
    "`nativeInit()`, que sí se invoca desde el bloque `static {}` de la "
    "misma clase.\n"
    "   - La clase es real y activa (`PendingCacheDrone` se usa desde "
    "`DroneAnimator`/`SeqFile`), así que no es un archivo huérfano — es "
    "específicamente este método el que quedó sin usar, probablemente "
    "declarado por simetría con `nativeInit()` (init/destroy) pero nunca "
    "conectado a un `finalize()`/`shutdown()` real.\n"
    "   - **Conclusión práctica**: no hace falta reimplementarlo. Si en la "
    "fase de reimplementación del renderer se detecta necesidad de un "
    "cleanup path para el caché de avatares, es la pista de dónde debería "
    "ir — pero no bloquea nada del cliente actual.\n\n"
    "3. **`NET.worlds.console.Console.getVolumeInfo`** — ⚠️ **también "
    "código muerto, mismo patrón que el anterior.** Evidencia:\n"
    "   - Existe un método **gemelo** en otra clase, "
    "`NET.worlds.console.Startup.getVolumeInfo()`, que sí está exportado "
    "(`_Java_NET_worlds_console_Startup_getVolumeInfo@8`) y sí se llama "
    "realmente desde `LoginWizard.java:702`.\n"
    "   - La versión de `Console` no tiene export bajo su propio nombre "
    "calificado (`grep` sobre las 372 entradas de `gamma.dll` solo "
    "encuentra la de `Startup`) y **0 call sites** en todo el código "
    "decompilado.\n"
    "   - Lectura más probable: la funcionalidad se movió de `Console` a "
    "`Startup` en algún momento del desarrollo original (2000-2004) y "
    "quedó la declaración vieja sin limpiar en `Console`.\n\n"
)
out.append("## ✅ Coinciden con un export de gamma.dll\n\n")
out.append("| Clase | Método | Firma | Export(s) en gamma.dll | Mangling |\n")
out.append("|---|---|---|---|---|\n")
for r in matched:
    exp = "<br>".join(f"`{e}`" for e in r["matches"])
    out.append(f"| `{r['class']}` | `{r['method']}` | `{r['ret']} {r['method']}({r['params']})` | {exp} | {r['match_kind']} |\n")

out.append("\n## Sin export directo encontrado en gamma.dll\n\n")
for r in unmatched:
    out.append(f"### `{r['class']}.{r['method']}`\n\n")
    out.append(f"- Firma: `{r['ret']} {r['method']}({r['params']})`\n")
    out.append(f"- Prefijo JNI esperado (escapado): `{r['prefix']}`\n")
    out.append(f"- Ocurrencias de `{r['method']}(` como *llamada* en el resto del código "
               f"decompilado (excluyendo la propia declaración): "
               f"**{r['call_sites_excl_decl']}**\n")
    out.append("\n")

Path(sys.argv[3]).write_text("".join(out))
print(f"Written to {sys.argv[3]}")
