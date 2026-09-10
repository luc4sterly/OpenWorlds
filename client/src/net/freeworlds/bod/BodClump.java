package net.freeworlds.bod;

import java.util.List;

/**
 * One clump (limb/part or sub-piece) in a .bod's recursive hierarchy. A
 * "part" (see the tag-name table in worlds-chat-project.md /
 * RWXTOBOD.PL's %tags) is a root clump directly listed in the file's part
 * table; every clump can have further child clumps, either real
 * sub-limbs, synthetic zero-tag material-split pieces, or placeholder
 * transform stubs re-attaching another part.
 */
public final class BodClump {
    public int tag;              // 0 = unnamed/synthetic (material split); see RWXTOBOD.PL %tags for real limb tags
    public boolean placeholder;  // true: only tx/ty/tz are meaningful, no geometry/children were even encoded
    public float tx, ty, tz;     // translation relative to parent

    // only meaningful when !placeholder:
    public int r, g, b;
    public List<BodVertex> vertices;
    public List<int[]> triangles; // each: 3 indices into `vertices`
    public List<BodClump> children;
}
