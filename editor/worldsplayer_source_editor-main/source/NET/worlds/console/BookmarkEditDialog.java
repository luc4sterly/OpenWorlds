package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;

class BookmarkEditDialog extends PolledDialog {
   private TextField nameField;
   private TextField URLField;
   private Button okButton;
   private Button cancelButton;
   private String newName;
   private String newTarget;
   private int index;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);

   BookmarkEditDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5) {
      this(var1, var2, var3, var4, Console.message("OK"), Console.message("Cancel"), var5, -1);
   }

   BookmarkEditDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, String var6, String var7) {
      this(var1, var2, var3, var4, var5, var6, var7, -1);
   }

   BookmarkEditDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, int var5) {
      this(var1, var2, Console.message("Edit-WorldsMark"), var3, Console.message("OK"), Console.message("Cancel"), var4, var5);
   }

   private BookmarkEditDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4, String var5, String var6, String var7, int var8) {
      super(var1, var2, var3, true);
      this.index = var8;
      this.nameField = new TextField(var4, 40);
      this.URLField = new TextField(var7, 40);
      this.okButton = new Button(var5);
      this.cancelButton = new Button(var6);
      this.ready();
   }

   protected void build() {
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      var2.fill = 0;
      var2.weightx = 1.0;
      var2.weighty = 1.0;
      var2.gridwidth = 2;
      var2.gridheight = 1;
      Label var3 = new Label(Console.message("Name"));
      this.add(var1, var3, var2);
      var2.gridwidth = 0;
      var2.fill = 2;
      this.nameField.setFont(font);
      this.URLField.setFont(font);
      this.add(var1, this.nameField, var2);
      var2.fill = 0;
      var2.gridwidth = 2;
      this.add(var1, new Label("URL:"), var2);
      var2.gridwidth = 0;
      var2.fill = 2;
      this.add(var1, this.URLField, var2);
      Panel var4 = new Panel();
      this.okButton.setFont(bfont);
      this.cancelButton.setFont(bfont);
      var4.add(this.okButton);
      var4.add(this.cancelButton);
      var2.gridwidth = 0;
      var2.fill = 0;
      this.add(var1, var4, var2);
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

   public String getTarget() {
      return this.newTarget;
   }

   public int getIndex() {
      return this.index;
   }

   private boolean mayConfirm() {
      this.newName = this.nameField.getText();
      int var1 = this.newName.length();

      do {
         var1--;
      } while (var1 >= 0 && this.newName.charAt(var1) == ' ');

      this.newName = this.newName.substring(0, var1 + 1);
      this.newTarget = this.URLField.getText().trim();
      return this.newName.length() != 0 && this.newTarget.length() != 0;
   }

   public boolean keyDown(Event var1, int var2) {
      if (var2 == 27) {
         return this.done(false);
      }

      if (var2 == 10) {
         if (this.mayConfirm()) {
            return this.done(true);
         }
      } else if (var2 == 9) {
         if (var1.target == this.nameField) {
            this.URLField.requestFocus();
            this.URLField.selectAll();
         } else if (var1.target == this.URLField) {
            this.nameField.requestFocus();
            this.nameField.selectAll();
         }

         return true;
      }

      return super.keyDown(var1, var2);
   }

   public void show() {
      super.show();
      this.nameField.requestFocus();
      this.nameField.selectAll();
   }
}
