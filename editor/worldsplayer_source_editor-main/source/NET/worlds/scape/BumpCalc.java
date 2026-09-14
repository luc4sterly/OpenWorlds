package NET.worlds.scape;

public abstract class BumpCalc extends SuperRoot {
   public abstract void detectBump(BumpEventTemp var1, WObject var2);

   public String toString() {
      return this.getName();
   }
}
