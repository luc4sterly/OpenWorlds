package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;

class Sound$1 implements MainCallback {
   Sound this$0;

   Sound$1(Sound var1) {
      this.this$0 = var1;
   }

   public void mainCallback() {
      this.this$0.openInMainThread();
      Main.unregister(this);
   }
}
