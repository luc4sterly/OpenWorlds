package NET.worlds.scape;

import java.io.IOException;

public class CameraHeightAction extends Action {
   public float newEyeHeight = 0.0F;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 != null && var3 instanceof WObject) {
         WObject var4 = (WObject)var3;
         Pilot var5 = Pilot.getActive();
         if (var5 == null) {
            return null;
         }

         if (var5.getRoom() != var4.getRoom()) {
            return null;
         }

         if (var5 instanceof HoloPilot) {
            HoloPilot var6 = (HoloPilot)var5;
            var6.setEyeHeight(this.newEyeHeight);
         }

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
               var5 = FloatPropertyEditor.make(new Property(this, var1, "New Eye Height"));
            } else if (var3 == 1) {
               var5 = new Float(this.newEyeHeight);
            } else if (var3 == 2) {
               this.newEyeHeight = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "[New Eye Height: " + this.newEyeHeight + "]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.newEyeHeight);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.newEyeHeight = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }
}
