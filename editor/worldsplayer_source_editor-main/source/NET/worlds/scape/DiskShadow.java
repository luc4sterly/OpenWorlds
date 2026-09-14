package NET.worlds.scape;

import java.awt.Color;

public class DiskShadow extends Polygon implements NonPersister, Shadow {
   private static int numSides = 8;
   private static float[] diskVertices = new float[5 * numSides];

   public DiskShadow(WObject var1) {
      super(diskVertices, new Material(0.0F, 0.0F, 0.0F, Color.black, null, 0.5F, false, false));
      this.setBumpable(false);
      this.adjustShadow(var1);
   }

   public void adjustShadow(WObject var1) {
      Room var2 = var1.getRoom();
      if (var1.getVisible() && var2 != null) {
         float var3 = 0.0F;
         float var4 = var1.getMinXYExtent();
         BoundBoxTemp var5 = var1.getBoundBox();
         if (!(var4 <= 0.0F) && !(var4 > 10000.0F) && !(var5.hi.z < 0.0F) && !(var5.lo.z >= 250.0F)) {
            float var6 = 1.0F;
            if (var5.lo.z > 0.0F) {
               var6 = 1.0F - var5.lo.z / 250.0F;
            }

            if (this.getOwner() == null && var2 != null) {
               var2.getEnvironment().add(this);
            }

            Point3Temp var7 = var1.getWorldPosition();
            this.moveTo(var7.x, var7.y, var2.floorHeight(var7.x, var7.y, var7.z) + 0.5F);
            this.yaw(this.getYaw() - var1.getYaw());
            this.scale(var4 * var6 / this.getScaleX());
         } else {
            this.detach();
         }
      } else {
         this.detach();
      }
   }

   static {
      float var0 = 0.5F;
      int var1 = 5 * numSides;
      double var2 = 0.0;
      double var4 = (float)((Math.PI * 2) / numSides);

      for (byte var6 = 0; var6 < var1; var2 += var4) {
         float var7 = (float)Math.cos(var2);
         float var8 = (float)Math.sin(var2);
         diskVertices[var6 + 0] = var0 * var7;
         diskVertices[var6 + 1] = var0 * var8;
         diskVertices[var6 + 2] = 0.0F;
         diskVertices[var6 + 3] = 0.5F + 0.5F * var7;
         diskVertices[var6 + 4] = 0.5F + 0.5F * var8;
         var6 += 5;
      }
   }
}
