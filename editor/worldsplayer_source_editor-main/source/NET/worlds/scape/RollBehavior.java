package NET.worlds.scape;

import java.io.IOException;

public class RollBehavior extends VelocityBehavior {
   public float rollFactor;
   private long lastTime;
   private float bumpFraction;
   private static Object classCookie = new Object();

   public RollBehavior(Point3Temp var1, float var2) {
      super(var1, 0.0F, Point3Temp.make(0.0F, 0.0F, 1.0F), 0.0F, 0.0F);
      this.rollFactor = 360.0F / (3.1416F * var2);
   }

   public RollBehavior() {
   }

   public boolean handle(FrameEvent var1) {
      float var2 = this.linearVel;
      float var3 = (float)(var1.time - this.lastTime) / 1000.0F;
      this.bumpFraction = 1.0F;
      super.handle(var1);
      if (var2 != 0.0F && this.lastTime != 0L) {
         var1.receiver.worldSpin(-this.dir.y, this.dir.x, this.dir.z, this.dir.length() * var3 * var2 * this.rollFactor * this.bumpFraction);
      }

      this.lastTime = var1.time;
      return true;
   }

   public boolean handle(BumpEventTemp var1) {
      this.bumpFraction = var1.fraction;
      return super.handle(var1);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Roll Factor"));
            } else if (var3 == 1) {
               var5 = new Float(this.rollFactor);
            } else if (var3 == 2) {
               this.rollFactor = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.rollFactor);
      var1.saveFloat(this.bumpFraction);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.rollFactor = var1.restoreFloat();
            this.bumpFraction = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }
}
