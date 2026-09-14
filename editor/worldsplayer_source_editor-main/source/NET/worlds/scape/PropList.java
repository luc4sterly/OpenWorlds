package NET.worlds.scape;

import NET.worlds.core.IniFile;
import java.awt.List;
import java.util.Vector;

public class PropList extends List {
   private Object obj;
   private Vector properties;
   private static String[] sortOrder = new String[]{
      "Name",
      "Tilesize",
      "Transform",
      "From",
      "To",
      "Extent",
      "Bumpable",
      "Collision Extent",
      "Visible",
      "Optimizable",
      "DrawFirstOnIntersection",
      "DrawOrderUnimportant"
   };

   public static void setPreferences(String[] var0) {
      sortOrder = var0;
   }

   public Object getObject() {
      return this.obj;
   }

   public void setObject(Object var1) {
      int var2 = this.getSelectedIndex();
      if (var1 != this.obj) {
         var2 = -1;
      }

      this.obj = var1;
      int var3 = this.countItems();
      if (var3 != 0) {
         this.delItems(0, var3 - 1);
      }

      Vector var4 = new Vector();
      EnumProperties var5 = new EnumProperties(var1);

      for (int var11 = 0; var5.hasMoreElements(); var11++) {
         Property var6 = (Property)var5.nextElement();
         if (!(var6 instanceof VectorProperty) && (var6.getEditor() != null || !(var6.get() instanceof Properties))) {
            var4.addElement(var6);
         }
      }

      this.properties = new Vector(var4.size());

      for (int var13 = 0; var13 < sortOrder.length; var13++) {
         String var7 = sortOrder[var13];
         int var8 = var4.size();

         for (int var9 = 0; var9 < var8; var9++) {
            Property var10 = (Property)var4.elementAt(var9);
            if (var10.getName().equals(var7)) {
               this.properties.addElement(var10);
               var4.removeElementAt(var9);
               break;
            }
         }
      }

      int var14 = var4.size();

      for (int var16 = 0; var16 < var14; var16++) {
         this.properties.addElement(var4.elementAt(var16));
      }

      var14 = this.properties.size();

      for (int var17 = 0; var17 < var14; var17++) {
         Property var18 = (Property)this.properties.elementAt(var17);
         this.addItem(var18.getName() + " (" + var18.getPropertyType() + ")" + " (" + var18.get() + ")");
      }

      var3 = this.countItems();
      if (var3 != 0 && var2 != -1) {
         if (var2 >= var3) {
            var2 = var3 - 1;
         }

         this.select(var2);
      }
   }

   public Property getSelectedProperty() {
      int var1 = this.getSelectedIndex();
      return var1 != -1 ? (Property)this.properties.elementAt(var1) : null;
   }

   public void addItem(String var1) {
      if (var1.length() > 128) {
         var1 = var1.substring(0, 125) + "...";
      }

      super.addItem(var1);
   }

   static {
      int var0 = IniFile.gamma().getIniInt("PropertyOrderCount", -1);
      if (var0 >= 0) {
         sortOrder = new String[var0];

         for (int var1 = 0; var1 < var0; var1++) {
            sortOrder[var1] = IniFile.gamma().getIniString("PropertyOrder" + var1, "");
         }
      }
   }
}
