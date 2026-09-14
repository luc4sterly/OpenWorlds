package NET.worlds.scape;

public class Event implements Cloneable {
   public static final Class eventSuperclass = new Object().getClass();
   public int time;
   public Object source;
   public WObject target;
   public WObject receiver;

   public Event(int var1, Object var2, WObject var3) {
      this.time = var1;
      this.source = var2;
      this.target = var3;
   }

   public Object clone() {
      try {
         return super.clone();
      } catch (CloneNotSupportedException var2) {
         System.out.println("Clone of Object not supported!");
         return null;
      }
   }

   public boolean isA(Class var1) {
      for (Class var2 = this.getClass(); var2 != eventSuperclass; var2 = var2.getSuperclass()) {
         if (var2 == var1) {
            return true;
         }
      }

      return false;
   }

   public boolean deliver(Object var1) {
      return var1 instanceof Handler && ((Handler)var1).handle(this);
   }

   public String toString() {
      String var1 = "Event at " + this.time;
      String var2 = null;
      if (this.source instanceof SuperRoot) {
         var2 = ((SuperRoot)this.source).getName();
      } else if (this.source != null) {
         var2 = this.source.toString();
      }

      if (var2 != null) {
         var1 = var1 + " from " + var2;
      }

      Object var3 = null;
      if (this.target != null) {
         this.target.getName();
      }

      if (var3 != null) {
         var1 = var1 + " to " + var3;
      }

      Object var4 = null;
      if (this.receiver != null) {
         this.receiver.getName();
      }

      if (var4 != null) {
         var1 = var1 + " handled by " + var4;
      }

      return var1;
   }
}
