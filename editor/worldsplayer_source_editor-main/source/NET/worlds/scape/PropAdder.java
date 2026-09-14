package NET.worlds.scape;

import NET.worlds.console.PolledDialog;
import NET.worlds.core.Debug;

public class PropAdder implements LibraryDrop {
   protected VectorProperty property;

   protected PropAdder(VectorProperty var1) {
      this.property = var1;
   }

   public static VectorProperty make(VectorProperty var0) {
      return var0.setAdder(new PropAdder(var0));
   }

   public PolledDialog add(EditTile var1, String var2) {
      Debug.dAssert(false);
      return null;
   }

   public boolean hasAddDialog() {
      return false;
   }

   protected boolean checkObject(Object var1) {
      return this.property.addTest(var1);
   }

   public boolean libraryDrop(EditTile var1, Object var2, boolean var3, boolean var4) {
      if (!this.checkObject(var2)) {
         return false;
      }

      if (var4) {
         if (var3) {
            var1.addUndoablePaste(this.property, var2);
         } else {
            var1.addUndoableAdd(this.property, var2, true);
         }

         return !(var2 instanceof SuperRoot) || ((SuperRoot)var2).getOwner() != null;
      } else {
         return true;
      }
   }
}
