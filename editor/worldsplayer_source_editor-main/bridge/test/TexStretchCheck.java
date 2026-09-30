package NET.worlds.core;

/**
 * FUN_004222b0 with a 16-bit screen: StretchBlt in mode 3 (COLORONCOLOR)
 * of the image to 128x128 and conversion to 5-6-5, and the palette of
 * FUN_00422b30. Hand-calculated cases. Exits with 1 if anything fails.
 */
public final class TexStretchCheck {
   private static int failures = 0;

   public static void main(String[] args) {
      // source pixel of each destination: d * s / 128, rounded down
      eq("4->128 d=0", NativeTextures.gdiSourceIndex(0, 128, 4), 0);
      eq("4->128 d=31", NativeTextures.gdiSourceIndex(31, 128, 4), 0);
      eq("4->128 d=32", NativeTextures.gdiSourceIndex(32, 128, 4), 1);
      eq("4->128 d=127", NativeTextures.gdiSourceIndex(127, 128, 4), 3);
      eq("118->128 d=64", NativeTextures.gdiSourceIndex(64, 128, 118), 59); // 7552/128 = 59
      eq("118->128 d=127", NativeTextures.gdiSourceIndex(127, 128, 118), 117); // 14986/128 = 117.07
      eq("154->128 d=1", NativeTextures.gdiSourceIndex(1, 128, 154), 1); // 1.2
      eq("154->128 d=127", NativeTextures.gdiSourceIndex(127, 128, 154), 152); // 19558/128 = 152.8
      eq("128->128 identity", NativeTextures.gdiSourceIndex(77, 128, 128), 77);

      // truncated 565: white, red, the palette's (8,8,8) and the key black
      eq("565 white", NativeTextures.gdiTo565(0xFFFFFF) & 0xFFFF, 0xFFFF);
      eq("565 red", NativeTextures.gdiTo565(0xFF0000) & 0xFFFF, 0xF800);
      eq("565 (8,8,8)", NativeTextures.gdiTo565(0x080808) & 0xFFFF, 0x0841); // 1<<11 | 2<<5 | 1
      eq("565 (7,3,7) falls to 0", NativeTextures.gdiTo565(0x070307) & 0xFFFF, 0);

      // 2x1 [red, blue] -> columns 0..63 red, 64..127 blue, on all rows;
      // COLORONCOLOR does not blend: no intermediate texel
      short[] t = NativeTextures.gdiStretchToTexture(new int[]{0xFF0000, 0x0000FF}, 2, 1);
      eq("2x1 (0,0)", t[0] & 0xFFFF, 0xF800);
      eq("2x1 (63,0)", t[63] & 0xFFFF, 0xF800);
      eq("2x1 (64,0)", t[64] & 0xFFFF, 0x001F);
      eq("2x1 (127,127)", t[127 * 128 + 127] & 0xFFFF, 0x001F);
      eq("2x1 (0,127)", t[127 * 128] & 0xFFFF, 0xF800);
      int other = 0;
      for (short s : t) {
         if ((s & 0xFFFF) != 0xF800 && (s & 0xFFFF) != 0x001F) {
            other++;
         }
      }
      eq("2x1 without blended colors", other, 0);

      // 3x3 with the key black in the center: rows/columns 43..85 are
      // source 1 (43*3/128 = 1.007, 85*3/128 = 1.99) -> 43x43 texels at 0
      int[] img = new int[9];
      java.util.Arrays.fill(img, 0xFFFFFF);
      img[4] = 0;
      t = NativeTextures.gdiStretchToTexture(img, 3, 3);
      int zeros = 0;
      for (short s : t) {
         if (s == 0) {
            zeros++;
         }
      }
      eq("3x3 transparent texels", zeros, 43 * 43);
      eq("3x3 (42,42) white", t[42 * 128 + 42] & 0xFFFF, 0xFFFF);
      eq("3x3 (43,43) key", t[43 * 128 + 43] & 0xFFFF, 0);

      // how much another phase of the DDA (pixel center) would move at the two
      // real sizes of GroundZero (informational)
      System.out.println("columns that change with the phase at the center: 118->128 " + phaseDiff(118)
         + ", 100->128 " + phaseDiff(100) + ", 154->128 " + phaseDiff(154));

      if (failures > 0) {
         System.out.println("TexStretchCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("TexStretchCheck: OK");
   }

   private static int phaseDiff(int s) {
      int n = 0;
      for (int d = 0; d < 128; d++) {
         if (NativeTextures.gdiSourceIndex(d, 128, s) != (int) ((2L * d + 1) * s / 256)) {
            n++;
         }
      }
      return n;
   }

   private static void eq(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FAIL " + what + ": " + got + " (expected " + want + ")");
      }
   }
}
