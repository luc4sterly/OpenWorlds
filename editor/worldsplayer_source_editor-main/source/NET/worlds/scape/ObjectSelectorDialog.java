package NET.worlds.scape;

import NET.worlds.core.Std;
import java.util.Enumeration;
import java.util.Vector;

abstract class ObjectSelectorDialog extends ListAdderDialog {
   private Property property;
   private Vector objectVector = null;
   SuperRoot root = null;
   Class clas = null;

   ObjectSelectorDialog(EditTile var1, String var2, Property var3, SuperRoot var4, Class var5) {
      super(var1, var2);
      this.property = var3;
      this.root = var4;
      this.clas = var5;
      this.ready();
   }

   private void quicksort(String[] var1, int var2, int var3) {
      if (var3 > var2) {
         String var4 = var1[var3];
         int var7 = var2 - 1;
         int var8 = var3;

         String var5;
         Object var6;
         do {
            while (var1[++var7].compareTo(var4) < 0) {
            }

            do {
               var8--;
            } while (var8 > var2 && var1[var8].compareTo(var4) > 0);

            var5 = var1[var7];
            var1[var7] = var1[var8];
            var1[var8] = var5;
            var6 = this.objectVector.elementAt(var7);
            this.objectVector.setElementAt(this.objectVector.elementAt(var8), var7);
            this.objectVector.setElementAt(var6, var8);
         } while (var8 > var7);

         var1[var8] = var1[var7];
         var1[var7] = var1[var3];
         var1[var3] = var5;
         this.objectVector.setElementAt(this.objectVector.elementAt(var7), var8);
         this.objectVector.setElementAt(this.objectVector.elementAt(var3), var7);
         this.objectVector.setElementAt(var6, var3);
         this.quicksort(var1, var2, var7 - 1);
         this.quicksort(var1, var7 + 1, var3);
      }
   }

   protected void build() {
      this.objectVector = new Vector();
      if (this.root != null) {
         Enumeration var1 = this.root.getDeepOwned();

         while (var1.hasMoreElements()) {
            Object var2 = var1.nextElement();
            if (Std.instanceOf(var2, this.clas)) {
               this.objectVector.addElement(var2);
            }
         }

         String[] var3 = new String[this.objectVector.size()];

         for (int var4 = 0; var4 < var3.length; var4++) {
            var3[var4] = this.objectVector.elementAt(var4).toString();
         }

         this.quicksort(var3, 0, var3.length - 1);
         this.setListContents(var3);
      }

      super.build();
   }

   protected abstract void addIt(Property var1, Object var2);

   protected void add(int var1) {
      Object var2 = this.objectVector.elementAt(var1);
      if (var2 != null) {
         this.addIt(this.property, var2);
      }
   }
}
