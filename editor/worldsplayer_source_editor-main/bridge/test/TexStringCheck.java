package NET.worlds.core;

/**
 * StringTexture.makeStringTexture (gamma.dll 0x00424af0 / FUN_00424870):
 * size of the text DIB, 16-bit colors, "Kanji" face, and the resulting
 * texture: the text stretched to 128x128 by COLORONCOLOR, with only the two
 * colors (no antialiasing). Hand-calculated cases; the text width
 * depends on the glyphs (⚠️, see NativeTextures) and is only bounded. Exits
 * with 1 if anything fails.
 */
public final class TexStringCheck {
   private static int failures = 0;

   public static void main(String[] args) {
      System.setProperty("java.awt.headless", "true");

      // FUN_00424870: extent as is; if cx*cy > 0xfffff, cx = cy/2^20
      // (0 for any normal height) and then 0 -> 8x8
      int[] e = NativeTextures.stringExtent(100, 48);
      eq("extent 100x48", e[0], 100);
      eq("extent 100x48 height", e[1], 48);
      e = NativeTextures.stringExtent(21845, 48); // 1048560 <= 0xfffff
      eq("21845x48 fits", e[0], 21845);
      e = NativeTextures.stringExtent(21846, 48); // 1048608 > 0xfffff -> cx = 0 -> 8x8
      eq("21846x48 -> 8 wide", e[0], 8);
      eq("21846x48 -> 8 high", e[1], 8);
      e = NativeTextures.stringExtent(0, 48);
      eq("empty -> 8x8", e[0] * 1000 + e[1], 8008);

      // colors (COLORREF 0x00BBGGRR) after 0x424a53..0x424a77
      int[] c = NativeTextures.stringColors(0, 0xfefefe);
      eq("black text -> 080808", c[0], 0x080808);
      eq("background fefefe -> 0 (transparent)", c[1], 0);
      c = NativeTextures.stringColors(0xffffff, 0);
      eq("black background -> 080808", c[1], 0x080808);
      eq("Color.red -> COLORREF", NativeTextures.colorRef(java.awt.Color.red.getRGB()), 0x0000ff);
      eq("Color(1,2,3) -> COLORREF", NativeTextures.colorRef(new java.awt.Color(1, 2, 3).getRGB()), 0x030201);
      check("Kanji -> MS Gothic", "MS Gothic".equals(NativeTextures.stringFace("Kanji")));
      check("Arial -> Arial", "Arial".equals(NativeTextures.stringFace("Arial")));

      // NametagDrone: black on white, Arial 48 -> 128x128 with only 0x0841
      // (text) and 0xFFFF (background); row 127 comes from DIB row 47
      // (127*48/128 = 47.6), below the baseline of "HI": background
      int h = NativeTextures.makeStringTexture("HI".toCharArray(), 2, "Arial", 48,
         java.awt.Color.black.getRGB(), java.awt.Color.white.getRGB());
      NativeTextures.Texture t = NativeTextures.texture(h);
      check("texture created", t != null && t.pixels.length == 128 * 128);
      if (t != null) {
         int text = 0, back = 0, other = 0;
         for (short s : t.pixels) {
            int v = s & 0xFFFF;
            if (v == 0x0841) {
               text++;
            } else if (v == 0xFFFF) {
               back++;
            } else {
               other++;
            }
         }
         eq("only two colors", other, 0);
         check("there is text and background", text > 0 && back > text);
         for (int x = 0; x < 128; x++) {
            eq("row 127 background x=" + x, t.pixels[127 * 128 + x] & 0xFFFF, 0xFFFF);
         }
         check("outside the dictionary", t.name == null);
      }

      // Drone with background (254,254,254): the background is transparent texel 0
      h = NativeTextures.makeStringTexture("HI".toCharArray(), 2, "Arial", 48,
         java.awt.Color.black.getRGB(), new java.awt.Color(254, 254, 254).getRGB());
      t = NativeTextures.texture(h);
      eq("transparent background", t == null ? -1 : t.pixels[127 * 128] & 0xFFFF, 0);

      // empty string: a " " is painted -> all background
      h = NativeTextures.makeStringTexture(new char[0], 0, "Arial", 48,
         java.awt.Color.black.getRGB(), java.awt.Color.white.getRGB());
      t = NativeTextures.texture(h);
      int nonBack = 0;
      if (t != null) {
         for (short s : t.pixels) {
            if ((s & 0xFFFF) != 0xFFFF) {
               nonBack++;
            }
         }
      }
      check("empty created", t != null);
      eq("empty: all background", nonBack, 0);

      if (failures > 0) {
         System.out.println("TexStringCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("TexStringCheck: OK");
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FAIL " + what);
      }
   }

   private static void eq(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FAIL " + what + ": 0x" + Long.toHexString(got) + " (expected 0x" + Long.toHexString(want) + ")");
      }
   }
}
