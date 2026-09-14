package NET.worlds.scape;

public class MouseDeltaEvent extends MouseEvent {
   public int dx;
   public int dy;

   public MouseDeltaEvent(int var1, WObject var2, int var3, int var4) {
      super(var1, var2, 0, 0);
      this.dx = var3;
      this.dy = var4;
   }

   public boolean deliver(Object var1) {
      return var1 instanceof MouseDeltaHandler && ((MouseDeltaHandler)var1).handle(this) ? true : super.deliver(var1);
   }
}
