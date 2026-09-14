package NET.worlds.scape;

import java.io.IOException;

class Facer extends SwitchableBehavior {
   public void saveState(Saver var1) throws IOException {
   }

   public void restoreState(Restorer var1) throws IOException {
      System.out.println("WARNING! Facers are obsolete.  Use 1-image Holograms instead.");
   }
}
