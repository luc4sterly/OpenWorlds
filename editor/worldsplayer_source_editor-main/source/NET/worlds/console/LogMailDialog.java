package NET.worlds.console;

import java.awt.GridBagConstraints;
import java.awt.TextArea;

class LogMailDialog extends OkCancelDialog {
   private TextArea commentArea;
   private String tagString;

   public LogMailDialog(DialogReceiver var1, String var2) {
      super(Console.getFrame(), var1, Console.message("Log-Mailer"), Console.message("Dont-Report"), Console.message("Report"), null, false);
      this.tagString = var2;
      this.commentArea = new TextArea("", 5, 60, 1);
      this.commentArea.setEditable(true);
      this.setConfirmKey(-1);
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      if (this.tagString != null) {
         var1.weightx = 1.0;
         var1.weighty = 1.0;
         var1.gridwidth = 0;
         this.add(this.gbag, new MultiLineLabel(this.tagString, 5, 5), var1);
      }

      var1.weightx = 1.0;
      var1.weighty = 1.0;
      var1.gridwidth = 0;
      this.add(this.gbag, this.commentArea, var1);
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
         this.add(this.gbag, this.okButton, var1);
      }

      if (this.cancelButton != null) {
         this.add(this.gbag, this.cancelButton, var1);
      }
   }

   public String getComment() {
      return this.commentArea.getText();
   }
}
