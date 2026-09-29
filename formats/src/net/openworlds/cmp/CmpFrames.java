package net.openworlds.cmp;

import java.io.IOException;

/**
 * Palette-index planes of every frame of a .cmp/.mov, decoded the way
 * gamma.dll's ScapePic reader does it (FUN_00442bc0 per frame into the DIB
 * of FUN_00422b30): width = u16@8, height = u16@6 (windr3.mov, the only
 * non-square file, has 64 row pairs = height 128 and 39 nibble columns =
 * width 154), frames located through the movie frame table
 * ({@link CmpStage1#frameTable}), and all frames decoded in order into ONE
 * history buffer that is never cleared, so a frame whose table entry
 * references the previous one starts from its pixels.
 *
 * A frame can be several groups of rows, each with its own header and five
 * streams (FUN_00442bc0), and the esi row of FUN_00457d88 is one buffer
 * for the whole file (FUN_00442750, this+0x3c): both are kept here. Carrying
 * that row from frame to frame changed frame 3 of logo256.mov and frame 1 of
 * splashscreen.mov (GroundZero), where a lookback at a frame's first pass
 * now reads the previous frame's last pass instead of 0; frame 0 of every
 * file is unchanged.
 *
 * Unverified beyond frame 0 against a reference renderer: cmpview.exe
 * shows only one image per movie.
 */
public final class CmpFrames {
   public final int width;
   public final int height;
   /** Width rounded up to 4 and height rounded up to 2 (the DIB size). */
   public final int dibW;
   public final int dibH;
   public final int[][] palette;
   /** Top-down palette indices, dibW * dibH, one per decoded frame. */
   public final byte[][] frames;

   private CmpFrames(int width, int height, int[][] palette, byte[][] frames) {
      this.width = width;
      this.height = height;
      this.dibW = width + 3 & ~3;
      this.dibH = height + 1 & ~1;
      this.palette = palette;
      this.frames = frames;
   }

   private static int u16(byte[] b, int o) {
      return (b[o] & 0xFF) | (b[o + 1] & 0xFF) << 8;
   }

   /** Decodes up to maxFrames frames; a frame that fails ends the list there. */
   public static CmpFrames decode(byte[] file, int maxFrames) throws IOException {
      if (file.length < 34 || file[0] != 'L' || file[1] != 'z' || file[2] != 'H' || file[3] != '2') {
         throw new IOException("not a LzH2 file");
      }
      int width = u16(file, 8);
      int height = u16(file, 6);
      int[][] table = CmpStage1.frameTable(file);
      int n = Math.min(table.length, maxFrames);
      int w4 = width + 3 & ~3;
      int h2 = height + 1 & ~1;
      int stride = -w4;
      int outer = h2 / 2;
      int ch0 = w4 / 4;
      int backwardRoom = outer * 2 * w4 + 4096;
      byte[] history = new byte[backwardRoom + 4096];
      int edi0 = backwardRoom;
      boolean evenIsA = (file[5] & 0x01) != 0;
      int[][] palette = null;
      byte[][] frames = new byte[n][];
      // The esi row of FUN_00457d88: one buffer per reader, (w+3>>2)*2 bytes
      // allocated once (FUN_00442750, this+0x3c), never cleared, shared by
      // every group and frame. Lookbacks can read what an earlier pass left.
      byte[] esiRow = null;
      int done = 0;
      for (int f = 0; f < n; f++) {
         // A frame is a run of groups (FUN_00442bc0's loop): each one
         // decodes its own row pairs from its own five streams, starting
         // where the previous group's rows ended, until the height is
         // covered. The first group's size comes from the frame table, the
         // next one's from the group header. tex/mug.cmp of the Blair Witch
         // world (TheBurkittsvilleDiner) is 233 rows high in two groups of
         // 76 and 41 row pairs (assets/cmp-verified/mug); every file of the
         // GroundZero corpus has one group per frame.
         int edi = edi0;
         int outerAdvance = 2 * stride - ch0 * 4;
         int groupOff = table[f][0];
         int groupSize = table[f][1];
         int rows = 0;
         boolean failed = false;
         while (rows < height) {
            CmpStage1 s1;
            try {
               s1 = CmpStage1.decodeGroupAt(file, groupOff, groupSize);
            } catch (IOException e) {
               failed = true;
               break;
            }
            // (puVar3[7] & 0x7fff) != 0 or byte 0xf negative: error 6
            if (s1.groupFlags != 0 || s1.rowPairs <= 0 || rows + 2 * s1.rowPairs > h2) {
               failed = true;
               break;
            }
            if (palette == null) {
               palette = s1.palette;
            }
            CmpStage2 dec = new CmpStage2(history, edi0, stride, pad(s1.streamA), pad(s1.streamCtrl),
               pad(s1.streamLit), pad(s1.streamFillIdx), pad(s1.bits));
            dec.out = esiRow;
            for (int o = 0; o < s1.rowPairs; o++) {
               dec.outPos = 0;
               dec.decode(ch0, edi);
               edi += ch0 * 4 + outerAdvance;
            }
            // CmpStage2 works on a padded copy: carry that buffer on
            history = java.util.Arrays.copyOf(dec.history, history.length);
            esiRow = dec.out;
            rows += 2 * s1.rowPairs;
            groupOff += groupSize;
            groupSize = s1.nextGroupSize;
         }
         if (failed) {
            break;
         }
         byte[] idx = new byte[w4 * h2];
         for (int p = 0; p < outer; p++) {
            int edip = edi0 + p * 2 * stride;
            int rEven = h2 - 2 - 2 * p;
            int rOdd = h2 - 1 - 2 * p;
            for (int x = 0; x < w4; x++) {
               byte a = history[edip + x];
               byte b = history[edip + stride + x];
               idx[rEven * w4 + x] = evenIsA ? a : b;
               idx[rOdd * w4 + x] = evenIsA ? b : a;
            }
         }
         if (height < h2) {
            System.arraycopy(idx, (h2 - height) * w4, idx, 0, w4 * height);
         }
         frames[f] = idx;
         done++;
      }
      if (done < n) {
         byte[][] shorter = new byte[done][];
         System.arraycopy(frames, 0, shorter, 0, done);
         frames = shorter;
      }
      return new CmpFrames(width, height, palette == null ? new int[256][] : palette, frames);
   }

   private static byte[] pad(byte[] a) {
      byte[] b = new byte[a.length + 512];
      System.arraycopy(a, 0, b, 0, a.length);
      return b;
   }
}
