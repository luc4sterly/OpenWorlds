package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

public class Action_Motion extends Action {
   public Persister trigger(Event var1, Persister var2) {
      return null;
   }

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException {
      MoveAction var2 = new MoveAction();
      var1.replace(this, var2);
      var2.cycleTime = (int)var1.restoreFloat();
      var2.cycles = var1.restoreInt();

      try {
         var2.extentPoint.restoreState(var1);
         var2.startPoint.restoreState(var1);
         var2.extentScale.restoreState(var1);
         var2.startScale.restoreState(var1);
         var2.extentSpin.restoreState(var1);
         var2.startSpin.restoreState(var1);
      } catch (Exception var4) {
      }

      var2.extentRotation = var1.restoreFloat();
      var2.startRotation = var1.restoreFloat();
      var2.extentPoint.minus(var2.startPoint);
      var2.extentScale.dividedBy(var2.startScale);
   }
}
