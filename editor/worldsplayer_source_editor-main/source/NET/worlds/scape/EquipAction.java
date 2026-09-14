package NET.worlds.scape;

import NET.worlds.console.Console;
import java.io.IOException;
import java.util.Vector;

public class EquipAction extends Action {
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      Vector var3 = InventoryManager.getInventoryManager().getEquippableItems();
      new Vector();
      InventoryDialog var5 = new InventoryDialog(Console.getFrame());
      var5.show();
      return null;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
