package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

public class HorizontalRect extends Surface {
   private static Object classCookie = new Object();

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            float var2 = var1.restoreFloat();
            float var3 = var1.restoreFloat();
            float var4 = var1.restoreFloat();
            float var5 = var1.restoreFloat();
            boolean var6 = var1.restoreBoolean();
            Rect var7 = new Rect(1.0F, 1.0F, this.getMaterial());
            var7.setTransform(this);
            if (var6) {
               var7.pitch(-90.0F).scale(var2, 1.0F, var3);
            } else {
               var7.yaw(90.0F).pitch(90.0F).scale(var3, 1.0F, var2);
            }

            var7.setUV(var4, var5);
            var1.replace(this, var7);
            return;
         default:
            throw new TooNewException();
      }
   }
}
