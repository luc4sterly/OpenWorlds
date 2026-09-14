package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.scape.BumpEventTemp;
import NET.worlds.scape.BumpHandler;
import NET.worlds.scape.NoSuchPropertyException;
import NET.worlds.scape.Portal;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Room;
import NET.worlds.scape.Saver;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.VectorProperty;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class RemoveHandler extends SuperRoot implements BumpHandler {
   private Vector handlers = new Vector(1);
   private static Object classCookie = new Object();

   public RemoveHandler() {
   }

   public RemoveHandler(SuperRoot var1) {
      this.handlers.addElement(var1);
   }

   public boolean handle(BumpEventTemp var1) {
      Room var2 = ((Portal)var1.target).getRoom();
      Debug.assert_(var2 instanceof Staircase || var2 instanceof Stair);
      Enumeration var3 = this.handlers.elements();

      while (var3.hasMoreElements()) {
         SuperRoot var4 = (SuperRoot)var3.nextElement();
         if (var2.hasHandler(var4)) {
            var2.removeHandler(var4);
         }
      }

      return true;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveVector(this.handlers);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
         case 0:
            if (var1.restoreBoolean()) {
               this.handlers.addElement(var1.restore());
            }
            break;
         case 2:
            super.restoreState(var1);
            this.handlers = var1.restoreVector();
            break;
         default:
            throw new TooNewException();
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new VectorProperty(this, var1, "Handlers to Remove");
            } else if (var3 == 1) {
               var5 = this.handlers.clone();
            } else if (var3 == 4) {
               this.handlers.removeElement(var4);
            } else if (var3 == 3) {
               this.handlers.addElement(var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }
}
