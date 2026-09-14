package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;
import java.util.Vector;

public class AddObjectAction extends SetPropertyAction {
   private SuperRoot _value;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      Debug.assert_(!this.useParam());
      this.add((Object)this._value);
      return null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               VectorProperty var6 = new VectorProperty(this, var1, "Object to Add");
               if (this._value != null) {
                  var6.allowSetNull();
                  var5 = var6;
               }
            } else if (var3 == 1) {
               var5 = new Vector(1);
               if (this._value != null) {
                  ((Vector)var5).addElement(this._value);
               }
            } else if (var3 == 4) {
               Debug.assert_(var4 == this._value);
               this._value = null;
            } else if (var3 == 3) {
               Debug.assert_(this._value == null);
               this._value = (SuperRoot)var4;
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
            this._value = (SuperRoot)var1.restoreMaybeNull();
            return;
         default:
            throw new TooNewException();
      }
   }
}
