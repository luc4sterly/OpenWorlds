package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.ConnectionWaiter;
import NET.worlds.network.DNSLookup;
import NET.worlds.network.Galaxy;
import NET.worlds.network.InfiniteWaitException;
import NET.worlds.network.InvalidServerURLException;
import NET.worlds.network.NetworkObject;
import NET.worlds.network.OldPropertyList;
import NET.worlds.network.PacketTooLargeException;
import NET.worlds.network.PropertyList;
import NET.worlds.network.PropertySetCmd;
import NET.worlds.network.URL;
import NET.worlds.network.VarErrorException;
import NET.worlds.network.WorldServer;
import NET.worlds.network.net2Property;
import NET.worlds.scape.Attribute;
import NET.worlds.scape.BooleanPropertyEditor;
import NET.worlds.scape.Drone;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.FrameHandler;
import NET.worlds.scape.HoloDrone;
import NET.worlds.scape.HoloPilot;
import NET.worlds.scape.InventoryManager;
import NET.worlds.scape.LoadedURLSelf;
import NET.worlds.scape.NoSuchPropertyException;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.ProgressiveAdder;
import NET.worlds.scape.PropAdder;
import NET.worlds.scape.Property;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Room;
import NET.worlds.scape.Saver;
import NET.worlds.scape.StringPropertyEditor;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.TeleportStatus;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.URLPropertyEditor;
import NET.worlds.scape.URLSelf;
import NET.worlds.scape.URLSelfLoader;
import NET.worlds.scape.VectorProperty;
import NET.worlds.scape.WObject;
import NET.worlds.scape.WobLoaded;
import NET.worlds.scape.WobLoader;
import NET.worlds.scape.World;
import java.awt.CardLayout;
import java.awt.CheckboxMenuItem;
import java.awt.Container;
import java.awt.Event;
import java.awt.Font;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.MenuShortcut;
import java.awt.Panel;
import java.awt.PopupMenu;
import java.io.File;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Locale;
import java.util.MissingResourceException;
import java.util.ResourceBundle;
import java.util.Vector;

public abstract class Console extends SuperRoot implements URLSelf, MainCallback, NetworkObject, WobLoaded, DialogDisabled, ConnectionWaiter {
   private static Vector storedLines = new Vector();
   protected boolean disableShaperAccess = false;
   protected boolean disableSingleUserAccess = false;
   private static Console active;
   private Panel myCard;
   private static int nameCounter;
   private static Font font = new Font(message("MenuFont"), 0, 12);
   private URL targetAv;
   private static String activeTeleportURL;
   private static FrameEvent frameEvent;
   private static int freezeFrameEvents = 0;
   private String sleepMode = "";
   private int lastUserAction;
   private Vector parts = new Vector();
   private static MenuBar menuBar = new MenuBar();
   protected boolean enableMenu = false;
   protected MenuItem exitItem;
   private Hashtable menus = new Hashtable();
   protected static boolean autoFullVIP = IniFile.override().getIniInt("tieredVIP", 0) == 0;
   protected static boolean isRedLightWorld = IniFile.override().getIniString("ProductName", "").equalsIgnoreCase("RedLightWorld");
   protected static int vip = IniFile.gamma().getIniInt("VIP", 0) != 0 ? (autoFullVIP ? 2 : 1) : 0;
   protected static int spguest = IniFile.gamma().getIniInt("SPGUEST", 0) != 0 ? 2 : 0;
   private boolean canBroadcast = false;
   protected URL lastPilotRequested;
   public String pendingPilot = "";
   protected Vector callbacks = new Vector();
   private String defaultAction = "";
   protected String tempCarAvatar = "";
   protected static String defaultConsole = IniFile.gamma().getIniString("DEFAULTCONSOLE", "NET.worlds.console.DefaultConsole");
   private static Hashtable defConsoles = new Hashtable();
   private static Console defaultUnshared;
   private int refcnt = 0;
   protected Pilot pilotSoulTemplate;
   protected Drone droneSoulTemplate;
   protected Pilot pilot;
   public boolean targetValid = false;
   private String sleepStr = message("asleep");
   protected static GammaFrame frame = new GammaFrame();
   protected Galaxy galaxy = null;
   protected URL _galaxyURL;
   private Cursor cursor = new Cursor(URL.make("system:WAIT_CURSOR"));
   private Vector tempArea = new Vector();
   private static Object classCookie = new Object();

   public static synchronized void println(String var0) {
      if (active != null) {
         active.printLine(var0);
      } else {
         storedLines.addElement(var0);
      }
   }

   public static void printWhisper(String var0, String var1) {
      if (active != null) {
         active.printWhisperFrom(var0, var1);
      }
   }

   public static void printOwnWhisper(String var0, String var1) {
      if (active != null) {
         active.printWhisperTo(var0, var1);
      }
   }

   public static void startWhispering(String var0) {
      if (active != null) {
         active.startWhisperingTo(var0);
      }
   }

   public static synchronized String message(String var0) {
      Locale var1 = Locale.getDefault();

      try {
         String var2 = IniFile.override().getIniString("BundlePrefix", "MessagesBundle");
         ResourceBundle var3 = ResourceBundle.getBundle(var2, var1);
         String var4 = var3.getString(var0);
         if (var4.indexOf(123) == -1 && var4.indexOf(125) == -1) {
            var4 = Std.replaceStr(var4, "''", "'");
         }

         if (var4.lastIndexOf(".gif") > 0 || var4.lastIndexOf(".jpg") > 0 || var4.lastIndexOf(".bmp") > 0) {
            File var5 = new File(var4);
            if (!var5.exists()) {
               return var0;
            }
         }

         return var4;
      } catch (MissingResourceException var6) {
         System.out.println("MRE: " + var6.getClassName() + " " + var6.getKey());
         System.out.println("NO MESSAGE for " + var0);
         return var0;
      }
   }

   public static synchronized String parseUnicode(String var0) {
      if (var0 == null) {
         return var0;
      }

      int var1;
      while ((var1 = var0.indexOf("\\u")) != -1) {
         if (var1 >= var0.length() - 5) {
            return var0;
         }

         String var2 = var0.substring(var1 + 2, var1 + 6);
         char var3 = (char)Integer.parseInt(var2, 16);
         String var4 = var0.substring(0, var1) + var3 + var0.substring(var1 + 6);
         var0 = var4;
      }

      return var0;
   }

   public static synchronized Vector parseUnicode(Vector var0) {
      for (int var1 = 0; var1 < var0.size(); var1++) {
         String var2 = (String)var0.elementAt(var1);
         String var3 = parseUnicode(var2);
         var0.setElementAt(var3, var1);
      }

      return var0;
   }

   public static synchronized String parseExtended(String var0) {
      String var1 = "";

      for (int var2 = 0; var2 < var0.length(); var2++) {
         char var3 = var0.charAt(var2);
         if (var3 > 255) {
            char var4 = var3;

            try {
               var1 = var1 + "\\u" + Integer.toHexString(var4);
            } catch (NumberFormatException var6) {
               var1 = var1 + "?";
            }
         } else {
            var1 = var1 + var3;
         }
      }

      return var1;
   }

   public static boolean wasHttpNoSuchFile(String var0) {
      java.net.URL var1 = null;
      HttpURLConnection var2 = null;

      try {
         var1 = DNSLookup.lookup(new java.net.URL(var0));
         var2 = (HttpURLConnection) var1.openConnection();
      } catch (Exception var5) {
         return true;
      }

      try {
         return var2.getResponseCode() == 404;
      } catch (Exception var4) {
         return true;
      }
   }

   protected void printWhisperFrom(String var1, String var2) {
      if (!var2.startsWith("&|+")) {
         Object[] var3 = new Object[]{new String(var1), new String(var2)};
         println(MessageFormat.format(message("whispered"), var3));
      }
   }

   protected void printWhisperTo(String var1, String var2) {
      if (!var2.startsWith("&|+")) {
         Object[] var3 = new Object[]{new String(var1), new String(var2)};
         println(MessageFormat.format(message("You-whispered"), var3));
      }
   }

   protected void startWhisperingTo(String var1) {
      Object[] var2 = new Object[]{new String(var1)};
      println(MessageFormat.format(message("You-want-whisp"), var2));
   }

   public void printLine(String var1) {
      System.out.println(var1);
   }

   public boolean isShaperAccessDisabled() {
      return this.disableShaperAccess;
   }

   public boolean isSingleUserAccessDisabled() {
      return this.disableSingleUserAccess;
   }

   public static Console getActive() {
      return active;
   }

   public void inventoryChanged() {
   }

   public void forPilotOnlyActivate() {
      if (active != this) {
         this.myCard = new Panel();
         String var1 = "" + nameCounter++;
         Container var2 = frame.getConsoleTile();
         var2.add(var1, this.myCard);
         Console var3 = active;
         this.activate(this.myCard);
         ((CardLayout)var2.getLayout()).show(var2, var1);
         getFrame().validate();
         if (var3 != null) {
            var2.remove(var3.myCard);
            var3.myCard.removeAll();
         }
      }
   }

   protected void setEnableMenu(boolean var1) {
      this.enableMenu = var1;
      if (this == active) {
         var1 |= Gamma.shaper != null;
         boolean var2 = frame.getMenuBar() == menuBar && menuBar != null;
         if (var1 != var2) {
            frame.setMenuBar(var1 ? menuBar : null);
            frame.pack();
         }
      }
   }

   private static synchronized void setActive(Console var0) {
      active = var0;
      int var1 = storedLines.size();
      if (var1 > 0) {
         for (int var2 = 0; var2 < var1; var2++) {
            var0.printLine((String)storedLines.elementAt(var2));
         }

         storedLines.removeAllElements();
      }
   }

   protected void activate(Container var1) {
      Debug.dAssert(this.pilot != null);
      Console var2 = active;
      if (active != null) {
         active.deactivate();
      }

      setActive(this);
      Main.register(this);
      this.menus.clear();
      menuBar = new MenuBar();
      this.getMenu("File");
      if (Gamma.shaper != null) {
         Gamma.shaper.activate(this, var1, var2);
      }

      int var3 = this.parts.size();

      for (int var4 = 0; var4 < var3; var4++) {
         ((FramePart)this.parts.elementAt(var4)).activate(this, var1, var2);
      }

      this.exitItem = this.addMenuItem(message("Exit"), "File");
      if (activeTeleportURL != null) {
         teleportNotification("", activeTeleportURL);
      }

      this.cursor.activate();
   }

   protected void menuDone() {
      this.setEnableMenu(this.enableMenu);
   }

   protected void deactivate() {
      if (active == this) {
         setActive(null);
         Main.unregister(this);
         int var1 = this.parts.size();

         for (int var2 = 0; var2 < var1; var2++) {
            ((FramePart)this.parts.elementAt(var2)).deactivate();
         }

         if (Gamma.shaper != null) {
            Gamma.shaper.deactivate();
         }

         this.cursor.deactivate();
         frame.deactivate();
      }
   }

   public static void teleportNotification(String var0, String var1) {
      if (var0 != null && var0.length() == 0) {
         activeTeleportURL = var1;
      } else {
         activeTeleportURL = null;
      }

      if (active != null) {
         if (active instanceof TeleportStatus) {
            ((TeleportStatus)active).teleportStatus(var0, var1);
         }

         int var2 = active.parts.size();

         for (int var3 = 0; var3 < var2; var3++) {
            Object var4 = active.parts.elementAt(var3);
            if (var4 instanceof TeleportStatus) {
               ((TeleportStatus)var4).teleportStatus(var0, var1);
            }
         }
      }
   }

   public static void setFreezeFrameEvents(boolean var0) {
      if (var0) {
         freezeFrameEvents++;
      } else {
         freezeFrameEvents--;
         Debug.assert_(freezeFrameEvents >= 0);
      }
   }

   public void mainCallback() {
      if (frameEvent == null) {
         frameEvent = new FrameEvent(null, null);
      }

      if (freezeFrameEvents <= 0) {
         frameEvent.newFrameTime();
         frameEvent.source = this;
         this.generateFrameEvents(frameEvent);
         frameEvent.target = null;
         frameEvent.receiver = null;
         frameEvent.source = null;
      }
   }

   public void generateFrameEvents(FrameEvent var1) {
      World.generateFrameEvents(var1);
      int var2 = Std.getFastTime();
      if (Window.getAndResetUserActionCount() != 0) {
         this.setSleepMode(null);
         this.lastUserAction = var2;
      } else if (var2 > this.lastUserAction + 300000) {
         if (this.lastUserAction == 0) {
            this.lastUserAction = var2;
         } else {
            this.goToSleep();
         }
      }

      int var3 = this.parts.size();
      if (Main.profile != 0) {
         for (int var4 = 0; var4 < var3; var4++) {
            FramePart var5 = (FramePart)this.parts.elementAt(var4);
            int var6 = Std.getRealTime();
            long var7 = Runtime.getRuntime().freeMemory();
            var5.handle(var1);
            int var9 = Std.getRealTime() - var6;
            long var10 = var7 - Runtime.getRuntime().freeMemory();
            if (var9 > Main.profile) {
               System.out.println("Took " + var9 + "ms and " + var10 + " bytes to call framePart " + var5);
            }
         }
      } else {
         for (int var12 = 0; var12 < var3; var12++) {
            ((FramePart)this.parts.elementAt(var12)).handle(var1);
         }
      }

      ProgressiveAdder.get().handle(var1);
      if (this instanceof FrameHandler) {
         ((FrameHandler)this).handle(var1);
      }

      if (this.pilot != null) {
         this.pilot.generateFrameEvents(var1);
      }
   }

   public void addPart(FramePart var1) {
      this.parts.addElement(var1);
   }

   public Enumeration getParts() {
      return this.parts.elements();
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.exitItem) {
         return maybeQuit();
      }

      if (Gamma.shaper != null && Gamma.shaper.action(var1, var2)) {
         return true;
      }

      int var3 = this.parts.size();

      for (int var4 = 0; var4 < var3; var4++) {
         if (((FramePart)this.parts.elementAt(var4)).action(var1, var2)) {
            return true;
         }
      }

      return false;
   }

   public boolean handleEvent(Event var1) {
      return var1.id == 201 ? maybeQuit() : false;
   }

   public boolean okToQuit() {
      return true;
   }

   public static void quit() {
      if (Gamma.getShaper() != null) {
         Gamma.getShaper().maybeQuit();
      } else {
         GammaFrameState.saveBorder();
         Main.end();
      }
   }

   public static boolean maybeQuit() {
      Console var0 = getActive();
      if (var0 == null || var0.okToQuit()) {
         quit();
      }

      return true;
   }

   public static MenuBar getMenuBar() {
      return menuBar;
   }

   public Menu getMenu(String var1) {
      Menu var2 = (Menu)this.menus.get(var1);
      if (var2 == null) {
         if (!var1.equals("Help") && !var1.equals("Options") && !var1.equals("VIP")) {
            var2 = new Menu(var1);
            menuBar.add(var2);
         } else {
            var2 = new PopupMenu();
         }

         this.menus.put(var1, var2);
      }

      return var2;
   }

   public void addMenuItem(MenuItem var1, String var2) {
      this.getMenu(var2).add(var1);
      var1.setFont(font);
   }

   public MenuItem addMenuItem(String var1, String var2) {
      MenuItem var3 = new MenuItem(var1);
      this.getMenu(var2).add(var3);
      var3.setFont(font);
      return var3;
   }

   public MenuItem addMenuItem(String var1, String var2, int var3, boolean var4) {
      MenuItem var5 = new MenuItem(var1);
      MenuShortcut var6 = new MenuShortcut(var3, var4);
      var5.setShortcut(var6);
      this.getMenu(var2).add(var5);
      var5.setFont(font);
      return var5;
   }

   public CheckboxMenuItem addMenuCheckbox(String var1, String var2) {
      CheckboxMenuItem var3 = new CheckboxMenuItem(var1);
      this.getMenu(var2).add(var3);
      var3.setFont(font);
      return var3;
   }

   public void dialogDisable(boolean var1) {
      int var2 = this.parts.size();

      for (int var3 = 0; var3 < var2; var3++) {
         FramePart var4 = (FramePart)this.parts.elementAt(var3);
         if (var4 instanceof DialogDisabled) {
            ((DialogDisabled)var4).dialogDisable(var1);
         }
      }
   }

   public static final native String encrypt(String var0);

   public static final native String decrypt(String var0);

   public static String encode(String var0) {
      String var1 = "";
      if (var0 != null) {
         char[] var2 = encrypt(var0).toCharArray();

         for (int var3 = 0; var3 < var2.length; var3++) {
            String var4 = Integer.toHexString(var2[var3]);
            if (var4.length() == 1) {
               var4 = "0" + var4;
            }

            var1 = var1 + var4;
         }
      }

      return var1;
   }

   public static String decode(String var0) {
      try {
         int var1 = var0.length();
         if (var1 != 0 && (var1 & 1) == 0) {
            char[] var2 = new char[var1 / 2];
            byte var3 = 0;

            for (int var4 = 0; var4 < var2.length; var3 += 2) {
               var2[var4] = (char)Integer.parseInt(var0.substring(var3, var3 + 2), 16);
               var4++;
            }

            String var6 = decrypt(new String(var2));
            if (var6 != null && var6.length() != 0) {
               return var6;
            }
         }
      } catch (NumberFormatException var5) {
      }

      return null;
   }

   public static final native int getVolumeInfo();

   public boolean getVIPAvatars() {
      return vip > 0 || isRedLightWorld;
   }

   public boolean getVIP() {
      return vip > 0;
   }

   public void setVIP(boolean var1) {
      vip = var1 ? 1 : 0;
      this.checkCourtesyVIP();
      IniFile.gamma().setIniInt("VIP", vip);
      if (autoFullVIP && var1) {
         vip = 2;
      }
   }

   public boolean getFullVIP() {
      return vip == 2;
   }

   public void setFullVIP(boolean var1) {
      if (var1) {
         vip = 2;
      }

      IniFile.gamma().setIniInt("VIP", vip);
   }

   public boolean getSpecialGuest() {
      return spguest > 0;
   }

   public void setSpecialGuest(boolean var1) {
      if (spguest > 1 != var1) {
         spguest = var1 ? 1 : 0;
         IniFile.gamma().setIniInt("SPGUEST", spguest);
         spguest = spguest + spguest;
      }
   }

   public void checkCourtesyVIP() {
      int var1 = vip;
      if (vip < 1) {
         World var2 = this.getPilot().getWorld();
         vip = var2 != null && var2.isHomeWorld() && var2.getCourtesyVIP() ? 1 : 0;
      }

      if (vip != var1) {
         if (vip == 1) {
            println(message("You-VIP"));
         } else {
            println(message("You-no-VIP"));
         }
      }

      URL var3 = this.getDefaultAvatarURL();
      if (!var3.equals(this.getAvatarName())) {
         this.setAvatar(var3);
      }
   }

   public boolean broadcastEnabled() {
      return this.canBroadcast;
   }

   public void enableBroadcast(boolean var1) {
      this.canBroadcast = var1;
   }

   public abstract URL getAvatarName();

   public abstract void setChatname(String var1);

   public void serverStatus(WorldServer var1, VarErrorException var2) {
      System.out.println("status-- " + var1 + ": " + var2.getMsg());
   }

   public void property(OldPropertyList var1) {
      Debug.dAssert(false);
   }

   public void propertyUpdate(PropertyList var1) {
      Debug.dAssert(false);
   }

   public WorldServer getServer() {
      URL var1 = this.getGalaxyURL();
      if (var1 != null && this.galaxy != null) {
         try {
            return this.getGalaxy().getServer(var1);
         } catch (InvalidServerURLException var3) {
            println(">>" + var3.getMessage());
            return null;
         }
      } else {
         return null;
      }
   }

   public WorldServer getServerNew() {
      URL var1 = this.getGalaxyURL();
      if (var1 != null && this.galaxy != null) {
         try {
            return this.getGalaxy().getServer(var1);
         } catch (InvalidServerURLException var3) {
            println(">>" + var3.getMessage());
            return null;
         }
      } else {
         return null;
      }
   }

   public String getLongID() {
      return this.galaxy.getChatname();
   }

   public void register() {
   }

   public void galaxyDisconnected() {
      this.setChatname("");
      this.galaxy.waitForConnection(this);
   }

   public void reacquireServer(WorldServer var1) {
   }

   public void changeChannel(Galaxy var1, String var2, String var3) {
      this.pilot.changeChannel(var1, var2, var3);
   }

   protected void handleVAR_BITMAP(String var1) {
      if (var1.charAt(0) == 0) {
         var1 = var1.substring(2);
      }

      try {
         this.loadPilot(new URL(URL.getAvatar(), var1));
      } catch (MalformedURLException var3) {
         this.loadPilot(URL.make("error:\"" + var1 + '"'));
      }
   }

   protected void loadPilot(URL var1) {
      if (!var1.equals(this.lastPilotRequested)) {
         this.lastPilotRequested = var1;
         this.pendingPilot = var1.toString();
         Pilot.load(var1, this);
      }
   }

   public void wobLoaded(WobLoader var1, SuperRoot var2) {
      String var3 = null;
      if (var2 == null) {
         var3 = message("no-load-pilot");
         println(var3 + " " + var1.getWobName());
      } else if (!(var2 instanceof Pilot)) {
         var3 = message("not-pilot");
         println(var1.getWobName().toString() + " " + var3);
      } else {
         try {
            this.setPilot((Pilot)var2);
         } catch (IllegalPilotException var7) {
            var3 = var7.getMessage();
         }
      }

      if (this.pilot == null && var3 != null && !this.disableSingleUserAccess) {
         this.useDefaultPilot();
         var3 = null;
      }

      int var4 = this.callbacks.size();

      for (int var5 = 0; var5 < var4; var5++) {
         LoadedURLSelf var6 = (LoadedURLSelf)this.callbacks.elementAt(var5);
         if (var3 == null) {
            var6.loadedURLSelf(this, this.getSourceURL(), null);
         } else {
            this.decRef();
            var6.loadedURLSelf(null, this.getSourceURL(), var3);
         }
      }

      this.callbacks.removeAllElements();
   }

   public static URL getDefaultURL() {
      String var0 = IniFile.override().getIniString("DefaultAvatar", "avatar:pengo.mov");
      return URL.make(var0);
   }

   protected void useDefaultPilot() {
      try {
         this.setPilot(new HoloPilot(getDefaultURL()));
      } catch (IllegalPilotException var2) {
         Debug.dAssert(false);
      }
   }

   public abstract void setOnlineState(boolean var1, boolean var2);

   public void connectionCallback(Object var1, boolean var2) {
      if (var1 instanceof Galaxy) {
         if (var1 != this.galaxy) {
            return;
         }

         if (!var2) {
            return;
         }

         this.setAvatar(this.lastPilotRequested);
         this.displayAds();
      }
   }

   public void displayAds() {
      Pilot var1 = Pilot.getActive();
      if (var1 != null) {
         World var2 = var1.getWorld();
         if (var2 != null) {
            var2.setupAdBanner();
         }
      }
   }

   public void setDefaultAction(String var1) {
      this.defaultAction = var1;
   }

   public String getDefaultAction() {
      return this.defaultAction;
   }

   public URL getDefaultAvatarURL() {
      String var1 = getDefaultURL().toString();
      String var2 = IniFile.gamma().getIniString("AVATAR", var1);
      String var3 = IniFile.gamma().getIniString("VIPAVATAR", "");
      boolean var4 = var2.toLowerCase().endsWith(".rwg");
      if (var3.equals("")) {
         var3 = var2;
         if (var4) {
            IniFile.gamma().setIniString("VIPAVATAR", var3);
         }
      }

      if (this.tempCarAvatar != "") {
         var2 = this.tempCarAvatar;
      } else if (this.getVIPAvatars()) {
         var2 = var3;
      } else if (var4) {
         var2 = var1;
      }

      return URL.make(var2);
   }

   public Console() {
      this.add(this.cursor);
      this.galaxy = Galaxy.getAnonGalaxy();
      this.regWithGalaxy();
      this.setServerURL(null);
   }

   public Console(URL var1) {
      this.add(this.cursor);
      this.galaxy = Galaxy.getAnonGalaxy();
      this.regWithGalaxy();
      this.setServerURL(var1);
      this.templateInit();
   }

   public void loadInit() {
      this.templateInit();
      this.add(this.cursor);
   }

   public void addCursor(Cursor var1) {
      this.add(var1);
   }

   private void templateInit() {
      this.pilotSoulTemplate = new HoloPilot();
      this.droneSoulTemplate = new HoloDrone();
      this.add(this.pilotSoulTemplate);
      this.add(this.droneSoulTemplate);
   }

   public static void load(URL var0, LoadedURLSelf var1) {
      if (var0 != null && var0.endsWith(".console")) {
         new ConsoleLoader(var0, var1);
      } else {
         Console var2;
         if (var0 == null) {
            var2 = defaultUnshared;
         } else {
            var2 = (Console)defConsoles.get(var0);
         }

         if (var2 != null && var2.galaxy == null) {
            if (var2.getGalaxyURL() == null) {
               var2.galaxy = Galaxy.getAnonGalaxy();
            } else {
               try {
                  var2.galaxy = Galaxy.getGalaxy(var2.getGalaxyURL());
               } catch (InvalidServerURLException var5) {
                  System.out.println("Illegal ServerURL = " + var2.getGalaxyURL());
                  var2.galaxy = Galaxy.getAnonGalaxy();
                  var2.setServerURL(null);
               }
            }

            var2.regWithGalaxy();
            var2.regPilot();
         }

         Debug.dAssert(var2 == null || var2.galaxy != null);
         if (var2 == null) {
            try {
               Class var3 = Class.forName(defaultConsole);
               var2 = (Console)var3.newInstance();
            } catch (Exception var4) {
               System.out.println("Can't use class " + defaultConsole + ", using DefaultConsole instead.");
               var4.printStackTrace(System.out);
               var2 = new DefaultConsole();
            }

            Debug.dAssert(var2 != null);
            if (var2.galaxy == null) {
               var2.galaxy = Galaxy.getAnonGalaxy();
               var2.regWithGalaxy();
               var2.regPilot();
            }

            Debug.dAssert(var2.galaxy != null);
            var2.loadInit();
            var2.setServerURL(var0);
            if (var0 == null) {
               var2.setName("unshared");
               defaultUnshared = var2;
            } else {
               defConsoles.put(var2.getGalaxyURL(), var2);
            }
         }

         var2.incRef();
         var2.initPilot(var0, var1);
      }
   }

   protected void initPilot(URL var1, LoadedURLSelf var2) {
      this.loadPilot(this.getDefaultAvatarURL());
      if (this.pilot == null) {
         this.useDefaultPilot();
      }

      var2.loadedURLSelf(this, var1, null);
   }

   public void incRef() {
      this.refcnt++;
   }

   public void decRef() {
      if (--this.refcnt == 0) {
         if (this.galaxy != null) {
            this.unregWithGalaxy();
            this.unregPilot();
            this.galaxy.decWorldCount();
            Galaxy var1 = this.galaxy;
            this.galaxy = null;
         }

         this.pilot = null;
         URL var2 = this.getSourceURL();
         if (var2 != null) {
            if (var2.endsWith(".console")) {
               URLSelfLoader.unload(this);
            } else {
               defConsoles.remove(var2);
            }
         }
      }
   }

   public String toString() {
      return super.toString() + "[" + this.getSourceURL() + "]";
   }

   public Pilot getPilotSoulTemplate() {
      return this.pilotSoulTemplate;
   }

   public Drone getDroneSoulTemplate() {
      return this.droneSoulTemplate;
   }

   public Pilot getPilot() {
      return this.pilot;
   }

   public boolean isValidAv() {
      if (this.targetAv == null) {
         return false;
      }

      if (!InventoryManager.getInventoryManager().inventoryInitialized()) {
         return true;
      }

      String var1 = this.targetAv.getAbsolute();
      int var2 = var1.length();

      for (int var3 = 1; var3 < var2; var3++) {
         if (var1.charAt(var3 - 1) == '_') {
            char var4 = var1.charAt(var3);
            if (Character.isLowerCase(var4)) {
               StringBuffer var5 = new StringBuffer();
               var5.append(Character.toUpperCase(var4));

               while (++var3 < var2) {
                  char var6 = var1.charAt(var3);
                  if (!Character.isLowerCase(var6)) {
                     break;
                  }

                  var5.append(var6);
               }

               if (InventoryManager.getInventoryManager().checkInventoryFor(var5.toString()) <= 0) {
                  return false;
               }
            }
         }
      }

      return true;
   }

   public void resetAvatar() {
      this.setAvatar(this.targetAv);
   }

   public void setAvatar(URL var1) {
      if (var1 != null) {
         BlackBox.getInstance().submitEvent(new BBDroneBitmapCommand("@Pilot", var1.toString()));
         this.targetAv = var1;
         this.targetValid = true;
         if (var1.getAbsolute().length() > 220) {
            println(message("av-too-complex"));
            var1 = URL.make("avatar:holden.mov");
            this.targetValid = false;
         } else if (!this.isValidAv()) {
            println(message("av-has-inventory"));
            var1 = URL.make("avatar:holden.mov");
            this.targetValid = false;
         }

         this.loadPilot(var1);
         WorldServer var2 = this.getServerNew();
         if (var2 != null) {
            Debug.dAssert(var2.getVersion() >= 18);
            PropertyList var3 = new PropertyList();
            var3.addProperty(new net2Property(5, 64, 1, var1.getAbsolute()));

            try {
               var2.sendNetworkMsg(new PropertySetCmd(var3));
            } catch (PacketTooLargeException var5) {
               Debug.dAssert(var1.getAbsolute().length() < 220);
               Debug.dAssert(false);
            } catch (InfiniteWaitException var6) {
            }
         }
      }
   }

   public static void wake() {
      if (active != null) {
         active.setSleepMode(null);
      }
   }

   public void goToSleep() {
      this.setSleepMode(this.sleepStr);
      Window.getAndResetUserActionCount();
   }

   public boolean isSleeping() {
      return !this.sleepMode.equals("");
   }

   protected void setSleepMode(String var1) {
      if (var1 == null) {
         var1 = "";
         this.lastUserAction = Std.getFastTime();
      }

      if (this.pilot != null) {
         this.pilot.setSleepMode(var1);
      }

      if (!var1.equals(this.sleepMode)) {
         WorldServer var2 = this.getServerNew();
         if (var2 != null) {
            PropertyList var3 = new PropertyList();
            var3.addProperty(new net2Property(23, 64, 1, var1));

            try {
               var2.sendNetworkMsg(new PropertySetCmd(var3));
            } catch (PacketTooLargeException var5) {
               Debug.dAssert(false);
            } catch (InfiniteWaitException var6) {
            }

            this.sleepMode = var1;
         }
      }
   }

   public void setPilot(Pilot var1) throws IllegalPilotException {
      Debug.dAssert(var1 != null);
      Room var2 = null;
      if (this.pilot != null) {
         var2 = this.pilot.getRoom();
         this.unregPilot();
      }

      this.pilot = var1;
      this.pilot.getSharer().createDynamicFromNet();
      this.pilot.setConsole(this);
      this.regPilot();
      if (active == this) {
         Pilot.changeActiveRoom(var2);
      }

      this.pilot.setSleepMode(this.sleepMode);
      if (this instanceof DefaultConsole) {
         ((DefaultConsole)this).resetCamera();
      }
   }

   public static GammaFrame getFrame() {
      return frame;
   }

   public Galaxy getGalaxy() {
      Debug.dAssert(this.galaxy != null);
      return this.galaxy;
   }

   public URL getGalaxyURL() {
      return this._galaxyURL;
   }

   public void setServerURL(URL var1) {
      try {
         if (var1 != null) {
            this._galaxyURL = URL.make("worldserver://" + getServerHost(var1) + "/");
         }
      } catch (InvalidServerURLException var5) {
         println(">>" + var5.getMessage());
         Debug.dAssert(false);
         this._galaxyURL = null;
      }

      Galaxy var2 = this.galaxy;
      this.unregWithGalaxy();
      this.unregPilot();
      if (this._galaxyURL != null) {
         try {
            this.galaxy = Galaxy.getGalaxy(this._galaxyURL);
         } catch (InvalidServerURLException var4) {
            println(">>" + var4.getMessage());
            this.galaxy = Galaxy.getAnonGalaxy();
         }
      } else {
         this.galaxy = Galaxy.getAnonGalaxy();
      }

      Debug.dAssert(this.galaxy != null);
      this.regWithGalaxy();
      this.regPilot();
      if (var2 != null) {
         var2.decWorldCount();
         if (var2 != this.galaxy) {
            var2.forceObjectRereg();
         }
      }
   }

   private void regWithGalaxy() {
      Debug.dAssert(this.galaxy != null);
      this.galaxy.addConsole(this);
      this.galaxy.waitForConnection(this);
   }

   private void unregWithGalaxy() {
      Debug.dAssert(this.galaxy != null);
      this.galaxy.delConsole(this);
   }

   protected void regPilot() {
      if (this.pilot != null) {
         this.pilot.getSharer().adjustShare();
      }
   }

   public static String getServerHost(URL var0) throws InvalidServerURLException {
      String var1 = var0.unalias();
      int var2 = var1.length();
      if (var2 > 14 && var1.startsWith("worldserver://")) {
         if (var1.charAt(var2 - 1) == '/') {
            var2--;
         }

         var1 = var1.substring(14, var2);
         if (var1.equals("209.67.68.214:6650")) {
            var1 = "www.3dcd.com:6650";
         }

         return var1;
      } else {
         throw new InvalidServerURLException("Bad worldserver:// URL format");
      }
   }

   public static URL makeServerURL(String var0) {
      Debug.assert_(var0 != null && var0.length() > 0);
      return URL.make("worldserver://" + var0 + "/");
   }

   protected void unregPilot() {
      if (this.pilot != null) {
         this.pilot.getSharer().adjustShare();
      }
   }

   public Cursor getCursor() {
      return this.cursor;
   }

   public String getScriptServer() {
      String var1 = "Fred";
      String var2 = IniFile.override().getIniString("ScriptServer", var1);
      if (!var2.equals(var1)) {
         return new String(var2);
      }

      WorldServer var3 = this.getServerNew();
      if (var3 != null) {
         String var4 = var3.getScriptServer();
         if (var4 != null) {
            return new String(var4);
         }
      }

      return new String("http://www-dynamic.us.worlds.net/cgi-bin/");
   }

   public String getSmtpServer() {
      WorldServer var1 = this.getServerNew();
      if (var1 != null) {
         String var2 = var1.getSmtpServer();
         if (var2 != null) {
            return var2;
         }
      }

      return "www.3dcd.com:25";
   }

   public String getMailDomain() {
      WorldServer var1 = this.getServerNew();
      if (var1 != null) {
         String var2 = var1.getMailDomain();
         if (var2 != null) {
            return var2;
         }
      }

      return "3dcd.com";
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Server URL").allowSetNull(), null);
            } else if (var3 == 1) {
               var5 = this.getGalaxyURL();
            } else if (var3 == 2) {
               if (var4 == null) {
                  this.setServerURL(null);
               } else {
                  URL var7 = (URL)var4;
                  if (var7 != null && !var7.unalias().startsWith("worldserver:")) {
                     println(message("server-URL"));
                  } else {
                     this.setServerURL(var7);
                  }
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Enable Menu Bar"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.enableMenu);
            } else if (var3 == 2) {
               this.setEnableMenu((Boolean)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Disable Shaper Access (irreversible!)"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.disableShaperAccess);
            } else if (var3 == 2) {
               this.disableShaperAccess = (Boolean)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Disable Single-user Access"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.disableSingleUserAccess);
            } else if (var3 == 2) {
               this.disableSingleUserAccess = (Boolean)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Pilot Soul Template");
            } else if (var3 == 1) {
               var5 = this.pilotSoulTemplate;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Drone Soul Template");
            } else if (var3 == 1) {
               var5 = this.droneSoulTemplate;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Cursor");
            } else if (var3 == 1) {
               var5 = this.getCursor();
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Temporary Area"));
            } else if (var3 == 1) {
               var5 = this.tempArea.clone();
            } else if (var3 == 4) {
               this.tempArea.removeElement(var4);
               ((SuperRoot)var4).detach();
            } else if (var3 == 3) {
               this.tempArea.addElement(var4);
               this.add((SuperRoot)var4);
               if (var4 instanceof Console) {
                  Console var6 = (Console)var4;
                  if (var6.pilotSoulTemplate == null) {
                     var6.loadInit();
                  }
               }
            } else if (var3 == 5 && var4 instanceof SuperRoot && !(var4 instanceof Room)) {
               var5 = var4;
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Default Action"));
            } else if (var3 == 1) {
               var5 = this.getDefaultAction();
            } else if (var3 == 2) {
               this.setDefaultAction((String)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 9, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(4, classCookie);
      super.saveState(var1);
      URL.save(var1, this.getGalaxyURL());
      var1.saveBoolean(this.enableMenu);
      var1.saveBoolean(this.disableShaperAccess);
      var1.saveString(this.defaultAction);
      var1.save(this.pilotSoulTemplate);
      var1.save(this.droneSoulTemplate);
      var1.save(this.cursor);
   }

   private static URL restoreOldURL(Restorer var0) throws IOException {
      String var1 = var0.restoreString();
      return var1 != null && !var1.equals("UNSHARED") ? makeServerURL(var1) : null;
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
         case 1:
            WObject var3 = new WObject();
            var3.restoreState(var1);
            this.setName(var3.getName());
            this.templateInit();
            Enumeration var4 = var3.getAttributes();

            while (var4.hasMoreElements()) {
               Attribute var5 = (Attribute)var4.nextElement();
               var5.setAttrID(var5.getForwardAttrID());
            }

            Pilot.copySoul(var3, this.pilotSoulTemplate);
            this.setServerURL(restoreOldURL(var1));
            this.enableMenu = var1.restoreBoolean();
            this.disableShaperAccess = var1.restoreBoolean();
            if (var2 == 1) {
               this.cursor = (Cursor)var1.restore();
            }
            break;
         case 2:
            super.restoreState(var1);
            this.setServerURL(restoreOldURL(var1));
            this.enableMenu = var1.restoreBoolean();
            this.disableShaperAccess = var1.restoreBoolean();
            this.pilotSoulTemplate = (Pilot)var1.restore();
            this.add(this.pilotSoulTemplate);
            this.droneSoulTemplate = (Drone)var1.restore();
            this.add(this.droneSoulTemplate);
            this.cursor = (Cursor)var1.restore();
            break;
         case 3:
            super.restoreState(var1);
            this.setServerURL(restoreOldURL(var1));
            this.enableMenu = var1.restoreBoolean();
            this.disableShaperAccess = var1.restoreBoolean();
            this.defaultAction = var1.restoreString();
            this.pilotSoulTemplate = (Pilot)var1.restore();
            this.add(this.pilotSoulTemplate);
            this.droneSoulTemplate = (Drone)var1.restore();
            this.add(this.droneSoulTemplate);
            this.cursor = (Cursor)var1.restore();
            break;
         case 4:
            super.restoreState(var1);
            this.setServerURL(URL.restore(var1));
            this.enableMenu = var1.restoreBoolean();
            this.disableShaperAccess = var1.restoreBoolean();
            this.defaultAction = var1.restoreString();
            this.pilotSoulTemplate = (Pilot)var1.restore();
            this.add(this.pilotSoulTemplate);
            this.droneSoulTemplate = (Drone)var1.restore();
            this.add(this.droneSoulTemplate);
            this.cursor = (Cursor)var1.restore();
            break;
         default:
            throw new TooNewException();
      }

      this.add(this.cursor);
   }

   static {
      WhisperManager.whisperManager().setParent(frame);
   }
}
