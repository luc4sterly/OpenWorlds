package NET.worlds.scape;

import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.util.Enumeration;
import java.util.Vector;

class DroneLoader {
   private int MaxDroneLoadingRate = 2000;
   static final boolean debug = false;

   DroneLoader() {
      int var1 = IniFile.gamma().getIniInt("avatars", 24);
      int var2 = IniFile.gamma().getIniInt("droneLoadRate", 8000);
      this.MaxDroneLoadingRate = var2 / var1;
   }

   public synchronized void load(Vector var1) {
      try {
         if (var1.size() > 0) {
            Vector var2 = (Vector)var1.clone();
            Enumeration var3 = var2.elements();

            while (var3.hasMoreElements()) {
               PendingDrone var4 = (PendingDrone)var3.nextElement();
               if (var4.getDrone().discarded) {
                  var1.removeElement(var4);
               } else {
                  loadDrone(var4);
                  var1.removeElement(var4);
               }
            }
         }

         this.wait();
      } catch (InterruptedException var5) {
      }
   }

   public synchronized void wakeUp() {
      this.notify();
   }

   private static void loadDrone(PendingDrone var0) {
      if (!var0.getLoaded()) {
         Enumeration var1 = PosableShape.getComponentAvatars(var0.getUrl());
         if (var1 != null) {
            while (var1.hasMoreElements()) {
               String var2 = (String)var1.nextElement();
               var0.download(URL.make(var2));
            }
         }

         PosableShape var4;
         if (VehicleShape.isVehicle(var0.getUrl())) {
            var4 = new VehicleShape();
         } else {
            var4 = new PosableShape();
         }

         boolean var3 = ProgressiveAdder.get().enabled();
         if (var3) {
            ProgressiveAdder.get().scheduleForAdd(var0.getDrone(), var4);
         }

         var4.setURL(var0.getUrl());
         var4.setVisible(true);
         var4.setBumpable(false);
         if (!var0.getDrone().isPilotDrone(var0.getUrl())) {
            var4.enableLOD(true);
         }

         if (!var3) {
            var0.getDrone().SetPendingShape(var4);
         }

         var0.setLoaded();
      }
   }
}
