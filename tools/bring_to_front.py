#!/usr/bin/env python3
"""Bring an X11 window to the current desktop and focus it, via raw X
protocol (no xlib/xdotool needed). Usage: activate.py <window-id-hex>."""
import os
import socket
import struct
import sys


def read_cookie():
    path = os.environ.get("XAUTHORITY", os.path.expanduser("~/.Xauthority"))
    with open(path, "rb") as f:
        data = f.read()
    # .Xauthority record: family:2 addrlen:2 addr numberlen:2 number
    # namelen:2 name datalen:2 data (all BE)
    off = 0
    while off + 6 <= len(data):
        fam, alen = struct.unpack(">HH", data[off:off + 4])
        off += 4
        addr = data[off:off + alen]
        off += alen
        nlen = struct.unpack(">H", data[off:off + 2])[0]
        off += 2
        num = data[off:off + nlen]
        off += nlen
        nmlen = struct.unpack(">H", data[off:off + 2])[0]
        off += 2
        name = data[off:off + nmlen]
        off += nmlen
        dlen = struct.unpack(">H", data[off:off + 2])[0]
        off += 2
        d = data[off:off + dlen]
        off += dlen
        if num in (b"0", b"") and name == b"MIT-MAGIC-COOKIE-1":
            return name, d
    raise RuntimeError("no :0 MIT cookie in %s" % path)


class X:
    def __init__(self, disp=":0"):
        n = disp.split(":")[1].split(".")[0]
        self.s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        self.s.connect("/tmp/.X11-unix/X%s" % n)
        self.seq = 0
        aname, adata = read_cookie()
        padn = (-len(aname)) % 4
        padd = (-len(adata)) % 4
        self.s.sendall(struct.pack("BBHHHHH", 0x6C, 0, 11, 0, len(aname), len(adata), 0)
                       + aname + b"\x00" * padn + adata + b"\x00" * padd)
        head = self.recvn(8)
        status, _, _, _, length = struct.unpack("BBHHH", head)
        if status != 1:
            raise RuntimeError("X setup failed, status=%d" % status)
        body = self.recvn(length * 4)
        vlen, nroots = struct.unpack("HHB", body[16:21])[0:1] + (0,)  # placeholder
        vlen = struct.unpack("H", body[16:18])[0]
        nroots = body[20]
        npix = body[21]
        off = 32 + ((vlen + 3) & ~3) + npix * 8
        self.root = struct.unpack("I", body[off:off + 4])[0]
        self.xid = struct.unpack("I", body[4:8])[0]  # rid_base

    def recvn(self, n):
        b = b""
        while len(b) < n:
            c = self.s.recv(n - len(b))
            if not c:
                raise RuntimeError("EOF from X server")
            b += c
        return b

    def intern(self, name):
        self.seq += 1
        nb = name.encode()
        pad = (-len(nb)) % 4
        req = struct.pack("BBH", 16, 0, 2 + (len(nb) + pad) // 4)
        req += struct.pack("H", len(nb)) + b"\x00\x00" + nb + b"\x00" * pad
        self.s.sendall(req)
        rep = self.recvn(32)
        return struct.unpack("I", rep[8:12])[0]

    def send_client(self, window, atom, d0, d1=0, d2=0):
        self.seq += 1
        ev = struct.pack("BBH", 33, 32, self.seq) + struct.pack("II", window, atom)
        ev += struct.pack("IIIII", d0, d1, d2, 0, 0)
        req = struct.pack("BBH", 25, 0, 11) + struct.pack("II", self.root, 0x120000) + ev
        self.s.sendall(req)

    def send_state(self, window, state_atom, action, prop_atom):
        # _NET_WM_STATE client message goes TO the window itself
        self.seq += 1
        ev = struct.pack("BBH", 33, 32, self.seq) + struct.pack("II", window, state_atom)
        ev += struct.pack("IIIII", action, prop_atom, 0, 1, 0)
        req = struct.pack("BBH", 25, 0, 11) + struct.pack("II", self.root, 0x120000) + ev
        self.s.sendall(req)


def find_by_title(x, disp, title, timeout_s=30.0):
    """Poll _NET_CLIENT_LIST for a window whose WM_NAME contains title."""
    import time as _t
    root = x.root
    deadline = _t.time() + timeout_s
    while _t.time() < deadline:
        ids = client_list(x)
        for wid in ids:
            if title in (wm_name(x, wid) or ""):
                return wid
        _t.sleep(0.5)
    return None


def get_prop(x, window, prop_name, max_items=64):
    """X_GetProperty (8-bit format assumed: strings/lists). Returns raw bytes."""
    import struct as _s
    atom = x.intern(prop_name)
    x.seq += 1
    x.s.sendall(_s.pack("BBH", 20, 0, 6) + _s.pack("IIIII", window, atom, 0, 0, max_items))
    rep = x.recvn(32)
    fmt = rep[1]
    n = _s.unpack("I", rep[16:20])[0]
    unit = fmt // 8
    raw = b""
    while len(raw) < n * unit:
        raw += x.s.recv(n * unit - len(raw))
    return raw


def client_list(x):
    import struct as _s
    raw = get_prop(x, x.root, "_NET_CLIENT_LIST")
    return list(_s.unpack("I" * (len(raw) // 4), raw))


def wm_name(x, wid):
    try:
        return get_prop(x, wid, "WM_NAME").rstrip(b"\x00").decode("latin1")
    except Exception:
        return None


def main():
    import os as _os
    disp = _os.environ.get("DISPLAY", ":0")
    if len(sys.argv) > 1 and not sys.argv[1].startswith("--"):
        win = int(sys.argv[1], 16)
    else:
        title = sys.argv[2] if len(sys.argv) > 2 else "FreeWorlds World Viewer"
        x0 = X(disp)
        win = find_by_title(x0, disp, title)
        if win is None:
            print("no window matching %r appeared" % title)
            sys.exit(1)
    x = X(disp)
    net_desktop = x.intern("_NET_WM_DESKTOP")
    net_active = x.intern("_NET_ACTIVE_WINDOW")
    net_state = x.intern("_NET_WM_STATE")
    net_hidden = x.intern("_NET_WM_STATE_HIDDEN")
    # unminimize first (action=0 remove HIDDEN), then desktop + focus
    x.send_state(win, net_state, 0, net_hidden)
    x.send_client(win, net_desktop, 1, 1)
    x.send_client(win, net_active, 1, 0, 0)
    print("sent unminimize + _NET_WM_DESKTOP=1 + _NET_ACTIVE_WINDOW to %#x" % win)


if __name__ == "__main__":
    main()
