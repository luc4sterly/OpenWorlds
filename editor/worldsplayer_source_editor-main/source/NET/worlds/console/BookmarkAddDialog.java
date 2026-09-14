package NET.worlds.console;

class BookmarkAddDialog implements MainCallback, DialogReceiver {
   private java.awt.Window parent;
   private DialogReceiver receiver;
   private String name;
   private BookmarkEditDialog editor;

   BookmarkAddDialog(java.awt.Window var1, DialogReceiver var2) {
      this.parent = var1;
      this.receiver = var2;
      this.name = this.name;
      Main.register(this);
   }

   public void mainCallback() {
      this.editor = new BookmarkEditDialog(
         this.parent,
         this,
         Console.message("Add-WorldsMark2"),
         WorldsMarkPart.getCurrentPositionName(),
         Console.message("Add"),
         Console.message("Cancel"),
         WorldsMarkPart.getCurrentPositionURL(false)
      );
      Main.unregister(this);
   }

   public BookmarkEditDialog getEditor() {
      return this.editor;
   }

   public void dialogDone(Object var1, boolean var2) {
      this.receiver.dialogDone(this, var2);
   }
}
