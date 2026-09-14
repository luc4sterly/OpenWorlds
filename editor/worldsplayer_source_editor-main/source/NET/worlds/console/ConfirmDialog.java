package NET.worlds.console;

import java.awt.GridBagConstraints;
import java.awt.Label;

public class ConfirmDialog extends OkCancelDialog {
   private String prompt;

   public ConfirmDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4) {
      super(var1, var2, var3, Console.message("No"), Console.message("Yes"));
      this.prompt = var4;
      this.ready();
   }

   public ConfirmDialog(java.awt.Window var1, String var2, String var3) {
      this(var1, (DialogReceiver)var1, var2, var3);
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      var1.weightx = 1.0;
      var1.weighty = 1.0;
      var1.gridwidth = 0;
      this.add(this.gbag, new Label(this.prompt), var1);
      super.build();
   }

   protected boolean setValue() {
      return true;
   }

   public void show() {
      super.show();
      this.okButton.requestFocus();
   }
}
