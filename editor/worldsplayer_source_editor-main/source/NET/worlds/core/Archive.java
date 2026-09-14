package NET.worlds.core;

import NET.worlds.network.URL;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

public class Archive {
   public static final String archiveName = "content.zip";
   private static Object mutex = new Object();
   private static Object noArchive = new Object();
   private static java.util.Hashtable archives = new java.util.Hashtable();
   private static String homePrefix = URL.getHome().unalias();
   private ZipFile zip;

   public static boolean exists(String var0) {
      synchronized (mutex) {
         String var2 = var0.toLowerCase().replace('\\', '/');
         if (var2.startsWith("./")) {
            var2 = homePrefix + var2.substring(2);
         }

         if (var2.startsWith(homePrefix)) {
            var2 = var2.substring(homePrefix.length());
            Archive var3 = getOrMake("");
            if (var3 != null && var3.lookup(var2) != null) {
               return true;
            }

            int var5 = -1;

            int var6;
            while ((var6 = var2.indexOf(47, var5 + 1)) != -1) {
               String var7 = var2.substring(0, var6 + 1);
               var3 = getOrMake(var7);
               if (var3 != null) {
                  String var8 = var2.substring(var6 + 1);
                  if (var3.lookup(var8) != null) {
                     return true;
                  }
               }

               var5 = var6;
            }
         }

         File var13 = new File(var0);
         int var4 = (int)var13.length();
         return var4 != 0;
      }
   }

   private static void reallyRead(InputStream var0, byte[] var1) throws IOException {
      int var2 = var1.length;
      int var3 = 0;

      while (var2 > 0) {
         int var4 = var0.read(var1, var3, var2);
         var3 += var4;
         if (var4 == -1) {
            return;
         }

         var2 -= var4;
      }
   }

   public static byte[] readBinaryFile(String var0) {
      synchronized (mutex) {
         try {
            String var2 = var0.toLowerCase().replace('\\', '/');
            if (var2.startsWith("./")) {
               var2 = homePrefix + var2.substring(2);
            }

            if (var2.startsWith(homePrefix)) {
               var2 = var2.substring(homePrefix.length());
               Archive var3 = getOrMake("");
               ZipEntry var4;
               if (var3 != null && (var4 = var3.lookup(var2)) != null) {
                  return var3.load(var4);
               }

               int var5 = -1;

               int var6;
               while ((var6 = var2.indexOf(47, var5 + 1)) != -1) {
                  String var7 = var2.substring(0, var6 + 1);
                  var3 = getOrMake(var7);
                  if (var3 != null) {
                     String var8 = var2.substring(var6 + 1);
                     if ((var4 = var3.lookup(var8)) != null) {
                        return var3.load(var4);
                     }
                  }

                  var5 = var6;
               }
            }

            File var14 = new File(var0);
            int var16 = (int)var14.length();
            if (var16 != 0) {
               FileInputStream var17 = new FileInputStream(var14);
               byte[] var18 = new byte[var16];
               reallyRead(var17, var18);
               var17.close();
               return var18;
            }
         } catch (IOException var10) {
         }

         return null;
      }
   }

   public static byte[] readTextFile(String var0) {
      byte[] var1 = readBinaryFile(var0);
      if (var1 != null) {
         int var2 = 0;

         for (int var3 = 0; var3 < var1.length; var3++) {
            if (var1[var3] == 13 && var1[var3 + 1] == 10) {
               var3++;
               var2++;
            }
         }

         byte[] var6 = new byte[var1.length - var2];
         int var4 = 0;

         for (int var5 = 0; var5 < var1.length; var5++) {
            if (var1[var5] != 13 || var1[var5 + 1] != 10) {
               var6[var4++] = var1[var5];
            }
         }

         var1 = var6;
      }

      return var1;
   }

   public static void flushAll() {
      synchronized (mutex) {
         Enumeration var1 = archives.elements();

         while (var1.hasMoreElements()) {
            Object var2 = var1.nextElement();
            if (var2 instanceof Archive) {
               ((Archive)var2).close();
            }
         }

         archives.clear();
      }
   }

   private static Archive getOrMake(String var0) {
      String var1 = var0 + "content.zip";
      Object var2 = archives.get(var1);
      if (var2 == null) {
         try {
            Archive var3 = new Archive(var1);
            archives.put(var1, var3);
            return var3;
         } catch (IOException var4) {
            archives.put(var1, noArchive);
         }
      } else if (var2 != noArchive) {
         return (Archive)var2;
      }

      return null;
   }

   private Archive(String var1) throws IOException {
      this.zip = new ZipFile(homePrefix + var1);
   }

   private void close() {
      try {
         this.zip.close();
      } catch (IOException var2) {
      }
   }

   private ZipEntry lookup(String var1) {
      return this.zip.getEntry(var1);
   }

   private byte[] load(ZipEntry var1) throws IOException {
      return load(this.zip, var1);
   }

   static byte[] load(ZipFile var0, ZipEntry var1) throws IOException {
      int var2 = (int)var1.getSize();
      byte[] var3 = new byte[var2];
      InputStream var4 = var0.getInputStream(var1);
      if (var1.getMethod() == 0) {
         reallyRead(var4, var3);
      } else {
         BufferedInputStream var5 = new BufferedInputStream(var4, 4096);
         int var6 = 0;

         while (var6 < var2) {
            var6 += var5.read(var3, var6, var2 - var6);
         }

         var5.close();
      }

      return var3;
   }

   static Object getMutex() {
      return mutex;
   }
}
