package NET.worlds.scape;

class StringFieldEditorDialog extends FieldEditorDialog {
   Property property;

   StringFieldEditorDialog(EditTile var1, String var2, Property var3) {
      super(var1, var2);
      this.property = var3;
      this.ready();
   }

   protected String getValue() {
      String var1 = (String)this.property.get();
      return var1 != null ? var1 : "";
   }

   protected boolean setValue(String var1) {
      if (var1.length() == 0) {
         if (!this.property.canSetNull()) {
            return false;
         }

         var1 = null;
      }

      this.parent.addUndoableSet(this.property, var1);
      return true;
   }
}
