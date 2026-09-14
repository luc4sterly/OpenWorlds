package NET.worlds.console;

import NET.worlds.core.Debug;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Panel;
import java.awt.Point;

public class ScapePicPanel extends Panel {
   private static final int QUARTERED = 0;
   private static final int UPPERLEFT = 1;
   private ScapePicImage image = null;
   private int hWnd;
   private int drawMode = 0;

   public ScapePicPanel() {
      this(null);
   }

   public ScapePicPanel(ScapePicImage var1) {
      this.setImage(var1);
   }

   public void setImage(ScapePicImage var1) {
      this.image = var1;
   }

   public void paint(Graphics var1) {
      this.drawBackground();
      super.paint(var1);
   }

   public void update(Graphics var1) {
      this.paint(var1);
   }

   public void setQuartered() {
      this.drawMode = 0;
   }

   public void setUpperLeft() {
      this.drawMode = 1;
   }

   private void drawBackground() {
      Debug.dAssert(this.drawMode == 1 || this.drawMode == 0);
      if (this.image != null) {
         Dimension var1 = this.size();
         Debug.dAssert(var1 != null);
         Debug.dAssert(var1.height >= 0 && var1.width >= 0);
         if (this.drawMode == 1) {
            for (int var2 = 0; var2 < var1.height; var2 += this.image.getHeight()) {
               for (int var3 = 0; var3 < var1.width; var3 += this.image.getWidth()) {
                  this.drawScapePicImage(this.image, var3, var2, 0, 0, this.image.getWidth(), this.image.getHeight());
               }
            }
         }

         if (this.drawMode == 0) {
            int var10 = var1.width / 2;
            int var11 = var1.height / 2;

            for (int var4 = 0; var4 < var11; var4 += this.image.getHeight()) {
               for (int var5 = 0; var5 < var10; var5 += this.image.getWidth()) {
                  int var6 = Math.min(var10 - var5, this.image.getWidth());
                  int var7 = Math.min(var11 - var4, this.image.getHeight());
                  this.drawScapePicImage(this.image, var5, var4, 0, 0, var6, var7);
               }
            }

            for (int var12 = 0; var12 < var11; var12 += this.image.getHeight()) {
               for (int var15 = var1.width; var15 > var10; var15 -= this.image.getWidth()) {
                  int var18 = Math.max(var15 - this.image.getWidth(), var10);
                  int var21 = this.image.getWidth() - (var15 - var18);
                  int var8 = Math.min(var11 - var12, this.image.getHeight());
                  this.drawScapePicImage(this.image, var18, var12, var21, 0, var15 - var18, var8);
               }
            }

            for (int var13 = var1.height; var13 > var11; var13 -= this.image.getHeight()) {
               for (int var16 = 0; var16 < var10; var16 += this.image.getWidth()) {
                  int var19 = Math.min(var10 - var16, this.image.getWidth());
                  int var22 = Math.max(var13 - this.image.getHeight(), var11);
                  int var24 = this.image.getHeight() - (var13 - var22);
                  this.drawScapePicImage(this.image, var16, var22, 0, var24, var19, var13 - var22);
               }
            }

            for (int var14 = var1.height; var14 > var11; var14 -= this.image.getHeight()) {
               for (int var17 = var1.width; var17 > var10; var17 -= this.image.getWidth()) {
                  int var20 = Math.max(var17 - this.image.getWidth(), var10);
                  int var23 = this.image.getWidth() - (var17 - var20);
                  int var25 = Math.max(var14 - this.image.getHeight(), var11);
                  int var9 = this.image.getHeight() - (var14 - var25);
                  this.drawScapePicImage(this.image, var20, var25, var23, var9, var17 - var20, var14 - var25);
               }
            }
         }
      }
   }

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

      ScapePicCanvas.bitBlt(this.hWnd, var1.getDIB(), var2, var3, var4, var5, var6, var7);
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
}
