package NET.worlds.console;

import java.awt.Dimension;
import java.awt.Label;

class UnpaddedLabel extends Label {
   UnpaddedLabel(String var1, int var2) {
      super(var1, var2);
   }

   public Dimension preferredSize() {
      return new Dimension(1, 1);
   }

   public Dimension minimumSize() {
      return this.preferredSize();
   }
}
