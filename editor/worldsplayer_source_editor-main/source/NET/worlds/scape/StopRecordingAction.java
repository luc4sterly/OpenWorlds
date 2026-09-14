package NET.worlds.scape;

import NET.worlds.console.BlackBox;
import java.io.IOException;

public class StopRecordingAction extends Action {
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      BlackBox.getInstance().stop();
      return null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      return super.properties(var1, var2, var3, var4);
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
