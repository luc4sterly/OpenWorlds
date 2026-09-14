package NET.worlds.scape;

import java.io.IOException;

public class StartupSensor extends Sensor implements FrameHandler {
   private boolean hasTriggered = false;
   private static Object classCookie = new Object();

   public void addAction(Action var1) {
      this.hasTriggered = false;
      super.addAction(var1);
   }

   public boolean handle(FrameEvent var1) {
      if (!this.hasTriggered) {
         this.hasTriggered = true;
         this.trigger(var1);
      }

      return true;
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
