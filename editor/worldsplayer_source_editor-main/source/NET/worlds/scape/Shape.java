package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.StatMemNode;
import NET.worlds.core.Archive;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.awt.PopupMenu;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.Enumeration;
import java.util.StringTokenizer;
import java.util.Vector;

public class Shape extends WObject implements MainCallback, Animatable, MouseDownHandler {
   static int disableLOD = IniFile.gamma().getIniInt("DisableLOD", 1);
   static int forceLODLevel;
   Vector listeners = null;
   URL url;
   boolean mustReload;
   boolean recomputeLODs;
   int numDetailLevels;
   int currentLOD;
   int lastLOD;
   URL[] lodURLs;
   float[] lodDistanceTriggers;
   float[] lodAreas;
   protected static int NORMAL;
   protected static int ERROR;
   protected static int LOADING;
   private int pendingShape;
   boolean isDefault;
   static URL xShape;
   URL realFile;
   private boolean prepareRoom;
   private Material animatableMaterial;
   protected int animatableClumpID;
   Vector textures;
   private static Object classCookie;

   public Shape() {
      this.pendingShape = NORMAL;
      this.isDefault = false;
      this.numDetailLevels = 0;
      this.recomputeLODs = true;
      this.currentLOD = this.lastLOD = 0;
   }

   void addLoadListener(ShapeLoaderListener var1) {
      if (this.listeners == null) {
         this.listeners = new Vector();
      }

      if (!this.listeners.contains(var1)) {
         this.listeners.addElement(var1);
      }
   }

   private void notifyLoadListeners() {
      if (this.listeners != null) {
         Enumeration var1 = this.listeners.elements();
         if (var1 != null) {
            while (var1.hasMoreElements()) {
               ShapeLoaderListener var2 = (ShapeLoaderListener)var1.nextElement();
               var2.notifyShapeLoaded(this);
            }
         }

         this.listeners.removeAllElements();
      }
   }

   void removeLoadListener(ShapeLoaderListener var1) {
      if (this.listeners != null) {
         this.listeners.removeElement(var1);
      }
   }

   public void setBaseLODURL(URL var1) {
      if (disableLOD == 0 && var1 != null && var1.getAbsolute().startsWith("avatar:")) {
         int var2 = var1.toString().indexOf(58);
         int var3 = var1.toString().indexOf(46);
         String var4 = var1.toString().substring(var2 + 1, var3);
         String var5 = "avatar:lod/" + var4 + ".lod";

         URL var6;
         try {
            var6 = new URL(var5);
         } catch (MalformedURLException var16) {
            return;
         }

         byte[] var7 = Archive.readTextFile(var6.unalias());
         if (var7 != null) {
            String var8 = new String(var7);
            StringTokenizer var9 = new StringTokenizer(var8);
            this.numDetailLevels = Integer.parseInt(var9.nextToken());
            this.lodURLs = new URL[this.numDetailLevels];
            this.lodAreas = new float[this.numDetailLevels];
            this.lodDistanceTriggers = new float[this.numDetailLevels];
            int var10 = 0;
            this.lodURLs[var10] = var1;

            for (this.lodAreas[var10++] = 0.0F; var9.hasMoreTokens(); var10++) {
               String var11 = var9.nextToken();
               String var12 = var9.nextToken();
               Float var13 = new Float(var12);
               this.lodAreas[var10] = var13;

               try {
                  this.lodURLs[var10] = new URL("avatar:lod/" + var4 + var11 + var1.toString().substring(var3));
               } catch (MalformedURLException var15) {
                  System.out.println("Error creating lod URL!\n");
                  this.numDetailLevels = 0;
                  return;
               }
            }
         }
      }

      this.recomputeLODs = true;
   }

   public native float calcLODDistance(float var1);

   public synchronized boolean setLOD(float var1) {
      boolean var2 = false;
      if (this.numDetailLevels > 0) {
         if (forceLODLevel != -1) {
            int var5 = forceLODLevel > this.numDetailLevels - 1 ? this.numDetailLevels - 1 : forceLODLevel;
            if (var5 != this.lastLOD) {
               this.setURL(this.lodURLs[var5]);
               this.currentLOD = this.lastLOD = var5;
               return true;
            }

            return false;
         }

         if (this.recomputeLODs) {
            for (int var3 = 0; var3 < this.numDetailLevels; var3++) {
               this.lodDistanceTriggers[var3] = this.calcLODDistance(this.lodAreas[var3]);
            }

            this.recomputeLODs = false;
         }

         for (int var4 = 0; var4 < this.numDetailLevels; var4++) {
            if (this.lodDistanceTriggers[var4] > var1) {
               if (var4 != this.lastLOD) {
                  this.currentLOD = var4;
                  if (this instanceof PosableShape) {
                     ((PosableShape)this).removeSubparts();
                  }

                  if (this.isLoaded()) {
                     this.releasePendingShape();
                  }

                  this.setURL(this.lodURLs[var4]);
               }
               break;
            }
         }
      }

      if (this.lastLOD != this.currentLOD) {
         var2 = true;
      }

      this.lastLOD = this.currentLOD;
      return var2;
   }

   public URL getURL() {
      return this.url;
   }

   synchronized boolean isLoaded() {
      return this.pendingShape < -2 || this.pendingShape > 0;
   }

   public boolean isFullyLoaded() {
      return this.pendingShape == NORMAL && this.hasClump();
   }

   public boolean handle(MouseDownEvent var1) {
      SuperRoot var2 = this;

      while (var2.getOwner() != null) {
         var2 = var2.getOwner();
         if (var2 instanceof PosableShape && var2.getOwner() instanceof PosableDrone) {
            return false;
         }
      }

      PopupMenu var3 = new PopupMenu();
      if (AnimatedActionManager.get().buildActionMenu(var3, this)) {
         Console var4 = Console.getActive();
         if (var4 instanceof DefaultConsole) {
            DefaultConsole var5 = (DefaultConsole)var4;
            if (var5.getRender() != null) {
               var5.getRender().add(var3);
               var3.addActionListener(AnimatedActionManager.get());
               var3.show(var5.getRender(), var1.x, var1.y);
               return true;
            }
         }
      }

      var3 = WorldScriptManager.getInstance().shapeClicked(this);
      if (var3 != null) {
         Console var7 = Console.getActive();
         if (var7 instanceof DefaultConsole) {
            DefaultConsole var8 = (DefaultConsole)var7;
            if (var8.getRender() != null) {
               var8.getRender().add(var3);
               var3.addActionListener(WorldScriptManager.getInstance());
               var3.show(var8.getRender(), var1.x, var1.y);
               return true;
            }
         }
      }

      return false;
   }

   void setState(int var1, Vector var2) {
      if (this.isLoaded()) {
         this.releasePendingShape();
      }

      this.releaseTextures();
      this.pendingShape = var1;
      if (this.isLoaded()) {
         this.shapeRedraw();
      }

      this.textures = var2;
   }

   public synchronized void setURL(URL var1) {
      if (var1 != this.url && (var1 == null || !var1.equals(this.url))) {
         this.url = var1;
         this.realFile = null;
         boolean var2 = this.mustReload;
         this.mustReload = true;
         this.setState(NORMAL, null);
         this.shapeRedraw();
         this.mustReload = var2;
      }
   }

   void shapeRedraw() {
      if (this.hasClump()) {
         this.reclump();
      }

      this.notifyLoadListeners();
   }

   boolean isAv() {
      return this.url != null && this.url.getAbsolute().startsWith("avatar:");
   }

   static String getBodBase(URL var0) {
      String var1 = var0.getBase();
      int var2 = var1.length();
      return var1.endsWith(".bod") && var2 >= 6 ? var1.substring(0, var2 - 6) : null;
   }

   int getBodPartNum() {
      String var1 = this.url.getInternal();
      int var2 = var1.length();
      return var1.endsWith(".bod") && var2 >= 6 ? (var1.charAt(var2 - 6) - 48) * 10 + (var1.charAt(var2 - 5) - 48) : 0;
   }

   protected synchronized void addRwChildren(WObject var1) {
      Debug.dAssert(!this.hasClump());
      if (this.pendingShape == NORMAL && this.url != null) {
         String var2;
         if ((var2 = this.url.getAbsolute()).startsWith("system:subclump")) {
            SuperRoot var3 = this.getOwner();
            if (var3 instanceof Shape) {
               Shape var4 = (Shape)var3;
               int var5 = 0;

               try {
                  var5 = new Integer(var2.substring(15));
               } catch (NumberFormatException var7) {
               }

               this.animatableClumpID = ((Shape)var3).extractSubclump(var5);
               this.clumpID = addEmptyParentClump(this.animatableClumpID);
               this.isDefault = false;
               this.newRwClumpChildHelper(var1);
               return;
            }

            this.pendingShape = ERROR;
         } else {
            this.setState(-2, null);
            this.isDefault = false;
            this.realFile = this.isAv() ? xShape : this.url;
            if (this.url.endsWith(".bod")) {
               String var8 = getBodBase(this.url);
               this.realFile = URL.make(this.url, var8 + ".bod");
            }

            BackgroundLoader.get(new ShapeLoader(this), this.realFile);
         }
      }

      if (!this.isLoaded()) {
         this.clumpID = makeDefaultShape();
         this.isDefault = true;
      } else {
         this.clumpID = this.pendingShape;
         this.pendingShape = NORMAL;
         this.isDefault = false;
      }

      this.newRwClumpChildHelper(var1);
   }

   public void recursiveAddRwChildren(WObject var1) {
      if (this.animatableMaterial != null && this.animatableClumpID == 0) {
         this.animatableMaterial.addRwChildren();
      }

      super.recursiveAddRwChildren(var1);
      if (this.animatableMaterial != null) {
         this.nativeSetMaterial(this.animatableMaterial);
      }
   }

   public Material getMaterial() {
      return this.animatableMaterial;
   }

   protected void voidClump() {
      if (!this.mustReload && !this.isDefault && this.pendingShape == NORMAL) {
         this.pendingShape = this.extractClump();
      } else {
         if (this.isLoaded()) {
            this.releasePendingShape();
         }

         this.releaseTextures();
         super.voidClump();
         this.animatableClumpID = 0;
         if (this.animatableMaterial != null) {
            this.animatableMaterial.markVoid();
         }
      }
   }

   public void discard() {
      if (this.isLoaded()) {
         this.releasePendingShape();
      }

      this.releaseTextures();
      super.discard();
   }

   public void makeSpecials() {
      if (!this.prepareRoom) {
         Vector var1 = new Vector();
         Enumeration var2 = this.getRoom().getContents();

         while (var2.hasMoreElements()) {
            Object var3 = var2.nextElement();
            if (var3 instanceof WObject) {
               WObject var4 = (WObject)var3;
               if (var4.getAutobuilt()) {
                  var1.addElement(var4);
               }
            }
         }

         var2 = var1.elements();

         while (var2.hasMoreElements()) {
            ((WObject)var2.nextElement()).detach();
         }

         Main.register(this);
         this.prepareRoom = true;
      }
   }

   public void mainCallback() {
      if (this.hasClump()) {
         convertSpecial(this.clumpID);
         this.prepareRoom = false;
         Main.unregister(this);
      }
   }

   public void setMaterial(Material var1) {
      if (this.animatableMaterial != null) {
         this.animatableMaterial.detach();
      }

      this.add(var1);
      this.animatableMaterial = var1;
      this.nativeSetMaterial(var1);
   }

   public native void nativeSetMaterial(Material var1);

   protected native int extractSubclump(int var1);

   protected static native int addEmptyParentClump(int var0);

   private static native void convertSpecial(int var0);

   public static native void nativeInit();

   private static native int makeDefaultShape();

   private native void releasePendingShape();

   private void releaseTextures() {
      if (this.textures != null) {
         Enumeration var1 = this.textures.elements();

         while (var1.hasMoreElements()) {
            ((Texture)var1.nextElement()).decRef();
         }

         this.textures = null;
      }
   }

   protected void finalize() {
      if (this.isLoaded()) {
         this.releasePendingShape();
      }

      this.releaseTextures();
      super.finalize();
   }

   public void setReload(boolean var1) {
      this.mustReload = var1;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "File"), "rwx;rwg;bod");
            } else if (var3 == 1) {
               var5 = this.url;
            } else if (var3 == 2) {
               URL var6 = (URL)var4;
               if (var6 != null && var6.equals(this.url)) {
                  this.setURL(null);
               }

               this.setURL(var6);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "PrepareRoom"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.prepareRoom);
            } else if (var3 == 2 && (Boolean)var4) {
               this.makeSpecials();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      URL.save(var1, this.url);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
         case 1:
            super.restoreState(var1);
            URL var2 = URL.restore(var1);
            if (var2 != null) {
               this.setURL(var2);
            }

            return;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.url + "]";
   }

   static {
      if (ProgressiveAdder.get().enabled()) {
         disableLOD = 1;
      }

      if (disableLOD == 1) {
         System.out.println("Avatar dynamic LOD disabled.");
      } else {
         System.out.println("Using avatar dynamic LOD when available.");
      }

      StatMemNode var0 = StatMemNode.getNode();
      forceLODLevel = IniFile.gamma().getIniInt("LowResAvs", -1);
      if (forceLODLevel != -1) {
         System.out.println("Avatar LOD's forced to level " + forceLODLevel);
         disableLOD = 0;
      }

      int var1 = IniFile.gamma().getIniInt("ForceLowResRAMLimit", 33554432);
      var0.updateMemoryStatus();
      if (var0._totPhysMem <= var1 && var0._totPhysMem > 0) {
         System.out.println("Low memory detected, using LOD 2 for all avatars.");
         forceLODLevel = 2;
         disableLOD = 0;
      }

      NORMAL = 0;
      ERROR = -1;
      LOADING = -2;
      xShape = URL.make("home:avatar.rwg");
      nativeInit();
      classCookie = new Object();
   }
}
