package NET.worlds.console;

import NET.worlds.scape.FrameEvent;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Graphics;
import java.awt.PopupMenu;
import java.awt.Rectangle;
import java.awt.event.MouseEvent;

public class ImageButtons extends ImageCanvas implements FramePart, DialogDisabled {
   protected static final int BLANK = 0;
   protected static final int NORMAL = 1;
   protected static final int CURSED = 2;
   protected static final int DOWN = 3;
   private static final int TITLE = 0;
   private static final int BUTTON = 1;
   private int width;
   private int height;
   private Dimension ghostImageDimension;
   protected Rectangle[] buttons;
   private int[] types;
   private boolean background = false;
   private int cursedButton = -1;
   private int clickedButton = -1;
   private boolean clickedButtonDown;
   private ImageButtonsCallback handler;
   private ImageButtonsCallback downUpHandler;
   private PopupMenu menu;
   private boolean isDialogDisabled;

   private void initEvents() {
      this.enableEvents(16L);
      this.enableEvents(32L);
   }

   protected ImageButtons() {
      this.buttons = new Rectangle[0];
      this.initEvents();
   }

   public ImageButtons(String var1, int var2, int var3, ImageButtonsCallback var4) {
      this(var1, var2, intToInts(var3), var4);
   }

   public ImageButtons(String var1, Rectangle[] var2, ImageButtonsCallback var3) {
      super(var1);
      this.handler = var3;
      this.background = true;
      this.setHotspots(var2);
      this.initEvents();
   }

   public ImageButtons(String var1, int var2, int[] var3, ImageButtonsCallback var4) {
      super(var1);
      this.handler = var4;
      this.buttons = new Rectangle[var3.length];
      this.types = new int[var3.length];
      int var5 = 0;

      for (int var6 = 0; var6 < var3.length; var6++) {
         int var7 = var3[var6];
         int var8;
         if (var7 > 0) {
            var8 = var7;
            this.types[var6] = 1;
         } else {
            var8 = -var7;
            this.types[var6] = 0;
         }

         this.buttons[var6] = new Rectangle(0, var5, var2, var8);
         var5 += var8;
      }

      this.ghostImageDimension = new Dimension(var2 * 4, var3[0]);
      this.initEvents();
   }

   public void setHandler(ImageButtonsCallback var1) {
      this.handler = var1;
   }

   public void setDownUpHandler(ImageButtonsCallback var1) {
      this.downUpHandler = var1;
   }

   protected void setBackground(boolean var1) {
      this.background = var1;
   }

   protected void setWidth(int var1) {
      this.width = var1;
   }

   protected void setHeight(int var1) {
      this.height = var1;
   }

   protected synchronized void setHotspots(Rectangle[] var1) {
      this.buttons = new Rectangle[var1.length];
      this.types = new int[var1.length];

      for (int var2 = 0; var2 < var1.length; var2++) {
         this.types[var2] = 1;
         this.buttons[var2] = new Rectangle(var1[var2]);
      }

      this.cursedButton = -1;
      this.clickedButton = -1;
      this.clickedButtonDown = false;
   }

   public synchronized void paint(Graphics var1) {
      var1.clipRect(0, 0, this.width, this.height);
      if (this.background && this.image_ != null) {
         var1.drawImage(this.image_, -1 * this.width, 0, null);
      }

      for (int var2 = 0; var2 < this.buttons.length; var2++) {
         byte var3 = 1;
         if (var2 == this.cursedButton) {
            var3 = 2;
         }

         if (var2 == this.clickedButton) {
            var3 = (byte)(this.clickedButtonDown ? 3 : 1);
         }

         this.drawButton(var1, var2, var3);
      }
   }

   public Dimension preferredSize() {
      Dimension var1 = super.preferredSize();
      if (var1.width == 0 && var1.height == 0 && this.ghostImageDimension != null) {
         var1 = this.ghostImageDimension;
      }

      return new Dimension(this.width = var1.width / 4, this.height = var1.height);
   }

   public Dimension minimumSize() {
      return this.preferredSize();
   }

   public void processMouseMotionEvent(MouseEvent var1) {
      if (!this.isDialogDisabled) {
         switch (var1.getID()) {
            case 503:
            case 506:
               this.buttonAction(var1.getX(), var1.getY(), var1.getID());
         }
      }

      super.processMouseEvent(var1);
   }

   public void processMouseEvent(MouseEvent var1) {
      if (!this.isDialogDisabled) {
         switch (var1.getID()) {
            case 501:
            case 502:
            case 504:
            case 505:
               this.buttonAction(var1.getX(), var1.getY(), var1.getID());
            case 503:
         }
      }

      super.processMouseEvent(var1);
   }

   public boolean mouseMove(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 503);
   }

   public boolean mouseDown(Event var1, int var2, int var3) {
      return (var1.modifiers & 12) != 0 ? false : this.buttonAction(var2, var3, 501);
   }

   public boolean mouseUp(Event var1, int var2, int var3) {
      return (var1.modifiers & 12) != 0 ? false : this.buttonAction(var2, var3, 502);
   }

   public boolean mouseDrag(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 506);
   }

   public boolean mouseEnter(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 504);
   }

   public boolean mouseExit(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 505);
   }

   public boolean handleEvent(Event var1) {
      return this.isDialogDisabled ? false : super.handleEvent(var1);
   }

   protected Graphics drawButton(Graphics var1, int var2, int var3) {
      if (var2 != -1) {
         Rectangle var4 = this.buttons[var2];
         if (this.image_ != null && (var1 != null || (var1 = this.getGraphics()) != null)) {
            Graphics var5 = var1.create(var4.x, var4.y, var4.width, var4.height);
            var5.drawImage(this.image_, -var3 * this.width - var4.x, -var4.y, null);
            var5.dispose();
         }
      }

      return var1;
   }

   private synchronized boolean buttonAction(int var1, int var2, int var3) {
      return this.buttonAction(this.locateButton(var1, var2), var3);
   }

   private int locateButton(int var1, int var2) {
      for (int var3 = 0; var3 < this.buttons.length; var3++) {
         if (this.types[var3] == 1 && this.buttons[var3].inside(var1, var2)) {
            return var3;
         }
      }

      return -1;
   }

   public void drawFirstButton(int var1) {
      if (this.buttons.length > 0) {
         Graphics var2 = this.drawButton(null, 0, var1);
         if (var2 != null) {
            var2.dispose();
         }
      }
   }

   public void drawNormal() {
      this.drawFirstButton(1);
   }

   public void drawCursed() {
      this.drawFirstButton(2);
   }

   public void drawDown() {
      this.drawFirstButton(3);
   }

   boolean buttonAction(int var1, int var2) {
      Graphics var3 = null;
      if (var2 != 503 && var2 != 504) {
         if (var2 == 505) {
            if (this.cursedButton != -1) {
               var3 = this.drawButton(var3, this.cursedButton, 1);
               this.cursedButton = -1;
            }

            if (this.downUpHandler == null && this.clickedButton != -1 && this.clickedButtonDown) {
               var3 = this.drawButton(var3, this.clickedButton, 1);
               this.clickedButtonDown = false;
            }
         } else if (var2 == 501) {
            if (this.clickedButton != -1) {
               var3 = this.drawButton(var3, this.clickedButton, 1);
               if (this.downUpHandler != null) {
                  this.downUpHandler.imageButtonsCallback(this, -1);
               }

               this.clickedButtonDown = false;
            }

            if (this.cursedButton != -1) {
               var3 = this.drawButton(var3, this.cursedButton, 1);
               this.cursedButton = -1;
            }

            if ((this.clickedButton = var1) != -1) {
               var3 = this.drawButton(var3, this.clickedButton, 3);
               this.clickedButtonDown = true;
               if (this.downUpHandler != null) {
                  this.downUpHandler.imageButtonsCallback(this, var1);
               }
            }
         } else if (var2 == 506) {
            if (this.downUpHandler == null && this.clickedButton != -1) {
               if (this.clickedButtonDown) {
                  if (var1 != this.clickedButton) {
                     var3 = this.drawButton(var3, this.clickedButton, 1);
                     this.clickedButtonDown = false;
                  }
               } else if (var1 == this.clickedButton) {
                  var3 = this.drawButton(var3, this.clickedButton, 3);
                  this.clickedButtonDown = true;
               }
            }
         } else if (var2 == 502) {
            this.cursedButton = var1;
            if (this.cursedButton != -1) {
               var3 = this.drawButton(var3, this.cursedButton, 2);
            }

            if (this.clickedButtonDown) {
               if (this.cursedButton != this.clickedButton) {
                  var3 = this.drawButton(var3, this.clickedButton, 1);
               }

               Object var4 = this.handler.imageButtonsCallback(this, this.clickedButton);
               if (var4 instanceof PopupMenu && this.clickedButton != -1) {
                  if (this.menu != null) {
                     this.remove(this.menu);
                  }

                  this.add(this.menu = (PopupMenu)var4);
                  this.menu.show(this, this.buttons[this.clickedButton].x, this.buttons[this.clickedButton].y + this.buttons[this.clickedButton].height);
               }

               if (this.downUpHandler != null && this.downUpHandler.imageButtonsCallback(this, -1) != null) {
                  this.cursedButton = -1;
               }

               this.clickedButtonDown = false;
               this.clickedButton = -1;
            }
         }
      } else {
         if (var1 != this.cursedButton) {
            var3 = this.drawButton(var3, this.cursedButton, 1);
            var3 = this.drawButton(var3, this.cursedButton = var1, 2);
         }

         if (this.clickedButton != -1 && this.clickedButton != var1 && this.downUpHandler == null) {
            var3 = this.drawButton(var3, this.clickedButton, 1);
            this.clickedButtonDown = false;
         }
      }

      if (var3 != null) {
         var3.dispose();
      }

      return true;
   }

   public static int[] intToInts(int var0) {
      return new int[]{var0};
   }

   public void activate(Console var1, Container var2, Console var3) {
   }

   public void deactivate() {
   }

   public boolean action(Event var1, Object var2) {
      return false;
   }

   public boolean handle(FrameEvent var1) {
      return false;
   }

   public void dialogDisable(boolean var1) {
      if (this.isDialogDisabled = var1) {
         this.cursedButton = -1;
         this.clickedButton = -1;
         this.clickedButtonDown = false;
         this.repaint();
      }
   }
}
