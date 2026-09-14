package NET.worlds.scape;

class ObjectAdderDialog extends ObjectSelectorDialog {
   ObjectAdderDialog(EditTile var1, String var2, VectorProperty var3, SuperRoot var4, Class var5) {
      super(var1, var2, var3, var4, var5);
   }

   protected void addIt(Property var1, Object var2) {
      this.parent.addUndoableAdd((VectorProperty)var1, var2, false);
   }
}
