package NET.worlds.scape;

import java.io.IOException;

public class PlaneBumpCalc extends BumpCalc {
   private static Object classCookie = new Object();

   public void detectBump(BumpEventTemp var1, WObject var2) {
      WObject var3 = (WObject)var1.source;
      Point3Temp var4 = var3.getWorldPosition();
      Transform var5 = var2.getObjectToWorldMatrix();
      Point3Temp var6 = var5.getPosition();
      Point3Temp var7 = var2.getPlaneExtent().times(var5);
      Point3Temp var8 = Point3Temp.make(var7).minus(var6);
      var5.recycle();
      BoundBoxTemp var9 = var3.getBoundBox();
      Point2 var10;
      if (var8.x > 0.0F) {
         if (var8.y > 0.0F) {
            var10 = new Point2(var9.lo.x, var9.hi.y);
         } else {
            var10 = new Point2(var9.hi.x, var9.hi.y);
         }
      } else if (var8.y > 0.0F) {
         var10 = new Point2(var9.lo.x, var9.lo.y);
      } else {
         var10 = new Point2(var9.hi.x, var9.lo.y);
      }

      Point2 var11 = new Point2(-var8.y, var8.x).normalize();
      var10.x = var10.x - var4.x;
      var10.y = var10.y - var4.y;
      float var12 = var10.dot(var11);
      Point3Temp var13 = Point3Temp.make(var11.x * var12, var11.y * var12, 0.0F);
      if (!var1.hitRegion(var2, Point3Temp.make(var6).minus(var13), var8, var13)) {
         Point3Temp var14 = Point3Temp.make(var13.y, -var13.x, 0.0F);
         var8 = Point3Temp.make(var14).minus(var13);
         Point3Temp var15 = Point3Temp.make(-var8.y, var8.x, 0.0F).normalize().times(var12 / 1.5F);
         Point3Temp var16 = Point3Temp.make(var6).minus(var14);
         if (!var1.hitRegion(var2, var16, var8, var15)) {
            if (!var1.hitRegion(var2, Point3Temp.make(var7).minus(var13), Point3Temp.make(-var8.y, var8.x, 0.0F), Point3Temp.make(-var15.y, var15.x, 0.0F))) {
               ;
            }
         }
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
