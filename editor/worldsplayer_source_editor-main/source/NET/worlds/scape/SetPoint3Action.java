package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

public class SetPoint3Action extends SlidePropertyAction {
   private Point3 _value = null;
   private Point3 _start;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SetPoint3Action var3 = null;
      Point3 var4 = null;
      if (this.useParam()) {
         String var5 = this.param();
         if (var5 == null) {
            this._value = null;
         } else {
            float var6 = 0.0F;
            float var7 = 0.0F;
            float var8 = 0.0F;
            boolean var9 = true;
            int var10 = var5.indexOf(44);
            if (var10 == -1) {
               var9 = false;
            } else {
               try {
                  var6 = Float.valueOf(var5.substring(0, var10));
                  var5 = var5.substring(var10 + 1);
                  var10 = var5.indexOf(44);
                  if (var10 == -1) {
                     var9 = false;
                  } else {
                     var7 = Float.valueOf(var5.substring(0, var10));
                     var5 = var5.substring(var10 + 1);
                     var8 = Float.valueOf(var5);
                  }
               } catch (NumberFormatException var12) {
                  var9 = false;
               }
            }

            if (!var9) {
               System.out.println(this.getName() + " unable to parse " + this.paramName());
               var6 = 0.0F;
               var7 = 0.0F;
               var8 = 0.0F;
            }

            this._value = new Point3(var6, var7, var8);
         }
      }

      if (this._value == null) {
         Debug.assert_(!this.slide());
      } else {
         if (this.slide()) {
            if (var2 == null) {
               this.start();
               this._start = (Point3)this.get();
            }

            float var15 = this.fraction();
            if (var15 < 1.0) {
               var4 = new Point3(this._value);
               var4.x = (this._value.x - this._start.x) * var15 + this._start.x;
               var4.y = (this._value.y - this._start.y) * var15 + this._start.y;
               var4.z = (this._value.z - this._start.z) * var15 + this._start.z;
               var3 = this;
            }
         }

         if (var4 == null) {
            var4 = this._value;
         }
      }

      this.set(var4);
      return var3;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Set To").allowSetNull());
               if (this._value == null) {
                  var5 = MaybeNullPropertyEditor.make((Property)var5, new Point3());
               }
            } else if (var3 == 1) {
               var5 = this._value;
            } else if (var3 == 2) {
               this._value = (Point3)var4;
            } else if (var3 == 4) {
               this._value = null;
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
      var1.saveMaybeNull(this._value);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this._value = (Point3)var1.restoreMaybeNull();
            return;
         default:
            throw new TooNewException();
      }
   }
}
