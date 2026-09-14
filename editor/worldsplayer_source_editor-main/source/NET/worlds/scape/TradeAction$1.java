package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;

class TradeAction$1 implements MainCallback {
   TradeAction this$0;
   String val$dealStr;

   TradeAction$1(TradeAction var1, String var2) {
      this.this$0 = var1;
      this.val$dealStr = var2;
   }

   public void mainCallback() {
      Pilot.sendText("TRADE", this.val$dealStr);
      Main.unregister(this);
   }
}
