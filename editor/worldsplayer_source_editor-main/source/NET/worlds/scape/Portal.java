package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.core.Debug;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import java.awt.Color;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Vector;

public class Portal extends Rect implements BumpHandler, Prerenderable, Postrenderable, Properties, Persister, LoadedURLSelf {
   static final int UNCONNECTED = -1;
   static final int INITIAL = 0;
   static final int DOWNLOADING = 1;
   static final int DONE = 2;
   private int _state = -1;
   private Portal _farSidePortal = null;
   String _farSidePortalName = null;
   private boolean _farSideIsPortal = true;
   private boolean _allowDownload = true;
   String _farSideRoomName = null;
   private URL _farSideWorld = null;
   private Room _farSideRoom = null;
   private float _farx;
   private float _fary;
   private float _farz;
   private float _fartheta;
   private float _userFarx;
   private float _userFary;
   private float _userFarz;
   private float _userFartheta;
   private boolean frozeFrameEvents;
   private Transform _p2pxform = null;
   private int _changeNum = 0;
   private int _farChangeNum = -1;
   static BumpCalc standardPassthroughBumpCalc = new PassthroughBumpCalc();
   private static Object classCookie = new Object();

   protected Room getFarSideRoom() {
      return this._farSideRoom;
   }

   public Portal(float var1, float var2) {
      super(var1, var2, null);
   }

   public Portal(float var1, float var2, float var3, float var4, float var5, float var6) {
      super(var1, var2, var3, var4, var5, var6, null);
   }

   public Portal() {
   }

   public void setFarSideInfo(URL var1, String var2, String var3) {
      this._farSideWorld = var1;
      this._farSideRoomName = var2;
      this._farSidePortalName = var3;
   }

   public Portal(Point3Temp var1, Point3Temp var2) {
      super(var1, var2, null);
   }

   public static Portal findByName(Room var0, String var1) {
      SuperRoot var2 = SuperRoot.nameSearch(var0.getDeepOwned(), var1);
      return var2 != null && var2 instanceof Portal ? (Portal)var2 : null;
   }

   public Portal connectTo(Portal var1) {
      Debug.assert_(this._state == -1);
      this._farSideIsPortal = true;
      this._farSidePortal = var1;
      this.newFarSide();
      return this;
   }

   public Portal connectTo(URL var1, String var2, Point3Temp var3, Point3Temp var4) {
      return this.connectTo(var1, var2, var3.x, var3.y, var3.z, var4.x, var4.y, var4.z);
   }

   public Portal connectTo(Room var1, Point3Temp var2, Point3Temp var3) {
      System.out.println("Warning! Old style Portal.connectTo called!");
      Thread.dumpStack();
      Debug.assert_(this._state == -1);
      this._farSideWorld = var1.getWorld().getSourceURL();
      this._farSideRoomName = var1.getName();
      this.setFarSideRoom(var1);
      this._farx = this._userFarx = var3.x;
      this._fary = this._userFary = var3.y;
      this._farz = this._userFarz = var2.z;
      this._userFartheta = (float)(Math.atan2(var2.y - var3.y, var2.x - var3.x) * 180.0 / Math.PI);
      this._fartheta = this._userFartheta;
      this._state = 2;
      this._farSideIsPortal = false;
      this.setTransform();
      this.updateVisible();
      return this;
   }

   public Portal connectTo(URL var1, String var2, float var3, float var4, float var5, float var6, float var7, float var8) {
      float var9 = (float)(Math.atan2(var4 - var7, var3 - var6) * 180.0 / Math.PI);
      return this.connectTo(var1, var2, var6, var7, var5, var9);
   }

   public Portal connectTo(URL var1, String var2, float var3, float var4, float var5, float var6) {
      Debug.assert_(this._state == -1);
      this._farSideWorld = var1;
      this._farSideRoomName = var2;
      this._farx = this._userFarx = var3;
      this._fary = this._userFary = var4;
      this._farz = this._userFarz = var5;
      this._fartheta = this._userFartheta = var6;
      this._farSideIsPortal = false;
      this.reset();
      return this;
   }

   public Portal remotify() {
      RPAction var1 = new RPAction();
      this.addAction(var1);
      this.addHandler(new SameRoomSensor(var1));
      return this;
   }

   private void findFarSidePortal(boolean var1) {
      if (this._farSideIsPortal) {
         if (this._farSidePortalName == null) {
            this._state = -1;
         } else {
            this._farSidePortal = null;
            Vector var2 = this._farSideRoom.getOutgoingPortals();
            int var3 = var2.size();

            for (int var4 = 0; var4 < var3; var4++) {
               Portal var5 = (Portal)var2.elementAt(var4);
               if (var5.getName().equals(this._farSidePortalName)) {
                  this._farSidePortal = var5;
                  break;
               }
            }

            if (this._farSidePortal == null) {
               if (var1) {
                  Object[] var6 = new Object[]{
                     new String(this.getName()), new String("" + this._farSideWorld), new String(this._farSideRoomName), new String(this._farSidePortalName)
                  };
                  Console.println(MessageFormat.format(Console.message("Portal-doesnt"), var6));
               }

               this._state = -1;
            }
         }

         if (this._farSidePortal != null) {
            this.newFarSide();
         }
      } else {
         this._farSidePortal = null;
         this._farx = this._userFarx;
         this._fary = this._userFary;
         this._farz = this._userFarz;
         this._fartheta = this._userFartheta;
         this._p2pxform = null;
      }
   }

   public void reset() {
      this.reset(true);
   }

   public void reset(boolean var1) {
      this.setFarSideRoom(null);
      if (this._farSideRoomName == null || (this.flags & 262144) != 0) {
         this._state = -1;
      } else if (this._farSideWorld == null) {
         Room var2 = this.getRoom();
         if (var2 != null) {
            World var3 = var2.getWorld();
            if (var3 != null) {
               this.setFarSideRoom(var3.getRoom(this._farSideRoomName));
            }
         }

         if (this._farSideRoom != null) {
            this.findFarSidePortal(var1);
         } else {
            this._state = -1;
            this._farSidePortal = null;
            if (var1) {
               Object[] var4 = new Object[]{
                  new String(this.getName()), new String("" + this.getRoom()), new String(this._farSideRoomName), new String(this._farSidePortalName)
               };
               Console.println(MessageFormat.format(Console.message("Room-doesnt"), var4));
            }
         }
      } else {
         if (this._farSidePortalName == null) {
            this._farSidePortal = null;
         }

         this._state = 0;
      }

      this.setTransform();
      this.updateVisible();
   }

   public void discard() {
      Portal var1 = this._farSidePortal;
      this.setFarSideRoom(null);
      this._state = 0;
      super.discard();
      if (var1 != null && var1.getRoom() != null && this._farSideWorld != null) {
         var1.reset();
      }
   }

   private void recomputeFarPosition() {
      this.setFarSideRoom(this._farSidePortal.getRoom());
      if (this._farSideRoom != null) {
         this._farSideRoomName = this._farSideRoom.getName();
      }

      this._farSidePortalName = this._farSidePortal.getName();
      Point3Temp var1 = Point3Temp.make(1.0F, 0.0F, 1.0F).vectorTimes(this._farSidePortal);
      Point3Temp var2 = this._farSidePortal.getPosition();
      if ((this.flags & 4) == 0) {
         var2.x = var2.x + var1.x;
         var2.y = var2.y + var1.y;
      }

      this._farx = var2.x;
      this._fary = var2.y;
      this._farz = var2.z;
      this._fartheta = (-this._farSidePortal.getYaw() + 180.0F) % 360.0F;
      this._farChangeNum = this._farSidePortal._changeNum;
      this._p2pxform = null;
   }

   public Portal biconnect(Portal var1) {
      this.connectTo(var1);
      var1.connectTo(this);
      return this;
   }

   public void disconnect() {
      this._farSideWorld = null;
      this._farSideRoomName = null;
      this.setFarSideRoom(null);
      this._farSidePortal = null;
      this._farSideIsPortal = true;
      this._farSidePortalName = null;
      this._state = -1;
      this.updateVisible();
      this.discardTransform();
   }

   public void bidisconnect() {
      this._farSidePortal.disconnect();
      this.disconnect();
   }

   public boolean connected() {
      return this._farSidePortal != null || this._farSideRoomName != null && !this._farSideIsPortal;
   }

   public boolean active() {
      return this._state == 2;
   }

   public boolean unconnected() {
      return this._state == -1;
   }

   public boolean remote() {
      return this._farSideWorld != null;
   }

   public Portal farSide() {
      return this._farSideIsPortal ? this._farSidePortal : null;
   }

   public Room farSideRoom() {
      return this._farSideRoom;
   }

   private void setFarSideRoom(Room var1) {
      this._farSideRoom = var1;
   }

   protected void noteAddingTo(SuperRoot var1) {
      this.addToRoom(var1);
      super.noteAddingTo(var1);
   }

   private void addToRoom(SuperRoot var1) {
      if (var1 instanceof WObject) {
         Room var2 = ((WObject)var1).getRoom();
         if (var2 != null) {
            var2.addOutgoingPortal(this);
         }
      }
   }

   public void detach() {
      Room var1 = this.getRoom();
      if (var1 != null) {
         var1.removeOutgoingPortal(this);
      }

      super.detach();
   }

   public String farRoom() {
      return this._farSideRoomName;
   }

   public URL farWorld() {
      return this._farSideWorld;
   }

   public Transform p2pXform() {
      return this._p2pxform;
   }

   protected void addRwChildren(WObject var1) {
      if (this._farSidePortal != null && this._farSidePortal instanceof TwoWayPortal && !this._farSidePortal.isActive()) {
         Main.register(new Portal$1(this));
      }

      super.addRwChildren(var1);
      this.updateVisible();
      this.setTransform();
      this.getRoom().prependPrerenderHandler(this);
      this.getRoom().prependPostrenderHandler(this);
   }

   protected void markVoid() {
      this.getRoom().removePrerenderHandler(this);
      this.getRoom().removePostrenderHandler(this);
      super.markVoid();
   }

   protected void noteTransformChange() {
      this._changeNum++;
      super.noteTransformChange();
      this.discardTransform();
   }

   public static native void nativeInit();

   protected native void updateVisible();

   native void setTransform();

   public void discardTransform() {
      if (this._p2pxform != null) {
         this._p2pxform = null;
         if (this._farSidePortal != null) {
            this._farSidePortal.discardTransform();
         }
      }
   }

   public native void prerender(Camera var1);

   public native void postrender(Camera var1);

   public BumpCalc getBumpCalc(BumpEventTemp var1) {
      if (this._farSidePortal == null
         || !(var1.source instanceof Camera)
         || (this.flags & 4) == 0 && this._farSidePortal.active() && this._farSidePortal._p2pxform != null && this._farSidePortal.getVisible()) {
         if (this.bumpCalc != null) {
            return this.bumpCalc;
         }

         if (this._farSideRoomName == null) {
            return standardPassthroughBumpCalc;
         }

         if (this.connected() && (this.flags & 262144) == 0) {
            if (this._farSideRoom == null && this._farSideIsPortal && this._farSidePortal != null) {
               this.setFarSideRoom(this._farSidePortal.getRoom());
            }

            if (this._farSideRoom != null && this._farSideRoom.isActive()) {
               return standardPassthroughBumpCalc;
            }
         }

         return super.getBumpCalc(var1);
      } else {
         return super.getBumpCalc(var1);
      }
   }

   public boolean handle(BumpEventTemp var1) {
      if (this._farSidePortal == null
         || !(var1.source instanceof Camera)
         || (this.flags & 4) == 0 && this._farSidePortal.active() && this._farSidePortal._p2pxform != null && this._farSidePortal.getVisible()) {
         this.portalBumpHandler(var1);
         return true;
      } else {
         return true;
      }
   }

   public void portalBumpHandler(BumpEventTemp var1) {
      if (var1.target == this && this._state == 2) {
         if (this._farSideRoom == null && this._farSideIsPortal && this._farSidePortal != null) {
            this.setFarSideRoom(this._farSidePortal.getRoom());
         }

         if (this._farSideRoom != null && this._farSideRoom.isActive()) {
            if (this._p2pxform == null) {
               this.setTransform();
               if (this._p2pxform == null) {
                  return;
               }
            }

            var1.postBumpRoom = this._farSideRoom;
            Transform var2 = ((WObject)var1.source).getObjectToWorldMatrix();
            var1.postBumpPosition.setTransform(var2);
            var2.recycle();
            var1.postBumpPosition.moveBy(var1.path).post(this._p2pxform);
            var1.postBumpPath = new Point3(var1.fullPath).times(1.0F - var1.fraction).vectorTimes(this._p2pxform);
         }
      } else {
         if (this._state == 1 && this._farSideWorld != null && !this._farSideWorld.isRemote() && !this.frozeFrameEvents) {
            this.frozeFrameEvents = true;
            Console.setFreezeFrameEvents(true);
         }
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Destination World URL (null means this world)").allowSetNull(), "world");
            } else if (var3 == 1) {
               var5 = this._farSideWorld;
            } else if (var3 == 2) {
               this._farSideWorld = (URL)var4;
               this.reset();
               this.triggerLoad();
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Destination Room Name").allowSetNull());
            } else if (var3 == 1) {
               var5 = this._farSideRoomName == null ? "" : this._farSideRoomName;
            } else if (var3 == 2) {
               this._farSideRoomName = (String)var4;
               if ("".equals(this._farSideRoomName)) {
                  this._farSideRoomName = null;
               }

               this.reset();
               this.triggerLoad();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Connect to a portal"), "Use location and orientation", "Use portal");
            } else if (var3 == 1) {
               var5 = new Boolean(this._farSideIsPortal);
            } else if (var3 == 2) {
               boolean var8 = (Boolean)var4;
               this._farSideIsPortal = var8;
               this.reset();
               this.triggerLoad();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Download if world not present"), "Never download", "Allow download");
            } else if (var3 == 1) {
               var5 = new Boolean(this._allowDownload);
            } else if (var3 == 2) {
               boolean var7 = (Boolean)var4;
               this._allowDownload = var7;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Destination Portal Name");
               if (this._farSideIsPortal) {
                  var5 = StringPropertyEditor.make((Property)var5);
               }
            } else if (var3 == 1) {
               var5 = this._farSidePortalName == null ? "" : this._farSidePortalName;
            } else if (var3 == 2) {
               this._farSidePortalName = (String)var4;
               if ("".equals(this._farSidePortalName)) {
                  this._farSidePortalName = null;
               }

               this.reset();
               this.triggerLoad();
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Destination position");
               if (!this._farSideIsPortal) {
                  var5 = Point3PropertyEditor.make((Property)var5);
               }
            } else if (var3 == 1) {
               var5 = new Point3(this._userFarx, this._userFary, this._userFarz);
            } else if (var3 == 2) {
               Point3 var6 = (Point3)var4;
               this._farx = this._userFarx = var6.x;
               this._fary = this._userFary = var6.y;
               this._farz = this._userFarz = var6.z;
               this.reset();
               this.triggerLoad();
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Destination orientation (degrees, clockwise from North)");
               if (!this._farSideIsPortal) {
                  var5 = FloatPropertyEditor.make((Property)var5, 0.0F, 360.0F);
               }
            } else if (var3 == 1) {
               var5 = new Float(this._userFartheta);
            } else if (var3 == 2) {
               this._fartheta = this._userFartheta = (Float)var4;
               this.reset();
               this.triggerLoad();
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Mirrored"), "Normal", "Mirrored");
            } else if (var3 == 1) {
               var5 = new Boolean((this.flags & 4) != 0);
            } else if (var3 == 2) {
               if ((Boolean)var4) {
                  this.flags |= 4;
               } else {
                  this.flags &= -5;
               }

               this.reset();
               this.triggerLoad();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 8, var3, var4);
      }

      return var5;
   }

   private void newFarSide() {
      this._farSidePortalName = this._farSidePortal.getName();
      if (this._state == -1 && (this.flags & 262144) == 0) {
         this._state = 2;
      }

      this.recomputeFarPosition();
      this.setTransform();
      this.updateVisible();
   }

   public void saveState(Saver var1) throws IOException {
      Portal var2 = null;
      if (this._farSideWorld != null || this._farSidePortal != null && (!this._farSidePortal.isActive() || this._farSidePortal instanceof NonPersister)) {
         var2 = this._farSidePortal;
         this._farSidePortal = null;
      }

      var1.saveVersion(9, classCookie);
      super.saveState(var1);
      var1.saveBoolean(this._farSideIsPortal);
      var1.saveBoolean(this._allowDownload);
      var1.saveString(this._farSidePortalName);
      var1.saveMaybeNull(this._farSidePortal);
      URL.save(var1, this._farSideWorld);
      var1.saveString(this._farSideRoomName);
      var1.saveFloat(this._userFarx);
      var1.saveFloat(this._userFary);
      var1.saveFloat(this._userFarz);
      var1.saveFloat(this._userFartheta);
      if (var2 != null) {
         this._farSidePortal = var2;
      }
   }

   public void superRestoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreWObjectState(var1);
      this.setMaterial(new Material(Color.black));
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      float var2 = 0.0F;
      float var3 = 0.0F;
      float var4 = 0.0F;
      int var5 = var1.restoreVersion(classCookie);
      switch (var5) {
         case 0:
         case 1:
         case 2:
         case 3:
         case 4:
         case 5:
         case 6:
         case 7:
            var1.setOldFlag();
            this.superRestoreState(var1);
            if (var5 < 6) {
               if (var5 == 0) {
                  var1.restoreInt();
               }

               var2 = var1.restoreFloat();
               var3 = var1.restoreFloat();
               var4 = var1.restoreFloat();
               this.scale(var2, 1.0F, var4);
            }

            if (var1.restoreBoolean()) {
               this.flags |= 4;
            }

            if (var5 >= 4) {
               this._farSidePortalName = var1.restoreString();
            }

            this._farSidePortal = (Portal)var1.restoreMaybeNull();
            if (var5 == 1) {
               String var6 = var1.restoreString();
               if (!"".equals(var6)) {
                  this.setName(var6);
               }
            } else if (var5 >= 3) {
               if (var5 >= 7) {
                  this._farSideWorld = URL.restore(var1);
               } else {
                  this._farSideWorld = URL.restore(var1, ".world");
               }

               this._farSideRoomName = var1.restoreString();
               this._farx = var1.restoreFloat();
               this._fary = var1.restoreFloat();
               this._farz = var1.restoreFloat();
               this._fartheta = var1.restoreFloat();
               Material var11 = Material.restore(var1);
               Material var7 = Material.restore(var1);
               if (var11 != null) {
                  this.setMaterial(var11);
                  if (var7 != null && (var11.textureName == null || !var11.textureName.equals(var7.textureName))) {
                     System.out
                        .println(
                           "Both initial and download covers, "
                              + var11.textureName
                              + " and "
                              + var7.textureName
                              + ", in "
                              + this.getName()
                              + " -- using initial."
                        );
                  }
               } else {
                  this.setMaterial(var7);
               }

               if (var5 >= 5) {
                  this._farSideIsPortal = var1.restoreBoolean();
               }
            }
            break;
         case 8:
         case 9:
            super.restoreState(var1);
            this._farSideIsPortal = var1.restoreBoolean();
            if (var5 >= 9) {
               this._allowDownload = var1.restoreBoolean();
            }

            this._farSidePortalName = var1.restoreString();
            this._farSidePortal = (Portal)var1.restoreMaybeNull();
            this._farSideWorld = URL.restore(var1);
            this._farSideRoomName = var1.restoreString();
            this._farx = var1.restoreFloat();
            this._fary = var1.restoreFloat();
            this._farz = var1.restoreFloat();
            this._fartheta = var1.restoreFloat();
            break;
         default:
            throw new TooNewException();
      }

      if (var5 <= 4 && this._farSideRoomName != null && this._farSidePortal == null && this._farSidePortalName == null) {
         this._farSideIsPortal = false;
      }

      this._userFarx = this._farx;
      this._userFary = this._fary;
      this._userFarz = this._farz;
      this._userFartheta = this._fartheta;
   }

   public void postRestore(int var1) {
      super.postRestore(var1);
      if (this.getOwner() != null) {
         this.addToRoom(this.getOwner());
         Room var2 = this.getOwner().getRoom();
         if (this._farSidePortal == null) {
            this.reset();
         } else {
            this.newFarSide();
         }
      }
   }

   public String toString() {
      String var1;
      if (this._state == -1) {
         var1 = "(not connected)";
      } else {
         if (this._farSideWorld != null) {
            var1 = this._farSideWorld.toString();
         } else {
            var1 = "";
         }

         if (this._farSideRoom != null) {
            var1 = var1 + "#" + this._farSideRoomName;
         }

         if (this._farSidePortalName != null) {
            var1 = var1 + "#" + this._farSidePortalName;
         }
      }

      return super.toString() + "[Connected To " + var1 + "]";
   }

   public Portal triggerLoad() {
      if (this._farSideWorld != null && this._farSideRoomName != null) {
         if (this._farSidePortal != null && !this._farSidePortal.isActive()) {
            this.reset();
         }

         if (this._state == 0) {
            this._state = 1;
            World.load(this._farSideWorld, this);
         }
      }

      return this;
   }

   public void loadedURLSelf(URLSelf var1, URL var2, String var3) {
      if (this.frozeFrameEvents) {
         this.frozeFrameEvents = false;
         Console.setFreezeFrameEvents(false);
      }

      if (this._state == 1) {
         if (var3 == null && var1 instanceof World) {
            World var8 = (World)var1;
            this.setFarSideRoom(var8.getRoom(this._farSideRoomName));
            if (this._farSideRoom != null) {
               this._state = 2;
               this.findFarSidePortal(true);
            } else {
               Object[] var9 = new Object[]{new String(this._farSideRoomName), new String("" + this._farSideWorld)};
               Console.println(MessageFormat.format(Console.message("Cant-find-remote"), var9));
               this._state = -1;
            }
         } else {
            if (var3 == null) {
               var3 = "doesn't contain a World";
               var1.decRef();
            }

            String var4 = TeleportAction.getReadableNameOfWorld(var2);
            this._state = -1;
            if (this._allowDownload && !World.isProscribed(var2, false)) {
               Object[] var5 = new Object[]{new String(var4)};
               Console.println(MessageFormat.format(Console.message("Dont-have-world"), var5));
               String var6 = TeleportAction.getPackageNameOfWorld(var2);
               if (var6 != null) {
                  NetUpdate.loadWorld(var6, false);
               }
            }
         }

         this.updateVisible();
      }
   }

   static {
      nativeInit();
      standardPassthroughBumpCalc.setName("defaultPassthroughBumpCalc");
   }
}
