package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class ColorPropertyEditor extends PropEditor {
   private ColorPropertyEditor(Property var1) {
      super(var1);
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new ColorEditorDialog(var1, var2, this.property);
   }

   public static Property make(Property var0) {
      var0.setPropertyType(4);
      return var0.setEditor(new ColorPropertyEditor(var0));
   }
}
