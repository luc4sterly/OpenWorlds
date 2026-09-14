package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Gamma;
import NET.worlds.console.RightMenu;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.NetworkObject;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class WObject extends Transform implements Prerenderable {
   private boolean mouseOver = false;
   private String _toolTipText;
   private Vector contents = null;
   private Shadow shadow;
   public static boolean shadowsOn = IniFile.gamma().getIniInt("shadows", 0) != 0;
   protected boolean discarded = false;
   protected int clumpID;
   protected int highlightID = 0;
   protected static final int isVisibleMask = 1;
   protected static final int isBumpableMask = 2;
   protected static final int isHologramRoughCutMask = 4;
   protected static final int isMirrored = 4;
   protected static final int isOptimizableMask = 8;
   protected static final int isDrawFirstOnIntersectionMask = 16;
   protected static final int isDrawOrderUnimportantMask = 32;
   protected static final int isMaterialVisible = 64;
   protected static final int isHighlitMask = 128;
   protected static final int isAutoGapMask = 256;
   protected static final int isAutoGapFromLocalMask = 512;
   protected static final int isDisablePixelDoublingMask = 1024;
   protected static final int isSharerMode0 = 2048;
   protected static final int isSharerMode1 = 4096;
   protected static final int isSharerMode2 = 8192;
   protected static final int duringRestore = 16384;
   protected static final int isShadowedLocally = 32768;
   protected static final int isShadowed = 65536;
   protected static final int isAutobuiltMask = 131072;
   protected static final int isHologramViewplaneAlignedMask = 262144;
   protected static final int isDontConnect = 262144;
   protected static final int isSurfaceUFlippedMask = 524288;
   protected static final int isSurfaceVFlippedMask = 1048576;
   protected static final int isReclumpingMask = 2097152;
   protected static final int isHologramAutosize = 4194304;
   protected int flags = 3;
   Vector eventHandlers;
   protected Vector actions = null;
   protected BumpCalc bumpCalc = null;
   static BumpCalc standardBoxBumpCalc = new BoxBumpCalc();
   private static Object classCookie = new Object();
   public static boolean replaceWithMontyDoor = IniFile.gamma().getIniInt("replaceWithMontyDoor", 0) != 0;
   private Sharer _sharer = null;
   public VisiAttribute _visibilityAttribute;
   public TransAttribute _transformAttribute;
   public BumpAttribute _bumpableAttribute;

   public static native void nativeInit();

   public boolean getMouseOver() {
      if (this.mouseOver) {
         return true;
      }

      WObject var1;
      try {
         var1 = (WObject)this.getOwner();
      } catch (ClassCastException var3) {
         return false;
      }

      return var1 == null ? false : var1.getMouseOver();
   }

   public void setMouseOver(boolean var1) {
      this.mouseOver = var1;
   }

   public String getToolTipText() {
      if (this._toolTipText != null) {
         return this._toolTipText;
      }

      WObject var1;
      try {
         var1 = (WObject)this.getOwner();
      } catch (ClassCastException var3) {
         return null;
      }

      return var1 == null ? null : var1.getToolTipText();
   }

   public void setToolTipText(String var1) {
      this._toolTipText = var1;
   }

   public void setName(String var1) {
      super.setName(this.getBangName(var1));
   }

   private String getBangName(String var1) {
      boolean var2 = var1.startsWith("!");
      if (var2 != this.isDynamic()) {
         return var2 ? var1.substring(1) : "!" + var1;
      } else {
         return var1;
      }
   }

   public void markEdited() {
      if (!this.isDynamic()) {
         super.markEdited();
      }
   }

   public void getChildren(DeepEnumeration var1) {
      if (this.contents != null) {
         var1.addChildVector(this.contents);
      }

      if (this.eventHandlers != null) {
         var1.addChildVector(this.eventHandlers);
      }

      if (this.actions != null) {
         var1.addChildVector(this.actions);
      }

      if (this._sharer != null) {
         var1.addChildElement(this._sharer);
      }
   }

   public void add(WObject var1) {
      super.add(var1);
      if (this.hasClump()) {
         var1.recursiveAddRwChildren(this);
      }

      if (var1._sharer != null) {
         var1._sharer.adjustShare();
      }

      if (this.contents == null) {
         this.contents = new Vector();
      }

      this.contents.addElement(var1);
   }

   public Enumeration getContents() {
      return this.contents == null ? new Vector().elements() : this.contents.elements();
   }

   public boolean hasContents() {
      return this.contents != null;
   }

   public boolean contentsContain(WObject var1) {
      return this.contents == null ? false : this.contents.contains(var1);
   }

   protected void noteUnadding(SuperRoot var1) {
      if (this.contents != null && this.contents.removeElement(var1) && this.contents.size() == 0) {
         this.contents = null;
      }
   }

   public void makeShadow() {
      Debug.dAssert(this.shadow == null);
      this.shadow = new DiskShadow(this);
   }

   public void detach() {
      if (this.clumpID != 0) {
         this.markVoid();
      }

      super.detach();
      if (this._sharer != null) {
         this._sharer.adjustShare();
      }

      if (this.shadow != null) {
         this.shadow.adjustShadow(this);
         this.shadow = null;
      }
   }

   public void discard() {
      super.discard();
      this.discarded = true;
      if (this.contents != null) {
         int var1 = this.contents.size();

         while (--var1 >= 0) {
            ((WObject)this.contents.elementAt(var1)).discard();
         }
      }

      if (this.eventHandlers != null) {
         int var2 = this.eventHandlers.size();

         while (--var2 >= 0) {
            this.removeHandler((SuperRoot)this.eventHandlers.elementAt(var2));
         }
      }

      if (this.actions != null) {
         int var3 = this.actions.size();

         while (--var3 >= 0) {
            this.removeAction((Action)this.actions.elementAt(var3));
         }
      }

      this.releaseAuxilaryData();
   }

   protected void finalize() {
      if (!this.discarded) {
         this.releaseAuxilaryData();
      }

      super.finalize();
   }

   public void reclump() {
      if (this.clumpID != 0) {
         Debug.assert_((this.flags & 2097152) == 0);
         this.flags |= 2097152;
         this.markVoid();
         this.recursiveAddRwChildren((WObject)this.getOwner());
         Debug.assert_((this.flags & 2097152) != 0);
         this.flags &= -2097153;
      }
   }

   public boolean isReclumping() {
      return (this.flags & 2097152) != 0;
   }

   protected void noteTransformChange() {
      this.setClumpMatrix();
      this.updateHighlight();
      if (this.shadow != null) {
         this.shadow.adjustShadow(this);
      }

      if (this._transformAttribute != null) {
         this._transformAttribute.noteChange();
      }
   }

   protected void markVoid() {
      if (this.contents != null) {
         int var1 = this.contents.size();

         while (--var1 >= 0) {
            ((WObject)this.contents.elementAt(var1)).markVoid();
         }
      }

      Room var4 = this.getRoomFromClump();
      if (this instanceof FrameHandler) {
         var4.removeFrameHandler((FrameHandler)this, this);
      }

      if (this.eventHandlers != null) {
         int var2 = this.eventHandlers.size();

         while (--var2 >= 0) {
            Object var3 = this.eventHandlers.elementAt(var2);
            if (var3 instanceof FrameHandler) {
               var4.removeFrameHandler((FrameHandler)var3, this);
            }
         }
      }

      this.voidClump();
      if (this.shadow != null) {
         this.shadow.adjustShadow(this);
      }
   }

   protected void addRwChildren(WObject var1) {
      this.addNewRwChild(var1);
   }

   public void recursiveAddRwChildren(WObject var1) {
      this.addRwChildren(var1);
      if (this.contents != null) {
         int var2 = this.contents.size();

         for (int var3 = 0; var3 < var2; var3++) {
            ((WObject)this.contents.elementAt(var3)).recursiveAddRwChildren(this);
         }
      }
   }

   protected final void addNewRwChild(WObject var1) {
      Debug.assert_(this.clumpID == 0);
      this.createClump();
      this.newRwClumpChildHelper(var1);
   }

   protected void newRwClumpChildHelper(WObject var1) {
      Debug.dAssert(var1 != null);
      this.addChildToClump(var1);
      this.newRwChildHelper();
      if (!this.getVisible()) {
         this.updateVisible();
      }

      if (this.shadow != null) {
         this.shadow.adjustShadow(this);
      } else {
         if (this.getShadowedLocally() ? !this.getLocalShadowed() : !shadowsOn) {
            return;
         }

         if (this.inRoomContents() && this.getOwner() instanceof Room) {
            this.makeShadow();
         }
      }
   }

   protected void newRwChildHelper() {
      this.initClumpData();
      this.setClumpMatrix();
      Room var1 = this.getRoom();
      if (this instanceof FrameHandler) {
         var1.addFrameHandler((FrameHandler)this, this);
      }

      if (this.eventHandlers != null) {
         for (int var2 = 0; var2 < this.eventHandlers.size(); var2++) {
            Object var3 = this.eventHandlers.elementAt(var2);
            if (var3 instanceof FrameHandler) {
               var1.addFrameHandler((FrameHandler)var3, this);
            }
         }
      }
   }

   native void createClump();

   public final boolean hasClump() {
      return this.clumpID != 0;
   }

   public final int getID() {
      return this.clumpID;
   }

   public native boolean nativeInCamSpace(Camera var1, Point3Temp var2);

   public Point3Temp inCamSpace(Camera var1) {
      Point3Temp var2 = Point3Temp.make();
      return this.nativeInCamSpace(var1, var2) ? var2 : null;
   }

   protected native void voidClump();

   protected native int extractClump();

   native void addChildToClump(WObject var1);

   native void setClumpMatrix();

   private native void initClumpData();

   native void doneWithEditing();

   native int getNumVerts();

   public Transform getObjectToWorldMatrix() {
      if (this.hasClump()) {
         return this.getObjectToWorldMatrix(Transform.make());
      }

      Transform var1 = this.getTransform();
      SuperRoot var2 = this.getOwner();
      if (var2 instanceof WObject) {
         Transform var3 = ((WObject)var2).getObjectToWorldMatrix();
         var1.post(var3);
         var3.recycle();
      }

      return var1;
   }

   private native Transform getObjectToWorldMatrix(Transform var1);

   protected native Transform getJointedObjectToWorldMatrix(Transform var1);

   public Point3Temp getWorldPosition() {
      Transform var1 = this.getObjectToWorldMatrix();
      Point3Temp var2 = var1.getPosition();
      var1.recycle();
      return var2;
   }

   public native void updateHighlight();

   public native void getClumpBBox(Point3Temp var1, Point3Temp var2);

   public BoundBoxTemp getClumpBBox() {
      Point3Temp var1 = Point3Temp.make();
      Point3Temp var2 = Point3Temp.make();
      this.getClumpBBox(var1, var2);
      return BoundBoxTemp.make(var1, var2);
   }

   public WObject setHighlit(boolean var1) {
      if (var1) {
         this.flags |= 128;
      } else {
         this.flags &= -129;
      }

      this.updateHighlight();
      return this;
   }

   public final boolean getHighlit() {
      return (this.flags & 128) != 0;
   }

   public void setAutobuilt(boolean var1) {
      if (var1) {
         this.flags |= 131072;
      } else {
         this.flags &= -131073;
      }
   }

   public final boolean getAutobuilt() {
      return (this.flags & 131072) != 0;
   }

   public WObject setOptimizable(boolean var1) {
      if (var1) {
         this.flags |= 8;
      } else {
         this.flags &= -9;
      }

      return this;
   }

   public final boolean getOptimizable() {
      return (this.flags & 8) != 0;
   }

   final void setSharerMode(int var1) {
      Debug.dAssert(var1 >= 0 && var1 < 8);
      this.flags &= -14337;
      this.flags |= var1 << 11;
      this.setName(this.getName());
   }

   final int getSharerMode() {
      return this.flags >>> 11 & 7;
   }

   public final boolean isDynamic() {
      return (this.getSharerMode() & 4) != 0;
   }

   public WObject setLocalAutoGap(boolean var1) {
      if (var1) {
         this.flags |= 256;
      } else {
         this.flags &= -257;
      }

      if (this instanceof Room) {
         Enumeration var2 = this.getDeepOwned();

         while (var2.hasMoreElements()) {
            Object var3 = var2.nextElement();
            if (var3 instanceof WObject) {
               ((WObject)var3).noteTransformChange();
            }
         }
      }

      return this;
   }

   public final boolean getLocalAutoGap() {
      return (this.flags & 256) != 0;
   }

   public WObject setAutoGapFromRoom(boolean var1) {
      if (var1) {
         this.flags &= -513;
      } else {
         this.flags |= 512;
      }

      this.noteTransformChange();
      return this;
   }

   public final boolean getAutoGapFromRoom() {
      return (this.flags & 512) == 0;
   }

   public boolean getAutoGap() {
      return (this.getAutoGapFromRoom() ? this.getRoom() : this).getLocalAutoGap();
   }

   public void setVisible(boolean var1) {
      if (var1 != this.getVisible()) {
         if (var1) {
            this.flags |= 1;
         } else {
            this.flags &= -2;
         }

         this.updateVisible();
         if (this.shadow != null) {
            this.shadow.adjustShadow(this);
         }

         if (this._visibilityAttribute != null) {
            this._visibilityAttribute.noteChange();
         }
      }
   }

   public boolean getLocalShadowed() {
      return (this.flags & 65536) != 0;
   }

   public void setLocalShadowed(boolean var1) {
      if (var1) {
         this.flags |= 65536;
      } else {
         this.flags &= -65537;
      }
   }

   public boolean getShadowedLocally() {
      return (this.flags & 32768) != 0;
   }

   public void setShadowedLocally(boolean var1) {
      if (var1) {
         this.flags |= 32768;
      } else {
         this.flags &= -32769;
      }
   }

   protected native void updateVisible();

   public final boolean getVisible() {
      return (this.flags & 1) != 0;
   }

   public WObject setBumpable(boolean var1) {
      if (var1) {
         this.flags |= 2;
      } else {
         this.flags &= -3;
      }

      if (this._bumpableAttribute != null) {
         this._bumpableAttribute.noteChange();
      }

      return this;
   }

   public final boolean getBumpable() {
      return (this.flags & 2) != 0;
   }

   public boolean deliver(Event var1) {
      var1.receiver = this;
      boolean var2 = var1.deliver(this);
      if (this.eventHandlers != null) {
         Enumeration var3 = this.eventHandlers.elements();

         while (var3.hasMoreElements()) {
            var1.receiver = this;
            if (var1.deliver(var3.nextElement())) {
               var2 = true;
            }
         }
      }

      if (var2) {
         return true;
      }

      if (var1 instanceof UserEvent) {
         SuperRoot var4 = this.getOwner();
         if (var4 instanceof WObject) {
            return ((WObject)var4).deliver(var1);
         }
      }

      return false;
   }

   public Enumeration getHandlers() {
      return this.eventHandlers == null ? new Vector().elements() : this.eventHandlers.elements();
   }

   public boolean hasHandler(SuperRoot var1) {
      return this.eventHandlers != null && this.eventHandlers.indexOf(var1) != -1;
   }

   public WObject addHandler(SuperRoot var1) {
      if (this.eventHandlers == null) {
         this.eventHandlers = new Vector();
      }

      this.eventHandlers.addElement(var1);
      if (this.clumpID != 0 && var1 instanceof FrameHandler) {
         this.getRoomFromClump().addFrameHandler((FrameHandler)var1, this);
      }

      super.add(var1);
      return this;
   }

   public Room getRoom() {
      return this.clumpID != 0 ? this.getRoomFromClump() : this.getRoomNotFromClump();
   }

   public Room getRoomNotFromClump() {
      SuperRoot var1 = this.getOwner();
      return var1 instanceof WObject ? ((WObject)var1).getRoomNotFromClump() : null;
   }

   public native Room getRoomFromClump();

   public native boolean inRoomContents();

   public World getWorld() {
      if (this.clumpID != 0) {
         return this.getRoomFromClump().getWorld();
      }

      Room var1 = this.getRoomNotFromClump();
      return var1 == null ? null : var1.getWorld();
   }

   public boolean isActive() {
      return this.clumpID != 0 ? true : super.isActive();
   }

   public void removeHandler(SuperRoot var1) {
      if (this.eventHandlers.contains(var1)) {
         var1.detach();
         this.eventHandlers.removeElement(var1);
         if (this.eventHandlers.size() == 0) {
            this.eventHandlers = null;
         }

         if (this.clumpID != 0 && var1 instanceof FrameHandler) {
            this.getRoomFromClump().removeFrameHandler((FrameHandler)var1, this);
         }
      }
   }

   public Enumeration getActions() {
      return this.actions == null ? new Vector().elements() : this.actions.elements();
   }

   public boolean hasActions() {
      return this.actions != null;
   }

   public WObject addAction(Action var1) {
      if (this.actions == null) {
         this.actions = new Vector();
      }

      this.actions.addElement(var1);
      super.add(var1);
      return this;
   }

   public void removeAction(Action var1) {
      Debug.dAssert(var1.getOwner() == this);
      var1.detach();
      this.actions.removeElement(var1);
      if (this.actions.size() == 0) {
         this.actions = null;
      }
   }

   public void rightMenu() {
      new RightMenu(this, this.getActions());
   }

   public void doAction(String var1, Event var2) {
      if (var1 != null && !var1.equals("")) {
         if (Gamma.getShaper() != null && var1.equals("Edit Properties...")) {
            Console.getFrame().getEditTile().viewProperties(this);
         } else if (this.actions != null) {
            int var3 = 0;

            while (var3 < this.actions.size()) {
               Action var4 = (Action)this.actions.elementAt(var3);
               var3++;
               if (var1.equals(var4.rightMenuLabel)) {
                  RunningActionHandler.trigger(var4, this.getWorld(), var2);
               }
            }
         }
      }
   }

   public WObject setBumpCalc(BumpCalc var1) {
      if (this.bumpCalc != null) {
         this.bumpCalc.detach();
      }

      this.bumpCalc = var1;
      if (this.bumpCalc != null) {
         super.add(this.bumpCalc);
      }

      return this;
   }

   public BumpCalc getBumpCalc(BumpEventTemp var1) {
      return this.bumpCalc == null ? standardBoxBumpCalc : this.bumpCalc;
   }

   public Point3Temp getPlaneExtent() {
      return Point3Temp.make();
   }

   public BoundBoxTemp getBoundBox() {
      if (this.getVisible()) {
         return this.getClumpBBox();
      }

      Transform var1 = this.getObjectToWorldMatrix();
      BoundBoxTemp var2 = BoundBoxTemp.make(var1.getPosition(), this.getPlaneExtent().times(var1));
      var1.recycle();
      return var2;
   }

   public float getMinXYExtent() {
      if (this.getVisible()) {
         return this.getClumpMinXYExtent();
      }

      BoundBoxTemp var1 = this.getBoundBox();
      float var2 = var1.hi.x - var1.lo.x;
      float var3 = var1.hi.y - var1.lo.y;
      return var2 < var3 ? var2 : var3;
   }

   public native float getClumpMinXYExtent();

   public void detectBump(BumpEventTemp var1) {
      BoundBoxTemp var2 = this.getBoundBox();
      if (!var2.isEmpty() && var1.bound.overlaps(var2)) {
         this.getBumpCalc(var1).detectBump(var1, this);
      }

      if (this.contents != null) {
         int var3 = this.contents.size();

         while (--var3 >= 0) {
            WObject var4 = (WObject)this.contents.elementAt(var3);
            if (var4.getBumpable() && var1.source != var4) {
               var4.detectBump(var1);
            }
         }
      }
   }

   public void premoveThrough(Point3Temp var1) {
      Point3Temp var2 = this.getPosition();
      this.moveThrough(Point3Temp.make(var1).times(this).minus(var2));
   }

   public void moveThrough(Point3Temp var1) {
      if (this.getRoom() == null || !this.getBumpable()) {
         this.moveBy(var1);
      } else if (this.getRoom().hasClump()) {
         int var2 = Std.getRealTime();
         WObject var3 = this;

         for (int var4 = 4; var4 > 0; var4--) {
            BumpEventTemp var5 = BumpEventTemp.make(var2, var3, var1);

            try {
               if (var5.target == null) {
                  var3.moveBy(var5.fullPath);
                  break;
               }

               var5.postBumpRoom = var3.getRoom();
               var5.postBumpPosition = var3.getObjectToWorldMatrix().moveBy(var5.path);
               var5.postBumpPath = Point3Temp.make(var5.fullPath).times(1.0F - var5.fraction);
               Transform var6 = var3.getTransform();

               try {
                  Room var7 = this.getRoom();
                  var5.target.deliver(var5);
                  var3.deliver(var5);
                  if (!var3.isTransformEqual(var6) || var7 != this.getRoom()) {
                     break;
                  }
               } finally {
                  var6.recycle();
               }

               Transform var16 = var5.postBumpRoom.getObjectToWorldMatrix();
               var16.invert();
               if (var3.getRoom() != var5.postBumpRoom) {
                  var16.pre(var5.postBumpPosition);
                  var3 = var3.changeRoom(var5.postBumpRoom, var16);
                  if (var3 == null) {
                     break;
                  }
               } else {
                  var3.makeIdentity();
                  var3.pre(var16);
                  var3.pre(var5.postBumpPosition);
               }

               var5.postBumpPosition.recycle();
               var5.postBumpPosition = null;
               var16.recycle();
               var1 = var5.postBumpPath;
            } finally {
               var5.recycle();
            }
         }
      }
   }

   protected WObject changeRoom(Room var1, Transform var2) {
      this.detach();
      var1.add(this);
      this.makeIdentity();
      this.pre(var2);
      return this;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Contents"));
            } else if (var3 == 1) {
               if (this.contents != null) {
                  var5 = this.contents.clone();
               }
            } else if (var3 == 4) {
               ((WObject)var4).detach();
            } else if (var3 == 3) {
               this.add((WObject)var4);
            } else if (var3 == 5 && var4 instanceof WObject && !(var4 instanceof Room)) {
               var5 = var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Event Handlers"));
            } else if (var3 == 1) {
               if (this.eventHandlers != null) {
                  var5 = this.eventHandlers.clone();
               }
            } else if (var3 == 4) {
               this.removeHandler((SuperRoot)var4);
            } else if (var3 == 3) {
               this.addHandler((SuperRoot)var4);
            } else if (var3 == 5 && (var4 instanceof SwitchableBehavior || var4 instanceof Sensor)) {
               var5 = var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Actions"));
            } else if (var3 == 1) {
               if (this.actions != null) {
                  var5 = this.actions.clone();
               }
            } else if (var3 == 4) {
               this.removeAction((Action)var4);
            } else if (var3 == 3) {
               this.addAction((Action)var4);
            } else if (var3 == 5 && var4 instanceof Action) {
               var5 = var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Bumpable"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getBumpable());
            } else if (var3 == 2) {
               this.setBumpable((Boolean)var4);
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Visible"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getVisible());
            } else if (var3 == 2) {
               this.setVisible((Boolean)var4);
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Sharing Mode (100 for help)", true));
            } else if (var3 == 1) {
               var5 = new Integer(this.getSharerMode());
            } else if (var3 == 2) {
               int var6 = (Integer)var4;
               if (this instanceof Room && var6 >= 0 && var6 <= 5) {
                  Console.println("A Room's sharing mode\nmust be 2, and is\nautomatically set by the shaper.");
               } else if (var6 != 0 && var6 != 3 && var6 != 5) {
                  Console.println("0 = default (chooses 2 or 3 for you)");
                  Console.println("2 = static (stored in .world)");
                  Console.println("3 = forwarded static");
                  Console.println("4 = dynamic (stored only on server)");
                  Console.println("5 = forwarded dynamic");
                  Console.println("Modes 2, and 4, are not generally\nsupported, except that mode 2\nis required for Rooms");
               } else if (var6 == 5 && this.getSourceURL() == null) {
                  Console.println("Only WObjects read from files may be forwarded dynamic.");
               } else {
                  this.getSharer().setMode(var6);
               }
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Shared Attributes"));
            } else if (var3 == 1) {
               if (this._sharer != null) {
                  var5 = this._sharer.getAttributesList();
               } else {
                  var5 = new Vector();
               }
            } else if (var3 == 4) {
               this.removeShareableAttribute((Attribute)var4);
            } else if (var3 == 3) {
               this.addShareableAttribute((Attribute)var4);
            } else if (var3 == 5 && var4 instanceof Attribute) {
               var5 = var4;
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Tool Tip Text"));
            } else if (var3 == 1) {
               var5 = this.getToolTipText();
            } else if (var3 == 2) {
               this.setToolTipText((String)var4);
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Mouse Change"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getMouseOver());
            } else if (var3 == 2) {
               this.setMouseOver((Boolean)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 9, var3, var4);
      }

      return var5;
   }

   public static void saveUnsharedWObjects(Saver var0, Vector var1) throws IOException {
      int var2 = 0;
      Enumeration var3 = var1.elements();

      while (var3.hasMoreElements()) {
         WObject var4 = (WObject)var3.nextElement();
         if (var4 instanceof Persister && !(var4 instanceof NonPersister) && !var4.isDynamic()) {
            var2++;
         }
      }

      var0.saveInt(var2);
      var3 = var1.elements();

      while (var3.hasMoreElements()) {
         WObject var6 = (WObject)var3.nextElement();
         if (var6 instanceof Persister && !(var6 instanceof NonPersister) && !var6.isDynamic()) {
            var0.save(var6);
         }
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(10, classCookie);
      super.saveState(var1);
      var1.saveInt(this.flags & -129);
      if (this.contents == null) {
         var1.saveBoolean(false);
      } else {
         var1.saveBoolean(true);
         saveUnsharedWObjects(var1, this.contents);
      }

      var1.saveVectorMaybeNull(this.eventHandlers);
      var1.saveVectorMaybeNull(this.actions);
      var1.saveMaybeNull(this.bumpCalc);
      if (this._sharer != null && this._sharer.isEmpty()) {
         var1.saveMaybeNull(null);
      } else {
         var1.saveMaybeNull(this._sharer);
      }

      var1.saveString(this.getToolTipText());
      var1.saveBoolean(this.getMouseOver());
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreWObjectState(var1);
   }

   public void restoreWObjectState(Restorer var1) throws IOException, TooNewException {
      Vector var2 = null;
      Vector var3 = null;
      Vector var4 = null;
      int var5 = var1.restoreVersion(classCookie);
      switch (var5) {
         case 0:
            var1.setOldFlag();
            super.restoreState(var1);
            this.flags = var1.restoreInt();
            var1.restoreMaybeNull();
            this.flags |= 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = new Vector();
            break;
         case 1:
            var1.setOldFlag();
            super.restoreState(var1);
            this.flags = var1.restoreInt();
            var1.restoreMaybeNull();
            this.flags |= 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = var1.restoreVectorMaybeNull();
            break;
         case 2:
            var1.setOldFlag();
            super.restoreState(var1);
            this.flags = var1.restoreInt() | 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = var1.restoreVectorMaybeNull();
            break;
         case 3:
            super.restoreState(var1);
            this.flags = var1.restoreInt() | 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = var1.restoreVectorMaybeNull();
            var1.restore();
            break;
         case 4:
            super.restoreState(var1);
            this.flags = var1.restoreInt() | 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = var1.restoreVectorMaybeNull();
            var1.restore();
            this._sharer = (Sharer)var1.restoreMaybeNull();
            break;
         case 5:
         case 7:
         case 8:
            super.restoreState(var1);
            this.flags = var1.restoreInt() | 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = var1.restoreVectorMaybeNull();
            this.setBumpCalc((BumpCalc)var1.restoreMaybeNull());
            this._sharer = (Sharer)var1.restoreMaybeNull();
            break;
         case 6:
            super.restoreState(var1);
            this.flags = var1.restoreInt() | 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = var1.restoreVectorMaybeNull();
            this.setBumpCalc((BumpCalc)var1.restoreMaybeNull());
            this._sharer = (Sharer)var1.restoreMaybeNull();
            var1.restoreString();
            break;
         case 9:
            super.restoreState(var1);
            this.flags = var1.restoreInt() | 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = var1.restoreVectorMaybeNull();
            this.setBumpCalc((BumpCalc)var1.restoreMaybeNull());
            this._sharer = (Sharer)var1.restoreMaybeNull();
            this.setToolTipText(var1.restoreString());
            break;
         case 10:
            super.restoreState(var1);
            this.flags = var1.restoreInt() | 16384;
            var2 = var1.restoreVectorMaybeNull();
            var4 = var1.restoreVectorMaybeNull();
            var3 = var1.restoreVectorMaybeNull();
            this.setBumpCalc((BumpCalc)var1.restoreMaybeNull());
            this._sharer = (Sharer)var1.restoreMaybeNull();
            this.setToolTipText(var1.restoreString());
            this.setMouseOver(var1.restoreBoolean());
            break;
         default:
            throw new TooNewException();
      }

      if (var5 < 8) {
         this.flags &= -65;
      }

      if (var2 != null) {
         for (int var6 = 0; var6 < var2.size(); var6++) {
            this.add((WObject)var2.elementAt(var6));
         }
      }

      if (var3 != null) {
         for (int var10 = 0; var10 < var3.size(); var10++) {
            this.addAction((Action)var3.elementAt(var10));
         }
      }

      if (var4 != null) {
         for (int var11 = 0; var11 < var4.size(); var11++) {
            this.addHandler((SuperRoot)var4.elementAt(var11));
         }
      }

      if (this._sharer != null) {
         super.add(this._sharer);
      }
   }

   public void postRestore(int var1) {
      super.postRestore(var1);
      if (var1 < 7) {
         Enumeration var2 = this.getHandlers();

         while (var2.hasMoreElements()) {
            SuperRoot var3 = (SuperRoot)var2.nextElement();
            if (var3.getOwner() != this) {
               SuperRoot var4 = (SuperRoot)var3.clone();
               this.eventHandlers.removeElement(var3);
               if (this.eventHandlers.size() == 0) {
                  this.eventHandlers = null;
               }

               if (this.clumpID != 0 && var3 instanceof FrameHandler) {
                  this.getRoomFromClump().removeFrameHandler((FrameHandler)var3, this);
               }

               this.addHandler(var4);
            }
         }
      }

      if (replaceWithMontyDoor
         && this.getClass()
            == (NET.worlds.scape.WObject.class)
         )
       {
         this.replaceMonty();
      }

      if (this._sharer != null) {
         this._sharer.ownerPostRestore();
      }

      this.flags &= -16385;
      if (this.isDynamic()) {
         this.getSharer();
      }
   }

   private void replaceMonty() {
      if (this.actions != null && this.actions.size() == 3 && this.getOwner() instanceof WObject) {
         byte var1 = 0;

         try {
            if (this.actions.elementAt(0) instanceof SetURLAction) {
               SetURLAction var2 = (SetURLAction)this.actions.elementAt(0);
               if (var2._propName.equals("File") && var2._roomName != null) {
                  var1 = 1;
                  Object var3 = this.actions.elementAt(1);
                  Object var4 = this.actions.elementAt(2);
                  if (var3 instanceof DialogAction && var4.getClass() == var3.getClass() && ((DialogAction)var4).cancelOnly != ((DialogAction)var3).cancelOnly) {
                     if (((DialogAction)var3).cancelOnly) {
                        var3 = var4;
                     }

                     var1 = 2;
                     if (this.actions.elementAt(0) instanceof SetURLAction) {
                        var1 = 3;
                        if (this.contents != null
                           && this.contents.size() >= 2
                           && this.contents.size() <= 3
                           && this.contents.elementAt(0).getClass()
                              == (
                                 NET.worlds.scape.Rect.class
                              )
                           && this.contents.elementAt(1).getClass()
                              == (
                                 NET.worlds.scape.Portal.class
                              )) {
                           var1 = 4;
                           boolean var5 = this.contents.size() == 3;
                           Rect var6 = (Rect)this.contents.elementAt(0);
                           Portal var7 = (Portal)this.contents.elementAt(1);
                           Rect var8 = null;
                           if (var5) {
                              if (this.contents.elementAt(2).getClass()
                                 != (
                                    NET.worlds.scape.Rect.class
                                 )) {
                                 return;
                              }

                              var8 = (Rect)this.contents.elementAt(2);
                           }

                           var1 = 5;
                           if (var6.eventHandlers != null
                              && var6.eventHandlers.size() == 1
                              && var6.eventHandlers.elementAt(0).getClass()
                                 == (
                                    NET.worlds.scape.ClickSensor.class
                                 )) {
                              var1 = 6;
                              ClickSensor var9 = (ClickSensor)var6.eventHandlers.elementAt(0);
                              if (var9.countActions() == 1) {
                                 var1 = 7;
                                 if (var6.actions != null
                                    && var6.actions.size() == 3
                                    && var6.actions.elementAt(2).getClass()
                                       == (
                                          NET.worlds.scape.SequenceAction.class
                                       )) {
                                    var1 = 8;
                                    SequenceAction var10 = (SequenceAction)var6.actions.elementAt(2);
                                    if (var10.actions != null && var10.actions.size() == (var5 ? 9 : 7)) {
                                       var1 = 9;
                                       if (var7.actions != null && var7.actions.size() == 2 && var7._farSideRoomName != null && var7._farSidePortalName != null
                                          )
                                        {
                                          var1 = 10;
                                          URL var11 = (var5 ? var8 : var6).getMaterial().textureName;
                                          if (var11 != null) {
                                             var1 = 11;
                                             MontyDoor var12 = new MontyDoor();
                                             var12.setsAvatar = var3 instanceof SelectAvatarAction;
                                             if (!var12.setsAvatar) {
                                                if (!(var3 instanceof SendURLAction)) {
                                                   return;
                                                }

                                                var12.description = ((SendURLAction)var3).description;
                                                var12.url = ((SendURLAction)var3).destination;
                                             } else {
                                                var12.url = ((SelectAvatarAction)var3).url;
                                             }

                                             var1 = 12;
                                             var12.viewURL = var2._value;
                                             var12.viewName = var2._targetName;
                                             var12.setFarSideInfo(null, var2._roomName, var7._farSidePortalName);
                                             var12.post(var7);
                                             var12.post(this);
                                             String var13 = var11.getInternal();
                                             if (var5) {
                                                if (!var13.endsWith("b.cmp")) {
                                                   Console.println("Texture: " + var13);
                                                   return;
                                                }

                                                int var14 = var13.length();
                                                var13 = var13.substring(0, var14 - 5) + "m2v*.mov";
                                             }

                                             var1 = 13;
                                             var12.setMaterial(new Material(URL.make(var13)));
                                             ((WObject)this.getOwner()).add(var12);
                                             this.detach();
                                             var7.detach();
                                             var12.reset();
                                             var1 = 100;
                                          }
                                       }
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         } finally {
            if (var1 != 100) {
               Console.println("Failed MontyDoor conversion of " + this.getName() + " in stage " + var1 + ".\n");
            }
         }
      }
   }

   public String toString() {
      String var1 = this.getName();
      if (!this.isActive()) {
         var1 = var1 + "(inactive)";
      }

      var1 = var1 + this.toTransformSubstring();
      return this.contents == null ? var1 : var1 + this.contents.toString();
   }

   public static String getSaveExtension() {
      return "wob";
   }

   public WObject getServed() {
      int var1 = this.getSharerMode();
      if (var1 == 0) {
         Sharer var2 = this.getSharer();
         if (var2 != null) {
            var1 = var2.getMode();
         }
      }

      if ((var1 & 1) == 0) {
         return this;
      }

      SuperRoot var3 = this.getOwner();
      return var3 != null && var3 instanceof WObject ? ((WObject)var3).getServed() : null;
   }

   public void prerender(Camera var1) {
      WorldScriptManager.getInstance().onPrerender(this, var1);
   }

   public WorldServer getServer() {
      WObject var1 = this.getServed();
      NetworkObject var2;
      if (var1 instanceof Room) {
         var2 = ((Room)var1).getNetworkRoom();
      } else {
         var2 = (NetworkObject)var1;
      }

      if (var2 == null) {
         return null;
      }

      Debug.dAssert(var2 != this);
      return var2.getServer();
   }

   public Enumeration getAttributes() {
      return this.getSharer().getAttributes();
   }

   public Sharer getSharer() {
      if (this._sharer == null) {
         Debug.dAssert((this.flags & 16384) == 0);
         this._sharer = new Sharer();
         super.add(this._sharer);
      }

      return this._sharer;
   }

   public boolean hasSharer() {
      return this._sharer != null;
   }

   public Attribute getAttribute(int var1) {
      return this.getSharer().getAttribute(var1);
   }

   public int addAttribute(Attribute var1) {
      return this.getSharer().addAttribute(var1);
   }

   public int addShareableAttribute(Attribute var1) {
      return this.addAttribute(var1);
   }

   public void removeAttribute(Attribute var1) {
      this.getSharer().removeAttribute(var1);
   }

   public void removeShareableAttribute(Attribute var1) {
      this.removeAttribute(var1);
   }

   public boolean isShared() {
      return this._sharer != null;
   }

   public void notifyRegister(int var1) {
   }

   public boolean acceptsLeftClicks() {
      return this.getMouseOver();
   }

   public void releaseAuxilaryData() {
      if (this._sharer != null) {
         this._sharer.releaseAuxilaryData();
      }
   }

   static {
      nativeInit();
      standardBoxBumpCalc.setName("defaultBoxBumpCalc");
   }
}
