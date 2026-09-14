package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

public class Action_Animation extends Action {
   public Persister trigger(Event var1, Persister var2) {
      return null;
   }

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException {
      AnimateAction var2 = new AnimateAction();
      var1.replace(this, var2);
      var2.cycleTime = (int)var1.restoreFloat();
      var2.cycles = var1.restoreInt();
      var2.frameList = var1.restoreString();
   }
}
