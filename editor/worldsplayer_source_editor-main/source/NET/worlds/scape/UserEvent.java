package NET.worlds.scape;

public class UserEvent extends Event {
   public UserEvent(int var1, Object var2, WObject var3) {
      super(var1, var2, var3);
   }

   public boolean deliver(Object var1) {
      return var1 instanceof UserHandler && ((UserHandler)var1).handle(this);
   }
}
