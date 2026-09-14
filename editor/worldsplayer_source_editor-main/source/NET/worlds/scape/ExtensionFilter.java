package NET.worlds.scape;

import java.io.File;
import java.io.FilenameFilter;

public class ExtensionFilter implements FilenameFilter {
   private String _ext;

   public ExtensionFilter(String var1) {
      this._ext = var1;
   }

   public boolean accept(File var1, String var2) {
      return var2.endsWith(this._ext);
   }
}
