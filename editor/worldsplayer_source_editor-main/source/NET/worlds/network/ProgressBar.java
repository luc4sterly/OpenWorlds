package NET.worlds.network;

import NET.worlds.console.Console;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Toolkit;

public class ProgressBar extends Canvas {
   private static final int borderThickness = 1;
   private static final int heightPadding = 2;
   private int barWidth;
   private int barHeight;
   private Font font;
   private int fillWidth = -1;
   private double amt;
   private int percent;

   public ProgressBar(int var1) {
      this.barWidth = var1;
      this.font = new Font(Console.message("DialogFont"), 1, 14);
      FontMetrics var2 = Toolkit.getDefaultToolkit().getFontMetrics(this.font);
      this.barHeight = var2.getAscent() + 4 + 2;
   }

   public void setProgress(double var1) {
      int var3 = this.size().width;
      if (var3 == 0) {
         var3 = this.barWidth;
      }

      int var4 = (int)(var1 * (var3 - 2));
      if (var4 != this.fillWidth) {
         this.fillWidth = var4;
         this.percent = (int)Math.round(100.0 * var1);
         this.repaint();
      }
   }

   public Dimension preferredSize() {
      return new Dimension(this.barWidth, this.barHeight);
   }

   public Dimension minimumSize() {
      return this.preferredSize();
   }

   public boolean handleEvent(Event var1) {
      return var1.id == 201 ? true : super.handleEvent(var1);
   }

   public void paint(Graphics var1) {
      Dimension var2 = this.size();
      int var3 = var2.width;
      int var4 = var2.height;
      var1.setColor(Color.lightGray);
      var1.draw3DRect(0, 0, var3 - 1, var4 - 1, true);
      if (this.fillWidth > 0) {
         var1.setColor(Color.blue);
         var1.fillRect(1, 1, this.fillWidth, var4 - 2);
      }

      String var5 = "" + this.percent + "%";
      var1.setFont(this.font);
      FontMetrics var6 = var1.getFontMetrics();
      int var7 = var6.stringWidth(var5);
      var1.setColor(Color.black);
      var1.drawString(var5, (var3 - var7) / 2, (var4 + var6.getAscent()) / 2 - 1);
   }
}
