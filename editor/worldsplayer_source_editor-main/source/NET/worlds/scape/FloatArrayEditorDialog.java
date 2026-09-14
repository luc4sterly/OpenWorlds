package NET.worlds.scape;

import java.util.StringTokenizer;

class FloatArrayEditorDialog extends ListEditorDialog {
   protected Property property;
   protected float[] arr;

   FloatArrayEditorDialog(EditTile var1, String var2, Property var3) {
      super(var1, var2);
      this.property = var3;
      this.ready();
   }

   protected void build() {
      this.arr = (float[])this.property.get();
      super.build();
   }

   protected int getElementCount() {
      return this.arr.length;
   }

   protected String getElement(int var1) {
      return "" + this.arr[var1];
   }

   protected boolean setElements(StringTokenizer var1) {
      int var2 = 0;

      while (var1.hasMoreTokens()) {
         try {
            this.arr[var2++] = Float.valueOf(var1.nextToken());
         } catch (Exception var4) {
            return false;
         }
      }

      if (var2 == this.arr.length) {
         this.parent.addUndoableSet(this.property, this.arr);
         return true;
      } else {
         return false;
      }
   }
}
