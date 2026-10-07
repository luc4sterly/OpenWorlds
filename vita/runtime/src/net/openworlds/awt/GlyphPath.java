package net.openworlds.awt;

import java.awt.Rectangle;
import java.awt.Shape;

/** The outline of some text (GlyphVector.getOutline): closed polygons, filled with the non-zero rule. */
public final class GlyphPath implements Shape {
   private final double[][] xs;
   private final double[][] ys;

   public GlyphPath(double[][] xs, double[][] ys) {
      this.xs = xs;
      this.ys = ys;
   }

   public int contours() {
      return xs.length;
   }

   public double[] xs(int contour) {
      return xs[contour];
   }

   public double[] ys(int contour) {
      return ys[contour];
   }

   public Rectangle getBounds() {
      double minX = Double.MAX_VALUE, minY = Double.MAX_VALUE, maxX = -Double.MAX_VALUE, maxY = -Double.MAX_VALUE;
      for (int c = 0; c < xs.length; c++) {
         for (int i = 0; i < xs[c].length; i++) {
            minX = Math.min(minX, xs[c][i]);
            maxX = Math.max(maxX, xs[c][i]);
            minY = Math.min(minY, ys[c][i]);
            maxY = Math.max(maxY, ys[c][i]);
         }
      }
      if (minX > maxX) {
         return new Rectangle();
      }
      int x = (int) Math.floor(minX);
      int y = (int) Math.floor(minY);
      return new Rectangle(x, y, (int) Math.ceil(maxX) - x, (int) Math.ceil(maxY) - y);
   }

   /** Non-zero winding. */
   public boolean contains(double px, double py) {
      int winding = 0;
      for (int c = 0; c < xs.length; c++) {
         double[] x = xs[c];
         double[] y = ys[c];
         int n = x.length;
         for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (y[i] <= py) {
               if (y[j] > py && (x[j] - x[i]) * (py - y[i]) - (px - x[i]) * (y[j] - y[i]) > 0) {
                  winding++;
               }
            } else if (y[j] <= py && (x[j] - x[i]) * (py - y[i]) - (px - x[i]) * (y[j] - y[i]) < 0) {
               winding--;
            }
         }
      }
      return winding != 0;
   }
}
