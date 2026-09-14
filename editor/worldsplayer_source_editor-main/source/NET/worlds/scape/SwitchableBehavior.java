package NET.worlds.scape;

import java.io.IOException;

public class SwitchableBehavior extends SuperRoot {
   protected boolean enabled = true;
   private static Object classCookie = new Object();

   public boolean getEnabled() {
      return this.enabled;
   }

   public SwitchableBehavior setEnabled(boolean var1) {
      this.enabled = var1;
      return this;
   }

   public SwitchableBehavior toggleEnabled() {
      this.setEnabled(!this.getEnabled());
      return this;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Enabled"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.enabled);
            } else if (var3 == 2) {
               this.enabled = (Boolean)var4;
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
      var1.saveBoolean(this.enabled);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
         case 0:
            this.enabled = var1.restoreBoolean();
            return;
         default:
            throw new TooNewException();
      }
   }
}
