#!/usr/bin/env python3
"""RWX parser comparison harness (docs/worlds-chat-project.md sec. 7, tool #3).

Runs the same .rwx file through the JS reference (three-rwx-loader, via
extract.mjs) and our Java parser (RwxExtractMain), then diffs the
resulting canonical geometry (vertices/triangles/materials). Writes a
per-file status table to docs/rwx-parser-progress.md - the source of
truth for "does our parser actually match the reference" per file.

Both sides emit the SAME shape (see extract.mjs / RwxJsonWriter.java):
{triangleCount, vertexCount, materialCount, materials: [{color(hex),
opacity, transparent, map}], triangles: [{v: [[x,y,z]x3], material: idx}],
warnings: []}, with triangles sorted by JSON.stringify(v) so parsers that
walk/group geometry in a different order still compare equal.

Usage: python3 compare.py [--dir <rwx-dir>] [--limit N]
"""
import argparse
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HARNESS_DIR = ROOT / "tools" / "rwx-harness"
NODE_BIN = ROOT / "tools" / "node" / "bin" / "node"
CLIENT_OUT = ROOT / "client" / "out"
PROGRESS_MD = ROOT / "docs" / "rwx-parser-progress.md"

VERTEX_TOL = 1e-3


def run_js(rwx_path: Path):
    p = subprocess.run(
        [str(NODE_BIN), str(HARNESS_DIR / "extract.mjs"), str(rwx_path)],
        capture_output=True, text=True, timeout=30, cwd=str(HARNESS_DIR),
    )
    return parse_last_json_line(p.stdout, p.stderr)


def run_java(rwx_path: Path):
    p = subprocess.run(
        ["java", "-cp", str(CLIENT_OUT), "net.freeworlds.rwx.RwxExtractMain", str(rwx_path)],
        capture_output=True, text=True, timeout=30,
    )
    return parse_last_json_line(p.stdout, p.stderr)


def parse_last_json_line(stdout, stderr):
    lines = [l for l in stdout.strip().splitlines() if l.strip()]
    if not lines:
        return None, f"no output. stderr: {stderr[:300]}"
    try:
        return json.loads(lines[-1]), None
    except Exception as e:
        return None, f"not JSON: {e}: stdout={stdout[:300]} stderr={stderr[:300]}"


def close(a, b, tol=VERTEX_TOL):
    return abs(a - b) <= tol


def tri_vertices_close(a, b):
    return all(all(close(x, y) for x, y in zip(pa, pb)) for pa, pb in zip(a, b))


def numeric_sort_key(tri):
    # IMPORTANT: do NOT trust each side's own "sort by JSON.stringify(v)"
    # ordering (extract.mjs / RwxJsonWriter.java each pre-sort their own
    # output) - JS and Java format small/large floats differently
    # ("7e-05" vs "7.0E-5"), which silently desyncs a string-based sort
    # between the two even when the underlying triangle SETS are
    # identical, producing false "N/N triangle vertex positions differ"
    # reports. Re-sort both sides here using a rounded NUMERIC tuple key
    # instead, computed identically regardless of source formatting.
    # Rounded to the SAME precision as VERTEX_TOL (not finer): with a finer
    # sort-key precision, two triangles within tolerance of each other but
    # on opposite sides of a rounding boundary (float vs double accumulated
    # error, see docs/rwx-parser-progress.md) can sort-swap relative to a
    # third nearby triangle and misalign the whole rest of the list.
    return tuple(round(c, 3) for v in tri["v"] for c in v)


def diff_geometry(js, jv):
    issues = []
    if js.get("error"):
        return [f"reference (JS) itself errored: {js['error'][:200]}"]
    if jv.get("error"):
        return [f"java errored: {jv['error'][:200]}"]

    jst = sorted(js.get("triangles", []), key=numeric_sort_key)
    jvt = sorted(jv.get("triangles", []), key=numeric_sort_key)
    if len(jst) != len(jvt):
        issues.append(f"triangle count: js={len(jst)} java={len(jvt)}")
    else:
        mismatches = sum(
            1 for a, b in zip(jst, jvt) if not tri_vertices_close(a["v"], b["v"])
        )
        if mismatches:
            issues.append(f"{mismatches}/{len(jst)} triangle vertex positions differ (tol={VERTEX_TOL})")

    return issues


def material_note(js, jv):
    # Material comparison is NOT authoritative (see docs/rwx-format-reference.md):
    # the JS reference needs setEnableTextures(false) to avoid a texture-load
    # failure corrupting *color* too (falls back to flat gray "d8d8d8" on
    # every triangle otherwise, regardless of the file's real Color/Texture
    # commands) - but that also means the reference never records a texture
    # name at all, and THREE.Color's linear/sRGB handling means its hex
    # strings aren't directly comparable to a raw-value hex conversion
    # anyway. So this is reported as an informational note, never a
    # pass/fail signal - geometry (above) is the authoritative comparison.
    return f"materials: js={js.get('materialCount', '?')} java={jv.get('materialCount', '?')} (informational only, see notes)"


def status_for(rwx_path: Path):
    js, jerr = run_js(rwx_path)
    jv, verr = run_java(rwx_path)
    if jerr:
        return "FALLA (js)", jerr
    if verr:
        return "FALLA (java)", verr
    issues = diff_geometry(js, jv)
    note = material_note(js, jv)
    if not issues:
        return "OK", f"{jv.get('triangleCount', 0)} t; {note}"
    return "DIFERENCIAS", "; ".join(issues) + f"; {note}"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dir", default=str(ROOT / "assets"))
    ap.add_argument("--limit", type=int, default=None)
    args = ap.parse_args()

    files = sorted(Path(args.dir).rglob("*.[Rr][Ww][Xx]"))
    if args.limit:
        files = files[: args.limit]

    if not CLIENT_OUT.exists():
        print(f"error: {CLIENT_OUT} does not exist - compile the Java parser first", file=sys.stderr)
        sys.exit(1)

    rows = []
    counts = {}
    for f in files:
        status, detail = status_for(f)
        counts[status] = counts.get(status, 0) + 1
        rel = f.relative_to(ROOT)
        rows.append((str(rel), status, detail))
        print(f"{status:14s} {rel}  {detail}")

    fails = counts.get("FALLA (js)", 0) + counts.get("FALLA (java)", 0)
    out = ["# Progreso del parser RWX (Java) vs. three-rwx-loader (JS)\n\n",
           "Generado por `tools/rwx-harness/compare.py`. Fuente de verdad del estado "
           "real archivo por archivo - no asumir cobertura sin correr esto.\n\n",
           f"**Resumen**: {counts.get('OK',0)} OK / {counts.get('DIFERENCIAS',0)} con diferencias / "
           f"{fails} fallan  (de {len(files)} archivos .rwx probados)\n\n",
           "| Archivo | Estado | Detalle |\n|---|---|---|\n"]
    for rel, status, detail in rows:
        out.append(f"| `{rel}` | {status} | {detail} |\n")

    PROGRESS_MD.write_text("".join(out))
    print(f"\nWritten to {PROGRESS_MD}")


if __name__ == "__main__":
    main()
