package java.awt;

/** A closed polygon of integer points, as java.awt.Polygon. */
public class Polygon implements Shape, java.io.Serializable {
   public int npoints;
   public int[] xpoints;
   public int[] ypoints;
   protected Rectangle bounds;

   public Polygon() {
      xpoints = new int[4];
      ypoints = new int[4];
   }

   public Polygon(int[] xpoints, int[] ypoints, int npoints) {
      if (npoints > xpoints.length || npoints > ypoints.length) {
         throw new IndexOutOfBoundsException("npoints > xpoints.length || npoints > ypoints.length");
      }
      if (npoints < 0) {
         throw new NegativeArraySizeException("npoints < 0");
      }
      this.npoints = npoints;
      this.xpoints = new int[npoints];
      this.ypoints = new int[npoints];
      System.arraycopy(xpoints, 0, this.xpoints, 0, npoints);
      System.arraycopy(ypoints, 0, this.ypoints, 0, npoints);
   }

   public void reset() {
      npoints = 0;
      bounds = null;
   }

   public void invalidate() {
      bounds = null;
   }

   public void translate(int dx, int dy) {
      for (int i = 0; i < npoints; i++) {
         xpoints[i] += dx;
         ypoints[i] += dy;
      }
      if (bounds != null) {
         bounds.translate(dx, dy);
      }
   }

   public void addPoint(int x, int y) {
      if (npoints >= xpoints.length) {
         int n = Math.max(npoints * 2, 4);
         int[] nx = new int[n];
         int[] ny = new int[n];
         System.arraycopy(xpoints, 0, nx, 0, npoints);
         System.arraycopy(ypoints, 0, ny, 0, npoints);
         xpoints = nx;
         ypoints = ny;
      }
      xpoints[npoints] = x;
      ypoints[npoints] = y;
      npoints++;
      if (bounds != null) {
         bounds.add(x, y);
      }
   }

   public Rectangle getBounds() {
      return getBoundingBox();
   }

   public Rectangle getBoundingBox() {
      if (npoints == 0) {
         return new Rectangle();
      }
      if (bounds == null) {
         int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
         for (int i = 0; i < npoints; i++) {
            minX = Math.min(minX, xpoints[i]);
            maxX = Math.max(maxX, xpoints[i]);
            minY = Math.min(minY, ypoints[i]);
            maxY = Math.max(maxY, ypoints[i]);
         }
         bounds = new Rectangle(minX, minY, maxX - minX, maxY - minY);
      }
      return new Rectangle(bounds);
   }

   public boolean contains(Point p) {
      return contains(p.x, p.y);
   }

   public boolean contains(int x, int y) {
      return contains((double) x, (double) y);
   }

   public boolean inside(int x, int y) {
      return contains((double) x, (double) y);
   }

   /** Even-odd rule, as java.awt.Polygon. */
   public boolean contains(double x, double y) {
      if (npoints <= 2 || !getBoundingBox().contains(x, y)) {
         return false;
      }
      int hits = 0;
      int lastx = xpoints[npoints - 1];
      int lasty = ypoints[npoints - 1];
      int curx, cury;
      for (int i = 0; i < npoints; lastx = curx, lasty = cury, i++) {
         curx = xpoints[i];
         cury = ypoints[i];
         if (cury == lasty) {
            continue;
         }
         int leftx;
         if (curx < lastx) {
            if (x >= lastx) {
               continue;
            }
            leftx = curx;
         } else {
            if (x >= curx) {
               continue;
            }
            leftx = lastx;
         }
         double test1, test2;
         if (cury < lasty) {
            if (y < cury || y >= lasty) {
               continue;
            }
            if (x < leftx) {
               hits++;
               continue;
            }
            test1 = x - curx;
            test2 = y - cury;
         } else {
            if (y < lasty || y >= cury) {
               continue;
            }
            if (x < leftx) {
               hits++;
               continue;
            }
            test1 = x - lastx;
            test2 = y - lasty;
         }
         if (test1 < (test2 / (lasty - cury) * (lastx - curx))) {
            hits++;
         }
      }
      return (hits & 1) != 0;
   }
}
