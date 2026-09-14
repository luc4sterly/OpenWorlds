package NET.worlds.scape;

public class KeyEvent extends UserEvent {
   char key;

   public KeyEvent(int var1, Object var2, WObject var3, char var4) {
      super(var1, var2, var3);
      this.key = var4;
   }

   public boolean deliver(Object var1) {
      return var1 instanceof KeyHandler && ((KeyHandler)var1).handle(this) ? true : super.deliver(var1);
   }

   public char getKey() {
      return this.key;
   }
}
