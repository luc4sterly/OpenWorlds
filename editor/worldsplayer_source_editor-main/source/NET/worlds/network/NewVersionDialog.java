package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.console.MultiLineLabel;
import NET.worlds.console.PolledDialog;
import NET.worlds.core.Std;
import java.awt.Button;
import java.awt.Event;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.text.MessageFormat;

public class NewVersionDialog extends PolledDialog {
   private Button yesButton = new Button(Console.message("Yes-Restart"));
   private Button noButton = new Button(Console.message("No-Keep-Playing"));
   private boolean confirmed;
   Object[] arguments = new Object[]{new String(Std.getProductName())};
   private String message = MessageFormat.format(Console.message("upgrade-is-now"), this.arguments);
   private static String title = Console.message("Download-Complete");
   private boolean done;

   public NewVersionDialog() {
      super(Console.getFrame(), null, title, false);
      this.setAlignment(1);
      this.readySetGo();
   }

   protected void build() {
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      var2.anchor = 10;
      var2.fill = 0;
      var2.weightx = 1.0;
      var2.weighty = 1.0;
      var2.gridwidth = 0;
      var2.gridheight = 1;
      this.add(var1, new MultiLineLabel(this.message, 5, 5), var2);
      var2.gridwidth = 2;
      this.add(var1, this.yesButton, var2);
      this.add(var1, this.noButton, var2);
   }

   public void show() {
      super.show();
      this.yesButton.requestFocus();
   }

   public synchronized boolean confirmRestart() {
      while (this.isActive()) {
         try {
            this.wait();
         } catch (InterruptedException var2) {
         }
      }

      return this.getConfirmed();
   }

   protected synchronized boolean done(boolean var1) {
      boolean var2 = super.done(var1);
      this.notify();
      return var2;
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.yesButton) {
         return this.done(true);
      } else {
         return var1.target == this.noButton ? this.done(false) : false;
      }
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 == 27 ? this.done(false) : super.keyDown(var1, var2);
   }
}
