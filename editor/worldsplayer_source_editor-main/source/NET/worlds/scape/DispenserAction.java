package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.io.IOException;

public class DispenserAction extends Action {
   URL wobName;
   Point3 center = new Point3(200.0F, 200.0F, 0.0F);
   float radius = 50.0F;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      WObject var3 = (WObject)this.getOwner();
      SuperRoot var4 = SuperRoot.readFile(this.wobName);
      if (!(var4 instanceof WObject)) {
         Console.println(Console.message("Cant-find") + this.wobName);
         return null;
      } else {
         WObject var5 = (WObject)var4;
         Point3Temp var6 = Point3Temp.make(
               this.radius - (float)Math.random() * 2.0F * this.radius, this.radius - (float)Math.random() * 2.0F * this.radius, 0.0F
            )
            .plus(this.center);
         var6.z = var5.getZ();
         var5.moveTo(var6);
         var3.getRoom().add(var5);
         return null;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "wob File Name"), "wob");
            } else if (var3 == 1) {
               var5 = this.wobName;
            } else if (var3 == 2) {
               this.wobName = (URL)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Center Position For Drop"));
            } else if (var3 == 1) {
               var5 = new Point3(this.center);
            } else if (var3 == 2) {
               this.center = new Point3((Point3)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Drop-position Radius"));
            } else if (var3 == 1) {
               var5 = new Float(this.radius);
            } else if (var3 == 2) {
               this.radius = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 3, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      URL.save(var1, this.wobName);
      var1.save(this.center);
      var1.saveFloat(this.radius);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.wobName = URL.restore(var1);
            this.center = (Point3)var1.restore();
            this.radius = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.wobName + "]";
   }
}
