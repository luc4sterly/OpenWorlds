package NET.worlds.console;

import java.io.File;

class LogFile$1 implements DialogReceiver {
   String val$server;

   LogFile$1(String var1) {
      this.val$server = var1;
   }

   public void dialogDone(Object var1, boolean var2) {
      LogMailDialog var3 = (LogMailDialog)var1;
      File var4 = new File(LogFile.access$000() + ".mail");
      if (var4.isFile()) {
         if (var2) {
            LogFile.access$200(this.val$server, var4, LogFile.access$100(), var3.getComment());
         } else {
            var4.delete();
         }
      }
   }
}
