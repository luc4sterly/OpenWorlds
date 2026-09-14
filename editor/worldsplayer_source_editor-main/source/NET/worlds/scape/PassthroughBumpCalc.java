package NET.worlds.scape;

import java.io.IOException;

public class PassthroughBumpCalc extends BumpCalc {
   private static Object classCookie = new Object();

   public void detectBump(BumpEventTemp var1, WObject var2) {
      Transform var3 = var2.getObjectToWorldMatrix();
      Point3Temp var4 = var3.getPosition();
      Point3Temp var5 = var2.getPlaneExtent().vectorTimes(var3);
      var3.recycle();
      var1.hitPlane(var2, var4, var5);
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
