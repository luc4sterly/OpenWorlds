package NET.worlds.console;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Toolkit;
import java.util.Vector;

public class TextCanvas extends Canvas {
   private Dimension calcSize;
   private Font font;
   private FontMetrics metrics;
   private Vector lines = new Vector();

   public TextCanvas(String var1, int var2) {
      this.font = new Font(Console.message("CanvasFont"), 0, 12);
      this.metrics = Toolkit.getDefaultToolkit().getFontMetrics(this.font);
      char[] var3 = var1.toCharArray();
      int var4 = 0;
      int var5 = 0;
      int var6 = 0;
      int var7 = 0;
      var5 = var4;

      while (var5 < var3.length) {
         char var8 = var3[var5];
         boolean var9 = var8 == '\n';
         if (!var9 && var5 == var3.length - 1) {
            var9 = true;
            var5++;
         }

         if (var8 != ' ' && !var9) {
            var5++;
         } else {
            var7 = this.metrics.charsWidth(var3, var4, var5 - var4);
            if (var2 != -1 && var7 > var2) {
               var5 = var6;
            } else if ((var2 == -1 || var7 < var2) && !var9) {
               var6 = var5++;
               continue;
            }

            this.lines.addElement(new String(var3, var4, var5 - var4));
            var4 = var5 + 1;

            while (var4 < var3.length && var3[var4] == ' ') {
               var4++;
            }

            var5 = var4;
            var6 = var4;
         }
      }

      this.calcSize = new Dimension(var2 == -1 ? var7 : var2, this.metrics.getHeight() * this.lines.size());
   }

   public void paint(Graphics var1) {
      super.paint(var1);
      var1.setFont(this.font);
      var1.setColor(Color.black);
      int var2 = this.metrics.getHeight();
      int var3 = this.metrics.getAscent() + this.metrics.getLeading();

      for (int var4 = 0; var4 < this.lines.size(); var4++) {
         String var5 = (String)this.lines.elementAt(var4);
         var1.drawString(var5, 0, var3);
         var3 += var2;
      }
   }

   public Dimension preferredSize() {
      return this.calcSize;
   }
}
