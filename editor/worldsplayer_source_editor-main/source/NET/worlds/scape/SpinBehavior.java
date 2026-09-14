package NET.worlds.scape;

import java.io.IOException;

public class SpinBehavior extends SwitchableBehavior implements FrameHandler {
   protected float cycleTime;
   protected float ax;
   protected float ay;
   protected float az;
   private static Object classCookie = new Object();

   public SpinBehavior() {
      this(5.0F);
   }

   public SpinBehavior(float var1) {
      this(var1, 0.0F, 0.0F, 1.0F);
   }

   public SpinBehavior(Point3Temp var1) {
      this(5.0F, var1);
   }

   public SpinBehavior(float var1, float var2, float var3) {
      this(5.0F, var1, var2, var3);
   }

   public SpinBehavior(float var1, Point3Temp var2) {
      this(var1, var2.x, var2.y, var2.z);
   }

   public SpinBehavior(float var1, float var2, float var3, float var4) {
      this.cycleTime = var1;
      this.ax = var2;
      this.ay = var3;
      this.az = var4;
   }

   public float getCycleTime() {
      return this.cycleTime;
   }

   public void setCycleTime(float var1) {
      this.cycleTime = var1;
   }

   public Point3Temp getAxis() {
      return Point3Temp.make(this.ax, this.ay, this.az);
   }

   public void setAxis(Point3Temp var1) {
      this.ax = var1.x;
      this.ay = var1.y;
      this.az = var1.z;
   }

   public boolean handle(FrameEvent var1) {
      if (this.enabled && this.cycleTime > 0.0F) {
         var1.receiver.spin(this.ax, this.ay, this.az, 0.36F * var1.dt / this.cycleTime);
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Cycle Time"));
            } else if (var3 == 1) {
               var5 = new Float(this.cycleTime);
            } else if (var3 == 2) {
               this.cycleTime = (Float)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Axis"));
            } else if (var3 == 1) {
               var5 = new Point3(this.getAxis());
            } else if (var3 == 2) {
               this.setAxis((Point3)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "[axis " + this.getAxis() + ", cycleTime " + this.cycleTime + ", enabled " + this.enabled + "]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      var1.saveFloat(this.cycleTime);
      var1.saveFloat(this.ax);
      var1.saveFloat(this.ay);
      var1.saveFloat(this.az);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this.cycleTime = var1.restoreFloat();
            this.ax = var1.restoreFloat();
            this.ay = var1.restoreFloat();
            this.az = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }
}
