package NET.worlds.scape;

import NET.worlds.network.ObjID;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import java.io.IOException;

public class MutedDrone extends Drone {
   private static Object classCookie = new Object();

   public MutedDrone(ObjID var1, WorldServer var2, URL var3) {
      super(var1, var2);
      this.setSourceURL(var3);
   }

   public MutedDrone() {
   }

   public Drone setAvatarNow(URL var1) {
      if (this.shouldBeMuted()) {
         this.setSourceURL(var1);
         return this;
      } else {
         return super.setAvatarNow(var1);
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 1:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
