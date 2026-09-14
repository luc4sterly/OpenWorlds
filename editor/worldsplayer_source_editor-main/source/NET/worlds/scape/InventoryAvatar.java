package NET.worlds.scape;

public class InventoryAvatar extends InventoryItem {
   public InventoryAvatar(String var1, String var2) {
      super(var1, var2);
   }

   public InventoryAvatar(String var1, String var2, int var3) {
      super(var1, var2, var3);
   }

   public InventoryAvatar(InventoryAvatar var1) {
      super(var1);
   }

   public InventoryItem cloneItem() {
      return new InventoryAvatar(this);
   }
}
