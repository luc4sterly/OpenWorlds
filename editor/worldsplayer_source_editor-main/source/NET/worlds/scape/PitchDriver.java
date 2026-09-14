package NET.worlds.scape;

import java.io.IOException;
import java.util.Enumeration;

public class PitchDriver extends SwitchableBehavior implements KeyUpHandler, KeyDownHandler, FrameHandler, Persister, MomentumBehavior {
   protected float pitch_force;
   protected float pitch_vel;
   protected int lastTime;
   protected float maxdvpitch = 166.0F;
   protected float pitch_damp = -5.0F;
   protected float minpitch_vel = 3.0F;
   protected float pitch_key = 500.0F;
   private static Object cookie = new Object();

   public void applyFrameForce(Event var1) {
      if (var1.receiver instanceof Pilot) {
         Camera var2 = ((Pilot)var1.receiver).getMainCamera();
         int var3 = var1.time;
         float var4 = (var3 - this.lastTime) / 1000.0F;
         if (!(var4 <= 0.0F)) {
            this.lastTime = var3;
            float var5 = this.pitch_vel * var4;
            float var6 = 0.0F;
            if (this.pitch_force != 0.0F) {
               var6 += this.pitch_force * var4;
               var6 = this.maxdvpitch * (float)Math.atan(var6 / this.maxdvpitch);
               this.pitch_vel += var6;
               var5 += var6 * var4;
            }

            if (var5 != 0.0F) {
               Point3Temp var7 = Point3Temp.make();
               float var8 = var2.lookAround.getSpin(var7);
               if (var7.x < 0.0F) {
                  var8 = -var8;
               }

               if (var8 + var5 > 90.0F) {
                  var5 = 90.0F - var8;
               } else if (var8 + var5 < -90.0F) {
                  var5 = -90.0F - var8;
               }

               var2.lookAround.spin(1.0F, 0.0F, 0.0F, var5);
            }

            this.pitch_vel = (float)(this.pitch_vel * Math.exp(this.pitch_damp * var4));
            if (Math.abs(this.pitch_vel) < this.minpitch_vel) {
               this.pitch_vel = 0.0F;
            }
         }
      }
   }

   public boolean handle(FrameEvent var1) {
      this.applyFrameForce(var1);
      return true;
   }

   public void resetPitch(Event var1) {
      Camera var2 = ((Pilot)var1.receiver).getMainCamera();
      var2.lookAround.makeIdentity();
   }

   public boolean handle(KeyDownEvent var1) {
      float var2;
      if (var1.getKey() == '\ue321') {
         var2 = this.pitch_key;
      } else {
         if (var1.getKey() != '\ue322') {
            if (var1.getKey() == '\ue324') {
               this.resetPitch(var1);
            }

            return true;
         }

         var2 = -this.pitch_key;
      }

      this.applyFrameForce(var1);
      this.pitch_force = var2;
      return true;
   }

   public boolean handle(KeyUpEvent var1) {
      if (var1.getKey() == '\ue321' || var1.getKey() == '\ue322') {
         this.applyFrameForce(var1);
         this.pitch_force = 0.0F;
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Pitch max acceleration"));
            } else if (var3 == 1) {
               var5 = new Float(this.maxdvpitch);
            } else if (var3 == 2) {
               this.maxdvpitch = ((Float)var4).intValue();
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Pitch rate damping"));
            } else if (var3 == 1) {
               var5 = new Float(this.pitch_damp);
            } else if (var3 == 2) {
               this.pitch_damp = ((Float)var4).intValue();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Pitch min rate"));
            } else if (var3 == 1) {
               var5 = new Float(this.minpitch_vel);
            } else if (var3 == 2) {
               this.minpitch_vel = ((Float)var4).intValue();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Pitch rate increment for up/down arrow keys"));
            } else if (var3 == 1) {
               var5 = new Float(this.pitch_key);
            } else if (var3 == 2) {
               this.pitch_key = ((Float)var4).intValue();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 12, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, cookie);
      super.saveState(var1);
      var1.saveFloat(this.pitch_vel);
      var1.saveFloat(this.maxdvpitch);
      var1.saveFloat(this.pitch_damp);
      var1.saveFloat(this.minpitch_vel);
      var1.saveFloat(this.pitch_key);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(cookie)) {
         case 0:
            var1.setOldFlag();
            super.restoreState(var1);
            var1.restoreFloat();
            this.pitch_vel = var1.restoreFloat();
            this.maxdvpitch = var1.restoreFloat();
            this.pitch_damp = var1.restoreFloat();
            this.minpitch_vel = var1.restoreFloat();
            this.pitch_key = var1.restoreFloat();
            break;
         case 1:
            super.restoreState(var1);
            this.pitch_vel = var1.restoreFloat();
            this.maxdvpitch = var1.restoreFloat();
            this.pitch_damp = var1.restoreFloat();
            this.minpitch_vel = var1.restoreFloat();
            this.pitch_key = var1.restoreFloat();
            break;
         default:
            throw new TooNewException();
      }
   }

   public void transferFrom(Enumeration var1) {
      while (var1.hasMoreElements()) {
         SuperRoot var2 = (SuperRoot)var1.nextElement();
         if (var2 instanceof PitchDriver) {
            PitchDriver var3 = (PitchDriver)var2;
            this.pitch_vel = var3.pitch_vel;
            this.pitch_force = var3.pitch_force;
            this.lastTime = var3.lastTime;
            break;
         }
      }
   }
}
