package NET.worlds.scape;

import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.util.Hashtable;

class WorldScriptLoader extends ClassLoader {
   Hashtable cache = new Hashtable();
   String lastWorldName;

   private byte[] loadClassData(String var1) {
      String var2 = "NET.worlds.scape.";
      if (var1.startsWith(var2)) {
         var1 = var1.substring(var2.length());
      }

      int var3 = var1.indexOf("WorldScript");
      if (var3 == -1) {
         var3 = 0;
      } else {
         var3 += new String("WorldScript").length();
      }

      int var4 = var1.indexOf(".class");
      String var5;
      if (var3 == 0 && this.lastWorldName != null) {
         var5 = this.lastWorldName;
         if (!var1.endsWith(".class")) {
            var1 = var1 + ".class";
         }
      } else if (var4 != -1) {
         var5 = var1.substring(var3, var4);
      } else {
         var5 = var1.substring(var3);
         var1 = var1 + ".class";
      }

      URL var6 = URL.make(NetUpdate.getUpgradeServerURL() + var5 + "/" + var1);
      CacheFile var7 = Cache.getFile(var6, true);
      var7.waitUntilLoaded();
      if (var7.error()) {
         return null;
      }

      this.lastWorldName = var5;
      String var8 = var7.getLocalName();

      try {
         File var9 = new File(var8);
         FileInputStream var10 = new FileInputStream(var9);
         byte[] var11 = new byte[1024];
         ByteArrayOutputStream var12 = new ByteArrayOutputStream();

         while (true) {
            try {
               int var13 = var10.read(var11);
               if (var13 == -1) {
                  break;
               }

               var12.write(var11, 0, var13);
            } catch (Exception var14) {
               break;
            }
         }

         return var12.toByteArray();
      } catch (Exception var15) {
         return null;
      }
   }

   public synchronized Class loadClass(String var1, boolean var2) {
      Class var3 = (Class)this.cache.get(var1);
      if (var3 == null) {
         byte[] var4 = null;
         if (!var1.startsWith("java.")) {
            var4 = this.loadClassData(var1);
         }

         if (var4 == null) {
            try {
               return this.findSystemClass(var1);
            } catch (Error var6) {
               System.out.println("Could not load script " + var1 + " " + var6);
               return null;
            } catch (Exception var7) {
               System.out.println("Could not load script " + var1 + " " + var7);
               return null;
            }
         }

         var3 = this.defineClass(var4, 0, var4.length);
         this.cache.put(var1, var3);
      }

      if (var2) {
         this.resolveClass(var3);
      }

      return var3;
   }
}
