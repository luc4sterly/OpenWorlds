package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;

public class BootDialog extends PolledDialog {
   private Label bootLabel = new Label(Console.message("User-to-Boot"));
   private Button okButton = new Button(Console.message("OK"));
   private Button cancelButton = new Button(Console.message("Cancel"));
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);
   private TextField bootField = new TextField("");

   public BootDialog(java.awt.Window var1, DialogReceiver var2, String var3) {
      super(var1, var2, var3, true);
      this.ready();
   }

   public String getBoot() {
      return this.bootField.getText();
   }

   protected void build() {
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      var2.weightx = 1.0;
      var2.weighty = 1.0;
      var2.gridheight = 1;
      var2.fill = 0;
      var2.gridwidth = 2;
      this.add(var1, this.bootLabel, var2);
      var2.gridwidth = 0;
      var2.fill = 2;
      this.bootField.setFont(font);
      this.add(var1, this.bootField, var2);
      Panel var3 = new Panel();
      this.okButton.setFont(bfont);
      var3.add(this.okButton);
      this.cancelButton.setFont(bfont);
      var3.add(this.cancelButton);
      var2.gridwidth = 0;
      var2.fill = 0;
      this.add(var1, var3, var2);
   }

   public void show() {
      this.initialSize(320, 140);
      super.show();
      this.bootField.requestFocus();
   }

   public boolean handleEvent(Event var1) {
      return var1.id == 201 ? this.done(false) : super.handleEvent(var1);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.cancelButton) {
         this.done(false);
      } else if (var3 == this.okButton) {
         this.done(true);
      }

      return false;
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 == 27 ? this.done(false) : super.keyDown(var1, var2);
   }
}
