package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.scape.PropList;
import java.awt.List;
import java.util.Vector;

class AttributeList extends List {
   public AttributeList(int var1) {
      super(var1);
      Vector var2 = new Vector();
      int var3 = IniFile.gamma().getIniInt("PropertyOrderCount", -1);
      if (var3 >= 0) {
         var2 = new Vector(var3);

         for (int var4 = 0; var4 < var3; var4++) {
            var2.addElement(IniFile.gamma().getIniString("PropertyOrder" + var4, ""));
         }
      }

      for (int var6 = 0; var6 < var2.size(); var6++) {
         String var5 = (String)var2.elementAt(var6);
         this.add(var5);
      }
   }

   public void save() {
      int var1 = this.getItemCount();
      PropList.setPreferences(this.getItems());
      IniFile.gamma().setIniInt("PropertyOrderCount", var1);

      for (int var2 = 0; var2 < var1; var2++) {
         IniFile.gamma().setIniString("PropertyOrder" + var2, this.getItem(var2));
      }
   }
}
