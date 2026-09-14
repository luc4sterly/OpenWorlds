package NET.worlds.scape;

public class MouseButtonEvent extends MouseEvent {
   public char key;

   public MouseButtonEvent(int var1, WObject var2, char var3, int var4, int var5) {
      super(var1, var2, var4, var5);
      this.key = var3;
   }

   public boolean deliver(Object var1) {
      return var1 instanceof MouseButtonHandler && ((MouseButtonHandler)var1).handle(this) ? true : super.deliver(var1);
   }
}
