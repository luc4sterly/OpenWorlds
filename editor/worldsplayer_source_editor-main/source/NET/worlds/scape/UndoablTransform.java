package NET.worlds.scape;

class UndoablTransform implements Undoable {
   private WObject wob;
   private Transform transform;

   UndoablTransform(WObject var1) {
      this.wob = var1;
      this.transform = var1.getTransform();
   }

   public void undo() {
      this.wob.setTransform(this.transform);
   }
}
