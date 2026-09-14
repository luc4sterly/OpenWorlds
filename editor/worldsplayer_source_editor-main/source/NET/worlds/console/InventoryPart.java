package NET.worlds.console;

import NET.worlds.scape.FrameEvent;
import java.awt.Container;
import java.awt.Event;
import java.awt.MenuItem;

public class InventoryPart implements FramePart {
   MenuItem inventoryItem;

   public void activate(Console var1, Container var2, Console var3) {
      this.inventoryItem = var1.addMenuItem(Console.message("Inventory") + "...", "File");
   }

   public void deactivate() {
      this.inventoryItem = null;
   }

   public boolean handle(FrameEvent var1) {
      return true;
   }

   public boolean action(Event var1, Object var2) {
      return false;
   }
}
