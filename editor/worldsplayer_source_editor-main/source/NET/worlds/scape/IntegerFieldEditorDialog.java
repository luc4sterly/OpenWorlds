package NET.worlds.scape;

class IntegerFieldEditorDialog extends FieldEditorDialog {
   Property property;
   IntegerPropertyEditor limits;

   IntegerFieldEditorDialog(EditTile var1, String var2, Property var3, IntegerPropertyEditor var4) {
      super(var1, var2);
      this.property = var3;
      this.limits = var4;
      this.ready();
   }

   protected String getValue() {
      return "" + this.property.get();
   }

   protected boolean setValue(String var1) {
      if (var1.length() != 0) {
         try {
            int var2 = Integer.parseInt(var1);
            if (!this.limits.rangeLimits || var2 >= this.limits.minVal && var2 <= this.limits.maxVal) {
               this.parent.addUndoableSet(this.property, new Integer(var2));
               return true;
            }
         } catch (NumberFormatException var3) {
         }
      }

      return false;
   }
}
