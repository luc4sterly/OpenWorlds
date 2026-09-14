package NET.worlds.scape;

import java.util.StringTokenizer;

class Point3EditorDialog extends ListEditorDialog {
   protected Property property;
   protected Point3 p;

   Point3EditorDialog(EditTile var1, String var2, Property var3) {
      super(var1, var2);
      this.property = var3;
      this.ready();
   }

   protected void build() {
      this.p = (Point3)this.property.get();
      super.build();
   }

   protected int getElementCount() {
      return 3;
   }

   protected String getElement(int var1) {
      switch (var1) {
         case 0:
            return "" + this.p.x;
         case 1:
            return "" + this.p.y;
         default:
            return "" + this.p.z;
      }
   }

   protected boolean setElements(StringTokenizer var1) {
      Point3 var2 = new Point3();
      int var3 = 0;

      while (var1.hasMoreTokens()) {
         try {
            float var4 = Float.valueOf(var1.nextToken());
            switch (var3++) {
               case 0:
                  var2.x = var4;
                  break;
               case 1:
                  var2.y = var4;
                  break;
               case 2:
                  var2.z = var4;
                  break;
               default:
                  return false;
            }
         } catch (Exception var5) {
            return false;
         }
      }

      if (var3 != 3) {
         return false;
      }

      this.parent.addUndoableSet(this.property, var2);
      return true;
   }
}
