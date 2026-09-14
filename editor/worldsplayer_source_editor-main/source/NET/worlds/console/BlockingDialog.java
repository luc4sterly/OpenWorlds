package NET.worlds.console;

import java.awt.Dialog;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BlockingDialog extends Dialog implements ActionListener {
   boolean stillWaiting = true;

   public BlockingDialog(Frame var1, String var2, boolean var3) {
      super(var1, var2, var3);
      this.addWindowListener(new BlockingDialog$1(this));
   }

   public void actionPerformed(ActionEvent var1) {
      this.finish();
   }

   public void finish() {
      this.responded();
      this.setVisible(false);
   }

   public synchronized void waitForResponse() {
      try {
         while (this.stillWaiting) {
            this.wait();
         }
      } catch (Exception var2) {
      }
   }

   public synchronized void responded() {
      this.stillWaiting = false;
      this.notifyAll();
   }
}
