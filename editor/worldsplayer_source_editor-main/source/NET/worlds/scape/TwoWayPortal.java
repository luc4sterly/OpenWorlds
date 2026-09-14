package NET.worlds.scape;

import java.io.IOException;

public class TwoWayPortal extends Portal {
   private static Object classCookie = new Object();

   public TwoWayPortal(String var1, float var2, float var3, float var4, float var5, float var6, float var7) {
      super(var2, var3, var4, var5, var6, var7);
      this.setFarSideInfo(null, var1, null);
   }

   public TwoWayPortal() {
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }

   public void detach() throws ClassCastException {
      super.detach();
      Portal var1 = this.farSide();
      if (var1 != null) {
         var1.detach();
      }
   }

   public void reset(boolean var1) {
      super.reset(var1);
      if (this.farSideRoom() != null) {
         Portal var2 = this.farSide();
         if (var2 != null) {
            if (var2.isActive()) {
               return;
            }

            var2.detach();
            this.bidisconnect();
         }

         Point3Temp var3 = this.getWorldPosition();
         Point3Temp var4 = this.getFarCorner();
         var2 = new Portal(var4.x, var4.y, var3.z, var3.x, var3.y, var4.z);
         this.farSideRoom().add(var2);
         this.biconnect(var2);
      }
   }
}
