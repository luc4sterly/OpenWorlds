import NET.worlds.core.NativeUiConsole;

/**
 * Console.encrypt (0x0040b7f0) / decrypt (0x0040bb00): hand-calculated
 * vectors (calculations in the comments) and round trip.
 */
public class UiConsoleCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + what);
      if (!ok) {
         fails++;
      }
   }

   public static void main(String[] a) {
      // "ab", salt 0, serial 0: b = 00 02 61 62 | padding 00 00 (n=6), key 0.
      //   0x000261: 0, 0, 609>>6=9, 609&63=33 -> ' ' ' ' ')' 'A'
      //   0x620000: 011000 100000 000000 000000 = 24, 32, 0, 0 -> '8' '@' ' ' ' '
      String c = NativeUiConsole.encrypt("ab", 0, 0);
      check(c.equals("  )A8@  "), "encrypt(\"ab\", salt 0, serial 0) = \"  )A8@  \" (got \"" + c + "\")");
      // "ab", salt 0x5A, serial 0x12345678: key = 78 56 34 12 ^ 5A = 22 0C 6E 48
      //   b = 5A 02 61 62 00 00 -> 5A 20 6D 0C 48 22 (b[j] ^= key[(j-1)%4])
      //   0x5A206D: 22, 1442&63=34, 92289&63=1, 0x6D&63=45 -> '6' 'B' '!' 'M'
      //   0x0C4822: 3, 196&63=4, 12576&63=32, 0x22=34 -> '#' '$' '@' 'B'
      c = NativeUiConsole.encrypt("ab", 0x5A, 0x12345678);
      check(c.equals("6B!M#$@B"), "encrypt(\"ab\", salt 0x5A, serial 0x12345678) = \"6B!M#$@B\" (got \"" + c + "\")");
      check("ab".equals(NativeUiConsole.decrypt("6B!M#$@B", 0x12345678)), "decrypt(\"6B!M#$@B\") = \"ab\"");
      check("ab".equals(NativeUiConsole.decrypt("  )A8@  ", 0)), "decrypt(\"  )A8@  \", serial 0) = \"ab\"");
      // another serial: the decrypted length falls outside [n-4, n-2] -> empty
      //   serial 0: key(salt 0x5A) = 5A 5A 5A 5A; b[1] = 0x20 ^ 0x5A = 0x7A = 122 > n-2 = 4 -> ""
      check("".equals(NativeUiConsole.decrypt("6B!M#$@B", 0)), "decrypt with another serial -> \"\" (invalid length)");
      // empty string: len 0, b = S 00 | padding 00 -> 3 bytes, one group
      c = NativeUiConsole.encrypt("", 0, 0);
      check(c.equals("    "), "encrypt(\"\", 0, 0) = 4 spaces");
      check("".equals(NativeUiConsole.decrypt("", 7)), "decrypt(\"\") = \"\"");
      // incomplete group: "  )" = (0*64+0)*64+9)*64+0 -> 00 02 40; key 0; len 2 and n-2=1 < 2 -> ""
      check("".equals(NativeUiConsole.decrypt("  )", 0)), "decrypt of an incomplete group with an impossible length -> \"\"");
      // round trip with different salts and serials, including non-ASCII (modified UTF-8)
      String[] pw = {"x", "fwtest1", "naïve-café", "Ab3$%^&*()_+{}|:<>?", "0123456789012345678901234567890123456789"};
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
                  System.out.println("  round trip fails: " + p + " salt " + salt + " serial " + s);
               }
            }
         }
      }
      check(all, "round trip (5 passwords x 4 serials x 7 salts), output in 0x20..0x5f and a multiple of 4");
      // 255-byte cap (strlen capped at 0xff)
      StringBuilder big = new StringBuilder();
      for (int i = 0; i < 300; i++) {
         big.append((char) ('a' + i % 26));
      }
      String d = NativeUiConsole.decrypt(NativeUiConsole.encrypt(big.toString(), 1, 2), 2);
      check(d.equals(big.substring(0, 255)), "300-byte password -> 255 are stored");
      System.out.println(fails == 0 ? "UiConsoleCheck: all OK" : "UiConsoleCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}
