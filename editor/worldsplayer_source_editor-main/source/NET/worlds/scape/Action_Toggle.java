package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

class Action_Toggle extends Action {
   public Persister trigger(Event var1, Persister var2) {
      return null;
   }

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException {
      SetVisibleBumpableAction var2 = new SetVisibleBumpableAction();
      var1.replace(this, var2);
      var2.targetBumpable = var1.restoreBoolean();
      var2.targetVisible = var1.restoreBoolean();
   }
}
