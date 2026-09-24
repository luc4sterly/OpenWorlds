import NET.worlds.core.NativeCamera;

/**
 * Tabla de reciprocos (RWDL6D21 DAT_10079214, 0x1000a008), pendientes de
 * arista y tramos texturizados de 0x1002cbb0 (division de perspectiva cada
 * 16 pixeles, u/v empaquetados) en el puente. Casos calculados a mano.
 */
public final class RasterSpanCheck {
   private static int failures;

   private static void expect(String what, boolean ok) {
      if (!ok) {
         System.out.println("FALLA " + what);
         failures++;
      }
   }

   private static int texU(int pk) {
      return pk >>> 25;
   }

   public static void main(String[] args) {
      // Tabla: (dx << 16) / dy truncando hacia cero.
      expect("slope(5,3) = 109226", NativeCamera.slope(5, 3) == 109226);
      expect("slope(-5,3) = -109226", NativeCamera.slope(-5, 3) == -109226);
      expect("slope(31,31) = 65536", NativeCamera.slope(31, 31) == 65536);
      expect("slope(-32,1) = -32<<16", NativeCamera.slope(-32, 1) == -0x200000);
      expect("slope(7,2) = 7*0x8000", NativeCamera.slope(7, 2) == 229376);
      // fuera de la tabla (|dx| >= 32 o dy >= 32): idiv
      expect("slope(100,7) = 936228", NativeCamera.slope(100, 7) == 936228);
      expect("slope(3,40) = 4915", NativeCamera.slope(3, 40) == 4915);
      // la tabla da lo mismo que la division en todo su dominio
      boolean same = true;
      for (int dx = -31; dx < 32; dx++) {
         for (int dy = 3; dy < 32; dy++) {
            same &= NativeCamera.slope(dx, dy) == (dx << 16) / dy;
         }
      }
      expect("tabla == (dx<<16)/dy", same);

      // Tramo corto (8 px), afin (q = 512 en los dos extremos): u y v de 0
      // a 65536 (1.0 = 128 texels): paso 65536 * 0.125 = 8192 -> texel 16*i.
      int[] s = NativeCamera.texSpan(512, 0, 0, 512, 65536, 65536, 8, null);
      boolean ok = true;
      for (int i = 0; i < 8; i++) {
         ok &= NativeCamera.texelIndex(s[i]) == (16 * i) * 128 + 16 * i;
      }
      expect("tramo corto 8 px: texel (16i,16i)", ok);

      // Tramo largo afin de 20 px, u de 0 a 40960: bloque de 16 con paso
      // (32768 & ~15) << 12 -> 2048/px (texel 4i); cola de 4 px con
      // (32768 - 40960) / -4 = 2048.
      s = NativeCamera.texSpan(512, 0, 0, 512, 40960, 0, 20, null);
      expect("20 px afin: extremos 0 y 76, medio 40", texU(s[0]) == 0 && texU(s[10]) == 40 && texU(s[19]) == 76);

      // Tramo largo con perspectiva: q 512 -> 1024, uq 0 -> 81920 (u = 0 a
      // la izquierda, 40960 a la derecha). Bloque: q = 921.6, uq = 65536,
      // u1 = ftol(65536 * 512/921.6) = 36408, paso (36400 << 12) -> 2275/px:
      // texel 0, 35 (px 8), 66 (px 15). Cola: u0 = 36408 (texel 71), paso
      // (36408 - 40960) / -4 = 1138 -> px 19 = 39822 (texel 77). Lineal
      // puro daria texel 40 en el px 8.
      s = NativeCamera.texSpan(512, 0, 0, 1024, 81920, 0, 20, null);
      expect("20 px con perspectiva: " + texU(s[0]) + "," + texU(s[8]) + "," + texU(s[15]) + "," + texU(s[16]) + "," + texU(s[19]),
         texU(s[0]) == 0 && texU(s[8]) == 35 && texU(s[15]) == 66 && texU(s[16]) == 71 && texU(s[19]) == 77);

      if (failures != 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("RasterSpanCheck OK");
   }
}
