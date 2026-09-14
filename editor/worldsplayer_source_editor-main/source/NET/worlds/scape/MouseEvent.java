package NET.worlds.scape;

public class MouseEvent extends UserEvent {
   public int x;
   public int y;

   public MouseEvent(int var1, WObject var2, int var3, int var4) {
      super(var1, null, var2);
      this.x = var3;
      this.y = var4;
   }

   public boolean deliver(Object var1) {
      return var1 instanceof MouseHandler && ((MouseHandler)var1).handle(this) ? true : super.deliver(var1);
   }
}
