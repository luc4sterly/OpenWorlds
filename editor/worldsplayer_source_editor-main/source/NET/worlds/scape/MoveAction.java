package NET.worlds.scape;

import NET.worlds.core.Std;
import java.io.IOException;
import java.util.Enumeration;

public class MoveAction extends Action {
   int startTime;
   boolean killOthers = true;
   boolean killed = false;
   public int cycleTime = 1000;
   public int cycles = 1;
   public boolean loopInfinite = false;
   public Point3 startPoint = new Point3();
   public Point3 startScale = new Point3(1.0F, 1.0F, 1.0F);
   public Point3 startSpin = new Point3(0.0F, 0.0F, -1.0F);
   public float startRotation;
   public Point3 extentPoint = new Point3();
   public Point3 extentScale = new Point3(1.0F, 1.0F, 1.0F);
   public Point3 extentSpin = new Point3(0.0F, 0.0F, -1.0F);
   public float extentRotation;
   protected Persister activeID;
   private static Object classCookie = new Object();

   public void noteAddingTo(SuperRoot var1) {
      if (this.startPoint.x == 0.0F
         && this.startPoint.y == 0.0F
         && this.startPoint.z == 0.0F
         && this.startScale.x == 1.0F
         && this.startScale.y == 1.0F
         && this.startScale.z == 1.0F
         && this.startSpin.x == 0.0F
         && this.startSpin.y == 0.0F
         && this.startSpin.z == -1.0F
         && this.startRotation == 0.0F) {
         this.updateStored(true);
      }
   }

   public void updateStored(boolean var1) {
      SuperRoot var2 = this.getOwner();
      if (var2 != null && var2 instanceof WObject) {
         WObject var3 = (WObject)var2;
         if (!var1) {
            this.extentPoint.copy(var3.getPosition());
            this.extentScale.copy(var3.getScale());
            Point3Temp var4 = Point3Temp.make();
            this.endToExtent(var3.getSpin(var4), var4);
         } else {
            this.startPoint.copy(var3.getPosition());
            this.startScale.copy(var3.getScale());
            this.startRotation = var3.getSpin(this.startSpin);
         }
      }
   }

   public void endToExtent(float var1, Point3Temp var2) {
      this.extentPoint.minus(this.startPoint);
      this.extentScale.dividedBy(this.startScale);
      Transform var3 = Transform.make();
      var3.spin(var2, var1);
      var3.spin(this.startSpin, -this.startRotation);
      var1 = var3.getSpin(var2);
      var3.recycle();
      if (this.equivalentSpinAxises(var2, this.extentSpin)) {
         int var4 = Math.round((this.extentRotation - var1) / 360.0F);
         this.extentRotation = var1 + var4 * 360;
      } else if (this.equivalentSpinAxises(var2, this.extentSpin.negate())) {
         this.extentSpin.negate();
         var1 = -var1;
         int var7 = Math.round((this.extentRotation - var1) / 360.0F);
         this.extentRotation = var1 + var7 * 360;
      } else {
         this.extentSpin.copy(var2);
         this.extentRotation = var1;
      }
   }

   private boolean equivalentSpinAxises(Point3Temp var1, Point3Temp var2) {
      return Math.abs(var1.x - var2.x) + Math.abs(var1.y - var2.y) + Math.abs(var1.z - var2.z) < 0.001F;
   }

   public void updateOwner(boolean var1) {
      SuperRoot var2 = this.getOwner();
      if (var2 != null && var2 instanceof WObject) {
         WObject var3 = (WObject)var2;
         var3.makeIdentity();
         if (!var1) {
            var3.spin(this.extentSpin, this.extentRotation);
            var3.moveBy(this.extentPoint);
            var3.scale(this.extentScale);
         }

         var3.scale(this.startScale);
         var3.spin(this.startSpin, this.startRotation);
         var3.moveBy(this.startPoint);
      }
   }

   public void kill() {
      this.killed = true;
   }

   public boolean isRunning() {
      return this.activeID != null;
   }

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (var3 != null && var3 instanceof WObject) {
         WObject var4 = (WObject)var3;
         if (this.killed) {
            this.killed = false;
            this.activeID = null;
            return null;
         }

         if (var2 == null) {
            if (this.activeID != null) {
               return this.activeID;
            }

            if (this.killOthers) {
               Enumeration var5 = var4.getActions();

               while (var5.hasMoreElements()) {
                  Action var6 = (Action)var5.nextElement();
                  if (var6 != this && var6 instanceof MoveAction) {
                     MoveAction var7 = (MoveAction)var6;
                     if (var7.isRunning()) {
                        var7.kill();
                     }
                  }
               }
            }

            this.startTime = Std.getRealTime();
            this.activeID = new SuperRoot();
            var2 = this.activeID;
         }

         if (var2 != this.activeID) {
            return null;
         }

         int var10 = Std.getRealTime();
         int var11 = (var10 - this.startTime) / this.cycleTime;
         float var12 = 1.0F;
         if (var11 >= this.cycles && !this.loopInfinite) {
            this.activeID = null;
         } else {
            var12 = (float)((var10 - this.startTime) % this.cycleTime) / this.cycleTime;
         }

         if (var4 instanceof Camera) {
         }

         if (var4 instanceof PosableDrone) {
            float var8 = -(this.startRotation + this.extentRotation * var12);
            Point3Temp var9 = Point3Temp.make(this.extentPoint).times(var12).plus(this.startPoint);
            var4.makeIdentity().moveTo(var9).yaw(var8);
         } else {
            var4.makeIdentity();
            var4.spin(this.extentSpin, this.extentRotation * var12);
            var4.spin(this.startSpin, this.startRotation);
            Point3Temp var13 = Point3Temp.make(
               (float)Math.pow(this.extentScale.x, var12), (float)Math.pow(this.extentScale.y, var12), (float)Math.pow(this.extentScale.z, var12)
            );
            var4.scale(var13.times(this.startScale));
            var4.moveTo(Point3Temp.make(this.extentPoint).times(var12).plus(this.startPoint));
         }

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
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Copy Start/End 1/2:Action->Owner  3/4:Owner->Action"));
            } else if (var3 == 1) {
               var5 = new Integer(0);
            } else if (var3 == 2) {
               switch ((Integer)var4) {
                  case 1:
                     this.updateOwner(true);
                     return var5;
                  case 2:
                     this.updateOwner(false);
                     return var5;
                  case 3:
                     this.updateStored(true);
                     return var5;
                  case 4:
                     this.updateStored(false);
               }
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
         case 7:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Start Point"));
            } else if (var3 == 1) {
               var5 = new Point3(this.startPoint);
            } else if (var3 == 2) {
               this.startPoint.copy((Point3)var4);
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Start Scale"));
            } else if (var3 == 1) {
               var5 = new Point3(this.startScale);
            } else if (var3 == 2) {
               this.startScale.copy((Point3)var4);
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Start Spin"));
            } else if (var3 == 1) {
               var5 = new Point3(this.startSpin);
            } else if (var3 == 2) {
               this.startSpin.copy((Point3)var4);
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Start Rotation"));
            } else if (var3 == 1) {
               var5 = new Float(this.startRotation);
            } else if (var3 == 2) {
               this.startRotation = (Float)var4;
            }
            break;
         case 11:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Kill Other Move Actions"), "Let other moves finish", "Kill other move actions");
            } else if (var3 == 1) {
               var5 = new Boolean(this.killOthers);
            } else if (var3 == 2) {
               this.killOthers = (Boolean)var4;
            }
            break;
         case 12:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Loop Infinite"), "False", "True");
            } else if (var3 == 1) {
               var5 = new Boolean(this.loopInfinite);
            } else if (var3 == 2) {
               this.loopInfinite = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 13, var3, var4);
      }

      return var5;
   }

   public String toString() {
      String var1 = super.toString() + "[cycleTime " + this.cycleTime / 1000.0F + ", cycles " + this.cycles + ",";
      if (!this.loopInfinite) {
         var1 = var1 + " not ";
      }

      return var1 + " Infinite ]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(6, classCookie);
      super.saveState(var1);
      var1.saveBoolean(this.loopInfinite);
      var1.saveInt(this.cycleTime);
      var1.saveInt(this.cycles);
      var1.save(this.extentPoint);
      var1.save(this.startPoint);
      var1.save(this.extentScale);
      var1.save(this.startScale);
      var1.save(this.extentSpin);
      var1.save(this.startSpin);
      var1.saveFloat(this.extentRotation);
      var1.saveFloat(this.startRotation);
      var1.saveBoolean(this.killOthers);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreStateMoveActionHelper(var1, classCookie);
   }

   public void restoreStateMoveActionHelper(Restorer var1, Object var2) throws IOException, TooNewException {
      switch (var1.restoreVersion(var2)) {
         case 1:
            super.restoreState(var1);
         case 0:
            var1.setOldFlag();
            this.cycleTime = (int)var1.restoreFloat();
            this.cycles = var1.restoreInt();
            this.loopInfinite = this.cycles == 0;
            this.extentPoint = (Point3)var1.restore();
            this.startPoint = (Point3)var1.restore();
            this.extentScale = (Point3)var1.restore();
            this.startScale = (Point3)var1.restore();
            this.extentSpin = (Point3)var1.restore();
            this.startSpin = (Point3)var1.restore();
            this.extentRotation = var1.restoreFloat();
            this.startRotation = var1.restoreFloat();
            this.extentPoint.minus(this.startPoint);
            this.extentScale.dividedBy(this.startScale);
            break;
         case 2:
            var1.setOldFlag();
            super.restoreState(var1);
            this.cycleTime = var1.restoreInt();
            this.cycles = var1.restoreInt();
            this.loopInfinite = this.cycles == 0;
            this.extentPoint = (Point3)var1.restore();
            this.startPoint = (Point3)var1.restore();
            this.extentScale = (Point3)var1.restore();
            this.startScale = (Point3)var1.restore();
            this.extentSpin = (Point3)var1.restore();
            this.startSpin = (Point3)var1.restore();
            this.extentRotation = var1.restoreFloat();
            this.startRotation = var1.restoreFloat();
            var1.restoreBoolean();
            break;
         case 3:
         case 4:
            var1.setOldFlag();
            super.restoreState(var1);
            this.cycleTime = var1.restoreInt();
            this.cycles = var1.restoreInt();
            this.loopInfinite = this.cycles == 0;
            this.extentPoint = (Point3)var1.restore();
            this.startPoint = (Point3)var1.restore();
            this.extentScale = (Point3)var1.restore();
            this.startScale = (Point3)var1.restore();
            this.extentSpin = (Point3)var1.restore();
            this.startSpin = (Point3)var1.restore();
            this.extentRotation = var1.restoreFloat();
            this.startRotation = var1.restoreFloat();
            break;
         case 5:
            super.restoreState(var1);
            this.cycleTime = var1.restoreInt();
            this.cycles = var1.restoreInt();
            this.loopInfinite = this.cycles == 0;
            this.extentPoint = (Point3)var1.restore();
            this.startPoint = (Point3)var1.restore();
            this.extentScale = (Point3)var1.restore();
            this.startScale = (Point3)var1.restore();
            this.extentSpin = (Point3)var1.restore();
            this.startSpin = (Point3)var1.restore();
            this.extentRotation = var1.restoreFloat();
            this.startRotation = var1.restoreFloat();
            this.killOthers = var1.restoreBoolean();
            break;
         case 6:
            super.restoreState(var1);
            this.loopInfinite = var1.restoreBoolean();
            this.cycleTime = var1.restoreInt();
            this.cycles = var1.restoreInt();
            this.extentPoint = (Point3)var1.restore();
            this.startPoint = (Point3)var1.restore();
            this.extentScale = (Point3)var1.restore();
            this.startScale = (Point3)var1.restore();
            this.extentSpin = (Point3)var1.restore();
            this.startSpin = (Point3)var1.restore();
            this.extentRotation = var1.restoreFloat();
            this.startRotation = var1.restoreFloat();
            this.killOthers = var1.restoreBoolean();
            break;
         default:
            throw new TooNewException();
      }
   }
}
