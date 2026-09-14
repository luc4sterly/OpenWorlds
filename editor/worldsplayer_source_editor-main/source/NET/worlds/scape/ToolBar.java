package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogDisabled;
import NET.worlds.console.ExposedPanel;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.Window;
import java.awt.Color;
import java.awt.FlowLayout;
import java.util.Enumeration;
import java.util.Vector;

class ToolBar extends ExposedPanel implements MainCallback, DialogDisabled {
   private Vector buttons = new Vector();
   private WidgetButton active;
   private boolean activeDown;
   private WidgetButton entered;
   private WObject curWObj;
   private boolean haveDelta = false;
   private WObjectHighlighter highlight;
   private boolean initialDrag;
   private boolean isDialogDisabled;
   private boolean testConstrained;
   private boolean constrainToX;
   private boolean constrainToY;
   private int cumx;
   private int cumy;
   private float motionDivisor = 1.0F;
   private static final int constrainThresh = 5;

   public ToolBar() {
      this.setLayout(new FlowLayout(0, 1, 1));
      this.addButton(new HTransWidget(this));
      this.addButton(new VTransWidget(this));
      this.addButton(new PitchWidget(this));
      this.addButton(new RollWidget(this));
      this.addButton(new YawWidget(this));
      this.addButton(new ScaleWidget(this));
      this.addButton(new CutWidget(this));
      this.addButton(new CopyWidget(this));
      this.addButton(new PasteWidget(this));
      this.addButton(new SaveWidget(this));
      this.addButton(new UndoWidget(this));
      this.setBackground(Color.lightGray);
   }

   public void done() {
      if (this.highlight != null) {
         this.highlight.stop();
      }
   }

   private void addButton(WidgetButton var1) {
      this.add(var1);
      this.buttons.addElement(var1);
   }

   public void setCurrentObject(Object var1) {
      this.curWObj = var1 instanceof WObject ? (WObject)var1 : null;
      if (this.highlight != null) {
         this.highlight.stop();
         this.highlight = null;
      }

      if (this.curWObj != null) {
         this.highlight = new WObjectHighlighter(this.curWObj);
      }

      Enumeration var2 = this.buttons.elements();
      this.clearPrompt();

      while (var2.hasMoreElements()) {
         ((WidgetButton)var2.nextElement()).repaint();
      }
   }

   public WObject getCurrentWObject() {
      return this.curWObj;
   }

   public void dialogDisable(boolean var1) {
      this.isDialogDisabled = var1;
   }

   public boolean handleEvent(java.awt.Event var1) {
      return this.isDialogDisabled ? false : super.handleEvent(var1);
   }

   public synchronized boolean mouseDown(java.awt.Event var1, int var2, int var3) {
      WidgetButton var4;
      if (var1.target instanceof WidgetButton && (var1.modifiers & 4) == 0 && this.active == null && (var4 = (WidgetButton)var1.target).available()) {
         this.active = var4;
         this.active.draw(true);
         if (this.active.usesDrag()) {
            this.initialDrag = true;
            this.highlight.stop();
            Window.hideCursor();
            Main.register(this);
            this.haveDelta = true;
         } else {
            this.activeDown = true;
         }
      }

      return true;
   }

   public synchronized boolean mouseDrag(java.awt.Event var1, int var2, int var3) {
      if (this.active != null) {
         if (this.active.usesDrag()) {
            if ((var1.modifiers & 1) != 0 && !this.constrainToX && !this.constrainToY) {
               this.testConstrained = true;
               this.cumx = this.cumy = 0;
            }

            this.motionDivisor = (var1.modifiers & 2) != 0 ? 10.0F : 1.0F;
            this.haveDelta = true;
         } else {
            boolean var4 = this.active.getBounds().inside(var2, var3);
            if (var4 != this.activeDown) {
               this.active.draw(this.activeDown = var4);
            }
         }
      }

      return true;
   }

   public synchronized void mainCallback() {
      if (this.haveDelta && this.active != null) {
         int[] var1 = Window.getHiddenCursorDelta();
         if (this.testConstrained) {
            this.cumx = this.cumx + var1[0];
            this.cumy = this.cumy + var1[1];
            int var2 = Math.abs(this.cumx);
            int var3 = Math.abs(this.cumy);
            if (var2 > var3 + 5) {
               this.constrainToX = true;
            } else {
               if (var3 <= var2 + 5) {
                  return;
               }

               this.constrainToY = true;
            }

            this.testConstrained = false;
         }

         if (this.constrainToX) {
            var1[0] += this.cumx;
            this.cumx = 0;
            var1[1] = 0;
         } else if (this.constrainToY) {
            var1[1] += this.cumy;
            this.cumy = 0;
            var1[0] = 0;
         }

         this.setPrompt(this.active.drag(this.initialDrag, var1[0] / this.motionDivisor, -var1[1] / this.motionDivisor));
         this.initialDrag = false;
         this.haveDelta = false;
      }
   }

   public synchronized boolean mouseUp(java.awt.Event var1, int var2, int var3) {
      if (this.active != null) {
         this.active.draw(false);
         boolean var4 = true;
         if (this.active.usesDrag()) {
            this.highlight.start();
            Main.unregister(this);
         } else if (this.activeDown) {
            this.active.perform();
            this.activeDown = false;
         } else {
            var4 = false;
         }

         this.active = null;
         if (var4) {
            Console.getFrame().getEditTile().update();
         }
      }

      return true;
   }

   public boolean mouseEnter(java.awt.Event var1, int var2, int var3) {
      WidgetButton var4;
      if (this.active == null && var1.target instanceof WidgetButton && (var4 = (WidgetButton)var1.target).available()) {
         this.entered = var4;
         this.setPrompt(this.entered.getPrompt());
      }

      return true;
   }

   public boolean mouseMove(java.awt.Event var1, int var2, int var3) {
      return this.mouseEnter(var1, var2, var3);
   }

   public synchronized boolean keyUp(java.awt.Event var1, int var2) {
      if ((var1.modifiers & 1) == 0) {
         this.testConstrained = this.constrainToX = this.constrainToY = false;
      }

      return true;
   }

   public void setPrompt(String var1) {
      Console.getFrame().getEditTile().setPrompt(var1);
   }

   private void clearPrompt() {
      this.entered = null;
      Console.getFrame().getEditTile().setPrompt(null);
   }

   public boolean mouseExit(java.awt.Event var1, int var2, int var3) {
      if (this.active == null && var1.target == this.entered) {
         this.clearPrompt();
      }

      return true;
   }
}
