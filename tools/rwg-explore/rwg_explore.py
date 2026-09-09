#!/usr/bin/env python3
"""Exploratory chunk-tree walker for .rwg/.bod files: [4-byte ASCII tag]
[4-byte big-endian length=payload size][payload], nested. Prints the
tag/length structure at every level so we can verify against real bytes.
"""
import struct
import sys


def is_ascii_tag(b):
    return all(65 <= c <= 90 for c in b)  # uppercase A-Z only


def dump(data, offset, end, depth, out):
    while offset + 8 <= end:
        tag = data[offset:offset + 4]
        if not is_ascii_tag(tag):
            out.append("  " * depth + f"[0x{offset:04x}] non-tag bytes, stopping: {data[offset:offset+16].hex()}")
            return offset
        length = struct.unpack(">I", data[offset + 4:offset + 8])[0]
        payload_start = offset + 8
        payload_end = payload_start + length
        out.append("  " * depth + f"[0x{offset:04x}] {tag.decode()} len=0x{length:x} "
                    f"payload=[0x{payload_start:04x}:0x{payload_end:04x}] ({length} bytes)")
        if payload_end > end or length < 0:
            out.append("  " * depth + f"  !! payload_end 0x{payload_end:x} exceeds bound 0x{end:x}")
            return offset
        if length >= 8 and is_ascii_tag(data[payload_start:payload_start + 4]):
            dump(data, payload_start, payload_end, depth + 1, out)
        else:
            preview = data[payload_start:min(payload_start + 64, payload_end)]
            out.append("  " * depth + f"    data ({len(data[payload_start:payload_end])}B): {preview.hex()}")
        offset = payload_end
    return offset


if __name__ == "__main__":
    path = sys.argv[1]
    data = open(path, "rb").read()
    print(f"file size: {len(data)} bytes")
    start = 8
    while start + 4 <= len(data) and not is_ascii_tag(data[start:start + 4]):
        start += 1
    print(f"first tag at 0x{start:04x}: header(8..{start})={data[8:start].hex()}")
    out = []
    dump(data, start, len(data), 0, out)
    print("\n".join(out))
