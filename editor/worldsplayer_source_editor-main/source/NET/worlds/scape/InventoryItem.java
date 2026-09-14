package NET.worlds.scape;

import NET.worlds.network.URL;

public class InventoryItem {
   protected String itemId_;
   protected String itemName_;
   protected int itemQuantity_;
   protected URL itemGraphicLocation_;

   public InventoryItem(String var1, String var2) {
      this.itemId_ = var1;
      this.itemName_ = var2;
      this.itemQuantity_ = 1;
   }

   public InventoryItem(String var1, String var2, int var3) {
      this.itemId_ = var1;
      this.itemName_ = var2;
      this.itemQuantity_ = var3;
   }

   public InventoryItem(InventoryItem var1) {
      this.itemId_ = var1.itemId_;
      this.itemName_ = var1.itemName_;
      this.itemQuantity_ = var1.itemQuantity_;
      this.itemGraphicLocation_ = var1.itemGraphicLocation_;
   }

   public String getItemId() {
      return this.itemId_;
   }

   public void setItemId(String var1) {
      this.itemId_ = var1;
   }

   public String getItemName() {
      return this.itemName_;
   }

   public void setItemName(String var1) {
      this.itemName_ = var1;
   }

   public int getItemQuantity() {
      return this.itemQuantity_;
   }

   public void setQuantity(int var1) {
      this.itemQuantity_ = var1;
   }

   public URL getItemGraphicLocation() {
      return this.itemGraphicLocation_;
   }

   public void setItemGraphicLocation(URL var1) {
      this.itemGraphicLocation_ = var1;
   }

   public InventoryItem cloneItem() {
      return new InventoryItem(this);
   }
}
