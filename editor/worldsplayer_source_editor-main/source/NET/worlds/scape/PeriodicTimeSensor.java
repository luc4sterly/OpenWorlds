package NET.worlds.scape;

import NET.worlds.core.Std;
import java.io.IOException;

public class PeriodicTimeSensor extends Sensor implements FrameHandler {
   private float timeInterval = 1.0F;
   private long lastTrigger;
   private static Object classCookie = new Object();

   public PeriodicTimeSensor(Action var1) {
      if (var1 != null) {
         this.addAction(var1);
      }
   }

   public PeriodicTimeSensor() {
   }

   public boolean handle(FrameEvent var1) {
      long var2 = 0L;
      if (var1 == null) {
         var2 = Std.getFastTime();
      } else {
         var2 = var1.time;
      }

      if (var2 - this.lastTrigger > (long)(1000.0F * this.timeInterval)) {
         this.lastTrigger = var2;
         this.trigger(var1);
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Time Interval (s)"));
            } else if (var3 == 1) {
               var5 = new Float(this.timeInterval);
            } else if (var3 == 2) {
               this.timeInterval = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.timeInterval);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this.timeInterval = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return "*every " + this.timeInterval + " s";
   }
}
