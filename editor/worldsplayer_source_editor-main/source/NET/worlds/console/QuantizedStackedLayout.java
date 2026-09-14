package NET.worlds.console;

import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Insets;

class QuantizedStackedLayout extends StackedLayout {
   ColorFiller m_filler;

   public QuantizedStackedLayout(ColorFiller var1) {
      this.m_filler = var1;
   }

   public void layoutContainer(Container var1) {
      int var2 = var1.getComponentCount();
      Insets var3 = var1.getInsets();
      Dimension var4 = var1.getSize();
      int var5 = var4.width - var3.left - var3.right;
      int var6 = var4.height - var3.top - var3.bottom;
      int var7 = 0;

      for (int var9 = 0; var9 < var2; var9++) {
         Component var10 = var1.getComponent(var9);
         if (var10 != this.m_filler) {
            int var8 = var10.getPreferredSize().height;
            if (var9 == var2 - 1) {
               var8 = Math.max(var8, var6);
            } else {
               var8 = Math.min(var8, var6);
            }

            var8 = Math.max(0, var8);
            var6 -= var8;
            if (var10 instanceof QuantizedCanvas) {
               QuantizedCanvas var11 = (QuantizedCanvas)var10;
               var7 += var11.getRemainder(var8);
            }
         }
      }

      this.m_filler.setHeight(var7);
      int var19 = var3.left;
      int var20 = var3.top;
      var6 = var4.height - var3.top - var3.bottom;

      for (int var21 = 0; var21 < var2; var21++) {
         Component var12 = var1.getComponent(var21);
         int var16 = var12.getPreferredSize().height;
         if (var21 == var2 - 1) {
            var16 = Math.max(var16, var6);
         } else {
            var16 = Math.min(var16, var6);
         }

         var16 = Math.max(0, var16);
         var12.setBounds(var19, var20, var5, var16);
         var6 -= var16;
         var20 += var16;
      }
   }
}
