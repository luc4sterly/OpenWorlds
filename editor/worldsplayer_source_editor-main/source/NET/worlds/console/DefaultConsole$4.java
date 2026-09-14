package NET.worlds.console;

import java.io.File;
import java.io.FilenameFilter;

class DefaultConsole$4 implements FilenameFilter {
   public boolean accept(File var1, String var2) {
      return var2.startsWith("MessagesBundle") && var2.endsWith(".properties");
   }
}
