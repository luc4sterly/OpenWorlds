package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class TransformPropertyEditor extends PropEditor {
   private TransformPropertyEditor(Property var1) {
      super(var1);
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new TransformEditorDialog(var1, var2, this.property);
   }

   public static Property make(Property var0) {
      var0.setPropertyType(9);
      return var0.setEditor(new TransformPropertyEditor(var0));
   }
}
