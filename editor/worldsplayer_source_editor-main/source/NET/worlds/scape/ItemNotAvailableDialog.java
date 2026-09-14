package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.ImageButtons;
import NET.worlds.console.ImageButtonsCallback;
import NET.worlds.console.PolledDialog;
import java.awt.Component;
import java.awt.Rectangle;
import java.awt.Window;

public class ItemNotAvailableDialog extends PolledDialog implements ImageButtonsCallback {
   private ImageButtons ib;

   public ItemNotAvailableDialog(Window var1, DialogReceiver var2) {
      super(var1, var2, Console.message("Not-Available"), false);
      this.setAlignment(1);
      Rectangle[] var3 = new Rectangle[]{new Rectangle(101, 22, 48, 19)};
      this.ib = new ImageButtons(Console.message("notavail.gif"), var3, this);
      this.ready();
   }

   protected void build() {
      this.add("Center", this.ib);
   }

   public Object imageButtonsCallback(Component var1, int var2) {
      this.done(false);
      return null;
   }

   public boolean keyDown(java.awt.Event var1, int var2) {
      if (var2 == 27) {
         return this.done(false);
      } else {
         return var2 == 10 ? this.done(false) : super.keyDown(var1, var2);
      }
   }
}
