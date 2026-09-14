package NET.worlds.scape;

import NET.worlds.console.Window;
import java.io.IOException;
import java.util.Enumeration;

public class SmoothDriver
   extends SwitchableBehavior
   implements MouseDeltaHandler,
   KeyUpHandler,
   KeyDownHandler,
   FrameHandler,
   MouseDownHandler,
   MouseUpHandler,
   MomentumBehavior {
   protected float FB_force;
   protected boolean FB_forceFromMouse;
   protected float FB_vel;
   protected float LR_force;
   protected float LR_vel;
   protected int lastTime;
   protected float maxdvFB = 300.0F;
   protected float FB_damp = -2.5F;
   protected float minFB_vel = 4.0F;
   protected float minFB_pixDouble = 40.0F;
   protected float maxdvLR = 166.0F;
   protected float LR_damp = -5.0F;
   protected float minLR_vel = 3.0F;
   protected float minLR_pixDouble = 40.0F;
   protected float eyeHeight = 150.0F;
   private int appliedForceThisFrame = 0;
   private int forceDouble = 0;
   protected float FB_key = 1200.0F;
   protected float LR_key = 500.0F;
   private static Object classCookie = new Object();

   public boolean handle(MouseDeltaEvent var1) {
      if (UniverseHandler.handle(var1)) {
         return true;
      }

      if (var1.dx != 0 || var1.dy != 0) {
         this.applyFrameForce(var1);
         float var2 = var1.dx * var1.dx;
         float var3 = var1.dy * var1.dy;
         double var4 = Math.sqrt(var2 + var3);
         if (var1.dy < 0) {
            var3 = -var3;
         }

         this.FB_vel -= (float)(1.1 * var3 / var4);
         if (var1.dx < 0) {
            var2 = -var2;
         }

         this.LR_vel -= (float)(0.5 * var2 / var4);
      }

      return true;
   }

   public void setVelocityDamping(float var1) {
      this.FB_damp = var1;
   }

   public float getVelocityDamping() {
      return this.FB_damp;
   }

   public void setEyeHeight(float var1) {
      this.eyeHeight = var1;
   }

   public float getEyeHeight() {
      return this.eyeHeight;
   }

   public void applyFrameForce(Event var1) {
      if (var1.receiver instanceof Pilot) {
         Pilot var2 = (Pilot)var1.receiver;
         if (var2.isActive()) {
            this.appliedForceThisFrame++;
            int var3 = var1.time;
            float var4 = (var3 - this.lastTime) / 1000.0F;
            if (!(var4 <= 0.0F)) {
               if (var4 > 0.33F) {
                  var4 = 0.33F;
               }

               this.lastTime = var3;
               float var5 = this.FB_vel * var4;
               float var6 = 0.0F;
               if (this.FB_force != 0.0F) {
                  var6 += this.FB_force * var4;
                  var6 = this.maxdvFB * (float)Math.atan(var6 / this.maxdvFB);
                  this.FB_vel += var6;
                  var5 += var6 * var4;
               }

               float var7 = this.eyeHeight - var2.getZ();
               Room var8 = var2.getRoom();
               if (var8 != null) {
                  var7 += var8.floorHeight(var2.getX(), var2.getY(), var2.getZ());
               }

               if (var5 != 0.0F || var7 != 0.0F) {
                  this.moveLevel(var2, var5, var7);
               }

               this.FB_vel = (float)(this.FB_vel * Math.exp(this.FB_damp * var4));
               if (Math.abs(this.FB_vel) < this.minFB_vel) {
                  this.FB_vel = 0.0F;
               }

               var6 = this.LR_vel * var4;
               var7 = 0.0F;
               if (this.LR_force != 0.0F) {
                  var7 += this.LR_force * var4;
                  var7 = this.maxdvLR * (float)Math.atan(var7 / this.maxdvLR);
                  this.LR_vel += var7;
                  var6 += var7 * var4;
               }

               if (var6 != 0.0F) {
                  this.yawLevel(var2, var6);
               }

               this.LR_vel = (float)(this.LR_vel * Math.exp(this.LR_damp * var4));
               if (Math.abs(this.LR_vel) < this.minLR_vel) {
                  this.LR_vel = 0.0F;
               }
            }
         }
      }
   }

   private void moveLevel(Pilot var1, float var2, float var3) {
      float var4 = var1.getYaw();
      Point3Temp var5 = Point3Temp.make();
      float var6 = var1.getSpin(var5);
      Point3Temp var7 = var1.getPosition();
      var1.makeIdentity().moveTo(var7).yaw(-var4);
      var1.premoveThrough(Point3Temp.make(0.0F, var2, var3));
      var1.yaw(var4);
      var1.spin(var5, var6);
   }

   private void yawLevel(Pilot var1, float var2) {
      float var3 = var1.getYaw();
      Point3Temp var4 = Point3Temp.make();
      float var5 = var1.getSpin(var4);
      Point3Temp var6 = var1.getPosition();
      var1.makeIdentity().moveTo(var6).yaw(-var3);
      var1.yaw(var2);
      var1.yaw(var3);
      var1.spin(var4, var5);
   }

   public boolean handle(FrameEvent var1) {
      if (this.FB_forceFromMouse && !this.isDelta(var1)) {
         this.applyFrameForce(var1);
         this.FB_force = 0.0F;
         this.FB_forceFromMouse = false;
      }

      if (this.appliedForceThisFrame == 0) {
         this.applyFrameForce(var1);
      }

      this.appliedForceThisFrame = 0;
      return true;
   }

   public boolean handle(KeyDownEvent var1) {
      if (UniverseHandler.handle(var1)) {
         return true;
      }

      float var2;
      if (var1.key == '\ue326') {
         var2 = this.FB_key;
      } else {
         if (var1.key != '\ue328') {
            float var3;
            if (var1.key == '\ue325') {
               var3 = this.LR_key;
            } else {
               if (var1.key != '\ue327') {
                  return true;
               }

               var3 = -this.LR_key;
            }

            this.applyFrameForce(var1);
            this.LR_force = var3;
            return true;
         }

         var2 = -this.FB_key;
      }

      this.applyFrameForce(var1);
      this.FB_force = var2;
      return true;
   }

   public boolean handle(KeyUpEvent var1) {
      if (UniverseHandler.handle(var1)) {
         return true;
      }

      if (var1.key == '\ue326' || var1.key == '\ue328') {
         this.applyFrameForce(var1);
         this.FB_force = 0.0F;
      } else if (var1.key == '\ue325' || var1.key == '\ue327') {
         this.applyFrameForce(var1);
         this.LR_force = 0.0F;
      }

      return true;
   }

   private boolean isDelta(Event var1) {
      if (var1.receiver instanceof Pilot && ((Pilot)var1.receiver).isActive()) {
         Window var2 = Window.getMainWindow();
         return var2 != null && var2.getDeltaMode();
      } else {
         return false;
      }
   }

   public boolean handle(MouseDownEvent var1) {
      if (var1.key == '\ue302' && this.isDelta(var1)) {
         this.applyFrameForce(var1);
         this.FB_force = this.FB_key;
         this.FB_forceFromMouse = true;
      }

      return true;
   }

   public boolean handle(MouseUpEvent var1) {
      if (var1.key == '\ue302' && this.isDelta(var1)) {
         this.applyFrameForce(var1);
         this.FB_force = 0.0F;
         this.FB_forceFromMouse = false;
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Eye Height"));
            } else if (var3 == 1) {
               var5 = new Float(this.getEyeHeight());
            } else if (var3 == 2) {
               this.setEyeHeight((Float)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Fore/aft max acceleration"));
            } else if (var3 == 1) {
               var5 = new Float(this.maxdvFB);
            } else if (var3 == 2) {
               this.maxdvFB = (Float)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Fore/aft velocity damping"));
            } else if (var3 == 1) {
               var5 = new Float(this.FB_damp);
            } else if (var3 == 2) {
               this.FB_damp = (Float)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Fore/aft min velocity"));
            } else if (var3 == 1) {
               var5 = new Float(this.minFB_vel);
            } else if (var3 == 2) {
               this.minFB_vel = (Float)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Fore/aft velocity threshold for pixel doubling"));
            } else if (var3 == 1) {
               var5 = new Float(this.minFB_pixDouble);
            } else if (var3 == 2) {
               this.minFB_pixDouble = (Float)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Yaw max acceleration"));
            } else if (var3 == 1) {
               var5 = new Float(this.maxdvLR);
            } else if (var3 == 2) {
               this.maxdvLR = (Float)var4;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Yaw rate damping"));
            } else if (var3 == 1) {
               var5 = new Float(this.LR_damp);
            } else if (var3 == 2) {
               this.LR_damp = (Float)var4;
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Yaw min rate"));
            } else if (var3 == 1) {
               var5 = new Float(this.minLR_vel);
            } else if (var3 == 2) {
               this.minLR_vel = (Float)var4;
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Yaw rate threshold for pixel doubling"));
            } else if (var3 == 1) {
               var5 = new Float(this.minLR_pixDouble);
            } else if (var3 == 2) {
               this.minLR_pixDouble = (Float)var4;
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Fore/aft velocity increment for up/down arrow keys"));
            } else if (var3 == 1) {
               var5 = new Float(this.FB_key);
            } else if (var3 == 2) {
               this.FB_key = (Float)var4;
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Yaw rate increment for up/down arrow keys"));
            } else if (var3 == 1) {
               var5 = new Float(this.LR_key);
            } else if (var3 == 2) {
               this.LR_key = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 11, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(3, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.FB_vel);
      var1.saveFloat(this.LR_vel);
      var1.saveFloat(this.maxdvFB);
      var1.saveFloat(this.FB_damp);
      var1.saveFloat(this.minFB_vel);
      var1.saveFloat(this.maxdvLR);
      var1.saveFloat(this.LR_damp);
      var1.saveFloat(this.minLR_vel);
      var1.saveFloat(this.eyeHeight);
      var1.saveFloat(this.FB_key);
      var1.saveFloat(this.LR_key);
      var1.saveInt(this.forceDouble);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            var1.setOldFlag();
            super.restoreState(var1);
            var1.restoreFloat();
            this.FB_vel = var1.restoreFloat();
            var1.restoreFloat();
            this.LR_vel = var1.restoreFloat();
            break;
         case 1:
            var1.setOldFlag();
            super.restoreState(var1);
            var1.restoreFloat();
            this.FB_vel = var1.restoreFloat();
            var1.restoreFloat();
            this.LR_vel = var1.restoreFloat();
            this.maxdvFB = var1.restoreFloat();
            this.FB_damp = var1.restoreFloat();
            this.minFB_vel = var1.restoreFloat();
            this.maxdvLR = var1.restoreFloat();
            this.LR_damp = var1.restoreFloat();
            this.minLR_vel = var1.restoreFloat();
            this.eyeHeight = var1.restoreFloat();
            this.FB_key = var1.restoreFloat();
            this.LR_key = var1.restoreFloat();
            break;
         case 2:
            var1.setOldFlag();
            super.restoreState(var1);
            var1.restoreFloat();
            this.FB_vel = var1.restoreFloat();
            var1.restoreFloat();
            this.LR_vel = var1.restoreFloat();
            this.maxdvFB = var1.restoreFloat();
            this.FB_damp = var1.restoreFloat();
            this.minFB_vel = var1.restoreFloat();
            this.maxdvLR = var1.restoreFloat();
            this.LR_damp = var1.restoreFloat();
            this.minLR_vel = var1.restoreFloat();
            this.eyeHeight = var1.restoreFloat();
            this.FB_key = var1.restoreFloat();
            this.LR_key = var1.restoreFloat();
            this.forceDouble = var1.restoreInt();
            break;
         case 3:
            super.restoreState(var1);
            this.FB_vel = var1.restoreFloat();
            this.LR_vel = var1.restoreFloat();
            this.maxdvFB = var1.restoreFloat();
            this.FB_damp = var1.restoreFloat();
            this.minFB_vel = var1.restoreFloat();
            this.maxdvLR = var1.restoreFloat();
            this.LR_damp = var1.restoreFloat();
            this.minLR_vel = var1.restoreFloat();
            this.eyeHeight = var1.restoreFloat();
            this.FB_key = var1.restoreFloat();
            this.LR_key = var1.restoreFloat();
            this.forceDouble = var1.restoreInt();
            break;
         default:
            throw new TooNewException();
      }
   }

   public void transferFrom(Enumeration var1) {
      this.FB_force = 0.0F;
      this.LR_force = 0.0F;

      while (var1.hasMoreElements()) {
         SuperRoot var2 = (SuperRoot)var1.nextElement();
         if (var2 instanceof SmoothDriver) {
            SmoothDriver var3 = (SmoothDriver)var2;
            this.FB_vel = var3.FB_vel;
            this.LR_vel = var3.LR_vel;
            this.lastTime = var3.lastTime;
            return;
         }
      }

      this.FB_vel = 0.0F;
      this.LR_vel = 0.0F;
      this.lastTime = 0;
   }
}
