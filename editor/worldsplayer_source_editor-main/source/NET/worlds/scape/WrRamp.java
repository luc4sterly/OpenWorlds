package NET.worlds.scape;

import java.io.IOException;

public class WrRamp extends Room {
   private static final float epsilon = 0.01F;
   public Portal portal1;
   public Portal portal2;
   private float dzByLength;

   public WrRamp(
      World var1,
      String var2,
      float var3,
      float var4,
      float var5,
      float var6,
      float var7,
      float var8,
      float var9,
      float var10,
      float var11,
      float var12,
      float var13,
      float var14,
      float var15,
      float var16,
      Material var17,
      Material var18,
      Material var19,
      Material var20,
      Material var21,
      Material var22
   ) {
      super(var1, var2);
      if (var5 > var4) {
         System.out.println("WrRamp: portal too wide; reducing.");
         var5 = var4;
      }

      if (var3 < 0.0F) {
         System.out.println("WrRamp: length must be positive; inverting.");
         var3 = -var3;
      }

      if (var4 < 0.0F) {
         System.out.println("WrRamp: width must be positive; inverting.");
         var4 = -var4;
      }

      if (var5 < 0.0F) {
         System.out.println("WrRamp: portal width must be positive; inverting.");
         var5 = -var5;
      }

      if (var6 < 0.0F) {
         System.out.println("WrRamp: portal height must be positive; inverting.");
         var6 = -var6;
      }

      if (var8 < 0.0F) {
         System.out.println("WrRamp: lintel height must be positive; ignoring.");
         var8 = 0.0F;
      }

      if (var9 < 10.0F) {
         System.out.println("WrRamp: floor tile width must be at least 10; fixing.");
         var9 = 10.0F;
      }

      if (var10 < 10.0F) {
         System.out.println("WrRamp: floor tile length must be at least 10; fixing.");
         var10 = 10.0F;
      }

      if (var11 < 10.0F) {
         System.out.println("WrRamp: ceiling tile width must be at least 10; fixing.");
         var11 = 10.0F;
      }

      if (var12 < 10.0F) {
         System.out.println("WrRamp: ceiling tile length must be at least 10; fixing.");
         var12 = 10.0F;
      }

      if (var13 < 10.0F) {
         System.out.println("WrRamp: lWall tile width must be at least 10; fixing.");
         var13 = 10.0F;
      }

      if (var14 < 10.0F) {
         System.out.println("WrRamp: lWall tile length must be at least 10; fixing.");
         var14 = 10.0F;
      }

      if (var15 < 10.0F) {
         System.out.println("WrRamp: rWall tile width must be at least 10; fixing.");
         var15 = 10.0F;
      }

      if (var16 < 10.0F) {
         System.out.println("WrRamp: rWall tile length must be at least 10; fixing.");
         var16 = 10.0F;
      }

      RoomEnvironment var23 = this.getEnvironment();
      float var24 = (var4 - var5) / 2.0F;
      this.dzByLength = var7 / var3;
      float var25 = var6 + var8;
      float var26 = var7 + var25;
      this.portal1 = new Portal(var4 - var24, 0.0F, 0.0F, var24, 0.0F, var6);
      this.portal2 = new Portal(var24, var3, var7, var4 - var24, var3, var7 + var6);
      var23.add(this.portal1);
      var23.add(this.portal2);
      float[] var27 = new float[]{
         0.0F, 0.0F, 0.0F, 0.0F, 0.0F, var4, 0.0F, 0.0F, var4 / var9, 0.0F, var4, var3, var7, var4 / var9, var3 / var10, 0.0F, var3, var7, 0.0F, var3 / var10
      };
      var23.add(new Polygon(var27, var17));
      if (var8 > 0.0F) {
         var23.add(new Rect(var4, 0.0F, var6, 0.0F, 0.0F, var25, var21));
         var23.add(new Rect(0.0F, var3, var7 + var6, var4, var3, var26, var21));
      }

      if (var4 > var5) {
         var23.add(new Rect(var4, 0.0F, 0.0F, var4 - var24, 0.0F, var6, var20));
         var23.add(new Rect(var24, 0.0F, 0.0F, 0.0F, 0.0F, var6, var20));
         var23.add(new Rect(0.0F, var3, var7, var24, var3, var7 + var6, var20));
         var23.add(new Rect(var4 - var24, var3, var7, var4, var3, var7 + var6, var20));
      }

      float[] var28 = new float[]{
         0.0F,
         0.0F,
         var25,
         0.0F,
         0.0F,
         0.0F,
         var3,
         var26,
         0.0F,
         var3 / var12,
         var4,
         var3,
         var26,
         var4 / var11,
         var3 / var12,
         var4,
         0.0F,
         var25,
         var4 / var11,
         0.0F
      };
      var23.add(new Polygon(var28, var22));
      float var29 = Math.min(var7, 0.0F);
      float var30 = Math.max(var25, var26);
      var23.add(new Rect(-0.01F, 0.0F, var29, -0.01F, var3, var30, var18));
      var23.add(new Rect(var4 + 0.01F, var3, var29, var4 + 0.01F, 0.0F, var30, var19));
   }

   public WrRamp() {
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
