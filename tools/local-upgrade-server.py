#!/usr/bin/env python3
"""Local upgrade server for the original client (diagnostics).

The original client builds the URLs of avatars, world scripts, tables,
world packages, etc. from `upgradeServer` in worlds.ini
(http://us1.worlds.net/3DCDup). This server serves files from a root folder
(assets/WorldsPlayer by default) under /3DCDup/ and answers 404 at once for
whatever does not exist, instead of waiting on a dead host. It also serves
under /3DCDup/avatar/ the official base avatars from
assets/gammatutorial-samples/base-avatars (AVATARS.ZIP from the 2002
installer), looking them up case-insensitively (the client asks for
pengo.mov and the file is PENGO.mov, as on Windows).

With --mirror URL, whatever is not available locally is requested from that
mirror and stored in --cache (us1.worlds.net answers again: it is the
LibreWorlds mirror, with the world packages and the avatar wardrobe). This is
the Python version of the launcher's UpgradeServer; run_gamma.sh uses it.

Usage: tools/local-upgrade-server.py [--port N] [--root DIR] [--mirror URL [--cache DIR]]
       (--port 0 picks a free one; prints "PORT=<n>" on the first line)
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
    """File in `directory` whose name matches `name`, ignoring case."""
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
    """Whatever is missing locally, requested from the mirror and cached (like UpgradeServer)."""

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
                                         headers={"User-Agent": "OpenWorlds-diagnostic"})
            try:
                with urllib.request.urlopen(req, timeout=30) as r:
                    data = r.read()
            except (urllib.error.URLError, OSError) as e:
                code = getattr(e, "code", e)
                sys.stderr.write("[upgrade-server] mirror %s %s\n" % (code, rel))
                with self.guard:
                    self.missing.add(rel)
                return None
            os.makedirs(os.path.dirname(dest), exist_ok=True)
            with open(dest + ".part", "wb") as f:
                f.write(data)
            os.replace(dest + ".part", dest)
            sys.stderr.write("[upgrade-server] mirror: %s (%d bytes)\n" % (rel, len(data)))
            return dest


class Handler(http.server.SimpleHTTPRequestHandler):
    avatar_dir = None
    mirror = None

    def translate_path(self, path):
        path = urllib.parse.unquote(path.split("?", 1)[0].split("#", 1)[0])
        # a path that does not exist: send_head answers 404 (a name with a NUL
        # made open() raise ValueError and the response came out empty)
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
    ap.add_argument("--mirror", default=None, help="mirror for whatever is missing (e.g. http://us1.worlds.net/3DCDup)")
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
