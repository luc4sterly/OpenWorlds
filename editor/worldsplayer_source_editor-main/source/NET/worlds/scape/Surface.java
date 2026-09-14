package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;
import java.awt.Color;
import java.io.IOException;
import java.text.MessageFormat;

public class Surface extends WObject implements Animatable {
   private int[] polygonIDs;
   protected Material material;
   private static Object classCookie = new Object();

   public Surface(Material var1) {
      if (var1 != null && var1.getOwner() != null) {
         var1 = (Material)var1.clone();
      }

      this.setMaterial(var1);
   }

   Surface() {
   }

   public static native void nativeInit();

   public void loadInit() {
      this.setMaterial(null);
   }

   protected void markVoid() {
      super.markVoid();
      this.polygonIDs = null;
      this.material.markVoid();
   }

   public void recursiveAddRwChildren(WObject var1) {
      this.material.addRwChildren();
      super.recursiveAddRwChildren(var1);
      int var2 = this.material.getHRes();
      int var3 = this.material.getVRes();
      int var4 = this.getNumVerts();
      if (var4 != 4 || !this.material.getHiRes() && !this.uvOutOfRange()) {
         Debug.assert_(var4 > 0);
         int[] var7 = new int[var4];

         for (int var8 = 0; var8 < var4; var8++) {
            var7[var8] = var8 + 1;
         }

         this.polygonIDs = new int[1];
         this.addPolygon(var7);
      } else {
         int var5 = this.addSubPolys(var2, var3);
         if (var5 >= 100 && Console.getFrame().isShaperVisible()) {
            Object[] var6 = new Object[]{new Integer(var5), new String(this.getRoom().getName()), new String(this.getName())};
            Console.println(MessageFormat.format(Console.message("Memory-hog"), var6));
         }
      }

      this.nativeSetMaterial();
      this.doneWithEditing();
   }

   protected void setVFlip(boolean var1) {
      if (var1) {
         this.flags |= 1048576;
      } else {
         this.flags &= -1048577;
      }
   }

   protected void setUFlip(boolean var1) {
      if (var1) {
         this.flags |= 524288;
      } else {
         this.flags &= -524289;
      }
   }

   protected boolean getUFlip() {
      return (this.flags & 524288) != 0;
   }

   protected boolean getVFlip() {
      return (this.flags & 1048576) != 0;
   }

   public void setMaterial(Material var1) {
      this.setMaterial(var1, false);
   }

   public void setMaterial(Material var1, boolean var2) {
      if (var1 == null) {
         var1 = new Material(new Color((int)(Math.random() * 1.6777216E7)));
      } else if (this.material == var1 && !var2) {
         return;
      }

      boolean var3 = this.polygonIDs != null
         && this.polygonIDs.length >= 1
         && this.material.getHRes() == var1.getHRes()
         && this.material.getVRes() == var1.getVRes();
      if (this.material != var1) {
         if (this.material != null) {
            this.material.detach();
         }

         this.add(var1);
         this.material = var1;
      }

      if (this.polygonIDs != null) {
         if (var3) {
            this.nativeSetMaterial();
         } else {
            this.reclump();
         }
      }
   }

   private native void nativeSetMaterial();

   private native boolean uvOutOfRange();

   public Material getMaterial() {
      return this.material;
   }

   native void addVertex(float var1, float var2, float var3, float var4, float var5);

   native void addPolygon(int[] var1);

   private native int addSubPolys(int var1, int var2);

   public void getChildren(DeepEnumeration var1) {
      super.getChildren(var1);
      var1.addChildElement(this.material);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Material");
            } else if (var3 == 1) {
               var5 = this.material;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.save(this.material);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.setMaterial(Material.restore(var1));
            break;
         case 1:
            super.restoreState(var1);
            this.setMaterial((Material)var1.restore());
            break;
         default:
            throw new TooNewException();
      }
   }

   static {
      nativeInit();
   }
}
