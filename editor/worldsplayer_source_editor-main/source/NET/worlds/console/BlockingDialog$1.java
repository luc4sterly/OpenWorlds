package NET.worlds.console;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class BlockingDialog$1 extends WindowAdapter {
   BlockingDialog this$0;

   BlockingDialog$1(BlockingDialog var1) {
      this.this$0 = var1;
   }

   public void windowClosing(WindowEvent var1) {
      this.this$0.finish();
   }
}
