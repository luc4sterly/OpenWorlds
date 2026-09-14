package NET.worlds.scape;

import java.awt.CardLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Insets;
import java.awt.Panel;
import java.awt.Point;
import java.util.Vector;

class TabbedDisplayPanel extends Panel {
   private int count;
   private Vector cards = new Vector();
   private Vector cardNames = new Vector();

   TabbedDisplayPanel() {
      this.setLayout(new CardLayout());
   }

   void addItem(Component var1) {
      this.insertItem(this.cards.size(), var1);
   }

   void insertItem(int var1, Component var2) {
      String var3 = "" + this.count++;
      this.cardNames.insertElementAt(var3, var1);
      this.cards.insertElementAt(var2, var1);
      this.add(var3, var2);
      this.validate();
      this.repaint();
   }

   void removeItem(int var1) {
      this.remove((Component)this.cards.elementAt(var1));
      this.cards.removeElementAt(var1);
      this.cardNames.removeElementAt(var1);
   }

   public Component getComponent(int var1) {
      return (Component)this.cards.elementAt(var1);
   }

   void setChoice(int var1) {
      ((CardLayout)this.getLayout()).show(this, (String)this.cardNames.elementAt(var1));
   }

   public Insets insets() {
      return new Insets(0, 2, 2, 0);
   }

   public void paint(Graphics var1) {
      var1.setColor(this.getBackground());
      if (this.cards.size() != 0) {
         Dimension var2 = this.size();
         vLine(var1, 1, 0, var2.height);
         var1.setColor(this.getBackground().brighter());
         vLine(var1, 0, 0, var2.height - 2);
         var1.setColor(this.getBackground().darker());
         hLine(var1, 0, var2.height - 1, var2.width - 1);
         vLine(var1, var2.width - 1, var2.height - 1, 0);
         hLine(var1, 1, var2.height - 2, var2.width - 2);
         vLine(var1, var2.width - 2, var2.height - 2, 0);
      } else {
         var1.fillRect(0, 0, this.size().width, this.size().height);
      }
   }

   private static void vLine(Graphics var0, int var1, int var2, int var3) {
      var0.drawLine(var1, var2, var1, var3);
   }

   private static void hLine(Graphics var0, int var1, int var2, int var3) {
      var0.drawLine(var1, var2, var3, var2);
   }

   public Component locate(int var1, int var2) {
      if (!this.inside(var1, var2)) {
         return null;
      }

      int var3 = this.countComponents();

      for (int var4 = 0; var4 < var3; var4++) {
         Component var5 = this.getComponent(var4);
         Point var6 = var5.location();
         if (var5 != null && var5.isVisible() && var5.inside(var1 - var6.x, var2 - var6.y)) {
            return var5;
         }
      }

      return this;
   }
}
