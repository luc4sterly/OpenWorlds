package NET.worlds.scape;

import NET.worlds.console.AdPart;
import NET.worlds.console.BBAnimateDroneCommand;
import NET.worlds.console.BBMoveDroneCommand;
import NET.worlds.console.BBTeleportCommand;
import NET.worlds.console.BlackBox;
import NET.worlds.console.Console;
import NET.worlds.console.RenderCanvas;
import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import NET.worlds.network.Galaxy;
import NET.worlds.network.InfiniteWaitException;
import NET.worlds.network.NetworkObject;
import NET.worlds.network.OldPropertyList;
import NET.worlds.network.PacketTooLargeException;
import NET.worlds.network.PropertyList;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import NET.worlds.network.longLocCmd;
import NET.worlds.network.netPacket;
import NET.worlds.network.roomChangeCmd;
import NET.worlds.network.teleportCmd;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public abstract class Pilot extends WObject implements NetworkObject, BumpHandler {
   static Vector visibleRooms = new Vector();
   static Vector visibleRoomInfo = new Vector();
   int lastUpdateTime;
   private static Vector nextVisibleRooms = new Vector();
   private static Vector nextVisibleRoomInfo = new Vector();
   int positionSentTime;
   short lastx;
   short lasty;
   short lastz;
   short lastdir;
   Room lastroom;
   Room lastFrameRoom;
   private static Vector subscribers = new Vector();
   private static int lastWarning;
   private static Pilot active;
   protected int cameraMode = 0;
   protected int cameraSpeed = 0;
   private static World lastWorld = null;
   private Camera lastCam;
   protected Console console;
   private static Object classCookie = new Object();

   public static native void nativeInit();

   public float animate(String var1) {
      var1 = var1.toLowerCase();
      BlackBox.getInstance().submitEvent(new BBAnimateDroneCommand("@Pilot", var1));
      if (var1.equals("sleep") || var1.equals("s")) {
         Console var2 = Console.getActive();
         if (var2 != null) {
            var2.goToSleep();
         }
      } else if (this == getActive()) {
         sendText("&|+action>" + var1);
      }

      return 0.0F;
   }

   public Vector getAnimationList() {
      Vector var1 = new Vector();
      var1.addElement("sleep");
      return var1;
   }

   public void setSleepMode(String var1) {
   }

   public static void load(URL var0, WobLoaded var1) {
      if (!var0.endsWith(".mov") && !var0.endsWith(".rwx") && !var0.endsWith(".rwg")) {
         String var2 = var0.getInternal();
         if (var2.endsWith(".drone")) {
            var2 = var2.substring(0, var2.length() - 6) + ".pilot";
         } else if (!var2.endsWith(".pilot")) {
            var2 = var2 + ".pilot";
         }

         new WobLoader(URL.make(var2), var1);
      } else {
         var1.wobLoaded(null, new HoloPilot(var0));
      }
   }

   public void addInventory(WObject var1) throws ClassCastException {
      Debug.dAssert(var1.isDynamic());
      this.add(var1);
   }

   public void addInSlot(WObject var1, int var2) {
      Debug.dAssert(var1.isDynamic());
      Sharer var3 = this.getSharer();
      if (var3.getAttribute(var2) != null) {
         System.out.println("Attempting to add a second object (" + var1.getName() + ") to slot number " + var2);
      } else {
         var3.moveToSlot(var1, var2);
      }
   }

   public void add(WObject var1) {
      super.add(var1);
   }

   public float distToVisibleObject(WObject var1) {
      return this.distToVisiblePoint(var1.getRoom(), var1.getWorldPosition());
   }

   public void aboutToDraw() {
   }

   public float distToVisiblePoint(Room var1, Point3Temp var2) {
      if (var1 == null) {
         return 0.0F;
      }

      int var3 = visibleRooms.indexOf(var1);
      if (var3 == -1) {
         return 0.0F;
      }

      RoomSubscribeInfo var4 = (RoomSubscribeInfo)visibleRoomInfo.elementAt(var3);
      return var4.d == 0.0F ? var2.minus(this.getWorldPosition()).length() : var2.minus(Point3Temp.make(var4.x, var4.y, var4.z)).length() + var4.d;
   }

   public static void addVisibleRoom(Room var0, float var1, float var2, float var3, float var4) {
      var0.noteRef();
      int var5 = nextVisibleRooms.indexOf(var0);
      if (var5 == -1) {
         nextVisibleRooms.addElement(var0);
         nextVisibleRoomInfo.addElement(new RoomSubscribeInfo(var1, var2, var3, var4));
      } else {
         RoomSubscribeInfo var6 = (RoomSubscribeInfo)nextVisibleRoomInfo.elementAt(var5);
         if (var4 < var6.d) {
            var6.x = var1;
            var6.y = var2;
            var6.z = var3;
            var6.d = var4;
         }
      }
   }

   public void generateFrameEvents(FrameEvent var1) {
      Room var2 = this.getRoom();
      if (var2 != null) {
         addVisibleRoom(var2, 0.0F, 0.0F, 0.0F, 0.0F);
      }

      synchronized (visibleRooms) {
         Vector var4 = visibleRoomInfo;
         visibleRoomInfo = nextVisibleRoomInfo;
         nextVisibleRoomInfo = var4;
         var4 = nextVisibleRooms;
         nextVisibleRooms = visibleRooms;
         visibleRooms = var4;
      }

      Vector var9 = nextVisibleRooms;
      Vector var11 = nextVisibleRoomInfo;
      Object var5 = var1.source;
      var1.source = this;
      int var6 = visibleRooms.size();

      while (--var6 >= 0) {
         Room var7 = (Room)visibleRooms.elementAt(var6);
         var7.generateFrameEvents(var1);
         var9.removeElement(var7);
      }

      var6 = var9.size();

      while (--var6 >= 0) {
         ((Room)var9.elementAt(var6)).generateFrameEvents(var1);
      }

      nextVisibleRooms.removeAllElements();
      nextVisibleRoomInfo.removeAllElements();
      var6 = var1.time - this.lastUpdateTime;
      if (var6 > 500) {
         this.subscribeRooms();
         boolean var14 = this.pilotUpdate(var1.time);
         this.subscriptionUpdate(var14);
         this.updateUnsubscribes();
         this.lastUpdateTime = var1.time;
      }

      this.touchSubscribers();
      var1.source = var5;
   }

   public static void sendText(String var0) {
      sendText(null, var0);
   }

   public static boolean containsWord(String var0, String var1) {
      int var2 = -1;

      while ((var2 = var1.indexOf(var0, var2 + 1)) >= 0) {
         if (var2 == 0 || !Character.isLetter(var1.charAt(var2 - 1))) {
            int var3 = var2 + var0.length();
            if (var3 >= var1.length() || !Character.isLetter(var1.charAt(var3))) {
               return true;
            }
         }
      }

      return false;
   }

   public static void sendText(String var0, String var1) {
      WorldServer var2 = active.getServer();
      if (var2 != null) {
         var2.sendText(var0, var1);
         if ((containsWord("brb", var1) || containsWord("ggp", var1)) && Console.getActive() != null) {
            Console.getActive().goToSleep();
         }

         int var4 = var1.indexOf(42);

         int var3;
         while (var4 >= 0 && (var3 = var1.indexOf(42, var4 + 1)) > var4) {
            int var5 = var1.indexOf(32, var4);
            if (var3 > var4 + 1 && (var5 == -1 || var5 > var3)) {
               String var6 = var1.substring(var4 + 1, var3).toLowerCase();
               if (var0 == null && active != null) {
                  active.animate(var6);
               } else {
                  sendText(var0, "&|+action>" + var6);
               }
            }

            var4 = var3;
         }
      } else if (!var1.startsWith("&|+")) {
         Console.println(Console.message("No-server-connect"));
      }
   }

   private static float round(float var0, float var1) {
      return var1 * Math.round(var0 / var1);
   }

   public String getWorldRoomChannel(Room var1) {
      if (var1 == null) {
         return null;
      }

      World var2 = var1.getWorld();
      if (var2 == null) {
         return null;
      }

      URL var3 = var2.getSourceURL();
      if (var3 == null) {
         return null;
      }

      String var4 = var3.getAbsolute();
      Galaxy var5 = var1.getGalaxy();
      String var6 = var5.getChannel();
      return var4 + "#" + var1.getName() + "<" + var6 + ">";
   }

   public String getURL() {
      Room var1 = this.getRoom();
      String var2 = this.getWorldRoomChannel(var1);
      if (var2 == null) {
         return null;
      }

      float var3 = round(this.getX(), 1.0F);
      var2 = var2 + "@" + var3;
      var3 = round(this.getY(), 1.0F);
      var2 = var2 + "," + var3;
      var3 = round(this.getZ(), 1.0F);
      var2 = var2 + "," + var3;
      Point3Temp var4 = Point3.make();
      var3 = round(this.getSpin(var4), 1.0F);
      var2 = var2 + "," + var3;
      var3 = round(var4.x, 0.001F);
      var2 = var2 + "," + var3;
      var3 = round(var4.y, 0.001F);
      var2 = var2 + "," + var3;
      var3 = round(var4.z, 0.001F);
      return var2 + "," + var3;
   }

   public String getTeleportURL() {
      Camera var1 = new Camera();
      Room var2 = this.getRoom();
      if (var2 == null) {
         return null;
      }

      var2.add(var1);
      var1.yaw(220.0F);
      var1.post(this);
      boolean var3 = this.getBumpable();
      this.setBumpable(false);
      Transform var4 = var1.getObjectToWorldMatrix();
      var1.moveThrough(Point3Temp.make(0.0F, -170.0F, 0.0F).times(var4).minus(var4.getPosition()));
      var4.recycle();
      this.setBumpable(var3);
      var2 = var1.getRoom();
      var1.detach();
      String var5 = this.getWorldRoomChannel(var2);
      return var5 == null ? null : var5 + "@" + (int)var1.getX() + "," + (int)var1.getY() + "," + (int)var1.getZ() + "," + (int)var1.getYaw();
   }

   public Room getLastServedRoom() {
      return this.lastroom;
   }

   public float getFootHeight() {
      return 0.0F;
   }

   private static void sendToRoom(Room var0, netPacket var1) {
      if (var0 != null) {
         synchronized (var0) {
            WorldServer var3 = var0.getServer();
            if (var3 != null) {
               try {
                  var3.sendNetworkMsg(var1);
               } catch (InfiniteWaitException var6) {
               } catch (PacketTooLargeException var7) {
               }
            }
         }
      }
   }

   private boolean validRoom(Room var1) {
      return var1 == null || var1.getNetworkRoom().getRoomID() != 0;
   }

   public boolean pilotUpdate(int var1) {
      short var2 = (short)this.getX();
      short var3 = (short)this.getY();
      short var4 = (short)this.getFootHeight();
      short var5 = (short)(-this.getYaw() + 90.0F);
      var5 = (short)(var5 % 360);

      while (var5 < 0) {
         var5 = (short)(var5 + 360);
      }

      Room var6 = this.getRoom();
      if (var6 != this.lastFrameRoom) {
         BlackBox.getInstance().submitEvent(new BBTeleportCommand(this.getURL()));
         this.lastFrameRoom = this.getRoom();
      }

      if (var6 != null && !var6.getNetworkRoom().isServed()) {
         var6 = null;
      }

      if (this.lastroom != null && !this.lastroom.getNetworkRoom().isServed()) {
         this.lastroom = null;
      }

      int var7 = var1 - this.positionSentTime;
      if (var2 == this.lastx && var3 == this.lasty && var4 == this.lastz && var5 == this.lastdir && var7 <= 40000 && var6 == this.lastroom) {
         return false;
      }

      BlackBox.getInstance().submitEvent(new BBMoveDroneCommand("@Pilot", var2, var3, var4, var5));
      if (var6 != this.lastroom && this.validRoom(var6) && this.validRoom(this.lastroom)) {
         Galaxy var9 = null;
         Galaxy var8 = null;
         if (var6 != null) {
            var8 = var6.getGalaxy();
         }

         if (this.lastroom != null) {
            var9 = this.lastroom.getGalaxy();
         }

         if (var8 != var9) {
            if (var6 != null) {
               sendToRoom(var6, new teleportCmd(var6, (byte)0, (byte)1, var2, var3, var4, var5));
               BlackBox.getInstance().submitEvent(new BBTeleportCommand(this.getURL()));
            }

            if (this.lastroom != null) {
               sendToRoom(this.lastroom, new teleportCmd(null, (byte)1, (byte)0, var2, var3, var4, var5));
            }

            BlackBox.getInstance().submitEvent(new BBTeleportCommand(this.getURL()));
         } else if (var6.getServer() != this.lastroom.getServer()) {
            if (var6 != null) {
               sendToRoom(var6, new teleportCmd(var6, (byte)0, (byte)1, var2, var3, var4, var5));
               BlackBox.getInstance().submitEvent(new BBTeleportCommand(this.getURL()));
            }

            if (this.lastroom != null) {
               sendToRoom(this.lastroom, new teleportCmd(null, (byte)1, (byte)0, var2, var3, var4, var5));
            }
         } else {
            sendToRoom(this.lastroom, new roomChangeCmd(var6, var2, var3, var4, var5));
            BlackBox.getInstance().submitEvent(new BBTeleportCommand(this.getURL()));
         }

         this.lastroom = var6;
      } else if (var6 != null) {
         sendToRoom(var6, new longLocCmd(var2, var3, var4, var5));
      }

      this.positionSentTime = var1;
      this.lastx = var2;
      this.lasty = var3;
      this.lastz = var4;
      this.lastdir = var5;
      return true;
   }

   private void updateUnsubscribes() {
      int var1 = subscribers.size();

      while (--var1 >= 0) {
         if (!visibleRooms.contains(subscribers.elementAt(var1))) {
            ((Room)subscribers.elementAt(var1)).unsubscribe();
            subscribers.removeElementAt(var1);
         }
      }
   }

   public void subscribeRooms() {
      int var1 = visibleRooms.size();

      while (--var1 >= 0) {
         Room var2 = (Room)visibleRooms.elementAt(var1);
         if (!subscribers.contains(var2)) {
            RoomSubscribeInfo var3 = (RoomSubscribeInfo)visibleRoomInfo.elementAt(var1);
            var2.subscribe(var3);
         }
      }
   }

   public boolean removeSubscribedRoom(Room var1) {
      int var2 = subscribers.size();

      while (--var2 >= 0) {
         if ((Room)subscribers.elementAt(var2) == var1) {
            subscribers.removeElementAt(var2);
            return true;
         }
      }

      return false;
   }

   public void touchSubscribers() {
      int var1 = subscribers.size();

      while (--var1 >= 0) {
         ((Room)subscribers.elementAt(var1)).noteRef();
      }
   }

   private void subscriptionUpdate(boolean var1) {
      Room var2 = this.getRoom();
      int var3 = visibleRooms.size();

      while (--var3 >= 0) {
         Room var4 = (Room)visibleRooms.elementAt(var3);
         Debug.dAssert(var4.getNetworkRoom() != null);
         RoomSubscribeInfo var5 = (RoomSubscribeInfo)visibleRoomInfo.elementAt(var3);
         if (!subscribers.contains(var4)) {
            subscribers.addElement(var4);
         } else if (var1 && var4.getNetworkRoom().isServed() && var4 != var2) {
            var4.subscribeDist(var5);
         }
      }
   }

   public void property(OldPropertyList var1) {
   }

   public void propertyUpdate(PropertyList var1) {
   }

   public void register() {
   }

   public void galaxyDisconnected() {
   }

   public void reacquireServer(WorldServer var1) {
   }

   public void changeChannel(Galaxy var1, String var2, String var3) {
      sendToRoom(this.lastroom, new teleportCmd(null, (byte)1, (byte)0, this.lastx, this.lasty, this.lastz, this.lastdir));
      BlackBox.getInstance().submitEvent(new BBTeleportCommand(this.getURL()));
      this.lastroom = null;
   }

   public WorldServer getServer() {
      Room var1 = this.getLastServedRoom();
      if (var1 != null) {
         return var1.getServer();
      } else {
         return this.console == null ? null : this.console.getServerNew();
      }
   }

   public String getLongID() {
      return this.console != null ? this.console.getGalaxy().getChatname() : null;
   }

   public WObject changeRoom(Room var1, Transform var2) {
      Debug.dAssert(this == active);
      if (var1.getVIPOnly() && !var1.getWorld().getConsole().getVIP()) {
         int var5 = Std.getFastTime();
         if (var5 > lastWarning + 3000) {
            lastWarning = var5;
            Console.println(Console.message("Only-VIPs-here"));
         }

         return null;
      } else {
         Room var3 = getActiveRoom();
         if (var3 != null) {
            var3.removePostrenderHandler(BlackBox.getInstance());
            var3.removeFrameHandler(BlackBox.getInstance(), null);
         }

         Pilot var4 = changeActiveRoom(var1);
         var4.makeIdentity();
         var4.pre(var2);
         if (var3 != null) {
            var3.move(var3, var1);
         }

         if (var1 != null) {
            var1.move(var3, var1);
         }

         return var4;
      }
   }

   public static Pilot getActive() {
      return active;
   }

   public void setOutsideCameraMode(int var1, int var2) {
      this.cameraMode = var1;
      this.cameraSpeed = var2;
      if (this.getMainCamera() != null) {
         this.getMainCamera().lookAround.makeIdentity();
      }
   }

   public int getOutsideCameraMode() {
      return this.cameraMode;
   }

   public int getOutsideCameraSpeed() {
      return this.cameraSpeed;
   }

   public static Room getActiveRoom() {
      return active == null ? null : active.getRoom();
   }

   public static World getActiveWorld() {
      return active == null ? null : active.getWorld();
   }

   public abstract void resetAvatarNow();

   public static Pilot changeActiveRoom(Room var0) {
      BackgroundLoader.activeRoomChanged(var0);
      Console var1 = Console.getActive();
      Console var2 = var1;
      if (var0 != null) {
         var2 = var0.getWorld().getConsole();
      }

      Pilot var3 = var2.getPilot();
      if (var3 != active) {
         var3.transferFrom(active);
         if (var0 != null && active != null && var0 == active.getRoom()) {
            var3.makeIdentity().post(active);
         }
      }

      if (var1 != var2) {
         var2.forPilotOnlyActivate();
      }

      if (var1 != null) {
         active.detach();
      }

      active = var3;
      var3.setUpCameras(var2);
      if (var0 != null) {
         var0.add(var3);
      }

      active.resetAvatarNow();
      var2.checkCourtesyVIP();
      if (active.getWorld() != lastWorld) {
         lastWorld = active.getWorld();
         var2.displayAds();
         WorldScriptManager.getInstance().worldEntered(lastWorld.toString());
      }

      WorldScriptManager.getInstance().roomEntered(var0.toString());
      var0.addPostrenderHandler(BlackBox.getInstance());
      var0.addFrameHandler(BlackBox.getInstance(), null);
      return active;
   }

   public void changeChannel(String var1) {
      Galaxy var2 = this.console.getGalaxy();
      var2.changeChannel(var1);
   }

   private void setUpCameras(Console var1) {
      DeepEnumeration var2 = new DeepEnumeration(this.getContents());
      Enumeration var3 = var1.getParts();

      while (var3.hasMoreElements()) {
         Object var4 = var3.nextElement();
         if (var4 instanceof RenderCanvas && !(var4 instanceof AdPart)) {
            ((RenderCanvas)var4).setCamera(getNextCamera(var2));
         }
      }
   }

   public Camera getMainCamera() {
      if (this.lastCam != null) {
         SuperRoot var1 = this.lastCam.getOwner();
         if (var1 == this || var1 != null && var1.getOwner() == this) {
            return this.lastCam;
         }
      }

      return this.lastCam = getNextCamera(new DeepEnumeration(this.getContents()));
   }

   private static Camera getNextCamera(Enumeration var0) {
      while (var0.hasMoreElements()) {
         Object var1 = var0.nextElement();
         if (var1 instanceof Camera) {
            return (Camera)var1;
         }
      }

      return null;
   }

   protected void transferFrom(Pilot var1) {
      if (var1 != null) {
         this.lastx = var1.lastx;
         this.lasty = var1.lasty;
         this.lastz = var1.lastz;
         this.lastdir = var1.lastdir;
         this.lastroom = var1.lastroom;
         this.positionSentTime = var1.positionSentTime;
         Enumeration var2 = this.getHandlers();

         while (var2.hasMoreElements()) {
            Object var3 = var2.nextElement();
            if (var3 instanceof MomentumBehavior) {
               ((MomentumBehavior)var3).transferFrom(var1.getHandlers());
            }
         }

         this.getMainCamera().transferFrom(var1.getMainCamera());
      }
   }

   public boolean handle(BumpEventTemp var1) {
      this.slideBumpHandler(var1);
      return true;
   }

   public void slideBumpHandler(BumpEventTemp var1) {
      if (var1.receiver == var1.source) {
         Point3Temp var2 = Point3Temp.make(var1.bumpNormal).normalize();
         var1.postBumpPath.minus(Point3Temp.make(var2).times(var1.postBumpPath.dot(var2)));
         var1.postBumpPath.plus(Point3Temp.make(var1.bumpNormal).times(1.0E-6F));
      }
   }

   public void makeShadow() {
   }

   public void setConsole(Console var1) {
      Debug.dAssert(this.console == null);
      this.console = var1;
      copySoul(var1.getPilotSoulTemplate(), this);
   }

   private static void saveEnum(Saver var0, Enumeration var1) throws IOException {
      while (var1.hasMoreElements()) {
         Object var2 = var1.nextElement();
         if (var2 instanceof Persister && !(var2 instanceof NonPersister)) {
            var0.saveMaybeNull((Persister)var2);
         }
      }

      var0.saveMaybeNull(null);
   }

   public static void copySoul(WObject var0, WObject var1) {
      ByteArrayOutputStream var2 = new ByteArrayOutputStream();

      try {
         Saver var3 = new Saver(new DataOutputStream(var2));
         saveEnum(var3, var0.getContents());
         saveEnum(var3, var0.getHandlers());
         saveEnum(var3, var0.getActions());
         saveEnum(var3, var0.getAttributes());
         var3.done();
      } catch (Exception var5) {
         var5.printStackTrace(System.out);
         throw new Error(var5.toString());
      }

      try {
         Restorer var7 = new Restorer(new DataInputStream(new ByteArrayInputStream(var2.toByteArray())));

         Persister var4;
         while ((var4 = var7.restoreMaybeNull()) != null) {
            var1.add((Transform)var4);
         }

         while ((var4 = var7.restoreMaybeNull()) != null) {
            var1.addHandler((SuperRoot)var4);
         }

         while ((var4 = var7.restoreMaybeNull()) != null) {
            var1.addAction((Action)var4);
         }

         while ((var4 = var7.restoreMaybeNull()) != null) {
            var1.addAttribute((Attribute)var4);
         }

         var7.done();
      } catch (Exception var6) {
         var6.printStackTrace(System.out);
         throw new Error(var6.toString());
      }
   }

   protected void noteUnadding(SuperRoot var1) {
      if (var1 instanceof WObject) {
         WObject var2 = (WObject)var1;
         if (var2.isDynamic()) {
         }
      }

      super.noteUnadding(var1);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Console");
            } else if (var3 == 1) {
               var5 = this.console;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      if (this.console != null) {
         System.out.println("Warning: saving pilot " + this.getName() + " with soul, which won't restore correctly!");
      }

      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }

   static {
      nativeInit();
   }
}
