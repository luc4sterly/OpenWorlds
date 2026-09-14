package NET.worlds.scape;

import NET.worlds.console.AdBanner;
import NET.worlds.console.Console;
import NET.worlds.console.Gamma;
import NET.worlds.console.Main;
import NET.worlds.console.WorldsMarkPart;
import NET.worlds.core.Debug;
import NET.worlds.core.Hashtable;
import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.Galaxy;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Vector;

public class World extends SuperRoot implements URLSelf, LoadedURLSelf, IncrementalRestorer {
   static WorldRedirector redir = new WorldRedirector(URL.make(Gamma.getHome() + "redir.txt"));
   private static boolean cloistered = false;
   private static boolean cloisteredSet = false;
   private String adCubeBaseURL = null;
   private boolean hasClickableAdCube = false;
   private boolean adCubeFormatIsGif = false;
   private String defaultAdCubeURL = IniFile.override().getIniString("defaultAdCubeURL", "http://www.worlds.com/");
   private boolean hasBeenEdited = false;
   private String defaultRoomName = "";
   protected Hashtable roomHash = new Hashtable();
   protected Vector roomList = new Vector();
   Vector eventHandlers;
   private static boolean[] didTouch = new boolean[1];
   private static int lastGeneratedFrameEvents;
   private int renderStamp;
   private int timeoutAge = 15000;
   private int nextRoomCheck = 0;
   private static Hashtable worldHash = new Hashtable();
   private static Vector worldList = new Vector();
   private boolean registerable = false;
   private static Object classCookie = new Object();
   private static final int INIT = 0;
   private static final int RESTOREROOMS = 1;
   private static final int ADDROOMS = 2;
   private static final int LOADCONSOLE = 3;
   private static final int DONE = -1;
   private Enumeration tmpenum;
   protected Console console = null;
   String loadErr;
   static URL defaultServerURL = URL.make("worldserver://www.3dcd.com:6650/");
   private URL worldServerURL;
   private URL desiredWorldServerURL = defaultServerURL;
   private boolean isCourtesyVIP;
   private boolean isForceHuman = false;
   private boolean hasAdBanner = false;
   private int adBannerWidth = 474;
   private int adBannerHeight = 65;
   private String adBannerURL = "$SCRIPTSERVERgetad.pl?s=$SERIALNUM";
   private static AdBanner theAdBanner = null;
   private boolean isMultiuser;

   World() {
   }

   public World getWorld() {
      return this;
   }

   public static void load(URL var0, LoadedURLSelf var1, boolean var2) {
      if (Gamma.loadProgress != null) {
         Gamma.loadProgress.setMessage("Loading world files...");
         Gamma.loadProgress.advance();
      }

      if (var0.toString().indexOf("UserHomeWorld") != -1) {
         String var3 = WorldsMarkPart.getFirstSystemMarkURL();
         if (var3 != null) {
            int var4 = var3.indexOf("#");
            if (var4 != -1) {
               var3 = var3.substring(0, var4);
            }

            var0 = URL.make(var3);
         }
      }

      File var5 = new File(var0.unalias());
      if (!var5.exists()) {
         var0 = redir.get(var0);
      }

      if (isProscribed(var0, var2)) {
         var1.loadedURLSelf(null, var0, "Can't autoload WorldsStore");
      } else {
         World var6 = (World)worldHash.get(var0);
         if (var6 != null) {
            var6.incRef();
            var1.loadedURLSelf(var6, var0, null);
         } else {
            URLSelfLoader.load(var0, var1, true);
         }
      }
   }

   public static void load(URL var0, LoadedURLSelf var1) {
      load(var0, var1, false);
   }

   public static boolean isCloistered() {
      if (!cloisteredSet) {
         URL var0 = URL.make("home:" + WorldsMarkPart.getFirstWorld());
         cloistered = new File(var0.unalias() + "/cloistered").exists();
         cloisteredSet = true;
      }

      return cloistered;
   }

   public static URL getHomeStore() {
      URL var0 = URL.make("home:" + WorldsMarkPart.getFirstWorld() + "/store.inf");
      URL var1 = URL.make("home:PolyGram/polygramdlb.world");
      File var2 = new File(var0.unalias());
      if (!var2.exists() || !var2.isFile()) {
         var2 = new File(URL.make("home:PolyGram/store.inf").unalias());
         if (!var2.exists() || !var2.isFile()) {
            return var1;
         }
      }

      try {
         BufferedReader var3 = new BufferedReader(new FileReader(var2));
         String var4 = var3.readLine();
         var3.close();
         var1 = new URL(var4);
      } catch (IOException var5) {
      }

      return var1;
   }

   public static boolean isWorldsStoreProscribed() {
      return isCloistered() && IniFile.gamma().getIniInt("WorldsStoreProscribed", 1) != 0;
   }

   public static boolean isProscribed(URL var0, boolean var1) {
      return !var1 && !WorldValidator.allow(var0.toString());
   }

   public boolean isHomeWorld() {
      URL var1 = this.getSourceURL();
      if (var1 != null) {
         URL var2 = URL.make("home:" + WorldsMarkPart.getFirstWorld());
         if (var1.unalias().startsWith(var2.unalias() + "/")) {
            return true;
         }
      }

      return false;
   }

   public void setEdited(boolean var1) {
      if (var1 != this.hasBeenEdited) {
         this.hasBeenEdited = var1;
         worldListChanged();
      }
   }

   public void markEdited() {
      this.setEdited(true);
   }

   public String getAdCubeBaseURL() {
      if (this.adCubeBaseURL == null) {
         String var1 = this.getSourceURL().toString();
         if (var1.lastIndexOf("/") == -1) {
            return "ads/ad";
         }

         var1 = var1.substring(0, var1.lastIndexOf("/"));
         WorldServer var2 = Pilot.getActive().getServer();
         if (var2 != null && var2.getGalaxy().getOnline()) {
            String var3 = NetUpdate.getUpgradeServerURL();
            if (var3 != null) {
               int var4 = var1.lastIndexOf("/");
               int var5 = var1.lastIndexOf(":");
               var4 = var4 > var5 ? var4 : var5;
               if (var4 > -1) {
                  var1 = var1.substring(var4 + 1);
               }

               return var3 + var1 + "/ads/ad";
            }
         }

         return var1 + "/ads/ad";
      } else {
         return this.adCubeBaseURL;
      }
   }

   public void setAdCubeBaseURL(String var1) {
      this.adCubeBaseURL = new String(var1);
   }

   public boolean getHasClickableAdCube() {
      return this.hasClickableAdCube;
   }

   public void setHasClickableAdCube(boolean var1) {
      this.hasClickableAdCube = var1;
   }

   public boolean getAdCubeFormatIsGif() {
      return this.adCubeFormatIsGif;
   }

   public void setAdCubeFormatIsGif(boolean var1) {
      this.adCubeFormatIsGif = var1;
   }

   public String getDefaultAdCubeURL() {
      return this.defaultAdCubeURL;
   }

   public void setDefaultAdCubeURL(String var1) {
      this.defaultAdCubeURL = new String(var1);
   }

   public boolean getEdited() {
      return this.hasBeenEdited;
   }

   private static void worldListChanged() {
      if (Gamma.getShaper() != null) {
         Gamma.getShaper().worldListChange();
      }
   }

   public void getChildren(DeepEnumeration var1) {
      var1.addChildEnumeration(this.getRooms());
      if (this.eventHandlers != null) {
         var1.addChildVector(this.eventHandlers);
      }
   }

   public Room getRoom(String var1) {
      if (var1.indexOf("UserHomeRoom") != -1) {
         var1 = this.getDefaultRoomName();
      }

      return (Room)this.roomHash.get(var1);
   }

   public String getDefaultRoomName() {
      if (this.getRoom(this.defaultRoomName) == null) {
         if (this.roomList.isEmpty()) {
            this.defaultRoomName = "";
         } else {
            this.defaultRoomName = ((Room)this.roomList.elementAt(0)).getName();
         }
      }

      return this.defaultRoomName;
   }

   public void setDefaultRoomName(String var1) {
      this.defaultRoomName = var1;
   }

   public void addRoom(Room var1) {
      String var2 = var1.getName();
      int var3 = 1;

      while (this.getRoom(var2) != null) {
         var2 = "Room" + var3++;
      }

      var1.setName(var2);
      this.roomHash.put(var2, var1);
      this.roomList.addElement(var1);
      this.add(var1);
      URL var4 = this.getSourceURL();
      if (var4 != null && worldHash.containsKey(var4)) {
         var1.register();
      }
   }

   public void renameRoom(String var1, String var2, Room var3) {
      if (var1 != null) {
         Debug.assert_(this.roomHash.get(var1) == var3);
         this.roomHash.remove(var1);
      } else {
         Debug.assert_(!this.roomList.removeElement(var3));
         this.roomList.addElement(var3);
      }

      Debug.assert_(var2 != null);
      Debug.assert_(var3.getName().equals(var2));
      this.roomHash.put(var2, var3);
   }

   public void removeRoom(Room var1) {
      this.roomHash.remove(this.roomHash.getKey(var1));
      this.roomList.removeElement(var1);
   }

   public Enumeration getRooms() {
      return this.roomList.elements();
   }

   public static Room findRoomByName(String var0) {
      Enumeration var1 = worldList.elements();

      while (var1.hasMoreElements()) {
         World var2 = (World)var1.nextElement();
         Enumeration var3 = var2.getRooms();

         while (var3.hasMoreElements()) {
            Room var4 = (Room)var3.nextElement();
            if (var4.toString().equals(var0)) {
               return var4;
            }
         }
      }

      return null;
   }

   public void invokeActions(String var1) {
      Enumeration var2 = this.getDeepOwned();

      while (var2.hasMoreElements()) {
         Object var3 = var2.nextElement();
         if (var3 instanceof WObject) {
            ((WObject)var3).doAction(var1, null);
         }
      }
   }

   public boolean deliver(FrameEvent var1) {
      if (this.eventHandlers != null) {
         if (Main.profile != 0) {
            int var2 = this.eventHandlers.size();

            while (--var2 >= 0) {
               FrameHandler var3 = (FrameHandler)this.eventHandlers.elementAt(var2);
               int var4 = Std.getRealTime();
               long var5 = Runtime.getRuntime().freeMemory();
               var1.retargetAndDeliver(var3, null);
               int var7 = Std.getRealTime() - var4;
               long var8 = Runtime.getRuntime().freeMemory() - var5;
               if (var7 > Main.profile) {
                  System.out.println("Took " + var7 + "ms and " + var8 + " bytes to call world eventHandler " + var3);
               }
            }
         } else {
            int var10 = this.eventHandlers.size();

            while (--var10 >= 0) {
               var1.retargetAndDeliver((FrameHandler)this.eventHandlers.elementAt(var10), null);
            }
         }
      }

      return true;
   }

   public static void generateFrameEvents(FrameEvent var0) {
      didTouch[0] = false;
      int var1 = Std.getFastTime();
      int var2 = worldList.size();

      while (--var2 >= 0) {
         World var3 = (World)worldList.elementAt(var2);
         if (!var3.discardIfOld(didTouch)) {
            var3.deliver(var0);
         }
      }

      if (Pilot.getActiveWorld() != null) {
         lastGeneratedFrameEvents = var1;
      }
   }

   public Enumeration getHandlers() {
      return this.eventHandlers == null ? new Vector().elements() : this.eventHandlers.elements();
   }

   public boolean hasHandler(SuperRoot var1) {
      return this.eventHandlers != null && this.eventHandlers.indexOf(var1) != -1;
   }

   public World addHandler(SuperRoot var1) {
      if (!(var1 instanceof FrameHandler)) {
         Object[] var2 = new Object[]{new String(var1.getName())};
         Console.println(MessageFormat.format(Console.message("FrameHandler"), var2));
         return this;
      }

      if (this.eventHandlers == null) {
         this.eventHandlers = new Vector();
      }

      this.eventHandlers.addElement(var1);
      this.add(var1);
      return this;
   }

   public void removeHandler(SuperRoot var1) {
      if (this.eventHandlers.contains(var1)) {
         var1.detach();
         this.eventHandlers.removeElement(var1);
         if (this.eventHandlers.size() == 0) {
            this.eventHandlers = null;
         }
      }
   }

   public void incRef() {
      this.renderStamp = Std.getFastTime();
   }

   public void decRef() {
   }

   private void touchAdjacentRooms(boolean[] var1) {
      if (!var1[0]) {
         var1[0] = true;
         Room var2 = Pilot.getActiveRoom();
         if (var2 != null) {
            Vector var3 = var2.getOutgoingPortals();
            int var4 = var3.size();

            while (--var4 >= 0) {
               Room var5 = ((Portal)var3.elementAt(var4)).farSideRoom();
               if (var5 != null) {
                  var5.noteRef();
               }
            }
         }
      }
   }

   boolean discardIfOld(boolean[] var1) {
      int var2 = Std.getFastTime();
      if (var2 < this.nextRoomCheck) {
         return false;
      }

      this.nextRoomCheck = var2 + 5000 + (int)(3000.0 * Math.random());
      this.touchAdjacentRooms(var1);
      int var3 = this.roomList.size();

      while (--var3 >= 0) {
         ((Room)this.roomList.elementAt(var3)).discardIfOld();
      }

      if (this.hasBeenEdited) {
         return false;
      } else {
         var3 = var2 - this.renderStamp;
         if (var3 > this.timeoutAge && this.renderStamp < lastGeneratedFrameEvents && var3 > this.timeoutAge) {
            this.discard();
            return true;
         } else {
            return false;
         }
      }
   }

   public void discard() {
      URL var1 = this.getSourceURL();
      synchronized (worldHash) {
         worldHash.remove(var1);
         worldList.removeElement(this);
      }

      worldListChanged();
      URLSelfLoader.unload(this);
      if (this.eventHandlers != null) {
         int var5 = this.eventHandlers.size();

         while (--var5 >= 0) {
            this.removeHandler((SuperRoot)this.eventHandlers.elementAt(var5));
         }
      }

      Debug.assert_(this.eventHandlers == null);
      this.discardRooms();
      if (this.console != null) {
         this.console.decRef();
      }

      this.console = null;
      System.gc();
      System.runFinalization();
   }

   private void discardRooms() {
      while (!this.roomList.isEmpty()) {
         Room var1 = (Room)this.roomList.elementAt(0);
         var1.discard();
      }
   }

   protected void finalize() {
      this.discardRooms();
      super.finalize();
   }

   private void markInitialized() {
      if (this.getSourceURL() != null) {
         this.register();
      } else {
         this.registerable = true;
      }
   }

   private void register() {
      URL var1 = this.getSourceURL();
      synchronized (worldHash) {
         Debug.dAssert(!worldHash.containsKey(var1));
         worldHash.put(var1, this);
         worldList.addElement(this);
      }

      worldListChanged();
      this.registerable = false;
      int var5 = this.roomList.size();

      while (--var5 >= 0) {
         ((Room)this.roomList.elementAt(var5)).register();
      }
   }

   public void setSourceURL(URL var1) {
      super.setSourceURL(var1);
      if (this.registerable) {
         this.register();
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Default Room Name"));
            } else if (var3 == 1) {
               var5 = this.getDefaultRoomName();
            } else if (var3 == 2) {
               String var13 = (String)var4;
               if (this.getRoom(var13) == null) {
                  Console.println(var13 + Console.message("No-room-named"));
               } else {
                  this.setDefaultRoomName(var13);
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Multiuser"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getMultiuser());
            } else if (var3 == 2) {
               this.setMultiuser((Boolean)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Console");
            } else if (var3 == 1) {
               var5 = this.console;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Rooms"));
            } else if (var3 == 1) {
               var5 = VectorProperty.toVector(this.roomHash);
            } else if (var3 == 4) {
               ((Room)var4).detach();
            } else if (var3 == 3) {
               if (!(var4 instanceof Room)) {
                  throw new Error("Can only add Rooms to a World.");
               }

               this.addRoom((Room)var4);
            } else if (var3 == 5 && var4 instanceof Room) {
               var5 = var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Time-out Age (seconds)"));
            } else if (var3 == 1) {
               var5 = new Float(this.timeoutAge / 1000.0F);
            } else if (var3 == 2) {
               this.timeoutAge = Math.round((Float)var4 * 1000.0F);
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Running Actions (delete to stop)"));
            } else if (var3 == 1) {
               if (this.eventHandlers != null) {
                  var5 = this.eventHandlers.clone();
               }
            } else if (var3 == 4) {
               this.removeHandler((SuperRoot)var4);
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Server URL"), "console");
            } else if (var3 == 1) {
               var5 = this.desiredWorldServerURL;
               if (var5 != null) {
                  String var11 = this.desiredWorldServerURL.unalias();
                  if (var11.startsWith("worldserver://")) {
                     var5 = URL.make(var11 + "default.console");
                  }
               }
            } else if (var3 == 2) {
               URL var12 = (URL)var4;
               if (var12 != null) {
                  String var7 = var12.unalias();
                  int var8 = var7.length();
                  if (var7.startsWith("worldserver://")) {
                     if (!var12.endsWith("/default.console") || var8 < 31) {
                        Console.println(Console.message("server-URL") + "default.console");
                        break;
                     }

                     var7 = var7.substring(14, var8 - 16);
                  }

                  var12 = Console.makeServerURL(var7);
               }

               this.setWorldServerURL(var12);
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Courtesy VIP"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getCourtesyVIP());
            } else if (var3 == 2) {
               this.setCourtesyVIP((Boolean)var4);
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Force Human"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getForceHuman());
            } else if (var3 == 2) {
               this.setForceHuman((Boolean)var4);
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Has Ad Banner"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getHasAdBanner());
            } else if (var3 == 2) {
               this.setHasAdBanner((Boolean)var4);
               this.setupAdBanner();
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Banner Width"));
            } else if (var3 == 1) {
               var5 = new Integer(this.getBannerWidth());
            } else if (var3 == 2) {
               this.setBannerWidth((Integer)var4);
               this.setupAdBanner();
            }
            break;
         case 11:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Banner Height"));
            } else if (var3 == 1) {
               var5 = new Integer(this.getBannerHeight());
            } else if (var3 == 2) {
               this.setBannerHeight((Integer)var4);
               this.setupAdBanner();
            }
            break;
         case 12:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Ad Banner URL"));
            } else if (var3 == 1) {
               var5 = this.getBannerURL();
            } else if (var3 == 2) {
               String var10 = (String)var4;
               this.setBannerURL(var10);
            }
            break;
         case 13:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Has Clickable Ad Cube"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getHasClickableAdCube());
            } else if (var3 == 2) {
               this.setHasClickableAdCube((Boolean)var4);
            }
            break;
         case 14:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Ad Cube image format"), "CMP", "GIF");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getAdCubeFormatIsGif());
            } else if (var3 == 2) {
               this.setAdCubeFormatIsGif((Boolean)var4);
            }
            break;
         case 15:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Ad cube base URL"));
            } else if (var3 == 1) {
               var5 = this.getAdCubeBaseURL();
            } else if (var3 == 2) {
               String var9 = (String)var4;
               this.setAdCubeBaseURL(var9);
            }
            break;
         case 16:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Ad cube default click URL"));
            } else if (var3 == 1) {
               var5 = this.getDefaultAdCubeURL();
            } else if (var3 == 2) {
               String var6 = (String)var4;
               this.setDefaultAdCubeURL(var6);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 17, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(13, classCookie);
      super.saveState(var1);
      var1.saveString(this.defaultRoomName);
      URL.save(var1, this.desiredWorldServerURL);
      var1.saveInt(this.timeoutAge);
      var1.saveBoolean(this.getMultiuser());
      var1.saveBoolean(this.getCourtesyVIP());
      var1.saveBoolean(this.getForceHuman());
      var1.saveBoolean(this.getHasAdBanner());
      var1.saveInt(this.getBannerWidth());
      var1.saveInt(this.getBannerHeight());
      var1.saveString(this.getBannerURL());
      var1.saveBoolean(this.getHasClickableAdCube());
      var1.saveBoolean(this.getAdCubeFormatIsGif());
      var1.saveString(this.getAdCubeBaseURL());
      var1.saveString(this.getDefaultAdCubeURL());
      var1.save(this.roomHash);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      URLSelfLoader.immediateLoad(this, var1);
   }

   private void restoreOldURL(Restorer var1) throws IOException {
      String var2 = var1.restoreString();
      URL var3;
      if (var2 == null || var2.equals("UNSHARED")) {
         var3 = null;
      } else if (!var2.endsWith(".console")) {
         var3 = Console.makeServerURL(var2);
      } else {
         var3 = URL.restore(var1, var2, null);
      }

      if (var3 == null) {
         var3 = defaultServerURL;
      } else {
         this.setMultiuser(true);
      }

      this.setWorldServerURL(var3);
   }

   public int restorePreRooms(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            var1.setOldFlag();
            this.setName(var1.restoreString());
            this.defaultRoomName = var1.restoreString();
            this.restoreOldURL(var1);
            this.roomHash = (Hashtable)var1.restore(false);
            break;
         case 1:
         case 3:
            var1.setOldFlag();
            super.restoreState(var1);
            this.defaultRoomName = var1.restoreString();
            this.restoreOldURL(var1);
            this.roomHash = (Hashtable)var1.restore(false);
            break;
         case 2:
            var1.setOldFlag();
            super.restoreState(var1);
            this.defaultRoomName = var1.restoreString();
            this.restoreOldURL(var1);
            var1.restoreString();
            this.roomHash = (Hashtable)var1.restore(false);
            break;
         case 4:
            super.restoreState(var1);
            this.defaultRoomName = var1.restoreString();
            this.restoreOldURL(var1);
            this.roomHash = (Hashtable)var1.restore(false);
            break;
         case 5:
            super.restoreState(var1);
            this.defaultRoomName = var1.restoreString();
            this.restoreOldURL(var1);
            this.timeoutAge = var1.restoreInt();
            this.roomHash = (Hashtable)var1.restore(false);
            break;
         case 6:
            super.restoreState(var1);
            this.defaultRoomName = var1.restoreString();
            this.restoreOldURL(var1);
            this.timeoutAge = var1.restoreInt();
            var1.restoreBoolean();
            this.roomHash = (Hashtable)var1.restore(false);
            break;
         case 7:
            super.restoreState(var1);
            this.defaultRoomName = var1.restoreString();
            URL var3 = URL.restore(var1);
            if (var3 == null) {
               var3 = defaultServerURL;
            } else {
               this.setMultiuser(true);
            }

            this.setWorldServerURL(var3);
            this.timeoutAge = var1.restoreInt();
            var1.restoreBoolean();
            this.roomHash = (Hashtable)var1.restore(false);
            break;
         case 8:
         case 9:
         case 10:
         case 11:
         case 12:
         case 13:
            super.restoreState(var1);
            this.defaultRoomName = var1.restoreString();
            this.setWorldServerURL(URL.restore(var1));
            this.timeoutAge = var1.restoreInt();
            this.setMultiuser(var1.restoreBoolean());
            if (var2 > 9) {
               this.setCourtesyVIP(var1.restoreBoolean());
            }

            if (var2 > 10) {
               this.setForceHuman(var1.restoreBoolean());
            }

            if (var2 > 11) {
               this.setHasAdBanner(var1.restoreBoolean());
               this.setBannerWidth(var1.restoreInt());
               this.setBannerHeight(var1.restoreInt());
               this.setBannerURL(var1.restoreString());
            }

            if (var2 > 12) {
               this.setHasClickableAdCube(var1.restoreBoolean());
               this.setAdCubeFormatIsGif(var1.restoreBoolean());
               this.setAdCubeBaseURL(var1.restoreString());
               this.setDefaultAdCubeURL(var1.restoreString());
            }

            this.roomHash = (Hashtable)var1.restore(false);
            break;
         default:
            throw new TooNewException();
      }

      Enumeration var4 = this.roomHash.elements();

      while (var4.hasMoreElements()) {
         this.roomList.addElement(var4.nextElement());
      }

      if (var2 < 9 && this.timeoutAge == 60000) {
         this.timeoutAge = 15000;
      }

      return var2;
   }

   public Object clone() {
      World var1 = (World)super.clone();
      int var2 = 1;

      String var3;
      URL var4;
      do {
         var3 = "World" + var2++;
         var4 = URL.make("session:" + var3 + ".world");
      } while (worldHash.containsKey(var4));

      var1.setName(var3);
      var1.setSourceURL(var4);
      return var1;
   }

   public int incRestore(int var1, Restorer var2, URLSelfLoader var3) throws Exception {
      switch (var1) {
         case 0:
            var3.itemp2 = this.restorePreRooms(var2);
            var3.itemp1 = this.roomHash.restoreCount(var2);
         case 1:
            if (--var3.itemp1 >= 0) {
               this.roomHash.restoreEntry(var2);
               return 1;
            } else {
               if (var3.itemp2 == 4) {
                  this.timeoutAge = var2.restoreInt();
                  if (this.timeoutAge == 900000 || this.timeoutAge == 60000) {
                     this.timeoutAge = 15000;
                  }
               }

               if (var2.version() < 3) {
                  return -1;
               }
            }
         case 2:
         case 3:
            return this.finishRestore(var1, var2.version() != Saver.version() || var2.oldFlag(), var3.getURL());
         default:
            Debug.assert_(false);
            return -1;
      }
   }

   public int finishRestore(int var1, boolean var2, URL var3) throws Exception {
      switch (var1) {
         case 0:
         case 1:
            this.tmpenum = this.roomHash.elements();
            this.roomHash = new Hashtable();
         case 2:
            if (this.tmpenum.hasMoreElements()) {
               Room var4 = (Room)this.tmpenum.nextElement();
               this.addRoom(var4);
               return 2;
            } else {
               this.tmpenum = null;
            }
         case 3:
            if (this.console == null && this.loadErr == null) {
               return 3;
            } else {
               if (this.loadErr != null) {
                  throw new IOException(this.loadErr);
               }

               this.markInitialized();
               return -1;
            }
         default:
            Debug.assert_(false);
            return -1;
      }
   }

   public void postRestore(int var1) {
      super.postRestore(var1);
      if (var1 <= 2) {
         int var2 = 0;

         try {
            while ((var2 = this.finishRestore(var2, true, URL.make("error:This file"))) != -1) {
            }
         } catch (Exception var4) {
            var4.printStackTrace(System.out);
            Debug.assert_(false);
         }
      }
   }

   public Console getConsole() {
      return this.console;
   }

   public void loadedURLSelf(URLSelf var1, URL var2, String var3) {
      if (var3 == null && var1 instanceof Console) {
         Console var7 = this.console;
         this.console = (Console)var1;
         if (var7 != null) {
            Galaxy var5 = var7.getGalaxy();
            Galaxy var6 = this.console.getGalaxy();
            Debug.dAssert(var5 != null);
            Debug.dAssert(var6 != null);
            if (var5 != var6) {
               var5.forceObjectRereg();
            }

            var7.decRef();
         }

         this.worldServerURL = var2;
         if (Pilot.getActive() != null && Pilot.getActive().getWorld() == this) {
            Pilot.changeActiveRoom(Pilot.getActive().getRoom());
         }
      } else {
         if (var3 == null) {
            Object[] var4 = new Object[]{new String("" + var2)};
            Console.println(MessageFormat.format(Console.message("no-world"), var4));
            var1.decRef();
         }

         Console.println(Console.message("cant-load") + var3);
         Console.load(null, this);
      }
   }

   public boolean getCourtesyVIP() {
      return this.isCourtesyVIP;
   }

   private void setCourtesyVIP(boolean var1) {
      this.isCourtesyVIP = var1;
   }

   public boolean getForceHuman() {
      return this.isForceHuman;
   }

   private void setForceHuman(boolean var1) {
      this.isForceHuman = var1;
   }

   public boolean getHasAdBanner() {
      return this.hasAdBanner;
   }

   public void setHasAdBanner(boolean var1) {
      this.hasAdBanner = var1;
   }

   public int getBannerWidth() {
      return this.adBannerWidth;
   }

   public void setBannerWidth(int var1) {
      this.adBannerWidth = var1;
   }

   public int getBannerHeight() {
      return this.adBannerHeight;
   }

   public void setBannerHeight(int var1) {
      this.adBannerHeight = var1;
   }

   public String getBannerURL() {
      return this.adBannerURL;
   }

   public void setBannerURL(String var1) {
      this.adBannerURL = var1;
   }

   public void setupAdBanner() {
      if (theAdBanner != null) {
         theAdBanner.detach();
         theAdBanner = null;
      }

      if (this.hasAdBanner) {
         theAdBanner = new AdBanner(this.adBannerWidth, this.adBannerHeight, this.adBannerURL);
      }
   }

   private boolean getMultiuser() {
      return this.isMultiuser;
   }

   private void setMultiuser(boolean var1) {
      this.isMultiuser = var1;
      this.setWorldServerURL(this.desiredWorldServerURL);
   }

   public World setWorldServerURL(URL var1) {
      this.desiredWorldServerURL = var1;
      String var2 = var1.getInternal();
      if (var2.startsWith("worldserver://www.3dcd.com") && NetUpdate.overrideWorldServer != null) {
         var2 = var2.substring(26);
         if (var2.startsWith(":") && NetUpdate.overrideWorldServer.indexOf(58, 13) >= 0) {
            int var3 = 1;

            while (var3 < var2.length() && Character.isDigit(var2.charAt(var3))) {
               var3++;
            }

            var2 = var2.substring(var3);
         }

         var1 = URL.make(NetUpdate.overrideWorldServer + var2);
      }

      this.loadErr = null;
      Console.load(this.isMultiuser ? var1 : null, this);
      return this;
   }

   public static Enumeration getWorlds() {
      return worldList.elements();
   }
}
