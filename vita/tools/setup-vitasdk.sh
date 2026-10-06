#!/bin/bash
# Builds VitaSDK (the PSVita toolchain: arm-vita-eabi GCC, newlib, the
# system stubs, vita-elf-create, vita-pack-vpk...) from vitasdk/buildscripts
# at a pinned commit, with vita/tools/vitasdk-buildscripts.patch: zlib and
# libelf also from mirrors outside GitHub's release downloads, and an option
# to leave gdb out (it is not needed to build, and its expat comes only from
# GitHub releases).
#
#   vita/tools/setup-vitasdk.sh          # installs into $VITASDK, or ~/vitasdk
#
# Needs cmake, git, make, a C/C++ compiler, autoconf, automake, libtool,
# texinfo, bison and flex (Debian/Ubuntu: apt-get install cmake git
# build-essential autoconf automake libtool libtool-bin texinfo bison flex).
# Takes 20 to 60 minutes. Afterwards: export VITASDK=<prefix>.
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
PREFIX="${VITASDK:-$HOME/vitasdk}"
WORK="${OPENWORLDS_VITASDK_WORK:-$REPO/build/vita/vitasdk-build}"
URL=https://github.com/vitasdk/buildscripts
COMMIT=3c0b9c7b2c8ecb7bf68a674451a295f724b7fafb
JOBS="${JOBS:-$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)}"

say() { echo "[vitasdk] $*"; }

# Tarballs carry file names that need a UTF-8 locale to extract
export LANG=C.UTF-8 LC_ALL=C.UTF-8

SRC="$WORK/buildscripts"
mkdir -p "$WORK"
if [ ! -d "$SRC/.git" ]; then
   git init -q "$SRC"
   git -C "$SRC" remote add origin "$URL"
fi
git -C "$SRC" fetch -q --depth 1 origin "$COMMIT"
git -C "$SRC" checkout -q -f "$COMMIT"
git -C "$SRC" apply "$HERE/vitasdk-buildscripts.patch"
say "buildscripts at $COMMIT, building into $PREFIX with $JOBS jobs"

mkdir -p "$WORK/build"
cd "$WORK/build"
cmake "$SRC" -DVITASDK_NO_GDB=ON -DCMAKE_INSTALL_PREFIX="$PREFIX" > "$WORK/cmake.log"
make -j"$JOBS" > "$WORK/make.log" 2>&1 || { tail -40 "$WORK/make.log"; exit 1; }
# The target libraries (libgcc, libstdc++) and the checks are a target of their own
make -j"$JOBS" finalize-sdk > "$WORK/finalize.log" 2>&1 || { tail -40 "$WORK/finalize.log"; exit 1; }
say "done: export VITASDK=$PREFIX"
