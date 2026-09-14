package NET.worlds.console;

import java.awt.Scrollbar;
import java.awt.event.MouseEvent;

class GammaTextScrollbar extends Scrollbar {
   GammaTextScrollbar(int var1) {
      super(var1);
      this.enableEvents(20L);
   }

   protected void processMouseEvent(MouseEvent var1) {
      if (var1.getID() == 501) {
         this.getParent().requestFocus();
      }

      super.processMouseEvent(var1);
   }
}
