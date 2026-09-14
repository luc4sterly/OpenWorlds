package NET.worlds.scape;

import java.io.IOException;

public class WrStaircase extends Room {
   private static final float epsilon = 0.01F;
   public Portal portal1;
   public Portal portal2;
   private float dzByLength;

   public WrStaircase(
      World var1,
      String var2,
      float var3,
      float var4,
      float var5,
      float var6,
      float var7,
      float var8,
      int var9,
      Material var10,
      Material var11,
      Material var12,
      Material var13,
      Material var14,
      Material var15,
      Material var16
   ) {
      super(var1, var2);
      if (var5 > var4) {
         System.out.println("WrStaircase: portal too wide; reducing.");
         var5 = var4;
      }

      if (var3 < 0.0F) {
         System.out.println("WrStaircase: length must be positive; inverting.");
         var3 = -var3;
      }

      if (var4 < 0.0F) {
         System.out.println("WrStaircase: width must be positive; inverting.");
         var4 = -var4;
      }

      if (var5 < 0.0F) {
         System.out.println("WrStaircase: portal width must be positive; inverting.");
         var5 = -var5;
      }

      if (var6 < 0.0F) {
         System.out.println("WrStaircase: portal height must be positive; inverting.");
         var6 = -var6;
      }

      if (var8 < 0.0F) {
         System.out.println("WrStaircase: lintel height must be positive; ignoring.");
         var8 = 0.0F;
      }

      if (var9 < 2) {
         System.out.println("WrStaircase: must have at least 2 steps.");
         var9 = 2;
      }

      RoomEnvironment var17 = this.getEnvironment();
      float var18 = (var4 - var5) / 2.0F;
      float var19 = Math.min(var7, 0.0F);
      float var20 = Math.max(var7, 0.0F) + var6 + var8;
      this.dzByLength = var7 / var3;
      this.portal1 = new Portal(var4 - var18, 0.0F, 0.0F, var18, 0.0F, var6);
      this.portal2 = new Portal(var18, var3, var7, var4 - var18, var3, var7 + var6);
      var17.add(this.portal1);
      var17.add(this.portal2);
      float var21 = var3 / var9;
      float var22 = var7 / var9;

      for (int var23 = 1; var23 <= var9; var23++) {
         Rect var24 = new Rect(0.0F, var23 * var21, (var23 - 1) * var22, var4, var23 * var21, var23 * var22 - 0.01F, var10);
         var24.setTileSize(var22, var22);
         var17.add(var24);
      }

      for (int var25 = 0; var25 < var9; var25++) {
         Rect var26 = Rect.floor(0.0F, var25 * var21, var25 * var22, var4, (var25 + 1) * var21 - 0.01F, var11);
         var26.setTileSize(Math.abs(var21), Math.abs(var21));
         var17.add(var26);
      }

      if (var20 > var6) {
         var17.add(new Rect(var4, 0.0F, var6, 0.0F, 0.0F, var20 - 0.01F, var15));
      }

      if (var20 > var7 + var6) {
         var17.add(new Rect(0.0F, var3, var7 + var6, var4, var3, var20 - 0.01F, var15));
      }

      if (var4 > var5) {
         var17.add(new Rect(var4, 0.0F, 0.0F, var4 - var18, 0.0F, var6, var14));
         var17.add(new Rect(var18, 0.0F, 0.0F, 0.0F, 0.0F, var6, var14));
         var17.add(new Rect(0.0F, var3, var7, var18, var3, var7 + var6, var14));
         var17.add(new Rect(var4 - var18, var3, var7, var4, var3, var7 + var6, var14));
      }

      var17.add(Rect.ceiling(0.0F, 0.0F, var20, var4, var3, var16));
      var17.add(new Rect(-0.01F, 0.0F, var19, -0.01F, var3, var20, var12));
      var17.add(new Rect(var4 + 0.01F, var3, var19, var4 + 0.01F, 0.0F, var20, var13));
   }

   public WrStaircase() {
   }

   public float floorHeight(float var1, float var2, float var3) {
      return var2 * this.dzByLength;
   }

   public Point3 surfaceNormal(float var1, float var2, float var3) {
      Point3 var4 = new Point3(1.0F, 0.0F, 0.0F);
      Point3Temp var5 = Point3Temp.make(0.0F, 1.0F, this.dzByLength);
      var4.cross(var5);
      var4.normalize();
      return var4;
   }

   public void saveState(Saver var1) throws IOException {
      super.saveState(var1);
      var1.saveFloat(this.dzByLength);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      super.restoreState(var1);
      this.dzByLength = var1.restoreFloat();
   }
}
