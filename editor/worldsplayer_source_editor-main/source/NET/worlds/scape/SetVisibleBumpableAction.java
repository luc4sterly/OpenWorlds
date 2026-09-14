package NET.worlds.scape;

import java.io.IOException;

public class SetVisibleBumpableAction extends Action {
   public boolean targetBumpable = true;
   public boolean targetVisible = true;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 != null && var3 instanceof WObject) {
         WObject var4 = (WObject)var3;
         var4.setBumpable(this.targetBumpable);
         var4.setVisible(this.targetVisible);
         return null;
      } else {
         return null;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Target Bumpable"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.targetBumpable);
            } else if (var3 == 2) {
               this.targetBumpable = (Boolean)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Target Visible"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.targetVisible);
            } else if (var3 == 2) {
               this.targetVisible = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveBoolean(this.targetBumpable);
      var1.saveBoolean(this.targetVisible);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
         case 0:
            this.targetBumpable = var1.restoreBoolean();
            this.targetVisible = var1.restoreBoolean();
            return;
         default:
            throw new TooNewException();
      }
   }
}
