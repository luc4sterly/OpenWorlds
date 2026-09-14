package NET.worlds.scape;

public class MouseEnterEvent extends MousePositionEvent {
   public MouseEnterEvent(int var1, WObject var2, int var3, int var4) {
      super(var1, var2, var3, var4);
   }

   public boolean deliver(Object var1) {
      return var1 instanceof MouseEnterHandler && ((MouseEnterHandler)var1).handle(this) ? true : super.deliver(var1);
   }
}
