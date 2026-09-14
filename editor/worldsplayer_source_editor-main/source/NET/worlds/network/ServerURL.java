package NET.worlds.network;

import NET.worlds.core.Debug;

public class ServerURL {
   private String _serverType = null;
   private String _serverHost = null;
   private String _serverOptions = null;

   public String getHost() {
      return this._serverHost;
   }

   public String getType() {
      return this._serverType;
   }

   public ServerURL(String var1) throws InvalidServerURLException {
      String var2 = var1;
      int var3 = var1.indexOf("://");
      if (var3 >= 0) {
         String var4 = var1.substring(0, var3);
         Debug.dAssert(var4.equals("worldserver"));
         var1 = var1.substring(var3 + 3);
      }

      int var8 = var1.indexOf(47);
      if (var8 >= 0) {
         this._serverHost = var1.substring(0, var8);
         var1 = var1.substring(var8 + 1);
      } else {
         this._serverHost = var1;
         var1 = "AutoServer";
      }

      int var5 = var1.indexOf(47);
      if (var5 >= 0) {
         this._serverType = var1.substring(0, var5);
         var1 = var1.substring(var5 + 1);
      } else {
         this._serverType = var1;
         var1 = "";
      }

      this._serverOptions = var1;
      if (this._serverHost.length() == 0) {
         throw new InvalidServerURLException("Invalid server URL: " + var2);
      }

      if (this._serverType.length() == 0) {
         this._serverType = "AutoServer";
      }
   }

   public String toString() {
      return "worldserver://" + this._serverHost + "/" + this._serverType + "/" + this._serverOptions;
   }
}
