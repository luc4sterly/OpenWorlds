package NET.worlds.scape;

import java.io.IOException;

public class SetIntegerAction extends SlidePropertyAction {
   private int _value;
   private int _start;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SetIntegerAction var3 = null;
      if (this.useParam()) {
         try {
            this._value = Integer.valueOf(this.param());
         } catch (NumberFormatException var6) {
            System.out.println(this.getName() + " unable to parse " + this.paramName());
            this._value = 0;
         }
      }

      int var4 = this._value;
      if (this.slide()) {
         if (var2 == null) {
            this.start();
            this._start = (Integer)this.get();
         }

         float var5 = this.fraction();
         if (var5 < 1.0) {
            var4 = (int)((this._value - this._start) * var5 + this._start);
            var3 = this;
         }
      }

      this.set(new Integer(var4));
      return var3;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Set To"));
            } else if (var3 == 1) {
               var5 = new Integer(this._value);
            } else if (var3 == 2) {
               this._value = (Integer)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveInt(this._value);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            this.setPropertyActionRestoreState(var1);
            this._value = var1.restoreInt();
            break;
         case 2:
            super.restoreState(var1);
            this._value = var1.restoreInt();
            break;
         default:
            throw new TooNewException();
      }
   }
}
