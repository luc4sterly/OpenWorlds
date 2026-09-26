#!/usr/bin/env python3
"""Genera el icono de FreeWorlds: un planeta low-poly con anillo.

El planeta es una icosfera de 80 caras con sombreado plano, como el 3D de
RenderWare 2.1 (una luz, una cara un color), con continentes y un anillo que
pasa por detras y por delante. Salidas en tools/icons/:

- freeworlds.svg        el dibujo a 1024x1024 (con estrellas)
- freeworlds-small.svg  la variante para 16-32 px (sin estrellas, anillo mas grueso)
- freeworlds.png        1024x1024 (app de Linux, y fuente de las demas)
- freeworlds.ico        16, 24, 32, 48, 64, 128 y 256 (Windows)
- freeworlds.icns       16 a 1024 (macOS)
- launcher/resources/net/freeworlds/launcher/icon.png  256x256 (ventana del lanzador)

Uso: python3 tools/icons/make_icons.py [--chrome RUTA]
Necesita Pillow y un Chrome/Chromium sin interfaz para pasar el SVG a PNG a
1024 px (busca el de Playwright en /opt/pw-browsers, google-chrome, chromium
o el de macOS; --chrome o $CHROME para otro); los demas tamanos se reducen
de ahi.
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
TILE = (80, 80, 864, 864, 190)  # x, y, ancho, alto, radio de las esquinas


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


def planet_svg(small=False, size=W):
    cx, cy, R = 512, 512, 236 if not small else 250
    verts, faces = icosphere(1)
    verts = [rot(v, math.radians(-14), math.radians(28)) for v in verts]
    L = norm((-0.55, 0.62, 0.56))
    sea = ((30, 34, 118), (84, 214, 240))
    land = ((12, 56, 66), (150, 245, 196))
    polys = []
    for a, b, c in faces:
        pa, pb, pc = verts[a], verts[b], verts[c]
        u = (pb[0] - pa[0], pb[1] - pa[1], pb[2] - pa[2])
        w = (pc[0] - pa[0], pc[1] - pa[1], pc[2] - pa[2])
        n = norm((u[1] * w[2] - u[2] * w[1], u[2] * w[0] - u[0] * w[2], u[0] * w[1] - u[1] * w[0]))
        cen = ((pa[0] + pb[0] + pc[0]) / 3, (pa[1] + pb[1] + pc[1]) / 3, (pa[2] + pb[2] + pc[2]) / 3)
        if sum(n[i] * cen[i] for i in range(3)) < 0:
            n = (-n[0], -n[1], -n[2])
        if n[2] <= 0.02:
            continue
        d = max(0.0, sum(n[i] * L[i] for i in range(3)))
        k = 0.3 + 0.7 * d ** 1.05
        is_land = (math.sin(4.1 * cen[0] + 1.3) + math.sin(3.3 * cen[1] + 0.4) + math.cos(5.2 * cen[2] - 0.9)) > 1.05
        col = hexc(lerp(*(land if is_land else sea), k))
        pts = " ".join("%.1f,%.1f" % (cx + R * p[0], cy - R * p[1]) for p in (pa, pb, pc))
        polys.append((cen[2], '<polygon points="%s" fill="%s" stroke="%s" stroke-width="1.5" stroke-linejoin="round"/>' % (pts, col, col)))
    polys.sort()
    rx, ry, rw = (372, 96, 30) if not small else (392, 104, 46)
    big = 2000
    ring = '<ellipse cx="%d" cy="%d" rx="%d" ry="%d" fill="none" stroke="url(#ring)" stroke-width="%d"/>' % (cx, cy, rx, ry, rw)
    x, y, w, h, r = TILE
    defs = ('<clipPath id="tile"><rect x="%d" y="%d" width="%d" height="%d" rx="%d"/></clipPath>' % (x, y, w, h, r) +
            '<clipPath id="back"><rect x="%d" y="%d" width="%d" height="%d"/></clipPath>' % (cx - big, cy - big, 2 * big, big) +
            '<clipPath id="front"><rect x="%d" y="%d" width="%d" height="%d"/></clipPath>' % (cx - big, cy, 2 * big, big) +
            '<linearGradient id="bg" x1="0" y1="0" x2="1" y2="1"><stop offset="0" stop-color="#2d1d72"/><stop offset="1" stop-color="#0a0724"/></linearGradient>'
            '<radialGradient id="glow"><stop offset="0" stop-color="#4fd6ff" stop-opacity="0.45"/><stop offset="1" stop-color="#4fd6ff" stop-opacity="0"/></radialGradient>'
            '<linearGradient id="ring" x1="0" y1="0" x2="1" y2="0"><stop offset="0" stop-color="#ff5e62"/><stop offset="0.55" stop-color="#ff9f43"/><stop offset="1" stop-color="#ffd166"/></linearGradient>')
    sky = "" if small else stars(7, 26, [(cx, cy, R + 60)]) + sparkle(250, 230, 26) + sparkle(790, 800, 18, op=0.8)
    body = ('<rect x="%d" y="%d" width="%d" height="%d" rx="%d" fill="url(#bg)"/>' % (x, y, w, h, r) +
            '<g clip-path="url(#tile)">' + sky +
            '<circle cx="%d" cy="%d" r="%d" fill="url(#glow)"/>' % (cx, cy, R + 150) +
            '<g transform="rotate(-17 %d %d)"><g clip-path="url(#back)">%s</g></g>' % (cx, cy, ring) +
            "".join(p for _, p in polys) +
            '<g transform="rotate(-17 %d %d)"><g clip-path="url(#front)">%s</g></g>' % (cx, cy, ring) + "</g>")
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
    sys.exit("make_icons: no encuentro Chrome/Chromium (--chrome RUTA)")


def render(chrome, svg_text, size, out_png, tmp):
    src = os.path.join(tmp, "icon-%d.svg" % size)
    with open(src, "w") as f:
        f.write(svg_text)
    subprocess.run([chrome, "--headless=new", "--no-sandbox", "--disable-gpu", "--hide-scrollbars",
                    "--disable-background-networking", "--default-background-color=00000000",
                    "--window-size=%d,%d" % (size, size), "--screenshot=" + out_png, "file://" + src],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, timeout=120)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--chrome")
    a = ap.parse_args()
    from PIL import Image
    chrome = find_chrome(a.chrome)
    with open(os.path.join(HERE, "freeworlds.svg"), "w") as f:
        f.write(planet_svg())
    with open(os.path.join(HERE, "freeworlds-small.svg"), "w") as f:
        f.write(planet_svg(small=True))
    tmp = tempfile.mkdtemp(prefix="fw-icons-")
    try:
        # Chrome sin interfaz recorta las ventanas pequenas (un 128x128 sale
        # a medias): se dibuja todo a 1024 y se reduce con Lanczos. 16-32 px
        # salen de la variante sin estrellas y con el anillo mas grueso.
        big = os.path.join(tmp, "big.png")
        small = os.path.join(tmp, "small.png")
        render(chrome, planet_svg(), W, big, tmp)
        render(chrome, planet_svg(small=True), W, small, tmp)
        big_im = Image.open(big).convert("RGBA")
        small_im = Image.open(small).convert("RGBA")
        imgs = {}
        for s in (16, 24, 32):
            imgs[s] = small_im.resize((s, s), Image.LANCZOS)
        for s in (48, 64, 128, 256, 512):
            imgs[s] = big_im.resize((s, s), Image.LANCZOS)
        imgs[1024] = big_im
        imgs[1024].save(os.path.join(HERE, "freeworlds.png"), optimize=True)
        imgs[256].save(os.path.join(REPO, "launcher", "resources", "net", "freeworlds", "launcher", "icon.png"), optimize=True)
        ico_sizes = [16, 24, 32, 48, 64, 128, 256]
        imgs[256].save(os.path.join(HERE, "freeworlds.ico"), sizes=[(s, s) for s in ico_sizes],
                       append_images=[imgs[s] for s in ico_sizes if s != 256])
        imgs[1024].save(os.path.join(HERE, "freeworlds.icns"),
                        append_images=[imgs[s] for s in (16, 32, 64, 128, 256, 512)])
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    print("make_icons: freeworlds.svg/-small.svg/.png/.ico/.icns y el icono del lanzador")


if __name__ == "__main__":
    main()
