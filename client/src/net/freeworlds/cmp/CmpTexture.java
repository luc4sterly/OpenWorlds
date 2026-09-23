package net.freeworlds.cmp;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

/**
 * A .cmp/.mov texture as top-down RGB.
 *
 * Real files ({@link #loadRaw}, {@link #loadMov}, {@link #loadMovFrames})
 * go through {@link CmpFrames}: header, frame table and per-frame decode
 * as gamma.dll's ScapePic reader (FUN_00442750 / FUN_00442bc0), width =
 * u16@8, height = u16@6, palette embedded in the file.
 *
 * {@link #load} is the legacy loader for pre-captured Stage-2 streams
 * plus a hand-voted palette (RwxViewer, tools/gamma-dll-debug-harness);
 * the rest of this comment describes that path only.
 *
 * Scope, stated honestly (see tools/gamma-dll-debug-harness/
 * cmp-stage2-decoder/README.md, round-5 section):
 * - The Huffman bit-decoder (Stage 1, FUN_00426af0, .cmp bytes -&gt; symbol
 *   streams) is NOT reimplemented. The 5 symbol streams loaded here are the
 *   real Stage-1 outputs captured live from gamma.dll and trimmed to the
 *   exact consumption of a full verified decode (byte-exact on the captured
 *   ground truth). Decoding any OTHER .cmp file requires Stage 1 first.
 * - The palette is NOT parsed from the .cmp (its on-disk location is still
 *   unknown). It was derived once, offline, by voting each verified decoder
 *   index against the real cmpview.exe rendering of the same file
 *   (deterministic mode color per index - the voted render is structurally
 *   identical to cmpview's own pixels). A wrong or guessed palette would
 *   silently recolor everything, so the palette ships as an explicit,
 *   inspectable resource, never as an inline assumption.
 * - Geometry (W/H) IS parsed from the .cmp header itself (bytes 6-9,
 *   little-endian W then H - verified on test4b 32x32, rustwood/sball
 *   128x128) and cross-checked against the palette file; ch = W/4,
 *   outer = H/2, stride = -W are asserted, not assumed - anything else
 *   throws rather than rendering plausible-but-unverified pixels.
 *
 * Resource layout (directory + base name, e.g. assets/cmp-verified/sball):
 *   &lt;base&gt;.cmp                 original file (header dims + provenance)
 *   &lt;base&gt;.stream_{a,ctrl,lit,fillidx,bits}.bin   trimmed Stage-2 streams
 *   &lt;base&gt;.palette.txt        first line "W H", then "idx r g b" lines
 */
public final class CmpTexture {
   public final int width;
   public final int height;
   /** Top-down RGB bytes, {@code width*height*3}. */
   public final byte[] rgb;

   private CmpTexture(int width, int height, byte[] rgb) {
      this.width = width;
      this.height = height;
      this.rgb = rgb;
   }

   public static CmpTexture load(File dir, String base) throws IOException {
      byte[] cmp = read(new File(dir, base + ".cmp"));
      if (cmp.length < 16 || cmp[0] != 'L' || cmp[1] != 'z' || cmp[2] != 'H' || cmp[3] != '2') {
         throw new IOException("not a LzH2 .cmp file: " + base);
      }
      int w = (cmp[6] & 0xFF) | ((cmp[7] & 0xFF) << 8);
      int h = (cmp[8] & 0xFF) | ((cmp[9] & 0xFF) << 8);
      if (w <= 0 || h <= 0 || w % 4 != 0 || h % 2 != 0 || w > 1024 || h > 1024) {
         throw new IOException("unsupported .cmp geometry W=" + w + " H=" + h + " (" + base + ")");
      }

      int[][] palette = new int[256][];
      int palW = -1, palH = -1;
      boolean pass0Top = true;
      boolean evenIsA = true;
      for (String line : readLines(new File(dir, base + ".palette.txt"))) {
         line = line.trim();
         if (line.isEmpty() || line.startsWith("#")) {
            continue;
         }
         String[] p = line.split("\\s+");
         if (p[0].equals("orient")) {
            // Row-assembly convention, established empirically per file
            // against cmpview.exe's own pixels (see harness README round 5):
            // pass0_top=1: top-down row 2p = pass p's linear-row writes;
            // even_is_A=1: even output bytes come from those linear rows
            // (sball.cmp needs "orient 0 0"; test4b.cmp needs "1 1" -
            // orientation evidently varies per file, presumably a header
            // flag whose meaning is still open - never guessed here).
            pass0Top = p[1].equals("1");
            evenIsA = p[2].equals("1");
            continue;
         }
         if (palW < 0) {
            palW = Integer.parseInt(p[0]);
            palH = Integer.parseInt(p[1]);
            continue;
         }
         palette[Integer.parseInt(p[0])] = new int[]{
            Integer.parseInt(p[1]), Integer.parseInt(p[2]), Integer.parseInt(p[3])};
      }
      if (palW != w || palH != h) {
         throw new IOException("palette dims " + palW + "x" + palH
            + " disagree with .cmp header " + w + "x" + h + " (" + base + ")");
      }

      byte[] a = read(new File(dir, base + ".stream_a.bin"));
      byte[] ctrl = read(new File(dir, base + ".stream_ctrl.bin"));
      byte[] lit = read(new File(dir, base + ".stream_lit.bin"));
      byte[] fill = read(new File(dir, base + ".stream_fillidx.bin"));
      byte[] bits = read(new File(dir, base + ".stream_bits.bin"));

      return render(w, h, palette, a, ctrl, lit, fill, bits, pass0Top, evenIsA, base);
   }

   /**
    * Load and decode a real .cmp still: frame 0 of {@link CmpFrames}, the
    * same decode gamma.dll's ScapePic reader does (FUN_00442750 header +
    * frame table, FUN_00442bc0 per frame). Measured on the 159 .cmp of
    * GroundZero/content.zip (2026-09-22): byte-identical RGB to the
    * previous CmpStage1.decode + render path, so nothing changes for
    * stills (all 159 are square; the old path read width from u16@6).
    */
   public static CmpTexture loadRaw(File cmpFile) throws IOException {
      return frame(CmpFrames.decode(read(cmpFile), 1), 0, cmpFile.getName(), false);
   }

   /**
    * Frame 0 of a .mov (see {@link #loadMovFrames}). What a Material shows
    * for a plain "x.mov" texture: Material.calcRes sets sPos = 0 and
    * hRes = vRes = 1, so syncBackgroundLoad takes frames[0] of the movie
    * (NET/worlds/scape/Material.java, calcRes + syncBackgroundLoad).
    *
    * Before 2026-09-22 this located the group by a header signature
    * (CmpStage1.decodeMovFrame0, removed) and decoded the LAST frame of
    * every movie; windr3 also came out 128x154 instead of 154x128.
    */
   public static CmpTexture loadMov(File movFile) throws IOException {
      return frame(CmpFrames.decode(read(movFile), 1), 0, movFile.getName(), true);
   }

   /**
    * Every frame of a .mov in frame-table order (CmpFrames: one shared
    * history, frame i starting from frame i-1 as gamma.dll's DIB does).
    * In the original these frames are not played over time by the
    * texture itself: Material uses them as the hRes x vRes tiles of one
    * surface (and the "Ns*" suffix picks the N-th group of tiles), and
    * Hologram uses them as view-angle sides - see
    * docs/cmp-texture-format-reference.md ".mov".
    */
   public static CmpTexture[] loadMovFrames(File movFile) throws IOException {
      CmpFrames f = CmpFrames.decode(read(movFile), Integer.MAX_VALUE);
      CmpTexture[] out = new CmpTexture[f.frames.length];
      for (int i = 0; i < out.length; i++) {
         out[i] = frame(f, i, movFile.getName(), true);
      }
      return out;
   }

   /**
    * One frame of a decoded ScapePic as top-down RGB, width x height
    * cropped from the dibW-wide index plane. Movie palettes hold 255
    * entries (indices 0..254); index 255 is the paper/transparent
    * background cmpview.exe shows as its white canvas (verified: cbirda4
    * background renders white in cmpview while our index-255 pixels would
    * otherwise fall back to magenta). Stills always carry a real entry
    * 255, so that fallback applies to movies only.
    */
   private static CmpTexture frame(CmpFrames f, int i, String label, boolean movie) throws IOException {
      if (i >= f.frames.length) {
         throw new IOException(label + ": frame " + i + " not decoded (" + f.frames.length + " frames)");
      }
      int w = f.width;
      int h = f.height;
      byte[] idx = f.frames[i];
      byte[] rgb = new byte[w * h * 3];
      int missing = 0;
      for (int y = 0; y < h; y++) {
         for (int x = 0; x < w; x++) {
            int k = idx[y * f.dibW + x] & 0xFF;
            int[] c = f.palette[k];
            if (c == null && movie && k == 255) {
               c = WHITE;
            }
            int o = (y * w + x) * 3;
            if (c == null) {
               missing++;
               rgb[o] = (byte) 255;
               rgb[o + 1] = 0;
               rgb[o + 2] = (byte) 255;
            } else {
               rgb[o] = (byte) c[0];
               rgb[o + 1] = (byte) c[1];
               rgb[o + 2] = (byte) c[2];
            }
         }
      }
      if (missing > 0) {
         System.out.println("CmpTexture " + label + ": " + missing
            + " pixels used unmapped palette indices (magenta, see docs)");
      }
      return new CmpTexture(w, h, rgb);
   }

   private static final int[] WHITE = {255, 255, 255};

   private static byte[] pad(byte[] a) {
      byte[] b = new byte[a.length + 512];
      System.arraycopy(a, 0, b, 0, a.length);
      return b;
   }

   private static CmpTexture render(int w, int h, int[][] palette, byte[] a, byte[] ctrl,
                                     byte[] lit, byte[] fill, byte[] bits,
                                     boolean pass0Top, boolean evenIsA, String label) throws IOException {
      int ch0 = w / 4;
      int outer = h / 2;
      int stride = -w;
      if ((long) outer * 2 * -stride != (long) w * h) {
         throw new IOException("geometry not covered by outer*2*stride == W*H"
            + " (W=" + w + " H=" + h + ", ch=" + ch0 + " outer=" + outer + ")");
      }
      int outerAdvance = 2 * stride - ch0 * 4;
      int totalNet = outer * 2 * stride;
      int backwardRoom = Math.max(0, -totalNet) + 4096;
      int forwardRoom = Math.max(0, totalNet) + 4096;
      int edi0 = backwardRoom;
      // Zero seed: verified live that the history window is all zeros at
      // call entry for every file tested (fresh heap pages), so a zero
      // buffer reproduces the real initial context exactly.
      CmpStage2 dec = new CmpStage2(new byte[backwardRoom + forwardRoom],
         edi0, stride, a, ctrl, lit, fill, bits);
      int edi = edi0;
      for (int o = 0; o < outer; o++) {
         dec.outPos = 0;
         dec.decode(ch0, edi);
         edi += ch0 * 4 + outerAdvance;
      }
      // Full image = final history buffer: pass p wrote a linear row at
      // edi0+p*2*stride and a stride row at edi0+p*2*stride+stride, each W
      // bytes (every branch writes both rows fully, so unlike the esi
      // subsample this needs no branch-dependent interpretation).
      // Which address is which top-down row is the per-file orientation
      // above (pass 0 = TOP pair for test4b.cmp, BOTTOM pair for sball.cmp,
      // measured against cmpview - the .cmp header flag behind it is TBD).
      byte[] hist = dec.history;
      byte[] rgb = new byte[w * h * 3];
      int missing = 0;
      for (int p = 0; p < outer; p++) {
         int edip = edi0 + p * 2 * stride;
         int rEven = pass0Top ? 2 * p : h - 2 - 2 * p;
         int rOdd = pass0Top ? 2 * p + 1 : h - 1 - 2 * p;
         for (int x = 0; x < w; x++) {
            int idxA = hist[edip + x] & 0xFF;
            int idxB = hist[edip + stride + x] & 0xFF;
            int idxEven = evenIsA ? idxA : idxB;
            int idxOdd = evenIsA ? idxB : idxA;
            int[] cEven = palette[idxEven];
            int[] cOdd = palette[idxOdd];
            int oEven = (rEven * w + x) * 3;
            int oOdd = (rOdd * w + x) * 3;
            if (cEven == null) {
               missing++;
               rgb[oEven] = (byte) 255;
               rgb[oEven + 1] = 0;
               rgb[oEven + 2] = (byte) 255;
            } else {
               rgb[oEven] = (byte) cEven[0];
               rgb[oEven + 1] = (byte) cEven[1];
               rgb[oEven + 2] = (byte) cEven[2];
            }
            if (cOdd == null) {
               missing++;
               rgb[oOdd] = (byte) 255;
               rgb[oOdd + 1] = 0;
               rgb[oOdd + 2] = (byte) 255;
            } else {
               rgb[oOdd] = (byte) cOdd[0];
               rgb[oOdd + 1] = (byte) cOdd[1];
               rgb[oOdd + 2] = (byte) cOdd[2];
            }
         }
      }
      if (missing > 0) {
         System.out.println("CmpTexture " + label + ": " + missing
            + " pixels used unmapped palette indices (magenta, see docs)");
      }
      return new CmpTexture(w, h, rgb);
   }

   private static byte[] read(File f) throws IOException {
      return Files.readAllBytes(f.toPath());
   }

   private static List<String> readLines(File f) throws IOException {
      List<String> out = new ArrayList<>();
      for (String line : new String(read(f), "ISO-8859-1").split("\r\n|\r|\n")) {
         out.add(line);
      }
      return out;
   }
}
