package NET.worlds.scape;

public class PickEvent extends UserEvent {
   public float x;
   public float y;
   public float z;

   public PickEvent(int var1, WObject var2, float var3, float var4, float var5) {
      super(var1, null, var2);
      this.x = var3;
      this.y = var4;
      this.z = var5;
   }

   public boolean deliver(Object var1) {
      return var1 instanceof PickHandler && ((PickHandler)var1).handle(this) ? true : super.deliver(var1);
   }
}
