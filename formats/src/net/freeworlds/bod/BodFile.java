package net.freeworlds.bod;

import java.util.List;

/** Top-level parsed .bod: a version byte and a flat list of "part" root clumps. */
public final class BodFile {
    public int version;
    public List<BodClump> parts;
    public int byteLength;
    public int consumedThroughOffset; // should equal byteLength if the whole file was consumed
}
