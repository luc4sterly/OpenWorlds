package NET.worlds.scape;

import NET.worlds.core.Std;
import java.io.IOException;

public class RelativeMoveAction extends Action {
   int startTime;
   public int cycleTime = 1000;
   public int cycles = 1;
   public boolean loopInfinite = false;
   public Point3 extentPoint = new Point3();
   public Point3 extentScale = new Point3(1.0F, 1.0F, 1.0F);
   public Point3 extentSpin = new Point3(0.0F, 0.0F, -1.0F);
   public float extentRotation = 0.0F;
   public float accumulatedRotation;
   public Point3 accumulatedScale;
   public Point3 accumulatedPoint;
   protected Persister activeID;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 != null && var3 instanceof WObject) {
         WObject var4 = (WObject)var3;
         if (var2 == null) {
            if (this.activeID != null) {
               return this.activeID;
            }

            this.startTime = Std.getRealTime();
            this.activeID = new SuperRoot();
            var2 = this.activeID;
            this.accumulatedRotation = 0.0F;
            this.accumulatedPoint = new Point3(0.0F, 0.0F, 0.0F);
            this.accumulatedScale = new Point3(1.0F, 1.0F, 1.0F);
         }

         if (var2 != this.activeID) {
            return null;
         }

         int var5 = Std.getRealTime();
         int var6 = (var5 - this.startTime) / this.cycleTime;
         float var7 = 1.0F;
         if (var6 >= this.cycles && !this.loopInfinite) {
            this.activeID = null;
         } else {
            var7 = (float)((var5 - this.startTime) % this.cycleTime) / this.cycleTime;
         }

         float var8 = this.extentRotation * var7;
         var4.spin(this.extentSpin, var8 - this.accumulatedRotation);
         this.accumulatedRotation = var8;
         Point3 var9 = new Point3(
            (float)Math.pow(this.extentScale.x, var7), (float)Math.pow(this.extentScale.y, var7), (float)Math.pow(this.extentScale.z, var7)
         );
         var4.scale(Point3Temp.make(var9).dividedBy(this.accumulatedScale));
         this.accumulatedScale = var9;
         Point3 var10 = new Point3(Point3Temp.make(this.extentPoint).times(var7));
         var4.moveBy(Point3Temp.make(var10).minus(this.accumulatedPoint));
         this.accumulatedPoint = var10;
         return this.activeID;
      } else {
         return null;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Cycle Time (in seconds)"));
            } else if (var3 == 1) {
               var5 = new Float(this.cycleTime / 1000.0F);
            } else if (var3 == 2) {
               this.cycleTime = (int)(1000.0F * (Float)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Cycles"));
            } else if (var3 == 1) {
               var5 = new Integer(this.cycles);
            } else if (var3 == 2) {
               this.cycles = (Integer)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Loop Infinite"), "False", "True");
            } else if (var3 == 1) {
               var5 = new Boolean(this.loopInfinite);
            } else if (var3 == 2) {
               this.loopInfinite = (Boolean)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Translation Extent"));
            } else if (var3 == 1) {
               var5 = new Point3(this.extentPoint);
            } else if (var3 == 2) {
               this.extentPoint.copy((Point3)var4);
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Scale Extent"));
            } else if (var3 == 1) {
               var5 = new Point3(this.extentScale);
            } else if (var3 == 2) {
               this.extentScale.copy((Point3)var4);
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Spin Axis For Extent"));
            } else if (var3 == 1) {
               Point3 var6 = new Point3(this.extentSpin);
               var6.x = Math.round(var6.x * 10000.0F) / 10000.0F;
               var6.y = Math.round(var6.y * 10000.0F) / 10000.0F;
               var6.z = Math.round(var6.z * 10000.0F) / 10000.0F;
               var5 = var6;
            } else if (var3 == 2) {
               this.extentSpin.copy((Point3)var4);
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Extent Rotation Amount"));
            } else if (var3 == 1) {
               var5 = new Float(this.extentRotation);
            } else if (var3 == 2) {
               this.extentRotation = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 7, var3, var4);
      }

      return var5;
   }

   public String toString() {
      String var1 = super.toString() + "[cycleTime " + this.cycleTime / 1000.0F + ", cycles " + this.cycles + ", ";
      if (!this.loopInfinite) {
         var1 = var1 + " NOT";
      }

      return var1 + " Infinite]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(5, classCookie);
      super.saveState(var1);
      var1.saveBoolean(this.loopInfinite);
      var1.saveInt(this.cycleTime);
      var1.saveInt(this.cycles);
      var1.save(this.extentPoint);
      var1.save(this.extentScale);
      var1.save(this.extentSpin);
      var1.saveFloat(this.extentRotation);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 4:
            super.restoreState(var1);
            this.cycleTime = var1.restoreInt();
            this.cycles = var1.restoreInt();
            this.extentPoint = (Point3)var1.restore();
            this.extentScale = (Point3)var1.restore();
            this.extentSpin = (Point3)var1.restore();
            this.extentRotation = var1.restoreFloat();
            break;
         case 5:
            super.restoreState(var1);
            this.loopInfinite = var1.restoreBoolean();
            this.cycleTime = var1.restoreInt();
            this.cycles = var1.restoreInt();
            this.extentPoint = (Point3)var1.restore();
            this.extentScale = (Point3)var1.restore();
            this.extentSpin = (Point3)var1.restore();
            this.extentRotation = var1.restoreFloat();
            break;
         default:
            throw new TooNewException();
      }
   }
}
