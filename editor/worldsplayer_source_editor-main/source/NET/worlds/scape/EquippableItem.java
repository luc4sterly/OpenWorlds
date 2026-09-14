package NET.worlds.scape;

public class EquippableItem extends InventoryItem {
   private String modelLocation_;
   private float xPos_;
   private float yPos_;
   private float zPos_;
   private float scale_;
   private int pitch_;
   private int roll_;
   private int yaw_;
   private Shape shape_;
   private int bodyLocation_;

   public EquippableItem(String var1, String var2, int var3, String var4, float var5, int var6) {
      super(var1, var2, var3);
      this.modelLocation_ = var4;
      this.scale_ = var5;
      this.bodyLocation_ = var6;
      this.shape_ = null;
   }

   public EquippableItem(String var1, String var2, int var3, String var4, float var5, int var6, float var7, float var8, float var9) {
      super(var1, var2, var3);
      this.modelLocation_ = var4;
      this.scale_ = var5;
      this.bodyLocation_ = var6;
      this.xPos_ = var7;
      this.yPos_ = var8;
      this.zPos_ = var9;
      this.shape_ = null;
   }

   public EquippableItem(
      String var1, String var2, int var3, String var4, float var5, int var6, float var7, float var8, float var9, int var10, int var11, int var12
   ) {
      super(var1, var2, var3);
      this.modelLocation_ = var4;
      this.scale_ = var5;
      this.bodyLocation_ = var6;
      this.xPos_ = var7;
      this.yPos_ = var8;
      this.zPos_ = var9;
      this.pitch_ = var10;
      this.roll_ = var11;
      this.yaw_ = var12;
      this.shape_ = null;
   }

   public EquippableItem(EquippableItem var1) {
      super(var1);
      this.modelLocation_ = var1.modelLocation_;
      this.scale_ = var1.scale_;
      this.bodyLocation_ = var1.bodyLocation_;
      this.xPos_ = var1.xPos_;
      this.yPos_ = var1.yPos_;
      this.zPos_ = var1.zPos_;
      this.pitch_ = var1.pitch_;
      this.roll_ = var1.roll_;
      this.yaw_ = var1.yaw_;
      this.shape_ = null;
   }

   public InventoryItem cloneItem() {
      return new EquippableItem(this);
   }

   public String getModelLocation() {
      return this.modelLocation_;
   }

   public void setModelLocation(String var1) {
      this.modelLocation_ = var1;
   }

   public int getBodyLocation() {
      return this.bodyLocation_;
   }

   public void setBodyLocation(int var1) {
      this.bodyLocation_ = var1;
   }

   public float getScale() {
      return this.scale_;
   }

   public void setScale(float var1) {
      this.scale_ = var1;
   }

   public float getXPos() {
      return this.xPos_;
   }

   public float getYPos() {
      return this.yPos_;
   }

   public float getZPos() {
      return this.zPos_;
   }

   public void setPosition(float var1, float var2, float var3) {
      this.xPos_ = var1;
      this.yPos_ = var2;
      this.zPos_ = var3;
   }

   public int getPitch() {
      return this.pitch_;
   }

   public int getRoll() {
      return this.roll_;
   }

   public int getYaw() {
      return this.yaw_;
   }

   public void setRotation(int var1, int var2, int var3) {
      this.pitch_ = var1;
      this.roll_ = var2;
      this.yaw_ = var3;
   }

   public void setOwnedShape(Shape var1) {
      this.shape_ = var1;
   }

   public Shape getOwnedShape() {
      return this.shape_;
   }
}
