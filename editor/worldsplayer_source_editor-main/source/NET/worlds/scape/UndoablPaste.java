package NET.worlds.scape;

class UndoablPaste extends UndoablAdd {
   private ClipboardEntry clipboard;

   UndoablPaste(VectorProperty var1, ClipboardEntry var2, Object var3) {
      super(var1, var3);
      this.clipboard = var2;
   }

   public void undo() {
      super.undo();
      this.clipboard.unPaste((SuperRoot)this.obj);
   }
}
