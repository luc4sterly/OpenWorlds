package NET.worlds.scape;

import java.io.IOException;

public class Point2 implements Persister {
   public float x;
   public float y;
   private static Object classCookie = new Object();

   public Point2() {
   }

   public Point2(float var1, float var2) {
      this.set(var1, var2);
   }

   public Point2(Point2 var1) {
      this.x = var1.x;
      this.y = var1.y;
   }

   public Point2 copy(Point2 var1) {
      this.x = var1.x;
      this.y = var1.y;
      return this;
   }

   public void set(float var1, float var2) {
      this.x = var1;
      this.y = var2;
   }

   public float length() {
      return (float)Math.sqrt(this.x * this.x + this.y * this.y);
   }

   public Point2 normalize() {
      float var1 = this.length();
      if (var1 > 0.0F) {
         this.dividedBy(var1);
      }

      return this;
   }

   public Point2 negate() {
      this.x = -this.x;
      this.y = -this.y;
      return this;
   }

   public Point2 plus(Point2 var1) {
      this.x = this.x + var1.x;
      this.y = this.y + var1.y;
      return this;
   }

   public Point2 plus(float var1) {
      this.x += var1;
      this.y += var1;
      return this;
   }

   public Point2 minus(float var1) {
      return this.plus(-var1);
   }

   public Point2 minus(Point2 var1) {
      this.x = this.x - var1.x;
      this.y = this.y - var1.y;
      return this;
   }

   public Point2 times(float var1) {
      this.x *= var1;
      this.y *= var1;
      return this;
   }

   public Point2 times(Point2 var1) {
      this.x = this.x * var1.x;
      this.y = this.y * var1.y;
      return this;
   }

   public Point2 dividedBy(float var1) {
      this.x /= var1;
      this.y /= var1;
      return this;
   }

   public Point2 dividedBy(Point2 var1) {
      this.x = this.x / var1.x;
      this.y = this.y / var1.y;
      return this;
   }

   public float dot(Point2 var1) {
      return var1.x * this.x + var1.y * this.y;
   }

   public String toString() {
      return "" + this.x + "," + this.y;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      var1.saveFloat(this.x);
      var1.saveFloat(this.y);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this.x = var1.restoreFloat();
            this.y = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }
}
