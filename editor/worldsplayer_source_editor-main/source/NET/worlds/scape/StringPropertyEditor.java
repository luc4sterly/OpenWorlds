package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class StringPropertyEditor extends PropEditor {
   private StringPropertyEditor(Property var1) {
      super(var1);
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new StringFieldEditorDialog(var1, var2, this.property);
   }

   public static Property make(Property var0) {
      var0.setPropertyType(3);
      return var0.setEditor(new StringPropertyEditor(var0));
   }
}
