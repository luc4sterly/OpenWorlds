package NET.worlds.scape;

import NET.worlds.console.Console;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Date;

class MultiMotion extends TriggeredSwitchableBehavior implements FrameHandler, Persister, MouseDownHandler, BumpHandler {
   protected int motionNumber = 0;
   protected int motionNumberCount = 0;
   protected int motionNumberMax = 100;
   long startMultiMotionTime;
   long totalMultiMotionTime = 0L;
   protected String cycleTime;
   protected float[] cycleTimeArray;
   protected int cycles;
   protected Transform MultiMotionTransform;
   protected String startPoint;
   protected String endPoint;
   protected String deltaPoint;
   protected String startScale;
   protected String endScale;
   protected String deltaScale;
   protected String startSpin;
   protected String endSpin;
   protected Point3[] startPointArray;
   protected Point3[] endPointArray;
   protected Point3[] deltaPointArray;
   protected Point3[] startScaleArray;
   protected Point3[] endScaleArray;
   protected Point3[] deltaScaleArray;
   protected Point3[] startSpinArray;
   protected Point3[] endSpinArray;
   protected String startRotation;
   protected String endRotation;
   protected float[] startRotationArray;
   protected float[] endRotationArray;
   protected boolean MultiMotionTransformInitialized;
   protected boolean variableInitialized;
   protected boolean multiMotionEnd = true;

   public MultiMotion() {
      this.cycleTime = new String("1000");
      this.cycleTimeArray = new float[this.motionNumberMax];
      this.cycleTimeArray[0] = 1000.0F;
      this.trigger = new String("none");
      this.externalTriggerTag = new String("");
      this.cycles = 0;
      this.MultiMotionTransformInitialized = false;
      this.variableInitialized = false;
      this.startPointArray = new Point3[this.motionNumberMax];
      this.endPointArray = new Point3[this.motionNumberMax];
      this.deltaPointArray = new Point3[this.motionNumberMax];
      this.startScaleArray = new Point3[this.motionNumberMax];
      this.endScaleArray = new Point3[this.motionNumberMax];
      this.deltaScaleArray = new Point3[this.motionNumberMax];
      this.startSpinArray = new Point3[this.motionNumberMax];
      this.endSpinArray = new Point3[this.motionNumberMax];

      for (int var1 = 0; var1 < this.motionNumberMax; var1++) {
         this.startPointArray[var1] = new Point3();
         this.endPointArray[var1] = new Point3();
         this.deltaPointArray[var1] = new Point3();
         this.startScaleArray[var1] = new Point3();
         this.endScaleArray[var1] = new Point3();
         this.deltaScaleArray[var1] = new Point3();
         this.startSpinArray[var1] = new Point3();
         this.endSpinArray[var1] = new Point3();
      }

      this.startRotationArray = new float[this.motionNumberMax];
      this.endRotationArray = new float[this.motionNumberMax];
      this.startMultiMotion();
   }

   public void ExternalTrigger(Trigger var1, int var2, int var3) {
      this.trigger_source = var1;
      this.sequence_no = var2;
      this.event_no = var3;
      this.startMultiMotion();
   }

   public void startMultiMotion() {
      Date var1 = new Date();
      this.startMultiMotionTime = var1.getTime();
      this.motionNumber = 0;
      this.multiMotionEnd = false;
   }

   public void setTotalMultiMotionTime() {
      this.totalMultiMotionTime = 0L;

      for (int var1 = 0; var1 < this.motionNumberCount; var1++) {
         this.totalMultiMotionTime = this.totalMultiMotionTime + (int)this.cycleTimeArray[var1];
      }
   }

   public void parseFloatString(String var1, float[] var2) {
      int var3 = 0;
      int var4 = 0;
      int var5 = 0;
      int var6 = var1.lastIndexOf(" ");
      if (var6 != -1 || var1.length() != 0) {
         if (var6 == -1) {
            var2[var3] = Float.valueOf(var1);
         } else {
            var5 = var1.indexOf(" ");
            var2[var3] = Float.valueOf(var1.substring(0, var5));
            var3++;

            while (var5 != var6) {
               var4 = var5;
               var5 = var1.indexOf(" ", var4 + 1);
               var2[var3] = Float.valueOf(var1.substring(var4 + 1, var5));
               var3++;
            }

            var2[var3] = Float.valueOf(var1.substring(var5 + 1));
         }
      }
   }

   public Point3 StringToPoint3(String var1) {
      Point3 var2 = new Point3();
      int var3 = 0;
      var2.x = Float.valueOf(var1.substring(var3, var1.indexOf(",", var3)));
      var3 = var1.indexOf(",", var3) + 1;
      var2.y = Float.valueOf(var1.substring(var3, var1.indexOf(",", var3)));
      var3 = var1.indexOf(",", var3) + 1;
      var2.z = Float.valueOf(var1.substring(var3, var1.length()));
      return var2;
   }

   public void parsePoint3String(String var1, Point3[] var2) {
      int var3 = 0;
      int var4 = 0;
      int var5 = 0;
      int var6 = var1.lastIndexOf(" ");
      if (var6 != -1 || var1.length() != 0) {
         if (var6 == -1) {
            var2[var3] = this.StringToPoint3(var1);
         } else {
            var5 = var1.indexOf(" ");
            var2[var3] = this.StringToPoint3(var1.substring(0, var5));
            var3++;

            while (var5 != var6) {
               var4 = var5;
               var5 = var1.indexOf(" ", var4 + 1);
               var2[var3] = this.StringToPoint3(var1.substring(var4 + 1, var5));
               var3++;
            }

            var2[var3] = this.StringToPoint3(var1.substring(var5 + 1));
         }
      }
   }

   public boolean handle(FrameEvent var1) {
      if (!this.MultiMotionTransformInitialized) {
         this.MultiMotionTransform = var1.target;
         this.MultiMotionTransformInitialized = true;
      }

      if (!this.variableInitialized) {
         this.startPoint = this.MultiMotionTransform.getPosition().toString();
         this.startPointArray[0].copy(this.MultiMotionTransform.getPosition());
         this.endPoint = new String(this.startPoint);
         this.endPointArray[0].copy(this.startPointArray[0]);
         this.startScaleArray[0].x = this.MultiMotionTransform.getTotalScale();
         this.startScaleArray[0].y = this.MultiMotionTransform.getTotalScale();
         this.startScaleArray[0].z = this.MultiMotionTransform.getTotalScale();
         this.startScale = this.startScaleArray[0].toString();
         this.endScaleArray[0].copy(this.startScaleArray[0]);
         this.endScale = this.endScaleArray[0].toString();
         this.startRotation = new Float(this.MultiMotionTransform.getSpin(this.startSpinArray[0])).toString();
         this.startRotationArray[0] = Float.valueOf(this.startRotation);
         this.startSpin = this.startSpinArray[0].toString();
         this.endRotation = new String("0.0");
         this.endRotationArray[0] = Float.valueOf(this.endRotation);
         this.endSpinArray[0] = new Point3();
         this.endSpin = this.endSpinArray[0].toString();
         this.variableInitialized = true;
      }

      if (this.enabled) {
         Date var3 = new Date();
         long var4 = var3.getTime();
         int var6 = 0;
         if (this.totalMultiMotionTime > 0L) {
            var6 = (int)((-this.startMultiMotionTime + var4) / this.totalMultiMotionTime);
         }

         if (this.totalMultiMotionTime > 0L && (var6 < this.cycles || this.cycles == 0)) {
            long var7 = 0L;
            int var9 = (int)((var4 - this.startMultiMotionTime) % this.totalMultiMotionTime);
            int var10 = 0;

            for (this.motionNumber = 0; this.motionNumber < this.motionNumberCount && var7 <= var9; this.motionNumber++) {
               var10 = (int)this.cycleTimeArray[this.motionNumber];
               var7 += var10;
            }

            this.motionNumber--;
            if (var7 < var9) {
               System.out.print("Error in totalMultiMotionTime computation.\n");
            }

            var10 = (int)(var10 - (var7 - var9));
            float var11 = var10 % this.cycleTimeArray[this.motionNumber] / this.cycleTimeArray[this.motionNumber];
            var1.receiver.makeIdentity();
            var1.receiver
               .scale(
                  this.startScaleArray[this.motionNumber].x + (this.endScaleArray[this.motionNumber].x - this.startScaleArray[this.motionNumber].x) * var11,
                  this.startScaleArray[this.motionNumber].x + (this.endScaleArray[this.motionNumber].x - this.startScaleArray[this.motionNumber].x) * var11,
                  this.startScaleArray[this.motionNumber].x + (this.endScaleArray[this.motionNumber].x - this.startScaleArray[this.motionNumber].x) * var11
               );
            var1.receiver
               .moveTo(
                  this.startPointArray[this.motionNumber].x + (this.endPointArray[this.motionNumber].x - this.startPointArray[this.motionNumber].x) * var11,
                  this.startPointArray[this.motionNumber].y + (this.endPointArray[this.motionNumber].y - this.startPointArray[this.motionNumber].y) * var11,
                  this.startPointArray[this.motionNumber].z + (this.endPointArray[this.motionNumber].z - this.startPointArray[this.motionNumber].z) * var11
               );
            var1.receiver.spin(this.startSpinArray[this.motionNumber], this.startRotationArray[this.motionNumber]);
            var1.receiver.spin(this.endSpinArray[this.motionNumber], this.endRotationArray[this.motionNumber] * var11);
         } else if (var6 >= this.cycles && this.cycles != 0 && !this.multiMotionEnd) {
            this.multiMotionEnd = true;
            if (this.trigger_source != null) {
               this.trigger_source.registerFinishedTriggerTag(this.sequence_no, this.event_no);
            }
         }
      }

      return true;
   }

   public boolean handle(MouseDownEvent var1) {
      if (this.enabled && this.trigger.equals("click")) {
         this.startMultiMotion();
      }

      return true;
   }

   public boolean handle(BumpEventTemp var1) {
      if (this.enabled && this.trigger.equals("bump")) {
         this.startMultiMotion();
      }

      return true;
   }

   public void startTransform() {
      if (this.MultiMotionTransform != null) {
         this.MultiMotionTransform.makeIdentity();
         this.MultiMotionTransform
            .scale(this.startScaleArray[this.motionNumber].x, this.startScaleArray[this.motionNumber].x, this.startScaleArray[this.motionNumber].x);
         this.MultiMotionTransform
            .moveTo(this.startPointArray[this.motionNumber].x, this.startPointArray[this.motionNumber].y, this.startPointArray[this.motionNumber].z);
         this.MultiMotionTransform.spin(this.startSpinArray[this.motionNumber], this.startRotationArray[this.motionNumber]);
      }
   }

   public void endTransform() {
      if (this.MultiMotionTransform != null) {
         this.MultiMotionTransform.makeIdentity();
         this.MultiMotionTransform
            .scale(this.endScaleArray[this.motionNumber].x, this.endScaleArray[this.motionNumber].x, this.endScaleArray[this.motionNumber].x);
         this.MultiMotionTransform
            .moveTo(this.endPointArray[this.motionNumber].x, this.endPointArray[this.motionNumber].y, this.endPointArray[this.motionNumber].z);
         this.MultiMotionTransform.spin(this.startSpinArray[this.motionNumber], this.startRotationArray[this.motionNumber]);
         this.MultiMotionTransform.spin(this.endSpinArray[this.motionNumber], this.endRotationArray[this.motionNumber]);
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new ClassProperty(this, var1, "MultiMotion");
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Number of Motions"));
            } else if (var3 == 1) {
               var5 = new Integer(this.motionNumberCount);
            } else if (var3 == 2) {
               this.motionNumberCount = (Integer)var4;
               this.setTotalMultiMotionTime();
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
               var5 = StringPropertyEditor.make(new Property(this, var1, "Cycle Time"));
            } else if (var3 == 1) {
               var5 = new String(this.cycleTime);
            } else if (var3 == 2) {
               this.cycleTime = (String)var4;
               this.parseFloatString(this.cycleTime, this.cycleTimeArray);
               this.setTotalMultiMotionTime();
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "End Point"));
            } else if (var3 == 1) {
               var5 = new String(this.endPoint);
               this.endTransform();
            } else if (var3 == 2) {
               this.endPoint = (String)var4;
               this.parsePoint3String(this.endPoint, this.endPointArray);
               this.endTransform();
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Start Point"));
            } else if (var3 == 1) {
               var5 = new String(this.startPoint);
               this.startTransform();
            } else if (var3 == 2) {
               this.startPoint = (String)var4;
               this.parsePoint3String(this.startPoint, this.startPointArray);
               this.startTransform();
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "End Scale"));
            } else if (var3 == 1) {
               var5 = new String(this.endScale);
               this.endTransform();
            } else if (var3 == 2) {
               this.endScale = (String)var4;
               this.parsePoint3String(this.endScale, this.endScaleArray);
               this.endTransform();
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Start Scale"));
            } else if (var3 == 1) {
               var5 = new String(this.startScale);
               this.startTransform();
            } else if (var3 == 2) {
               this.startScale = (String)var4;
               this.parsePoint3String(this.startScale, this.startScaleArray);
               this.startTransform();
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "End Spin (Relative)"));
            } else if (var3 == 1) {
               var5 = new String(this.endSpin);
               this.endTransform();
            } else if (var3 == 2) {
               this.endSpin = (String)var4;
               this.parsePoint3String(this.endSpin, this.endSpinArray);
               this.endTransform();
            }
            break;
         case 11:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Start Spin"));
            } else if (var3 == 1) {
               var5 = new String(this.startSpin);
               this.startTransform();
            } else if (var3 == 2) {
               this.startSpin = (String)var4;
               this.parsePoint3String(this.startSpin, this.startSpinArray);
               this.startTransform();
            }
            break;
         case 12:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "End Rotation (Relative)"));
            } else if (var3 == 1) {
               var5 = new String(this.endRotation);
               this.endTransform();
            } else if (var3 == 2) {
               this.endRotation = (String)var4;
               this.parseFloatString(this.endRotation, this.endRotationArray);
               this.endTransform();
            }
            break;
         case 13:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Start Rotation"));
            } else if (var3 == 1) {
               var5 = new String(this.startRotation);
               this.startTransform();
            } else if (var3 == 2) {
               this.startRotation = (String)var4;
               this.parseFloatString(this.startRotation, this.startRotationArray);
               this.startTransform();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 14, var3, var4);
      }

      if (var3 == 2 && this.trigger.equals("none")) {
         this.startMultiMotion();
      }

      return var5;
   }

   public String toString() {
      return "Multimotion: cycleTime "
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
      var1.saveInt(this.motionNumberCount);
      var1.saveInt(this.cycles);
      var1.saveString(this.trigger);
      var1.saveString(this.externalTriggerTag);
      var1.saveString(this.cycleTime);
      var1.saveString(this.endPoint);
      var1.saveString(this.startPoint);
      var1.saveString(this.endScale);
      var1.saveString(this.startScale);
      var1.saveString(this.endSpin);
      var1.saveString(this.startSpin);
      var1.saveString(this.endRotation);
      var1.saveString(this.startRotation);
   }

   public void restoreState(Restorer var1) throws IOException {
      this.motionNumberCount = var1.restoreInt();
      this.cycles = var1.restoreInt();
      this.trigger = var1.restoreString();
      if (this.trigger.equals("external")) {
         Trigger.TriggeredSwitchableBehaviorList[Trigger.TriggeredSwitchableBehaviorListCount] = this;
         Trigger.TriggeredSwitchableBehaviorListCount++;
      }

      this.externalTriggerTag = var1.restoreString();
      this.cycleTime = var1.restoreString();
      this.parseFloatString(this.cycleTime, this.cycleTimeArray);
      this.endPoint = var1.restoreString();
      this.parsePoint3String(this.endPoint, this.endPointArray);
      this.setTotalMultiMotionTime();
      this.startPoint = var1.restoreString();
      this.parsePoint3String(this.startPoint, this.startPointArray);
      this.endScale = var1.restoreString();
      this.parsePoint3String(this.endScale, this.endScaleArray);
      this.startScale = var1.restoreString();
      this.parsePoint3String(this.startScale, this.startScaleArray);
      this.endSpin = var1.restoreString();
      this.parsePoint3String(this.endSpin, this.endSpinArray);
      this.startSpin = var1.restoreString();
      this.parsePoint3String(this.startSpin, this.startSpinArray);
      this.endRotation = var1.restoreString();
      this.parseFloatString(this.endRotation, this.endRotationArray);
      this.startRotation = var1.restoreString();
      this.parseFloatString(this.startRotation, this.startRotationArray);
      this.variableInitialized = true;
      if (!this.trigger.equals("none")) {
         this.startMultiMotionTime = (int)(-(this.cycles * this.cycleTimeArray[this.motionNumber]));
      } else {
         this.startMultiMotion();
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
      Console.println(MessageFormat.format(Console.message("MultiMotion-obs"), var7));
   }
}
