package NET.worlds.scape;

import NET.worlds.console.Window;
import java.io.IOException;
import java.util.Enumeration;

public class SetZoomMode extends Action implements MomentumBehavior {
   private boolean zoomMode;
   private static Object classCookie = new Object();

   public SetZoomMode(boolean var1) {
      this.zoomMode = var1;
   }

   public SetZoomMode() {
   }

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 != null && var3 instanceof Pilot && ((Pilot)var3).isActive()) {
         Window var4 = Window.getMainWindow();
         if (var4 == null) {
            return null;
         }

         var4.setDeltaMode(this.zoomMode);
         return null;
      } else {
         return null;
      }
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

   public void transferFrom(Enumeration var1) {
      while (var1.hasMoreElements()) {
         SuperRoot var2 = (SuperRoot)var1.nextElement();
         if (var2 instanceof SetZoomMode) {
            this.zoomMode = ((SetZoomMode)var2).zoomMode;
            break;
         }
      }
   }
}
