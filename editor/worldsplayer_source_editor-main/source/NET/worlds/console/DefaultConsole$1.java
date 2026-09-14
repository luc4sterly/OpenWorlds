package NET.worlds.console;

import java.awt.Component;

class DefaultConsole$1 implements ImageButtonsCallback {
   DefaultConsole this$0;

   DefaultConsole$1(DefaultConsole var1) {
      this.this$0 = var1;
   }

   public Object imageButtonsCallback(Component var1, int var2) {
      if (var2 != -1) {
         this.this$0.startDrive();
      } else {
         this.this$0.driveButton.drawDown();
      }

      return this;
   }
}
