package NET.worlds.console;

import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.Rectangle;

class MoveablePolygon extends Polygon {
   private int xOffset;
   private int yOffset;
   private Rectangle boundingBox = new Rectangle();

   public MoveablePolygon() {
   }

   public MoveablePolygon(int[] var1, int[] var2) {
      super(var1, var2, var1.length);
   }

   public void moveTo(int var1, int var2) {
      if (var1 != this.xOffset || var2 != this.yOffset) {
         int var3 = var1 - this.xOffset;
         int var4 = var2 - this.yOffset;
         this.xOffset = var1;
         this.yOffset = var2;

         for (int var5 = 0; var5 < this.npoints; var5++) {
            this.xpoints[var5] = this.xpoints[var5] + var3;
            this.ypoints[var5] = this.ypoints[var5] + var4;
         }
      }
   }

   public void drawFilled(Graphics var1, int var2, int var3) {
      this.moveTo(var2, var3);
      var1.fillPolygon(this);
   }

   public Rectangle getBoundingBox() {
      int var1 = Integer.MAX_VALUE;
      int var2 = Integer.MAX_VALUE;
      int var3 = Integer.MIN_VALUE;
      int var4 = Integer.MIN_VALUE;

      for (int var5 = 0; var5 < this.npoints; var5++) {
         int var6 = this.xpoints[var5];
         var1 = Math.min(var1, var6);
         var3 = Math.max(var3, var6);
         int var7 = this.ypoints[var5];
         var2 = Math.min(var2, var7);
         var4 = Math.max(var4, var7);
      }

      this.boundingBox.reshape(var1, var2, var3 - var1, var4 - var2);
      return this.boundingBox;
   }
}
