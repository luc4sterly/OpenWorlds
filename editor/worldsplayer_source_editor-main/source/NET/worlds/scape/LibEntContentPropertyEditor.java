package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class LibEntContentPropertyEditor extends PropEditor {
   private LibEntContentPropertyEditor(Property var1) {
      super(var1);
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new LibEntContentEditorDialog(var1, var2, this.property);
   }

   public static Property make(Property var0) {
      return var0.setEditor(new LibEntContentPropertyEditor(var0));
   }
}
