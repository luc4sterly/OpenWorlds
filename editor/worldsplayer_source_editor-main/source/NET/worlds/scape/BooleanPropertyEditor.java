package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public class BooleanPropertyEditor extends PropEditor {
   private String[] choices;
   private String falseName;
   private String trueName;

   private BooleanPropertyEditor(Property var1, String var2, String var3) {
      super(var1);
      this.falseName = var2;
      this.trueName = var3;
   }

   public PolledDialog edit(EditTile var1, String var2) {
      String[] var3 = new String[]{this.falseName, this.trueName};
      return new BooleanFieldEditorDialog(var1, var2, this.property, var3);
   }

   public static Property make(Property var0, String var1, String var2) {
      var0.setPropertyType(0);
      return var0.setEditor(new BooleanPropertyEditor(var0, var1, var2));
   }
}
