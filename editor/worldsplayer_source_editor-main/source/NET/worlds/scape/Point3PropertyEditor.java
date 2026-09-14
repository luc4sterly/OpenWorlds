package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class Point3PropertyEditor extends PropEditor {
   private Point3PropertyEditor(Property var1) {
      super(var1);
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new Point3EditorDialog(var1, var2, this.property);
   }

   public static Property make(Property var0) {
      var0.setPropertyType(8);
      return var0.setEditor(new Point3PropertyEditor(var0));
   }
}
