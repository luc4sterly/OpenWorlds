package NET.worlds.scape;

public class Mirror extends Portal {
   public Mirror(float var1, float var2) {
      super(var1, var2);
      this.connectTo(this);
      this.flags |= 4;
   }

   public Mirror(float var1, float var2, float var3, float var4, float var5, float var6) {
      super(var1, var2, var3, var4, var5, var6);
      this.connectTo(this);
      this.flags |= 4;
   }

   public Mirror(Point3Temp var1, Point3Temp var2) {
      super(var1, var2);
      this.connectTo(this);
      this.flags |= 4;
   }

   public BumpCalc getBumpCalc(BumpEventTemp var1) {
      return this.bumpCalc == null ? Rect.standardPlaneBumpCalc : this.bumpCalc;
   }

   public Mirror() {
   }

   public boolean handle(BumpEventTemp var1) {
      return true;
   }
}
