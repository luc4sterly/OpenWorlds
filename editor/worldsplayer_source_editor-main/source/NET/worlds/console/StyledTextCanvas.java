package NET.worlds.console;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Scrollbar;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;

class StyledTextCanvas extends Canvas {
   public StyledTextCanvas() {
      this.enableEvents(29L);
      this.setEnabled(true);
   }

   public void setBounds(int var1, int var2, int var3, int var4) {
      if (this.getParent() instanceof GammaTextArea) {
         GammaTextArea var5 = (GammaTextArea)this.getParent();
         var5.setWidth(var3);
         var5.setHeight(var4);
         var5.rewrap();
      }

      super.setBounds(var1, var2, var3, var4);
   }

   protected void processMouseEvent(MouseEvent var1) {
      if (var1.getID() == 500) {
         this.getParent().requestFocus();
      }

      super.processMouseEvent(var1);
   }

   protected void processKeyEvent(KeyEvent var1) {
      if (var1.getID() == 401) {
         Scrollbar var2 = null;
         if (this.getParent() instanceof GammaTextArea) {
            GammaTextArea var3 = (GammaTextArea)this.getParent();
            var2 = var3.getVertScrollbar();
         }

         if (var1.getKeyCode() == 33) {
            if (var2 != null && var2.isEnabled()) {
               var2.dispatchEvent(var1);
            }
         } else if (var1.getKeyCode() == 34 && var2 != null && var2.isEnabled()) {
            var2.dispatchEvent(var1);
         }
      }

      super.processKeyEvent(var1);
   }

   public void update(Graphics var1) {
      this.paint(var1);
   }

   public void paint(Graphics var1) {
      if (this.getParent().isEnabled()) {
         GammaTextArea var2 = (GammaTextArea)this.getParent();
         Rectangle var3 = this.getBounds();
         Image var4 = this.createImage(var3.width, var3.height);
         Graphics var5 = var4.getGraphics();
         var5.setColor(GammaTextArea.getBackgroundColor());
         var5.fillRect(var3.x, var3.y, var3.width, var3.height);
         var5.setColor(Color.black);
         if (var2.getHasFocus()) {
            var5.setColor(Color.blue);
            var5.drawRect(var3.x, var3.y, var3.width - 1, var3.height - 1);
            var5.drawRect(var3.x + 1, var3.y + 1, var3.width - 2, var3.height - 2);
            var5.setColor(Color.black);
         }

         var5.setFont(var2.getFont());
         FontMetrics var6 = var5.getFontMetrics(var2.getFont());
         if (var2.getNumLines() <= var2.getCanvasLines()) {
            for (int var9 = 0; var9 < var2.getNumLines(); var9++) {
               var2.drawLine(var5, var9, (var9 + 1) * var6.getHeight());
            }
         } else {
            int var7 = var2.getScrollLine();

            for (int var8 = 1; var7 < var2.getNumLines(); var8++) {
               var2.drawLine(var5, var7, var8 * var6.getHeight());
               var7++;
            }
         }

         var1.drawImage(var4, 0, 0, this);
      }
   }
}
