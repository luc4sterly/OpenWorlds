package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.awt.Color;
import java.io.IOException;

public class RoomEnvironment extends WObject {
   private int lightid = 0;
   private int lightid2 = 0;
   int nextVertex = 1;
   boolean wasEdited = false;
   private static Object classCookie = new Object();
   private int sceneID;

   RoomEnvironment() {
   }

   public static native void nativeInit();

   protected void addRwChildren(WObject var1) {
      this.createClump();
      Room var2 = (Room)this.getOwner();
      this.createScene(var2);
      this.newRwChildHelper();
      this.addLight(var2.getLightPosition(), var2.getLightColor());
   }

   protected void noteAddingTo(SuperRoot var1) {
      Room var2 = (Room)var1;
   }

   private void addLight(Point3Temp var1, Color var2) {
      Debug.assert_(this.lightid == 0);
      float var3 = var2.getRed() / 256.0F;
      float var4 = var2.getGreen() / 256.0F;
      float var5 = var2.getBlue() / 256.0F;
      this.lightid = Room.addLight(this.sceneID, var1.x, var1.y, var1.z, var3, var4, var5);
      this.lightid2 = Room.addLight(this.sceneID, -var1.x, -var1.y, -var1.z, var3 * 0.5F, var4 * 0.5F, var5 * 0.5F);
   }

   void setLightPosition(float var1, float var2, float var3) {
      if (this.lightid != 0) {
         Room.setLightPosition(this.lightid, var1, var2, var3);
      }

      if (this.lightid2 != 0) {
         Room.setLightPosition(this.lightid2, -var1, -var2, -var3);
      }
   }

   void setLightColor(float var1, float var2, float var3) {
      if (this.lightid != 0) {
         Room.setLightColor(this.lightid, var1, var2, var3);
      }

      if (this.lightid2 != 0) {
         Room.setLightColor(this.lightid2, var1 * 0.5F, var2 * 0.5F, var3 * 0.5F);
      }
   }

   public BoundBoxTemp getBoundBox() {
      return BoundBoxTemp.make(Point3Temp.make(), Point3Temp.make());
   }

   protected void markVoid() {
      super.markVoid();
      this.destroyScene();
      this.lightid = 0;
      this.lightid2 = 0;
   }

   public void markClumpEdited() {
      this.wasEdited = true;
   }

   public void prerender() {
      if (this.wasEdited) {
         this.wasEdited = false;
         this.doneWithEditing();
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            var1.setOldFlag();
            super.restoreState(var1);
            var1.restore();
            break;
         case 1:
            super.restoreState(var1);
            break;
         default:
            throw new TooNewException();
      }
   }

   native void createScene(Room var1);

   native void destroyScene();

   static {
      nativeInit();
   }
}
