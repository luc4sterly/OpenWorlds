package NET.worlds.console;

import java.awt.Button;
import java.awt.Color;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;

public class LocationDialog extends PolledDialog {
   private Button okButton = new Button(Console.message("OK"));
   private Button cancelButton = new Button(Console.message("Cancel"));
   private Label label = new Label(Console.message("New-URL"));
   private static Font font = new Font(Console.message("ButtonFont"), 0, 12);
   private static Font gfont = new Font(Console.message("GammaTextFont"), 0, 12);
   private TextField locationField;

   public LocationDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4) {
      super(var1, var2, var3, true);
      this.locationField = new TextField(var4, 40);
      this.locationField.setFont(gfont);
      this.ready();
   }

   public String getLocationURL() {
      return this.locationField.getText();
   }

   protected void build() {
      this.setBackground(Color.white);
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      var2.weightx = 0.0;
      var2.weighty = 0.0;
      var2.gridheight = 1;
      var2.fill = 0;
      var2.anchor = 13;
      var2.gridwidth = 1;
      this.label.setFont(font);
      this.add(var1, this.label, var2);
      var2.weightx = 1.0;
      var2.weighty = 0.0;
      var2.gridwidth = 0;
      var2.fill = 2;
      var2.anchor = 17;
      this.locationField.setFont(gfont);
      this.add(var1, this.locationField, var2);
      Panel var3 = new Panel();
      this.okButton.setFont(font);
      this.cancelButton.setFont(font);
      var3.add(this.okButton);
      var3.add(this.cancelButton);
      var2.gridwidth = 0;
      var2.anchor = 10;
      var2.fill = 0;
      this.add(var1, var3, var2);
   }

   public void show() {
      super.show();
      this.locationField.requestFocus();
   }

   public boolean handleEvent(Event var1) {
      return var1.id == 201 ? this.done(false) : super.handleEvent(var1);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.cancelButton) {
         return this.done(false);
      } else {
         return var3 == this.okButton ? this.done(true) : false;
      }
   }

   public boolean keyDown(Event var1, int var2) {
      if (var2 == 27) {
         return this.done(false);
      } else {
         return var2 == 10 ? this.done(true) : super.keyDown(var1, var2);
      }
   }
}
