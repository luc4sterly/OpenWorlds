package net.openworlds.rwg;

/**
 * A VLST record as read by RWL21.DLL's RwReadStreamChunk(VLST)
 * (0x1003b328). The flags of VLST's STRT say which fields
 * each record carries, in this order:
 *
 * <pre>
 *  always       x, y, z (3 reals)                   -> vertex +0x0c..
 *  flag 1       normal (3 reals), mark 0x40          -> vertex +0x04.. (normal set)
 *  flag 2       u, v (2 reals) in 16.16 (x 65536)    -> vertex +0x1c/+0x20
 *  flag 4       3 reals in 16.16 (x 65536)           -> vertex +0x10/+0x14/+0x18
 * </pre>
 *
 * The factor 65536.0 is DAT_10052298 (a double read from the binary) and the
 * conversion to integer is __ftol (0x10044788). The fields that the record
 * does not carry are left at 0 here and {@link #hasNormal}/{@link #hasUv}/{@link #hasExtra}
 * say so.
 */
public final class RwgVertex {
   public final float x;
   public final float y;
   public final float z;
   public final boolean hasNormal;
   public final float normalX;
   public final float normalY;
   public final float normalZ;
   public final boolean hasUv;
   public final float u;
   public final float v;
   public final boolean hasExtra;
   /**
    * ⚠️ VERIFY: the 3 reals of flag 4 (vertex +0x10..+0x18, in
    * 16.16). No exported RWL21 function reviewed reads those fields
    * by name, and in the corpus they are always 0.
    */
   public final float unknown8;
   public final float unknown9;
   public final float unknown10;

   public RwgVertex(float x, float y, float z, boolean hasNormal, float normalX, float normalY, float normalZ,
                    boolean hasUv, float u, float v, boolean hasExtra, float unknown8, float unknown9, float unknown10) {
      this.x = x;
      this.y = y;
      this.z = z;
      this.hasNormal = hasNormal;
      this.normalX = normalX;
      this.normalY = normalY;
      this.normalZ = normalZ;
      this.hasUv = hasUv;
      this.u = u;
      this.v = v;
      this.hasExtra = hasExtra;
      this.unknown8 = unknown8;
      this.unknown9 = unknown9;
      this.unknown10 = unknown10;
   }

   /** RW stores the UV as 16.16 (__ftol truncates toward zero): the value the rasterizer sees. */
   public static int toFixed(float f) {
      return (int) (f * 65536.0);
   }
}
