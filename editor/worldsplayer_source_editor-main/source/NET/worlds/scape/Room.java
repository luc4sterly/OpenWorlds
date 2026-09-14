package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import NET.worlds.network.Galaxy;
import NET.worlds.network.NetworkRoom;
import java.awt.Color;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class Room extends WObject implements TeleportStatus {
   public WObject highlightTarget;
   private int sceneID;
   public Point3 defaultPosition = new Point3(100.0F, 100.0F, 120.0F);
   public Point3 defaultOrientationAxis = new Point3(0.0F, 0.0F, -1.0F);
   public float defaultOrientation = 0.0F;
   String teleportChain = "home:avatargallery/avatar.world#AVATARgallery@65.0,145.0,150.0,89.0";
   int roomLoadTime = 0;
   int teleportInterval = -1;
   boolean teleported = false;
   private RoomEnvironment environment;
   private Vector outgoingPortals = new Vector();
   private Vector aFilters = new Vector();
   private Point3 lightPosition = new Point3(-1.0F, 1.0F, -1.0F);
   private Color lightColor = new Color(255, 255, 255);
   private int lightid = 0;
   private int lightid2 = 0;
   private int renderStamp;
   private static int timeoutAge = 15000;
   private Vector frameHandlers = new Vector();
   private Vector frameHandlerWObjects = new Vector();
   private Color skyColor;
   private Color groundColor;
   private Vector prerenderHandlers = new Vector();
   private Vector postrenderHandlers = new Vector();
   private static int isRendering = 4;
   private static int isVIPOnly = 262144;
   private static int isVIPViewOnly = 524288;
   private NetworkRoom _netRoom;
   private static String[] skyOptions = new String[]{"Blue Sky"};
   private static String[] groundOptions = new String[]{"Green Ground"};
   private boolean allowTeleport = true;
   private static Object classCookie = new Object();
   private RoomEnvironment infiniteBackground;

   public Room(World var1, String var2) {
      this.setName(var2);
      this.environment = new RoomEnvironment();
      this.infiniteBackground = new RoomEnvironment();
      super.add(this.environment);
      super.add(this.infiniteBackground);
      if (var1 != null) {
         var1.addRoom(this);
      }
   }

   public Room() {
   }

   public static native void nativeInit();

   public void getChildren(DeepEnumeration var1) {
      if (this.infiniteBackground != null) {
         var1.addChildElement(this.infiniteBackground);
      }

      if (this.environment != null) {
         var1.addChildElement(this.environment);
      }

      super.getChildren(var1);
   }

   public void setName(String var1) {
      String var2 = this.getName();
      super.setName(var1);
      World var3 = this.getWorld();
      if (var3 != null) {
         var3.renameRoom(var2, this.getName(), this);
      }

      if (!var2.equals(var1)) {
         synchronized (this) {
            if (this._netRoom != null) {
               this._netRoom.setName(var1);
            }
         }
      }
   }

   synchronized void register() {
      Debug.dAssert(this._netRoom == null);
      this._netRoom = new NetworkRoom(this);
   }

   public void detach() {
      if (this.hasClump()) {
         System.out.println("Detaching clumped room " + this.getName());
         this.markVoid();
      }

      Debug.dAssert(this._netRoom != null);
      boolean var1 = Pilot.getActive().removeSubscribedRoom(this);
      if (var1) {
         this._netRoom.unsubscribe();
      }

      synchronized (this) {
         this._netRoom.detach();
         this._netRoom = null;
      }

      this.getWorld().removeRoom(this);
      super.detach();
   }

   public void discard() {
      this.environment.discard();
      this.infiniteBackground.discard();
      super.discard();
      this.frameHandlers.removeAllElements();
      this.frameHandlerWObjects.removeAllElements();
      this.outgoingPortals.removeAllElements();
      this.aFilters.removeAllElements();
      this.prerenderHandlers.removeAllElements();
      this.postrenderHandlers.removeAllElements();
   }

   int getSceneID() {
      return this.sceneID;
   }

   public Point3Temp getDefaultPosition() {
      return Point3Temp.make(this.defaultPosition);
   }

   public Point3Temp getDefaultOrientationAxis() {
      return Point3Temp.make(this.defaultOrientationAxis);
   }

   public float getDefaultOrientation() {
      return this.defaultOrientation;
   }

   protected final void noteAddingTo(SuperRoot var1) {
      World var2 = (World)var1;
   }

   public RoomEnvironment getEnvironment() {
      return this.environment;
   }

   public Vector getOutgoingPortals() {
      return this.outgoingPortals;
   }

   public void addOutgoingPortal(Portal var1) {
      if (!this.outgoingPortals.contains(var1)) {
         this.outgoingPortals.addElement(var1);

         for (int var2 = 0; var2 < this.aFilters.size(); var2++) {
            ((AudibilityFilter)this.aFilters.elementAt(var2)).moveEmitter();
         }
      }
   }

   public void removeOutgoingPortal(Portal var1) {
      this.outgoingPortals.removeElement(var1);
      Vector var2 = this.getAFilters();

      for (int var3 = 0; var3 < var2.size(); var3++) {
         ((AudibilityFilter)var2.elementAt(var3)).moveEmitter();
      }
   }

   public Vector getAFilters() {
      return this.aFilters;
   }

   public void addAFilter(AudibilityFilter var1) {
      this.aFilters.addElement(var1);
   }

   public void removeAFilter(AudibilityFilter var1) {
      this.aFilters.removeElement(var1);
   }

   public void move(Room var1, Room var2) {
      Vector var3 = var1.getAFilters();

      for (int var4 = 0; var4 < var3.size(); var4++) {
         ((AudibilityFilter)var3.elementAt(var4)).updateListenerState();
      }

      var3 = var2.getAFilters();

      for (int var6 = 0; var6 < var3.size(); var6++) {
         ((AudibilityFilter)var3.elementAt(var6)).updateListenerState();
      }
   }

   static native int addLight(int var0, float var1, float var2, float var3, float var4, float var5, float var6);

   static native void setLightPosition(int var0, float var1, float var2, float var3);

   static native void setLightColor(int var0, float var1, float var2, float var3);

   private void setLightPosition(float var1, float var2, float var3) {
      if (this.lightid != 0) {
         setLightPosition(this.lightid, var1, var2, var3);
      }

      if (this.lightid2 != 0) {
         setLightPosition(this.lightid2, -var1, -var2, -var3);
      }
   }

   private void setLightColor(float var1, float var2, float var3) {
      if (this.lightid != 0) {
         setLightColor(this.lightid, var1, var2, var3);
      }

      if (this.lightid2 != 0) {
         setLightColor(this.lightid2, var1 / 2.0F, var2 / 2.0F, var3 / 2.0F);
      }
   }

   public void setLightPosition(Point3Temp var1) {
      this.lightPosition.set(var1.x, var1.y, var1.z);
      this.setLightPosition(var1.x, var1.y, var1.z);
      RoomEnvironment var2 = this.getEnvironment();
      if (var2 != null) {
         var2.setLightPosition(var1.x, var1.y, var1.z);
      }

      var2 = this.getInfiniteBackground();
      if (var2 != null) {
         var2.setLightPosition(var1.x, var1.y, var1.z);
      }
   }

   public void setLightColor(Color var1) {
      this.lightColor = new Color(var1.getRGB());
      float var2 = var1.getRed() / 256.0F;
      float var3 = var1.getGreen() / 256.0F;
      float var4 = var1.getBlue() / 256.0F;
      this.setLightColor(var2, var3, var4);
      RoomEnvironment var5 = this.getEnvironment();
      if (var5 != null) {
         var5.setLightColor(var2, var3, var4);
      }

      var5 = this.getInfiniteBackground();
      if (var5 != null) {
         var5.setLightColor(var2, var3, var4);
      }
   }

   public Point3Temp getLightPosition() {
      return Point3Temp.make(this.lightPosition);
   }

   public Color getLightColor() {
      return new Color(this.lightColor.getRGB());
   }

   public void noteRef() {
      this.renderStamp = Std.getRealTime();
      World var1 = this.getWorld();
      if (var1 != null) {
         var1.incRef();
      }
   }

   public void discardIfOld() {
      if (this.hasClump()) {
         int var1 = Std.getFastTime() - this.renderStamp;
         if (var1 > timeoutAge) {
            this.markVoid();
         }
      }
   }

   public void generateFrameEvents(FrameEvent var1) {
      this.noteRef();
      if (Main.profile != 0) {
         for (int var2 = 0; var2 < this.frameHandlers.size(); var2++) {
            FrameHandler var3 = (FrameHandler)this.frameHandlers.elementAt(var2);
            WObject var4 = (WObject)this.frameHandlerWObjects.elementAt(var2);
            int var5 = Std.getRealTime();
            long var6 = Runtime.getRuntime().freeMemory();
            var1.retargetAndDeliver(var3, var4);
            int var8 = Std.getRealTime() - var5;
            long var9 = var6 - Runtime.getRuntime().freeMemory();
            if (var8 > Main.profile) {
               if (var3 instanceof SuperRoot) {
                  System.out
                     .println("Took " + var8 + "ms and " + var9 + " bytes to call frameHandler " + ((SuperRoot)var3).getName() + " of " + var4.getName());
               } else {
                  System.out.println("Took " + var8 + "ms and " + var9 + " bytes to call frameHandler " + var3 + " of " + var4.getName());
               }
            }
         }
      } else {
         for (int var11 = 0; var11 < this.frameHandlers.size(); var11++) {
            var1.retargetAndDeliver((FrameHandler)this.frameHandlers.elementAt(var11), (WObject)this.frameHandlerWObjects.elementAt(var11));
         }
      }

      if (this.teleportChain != null && this.teleportInterval != -1 && !this.teleported && Std.getSynchronizedTime() % this.teleportInterval == 0) {
         this.teleported = true;
         TeleportAction.teleport(this.teleportChain, this);
      }
   }

   public void teleportStatus(String var1, String var2) {
      if (var1 != null) {
         this.teleported = false;
      }
   }

   private int findFrameHandler(FrameHandler var1, WObject var2) {
      int var4 = 0;

      while (true) {
         var4 = this.frameHandlers.indexOf(var1, var4);
         if (var4 == -1) {
            return -1;
         }

         if (this.frameHandlerWObjects.elementAt(var4) == var2) {
            return var4;
         }

         var4++;
      }
   }

   void addFrameHandler(FrameHandler var1, WObject var2) {
      int var3 = this.findFrameHandler(var1, var2);
      if (var3 < 0) {
         this.frameHandlers.addElement(var1);
         this.frameHandlerWObjects.addElement(var2);
      }
   }

   void removeFrameHandler(FrameHandler var1, WObject var2) {
      int var3 = this.findFrameHandler(var1, var2);
      if (var3 >= 0) {
         this.frameHandlers.removeElementAt(var3);
         this.frameHandlerWObjects.removeElementAt(var3);
      }
   }

   native void createScene();

   native void destroyScene();

   protected void markVoid() {
      this.infiniteBackground.markVoid();
      this.environment.markVoid();
      super.markVoid();
      this.destroyScene();
      this.lightid = 0;
      this.lightid2 = 0;
   }

   protected void noteTransformChange() {
      super.noteTransformChange();
      this.getInfiniteBackground().setTransform(this);
      this.getEnvironment().setTransform(this);
      int var1 = this.outgoingPortals.size();

      while (--var1 >= 0) {
         ((Portal)this.outgoingPortals.elementAt(var1)).discardTransform();
      }
   }

   public void setSkyColor(Color var1) {
      this.skyColor = var1;
   }

   public Color getSkyColor() {
      return this.skyColor;
   }

   public void setGroundColor(Color var1) {
      this.groundColor = var1;
   }

   public Color getGroundColor() {
      return this.groundColor;
   }

   public boolean getVIPOnly() {
      return (this.flags & isVIPOnly) != 0;
   }

   public void prerender(Camera var1, float var2, float var3, float var4, float var5) {
      this.flags = this.flags | isRendering;
      this.infiniteBackground.prerender();
      this.environment.prerender();
      Pilot.addVisibleRoom(this, var2, var3, var4, var5);
      int var6 = this.prerenderHandlers.size();

      for (int var7 = 0; var7 < var6; var7++) {
         Prerenderable var8 = (Prerenderable)this.prerenderHandlers.elementAt(var7);
         var8.prerender(var1);
      }
   }

   public void addPrerenderHandler(Prerenderable var1) {
      Debug.assert_((this.flags & isRendering) == 0);
      if (!this.prerenderHandlers.contains(var1)) {
         this.prerenderHandlers.addElement(var1);
      }
   }

   public void prependPrerenderHandler(Prerenderable var1) {
      Debug.assert_((this.flags & isRendering) == 0);
      if (!this.prerenderHandlers.contains(var1)) {
         this.prerenderHandlers.insertElementAt(var1, 0);
      }
   }

   public void removePrerenderHandler(Prerenderable var1) {
      Debug.assert_((this.flags & isRendering) == 0);
      this.prerenderHandlers.removeElement(var1);
   }

   public void postrender(Camera var1, float var2, float var3, float var4, float var5) {
      Pilot.addVisibleRoom(this, var2, var3, var4, var5);
      int var6 = this.postrenderHandlers.size();

      while (--var6 >= 0) {
         Postrenderable var7 = (Postrenderable)this.postrenderHandlers.elementAt(var6);
         var7.postrender(var1);
      }

      this.flags = this.flags & ~isRendering;
   }

   public void addPostrenderHandler(Postrenderable var1) {
      Debug.assert_((this.flags & isRendering) == 0);
      if (!this.postrenderHandlers.contains(var1)) {
         this.postrenderHandlers.addElement(var1);
      }
   }

   public void prependPostrenderHandler(Postrenderable var1) {
      Debug.assert_((this.flags & isRendering) == 0);
      if (!this.postrenderHandlers.contains(var1)) {
         this.postrenderHandlers.insertElementAt(var1, 0);
      }
   }

   public void removePostrenderHandler(Postrenderable var1) {
      Debug.assert_((this.flags & isRendering) == 0);
      this.postrenderHandlers.removeElement(var1);
   }

   public void detectBump(BumpEventTemp var1) {
      if (this.environment.getBumpable()) {
         this.environment.detectBump(var1);
      }

      super.detectBump(var1);
   }

   public BoundBoxTemp getBoundBox() {
      return BoundBoxTemp.make(Point3Temp.make(), Point3Temp.make());
   }

   public World getWorld() {
      return (World)this.getOwner();
   }

   public Room getRoom() {
      return this;
   }

   public Room getRoomFromClump() {
      return this;
   }

   public Room getRoomNotFromClump() {
      return this;
   }

   public Galaxy getGalaxy() {
      World var1 = this.getWorld();
      return var1 == null ? null : var1.getConsole().getGalaxy();
   }

   public String getURL() {
      return this.getWorld().getSourceURL().getAbsolute() + "#" + this.getName();
   }

   public boolean registerShare(WObject var1) {
      var1.notifyRegister(1);
      return true;
   }

   private void processPendingRegistrations() {
      this.notifyRegister(1);
   }

   public NetworkRoom getNetworkRoom() {
      return this._netRoom;
   }

   void subscribe(RoomSubscribeInfo var1) {
      Debug.dAssert(this._netRoom != null);
      this._netRoom.subscribe(var1);
   }

   void subscribeDist(RoomSubscribeInfo var1) {
      Debug.dAssert(this._netRoom != null);
      this._netRoom.subscribeDist(var1);
   }

   void unsubscribe() {
      if (this._netRoom != null) {
         this._netRoom.unsubscribe();
      } else {
         System.out.println(this + ": unsubscribing from bad room?");
         new Exception().printStackTrace(System.out);
      }
   }

   public boolean getAllowTeleport() {
      return this.allowTeleport;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Environment");
            } else if (var3 == 1) {
               var5 = this.environment;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Infinite Background");
            } else if (var3 == 1) {
               var5 = this.infiniteBackground;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = ColorPropertyEditor.make(new Property(this, var1, "Sky Color").allowSetNull());
               if (this.getSkyColor() == null) {
                  var5 = MaybeNullPropertyEditor.make((Property)var5, Color.blue);
               }
            } else if (var3 == 1) {
               var5 = this.getSkyColor();
            } else if (var3 == 2) {
               this.setSkyColor((Color)var4);
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = ColorPropertyEditor.make(new Property(this, var1, "Ground Color").allowSetNull());
               if (this.getGroundColor() == null) {
                  var5 = MaybeNullPropertyEditor.make((Property)var5, Color.green);
               }
            } else if (var3 == 1) {
               var5 = this.getGroundColor();
            } else if (var3 == 2) {
               this.setGroundColor((Color)var4);
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Default Position"));
            } else if (var3 == 1) {
               var5 = new Point3(this.getDefaultPosition());
            } else if (var3 == 2) {
               this.defaultPosition = (Point3)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Default Orientation Axis"));
            } else if (var3 == 1) {
               var5 = new Point3(this.getDefaultOrientationAxis());
            } else if (var3 == 2) {
               this.defaultOrientationAxis = (Point3)var4;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Default Orientation Angle"));
            } else if (var3 == 1) {
               var5 = new Float(this.getDefaultOrientation());
            } else if (var3 == 2) {
               this.defaultOrientation = (Float)var4;
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "VIP only"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean((this.flags & isVIPOnly) != 0);
            } else if (var3 == 2) {
               if ((Boolean)var4) {
                  this.flags = this.flags | isVIPOnly;
               } else {
                  this.flags = this.flags & ~isVIPOnly;
               }
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Visible to VIP only"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean((this.flags & isVIPViewOnly) != 0);
            } else if (var3 == 2) {
               if ((Boolean)var4) {
                  this.flags = this.flags | isVIPViewOnly;
               } else {
                  this.flags = this.flags & ~isVIPViewOnly;
               }
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Light Source Direction"));
            } else if (var3 == 1) {
               var5 = this.lightPosition;
            } else if (var3 == 2) {
               this.setLightPosition((Point3)var4);
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = ColorPropertyEditor.make(new Property(this, var1, "Light Color"));
            } else if (var3 == 1) {
               var5 = this.lightColor;
            } else if (var3 == 2) {
               this.setLightColor((Color)var4);
            }
            break;
         case 11:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Time To Auto-Teleport (seconds, -1 = never)"));
            } else if (var3 == 1) {
               var5 = new Integer(this.teleportInterval);
            } else if (var3 == 2) {
               this.teleportInterval = (Integer)var4;
            }
            break;
         case 12:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Auto-Teleport destination"));
            } else if (var3 == 1) {
               var5 = this.teleportChain;
            } else if (var3 == 2) {
               this.teleportChain = new String((String)var4);
            }
            break;
         case 13:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Allow Teleporting"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.allowTeleport);
            } else if (var3 == 2) {
               this.allowTeleport = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 14, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(7, classCookie);
      super.saveState(var1);
      if (this.skyColor != null) {
         var1.saveBoolean(true);
         var1.saveInt(this.skyColor.getRGB());
      } else {
         var1.saveBoolean(false);
      }

      if (this.groundColor != null) {
         var1.saveBoolean(true);
         var1.saveInt(this.groundColor.getRGB());
      } else {
         var1.saveBoolean(false);
      }

      var1.save(this.defaultPosition);
      var1.save(this.defaultOrientationAxis);
      var1.saveFloat(this.defaultOrientation);
      var1.save(this.lightPosition);
      var1.saveInt(this.lightColor.getRGB());
      var1.save(this.environment);
      var1.save(this.infiniteBackground);
      var1.saveString(this.teleportChain);
      var1.saveInt(this.teleportInterval);
      var1.saveBoolean(this.allowTeleport);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            var1.setOldFlag();
            super.restoreState(var1);
            this.setName(var1.restoreString());
            var1.restore();
            if (var1.restoreBoolean()) {
               this.skyColor = new Color(var1.restoreInt());
            }

            if (var1.restoreBoolean()) {
               this.groundColor = new Color(var1.restoreInt());
            }

            var1.restoreMaybeNull();
            this.defaultPosition = (Point3)var1.restore();
            this.defaultOrientationAxis = (Point3)var1.restore();
            this.defaultOrientation = var1.restoreFloat();
            var1.restoreVector();
            this.environment = (RoomEnvironment)var1.restore();
            this.infiniteBackground = new RoomEnvironment();
            break;
         case 1:
            var1.setOldFlag();
            super.restoreState(var1);
            var1.restore();
            if (var1.restoreBoolean()) {
               this.skyColor = new Color(var1.restoreInt());
            }

            if (var1.restoreBoolean()) {
               this.groundColor = new Color(var1.restoreInt());
            }

            var1.restoreMaybeNull();
            this.defaultPosition = (Point3)var1.restore();
            this.defaultOrientationAxis = (Point3)var1.restore();
            this.defaultOrientation = var1.restoreFloat();
            this.environment = (RoomEnvironment)var1.restore();
            this.infiniteBackground = new RoomEnvironment();
            break;
         case 2:
            var1.setOldFlag();
            super.restoreState(var1);
            if (var1.restoreBoolean()) {
               this.skyColor = new Color(var1.restoreInt());
            }

            if (var1.restoreBoolean()) {
               this.groundColor = new Color(var1.restoreInt());
            }

            var1.restoreMaybeNull();
            this.defaultPosition = (Point3)var1.restore();
            this.defaultOrientationAxis = (Point3)var1.restore();
            this.defaultOrientation = var1.restoreFloat();
            this.environment = (RoomEnvironment)var1.restore();
            this.infiniteBackground = new RoomEnvironment();
            break;
         case 3:
            var1.setOldFlag();
            super.restoreState(var1);
            if (var1.restoreBoolean()) {
               this.skyColor = new Color(var1.restoreInt());
            }

            if (var1.restoreBoolean()) {
               this.groundColor = new Color(var1.restoreInt());
            }

            var1.restoreMaybeNull();
            this.defaultPosition = (Point3)var1.restore();
            this.defaultOrientationAxis = (Point3)var1.restore();
            this.defaultOrientation = var1.restoreFloat();
            this.environment = (RoomEnvironment)var1.restore();
            this.infiniteBackground = (RoomEnvironment)var1.restore();
            break;
         case 4:
            var1.setOldFlag();
            super.restoreState(var1);
            if (var1.restoreBoolean()) {
               this.skyColor = new Color(var1.restoreInt());
            }

            if (var1.restoreBoolean()) {
               this.groundColor = new Color(var1.restoreInt());
            }

            this.defaultPosition = (Point3)var1.restore();
            this.defaultOrientationAxis = (Point3)var1.restore();
            this.defaultOrientation = var1.restoreFloat();
            this.environment = (RoomEnvironment)var1.restore();
            this.infiniteBackground = (RoomEnvironment)var1.restore();
            break;
         case 5:
            super.restoreState(var1);
            if (var1.restoreBoolean()) {
               this.skyColor = new Color(var1.restoreInt());
            }

            if (var1.restoreBoolean()) {
               this.groundColor = new Color(var1.restoreInt());
            }

            this.defaultPosition = (Point3)var1.restore();
            this.defaultOrientationAxis = (Point3)var1.restore();
            this.defaultOrientation = var1.restoreFloat();
            this.setLightPosition((Point3)var1.restore());
            this.setLightColor(new Color(var1.restoreInt()));
            this.environment = (RoomEnvironment)var1.restore();
            this.infiniteBackground = (RoomEnvironment)var1.restore();
            break;
         case 6:
            super.restoreState(var1);
            if (var1.restoreBoolean()) {
               this.skyColor = new Color(var1.restoreInt());
            }

            if (var1.restoreBoolean()) {
               this.groundColor = new Color(var1.restoreInt());
            }

            this.defaultPosition = (Point3)var1.restore();
            this.defaultOrientationAxis = (Point3)var1.restore();
            this.defaultOrientation = var1.restoreFloat();
            this.setLightPosition((Point3)var1.restore());
            this.setLightColor(new Color(var1.restoreInt()));
            this.environment = (RoomEnvironment)var1.restore();
            this.infiniteBackground = (RoomEnvironment)var1.restore();
            this.teleportChain = var1.restoreString();
            this.teleportInterval = var1.restoreInt();
            this.roomLoadTime = Std.getFastTime() / 1000;
            break;
         case 7:
            super.restoreState(var1);
            if (var1.restoreBoolean()) {
               this.skyColor = new Color(var1.restoreInt());
            }

            if (var1.restoreBoolean()) {
               this.groundColor = new Color(var1.restoreInt());
            }

            this.defaultPosition = (Point3)var1.restore();
            this.defaultOrientationAxis = (Point3)var1.restore();
            this.defaultOrientation = var1.restoreFloat();
            this.setLightPosition((Point3)var1.restore());
            this.setLightColor(new Color(var1.restoreInt()));
            this.environment = (RoomEnvironment)var1.restore();
            this.infiniteBackground = (RoomEnvironment)var1.restore();
            this.teleportChain = var1.restoreString();
            this.teleportInterval = var1.restoreInt();
            this.roomLoadTime = Std.getFastTime() / 1000;
            this.allowTeleport = var1.restoreBoolean();
            break;
         default:
            throw new TooNewException();
      }

      super.add(this.environment);
      super.add(this.infiniteBackground);
   }

   public void aboutToDraw() {
      if (!this.hasClump() && this.getOwner() instanceof World) {
         this.recursiveAddRwChildren(null);
      }
   }

   protected void addRwChildren(WObject var1) {
      Debug.dAssert(var1 == null);
      this.createClump();
      this.createScene();
      this.newRwChildHelper();
      float var2 = this.lightColor.getRed() / 256.0F;
      float var3 = this.lightColor.getGreen() / 256.0F;
      float var4 = this.lightColor.getBlue() / 256.0F;
      this.lightid = addLight(this.sceneID, this.lightPosition.x, this.lightPosition.y, this.lightPosition.z, var2, var3, var4);
      this.lightid2 = addLight(this.sceneID, -this.lightPosition.x, -this.lightPosition.y, -this.lightPosition.z, var2 * 0.5F, var3 * 0.5F, var4 * 0.5F);
   }

   public void recursiveAddRwChildren(WObject var1) {
      super.recursiveAddRwChildren(var1);
      this.environment.recursiveAddRwChildren(this);
      this.infiniteBackground.recursiveAddRwChildren(this);
   }

   public final float floorHeight(float var1, float var2) {
      return this.floorHeight(var1, var2, 120.0F);
   }

   public float floorHeight(float var1, float var2, float var3) {
      Transform var4 = this.getObjectToWorldMatrix().invert();
      Point3Temp var5 = Point3Temp.make(var1, var2, var3).times(var4);
      var4.recycle();
      var1 = var5.x;
      var2 = var5.y;
      var3 = var5.z;
      float var6 = 0.0F;
      boolean var7 = false;
      Enumeration var8 = this.getContents();

      while (var8.hasMoreElements()) {
         Object var9 = var8.nextElement();
         if (var9 instanceof FloorPatch && ((FloorPatch)var9).inPatch(var1, var2)) {
            float var10 = ((FloorPatch)var9).floorHeight(var1, var2);
            if (var10 <= var3 && (var10 > var6 || !var7)) {
               var7 = true;
               var6 = ((FloorPatch)var9).floorHeight(var1, var2);
            }
         }
      }

      return var6;
   }

   public Point3 surfaceNormal(float var1, float var2, float var3) {
      Point3 var4 = new Point3(0.0F, 0.0F, 1.0F);
      FloorPatch var5 = null;
      float var6 = 0.0F;
      boolean var7 = false;
      Enumeration var8 = this.getContents();

      while (var8.hasMoreElements()) {
         Object var9 = var8.nextElement();
         if (var9 instanceof FloorPatch && ((FloorPatch)var9).inPatch(var1, var2)) {
            float var10 = ((FloorPatch)var9).floorHeight(var1, var2);
            if (var10 <= var3 && (var10 > var6 || !var7)) {
               var7 = true;
               var6 = ((FloorPatch)var9).floorHeight(var1, var2);
               var5 = (FloorPatch)var9;
            }
         }
      }

      if (var5 != null) {
         var4 = var5.surfaceNormal(var1, var2);
      }

      var4.vectorTimes(this.getObjectToWorldMatrix());
      return var4;
   }

   public RoomEnvironment getInfiniteBackground() {
      return this.infiniteBackground;
   }

   public String toString() {
      return this.getWorld() + "#" + this.getName();
   }

   static {
      nativeInit();
   }
}
