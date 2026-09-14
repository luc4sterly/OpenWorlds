package NET.worlds.console;

import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Insets;
import java.awt.LayoutManager;

class StackedLayout implements LayoutManager {
   public StackedLayout() {
   }

   public void addLayoutComponent(String var1, Component var2) {
   }

   public void removeLayoutComponent(Component var1) {
   }

   public Dimension preferredLayoutSize(Container var1) {
      Dimension var2 = new Dimension(0, 0);
      int var3 = var1.getComponentCount();

      for (int var4 = 0; var4 < var3; var4++) {
         Component var5 = var1.getComponent(var4);
         Dimension var6 = var5.getPreferredSize();
         var2.width = Math.max(var2.width, var6.width);
         var2.height = var2.height + var6.height;
      }

      Insets var7 = var1.getInsets();
      var2.width = var2.width + var7.left + var7.right;
      var2.height = var2.height + var7.top + var7.bottom;
      return var2;
   }

   public Dimension minimumLayoutSize(Container var1) {
      return this.preferredLayoutSize(var1);
   }

   public void layoutContainer(Container var1) {
      Insets var2 = var1.getInsets();
      Dimension var3 = var1.getSize();
      int var4 = var2.left;
      int var5 = var2.top;
      int var6 = var3.width - var2.left - var2.right;
      int var7 = var3.height - var2.top - var2.bottom;
      int var8 = var1.getComponentCount();

      for (int var9 = 0; var9 < var8; var9++) {
         Component var10 = var1.getComponent(var9);
         int var11 = var10.getPreferredSize().height;
         if (var9 == var8 - 1) {
            var11 = Math.max(var11, var7);
         } else {
            var11 = Math.min(var11, var7);
         }

         var11 = Math.max(0, var11);
         var10.setBounds(var4, var5, var6, var11);
         var7 -= var11;
         var5 += var11;
      }
   }
}
