package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;

class Portal$1 implements MainCallback {
   Portal this$0;

   Portal$1(Portal var1) {
      this.this$0 = var1;
   }

   public void mainCallback() {
      this.this$0.detach();
      Main.unregister(this);
   }
}
