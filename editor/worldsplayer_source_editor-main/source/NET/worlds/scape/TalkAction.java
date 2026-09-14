package NET.worlds.scape;

import java.io.IOException;

public class TalkAction extends Action {
   String txt = null;
   private static Object classCookie = new Object();

   public TalkAction() {
   }

   public TalkAction(String var1) {
      this.txt = var1;
   }

   public Persister trigger(Event var1, Persister var2) {
      Pilot.getActive();
      Pilot.sendText(this.txt);
      return null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Message"));
            } else if (var3 == 1) {
               var5 = this.txt;
            } else if (var3 == 2) {
               this.txt = (String)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveString(this.txt);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.txt = var1.restoreString();
            return;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.txt + "]";
   }
}
