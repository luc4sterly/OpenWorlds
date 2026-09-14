package NET.worlds.console;

import java.awt.Component;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.TextArea;
import java.awt.TextField;
import java.util.StringTokenizer;

class MailDialog extends OkCancelDialog {
   private TextField recipientField;
   private TextField subjectField;
   private TextArea bodyTextArea;
   private String tagString;
   private static Font font = new Font(Console.message("ConsoleFont"), 0, 12);

   public MailDialog(Console var1) {
      super(Console.getFrame(), new MailDialogReceiver(var1), Console.message("Mail"), Console.message("Dont-Send"), Console.message("Send"), null, false);
      this.setConfirmKey(0);
      this.recipientField = new TextField();
      this.recipientField.setFont(font);
      this.subjectField = new TextField();
      this.subjectField.setFont(font);
      this.bodyTextArea = new TextArea("", 5, 50, 1);
      this.bodyTextArea.setEditable(true);
      this.bodyTextArea.setFont(font);
      this.setAlignment(1);
   }

   public MailDialog(Console var1, String var2) {
      this(var1);
      this.recipientField.setText(Console.parseExtended(var2));
      this.recipientField.setFont(font);
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      int var2 = 0;
      var1.fill = 0;
      var1.anchor = 13;
      this.add(this.gbag, new Label(Console.message("To")), var1, 0, var2, 1, 1, 0, 0);
      var1.fill = 2;
      var1.anchor = 17;
      this.add(this.gbag, this.recipientField, var1, 1, var2, 3, 1, 100, 0);
      var2++;
      var1.fill = 0;
      var1.anchor = 13;
      Label var3 = new Label(Console.message("Subject"));
      var3.setFont(font);
      this.add(this.gbag, var3, var1, 0, var2, 1, 1, 0, 0);
      var1.fill = 2;
      var1.anchor = 17;
      this.add(this.gbag, this.subjectField, var1, 1, var2, 3, 1, 100, 0);
      var2++;
      var1.anchor = 10;
      var1.fill = 1;
      this.add(this.gbag, this.bodyTextArea, var1, 0, var2, 4, 1, 100, 100);
      var2++;
      var1.fill = 0;
      if (this.okButton != null) {
         this.okButton.setFont(font);
         this.add(this.gbag, this.okButton, var1, 1, var2, 1, 1, 100, 0);
      }

      if (this.cancelButton != null) {
         this.cancelButton.setFont(font);
         this.add(this.gbag, this.cancelButton, var1, 2, var2, 1, 1, 100, 0);
      }
   }

   private void add(GridBagLayout var1, Component var2, GridBagConstraints var3, int var4, int var5, int var6, int var7, int var8, int var9) {
      var3.gridx = var4;
      var3.gridy = var5;
      var3.gridwidth = var6;
      var3.gridheight = var7;
      var3.weightx = var8;
      var3.weighty = var9;
      this.add(var1, var2, var3);
   }

   public String[] getTo() {
      Console var1 = Console.getActive();
      String var2 = this.recipientField.getText();
      StringTokenizer var3 = new StringTokenizer(var2, ",");
      String[] var4 = new String[var3.countTokens()];

      for (int var5 = 0; var3.hasMoreTokens(); var5++) {
         var4[var5] = var3.nextToken().trim();
         if (var4[var5].indexOf("@") == -1 && var1 != null) {
            var4[var5] = var4[var5] + "@" + var1.getMailDomain();
         }
      }

      return var4;
   }

   public String getSubject() {
      return this.subjectField.getText();
   }

   public String getBody() {
      return this.bodyTextArea.getText();
   }
}
