package NET.worlds.scape;

import NET.worlds.core.IniFile;
import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;

public class PendingCacheDrone extends PendingDrone {
   static String upgradeDir = IniFile.gamma().getIniString("avatarDir", "avatar/");

   public PendingCacheDrone(PosableDrone var1, URL var2) {
      super(var1, var2);
   }

   public synchronized void download(URL var1) {
   }

   public static native void nativeInit();

   public static native void nativeDestroy();

   public static synchronized native void notifySeqLoaded(int var0, String var1);

   public static void downloadSeqFile(String var0, boolean var1, int var2) {
      var0 = var0.toLowerCase();
      if (!PosableDroneLoader.usingCache()) {
         notifySeqLoaded(var2, ".\\avatars\\" + var0);
      } else {
         String var3 = NetUpdate.getUpgradeServerURL() + upgradeDir + var0;
         if (var1) {
            CacheFile var4 = Cache.getFile(URL.make(var3));
            var4.waitUntilLoaded();
            if (var4.error()) {
               return;
            }

            notifySeqLoaded(var2, var4.getLocalName());
         } else {
            new SeqFile(var2, URL.make(var3));
         }
      }
   }

   public static String getAvatarDatPath() {
      if (!PosableDroneLoader.usingCache()) {
         return ".\\avatars\\avatars.dat";
      }

      if (IniFile.gamma().getIniInt("localavatarsdat", 0) == 1) {
         return ".\\avatars\\avatars.dat";
      }

      String var0 = NetUpdate.getUpgradeServerURL() + upgradeDir + "avatars.dat";
      CacheFile var1 = Cache.getFile(URL.make(var0));
      var1.waitUntilLoaded();
      return var1.error() ? null : var1.getLocalName();
   }

   static {
      if (!upgradeDir.endsWith("/")) {
         upgradeDir = upgradeDir + "/";
      }

      nativeInit();
   }
}
