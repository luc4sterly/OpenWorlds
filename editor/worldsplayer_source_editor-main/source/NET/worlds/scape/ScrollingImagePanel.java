package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogDisabled;
import NET.worlds.console.ExposedPanel;
import NET.worlds.console.WiderScrollbar;
import NET.worlds.network.URL;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.Point;
import java.awt.Scrollbar;
import java.awt.Toolkit;
import java.util.Enumeration;
import java.util.Vector;

public class ScrollingImagePanel extends ExposedPanel implements LibraryDropTarget, DialogDisabled {
   private Scrollbar scrollbar = new WiderScrollbar();
   private Vector items;
   private int cellWidth;
   private int cellHeight;
   private Font font = new Font(Console.message("ScImageFont"), 1, 12);
   private FontMetrics metrics = this.getFontMetrics(this.font);
   private int ascent = this.metrics.getAscent();
   private int descent = this.metrics.getDescent();
   private int textHeight = this.ascent + this.descent;
   private int scrollPos = 0;
   private ClickEventHandler handler;
   private ScrollingListElement downClicked;
   private boolean isDownClicked;
   private int maxScrollPos;
   private boolean useIcons = false;
   private boolean isDialogDisabled;

   public ScrollingImagePanel(ClickEventHandler var1, Vector var2, boolean var3) {
      this.handler = var1;
      this.setFont(this.font);
      this.setForeground(Color.black);
      this.setBackground(Color.lightGray);
      this.items = new Vector();
      this.setContents(var2, false);
      this.setLayout(new BorderLayout());
      this.add("East", this.scrollbar);
      this.useIcons = var3;
   }

   public void resetContents(Vector var1) {
      this.setContents(var1);
   }

   protected void add(GridBagLayout var1, Component var2, GridBagConstraints var3) {
      var1.setConstraints(var2, var3);
      this.add(var2);
   }

   public boolean handleEvent(java.awt.Event var1) {
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

   private void setContents(Vector var1) {
      this.setContents(var1, true);
   }

   private void setContents(Vector var1, boolean var2) {
      this.items.removeAllElements();
      int var3 = var1.size();

      for (int var4 = 0; var4 < var3; var4++) {
         this.addIcon((Iconic)var1.elementAt(var4), false);
      }

      if (var2) {
         this.recalc(this.size().width, this.size().height);
         this.repaint();
      }
   }

   private void addIcon(Iconic var1, boolean var2) {
      String var3 = var1.getIconCaption();
      int var4 = var3 != null ? this.metrics.stringWidth(var3) : 0;
      URL var5 = var1.getIconURL();
      Image var6 = null;
      if (var5 != null) {
         MediaTracker var7 = new MediaTracker(this);
         var6 = Toolkit.getDefaultToolkit().getImage(var5.unalias());
         var7.addImage(var6, 0);

         try {
            var7.waitForID(0);
         } catch (InterruptedException var9) {
         }

         if (var7.isErrorID(0)) {
            var6 = null;
            System.out.println("Error loading " + var5);
         }
      }

      this.items.addElement(new ScrollingListElement(var6, var3, var4));
   }

   private void findCellSize() {
      this.cellWidth = 30;
      this.cellHeight = 0;
      if (this.useIcons) {
         this.cellHeight = 30;
      }

      Enumeration var1 = this.items.elements();

      while (var1.hasMoreElements()) {
         ScrollingListElement var2 = (ScrollingListElement)var1.nextElement();
         this.cellWidth = Math.max(this.cellWidth, var2.titleWidth);
         if (this.useIcons && var2.image != null) {
            this.cellWidth = Math.max(this.cellWidth, var2.image.getWidth(this));
            this.cellHeight = Math.max(this.cellHeight, var2.image.getHeight(this));
         }
      }

      this.cellWidth += 2;
      this.cellHeight = this.cellHeight + this.textHeight + 2;
   }

   public void reshape(int var1, int var2, int var3, int var4) {
      super.reshape(var1, var2, var3, var4);
      this.recalc(var3, var4);
      this.repaint();
   }

   private void recalc(int var1, int var2) {
      this.findCellSize();
      this.scrollPos = 0;
      this.scrollbar.setValue(this.scrollPos);
      int var3 = 0;

      while (var3 < 2) {
         int var4 = 0;
         if (var3 == 1) {
            var4 = this.scrollbar.size().width;
         }

         int var5 = 0;
         if (this.cellWidth != 0) {
            int var6 = Math.max(1, (var1 - var4) / this.cellWidth);
            var5 = (this.items.size() + var6 - 1) / var6 * this.cellHeight;
         }

         if (var5 > var2) {
            if (var3 == 0) {
               if (!this.scrollbar.isVisible()) {
                  this.scrollbar.show();
                  this.validate();
               }

               var3++;
               continue;
            }

            this.maxScrollPos = var5;
            this.scrollbar.setValues(this.scrollPos, var2, 0, var5);
            this.scrollbar.setPageIncrement(var2);
            this.scrollbar.setLineIncrement(this.cellHeight);
            break;
         }

         if (this.scrollbar.isVisible()) {
            this.scrollbar.hide();
            this.validate();
         }
         break;
      }

      this.clearHitTest();
   }

   private void clearHitTest() {
      int var1 = this.items.size();

      for (int var2 = 0; var2 < var1; var2++) {
         ScrollingListElement var3 = (ScrollingListElement)this.items.elementAt(var2);
         var3.x = var3.y = -1;
      }
   }

   private ScrollingListElement findCell(int var1, int var2) {
      int var3 = this.items.size();

      for (int var4 = 0; var4 < var3; var4++) {
         ScrollingListElement var5 = (ScrollingListElement)this.items.elementAt(var4);
         if (var1 >= 0 && var2 >= 0 && var1 < var5.x && var2 < var5.y) {
            return var5;
         }
      }

      return null;
   }

   private void buttonAction(boolean var1) {
      if (this.isDownClicked != var1) {
         this.isDownClicked = var1;
         Graphics var2 = this.getGraphics();
         this.drawCell(var2, this.downClicked, this.isDownClicked);
         var2.dispose();
      }
   }

   private Component findComponent(Point var1) {
      Point var2 = this.getLocationOnScreen();
      Container var3 = null;

      for (Container var4 = this.getParent(); !(var4 instanceof Frame); var4 = var3.getParent()) {
         var3 = var4;
      }

      Point var8 = var3.getLocationOnScreen();
      var1.x = var1.x + var2.x - var8.x;
      var1.y = var1.y + var2.y - var8.y;
      Component var5 = var3;

      while (true) {
         Component var6 = var5.locate(var1.x, var1.y);
         if (var6 == var5 || var6 == null) {
            return var5;
         }

         Point var7 = var6.location();
         var1.x = var1.x - var7.x;
         var1.y = var1.y - var7.y;
         var5 = var6;
      }
   }

   public boolean mouseUp(java.awt.Event var1, int var2, int var3) {
      if (this.downClicked != null) {
         Point var4 = new Point(var2, var3);
         this.buttonAction(false);
         this.handler.clickEvent(this.findComponent(var4), var4, 2);
         this.downClicked = null;
         return true;
      } else {
         return false;
      }
   }

   public int itemAt(Point var1) {
      ScrollingListElement var2 = this.findCell(var1.x, var1.y);
      return var2 != null ? this.items.indexOf(var2) : -1;
   }

   public boolean mouseDown(java.awt.Event var1, int var2, int var3) {
      if (this.downClicked == null && (this.downClicked = this.findCell(var2, var3)) != null) {
         this.buttonAction(true);
         byte var4 = 1;
         if (var1.metaDown()) {
            var4 |= 4;
         }

         this.handler.clickEvent(this, new Point(var2, var3), var4);
         return true;
      } else {
         return false;
      }
   }

   public boolean mouseDrag(java.awt.Event var1, int var2, int var3) {
      if (this.downClicked != null) {
         Point var4 = new Point(var2, var3);
         this.handler.clickEvent(this.findComponent(var4), var4, 8);
         return true;
      } else {
         return false;
      }
   }

   private void drawCell(Graphics var1, ScrollingListElement var2, boolean var3) {
      int var4 = var2.x - this.cellWidth;
      int var5 = var2.y - this.cellHeight;
      int var6 = this.cellHeight - this.textHeight;
      int var7 = var6 + this.ascent;
      Color var8 = var1.getColor();
      var1.setColor(this.getBackground());
      var1.draw3DRect(var4, var5, this.cellWidth - 1, this.cellHeight - 1, !var3);
      var1.setColor(var8);
      if (this.useIcons && var2.image != null) {
         int var9 = var2.image.getWidth(this);
         int var10 = var2.image.getHeight(this);
         var1.drawImage(var2.image, var4 + (this.cellWidth - var9) / 2, var5 + (var6 - var10) / 2, null);
      }

      if (var2.title != null) {
         var1.drawString(var2.title, var4 + (this.cellWidth - var2.titleWidth) / 2, var5 + var7);
      }
   }

   public void paint(Graphics var1) {
      Color var2 = var1.getColor();
      super.paint(var1);
      var1.setColor(var2);
      this.clearHitTest();
      int var3 = this.size().width;
      int var4 = this.size().height;
      int var5 = 0;
      int var6 = -this.scrollbar.getValue();
      int var7 = this.items.size();

      for (int var8 = 0; var8 < var7; var8++) {
         if (var6 + this.cellHeight > 0) {
            ScrollingListElement var9 = (ScrollingListElement)this.items.elementAt(var8);
            var9.x = var5 + this.cellWidth;
            var9.y = var6 + this.cellHeight;
            this.drawCell(var1, var9, false);
         }

         var5 += this.cellWidth;
         if (var5 + this.cellWidth > var3) {
            var5 = 0;
            if ((var6 += this.cellHeight) >= var4) {
               break;
            }
         }
      }
   }

   public boolean isIconsVisible() {
      return this.useIcons;
   }

   public void setIconsVisible(boolean var1) {
      this.useIcons = var1;
      this.recalc(this.size().width, this.size().height);
      this.repaint();
   }

   private boolean setScrollValue(int var1) {
      this.scrollPos = Math.max(this.scrollbar.getMinimum(), var1);
      this.scrollPos = Math.min(this.maxScrollPos, this.scrollPos);
      this.scrollbar.setValue(this.scrollPos);
      this.repaint();
      return true;
   }

   private boolean scrollLineUp() {
      return this.setScrollValue(this.scrollPos - this.scrollbar.getLineIncrement());
   }

   private boolean scrollLineDown() {
      return this.setScrollValue(this.scrollPos + this.scrollbar.getLineIncrement());
   }

   private boolean scrollPageUp() {
      return this.setScrollValue(this.scrollPos - this.scrollbar.getPageIncrement());
   }

   private boolean scrollPageDown() {
      return this.setScrollValue(this.scrollPos + this.scrollbar.getPageIncrement());
   }

   private boolean scrollAbsolute() {
      return this.setScrollValue(this.scrollbar.getValue());
   }
}
