package NET.worlds.scape;

import java.util.Vector;

class CDPositionEditorDialog extends FieldWithListEditorDialog {
   Property property;

   CDPositionEditorDialog(EditTile var1, String var2, Property var3, Vector var4) {
      super(var1, var2, var4);
      this.property = var3;
      this.ready();
   }

   protected String getValue() {
      return "" + this.property.get();
   }

   protected boolean setValue(String var1) {
      int var2 = var1.indexOf("#");
      if (var2 != -1) {
         var1 = var1.substring(0, var2).trim();
      }

      try {
         this.parent.addUndoableSet(this.property, new Integer(var1));
         return true;
      } catch (NumberFormatException var4) {
         return false;
      }
   }
}
