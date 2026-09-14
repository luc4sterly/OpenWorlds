package NET.worlds.scape;

import NET.worlds.core.Std;
import java.io.IOException;

public class WaitAction extends Action {
   float duration = 1.0F;
   private static Object classCookie = new Object();

   public WaitAction() {
   }

   public WaitAction(float var1) {
      this.duration = var1;
   }

   public Persister trigger(Event var1, Persister var2) {
      long var3 = 0L;
      if (var1 == null) {
         var3 = Std.getFastTime();
      } else {
         var3 = var1.time;
      }

      if (var2 == null) {
         var2 = new WaitActionState(var3 + (long)(1000.0F * this.duration));
      }

      if (!((WaitActionState)var2).run(var3)) {
         var2 = null;
      }

      return var2;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Duration (s)"));
            } else if (var3 == 1) {
               var5 = new Float(this.duration);
            } else if (var3 == 2) {
               this.duration = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.duration);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            var1.setOldFlag();
            super.restoreState(var1);
            this.duration = var1.restoreInt();
            break;
         case 1:
            var1.setOldFlag();
            super.restoreState(var1);
            this.duration = var1.restoreFloat();
            var1.restoreLong();
            break;
         case 2:
            super.restoreState(var1);
            this.duration = var1.restoreFloat();
            break;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.duration + " s]";
   }
}
