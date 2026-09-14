package NET.worlds.console;

import java.awt.event.MouseEvent;

class UniverseImage extends ImageCanvas {
   public UniverseImage(String var1) {
      super(var1);
      this.enableEvents(16L);
   }

   public void processMouseEvent(MouseEvent var1) {
      if (var1.getID() != 501) {
         super.processMouseEvent(var1);
      } else {
         Console var2 = Console.getActive();
         if (var2 != null && var2 instanceof DefaultConsole) {
            ((DefaultConsole)var2).startDrive();
         }
      }
   }
}
