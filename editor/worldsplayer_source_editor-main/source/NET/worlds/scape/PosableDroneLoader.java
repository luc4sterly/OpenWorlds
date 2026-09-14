package NET.worlds.scape;

import NET.worlds.core.Archive;
import NET.worlds.network.URL;
import java.net.MalformedURLException;
import java.util.Enumeration;
import java.util.Vector;

public class PosableDroneLoader implements Runnable {
   static final boolean debug = false;
   DroneLoader loader;
   private static boolean useCachedFiles = URL.usingCachedAvatars();
   private Vector droneList = new Vector();

   PosableDroneLoader() {
   }

   public static boolean usingCache() {
      return useCachedFiles;
   }

   public static PendingDrone makePendingDrone(PosableDrone var0, URL var1) {
      return useCachedFiles ? new PendingCacheDrone(var0, var1) : new PendingDrone(var0, var1);
   }

   public void load(PosableDrone var1, URL var2) {
      PendingDrone var3 = makePendingDrone(var1, var2);
      this.droneList.addElement(var3);
      if (this.loader != null) {
         this.loader.wakeUp();
      }
   }

   public boolean isPending(PosableDrone var1, URL var2) {
      Vector var3 = (Vector)this.droneList.clone();
      Enumeration var4 = var3.elements();

      while (var4.hasMoreElements()) {
         PendingDrone var5 = (PendingDrone)var4.nextElement();
         if (var5.getUrl().toString().equals(var2.toString()) && var5.getDrone().toString().equals(var1.toString())) {
            return true;
         }
      }

      return false;
   }

   public void run() {
      this.loader = new DroneLoader();

      while (true) {
         this.loader.load(this.droneList);
      }
   }

   public static String getAvatarBaseName(URL var0) {
      String var1 = null;
      int var2 = var0.getAbsolute().indexOf(46);
      if (var2 != -1) {
         var1 = var0.getAbsolute().substring(7, var2);
      }

      return var1;
   }

   public static boolean avatarExistsLocally(URL var0) throws MalformedURLException {
      if (useCachedFiles) {
         return false;
      }

      if (var0.toString().equals(PosableShape.getDefaultURL().toString())) {
         return true;
      }

      if (!var0.getAbsolute().substring(0, 7).equals("avatar:")) {
         throw new MalformedURLException("Not an avatar URL");
      }

      String var1 = getAvatarBaseName(var0);
      if (var1 == null) {
         throw new MalformedURLException("No file extension");
      }

      URL var2 = URL.make(var0, var1 + ".bod");
      return Archive.exists(var2.unalias());
   }
}
