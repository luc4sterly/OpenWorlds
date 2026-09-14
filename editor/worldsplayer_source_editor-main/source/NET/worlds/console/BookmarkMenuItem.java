package NET.worlds.console;

import NET.worlds.scape.Persister;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import NET.worlds.scape.TooNewException;
import java.awt.MenuItem;
import java.io.IOException;

public class BookmarkMenuItem extends MenuItem implements Persister {
   private String target;
   private static Object classCookie = new Object();

   public BookmarkMenuItem(String var1, String var2) {
      super(var1);
      this.target = var2;
   }

   public BookmarkMenuItem() {
   }

   public String getTarget() {
      return this.target;
   }

   public void setTarget(String var1) {
      this.target = var1;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      var1.saveString(this.getLabel());
      var1.saveString(this.target);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            this.setLabel(var1.restoreString());
            this.target = var1.restoreString();
            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }
}
