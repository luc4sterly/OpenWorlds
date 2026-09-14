package NET.worlds.scape;

class ObjEditorDialog extends ObjectSelectorDialog {
   ObjEditorDialog(EditTile var1, String var2, Property var3, SuperRoot var4, Class var5) {
      super(var1, var2, var3, var4, var5);
   }

   protected void addIt(Property var1, Object var2) {
      this.parent.addUndoableSet(var1, var2);
   }
}
