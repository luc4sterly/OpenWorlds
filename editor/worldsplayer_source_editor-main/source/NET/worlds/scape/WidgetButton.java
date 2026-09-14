package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.ImageCanvas;
import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;

abstract class WidgetButton extends Canvas {
   private String name;
   private Image image;
   private Dimension dim;
   private String prompt;
   private ToolBar toolbar;
   private boolean depressed;

   WidgetButton(ToolBar var1, String var2, String var3) {
      this.name = var2;
      this.toolbar = var1;
      this.prompt = var3;
   }

   public WObject getWObject() {
      return this.toolbar.getCurrentWObject();
   }

   public String drag(boolean var1, float var2, float var3) {
      return null;
   }

   protected ToolBar getToolBar() {
      return this.toolbar;
   }

   protected Point3Temp getWorldAxis(int var1, int var2, int var3) {
      Point3Temp var4 = new Point3(var1, var2, var3).vectorTimes(Pilot.getActive());
      float var5 = Math.abs(var4.x);
      float var6 = Math.abs(var4.y);
      float var7 = Math.abs(var4.z);
      if (var5 > var6) {
         if (var5 > var7) {
            return var4.x > 0.0F ? Point3Temp.make(1.0F, 0.0F, 0.0F) : Point3Temp.make(-1.0F, 0.0F, 0.0F);
         }
      } else if (var6 > var7) {
         return var4.y > 0.0F ? Point3Temp.make(0.0F, 1.0F, 0.0F) : Point3Temp.make(0.0F, -1.0F, 0.0F);
      }

      return var4.z > 0.0F ? Point3Temp.make(0.0F, 0.0F, 1.0F) : Point3Temp.make(0.0F, 0.0F, -1.0F);
   }

   protected void applyWorldTransform(boolean var1, Transform var2) {
      WObject var3 = this.getWObject();
      if (var1) {
         Console.getFrame().getEditTile().addUndoable(new UndoablTransform(var3));
      }

      Point3Temp var4 = var3.getPosition();
      var3.moveTo(0.0F, 0.0F, 0.0F).post(var2).moveBy(var4);
      var3.markEdited();
   }

   public void draw(boolean var1) {
      this.depressed = var1;
      Graphics var2 = this.getGraphics();
      this.drawOutline(var2);
      var2.dispose();
   }

   public void perform() {
   }

   public boolean usesDrag() {
      return true;
   }

   private void drawOutline(Graphics var1) {
      var1.setColor(this.getBackground());
      var1.draw3DRect(0, 0, this.dim.width - 1, this.dim.height - 1, !this.depressed);
   }

   public boolean available() {
      return this.getWObject() != null;
   }

   public void paint(Graphics var1) {
      super.paint(var1);
      if (this.available() && this.dim.width != 0) {
         var1.drawImage(this.image, 2, 2, this);
         this.drawOutline(var1);
      }
   }

   private Dimension imageSize() {
      if (this.image == null) {
         this.image = ImageCanvas.getSystemImage(this.name, this);
         if (this.image != null) {
            int var1 = this.image.getWidth(this);
            int var2 = this.image.getHeight(this);
            if (var1 != -1 && var2 != -1) {
               return this.dim = new Dimension(var1 + 4, var2 + 4);
            }
         }

         this.dim = new Dimension(0, 0);
      }

      return this.dim;
   }

   public Dimension preferredSize() {
      return this.imageSize();
   }

   public Dimension minimumSize() {
      return this.imageSize();
   }

   public String getPrompt() {
      return this.prompt;
   }
}
