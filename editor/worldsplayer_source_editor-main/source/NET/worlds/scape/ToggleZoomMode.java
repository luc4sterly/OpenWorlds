package NET.worlds.scape;

import NET.worlds.console.Window;

public class ToggleZoomMode extends Action {
   public Persister trigger(Event var1, Persister var2) {
      if (var1.receiver instanceof Pilot && ((Pilot)var1.receiver).isActive()) {
         Window var3 = Window.getMainWindow();
         if (var3 == null) {
            return null;
         }

         var3.setDeltaMode(!var3.getDeltaMode());
         return null;
      } else {
         return null;
      }
   }
}
