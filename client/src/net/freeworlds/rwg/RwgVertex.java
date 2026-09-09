package net.freeworlds.rwg;

/**
 * One VLST vertex record (44 bytes / 11 big-endian floats). Only fields
 * [0..2] (position) and [6..7] (probable UV, medium confidence) are
 * interpreted with real evidence - see docs/rwg-bod-format-reference.md.
 * The remaining raw floats are kept verbatim (not discarded, not guessed)
 * so future sessions can re-derive their meaning against a richer corpus.
 */
public final class RwgVertex {
   public final float x;
   public final float y;
   public final float z;
   /** Per-vertex normal X - verified against a real 6-face cube (each face's 4 vertices share the same axis-aligned normal, matching the PLST-level face normal). */
   public final float normalX;
   public final float normalY;
   public final float normalZ;
   /** ⚠️ VERIFICAR - probable U texture coordinate (medium confidence, see docs). */
   public final float u;
   /** ⚠️ VERIFICAR - probable V texture coordinate (medium confidence, see docs). */
   public final float v;
   /** ⚠️ VERIFICAR - meaning unknown, kept raw (3 floats). */
   public final float unknown8;
   public final float unknown9;
   public final float unknown10;

   public RwgVertex(float x, float y, float z, float normalX, float normalY, float normalZ,
                     float u, float v, float unknown8, float unknown9, float unknown10) {
      this.x = x;
      this.y = y;
      this.z = z;
      this.normalX = normalX;
      this.normalY = normalY;
      this.normalZ = normalZ;
      this.u = u;
      this.v = v;
      this.unknown8 = unknown8;
      this.unknown9 = unknown9;
      this.unknown10 = unknown10;
   }
}
