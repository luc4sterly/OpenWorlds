package NET.worlds.console;

import java.awt.Dimension;
import java.awt.LayoutManager;
import java.awt.Panel;

class FixedWidthPanel extends Panel {
   private int width;

   public FixedWidthPanel(LayoutManager var1, int var2) {
      super(var1);
      this.width = var2;
   }

   public Dimension preferredSize() {
      Dimension var1 = super.preferredSize();
      var1.width = this.width;
      return var1;
   }
}
