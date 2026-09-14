package NET.worlds.scape;

import java.io.IOException;

public class PostspinBehavior extends SpinBehavior implements FrameHandler {
   private float xCenter;
   private float yCenter;
   private float zCenter;
   private static Object classCookie = new Object();

   public PostspinBehavior(float var1, float var2, float var3, float var4) {
      this(var1, var2, var3, 0.0F, 0.0F, 1.0F, var4);
   }

   public PostspinBehavior(float var1, float var2, float var3, float var4, float var5, float var6) {
      this(var1, var2, var3, var4, var5, var6, 5.0F);
   }

   public PostspinBehavior(float var1, float var2, float var3, float var4, float var5, float var6, float var7) {
      super(var7, var4, var5, var6);
      this.xCenter = var1;
      this.yCenter = var2;
      this.zCenter = var3;
   }

   public PostspinBehavior() {
   }

   public float getXCenter() {
      return this.xCenter;
   }

   public float getYCenter() {
      return this.yCenter;
   }

   public float getZCenter() {
      return this.zCenter;
   }

   public Point3Temp getCenter() {
      return Point3Temp.make(this.xCenter, this.yCenter, this.zCenter);
   }

   public void setXCenter(float var1) {
      this.xCenter = var1;
   }

   public void setYCenter(float var1) {
      this.yCenter = var1;
   }

   public void setZCenter(float var1) {
      this.zCenter = var1;
   }

   public void setCenter(Point3Temp var1) {
      this.xCenter = var1.x;
      this.yCenter = var1.y;
      this.zCenter = var1.z;
   }

   public boolean handle(FrameEvent var1) {
      if (this.enabled && this.cycleTime > 0.0F) {
         var1.receiver.moveBy(-this.xCenter, -this.yCenter, -this.zCenter);
         var1.receiver.postspin(this.ax, this.ay, this.az, 0.36F * var1.dt / this.cycleTime);
         var1.receiver.moveBy(this.xCenter, this.yCenter, this.zCenter);
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Center"));
            } else if (var3 == 1) {
               var5 = new Point3(this.getCenter());
            } else if (var3 == 2) {
               this.setCenter((Point3)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString()
         + "[center "
         + this.getCenter()
         + ", axis "
         + this.getAxis()
         + ", cycleTime "
         + this.cycleTime
         + ", enabled "
         + this.enabled
         + "]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.xCenter);
      var1.saveFloat(this.yCenter);
      var1.saveFloat(this.zCenter);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.xCenter = var1.restoreFloat();
            this.yCenter = var1.restoreFloat();
            this.zCenter = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }
}
