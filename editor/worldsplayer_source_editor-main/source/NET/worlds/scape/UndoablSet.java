package NET.worlds.scape;

class UndoablSet implements Undoable {
   private Property prop;
   private Object obj;

   UndoablSet(Property var1, Object var2) {
      this.prop = var1;
      this.obj = var1.get();
      var1.set(var2);
   }

   public void undo() {
      this.prop.set(this.obj);
   }
}
