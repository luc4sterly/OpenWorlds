package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class FloatPropertyEditor extends PropEditor {
   boolean rangeLimits = false;
   float minVal;
   float maxVal;

   private FloatPropertyEditor(Property var1) {
      super(var1);
   }

   private FloatPropertyEditor(Property var1, float var2, float var3) {
      super(var1);
      this.rangeLimits = true;
      this.minVal = var2;
      this.maxVal = var3;
   }

   public PolledDialog edit(EditTile var1, String var2) {
      return new FloatFieldEditorDialog(var1, var2, this.property, this);
   }

   public static Property make(Property var0) {
      var0.setPropertyType(2);
      return var0.setEditor(new FloatPropertyEditor(var0));
   }

   public static Property make(Property var0, float var1, float var2) {
      var0.setPropertyType(2);
      return var0.setEditor(new FloatPropertyEditor(var0, var1, var2));
   }
}
