package java.awt;

/** A width and a height, as java.awt.Dimension. */
public class Dimension implements java.io.Serializable {
   public int width;
   public int height;

   public Dimension() {
   }

   public Dimension(Dimension d) {
      this(d.width, d.height);
   }

   public Dimension(int width, int height) {
      this.width = width;
      this.height = height;
   }

   public double getWidth() {
      return width;
   }

   public double getHeight() {
      return height;
   }

   public Dimension getSize() {
      return new Dimension(width, height);
   }

   public void setSize(Dimension d) {
      setSize(d.width, d.height);
   }

   public void setSize(int width, int height) {
      this.width = width;
      this.height = height;
   }

   public boolean equals(Object o) {
      if (!(o instanceof Dimension)) {
         return false;
      }
      Dimension d = (Dimension) o;
      return width == d.width && height == d.height;
   }

   public int hashCode() {
      int sum = width + height;
      return sum * (sum + 1) / 2 + width;
   }

   public String toString() {
      return getClass().getName() + "[width=" + width + ",height=" + height + "]";
   }
}
