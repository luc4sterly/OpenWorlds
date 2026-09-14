package NET.worlds.scape;

import NET.worlds.core.Std;
import java.io.IOException;

public abstract class SlidePropertyAction extends SetPropertyAction {
   private float _duration = 0.0F;
   private int _startMilliTime = 0;
   private static Object classCookie = new Object();

   protected boolean slide() {
      return this._duration != 0.0F;
   }

   protected void start() {
      this._startMilliTime = Std.getFastTime();
   }

   protected float fraction() {
      return (Std.getFastTime() - this._startMilliTime) / (1000.0F * this._duration);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Duration"));
            } else {
               if (var3 == 1) {
                  return new Float(this._duration);
               }

               if (var3 == 2) {
                  this._duration = (Float)var4;
               }
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
      var1.saveFloat(this._duration);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this._duration = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }
}
