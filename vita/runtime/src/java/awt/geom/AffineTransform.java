package java.awt.geom;

/** A 2D affine transform, as java.awt.geom.AffineTransform (what fonts and contexts carry). */
public class AffineTransform implements Cloneable, java.io.Serializable {
   double m00 = 1;
   double m10;
   double m01;
   double m11 = 1;
   double m02;
   double m12;

   public AffineTransform() {
   }

   public AffineTransform(AffineTransform tx) {
      setTransform(tx);
   }

   public AffineTransform(double m00, double m10, double m01, double m11, double m02, double m12) {
      this.m00 = m00;
      this.m10 = m10;
      this.m01 = m01;
      this.m11 = m11;
      this.m02 = m02;
      this.m12 = m12;
   }

   public AffineTransform(float m00, float m10, float m01, float m11, float m02, float m12) {
      this((double) m00, m10, m01, m11, m02, m12);
   }

   public static AffineTransform getTranslateInstance(double tx, double ty) {
      return new AffineTransform(1, 0, 0, 1, tx, ty);
   }

   public static AffineTransform getScaleInstance(double sx, double sy) {
      return new AffineTransform(sx, 0, 0, sy, 0, 0);
   }

   public static AffineTransform getRotateInstance(double theta) {
      double c = Math.cos(theta);
      double s = Math.sin(theta);
      return new AffineTransform(c, s, -s, c, 0, 0);
   }

   public void setTransform(AffineTransform tx) {
      m00 = tx.m00;
      m10 = tx.m10;
      m01 = tx.m01;
      m11 = tx.m11;
      m02 = tx.m02;
      m12 = tx.m12;
   }

   public void setToIdentity() {
      m00 = m11 = 1;
      m10 = m01 = m02 = m12 = 0;
   }

   public boolean isIdentity() {
      return m00 == 1 && m11 == 1 && m10 == 0 && m01 == 0 && m02 == 0 && m12 == 0;
   }

   public double getScaleX() {
      return m00;
   }

   public double getScaleY() {
      return m11;
   }

   public double getShearX() {
      return m01;
   }

   public double getShearY() {
      return m10;
   }

   public double getTranslateX() {
      return m02;
   }

   public double getTranslateY() {
      return m12;
   }

   public void translate(double tx, double ty) {
      m02 += tx * m00 + ty * m01;
      m12 += tx * m10 + ty * m11;
   }

   public void scale(double sx, double sy) {
      m00 *= sx;
      m10 *= sx;
      m01 *= sy;
      m11 *= sy;
   }

   public void rotate(double theta) {
      concatenate(getRotateInstance(theta));
   }

   public void concatenate(AffineTransform t) {
      double a = m00 * t.m00 + m01 * t.m10;
      double b = m10 * t.m00 + m11 * t.m10;
      double c = m00 * t.m01 + m01 * t.m11;
      double d = m10 * t.m01 + m11 * t.m11;
      double e = m00 * t.m02 + m01 * t.m12 + m02;
      double f = m10 * t.m02 + m11 * t.m12 + m12;
      m00 = a;
      m10 = b;
      m01 = c;
      m11 = d;
      m02 = e;
      m12 = f;
   }

   public void getMatrix(double[] flatmatrix) {
      flatmatrix[0] = m00;
      flatmatrix[1] = m10;
      flatmatrix[2] = m01;
      flatmatrix[3] = m11;
      if (flatmatrix.length > 5) {
         flatmatrix[4] = m02;
         flatmatrix[5] = m12;
      }
   }

   public Object clone() {
      return new AffineTransform(this);
   }

   public boolean equals(Object o) {
      if (!(o instanceof AffineTransform)) {
         return false;
      }
      AffineTransform t = (AffineTransform) o;
      return m00 == t.m00 && m10 == t.m10 && m01 == t.m01 && m11 == t.m11 && m02 == t.m02 && m12 == t.m12;
   }

   public int hashCode() {
      return (int) (Double.doubleToLongBits(m00) ^ Double.doubleToLongBits(m11) ^ Double.doubleToLongBits(m02) ^ Double.doubleToLongBits(m12));
   }

   public String toString() {
      return "AffineTransform[[" + m00 + ", " + m01 + ", " + m02 + "], [" + m10 + ", " + m11 + ", " + m12 + "]]";
   }
}
