#!/usr/bin/env python3
"""
Corpus-wide `.cmp` decode coverage harness. This is the project's real
closing criterion for Stage 1 work from here on - nothing gets called
"resolved" without passing through this against the real game corpus,
not just the 3 hand-captured tutorial files.

For each real .cmp file:
  1. Extract independent, authoritative ground truth by running the
     OFFICIAL cmpview.exe under Wine and reading its real decoded pixels
     off screen (cmp_ground_truth.py - calibrated this session against
     test4b.cmp's already-documented exact expected pixels, and
     cross-validated against sball.cmp's already-verified decoder output:
     both AE=0, zero pixel difference).
  2. Attempt to decode the same file with our own Java pipeline
     (CmpDecodeCli -> net.freeworlds.cmp.CmpTexture).
  3. If both succeed, pixel-diff them (ImageMagick `compare -metric AE`).
  4. Record OK / FAIL(reason) / NOT TESTED(reason) - never invented.

Usage:
  python3 cmp_stage1_coverage.py <cmp-file-or-dir> [<cmp-file-or-dir> ...] \
      --report /path/to/report.md [--java-classes /path/to/compiled/classes]

Each positional arg is either a .cmp file, or a directory (scanned
non-recursively for *.cmp), or a manifest .txt file (one path per line).
"""
import argparse
import glob
import os
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cmp_ground_truth as gt

REPO_ROOT = "/home/lucas/FreeWorlds"
CLI_CLASS = "CmpDecodeCli"


def collect_files(args):
    files = []
    for a in args:
        if os.path.isdir(a):
            files.extend(sorted(glob.glob(os.path.join(a, "*.cmp"))))
        elif a.endswith(".txt"):
            with open(a) as f:
                for line in f:
                    line = line.strip()
                    if line and not line.startswith("#"):
                        files.append(line)
        else:
            files.append(a)
    # de-dup by real path, keep order
    seen = set()
    out = []
    for f in files:
        rp = os.path.abspath(f)
        if rp not in seen:
            seen.add(rp)
            out.append(f)
    return out


def decode_with_java(cmp_path, java_classes, work_dir):
    d = os.path.dirname(os.path.abspath(cmp_path))
    base = os.path.basename(cmp_path)
    if base.lower().endswith(".cmp"):
        base = base[:-4]
    out_ppm = os.path.join(work_dir, base + "_decoded.ppm")
    r = subprocess.run(
        ["java", "-cp", java_classes, CLI_CLASS, d, base, out_ppm],
        capture_output=True, text=True, timeout=30,
    )
    if r.returncode == 0:
        return out_ppm, None
    reason = (r.stderr or r.stdout).strip().splitlines()
    reason = reason[-1] if reason else "unknown Java failure (no output)"
    return None, reason


def run_one(cmp_path, java_classes, work_dir, wineprefix, display):
    name = os.path.basename(cmp_path)
    row = {"file": name, "path": cmp_path}
    try:
        w, h, gt_rgb = gt.capture(cmp_path, os.path.join(work_dir, "gt"), wineprefix, display)
    except Exception as e:
        row["status"] = "NOT TESTED"
        row["reason"] = "ground truth: %s" % e
        return row
    row["w"], row["h"] = w, h

    decoded_ppm, decode_err = decode_with_java(cmp_path, java_classes, work_dir)
    if decoded_ppm is None:
        row["status"] = "FAIL"
        row["reason"] = "decode: %s" % decode_err
        return row

    gt_ppm = os.path.join(work_dir, name + "_gt.ppm")
    gt.save_ppm(gt_ppm, w, h, gt_rgb)
    cmp_res = subprocess.run(
        ["compare", "-metric", "AE", decoded_ppm, gt_ppm, "/dev/null"],
        capture_output=True, text=True,
    )
    ae_text = (cmp_res.stderr or cmp_res.stdout).strip().split()
    try:
        ae = int(ae_text[0]) if ae_text else -1
    except ValueError:
        ae = -1
    total_px = w * h
    if ae == 0:
        row["status"] = "OK"
        row["reason"] = "byte-exact, 0/%d pixels differ" % total_px
    else:
        row["status"] = "FAIL"
        row["reason"] = "decoded but %s/%d pixels differ from real cmpview.exe ground truth" % (
            ae_text[0] if ae_text else "?", total_px)
    return row


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("inputs", nargs="+")
    ap.add_argument("--report", required=True)
    ap.add_argument("--java-classes", default="/tmp/cmp-coverage-out")
    ap.add_argument("--wineprefix", default="/tmp/cmp-gt-wine")
    ap.add_argument("--display", default=":100")
    ap.add_argument("--work-dir", default="/tmp/cmp-coverage-work")
    args = ap.parse_args()

    files = collect_files(args.inputs)
    os.makedirs(args.work_dir, exist_ok=True)
    results = []
    t0 = time.time()
    for i, f in enumerate(files):
        t1 = time.time()
        row = run_one(f, args.java_classes, args.work_dir, args.wineprefix, args.display)
        dt = time.time() - t1
        results.append(row)
        print("[%d/%d] %s: %s (%.1fs)" % (i + 1, len(files), row["file"], row["status"], dt),
              file=sys.stderr)

    ok = sum(1 for r in results if r["status"] == "OK")
    fail = sum(1 for r in results if r["status"] == "FAIL")
    nt = sum(1 for r in results if r["status"] == "NOT TESTED")

    with open(args.report, "w") as out:
        out.write("# `.cmp` Stage 1 corpus coverage report\n\n")
        out.write(
            "This is the project's real closing criterion for `.cmp` Stage 1 work: "
            "nothing is claimed \"decoded\" without passing through this harness "
            "against the real game corpus, not just the 3 hand-captured tutorial "
            "files (`test4b`/`rustwood`/`sball`) used in earlier sessions.\n\n"
            "**Method**: for every file, `tools/gamma-dll-debug-harness/"
            "cmp_ground_truth.py` runs the OFFICIAL `cmpview.exe` "
            "(Knowledge Adventure 1993-95, `tools/gdk-sdk/cmpview.exe`) natively "
            "under Wine and reads its real decoded pixels directly off the "
            "rendered window (auto-detecting the image's on-screen position, not "
            "a hardcoded offset). This is INDEPENDENT of our own decoder - "
            "cmpview.exe decodes any real `.cmp` file today, Stage 1 or not.\n\n"
            "**Ground-truth method calibrated and cross-validated this session, "
            "with real evidence, not just re-asserted**: against `test4b.cmp` "
            "(self-designed, exactly known expected pixels - see "
            "`cmp-stage2-decoder/README.md`) this harness's own extraction "
            "reproduces the documented 256px-each-of-4-colors result exactly, "
            "zero noise. Against `sball.cmp` (already independently verified "
            "byte-exact by our own decoder), this harness's freshly-extracted "
            "ground truth and our decoder's output are pixel-IDENTICAL "
            "(`compare -metric AE` = 0/16384). One real bug was found and fixed "
            "while building this: the naive \"first non-white pixel\" scan "
            "locked onto cmpview.exe's own ~4px black window-frame border "
            "instead of the real image - fixed by requiring a solid run of "
            "non-white pixels, not just one.\n\n"
            "Then, for each file, the existing Java pipeline "
            "(`net.freeworlds.cmp.CmpTexture`, via the `CmpDecodeCli` wrapper in "
            "`cmp-stage2-decoder/`) attempts to decode the SAME file, and if it "
            "succeeds, the two are pixel-diffed. **OK** = byte-exact against real "
            "ground truth. **FAIL** = either our decoder threw (with the real "
            "exception message) or it produced pixels that don't match. **NOT "
            "TESTED** = even the ground-truth extraction itself failed for that "
            "file (reported honestly, never silently skipped).\n\n"
        )
        out.write("**%d files tested: %d OK, %d FAIL, %d NOT TESTED "
                   "(total run time %.0fs)**\n\n" % (len(results), ok, fail, nt, time.time() - t0))
        out.write("| file | status | dims | reason |\n|---|---|---|---|\n")
        for r in results:
            dims = "%sx%s" % (r.get("w", "?"), r.get("h", "?"))
            out.write("| `%s` | %s | %s | %s |\n" % (r["file"], r["status"], dims, r["reason"]))
    print("Report written to %s" % args.report, file=sys.stderr)
    print("SUMMARY: %d/%d OK, %d FAIL, %d NOT TESTED" % (ok, len(results), fail, nt))


if __name__ == "__main__":
    main()
