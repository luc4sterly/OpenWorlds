package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;

public class ChannelDialog extends PolledDialog {
   private Label channelLabel = new Label(Console.message("New-channel"));
   private Button okButton = new Button(Console.message("OK"));
   private Button cancelButton = new Button(Console.message("Cancel"));
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private TextField channelField;

   public ChannelDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4) {
      super(var1, var2, var3, true);
      this.channelField = new TextField(var4);
      this.ready();
   }

   public String getChannel() {
      return this.channelField.getText();
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
      this.channelLabel.setFont(font);
      this.add(var1, this.channelLabel, var2);
      var2.gridwidth = 0;
      var2.fill = 2;
      this.channelField.setFont(font);
      this.add(var1, this.channelField, var2);
      Panel var3 = new Panel();
      var3.add(this.okButton);
      var3.add(this.cancelButton);
      this.okButton.setFont(font);
      this.cancelButton.setFont(font);
      var2.gridwidth = 0;
      var2.fill = 0;
      this.add(var1, var3, var2);
   }

   public void show() {
      this.initialSize(320, 140);
      super.show();
      this.channelField.requestFocus();
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
