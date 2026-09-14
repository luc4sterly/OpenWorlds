package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Std;
import java.util.Enumeration;

public class HighJump extends InventoryAction implements MainCallback {
   int start;
   SmoothDriver sd;

   public HighJump(String var1, String var2) {
      super(var1, var2);
   }

   public HighJump(String var1, String var2, int var3) {
      super(var1, var2, var3);
   }

   public HighJump(HighJump var1) {
      super(var1);
   }

   public InventoryItem cloneItem() {
      return new HighJump(this);
   }

   private SmoothDriver findSD(Pilot var1) {
      Enumeration var2 = var1.getHandlers();

      while (var2.hasMoreElements()) {
         Object var3 = var2.nextElement();
         if (var3 instanceof SmoothDriver) {
            return (SmoothDriver)var3;
         }
      }

      return null;
   }

   public boolean doAction() {
      if (this.itemQuantity_ > 0) {
         Pilot var1 = Pilot.getActive();
         if (var1 == null) {
            return false;
         }

         this.sd = this.findSD(var1);
         if (this.sd == null) {
            return false;
         }

         if (this.sd != null) {
            Main.register(this);
            this.start = Std.getRealTime();
            this.itemQuantity_--;
         }

         return true;
      } else {
         return false;
      }
   }

   public void mainCallback() {
      int var1 = Std.getFastTime();
      if (var1 > this.start + 6000) {
         Main.unregister(this);
         this.sd.setEyeHeight(150.0F);
      } else {
         float var2 = 1.0F - (float)Math.pow(1.0F - (var1 - this.start) / 3000.0F, 4.0);
         this.sd.setEyeHeight(150.0F + 150.0F * var2);
      }
   }
}
