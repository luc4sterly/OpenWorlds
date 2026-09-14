package NET.worlds.scape;

public class MouseUpEvent extends MouseButtonEvent {
   public MouseUpEvent(int var1, WObject var2, char var3, int var4, int var5) {
      super(var1, var2, var3, var4, var5);
   }

   public boolean deliver(Object var1) {
      return var1 instanceof MouseUpHandler && ((MouseUpHandler)var1).handle(this) ? true : super.deliver(var1);
   }

   public String toString() {
      return "MouseUp" + super.toString();
   }
}
