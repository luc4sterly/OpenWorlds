package NET.worlds.scape;

import java.io.IOException;

public class CrashAction extends Action {
   private String message = "CrashAction";
   private static Object classCookie = new Object();

   public void setMessage(String var1) {
      this.message = var1;
   }

   public Persister trigger(Event var1, Persister var2) {
      throw new Error(this.message);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Message"));
            } else if (var3 == 1) {
               var5 = new String(this.message);
            } else if (var3 == 2) {
               this.message = (String)var4;
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
      var1.saveString(this.message);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this.message = var1.restoreString();
            return;
         default:
            throw new TooNewException();
      }
   }
}
