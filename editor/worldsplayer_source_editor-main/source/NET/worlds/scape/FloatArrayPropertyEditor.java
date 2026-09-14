package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class FloatArrayPropertyEditor extends PropEditor {
   private FloatArrayPropertyEditor(Property var1) {
      super(var1);
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new FloatArrayEditorDialog(var1, var2, this.property);
   }

   public static Property make(Property var0) {
      var0.setPropertyType(6);
      return var0.setEditor(new FloatArrayPropertyEditor(var0));
   }
}
