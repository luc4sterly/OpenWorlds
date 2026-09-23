package NET.worlds.core;

/**
 * StringTexture.makeStringTexture (gamma.dll 0x00424af0 / FUN_00424870):
 * tamaño del DIB de texto, colores de 16 bits, cara "Kanji", y la textura
 * resultante: el texto estirado a 128x128 por COLORONCOLOR, solo con los dos
 * colores (sin antialias). Casos calculados a mano; el ancho del texto
 * depende de los glifos (⚠️, ver NativeTextures) y solo se acota. Sale con 1
 * si algo falla.
 */
public final class TexStringCheck {
   private static int failures = 0;

   public static void main(String[] args) {
      System.setProperty("java.awt.headless", "true");

      // FUN_00424870: extensión tal cual; si cx*cy > 0xfffff, cx = cy/2^20
      // (0 para cualquier alto normal) y luego 0 -> 8x8
      int[] e = NativeTextures.stringExtent(100, 48);
      eq("extensión 100x48", e[0], 100);
      eq("extensión 100x48 alto", e[1], 48);
      e = NativeTextures.stringExtent(21845, 48); // 1048560 <= 0xfffff
      eq("21845x48 cabe", e[0], 21845);
      e = NativeTextures.stringExtent(21846, 48); // 1048608 > 0xfffff -> cx = 0 -> 8x8
      eq("21846x48 -> 8 de ancho", e[0], 8);
      eq("21846x48 -> 8 de alto", e[1], 8);
      e = NativeTextures.stringExtent(0, 48);
      eq("vacío -> 8x8", e[0] * 1000 + e[1], 8008);

      // colores (COLORREF 0x00BBGGRR) tras 0x424a53..0x424a77
      int[] c = NativeTextures.stringColors(0, 0xfefefe);
      eq("texto negro -> 080808", c[0], 0x080808);
      eq("fondo fefefe -> 0 (transparente)", c[1], 0);
      c = NativeTextures.stringColors(0xffffff, 0);
      eq("fondo negro -> 080808", c[1], 0x080808);
      eq("Color.red -> COLORREF", NativeTextures.colorRef(java.awt.Color.red.getRGB()), 0x0000ff);
      eq("Color(1,2,3) -> COLORREF", NativeTextures.colorRef(new java.awt.Color(1, 2, 3).getRGB()), 0x030201);
      check("Kanji -> MS Gothic", "MS Gothic".equals(NativeTextures.stringFace("Kanji")));
      check("Arial -> Arial", "Arial".equals(NativeTextures.stringFace("Arial")));

      // NametagDrone: negro sobre blanco, Arial 48 -> 128x128 con solo 0x0841
      // (texto) y 0xFFFF (fondo); la fila 127 viene de la fila 47 del DIB
      // (127*48/128 = 47.6), bajo la línea base de "HI": fondo
      int h = NativeTextures.makeStringTexture("HI".toCharArray(), 2, "Arial", 48,
         java.awt.Color.black.getRGB(), java.awt.Color.white.getRGB());
      NativeTextures.Texture t = NativeTextures.texture(h);
      check("textura creada", t != null && t.pixels.length == 128 * 128);
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
         eq("solo dos colores", other, 0);
         check("hay texto y fondo", text > 0 && back > text);
         for (int x = 0; x < 128; x++) {
            eq("fila 127 fondo x=" + x, t.pixels[127 * 128 + x] & 0xFFFF, 0xFFFF);
         }
         check("fuera del diccionario", t.name == null);
      }

      // Drone con fondo (254,254,254): el fondo es el texel 0 transparente
      h = NativeTextures.makeStringTexture("HI".toCharArray(), 2, "Arial", 48,
         java.awt.Color.black.getRGB(), new java.awt.Color(254, 254, 254).getRGB());
      t = NativeTextures.texture(h);
      eq("fondo transparente", t == null ? -1 : t.pixels[127 * 128] & 0xFFFF, 0);

      // cadena vacía: se pinta un " " -> todo fondo
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
      check("vacía creada", t != null);
      eq("vacía: todo fondo", nonBack, 0);

      if (failures > 0) {
         System.out.println("TexStringCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("TexStringCheck: OK");
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FALLA " + what);
      }
   }

   private static void eq(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FALLA " + what + ": 0x" + Long.toHexString(got) + " (esperado 0x" + Long.toHexString(want) + ")");
      }
   }
}
