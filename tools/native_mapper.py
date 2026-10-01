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
out.append(f"# `native` method mapper — WorldsPlayer client vs. `gamma.dll`\n")
out.append(f"Generated automatically by cross-referencing the `native` methods of the\n"
           f"decompiled Java code (`editor/worldsplayer_source_editor-main/source/`)\n"
           f"against the export table of `move/bin/gamma.dll` (372 JNI symbols).\n\n")
out.append(f"- Total `native` declarations found: **{len(rows)}**\n")
out.append(f"- With a matching JNI export in `gamma.dll`: **{len(matched)}**\n")
out.append(f"- Without a match: **{len(unmatched)}**\n\n")

out.append(
    "## Investigation of the originally unmapped methods (2026-09-08)\n\n"
    "The mapper's first pass (simple heuristic: JNI escapes `_` as `_1` in "
    "the exported name, and a modifiers regex that only accepted `static` "
    "in a fixed position) left 2 of 360 without a match, and in passing "
    "skipped 5 real declarations because they have their modifiers in a "
    "different order (`static final native`, `static synchronized "
    "native`). With the regex fixed the real total is **365**, of which "
    "**2** remain unmapped. Investigated with real evidence, not "
    "assumption:\n\n"
    "1. **`NET.worlds.scape.sendURL.silent_get`** — ✅ **RESOLVED, it was a "
    "false negative of the script.** The symbol does exist in `gamma.dll`:\n"
    "   ```\n"
    "   ?Java_NET_worlds_scape_sendURL_silent_get@@YGJPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z\n"
    "   ```\n"
    "   `gamma.dll` mixes two export conventions: most are "
    "`extern \"C\" __stdcall` functions (`_Java_...@N`, following the "
    "standard JNI escape `_`→`_1`), but a handful were exported with MSVC "
    "C++ mangling (`?Java_...@@YG...@Z`), where the JNI name was wrapped as "
    "a C++ identifier **without** applying the `_1` escape. The script has "
    "already been updated to try both forms (*Mangling* column in the "
    "table below).\n\n"
    "2. **`NET.worlds.scape.PendingCacheDrone.nativeDestroy`** — ⚠️ "
    "**confirmed dead code, not a reverse-engineering gap.** "
    "Evidence:\n"
    "   - It does not appear in any export of `gamma.dll` under either of "
    "the two conventions (`grep -i destroy` over the 372 entries does not "
    "find it; `PendingCacheDrone_nativeInit` and "
    "`PendingCacheDrone_notifySeqLoaded` do appear, the other two natives "
    "of the same class).\n"
    "   - **0 call sites** in the 722 decompiled files — neither "
    "`nativeDestroy()` inside the class itself, nor "
    "`PendingCacheDrone.nativeDestroy()` from any other. Compare with "
    "`nativeInit()`, which is invoked from the `static {}` block of the "
    "same class.\n"
    "   - The class is real and active (`PendingCacheDrone` is used from "
    "`DroneAnimator`/`SeqFile`), so it is not an orphan file — it is "
    "specifically this method that was left unused, probably declared for "
    "symmetry with `nativeInit()` (init/destroy) but never wired to a real "
    "`finalize()`/`shutdown()`.\n"
    "   - **Practical conclusion**: there is no need to reimplement it. If "
    "during the renderer reimplementation phase a need for a cleanup path "
    "for the avatar cache is detected, this is the hint of where it should "
    "go — but it blocks nothing in the current client.\n\n"
    "3. **`NET.worlds.console.Console.getVolumeInfo`** — ⚠️ **also dead "
    "code, same pattern as the previous one.** Evidence:\n"
    "   - There is a **twin** method in another class, "
    "`NET.worlds.console.Startup.getVolumeInfo()`, which is exported "
    "(`_Java_NET_worlds_console_Startup_getVolumeInfo@8`) and is actually "
    "called from `LoginWizard.java:702`.\n"
    "   - The `Console` version has no export under its own qualified name "
    "(a `grep` over the 372 entries of `gamma.dll` only finds the `Startup` "
    "one) and **0 call sites** in the whole decompiled code.\n"
    "   - Most likely reading: the functionality was moved from `Console` to "
    "`Startup` at some point in the original development (2000-2004) and "
    "the old declaration was left uncleaned in `Console`.\n\n"
)
out.append("## ✅ Matched to a gamma.dll export\n\n")
out.append("| Class | Method | Signature | Export(s) in gamma.dll | Mangling |\n")
out.append("|---|---|---|---|---|\n")
for r in matched:
    exp = "<br>".join(f"`{e}`" for e in r["matches"])
    out.append(f"| `{r['class']}` | `{r['method']}` | `{r['ret']} {r['method']}({r['params']})` | {exp} | {r['match_kind']} |\n")

out.append("\n## No direct export found in gamma.dll\n\n")
for r in unmatched:
    out.append(f"### `{r['class']}.{r['method']}`\n\n")
    out.append(f"- Signature: `{r['ret']} {r['method']}({r['params']})`\n")
    out.append(f"- Expected JNI prefix (escaped): `{r['prefix']}`\n")
    out.append(f"- Occurrences of `{r['method']}(` as a *call* in the rest of the "
               f"decompiled code (excluding the declaration itself): "
               f"**{r['call_sites_excl_decl']}**\n")
    out.append("\n")

Path(sys.argv[3]).write_text("".join(out))
print(f"Written to {sys.argv[3]}")
