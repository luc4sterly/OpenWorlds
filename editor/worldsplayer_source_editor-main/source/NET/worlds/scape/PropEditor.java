package NET.worlds.scape;

import NET.worlds.console.PolledDialog;

public abstract class PropEditor implements LibraryDrop {
   protected Property property;

   protected PropEditor(Property var1) {
      this.property = var1;
   }

   public abstract PolledDialog edit(EditTile var1, String var2);

   public boolean libraryDrop(EditTile var1, Object var2, boolean var3, boolean var4) {
      return false;
   }
}
