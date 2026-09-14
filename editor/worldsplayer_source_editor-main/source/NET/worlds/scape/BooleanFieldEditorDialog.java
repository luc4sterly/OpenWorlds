package NET.worlds.scape;

class BooleanFieldEditorDialog extends CheckboxEditorDialog {
   private Property property;

   BooleanFieldEditorDialog(EditTile var1, String var2, Property var3, String[] var4) {
      super(var1, var2, var4);
      this.property = var3;
      this.ready();
   }

   protected int getValue() {
      return (Boolean)this.property.get() ? 1 : 0;
   }

   protected void setValue(int var1) {
      this.parent.addUndoableSet(this.property, new Boolean(var1 == 1));
   }
}
