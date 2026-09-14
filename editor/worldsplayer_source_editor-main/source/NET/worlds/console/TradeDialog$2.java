package NET.worlds.console;

class TradeDialog$2 implements MainCallback {
   TradeDialog this$0;

   TradeDialog$2(TradeDialog var1) {
      this.this$0 = var1;
   }

   public void mainCallback() {
      this.this$0.build();
      this.this$0.pack();
      Main.unregister(this);
   }
}
