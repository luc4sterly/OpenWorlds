package NET.worlds.scape;

public class BoundBoxTemp {
   private static Recycler recycler = new Recycler();
   public Point3Temp lo;
   public Point3Temp hi;

   public static BoundBoxTemp make(Point3Temp var0, Point3Temp var1) {
      BoundBoxTemp var2 = (BoundBoxTemp)recycler.alloc();
      if (var2 == null) {
         recycler.recycle(new BoundBoxTemp());
         var2 = (BoundBoxTemp)recycler.alloc();
      }

      var2.lo = Point3Temp.make(var0);
      var2.hi = Point3Temp.make(var1);
      if (var0.x > var1.x) {
         var2.lo.x = var1.x;
         var2.hi.x = var0.x;
      }

      if (var0.y > var1.y) {
         var2.lo.y = var1.y;
         var2.hi.y = var0.y;
      }

      if (var0.z > var1.z) {
         var2.lo.z = var1.z;
         var2.hi.z = var0.z;
      }

      return var2;
   }

   public static BoundBoxTemp make(BoundBoxTemp var0) {
      return make(var0.lo, var0.hi);
   }

   private BoundBoxTemp() {
   }

   public boolean contains(Point3Temp var1) {
      return var1.x >= this.lo.x && var1.x <= this.hi.x && var1.y >= this.lo.y && var1.y <= this.hi.y && var1.z >= this.lo.z && var1.z <= this.hi.z;
   }

   public boolean isEmpty() {
      return this.lo.x == this.hi.x && this.lo.y == this.hi.y && this.lo.z == this.hi.z;
   }

   public boolean overlaps(BoundBoxTemp var1) {
      return !(this.hi.x < var1.lo.x)
         && !(var1.hi.x < this.lo.x)
         && !(this.hi.y < var1.lo.y)
         && !(var1.hi.y < this.lo.y)
         && !(this.hi.z < var1.lo.z)
         && !(var1.hi.z < this.lo.z);
   }

   public void encompass(Point3Temp var1) {
      if (var1.x < this.lo.x) {
         this.lo.x = var1.x;
      }

      if (var1.y < this.lo.y) {
         this.lo.y = var1.y;
      }

      if (var1.z < this.lo.z) {
         this.lo.z = var1.z;
      }

      if (var1.x > this.hi.x) {
         this.hi.x = var1.x;
      }

      if (var1.y > this.hi.y) {
         this.hi.y = var1.y;
      }

      if (var1.z > this.hi.z) {
         this.hi.z = var1.z;
      }
   }

   public String toString() {
      return "BoundBoxTemp[lo=" + this.lo + ", hi=" + this.hi + "]";
   }
}
