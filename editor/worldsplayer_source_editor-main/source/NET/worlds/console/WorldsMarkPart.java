package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.RemoteFileConst;
import NET.worlds.network.URL;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Room;
import NET.worlds.scape.Saver;
import NET.worlds.scape.TeleportAction;
import NET.worlds.scape.TeleportStatus;
import NET.worlds.scape.World;
import java.awt.Container;
import java.awt.Event;
import java.awt.Font;
import java.awt.Menu;
import java.awt.MenuItem;
import java.awt.PopupMenu;
import java.io.File;
import java.util.Hashtable;
import java.util.Locale;
import java.util.Vector;

public class WorldsMarkPart implements FramePart, DialogReceiver, TeleportStatus, RemoteFileConst {
   private static final String worldsMarksFileName = "Gamma.worldsmarks";
   private static final int MAX_HISTORY = 10;
   private static URL userMarksURL = URL.make("home:Gamma.worldsmarks");
   private String name;
   private Menu menu;
   private Menu letsMenu;
   private MenuItem addItem = new MenuItem(Console.message("Add-WorldsMark"));
   private MenuItem deleteItem = new MenuItem(Console.message("Delete-WorldsMark"));
   private MenuItem editItem = new MenuItem(Console.message("Edit-WorldsMark"));
   private MenuItem locationItem = new MenuItem(Console.message("Change-Location"));
   private Menu historyMenu = new Menu(Console.message("Back"));
   private static Font font;
   private boolean teleporting = false;
   private boolean startLocationDialog = false;
   static Vector systemMarksNames;
   private static Vector systemMarks;
   private static Vector userMarks;
   private static Vector historyItems;
   private static int firstUserItem;
   private static Hashtable renamed;
   private static Vector excludes;
   private static Vector sequence;

   public WorldsMarkPart() {
      this(null);
   }

   public WorldsMarkPart(String var1) {
      this.name = var1;
   }

   public boolean isTeleporting() {
      return this.teleporting;
   }

   public static String getExternalName(String var0) {
      String var1 = (String)renamed.get(var0.toLowerCase());
      return var1 != null ? var1 : var0;
   }

   public Menu getMenu() {
      if (this.menu == null) {
         if (this.name != null) {
            this.menu = new Menu(this.name);
         } else {
            this.menu = new PopupMenu();
         }

         this.letsMenu = new PopupMenu();
         this.historyMenu.setFont(font);
         this.letsMenu.add(this.historyMenu);
         this.letsMenu.addSeparator();
         if (userMarks == null) {
            loadMarks();
         }

         if (systemMarks.size() != 0) {
            for (int var1 = 0; var1 < systemMarks.size(); var1++) {
               String var2 = (String)systemMarksNames.elementAt(var1);
               Menu var3 = new Menu(getExternalName(var2));
               addItems(var3, (Vector)systemMarks.elementAt(var1));
               var3.setFont(font);
               this.letsMenu.add(var3);
            }
         }

         this.addMainMenuItem(this.addItem);
         this.addMainMenuItem(this.deleteItem);
         this.addMainMenuItem(this.editItem);
         this.addMainMenuItem(this.locationItem);
         this.addMainMenuSeparator();
         addItems(this.menu, userMarks);
         addItems(this.historyMenu, historyItems);
      }

      return this.menu;
   }

   public Menu getLetsMenu() {
      if (this.letsMenu == null) {
         this.getMenu();
      }

      return this.letsMenu;
   }

   public static PopupMenu getPackageMenu(String var0) {
      int var1 = findPackageNum(var0);
      if (var1 < 0) {
         return null;
      }

      PopupMenu var2 = new PopupMenu();
      Vector var3 = (Vector)systemMarks.elementAt(var1);

      for (int var4 = 0; var4 < var3.size(); var4++) {
         MenuItem var5 = (MenuItem)var3.elementAt(var4);
         if (var5 instanceof BookmarkMenuItem) {
            BookmarkMenuItem var6 = (BookmarkMenuItem)var3.elementAt(var4);
            String var7 = var6.getLabel();
            String var8 = var6.getTarget();
            URL var9 = URL.make(TeleportAction.toURLString(var8));
            String var10 = TeleportAction.getPackageNameOfWorld(var9);
            if (var10 != null && findPackage(var10) == null) {
               String var11 = URL.make("home:" + var10).unalias();
               if (!new File(var11).isDirectory()) {
                  var7 = "Download " + var7;
               }
            }

            var2.add(new BookmarkMenuItem(var7, var8));
         }
      }

      boolean var12 = true;

      for (int var13 = 0; var13 < userMarks.size(); var13++) {
         URL var14 = URL.make(TeleportAction.toURLString(getBookmarkTarget(var13)));
         String var15 = TeleportAction.getPackageNameOfWorld(var14);
         if (var15 != null && var15.equalsIgnoreCase(var0)) {
            if (var12) {
               var12 = false;
               var2.addSeparator();
            }

            BookmarkMenuItem var16 = new BookmarkMenuItem(getBookmarkName(var13), getBookmarkTarget(var13));
            var2.add(var16);
         }
      }

      return var2;
   }

   private static void addItems(Menu var0, Vector var1) {
      for (int var2 = 0; var2 < var1.size(); var2++) {
         MenuItem var3 = (MenuItem)var1.elementAt(var2);
         var3.setFont(font);
         var0.add(var3);
      }
   }

   private void addMainMenuItem(MenuItem var1) {
      var1.setFont(font);
      this.menu.add(var1);
      firstUserItem++;
   }

   private void addMainMenuSeparator() {
      this.menu.addSeparator();
      firstUserItem++;
   }

   public static String getFirstWorld() {
      IniFile var0 = new IniFile("InstalledWorlds");
      return var0.getIniString("InstalledWorld0", "");
   }

   public static String getFirstSystemMarkURL() {
      if (userMarks == null) {
         loadMarks();
      }

      for (int var0 = 0; var0 < systemMarks.size(); var0++) {
         Vector var1 = (Vector)systemMarks.elementAt(var0);
         if (var1.size() > 0) {
            return ((BookmarkMenuItem)var1.elementAt(0)).getTarget();
         }
      }

      byte var2 = 0;
      return var2 < userMarks.size() ? ((BookmarkMenuItem)userMarks.elementAt(var2)).getTarget() : null;
   }

   private static void shortenNames(String var0, Vector var1) {
      int var2 = var1.size();
      int var3 = var0.length();

      for (int var4 = 0; var4 < var2; var4++) {
         MenuItem var5 = (MenuItem)var1.elementAt(var4);
         String var6 = var5.getLabel();
         if (var6.startsWith(var0)) {
            var5.setLabel(var6.substring(var3).trim());
         }
      }
   }

   private static int findPackageNum(String var0) {
      Vector var1 = systemMarksNames;
      if (var1 != null) {
         int var2 = var1.size();

         while (--var2 >= 0) {
            String var3 = (String)var1.elementAt(var2);
            if (var3.equalsIgnoreCase(var0)) {
               return var2;
            }
         }
      }

      return -1;
   }

   public static String findPackage(String var0) {
      int var1 = findPackageNum(var0);
      return var1 < 0 ? null : (String)systemMarksNames.elementAt(var1);
   }

   private static void loadMarks() {
      systemMarks = new Vector();
      systemMarksNames = new Vector();
      IniFile var2 = new IniFile("InstalledWorlds");
      String[] var3 = new String[sequence.size()];

      for (int var0 = 0; var0 < NetUpdate.maxInstalledWorlds(); var0++) {
         String var1 = var2.getIniString("InstalledWorld" + var0, "");
         if (!var1.equals("")) {
            NetUpdate.maxInstalledWorld(var0);
            String var4 = var1.toLowerCase();
            if (!excludes.contains(var4) && (!var4.equals("polygram") || !World.isWorldsStoreProscribed())) {
               int var5 = sequence.indexOf(var4);
               if (var5 != -1) {
                  var3[var5] = var1;
               } else {
                  systemMarksNames.addElement(var1);
               }
            }
         }
      }

      for (int var7 = var3.length - 1; var7 >= 0; var7--) {
         if (var3[var7] != null) {
            systemMarksNames.insertElementAt(var3[var7], 0);
         }
      }

      int var8 = 0;

      while (var8 < systemMarksNames.size()) {
         String var9 = (String)systemMarksNames.elementAt(var8);
         Vector var6 = loadVector(URL.make("home:" + var9 + "/" + "Gamma.worldsmarks"));
         if (var6.size() != 0) {
            shortenNames(var9, var6);
            systemMarks.addElement(var6);
            var8++;
         } else {
            systemMarksNames.removeElementAt(var8);
         }
      }

      userMarks = loadVector(userMarksURL);
   }

   private static Vector loadVector(URL var0) {
      Vector var1 = null;

      try {
         Restorer var2 = new Restorer(var0);
         var1 = var2.restoreVector();
         var2.done();
      } catch (Exception var3) {
         if (var1 != null) {
            saveVector(var0, var1);
         } else {
            var1 = new Vector();
         }
      }

      return var1;
   }

   private static void saveMarks() {
      saveVector(userMarksURL, userMarks);
   }

   private static void saveVector(URL var0, Vector var1) {
      try {
         Saver var2 = new Saver(var0);
         var2.saveVector(var1);
         var2.done();
      } catch (Exception var3) {
      }
   }

   static void gotoBookmark(int var0) {
      TeleportAction.teleport(getBookmarkTarget(var0), null);
   }

   static int getBookmarkCount() {
      return userMarks.size();
   }

   private static BookmarkMenuItem getBookmark(int var0) {
      return (BookmarkMenuItem)userMarks.elementAt(var0);
   }

   static String getBookmarkName(int var0) {
      return getBookmark(var0).getLabel();
   }

   static String getBookmarkTarget(int var0) {
      return getBookmark(var0).getTarget();
   }

   void addBookmark(String var1, String var2) {
      BookmarkMenuItem var3 = new BookmarkMenuItem(var1, var2);
      this.menu.add(var3);
      userMarks.addElement(var3);
      saveMarks();
   }

   void removeBookmark(int var1) {
      userMarks.removeElementAt(var1);
      this.menu.remove(var1 + firstUserItem);
      saveMarks();
   }

   void changeBookmark(int var1, String var2, String var3) {
      BookmarkMenuItem var4 = getBookmark(var1);
      var4.setLabel(var2);
      var4.setTarget(var3);
      saveMarks();
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var2) {
         if (var1 instanceof LocationDialog) {
            LocationDialog var3 = (LocationDialog)var1;
            String var4 = var3.getLocationURL();
            if (var4.length() != 0) {
               TeleportAction.teleport(var4, null);
            }
         } else {
            BookmarkAddDialog var5 = (BookmarkAddDialog)var1;
            BookmarkEditDialog var6 = var5.getEditor();
            this.addBookmark(var6.getName(), var6.getTarget());
         }
      }
   }

   private static BookmarkMenuItem getHistory(int var0) {
      return (BookmarkMenuItem)historyItems.elementAt(var0);
   }

   private static BookmarkMenuItem getItemFromTarget(String var0, Vector var1) {
      for (int var2 = 0; var2 < var1.size(); var2++) {
         BookmarkMenuItem var3 = (BookmarkMenuItem)var1.elementAt(var2);
         if (var3.getTarget().equals(var0)) {
            return var3;
         }
      }

      return null;
   }

   private static BookmarkMenuItem getItemFromName(String var0, Vector var1) {
      for (int var2 = 0; var2 < var1.size(); var2++) {
         BookmarkMenuItem var3 = (BookmarkMenuItem)var1.elementAt(var2);
         if (var3.getLabel().equals(var0)) {
            return var3;
         }
      }

      return null;
   }

   private static String getWorldName(String var0) {
      int var1 = var0.toLowerCase().lastIndexOf(".world");
      int var2;
      return var1 == -1 || (var2 = var0.lastIndexOf(47, var1)) == -1 && (var2 = var0.lastIndexOf(58, var1)) == -1 ? null : var0.substring(var2 + 1, var1);
   }

   public static String getCurrentPackageName() {
      Pilot var0 = Pilot.getActive();
      if (var0 == null) {
         return null;
      }

      World var1 = var0.getWorld();
      if (var1 == null) {
         return null;
      }

      URL var2 = var1.getSourceURL();
      return var2 == null ? null : TeleportAction.getPackageNameOfWorld(var2);
   }

   private static String getCurrentURLName() {
      String var0 = "";
      Pilot var1 = Pilot.getActive();
      if (var1 != null) {
         World var2 = var1.getWorld();
         if (var2 != null) {
            URL var3 = var2.getSourceURL();
            if (var3 != null) {
               String var4 = getWorldName(var3.getAbsolute());
               if (var4 != null) {
                  var0 = var4;
               }
            }

            String var7 = var2.getName();
            if (var7 != null) {
               if (!var0.equals("")) {
                  var0 = var0 + " ";
               }

               var0 = var0 + var7;
            }

            Room var5 = var1.getRoom();
            if (var5 != null) {
               String var6 = var5.getName();
               if (var6 != null) {
                  if (!var0.equals("")) {
                     var0 = var0 + " ";
                  }

                  var0 = var0 + var6;
               }
            }
         }
      }

      return var0;
   }

   static String getCurrentPositionName() {
      return getCurrentPositionName(userMarks);
   }

   static String getCurrentPositionName(Vector var0) {
      String var1 = getCurrentPositionURL(false);
      int var3 = systemMarks.size();

      for (int var4 = 0; var4 < var3; var4++) {
         BookmarkMenuItem var2;
         if ((var2 = getItemFromTarget(var1, (Vector)systemMarks.elementAt(var4))) != null) {
            return (String)systemMarksNames.elementAt(var4) + " " + var2.getLabel();
         }
      }

      BookmarkMenuItem var7;
      if ((var7 = getItemFromTarget(var1, userMarks)) == null && (var7 = getItemFromTarget(var1, historyItems)) == null) {
         String var8 = getCurrentURLName();
         String var5 = var8;
         int var6 = 1;

         while (getItemFromName(var5, var0) != null) {
            var5 = var8 + "-" + ++var6;
         }

         return var5;
      } else {
         return var7.getLabel();
      }
   }

   static String getCurrentPositionURL(boolean var0) {
      Pilot var1 = Pilot.getActive();
      if (var1 == null) {
         return "";
      }

      String var2 = var1.getURL();
      if (var2 == null) {
         return "";
      }

      if (!var0) {
         int var3 = var2.indexOf("<dimension-");
         if (var3 < 0) {
            var3 = var2.indexOf("<>@");
         }

         int var4 = var2.indexOf(">@");
         if (var3 > 0 && var3 < var4) {
            var2 = var2.substring(0, var3) + var2.substring(var4 + 1);
         }
      }

      return var2;
   }

   public void teleportStatus(String var1, String var2) {
      this.teleporting = var1 != null && var1.length() == 0;
      if (var1 == null) {
         var2 = getCurrentPositionURL(true);
         if (var2.length() == 0) {
            return;
         }

         Menu var3 = this.getMenu();

         for (int var4 = 0; var4 < historyItems.size(); var4++) {
            if (getHistory(var4).getTarget().equals(var2)) {
               historyItems.removeElementAt(var4);
               this.historyMenu.remove(var4);
               break;
            }
         }

         BookmarkMenuItem var6 = new BookmarkMenuItem(getCurrentPositionName(historyItems), var2);
         historyItems.insertElementAt(var6, 0);
         this.historyMenu.insert(var6, 0);

         while (historyItems.size() > 10) {
            historyItems.removeElementAt(10);
            this.historyMenu.remove(10);
         }
      }
   }

   public void activate(Console var1, Container var2, Console var3) {
   }

   public void deactivate() {
      if (this.menu != null) {
         this.menu.removeAll();
      }

      this.menu = null;
      this.letsMenu = null;
      firstUserItem = 0;
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (this.menu != null) {
         if (var3 == this.addItem) {
            if (Pilot.getActive().getRoom().getAllowTeleport()) {
               new BookmarkAddDialog(Console.getFrame(), this);
            } else {
               Console.println(Console.message("no-teleport"));
            }
         } else if (var3 == this.deleteItem) {
            new BookmarkDeleteDialog(this);
         } else if (var3 == this.editItem) {
            new BookmarkListDialog(this);
         } else if (var3 == this.locationItem) {
            this.startLocationDialog = true;
         } else {
            if (!(var3 instanceof BookmarkMenuItem)) {
               return false;
            }

            TeleportAction.teleport(((BookmarkMenuItem)var3).getTarget(), null);
         }

         return true;
      } else {
         return false;
      }
   }

   public boolean handle(FrameEvent var1) {
      if (this.startLocationDialog) {
         this.startLocationDialog = false;
         String var2 = "";
         Pilot var3 = Pilot.getActive();
         if (var3 != null) {
            var2 = var3.getURL();
         }

         new LocationDialog(Console.getFrame(), this, Console.message("Change-Location"), var2);
      }

      return true;
   }

   static {
      Locale var0 = Locale.getDefault();
      System.out.println("System Locale is " + var0);
      String var1 = IniFile.gamma().getIniString("DEFAULTLANGUAGE", "");
      if (!var1.equals("")) {
         String var2 = null;
         String var3 = null;
         if (var1.length() >= 2) {
            var2 = var1.substring(0, 2);
         }

         if (var1.length() >= 5) {
            var3 = var1.substring(3, 5);
         }

         if (var2 != null && var3 != null) {
            Locale.setDefault(new Locale(var2, var3));
            var0 = Locale.getDefault();
            System.out.println("New Locale is " + var0);
         } else {
            System.out.println("ERROR: DEFAULTLANGUAGE mustbe in the form xx_XX");
         }
      }

      font = new Font(Console.message("MenuFont"), 0, 12);
      historyItems = new Vector();
      historyItems.addElement(new BookmarkMenuItem(Console.message("end-of-last"), "world:restart"));
      renamed = new Hashtable();
      renamed.put("lets", "Hang");
      renamed.put("worldschat", "WorldsCenter");
      renamed.put("polygram", "WorldsStore.com");
      renamed.put("stadium", "NY Yankees");
      renamed.put("bowie", "Bowie I");
      renamed.put("texas", "Texas");
      renamed.put("hanson", "Hanson I");
      excludes = new Vector();
      excludes.addElement("funhouse");
      excludes.addElement("chaos");
      sequence = new Vector();
      sequence.addElement(getFirstWorld().toLowerCase());
      sequence.addElement("avatargallery");
      sequence.addElement("dressingroom");
   }
}
