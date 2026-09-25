package NET.worlds.core;

/**
 * FUN_004222b0 con pantalla de 16 bits: StretchBlt en modo 3 (COLORONCOLOR)
 * de la imagen a 128x128 y paso a 5-6-5, y la paleta de FUN_00422b30.
 * Casos calculados a mano. Sale con 1 si algo falla.
 */
public final class TexStretchCheck {
   private static int failures = 0;

   public static void main(String[] args) {
      // píxel fuente de cada destino: d * s / 128, hacia abajo
      eq("4->128 d=0", NativeTextures.gdiSourceIndex(0, 128, 4), 0);
      eq("4->128 d=31", NativeTextures.gdiSourceIndex(31, 128, 4), 0);
      eq("4->128 d=32", NativeTextures.gdiSourceIndex(32, 128, 4), 1);
      eq("4->128 d=127", NativeTextures.gdiSourceIndex(127, 128, 4), 3);
      eq("118->128 d=64", NativeTextures.gdiSourceIndex(64, 128, 118), 59); // 7552/128 = 59
      eq("118->128 d=127", NativeTextures.gdiSourceIndex(127, 128, 118), 117); // 14986/128 = 117.07
      eq("154->128 d=1", NativeTextures.gdiSourceIndex(1, 128, 154), 1); // 1.2
      eq("154->128 d=127", NativeTextures.gdiSourceIndex(127, 128, 154), 152); // 19558/128 = 152.8
      eq("128->128 identidad", NativeTextures.gdiSourceIndex(77, 128, 128), 77);

      // 565 truncado: blanco, rojo, el (8,8,8) de la paleta y el negro clave
      eq("565 blanco", NativeTextures.gdiTo565(0xFFFFFF) & 0xFFFF, 0xFFFF);
      eq("565 rojo", NativeTextures.gdiTo565(0xFF0000) & 0xFFFF, 0xF800);
      eq("565 (8,8,8)", NativeTextures.gdiTo565(0x080808) & 0xFFFF, 0x0841); // 1<<11 | 2<<5 | 1
      eq("565 (7,3,7) cae a 0", NativeTextures.gdiTo565(0x070307) & 0xFFFF, 0);

      // 2x1 [rojo, azul] -> columnas 0..63 rojo, 64..127 azul, en todas las filas;
      // COLORONCOLOR no mezcla: ningún texel intermedio
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
      eq("2x1 sin colores mezclados", other, 0);

      // 3x3 con el negro clave en el centro: filas/columnas 43..85 son la
      // fuente 1 (43*3/128 = 1.007, 85*3/128 = 1.99) -> 43x43 texels a 0
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
      eq("3x3 texels transparentes", zeros, 43 * 43);
      eq("3x3 (42,42) blanco", t[42 * 128 + 42] & 0xFFFF, 0xFFFF);
      eq("3x3 (43,43) clave", t[43 * 128 + 43] & 0xFFFF, 0);

      // cuánto movería otra fase del DDA (centro del píxel) en los dos
      // tamaños reales de GroundZero (informativo)
      System.out.println("columnas que cambian con fase al centro: 118->128 " + phaseDiff(118)
         + ", 100->128 " + phaseDiff(100) + ", 154->128 " + phaseDiff(154));

      if (failures > 0) {
         System.out.println("TexStretchCheck: " + failures + " fallos");
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
         System.out.println("FALLA " + what + ": " + got + " (esperado " + want + ")");
      }
   }
}
