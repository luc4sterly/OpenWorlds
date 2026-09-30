import NET.worlds.core.NativeCamera;

/**
 * Reciprocal table (RWDL6D21 DAT_10079214, 0x1000a008), edge slopes
 * and textured spans of 0x1002cbb0 (perspective division every
 * 16 pixels, packed u/v) in the bridge. Hand-calculated cases.
 */
public final class RasterSpanCheck {
   private static int failures;

   private static void expect(String what, boolean ok) {
      if (!ok) {
         System.out.println("FAIL " + what);
         failures++;
      }
   }

   private static int texU(int pk) {
      return pk >>> 25;
   }

   public static void main(String[] args) {
      // Table: (dx << 16) / dy truncating toward zero.
      expect("slope(5,3) = 109226", NativeCamera.slope(5, 3) == 109226);
      expect("slope(-5,3) = -109226", NativeCamera.slope(-5, 3) == -109226);
      expect("slope(31,31) = 65536", NativeCamera.slope(31, 31) == 65536);
      expect("slope(-32,1) = -32<<16", NativeCamera.slope(-32, 1) == -0x200000);
      expect("slope(7,2) = 7*0x8000", NativeCamera.slope(7, 2) == 229376);
      // outside the table (|dx| >= 32 or dy >= 32): idiv
      expect("slope(100,7) = 936228", NativeCamera.slope(100, 7) == 936228);
      expect("slope(3,40) = 4915", NativeCamera.slope(3, 40) == 4915);
      // the table gives the same as the division over its whole domain
      boolean same = true;
      for (int dx = -31; dx < 32; dx++) {
         for (int dy = 3; dy < 32; dy++) {
            same &= NativeCamera.slope(dx, dy) == (dx << 16) / dy;
         }
      }
      expect("table == (dx<<16)/dy", same);

      // Short span (8 px), affine (q = 512 at both ends): u and v from 0
      // to 65536 (1.0 = 128 texels): step 65536 * 0.125 = 8192 -> texel 16*i.
      int[] s = NativeCamera.texSpan(512, 0, 0, 512, 65536, 65536, 8, null);
      boolean ok = true;
      for (int i = 0; i < 8; i++) {
         ok &= NativeCamera.texelIndex(s[i]) == (16 * i) * 128 + 16 * i;
      }
      expect("short span 8 px: texel (16i,16i)", ok);

      // Long affine span of 20 px, u from 0 to 40960: block of 16 with step
      // (32768 & ~15) << 12 -> 2048/px (texel 4i); tail of 4 px with
      // (32768 - 40960) / -4 = 2048.
      s = NativeCamera.texSpan(512, 0, 0, 512, 40960, 0, 20, null);
      expect("20 px affine: ends 0 and 76, middle 40", texU(s[0]) == 0 && texU(s[10]) == 40 && texU(s[19]) == 76);

      // Long span with perspective: q 512 -> 1024, uq 0 -> 81920 (u = 0 at
      // the left, 40960 at the right). Block: q = 921.6, uq = 65536,
      // u1 = ftol(65536 * 512/921.6) = 36408, step (36400 << 12) -> 2275/px:
      // texel 0, 35 (px 8), 66 (px 15). Tail: u0 = 36408 (texel 71), step
      // (36408 - 40960) / -4 = 1138 -> px 19 = 39822 (texel 77). Purely
      // linear would give texel 40 at px 8.
      s = NativeCamera.texSpan(512, 0, 0, 1024, 81920, 0, 20, null);
      expect("20 px with perspective: " + texU(s[0]) + "," + texU(s[8]) + "," + texU(s[15]) + "," + texU(s[16]) + "," + texU(s[19]),
         texU(s[0]) == 0 && texU(s[8]) == 35 && texU(s[15]) == 66 && texU(s[16]) == 71 && texU(s[19]) == 77);

      // Gouraud 0x1006a340: R and B integers, G + carry of (fraction + threshold).
      expect("gouraud without carry", NativeCamera.gouraudPixel(NativeCamera.packRG(10, 20), 5 << 8, 0x80) == 21765);
      expect("gouraud with carry", NativeCamera.gouraudPixel(NativeCamera.packRG(10, 20) | 0x90, 5 << 8, 0x80) == 21829);
      // G = 31 + carry overflows into R's low bit (11, G 0): 22533
      expect("gouraud overflow into R", NativeCamera.gouraudPixel(NativeCamera.packRG(10, 31) | 0xFF, 5 << 8, 0x01) == 22533);
      expect("pack(1,-1) = 65535", NativeCamera.pack(1, -1) == 65535);
      boolean seq = true;
      for (int i = 0; i < 7; i++) {
         int d = NativeCamera.DITHER_COLS[i];
         seq &= (d ^ d >>> 6) == NativeCamera.DITHER_COLS[i + 1];
      }
      expect("dither table x: each word = previous ^ (previous >>> 6)", seq);
      if (failures != 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("RasterSpanCheck OK");
   }
}
