package NET.worlds.scape;

public class Point3Temp {
   public float x;
   public float y;
   public float z;
   private static Recycler recycler = new Recycler();

   public static native void nativeInit();

   public static Point3Temp make(float var0, float var1, float var2) {
      Point3Temp var3 = (Point3Temp)recycler.alloc();
      if (var3 == null) {
         recycler.recycle(new Point3Temp(0));
         var3 = (Point3Temp)recycler.alloc();
      }

      var3.x = var0;
      var3.y = var1;
      var3.z = var2;
      return var3;
   }

   public static Point3Temp make() {
      return make(0.0F, 0.0F, 0.0F);
   }

   public static Point3Temp make(Point3Temp var0) {
      return make(var0.x, var0.y, var0.z);
   }

   protected Point3Temp(int var1) {
   }

   public Point3Temp copy(Point3Temp var1) {
      this.set(var1.x, var1.y, var1.z);
      return this;
   }

   public void set(float var1, float var2, float var3) {
      this.x = var1;
      this.y = var2;
      this.z = var3;
   }

   public float length() {
      return (float)Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
   }

   public float squaredLength() {
      return this.x * this.x + this.y * this.y + this.z * this.z;
   }

   public native Point3Temp times(Transform var1);

   public native Point3Temp vectorTimes(Transform var1);

   public Point3Temp normalize() {
      float var1 = this.length();
      if (var1 > 0.0F) {
         this.dividedBy(var1);
      }

      return this;
   }

   public Point3Temp negate() {
      this.x = -this.x;
      this.y = -this.y;
      this.z = -this.z;
      return this;
   }

   public Point3Temp abs() {
      this.x = Math.abs(this.x);
      this.y = Math.abs(this.y);
      this.z = Math.abs(this.z);
      return this;
   }

   public static Point3Temp getDirVector(float var0, float var1) {
      var1 = (float)(var1 * (Math.PI / 180.0));
      return make(-var0 * (float)Math.sin(var1), var0 * (float)Math.cos(var1), 0.0F);
   }

   public Point3Temp plus(Point3Temp var1) {
      this.x = this.x + var1.x;
      this.y = this.y + var1.y;
      this.z = this.z + var1.z;
      return this;
   }

   public Point3Temp cross(Point3Temp var1) {
      float var2 = this.y * var1.z - this.z * var1.y;
      float var3 = this.z * var1.x - this.x * var1.z;
      this.z = this.x * var1.y - this.y * var1.x;
      this.x = var2;
      this.y = var3;
      return this;
   }

   public Point3Temp plus(float var1) {
      this.x += var1;
      this.y += var1;
      this.z += var1;
      return this;
   }

   public Point3Temp minus(float var1) {
      return this.plus(-var1);
   }

   public Point3Temp minus(Point3Temp var1) {
      this.x = this.x - var1.x;
      this.y = this.y - var1.y;
      this.z = this.z - var1.z;
      return this;
   }

   public Point3Temp times(float var1) {
      this.x *= var1;
      this.y *= var1;
      this.z *= var1;
      return this;
   }

   public Point3Temp times(Point3Temp var1) {
      this.x = this.x * var1.x;
      this.y = this.y * var1.y;
      this.z = this.z * var1.z;
      return this;
   }

   public Point3Temp dividedBy(float var1) {
      this.x /= var1;
      this.y /= var1;
      this.z /= var1;
      return this;
   }

   public Point3Temp dividedBy(Point3Temp var1) {
      this.x = this.x / var1.x;
      this.y = this.y / var1.y;
      this.z = this.z / var1.z;
      return this;
   }

   public float dot(Point3Temp var1) {
      return var1.x * this.x + var1.y * this.y + var1.z * this.z;
   }

   public float det(Point3Temp var1, Point3Temp var2) {
      return this.x * var1.y * var2.z
         + var1.x * var2.y * this.z
         + var2.x * this.y * var1.z
         - this.z * var1.y * var2.x
         - var1.z * var2.y * this.x
         - var2.z * this.y * var1.x;
   }

   public boolean sameValue(Point3Temp var1) {
      return var1 == null ? false : this.x == var1.x && this.y == var1.y && this.z == var1.z;
   }

   public String toString() {
      return "" + this.x + "," + this.y + "," + this.z;
   }

   static {
      nativeInit();
   }
}
