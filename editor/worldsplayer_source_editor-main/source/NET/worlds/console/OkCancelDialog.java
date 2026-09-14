package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;

public class OkCancelDialog extends PolledDialog {
   protected Button okButton = new Button(Console.message("OK"));
   protected Button cancelButton = new Button(Console.message("Cancel"));
   protected GridBagLayout gbag = new GridBagLayout();
   private String prompt;
   protected int cancelKey = 27;
   protected int confirmKey = 10;
   protected static Font font = new Font(Console.message("GammaTextFont"), 0, 12);
   protected static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);

   protected OkCancelDialog(java.awt.Window var1, String var2) {
      this(var1, (DialogReceiver)var1, var2);
   }

   protected OkCancelDialog(java.awt.Window var1, String var2, String var3, String var4) {
      this(var1, (DialogReceiver)var1, var2, var3, var4);
   }

   protected OkCancelDialog(java.awt.Window var1, DialogReceiver var2, String var3) {
      this(var1, var2, var3, true);
   }

   protected OkCancelDialog(java.awt.Window var1, DialogReceiver var2, String var3, boolean var4) {
      super(var1, var2, var3, var4);
      this.setLayout(this.gbag);
   }

   protected OkCancelDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5) {
      this(var1, var2, var3, var4, var5, true);
   }

   protected OkCancelDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, boolean var6) {
      this(var1, var2, var3, var6);
      if (var5 != null) {
         this.okButton.setFont(bfont);
         this.okButton.setLabel(var5);
      } else {
         this.okButton = null;
      }

      if (var4 != null) {
         this.cancelButton.setFont(bfont);
         this.cancelButton.setLabel(var4);
      } else {
         this.cancelButton = null;
      }
   }

   public OkCancelDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, String var6) {
      this(var1, var2, var3, var4, var5, var6, true);
   }

   public OkCancelDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, String var6, boolean var7) {
      this(var1, var2, var3, var4, var5, var7);
      this.prompt = var6;
      this.ready();
   }

   public OkCancelDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, String var6, boolean var7, int var8) {
      this(var1, var2, var3, var4, var5, var7);
      this.prompt = var6;
      this.setAlignment(var8);
      this.ready();
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      if (this.prompt != null) {
         var1.weightx = 1.0;
         var1.weighty = 1.0;
         var1.gridwidth = 0;
         MultiLineLabel var2 = new MultiLineLabel(this.prompt, 5, 5);
         var2.setFont(font);
         this.add(this.gbag, var2, var1);
      }

      int var3 = 0;
      if (this.okButton != null) {
         var3++;
      }

      if (this.cancelButton != null) {
         var3++;
      }

      var1.gridwidth = var3;
      var1.weightx = 1.0;
      var1.weighty = 0.0;
      if (this.okButton != null) {
         this.okButton.setFont(bfont);
         this.add(this.gbag, this.okButton, var1);
      }

      if (this.cancelButton != null) {
         this.cancelButton.setFont(bfont);
         this.add(this.gbag, this.cancelButton, var1);
      }
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton && this.setValue()) {
         return this.done(true);
      } else {
         return var3 == this.cancelButton ? this.done(false) : false;
      }
   }

   protected boolean setValue() {
      return true;
   }

   public void setCancelKey(int var1) {
      this.cancelKey = var1;
   }

   public void setConfirmKey(int var1) {
      this.confirmKey = var1;
   }

   public boolean keyDown(Event var1, int var2) {
      if (var2 == this.cancelKey) {
         return this.done(false);
      }

      if (var2 == this.confirmKey) {
         if (this.okButton == null) {
            return this.done(false);
         }

         if (this.setValue()) {
            return this.done(true);
         }
      }

      return super.keyDown(var1, var2);
   }
}
