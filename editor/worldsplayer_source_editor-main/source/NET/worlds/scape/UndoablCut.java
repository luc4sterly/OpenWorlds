package NET.worlds.scape;

class UndoablCut extends UndoablDelete {
   private ClipboardEntry prevClipboard = EditTile.getClipboard();
   private boolean clipValid;

   UndoablCut(VectorProperty var1, int var2) {
      super(var1, var2);
      ClipboardEntry var3 = new ClipboardEntry();
      if (var3.cut((SuperRoot)this.obj)) {
         EditTile.setClipboard(var3);
         this.clipValid = true;
      }
   }

   public void undo() {
      super.undo();
      if (this.clipValid) {
         EditTile.setClipboard(this.prevClipboard);
      }
   }
}
