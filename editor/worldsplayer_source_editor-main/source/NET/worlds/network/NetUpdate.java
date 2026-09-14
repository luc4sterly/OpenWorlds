package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.console.Gamma;
import NET.worlds.console.InternetConnectionDialog;
import NET.worlds.console.LoginWizard;
import NET.worlds.console.Main;
import NET.worlds.console.Window;
import NET.worlds.console.WorldsMarkPart;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.RegKey;
import NET.worlds.core.RegKeyNotFoundException;
import NET.worlds.core.ServerTableManager;
import NET.worlds.core.Std;
import NET.worlds.scape.SendURLAction;
import NET.worlds.scape.World;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.text.MessageFormat;
import java.util.Date;
import java.util.Hashtable;
import java.util.StringTokenizer;
import java.util.Vector;

public class NetUpdate implements Runnable, RemoteFileConst {
   static final String VERSIONS = "upgrades.lst";
   static final String WORLDVERSIONS = "upgrades.lst";
   static final String SERVER = "upgradeServer";
   static final String RESTARTCMD = "run.exe";
   static final String WORLDCURVER = "\\ver.txt";
   static final String UPGRADER = ".\\bin\\gdkup.exe";
   static final String SCRIPTFILE = "updates.lst";
   static final String LANGUAGES = "languages.lst";
   static final int UPGRADETIMEOUT = IniFile.gamma().getIniInt("upgradeTimeout", 7);
   static int TESTAUTOUPGRADE = IniFile.gamma().getIniInt("testautoupgrade", 0);
   static final int TESTWORLDAUTOUPGRADE = IniFile.gamma().getIniInt("testworldautoupgrade", 0);
   private static String uServer = getUpgradeServerIniEntry(IniFile.gamma());
   private static String overrideServer;
   public static String overrideWorldServer = null;
   private static int _today;
   private static boolean beenCalled;
   static int gdkver;
   private boolean _force;
   private boolean forceWorldLoad;
   private String worldToUpdate;
   static int maxVers;
   private static final String INTERNAL = "internal";
   private static final String EXTERNAL = "external";
   private static int maxworld;
   private static Object updateLoadSyncer;

   static String getUpgradeServerIniEntry(IniFile var0) {
      return var0 == null ? "" : var0.getIniString("upgradeServer", "");
   }

   public static void setUpgradeServerURL(String var0) {
      if (overrideServer == null) {
         String var1 = uServer;
         int var2 = var1.length() - 1;
         if (var2 != -1) {
            if (var1.charAt(var2) == '/') {
               var2--;
            }

            var1 = var1.substring(var1.lastIndexOf(47, var2));
            uServer = var0 + var1;
            URL.setHttpServer(var0 + "/");
         }
      }
   }

   public static boolean isInternalVersion() {
      String var0 = null;
      Console var1 = Console.getActive();
      Galaxy var2 = null;
      if (var1 != null) {
         var2 = var1.getGalaxy();
      }

      if (var2 != null && var2.getOnline()) {
         var0 = var2.getChatname();
      } else {
         String var3 = IniFile.gamma().getIniString("lastchatname", "Fred");
         if (var3.startsWith("VIP ") || var3.startsWith("vip ")) {
            var0 = var3.substring(4);
         }
      }

      if (var0 != null) {
         String[] var5 = ServerTableManager.instance().getTable("employeeAccounts");
         if (var5 == null) {
            return false;
         }

         for (int var4 = 0; var4 < var5.length; var4++) {
            if (var5[var4].equals(var0)) {
               return true;
            }
         }
      }

      return false;
   }

   public static String getInfoURL() {
      return getInfoURL("");
   }

   public static String getInfoURL(String var0) {
      String var1 = getUpgradeServerURL();
      if (var1 == null) {
         return null;
      }

      String var2 = IniFile.override().getIniString("InfoPage", "index" + Console.message(".html"));
      if (Console.wasHttpNoSuchFile(var1 + var0 + var2)) {
         var2 = IniFile.override().getIniString("InfoPage", "index.html");
      }

      return var1 + var0 + var2;
   }

   public static String getUpgradeServerURL() {
      if (uServer.equals("")) {
         return null;
      }

      if (!uServer.endsWith("/")) {
         uServer = uServer + "/";
      }

      return uServer;
   }

   public static void showInfo() {
      showInfo("");
   }

   public static void showInfo(String var0) {
      new SendURLAction(getInfoURL(var0)).startBrowser();
   }

   private static boolean openPage(String var0, String var1) {
      DDEMLClass var2 = new DDEMLClass(var0, "WWW_Activate");
      boolean var3 = var2.Request("-1,0");
      var2.destroy();
      if (!var3) {
         return false;
      }

      var2 = new DDEMLClass(var0, "WWW_OpenURL");
      var3 = var2.Request("\"" + var1 + "\",,-1,0,,,");
      var2.destroy();
      return var3;
   }

   private NetUpdate(boolean var1) {
      this._force = var1;
   }

   private NetUpdate(String var1) {
      this.worldToUpdate = var1;
   }

   private NetUpdate(String var1, boolean var2) {
      this.worldToUpdate = var1;
      this.forceWorldLoad = var2;
   }

   static void notifyUser(String var0) {
      Console.println(var0);
   }

   static void warnUser(String var0) {
      IniFile.gamma().setIniString("RunUpgrade", "");
      notifyUser(var0);
   }

   private static boolean timeToUpdate(boolean var0) {
      while (Window.getMainWindow() == null || !LoginWizard.isFirstTimeDone() && !InternetConnectionDialog.isFirstTimeDone()) {
         try {
            Thread.sleep(1000L);
         } catch (InterruptedException var2) {
         }
      }

      if (!var0) {
         if (IniFile.gamma().getIniInt("lastUpgradeCheck", 0) + UPGRADETIMEOUT > _today) {
            return false;
         }

         if (!LoginWizard.isFirstTimeDone() && InternetConnectionDialog.choseSingleUserMode()) {
            return false;
         }
      }

      if (getUpgradeServerURL() == null) {
         Object[] var1 = new Object[]{new String("upgradeServer")};
         notifyUser(MessageFormat.format(Console.message("upgrade-check"), var1));
         return false;
      } else {
         return true;
      }
   }

   private static int getNextVers(String var0, int var1, int var2, int[] var3) {
      StringTokenizer var4 = null;

      try {
         var4 = new StringTokenizer(var0);
         if (!var4.hasMoreTokens()) {
            return -1;
         }

         int var5 = Integer.parseInt(var4.nextToken());
         if (var4.hasMoreTokens() && (var1 < 0 || var5 == var1) && (var1 >= 0 || var5 <= 0 && var5 >= var1)) {
            int var6 = -1;

            while (var4.hasMoreTokens()) {
               String var7 = var4.nextToken();
               int var8 = var7.indexOf(58);
               if (var8 != -1) {
                  int var9 = Integer.parseInt(var7.substring(var8 + 1));
                  if (var9 > 9999) {
                     var9 /= 10;
                  }

                  int var10 = gdkver <= 9999 ? gdkver : gdkver / 10;
                  int var11 = Std.getVersion();
                  var11 = var11 <= 9999 ? var11 : var11 / 10;
                  if (var9 > var11 || gdkver != 0 && var9 > var10) {
                     continue;
                  }

                  var7 = var7.substring(0, var8);
               }

               int var15 = 160000;
               int var16 = var7.indexOf(35);
               if (var16 != -1) {
                  var15 = Integer.parseInt(var7.substring(var16 + 1));
                  var7 = var7.substring(0, var16);
               }

               int var18 = Integer.parseInt(var7);
               int var12 = 0;
               if (var18 >= 999000000) {
                  var18 -= 999000000;
                  var12 = var18 / 100000 + 1;
                  var18 %= 100000;
                  if (var12 > var2) {
                     continue;
                  }
               }

               if (var18 <= maxVers && var18 > var6) {
                  var6 = var18;
                  var3[0] = var15;
               }
            }

            return var6;
         } else {
            return -1;
         }
      } catch (NumberFormatException var13) {
         return -1;
      }
   }

   private static String getVersions(URL var0, int var1, String var2, Vector var3, Vector var4, Vector var5, String var6, int var7) {
      CacheFile var8 = Cache.getFile(var0, true);
      var8.waitUntilLoaded();
      if (var8.error()) {
         return "Network error retrieving " + var0;
      }

      String var9 = var8.getLocalName();

      try {
         FileInputStream var10 = new FileInputStream(var9);
         DataInputStream var11 = new DataInputStream(var10);
         new Hashtable();
         int[] var14 = new int[1];

         String var13;
         while ((var13 = var11.readLine()) != null) {
            int var15 = getNextVers(var13, var1, var7, var14);
            if (var15 >= 0) {
               if (var3 != null) {
                  var3.addElement(new Integer(var15));
               }

               if (var1 < 0) {
                  var4.addElement(var2 + var15 + ".exe");
               } else {
                  var4.addElement(var2 + var1 + "-" + var15 + ".exe");
               }

               var5.addElement(new Integer(var14[0]));
               var1 = var15;
            }
         }

         var11.close();
         var10.close();
      } catch (FileNotFoundException var20) {
         return "system error re-opening " + var9 + ": " + var20;
      } catch (IOException var21) {
         return "System I/O error during upgrade processing";
      } finally {
         var8.close();
      }

      return null;
   }

   public static String getLanguages(URL var0, Vector var1, Vector var2, int[] var3) {
      if (Gamma.loadProgress != null) {
         Gamma.loadProgress.setMessage("Downloading language support information...");
         Gamma.loadProgress.advance();
      }

      CacheFile var4 = Cache.getFile(var0, true);
      var4.waitUntilLoaded();
      if (var4.error()) {
         return "Network error retrieving " + var0;
      }

      String var5 = var4.getLocalName();

      try {
         FileInputStream var6 = new FileInputStream(var5);
         DataInputStream var7 = new DataInputStream(var6);
         Object var9 = null;
         Object var10 = null;
         int var11 = 0;
         int var12 = 0;

         String var8;
         while ((var8 = var7.readLine()) != null) {
            if (var8.charAt(2) != '_' && var8.charAt(2) != ' ') {
               int var31 = var8.lastIndexOf(32);
               var9 = var8.substring(0, var31);
               var10 = null;
               int var14 = var8.length();

               try {
                  var11 = Integer.parseInt(var8.substring(var31 + 1, var14));
               } catch (NumberFormatException var22) {
                  System.out.println(var8.substring(var31, var14) + " is not quite a number");
               }

               var1.addElement(var9);
               var2.addElement(var10);
               var3[var12++] = var11;
            } else {
               var9 = var8.substring(0, 2);
               var10 = var8.substring(3, 5);
               int var13 = var8.length();

               try {
                  var11 = Integer.parseInt(var8.substring(6, var13));
               } catch (NumberFormatException var23) {
                  System.out.println(var8.substring(6, var13) + " is not quite a number");
               }

               var1.addElement(var9);
               var2.addElement(var10);
               var3[var12++] = var11;
            }
         }

         var7.close();
         var6.close();
      } catch (FileNotFoundException var24) {
         return "system error re-opening " + var5 + ": " + var24;
      } catch (IOException var25) {
         return "System I/O error during upgrade processing";
      } finally {
         var4.close();
      }

      return null;
   }

   private static int wantUpdate(Vector var0, Vector var1, boolean var2, String var3, String var4) {
      var3 = WorldsMarkPart.getExternalName(var3);
      if (!Gamma.shaperEnabled()) {
         return var0.size();
      }

      Vector var5 = new Vector();

      for (int var6 = 0; var6 < var1.size(); var6++) {
         var5.addElement("Rev " + var0.elementAt(var6));
      }

      return new UpgradeDialog(var5, var1, var2, var3, var4, true).confirmUpgradeFromList();
   }

   private static Vector needUpdate(int var0, Vector var1, Vector var2) {
      Vector var3 = new Vector();
      Vector var4 = new Vector();
      var1.removeAllElements();
      int var5 = Std.getVersion();
      String var6 = getVersions(URL.make(uServer + "upgrades.lst"), var5, "gdkup", var4, var3, var1, Std.getProductName(), TESTAUTOUPGRADE);
      if (var6 != null) {
         System.out.println(var6);
         return var3;
      }

      if (var3.size() == 0 || var0 == 0 && (var0 = wantUpdate(var4, var1, false, Std.getProductName(), "")) <= 0) {
         var0 = 0;
      }

      var3.setSize(var0);
      var1.setSize(var0);

      for (int var7 = 0; var7 < var0; var7++) {
         var2.addElement(var7 == var0 - 1 ? Std.getProductName() : null);
      }

      if (var0 > 0) {
         gdkver = (Integer)var4.elementAt(var0 - 1);
      }

      return var3;
   }

   public static int getCurrentVersionOfWorld(String var0, int var1) {
      if (var0.equals("")) {
         return var1;
      }

      try {
         DataInputStream var2 = new DataInputStream(new FileInputStream(var0 + "\\ver.txt"));
         String var3 = var2.readLine();
         int var4 = 0;
         if (var3.charAt(0) == '+') {
            var4 = var3.indexOf(32) + 1;
         }

         if (var3.regionMatches(true, var4, "internal", 0, "internal".length())) {
            var3 = var3.substring(var4 + "internal".length());
         } else if (var3.regionMatches(true, var4, "external", 0, "external".length())) {
            var3 = var3.substring(var4 + "external".length());
         }

         var1 = Integer.parseInt(var3.trim());
      } catch (FileNotFoundException var5) {
      } catch (IOException var6) {
      } catch (NumberFormatException var7) {
         System.out.println("Syntax error in " + var0 + "\\ver.txt");
      }

      return var1;
   }

   private boolean listWorldUpgrades(String var1, Vector var2, Vector var3, Vector var4) {
      if (var1.equals("")) {
         return true;
      }

      int var5 = getCurrentVersionOfWorld(var1, !this.forceWorldLoad && World.isCloistered() ? -1 : -2);
      Vector var6 = new Vector();
      Vector var7 = new Vector();
      Vector var8 = new Vector();
      String var9 = getVersions(
         URL.make(getUpgradeServerURL() + var1 + "/" + "upgrades.lst"), var5, var1 + "\\" + var1, var6, var7, var8, var1, TESTWORLDAUTOUPGRADE
      );
      if (var9 != null) {
         System.out.println(var9);
      } else {
         if (var7.size() == 0) {
            return false;
         }

         String var10 = WorldsMarkPart.getExternalName(var1) + " world";
         int var11 = wantUpdate(var6, var8, var5 < 0, "the " + var10, var1 + "/");
         if (var11 > 0) {
            var7.setSize(var11);
            var8.setSize(var11);

            for (int var12 = 0; var12 < var11; var12++) {
               var2.addElement(var7.elementAt(var12));
               var3.addElement(var8.elementAt(var12));
               var4.addElement(var12 == var11 - 1 ? var10 : null);
            }
         }
      }

      return true;
   }

   public static int maxInstalledWorlds() {
      if (maxworld == -1) {
         IniFile var0 = new IniFile("InstalledWorlds");
         maxworld = var0.getIniInt("MaxInstalledWorlds", 0);
         var0.setIniInt("MaxInstalledWorlds", maxworld);
      }

      return maxworld + 50;
   }

   public static void maxInstalledWorld(int var0) {
      if (maxworld == -1) {
         maxInstalledWorlds();
      }

      if (var0 > maxworld) {
         maxworld = var0;
         IniFile var1 = new IniFile("InstalledWorlds");
         var1.setIniInt("MaxInstalledWorlds", maxworld);
      }
   }

   public static Vector aboutWorlds() {
      Vector var0 = new Vector();
      IniFile var1 = new IniFile("InstalledWorlds");

      for (int var2 = 0; var2 < maxInstalledWorlds(); var2++) {
         String var3 = var1.getIniString("InstalledWorld" + var2, "").trim();
         int var4 = getCurrentVersionOfWorld(var3, -1);
         var3 = WorldsMarkPart.getExternalName(var3);
         if (var4 >= 0) {
            var0.addElement(var3 + " version " + var4);
            maxInstalledWorld(var2);
         }
      }

      return var0;
   }

   private static String getRestartCmd() {
      String var0 = "run.exe";
      return var0 + " world:restart";
   }

   private static boolean hasString(Vector var0, String var1) {
      int var2 = var0.size();

      do {
         var2--;
      } while (var2 >= 0 && !var1.equals((String)var0.elementAt(var2)));

      return var2 >= 0;
   }

   private static Vector getLinesFromScriptFile(String var0) {
      Vector var1 = new Vector();
      String var2 = IniFile.gamma().getIniString("RunUpgrade", "");
      if (!var2.equals("")) {
         DataInputStream var3 = null;

         try {
            var3 = new DataInputStream(new FileInputStream(var2));

            String var4;
            while ((var4 = var3.readLine()) != null) {
               if (var0 == null || !var4.equals(var0)) {
                  var1.addElement(var4.trim());
               }
            }
         } catch (IOException var14) {
         } finally {
            if (var3 != null) {
               try {
                  var3.close();
               } catch (IOException var13) {
               }
            }
         }
      }

      return var1;
   }

   private static void writeScriptFile(Vector var0, Vector var1, String var2) {
      String var3 = "updates.lst";
      int var4 = var1.size();

      for (int var5 = 0; var5 < var4; var5++) {
         String var6 = (String)var1.elementAt(var5);
         if (!hasString(var0, var6)) {
            FileInputStream var7 = null;
            boolean var8 = false;

            try {
               var7 = new FileInputStream(var6);
               byte[] var9 = new byte[4];
               int var10 = var7.read(var9);
               Debug.assert_(var10 == var9.length);
               var8 = var9[0] == 37 && var9[1] == 88 && var9[2] == 68 && var9[3] == 90;
            } catch (IOException var22) {
            } finally {
               if (var7 != null) {
                  try {
                     var7.close();
                  } catch (IOException var20) {
                  }
               }
            }

            if (var8) {
               String var27 = var6 + "-xdelta";
               new File(var6).renameTo(new File(var27));
               var0.addElement("./bin/xdelta patch " + var27 + " bin/xup.template " + var6);
            }

            var0.addElement(var6);
         }
      }

      if (var2 != null) {
         var0.addElement(var2);
      }

      IniFile.gamma().setIniString("RunUpgrade", "");

      try {
         PrintStream var25 = new PrintStream(new FileOutputStream(var3));
         var4 = var0.size();

         for (int var26 = 0; var26 < var4; var26++) {
            var25.println((String)var0.elementAt(var26));
         }

         var25.close();
         IniFile.gamma().setIniString("RunUpgrade", "updates.lst");
      } catch (IOException var21) {
         Console.println(Console.message("No-write-upgrade"));
      }
   }

   private static boolean loadPatchesAndUpdateScript(Vector var0, String var1, Vector var2, Vector var3, String var4) {
      Vector var5 = getLinesFromScriptFile(var1);
      int var6 = var0.size();

      while (--var6 >= 0) {
         String var7 = (String)var0.elementAt(var6);
         if (hasString(var5, var7)) {
            var0.removeElementAt(var6);
            var2.removeElementAt(var6);
            var3.removeElementAt(var6);
         }
      }

      Vector var20 = new Vector();
      Vector var21 = new Vector();
      Vector var8 = new Vector();
      int var9 = 0;
      int var10 = 0;
      boolean var11 = false;

      for (int var12 = 0; var12 < var2.size(); var12++) {
         String var13 = (String)var0.elementAt(var12);
         String var14 = (uServer + var13).replace('\\', '/');
         var20.addElement(URL.make(var14));
         if (var13.indexOf(45) < 0) {
            var11 = true;
         }

         var9 += (Integer)var2.elementAt(var12);
         if (var3.elementAt(var12) != null) {
            var10 += var9;
            var21.addElement(new Integer(var9));
            var9 = 0;
            var8.addElement(var3.elementAt(var12));
         }
      }

      Debug.assert_(var9 == 0);
      if (var10 == 0) {
         return true;
      }

      if (!Gamma.shaperEnabled()) {
         String var22 = var4 != null ? "the " + var4 + " world" : Std.getProductName();
         Vector var24 = new UpgradeDialog(var8, var21, var4 != null, var22, "", false).rejectedList();
         int var26 = var24.size();

         while (--var26 >= 0) {
            String var15 = (String)var24.elementAt(var26);
            int var16 = var3.size();

            while (--var16 >= 0) {
               String var17 = (String)var3.elementAt(var16);
               if (var17 != null && var15.equals(var17)) {
                  break;
               }
            }

            Debug.assert_(var16 >= 0);

            do {
               var10 -= (Integer)var2.elementAt(var16);
               var0.removeElementAt(var16);
               var20.removeElementAt(var16);
               var2.removeElementAt(var16);
               var16--;
            } while (var16 >= 0 && var3.elementAt(var16) == null);
         }
      }

      if (var10 == 0) {
         return false;
      }

      try {
         if (!new ProgressDialog(var10).loadFiles(var0, var20)) {
            return false;
         }
      } catch (IOException var19) {
         warnUser("Error creating upgrade script, upgrade failed");
         System.out.println("error creating scriptfile " + var19);
         return false;
      }

      writeScriptFile(var5, var0, var1);
      if (var11) {
         try {
            String var23 = isInternalVersion() ? "InternalGDK" : "3DCD";
            RegKey var25 = RegKey.getRootKey(2);
            RegKey var27 = new RegKey(var25, "SOFTWARE\\Worlds, Inc.\\" + var23, 0);
            String var28 = var27.getStringValue("InstallDir");
            String var29 = URL.homeUnalias("x");
            var29 = var29.substring(0, var29.length() - 2);
            var27.setStringValue("InstallDir", var29, false);
            var27.close();
         } catch (RegKeyNotFoundException var18) {
         }
      }

      return true;
   }

   private static boolean getUpdates(Vector var0, Vector var1, Vector var2, String var3) {
      String var4 = getRestartCmd();
      if (var4 == null) {
         notifyUser(Console.message("Automatic-restart"));
      }

      synchronized (updateLoadSyncer) {
         if (!loadPatchesAndUpdateScript(var0, var4, var1, var2, var3)) {
            return false;
         }
      }

      if (new NewVersionDialog().confirmRestart() && runUpdates("updates.lst")) {
         Main.end();
      }

      return true;
   }

   private static native boolean CreateProcSpecial(String var0, String var1);

   private static boolean runUpdates(String var0) {
      IniFile.gamma().setIniString("RunUpgrade", "");
      if (!CreateProcSpecial(".\\bin\\gdkup.exe", var0)) {
         System.out.println("error running .\\bin\\gdkup.exe");
         return false;
      } else {
         return true;
      }
   }

   public void run() {
      if (this.worldToUpdate != null) {
         this.asyncWorldCheck(this.worldToUpdate);
      } else {
         byte var1 = 0;
         if (TESTAUTOUPGRADE != 0 || TESTWORLDAUTOUPGRADE != 0) {
            this._force = true;
         }

         if (timeToUpdate(this._force)) {
            notifyUser(Console.message("Checking-network"));
            Vector var2 = new Vector();
            Vector var3 = new Vector();
            Vector var4 = needUpdate(var1, var2, var3);
            IniFile var5 = new IniFile("InstalledWorlds");

            for (int var6 = 0; var6 < maxInstalledWorlds(); var6++) {
               String var7 = var5.getIniString("InstalledWorld" + var6, "").trim();
               if (var7.length() > 0) {
                  this.listWorldUpgrades(var7, var4, var2, var3);
                  maxInstalledWorld(var6);
               }
            }

            if (var4.size() != 0 && getUpdates(var4, var2, var3, null)) {
               notifyUser(Console.message("finished-checking"));
            } else {
               notifyUser(Console.message("no-updates"));
            }

            IniFile.gamma().setIniInt("LastUpgradeCheck", _today);
         }

         beenCalled = false;
      }
   }

   public static void loadWorld(String var0, boolean var1) {
      if (var0.equals("chaos")) {
         var0 = "Chaos";
      }

      NetUpdate var2 = new NetUpdate(var0, var1);
      Thread var3 = new Thread(var2);
      var3.setDaemon(true);
      var3.start();
   }

   public void asyncWorldCheck(String var1) {
      if (getCurrentVersionOfWorld(var1, -1) < 0) {
         Vector var2 = new Vector();
         Vector var3 = new Vector();
         Vector var4 = new Vector();
         if (this.listWorldUpgrades(var1, var3, var2, var4)) {
            if (var3.size() != 0 && getUpdates(var3, var2, var4, var1)) {
               notifyUser(var1 + Console.message("download-finished"));
            }
         } else {
            notifyUser(var1 + Console.message("custom-world"));
         }
      }
   }

   private static synchronized boolean busy() {
      if (beenCalled) {
         return true;
      }

      beenCalled = true;
      return false;
   }

   public static boolean doUpdate(boolean var0) {
      if (busy()) {
         if (var0) {
            notifyUser(Console.message("Upgrade-progress"));
         }

         return false;
      } else {
         _today = (int)(new Date().getTime() / 86400000L);
         String var1 = IniFile.gamma().getIniString("RunUpgrade", "");
         if (!var0 && !var1.equals("")) {
            if (runUpdates(var1)) {
               return true;
            }

            beenCalled = false;
         } else {
            if (InternetConnectionDialog.choseSingleUserMode() && !var0) {
               return false;
            }

            if (!var0 && IniFile.gamma().getIniInt("CheckUpgrades", 1) == 0) {
               notifyUser(Console.message("Check-for-up-opt"));
               beenCalled = false;
            } else {
               Thread var2 = new Thread(new NetUpdate(var0));
               var2.setDaemon(true);
               var2.start();
            }
         }

         return false;
      }
   }

   static {
      IniFile var0 = IniFile.override();
      if (var0 != null) {
         overrideWorldServer = var0.getIniString("WorldServer", "");
         if (overrideWorldServer.equals("")) {
            if (Gamma.shaperEnabled()) {
               overrideWorldServer = "worldserver://test.3dcd.com";
            } else {
               overrideWorldServer = null;
            }
         }
      }

      String var1 = getUpgradeServerIniEntry(var0);
      if (!var1.equals("")) {
         overrideServer = var1;
         uServer = var1;
      }

      URL.setHttpServer(uServer.substring(0, uServer.lastIndexOf(47) + 1));
      beenCalled = false;
      gdkver = 0;
      maxVers = IniFile.gamma().getIniInt("maxupgradeversion", 999999999);
      maxworld = -1;
      updateLoadSyncer = new Object();
   }
}
