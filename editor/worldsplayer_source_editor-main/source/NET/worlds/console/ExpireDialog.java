package NET.worlds.console;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Dialog;
import java.awt.Event;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Frame;
import java.awt.Panel;
import java.text.DateFormat;
import java.util.Date;

class ExpireDialog extends Dialog {
   protected Button button;
   private static Font font = new Font(Console.message("ButtonFont"), 0, 12);

   public ExpireDialog(Date var1) {
      super((Frame)null, GammaFrame.getDefaultTitle(), false);
      this.setLayout(new BorderLayout(15, 15));
      this.add("Center", new MultiLineLabel(Console.message("beta-expired") + DateFormat.getDateTimeInstance().format(var1), 20, 20));
      this.button = new Button(Console.message("OK"));
      this.button.setFont(font);
      Panel var2 = new Panel();
      var2.setLayout(new FlowLayout(1, 15, 15));
      var2.add(this.button);
      this.add("South", var2);
      this.pack();
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.button) {
         this.hide();
         this.dispose();
         Main.end();
         return true;
      } else {
         return false;
      }
   }

   public boolean gotFocus(Event var1, Object var2) {
      this.button.requestFocus();
      return true;
   }
}
