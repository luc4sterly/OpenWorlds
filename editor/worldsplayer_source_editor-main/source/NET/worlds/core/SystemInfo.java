package NET.worlds.core;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;
import java.io.PrintStream;

public class SystemInfo implements MainCallback, MainTerminalCallback {
   private static SystemInfo instance = new SystemInfo();
   private long _lastFrame = 0L;
   private long _lastReport = 0L;
   private long _min;
   private long _max;
   private long _avg;
   private long _avgCount = 0L;

   private SystemInfo() {
      Main.register(this);
   }

   public void mainCallback() {
      long var1 = Std.getFastTime();
      long var3 = var1 - this._lastFrame;
      if (var3 < this._min) {
         this._min = var3;
      }

      if (var3 > this._max) {
         this._max = var3;
      }

      this._avg += var3;
      this._avgCount++;
      if (var1 - this._lastReport > 300000L) {
         if (this._lastFrame != 0L) {
            System.out.println(logTime() + "Frame rate report:" + this._min + "/" + this._avg / this._avgCount + "/" + this._max);
         }

         this._min = 10000L;
         this._max = 0L;
         this._avg = 0L;
         this._avgCount = 0L;
         this._lastReport = var1;
      }

      this._lastFrame = var1;
   }

   public void terminalCallback() {
      Main.unregister(this);
      if (this._avgCount != 0L) {
         System.out.println(logTime() + "Frame rate report:" + this._min + "/" + this._avg / this._avgCount + "/" + this._max);
      }
   }

   public static void Record(PrintStream var0) {
      var0.println("DISK REPORT:");
      recordPath(var0, "Windows SYSTEM path", GetSystemDirectory());
      recordPath(var0, "Current Working Directory", GetCurrentDirectory());
      var0.println("");
      var0.println("JAVA MEMORY:");
      var0.println(logTime() + "\t Free memory: " + Runtime.getRuntime().freeMemory());
      var0.println(logTime() + "\tTotal memory: " + Runtime.getRuntime().totalMemory());
      var0.println("");
      var0.println("WINDOWS MEMORY:");
      var0.println(logTime() + "\tTotal Physical Memory: " + GetTotalPhysicalMemory());
      var0.println(logTime() + "\tAvail Physical Memory: " + GetAvailPhysicalMemory());
      var0.println(logTime() + "\t   Total Paged Memory: " + GetTotalPagedMemory());
      var0.println(logTime() + "\t   Avail Paged Memory: " + GetAvailPagedMemory());
      var0.println("");
      var0.println(logTime() + "Java Properties: " + System.getProperties());
      var0.println(logTime() + "Number of CPUs: " + GetNumberOfProcessors());
      var0.println(logTime() + "Processor Type: " + GetProcessorType());
      var0.println(logTime() + "Platform  Type: " + GetPlatformID());
   }

   private static void recordPath(PrintStream var0, String var1, String var2) {
      var0.println(logTime() + var1 + ": " + var2);
      if (var2 != null) {
         String var3 = var2.substring(0, 2);
         var0.println(logTime() + "\tFree disk space (" + var3 + "): " + GetDiskFreeSpace(var3 + "\\") + " KB");
      }
   }

   public static String logTime() {
      return "[" + Std.getRealTime() + "] ";
   }

   public static native int GetDiskFreeSpace(String var0);

   public static int GetDiskFreeSpace() {
      return GetDiskFreeSpace(null);
   }

   public static native String GetSystemDirectory();

   public static native String GetCurrentDirectory();

   public static native int GetTotalPhysicalMemory();

   public static native int GetAvailPhysicalMemory();

   public static native int GetTotalPagedMemory();

   public static native int GetAvailPagedMemory();

   public static native String GetPlatformID();

   public static native int GetNumberOfProcessors();

   public static native String GetProcessorType();
}
