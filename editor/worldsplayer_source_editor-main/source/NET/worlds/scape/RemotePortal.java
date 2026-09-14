package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.io.IOException;
import java.util.Enumeration;

public class RemotePortal extends WObject {
   private static Object classCookie = new Object();

   RemotePortal() {
   }

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      Portal var2 = new Portal();
      var1.replace(this, var2);
      int var3 = var1.restoreVersion(classCookie);
      Surface var4 = null;
      Surface var5 = null;
      var2.superRestoreState(var1);
      Point3 var6 = (Point3)var1.restore();
      Point3 var7 = (Point3)var1.restore();
      var2.moveTo(var6);
      var2.setFarCorner(var7);
      Point3 var8 = (Point3)var1.restore();
      Point3 var9 = (Point3)var1.restore();
      URL var10 = URL.restore(var1);
      String var11 = var1.restoreString();
      var2.connectTo(var10, var11, var8, var9);
      switch (var3) {
         case 0:
            var1.setOldFlag();
            var1.restoreBoolean();
            var4 = (Surface)var1.restoreMaybeNull();
            var5 = (Surface)var1.restoreMaybeNull();
            var1.restoreMaybeNull();
            break;
         case 1:
            var4 = (Surface)var1.restoreMaybeNull();
            var5 = (Surface)var1.restoreMaybeNull();
            break;
         default:
            throw new TooNewException();
      }

      if (var5 instanceof Surface) {
         Surface var12 = var5;
         Material var13 = var12.getMaterial();
         var12.setMaterial(null);
         var2.setMaterial(var13);
      }

      if (var4 instanceof Surface) {
         Surface var16 = var4;
         Material var18 = var16.getMaterial();
         var16.setMaterial(null);
         var2.setMaterial(var18);
      }

      if (var5 != null) {
         for (Enumeration var17 = var5.getHandlers(); var17.hasMoreElements(); var17 = var5.getHandlers()) {
            SuperRoot var19 = (SuperRoot)var17.nextElement();
            var5.removeHandler(var19);
            var2.addHandler(var19);
         }
      }
   }
}
