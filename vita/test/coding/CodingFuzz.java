package codingtest;

import java.util.Random;

/**
 * The runtime's character encodings (Clearwing patch "Character encodings",
 * java.nio.charset.Coding) against the JDK's on random input: decoding
 * whole and cut in two, and encoding. vita/tools/run-coding-fuzz.sh copies
 * Coding into this package to run it on a JVM.
 */
public class CodingFuzz {
   static final String[] NAMES = {"UTF-8", "ISO-8859-1", "US-ASCII", "windows-1252", "UTF-16", "UTF-16BE", "UTF-16LE"};

   static String show(char[] c) {
      StringBuilder sb = new StringBuilder();
      for (char x : c) sb.append(Integer.toHexString(x)).append(' ');
      return sb.toString();
   }

   static String showb(byte[] b) {
      StringBuilder sb = new StringBuilder();
      for (byte x : b) sb.append(Integer.toHexString(x & 0xFF)).append(' ');
      return sb.toString();
   }

   public static void main(String[] a) throws Exception {
      // differences are printed (the first ten), "identical" when there are none
      Random r = new Random(42);
      int fails = 0;
      for (int cs = 0; cs < NAMES.length; cs++) {
         for (int iter = 0; iter < 200000 && fails < 10; iter++) {
            int n = r.nextInt(12);
            byte[] b = new byte[n];
            for (int i = 0; i < n; i++) {
               int k = r.nextInt(4);
               b[i] = (byte) (k == 0 ? r.nextInt(0x80) : k == 1 ? 0x80 + r.nextInt(0x40) : k == 2 ? 0xC0 + r.nextInt(0x40) : r.nextInt(256));
            }
            String jdk = new String(b, NAMES[cs]);
            char[] mine = Coding.decode(cs, b, 0, n);
            if (!jdk.equals(new String(mine))) {
               fails++;
               System.out.println("decode " + NAMES[cs] + " " + showb(b) + " jdk " + show(jdk.toCharArray()) + " mine " + show(mine));
            }
            // streaming: every split point gives the same
            if (n > 1) {
               int split = 1 + r.nextInt(n - 1);
               Coding.Decoder d = new Coding.Decoder(cs);
               char[] out = new char[64];
               int m = d.decode(b, 0, split, out, 0, false);
               m += d.decode(b, split, n - split, out, m, true);
               if (!jdk.equals(new String(out, 0, m))) {
                  fails++;
                  System.out.println("split " + split + " " + NAMES[cs] + " " + showb(b) + " jdk " + show(jdk.toCharArray()) + " mine " + show(java.util.Arrays.copyOf(out, m)));
               }
            }
            int cn = r.nextInt(8);
            char[] c = new char[cn];
            for (int i = 0; i < cn; i++) {
               int k = r.nextInt(5);
               c[i] = (char) (k == 0 ? r.nextInt(0x80) : k == 1 ? 0x80 + r.nextInt(0x180) : k == 2 ? 0xD800 + r.nextInt(0x800) : k == 3 ? 0x2000 + r.nextInt(0x200) : r.nextInt(0x10000));
            }
            byte[] je = new String(c).getBytes(NAMES[cs]);
            byte[] me = Coding.encode(cs, c, 0, cn);
            if (!java.util.Arrays.equals(je, me)) {
               fails++;
               System.out.println("encode " + NAMES[cs] + " " + show(c) + " jdk " + showb(je) + " mine " + showb(me));
            }
         }
      }
      System.out.println(fails == 0 ? "identical" : fails + " differences");
      System.exit(fails == 0 ? 0 : 1);
   }
}
