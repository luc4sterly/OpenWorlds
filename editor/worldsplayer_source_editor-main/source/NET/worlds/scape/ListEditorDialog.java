package NET.worlds.scape;

import java.util.StringTokenizer;

public abstract class ListEditorDialog extends FieldEditorDialog {
   public ListEditorDialog(EditTile var1, String var2) {
      super(var1, var2);
   }

   protected abstract int getElementCount();

   protected abstract String getElement(int var1);

   protected abstract boolean setElements(StringTokenizer var1);

   protected String getValue() {
      String var1 = "";
      int var2 = this.getElementCount();

      for (int var3 = 0; var3 < var2; var3++) {
         if (var3 != 0) {
            var1 = var1 + ", ";
         }

         var1 = var1 + this.getElement(var3);
      }

      return var1;
   }

   protected boolean setValue(String var1) {
      return this.setElements(new StringTokenizer(var1, ", \t", false));
   }
}
