package java.awt;

/** A location (x, y), as java.awt.Point. */
public class Point implements java.io.Serializable {
   public int x;
   public int y;

   public Point() {
   }

   public Point(Point p) {
      this(p.x, p.y);
   }

   public Point(int x, int y) {
      this.x = x;
      this.y = y;
   }

   public double getX() {
      return x;
   }

   public double getY() {
      return y;
   }

   public Point getLocation() {
      return new Point(x, y);
   }

   public void setLocation(Point p) {
      setLocation(p.x, p.y);
   }

   public void setLocation(int x, int y) {
      this.x = x;
      this.y = y;
   }

   public void move(int x, int y) {
      setLocation(x, y);
   }

   public void translate(int dx, int dy) {
      this.x += dx;
      this.y += dy;
   }

   public boolean equals(Object o) {
      if (!(o instanceof Point)) {
         return false;
      }
      Point p = (Point) o;
      return x == p.x && y == p.y;
   }

   public int hashCode() {
      return x * 31 + y;
   }

   public String toString() {
      return getClass().getName() + "[x=" + x + ",y=" + y + "]";
   }
}
