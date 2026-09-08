#!/usr/bin/env python3
"""Minimal PE32 export-table parser (no external deps).
Reads IMAGE_EXPORT_DIRECTORY and prints exported symbol names.
"""
import struct
import sys


def rva_to_offset(sections, rva):
    for va, vsize, praw, sraw in sections:
        if va <= rva < va + max(vsize, sraw):
            return praw + (rva - va)
    return None


def parse_exports(path):
    with open(path, "rb") as f:
        data = f.read()

    if data[0:2] != b"MZ":
        raise ValueError("not MZ")
    e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
    if data[e_lfanew:e_lfanew + 4] != b"PE\0\0":
        raise ValueError("not PE")

    coff_off = e_lfanew + 4
    machine, nsections = struct.unpack_from("<HH", data, coff_off)
    opt_hdr_size = struct.unpack_from("<H", data, coff_off + 16)[0]
    opt_hdr_off = coff_off + 20
    magic = struct.unpack_from("<H", data, opt_hdr_off)[0]
    is_pe32plus = magic == 0x20B

    if is_pe32plus:
        data_dir_off = opt_hdr_off + 112
    else:
        data_dir_off = opt_hdr_off + 96

    export_rva, export_size = struct.unpack_from("<II", data, data_dir_off)

    sec_off = opt_hdr_off + opt_hdr_size
    sections = []
    for i in range(nsections):
        base = sec_off + i * 40
        name = data[base:base + 8].rstrip(b"\0").decode(errors="replace")
        vsize, va, sraw, praw = struct.unpack_from("<IIII", data, base + 8)
        sections.append((va, vsize, praw, sraw))

    if export_rva == 0:
        return [], sections

    off = rva_to_offset(sections, export_rva)
    if off is None:
        return [], sections

    (characteristics, timestamp, majorv, minorv, name_rva, base_ord,
     num_funcs, num_names, addr_funcs_rva, addr_names_rva,
     addr_ordinals_rva) = struct.unpack_from("<IIHHIIIIIII", data, off)

    names_off = rva_to_offset(sections, addr_names_rva)
    names = []
    for i in range(num_names):
        name_ptr_rva = struct.unpack_from("<I", data, names_off + i * 4)[0]
        s_off = rva_to_offset(sections, name_ptr_rva)
        end = data.index(b"\0", s_off)
        names.append(data[s_off:end].decode(errors="replace"))
    return sorted(names), sections


if __name__ == "__main__":
    for path in sys.argv[1:]:
        try:
            names, sections = parse_exports(path)
        except Exception as e:
            print(f"{path}: ERROR {e}")
            continue
        print(f"=== {path} ({len(names)} exports) ===")
        for n in names:
            print(n)
