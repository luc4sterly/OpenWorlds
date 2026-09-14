package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.PolledDialog;
import java.io.IOException;

public abstract class DialogAction extends Action implements DialogReceiver {
   boolean showDialog = true;
   boolean cancelOnly = false;
   private static PolledDialog dialogUp = null;
   private PolledDialog thisDialog;
   protected static boolean doCancel = false;
   private static Object classCookie = new Object();

   public void dialogDone(Object var1, boolean var2) {
      if (dialogUp == var1) {
         doCancel = true;
         if (var2) {
            this.doIt();
         }
      }
   }

   public abstract void doIt();

   public abstract PolledDialog getDialog();

   public Persister trigger(Event var1, Persister var2) {
      Console var3 = Console.getActive();
      if (var3 == null) {
         return null;
      }

      if (!this.showDialog && !this.cancelOnly) {
         if (var3 != null) {
            this.doIt();
         }

         return null;
      } else if (dialogUp == null) {
         if (this.cancelOnly) {
            return null;
         }

         this.thisDialog = dialogUp = this.getDialog();
         doCancel = false;
         return this;
      } else {
         if (this.thisDialog == dialogUp && var2 != null) {
            if (doCancel) {
               dialogUp.closeIt(false);
               dialogUp = null;
               this.thisDialog = null;
               return null;
            }
         } else {
            doCancel = true;
         }

         return this;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Display Dialog Box"), "Don't ask", "Ask user to ok choice");
            } else if (var3 == 1) {
               var5 = new Boolean(this.showDialog);
            } else if (var3 == 2) {
               this.showDialog = (Boolean)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Cancel only"), "Regular operation", "Cancels dialog, doesn't do action");
            } else if (var3 == 1) {
               var5 = new Boolean(this.cancelOnly);
            } else if (var3 == 2) {
               this.cancelOnly = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveBoolean(this.showDialog);
      var1.saveBoolean(this.cancelOnly);
   }

   protected void dialogActionSkipRestore(Restorer var1) throws IOException, TooNewException {
      super.restoreState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.showDialog = var1.restoreBoolean();
            this.cancelOnly = var1.restoreBoolean();
            return;
         default:
            throw new TooNewException();
      }
   }
}
