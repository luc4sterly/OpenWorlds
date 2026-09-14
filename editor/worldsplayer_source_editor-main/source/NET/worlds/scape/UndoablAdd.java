package NET.worlds.scape;

class UndoablAdd implements Undoable {
   protected VectorProperty prop;
   protected Object obj;

   UndoablAdd(VectorProperty var1, Object var2) {
      this.prop = var1;
      this.obj = var2;
      var1.add(var2);
   }

   public void undo() {
      this.prop.delete(this.obj);
   }

   public Object getObject() {
      return this.obj;
   }
}
