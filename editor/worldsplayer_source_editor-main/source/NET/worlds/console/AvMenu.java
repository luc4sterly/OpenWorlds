package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import NET.worlds.scape.HoloDrone;
import NET.worlds.scape.InventoryAvatar;
import NET.worlds.scape.InventoryManager;
import NET.worlds.scape.PosableShape;
import NET.worlds.scape.SelectAvatarAction;
import NET.worlds.scape.WearAction;
import java.awt.Event;
import java.awt.Font;
import java.awt.Menu;
import java.awt.MenuItem;
import java.net.MalformedURLException;
import java.util.Arrays;
import java.util.Enumeration;
import java.util.StringTokenizer;
import java.util.Vector;

public class AvMenu extends Menu implements AvatarDialogCallback {
   DefaultConsole defcon;
   Menu articMenuAF;
   Menu articMenuGO;
   Menu articMenuPZ;
   Menu specialGuestMenu;
   public MenuItem customize;
   static AvatarDialog avDialog;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   Vector articulatedAvatarItemsAF;
   Vector articulatedAvatarItemsGO;
   Vector articulatedAvatarItemsPZ;
   Vector holographicAvatarItemsAL;
   Vector holographicAvatarItemsMZ;
   Vector specialGuestAvatarItems;
   private static Vector parts = new Vector();
   private static Vector sizes = new Vector();
   private static Vector colors = new Vector();
   private static Vector faceTypes = new Vector();
   private static Vector headTypes = new Vector();

   AvMenu(DefaultConsole var1, URL var2) {
      super(Console.message("choose-av"));
      this.defcon = var1;
      URL var3 = URL.getAvatar();
      String var4 = "";
      if (var2 != null) {
         var4 = var2.getAbsolute();
         String var5 = var3.getAbsolute();
         if (var4.startsWith(var5)) {
            var4 = var4.substring(var5.length());
         }
      }

      this.articMenuAF = new Menu(Console.message("Articulated-A-F"));
      this.articMenuGO = new Menu(Console.message("Articulated-G-O"));
      this.articMenuPZ = new Menu(Console.message("Articulated-P-Z"));
      this.articMenuAF.setFont(font);
      this.articMenuGO.setFont(font);
      this.articMenuPZ.setFont(font);
      this.add(this.articMenuAF);
      this.add(this.articMenuGO);
      this.add(this.articMenuPZ);
      this.addAvatars(var3, "abcdef", "bod", this.articMenuAF, var4, this.articulatedAvatarItemsAF = new Vector());
      this.addAvatars(var3, "ghijklmno", "bod", this.articMenuGO, var4, this.articulatedAvatarItemsGO = new Vector());
      this.addAvatars(var3, "0123456789pqrstuvwxyz", "bod", this.articMenuPZ, var4, this.articulatedAvatarItemsPZ = new Vector());
      Menu var7 = new Menu(Console.message("Holographic-A-L"));
      Menu var6 = new Menu(Console.message("Holographic-M-Z"));
      var7.setFont(font);
      var6.setFont(font);
      this.add(var7);
      this.add(var6);
      this.addAvatars("abcdefghijkl", var7, var4, this.holographicAvatarItemsAL = new Vector());
      this.addAvatars("0123456789mnopqrstuvwxyz", var6, var4, this.holographicAvatarItemsMZ = new Vector());
      this.specialGuestMenu = null;
      this.specialGuestAvatarItems = new Vector();
      this.buildSpecialGuestMenu();
      this.customize = new MenuItem(Console.message("customize-av"));
   }

   public void rebuildVIPMenu() {
      this.articMenuAF.removeAll();
      this.articulatedAvatarItemsAF.removeAllElements();
      this.articMenuGO.removeAll();
      this.articulatedAvatarItemsGO.removeAllElements();
      this.articMenuPZ.removeAll();
      this.articulatedAvatarItemsPZ.removeAllElements();
      URL var1 = URL.getAvatar();
      this.addAvatars(var1, "abcdef", "bod", this.articMenuAF, null, this.articulatedAvatarItemsAF);
      this.addAvatars(var1, "ghijklmno", "bod", this.articMenuGO, null, this.articulatedAvatarItemsGO);
      this.addAvatars(var1, "0123456789pqrstuvwxyz", "bod", this.articMenuPZ, null, this.articulatedAvatarItemsPZ);
   }

   public void buildSpecialGuestMenu() {
      Vector var1 = InventoryManager.getInventoryManager().getInventoryAvatars();
      if (var1 != null && var1.size() > 0) {
         if (this.specialGuestMenu != null) {
            this.specialGuestMenu.removeAll();
            this.specialGuestAvatarItems.removeAllElements();
         } else {
            this.specialGuestMenu = new Menu(Console.message("special-av"));
            this.add(this.specialGuestMenu);
         }

         Enumeration var2 = var1.elements();

         while (var2.hasMoreElements()) {
            InventoryAvatar var3 = (InventoryAvatar)var2.nextElement();
            String var4 = var3.getItemName();
            StringTokenizer var5 = new StringTokenizer(var4);
            if (var5.countTokens() < 1) {
               System.out.println("ERROR: Special avatar inventory item " + var4 + " does not conform to the form \"<name> avatar\"");
            } else {
               String var6 = "";
               String var7 = var5.nextToken();
               if (var7.length() > 1) {
                  var6 = var7.substring(0, 1).toUpperCase() + var7.substring(1);
                  AvMenuItem var8 = new AvMenuItem(var6, false);
                  var8.intAvatar = "_vv" + var7 + ".rwg";
                  this.specialGuestAvatarItems.addElement(var8);
                  this.specialGuestMenu.add(var8);
               }
            }
         }
      }
   }

   private void addAvatars(URL var1, String var2, String var3, Menu var4, String var5, Vector var6) {
      if (var5 != null) {
         var5 = SelectAvatarAction.getPrettyAvatarName(var5);
      }

      Vector var7 = PosableShape.getPermittedNames();
      Vector var8 = new Vector();
      int var9 = var7.size();

      for (int var10 = 0; var10 < var9; var10++) {
         String var11 = (String)var7.elementAt(var10);
         if (!var11.substring(0, 1).equals("_")) {
            String var12 = SelectAvatarAction.getPrettyAvatarName(var11);
            if (var2.indexOf(var12.toLowerCase().substring(0, 1)) >= 0) {
               AvMenuItem var13 = new AvMenuItem(var12, false);
               var13.intAvatar = AvMenuItem.avify(var11, ".rwg");
               var13.setFont(font);
               var8.addElement(var13);
            }
         }
      }

      try {
         this.SortMenu(var8, var4, var6);
      } catch (NoClassDefFoundError var14) {
         var9 = var8.size();

         for (int var17 = 0; var17 < var9; var17++) {
            AvMenuItem var18 = (AvMenuItem)var8.elementAt(var17);
            var6.addElement(var18);
            var4.add(var18);
         }
      }
   }

   private void SortMenu(Vector var1, Menu var2, Vector var3) throws NoClassDefFoundError {
      Vector var4 = new Vector();
      int var5 = var1.size();

      for (int var6 = 0; var6 < var5; var6++) {
         AvMenuItem var7 = (AvMenuItem)var1.elementAt(var6);
         var4.add(new AvMenuItemSortable(var7));
      }

      Object[] var10 = var4.toArray();
      Arrays.sort(var10);
      var5 = var10.length;

      for (int var11 = 0; var11 < var5; var11++) {
         AvMenuItem var8 = ((AvMenuItemSortable)var10[var11]).menuItem;
         var3.addElement(var8);
         var2.add(var8);
      }
   }

   private void addAvatars(String var1, Menu var2, String var3, Vector var4) {
      var3 = SelectAvatarAction.getPrettyAvatarName(var3);
      String[] var5 = HoloDrone.getPermittedList();
      Vector var6 = new Vector();

      for (String var9 : var5) {
         if (!var9.substring(0, 1).equals("_")) {
            String var10 = SelectAvatarAction.getPrettyAvatarName(var9);
            if (var1.indexOf(var10.toLowerCase().substring(0, 1).toLowerCase()) >= 0) {
               AvMenuItem var11 = new AvMenuItem(var10, false);
               var11.intAvatar = AvMenuItem.avify(var9, ".mov");
               var11.setFont(font);
               var6.addElement(var11);
            }
         }
      }

      try {
         this.SortMenu(var6, var2, var4);
      } catch (NoClassDefFoundError var12) {
         int var14 = var6.size();

         for (int var15 = 0; var15 < var14; var15++) {
            AvMenuItem var16 = (AvMenuItem)var6.elementAt(var15);
            var4.addElement(var16);
            var2.add(var16);
         }
      }
   }

   public boolean action(Event var1, Object var2) {
      if (this.articulatedAvatarItemsAF == null
         || !this.articulatedAvatarItemsAF.contains(var1.target)
            && !this.articulatedAvatarItemsGO.contains(var1.target)
            && !this.articulatedAvatarItemsPZ.contains(var1.target)) {
         if (this.holographicAvatarItemsAL == null
            || !this.holographicAvatarItemsAL.contains(var1.target) && !this.holographicAvatarItemsMZ.contains(var1.target)) {
            if (var1.target == this.customize && this.customize != null) {
               if (avDialog != null) {
                  avDialog.closeWin();
               }

               avDialog = new AvatarDialog(DefaultConsole.getFrame(), null, Console.message("customize-av"), this);
            } else {
               if (this.specialGuestAvatarItems == null || !this.specialGuestAvatarItems.contains(var1.target)) {
                  return false;
               }

               AvMenuItem var3 = (AvMenuItem)var1.target;
               this.changeAvatar(var3, "rwg", URL.make(URL.getAvatar(), "_vv" + var3.getLabel().toLowerCase() + ".rwg"));
            }
         } else {
            this.changeAvatar((AvMenuItem)var1.target, "mov", null);
         }
      } else {
         this.changeAvatar((AvMenuItem)var1.target, "rwg", null);
      }

      return true;
   }

   public void notifyOfChange() {
      if (avDialog != null) {
         avDialog.setChangeCheck();
      }
   }

   public Vector getChoices(int var1) {
      switch (var1) {
         case 0:
            return headTypes;
         case 1:
            return sizes;
         case 2:
            return faceTypes;
         default:
            return colors;
      }
   }

   private static void addProperCasedEntries(Vector var0, Vector var1) {
      for (int var2 = 0; var2 < var1.size(); var2++) {
         String var3 = (String)var1.elementAt(var2);
         if (var3.charAt(0) != '_') {
            var0.addElement(var3.substring(0, 1).toUpperCase() + var3.substring(1));
         }
      }
   }

   public static void rebuildHeadList() {
      headTypes.removeAllElements();
      headTypes.addElement(Console.message("Original"));
      addProperCasedEntries(headTypes, PosableShape.getPermittedNames());
   }

   public Vector getComponents() {
      return parts;
   }

   public static int findIndex(Vector var0, String var1) {
      int var2 = var0.size();

      for (int var3 = 0; var3 < var2; var3++) {
         String var4 = (String)var0.elementAt(var3);
         if (var4.equalsIgnoreCase(var1)) {
            return var3;
         }
      }

      return -1;
   }

   public int getCurrentSelection(int var1) {
      String var2 = PosableShape.getCurrentAvCustomizable();
      if (var2 == null) {
         return 0;
      }

      int var3 = var2.indexOf(".", 7);
      String var4 = var2.substring(7, var3).toLowerCase();
      int var5 = -1;
      switch (var1) {
         case 0:
            int var17 = var2.lastIndexOf("NS");
            if (var17 >= 0 && var2.charAt(var17 + 5) == 'G') {
               var5 = findIndex(headTypes, PosableShape.readName(var2, var17 + 6));
               if (var5 >= 0) {
                  return var5;
               }
            }

            var5 = findIndex(headTypes, var4);
            return var5 < 0 ? 0 : var5;
         case 1:
            int var16 = var2.lastIndexOf("NS");
            if (var16 >= 0) {
               var5 = "qhd0DHQ".indexOf(var2.charAt(var16 + 2));
            }

            return var5 < 0 ? 3 : var5;
         case 2:
            int var6 = var2.lastIndexOf("NS");
            int var14 = var2.lastIndexOf("DgT");
            if (var14 > var6) {
               var14 += 3;

               while (var2.charAt(var14) >= '0' && var2.charAt(var14) <= '9') {
                  var14++;
               }

               String var18 = PosableShape.readName(var2, var14);
               Vector var9 = faceTypes;
               int var10 = var9.size();

               while (--var10 >= 1) {
                  String var11 = (String)var9.elementAt(var10);
                  if (var11.regionMatches(true, 0, var18, 0, var11.length())) {
                     var5 = var10;
                     break;
                  }
               }

               if (var5 < 0) {
                  var5 = findIndex(faceTypes, var4);
               }

               if (var5 > 0 && ((String)faceTypes.elementAt(var5)).equals((String)headTypes.elementAt(this.getCurrentSelection(0)))) {
                  var5 = 0;
               }
            } else {
               var5 = 0;
            }

            return var5 < 0 ? 0 : var5;
         default:
            int var7 = PosableShape.getMatPosition(var2, "fabcdeOVKY".charAt(var1 - 3));
            if (var7 >= 0 && var2.charAt(var7) == 'C' && var2.charAt(var7 + 1) == '_') {
               char var8 = var2.charAt(var7 + 2);
               if (var8 >= 'A' && var8 <= 'Z') {
                  var5 = 1 + (var8 - 'A');
               }
            }

            return var5 < 0 ? 0 : var5;
      }
   }

   public void setCurrentSelection(int var1, int var2) {
      String var3 = PosableShape.getCurrentAvCustomizable();
      if (var3 != null) {
         int var4 = var3.indexOf(".", 7);
         String var5 = var3.substring(7, var4).toLowerCase();
         String var6;
         char var7;
         if (var1 >= 3) {
            var7 = "fabcdeOVKY".charAt(var1 - 3);
            Debug.assert_(var2 >= 0);
            Debug.assert_(var2 <= PosableShape.colorTable.length);
            var6 = var2 == 0 ? null : "C_" + (char)(65 + var2 - 1);
         } else if (var1 == 1) {
            char var8 = "qhd0DHQ".charAt(var2);
            char[] var9 = new char[]{var8, var8, var8};
            var7 = 'Q';
            var6 = new String(var9);
         } else {
            var7 = (char)(var1 == 0 ? 72 : 69);
            Vector var10 = var1 == 0 ? headTypes : faceTypes;
            var6 = var2 == 0 ? null : ((String)var10.elementAt(var2)).toLowerCase();
         }

         WearAction.setAvLimb(var7, var6);
      }
   }

   private void changeAvatar(AvMenuItem var1, String var2, URL var3) {
      if (var3 == null) {
         try {
            var3 = new URL(URL.getAvatar(), var1.intAvatar);
         } catch (MalformedURLException var5) {
            Console.println(Console.message("invalid-URL") + " " + var5);
            return;
         }
      }

      this.defcon.setNextAvatar(var3, var1);
   }

   private AvMenuItem findAvatar(Vector var1, String var2) {
      if (var1 != null) {
         int var3 = var1.size();

         for (int var4 = 0; var4 < var3; var4++) {
            AvMenuItem var5 = (AvMenuItem)var1.elementAt(var4);
            if (var5.getLabel().equals(var2)) {
               return var5;
            }
         }
      }

      return null;
   }

   public AvMenuItem findMenuItem(URL var1) {
      String var2 = URL.getAvatar().getAbsolute();
      String var3 = var1.getAbsolute().substring(var2.length());
      String var4 = SelectAvatarAction.getPrettyAvatarName(var3);
      int var5 = var4.length() + 3;
      boolean var6 = var3.regionMatches(true, 0, var4 + ".0E", 0, var5);
      String var7 = var3.substring(var3.lastIndexOf(46) + 1);
      AvMenuItem var8;
      return (!var7.equalsIgnoreCase("rwg") || this.articulatedAvatarItemsAF == null || (var8 = this.findAvatar(this.articulatedAvatarItemsAF, var4)) == null)
            && (var8 = this.findAvatar(this.articulatedAvatarItemsGO, var4)) == null
            && (var8 = this.findAvatar(this.articulatedAvatarItemsPZ, var4)) == null
            && (var8 = this.findAvatar(this.specialGuestAvatarItems, var4)) == null
            && (
               !var7.equalsIgnoreCase("mov")
                  || this.holographicAvatarItemsAL == null
                  || (var8 = this.findAvatar(this.holographicAvatarItemsAL, var4)) == null
                     && (var8 = this.findAvatar(this.holographicAvatarItemsMZ, var4)) == null
            )
         ? null
         : var8;
   }

   static {
      parts.addElement(Console.message("Head"));
      parts.addElement(Console.message("Head-size"));
      parts.addElement(Console.message("Face"));
      parts.addElement(Console.message("Hair"));
      parts.addElement(Console.message("Skin"));
      parts.addElement(Console.message("Shirt"));
      parts.addElement(Console.message("Coat"));
      parts.addElement(Console.message("Dress"));
      parts.addElement(Console.message("Pants"));
      parts.addElement(Console.message("Left-glove"));
      parts.addElement(Console.message("Right-glove"));
      parts.addElement(Console.message("Left-shoe"));
      parts.addElement(Console.message("Right-shoe"));
      sizes.addElement(Console.message("m30"));
      sizes.addElement(Console.message("m20"));
      sizes.addElement(Console.message("m10"));
      sizes.addElement(Console.message("standard"));
      sizes.addElement(Console.message("p10"));
      sizes.addElement(Console.message("p20"));
      sizes.addElement(Console.message("p30"));
      colors.addElement(Console.message("Original"));
      colors.addElement(Console.message("Black"));
      colors.addElement(Console.message("Blue"));
      colors.addElement(Console.message("Tan"));
      colors.addElement(Console.message("Red-orange"));
      colors.addElement(Console.message("Pale-pink"));
      colors.addElement(Console.message("Bright-green"));
      colors.addElement(Console.message("Green"));
      colors.addElement(Console.message("Dark-blue"));
      colors.addElement(Console.message("Blue-purple"));
      colors.addElement(Console.message("Light-blue"));
      colors.addElement(Console.message("Dark-pink"));
      colors.addElement(Console.message("Light-green"));
      colors.addElement(Console.message("Pale-orange"));
      colors.addElement(Console.message("Dark-grey"));
      colors.addElement(Console.message("Orange"));
      colors.addElement(Console.message("Pink"));
      colors.addElement(Console.message("Purple"));
      colors.addElement(Console.message("Red"));
      colors.addElement(Console.message("Burgundy"));
      colors.addElement(Console.message("Brown"));
      colors.addElement(Console.message("Light-grey"));
      colors.addElement(Console.message("Violet"));
      colors.addElement(Console.message("White"));
      colors.addElement(Console.message("Golden-yellow"));
      colors.addElement(Console.message("Medium-yellow"));
      colors.addElement(Console.message("Light-yellow"));
      headTypes.addElement(Console.message("Original"));
      addProperCasedEntries(headTypes, PosableShape.getPermittedNames());
      faceTypes.addElement(Console.message("Original"));
      addProperCasedEntries(faceTypes, PosableShape.getFaceNames());
   }
}
