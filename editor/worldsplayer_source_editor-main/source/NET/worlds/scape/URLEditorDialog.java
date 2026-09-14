package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.net.MalformedURLException;
import java.util.Vector;

class URLEditorDialog extends FieldWithListEditorDialog {
   Property property;
   FileList extChecker;

   URLEditorDialog(EditTile var1, String var2, Property var3, Vector var4, FileList var5) {
      super(var1, var2 + " dir: " + URL.getBestContainer((SuperRoot)var3.getOwner()), var4);
      this.property = var3;
      this.extChecker = var5;
      this.ready();
   }

   protected String getValue() {
      SuperRoot var1 = (SuperRoot)this.property.getOwner();
      if (var1 != null && this.property.getName().equals("Source URL")) {
         var1 = var1.getOwner();
      }

      String var2 = URL.getRelativeTo((URL)this.property.get(), var1);
      return var2 == null ? "" : var2;
   }

   protected boolean setValue(String var1) {
      URL var2 = null;
      if (var1.length() == 0) {
         if (!this.property.canSetNull()) {
            return false;
         }
      } else {
         if (this.extChecker != null && !this.extChecker.extMatches(var1)) {
            Console.println(Console.message("extension-match") + this.extChecker.getExtList());
            return false;
         }

         try {
            var2 = new URL((SuperRoot)this.property.getOwner(), var1);
         } catch (MalformedURLException var4) {
            Console.println(Console.message("Illegal-URL") + var4);
            return false;
         }
      }

      this.parent.addUndoableSet(this.property, var2);
      return true;
   }
}
