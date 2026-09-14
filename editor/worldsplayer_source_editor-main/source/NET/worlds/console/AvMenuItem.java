package NET.worlds.console;

import java.awt.CheckboxMenuItem;

class AvMenuItem extends CheckboxMenuItem {
   public String intAvatar;
   public String prettyAvatar;

   AvMenuItem(String var1, boolean var2) {
      super(var1, var2);
      this.prettyAvatar = var1;
   }

   public static String avify(String var0, String var1) {
      int var2 = var0.indexOf(46);
      return var2 != -1 ? var0.substring(0, var2).toLowerCase() + var1 : var0.toLowerCase() + var1;
   }
}
