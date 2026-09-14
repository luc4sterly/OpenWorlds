package NET.worlds.scape;

import java.io.IOException;

public class Light extends WObject {
   protected int lightID;
   private static Object classCookie = new Object();

   protected void addRwChildren(WObject var1) {
      super.addRwChildren(var1);
      Point3Temp var2 = this.getWorldPosition();
   }

   protected void markVoid() {
      super.markVoid();
      if (this.lightID != 0) {
         destroyLight(this.lightID);
      }
   }

   protected void noteTransformChange() {
      super.noteTransformChange();
      if (this.lightID != 0) {
         setLightTransform(this.lightID, this.clumpID);
      }
   }

   private static native void setLightTransform(int var0, int var1);

   private static native void destroyLight(int var0);

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         default:
            return super.properties(var1, var2 + 0, var3, var4);
      }
   }

   public void saveState(Saver var1) throws IOException {
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
}
