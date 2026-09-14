package NET.worlds.scape;

import NET.worlds.console.BlackBox;
import NET.worlds.network.URL;
import java.io.IOException;

public class PlaybackRecordingAction extends Action {
   private String filename = "home:record.rec";
   private static Object classCookie = new Object();

   public void setFilename(String var1) {
      this.filename = var1;
   }

   public Persister trigger(Event var1, Persister var2) {
      BlackBox.getInstance().play(URL.make(this.filename));
      return null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Filename"));
            } else if (var3 == 1) {
               var5 = new String(this.filename);
            } else if (var3 == 2) {
               this.filename = (String)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveString(this.filename);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this.filename = var1.restoreString();
            return;
         default:
            throw new TooNewException();
      }
   }
}
