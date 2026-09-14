package NET.worlds.scape;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class RollingAttribute extends Attribute {
   RollBehavior rb = new RollBehavior();
   public float initialKickVel = 200.0F;
   private Point3 kp = new Point3();
   private float kv = 0.0F;
   private Point3 kd = new Point3();
   private static Object classCookie = new Object();

   public RollingAttribute(int var1) {
      super(var1);
      this.rb.linearDamp = 0.95F;
      this.rb.rollFactor = 1.0F;
      this.rb.setNotifyAttribute(this);
   }

   public RollingAttribute() {
      this.rb.linearDamp = 0.8F;
      this.rb.setNotifyAttribute(this);
   }

   public void set(Point3Temp var1, float var2, Point3Temp var3) {
      if (this.kp.x != var1.x || this.kp.y != var1.y || this.kp.x != var1.z) {
         this.kp.x = var1.x;
         this.kp.y = var1.y;
         this.kp.z = var1.z;
         this.kv = var2;
         this.kd.x = var3.x;
         this.kd.y = var3.y;
         this.kd.z = var3.z;
         ((WObject)this.getOwner().getOwner()).moveTo(this.kp);
         this.rb.linearVel = this.kv;
         this.rb.setDir(this.kd);
         this.noteChange();
      }
   }

   public void notifyStopped() {
      WObject var1 = (WObject)((Sharer)this.getOwner()).getOwner();
      Point3Temp var2 = var1.getPosition();
      this.set(var2, 0.0F, Point3Temp.make(0.0F, 0.0F, 0.0F));
   }

   public void get(Point3Temp var1, float var2, Point3Temp var3) {
      var1.x = this.kp.x;
      var1.y = this.kp.y;
      var1.z = this.kp.z;
      var2 = this.kv;
      var3.x = this.kd.x;
      var3.y = this.kd.y;
      var3.z = this.kd.z;
   }

   protected void noteAddingTo(SuperRoot var1) {
      WObject var2 = (WObject)var1.getOwner();
      var2.addHandler(this.rb);
   }

   public boolean handle(BumpEventTemp var1) {
      if (var1.target == var1.receiver && !(this.rb.linearVel > 0.0F)) {
         if (this.rb.linearVel == 0.0F) {
            Point3Temp var15 = var1.target.getWorldPosition();
            WObject var3 = (WObject)var1.source;
            float var17 = var3.getYaw();
            Point3Temp var5 = var3.getWorldPosition();
            double var18 = var5.x - var15.x;
            double var19 = var5.y - var15.y;
            Math.atan2(var18, var19);
            float var10 = (float)var19;
            float var11 = (float)((360.0F - var17 + 90.0F) * Math.PI / 180.0);
            Point3Temp var12 = Point3Temp.make((float)Math.cos(var11), (float)Math.sin(var11), 0.0F);
            var15.x = var15.x + var12.x;
            var15.y = var15.y + var12.y;
            this.set(var15, this.initialKickVel, var12);
         }
      } else {
         if (var1.target instanceof Camera) {
            double var2 = this.rb.dir.x;
            double var4 = this.rb.dir.y;
            Math.atan2(var2, var4);
            double var6 = var4 + 60.0 * Math.random() - 30.0;
            double var8 = var2;
            var2 = var8 * Math.cos(var6 * Math.PI / 180.0);
            var4 = var8 * Math.sin(var6 * Math.PI / 180.0);
            this.rb.dir.x = (float)var2;
            this.rb.dir.y = (float)var4;
         }

         this.rb.processBumpEvent(var1);
         if (var1.target instanceof Camera || var1.source instanceof Camera) {
            Point3Temp var14 = ((WObject)((Sharer)this.getOwner()).getOwner()).getWorldPosition();
            this.set(var14, this.rb.linearVel, this.rb.dir);
         }
      }

      return true;
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      var1.writeFloat(this.kp.x);
      var1.writeFloat(this.kp.y);
      var1.writeFloat(this.kp.z);
      var1.writeFloat(this.kv);
      var1.writeFloat(this.kd.x);
      var1.writeFloat(this.kd.y);
      var1.writeFloat(this.kd.z);
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      Point3Temp var3 = Point3Temp.make();
      float var4 = 0.0F;
      Point3Temp var5 = Point3Temp.make();
      var3.x = var1.readFloat();
      var3.y = var1.readFloat();
      var3.z = var1.readFloat();
      var4 = var1.readFloat();
      var5.x = var1.readFloat();
      var5.y = var1.readFloat();
      var5.z = var1.readFloat();
      this.set(var3, var4, var5);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Roll Factor"));
            } else if (var3 == 1) {
               var5 = new Float(this.rb.rollFactor);
            } else if (var3 == 2) {
               this.rb.rollFactor = (Float)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Initial Kick Velocity"));
            } else if (var3 == 1) {
               var5 = new Float(this.initialKickVel);
            } else if (var3 == 2) {
               this.initialKickVel = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.initialKickVel);
      var1.saveFloat(this.rb.rollFactor);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.initialKickVel = var1.restoreFloat();
            float var2 = var1.restoreFloat();
            break;
         case 1:
            super.restoreState(var1);
            this.initialKickVel = var1.restoreFloat();
            this.rb.rollFactor = var1.restoreFloat();
            break;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + " [From " + this.kp + " with velocity " + this.kv + " toward " + this.kd + "] ";
   }
}
