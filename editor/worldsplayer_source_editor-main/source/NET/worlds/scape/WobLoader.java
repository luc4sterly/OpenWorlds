package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;

public class WobLoader implements BGLoaded {
   private WobLoaded loaded;
   private URL origURL;
   SuperRoot value;

   public WobLoader(URL var1, WobLoaded var2) {
      this(var1, var2, false);
   }

   public WobLoader(URL var1, WobLoaded var2, boolean var3) {
      this.origURL = var1;
      this.loaded = var2;
      if (var1.endsWith(".class")) {
         String var4 = var1.getAbsolute();
         if (var4.startsWith("system:")) {
            int var5 = var4.length();

            try {
               Class var6 = Class.forName(var4.substring(7, var5 - 6));
               SuperRoot var7 = (SuperRoot)var6.newInstance();
               var7.loadInit();
               this.gotIt(var7);
            } catch (Exception var8) {
               var8.printStackTrace(System.out);
               Console.println("Can't make instance of class " + var1);
               this.gotIt(null);
            }

            return;
         }
      }

      if (var3) {
         String var9 = var1.unalias();
         if (var9.indexOf(58) > 1) {
            this.gotIt(null);
         } else {
            this.syncBackgroundLoad(this.asyncBackgroundLoad(var9, var1), var1);
         }
      } else {
         BackgroundLoader.get(this, var1);
      }
   }

   public static SuperRoot immediateLoad(URL var0) {
      WobLoader var1 = new WobLoader(var0, null, true);
      return var1.value;
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      return var2.endsWith(".class") ? WobClassLoader.get(var1, var2.getClassName()) : var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      SuperRoot var3 = null;
      if (var1 != null) {
         if (var1 instanceof String) {
            var3 = SuperRoot.readFile((String)var1, var2);
         } else {
            try {
               var3 = (SuperRoot)((Class)var1).newInstance();
               var3.loadInit();
            } catch (Exception var5) {
               var5.printStackTrace(System.out);
            }
         }
      }

      this.gotIt(var3);
      return false;
   }

   private void gotIt(SuperRoot var1) {
      if (var1 != null) {
         var1.setSourceURL(this.origURL);
      }

      this.value = var1;
      if (this.loaded != null) {
         this.loaded.wobLoaded(this, var1);
      }
   }

   public Room getBackgroundLoadRoom() {
      if (this.loaded instanceof SuperRoot) {
         for (SuperRoot var1 = (SuperRoot)this.loaded; var1 != null; var1 = var1.getOwner()) {
            if (var1 instanceof WObject) {
               return ((WObject)var1).getRoom();
            }
         }
      }

      return null;
   }

   public URL getWobName() {
      return this.origURL;
   }
}
