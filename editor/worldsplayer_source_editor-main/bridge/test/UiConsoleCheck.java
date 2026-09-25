import NET.worlds.core.NativeUiConsole;

/**
 * Console.encrypt (0x0040b7f0) / decrypt (0x0040bb00): vectores calculados
 * a mano (cuentas en los comentarios) e ida y vuelta.
 */
public class UiConsoleCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLA ") + what);
      if (!ok) {
         fails++;
      }
   }

   public static void main(String[] a) {
      // "ab", sal 0, serie 0: b = 00 02 61 62 | relleno 00 00 (n=6), clave 0.
      //   0x000261: 0, 0, 609>>6=9, 609&63=33 -> ' ' ' ' ')' 'A'
      //   0x620000: 011000 100000 000000 000000 = 24, 32, 0, 0 -> '8' '@' ' ' ' '
      String c = NativeUiConsole.encrypt("ab", 0, 0);
      check(c.equals("  )A8@  "), "encrypt(\"ab\", sal 0, serie 0) = \"  )A8@  \" (sale \"" + c + "\")");
      // "ab", sal 0x5A, serie 0x12345678: clave = 78 56 34 12 ^ 5A = 22 0C 6E 48
      //   b = 5A 02 61 62 00 00 -> 5A 20 6D 0C 48 22 (b[j] ^= clave[(j-1)%4])
      //   0x5A206D: 22, 1442&63=34, 92289&63=1, 0x6D&63=45 -> '6' 'B' '!' 'M'
      //   0x0C4822: 3, 196&63=4, 12576&63=32, 0x22=34 -> '#' '$' '@' 'B'
      c = NativeUiConsole.encrypt("ab", 0x5A, 0x12345678);
      check(c.equals("6B!M#$@B"), "encrypt(\"ab\", sal 0x5A, serie 0x12345678) = \"6B!M#$@B\" (sale \"" + c + "\")");
      check("ab".equals(NativeUiConsole.decrypt("6B!M#$@B", 0x12345678)), "decrypt(\"6B!M#$@B\") = \"ab\"");
      check("ab".equals(NativeUiConsole.decrypt("  )A8@  ", 0)), "decrypt(\"  )A8@  \", serie 0) = \"ab\"");
      // otra serie: la longitud descifrada cae fuera de [n-4, n-2] -> vacia
      //   serie 0: clave(sal 0x5A) = 5A 5A 5A 5A; b[1] = 0x20 ^ 0x5A = 0x7A = 122 > n-2 = 4 -> ""
      check("".equals(NativeUiConsole.decrypt("6B!M#$@B", 0)), "decrypt con otra serie -> \"\" (longitud invalida)");
      // cadena vacia: len 0, b = S 00 | relleno 00 -> 3 bytes, un grupo
      c = NativeUiConsole.encrypt("", 0, 0);
      check(c.equals("    "), "encrypt(\"\", 0, 0) = 4 espacios");
      check("".equals(NativeUiConsole.decrypt("", 7)), "decrypt(\"\") = \"\"");
      // grupo incompleto: "  )" = (0*64+0)*64+9)*64+0 -> 00 02 40; clave 0; len 2 y n-2=1 < 2 -> ""
      check("".equals(NativeUiConsole.decrypt("  )", 0)), "decrypt de grupo incompleto con longitud imposible -> \"\"");
      // ida y vuelta con sales y series distintas, incluido no ASCII (UTF-8 modificado)
      String[] pw = {"x", "fwtest1", "contraseña", "Ab3$%^&*()_+{}|:<>?", "0123456789012345678901234567890123456789"};
      int[] serials = {0, 0x12345678, 0xDEADBEEF, 16777220};
      boolean all = true;
      for (String p : pw) {
         for (int s : serials) {
            for (int salt = 0; salt < 256; salt += 37) {
               String e = NativeUiConsole.encrypt(p, salt, s);
               boolean charset = e.length() % 4 == 0;
               for (char ch : e.toCharArray()) {
                  charset &= ch >= 0x20 && ch <= 0x5f;
               }
               if (!charset || !p.equals(NativeUiConsole.decrypt(e, s))) {
                  all = false;
                  System.out.println("  falla ida y vuelta: " + p + " sal " + salt + " serie " + s);
               }
            }
         }
      }
      check(all, "ida y vuelta (5 contrasenas x 4 series x 7 sales), salida en 0x20..0x5f y multiplo de 4");
      // tope de 255 bytes (strlen con tope 0xff)
      StringBuilder big = new StringBuilder();
      for (int i = 0; i < 300; i++) {
         big.append((char) ('a' + i % 26));
      }
      String d = NativeUiConsole.decrypt(NativeUiConsole.encrypt(big.toString(), 1, 2), 2);
      check(d.equals(big.substring(0, 255)), "contrasena de 300 bytes -> se guardan 255");
      System.out.println(fails == 0 ? "UiConsoleCheck: todo OK" : "UiConsoleCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}
