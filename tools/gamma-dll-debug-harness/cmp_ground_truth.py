#!/usr/bin/env python3
"""
Real pixel-exact ground-truth extractor for .cmp texture files, using the
OFFICIAL cmpview.exe (tools/gdk-sdk/cmpview.exe, Knowledge Adventure
1993-95) running natively under Wine - not our own decoder. This is
independent, authoritative ground truth: cmpview.exe decodes ANY real
.cmp file (verified against real GroundZero content, not just the 3
tutorial samples), so this works today regardless of whether our own
Stage 1 Huffman decoder is implemented yet.

Method (calibrated and verified this session against test4b.cmp, whose
exact expected pixels are already independently documented in
tools/gamma-dll-debug-harness/cmp-stage2-decoder/README.md - 256px each
of (252,0,0)/(0,252,0)/(0,0,252)/(252,252,0) - reproduced here EXACTLY,
zero-noise, via this script's own detection logic, not copied from that
doc):

1. Launch `wine cmpview.exe <file>.cmp` under a real Xvfb display (no
   window manager needed - Wine places its one top-level window at
   screen origin (0,0) reliably in this environment).
2. Screenshot the whole root window (`import -window root`).
3. cmpview.exe's client area is a plain white canvas with a menu bar;
   the image always starts at y=51 (confirmed identical across a 32x32
   synthetic file and a 128x128 real file - the menu bar's height is
   fixed regardless of image size) and some x offset that varies with
   window width (the window appears to horizontally center small
   images - x is NOT assumed fixed, detected per-capture instead).
   Scan row y=51 for the first x where a full run of `width` pixels
   isn't uniformly pure white - that's the image's left edge.
4. Crop the real width x height block from there - that's ground truth.

Real, honest failure mode: if no such run is found (the whole row stays
white), cmpview.exe didn't render an image - either it couldn't decode
the file (e.g. "File does not have correct format" dialog, seen in an
earlier session for a mis-encoded test file) or it's still loading.
Reported as a real failure, never guessed at.
"""
import os
import struct
import subprocess
import sys
import time

CMPVIEW_EXE = "/home/lucas/FreeWorlds/tools/gdk-sdk/cmpview.exe"
MENU_Y = 51  # confirmed fixed offset, see module docstring


def read_header_wh(cmp_path):
    with open(cmp_path, "rb") as f:
        data = f.read(16)
    if len(data) < 10 or data[0:4] != b"LzH2":
        raise ValueError("not a LzH2 .cmp file: " + cmp_path)
    w = struct.unpack("<H", data[6:8])[0]
    h = struct.unpack("<H", data[8:10])[0]
    return w, h


def _run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def ensure_wineprefix(wineprefix):
    os.makedirs(wineprefix, exist_ok=True)
    env = dict(os.environ, WINEPREFIX=wineprefix, WINEDEBUG="-all")
    if not os.path.exists(os.path.join(wineprefix, "system.reg")):
        _run(["wineboot", "--init"], env=env, timeout=60)
    return env


def capture(cmp_path, work_dir, wineprefix, display, settle_s=3.0, max_wait_s=9.0):
    """Returns (width, height, rgb_bytes) top-down RGB, or raises RuntimeError
    with a real, specific reason on failure. rgb_bytes is width*height*3 bytes."""
    os.makedirs(work_dir, exist_ok=True)
    base = os.path.basename(cmp_path)
    local_cmp = os.path.join(work_dir, base)
    if os.path.abspath(local_cmp) != os.path.abspath(cmp_path):
        with open(cmp_path, "rb") as src, open(local_cmp, "wb") as dst:
            dst.write(src.read())

    try:
        w, h = read_header_wh(local_cmp)
    except Exception as e:
        raise RuntimeError("bad header: %s" % e)

    env = ensure_wineprefix(wineprefix)
    env["DISPLAY"] = display

    # Wine's process model means the "wine" launcher PID is often NOT the
    # actual cmpview.exe process (it forks/execs through its own machinery,
    # sometimes via an internal start.exe wrapper) - proc.terminate() below
    # only ever reliably killed the launcher, leaving real cmpview.exe (and
    # start.exe) processes running. Across a 159-file corpus run those
    # orphans accumulate, eventually leaving multiple overlapping top-level
    # windows on screen - which silently breaks the "one window at origin"
    # assumption this module's docstring depends on (the screenshot then
    # captures stale/wrong/occluded content - a real bug found and fixed
    # this session after it silently corrupted a full corpus run's ground
    # truth (every file came back a false FAIL, not a true one).
    # Belt-and-suspenders fix: kill any leftover instances BEFORE starting
    # a new one, not just after.
    _run(["pkill", "-9", "-f", "cmpview.exe"])
    _run(["pkill", "-9", "-f", "start.exe /exec"])
    time.sleep(0.2)

    proc = subprocess.Popen(
        ["wine", CMPVIEW_EXE, base], cwd=work_dir, env=env,
        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
    )
    try:
        shot_path = os.path.join(work_dir, "_shot.ppm")
        deadline = time.time() + max_wait_s
        found = None
        # Poll: screenshot, try to detect the image; real content needs the
        # process to actually finish decoding+painting first, which varies
        # per file (bigger/more complex files take longer) - polling beats a
        # fixed sleep for speed across a large corpus.
        time.sleep(settle_s)
        while time.time() < deadline:
            r = _run(["import", "-display", display, "-window", "root", shot_path])
            if r.returncode != 0:
                time.sleep(0.5)
                continue
            found = _find_and_crop(shot_path, w, h)
            if found is not None:
                break
            time.sleep(0.5)
        if found is None:
            raise RuntimeError(
                "cmpview.exe did not render a %dx%d image within %.1fs "
                "(no image content detected at y=%d - likely a decode "
                "error dialog, or genuinely too slow)" % (w, h, max_wait_s, MENU_Y)
            )
        return w, h, found
    finally:
        proc.terminate()
        try:
            proc.wait(timeout=3)
        except subprocess.TimeoutExpired:
            proc.kill()
            proc.wait(timeout=3)
        # See the pre-launch cleanup above: proc.terminate()/kill() only
        # ever reliably kills the "wine" launcher, not the real cmpview.exe
        # (and possible start.exe wrapper) it spawns - clean those up by
        # name too so they never survive into the next file's capture.
        _run(["pkill", "-9", "-f", "cmpview.exe"])
        _run(["pkill", "-9", "-f", "start.exe /exec"])


def _read_ppm(path):
    with open(path, "rb") as f:
        magic = f.readline().strip()
        if magic != b"P6":
            raise RuntimeError("unexpected PPM magic: %r" % magic)
        dims = f.readline()
        while dims.startswith(b"#"):
            dims = f.readline()
        w, h = map(int, dims.split())
        maxval = f.readline()
        data = f.read()
    return w, h, data


def _find_and_crop(png_path, img_w, img_h):
    ppm_path = png_path + ".ppm"
    r = _run(["convert", png_path, "-depth", "8", "ppm:" + ppm_path])
    if r.returncode != 0:
        return None
    W, H, data = _read_ppm(ppm_path)
    os.remove(ppm_path)
    if MENU_Y >= H:
        return None

    def px(x, y):
        off = (y * W + x) * 3
        return data[off], data[off + 1], data[off + 2]

    def is_white(x, y):
        r, g, b = px(x, y)
        return r > 250 and g > 250 and b > 250

    # The window has a thin (~4px) black frame at x=0 before the white
    # client area starts - a naive "first non-white pixel" scan locks onto
    # that border, not the real image (found and fixed this session: x=0-3
    # black, x=4+ white, so "not is_white(0)" was true and the reject check
    # below only required the run to not be ALL-white, which a 4px-black +
    # rest-white run also satisfies). Real fix: require a solid run of
    # `probe` consecutive NON-white pixels (real image content), not just
    # "not literally every pixel is white".
    left = None
    probe = min(8, img_w)
    for x in range(0, W - img_w):
        if all(not is_white(xx, MENU_Y) for xx in range(x, x + probe)):
            left = x
            break
    if left is None:
        return None
    if left + img_w > W or MENU_Y + img_h > H:
        return None

    out = bytearray(img_w * img_h * 3)
    for yy in range(img_h):
        row_off = ((MENU_Y + yy) * W + left) * 3
        out_off = yy * img_w * 3
        out[out_off:out_off + img_w * 3] = data[row_off:row_off + img_w * 3]
    return bytes(out)


def save_ppm(path, w, h, rgb):
    with open(path, "wb") as f:
        f.write(b"P6\n%d %d\n255\n" % (w, h))
        f.write(rgb)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: cmp_ground_truth.py <file.cmp> [out.ppm]", file=sys.stderr)
        sys.exit(2)
    cmp_path = sys.argv[1]
    out_path = sys.argv[2] if len(sys.argv) > 2 else "/tmp/gt_out.ppm"
    work_dir = "/tmp/cmp-gt-work"
    wineprefix = os.environ.get("GT_WINEPREFIX", "/tmp/cmp-gt-wine")
    display = os.environ.get("GT_DISPLAY", ":100")
    w, h, rgb = capture(cmp_path, work_dir, wineprefix, display)
    save_ppm(out_path, w, h, rgb)
    print("OK %dx%d -> %s" % (w, h, out_path))
