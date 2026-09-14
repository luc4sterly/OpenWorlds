package NET.worlds.scape;

import NET.worlds.core.Debug;

public class BumpEventTemp extends Event {
   private static Recycler recycler = new Recycler();
   public Point3Temp fullPath;
   public Point3Temp path;
   public BoundBoxTemp bound;
   public float fraction;
   public Room postBumpRoom;
   public Transform postBumpPosition;
   public Point3Temp postBumpPath;
   public Point3Temp sourceAt;
   public BoundBoxTemp sourceBoxMinus;
   public Point3Temp bumpNormal;

   public static BumpEventTemp make(int var0, WObject var1, Point3Temp var2) {
      BumpEventTemp var3 = (BumpEventTemp)recycler.alloc();
      if (var3 == null) {
         recycler.recycle(new BumpEventTemp(0, null));
         var3 = (BumpEventTemp)recycler.alloc();
      }

      Debug.dAssert(var3.source == null);
      var3.time = var0;
      var3.source = var1;
      var3.fullPath = Point3Temp.make(var2);
      var3.path = var3.fullPath;
      var3.sourceAt = ((WObject)var3.source).getWorldPosition();
      var3.sourceBoxMinus = ((WObject)var3.source).getBoundBox();
      var3.sourceBoxMinus.lo.minus(var3.sourceAt);
      var3.sourceBoxMinus.hi.minus(var3.sourceAt);
      var3.setPathFraction(1.0F);
      Room var4 = var1.getRoom();
      if (var4.getBumpable()) {
         var4.detectBump(var3);
      }

      return var3;
   }

   public void recycle() {
      this.time = 0;
      this.source = null;
      this.target = null;
      this.receiver = null;
      this.postBumpRoom = null;
      this.postBumpPath = null;
      this.postBumpPosition = null;
   }

   private BumpEventTemp(int var1, Object var2) {
      super(var1, var2, null);
   }

   public void setPathFraction(float var1) {
      this.fraction = var1;
      this.path = Point3Temp.make(this.path).times(var1);
      this.bound = BoundBoxTemp.make(this.sourceAt, Point3Temp.make(this.sourceAt).plus(this.path));
      this.bound.lo.plus(this.sourceBoxMinus.lo);
      this.bound.hi.plus(this.sourceBoxMinus.hi);
   }

   public float isCollision(Point3Temp var1, Point3Temp var2, Point3Temp var3, Point3Temp var4) {
      double var5 = (double)var4.x * -var2.y + (double)var4.y * var2.x;
      if (var5 > 0.0) {
         Point3Temp var7 = Point3Temp.make(var3).minus(var1);
         double var8 = (double)var7.x * var2.y - (double)var7.y * var2.x;
         double var10 = (double)var7.x * var4.y - (double)var4.x * var7.y;
         return var10 >= 0.0 && var10 <= var5 && var8 >= 0.0 && var8 <= var5 ? (float)(var8 / var5) : -2.0F;
      } else {
         return -1.0F;
      }
   }

   public float hitPlane(WObject var1, Point3Temp var2, Point3Temp var3) {
      float var4 = this.isCollision(var2, var3, this.sourceAt, this.path);
      if (var4 >= 0.0F) {
         this.target = var1;
         this.setPathFraction(var4);
         this.bumpNormal = Point3Temp.make(var3.y, -var3.x, 0.0F).normalize();
         this.path.plus(Point3Temp.make(this.path).normalize().times(0.2F));
      }

      return var4;
   }

   public boolean hitRegion(WObject var1, Point3Temp var2, Point3Temp var3, Point3Temp var4) {
      float var5 = this.hitPlane(var1, var2, var3);
      if (var5 >= 0.0F) {
         return true;
      } else if (var5 == -1.0F) {
         return false;
      } else {
         Point3Temp var6 = Point3Temp.make(var2).plus(var3);
         Point3Temp var7 = Point3Temp.make().minus(var3);
         Point3Temp var8 = Point3Temp.make().minus(var4);
         if (this.isCollision(var6, var7, this.sourceAt, var8) > 0.0F) {
            this.target = var1;
            this.setPathFraction(0.0F);
            this.bumpNormal = var8;
            return true;
         } else {
            return false;
         }
      }
   }

   public boolean hitTriRegion(WObject var1, Point3Temp var2, Point3Temp var3, Point3Temp var4) {
      float var5 = this.hitPlane(var1, var2, var3);
      if (var5 >= 0.0F) {
         return true;
      }

      if (var5 == -1.0F) {
         return false;
      }

      Point3Temp var6 = Point3Temp.make(var2).plus(var3);
      Point3Temp var7 = Point3Temp.make().minus(var3);
      Point3Temp var8 = Point3Temp.make().minus(var4);
      if (this.isCollision(var6, var7, this.sourceAt, var8) > 0.0F) {
         float var9 = this.sourceAt.x - (var2.x + var3.x / 2.0F);
         float var10 = this.sourceAt.y - (var2.y + var3.y / 2.0F);
         float var11 = var9 * var9 + var10 * var10;
         var9 = this.sourceAt.x - (var2.x + var4.x);
         var10 = this.sourceAt.y - (var2.y + var4.y);
         float var12 = var9 * var9 + var10 * var10;
         if (var12 < var11) {
            return false;
         }

         var9 = this.sourceAt.x - (var6.x + var4.x);
         var10 = this.sourceAt.y - (var6.y + var4.y);
         float var13 = var9 * var9 + var10 * var10;
         if (var13 < var11) {
            return false;
         }

         this.target = var1;
         this.setPathFraction(0.0F);
         this.bumpNormal = var8;
         return true;
      } else {
         return false;
      }
   }

   public boolean deliver(Object var1) {
      return var1 instanceof BumpHandler ? ((BumpHandler)var1).handle(this) : false;
   }
}
