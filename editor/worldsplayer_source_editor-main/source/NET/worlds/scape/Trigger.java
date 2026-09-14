package NET.worlds.scape;

import NET.worlds.console.Console;
import java.io.IOException;
import java.text.MessageFormat;

public class Trigger extends SwitchableBehavior implements FrameHandler, Persister, MouseDownHandler, BumpHandler {
   public static TriggeredSwitchableBehavior[] TriggeredSwitchableBehaviorList = new TriggeredSwitchableBehavior[1000];
   public static int TriggeredSwitchableBehaviorListCount = 0;
   public String trigger = new String("none");
   public String targetTriggerTag = new String("");
   public String[][] targetTriggerTagArray = new String[20][10];
   public int targetTriggerTagCount = 0;
   public int[] finishedTriggerTagSequenceNo = new int[50];
   public int[] finishedTriggerTagEventNo = new int[50];
   public int finishedTriggerTagCount = 0;

   private void addTargetTriggerTagArray(String[] var1, String var2) {
      int var3 = 1;
      int var4 = 0;
      int var5 = 0;
      int var6 = var2.lastIndexOf("+");
      if (var6 == -1 && var2.length() == 0) {
         byte var8 = 0;
         var1[0] = String.valueOf(var8);
      } else if (var6 == -1) {
         var1[var3] = var2;
         var1[0] = String.valueOf(var3);
      } else {
         var5 = var2.indexOf("+");
         var1[var3] = var2.substring(0, var5);
         var3++;

         while (var5 != var6) {
            var4 = var5;
            var5 = var2.indexOf("+", var4 + 1);
            var1[var3] = var2.substring(var4 + 1, var5);
            var3++;
         }

         var1[var3] = var2.substring(var5 + 1);
         var1[0] = String.valueOf(var3);
      }
   }

   public void preprocessTargetTriggerTag(String var1) {
      int var2 = 1;
      int var3 = 0;
      int var4 = 0;
      int var5 = var1.lastIndexOf(" ");
      if (var5 != -1 || var1.length() != 0) {
         if (var5 == -1) {
            this.addTargetTriggerTagArray(this.targetTriggerTagArray[var2], var1);
            this.targetTriggerTagCount = var2;
         } else {
            var4 = var1.indexOf(" ");
            this.addTargetTriggerTagArray(this.targetTriggerTagArray[var2], var1.substring(0, var4));
            var2++;

            while (var4 != var5) {
               var3 = var4;
               var4 = var1.indexOf(" ", var3 + 1);
               this.addTargetTriggerTagArray(this.targetTriggerTagArray[var2], var1.substring(var3 + 1, var4));
               var2++;
            }

            this.addTargetTriggerTagArray(this.targetTriggerTagArray[var2], var1.substring(var4 + 1));
            this.targetTriggerTagCount = var2;
         }
      }
   }

   public void activateTrigger() {
      for (int var3 = 1; var3 <= this.targetTriggerTagCount; var3++) {
         boolean var1 = false;

         for (int var2 = 0; !var1 && var2 < TriggeredSwitchableBehaviorListCount; var2++) {
            if (this.targetTriggerTagArray[var3][1].equals(TriggeredSwitchableBehaviorList[var2].externalTriggerTag)
               && TriggeredSwitchableBehaviorList[var2] != null) {
               TriggeredSwitchableBehaviorList[var2].ExternalTrigger(this, var3, 1);
            }
         }
      }
   }

   public void activateSequenceTrigger() {
      for (int var3 = this.finishedTriggerTagCount; var3 > 0; var3--) {
         int var4 = this.finishedTriggerTagSequenceNo[var3];
         int var5 = this.finishedTriggerTagEventNo[var3];
         if (Integer.valueOf(this.targetTriggerTagArray[var4][0]) > var5) {
            boolean var1 = false;

            for (int var2 = 0; !var1 && var2 < TriggeredSwitchableBehaviorListCount; var2++) {
               if (this.targetTriggerTagArray[var4][var5 + 1].equals(TriggeredSwitchableBehaviorList[var2].externalTriggerTag)
                  && TriggeredSwitchableBehaviorList[var2] != null) {
                  TriggeredSwitchableBehaviorList[var2].ExternalTrigger(this, var4, var5 + 1);
               }
            }
         }
      }

      this.finishedTriggerTagCount = 0;
   }

   public synchronized void registerFinishedTriggerTag(int var1, int var2) {
      this.finishedTriggerTagCount++;
      this.finishedTriggerTagSequenceNo[this.finishedTriggerTagCount] = var1;
      this.finishedTriggerTagEventNo[this.finishedTriggerTagCount] = var2;
   }

   public boolean handle(FrameEvent var1) {
      if (this.enabled && this.finishedTriggerTagCount > 0) {
         this.activateSequenceTrigger();
      }

      return true;
   }

   public boolean handle(MouseDownEvent var1) {
      if (this.enabled && this.trigger.equals("click")) {
         this.activateTrigger();
      }

      return true;
   }

   public boolean handle(BumpEventTemp var1) {
      if (this.enabled && this.trigger.equals("bump")) {
         this.activateTrigger();
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Trigger"));
            } else if (var3 == 1) {
               var5 = new String(this.trigger);
            } else if (var3 == 2) {
               this.trigger = ((String)var4).toString().trim();
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target Trigger Tag"));
            } else if (var3 == 1) {
               var5 = new String(this.targetTriggerTag);
            } else if (var3 == 2) {
               this.targetTriggerTag = ((String)var4).toString().trim();
               this.preprocessTargetTriggerTag(this.targetTriggerTag);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "[enabled " + this.enabled + ", trigger " + this.trigger + ", targetTriggerTag " + this.targetTriggerTag + "]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveString(this.trigger);
      var1.saveString(this.targetTriggerTag);
   }

   public void restoreState(Restorer var1) throws IOException {
      this.trigger = var1.restoreString();
      this.targetTriggerTag = var1.restoreString();
      this.preprocessTargetTriggerTag(this.targetTriggerTag);
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
      Console.println(MessageFormat.format(Console.message("Trigger-obs"), var7));
   }
}
