package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class Point2PropertyEditor extends PropEditor {
   private Point2PropertyEditor(Property var1) {
      super(var1);
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new Point2EditorDialog(var1, var2, this.property);
   }

   public static Property make(Property var0) {
      var0.setPropertyType(7);
      return var0.setEditor(new Point2PropertyEditor(var0));
   }
}
