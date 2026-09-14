package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import java.util.Vector;

public class Main {
   public static int profile = IniFile.gamma().getIniInt("Profile", 0);
   private static Thread mainThread;
   private static boolean stopFlag = false;
   private static Vector v = new Vector();
   private static int lastAt = -1;

   private Main() {
   }

   public static void mainLoop() {
      for (mainThread = Thread.currentThread(); !stopFlag; Thread.yield()) {
         MainCallback var0 = getNextCallback();
         if (var0 != null) {
            if (profile != 0) {
               int var1 = Std.getRealTime();
               long var2 = Runtime.getRuntime().freeMemory();
               var0.mainCallback();
               int var4 = Std.getRealTime() - var1;
               long var5 = var2 - Runtime.getRuntime().freeMemory();
               if (var4 > profile && !(var0 instanceof Console)) {
                  System.out.println("Took " + var4 + "ms and " + var5 + " bytes to call mainCallback " + var0);
               }
            } else {
               var0.mainCallback();
            }
         }
      }

      MainCallback var7;
      while ((var7 = getNextCallback()) != null) {
         if (var7 instanceof MainTerminalCallback) {
            ((MainTerminalCallback)var7).terminalCallback();
            Thread.yield();
         } else {
            unregister(var7);
         }
      }

      mainThread = null;
   }

   public static void end() {
      stopFlag = true;
   }

   public static boolean isMainThread() {
      return Thread.currentThread() == mainThread;
   }

   public static int queueLength() {
      return v.size();
   }

   private static MainCallback getNextCallback() {
      synchronized (v) {
         int var2 = v.size();
         MainCallback var0;
         if (var2 == 0) {
            lastAt = -1;
            var0 = null;
         } else {
            if (++lastAt >= var2) {
               lastAt = 0;
            }

            var0 = (MainCallback)v.elementAt(lastAt);
         }

         return var0;
      }
   }

   public static void register(MainCallback var0) {
      v.addElement(var0);
   }

   public static void unregister(MainCallback var0) {
      synchronized (v) {
         int var2 = v.indexOf(var0);
         v.removeElementAt(var2);
         if (lastAt >= var2) {
            lastAt--;
         }
      }
   }
}
