package net.openworlds.awt;

/**
 * A TrueType font file: its metrics, character map and glyph outlines
 * (quadratic contours, simple and composite glyphs). No hinting: what the
 * Vita draws is the plain outline, antialiased.
 */
public final class TrueTypeFont {
   private final byte[] data;
   final String name;
   final int unitsPerEm;
   final int ascender;
   final int descender;
   final int lineGap;
   private final int numGlyphs;
   private final int numberOfHMetrics;
   private final int hmtx;
   private final int loca;
   private final int glyf;
   private final boolean longLoca;
   private final int cmapFormat;
   private final int cmapOffset;

   public TrueTypeFont(byte[] data, String name) {
      this.data = data;
      this.name = name;
      int numTables = u16(4);
      int head = -1, hhea = -1, maxp = -1, cmap = -1, hm = -1, lo = -1, gl = -1;
      for (int i = 0; i < numTables; i++) {
         int rec = 12 + 16 * i;
         String tag = "" + (char) data[rec] + (char) data[rec + 1] + (char) data[rec + 2] + (char) data[rec + 3];
         int off = s32(rec + 8);
         if (tag.equals("head")) {
            head = off;
         } else if (tag.equals("hhea")) {
            hhea = off;
         } else if (tag.equals("maxp")) {
            maxp = off;
         } else if (tag.equals("cmap")) {
            cmap = off;
         } else if (tag.equals("hmtx")) {
            hm = off;
         } else if (tag.equals("loca")) {
            lo = off;
         } else if (tag.equals("glyf")) {
            gl = off;
         }
      }
      if (head < 0 || hhea < 0 || maxp < 0 || cmap < 0 || hm < 0 || lo < 0 || gl < 0) {
         throw new IllegalArgumentException(name + ": not a TrueType font with outlines");
      }
      unitsPerEm = u16(head + 18);
      longLoca = s16(head + 50) != 0;
      ascender = s16(hhea + 4);
      descender = s16(hhea + 6);
      lineGap = s16(hhea + 8);
      numberOfHMetrics = u16(hhea + 34);
      numGlyphs = u16(maxp + 4);
      hmtx = hm;
      loca = lo;
      glyf = gl;
      // the best character map: Windows Unicode full (format 12), BMP (format 4), then any Unicode one
      int best = -1;
      int bestFormat = -1;
      int bestScore = -1;
      int n = u16(cmap + 2);
      for (int i = 0; i < n; i++) {
         int rec = cmap + 4 + 8 * i;
         int platform = u16(rec);
         int encoding = u16(rec + 2);
         int sub = cmap + s32(rec + 4);
         int format = u16(sub);
         int score;
         if (platform == 3 && encoding == 10 && format == 12) {
            score = 4;
         } else if (platform == 3 && encoding == 1 && format == 4) {
            score = 3;
         } else if (platform == 0 && format == 4) {
            score = 2;
         } else if (platform == 3 && encoding == 0 && format == 4) {
            score = 1;
         } else {
            continue;
         }
         if (score > bestScore) {
            bestScore = score;
            best = sub;
            bestFormat = format;
         }
      }
      if (best < 0) {
         throw new IllegalArgumentException(name + ": no Unicode character map");
      }
      cmapOffset = best;
      cmapFormat = bestFormat;
   }

   private int u8(int i) {
      return data[i] & 0xFF;
   }

   private int u16(int i) {
      return ((data[i] & 0xFF) << 8) | (data[i + 1] & 0xFF);
   }

   private int s16(int i) {
      return (short) u16(i);
   }

   private int s32(int i) {
      return ((data[i] & 0xFF) << 24) | ((data[i + 1] & 0xFF) << 16) | ((data[i + 2] & 0xFF) << 8) | (data[i + 3] & 0xFF);
   }

   /** The glyph of a character (0, the missing glyph, if the font has none). */
   public int glyphIndex(int c) {
      if (cmapFormat == 4) {
         int segX2 = u16(cmapOffset + 6);
         int ends = cmapOffset + 14;
         int starts = ends + segX2 + 2;
         int deltas = starts + segX2;
         int ranges = deltas + segX2;
         int lo = 0;
         int hi = segX2 / 2 - 1;
         while (lo <= hi) {
            int mid = (lo + hi) >>> 1;
            int end = u16(ends + mid * 2);
            if (end < c) {
               lo = mid + 1;
            } else {
               int start = u16(starts + mid * 2);
               if (start > c) {
                  hi = mid - 1;
               } else {
                  int delta = u16(deltas + mid * 2);
                  int rangeOffset = u16(ranges + mid * 2);
                  if (rangeOffset == 0) {
                     return (c + delta) & 0xFFFF;
                  }
                  int at = ranges + mid * 2 + rangeOffset + (c - start) * 2;
                  int g = u16(at);
                  return g == 0 ? 0 : (g + delta) & 0xFFFF;
               }
            }
         }
         return 0;
      }
      int groups = s32(cmapOffset + 12);
      int lo = 0;
      int hi = groups - 1;
      while (lo <= hi) {
         int mid = (lo + hi) >>> 1;
         int rec = cmapOffset + 16 + mid * 12;
         int start = s32(rec);
         int end = s32(rec + 4);
         if (c < start) {
            hi = mid - 1;
         } else if (c > end) {
            lo = mid + 1;
         } else {
            return s32(rec + 8) + (c - start);
         }
      }
      return 0;
   }

   public int advanceWidth(int glyph) {
      if (glyph < numberOfHMetrics) {
         return u16(hmtx + glyph * 4);
      }
      return u16(hmtx + (numberOfHMetrics - 1) * 4);
   }

   private int glyphOffset(int glyph) {
      if (glyph < 0 || glyph >= numGlyphs) {
         return -1;
      }
      if (longLoca) {
         return s32(loca + glyph * 4);
      }
      return u16(loca + glyph * 2) * 2;
   }

   private int glyphLength(int glyph) {
      int a = glyphOffset(glyph);
      int b = glyphOffset(glyph + 1);
      return a < 0 || b < 0 ? 0 : b - a;
   }

   /** The outline in font units (y up): contours of points, each with an on-curve flag. */
   static final class Outline {
      int[][] xs = new int[0][];
      int[][] ys = new int[0][];
      boolean[][] on = new boolean[0][];
      int xMin;
      int yMin;
      int xMax;
      int yMax;
   }

   Outline outline(int glyph) {
      Outline o = new Outline();
      outline(glyph, o, 1, 0, 0, 1, 0, 0, 0);
      return o;
   }

   private static final int ON_CURVE = 1;
   private static final int X_SHORT = 2;
   private static final int Y_SHORT = 4;
   private static final int REPEAT = 8;
   private static final int X_SAME = 16;
   private static final int Y_SAME = 32;

   private void outline(int glyph, Outline o, double a, double b, double c, double d, double e, double f, int depth) {
      if (depth > 8 || glyphLength(glyph) == 0) {
         return;
      }
      int at = glyf + glyphOffset(glyph);
      int contours = s16(at);
      if (depth == 0) {
         o.xMin = s16(at + 2);
         o.yMin = s16(at + 4);
         o.xMax = s16(at + 6);
         o.yMax = s16(at + 8);
      }
      if (contours >= 0) {
         int p = at + 10;
         int[] ends = new int[contours];
         for (int i = 0; i < contours; i++) {
            ends[i] = u16(p);
            p += 2;
         }
         int points = contours == 0 ? 0 : ends[contours - 1] + 1;
         int instructions = u16(p);
         p += 2 + instructions;
         int[] flags = new int[points];
         for (int i = 0; i < points; i++) {
            int fl = u8(p++);
            flags[i] = fl;
            if ((fl & REPEAT) != 0) {
               int count = u8(p++);
               for (int k = 0; k < count && i + 1 < points; k++) {
                  flags[++i] = fl;
               }
            }
         }
         int[] px = new int[points];
         int[] py = new int[points];
         int v = 0;
         for (int i = 0; i < points; i++) {
            int fl = flags[i];
            if ((fl & X_SHORT) != 0) {
               int dx = u8(p++);
               v += (fl & X_SAME) != 0 ? dx : -dx;
            } else if ((fl & X_SAME) == 0) {
               v += s16(p);
               p += 2;
            }
            px[i] = v;
         }
         v = 0;
         for (int i = 0; i < points; i++) {
            int fl = flags[i];
            if ((fl & Y_SHORT) != 0) {
               int dy = u8(p++);
               v += (fl & Y_SAME) != 0 ? dy : -dy;
            } else if ((fl & Y_SAME) == 0) {
               v += s16(p);
               p += 2;
            }
            py[i] = v;
         }
         int start = 0;
         int base = o.xs.length;
         int[][] nxs = new int[base + contours][];
         int[][] nys = new int[base + contours][];
         boolean[][] non = new boolean[base + contours][];
         System.arraycopy(o.xs, 0, nxs, 0, base);
         System.arraycopy(o.ys, 0, nys, 0, base);
         System.arraycopy(o.on, 0, non, 0, base);
         for (int k = 0; k < contours; k++) {
            int end = ends[k];
            int n = end - start + 1;
            int[] cx = new int[Math.max(0, n)];
            int[] cy = new int[Math.max(0, n)];
            boolean[] con = new boolean[Math.max(0, n)];
            for (int i = 0; i < n; i++) {
               int x = px[start + i];
               int y = py[start + i];
               cx[i] = (int) Math.round(a * x + c * y + e);
               cy[i] = (int) Math.round(b * x + d * y + f);
               con[i] = (flags[start + i] & ON_CURVE) != 0;
            }
            nxs[base + k] = cx;
            nys[base + k] = cy;
            non[base + k] = con;
            start = end + 1;
         }
         o.xs = nxs;
         o.ys = nys;
         o.on = non;
         return;
      }
      // composite glyph
      int p = at + 10;
      while (true) {
         int fl = u16(p);
         int index = u16(p + 2);
         p += 4;
         int arg1;
         int arg2;
         if ((fl & 1) != 0) {
            arg1 = s16(p);
            arg2 = s16(p + 2);
            p += 4;
         } else {
            arg1 = (byte) data[p];
            arg2 = (byte) data[p + 1];
            p += 2;
         }
         double ta = 1, tb = 0, tc = 0, td = 1;
         if ((fl & 8) != 0) {
            ta = td = f2dot14(p);
            p += 2;
         } else if ((fl & 0x40) != 0) {
            ta = f2dot14(p);
            td = f2dot14(p + 2);
            p += 4;
         } else if ((fl & 0x80) != 0) {
            ta = f2dot14(p);
            tb = f2dot14(p + 2);
            tc = f2dot14(p + 4);
            td = f2dot14(p + 6);
            p += 8;
         }
         double te = (fl & 2) != 0 ? arg1 : 0;
         double tf = (fl & 2) != 0 ? arg2 : 0;
         // compose: parent(child(x))
         double na = a * ta + c * tb;
         double nb = b * ta + d * tb;
         double nc = a * tc + c * td;
         double nd = b * tc + d * td;
         double ne = a * te + c * tf + e;
         double nf = b * te + d * tf + f;
         outline(index, o, na, nb, nc, nd, ne, nf, depth + 1);
         if ((fl & 0x20) == 0) {
            break;
         }
      }
   }

   private double f2dot14(int i) {
      return s16(i) / 16384.0;
   }
}
