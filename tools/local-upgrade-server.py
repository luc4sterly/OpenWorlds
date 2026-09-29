#!/usr/bin/env python3
"""Servidor local de actualizaciones para el cliente original (diagnostico).

El cliente original construye las URL de avatares, scripts de mundo, tablas,
paquetes de mundo, etc. a partir de `upgradeServer` en worlds.ini
(http://us1.worlds.net/3DCDup). Este servidor sirve ficheros de una carpeta
raiz (por defecto assets/WorldsPlayer) bajo /3DCDup/ y responde 404 al
instante a lo que no existe, en vez de esperar a un host muerto. Ademas sirve
bajo /3DCDup/avatar/ los avatares base oficiales de
assets/gammatutorial-samples/base-avatars (AVATARS.ZIP del instalador 2002),
buscando sin distinguir mayusculas (el cliente pide pengo.mov y el fichero es
PENGO.mov, como en Windows).

Con --mirror URL, lo que no hay en local se pide a ese espejo y se guarda en
--cache (us1.worlds.net vuelve a responder: es el espejo de LibreWorlds, con
los paquetes de mundo y el vestuario de avatares). Es la version Python de
UpgradeServer del lanzador; run_gamma.sh la usa.

Uso: tools/local-upgrade-server.py [--port N] [--root DIR] [--mirror URL [--cache DIR]]
     (--port 0 elige uno libre; imprime "PORT=<n>" en la primera linea)
"""
import argparse
import functools
import http.server
import os
import posixpath
import sys
import threading
import urllib.error
import urllib.parse
import urllib.request

PREFIX = "/3DCDup/"
AVATAR_PREFIX = PREFIX + "avatar/"


def find_nocase(directory, name):
    """Fichero de `directory` cuyo nombre coincide con `name` sin mayusculas."""
    if "/" in name or "\\" in name or name in ("", ".", ".."):
        return None
    want = name.lower()
    try:
        for f in os.listdir(directory):
            if f.lower() == want:
                return os.path.join(directory, f)
    except OSError:
        pass
    return None


class Mirror:
    """Lo que falta en local, pedido al espejo y guardado en cache (como UpgradeServer)."""

    def __init__(self, url, cache):
        self.url = url.rstrip("/") + "/"
        self.cache = os.path.abspath(cache)
        self.missing = set()
        self.locks = {}
        self.guard = threading.Lock()

    def get(self, rel):
        rel = posixpath.normpath(rel)
        if rel.startswith("..") or rel.startswith("/") or rel in (".", ""):
            return None
        dest = os.path.join(self.cache, *rel.split("/"))
        with self.guard:
            if rel in self.missing:
                return None
            lock = self.locks.setdefault(rel, threading.Lock())
        with lock:
            if os.path.isfile(dest):
                return dest
            req = urllib.request.Request(self.url + urllib.parse.quote(rel),
                                         headers={"User-Agent": "OpenWorlds-diagnostico"})
            try:
                with urllib.request.urlopen(req, timeout=30) as r:
                    data = r.read()
            except (urllib.error.URLError, OSError) as e:
                code = getattr(e, "code", e)
                sys.stderr.write("[upgrade-server] espejo %s %s\n" % (code, rel))
                with self.guard:
                    self.missing.add(rel)
                return None
            os.makedirs(os.path.dirname(dest), exist_ok=True)
            with open(dest + ".part", "wb") as f:
                f.write(data)
            os.replace(dest + ".part", dest)
            sys.stderr.write("[upgrade-server] espejo: %s (%d bytes)\n" % (rel, len(data)))
            return dest


class Handler(http.server.SimpleHTTPRequestHandler):
    avatar_dir = None
    mirror = None

    def translate_path(self, path):
        path = urllib.parse.unquote(path.split("?", 1)[0].split("#", 1)[0])
        # una ruta que no existe: send_head responde 404 (un nombre con NUL
        # hacia que open() lanzara ValueError y la respuesta saliera vacia)
        missing = os.path.join(self.directory, ".no-such-dir", "none")
        if not path.startswith(PREFIX):
            return missing
        if path.startswith(AVATAR_PREFIX) and self.avatar_dir:
            hit = find_nocase(self.avatar_dir, path[len(AVATAR_PREFIX):])
            if hit:
                return hit
        local = super().translate_path("/" + path[len(PREFIX):])
        if self.mirror and not os.path.exists(local):
            hit = self.mirror.get(path[len(PREFIX):])
            if hit:
                return hit
        return local

    def list_directory(self, path):
        self.send_error(404)
        return None

    def log_message(self, fmt, *args):
        sys.stderr.write("[upgrade-server] %s\n" % (fmt % args))


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", type=int, default=0)
    ap.add_argument("--root", default=os.path.join(here, "..", "assets", "WorldsPlayer"))
    ap.add_argument("--avatars", default=os.path.join(here, "..", "assets", "gammatutorial-samples", "base-avatars"))
    ap.add_argument("--mirror", default=None, help="espejo para lo que falte (p. ej. http://us1.worlds.net/3DCDup)")
    ap.add_argument("--cache", default=os.path.join(here, "..", "build", "mirror-cache"))
    a = ap.parse_args()
    Handler.avatar_dir = os.path.abspath(a.avatars) if os.path.isdir(a.avatars) else None
    Handler.mirror = Mirror(a.mirror, a.cache) if a.mirror else None
    handler = functools.partial(Handler, directory=os.path.abspath(a.root))
    srv = http.server.ThreadingHTTPServer(("127.0.0.1", a.port), handler)
    print("PORT=%d" % srv.server_address[1], flush=True)
    srv.serve_forever()


if __name__ == "__main__":
    main()
