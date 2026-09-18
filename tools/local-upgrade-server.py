#!/usr/bin/env python3
"""Servidor local que sustituye a http://us1.worlds.net/3DCDup (ya inexistente).

El cliente original construye las URL de avatares, scripts de mundo, tablas,
etc. a partir de `upgradeServer` en worlds.ini. Este servidor sirve ficheros
de una carpeta raiz (por defecto assets/WorldsPlayer) bajo /3DCDup/ y responde
404 al instante a lo que no existe, en vez de esperar a un host muerto.

Uso: tools/local-upgrade-server.py [--port N] [--root DIR]
     (--port 0 elige uno libre; imprime "PORT=<n>" en la primera linea)
"""
import argparse
import functools
import http.server
import os
import sys

PREFIX = "/3DCDup/"


class Handler(http.server.SimpleHTTPRequestHandler):
    def translate_path(self, path):
        path = path.split("?", 1)[0].split("#", 1)[0]
        if not path.startswith(PREFIX):
            return os.path.join(self.directory, "\0nonexistent")
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
    a = ap.parse_args()
    handler = functools.partial(Handler, directory=os.path.abspath(a.root))
    srv = http.server.ThreadingHTTPServer(("127.0.0.1", a.port), handler)
    print("PORT=%d" % srv.server_address[1], flush=True)
    srv.serve_forever()


if __name__ == "__main__":
    main()
