package NET.worlds.scape;

import NET.worlds.console.PolledDialog;
import NET.worlds.network.URL;
import java.util.Enumeration;
import java.util.Vector;

public class URLPropertyEditor extends PropEditor {
   private FileList files;
   private Enumeration additions;
   private boolean acceptAnyExt = false;
   private boolean acceptDrops;

   private URLPropertyEditor(Property var1, String var2, Enumeration var3, boolean var4) {
      super(var1);
      this.acceptDrops = var4;
      URL var5 = URL.getContainingOrCurDir((SuperRoot)var1.getOwner());
      if (var2 == null) {
         this.acceptAnyExt = true;
      } else {
         if (var2.startsWith("*")) {
            var2 = var2.substring(1);
            this.acceptAnyExt = true;
         }

         this.files = new FileList(var5.unalias(), var2);
      }

      this.additions = var3;
   }

   public PolledDialog edit(EditTile var1, String var2) {
      Vector var3 = this.files == null ? new Vector() : this.files.getList();
      if (this.additions != null) {
         while (this.additions.hasMoreElements()) {
            var3.addElement(this.additions.nextElement().toString());
         }
      }

      return new URLEditorDialog(var1, var2, this.property, var3, this.acceptAnyExt ? null : this.files);
   }

   public static Property make(Property var0, String var1) {
      return make(var0, var1, null, true);
   }

   public static Property make(Property var0, String var1, boolean var2) {
      return make(var0, var1, null, var2);
   }

   public static Property make(Property var0, String var1, Enumeration var2) {
      return make(var0, var1, var2, true);
   }

   public static Property make(Property var0, String var1, Enumeration var2, boolean var3) {
      var0.setPropertyType(10);
      return var0.setEditor(new URLPropertyEditor(var0, var1, var2, var3));
   }

   public boolean libraryDrop(EditTile var1, Object var2, boolean var3, boolean var4) {
      if (!var3 && this.acceptDrops && var2 instanceof URL && (this.acceptAnyExt || this.files.extMatches(((URL)var2).getExt()))) {
         if (var4) {
            var1.addUndoableSet(this.property, var2);
         }

         return true;
      } else {
         return false;
      }
   }
}
