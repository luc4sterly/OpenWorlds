package NET.worlds.console;

import NET.worlds.network.Galaxy;
import NET.worlds.network.VarErrorException;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.Panel;

public class InternetConnectionDialog extends PolledDialog {
   private String msg;
   private Button okButton;
   private Button cancelButton;
   private static boolean firstTimeDone;
   private static boolean choseSingleUserMode;
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);

   public static boolean isFirstTimeDone() {
      return firstTimeDone;
   }

   public static boolean choseSingleUserMode() {
      return choseSingleUserMode;
   }

   public InternetConnectionDialog(Galaxy var1, VarErrorException var2) {
      super(Console.getFrame(), var1, Console.message("Internet-Connection"), true);
      Console.getActive();
      this.okButton = new Button(Console.message("Retry"));
      this.cancelButton = new Button(Console.message("Single-user"));
      this.setAlignment(1);
      this.msg = var2.getMsg().replace('\n', ' ');
      this.ready();
   }

   protected boolean done(boolean var1) {
      boolean var2 = super.done(var1);
      choseSingleUserMode = !var1;
      firstTimeDone = true;
      return var2;
   }

   protected void build() {
      this.setLayout(new BorderLayout());
      Panel var1 = new Panel(new BorderLayout());
      var1.add("Center", new TextCanvas(this.msg, 400));
      var1.add("North", new Filler(10, 10));
      var1.add("South", new Filler(10, 10));
      var1.add("East", new Filler(10, 10));
      var1.add("West", new Filler(10, 10));
      this.add("Center", var1);
      Panel var2 = new Panel();
      this.okButton.setFont(bfont);
      this.cancelButton.setFont(bfont);
      var2.add(this.okButton);
      var2.add(this.cancelButton);
      this.add("South", var2);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton) {
         return this.done(true);
      } else {
         return var3 == this.cancelButton ? this.done(false) : false;
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
