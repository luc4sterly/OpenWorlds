package net.openworlds.cmp;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.util.zip.CRC32;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * CmpTexture over CmpFrames (2026-09-22). Exits with 1 if anything fails.
 *
 * Reference values (GroundZero/content.zip, tex/):
 * - windr3.mov: header u16@8 = 154 (width) and u16@6 = 128 (height); the old
 *   path returned 128x154. Frame table (20 bytes per entry, after the
 *   tables region): offsets 1037/3049/5075/8555, sizes
 *   2012/2026/3480/3074; checked by hand that they are contiguous and that the
 *   last one ends at the end of the file (8555 + 3074 = 11629 bytes). Each
 *   frame's reference is the previous one (0xFFFF, 0, 1, 2).
 * - cave.mov: frames at 1037/5061/8479/12774 (+2733 = 15507 = length).
 *   The old path's signature scan (decodeMovFrame0) stopped at
 *   12774, the LAST group: its output had CRC32 9978ee96 (measured before
 *   the change), which is exactly frame 3 of CmpFrames.
 * - The CRC32s of frame 0's RGB (8b07695b, e933c3eb) and of the still
 *   avflr1.cmp (375d1bfe, identical before and after: the 159 .cmp do
 *   not change) are regression values measured on 2026-09-22; what
 *   justifies them are the equalities above (frame 0 = first group of the
 *   table, frame 3 = what used to be seen), which the check also requires.
 */
public final class CmpTextureCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File zip = findContentZip();
      File tmp = Files.createTempDirectory("cmpcheck").toFile();
      try (ZipFile z = new ZipFile(zip)) {
         File windr3 = extract(z, "tex/windr3.mov", tmp);
         File cave = extract(z, "tex/cave.mov", tmp);
         File avflr1 = extract(z, "tex/avflr1.cmp", tmp);

         byte[] w3 = Files.readAllBytes(windr3.toPath());
         check("windr3 u16@8 (width)", u16(w3, 8), 154);
         check("windr3 u16@6 (height)", u16(w3, 6), 128);
         int[][] t = CmpStage1.frameTable(w3);
         check("windr3 frames", t.length, 4);
         int[] offs = {1037, 3049, 5075, 8555};
         int[] sizes = {2012, 2026, 3480, 3074};
         int[] refs = {0xFFFF, 0, 1, 2};
         for (int i = 0; i < 4; i++) {
            check("windr3 frame " + i + " offset", t[i][0], offs[i]);
            check("windr3 frame " + i + " size", t[i][1], sizes[i]);
            check("windr3 frame " + i + " ref", t[i][3], refs[i]);
         }
         check("windr3 last group ends at EOF", t[3][0] + t[3][1], w3.length);
         CmpTexture f0 = CmpTexture.loadMov(windr3);
         check("windr3 width", f0.width, 154);
         check("windr3 height", f0.height, 128);
         checkCrc("windr3 frame 0", f0.rgb, "8b07695b");

         byte[] cv = Files.readAllBytes(cave.toPath());
         int[][] ct = CmpStage1.frameTable(cv);
         check("cave frames", ct.length, 4);
         check("cave frame 0 offset", ct[0][0], 1037);
         check("cave frame 3 offset (where the old path stopped)", ct[3][0], 12774);
         check("cave last group ends at EOF", ct[3][0] + ct[3][1], cv.length);
         CmpTexture[] all = CmpTexture.loadMovFrames(cave);
         check("cave decoded frames", all.length, 4);
         CmpTexture c0 = CmpTexture.loadMov(cave);
         checkCrc("cave frame 0", c0.rgb, "e933c3eb");
         checkCrc("cave loadMovFrames[0] = loadMov", all[0].rgb, "e933c3eb");
         checkCrc("cave frame 3 = output of the old path", all[3].rgb, "9978ee96");

         CmpTexture s = CmpTexture.loadRaw(avflr1);
         check("avflr1 width", s.width, 128);
         check("avflr1 height", s.height, 128);
         checkCrc("avflr1.cmp (still, unchanged)", s.rgb, "375d1bfe");
      } finally {
         File[] fs = tmp.listFiles();
         if (fs != null) {
            for (File f : fs) {
               f.delete();
            }
         }
         tmp.delete();
      }
      if (failures > 0) {
         System.out.println("CmpTextureCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("CmpTextureCheck: OK");
   }

   private static int u16(byte[] b, int o) {
      return (b[o] & 0xFF) | (b[o + 1] & 0xFF) << 8;
   }

   private static void check(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FAIL " + what + ": " + got + " (expected " + want + ")");
      }
   }

   private static void checkCrc(String what, byte[] rgb, String want) {
      CRC32 c = new CRC32();
      c.update(rgb);
      String got = String.format("%08x", c.getValue());
      if (!got.equals(want)) {
         failures++;
         System.out.println("FAIL " + what + ": crc " + got + " (expected " + want + ")");
      }
   }

   private static File extract(ZipFile z, String name, File dir) throws IOException {
      ZipEntry e = z.getEntry(name);
      if (e == null) {
         throw new IOException(name + " is not in " + z.getName());
      }
      File out = new File(dir, name.substring(name.lastIndexOf('/') + 1));
      try (InputStream in = z.getInputStream(e)) {
         Files.copy(in, out.toPath());
      }
      return out;
   }

   /** assets/WorldsPlayer/GroundZero/content.zip, walking up from the current directory. */
   static File findContentZip() throws IOException {
      File d = new File(".").getAbsoluteFile();
      while (d != null) {
         File f = new File(d, "assets/WorldsPlayer/GroundZero/content.zip");
         if (f.isFile()) {
            return f;
         }
         d = d.getParentFile();
      }
      throw new IOException("cannot find assets/WorldsPlayer/GroundZero/content.zip from " + new File(".").getAbsolutePath());
   }
}
