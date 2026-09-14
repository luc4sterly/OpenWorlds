package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;

class AddNameDialog extends PolledDialog {
   private TextField nameField;
   private Button okButton = new Button(Console.message("OK"));
   private Button cancelButton = new Button(Console.message("Cancel"));
   private String newName;
   private static Font font = new Font(Console.message("ButtonFont"), 0, 12);

   AddNameDialog(EditNamesDialog var1, String var2) {
      super(var1, var1, var2, true);
      this.ready();
   }

   protected void build() {
      this.nameField = new TextField("", 40);
      this.nameField.setFont(font);
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      var2.fill = 0;
      var2.weightx = 1.0;
      var2.weighty = 1.0;
      var2.gridwidth = 2;
      var2.gridheight = 1;
      this.add(var1, new Label(Console.message("Name")), var2);
      var2.gridwidth = 0;
      var2.fill = 2;
      this.add(var1, this.nameField, var2);
      Panel var3 = new Panel();
      this.okButton.setFont(font);
      this.cancelButton.setFont(font);
      var3.add(this.okButton);
      var3.add(this.cancelButton);
      var2.gridwidth = 0;
      var2.fill = 0;
      this.add(var1, var3, var2);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton && this.mayConfirm()) {
         return this.done(true);
      } else {
         return var3 == this.cancelButton ? this.done(false) : false;
      }
   }

   public String getName() {
      return this.newName;
   }

   private boolean mayConfirm() {
      return FriendsListPart.isValidUserName(this.newName = this.nameField.getText().trim());
   }

   public boolean keyDown(Event var1, int var2) {
      if (var2 == 27) {
         return this.done(false);
      } else {
         return var2 == 10 && this.mayConfirm() ? this.done(true) : super.keyDown(var1, var2);
      }
   }

   public void show() {
      super.show();
      this.nameField.requestFocus();
      this.nameField.selectAll();
   }
}
