package NET.worlds.console;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;

class Overlay {
   private String name;
   private int x;
   private int y;
   private Image image;
   private Dimension dim;

   public Overlay(String var1, int var2, int var3) {
      this.name = var1;
      this.x = var2;
      this.y = var3;
      this.image = null;
   }

   public void paint(Graphics var1, Component var2) {
      if (this.image != null) {
         var1.drawImage(this.image, this.x, this.y, var2);
      }
   }

   public Dimension imageSize(Component var1) {
      if (this.image == null) {
         this.image = SplashCanvas.getEarlyImage(this.name, var1);
         if (this.image != null) {
            int var2 = this.image.getWidth(var1);
            int var3 = this.image.getHeight(var1);
            if (var2 != -1 && var3 != -1) {
               return this.dim = new Dimension(var2, var3);
            }
         }

         this.dim = new Dimension(0, 0);
      }

      return this.dim;
   }

   public boolean matches(String var1, int var2, int var3) {
      return var2 == this.x && var3 == this.y && var1.equals(this.name);
   }

   public void flush() {
      this.image.flush();
      this.image = null;
   }
}
