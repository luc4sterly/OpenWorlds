package NET.worlds.scape;

import NET.worlds.console.Console;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Date;

class Motion extends TriggeredSwitchableBehavior implements FrameHandler, Persister, MouseDownHandler, BumpHandler {
   long startMotionTime;
   protected float cycleTime;
   protected String frameList;
   protected int cycles;
   protected Transform motionTransform;
   protected Point3 startPoint;
   protected Point3 endPoint;
   protected Point3 deltaPoint;
   protected Point3 startScale;
   protected Point3 endScale;
   protected Point3 deltaScale;
   protected Point3 startSpin;
   protected Point3 endSpin;
   protected Point3 currentSpin;
   protected float startRotation;
   protected float endRotation;
   protected float currentRotation;
   protected boolean motionTransformInitialized;
   protected boolean variableInitialized;
   protected boolean motionEnd = true;

   public Motion() {
      this.cycleTime = 1000.0F;
      this.trigger = new String("none");
      this.externalTriggerTag = new String("");
      this.cycles = 0;
      this.motionTransformInitialized = false;
      this.variableInitialized = false;
      this.startPoint = new Point3();
      this.endPoint = new Point3();
      this.deltaPoint = new Point3();
      this.startScale = new Point3();
      this.endScale = new Point3();
      this.deltaScale = new Point3();
      this.startSpin = new Point3();
      this.endSpin = new Point3();
      this.currentSpin = new Point3();
      this.startMotion();
   }

   public void ExternalTrigger(Trigger var1, int var2, int var3) {
      this.trigger_source = var1;
      this.sequence_no = var2;
      this.event_no = var3;
      this.startMotion();
   }

   public boolean equivalent(Point3Temp var1, Point3Temp var2) {
      return Math.round(var1.x) == Math.round(var2.x) && Math.round(var1.y) == Math.round(var2.y) && Math.round(var1.z) == Math.round(var2.z);
   }

   public void startMotion() {
      if (this.motionTransform != null
         && this.equivalent(this.startPoint, this.motionTransform.getPosition())
         && Math.round(this.startScale.x) == Math.round(this.motionTransform.getTotalScale())) {
         this.currentRotation = Math.round(this.motionTransform.getSpin(this.currentSpin));
         this.startRotation = Math.round(this.startRotation);
         if ((this.startRotation == this.currentRotation || this.startRotation - 360.0F == this.currentRotation)
               && this.equivalent(this.startSpin, this.currentSpin)
            || (-this.startRotation == this.currentRotation || 360.0F - this.startRotation == this.currentRotation)
               && this.equivalent(this.startSpin, this.currentSpin.negate())) {
            Date var1 = new Date();
            this.startMotionTime = var1.getTime();
            this.motionEnd = true;
         }
      }
   }

   public boolean handle(FrameEvent var1) {
      if (!this.motionTransformInitialized) {
         this.motionTransform = var1.target;
         this.motionTransformInitialized = true;
      }

      if (!this.variableInitialized) {
         this.startPoint.copy(this.motionTransform.getPosition());
         this.endPoint.copy(this.startPoint);
         this.startScale.x = this.motionTransform.getTotalScale();
         this.startScale.y = this.motionTransform.getTotalScale();
         this.startScale.z = this.motionTransform.getTotalScale();
         this.endScale.copy(this.startScale);
         this.startRotation = this.motionTransform.getSpin(this.startSpin);
         this.endRotation = 0.0F;
         this.variableInitialized = true;
      }

      if (this.enabled) {
         Date var3 = new Date();
         long var4 = var3.getTime();
         float var6 = (float)(-this.startMotionTime + var4) % this.cycleTime / this.cycleTime;
         int var7 = (int)((float)(-this.startMotionTime + var4) / this.cycleTime);
         if (var7 < this.cycles || this.cycles == 0 || !this.motionEnd) {
            this.motionEnd = false;
            if (var7 >= this.cycles && this.cycles != 0) {
               this.motionEnd = true;
               var6 = 1.0F;
               if (this.trigger_source != null) {
                  this.trigger_source.registerFinishedTriggerTag(this.sequence_no, this.event_no);
               }
            }

            var1.receiver.makeIdentity();
            var1.receiver
               .scale(
                  this.startScale.x + (this.endScale.x - this.startScale.x) * var6,
                  this.startScale.x + (this.endScale.x - this.startScale.x) * var6,
                  this.startScale.x + (this.endScale.x - this.startScale.x) * var6
               );
            var1.receiver
               .moveTo(
                  this.startPoint.x + (this.endPoint.x - this.startPoint.x) * var6,
                  this.startPoint.y + (this.endPoint.y - this.startPoint.y) * var6,
                  this.startPoint.z + (this.endPoint.z - this.startPoint.z) * var6
               );
            var1.receiver.spin(this.startSpin, this.startRotation);
            var1.receiver.spin(this.endSpin, this.endRotation * var6);
         }
      }

      return true;
   }

   public boolean handle(MouseDownEvent var1) {
      if (this.enabled && this.trigger.equals("click")) {
         this.startMotion();
      }

      return true;
   }

   public boolean handle(BumpEventTemp var1) {
      if (this.enabled && this.trigger.equals("bump")) {
         this.startMotion();
      }

      return true;
   }

   public void startTransform() {
      if (this.motionTransform != null) {
         this.motionTransform.makeIdentity();
         this.motionTransform.scale(this.startScale.x, this.startScale.x, this.startScale.x);
         this.motionTransform.moveTo(this.startPoint.x, this.startPoint.y, this.startPoint.z);
         this.motionTransform.spin(this.startSpin, this.startRotation);
      } else {
         System.out.println("motionTransform is null!!!!");
      }
   }

   public void endTransform() {
      if (this.motionTransform != null) {
         this.motionTransform.makeIdentity();
         this.motionTransform.scale(this.endScale.x, this.endScale.x, this.endScale.x);
         this.motionTransform.moveTo(this.endPoint.x, this.endPoint.y, this.endPoint.z);
         this.motionTransform.spin(this.startSpin, this.startRotation);
         this.motionTransform.spin(this.endSpin, this.endRotation);
      } else {
         System.out.println("motionTransform is null!!!!");
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new ClassProperty(this, var1, "Motion");
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Cycle Time"));
            } else if (var3 == 1) {
               var5 = new Float(this.cycleTime);
            } else if (var3 == 2) {
               this.cycleTime = (Float)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Cycles"));
            } else if (var3 == 1) {
               var5 = new Integer(this.cycles);
            } else if (var3 == 2) {
               this.cycles = (Integer)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Trigger"));
            } else if (var3 == 1) {
               var5 = new String(this.trigger);
            } else if (var3 == 2) {
               this.trigger = ((String)var4).toString().trim();
               if (this.trigger.equals("external")) {
                  Trigger.TriggeredSwitchableBehaviorList[Trigger.TriggeredSwitchableBehaviorListCount] = this;
                  Trigger.TriggeredSwitchableBehaviorListCount++;
               }
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "External Trigger Tag"));
            } else if (var3 == 1) {
               var5 = new String(this.externalTriggerTag);
            } else if (var3 == 2) {
               this.externalTriggerTag = ((String)var4).toString().trim();
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "End Point"));
            } else if (var3 == 1) {
               var5 = new Point3(this.endPoint);
               this.endTransform();
            } else if (var3 == 2) {
               this.endPoint.copy((Point3)var4);
               this.endTransform();
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Start Point"));
            } else if (var3 == 1) {
               var5 = new Point3(this.startPoint);
               this.startTransform();
            } else if (var3 == 2) {
               this.startPoint.copy((Point3)var4);
               this.startTransform();
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "End Scale"));
            } else if (var3 == 1) {
               var5 = new Point3(this.endScale);
               this.endTransform();
            } else if (var3 == 2) {
               this.endScale.copy((Point3)var4);
               this.endTransform();
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Start Scale"));
            } else if (var3 == 1) {
               var5 = new Point3(this.startScale);
               this.startTransform();
            } else if (var3 == 2) {
               this.startScale.copy((Point3)var4);
               this.startTransform();
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "End Spin (Relative)"));
            } else if (var3 == 1) {
               var5 = new Point3(this.endSpin);
               this.endTransform();
            } else if (var3 == 2) {
               this.endSpin.copy((Point3)var4);
               this.endTransform();
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Start Spin"));
            } else if (var3 == 1) {
               var5 = new Point3(this.startSpin);
               this.startTransform();
            } else if (var3 == 2) {
               this.startSpin.copy((Point3)var4);
               this.startTransform();
            }
            break;
         case 11:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "End Rotation (Relative)"));
            } else if (var3 == 1) {
               var5 = new Float(this.endRotation);
               this.endTransform();
            } else if (var3 == 2) {
               this.endRotation = (Float)var4;
               this.endTransform();
            }
            break;
         case 12:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Start Rotation"));
            } else if (var3 == 1) {
               var5 = new Float(this.startRotation);
               this.startTransform();
            } else if (var3 == 2) {
               this.startRotation = (Float)var4;
               this.startTransform();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 13, var3, var4);
      }

      if (var3 == 2 && this.trigger.equals("none")) {
         this.startMotion();
      }

      return var5;
   }

   public String toString() {
      return "Motion: cycleTime "
         + this.cycleTime
         + ", cycles "
         + this.cycles
         + ", enabled "
         + this.enabled
         + ", trigger "
         + this.trigger
         + ", externalTriggerTag "
         + this.externalTriggerTag;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveFloat(this.cycleTime);
      var1.saveInt(this.cycles);
      var1.saveString(this.trigger);
      var1.saveString(this.externalTriggerTag);
      this.endPoint.saveState(var1);
      this.startPoint.saveState(var1);
      this.endScale.saveState(var1);
      this.startScale.saveState(var1);
      this.endSpin.saveState(var1);
      this.startSpin.saveState(var1);
      var1.saveFloat(this.endRotation);
      var1.saveFloat(this.startRotation);
   }

   public void restoreState(Restorer var1) throws IOException {
      this.cycleTime = var1.restoreFloat();
      this.cycles = var1.restoreInt();
      this.trigger = var1.restoreString();
      if (this.trigger.equals("external")) {
         Trigger.TriggeredSwitchableBehaviorList[Trigger.TriggeredSwitchableBehaviorListCount] = this;
         Trigger.TriggeredSwitchableBehaviorListCount++;
      }

      this.externalTriggerTag = var1.restoreString();

      try {
         this.endPoint.restoreState(var1);
         this.startPoint.restoreState(var1);
         this.endScale.restoreState(var1);
         this.startScale.restoreState(var1);
         this.endSpin.restoreState(var1);
         this.startSpin.restoreState(var1);
      } catch (Exception var3) {
      }

      this.endRotation = var1.restoreFloat();
      this.startRotation = var1.restoreFloat();
      this.variableInitialized = true;
      if (!this.trigger.equals("none")) {
         this.startMotionTime = (int)(-(this.cycles * this.cycleTime));
      } else {
         this.startMotion();
      }
   }

   public void postRestore(int var1) {
      String var2 = this.getName();
      String var3 = var2 == null ? "<null>" : var2;
      SuperRoot var4 = this.getOwner();
      String var5 = "";
      if (var4 != null) {
         var5 = var4.getName();
      }

      String var6 = var5 == null ? "<null>" : var5;
      Object[] var7 = new Object[]{new String(var3), new String(var6)};
      Console.println(MessageFormat.format(Console.message("Motion-obs"), var7));
   }
}
