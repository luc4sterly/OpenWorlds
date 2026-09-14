package NET.worlds.scape;

import NET.worlds.console.ConfirmDialog;
import NET.worlds.console.Console;

class MaybeNullDialog extends ConfirmDialog {
   private Property property;
   private Object newOne;
   private EditTile parent;

   MaybeNullDialog(EditTile var1, String var2, String var3, Property var4, Object var5) {
      super(Console.getFrame(), var1, var2, var3);
      this.property = var4;
      this.newOne = var5;
      this.parent = var1;
      this.ready();
   }

   protected boolean setValue() {
      this.parent.addUndoableSet(this.property, this.newOne);
      return true;
   }
}
