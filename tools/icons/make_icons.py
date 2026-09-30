#!/usr/bin/env python3
"""Draws the OpenWorlds icons: low-poly planets with a ring.

Each planet is an 80-face icosphere with flat shading, like the RenderWare
2.1 3D of the game (one light, one colour per face), with a ring that goes
behind and in front of it. Two variants:

- worlds: the game's launcher. Sea and continents, a coral-to-gold ring,
  an indigo night.
- solar:  J Solar Server, the server's admin app. A banded violet gas giant
  with a lavender-to-pink ring, a small moon and a purple night.

Outputs in tools/icons/ for each variant V (openworlds / solar):

- V.svg        the drawing at 1024x1024 (with stars)
- V-small.svg  the 16-32 px variant (no stars, thicker ring)
- V.png        1024x1024 (the Linux app, and the source of the others)
- V.ico        16, 24, 32, 48, 64, 128 and 256 (Windows)
- V.icns       16 to 1024 (macOS)
- and the 256x256 window icon of each app: launcher/resources/net/openworlds/launcher/icon.png
  and server/resources/net/openworlds/solar/icon.png

Usage: python3 tools/icons/make_icons.py [--chrome PATH]
Needs Pillow and a headless Chrome/Chromium to turn the SVG into a 1024 px
PNG (it looks for Playwright's in /opt/pw-browsers, google-chrome, chromium
or the macOS one; --chrome or $CHROME for another); the other sizes are
scaled down from there.
"""
import argparse
import glob
import math
import os
import shutil
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
W = 1024
TILE = (80, 80, 864, 864, 190)  # x, y, width, height, corner radius


def norm(v):
    l = math.sqrt(sum(c * c for c in v))
    return tuple(c / l for c in v)


def hexc(rgb):
    return "#%02x%02x%02x" % tuple(max(0, min(255, int(round(c)))) for c in rgb)


def lerp(a, b, t):
    return tuple(a[i] + (b[i] - a[i]) * t for i in range(3))


def icosphere(sub):
    t = (1 + 5 ** 0.5) / 2
    verts = [norm(v) for v in [(-1, t, 0), (1, t, 0), (-1, -t, 0), (1, -t, 0), (0, -1, t), (0, 1, t),
                               (0, -1, -t), (0, 1, -t), (t, 0, -1), (t, 0, 1), (-t, 0, -1), (-t, 0, 1)]]
    faces = [(0, 11, 5), (0, 5, 1), (0, 1, 7), (0, 7, 10), (0, 10, 11), (1, 5, 9), (5, 11, 4), (11, 10, 2),
             (10, 7, 6), (7, 1, 8), (3, 9, 4), (3, 4, 2), (3, 2, 6), (3, 6, 8), (3, 8, 9), (4, 9, 5), (2, 4, 11),
             (6, 2, 10), (8, 6, 7), (9, 8, 1)]
    for _ in range(sub):
        cache = {}

        def mid(a, b):
            k = (min(a, b), max(a, b))
            if k not in cache:
                va, vb = verts[a], verts[b]
                verts.append(norm(((va[0] + vb[0]) / 2, (va[1] + vb[1]) / 2, (va[2] + vb[2]) / 2)))
                cache[k] = len(verts) - 1
            return cache[k]

        nf = []
        for a, b, c in faces:
            ab, bc, ca = mid(a, b), mid(b, c), mid(c, a)
            nf += [(a, ab, ca), (b, bc, ab), (c, ca, bc), (ab, bc, ca)]
        faces = nf
    return verts, faces


def rot(v, ax, ay):
    x, y, z = v
    c, s = math.cos(ax), math.sin(ax)
    y, z = y * c - z * s, y * s + z * c
    c, s = math.cos(ay), math.sin(ay)
    x, z = x * c + z * s, -x * s + z * c
    return (x, y, z)


def stars(seed, n, avoid, box=(110, 110, 914, 914), rmax=7):
    import random
    rnd = random.Random(seed)
    out = []
    tries = 0
    while len(out) < n and tries < 5000:
        tries += 1
        x = rnd.uniform(box[0], box[2])
        y = rnd.uniform(box[1], box[3])
        if any((x - ax) ** 2 + (y - ay) ** 2 < ar ** 2 for ax, ay, ar in avoid):
            continue
        r = rnd.uniform(2.5, rmax)
        o = rnd.uniform(0.35, 0.95)
        out.append('<circle cx="%.1f" cy="%.1f" r="%.1f" fill="#fff" opacity="%.2f"/>' % (x, y, r, o))
    return "".join(out)


def sparkle(x, y, s, op=0.95):
    d = "M %.1f %.1f Q %.1f %.1f %.1f %.1f Q %.1f %.1f %.1f %.1f Q %.1f %.1f %.1f %.1f Q %.1f %.1f %.1f %.1f Z" % (
        x, y - s, x, y, x + s, y, x, y, x, y + s, x, y, x - s, y, x, y, x, y - s)
    return '<path d="%s" fill="#fff" opacity="%.2f"/>' % (d, op)


VARIANTS = {
    "openworlds": {
        "bg": ("#2d1d72", "#0a0724"),
        "glow": ("#4fd6ff", 0.45),
        "ring": ("#ff5e62", "#ff9f43", "#ffd166"),
        "moon": False,
    },
    "solar": {
        "bg": ("#43177a", "#12051f"),
        "glow": ("#c77dff", 0.42),
        "ring": ("#a78bfa", "#e879f9", "#f9a8d4"),
        "moon": True,
    },
}

# worlds: sea and land (dark end, lit end), the continents from a fixed function
SEA = ((30, 34, 118), (84, 214, 240))
LAND = ((12, 56, 66), (150, 245, 196))
# solar: the gas giant's bands, pole to equator (dark end, lit end)
BANDS = (((46, 16, 96), (196, 158, 255)),
         ((72, 16, 92), (255, 150, 222)),
         ((34, 22, 112), (160, 150, 255)))
MOON = ((58, 44, 108), (236, 226, 255))
LIGHT = norm((-0.55, 0.62, 0.56))
# the ring (and the solar planet's equator) lean this much on the picture
RING_ROLL = 17


def band_of(y):
    """Band index (0 = poles, 1, 2 = equator) for a latitude y in the planet's own frame."""
    a = abs(y)
    return 2 if a < 0.22 else 1 if a < 0.58 else 0


def roll(v, deg):
    """Rotation about the view axis, counter-clockwise on the picture (y up)."""
    c, s_ = math.cos(math.radians(deg)), math.sin(math.radians(deg))
    return (v[0] * c - v[1] * s_, v[0] * s_ + v[1] * c, v[2])


def shaded_sphere(cx, cy, R, sub, place, colour):
    """Flat-shaded polygons of a sphere: place(v) turns a unit vertex, colour(centroid_own, k) gives the fill."""
    verts, faces = icosphere(sub)
    placed = [place(v) for v in verts]
    polys = []
    for a, b, c in faces:
        pa, pb, pc = placed[a], placed[b], placed[c]
        u = (pb[0] - pa[0], pb[1] - pa[1], pb[2] - pa[2])
        w = (pc[0] - pa[0], pc[1] - pa[1], pc[2] - pa[2])
        n = norm((u[1] * w[2] - u[2] * w[1], u[2] * w[0] - u[0] * w[2], u[0] * w[1] - u[1] * w[0]))
        cen = ((pa[0] + pb[0] + pc[0]) / 3, (pa[1] + pb[1] + pc[1]) / 3, (pa[2] + pb[2] + pc[2]) / 3)
        if sum(n[i] * cen[i] for i in range(3)) < 0:
            n = (-n[0], -n[1], -n[2])
        if n[2] <= 0.02:
            continue
        d = max(0.0, sum(n[i] * LIGHT[i] for i in range(3)))
        k = 0.3 + 0.7 * d ** 1.05
        va, vb, vc = verts[a], verts[b], verts[c]
        own = ((va[0] + vb[0] + vc[0]) / 3, (va[1] + vb[1] + vc[1]) / 3, (va[2] + vb[2] + vc[2]) / 3)
        col = hexc(colour(own, cen, k))
        pts = " ".join("%.1f,%.1f" % (cx + R * p[0], cy - R * p[1]) for p in (pa, pb, pc))
        polys.append((cen[2], '<polygon points="%s" fill="%s" stroke="%s" stroke-width="1.5" stroke-linejoin="round"/>' % (pts, col, col)))
    polys.sort()
    return "".join(p for _, p in polys)


def planet_svg(variant="openworlds", small=False, size=W):
    v = VARIANTS[variant]
    cx, cy, R = 512, 512, 236 if not small else 250
    if variant == "solar":
        def place(p):
            return roll(rot(p, math.radians(-14), math.radians(28)), RING_ROLL)

        def colour(own, cen, k):
            return lerp(*BANDS[band_of(own[1])], k)
    else:
        def place(p):
            return rot(p, math.radians(-14), math.radians(28))

        def colour(own, cen, k):
            is_land = (math.sin(4.1 * cen[0] + 1.3) + math.sin(3.3 * cen[1] + 0.4) + math.cos(5.2 * cen[2] - 0.9)) > 1.05
            return lerp(*(LAND if is_land else SEA), k)
    planet = shaded_sphere(cx, cy, R, 1, place, colour)
    moon = ""
    mx, my, mr = 806, 250, 58
    if v["moon"] and not small:
        moon = shaded_sphere(mx, my, mr, 1, lambda p: rot(p, math.radians(20), math.radians(-35)),
                             lambda own, cen, k: lerp(*MOON, k))
    rx, ry, rw = (372, 96, 30) if not small else (392, 104, 46)
    big = 2000
    ring = '<ellipse cx="%d" cy="%d" rx="%d" ry="%d" fill="none" stroke="url(#ring)" stroke-width="%d"/>' % (cx, cy, rx, ry, rw)
    x, y, w, h, r = TILE
    bg0, bg1 = v["bg"]
    gc, go = v["glow"]
    r0, r1, r2 = v["ring"]
    defs = ('<clipPath id="tile"><rect x="%d" y="%d" width="%d" height="%d" rx="%d"/></clipPath>' % (x, y, w, h, r) +
            '<clipPath id="back"><rect x="%d" y="%d" width="%d" height="%d"/></clipPath>' % (cx - big, cy - big, 2 * big, big) +
            '<clipPath id="front"><rect x="%d" y="%d" width="%d" height="%d"/></clipPath>' % (cx - big, cy, 2 * big, big) +
            '<linearGradient id="bg" x1="0" y1="0" x2="1" y2="1"><stop offset="0" stop-color="%s"/><stop offset="1" stop-color="%s"/></linearGradient>' % (bg0, bg1) +
            '<radialGradient id="glow"><stop offset="0" stop-color="%s" stop-opacity="%.2f"/><stop offset="1" stop-color="%s" stop-opacity="0"/></radialGradient>' % (gc, go, gc) +
            '<radialGradient id="moonglow"><stop offset="0" stop-color="%s" stop-opacity="0.30"/><stop offset="1" stop-color="%s" stop-opacity="0"/></radialGradient>' % (gc, gc) +
            '<linearGradient id="ring" x1="0" y1="0" x2="1" y2="0"><stop offset="0" stop-color="%s"/><stop offset="0.55" stop-color="%s"/><stop offset="1" stop-color="%s"/></linearGradient>' % (r0, r1, r2))
    avoid = [(cx, cy, R + 60)] + ([(mx, my, mr + 40)] if moon else [])
    sky = "" if small else stars(7, 26, avoid) + sparkle(250, 230, 26) + sparkle(790, 800, 18, op=0.8)
    moon_glow = '<circle cx="%d" cy="%d" r="%d" fill="url(#moonglow)"/>' % (mx, my, mr + 46) if moon else ""
    body = ('<rect x="%d" y="%d" width="%d" height="%d" rx="%d" fill="url(#bg)"/>' % (x, y, w, h, r) +
            '<g clip-path="url(#tile)">' + sky + moon_glow + moon +
            '<circle cx="%d" cy="%d" r="%d" fill="url(#glow)"/>' % (cx, cy, R + 150) +
            '<g transform="rotate(-%d %d %d)"><g clip-path="url(#back)">%s</g></g>' % (RING_ROLL, cx, cy, ring) +
            planet +
            '<g transform="rotate(-%d %d %d)"><g clip-path="url(#front)">%s</g></g>' % (RING_ROLL, cx, cy, ring) + "</g>")
    return ('<svg xmlns="http://www.w3.org/2000/svg" width="%d" height="%d" viewBox="0 0 %d %d">'
            '<defs>%s</defs>%s</svg>\n') % (size, size, W, W, defs, body)


def find_chrome(explicit):
    cands = [explicit, os.environ.get("CHROME")]
    cands += sorted(glob.glob("/opt/pw-browsers/chromium-*/chrome-linux/chrome"), reverse=True)
    cands += [shutil.which(n) for n in ("google-chrome", "chromium", "chromium-browser", "chrome")]
    cands += ["/Applications/Google Chrome.app/Contents/MacOS/Google Chrome", "/Applications/Chromium.app/Contents/MacOS/Chromium"]
    for c in cands:
        if c and os.path.isfile(c):
            return c
    sys.exit("make_icons: no Chrome/Chromium found (--chrome PATH)")


def render(chrome, svg_text, size, out_png, tmp):
    src = os.path.join(tmp, "icon-%d.svg" % size)
    with open(src, "w") as f:
        f.write(svg_text)
    subprocess.run([chrome, "--headless=new", "--no-sandbox", "--disable-gpu", "--hide-scrollbars",
                    "--disable-background-networking", "--default-background-color=00000000",
                    "--window-size=%d,%d" % (size, size), "--screenshot=" + out_png, "file://" + src],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, timeout=120)


def make(chrome, variant, window_icon, tmp):
    from PIL import Image
    with open(os.path.join(HERE, variant + ".svg"), "w") as f:
        f.write(planet_svg(variant))
    with open(os.path.join(HERE, variant + "-small.svg"), "w") as f:
        f.write(planet_svg(variant, small=True))
    # headless Chrome crops small windows (a 128x128 comes out halved): draw
    # everything at 1024 and scale down with Lanczos. 16-32 px come from the
    # variant without stars and with the thicker ring.
    big = os.path.join(tmp, variant + "-big.png")
    small = os.path.join(tmp, variant + "-small.png")
    render(chrome, planet_svg(variant), W, big, tmp)
    render(chrome, planet_svg(variant, small=True), W, small, tmp)
    big_im = Image.open(big).convert("RGBA")
    small_im = Image.open(small).convert("RGBA")
    imgs = {}
    for s in (16, 24, 32):
        imgs[s] = small_im.resize((s, s), Image.LANCZOS)
    for s in (48, 64, 128, 256, 512):
        imgs[s] = big_im.resize((s, s), Image.LANCZOS)
    imgs[1024] = big_im
    imgs[1024].save(os.path.join(HERE, variant + ".png"), optimize=True)
    os.makedirs(os.path.dirname(window_icon), exist_ok=True)
    imgs[256].save(window_icon, optimize=True)
    ico_sizes = [16, 24, 32, 48, 64, 128, 256]
    imgs[256].save(os.path.join(HERE, variant + ".ico"), sizes=[(s, s) for s in ico_sizes],
                   append_images=[imgs[s] for s in ico_sizes if s != 256])
    imgs[1024].save(os.path.join(HERE, variant + ".icns"),
                    append_images=[imgs[s] for s in (16, 32, 64, 128, 256, 512)])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--chrome")
    a = ap.parse_args()
    chrome = find_chrome(a.chrome)
    tmp = tempfile.mkdtemp(prefix="ow-icons-")
    try:
        make(chrome, "openworlds", os.path.join(REPO, "launcher", "resources", "net", "openworlds", "launcher", "icon.png"), tmp)
        make(chrome, "solar", os.path.join(REPO, "server", "resources", "net", "openworlds", "solar", "icon.png"), tmp)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    print("make_icons: openworlds.* and solar.* (svg, -small.svg, png, ico, icns) and both window icons")


if __name__ == "__main__":
    main()
