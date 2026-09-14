package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

public class NamedPortal implements Persister {
   private static Object classCookie = new Object();

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            var1.setOldFlag();
            Portal var2 = new Portal();
            var1.replace(this, var2);
            var2.restoreState(var1);
            String var3 = var1.restoreString();
            var2.setName(var3);
            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
      Debug.assert_(false);
   }
}
