package NET.worlds.console;

import java.io.File;
import java.io.FilenameFilter;

class DefaultConsole$3 implements FilenameFilter {
   DefaultConsole this$0;

   DefaultConsole$3(DefaultConsole var1) {
      this.this$0 = var1;
   }

   public boolean accept(File var1, String var2) {
      return var2.startsWith("chat.") && var2.endsWith(".glog.html");
   }
}
