package NET.worlds.scape;

import java.io.IOException;

public class PickUpAction extends Action {
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      WObject var3 = (WObject)this.getOwner();
      var3.detach();
      var3.raise(-Pilot.getActive().getZ());
      Pilot.getActive().add(var3);
      return null;
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
