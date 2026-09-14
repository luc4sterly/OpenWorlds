package NET.worlds.console;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Graphics;
import java.awt.Panel;
import java.awt.Rectangle;

public class FourTilePanel extends Panel {
   private static final int tw = 5;
   private static final int th = 5;
   private static final int aw = 7;
   private static final int ah = 4;
   private static final int bw = 3;
   private static Color widgetColor = new Color(255, 238, 177);
   private static Color lineColor = new Color(162, 162, 162);
   private boolean init;
   private Component[] comps = new Component[4];
   private int[] order = new int[]{0, 1, 2, 3};
   private float[] divider = new float[]{0.22F, 0.63F};
   private int tx;
   private int ty;
   private int prevWidth;
   private int prevHeight;
   private Rectangle moveWidget = new Rectangle();
   private FourTileSwapper swap01 = new FourTileSwapper(this, 0, 1);
   private FourTileSwapper swap02 = new FourTileSwapper(this, 0, 2);
   private FourTileSwapper swap23 = new FourTileSwapper(this, 2, 3);
   private FourTileSwapper swap13 = new FourTileSwapper(this, 1, 3);
   private FourTileSwapper[] swaps = new FourTileSwapper[]{this.swap01, this.swap02, this.swap23, this.swap13};
   private boolean dragging;
   private int offsetx;
   private int offsety;
   private int minx;
   private int miny;
   private int maxx;
   private int maxy;
   private int specialTileIndex;
   private Component oneTile;

   public FourTilePanel(Component var1, Component var2, Component var3, Component var4, int var5) {
      this.setLayout(null);
      this.specialTileIndex = var5;
      this.add(this.comps[0] = var1);
      this.add(this.comps[1] = var2);
      this.add(this.comps[2] = var3);
      this.add(this.comps[3] = var4);
      this.setBackground(Color.black);
      if (GammaFrameState.restoreLayout(this.order, this.divider)) {
         this.useOneTileMode();
      } else {
         this.useFourTileMode();
      }
   }

   public boolean isOneTileMode() {
      return this.oneTile != null;
   }

   public void useOneTileMode() {
      if (this.oneTile == null) {
         this.oneTile = this.comps[this.specialTileIndex];

         for (int var1 = 0; var1 < 4; var1++) {
            if (var1 != this.specialTileIndex) {
               this.remove(this.comps[var1]);
            }
         }

         this.moveComponents();
         this.saveLayout();
         this.validate();
      }
   }

   public void useFourTileMode() {
      if (this.oneTile != null) {
         this.oneTile = null;

         for (int var1 = 0; var1 < 4; var1++) {
            if (var1 != this.specialTileIndex) {
               this.add(this.comps[var1]);
            }
         }

         this.moveComponents();
         this.saveLayout();
         this.validate();
      }
   }

   public void reshape(int var1, int var2, int var3, int var4) {
      super.reshape(var1, var2, var3, var4);
      if (!GammaFrameState.isIconic()) {
         if (this.prevWidth != var3) {
            this.tx = Math.max((int)(this.divider[0] * var3), 12);
            this.prevWidth = var3;
         }

         if (this.prevHeight != var4) {
            this.ty = Math.max((int)(this.divider[1] * var4), 9);
            this.prevHeight = var4;
         }

         this.moveComponents(var3, var4);
      }
   }

   private void saveLayout() {
      GammaFrameState.saveLayout(this.order, this.divider, this.oneTile != null);
   }

   private void moveComponents() {
      Dimension var1 = this.size();
      this.moveComponents(var1.width, var1.height);
   }

   private void moveComponents(int var1, int var2) {
      if (this.oneTile == null) {
         this.comps[this.order[0]].reshape(3, 3, this.tx - 3, this.ty - 3);
         this.comps[this.order[1]].reshape(this.tx + 5, 3, var1 - this.tx - 5 - 3, this.ty - 3);
         this.comps[this.order[2]].reshape(3, this.ty + 5, this.tx - 3, var2 - this.ty - 5 - 3);
         this.comps[this.order[3]].reshape(this.tx + 5, this.ty + 5, var1 - this.tx - 5 - 3, var2 - this.ty - 5 - 3);
      } else {
         this.oneTile.reshape(0, 0, var1, var2);
      }

      this.repaint();
   }

   public void paint(Graphics var1) {
      Dimension var2 = this.size();
      var1.setColor(this.getBackground());
      if (this.oneTile == null) {
         var1.fillRect(0, 0, 3, var2.height);
         var1.fillRect(0, 0, var2.width, 3);
         var1.fillRect(0, var2.height - 3, var2.width, 3);
         var1.fillRect(var2.width - 3, 0, 3, var2.height);
         var1.fillRect(0, this.ty, var2.width, 5);
         var1.fillRect(this.tx, 0, 5, var2.height);
         var1.setColor(lineColor);
         var1.drawLine(0, this.ty + 2, var2.width, this.ty + 2);
         var1.drawLine(this.tx + 2, 0, this.tx + 2, var2.height);
         var1.setColor(widgetColor);
         var1.fillRect(this.tx, this.ty, 5, 5);
         this.moveWidget.reshape(this.tx, this.ty, 5, 5);
         int var3 = (this.tx + 2 - 7) / 2;
         var1.fillArc(var3, this.ty - 2, 7, 4, 0, -180);
         var1.fillArc(var3, this.ty + 5 - 2, 7, 4, 0, 180);
         this.swap02.reshape(var3, this.ty, 7, 5);
         var3 = (this.tx + 2 + var2.width - 7) / 2;
         var1.fillArc(var3, this.ty - 2, 7, 4, 0, -180);
         var1.fillArc(var3, this.ty + 5 - 2, 7, 4, 0, 180);
         this.swap13.reshape(var3, this.ty, 7, 5);
         var3 = (this.ty + 2 - 7) / 2;
         var1.fillArc(this.tx - 2, var3, 4, 7, 90, -180);
         var1.fillArc(this.tx + 5 - 2, var3, 4, 7, 90, 180);
         this.swap01.reshape(this.tx, var3, 5, 7);
         var3 = (this.ty + 2 + var2.height - 7) / 2;
         var1.fillArc(this.tx - 2, var3, 4, 7, 90, -180);
         var1.fillArc(this.tx + 5 - 2, var3, 4, 7, 90, 180);
         this.swap23.reshape(this.tx, var3, 5, 7);
      }
   }

   public boolean mouseDrag(Event var1, int var2, int var3) {
      if (this.dragging) {
         this.tx = var2 + this.offsetx;
         this.ty = var3 + this.offsety;
         this.divider[0] = (float)this.tx / this.size().width;
         this.divider[1] = (float)this.ty / this.size().height;
         this.tx = Math.max(this.tx, this.minx);
         this.ty = Math.max(this.ty, this.miny);
         this.tx = Math.min(this.tx, this.maxx);
         this.ty = Math.min(this.ty, this.maxy);
         this.moveComponents();
      }

      return true;
   }

   public boolean mouseUp(Event var1, int var2, int var3) {
      if (this.dragging) {
         this.validate();
         this.saveLayout();
      }

      this.dragging = false;
      return true;
   }

   public boolean mouseDown(Event var1, int var2, int var3) {
      for (int var5 = 0; var5 < this.swaps.length; var5++) {
         if (this.swaps[var5].maybeSwap(var2, var3)) {
            return true;
         }
      }

      if (this.moveWidget.inside(var2, var3)) {
         this.offsetx = this.tx - var2;
         this.offsety = this.ty - var3;
         this.minx = 12;
         this.maxx = this.size().width - this.minx;
         this.miny = 12;
         this.maxy = this.size().height - this.miny;
         if (this.minx < this.maxx && this.miny < this.maxy) {
            this.dragging = true;
         }
      }

      return true;
   }

   void swap(int var1, int var2) {
      int var3 = this.order[var1];
      this.order[var1] = this.order[var2];
      this.order[var2] = var3;
      this.moveComponents();
      this.validate();
      this.saveLayout();
   }
}
