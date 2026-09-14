package NET.worlds.scape;

public class InventoryAction extends InventoryItem {
   public InventoryAction(String var1, String var2) {
      super(var1, var2);
   }

   public InventoryAction(String var1, String var2, int var3) {
      super(var1, var2, var3);
   }

   public InventoryAction(InventoryAction var1) {
      super(var1);
   }

   public InventoryItem cloneItem() {
      return new InventoryAction(this);
   }

   public static InventoryAction createAction(String var0, String var1, int var2) {
      return var0.equals("H") ? new HighJump(var0, var1, var2) : new InventoryAction(var0, var1, var2);
   }

   public boolean doAction() {
      return true;
   }
}
