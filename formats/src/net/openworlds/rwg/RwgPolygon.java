package net.openworlds.rwg;

/**
 * A PLST record as read by RWL21.DLL's RwReadStreamChunk(PLST)
 * (0x1003a6d9):
 *
 * <pre>
 *  always       material (1-based index into the MALT list; 0 or out of
 *               range = no material), number of vertices n
 *  always       n 1-based indices (counting from RW's vertex 1, i.e.
 *               VLST record 8)
 *  flag 1       face normal (3 reals)                -> polygon +0x10..
 *  flag 4       3 reals in 16.16 (x 65536)           -> polygon +0x04..+0x0c
 *  flag 0x10    tag (integer; stored in 16 bits)     -> polygon +0x38
 * </pre>
 *
 * The first field, which used to be read as "id/flag", is the material
 * index: in ball.rwg it counts 1..512 because that file carries 512
 * materials in MALT, one per triangle.
 */
public final class RwgPolygon {
   /** 1-based index into {@link RwgModel#materials}; 0 = no material. */
   public final int materialIndex;
   /** 0-based indices into {@link RwgAtom#vertices} (the file carries them 1-based). */
   public final int[] vertexIndices;
   /** Face normal (flag 1), or null. */
   private final float[] normal;
   /**
    * ⚠️ VERIFY: the 3 reals of flag 4 (polygon +0x04..+0x0c in
    * 16.16); no RWL21 function reviewed names them. In the corpus
    * they are always 0.
    */
   public final float[] extra;
   /** Polygon tag (flag 0x10), truncated to 16 bits as at +0x38; 0 without the flag. */
   public final short tag;

   public RwgPolygon(int materialIndex, int[] vertexIndices, float[] normal, float[] extra, short tag) {
      this.materialIndex = materialIndex;
      this.vertexIndices = vertexIndices;
      this.normal = normal;
      this.extra = extra;
      this.tag = tag;
   }

   /** Stored face normal (flag 1 of PLST's STRT), or null if the file does not carry it. */
   public float[] normal() {
      return this.normal == null ? null : this.normal.clone();
   }
}
