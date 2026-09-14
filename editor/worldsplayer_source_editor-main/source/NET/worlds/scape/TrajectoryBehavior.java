package NET.worlds.scape;

import java.io.IOException;

public class TrajectoryBehavior extends SwitchableBehavior implements FrameHandler, BumpHandler {
   protected Point3 dir;
   public float linearVel;
   public Point3 axis;
   public float angularVel;
   private RollingAttribute attr;
   public float linearDamp;
   public float bounceDamp;
   public float angularDamp;
   public float gravity;
   private long lastTime;
   private boolean bumplock = false;
   private static Object classCookie = new Object();

   public TrajectoryBehavior(Point3Temp var1, float var2, Point3Temp var3, float var4, float var5) {
      this.dir = new Point3();
      this.linearVel = 0.0F;
      this.linearDamp = var2;
      this.addVelocity(var1);
      this.axis = new Point3(var3);
      this.axis.normalize();
      this.angularVel = var4;
      this.angularDamp = var5;
   }

   public TrajectoryBehavior() {
      this(Point3Temp.make(0.0F, 0.0F, 0.0F));
   }

   public TrajectoryBehavior(Point3Temp var1) {
      this(var1, 0.0F, Point3Temp.make(0.0F, 0.0F, 1.0F), 0.0F, 0.0F);
   }

   public void setDir(Point3Temp var1) {
      double var2 = Math.sqrt(var1.x * var1.x + var1.y * var1.y + var1.z * var1.z);
      if (var2 == 0.0) {
         this.dir.x = 0.0F;
         this.dir.y = 0.0F;
         this.dir.z = 0.0F;
      } else {
         this.dir.x = (float)(var1.x / var2);
         this.dir.y = (float)(var1.y / var2);
         this.dir.z = (float)(var1.z / var2);
      }
   }

   public TrajectoryBehavior addVelocity(Point3Temp var1) {
      this.dir.times(this.linearVel).plus(var1);
      float var2 = this.dir.length();
      if (var2 > 0.0F) {
         this.dir.dividedBy(var2);
      }

      this.linearVel = var2;
      return this;
   }

   public void setNotifyAttribute(RollingAttribute var1) {
      this.attr = var1;
   }

   public boolean handle(FrameEvent var1) {
      this.bumplock = false;
      WObject var2 = var1.receiver;
      float var3 = (float)(var1.time - this.lastTime) / 1000.0F;
      if (this.lastTime == 0L) {
         this.lastTime = var1.time;
         return true;
      }

      this.lastTime = var1.time;
      Room var4 = var2.getRoom();
      if (var2.getZ() > var4.floorHeight(var2.getX(), var2.getY(), var2.getZ())) {
         this.addVelocity(Point3Temp.make(0.0F, 0.0F, -this.gravity * var3));
      } else if (this.dir.z < 0.0F) {
         this.dir.z = -this.dir.z;
         if (this.bounceDamp < 1.0) {
            this.linearVel = this.linearVel * this.bounceDamp;
            if (this.linearVel < 0.2 && this.linearVel > -0.2) {
               this.linearVel = 0.0F;
            }
         }
      }

      if (this.linearVel != 0.0F) {
         Point3Temp var5 = Point3Temp.make(this.dir).times(var3 * this.linearVel);
         var2.moveThrough(var5);
         if (this.linearDamp != 0.0F) {
            this.linearVel = (float)(this.linearVel * Math.exp(-this.linearDamp * var3));
            if (Math.abs(this.linearVel) < this.linearDamp * 16.0F) {
               this.linearVel = 0.0F;
               if (this.attr != null) {
                  this.attr.notifyStopped();
               }
            }
         }
      }

      if (this.angularVel != 0.0F) {
         var2.spin(this.axis.x, this.axis.y, this.axis.z, this.angularVel * var3);
         if (this.angularDamp != 0.0F) {
            this.angularVel = (float)(this.angularVel * Math.exp(-this.angularDamp * var3));
            if (Math.abs(this.angularVel) < this.angularDamp * 0.6F) {
               this.angularVel = 0.0F;
            }
         }
      }

      return true;
   }

   public boolean handle(BumpEventTemp var1) {
      if (this.bumplock) {
         return true;
      }

      if (this.attr != null) {
         this.attr.handle(var1);
      } else {
         this.processBumpEvent(var1);
      }

      this.bumplock = true;
      return true;
   }

   public void processBumpEvent(BumpEventTemp var1) {
      var1.postBumpPath.minus(var1.postBumpPath);
      if (this.dir.x != 0.0F || this.dir.y != 0.0F || this.dir.z != 0.0F) {
         WObject var3 = var1.receiver == var1.target ? (WObject)var1.source : var1.target;
         Point3Temp var2;
         if (!(var3 instanceof Camera) && !(var3 instanceof Hologram)) {
            var2 = Point3Temp.make(var1.bumpNormal);
         } else {
            float var4 = (float)((360.0F - var3.getYaw() + 90.0F) * Math.PI / 180.0);
            var2 = Point3Temp.make((float)Math.cos(var4), (float)Math.sin(var4), 0.0F);
         }

         float var8 = (float)Math.sqrt(var2.x * var2.x + var2.y * var2.y + var2.z * var2.z);
         var2.x /= var8;
         var2.y /= var8;
         var2.z /= var8;
         float var5 = Math.abs(this.dir.x * var2.x + this.dir.y * var2.y + this.dir.z * var2.z);
         this.dir.x = this.dir.x + var2.x * 2.0F * var5;
         this.dir.y = this.dir.y + var2.y * 2.0F * var5;
         this.dir.z = this.dir.z + var2.z * 2.0F * var5;
         double var6 = Math.sqrt(this.dir.x * this.dir.x + this.dir.y * this.dir.y + this.dir.z * this.dir.z);
         if (var6 != 0.0) {
            this.dir.x = (float)(this.dir.x / var6);
            this.dir.y = (float)(this.dir.y / var6);
            this.dir.z = (float)(this.dir.z / var6);
         }

         if (this.bounceDamp < 1.0) {
            this.linearVel = this.linearVel * this.bounceDamp;
            if (this.linearVel < 0.2 && this.linearVel > -0.2) {
               this.linearVel = 0.0F;
            }
         }
      }
   }

   public String toString() {
      return super.toString()
         + "["
         + this.getName()
         + ": lin. velocity "
         + this.linearVel
         + ", lin. damp "
         + this.linearDamp
         + ", direction "
         + this.dir
         + ", ang. vel "
         + this.angularVel
         + ", ang. damp "
         + this.angularDamp
         + ", axis "
         + this.axis
         + "]";
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Linear Velocity"));
            } else if (var3 == 1) {
               var5 = new Float(this.linearVel);
            } else if (var3 == 2) {
               this.linearVel = (Float)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Linear Damping"));
            } else if (var3 == 1) {
               var5 = new Float(this.linearDamp);
            } else if (var3 == 2) {
               this.linearDamp = (Float)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Direction"));
            } else if (var3 == 1) {
               var5 = new Point3(this.dir);
            } else if (var3 == 2) {
               this.dir = (Point3)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Angular Velocity"));
            } else if (var3 == 1) {
               var5 = new Float(this.angularVel);
            } else if (var3 == 2) {
               this.angularVel = (Float)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Angular Damping"));
            } else if (var3 == 1) {
               var5 = new Float(this.angularDamp);
            } else if (var3 == 2) {
               this.angularDamp = (Float)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Axis"));
            } else if (var3 == 1) {
               var5 = new Point3(this.axis);
            } else if (var3 == 2) {
               this.axis = (Point3)var4;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Gravitational Acceleration"));
            } else if (var3 == 1) {
               var5 = new Float(this.gravity);
            } else if (var3 == 2) {
               this.gravity = (Float)var4;
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Bounce Damping (1 = superball, 0 = beanbag)"));
            } else if (var3 == 1) {
               var5 = new Float(this.bounceDamp);
            } else if (var3 == 2) {
               this.bounceDamp = (Float)var4;
               this.bounceDamp = (float)Math.max(0.0, Math.min(1.0, this.bounceDamp));
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 8, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.linearVel);
      var1.saveFloat(this.linearDamp);
      var1.save(this.dir);
      var1.saveFloat(this.angularVel);
      var1.saveFloat(this.angularDamp);
      var1.save(this.axis);
      var1.saveFloat(this.gravity);
      var1.saveFloat(this.bounceDamp);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.linearVel = var1.restoreFloat();
            this.linearDamp = var1.restoreFloat();
            this.dir = (Point3)var1.restore();
            this.angularVel = var1.restoreFloat();
            this.angularDamp = var1.restoreFloat();
            this.axis = (Point3)var1.restore();
            this.gravity = var1.restoreFloat();
            this.bounceDamp = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }
}
