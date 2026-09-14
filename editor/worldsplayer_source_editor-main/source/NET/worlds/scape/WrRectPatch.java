package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

class WrRectPatch extends RectPatch {
   private static Object classCookie = new Object();

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      RectPatch var2 = new RectPatch();
      var1.replace(this, var2);
      var2.restoreStateRectPatchHelper(var1, classCookie);
   }
}
