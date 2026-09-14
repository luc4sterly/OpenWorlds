package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.core.Debug;
import java.io.IOException;
import java.util.Vector;

public class Transform extends SuperRoot {
   private static Vector recycled = new Vector();
   private int transformID;
   private float xScale;
   private float yScale;
   private float zScale;
   private static Object classCookie = new Object();

   public static native void nativeInit();

   public static Transform make() {
      Debug.dAssert(Main.isMainThread());
      int var0 = recycled.size() - 1;
      if (var0 == -1) {
         return new Transform();
      }

      Transform var1 = (Transform)recycled.elementAt(var0);
      recycled.removeElementAt(var0);
      return var1;
   }

   public void recycle() {
      if (recycled.size() < 100) {
         this.makeIdentity();
         recycled.addElement(this);
      }
   }

   protected Transform() {
      this.makeIdentity();
   }

   public native float getX();

   public native float getY();

   public native float getZ();

   public Point3Temp getPosition() {
      return Point3Temp.make(this.getX(), this.getY(), this.getZ());
   }

   public void setZ(float var1) {
      this.moveTo(this.getX(), this.getY(), var1);
   }

   public float getScaleX() {
      return this.xScale;
   }

   public float getScaleY() {
      return this.yScale;
   }

   public float getScaleZ() {
      return this.zScale;
   }

   public Point3Temp getScale() {
      return Point3Temp.make(this.getScaleX(), this.getScaleY(), this.getScaleZ());
   }

   public float getTotalScale() {
      return (this.getScaleX() + this.getScaleY() + this.getScaleZ()) / 3.0F;
   }

   public native float getYaw();

   public native float getPitch();

   public native float getSpin(Point3Temp var1);

   protected void noteTransformChange() {
   }

   public Transform raise(float var1) {
      return this.moveBy(0.0F, 0.0F, var1);
   }

   public Transform lower(float var1) {
      return this.moveBy(0.0F, 0.0F, -var1);
   }

   public Transform yaw(float var1) {
      return this.spin(0.0F, 0.0F, 1.0F, var1);
   }

   public Transform roll(float var1) {
      return this.spin(0.0F, 1.0F, 0.0F, var1);
   }

   public Transform pitch(float var1) {
      return this.spin(1.0F, 0.0F, 0.0F, var1);
   }

   public Transform scale(float var1) {
      return this.scale(var1, var1, var1);
   }

   protected void finalize() {
      this.nativeFinalize();
      super.finalize();
   }

   public native Transform pre(Transform var1);

   public Transform post(Transform var1) {
      Point3Temp var2 = var1.getScale();
      if (!this.checkPostScale(var2)) {
         return this;
      }

      this.xScale = this.xScale * var2.x;
      this.yScale = this.yScale * var2.y;
      this.zScale = this.zScale * var2.z;
      return this.postHelper(var1);
   }

   private boolean checkPostScale(Point3Temp var1) {
      if (this.getSpin(Point3Temp.make()) != 0.0F && (var1.x != var1.y || var1.y != var1.z)) {
         Console.println(Console.message("non-uniform"));
         return false;
      } else {
         return true;
      }
   }

   private native Transform postHelper(Transform var1);

   public native Transform makeIdentity();

   public Transform moveBy(Point3Temp var1) {
      return this.moveBy(var1.x, var1.y, var1.z);
   }

   public native Transform moveBy(float var1, float var2, float var3);

   public Transform moveTo(Point3Temp var1) {
      return this.moveTo(var1.x, var1.y, var1.z);
   }

   public native Transform moveTo(float var1, float var2, float var3);

   public native Transform premoveBy(float var1, float var2, float var3);

   public native Transform scale(float var1, float var2, float var3);

   public Transform scale(Point3Temp var1) {
      return this.scale(var1.x, var1.y, var1.z);
   }

   public void setScale(float var1, float var2, float var3) {
      this.scale(var1 / this.xScale, var2 / this.yScale, var3 / this.zScale);
   }

   public void setScale(Point3Temp var1) {
      this.setScale(var1.x, var1.y, var1.z);
   }

   public Transform postscale(float var1, float var2, float var3) {
      return this.postscale(Point3Temp.make(var1, var2, var3));
   }

   public Transform postscale(Point3Temp var1) {
      if (!this.checkPostScale(var1)) {
         return this;
      }

      this.xScale = this.xScale * var1.x;
      this.yScale = this.yScale * var1.y;
      this.zScale = this.zScale * var1.z;
      return this.postscaleHelper(var1.x, var1.y, var1.z);
   }

   private native Transform postscaleHelper(float var1, float var2, float var3);

   public Transform worldScale(float var1, float var2, float var3) {
      return this.worldScale(Point3Temp.make(var1, var2, var3));
   }

   public Transform worldScale(Point3Temp var1) {
      return !this.checkPostScale(var1) ? this : this.scale(var1);
   }

   public native Transform spin(float var1, float var2, float var3, float var4);

   public Transform spin(Point3Temp var1, float var2) {
      return this.spin(var1.x, var1.y, var1.z, var2);
   }

   public Transform postspin(Point3Temp var1, float var2) {
      return this.postspin(var1.x, var1.y, var1.z, var2);
   }

   public native Transform postspin(float var1, float var2, float var3, float var4);

   public Transform worldSpin(float var1, float var2, float var3, float var4) {
      return this.spin(this.worldVecToObjectVec(Point3Temp.make(var1, var2, var3)), var4);
   }

   private native void nativeFinalize();

   public Transform getTransform() {
      Transform var1 = make();
      var1.setTransform(this);
      return var1;
   }

   public native void setTransform(Transform var1);

   public native Transform invert();

   public Transform getObjectToWorldMatrix() {
      return this.getTransform();
   }

   private Point3Temp worldVecToObjectVec(Point3Temp var1) {
      Transform var2 = this.getObjectToWorldMatrix().invert();
      Point3Temp var3 = Point3Temp.make(var1).vectorTimes(var2).times(this.getScale());
      var2.recycle();
      return var3;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = TransformPropertyEditor.make(new Property(this, var1, "Transform"));
            } else if (var3 == 1) {
               var5 = this.getTransform();
            } else if (var3 == 2) {
               this.setTransform((Transform)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.xScale);
      var1.saveFloat(this.yScale);
      var1.saveFloat(this.zScale);
      float[] var2 = this.getGuts();

      for (int var3 = 0; var3 < 16; var3++) {
         var1.saveFloat(var2[var3]);
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
         case 0:
            this.xScale = this.yScale = this.zScale = var1.restoreFloat();
            float[] var4 = new float[16];

            for (int var5 = 0; var5 < 16; var5++) {
               var4[var5] = var1.restoreFloat();
            }

            this.setGuts(var4);
            break;
         case 2:
            super.restoreState(var1);
            this.xScale = var1.restoreFloat();
            this.yScale = var1.restoreFloat();
            this.zScale = var1.restoreFloat();
            float[] var2 = new float[16];

            for (int var3 = 0; var3 < 16; var3++) {
               var2[var3] = var1.restoreFloat();
            }

            this.setGuts(var2);
            break;
         default:
            throw new TooNewException();
      }
   }

   private native float[] getGuts();

   public native boolean isTransformEqual(Transform var1);

   private native void setGuts(float[] var1);

   public String toTransformSubstring() {
      Point3Temp var1 = Point3Temp.make();
      float var2 = this.getSpin(var1);
      Point3Temp var3 = this.getPosition();
      return var2 == 0.0F && this.xScale == 1.0F && this.yScale == 1.0F && this.zScale == 1.0F && var3.x == 0.0F && var3.y == 0.0F && var3.z == 0.0F
         ? "[identity]"
         : "[pos ("
            + var3
            + "), scale ("
            + (this.xScale == this.yScale && this.yScale == this.zScale ? "" + this.xScale : "" + this.xScale + "," + this.yScale + "," + this.zScale)
            + "), rot ("
            + var1
            + "@"
            + var2
            + ")]";
   }

   public String toString() {
      return this.getName() + this.toTransformSubstring();
   }

   public Transform printGuts() {
      float[] var1 = this.getGuts();
      Debug.dAssert(var1.length == 16);
      String[] var2 = new String[16];
      int var3 = 0;

      for (int var4 = 0; var4 < 16; var4++) {
         var2[var4] = Float.toString(var1[var4]);
         var3 = Math.max(var3, var2[var4].length());
      }

      for (int var8 = 0; var8 < 4; var8++) {
         for (int var5 = 0; var5 < 4; var5++) {
            String var6 = var2[var8 * 4 + var5];
            int var7 = var3 - var6.length() + 1;
            System.out.print(var6);

            while (var7-- != 0) {
               System.out.print(" ");
            }
         }

         System.out.println("");
      }

      return this;
   }

   static {
      nativeInit();
   }
}
