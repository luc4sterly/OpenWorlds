package NET.worlds.console;

import java.awt.Dimension;
import java.awt.Panel;
import java.awt.Rectangle;

class ColorFiller extends Panel {
   private int w;
   private int h;

   ColorFiller(int var1, int var2) {
      this.w = var1;
      this.h = var2;
   }

   public void setHeight(int var1) {
      this.h = var1;
   }

   public void setWidth(int var1) {
      this.w = var1;
   }

   public Dimension preferredSize() {
      return new Dimension(this.w, this.h);
   }

   public Dimension getMaximumSize() {
      return this.preferredSize();
   }

   public void setBounds(Rectangle var1) {
      var1.width = this.w;
      var1.height = this.h;
      super.setBounds(var1);
   }
}
