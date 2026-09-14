package NET.worlds.scape;

import NET.worlds.console.Cursor;
import NET.worlds.network.URL;
import java.io.IOException;
import java.net.MalformedURLException;

public class SetURLAction extends SetPropertyAction {
   URL _value;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      if (this.useParam()) {
         try {
            this._value = new URL(this.param());
         } catch (MalformedURLException var4) {
            System.out.println(this.getName() + " unable to parse " + this.paramName());
         }
      }

      this.set(this._value);
      return null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(
                  new Property(this, var1, "Set To").allowSetNull(),
                  "ani;console;cur;drone;mid;mov;pilot;ra;ram;rwg;rwx;wav;wob;world;" + TextureDecoder.getAllExts(),
                  Cursor.getSysCursorURLs()
               );
            } else if (var3 == 1) {
               var5 = this._value;
            } else if (var3 == 2) {
               this._value = (URL)var4;
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
      URL.save(var1, this._value);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this._value = URL.restore(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
