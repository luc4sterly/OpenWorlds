package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class IntegerPropertyEditor extends PropEditor {
   boolean rangeLimits = false;
   int minVal;
   int maxVal;

   private IntegerPropertyEditor(Property var1) {
      super(var1);
   }

   private IntegerPropertyEditor(Property var1, int var2, int var3) {
      super(var1);
      this.rangeLimits = true;
      this.minVal = var2;
      this.maxVal = var3;
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new IntegerFieldEditorDialog(var1, var2, this.property, this);
   }

   public static Property make(Property var0) {
      var0.setPropertyType(1);
      return var0.setEditor(new IntegerPropertyEditor(var0));
   }

   public static Property make(Property var0, int var1, int var2) {
      var0.setPropertyType(1);
      return var0.setEditor(new IntegerPropertyEditor(var0, var1, var2));
   }
}
