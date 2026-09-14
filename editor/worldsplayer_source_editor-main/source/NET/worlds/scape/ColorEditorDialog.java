package NET.worlds.scape;

import java.awt.Color;
import java.util.StringTokenizer;

class ColorEditorDialog extends ListEditorDialog {
   protected Property property;
   protected Color c;

   ColorEditorDialog(EditTile var1, String var2, Property var3) {
      super(var1, var2);
      this.property = var3;
      this.ready();
   }

   protected void build() {
      this.c = (Color)this.property.get();
      super.build();
   }

   protected int getElementCount() {
      return 3;
   }

   protected String getElement(int var1) {
      if (this.c == null) {
         return "null";
      }

      switch (var1) {
         case 0:
            return "" + this.c.getRed();
         case 1:
            return "" + this.c.getGreen();
         default:
            return "" + this.c.getBlue();
      }
   }

   protected boolean setElements(StringTokenizer var1) {
      int[] var2 = new int[3];
      int var3 = 0;

      while (var1.hasMoreTokens()) {
         try {
            int var4 = Integer.valueOf(var1.nextToken());
            if (var4 < 0 || var4 > 255) {
               return false;
            }

            var2[var3++] = var4;
         } catch (Exception var5) {
            return false;
         }
      }

      if (var3 == 3) {
         this.parent.addUndoableSet(this.property, new Color(var2[0], var2[1], var2[2]));
         return true;
      } else {
         return false;
      }
   }
}
