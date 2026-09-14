package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.io.IOException;
import java.net.MalformedURLException;
import java.text.MessageFormat;
import java.util.Date;

class Animation extends TriggeredSwitchableBehavior implements FrameHandler, Persister, MouseDownHandler, BumpHandler {
   long startFrameTime;
   protected float cycleTime;
   protected String frameList;
   protected int cycles;
   protected int cycleNo = 0;
   protected String[] frameListArray;
   protected Material[] frameMaterialArray;
   protected int frameListCount;
   protected int currentFrameNo;
   protected boolean animationEnd = true;

   public Animation() {
      this.cycleTime = 1000.0F;
      this.frameList = new String("");
      this.trigger = new String("none");
      this.externalTriggerTag = new String("");
      this.cycles = 0;
      this.frameListArray = new String[200];
      this.frameMaterialArray = new Material[200];
      this.frameListCount = 0;
      this.startAnimation();
   }

   public void ExternalTrigger(Trigger var1, int var2, int var3) {
      this.trigger_source = var1;
      this.sequence_no = var2;
      this.event_no = var3;
      this.startAnimation();
   }

   public void startAnimation() {
      Date var1 = new Date();
      this.startFrameTime = var1.getTime();
      this.cycleNo = 0;
      this.currentFrameNo = 0;
      this.animationEnd = false;
   }

   public float getCycleTime() {
      return this.cycleTime;
   }

   public void setCycleTime(float var1) {
      this.cycleTime = var1;
   }

   public int getNextFrameNo() {
      Date var1 = new Date();
      int var2 = 0;
      if (this.frameListCount > 0) {
         var2 = (int)(this.frameListCount * ((float)(var1.getTime() - this.startFrameTime) % this.cycleTime) / (this.cycleTime + 1.0F) + 1.0F);
         if (this.currentFrameNo > var2) {
            this.cycleNo++;
         }
      }

      return var2;
   }

   public void preprocessFrameList(String var1) {
      int var2 = 1;
      int var3 = 0;
      int var4 = 0;
      int var5 = var1.lastIndexOf(" ");
      if (var5 != -1 || var1.length() != 0) {
         if (var5 == -1) {
            this.frameListArray[var2] = var1;
         } else {
            var4 = var1.indexOf(" ");
            this.frameListArray[var2] = var1.substring(0, var4);
            var2++;

            while (var4 != var5) {
               var3 = var4;
               var4 = var1.indexOf(" ", var3 + 1);
               this.frameListArray[var2] = var1.substring(var3 + 1, var4);
               var2++;
            }

            this.frameListArray[var2] = var1.substring(var4 + 1);
            this.frameListCount = var2;
         }
      }

      for (int var11 = 1; var11 <= this.frameListCount; var11++) {
         String var6 = this.frameListArray[var11];

         URL var7;
         try {
            var7 = new URL(this, var6);
         } catch (MalformedURLException var9) {
            var7 = URL.make("error:\"" + var6 + '"');
         }

         this.frameMaterialArray[var11] = new Material(var7);
      }
   }

   public boolean handle(FrameEvent var1) {
      if (this.enabled && var1.receiver instanceof Rect) {
         int var2 = this.getNextFrameNo();
         if (this.cycleNo >= this.cycles && this.cycles != 0) {
            if (this.currentFrameNo != this.frameListCount) {
               Rect var4 = (Rect)var1.receiver;
               var4.setMaterial(this.frameMaterialArray[this.frameListCount]);
               this.currentFrameNo = this.frameListCount;
            }
         } else if (var2 > 0 && var2 != this.currentFrameNo) {
            this.currentFrameNo = var2;
            Rect var3 = (Rect)var1.receiver;
            var3.setMaterial(this.frameMaterialArray[this.currentFrameNo]);
         }

         if (this.cycleNo >= this.cycles && this.cycles != 0 && !this.animationEnd) {
            this.animationEnd = true;
            if (this.trigger_source != null) {
               this.trigger_source.registerFinishedTriggerTag(this.sequence_no, this.event_no);
            }
         }
      }

      return true;
   }

   public boolean handle(MouseDownEvent var1) {
      if (this.enabled && this.trigger.equals("click")) {
         this.startAnimation();
      }

      return true;
   }

   public boolean handle(BumpEventTemp var1) {
      if (this.enabled && this.trigger.equals("bump")) {
         this.startAnimation();
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new ClassProperty(this, var1, "Animation");
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
               var5 = StringPropertyEditor.make(new Property(this, var1, "Frame List"));
            } else if (var3 == 1) {
               var5 = new String(this.frameList);
            } else if (var3 == 2) {
               this.frameList = ((String)var4).toString().trim().toLowerCase();
               this.preprocessFrameList(this.frameList);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 6, var3, var4);
      }

      if (var3 == 2 && this.trigger.equals("none")) {
         this.startAnimation();
      }

      return var5;
   }

   public String toString() {
      return "Animation: cycleTime "
         + this.cycleTime
         + ", cycles "
         + this.cycles
         + ", enabled "
         + this.enabled
         + ", trigger "
         + this.trigger
         + ", externalTriggerTag "
         + this.externalTriggerTag
         + ", frameList "
         + this.frameList;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveFloat(this.cycleTime);
      var1.saveInt(this.cycles);
      var1.saveString(this.trigger);
      var1.saveString(this.externalTriggerTag);
      var1.saveString(this.frameList);
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
      if (!this.trigger.equals("none")) {
         this.cycleNo = this.cycles;
      } else {
         this.startAnimation();
      }

      this.frameList = var1.restoreString();
      this.preprocessFrameList(this.frameList);
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
      Console.println(MessageFormat.format(Console.message("Animation-obs"), var7));
   }
}
