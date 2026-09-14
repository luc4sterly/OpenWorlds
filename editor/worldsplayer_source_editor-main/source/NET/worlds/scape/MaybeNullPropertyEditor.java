package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class MaybeNullPropertyEditor extends PropEditor {
   private Object newOne;

   private MaybeNullPropertyEditor(Property var1, Object var2) {
      super(var1);
      this.newOne = var2;
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new MaybeNullDialog(var1, var2, "Create a new instance?", this.property, this.newOne);
   }

   public static Property make(Property var0, Object var1) {
      return var0.setEditor(new MaybeNullPropertyEditor(var0, var1));
   }
}
