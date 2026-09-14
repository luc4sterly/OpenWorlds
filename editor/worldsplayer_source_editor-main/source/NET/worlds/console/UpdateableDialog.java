package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;

public class UpdateableDialog extends PolledDialog {
   protected Button okButton = new Button(Console.message("OK"));
   protected Button cancelButton = new Button(Console.message("Cancel"));
   protected GridBagLayout gbag = new GridBagLayout();
   private String prompt;
   private MultiLineLabel promptLabel;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);
   protected int cancelKey = 27;
   protected int confirmKey = 10;

   protected UpdateableDialog(java.awt.Window var1, String var2) {
      this(var1, (DialogReceiver)var1, var2);
   }

   protected UpdateableDialog(java.awt.Window var1, String var2, String var3, String var4) {
      this(var1, (DialogReceiver)var1, var2, var3, var4);
   }

   protected UpdateableDialog(java.awt.Window var1, DialogReceiver var2, String var3) {
      this(var1, var2, var3, true);
   }

   protected UpdateableDialog(java.awt.Window var1, DialogReceiver var2, String var3, boolean var4) {
      super(var1, var2, var3, var4);
      this.setLayout(this.gbag);
   }

   protected UpdateableDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5) {
      this(var1, var2, var3, var4, var5, true);
   }

   protected UpdateableDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, boolean var6) {
      this(var1, var2, var3, var6);
      if (var5 != null) {
         this.okButton.setLabel(var5);
      } else {
         this.okButton = null;
      }

      if (var4 != null) {
         this.cancelButton.setLabel(var4);
      } else {
         this.cancelButton = null;
      }
   }

   public UpdateableDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, String var6) {
      this(var1, var2, var3, var4, var5, var6, true);
   }

   public UpdateableDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, String var6, boolean var7) {
      this(var1, var2, var3, var4, var5, var7);
      this.setFont(font);
      this.prompt = var6;
      this.ready();
   }

   public UpdateableDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, String var6, boolean var7, int var8) {
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
         this.promptLabel = new MultiLineLabel(this.prompt, 5, 5);
         this.promptLabel.setFont(font);
         this.add(this.gbag, this.promptLabel, var1);
      }

      int var2 = 0;
      if (this.okButton != null) {
         var2++;
      }

      if (this.cancelButton != null) {
         var2++;
      }

      var1.gridwidth = var2;
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

   public void setPrompt(String var1) {
      GridBagConstraints var2 = new GridBagConstraints();
      this.prompt = var1;
      if (this.promptLabel != null) {
         this.gbag.removeLayoutComponent(this.promptLabel);
      }

      var2.weightx = 1.0;
      var2.weighty = 1.0;
      var2.gridwidth = 0;
      this.promptLabel = new MultiLineLabel(this.prompt, 5, 5);
      this.add(this.gbag, this.promptLabel, var2);
      this.show();
   }

   public void closeIt(boolean var1) {
      this.done(var1);
   }
}
