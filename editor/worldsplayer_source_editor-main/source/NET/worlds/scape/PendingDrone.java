package NET.worlds.scape;

import NET.worlds.core.Archive;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;
import java.util.zip.ZipOutputStream;

public class PendingDrone {
   static boolean doAvatarUpdates = true;
   protected PosableDrone drone;
   protected URL url;
   protected boolean loaded;
   static final boolean debug = false;

   PendingDrone(PosableDrone var1, URL var2) {
      this.drone = var1;
      this.url = var2;
      this.loaded = false;
   }

   public PosableDrone getDrone() {
      return this.drone;
   }

   public URL getUrl() {
      return this.url;
   }

   public boolean getLoaded() {
      return this.loaded;
   }

   public void setLoaded() {
      this.loaded = true;
   }

   public synchronized void download(URL var1) {
      if (doAvatarUpdates) {
         if (var1 != null) {
            try {
               if (PosableDroneLoader.avatarExistsLocally(var1)) {
                  return;
               }
            } catch (MalformedURLException var5) {
               return;
            }

            String var2 = PosableDroneLoader.getAvatarBaseName(var1);
            Debug.assert_(var2 != null);
            var2 = var2.toLowerCase();
            URL var3 = URL.make(NetUpdate.getUpgradeServerURL() + "AvatarUpgrades/" + var2 + ".zip");
            CacheFile var4 = Cache.getFile(var3);
            var4.waitUntilLoaded();
            if (!var4.error()) {
               this.finishDownload(var4.getLocalName());
               var4.close();
            }
         }
      }
   }

   public synchronized boolean finishDownload(String var1) {
      ZipFile var2;
      try {
         var2 = new ZipFile(var1);
      } catch (IOException var11) {
         this.notify();
         return false;
      }

      Enumeration var3 = var2.entries();

      while (var3.hasMoreElements()) {
         ZipEntry var4 = (ZipEntry)var3.nextElement();
         String var5 = var4.getName();
         String var6 = URL.homeUnalias("avatars/" + var5);
         String[] var7 = new String[]{".bod", ".seq", ".dat", ".cmp", ".mov"};
         boolean var8 = false;

         for (int var9 = 0; var9 < var7.length; var9++) {
            if (var6.toString().endsWith(var7[var9])) {
               var8 = true;
               break;
            }
         }

         if (var8) {
            if (var6.toString().endsWith("avatars.dat")) {
               var6 = URL.homeUnalias("avatars/avatars.tmp");
               this.CopyAvatarFile(var2, var4, var6);
               this.AppendAvatarsDat();
            } else {
               this.CopyAvatarFile(var2, var4, var6);
            }
         }
      }

      try {
         var2.close();
      } catch (IOException var10) {
      }

      this.notify();
      return false;
   }

   public Room getBackgroundLoadRoom() {
      return this.drone != null && this.drone.getOwner() != null ? this.drone.getOwner().getRoom() : null;
   }

   private void AppendAvatarsDat() {
      String var1 = URL.homeUnalias("avatars/content.zip");
      Archive.flushAll();

      ZipFile var2;
      try {
         var2 = new ZipFile(var1);
      } catch (IOException var12) {
         var2 = null;
      }

      if (var2 != null) {
         ZipEntry var3 = var2.getEntry("avatars.dat");
         if (var3 != null) {
            this.CopyAvatarFile(var2, var3, URL.homeUnalias("avatars/avatars.dat"));
            this.StripAvatarDat(var2);
         } else {
            try {
               var2.close();
            } catch (IOException var11) {
            }
         }
      }

      FileOutputStream var14;
      try {
         var14 = new FileOutputStream(URL.homeUnalias("avatars/avatars.dat"), true);
      } catch (IOException var10) {
         System.out.println(var10);
         return;
      }

      FileInputStream var4;
      try {
         var4 = new FileInputStream(URL.homeUnalias("avatars/avatars.tmp"));
      } catch (FileNotFoundException var9) {
         try {
            var14.close();
         } catch (IOException var7) {
         }

         return;
      }

      byte[] var5 = new byte[1024];

      while (true) {
         try {
            int var6 = var4.read(var5);
            if (var6 == -1) {
               break;
            }

            var14.write(var5, 0, var6);
         } catch (IOException var13) {
            break;
         }
      }

      try {
         var14.close();
         var4.close();
      } catch (IOException var8) {
      }

      File var15 = new File(URL.homeUnalias("avatars/avatars.tmp"));
      var15.delete();
      DroneAnimator.loadconfig(URL.make("home:avatars/avatars.dat").unalias());
   }

   private void StripAvatarDat(ZipFile var1) {
      FileOutputStream var2;
      try {
         var2 = new FileOutputStream(URL.homeUnalias("avatars/content.tmp"));
      } catch (IOException var13) {
         return;
      }

      ZipOutputStream var3 = new ZipOutputStream(var2);
      Enumeration var4 = var1.entries();

      while (var4.hasMoreElements()) {
         ZipEntry var5 = (ZipEntry)var4.nextElement();
         String var6 = var5.getName();
         if (!var6.equals("avatars.dat")) {
            try {
               InputStream var7 = var1.getInputStream(var5);
               ZipEntry var8 = new ZipEntry(var5.getName());
               var3.putNextEntry(var8);
               byte[] var9 = new byte[1024];

               while (true) {
                  try {
                     int var10 = var7.read(var9);
                     if (var10 != -1) {
                        var3.write(var9, 0, var10);
                        continue;
                     }
                  } catch (IOException var14) {
                     System.out.println("IOException " + var5.getName() + " " + var14.getMessage());
                  }

                  var3.closeEntry();
                  var7.close();
                  break;
               }
            } catch (IOException var15) {
               System.out.println("IOException 2 " + var15.getMessage());
            }
         }
      }

      try {
         var1.close();
         var3.close();
      } catch (IOException var12) {
         System.out.println("Error closing zip files " + var12);
      }

      File var16 = new File(URL.homeUnalias("avatars/content.zip"));
      File var17 = new File(URL.homeUnalias("avatars/content.tmp"));
      File var18 = new File(URL.homeUnalias("avatars/content.old"));
      Archive.flushAll();

      try {
         boolean var19 = var16.renameTo(var18);
         var19 = var17.renameTo(var16);
      } catch (Exception var11) {
         System.out.println(var11);
      }
   }

   private void CopyAvatarFile(ZipFile var1, ZipEntry var2, String var3) {
      InputStream var4;
      try {
         var4 = var1.getInputStream(var2);
      } catch (IOException var11) {
         return;
      }

      FileOutputStream var5;
      try {
         var5 = new FileOutputStream(var3);
      } catch (IOException var10) {
         try {
            var4.close();
         } catch (IOException var8) {
         }

         return;
      }

      byte[] var6 = new byte[1024];

      while (true) {
         try {
            int var7 = var4.read(var6);
            if (var7 == -1) {
               break;
            }

            var5.write(var6, 0, var7);
         } catch (IOException var12) {
            break;
         }
      }

      try {
         var4.close();
         var5.close();
      } catch (IOException var9) {
      }
   }

   static {
      doAvatarUpdates = IniFile.gamma().getIniInt("noAvUpdates", 0) == 0;
   }
}
