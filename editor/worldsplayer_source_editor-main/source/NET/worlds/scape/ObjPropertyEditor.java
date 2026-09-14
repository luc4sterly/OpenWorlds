package NET.worlds.scape;

import NET.worlds.console.PolledDialog;
import NET.worlds.core.Debug;

public class ObjPropertyEditor extends PropEditor {
   SuperRoot root;
   Class clas;

   private ObjPropertyEditor(Property var1, SuperRoot var2, Class var3) {
      super(var1);
      this.root = var2;
      this.clas = var3;
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new ObjEditorDialog(var1, var2, this.property, this.root, this.clas);
   }

   public static Property make(Property var0, SuperRoot var1, Class var2) {
      return var0.setEditor(new ObjPropertyEditor(var0, var1, var2));
   }

   public static Property make(Property var0, SuperRoot var1, String var2) {
      Class var3 = null;

      try {
         var3 = Class.forName(var2);
      } catch (ClassNotFoundException var5) {
         System.out.println("Couldn't find " + var2);
         Debug.assert_(false);
      }

      return var0.setEditor(new ObjPropertyEditor(var0, var1, var3));
   }
}
