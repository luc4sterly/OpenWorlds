package NET.worlds.console;

import java.awt.Dimension;
import java.awt.Panel;

class FixedSizePanel extends Panel {
   int w;
   int h;

   public FixedSizePanel(int var1, int var2) {
      this.w = var1;
      this.h = var2;
   }

   public Dimension preferredSize() {
      Dimension var1 = super.preferredSize();
      if (this.w >= 0) {
         var1.width = this.w;
      }

      if (this.h >= 0) {
         var1.height = this.h;
      }

      return var1;
   }

   public Dimension minimumSize() {
      Dimension var1 = super.minimumSize();
      if (this.w >= 0) {
         var1.width = this.w;
      }

      if (this.h >= 0) {
         var1.height = this.h;
      }

      return var1;
   }
}
