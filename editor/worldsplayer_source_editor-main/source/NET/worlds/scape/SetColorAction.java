package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.awt.Color;
import java.io.IOException;

public class SetColorAction extends SlidePropertyAction {
   private Color _value = null;
   private Color _start;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SetColorAction var3 = null;
      Color var4 = null;
      if (this.useParam()) {
         try {
            this._value = new Color(Integer.valueOf(this.param()));
         } catch (NumberFormatException var9) {
            System.out.println(this.getName() + " unable to parse " + this.paramName());
            this._value = null;
         }
      }

      if (this._value == null) {
         Debug.assert_(!this.slide());
      } else {
         if (this.slide()) {
            if (var2 == null) {
               this.start();
               this._start = (Color)this.get();
            }

            float var5 = this.fraction();
            if (var5 < 1.0) {
               int var6 = (int)((this._value.getRed() - this._start.getRed()) * var5) + this._start.getRed();
               int var7 = (int)((this._value.getGreen() - this._start.getGreen()) * var5) + this._start.getGreen();
               int var8 = (int)((this._value.getBlue() - this._start.getBlue()) * var5) + this._start.getBlue();
               var4 = new Color(var6, var7, var8);
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
               var5 = ColorPropertyEditor.make(new Property(this, var1, "Set To").allowSetNull());
               if (this._value == null) {
                  var5 = MaybeNullPropertyEditor.make((Property)var5, Color.black);
               }
            } else if (var3 == 1) {
               var5 = this._value;
            } else if (var3 == 2) {
               this._value = (Color)var4;
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
      if (this._value == null) {
         var1.saveBoolean(false);
      } else {
         var1.saveBoolean(true);
         var1.saveInt(this._value.getRed());
         var1.saveInt(this._value.getGreen());
         var1.saveInt(this._value.getBlue());
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            if (var1.restoreBoolean()) {
               int var2 = var1.restoreInt();
               int var3 = var1.restoreInt();
               int var4 = var1.restoreInt();
               this._value = new Color(var2, var3, var4);
            }

            return;
         default:
            throw new TooNewException();
      }
   }
}
