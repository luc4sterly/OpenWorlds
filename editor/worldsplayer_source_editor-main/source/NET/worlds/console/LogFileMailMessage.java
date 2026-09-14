package NET.worlds.console;

import java.io.File;

class LogFileMailMessage extends MailMessage {
   private static final String mailTo = "bugs@3dcd.com";
   private File logFile;

   LogFileMailMessage(String var1, File var2) {
      super(var1, "bugs@3dcd.com", "bugs@3dcd.com", "Gamma Log: Abnormal Termination", "A Gamma log with potential errors has been detected");
      this.logFile = var2;
   }

   protected void finished(boolean var1) {
      if (!var1) {
         this.logFile.delete();
      } else {
         Console.println(Console.message("Error-mailing"));
      }
   }
}
