package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogDisabled;
import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Insets;
import java.awt.Panel;
import java.awt.Point;
import java.util.Vector;

public class TabbedPanel extends Panel implements ClickEventHandler, DialogDisabled {
   private Vector entries = new Vector();
   private int rows;
   private int itemWidth;
   private int itemHeight;
   private int itemsPerRow;
   private int choice;
   private Font nFont;
   private FontMetrics nFontMetrics;
   private Font bFont;
   private FontMetrics bFontMetrics;
   private int fontHeight;
   private TabbedDisplayPanel disp = new TabbedDisplayPanel();
   private ClickEventHandler handler;
   private boolean needRecalc;
   private boolean isDialogDisabled;

   public TabbedPanel(ClickEventHandler var1) {
      this.handler = var1;
      this.setLayout(new BorderLayout());
      this.add("Center", this.disp);
   }

   public TabbedPanel() {
      this(null);
      this.handler = this;
   }

   public void addItem(String var1, Component var2) {
      this.entries.addElement(var1);
      this.needRecalc = true;
      this.repaint();
      this.disp.addItem(var2);
   }

   public void insertItem(int var1, String var2, Component var3) {
      this.entries.insertElementAt(var2, var1);
      this.disp.insertItem(var1, var3);
      if (var1 <= this.choice) {
         this.choice = Math.min(this.choice + 1, this.entries.size() - 1);
      }

      this.needRecalc = true;
      this.repaint();
   }

   public void removeItem(int var1) {
      this.entries.removeElementAt(var1);
      this.disp.removeItem(var1);
      if (var1 == this.choice) {
         int var2 = this.entries.size();
         if (var2 > 0) {
            this.choice = Math.min(this.choice, var2 - 1);
            this.disp.setChoice(this.choice);
         }
      } else if (var1 < this.choice) {
         this.choice--;
      }

      this.needRecalc = true;
      this.repaint();
   }

   public void select(int var1) {
      this.choice = var1;
      this.repaint();
      this.disp.setChoice(var1);
   }

   public String getName(int var1) {
      return (String)this.entries.elementAt(var1);
   }

   public void setName(int var1, String var2) {
      this.entries.setElementAt(var2, var1);
      this.needRecalc = true;
      this.repaint();
   }

   public Component getComponent(int var1) {
      return var1 < this.entries.size() ? this.disp.getComponent(var1) : null;
   }

   public int selected() {
      return this.choice;
   }

   public int itemAt(Point var1) {
      if (!this.needRecalc) {
         Point var2 = new Point(0, 0);
         int var3 = this.entries.size();

         for (int var4 = 0; var4 < var3; var4++) {
            this.getPosition(var4, var2);
            if (var1.x >= var2.x && var1.y >= var2.y && var1.x < var2.x + this.itemWidth && var1.y < var2.y + this.itemHeight) {
               return var4;
            }
         }
      }

      return -1;
   }

   public void addNotify() {
      super.addNotify();
      this.nFont = new Font(Console.message("NotifyFont"), 0, 13);
      this.nFontMetrics = this.getFontMetrics(this.nFont);
      this.bFont = new Font(Console.message("NotifyFont"), 1, 14);
      this.bFontMetrics = this.getFontMetrics(this.bFont);
      this.fontHeight = Math.max(this.nFontMetrics.getHeight(), this.bFontMetrics.getHeight());
      this.itemHeight = this.fontHeight + 5;
   }

   public Insets insets() {
      if (this.needRecalc) {
         this.recalc();
      }

      return new Insets(this.rows * this.itemHeight, 0, 0, 0);
   }

   public void reshape(int var1, int var2, int var3, int var4) {
      super.reshape(var1, var2, var3, var4);
      this.needRecalc = true;
      this.repaint();
   }

   private void recalc() {
      boolean var1 = false;
      boolean var2 = false;
      boolean var3 = false;
      int var4 = this.entries.size();
      this.itemWidth = 0;

      for (int var5 = 0; var5 < var4; var5++) {
         String var6 = (String)this.entries.elementAt(var5);
         int var7 = Math.max(this.bFontMetrics.stringWidth(var6), this.nFontMetrics.stringWidth(" " + var6 + " "));
         this.itemWidth = Math.max(var7, this.itemWidth);
      }

      this.itemWidth += 4;
      this.itemsPerRow = Math.max(1, this.size().width / this.itemWidth);
      this.rows = (var4 + this.itemsPerRow - 1) / this.itemsPerRow;
      this.needRecalc = false;
      this.invalidate();
      this.validate();
   }

   private void getPosition(int var1, Point var2) {
      int var3 = this.entries.size();
      int var4 = this.choice / this.itemsPerRow;
      int var5 = var1 / this.itemsPerRow;
      int var6 = var5;
      int var7 = var1 - var5 * this.itemsPerRow;
      var2.x = var7 * this.itemWidth;
      var2.y = (this.rows - 1 - var6) * this.itemHeight - 2;
   }

   private static void vLine(Graphics var0, int var1, int var2, int var3) {
      var0.drawLine(var1, var2, var1, var3);
   }

   private static void hLine(Graphics var0, int var1, int var2, int var3) {
      var0.drawLine(var1, var2, var3, var2);
   }

   public void paint(Graphics var1) {
      if (this.needRecalc) {
         this.recalc();
      }

      var1.setColor(this.getBackground());
      var1.fillRect(0, 0, this.size().width, this.size().height);
      int var2 = this.entries.size();
      if (var2 != 0) {
         Point var3 = new Point(0, 0);
         int var4 = this.itemWidth - 4;

         for (int var5 = 0; var5 < var2; var5++) {
            this.getPosition(var5, var3);
            String var6 = (String)this.entries.elementAt(var5);
            int var7 = var3.x;
            int var8 = var3.y + 4;
            int var9 = var8 + this.fontHeight;
            int var10 = var8;
            Font var11 = this.nFont;
            FontMetrics var12 = this.nFontMetrics;
            boolean var13 = var5 == this.choice;
            if (var13) {
               var8 = var3.y + 2;
               var9 = var8 + this.fontHeight + 4;
               var10 = var8 + 1;
               var11 = this.bFont;
               var12 = this.bFontMetrics;
            }

            int var14 = var12.stringWidth(var6);
            int var15 = (var4 - var14) / 2;
            int var16 = var7 + var4;
            var1.setFont(var11);
            var1.setColor(this.getBackground().brighter());
            if (var13) {
               hLine(var1, 0, var9, var7);
               hLine(var1, var16 + 3, var9, this.size().width);
            }

            vLine(var1, var7, var9, var8 + 2);
            var1.drawLine(var7, var8 + 2, var7 + 2, var8);
            hLine(var1, var7 + 2, var8, var16);
            var1.setColor(this.getBackground().darker());
            vLine(var1, var16 + 1, var8 + 1, var9);
            vLine(var1, var16 + 2, var8 + 2, var9);
            var1.setColor(this.getForeground());
            var1.drawString(var6, var7 + 1 + var15, var10 + var12.getAscent() + var12.getLeading());
         }
      }
   }

   public void clickEvent(Component var1, Point var2, int var3) {
   }

   public boolean mouseDown(java.awt.Event var1, int var2, int var3) {
      Point var4 = new Point(var2, var3);
      int var5 = this.itemAt(var4);
      if (var5 != -1) {
         this.choice = var5;
         this.repaint();
         this.disp.setChoice(this.choice);
         byte var6 = 1;
         if (var1.metaDown()) {
            var6 |= 4;
         }

         this.handler.clickEvent(this, var4, var6);
         return true;
      } else {
         return false;
      }
   }

   public boolean handleEvent(java.awt.Event var1) {
      return this.isDialogDisabled ? false : super.handleEvent(var1);
   }

   public void dialogDisable(boolean var1) {
      this.isDialogDisabled = var1;
      Component var2 = this.getComponent(this.selected());
      if (var2 != null && var2 instanceof DialogDisabled) {
         ((DialogDisabled)var2).dialogDisable(var1);
      }
   }
}
