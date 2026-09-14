package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.io.IOException;
import java.text.MessageFormat;

public class sendURL extends TriggeredSwitchableBehavior implements MouseDownHandler, BumpHandler, FrameHandler {
   protected String browser;
   protected String destination;
   protected boolean silentURL;
   protected boolean initialized = false;

   public sendURL() {
      this.trigger = new String("none");
      this.externalTriggerTag = new String("");
      this.silentURL = false;
      this.browser = new String("NETSCAPE");
      this.destination = new String("http://www.worlds.net");
   }

   public static native int init(String var0);

   public static native int get(String var0);

   public static native int silent_get(String var0);

   public void ExternalTrigger(Trigger var1, int var2, int var3) {
      this.sendURLStart();
   }

   public void sendURLStart() {
      if (this.silentURL) {
         silent_get(this.destination);
      } else {
         get(this.destination);
      }
   }

   public boolean handle(FrameEvent var1) {
      if (!this.initialized) {
         init(this.browser);
         this.initialized = true;
      }

      return true;
   }

   public boolean handle(MouseDownEvent var1) {
      if (this.enabled && this.trigger.equals("click")) {
         this.sendURLStart();
      }

      return true;
   }

   public boolean handle(BumpEventTemp var1) {
      if (this.enabled && this.trigger.equals("bump")) {
         this.sendURLStart();
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
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Silent URL"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.silentURL);
            } else if (var3 == 2) {
               this.silentURL = (Boolean)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Destination"));
            } else if (var3 == 1) {
               var5 = new String(this.destination);
            } else if (var3 == 2) {
               this.destination = ((String)var4).toString().trim();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 4, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "[enabled " + this.enabled + ", trigger " + this.trigger + ", externalTriggerTag " + this.externalTriggerTag + "]";
   }

   public void saveState(Saver var1) throws IOException {
      Object[] var2 = new Object[]{new String(this.getName())};
      Console.println(MessageFormat.format(Console.message("sendURL-obs"), var2));
      var1.saveString(this.trigger);
      var1.saveString(this.externalTriggerTag);
      var1.saveBoolean(this.silentURL);
      var1.saveString(this.destination);
   }

   public void restoreState(Restorer var1) throws IOException {
      this.trigger = var1.restoreString();
      this.externalTriggerTag = var1.restoreString();
      this.silentURL = var1.restoreBoolean();
      this.destination = var1.restoreString();
      if (this.trigger.equals("external")) {
         Object[] var2 = new Object[]{new String(this.getName())};
         Console.println(MessageFormat.format(Console.message("sendURL-obs"), var2));
         Trigger.TriggeredSwitchableBehaviorList[Trigger.TriggeredSwitchableBehaviorListCount] = this;
         Trigger.TriggeredSwitchableBehaviorListCount++;
      } else {
         SendURLAction var3 = new SendURLAction();
         if (this.destination != null) {
            var3.setDestination(URL.make(this.destination));
         }

         var3.setTrigger(this.trigger);
         var1.replace(this, var3);
      }
   }
}
