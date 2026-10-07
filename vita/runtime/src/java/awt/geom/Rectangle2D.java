package java.awt.geom;

/** A rectangle with real coordinates, as java.awt.geom.Rectangle2D. */
public abstract class Rectangle2D {
   protected Rectangle2D() {
   }

   public abstract double getX();

   public abstract double getY();

   public abstract double getWidth();

   public abstract double getHeight();

   public double getMinX() {
      return getX();
   }

   public double getMinY() {
      return getY();
   }

   public double getMaxX() {
      return getX() + getWidth();
   }

   public double getMaxY() {
      return getY() + getHeight();
   }

   public double getCenterX() {
      return getX() + getWidth() / 2;
   }

   public double getCenterY() {
      return getY() + getHeight() / 2;
   }

   public boolean isEmpty() {
      return getWidth() <= 0 || getHeight() <= 0;
   }

   public boolean contains(double x, double y) {
      double x0 = getX();
      double y0 = getY();
      return x >= x0 && y >= y0 && x < x0 + getWidth() && y < y0 + getHeight();
   }

   public java.awt.Rectangle getBounds() {
      double x1 = Math.floor(getX());
      double y1 = Math.floor(getY());
      double x2 = Math.ceil(getMaxX());
      double y2 = Math.ceil(getMaxY());
      return new java.awt.Rectangle((int) x1, (int) y1, (int) (x2 - x1), (int) (y2 - y1));
   }

   public static class Float extends Rectangle2D {
      public float x;
      public float y;
      public float width;
      public float height;

      public Float() {
      }

      public Float(float x, float y, float w, float h) {
         this.x = x;
         this.y = y;
         this.width = w;
         this.height = h;
      }

      public double getX() {
         return x;
      }

      public double getY() {
         return y;
      }

      public double getWidth() {
         return width;
      }

      public double getHeight() {
         return height;
      }

      public String toString() {
         return getClass().getName() + "[x=" + x + ",y=" + y + ",w=" + width + ",h=" + height + "]";
      }
   }

   public static class Double extends Rectangle2D {
      public double x;
      public double y;
      public double width;
      public double height;

      public Double() {
      }

      public Double(double x, double y, double w, double h) {
         this.x = x;
         this.y = y;
         this.width = w;
         this.height = h;
      }

      public double getX() {
         return x;
      }

      public double getY() {
         return y;
      }

      public double getWidth() {
         return width;
      }

      public double getHeight() {
         return height;
      }

      public String toString() {
         return getClass().getName() + "[x=" + x + ",y=" + y + ",w=" + width + ",h=" + height + "]";
      }
   }
}
