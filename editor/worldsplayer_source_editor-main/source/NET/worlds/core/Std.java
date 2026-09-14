package NET.worlds.core;

import java.io.InputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Date;

public class Std {
   private static String productName;
   private static int lastTime;
   static boolean syncTimeInited = false;
   static int syncTimeBase;

   public static void assertFail(String var0, int var1) {
      String var2 = "Assertion failed: file " + var0 + ", line " + var1;
      dumpStackTrace();
      exit();
   }

   public static String replaceStr(String var0, String var1, String var2) {
      if (var1 != null && var2 != null) {
         int var3;
         while ((var3 = var0.indexOf(var1)) != -1) {
            String var4 = var0.substring(0, var3) + var2 + var0.substring(var3 + var1.length());
            var0 = var4;
         }

         return var0;
      } else {
         return var0;
      }
   }

   public static native void exit();

   public static void dumpStackTrace() {
      try {
         throw new Error("");
      } catch (Error var1) {
         var1.printStackTrace(System.out);
      }
   }

   public static String getProductName() {
      Debug.assert_(productName != null);
      return productName;
   }

   public static void initProductName() {
      Debug.assert_(productName == null);
      productName = IniFile.gamma().getIniString("PRODUCT_NAME", "Worlds.com - The 3D Entertainment Portal");
      productName = IniFile.override().getIniString("productName", productName);
   }

   private static native int nativeGetMillis();

   private static synchronized int getMillis() {
      return nativeGetMillis();
   }

   public static native int getTimeZero();

   public static native long getPerformanceFrequency();

   public static native long getPerformanceCount();

   public static boolean sleep(float var0) {
      try {
         Thread.sleep((long)(var0 * 1000.0F));
         return false;
      } catch (InterruptedException var2) {
         return true;
      }
   }

   public static int getFastTime() {
      if (lastTime == 0) {
         getRealTime();
      }

      return lastTime;
   }

   public static int getRealTime() {
      lastTime = getMillis();
      return lastTime;
   }

   public static int getSynchronizedTime() {
      initSyncTime();
      return getFastTime() / 1000 + syncTimeBase;
   }

   static void initSyncTime() {
      boolean var0 = IniFile.override().getIniInt("Offline", 0) == 1;
      boolean var1 = IniFile.gamma().getIniInt("StopOnHttpFault", 0) == 1;
      if (!var0 && !var1) {
         if (!syncTimeInited) {
            syncTimeInited = true;
            String var2 = IniFile.override().getIniString("timeServer", "time.worlds.net");

            try {
               InetAddress var3 = InetAddress.getByName(var2);
               Socket var4 = new Socket(var3, 37);
               InputStream var5 = var4.getInputStream();
               int var6 = var5.read();
               int var7 = var5.read();
               int var8 = var5.read();
               int var9 = var5.read();
               var5.close();
               long var10 = (var6 << 24) + (var7 << 16) + (var8 << 8) + var9;
               var10 -= -1141367296L;
               syncTimeBase = (int)var10 - getFastTime() / 1000;
               var4.close();
            } catch (Exception var12) {
               System.out.println("Error retrieving network time: " + var12);
            }
         }
      } else {
         syncTimeInited = true;
         syncTimeBase = 0;
      }
   }

   public static native boolean instanceOf(Object var0, Class var1);

   public static native String getenv(String var0);

   public static native int GetDiskFreeSpace(String var0);

   public static int GetDiskFreeSpace() {
      return GetDiskFreeSpace(null);
   }

   public static void printThreads() {
      ThreadGroup var0 = Thread.currentThread().getThreadGroup();
      Thread[] var1 = new Thread[100];
      int var2 = var0.enumerate(var1);
      var0.list();

      for (int var3 = 0; var3 < var2; var3++) {
         if (var1[var3].isDaemon()) {
            System.out.println("is daemon");
         } else {
            System.out.println("isn't daemon");
         }
      }
   }

   public static void printlnOut(String var0) {
      System.out.println(var0);
   }

   public static native boolean byteArraysEqual(byte[] var0, byte[] var1);

   public static native String getBuildInfo();

   public static native int getVersion();

   public static native String getClientVersion();

   private static native int getBuildYear();

   private static native int getBuildMonth();

   private static native int getBuildDay();

   public static long getBuildDate() {
      return Date.UTC(getBuildYear(), getBuildMonth(), getBuildDay(), 0, 0, 0);
   }

   public static native int checkNativeHeap();
}
