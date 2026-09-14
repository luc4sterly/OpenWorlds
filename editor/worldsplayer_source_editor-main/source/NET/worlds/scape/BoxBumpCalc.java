package NET.worlds.scape;

import java.io.IOException;

public class BoxBumpCalc extends BumpCalc {
   private static Object classCookie = new Object();

   public void detectBump(BumpEventTemp var1, WObject var2) {
      BoundBoxTemp var3 = var2.getBoundBox();
      BoundBoxTemp var4 = ((WObject)var1.source).getBoundBox();
      var3.lo.minus(var4.hi.minus(var1.sourceAt));
      var3.hi.minus(var4.lo.minus(var1.sourceAt));
      Point3Temp var5 = Point3Temp.make();
      var5.x = var3.lo.x;
      var5.y = var3.lo.y;
      float var6 = var3.hi.x - var3.lo.x;
      float var7 = var3.hi.y - var3.lo.y;
      Point3Temp var8 = Point3Temp.make(var6, 0.0F, 0.0F);
      Point3Temp var9 = Point3Temp.make(0.0F, var7 / 2.0F, 0.0F);
      if (!var1.hitTriRegion(var2, var5, var8, var9)) {
         var5.x = var3.hi.x;
         var5.y = var3.hi.y;
         var8.x = -var8.x;
         var9.y = -var9.y;
         if (!var1.hitTriRegion(var2, var5, var8, var9)) {
            var5.y = var3.lo.y;
            var8.y = var7;
            var8.x = 0.0F;
            var9.x = -var6 / 2.0F;
            var9.y = 0.0F;
            if (!var1.hitTriRegion(var2, var5, var8, var9)) {
               var5.x = var3.lo.x;
               var5.y = var3.hi.y;
               var8.y = -var8.y;
               var9.x = -var9.x;
               if (!var1.hitTriRegion(var2, var5, var8, var9)) {
                  ;
               }
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
