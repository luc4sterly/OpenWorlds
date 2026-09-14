package NET.worlds.console;

import NET.worlds.scape.SendURLAction;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class DefaultConsole$2 implements ActionListener {
   DefaultConsole this$0;

   DefaultConsole$2(DefaultConsole var1) {
      this.this$0 = var1;
   }

   public void actionPerformed(ActionEvent var1) {
      new SendURLAction("file:" + var1.getActionCommand()).startBrowser();
   }
}
