package NET.worlds.console;

import java.awt.Color;
import java.awt.Insets;
import java.awt.LayoutManager;
import java.awt.Panel;

class InsetPanel extends Panel {
   private Insets insets;

   InsetPanel(LayoutManager var1, int var2, int var3, int var4, int var5) {
      super(var1);
      this.init(var2, var3, var4, var5);
   }

   InsetPanel(int var1, int var2, int var3, int var4) {
      this.init(var1, var2, var3, var4);
   }

   private void init(int var1, int var2, int var3, int var4) {
      this.insets = new Insets(var1, var2, var3, var4);
      this.setBackground(Color.black);
   }

   public Insets getInsets() {
      return this.insets;
   }
}
