package NET.worlds.network;

import NET.worlds.console.Gamma;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;
import NET.worlds.core.Std;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

public class Cache implements MainCallback, MainTerminalCallback, Serializable {
   static final long serialVersionUID = 1L;
   private static String CACHE_DIR = Gamma.earlyURLUnalias("home:cachedir/").replace('/', '\\');
   private static final String CACHE_OPEN = "cache.open";
   private static File horked = new File(CACHE_DIR + "cache.open");
   static Cache cache = initLoad();
   private Hashtable table = new Hashtable();
   private CacheEntry terminator = new CacheEntry();
   transient int totalBytes;
   private int nextAvailable = 1;

   static Cache initLoad() {
      System.out.println("Initializing cache...");
      FileInputStream var1 = null;

      Cache var0;
      try {
         System.out.println("Verifying cache was closed properly...");
         if (horked.exists()) {
            throw new Exception("Cache was not properly closed last time.");
         }

         System.out.println("Marking cache as open...");
         FileOutputStream var2 = new FileOutputStream(horked);
         var2.close();
         System.out.println("Restoring cache...");
         var1 = new FileInputStream(CACHE_DIR + "cache.index");
         ObjectInputStream var11 = new ObjectInputStream(var1);
         int var4 = var11.readInt();
         if (var4 != 0) {
            throw new Exception("Wrong version of cache.index");
         }

         var0 = (Cache)var11.readObject();
         Hashtable var5 = new Hashtable();
         Enumeration var6 = var0.table.keys();

         while (var6.hasMoreElements()) {
            Object var7 = var6.nextElement();
            var5.put(var7, var0.table.get(var7));
         }

         var0.table = var5;
         var11.close();
         var1.close();
      } catch (Exception var8) {
         System.out.println(var8);
         System.out.println("Flushing cache index.");
         var0 = new Cache();
         File var3 = new File(CACHE_DIR + "cache.index");
         var3.mkdirs();
         var3.delete();
      }

      String[] var10 = new File(CACHE_DIR).list();
      Hashtable var12 = new Hashtable();
      if (var10 != null) {
         for (int var13 = 0; var13 < var10.length; var13++) {
            var12.put((CACHE_DIR + var10[var13]).toUpperCase(), "");
         }

         var12.remove((CACHE_DIR + "cache.index").toUpperCase());
         var12.remove((CACHE_DIR + "cache.open").toUpperCase());
      }

      var0.totalBytes = 0;
      CacheEntry var14 = var0.terminator.next;

      while (var14 != var0.terminator) {
         CacheEntry var17 = var14;
         var14 = var14.next;
         String var18 = var17.localName.toUpperCase();
         boolean var19 = var12.get(var18) != null;
         var12.remove(var18);
         var0.totalBytes = var0.totalBytes + var17.bytes;
         if (!var17.done() || !var19) {
            var0.remove(var17);
            if (var19) {
               new File(var18).delete();
            }
         }
      }

      Enumeration var15 = var12.keys();

      while (var15.hasMoreElements()) {
         new File((String)var15.nextElement()).delete();
      }

      File var16 = new File("./avatars.zip");
      if (var16.exists()) {
         cache = var0;
         InjectZipFile(var16, "avatar:");
      }

      Main.register(var0);
      return var0;
   }

   public static CacheFile getFile(URL var0, boolean var1) {
      return cache.getAFile(var0, var1);
   }

   public static CacheFile getFile(URL var0) {
      return cache.getAFile(var0, false);
   }

   public static void InjectZipFile(File var0, String var1) {
      long var2 = var0.lastModified();

      try {
         ZipFile var4 = new ZipFile(var0);
         Enumeration var5 = var4.entries();

         while (var5.hasMoreElements()) {
            ZipEntry var6 = (ZipEntry)var5.nextElement();
            InputStream var7 = var4.getInputStream(var6);
            URL var8 = URL.make(var1 + var6.getName());
            String var9 = assignLocalName(var8);
            FileOutputStream var10 = new FileOutputStream(var9);
            byte[] var11 = new byte[1024];

            while (true) {
               try {
                  int var12 = var7.read(var11);
                  if (var12 == -1) {
                     break;
                  }

                  var10.write(var11, 0, var12);
               } catch (IOException var13) {
                  break;
               }
            }

            var7.close();
            var10.close();
            CacheEntry var15 = new CacheEntry();
            var15.localName = new String(var9);
            var15.url = var8;
            var15.state = 4;
            var15.remoteTime = var2;
            cache.add(var15);
         }

         var4.close();
         if (!var0.delete()) {
            System.out.println("Failed to delete zipfile");
         }
      } catch (Exception var14) {
         System.out.println("Error processing cache zip file: " + var14);
      }
   }

   private synchronized CacheFile getAFile(URL var1, boolean var2) {
      CacheEntry var3 = null;
      if (var1.isRemote()) {
         var3 = cache.get(var1);
         if (var3 == null) {
            var3 = new CacheEntry(var1);
            cache.add(var3);
         } else if (var2) {
            var3.forceRecheck();
         }
      }

      return new CacheFile(var1, var3);
   }

   private Cache() {
   }

   public void mainCallback() {
   }

   public void terminalCallback() {
      Main.unregister(this);

      try {
         FileOutputStream var1 = new FileOutputStream(CACHE_DIR + "cache.index");
         ObjectOutputStream var2 = new ObjectOutputStream(var1);
         var2.writeInt(0);
         var2.writeObject(this);
         var2.flush();
         var1.close();
      } catch (Exception var3) {
         System.out.println("Error writing cache index: " + var3);
      }

      System.out.println("Marking cache as closed...");
      horked.delete();
   }

   static String assignLocalName(URL var0) {
      String var1 = var0.unalias();
      String var2 = ".temp";
      int var3 = var1.lastIndexOf(46);
      if (var3 > var1.lastIndexOf(47) && var1.indexOf("?", var3) < 0 && var1.indexOf("#", var3) < 0) {
         var2 = var1.substring(var3);
      }

      return CACHE_DIR + Integer.toString(cache.nextAvailable++, 36) + var2;
   }

   public synchronized void add(CacheEntry var1) {
      this.table.put(var1.url, var1);
      CacheEntry var2 = this.terminator.prev;
      var2.next = var1;
      var1.prev = var2;
      var1.next = this.terminator;
      this.terminator.prev = var1;
   }

   public int numEntries() {
      return this.table.size();
   }

   public synchronized CacheEntry get(URL var1) {
      return (CacheEntry)this.table.get(var1);
   }

   void remove(CacheEntry var1) {
      this.totalBytes = this.totalBytes - var1.bytes;
      var1.prev.next = var1.next;
      var1.next.prev = var1.prev;
      var1.prev = null;
      var1.next = null;
      this.table.remove(var1.url);
      new File(var1.localName.toUpperCase()).delete();
   }

   private CacheEntry freeLRU() {
      for (CacheEntry var1 = this.terminator.next; var1 != this.terminator; var1 = var1.next) {
         if (!var1.inUse()) {
            this.remove(var1);
            return var1;
         }
      }

      return null;
   }

   public synchronized void makeSpaceFor(int var1) {
      while (cache.numEntries() > CacheEntry.CACHE_MAX_ENTRIES) {
         this.freeLRU();

         while ((this.totalBytes + 2 * var1) / 1024 > Std.GetDiskFreeSpace() && Std.GetDiskFreeSpace() != -1) {
            CacheEntry var2 = this.freeLRU();
            if (var2 == null) {
               break;
            }
         }
      }
   }
}
