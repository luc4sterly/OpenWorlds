package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

public class SetPoint2Action extends SlidePropertyAction {
   private Point2 _value = null;
   private Point2 _start;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SetPoint2Action var3 = null;
      Point2 var4 = null;
      if (this.useParam()) {
         String var5 = this.param();
         if (var5 == null) {
            this._value = null;
         } else {
            float var6 = 0.0F;
            float var7 = 0.0F;
            boolean var8 = true;
            int var9 = var5.indexOf(44);
            if (var9 == -1) {
               var8 = false;
            } else {
               try {
                  var6 = Float.valueOf(var5.substring(0, var9));
                  var5 = var5.substring(var9 + 1);
                  var7 = Float.valueOf(var5);
               } catch (NumberFormatException var11) {
                  var8 = false;
               }
            }

            if (!var8) {
               var6 = 0.0F;
               var7 = 0.0F;
               System.out.println(this.getName() + " unable to parse " + this.paramName());
            }

            this._value = new Point2(var6, var7);
         }
      }

      if (this._value == null) {
         Debug.assert_(!this.slide());
      } else {
         if (this.slide()) {
            if (var2 == null) {
               this.start();
               this._start = (Point2)this.get();
            }

            float var13 = this.fraction();
            if (var13 < 1.0 && this._start != null) {
               var4 = new Point2(this._value);
               var4.x = (this._value.x - this._start.x) * var13 + this._start.x;
               var4.y = (this._value.y - this._start.y) * var13 + this._start.y;
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
               var5 = Point2PropertyEditor.make(new Property(this, var1, "Set To").allowSetNull());
               if (this._value == null) {
                  var5 = MaybeNullPropertyEditor.make((Property)var5, new Point2());
               }
            } else if (var3 == 1) {
               var5 = this._value;
            } else if (var3 == 2) {
               this._value = (Point2)var4;
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
            this._value = (Point2)var1.restoreMaybeNull();
            return;
         default:
            throw new TooNewException();
      }
   }
}
