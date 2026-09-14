package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.core.IniFile;
import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import java.io.RandomAccessFile;
import java.util.Vector;

public class WorldValidator {
   static Vector worldList = null;
   private static final boolean debug = true;

   public static boolean allow(String var0) {
      if (IniFile.gamma().getIniInt("FreeFreeFree", 1) == 1) {
         return true;
      }

      if (NetUpdate.isInternalVersion()) {
         return true;
      }

      Console var1 = Console.getActive();
      if (var1 != null && !var1.getGalaxy().getOnline()) {
         return true;
      }

      if (worldList == null) {
         try {
            initializeList();
         } catch (Exception var3) {
            return true;
         }
      }

      if (worldList == null) {
         return true;
      }

      var0 = normalize(var0);
      System.out.println("Validating " + var0);
      boolean var2 = worldList.contains(var0);
      System.out.println(var2);
      return var2;
   }

   public static void initializeList() throws Exception {
      String var0 = NetUpdate.getUpgradeServerURL() + "tables/worlds.txt";
      URL var1 = URL.make(var0);
      CacheFile var2 = Cache.getFile(var1, true);
      var2.waitUntilLoaded();
      if (!var2.error()) {
         boolean var3 = false;
         worldList = new Vector();
         RandomAccessFile var4 = new RandomAccessFile(var2.getLocalName(), "r");

         while (var4.getFilePointer() < var4.length()) {
            String var5 = var4.readLine();
            if (var5.indexOf(".world") != -1) {
               var5 = normalize(var5);
               var3 = true;
               System.out.println("Adding world " + var5);
               worldList.addElement(var5);
            }
         }

         var4.close();
         if (!var3) {
            throw new Exception();
         }
      } else {
         throw new Exception();
      }
   }

   private static String normalize(String var0) {
      String var1 = URL.make(var0).getAbsolute();
      if (var1.startsWith("home:/")) {
         var1 = "home:" + var1.substring(6);
      }

      return var1.toLowerCase().trim();
   }
}
