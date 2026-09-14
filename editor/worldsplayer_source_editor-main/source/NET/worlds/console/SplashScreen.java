package NET.worlds.console;

import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Toolkit;

public class SplashScreen extends java.awt.Window {
   private SplashCanvas sc = null;

   public SplashScreen(String var1, String var2) {
      super(new Frame(var1));
      this.sc = new SplashCanvas(var2);
      this.add(this.sc);
      this.pack();
      this.center();
   }

   public void setImageName(String var1) {
      this.sc.setImage(var1);
      this.pack();
      this.center();
      this.sc.repaint();
   }

   public void addOverlay(String var1, int var2, int var3) {
      this.sc.addOverlay(var1, var2, var3);
      this.center();
   }

   public void removeOverlay(String var1, int var2, int var3) {
      this.sc.removeOverlay(var1, var2, var3);
   }

   public void center() {
      Dimension var1 = this.getSize();
      Dimension var2 = Toolkit.getDefaultToolkit().getScreenSize();
      int var3 = var2.width >= var1.width ? (var2.width - var1.width) / 2 : 0;
      int var4 = var2.height >= var1.height ? (var2.height - var1.height) / 2 : 0;
      this.setLocation(var3, var4);
   }

   public void dispose() {
      super.dispose();

      try {
         this.sc.flush();
      } catch (NullPointerException var2) {
         System.out.println("Flushing went bad!");
      }
   }
}
