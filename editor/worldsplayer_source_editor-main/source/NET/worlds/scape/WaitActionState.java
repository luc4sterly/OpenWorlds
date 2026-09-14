package NET.worlds.scape;

import NET.worlds.core.Std;
import java.io.IOException;

class WaitActionState implements Persister {
   long endTime;
   private static Object classCookie = new Object();

   WaitActionState() {
   }

   WaitActionState(long var1) {
      this.endTime = var1;
   }

   public boolean run(long var1) {
      return var1 < this.endTime;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      var1.saveLong(this.endTime - Std.getFastTime());
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this.endTime = var1.restoreLong() + Std.getFastTime();
            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }
}
