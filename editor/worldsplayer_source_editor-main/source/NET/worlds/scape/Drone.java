package NET.worlds.scape;

import NET.worlds.console.BBAppearDroneCommand;
import NET.worlds.console.BBDisappearDroneCommand;
import NET.worlds.console.BBDroneBitmapCommand;
import NET.worlds.console.BBDroneDeltaPosCommand;
import NET.worlds.console.BBMoveDroneCommand;
import NET.worlds.console.BlackBox;
import NET.worlds.console.Console;
import NET.worlds.console.FriendsListPart;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MuteListPart;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.ServerTableManager;
import NET.worlds.core.Std;
import NET.worlds.network.FilthFilter;
import NET.worlds.network.Galaxy;
import NET.worlds.network.InfiniteWaitException;
import NET.worlds.network.NetworkObject;
import NET.worlds.network.ObjID;
import NET.worlds.network.OldPropertyList;
import NET.worlds.network.PacketTooLargeException;
import NET.worlds.network.PropertyList;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import NET.worlds.network.net2Property;
import NET.worlds.network.netProperty;
import NET.worlds.network.propReqCmd;
import java.awt.Color;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

public abstract class Drone extends WObject implements NetworkObject, WobLoaded, MouseDownHandler, FrameHandler {
   private int _last_FrameTime;
   private int _last_PosTime;
   private int _vel_x;
   private int _vel_y;
   private int _vel_z;
   private int _vel_yaw;
   private int _last_x;
   private int _last_y;
   private int _last_z;
   private int _last_yaw;
   private int _x;
   private int _y;
   private int _z;
   private int _yaw;
   private boolean inited = false;
   protected WObject tag;
   protected WObject tagbg;
   private Console console;
   private float tagHeight;
   private Shape sleepBox;
   static boolean showNametags = IniFile.gamma().getIniInt("SHOWNAMETAGS", 1) == 1;
   private static String[] employeeAccounts = ServerTableManager.instance().getTable("employeeAccounts");
   private static Hashtable employeeHash = null;
   public static Vector usableDrones = new Vector();
   private int lastUsed;
   protected WorldServer _server;
   private String sleepMode;
   private static Object classCookie = new Object();
   private static Object classCookieInterpolatedDrone = new Object();

   public Drone(ObjID var1, WorldServer var2) {
      if (var2 != null) {
         Debug.dAssert(var1 != null);
         this.attachToServer(var2.getLongID(var1), var2);
      }
   }

   protected Drone(String var1, WorldServer var2) {
      Debug.dAssert(var1 != null);
      if (var2 != null) {
         this.attachToServer(var1, var2);
      }
   }

   private void attachToServer(String var1, WorldServer var2) {
      if (var2 != null) {
         Debug.dAssert(Main.isMainThread());
         String var3 = null;
         if (this.tag != null) {
            var3 = this.getLongID();
         }

         this.getSharer().createDynamicFromNet();
         this.setName(var1);
         String var4 = this.getLongID();
         this._server = var2;
         this._server.incRefCnt(this);
         this._server.regObject(var4, this);

         try {
            this._server.sendNetworkMsg(new propReqCmd(new ObjID(this.getLongID())));
         } catch (InfiniteWaitException var6) {
         } catch (PacketTooLargeException var7) {
            Debug.dAssert(false);
         }

         if (var4.equals(var3)) {
            this.avatarHeightChangedTo(189.0F);
         } else {
            this.makeTag(false);
         }

         Main.register(new Drone.MakeSleepBox());
      }
   }

   private static void flushUnusedDrones() {
      synchronized (usableDrones) {
         int var1 = Std.getFastTime();
         int var2 = usableDrones.size();

         while (--var2 >= 0) {
            Drone var3 = (Drone)usableDrones.elementAt(var2);
            if (var1 > var3.lastUsed + 2000) {
               usableDrones.removeElementAt(var2);
               var3.discard();
            }
         }
      }
   }

   public static boolean isEmployeeAccount(String var0) {
      if (employeeHash == null) {
         employeeHash = new Hashtable();

         for (int var1 = 0; var1 < employeeAccounts.length; var1++) {
            employeeHash.put(employeeAccounts[var1], employeeAccounts[var1]);
         }
      }

      return employeeHash.get(var0) != null;
   }

   public void makeTag(boolean var1) {
      this.tagHeight = 195.0F;
      if (this.tag != null) {
         this.tagHeight = this.tag.getZ();
         this.tag.detach();
         this.tag = null;
      }

      if (this.tagbg != null) {
         this.tagbg.detach();
         this.tagbg = null;
      }

      if ((this._server != null || var1) && !(this instanceof MutedDrone) && showNametags) {
         String var2 = this.getLongID();
         String var3 = FilthFilter.get().filterName(var2);
         if (var3 != null && !var3.equals("")) {
            Texture[] var4 = new Texture[1];
            boolean var6 = RenderWare.get3DHardwareInUse();
            boolean var7 = var3.toLowerCase().startsWith(Console.message("host")) || var3.toLowerCase().startsWith("host");
            if (var7) {
               var3 = Console.message("host-upper") + var3.substring(4);
            }

            boolean var8 = var3.toLowerCase().startsWith(Console.message("guest-")) || var3.toLowerCase().startsWith("guest-");
            if (var8) {
               var3 = Console.message("guest-upper") + var3.substring(5);
            }

            boolean var9 = isEmployeeAccount(var3);
            Color var10;
            if (var8) {
               var10 = Color.pink;
            } else if (var7) {
               var10 = Color.yellow;
            } else if (var9) {
               var10 = Color.cyan;
            } else {
               var10 = Color.lightGray;
            }

            var4[0] = new StringTexture(var3, Console.message("TagFont"), 48, Color.black, var6 ? new Color(254, 254, 254) : var10);
            byte var5 = 14;
            int var11 = var3.length() * 10;
            Hologram var12 = new Hologram(var11, var5, var4);
            var12.setViewplaneAligned(true);
            var12.raise(this.tagHeight);
            var12.setScaleDist(300.0F);
            this.tag = var12;
            this.tag.setVisible(true);
            this.tag.setBumpable(false);
            this.tag.setLocalShadowed(false);
            this.tag.setShadowedLocally(true);
            this.add(this.tag);
            if (var6) {
               Texture[] var13 = new Texture[]{new StringTexture(var3, Console.message("TagFont"), 48, Color.black, var10)};
               Hologram var14 = new Hologram(var11, var5, var13);
               var14.setViewplaneAligned(true);
               var14.raise(this.tagHeight);
               var14.setScaleDist(300.0F);
               var14.setMaterial(new Material(0.75F, 0.0F, 0.0F, Color.white, null, 0.5F, false, false));
               this.tagbg = var14;
               this.tagbg.setVisible(true);
               this.tagbg.setBumpable(false);
               this.tagbg.setLocalShadowed(false);
               this.tagbg.setShadowedLocally(true);
               this.add(this.tagbg);
            }
         }
      }
   }

   protected void avatarHeightChangedTo(float var1) {
      if (this.tag != null) {
         this.tag.raise(var1 + 1.0F + 5.0F - this.tag.getZ());
      }

      if (this.tagbg != null) {
         this.tagbg.raise(var1 + 1.0F + 5.0F - this.tagbg.getZ());
      }
   }

   public void detachFromServer(boolean var1) {
      Debug.dAssert(Main.isMainThread());
      if (this._server != null) {
         this._server.delObject(new ObjID(this.getLongID()));
         this._server.decRefCnt(this);
         this._server = null;
      }

      if (var1) {
         this.lastUsed = Std.getFastTime();
         synchronized (usableDrones) {
            usableDrones.addElement(this);
         }
      }
   }

   public static Drone make(ObjID var0, WorldServer var1) {
      synchronized (usableDrones) {
         if (!usableDrones.isEmpty() && var0 != null && var1 != null) {
            String var3 = "!" + var1.getLongID(var0);

            int var4;
            for (var4 = usableDrones.size() - 1; var4 > 0; var4--) {
               Drone var5 = (Drone)usableDrones.elementAt(var4);
               if (var5.getName().equals(var3)) {
                  break;
               }
            }

            Drone var8 = (Drone)usableDrones.elementAt(var4);
            if (!var8.getName().equals(var3) && usableDrones.size() < 5) {
               return new HoloDrone(var0, var1);
            }

            usableDrones.removeElementAt(var4);
            var8.attachToServer(var1.getLongID(var0), var1);
            return var8;
         } else {
            return new HoloDrone(var0, var1);
         }
      }
   }

   public Drone() {
   }

   public boolean handle(MouseDownEvent var1) {
      if (this._server != null && (var1.key & 1) == 1) {
         FriendsListPart.droneClick(this, var1);
      }

      return true;
   }

   public float animate(String var1) {
      if (var1.equalsIgnoreCase("_hdb")) {
         new Drone.BounceNametag();
      }

      return 0.0F;
   }

   public Vector getAnimationList() {
      return new Vector();
   }

   public void muteStateChanged() {
      this.setAvatarNow(this.getCurrentURL());
   }

   public boolean shouldBeMuted() {
      return MuteListPart.isMuted(this._server, this.getLongID());
   }

   private World getOwnerWorld() {
      WObject var1 = (WObject)this.getOwner();
      Room var2 = var1 == null ? null : var1.getRoom();
      return var2 == null ? null : var2.getWorld();
   }

   public boolean shouldBeForcedHuman() {
      World var1 = this.getOwnerWorld();
      return var1 != null && var1.getForceHuman();
   }

   public URL getCurrentURL() {
      return this instanceof PosableDrone ? ((PosableDrone)this).getPosableShapeURL() : this.getSourceURL();
   }

   public Drone setAvatarNow(URL var1) {
      if (var1 == null) {
         return this;
      }

      if (this.shouldBeForcedHuman()) {
         var1 = PosableShape.getHuman(var1);
         if (Console.getActive() != null) {
            Console.getActive().pendingPilot = var1.toString();
         }
      }

      var1 = PosableShape.getPermitted(var1, this.getWorld());
      boolean var2 = this.shouldBeMuted();
      if (var1.equals(this.getCurrentURL()) && var2 == (this instanceof MutedDrone)) {
         return this;
      }

      if (!var1.endsWith(".rwx") && !var1.endsWith(".rwg") && !var1.endsWith(".mov")) {
         String var9 = var1.getInternal();
         if (var9.endsWith(".pilot")) {
            var9 = var9.substring(0, var9.length() - 6) + ".drone";
         } else if (!var9.endsWith(".drone")) {
            var9 = var9 + ".drone";
         }

         var1 = URL.make(var9);
         if (var1.equals(this.getSourceURL())) {
            return this;
         }

         new WobLoader(var1, this);
         return this;
      } else {
         WObject var3 = (WObject)this.getOwner();
         if (var3 == null) {
            return this;
         }

         WorldServer var4 = this._server;
         String var5 = this.getLongID();
         this.detachFromServer(false);
         this.detach();
         Drone var6;
         if (var2) {
            var6 = new MutedDrone(new ObjID(var5), var4, var1);
         } else if (var1.endsWith(".mov")) {
            var6 = new HoloDrone(new ObjID(var5), var4);
            var6.setAvatarNow(var1);
         } else {
            var6 = new PosableDrone(new ObjID(var5), var4, var1);
         }

         if (var4 != null) {
            var6.transferFrom(this);
            var6.addTo(var3.getRoom());
         } else {
            var6.makeIdentity().post(this);
            var6.setName(this.getLongID());
            var3.add(var6);
         }

         return var6;
      }
   }

   public void wobLoaded(WobLoader var1, SuperRoot var2) {
      if (var2 instanceof Drone) {
         Debug.dAssert(var2 != null);
         Drone var3 = (Drone)var2;
         var3.setName(this.getLongID());
         if (this._server == null) {
            WObject var7 = (WObject)this.getOwner();
            this.detach();
            var3.makeIdentity().post(this);
            var7.add(var3);
         } else {
            WorldServer var4 = this._server;
            String var5 = this.getLongID();
            this.detachFromServer(false);
            Room var6 = this.getRoom();
            this.detach();
            var3.addTo(var6);
            var3.attachToServer(var5, var4);
            var3.transferFrom(this);
         }
      }
   }

   public void addTo(Room var1) {
      if (var1 != null) {
         Console var2 = var1.getWorld().getConsole();
         if (this.console == null) {
            this.console = var2;
            if (var2 != null) {
               Pilot.copySoul(var2.getDroneSoulTemplate(), this);
            }
         }

         var1.add(this);
      }
   }

   public void add(WObject var1) {
      super.add(var1);
   }

   protected void noteUnadding(SuperRoot var1) {
      if (var1 instanceof WObject) {
         WObject var2 = (WObject)var1;
         if (var2.isDynamic()) {
            var2.setVisible(true);
         }
      }

      super.noteUnadding(var1);
   }

   public void setSleepMode(String var1) {
      if (!var1.equals(this.sleepMode)) {
         this.sleepMode = var1;
         Main.register(new Drone.MakeSleepBox());
      }
   }

   private void handleVAR_ASLEEP(String var1) {
      if (var1 != null && var1.length() > 2 && var1.charAt(0) == 0) {
         var1 = var1.substring(2);
      }

      this.setSleepMode(var1);
   }

   public Drone handleVAR_BITMAP(String var1) {
      if (var1.equals("")) {
         return this;
      }

      BlackBox.getInstance().submitEvent(new BBDroneBitmapCommand(this.getName(), var1));
      if (var1.charAt(0) == 0) {
         var1 = var1.substring(2);
      }

      try {
         return this.setAvatarNow(new URL(URL.getAvatar(), var1));
      } catch (MalformedURLException var3) {
         Console.println(Console.message("Invalid-av") + var1);
         return this;
      }
   }

   public Point3Temp getVelocity() {
      return Point3Temp.make(this._vel_x, this._vel_y, this._vel_z);
   }

   public int getYawRate() {
      return this._vel_yaw;
   }

   public boolean handle(FrameEvent var1) {
      if (this._server == null) {
         return true;
      }

      int var2 = var1.time;
      this.interpolate(var2, this._server.getUpdateTime(), this);
      return true;
   }

   public void interpolate(int var1, int var2, Transform var3) {
      if (this.inited) {
         if (var1 - this._last_PosTime > var2) {
            this._last_PosTime = var1;
            this._vel_x = this._last_x - this._x;
            this._vel_y = this._last_y - this._y;
            this._vel_z = this._last_z - this._z;
            this._vel_yaw = ((this._last_yaw - this._yaw) % 360 + 360) % 360;
            Debug.dAssert(this._vel_yaw >= 0);
            if (this._vel_yaw > 180) {
               this._vel_yaw -= 360;
            }
         }

         double var4 = (double)(var1 - this._last_FrameTime) / var2;
         if (var1 - this._last_FrameTime > var2) {
            var4 = 0.0;
         }

         this._x = this._x + (int)(var4 * this._vel_x);
         this._y = this._y + (int)(var4 * this._vel_y);
         this._z = this._z + (int)(var4 * this._vel_z);
         this._yaw = this._yaw + (int)(var4 * this._vel_yaw) % 360;
         var3.makeIdentity().moveBy(this._x, this._y, this._z).yaw(this._yaw);
         this._last_FrameTime = var1;
      }
   }

   public void reset(short var1, short var2, short var3, short var4) {
      this._x = var1;
      this._y = var2;
      this._z = var3;
      this._yaw = var4;
      this._vel_x = this._vel_y = this._vel_z = 0;
      this._vel_yaw = 0;
      this._last_x = this._x;
      this._last_y = this._y;
      this._last_z = this._z;
      this._last_yaw = this._yaw;
      this._last_PosTime = this._last_FrameTime = Std.getRealTime();
      this.inited = true;
   }

   protected void transferFrom(Drone var1) {
      this.makeIdentity().post(var1);
      this._x = var1._x;
      this._y = var1._y;
      this._z = var1._z;
      this._yaw = var1._yaw;
      this._vel_x = var1._vel_x;
      this._vel_y = var1._vel_y;
      this._vel_z = var1._vel_z;
      this._vel_yaw = var1._vel_yaw;
      this._last_x = var1._last_x;
      this._last_y = var1._last_y;
      this._last_z = var1._last_z;
      this._last_yaw = var1._last_yaw;
      this._last_PosTime = var1._last_PosTime;
      this._last_FrameTime = var1._last_FrameTime;
      this.inited = true;
   }

   public void appear(Room var1, short var2, short var3, short var4, short var5) {
      Debug.dAssert(var1 != null);
      BlackBox.getInstance().submitEvent(new BBAppearDroneCommand(var1.toString(), this.getName(), var2, var3, var4, var5));
      if (this.getRoom() != var1) {
         this.detach();
         var1.add(this);
      }

      this.makeIdentity().moveBy(var2, var3, var4).yaw(var5);
      this._x = var2;
      this._y = var3;
      this._z = var4;
      this._yaw = var5;
      this._vel_x = this._vel_y = this._vel_z = 0;
      this._vel_yaw = 0;
      this._last_x = var2;
      this._last_y = var3;
      this._last_z = var4;
      this._last_yaw = var5;
      this._last_PosTime = this._last_FrameTime = Std.getRealTime();
      URL var6 = this.getCurrentURL();
      if (var6 != null) {
         this.setAvatarNow(var6);
      }

      this.inited = true;
   }

   public void disappear() {
      BlackBox.getInstance().submitEvent(new BBDisappearDroneCommand(this.getName()));
      this.detachFromServer(true);
      this.detach();
   }

   public void longLoc(short var1, short var2, short var3, short var4) {
      if (!(this.getOwner() instanceof Pilot)) {
         BlackBox.getInstance().submitEvent(new BBMoveDroneCommand(this.getName(), var1, var2, var3, var4));
      }

      this._last_x = var1;
      this._last_y = var2;
      this._last_z = var3;
      this._last_yaw = var4;
      this._vel_x = this._last_x - this._x;
      this._vel_y = this._last_y - this._y;
      this._vel_z = this._last_z - this._z;
      this._vel_yaw = ((this._last_yaw - this._yaw) % 360 + 360) % 360;
      Debug.dAssert(this._vel_yaw >= 0);
      if (this._vel_yaw > 180) {
         this._vel_yaw -= 360;
      }

      this._last_PosTime = Std.getRealTime();
      this.inited = true;
   }

   public void property(OldPropertyList var1) {
      int var3 = var1.size();

      for (int var4 = 0; var4 < var3; var4++) {
         netProperty var2 = var1.elementAt(var4);
         switch (var2.property()) {
            case 5:
               this.handleVAR_BITMAP(var2.value());
               break;
            case 23:
               this.handleVAR_ASLEEP(var2.value());
               break;
            default:
               byte[] var5 = new byte[var2.value().length()];
               var2.value().getBytes(0, var2.value().length(), var5, 0);
               this.getSharer().setFromNetData(var2.property(), var5);
         }
      }
   }

   public void propertyUpdate(PropertyList var1) {
      int var3 = var1.size();

      for (int var4 = 0; var4 < var3; var4++) {
         net2Property var2 = var1.elementAt(var4);
         switch (var2.property()) {
            case 5:
               this.handleVAR_BITMAP(var2.value());
               break;
            case 23:
               this.handleVAR_ASLEEP(var2.value());
               break;
            default:
               this.getSharer().setFromNetData(var2.property(), var2.data());
         }
      }
   }

   public void roomChange(Room var1, short var2, short var3, short var4, short var5) {
      this.detach();
      if (var1 != null) {
         this.appear(var1, var2, var3, var4, var5);
      }
   }

   public void shortLoc(byte var1, byte var2, byte var3) {
      if (!(this.getOwner() instanceof Pilot)) {
         BlackBox.getInstance().submitEvent(new BBDroneDeltaPosCommand(this.getName(), var1, var2, var3));
      }

      this._last_x += var1;
      this._last_y += var2;
      this._last_yaw += var3;
      this._last_yaw %= 360;
      this._vel_x = this._last_x - this._x;
      this._vel_y = this._last_y - this._y;
      this._vel_z = 0;
      this._vel_yaw = ((this._last_yaw - this._yaw) % 360 + 360) % 360;
      Debug.dAssert(this._vel_yaw >= 0);
      if (this._vel_yaw > 180) {
         this._vel_yaw -= 360;
      }

      this._last_PosTime = Std.getRealTime();
   }

   public void teleport(WorldServer var1, byte var2, byte var3, Room var4, short var5, short var6, short var7, short var8) {
      Debug.dAssert(var1.getObject(new ObjID(this.getLongID())) == this);
      Room var9 = this.getRoom();
      switch (var2) {
         default:
            if (var9 != null) {
               Debug.dAssert(var9 != null);
               this.detach();
            }
         case 0:
            switch (var3) {
               case 0:
                  this.detachFromServer(true);
                  this.detach();
                  break;
               default:
                  if (var4 == null) {
                     this.detach();
                  } else {
                     Debug.dAssert(var4 != null);
                     this.appear(var4, var5, var6, var7, var8);
                  }
            }
      }
   }

   public WorldServer getServer() {
      return this._server;
   }

   public String getLongID() {
      String var1 = this.getName();
      if (var1.startsWith("!")) {
         var1 = var1.substring(1);
      }

      return var1;
   }

   public void register() {
      Debug.dAssert(false);
   }

   public void galaxyDisconnected() {
      Debug.dAssert(false);
   }

   public void reacquireServer(WorldServer var1) {
      Debug.dAssert(false);
   }

   public void changeChannel(Galaxy var1, String var2, String var3) {
      Debug.dAssert(false);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         default:
            return super.properties(var1, var2 + 0, var3, var4);
      }
   }

   public void saveState(Saver var1) throws IOException {
      if (this.console != null) {
         System.out.println("Warning: saving drone " + this.getName() + " WITH soul, which won't restore correctly!");
      }

      var1.saveVersion(0, classCookieInterpolatedDrone);
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreStateDrone(Restorer var1) throws IOException, TooNewException {
      var1.restoreVersion(classCookieInterpolatedDrone);
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            Enumeration var2 = this.getContents();

            while (var2.hasMoreElements()) {
               WObject var3 = (WObject)var2.nextElement();
               if (var3 instanceof Hologram) {
                  Hologram var4 = (Hologram)var3;
                  if (var4.getMovieName() == null) {
                     this.tag = var4;
                  }
               }
            }

            return;
         default:
            throw new TooNewException();
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreStateDrone(var1);
   }

   static {
      Main.register(new Drone.Flusher());
   }

   class BounceNametag implements MainCallback {
      int start;
      WObject origTag;
      WObject origTagbg;

      BounceNametag() {
         if (Drone.this.tag != null) {
            this.start = Std.getFastTime();
            this.origTag = Drone.this.tag;
            this.origTagbg = Drone.this.tagbg;
            Main.register(this);
         }
      }

      public void mainCallback() {
         int var1 = Std.getFastTime();
         float var2 = Drone.this.tagHeight;
         if (var1 > this.start + 6000 || this.origTag != Drone.this.tag || this.origTagbg != Drone.this.tagbg) {
            Main.unregister(this);
         } else if (var1 < this.start + 1500) {
            var2 = Drone.this.tagHeight + 200.0F * ((var1 - this.start) / 1500.0F);
         } else {
            float var3 = (var1 - this.start) / 1500.0F;
            var2 = (float)(200.0 * Math.pow(1.414F, var3) * Math.cos(var3 * 3.14159F));
         }

         this.origTag.setZ(var2);
         if (this.origTagbg != null) {
            this.origTagbg.setZ(var2);
         }
      }
   }

   static class Flusher implements MainCallback {
      int lastTime;

      public void mainCallback() {
         int var1 = Std.getFastTime();
         if (var1 > this.lastTime + 1000) {
            Drone.flushUnusedDrones();
            this.lastTime = var1;
         }
      }
   }

   class MakeSleepBox implements MainCallback {
      public void mainCallback() {
         if (Drone.this.sleepMode != null && Drone.this.sleepMode.equals(Console.message("asleep")) && !(Drone.this instanceof MutedDrone)) {
            if (Drone.this.sleepBox == null) {
               Drone.this.sleepBox = new Shape();
               Drone.this.sleepBox.setURL(URL.make("home:idle.rwg"));
               Drone.this.sleepBox.setBumpable(false);
               Drone.this.sleepBox.scale(100.0F);
               Drone.this.sleepBox.spin(0.0F, 1.0F, 1.0F, 180.0F);
               Drone.this.sleepBox.raise(189.0F);
               Drone.this.add(Drone.this.sleepBox);
            }
         } else if (Drone.this.sleepBox != null) {
            Drone.this.sleepBox.detach();
            Drone.this.sleepBox = null;
         }

         Main.unregister(this);
      }
   }
}
