package NET.worlds.network;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URLConnection;
import java.util.Hashtable;

public class DirTimeStamp {
   private static Hashtable _tsEntries = new Hashtable();
   private URL _name;
   private long _mtime;
   private boolean _loaded = false;

   private DirTimeStamp(URL var1) {
      this._name = var1;
      Debug.assert_(var1.isRemote());
   }

   private static synchronized DirTimeStamp lookup(URL var0) {
      DirTimeStamp var1 = (DirTimeStamp)_tsEntries.get(var0);
      if (var1 == null) {
         var1 = new DirTimeStamp(var0);
         _tsEntries.put(var0, var1);
      }

      return var1;
   }

   private void getMTime() {
      this._mtime = 0L;

      try {
         int var1 = (int)(Math.random() * 1000000.0);
         int var2 = IniFile.gamma().getIniInt("NetCacheRetries", 1);
         boolean var3 = CacheEntry.getOffline();
         boolean var4 = var3;
         if (var3) {
            this._loaded = true;
            return;
         }

         if (var4) {
            var2 = 1;
         }

         java.net.URL var5 = DNSLookup.lookup(new java.net.URL(this._name.unalias() + "?" + var1));

         while (true) {
            try {
               URLConnection var6 = var5.openConnection();
               this._mtime = var6.getLastModified();
               break;
            } catch (IOException var7) {
               if (--var2 <= 0 || var7 instanceof FileNotFoundException) {
                  throw var7;
               }

               System.out.println("Exception " + var7 + " querying " + this._name + ", retrying...");
            }
         }

         this._loaded = true;
      } catch (FileNotFoundException var8) {
         System.out.println("Warning: timestamp " + this._name + " not found.");
         this._loaded = true;
      } catch (Exception var9) {
         System.out.println("Timestamp query error: " + var9 + " accessing " + this._name);
         this._loaded = true;
      }
   }

   public static long request(URL var0) {
      URL var1 = URL.make(var0, "timestamp.dir");
      String var2 = var0.getInternal();
      int var3 = var2.lastIndexOf(47);
      if (var3 > 0) {
         int var4 = var2.lastIndexOf(47, var3 - 1) + 1;
         if (var4 > 11) {
            String var5 = var2.substring(var4, var3);
            if (var0.endsWith("upgrades.lst")) {
               if (!var5.equals("gdkup") && !var5.equals("newup") && !var5.equals("3DCDup")) {
                  var1 = URL.make(var2.substring(0, var4) + "timestamp.upgrades");
               } else {
                  var1 = URL.make(var0, "timestamp.upgrades");
               }
            } else if (var5.equals("cgi-bin")) {
               return 0L;
            }
         }
      }

      DirTimeStamp var8 = lookup(var1);
      synchronized (var8) {
         if (!var8._loaded) {
            var8.getMTime();
         }
      }

      return var8._mtime;
   }
}
