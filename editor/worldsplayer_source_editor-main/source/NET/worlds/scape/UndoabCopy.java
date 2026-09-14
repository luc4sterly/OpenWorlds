package NET.worlds.scape;

class UndoabCopy implements Undoable {
   private ClipboardEntry prevClipboard = EditTile.getClipboard();

   UndoabCopy(ClipboardEntry var1) {
      EditTile.setClipboard(var1);
   }

   public void undo() {
      EditTile.setClipboard(this.prevClipboard);
   }
}
