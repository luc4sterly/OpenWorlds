#!/usr/bin/env python3
"""Verify Java .mov frame-0 decodes against official cmpview.exe renders.
Template-matches each decode onto a full-desktop cmpview screenshot
(coarse-to-fine, pure stdlib+PIL), then counts exact pixel matches."""
import os
import subprocess
import sys
import time
from PIL import Image

CMPVIEW = "/home/lucas/FreeWorlds/tools/gdk-sdk/cmpview.exe"
DISPLAY = os.environ.get("VERIFY_DISPLAY", ":100")


def sh(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, **kw)


def launch(mov_path, workdir):
    sh(["pkill", "-9", "-f", "[c]mpview.exe"])
    time.sleep(0.3)
    base = os.path.basename(mov_path)
    local = os.path.join(workdir, base)
    if os.path.abspath(local) != os.path.abspath(mov_path):
        with open(mov_path, "rb") as s, open(local, "wb") as d:
            d.write(s.read())
    env = dict(os.environ, DISPLAY=DISPLAY, WINEDEBUG="-all")
    p = subprocess.Popen(["wine", CMPVIEW, base], cwd=workdir, env=env,
                         stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return p


def killall():
    sh(["pkill", "-9", "-f", "[c]mpview.exe"])
    time.sleep(0.3)


def shot(path):
    r = sh(["import", "-display", DISPLAY, "-window", "root", path])
    return r.returncode == 0


def sad(a, b):
    ap, bp = list(a.getdata()), list(b.getdata())
    return sum(abs(x[0] - y[0]) + abs(x[1] - y[1]) + abs(x[2] - y[2]) for x, y in zip(ap, bp))


def locate(desktop, mine):
    # coarse: both /4
    ds = desktop.resize((desktop.width // 4, desktop.height // 4))
    ms = mine.resize((32, 32))
    best = None
    for dy in range(0, ds.height - 32):
        for dx in range(0, ds.width - 32):
            s = sad(ds.crop((dx, dy, dx + 32, dy + 32)), ms)
            if best is None or s < best[0]:
                best = (s, dx, dy)
    cx, cy = best[1] * 4, best[2] * 4
    # refine full-res +-6
    best2 = None
    for dy in range(max(0, cy - 6), cy + 7):
        for dx in range(max(0, cx - 6), cx + 7):
            if dx + 128 > desktop.width or dy + 128 > desktop.height:
                continue
            s = sad(desktop.crop((dx, dy, dx + 128, dy + 128)), mine)
            if best2 is None or s < best2[0]:
                best2 = (s, dx, dy)
    return best2


def main(files):
    workdir = "/tmp/movverify"
    os.makedirs(workdir, exist_ok=True)
    results = []
    for f in files:
        name = os.path.basename(f).replace(".mov", "")
        mine = Image.open("/tmp/mov_%s.png" % name).convert("RGB")
        launch(f, workdir)
        time.sleep(4.0)
        sp = os.path.join(workdir, "_desk.ppm")
        ok = shot(sp)
        killall()
        if not ok:
            print("%s: SHOT-FAIL" % name)
            results.append((name, -1, -1))
            continue
        desk = Image.open(sp).convert("RGB")
        score, dx, dy = locate(desk, mine)
        crop = desk.crop((dx, dy, dx + 128, dy + 128))
        mp, cp = list(mine.getdata()), list(crop.getdata())
        exact = sum(1 for a, b in zip(mp, cp) if a == b)
        print("%s: pos=(%d,%d) sad=%d exact=%d/16384" % (name, dx, dy, score, exact))
        results.append((name, exact, score))
    return results


if __name__ == "__main__":
    main(sys.argv[1:])
