package NET.worlds.scape;

import NET.worlds.console.Console;
import java.io.IOException;
import java.text.MessageFormat;

public class Toggle extends TriggeredSwitchableBehavior implements Persister, FrameHandler, MouseDownHandler, BumpHandler {
   protected boolean toggleBumpable;
   protected boolean toggleVisible;
   protected WObject o;
   protected boolean initialized = false;

   public Toggle() {
      this.trigger = new String("none");
      this.externalTriggerTag = new String("");
      this.toggleBumpable = true;
      this.toggleVisible = true;
   }

   public void ExternalTrigger(Trigger var1, int var2, int var3) {
      this.trigger_source = var1;
      this.sequence_no = var2;
      this.event_no = var3;
      this.toggle();
   }

   public void toggle() {
      if (this.toggleBumpable) {
         this.o.setBumpable(true);
      } else {
         this.o.setBumpable(false);
      }

      if (this.toggleVisible) {
         this.o.setVisible(true);
      } else {
         this.o.setVisible(false);
      }

      if (this.trigger_source != null) {
         this.trigger_source.registerFinishedTriggerTag(this.sequence_no, this.event_no);
      }
   }

   public boolean handle(FrameEvent var1) {
      if (!this.initialized) {
         this.o = var1.receiver;
         this.initialized = true;
      }

      return true;
   }

   public boolean handle(MouseDownEvent var1) {
      if (this.enabled && this.trigger.equals("click")) {
         this.toggle();
      }

      return true;
   }

   public boolean handle(BumpEventTemp var1) {
      if (this.enabled && this.trigger.equals("bump")) {
         this.toggle();
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
               if (this.trigger.equals("external")) {
                  Trigger.TriggeredSwitchableBehaviorList[Trigger.TriggeredSwitchableBehaviorListCount] = this;
                  Trigger.TriggeredSwitchableBehaviorListCount++;
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "External Trigger Tag"));
            } else if (var3 == 1) {
               var5 = new String(this.externalTriggerTag);
            } else if (var3 == 2) {
               this.externalTriggerTag = ((String)var4).toString().trim();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Toggle Bumpable"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.toggleBumpable);
            } else if (var3 == 2) {
               this.toggleBumpable = (Boolean)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Toggle Visible"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.toggleVisible);
            } else if (var3 == 2) {
               this.toggleVisible = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 4, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "[" + " enabled " + this.enabled + ", trigger " + this.trigger + ", externalTriggerTag " + this.externalTriggerTag + "]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveString(this.trigger);
      var1.saveString(this.externalTriggerTag);
      var1.saveBoolean(this.toggleBumpable);
      var1.saveBoolean(this.toggleVisible);
   }

   public void restoreState(Restorer var1) throws IOException {
      this.trigger = var1.restoreString();
      if (this.trigger.equals("external")) {
         Trigger.TriggeredSwitchableBehaviorList[Trigger.TriggeredSwitchableBehaviorListCount] = this;
         Trigger.TriggeredSwitchableBehaviorListCount++;
      }

      this.externalTriggerTag = var1.restoreString();
      this.toggleBumpable = var1.restoreBoolean();
      this.toggleVisible = var1.restoreBoolean();
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
      Console.println(MessageFormat.format(Console.message("Toggle-obs"), var7));
   }
}
