package NET.worlds.scape;

import java.io.IOException;

public class SameRoomSensor extends Sensor implements FrameHandler {
   private Room lastCamRoom;
   private static Object classCookie = new Object();

   public SameRoomSensor(Action var1) {
      if (var1 != null) {
         this.addAction(var1);
      }
   }

   public SameRoomSensor() {
   }

   public void detach() {
      this.lastCamRoom = null;
      super.detach();
   }

   public boolean handle(FrameEvent var1) {
      SuperRoot var2 = this.getOwner();
      if (var2 != null && var2 instanceof WObject) {
         WObject var3 = (WObject)var2;
         Room var4 = var3.getRoom();
         Room var5 = Pilot.getActiveRoom();
         if (var5 == var4 && this.lastCamRoom != var5) {
            this.trigger(var1);
         }

         this.lastCamRoom = var5;
         return true;
      } else {
         return true;
      }
   }

   public void saveState(Saver var1) throws IOException {
      super.saveState(var1);
      var1.saveVersion(0, classCookie);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = super.restoreStateVers(var1);
      if (var2 > 1) {
         switch (var1.restoreVersion(classCookie)) {
            case 0:
               return;
            default:
               throw new TooNewException();
         }
      }
   }
}
