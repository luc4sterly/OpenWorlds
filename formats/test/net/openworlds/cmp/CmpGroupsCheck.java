package net.openworlds.cmp;

import java.io.File;
import java.nio.file.Files;
import java.util.zip.CRC32;

/**
 * A frame made of several row groups (FUN_00442bc0), with
 * assets/cmp-verified/mug/mug.cmp from The Blair Witch World: 213x233, two
 * groups; and the table region of assets/cmp-verified/kcl/kcl.mov, the only
 * known file with header byte 13 set. Exits with 1 if something fails.
 *
 * <p>Checked by hand in the file: the frame table gives the first group at
 * 943 with 2071 bytes (also header u16@30). Its header says 76 row pairs
 * and a next group of 1674 bytes, whose header says 41 pairs and next 0.
 * 76 + 41 = 117 = 234 / 2 rows, and 943 + 2071 + 1674 = 4688, the file
 * length. Header byte 12 = 255 colors, so index 255 has no palette entry:
 * it is the hologram's transparent background, and the four corners use it.
 * The CRC32 of the palette indices is a regression value measured on
 * 2026-09-26. What backs it is that every stream of both groups is used up
 * exactly, which the check also requires.
 */
public final class CmpGroupsCheck {
   private static int failures = 0;

   private static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + what);
      if (!ok) {
         failures++;
      }
   }

   private static byte[] pad(byte[] a) {
      byte[] b = new byte[a.length + 512];
      System.arraycopy(a, 0, b, 0, a.length);
      return b;
   }

   /**
    * kcl.mov: header byte 13 = 4, so the table region also holds a block of
    * as many bytes as colors (256) that the reader skips (gamma.dll
    * 0x442963..0x442983). By hand in the file: table region 1190 bytes
    * (u16@28), then 8 frame entries of 20 bytes, so frame 0 starts at
    * 34 + 1190 + 160 = 1384, and the eight groups end at 42099, the file
    * length. The stream use is independent of the pixels, so each group is
    * checked on its own.
    */
   private static void kcl(String path) throws Exception {
      File f = new File(path);
      if (!f.isFile()) {
         check(false, "not found: " + f.getAbsolutePath());
         return;
      }
      byte[] file = Files.readAllBytes(f.toPath());
      check(file.length == 42099 && (file[4] & 255) == 0xc2 && file[12] == 0 && file[13] == 4,
         "kcl.mov: 42099 bytes, mode 0xc2, 256 colors, byte 13 = 4");
      int[][] t = CmpStage1.frameTable(file);
      check(t.length == 8 && t[0][0] == 1384, "kcl.mov: 8 frames, the first at 1384");
      boolean chained = true;
      boolean exact = true;
      for (int i = 0; i < t.length; i++) {
         int end = t[i][0] + t[i][1];
         CmpStage1 s = CmpStage1.decodeGroupAt(file, t[i][0], t[i][1]);
         chained &= s.rowPairs == 64 && s.groupFlags == 0
            && (i + 1 < t.length ? t[i + 1][0] == end && s.nextGroupSize == t[i + 1][1] : end == file.length && s.nextGroupSize == 0);
         int back = 64 * 2 * 128 + 4096;
         CmpStage2 d = new CmpStage2(new byte[back + 4096], back, -128, pad(s.streamA), pad(s.streamCtrl), pad(s.streamLit),
            pad(s.streamFillIdx), pad(s.bits));
         int edi = back;
         for (int o = 0; o < s.rowPairs; o++) {
            d.outPos = 0;
            d.decode(32, edi);
            edi -= 2 * 128;
         }
         exact &= d.posA == s.streamA.length && d.posCtrl == s.streamCtrl.length && d.posLit == s.streamLit.length
            && d.posFillIdx == s.streamFillIdx.length;
      }
      check(chained, "kcl.mov: one group of 64 pairs per frame, contiguous up to the end of the file");
      check(exact, "kcl.mov: each group uses up A, ctrl, lit and fill exactly");
      CmpFrames c = CmpFrames.decode(file, 100);
      CRC32 crc = new CRC32();
      crc.update(c.frames[0]);
      check(c.frames.length == 8 && crc.getValue() == 0xe836e372L, "kcl.mov: CmpFrames gives 8 frames, CRC32 of the first e836e372 (regression)");
   }

   public static void main(String[] args) throws Exception {
      File f = new File(args.length > 0 ? args[0] : "assets/cmp-verified/mug/mug.cmp");
      if (!f.isFile()) {
         System.out.println("FAIL not found: " + f.getAbsolutePath() + " (run from the repo root)");
         System.exit(1);
      }
      byte[] file = Files.readAllBytes(f.toPath());
      check(file.length == 4688, "mug.cmp: 4688 bytes");

      int[][] table = CmpStage1.frameTable(file);
      check(table.length == 1 && table[0][0] == 943 && table[0][1] == 2071, "table: one frame, first group at 943 with 2071 bytes");

      CmpStage1 g0 = CmpStage1.decodeGroupAt(file, 943, 2071);
      CmpStage1 g1 = CmpStage1.decodeGroupAt(file, 943 + 2071, g0.nextGroupSize);
      check(g0.rowPairs == 76 && g0.nextGroupSize == 1674 && g0.groupFlags == 0, "group 0: 76 row pairs, next one of 1674 bytes");
      check(g1.rowPairs == 41 && g1.nextGroupSize == 0 && g1.groupFlags == 0, "group 1: 41 row pairs, no next one");
      check(943 + 2071 + 1674 == file.length && 2 * (76 + 41) == 234, "the two groups cover the file and the 234 rows");

      // stage 2 of both groups by hand, as CmpFrames chains them
      int w4 = 216;
      int stride = -w4;
      int ch0 = w4 / 4;
      int back = 117 * 2 * w4 + 4096;
      byte[] history = new byte[back + 4096];
      int edi = back;
      byte[] esi = null;
      CmpStage1[] groups = {g0, g1};
      for (int g = 0; g < 2; g++) {
         CmpStage1 s = groups[g];
         CmpStage2 d = new CmpStage2(history, back, stride, pad(s.streamA), pad(s.streamCtrl), pad(s.streamLit),
            pad(s.streamFillIdx), pad(s.bits));
         d.out = esi;
         for (int o = 0; o < s.rowPairs; o++) {
            d.outPos = 0;
            d.decode(ch0, edi);
            edi += 2 * stride;
         }
         check(d.posA == s.streamA.length && d.posCtrl == s.streamCtrl.length && d.posLit == s.streamLit.length
            && d.posFillIdx == s.streamFillIdx.length, "group " + g + ": A, ctrl, lit and fill used up exactly");
         // the bit reader loads 4 bytes at a time and one word ahead
         check(d.bitsBytePos >= s.bits.length && d.bitsBytePos <= s.bits.length + 8, "group " + g + ": bits used up (with the look-ahead word)");
         history = java.util.Arrays.copyOf(d.history, history.length);
         esi = d.out;
      }

      CmpFrames c = CmpFrames.decode(file, 1);
      check(c.width == 213 && c.height == 233 && c.frames.length == 1, "CmpFrames: 213x233, one frame");
      byte[] fr = c.frames[0];
      int last = (c.height - 1) * c.dibW;
      check((fr[0] & 255) == 255 && (fr[c.width - 1] & 255) == 255 && (fr[last] & 255) == 255
         && (fr[last + c.width - 1] & 255) == 255, "the four corners are index 255");
      check(c.palette[255] == null && c.palette[254] != null, "255 colors: index 255 has no entry (transparent)");
      CRC32 crc = new CRC32();
      crc.update(fr);
      check(crc.getValue() == 0x11e47437L, "CRC32 of the indices 11e47437 (regression)");

      kcl(args.length > 1 ? args[1] : "assets/cmp-verified/kcl/kcl.mov");

      System.out.println(failures == 0 ? "CmpGroupsCheck: all OK" : "CmpGroupsCheck: " + failures + " failures");
      System.exit(failures == 0 ? 0 : 1);
   }
}
