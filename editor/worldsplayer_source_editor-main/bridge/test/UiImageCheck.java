import NET.worlds.core.NativeUiImage;
import java.lang.reflect.Method;

/**
 * ImageConverter (0x00423670 / 0x00423920 / 0x004239d0): paleta y relleno
 * de filas de 8 bpp, y el direccionamiento en bytes de setDIBPixelInts del
 * original (fallo reproducido). Casos calculados a mano.
 */
public class UiImageCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLA ") + what);
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
      // 8 bpp, 3x2 -> fila de (3+3)&~3 = 4 bytes; paleta de 2 colores ARGB, resto blanco (DAT_004714ac)
      int h = NativeUiImage.prepareDIB(3, 2, 2, new int[]{0xFF112233, 0x80445566, 0, 0, 0, 0});
      // setPixels de una sola llamada: indices fila 0 = 0 1 0, fila 1 = 1 1 7; scansize 3
      NativeUiImage.setDIBPixelBytes(h, 3, 0, 0, 3, 2, new byte[]{0, 1, 0, 1, 1, 7}, 0, 3);
      check(rgb(h, 0, 0) == 0x112233 && rgb(h, 1, 0) == 0x445566 && rgb(h, 2, 0) == 0x112233, "fila 0: paleta B,G,R sin alfa");
      check(rgb(h, 0, 1) == 0x445566 && rgb(h, 2, 1) == 0xFFFFFF, "fila 1 en el byte 4 (relleno a 4); indice 7 = relleno blanco");
      // off se ignora: con off = 3 el nativo sigue leyendo desde el principio
      int h2 = NativeUiImage.prepareDIB(3, 1, 2, new int[]{0x000000, 0xFFFFFF});
      NativeUiImage.setDIBPixelBytes(h2, 3, 0, 0, 3, 1, new byte[]{1, 1, 1, 0, 0, 0}, 3, 3);
      check(rgb(h2, 0, 0) == 0xFFFFFF, "setDIBPixelBytes ignora off (0x423958)");
      // 32 bpp, 4x2; fila 0 = A B C D, fila 1 = E F G H; destino y*ancho+x en BYTES:
      // fila 0 -> bytes 0..15 (pixeles 0..3), fila 1 -> bytes 4..19 (pixeles 1..4)
      // resultado: A E F G | H 0 0 0
      int h3 = NativeUiImage.prepareDIB(4, 2, 0, null);
      int[] px = {0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10, 0x11};
      NativeUiImage.setDIBPixelInts(h3, 4, 0, 0, 4, 2, px, 0, 4);
      check(rgb(h3, 0, 0) == 0xA && rgb(h3, 1, 0) == 0xE && rgb(h3, 3, 0) == 0x10 && rgb(h3, 0, 1) == 0x11 && rgb(h3, 1, 1) == 0,
         "setDIBPixelInts con fila de 'ancho' bytes: A E F G / H 0 0 0");
      NativeUiImage.delete(h);
      check(NativeUiImage.prepareDIB(1, 1, 0, null) == h, "cleanup libera el handle y se reutiliza");
      System.out.println(fails == 0 ? "UiImageCheck: todo OK" : "UiImageCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}
