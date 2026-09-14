package NET.worlds.console;

import NET.worlds.scape.Pilot;

class TradeDialog$1 implements MainCallback {
   String val$msg;

   TradeDialog$1(String var1) {
      this.val$msg = var1;
   }

   public void mainCallback() {
      Pilot.sendText("TRADE", this.val$msg);
      Main.unregister(this);
   }
}
