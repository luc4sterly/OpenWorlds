package net.openworlds.awt;

import java.util.HashMap;

/**
 * A TrueType font at one pixel size: Java2D's integer metrics (ascent,
 * descent and leading rounded up as FontDesignMetrics does, advances
 * rounded) and the glyphs, rasterized by exact area coverage and cached.
 */
public final class FontFace {
   private final TrueTypeFont font;
   private final float size;
   private final double scale;
   public final int ascent;
   public final int descent;
   public final int leading;
   /** Exact values, for LineMetrics. */
   public final float ascentF;
   public final float descentF;
   public final float leadingF;
   private final HashMap<Integer, Glyph> smooth = new HashMap<Integer, Glyph>();
   private final HashMap<Integer, Glyph> sharp = new HashMap<Integer, Glyph>();
   private final int[] advances = new int[256];

   FontFace(TrueTypeFont font, float size) {
      this.font = font;
      this.size = size;
      this.scale = size / font.unitsPerEm;
      ascentF = (float) (font.ascender * scale);
      descentF = (float) (-font.descender * scale);
      leadingF = (float) (font.lineGap * scale);
      // FontDesignMetrics: (int) (0.95f + value)
      ascent = (int) (0.95f + ascentF);
      descent = (int) (0.95f + descentF);
      leading = (int) (0.95f + descentF + leadingF) - (int) (0.95f + descentF);
      for (int i = 0; i < advances.length; i++) {
         advances[i] = -1;
      }
   }

   public float size() {
      return size;
   }

   public int advance(char c) {
      if (c < 256) {
         int a = advances[c];
         if (a < 0) {
            a = computeAdvance(c);
            advances[c] = a;
         }
         return a;
      }
      return computeAdvance(c);
   }

   private int computeAdvance(char c) {
      if (c == '\t' || c == '\n' || c == '\r') {
         return computeAdvance(' ');
      }
      int g = font.glyphIndex(c);
      return (int) Math.round(font.advanceWidth(g) * scale);
   }

   public float advanceExact(char c) {
      return (float) (font.advanceWidth(font.glyphIndex(c)) * scale);
   }

   public int stringWidth(String s) {
      int w = 0;
      for (int i = 0; i < s.length(); i++) {
         w += advance(s.charAt(i));
      }
      return w;
   }

   public Glyph glyph(char c, boolean antialiased) {
      HashMap<Integer, Glyph> cache = antialiased ? smooth : sharp;
      synchronized (cache) {
         Integer key = Integer.valueOf(c);
         Glyph g = cache.get(key);
         if (g == null && !cache.containsKey(key)) {
            g = rasterize(c, antialiased);
            cache.put(key, g);
         }
         return g;
      }
   }

   /** The text's outline, its baseline at (x, y), y down. */
   public GlyphPath outline(String s, float x, float y) {
      java.util.ArrayList<double[]> xs = new java.util.ArrayList<double[]>();
      java.util.ArrayList<double[]> ys = new java.util.ArrayList<double[]>();
      double pen = x;
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         TrueTypeFont.Outline o = font.outline(font.glyphIndex(c));
         for (int k = 0; k < o.xs.length; k++) {
            double[][] poly = flatten(o.xs[k], o.ys[k], o.on[k], pen, y);
            if (poly[0].length >= 3) {
               xs.add(poly[0]);
               ys.add(poly[1]);
            }
         }
         pen += font.advanceWidth(font.glyphIndex(c)) * scale;
      }
      return new GlyphPath(xs.toArray(new double[xs.size()][]), ys.toArray(new double[ys.size()][]));
   }

   /** A contour as a polygon in pixels (y down), its quadratic curves cut in segments, placed at (ox, oy). */
   private double[][] flatten(int[] cx, int[] cy, boolean[] on, double ox, double oy) {
      int n = cx.length;
      DoubleList px = new DoubleList();
      DoubleList py = new DoubleList();
      if (n == 0) {
         return new double[][]{new double[0], new double[0]};
      }
      // start at an on-curve point (or the middle of the first two off ones)
      int first = -1;
      for (int i = 0; i < n; i++) {
         if (on[i]) {
            first = i;
            break;
         }
      }
      double sx;
      double sy;
      if (first < 0) {
         sx = (cx[0] + cx[1 % n]) / 2.0;
         sy = (cy[0] + cy[1 % n]) / 2.0;
         first = 0;
      } else {
         sx = cx[first];
         sy = cy[first];
      }
      double curX = sx;
      double curY = sy;
      px.add(ox + curX * scale);
      py.add(oy - curY * scale);
      int steps = Math.max(2, Math.min(16, (int) (size / 3)));
      int i = first + 1;
      for (int count = 0; count < n; count++, i++) {
         int k = i % n;
         if (on[k]) {
            curX = cx[k];
            curY = cy[k];
            px.add(ox + curX * scale);
            py.add(oy - curY * scale);
         } else {
            int nk = (k + 1) % n;
            double ex;
            double ey;
            if (on[nk]) {
               ex = cx[nk];
               ey = cy[nk];
               i++;
               count++;
            } else {
               ex = (cx[k] + cx[nk]) / 2.0;
               ey = (cy[k] + cy[nk]) / 2.0;
            }
            for (int s = 1; s <= steps; s++) {
               double t = (double) s / steps;
               double mt = 1 - t;
               double qx = mt * mt * curX + 2 * mt * t * cx[k] + t * t * ex;
               double qy = mt * mt * curY + 2 * mt * t * cy[k] + t * t * ey;
               px.add(ox + qx * scale);
               py.add(oy - qy * scale);
            }
            curX = ex;
            curY = ey;
         }
      }
      return new double[][]{px.toArray(), py.toArray()};
   }

   private Glyph rasterize(char c, boolean antialiased) {
      int g = font.glyphIndex(c);
      TrueTypeFont.Outline o = font.outline(g);
      if (o.xs.length == 0) {
         return new Glyph(0, 0, 0, 0, new byte[0]);
      }
      int left = (int) Math.floor(o.xMin * scale);
      int right = (int) Math.ceil(o.xMax * scale);
      int top = (int) Math.ceil(o.yMax * scale);
      int bottom = (int) Math.floor(o.yMin * scale);
      int w = Math.max(1, right - left + 1);
      int h = Math.max(1, top - bottom + 1);
      float[] acc = new float[w * h + 4];
      for (int k = 0; k < o.xs.length; k++) {
         double[][] poly = flatten(o.xs[k], o.ys[k], o.on[k], -left, top);
         double[] xs = poly[0];
         double[] ys = poly[1];
         int n = xs.length;
         for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            line(acc, w, h, xs[i], ys[i], xs[j], ys[j]);
         }
      }
      byte[] cov = new byte[w * h];
      float sum = 0;
      for (int i = 0; i < w * h; i++) {
         sum += acc[i];
         float v = Math.abs(sum);
         if (v > 1) {
            v = 1;
         }
         int a = (int) (v * 255 + 0.5f);
         if (!antialiased) {
            a = a >= 128 ? 255 : 0;
         }
         cov[i] = (byte) a;
      }
      return new Glyph(w, h, left, -top, cov);
   }

   /** Signed area coverage of one edge (font-rs' accumulation rasterizer). */
   private static void line(float[] a, int w, int h, double x0d, double y0d, double x1d, double y1d) {
      float x0p = (float) x0d;
      float y0p = (float) y0d;
      float x1p = (float) x1d;
      float y1p = (float) y1d;
      if (Math.abs(y0p - y1p) <= 1e-6f) {
         return;
      }
      float dir;
      float ax, ay, bx, by;
      if (y0p < y1p) {
         dir = 1f;
         ax = x0p;
         ay = y0p;
         bx = x1p;
         by = y1p;
      } else {
         dir = -1f;
         ax = x1p;
         ay = y1p;
         bx = x0p;
         by = y0p;
      }
      float dxdy = (bx - ax) / (by - ay);
      float x = ax;
      int ystart = (int) Math.max(0, ay);
      if (ay < 0) {
         x -= ay * dxdy;
      }
      int yend = Math.min(h, (int) Math.ceil(by));
      for (int y = ystart; y < yend; y++) {
         int linestart = y * w;
         float dy = Math.min(y + 1f, by) - Math.max((float) y, ay);
         float xnext = x + dxdy * dy;
         float d = dy * dir;
         float xa = Math.min(x, xnext);
         float xb = Math.max(x, xnext);
         float x0floor = (float) Math.floor(xa);
         int x0i = (int) x0floor;
         float x1ceil = (float) Math.ceil(xb);
         int x1i = (int) x1ceil;
         if (x0i < 0) {
            x0i = 0;
            x0floor = 0;
         }
         if (x1i <= x0i + 1) {
            float xmf = 0.5f * (x + xnext) - x0floor;
            int i = linestart + x0i;
            if (i >= 0 && i + 1 < a.length) {
               a[i] += d - d * xmf;
               a[i + 1] += d * xmf;
            }
         } else {
            float s = 1f / (xb - xa);
            float x0f = xa - x0floor;
            float a0 = 0.5f * s * (1f - x0f) * (1f - x0f);
            float x1f = xb - x1ceil + 1f;
            float am = 0.5f * s * x1f * x1f;
            int i0 = linestart + x0i;
            if (i0 < 0 || linestart + x1i >= a.length) {
               x = xnext;
               continue;
            }
            a[i0] += d * a0;
            if (x1i == x0i + 2) {
               a[i0 + 1] += d * (1f - a0 - am);
            } else {
               float a1 = s * (1.5f - x0f);
               a[i0 + 1] += d * (a1 - a0);
               for (int xi = x0i + 2; xi < x1i - 1; xi++) {
                  a[linestart + xi] += d * s;
               }
               float a2 = a1 + (x1i - x0i - 3) * s;
               a[linestart + x1i - 1] += d * (1f - a2 - am);
            }
            a[linestart + x1i] += d * am;
         }
         x = xnext;
      }
   }

   private static final class DoubleList {
      double[] v = new double[64];
      int n;

      void add(double d) {
         if (n == v.length) {
            double[] nv = new double[n * 2];
            System.arraycopy(v, 0, nv, 0, n);
            v = nv;
         }
         v[n++] = d;
      }

      double[] toArray() {
         double[] out = new double[n];
         System.arraycopy(v, 0, out, 0, n);
         return out;
      }
   }
}
