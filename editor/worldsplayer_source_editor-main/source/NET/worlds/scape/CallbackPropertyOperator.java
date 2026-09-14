package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Debug;

public class CallbackPropertyOperator implements MainCallback {
   private Property prop;
   private int func;
   private Object value;
   private boolean done;

   CallbackPropertyOperator(Property var1, int var2, Object var3) {
      this.prop = var1;
      this.func = var2;
      this.value = var3;
      Debug.dAssert(!Main.isMainThread());
      Main.register(this);
   }

   synchronized Object getValue() {
      while (!this.done) {
         try {
            this.wait();
         } catch (InterruptedException var2) {
         }
      }

      return this.value;
   }

   public synchronized void mainCallback() {
      this.modify();
      Main.unregister(this);
      this.notify();
   }

   private void modify() {
      this.value = this.prop.safeOperate(this.func, this.value);
      this.done = true;
   }
}
