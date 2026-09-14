package NET.worlds.scape;

class EnumFieldEditorDialog extends CheckboxEditorDialog {
   private Property property;
   private int[] numbers;

   EnumFieldEditorDialog(EditTile var1, String var2, Property var3, String[] var4, int[] var5) {
      super(var1, var2, var4);
      this.property = var3;
      this.numbers = var5;
      this.ready();
   }

   protected int getValue() {
      return (Integer)this.property.get();
   }

   protected void setValue(int var1) {
      this.parent.addUndoableSet(this.property, new Integer(this.numbers[var1]));
   }
}
