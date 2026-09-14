package NET.worlds.console;

import java.awt.Canvas;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.Toolkit;
import java.util.Vector;

class SplashCanvas extends Canvas {
   protected String name;
   protected Image image;
   protected Dimension dim;
   protected Vector overlays = new Vector();

   SplashCanvas(String var1) {
      this.name = var1;
   }

   public void flush() {
      this.image.flush();
      this.image = null;

      for (int var1 = 0; var1 < this.overlays.size(); var1++) {
         Overlay var2 = (Overlay)this.overlays.elementAt(var1);
         var2.flush();
      }

      this.overlays.removeAllElements();
   }

   public void paint(Graphics var1) {
      super.paint(var1);
      var1.drawImage(this.image, 0, 0, this);

      for (int var2 = 0; var2 < this.overlays.size(); var2++) {
         Overlay var3 = (Overlay)this.overlays.elementAt(var2);
         var3.paint(var1, this);
      }
   }

   public void setImage(String var1) {
      this.name = var1;
      this.image = null;
      this.imageSize();
   }

   public void addOverlay(String var1, int var2, int var3) {
      Overlay var4 = new Overlay(var1, var2, var3);
      Dimension var5 = var4.imageSize(this);
      this.overlays.addElement(var4);
      this.repaint(var2, var3, var5.width, var5.height);
   }

   public void removeOverlay(String var1, int var2, int var3) {
      for (int var4 = 0; var4 < this.overlays.size(); var4++) {
         Overlay var5 = (Overlay)this.overlays.elementAt(var4);
         if (var5.matches(var1, var2, var3)) {
            Dimension var6 = var5.imageSize(this);
            this.overlays.removeElementAt(var4);
            this.repaint(var2, var3, var6.width, var6.height);
            return;
         }
      }
   }

   private Dimension imageSize() {
      if (this.image == null) {
         this.image = getEarlyImage(this.name, this);
         if (this.image != null) {
            int var1 = this.image.getWidth(this);
            int var2 = this.image.getHeight(this);
            if (var1 != -1 && var2 != -1) {
               return this.dim = new Dimension(var1, var2);
            }
         }

         this.dim = new Dimension(0, 0);
      }

      for (int var3 = 0; var3 < this.overlays.size(); var3++) {
         Overlay var4 = (Overlay)this.overlays.elementAt(var3);
         var4.imageSize(this);
      }

      return this.dim;
   }

   public static Image getEarlyImage(String var0, Component var1) {
      for (int var2 = 0; var2 < 2; var2++) {
         String var3 = Gamma.earlyURLUnalias(var0);
         Image var4 = Toolkit.getDefaultToolkit().getImage(var3);
         MediaTracker var5 = new MediaTracker(var1);
         var5.addImage(var4, 0);

         try {
            var5.waitForAll();
         } catch (InterruptedException var7) {
         }

         if (!var5.isErrorAny()) {
            return var4;
         }

         if (var2 == 0) {
            var0 = "..\\" + var0;
         }
      }

      return null;
   }

   public Dimension preferredSize() {
      return this.imageSize();
   }

   public Dimension minimumSize() {
      return this.imageSize();
   }
}
