package java.awt;

/** A rectangle (x, y, width, height), as java.awt.Rectangle. */
public class Rectangle implements Shape, Cloneable, java.io.Serializable {
   public int x;
   public int y;
   public int width;
   public int height;

   public Rectangle() {
   }

   public Rectangle(Rectangle r) {
      this(r.x, r.y, r.width, r.height);
   }

   public Rectangle(int x, int y, int width, int height) {
      this.x = x;
      this.y = y;
      this.width = width;
      this.height = height;
   }

   public Rectangle(int width, int height) {
      this(0, 0, width, height);
   }

   public Rectangle(Point p, Dimension d) {
      this(p.x, p.y, d.width, d.height);
   }

   public Rectangle(Point p) {
      this(p.x, p.y, 0, 0);
   }

   public Rectangle(Dimension d) {
      this(0, 0, d.width, d.height);
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

   public Rectangle getBounds() {
      return new Rectangle(x, y, width, height);
   }

   public void setBounds(Rectangle r) {
      setBounds(r.x, r.y, r.width, r.height);
   }

   public void setBounds(int x, int y, int width, int height) {
      reshape(x, y, width, height);
   }

   public void reshape(int x, int y, int width, int height) {
      this.x = x;
      this.y = y;
      this.width = width;
      this.height = height;
   }

   public Point getLocation() {
      return new Point(x, y);
   }

   public void setLocation(Point p) {
      setLocation(p.x, p.y);
   }

   public void setLocation(int x, int y) {
      move(x, y);
   }

   public void move(int x, int y) {
      this.x = x;
      this.y = y;
   }

   public void translate(int dx, int dy) {
      this.x += dx;
      this.y += dy;
   }

   public Dimension getSize() {
      return new Dimension(width, height);
   }

   public void setSize(Dimension d) {
      setSize(d.width, d.height);
   }

   public void setSize(int width, int height) {
      resize(width, height);
   }

   public void resize(int width, int height) {
      this.width = width;
      this.height = height;
   }

   public boolean contains(Point p) {
      return contains(p.x, p.y);
   }

   public boolean contains(int px, int py) {
      return inside(px, py);
   }

   public boolean contains(double px, double py) {
      return width > 0 && height > 0 && px >= x && py >= y && px < x + width && py < y + height;
   }

   public boolean contains(Rectangle r) {
      return contains(r.x, r.y, r.width, r.height);
   }

   public boolean contains(int X, int Y, int W, int H) {
      return width > 0 && height > 0 && W > 0 && H > 0 && X >= x && Y >= y && X + W <= x + width && Y + H <= y + height;
   }

   public boolean inside(int px, int py) {
      return width > 0 && height > 0 && px >= x && py >= y && px < x + width && py < y + height;
   }

   public boolean intersects(Rectangle r) {
      if (width <= 0 || height <= 0 || r.width <= 0 || r.height <= 0) {
         return false;
      }
      return r.x < x + width && r.y < y + height && r.x + r.width > x && r.y + r.height > y;
   }

   public Rectangle intersection(Rectangle r) {
      int x1 = Math.max(x, r.x);
      int y1 = Math.max(y, r.y);
      long x2 = Math.min((long) x + width, (long) r.x + r.width);
      long y2 = Math.min((long) y + height, (long) r.y + r.height);
      x2 -= x1;
      y2 -= y1;
      if (x2 < Integer.MIN_VALUE) {
         x2 = Integer.MIN_VALUE;
      }
      if (y2 < Integer.MIN_VALUE) {
         y2 = Integer.MIN_VALUE;
      }
      return new Rectangle(x1, y1, (int) x2, (int) y2);
   }

   public Rectangle union(Rectangle r) {
      if (width < 0 || height < 0) {
         return new Rectangle(r);
      }
      if (r.width < 0 || r.height < 0) {
         return new Rectangle(this);
      }
      int x1 = Math.min(x, r.x);
      int y1 = Math.min(y, r.y);
      int x2 = Math.max(x + width, r.x + r.width);
      int y2 = Math.max(y + height, r.y + r.height);
      return new Rectangle(x1, y1, x2 - x1, y2 - y1);
   }

   public void add(int px, int py) {
      int x1 = Math.min(x, px);
      int x2 = Math.max(x + width, px);
      int y1 = Math.min(y, py);
      int y2 = Math.max(y + height, py);
      reshape(x1, y1, x2 - x1, y2 - y1);
   }

   public void add(Point p) {
      add(p.x, p.y);
   }

   public void add(Rectangle r) {
      Rectangle u = union(r);
      reshape(u.x, u.y, u.width, u.height);
   }

   public void grow(int h, int v) {
      x -= h;
      y -= v;
      width += h * 2;
      height += v * 2;
   }

   public boolean isEmpty() {
      return width <= 0 || height <= 0;
   }

   public boolean equals(Object o) {
      if (!(o instanceof Rectangle)) {
         return false;
      }
      Rectangle r = (Rectangle) o;
      return x == r.x && y == r.y && width == r.width && height == r.height;
   }

   public int hashCode() {
      return ((x * 31 + y) * 31 + width) * 31 + height;
   }

   public Object clone() {
      return new Rectangle(this);
   }

   public String toString() {
      return getClass().getName() + "[x=" + x + ",y=" + y + ",width=" + width + ",height=" + height + "]";
   }
}
