package NET.worlds.scape;

import java.io.IOException;

public class PosableAction extends Action {
   private String action = "wave";
   private static Object classCookie = new Object();

   public PosableAction() {
   }

   public PosableAction(String var1) {
      this.action = var1;
      this.rightMenuLabel = var1;
   }

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 instanceof PosableShape) {
         ((PosableShape)var3).animate(this.action);
      } else if (var3 instanceof Drone) {
         ((Drone)var3).animate(this.action);
      } else if (var3 instanceof Pilot) {
         ((Pilot)var3).animate(this.action);
      }

      return null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Action Name"));
            } else if (var3 == 1) {
               var5 = new String(this.action);
            } else if (var3 == 2) {
               this.action = (String)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "[action " + this.action + "]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveString(this.action);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.action = var1.restoreString();
            return;
         default:
            throw new TooNewException();
      }
   }
}
