package NET.worlds.console;

import NET.worlds.scape.Persister;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import NET.worlds.scape.TooNewException;
import java.awt.CheckboxMenuItem;
import java.io.IOException;

public class SavedAvMenuItem extends CheckboxMenuItem implements Persister {
   private String avatar;
   private static Object classCookie = new Object();

   public SavedAvMenuItem(String var1, String var2) {
      super(var1);
      this.avatar = var2;
   }

   public SavedAvMenuItem() {
   }

   public String getAvatar() {
      return this.avatar;
   }

   public void setAvatar(String var1) {
      this.avatar = var1;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      var1.saveString(this.getLabel());
      var1.saveString(this.avatar);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            this.setLabel(var1.restoreString());
            this.avatar = var1.restoreString();
            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }
}
