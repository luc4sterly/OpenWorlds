package NET.worlds.scape;

public class ValueEvent extends Event {
   public Object whoChanged;

   public ValueEvent(int var1, Object var2, WObject var3, Object var4) {
      super(var1, var2, var3);
      this.whoChanged = var4;
   }

   public boolean deliver(Object var1) {
      return var1 instanceof ValueHandler && ((ValueHandler)var1).handle(this);
   }
}
