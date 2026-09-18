#!/usr/bin/env python3
"""Servidor local que sustituye a http://us1.worlds.net/3DCDup (ya inexistente).

El cliente original construye las URL de avatares, scripts de mundo, tablas,
etc. a partir de `upgradeServer` en worlds.ini. Este servidor sirve ficheros
de una carpeta raiz (por defecto assets/WorldsPlayer) bajo /3DCDup/ y responde
404 al instante a lo que no existe, en vez de esperar a un host muerto.
Ademas sirve bajo /3DCDup/avatar/ los avatares base oficiales de
assets/gammatutorial-samples/base-avatars (AVATARS.ZIP del instalador 2002),
buscando sin distinguir mayusculas (el cliente pide pengo.mov y el fichero es
PENGO.mov, como en Windows).

Uso: tools/local-upgrade-server.py [--port N] [--root DIR]
     (--port 0 elige uno libre; imprime "PORT=<n>" en la primera linea)
"""
import argparse
import functools
import http.server
import os
import sys
import urllib.parse

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


class Handler(http.server.SimpleHTTPRequestHandler):
    avatar_dir = None

    def translate_path(self, path):
        path = urllib.parse.unquote(path.split("?", 1)[0].split("#", 1)[0])
        missing = os.path.join(self.directory, "\0nonexistent")
        if not path.startswith(PREFIX):
            return missing
        if path.startswith(AVATAR_PREFIX) and self.avatar_dir:
            hit = find_nocase(self.avatar_dir, path[len(AVATAR_PREFIX):])
            if hit:
                return hit
        return super().translate_path("/" + path[len(PREFIX):])

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
    a = ap.parse_args()
    Handler.avatar_dir = os.path.abspath(a.avatars) if os.path.isdir(a.avatars) else None
    handler = functools.partial(Handler, directory=os.path.abspath(a.root))
    srv = http.server.ThreadingHTTPServer(("127.0.0.1", a.port), handler)
    print("PORT=%d" % srv.server_address[1], flush=True)
    srv.serve_forever()


if __name__ == "__main__":
    main()
