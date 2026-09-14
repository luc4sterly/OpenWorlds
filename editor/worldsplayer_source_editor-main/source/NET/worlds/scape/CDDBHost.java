package NET.worlds.scape;

class CDDBHost {
   private String host;
   private int port;

   public CDDBHost(String var1, int var2) {
      this.host = var1;
      this.port = var2;
   }

   public String getHost() {
      return this.host;
   }

   public int getPort() {
      return this.port;
   }

   public String toString() {
      return this.host + ":" + this.port;
   }
}
