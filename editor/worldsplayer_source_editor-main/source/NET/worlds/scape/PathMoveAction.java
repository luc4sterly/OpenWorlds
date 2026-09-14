package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

public class PathMoveAction extends Action {
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      return null;
   }

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      MoveAction var2 = new MoveAction();
      var1.replace(this, var2);
      var2.restoreStateMoveActionHelper(var1, classCookie);
   }
}
