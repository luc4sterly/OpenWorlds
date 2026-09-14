package NET.worlds.scape;

import java.util.Vector;

class UndoablDelete implements Undoable {
   protected VectorProperty prop;
   protected Object obj;

   UndoablDelete(VectorProperty var1, int var2) {
      this.prop = var1;
      this.obj = ((Vector)var1.get()).elementAt(var2);
      var1.delete(this.obj);
   }

   public void undo() {
      this.prop.add(this.obj);
   }
}
