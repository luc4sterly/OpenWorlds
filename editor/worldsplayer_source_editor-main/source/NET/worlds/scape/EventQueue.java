package NET.worlds.scape;

import NET.worlds.core.Std;

public class EventQueue {
   private static final int keyDown = 1;
   private static final int keyUp = 2;
   private static final int keyChar = 3;
   private static final int mouseDown = 4;
   private static final int mouseUp = 5;
   private static final int mouseMove = 6;
   private static final int mouseDelta = 7;
   private static final int mouseEnter = 8;
   private static final int mouseExit = 9;
   private static final int teleport = 10;
   private char key;
   private int type;
   private int time;
   private int x;
   private int y;
   private static EventQueue dequeueInfo = new EventQueue();

   public static void pollForEvents(Camera var0) {
      if (var0 != null) {
         int var2 = getEventCount();

         Event var1;
         while (var2-- > 0 && (var1 = dequeueInfo.dequeue()) != null) {
            if (var1.target == null) {
               var1.target = var0;
            }

            var0.deliver(var1);
         }
      }
   }

   public static boolean redirectDrivingKeys(java.awt.Event var0) {
      boolean var1;
      if (!(var1 = var0.id == 403) && var0.id != 404) {
         return false;
      }

      char var2;
      switch (var0.key) {
         case 27:
            var2 = '\ue31b';
            break;
         case 1000:
            var2 = '\ue324';
            break;
         case 1001:
            var2 = '\ue323';
            break;
         case 1002:
            var2 = '\ue321';
            break;
         case 1003:
            var2 = '\ue322';
            break;
         case 1004:
            var2 = '\ue326';
            break;
         case 1005:
            var2 = '\ue328';
            break;
         case 1006:
            var2 = '\ue325';
            break;
         case 1007:
            var2 = '\ue327';
            break;
         default:
            return false;
      }

      addEvent(var2, var1 ? 1 : 2, Std.getTimeZero() + Std.getRealTime(), var0.x, var0.y);
      return true;
   }

   private EventQueue() {
   }

   private Event dequeue() {
      if (this.getNextEvent()) {
         this.time = this.time - Std.getTimeZero();
         switch (this.type) {
            case 1:
               return new KeyDownEvent(this.time, null, this.key);
            case 2:
               return new KeyUpEvent(this.time, null, this.key);
            case 3:
               return new KeyCharEvent(this.time, null, this.key);
            case 4:
               return new MouseDownEvent(this.time, null, this.key, this.x, this.y);
            case 5:
               return new MouseUpEvent(this.time, null, this.key, this.x, this.y);
            case 6:
               return new MouseMoveEvent(this.time, null, this.x, this.y);
            case 7:
               return new MouseDeltaEvent(this.time, null, this.x, this.y);
            case 8:
               return new MouseEnterEvent(this.time, null, this.x, this.y);
            case 9:
               return new MouseExitEvent(this.time, null, this.x, this.y);
            default:
               throw new Error("Illegal internal event type");
         }
      } else {
         return null;
      }
   }

   public static native void nativeInit();

   private native boolean getNextEvent();

   private static native int getEventCount();

   private static native void addEvent(char var0, int var1, int var2, int var3, int var4);

   static {
      nativeInit();
   }
}
