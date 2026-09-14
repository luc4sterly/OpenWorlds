package NET.worlds.scape;

import java.util.StringTokenizer;

class Point2EditorDialog extends ListEditorDialog {
   protected Property property;
   protected Point2 p;

   Point2EditorDialog(EditTile var1, String var2, Property var3) {
      super(var1, var2);
      this.property = var3;
      this.ready();
   }

   protected void build() {
      this.p = (Point2)this.property.get();
      super.build();
   }

   protected int getElementCount() {
      return 2;
   }

   protected String getElement(int var1) {
      switch (var1) {
         case 0:
            return "" + this.p.x;
         default:
            return "" + this.p.y;
      }
   }

   protected boolean setElements(StringTokenizer var1) {
      Point2 var2 = new Point2();
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
               default:
                  return false;
            }
         } catch (Exception var5) {
            return false;
         }
      }

      if (var3 != 2) {
         return false;
      }

      this.parent.addUndoableSet(this.property, var2);
      return true;
   }
}
