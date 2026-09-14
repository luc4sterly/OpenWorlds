package NET.worlds.scape;

public class KeyDownEvent extends KeyEvent {
   public KeyDownEvent(int var1, WObject var2, char var3) {
      super(var1, null, var2, var3);
   }

   public boolean deliver(Object var1) {
      return var1 instanceof KeyDownHandler && ((KeyDownHandler)var1).handle(this) ? true : super.deliver(var1);
   }
}
