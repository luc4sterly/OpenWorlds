package NET.worlds.scape;

import java.io.IOException;

public class DiffRoomSensor extends Sensor implements FrameHandler {
   private Room lastCamRoom;
   private static Object classCookie = new Object();

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
         if (var5 != var4 && this.lastCamRoom == var4) {
            this.trigger(var1);
         }

         this.lastCamRoom = var5;
         return true;
      } else {
         return true;
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
