package NET.worlds.scape;

import NET.worlds.core.Std;
import java.io.IOException;

public class GravityAction extends Action {
   public float cycleTime = 0.0F;
   int startTime;
   public int force = 300;
   public float xDest = 0.0F;
   public float yDest = 0.0F;
   public float zDest = 0.0F;
   static final float epsilon = 2.0F;
   int lastFrameTime;
   float initialDistance = 0.0F;
   Point3 initialPoint;
   protected boolean gravityEnd = true;
   private static Object classCookie = new Object();

   public void startGravity() {
      this.startTime = Std.getRealTime();
      this.gravityEnd = false;
      this.lastFrameTime = 0;
   }

   private float distance(float var1, float var2, float var3, float var4, float var5, float var6) {
      float var7 = var1 - var4;
      float var8 = var2 - var5;
      float var9 = var3 - var6;
      return (float)Math.sqrt(var7 * var7 + var8 * var8 + var9 * var9);
   }

   public void doGravity(Pilot var1, WObject var2) {
      int var10 = Std.getRealTime();
      float var3 = this.distance(var1.getX(), var1.getY(), var1.getZ(), var2.getX(), var2.getY(), var2.getZ());
      if (this.lastFrameTime == 0) {
         this.lastFrameTime = var10;
      }

      float var11 = this.distance(this.initialPoint.x, this.initialPoint.y, this.initialPoint.z, var1.getX(), var1.getY(), var1.getZ());
      this.initialDistance = this.distance(this.initialPoint.x, this.initialPoint.y, this.initialPoint.z, var2.getX(), var2.getY(), var2.getZ());
      if (var3 > 2.0F && var11 <= this.initialDistance) {
         float var4 = var2.getX() - var1.getX();
         if (var4 != 0.0) {
            float var7 = (var10 - this.lastFrameTime) * this.force * var4 / (var3 * var3);
            if (Math.abs(var7) < Math.abs(var4)) {
               var4 = var7;
            }
         }

         float var5 = var2.getY() - var1.getY();
         if (var5 != 0.0) {
            float var8 = (var10 - this.lastFrameTime) * this.force * var5 / (var3 * var3);
            if (Math.abs(var8) < Math.abs(var5)) {
               var5 = var8;
            }
         }

         float var6 = var2.getZ() - var1.getZ();
         if (var6 != 0.0) {
            float var9 = (var10 - this.lastFrameTime) * this.force * var6 / (var3 * var3);
            if (Math.abs(var9) < Math.abs(var6)) {
               var6 = var9;
            }
         }

         var1.moveBy(var4, var5, var6);
      } else {
         var1.moveTo(var2.getX(), var2.getY(), var2.getZ());
         this.gravityEnd = true;
      }

      this.lastFrameTime = var10;
   }

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 != null && var3 instanceof WObject) {
         WObject var4 = (WObject)var3;
         Pilot var5 = Pilot.getActive();
         if (var5 == null) {
            return null;
         }

         if (var5.getRoom() != var4.getRoom()) {
            if (this.gravityEnd && var5 instanceof HoloPilot) {
               HoloPilot var8 = (HoloPilot)var5;
               var8.returnSmoothDriver();
            }

            return null;
         } else {
            if (this.gravityEnd) {
               this.startGravity();
               if (var5 instanceof HoloPilot) {
                  HoloPilot var6 = (HoloPilot)var5;
                  var6.removeSmoothDriver();
                  this.initialPoint = new Point3(var5.getPosition());
                  this.initialDistance = this.distance(this.initialPoint.x, this.initialPoint.y, this.initialPoint.z, var4.getX(), var4.getY(), var4.getZ());
               }
            }

            this.doGravity(var5, var4);
            if (this.gravityEnd) {
               if (var5 instanceof HoloPilot) {
                  HoloPilot var7 = (HoloPilot)var5;
                  var7.returnSmoothDriver();
               }

               return null;
            } else {
               return this;
            }
         }
      } else {
         return null;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Force"));
            } else if (var3 == 1) {
               var5 = new Integer(this.force);
            } else if (var3 == 2) {
               this.force = (Integer)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "[Force " + this.force + "]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(4, classCookie);
      super.saveState(var1);
      var1.saveInt(this.force);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            var1.restore();
            this.cycleTime = var1.restoreFloat();
            this.force = var1.restoreInt();
            break;
         case 1:
            super.restoreState(var1);
            this.cycleTime = var1.restoreFloat();
            this.force = var1.restoreInt();
            break;
         case 2:
            super.restoreState(var1);
            this.cycleTime = var1.restoreFloat();
            this.force = var1.restoreInt();
            this.xDest = var1.restoreFloat();
            this.yDest = var1.restoreFloat();
            break;
         case 3:
            super.restoreState(var1);
            this.force = var1.restoreInt();
            this.xDest = var1.restoreFloat();
            this.yDest = var1.restoreFloat();
            this.zDest = var1.restoreFloat();
            break;
         case 4:
            super.restoreState(var1);
            this.force = var1.restoreInt();
            break;
         default:
            throw new TooNewException();
      }
   }
}
