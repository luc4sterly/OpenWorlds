import NET.worlds.core.NativeUiImage;
import java.lang.reflect.Method;

/**
 * ImageConverter (0x00423670 / 0x00423920 / 0x004239d0): palette and padding
 * of 8 bpp rows, and the byte addressing of the original's setDIBPixelInts
 * (bug reproduced). Hand-calculated cases.
 */
public class UiImageCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + what);
      if (!ok) {
         fails++;
      }
   }

   static int rgb(int dib, int x, int y) throws Exception {
      Method get = NativeUiImage.class.getDeclaredMethod("get", int.class);
      get.setAccessible(true);
      Object d = get.invoke(null, dib);
      Method m = d.getClass().getDeclaredMethod("rgb", int.class, int.class);
      m.setAccessible(true);
      return (Integer) m.invoke(d, x, y);
   }

   public static void main(String[] a) throws Exception {
      // 8 bpp, 3x2 -> row of (3+3)&~3 = 4 bytes; palette of 2 ARGB colors, rest white (DAT_004714ac)
      int h = NativeUiImage.prepareDIB(3, 2, 2, new int[]{0xFF112233, 0x80445566, 0, 0, 0, 0});
      // single-call setPixels: indices row 0 = 0 1 0, row 1 = 1 1 7; scansize 3
      NativeUiImage.setDIBPixelBytes(h, 3, 0, 0, 3, 2, new byte[]{0, 1, 0, 1, 1, 7}, 0, 3);
      check(rgb(h, 0, 0) == 0x112233 && rgb(h, 1, 0) == 0x445566 && rgb(h, 2, 0) == 0x112233, "row 0: palette B,G,R without alpha");
      check(rgb(h, 0, 1) == 0x445566 && rgb(h, 2, 1) == 0xFFFFFF, "row 1 at byte 4 (padded to 4); index 7 = white fill");
      // off is ignored: with off = 3 the native still reads from the start
      int h2 = NativeUiImage.prepareDIB(3, 1, 2, new int[]{0x000000, 0xFFFFFF});
      NativeUiImage.setDIBPixelBytes(h2, 3, 0, 0, 3, 1, new byte[]{1, 1, 1, 0, 0, 0}, 3, 3);
      check(rgb(h2, 0, 0) == 0xFFFFFF, "setDIBPixelBytes ignores off (0x423958)");
      // 32 bpp, 4x2; row 0 = A B C D, row 1 = E F G H; destination y*width+x in BYTES:
      // row 0 -> bytes 0..15 (pixels 0..3), row 1 -> bytes 4..19 (pixels 1..4)
      // result: A E F G | H 0 0 0
      int h3 = NativeUiImage.prepareDIB(4, 2, 0, null);
      int[] px = {0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10, 0x11};
      NativeUiImage.setDIBPixelInts(h3, 4, 0, 0, 4, 2, px, 0, 4);
      check(rgb(h3, 0, 0) == 0xA && rgb(h3, 1, 0) == 0xE && rgb(h3, 3, 0) == 0x10 && rgb(h3, 0, 1) == 0x11 && rgb(h3, 1, 1) == 0,
         "setDIBPixelInts with a row of 'width' bytes: A E F G / H 0 0 0");
      NativeUiImage.delete(h);
      check(NativeUiImage.prepareDIB(1, 1, 0, null) == h, "cleanup releases the handle and it is reused");
      System.out.println(fails == 0 ? "UiImageCheck: all OK" : "UiImageCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}
