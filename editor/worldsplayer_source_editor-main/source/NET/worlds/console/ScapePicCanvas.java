package NET.worlds.console;

import NET.worlds.core.Debug;
import java.awt.Canvas;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Point;

public class ScapePicCanvas extends Canvas {
   private int hWnd;

   public void drawScapePicImage(ScapePicImage var1, int var2, int var3, int var4, int var5, int var6, int var7) {
      if (this.hWnd == 0) {
         Point var8 = this.locationInWindow();
         Dimension var9 = this.size();
         String var10 = this.getFrameTitle();
         Debug.dAssert(var10 != null);
         int var11 = Window.findWindow(var10);
         Debug.dAssert(var11 != 0);
         this.hWnd = Window.findChildWindow(var11, var8.x, var8.y, var9.width, var9.height);
         Debug.dAssert(this.hWnd != 0);
      }

      bitBlt(this.hWnd, var1.getDIB(), var2, var3, var4, var5, var6, var7);
   }

   private String getFrameTitle() {
      for (Container var1 = this.getParent(); var1 != null; var1 = var1.getParent()) {
         if (var1 instanceof Frame) {
            return ((Frame)var1).getTitle();
         }
      }

      return null;
   }

   private Point locationInWindow() {
      Point var1 = this.location();

      for (Container var2 = this.getParent(); var2 != null; var2 = var2.getParent()) {
         Point var3 = var2.location();
         var1.translate(var3.x, var3.y);
      }

      return var1;
   }

   public static native void bitBlt(int var0, int var1, int var2, int var3, int var4, int var5, int var6, int var7);
}
