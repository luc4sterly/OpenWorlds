package NET.worlds.console;

import java.awt.Component;
import java.awt.Container;
import java.awt.Dialog;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Point;
import java.awt.Toolkit;

public abstract class PolledDialog extends Dialog implements MainCallback, DialogDisabled {
   public static final int CENTER = 0;
   public static final int BOTTOM = 1;
   public static final int RIGHT = 2;
   public static final int LEFT = 3;
   private boolean active;
   private boolean built;
   private boolean restarting;
   private boolean confirmed;
   private boolean killed;
   private boolean disableParent;
   private boolean toBeDisposed;
   private java.awt.Window parent;
   private DialogReceiver receiver;
   private int alignment = 0;
   private Point initialOffset = new Point(0, 0);
   private Object startupWaiter;
   private boolean started;

   protected PolledDialog(java.awt.Window var1, DialogReceiver var2, String var3, boolean var4) {
      super(findFrame(var1), var3, false);
      this.parent = var1;
      this.receiver = var2;
      if (var4) {
         this.disableParent();
      }
   }

   protected void disableParent() {
      this.disableParent = this.parent instanceof DialogDisabled;
      if (this.disableParent) {
         ((DialogDisabled)this.parent).dialogDisable(true);
      }
   }

   protected void ready() {
      this.killed = false;
      if (this.built && !this.active) {
         this.restarting = true;
      }

      Main.register(this);
      this.setResizable(true);
   }

   protected void readySetGo() {
      this.startupWaiter = new Object();
      this.started = false;
      synchronized (this.startupWaiter) {
         this.ready();

         while (!this.started) {
            try {
               this.startupWaiter.wait();
            } catch (InterruptedException var4) {
            }
         }
      }

      this.startupWaiter = null;
      this.started = false;
   }

   protected void setAlignment(int var1) {
      this.setAlignment(var1, 0, 0);
   }

   protected void setAlignment(int var1, int var2, int var3) {
      this.alignment = var1;
      this.initialOffset.x = var2;
      this.initialOffset.y = var3;
   }

   private static Frame findFrame(Container var0) {
      while (!(var0 instanceof Frame) && var0 != null) {
         var0 = var0.getParent();
      }

      return (Frame)var0;
   }

   protected abstract void build();

   public final synchronized void mainCallback() {
      if (!this.killed) {
         if (!this.built) {
            this.build();
            this.pack();
            this.restoreFrame();
            this.position();
            this.show();
            this.built = true;
            this.active = true;
         } else if (this.restarting) {
            this.restoreFrame();
            this.show();
            this.restarting = false;
            this.active = true;
         }
      }

      if (!this.killed && this.active) {
         this.activeCallback();
      } else {
         if (this.toBeDisposed) {
            this.setVisible(false);
            this.parent.requestFocus();
            if (this.getPeer() != null) {
               this.dispose();
            }

            this.toBeDisposed = false;
         }

         Main.unregister(this);
         if (this.receiver != null) {
            this.receiver.dialogDone(this, this.confirmed);
         }
      }
   }

   protected void activeCallback() {
   }

   private void restoreFrame() {
      int var1 = Window.getFrameHandle();
      if (var1 != 0 && Window.getWindowState(var1) == 1) {
         Window.setWindowState(var1, 0);
      }
   }

   public void show() {
      super.show();
      if (this.startupWaiter != null) {
         synchronized (this.startupWaiter) {
            this.started = true;
            this.startupWaiter.notify();
         }
      }
   }

   public void closeIt(boolean var1) {
      this.done(var1);
   }

   protected synchronized boolean done(boolean var1) {
      if (!this.killed && this.disableParent) {
         ((DialogDisabled)this.parent).dialogDisable(false);
      }

      this.killed = true;
      this.toBeDisposed = true;
      if (this.active) {
         this.savePosAndSize(new PolledDialogSaver(this));
         this.active = false;
      }

      this.confirmed = var1;
      return true;
   }

   public boolean isActive() {
      return this.active;
   }

   protected void add(GridBagLayout var1, Component var2, GridBagConstraints var3) {
      if (var2 != null && var3 != null) {
         var1.setConstraints(var2, var3);
         this.add(var2);
      } else {
         System.out.println("Bad parameter passed to PolledDialog::add, how bizarre.");
      }
   }

   public boolean handleEvent(Event var1) {
      if (var1.id == 201) {
         return this.done(false);
      }

      if (var1.id == 1004 || var1.id == 401 || var1.id == 501) {
         Console.wake();
      }

      return super.handleEvent(var1);
   }

   public void dialogDisable(boolean var1) {
      this.setVisible(!var1);
   }

   public boolean getConfirmed() {
      return this.confirmed;
   }

   protected void position() {
      Dimension var1 = this.size();
      this.initialSize(var1.width, var1.height);
   }

   protected void initialSize(int var1, int var2) {
      if (!PolledDialogSaver.restorePosAndSize(this.restorePosAndSize(), this)) {
         Point var3 = this.parent.location();
         Dimension var4 = null;
         if (this.parent instanceof Frame) {
            int var5 = Window.getFrameHandle();
            if (var5 != 0) {
               var4 = new Dimension(Window.getWindowWidth(var5), Window.getWindowHeight(var5));
            }
         }

         if (var4 == null) {
            var4 = this.parent.size();
         }

         int var8;
         if (this.alignment == 2) {
            var8 = var3.x + this.initialOffset.x + var4.width;
         } else if (this.alignment == 3) {
            var8 = var3.x + this.initialOffset.x - var1;
         } else {
            var8 = var3.x + this.initialOffset.x + (var4.width - var1) / 2;
         }

         int var6;
         if (this.alignment == 1) {
            var6 = var3.y + this.initialOffset.y + var4.height - var2;
         } else {
            var6 = var3.y + this.initialOffset.y + (var4.height - var2) / 2;
         }

         Dimension var7 = Toolkit.getDefaultToolkit().getScreenSize();
         if (var6 + var2 > var7.height) {
            var6 = var7.height - var2;
         }

         if (var6 < 0) {
            var6 = 0;
         }

         if (var8 + var1 > var7.width) {
            var8 = var7.width - var1;
         }

         if (var8 < 0) {
            var8 = 0;
         }

         this.reshape(var8, var6, var1, var2);
      }
   }

   public void savePosAndSize(Object var1) {
   }

   public Object restorePosAndSize() {
      return null;
   }
}
