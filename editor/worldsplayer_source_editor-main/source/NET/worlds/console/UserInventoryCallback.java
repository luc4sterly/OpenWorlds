package NET.worlds.console;

import NET.worlds.scape.InventoryCallback;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Point3Temp;
import NET.worlds.scape.Room;
import NET.worlds.scape.WObject;

public class UserInventoryCallback implements InventoryCallback {
   UserInventoryCallback() {
   }

   public void droppedInventoryItem(Object var1) {
      WObject var2 = (WObject)var1;
      var2.detach();
      var2.setVisible(true);
      Pilot var3 = Pilot.getActive();
      Room var4 = var3.getRoom();
      Point3Temp var5 = Point3Temp.make(0.0F, 180.0F, 0.0F);
      var5.times(var3);
      var5.z = var2.getZ() + var3.getZ();
      var2.moveTo(var5);
      var4.add(var2);
   }
}
