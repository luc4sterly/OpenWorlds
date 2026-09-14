package NET.worlds.console;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Event;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Point;
import java.awt.Scrollbar;
import java.util.Vector;

public class TreePanel extends ExposedPanel implements DialogDisabled {
   private Vector items = new Vector();
   private boolean delayRepaints;
   private boolean needRepaint;
   private boolean needRecalc;
   private boolean needMakeVisible;
   private Scrollbar scrollbar = new WiderScrollbar();
   private int scrollPos = 0;
   private int linesVisible;
   private int selectedIndex = -1;
   private boolean hasFocus = true;
   private Font nFont = new Font(Console.message("TreeFont"), 0, 13);
   private FontMetrics nFontMetrics = this.getFontMetrics(this.nFont);
   private Font bFont = new Font(Console.message("TreeFont"), 1, 11);
   private FontMetrics bFontMetrics = this.getFontMetrics(this.bFont);
   private int fontHeight = Math.max(this.nFontMetrics.getHeight(), this.bFontMetrics.getHeight());
   private int itemHeight = this.fontHeight;
   private boolean isDialogDisabled;
   private static final int[] cxs = new int[]{0, 0, 6};
   private static final int[] cys = new int[]{6, -6, 0};
   private MoveablePolygon closedIcon = new MoveablePolygon(cxs, cys);
   private static final int[] oxs = new int[]{-5, 6, 0};
   private static final int[] oys = new int[]{0, 0, 6};
   private MoveablePolygon openedIcon = new MoveablePolygon(oxs, oys);
   private static final Color normBGColor = new Color(80, 80, 80);
   private static final Color normFGColor = new Color(190, 190, 190);
   private static final Color selFGColor = new Color(255, 255, 175);
   private static final int indentPixels = 14;

   public TreePanel() {
      this.setBackground(normBGColor);
      this.setLayout(new BorderLayout());
      this.add("East", this.scrollbar);
      this.scrollbar.hide();
   }

   public synchronized void delayRepaints(boolean var1) {
      if (!(this.delayRepaints = var1)) {
         if (this.needRecalc) {
            this.recalc();
         }

         if (this.needMakeVisible) {
            this.makeVisible(this.selectedIndex);
         }

         if (this.needRepaint) {
            this.repaint();
         }
      }
   }

   private synchronized void needRepaint(boolean var1, boolean var2) {
      this.needRepaint = true;
      this.needRecalc |= var1;
      this.needMakeVisible |= var2;
      this.delayRepaints(this.delayRepaints);
   }

   public synchronized int getSelectedIndex() {
      return this.selectedIndex;
   }

   public synchronized void select(int var1) {
      this.selectedIndex = var1;
      this.needRepaint(false, true);
   }

   public void setFocus(boolean var1) {
      if (this.hasFocus != var1) {
         this.hasFocus = var1;
         this.needRepaint(false, false);
      }
   }

   public boolean hasFocus() {
      return this.hasFocus;
   }

   public synchronized void reshape(int var1, int var2, int var3, int var4) {
      super.reshape(var1, var2, var3, var4);
      this.needRepaint(true, false);
   }

   public synchronized TreeNode getSelectedNode() {
      return this.selectedIndex != -1 ? (TreeNode)this.items.elementAt(this.selectedIndex) : null;
   }

   public synchronized void reset(Vector var1) {
      this.items = var1;
      this.needRepaint(true, false);
   }

   public synchronized void removeAllElements() {
      this.items.removeAllElements();
      this.needRepaint(true, false);
   }

   public synchronized void insertElementAt(TreeNode var1, int var2) {
      this.items.insertElementAt(var1, var2);
      this.needRepaint(true, false);
   }

   public synchronized void removeElementAt(int var1) {
      this.items.removeElementAt(var1);
      this.needRepaint(true, false);
   }

   public synchronized void addElement(TreeNode var1) {
      this.items.addElement(var1);
      this.needRepaint(true, false);
   }

   public int countElements() {
      return this.items.size();
   }

   public TreeNode elementAt(int var1) {
      return (TreeNode)this.items.elementAt(var1);
   }

   public TreeNode elementAt(Point var1) {
      int var2 = this.scrollPos + var1.y / this.itemHeight;
      return var2 < this.items.size() ? (TreeNode)this.items.elementAt(var2) : null;
   }

   private void makeVisible(int var1) {
      int var2 = this.items.size();
      if (var2 > this.linesVisible && (var1 < this.scrollPos || var1 >= this.scrollPos + this.linesVisible)) {
         this.setScrollValue(Math.min(var1 * this.itemHeight, this.scrollbar.getMaximum()));
      }

      this.needMakeVisible = false;
   }

   private void add(GridBagLayout var1, Component var2, GridBagConstraints var3) {
      var1.setConstraints(var2, var3);
      this.add(var2);
   }

   public synchronized void recalc() {
      int var1 = this.size().height;
      this.linesVisible = Math.max(1, var1 / this.itemHeight);
      int var2 = this.items.size();
      if (var2 > this.linesVisible) {
         if (!this.scrollbar.isVisible()) {
            this.scrollbar.show();
            this.validate();
         }

         this.scrollbar.setValues(this.scrollPos * this.itemHeight, this.linesVisible * this.itemHeight, 0, var2 * this.itemHeight);
         this.scrollbar.setPageIncrement(this.linesVisible * this.itemHeight);
         this.scrollbar.setLineIncrement(this.itemHeight);
      } else {
         if (this.scrollbar.isVisible()) {
            this.scrollbar.hide();
            this.validate();
         }

         this.scrollPos = 0;
      }

      this.needRecalc = false;
   }

   public synchronized void paint(Graphics var1) {
      super.paint(var1);
      int var2 = this.size().width;
      int var3 = this.size().height;
      int var4 = this.items.size();
      int var5 = 0;

      for (int var6 = this.scrollPos; var6 < var4; var6++) {
         TreeNode var7 = this.elementAt(var6);
         String var8 = var7.toString();
         boolean var9 = var7.displayAsTitle();
         Font var10 = this.nFont;
         FontMetrics var11 = this.nFontMetrics;
         if (var9) {
            var10 = this.bFont;
            var11 = this.bFontMetrics;
         }

         var1.setFont(var10);
         int var12 = var11.getAscent();
         int var13 = var7.getLevel() * 14;
         var1.setColor(normFGColor);
         if (var7.isOpen()) {
            this.openedIcon.drawFilled(var1, var13 + 5, var5 + var12 - 5);
         } else {
            this.closedIcon.drawFilled(var1, var13 + 5, var5 + var12 - 5);
         }

         if (var6 == this.selectedIndex) {
            var1.setColor(selFGColor);
         }

         var1.drawString(var8, var13 + 11 + 5, var5 + var12);
         if (var6 == this.selectedIndex && this.hasFocus) {
            var1.drawRect(var13 + 11 + 3, var5, var11.stringWidth(var8) + 3, this.itemHeight);
         }

         var5 += this.itemHeight;
         if (var5 >= var3) {
            break;
         }
      }

      this.needRepaint = false;
   }

   public boolean handleEvent(Event var1) {
      if (this.isDialogDisabled) {
         return false;
      }

      switch (var1.id) {
         case 601:
            return this.scrollLineUp();
         case 602:
            return this.scrollLineDown();
         case 603:
            return this.scrollPageUp();
         case 604:
            return this.scrollPageDown();
         case 605:
            return this.scrollAbsolute();
         default:
            return super.handleEvent(var1);
      }
   }

   public void dialogDisable(boolean var1) {
      this.isDialogDisabled = var1;
   }

   public synchronized boolean mouseDown(Event var1, int var2, int var3) {
      this.setFocus(true);
      int var4 = this.scrollPos + var3 / this.itemHeight;
      if (var4 >= 0 && var4 < this.items.size()) {
         if (var1.clickCount == 1) {
            this.treeSelect(var4);
            int var5 = var3 / this.itemHeight * this.itemHeight;
            TreeNode var6 = this.elementAt(var4);
            MoveablePolygon var7 = var6.isOpen() ? this.openedIcon : this.closedIcon;
            FontMetrics var8 = var6.displayAsTitle() ? this.nFontMetrics : this.bFontMetrics;
            var7.moveTo(var6.getLevel() * 14 + 5, var5 + var8.getAscent() - 5);
            if (var7.getBoundingBox().inside(var2, var3)) {
               this.treeOpen(var4);
            }
         } else {
            this.treeOpen(var4);
         }
      }

      return true;
   }

   public void treeSelect(int var1) {
   }

   public void treeOpen(int var1) {
   }

   private boolean setScrollValue(int var1) {
      var1 = Math.max(this.scrollbar.getMinimum(), var1);
      var1 = Math.min(this.scrollbar.getMaximum(), var1);
      this.scrollPos = var1 / this.itemHeight;
      this.scrollbar.setValue(this.scrollPos * this.itemHeight);
      this.needRepaint(false, false);
      return true;
   }

   private boolean scrollLineUp() {
      return this.setScrollValue(this.scrollPos * this.itemHeight - this.scrollbar.getLineIncrement());
   }

   private boolean scrollLineDown() {
      return this.setScrollValue(this.scrollPos * this.itemHeight + this.scrollbar.getLineIncrement());
   }

   private boolean scrollPageUp() {
      return this.setScrollValue(this.scrollPos * this.itemHeight - this.scrollbar.getPageIncrement());
   }

   private boolean scrollPageDown() {
      return this.setScrollValue(this.scrollPos * this.itemHeight + this.scrollbar.getPageIncrement());
   }

   private boolean scrollAbsolute() {
      return this.setScrollValue(this.scrollbar.getValue());
   }
}
