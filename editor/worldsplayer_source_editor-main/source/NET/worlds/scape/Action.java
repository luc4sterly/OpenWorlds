package NET.worlds.scape;

import java.io.IOException;

public abstract class Action extends SuperRoot {
   public String rightMenuLabel;
   private static Object classCookie = new Object();

   public abstract Persister trigger(Event var1, Persister var2);

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(4, classCookie);
      var1.saveString(this.rightMenuLabel);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            var1.restoreInt();
            this.setName(var1.restoreString());
         case 0:
            var1.setOldFlag();
            break;
         case 2:
            var1.setOldFlag();
            super.restoreState(var1);
            var1.restoreInt();
            break;
         case 4:
            this.rightMenuLabel = var1.restoreString();
         case 3:
            super.restoreState(var1);
            break;
         default:
            throw new TooNewException();
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Trigger Now"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(false);
            } else if (var3 == 2 && (Boolean)var4) {
               RunningActionHandler.trigger(this, this.getWorld(), null);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Right Menu Label").allowSetNull());
            } else if (var3 == 1) {
               var5 = this.rightMenuLabel;
            } else if (var3 == 2) {
               this.rightMenuLabel = (String)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }
}
