package java.awt;

import java.awt.font.FontRenderContext;
import java.awt.image.BufferedImage;
import java.awt.image.ImageObserver;
import java.text.AttributedCharacterIterator;
import java.util.Map;

import net.openworlds.awt.FontFace;
import net.openworlds.awt.Glyph;
import net.openworlds.awt.GlyphPath;

/**
 * Drawing into ARGB pixels: a window's ({@link Window#pixels}) or an
 * image's. Software only, as the 2004 client's AWT drawing went through
 * GDI: no antialiasing except for text.
 */
final class SurfaceGraphics extends Graphics2D {
   /** Where the pixels are: a Window or a BufferedImage. */
   private final Object owner;
   private final Window window;
   private final BufferedImage image;
   private int[] pixels;
   private int width;
   private int height;
   private boolean intPixels;
   private boolean opaqueTarget;

   /** Origin of the user space in the target's pixels. */
   private int originX;
   private int originY;
   /** The clip the creator gave, and the user's clip inside it (both in the target's pixels; never null). */
   private final Rectangle deviceClip;
   private Rectangle clip;

   private Color color = Color.black;
   private int argb = 0xFF000000;
   private Color xorColor;
   private Color background = Color.black;
   private Font font = Theme.DIALOG_FONT;
   private RenderingHints hints = new RenderingHints(null);
   private boolean disposed;

   SurfaceGraphics(Window w, int originX, int originY, Rectangle clip) {
      this.owner = w;
      this.window = w;
      this.image = null;
      this.originX = originX;
      this.originY = originY;
      this.deviceClip = new Rectangle(clip);
      this.clip = new Rectangle(clip);
   }

   SurfaceGraphics(BufferedImage img) {
      this.owner = img;
      this.window = null;
      this.image = img;
      this.deviceClip = new Rectangle(0, 0, img.getWidth(), img.getHeight());
      this.clip = new Rectangle(deviceClip);
      this.color = Color.white;
      this.argb = 0xFFFFFFFF;
      this.background = Color.black;
   }

   private SurfaceGraphics(SurfaceGraphics g) {
      this.owner = g.owner;
      this.window = g.window;
      this.image = g.image;
      this.originX = g.originX;
      this.originY = g.originY;
      this.deviceClip = new Rectangle(g.deviceClip);
      this.clip = new Rectangle(g.clip);
      this.color = g.color;
      this.argb = g.argb;
      this.xorColor = g.xorColor;
      this.background = g.background;
      this.font = g.font;
      this.hints = (RenderingHints) g.hints.clone();
   }

   /** Picks up the target's current pixels (a window's are replaced when it is resized). */
   private boolean bind() {
      if (disposed) {
         return false;
      }
      if (window != null) {
         int[] p = window.pixels;
         if (p == null) {
            return false;
         }
         pixels = p;
         width = window.pixelsWidth;
         height = window.pixelsHeight;
         intPixels = true;
         opaqueTarget = true;
      } else {
         width = image.getWidth();
         height = image.getHeight();
         int[] p = image.intPixels();
         pixels = p;
         intPixels = p != null;
         opaqueTarget = !image.getColorModel().hasAlpha();
      }
      return true;
   }

   private void damage(int x, int y, int w, int h) {
      if (window != null) {
         WindowSystem.damage(window, x, y, w, h);
      }
   }

   /** The rectangle (device pixels) clipped, or null if nothing is left. */
   private Rectangle clipped(int x, int y, int w, int h) {
      Rectangle r = new Rectangle(x, y, w, h).intersection(clip).intersection(new Rectangle(0, 0, width, height));
      return r.width > 0 && r.height > 0 ? r : null;
   }

   // ------------------------------------------------------------------ pixels

   private void plot(int x, int y, int c) {
      if (intPixels) {
         int i = y * width + x;
         pixels[i] = blend(pixels[i], c);
      } else {
         image.setRGB(x, y, blend(image.getRGB(x, y), c));
      }
   }

   private int blend(int dst, int c) {
      if (xorColor != null) {
         return dst ^ ((c ^ xorColor.getRGB()) & 0x00FFFFFF);
      }
      int a = c >>> 24;
      if (a == 255) {
         return c;
      }
      if (a == 0) {
         return dst;
      }
      int da = dst >>> 24;
      int ia = 255 - a;
      int r = (((c >> 16) & 0xFF) * a + ((dst >> 16) & 0xFF) * ia) / 255;
      int g = (((c >> 8) & 0xFF) * a + ((dst >> 8) & 0xFF) * ia) / 255;
      int b = ((c & 0xFF) * a + (dst & 0xFF) * ia) / 255;
      int na = opaqueTarget ? 255 : Math.min(255, a + da * ia / 255);
      return (na << 24) | (r << 16) | (g << 8) | b;
   }

   /** A horizontal run in device pixels, already clipped. */
   private void span(int y, int x0, int x1, int c) {
      if (intPixels && xorColor == null && (c >>> 24) == 255) {
         java.util.Arrays.fill(pixels, y * width + x0, y * width + x1, c);
         return;
      }
      for (int x = x0; x < x1; x++) {
         plot(x, y, c);
      }
   }

   private void fillDevice(Rectangle r, int c) {
      for (int y = r.y; y < r.y + r.height; y++) {
         span(y, r.x, r.x + r.width, c);
      }
      damage(r.x, r.y, r.width, r.height);
   }

   /** One pixel in user space, clipped. */
   private void point(int ux, int uy) {
      int x = ux + originX;
      int y = uy + originY;
      if (x >= clip.x && y >= clip.y && x < clip.x + clip.width && y < clip.y + clip.height && x >= 0 && y >= 0 && x < width
            && y < height) {
         plot(x, y, argb);
      }
   }

   // ------------------------------------------------------------------ state

   public Graphics create() {
      return new SurfaceGraphics(this);
   }

   public void translate(int x, int y) {
      originX += x;
      originY += y;
   }

   public void translate(double tx, double ty) {
      translate((int) Math.round(tx), (int) Math.round(ty));
   }

   public Color getColor() {
      return color;
   }

   public void setColor(Color c) {
      if (c != null) {
         color = c;
         argb = c.getRGB();
      }
   }

   public void setPaintMode() {
      xorColor = null;
   }

   public void setXORMode(Color c1) {
      xorColor = c1;
   }

   public Font getFont() {
      return font;
   }

   public void setFont(Font f) {
      if (f != null) {
         font = f;
      }
   }

   public FontMetrics getFontMetrics(Font f) {
      return FontMetrics.of(f);
   }

   public void setBackground(Color c) {
      if (c != null) {
         background = c;
      }
   }

   public Color getBackground() {
      return background;
   }

   public Rectangle getClipBounds() {
      return new Rectangle(clip.x - originX, clip.y - originY, clip.width, clip.height);
   }

   public void clipRect(int x, int y, int w, int h) {
      clip = clip.intersection(new Rectangle(x + originX, y + originY, w, h));
      if (clip.width < 0) {
         clip.width = 0;
      }
      if (clip.height < 0) {
         clip.height = 0;
      }
   }

   public void setClip(int x, int y, int w, int h) {
      clip = deviceClip.intersection(new Rectangle(x + originX, y + originY, w, h));
      if (clip.width < 0) {
         clip.width = 0;
      }
      if (clip.height < 0) {
         clip.height = 0;
      }
   }

   public Shape getClip() {
      return getClipBounds();
   }

   public void setClip(Shape s) {
      if (s == null) {
         clip = new Rectangle(deviceClip);
      } else {
         Rectangle r = s.getBounds();
         setClip(r.x, r.y, r.width, r.height);
      }
   }

   public void setRenderingHint(RenderingHints.Key key, Object value) {
      hints.put(key, value);
   }

   public Object getRenderingHint(RenderingHints.Key key) {
      return hints.get(key);
   }

   public void setRenderingHints(Map<?, ?> h) {
      hints.clear();
      hints.putAll(h);
   }

   public void addRenderingHints(Map<?, ?> h) {
      hints.putAll(h);
   }

   public RenderingHints getRenderingHints() {
      return (RenderingHints) hints.clone();
   }

   public FontRenderContext getFontRenderContext() {
      return new FontRenderContext(null, textAntialiased(), false);
   }

   public void dispose() {
      disposed = true;
   }

   // ------------------------------------------------------------------ shapes

   public void fillRect(int x, int y, int w, int h) {
      if (w <= 0 || h <= 0 || !bind()) {
         return;
      }
      Rectangle r = clipped(x + originX, y + originY, w, h);
      if (r != null) {
         fillDevice(r, argb);
      }
   }

   public void clearRect(int x, int y, int w, int h) {
      if (w <= 0 || h <= 0 || !bind()) {
         return;
      }
      Rectangle r = clipped(x + originX, y + originY, w, h);
      if (r != null) {
         Color save = xorColor;
         xorColor = null;
         fillDevice(r, background.getRGB() | (opaqueTarget ? 0xFF000000 : 0));
         xorColor = save;
      }
   }

   public void drawLine(int x1, int y1, int x2, int y2) {
      if (!bind()) {
         return;
      }
      if (y1 == y2) {
         int a = Math.min(x1, x2);
         int b = Math.max(x1, x2);
         Rectangle r = clipped(a + originX, y1 + originY, b - a + 1, 1);
         if (r != null) {
            fillDevice(r, argb);
         }
         return;
      }
      if (x1 == x2) {
         int a = Math.min(y1, y2);
         int b = Math.max(y1, y2);
         Rectangle r = clipped(x1 + originX, a + originY, 1, b - a + 1);
         if (r != null) {
            fillDevice(r, argb);
         }
         return;
      }
      int dx = Math.abs(x2 - x1);
      int dy = -Math.abs(y2 - y1);
      int sx = x1 < x2 ? 1 : -1;
      int sy = y1 < y2 ? 1 : -1;
      int err = dx + dy;
      int x = x1;
      int y = y1;
      while (true) {
         point(x, y);
         if (x == x2 && y == y2) {
            break;
         }
         int e2 = 2 * err;
         if (e2 >= dy) {
            err += dy;
            x += sx;
         }
         if (e2 <= dx) {
            err += dx;
            y += sy;
         }
      }
      damage(Math.min(x1, x2) + originX, Math.min(y1, y2) + originY, dx + 1, -dy + 1);
   }

   public void drawPolyline(int[] xs, int[] ys, int n) {
      for (int i = 0; i + 1 < n; i++) {
         drawLine(xs[i], ys[i], xs[i + 1], ys[i + 1]);
      }
   }

   public void drawPolygon(int[] xs, int[] ys, int n) {
      if (n <= 0) {
         return;
      }
      drawPolyline(xs, ys, n);
      drawLine(xs[n - 1], ys[n - 1], xs[0], ys[0]);
   }

   /** Even-odd scanline fill through pixel centres, as AWT's fillPolygon. */
   public void fillPolygon(int[] xs, int[] ys, int n) {
      if (n < 3 || !bind()) {
         return;
      }
      double[] fx = new double[n];
      double[] fy = new double[n];
      for (int i = 0; i < n; i++) {
         fx[i] = xs[i];
         fy[i] = ys[i];
      }
      fillPolygons(new double[][]{fx}, new double[][]{fy}, new int[]{n}, true);
   }

   /** Scanline fill of closed polygons (user space), even-odd or non-zero winding. */
   private void fillPolygons(double[][] pxs, double[][] pys, int[] counts, boolean evenOdd) {
      double minY = Double.MAX_VALUE;
      double maxY = -Double.MAX_VALUE;
      double minX = Double.MAX_VALUE;
      double maxX = -Double.MAX_VALUE;
      int edges = 0;
      for (int p = 0; p < pxs.length; p++) {
         for (int i = 0; i < counts[p]; i++) {
            minY = Math.min(minY, pys[p][i]);
            maxY = Math.max(maxY, pys[p][i]);
            minX = Math.min(minX, pxs[p][i]);
            maxX = Math.max(maxX, pxs[p][i]);
         }
         edges += counts[p];
      }
      if (edges == 0) {
         return;
      }
      int y0 = (int) Math.max(Math.ceil(minY - 0.5), clip.y - originY);
      int y1 = (int) Math.min(Math.floor(maxY - 0.5), clip.y + clip.height - 1 - originY);
      double[] xsAt = new double[edges];
      int[] dirs = new int[edges];
      for (int y = y0; y <= y1; y++) {
         double cy = y + 0.5;
         int k = 0;
         for (int p = 0; p < pxs.length; p++) {
            int n = counts[p];
            double[] px = pxs[p];
            double[] py = pys[p];
            for (int i = 0; i < n; i++) {
               int j = (i + 1) % n;
               double ya = py[i];
               double yb = py[j];
               if ((ya <= cy && yb > cy) || (yb <= cy && ya > cy)) {
                  xsAt[k] = px[i] + (cy - ya) * (px[j] - px[i]) / (yb - ya);
                  dirs[k] = ya < yb ? 1 : -1;
                  k++;
               }
            }
         }
         // insertion sort, few crossings
         for (int a = 1; a < k; a++) {
            double v = xsAt[a];
            int d = dirs[a];
            int b = a - 1;
            while (b >= 0 && xsAt[b] > v) {
               xsAt[b + 1] = xsAt[b];
               dirs[b + 1] = dirs[b];
               b--;
            }
            xsAt[b + 1] = v;
            dirs[b + 1] = d;
         }
         int winding = 0;
         for (int a = 0; a + 1 < k; a++) {
            winding += dirs[a];
            boolean inside = evenOdd ? (a % 2 == 0) : winding != 0;
            if (!inside) {
               continue;
            }
            int xa = (int) Math.ceil(xsAt[a] - 0.5);
            int xb = (int) Math.ceil(xsAt[a + 1] - 0.5);
            if (xb > xa) {
               Rectangle r = clipped(xa + originX, y + originY, xb - xa, 1);
               if (r != null) {
                  span(r.y, r.x, r.x + r.width, argb);
               }
            }
         }
      }
      damage((int) Math.floor(minX) + originX, (int) Math.floor(minY) + originY, (int) Math.ceil(maxX - minX) + 1,
            (int) Math.ceil(maxY - minY) + 1);
   }

   public void drawRoundRect(int x, int y, int w, int h, int aw, int ah) {
      if (aw <= 0 || ah <= 0) {
         drawRect(x, y, w, h);
         return;
      }
      int[][] p = roundRect(x, y, w, h, aw, ah);
      drawPolygon(p[0], p[1], p[0].length);
   }

   public void fillRoundRect(int x, int y, int w, int h, int aw, int ah) {
      if (aw <= 0 || ah <= 0) {
         fillRect(x, y, w, h);
         return;
      }
      int[][] p = roundRect(x, y, w, h, aw, ah);
      fillPolygon(p[0], p[1], p[0].length);
   }

   private static int[][] roundRect(int x, int y, int w, int h, int aw, int ah) {
      aw = Math.min(aw, w);
      ah = Math.min(ah, h);
      int steps = 8;
      int n = 4 * (steps + 1);
      int[] xs = new int[n];
      int[] ys = new int[n];
      double rx = aw / 2.0;
      double ry = ah / 2.0;
      double[][] centres = {{x + w - rx, y + ry}, {x + rx, y + ry}, {x + rx, y + h - ry}, {x + w - rx, y + h - ry}};
      int k = 0;
      for (int c = 0; c < 4; c++) {
         for (int i = 0; i <= steps; i++) {
            double a = Math.PI / 2 * (c + (double) i / steps);
            xs[k] = (int) Math.round(centres[c][0] + rx * Math.cos(a));
            ys[k] = (int) Math.round(centres[c][1] - ry * Math.sin(a));
            k++;
         }
      }
      return new int[][]{xs, ys};
   }

   public void drawOval(int x, int y, int w, int h) {
      drawArc(x, y, w, h, 0, 360);
   }

   public void fillOval(int x, int y, int w, int h) {
      fillArc(x, y, w, h, 0, 360);
   }

   public void drawArc(int x, int y, int w, int h, int start, int extent) {
      if (w < 0 || h < 0) {
         return;
      }
      int[][] p = arc(x, y, w, h, start, extent, false);
      drawPolyline(p[0], p[1], p[0].length);
   }

   public void fillArc(int x, int y, int w, int h, int start, int extent) {
      if (w <= 0 || h <= 0) {
         return;
      }
      boolean full = Math.abs(extent) >= 360;
      int[][] p = arc(x, y, w, h, start, extent, !full);
      fillPolygon(p[0], p[1], p[0].length);
   }

   private static int[][] arc(int x, int y, int w, int h, int start, int extent, boolean pie) {
      if (extent > 360) {
         extent = 360;
      } else if (extent < -360) {
         extent = -360;
      }
      double rx = w / 2.0;
      double ry = h / 2.0;
      double cx = x + rx;
      double cy = y + ry;
      int steps = Math.max(8, (int) (Math.abs(extent) / 360.0 * Math.max(16, (w + h) / 2)));
      int n = steps + 1 + (pie ? 1 : 0);
      int[] xs = new int[n];
      int[] ys = new int[n];
      for (int i = 0; i <= steps; i++) {
         double a = Math.toRadians(start + (double) extent * i / steps);
         xs[i] = (int) Math.round(cx + rx * Math.cos(a));
         ys[i] = (int) Math.round(cy - ry * Math.sin(a));
      }
      if (pie) {
         xs[n - 1] = (int) Math.round(cx);
         ys[n - 1] = (int) Math.round(cy);
      }
      return new int[][]{xs, ys};
   }

   public void copyArea(int x, int y, int w, int h, int dx, int dy) {
      if (w <= 0 || h <= 0 || !bind()) {
         return;
      }
      Rectangle src = new Rectangle(x + originX, y + originY, w, h).intersection(new Rectangle(0, 0, width, height));
      Rectangle dst = new Rectangle(src.x + dx, src.y + dy, src.width, src.height).intersection(clip)
            .intersection(new Rectangle(0, 0, width, height));
      if (dst.width <= 0 || dst.height <= 0) {
         return;
      }
      int sx = dst.x - dx;
      int sy = dst.y - dy;
      int[] tmp = new int[dst.width * dst.height];
      for (int row = 0; row < dst.height; row++) {
         for (int col = 0; col < dst.width; col++) {
            tmp[row * dst.width + col] = intPixels ? pixels[(sy + row) * width + sx + col] : image.getRGB(sx + col, sy + row);
         }
      }
      for (int row = 0; row < dst.height; row++) {
         if (intPixels) {
            System.arraycopy(tmp, row * dst.width, pixels, (dst.y + row) * width + dst.x, dst.width);
         } else {
            for (int col = 0; col < dst.width; col++) {
               image.setRGB(dst.x + col, dst.y + row, tmp[row * dst.width + col]);
            }
         }
      }
      damage(dst.x, dst.y, dst.width, dst.height);
   }

   public void draw(Shape s) {
      if (s instanceof Rectangle) {
         Rectangle r = (Rectangle) s;
         drawRect(r.x, r.y, r.width, r.height);
      } else if (s instanceof Polygon) {
         drawPolygon((Polygon) s);
      } else if (s instanceof GlyphPath) {
         GlyphPath p = (GlyphPath) s;
         for (int c = 0; c < p.contours(); c++) {
            double[] xs = p.xs(c);
            double[] ys = p.ys(c);
            int n = xs.length;
            for (int i = 0; i < n; i++) {
               int j = (i + 1) % n;
               drawLine((int) Math.round(xs[i]), (int) Math.round(ys[i]), (int) Math.round(xs[j]), (int) Math.round(ys[j]));
            }
         }
      } else if (s != null) {
         Rectangle r = s.getBounds();
         drawRect(r.x, r.y, r.width, r.height);
      }
   }

   public void fill(Shape s) {
      if (s instanceof Rectangle) {
         Rectangle r = (Rectangle) s;
         fillRect(r.x, r.y, r.width, r.height);
      } else if (s instanceof Polygon) {
         fillPolygon((Polygon) s);
      } else if (s instanceof GlyphPath) {
         if (!bind()) {
            return;
         }
         GlyphPath p = (GlyphPath) s;
         int n = p.contours();
         double[][] xs = new double[n][];
         double[][] ys = new double[n][];
         int[] counts = new int[n];
         for (int c = 0; c < n; c++) {
            xs[c] = p.xs(c);
            ys[c] = p.ys(c);
            counts[c] = xs[c].length;
         }
         fillPolygons(xs, ys, counts, false);
      } else if (s != null) {
         if (!bind()) {
            return;
         }
         Rectangle b = s.getBounds();
         for (int y = b.y; y < b.y + b.height; y++) {
            for (int x = b.x; x < b.x + b.width; x++) {
               if (s.contains(x + 0.5, y + 0.5)) {
                  point(x, y);
               }
            }
         }
         damage(b.x + originX, b.y + originY, b.width, b.height);
      }
   }

   // ------------------------------------------------------------------ text

   private boolean textAntialiased() {
      Object v = hints.get(RenderingHints.KEY_TEXT_ANTIALIASING);
      if (v == RenderingHints.VALUE_TEXT_ANTIALIAS_OFF) {
         return false;
      }
      if (v == RenderingHints.VALUE_TEXT_ANTIALIAS_ON) {
         return true;
      }
      return Toolkit.textAntialiasing();
   }

   public void drawString(String s, int x, int y) {
      if (s == null) {
         throw new NullPointerException("String is null");
      }
      if (s.length() == 0 || !bind()) {
         return;
      }
      FontFace face = font.face();
      boolean aa = textAntialiased();
      int penX = x + originX;
      int baseY = y + originY;
      int minX = Integer.MAX_VALUE;
      int maxX = Integer.MIN_VALUE;
      int minY = Integer.MAX_VALUE;
      int maxY = Integer.MIN_VALUE;
      int rgb = argb & 0x00FFFFFF;
      int alpha = argb >>> 24;
      for (int i = 0; i < s.length(); i++) {
         char ch = s.charAt(i);
         Glyph gl = face.glyph(ch, aa);
         if (gl != null && gl.width > 0) {
            int gx = penX + gl.left;
            int gy = baseY + gl.top;
            Rectangle r = clipped(gx, gy, gl.width, gl.height);
            if (r != null) {
               byte[] cov = gl.coverage;
               for (int row = r.y; row < r.y + r.height; row++) {
                  int gi = (row - gy) * gl.width + (r.x - gx);
                  for (int col = r.x; col < r.x + r.width; col++, gi++) {
                     int a = cov[gi] & 0xFF;
                     if (a != 0) {
                        a = a * alpha / 255;
                        plot(col, row, (a << 24) | rgb);
                     }
                  }
               }
               minX = Math.min(minX, r.x);
               maxX = Math.max(maxX, r.x + r.width);
               minY = Math.min(minY, r.y);
               maxY = Math.max(maxY, r.y + r.height);
            }
         }
         penX += face.advance(ch);
      }
      if (maxX > minX) {
         damage(minX, minY, maxX - minX, maxY - minY);
      }
   }

   public void drawString(String s, float x, float y) {
      drawString(s, Math.round(x), Math.round(y));
   }

   public void drawString(AttributedCharacterIterator it, int x, int y) {
      StringBuilder b = new StringBuilder();
      for (char c = it.first(); c != AttributedCharacterIterator.DONE; c = it.next()) {
         b.append(c);
      }
      drawString(b.toString(), x, y);
   }

   // ------------------------------------------------------------------ images

   public boolean drawImage(Image img, int x, int y, ImageObserver observer) {
      return drawImage(img, x, y, null, observer);
   }

   public boolean drawImage(Image img, int x, int y, Color bg, ImageObserver observer) {
      BufferedImage src = Image.pixelsOf(img, observer);
      if (src == null) {
         return false;
      }
      int w = src.getWidth();
      int h = src.getHeight();
      return drawImage(img, x, y, x + w, y + h, 0, 0, w, h, bg, observer);
   }

   public boolean drawImage(Image img, int x, int y, int w, int h, ImageObserver observer) {
      return drawImage(img, x, y, w, h, null, observer);
   }

   public boolean drawImage(Image img, int x, int y, int w, int h, Color bg, ImageObserver observer) {
      BufferedImage src = Image.pixelsOf(img, observer);
      if (src == null) {
         return false;
      }
      if (w == 0 || h == 0) {
         return true;
      }
      return drawImage(img, x, y, x + w, y + h, 0, 0, src.getWidth(), src.getHeight(), bg, observer);
   }

   public boolean drawImage(Image img, int dx1, int dy1, int dx2, int dy2, int sx1, int sy1, int sx2, int sy2, ImageObserver observer) {
      return drawImage(img, dx1, dy1, dx2, dy2, sx1, sy1, sx2, sy2, null, observer);
   }

   /** Nearest neighbour scaling (GDI's COLORONCOLOR), alpha blended unless a background is given. */
   public boolean drawImage(Image img, int dx1, int dy1, int dx2, int dy2, int sx1, int sy1, int sx2, int sy2, Color bg,
         ImageObserver observer) {
      BufferedImage src = Image.pixelsOf(img, observer);
      if (src == null) {
         return false;
      }
      if (!bind() || dx1 == dx2 || dy1 == dy2 || sx1 == sx2 || sy1 == sy2) {
         return true;
      }
      int dxa = Math.min(dx1, dx2);
      int dxb = Math.max(dx1, dx2);
      int dya = Math.min(dy1, dy2);
      int dyb = Math.max(dy1, dy2);
      Rectangle r = clipped(dxa + originX, dya + originY, dxb - dxa, dyb - dya);
      if (r == null) {
         return true;
      }
      int sw = src.getWidth();
      int sh = src.getHeight();
      int[] spx = src.intPixels();
      boolean srcAlpha = src.getColorModel().hasAlpha();
      int bgc = bg == null ? 0 : bg.getRGB() | 0xFF000000;
      double scaleX = (double) (sx2 - sx1) / (dx2 - dx1);
      double scaleY = (double) (sy2 - sy1) / (dy2 - dy1);
      boolean direct = intPixels && xorColor == null && scaleX == 1.0 && scaleY == 1.0 && (!srcAlpha || bg != null) && spx != null;
      for (int y = r.y; y < r.y + r.height; y++) {
         int sy = (int) Math.floor(sy1 + ((y - originY) - dy1 + 0.5) * scaleY);
         if (sy < 0 || sy >= sh) {
            continue;
         }
         if (direct) {
            int sxStart = sx1 + (r.x - originX - dx1);
            int a = Math.max(r.x, r.x + (0 - sxStart));
            int b = Math.min(r.x + r.width, r.x + (sw - sxStart));
            if (b > a) {
               int srcIndex = sy * sw + sxStart + (a - r.x);
               int dstIndex = y * width + a;
               if (srcAlpha) {
                  for (int i = 0; i < b - a; i++) {
                     pixels[dstIndex + i] = blendOver(bgc, spx[srcIndex + i]);
                  }
               } else {
                  for (int i = 0; i < b - a; i++) {
                     pixels[dstIndex + i] = spx[srcIndex + i] | 0xFF000000;
                  }
               }
            }
            continue;
         }
         for (int x = r.x; x < r.x + r.width; x++) {
            int sx = (int) Math.floor(sx1 + ((x - originX) - dx1 + 0.5) * scaleX);
            if (sx < 0 || sx >= sw) {
               continue;
            }
            int c = spx != null ? spx[sy * sw + sx] : src.getRGB(sx, sy);
            if (!srcAlpha) {
               c |= 0xFF000000;
            } else if (bg != null) {
               c = blendOver(bgc, c);
            }
            plot(x, y, c);
         }
      }
      damage(r.x, r.y, r.width, r.height);
      return true;
   }

   private static int blendOver(int dst, int c) {
      int a = c >>> 24;
      if (a == 255) {
         return c;
      }
      if (a == 0) {
         return dst;
      }
      int ia = 255 - a;
      int r = (((c >> 16) & 0xFF) * a + ((dst >> 16) & 0xFF) * ia) / 255;
      int g = (((c >> 8) & 0xFF) * a + ((dst >> 8) & 0xFF) * ia) / 255;
      int b = ((c & 0xFF) * a + (dst & 0xFF) * ia) / 255;
      return 0xFF000000 | (r << 16) | (g << 8) | b;
   }

   public String toString() {
      return getClass().getName() + "[origin=" + originX + "," + originY + ",clip=" + clip + ",color=" + color + "]";
   }
}
