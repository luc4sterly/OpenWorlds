package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.FrameHandler;
import NET.worlds.scape.Material;
import NET.worlds.scape.Point3;
import NET.worlds.scape.Point3Temp;
import NET.worlds.scape.Portal;
import NET.worlds.scape.Rect;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Room;
import NET.worlds.scape.RoomEnvironment;
import NET.worlds.scape.Saver;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.WObject;
import NET.worlds.scape.World;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class Staircase extends Room implements FrameHandler {
   public Portal bottom;
   public Portal top;
   private float dzdx;
   private float dzdy;
   private Vector seenThings = new Vector();
   private Vector seenStarts = new Vector();
   private static Object classCookie = new Object();

   public Staircase(
      World var1,
      String var2,
      float var3,
      float var4,
      float var5,
      float var6,
      float var7,
      float var8,
      float var9,
      int var10,
      Material var11,
      Material var12,
      Material var13,
      Material var14,
      Material var15,
      Material var16
   ) {
      super(var1, var2);
      float var17 = (var6 - var3) / var10;
      float var18 = (var7 - var4) / var10;
      float var19 = (var8 - var5) / var10;
      this.dzdx = var19 / var17;
      this.dzdy = var19 / var18;
      Debug.assert_(var19 >= 0.0F);
      float var20 = var5 + var9 - var8;
      RoomEnvironment var21 = this.getEnvironment();
      var21.add(Rect.ceiling(var3, var4, var9, var6, var7, var16));
      if (var17 > 0.0F) {
         if (var18 > 0.0F) {
            var21.add(new Rect(var3 - 0.1F, var4, var5, var3 - 0.1F, var7, var9, var13));
            var21.add(new Rect(var6 + 0.1F, var7, var5, var6 + 0.1F, var4, var9, var14));
            var21.add(new Rect(var6, var4, var20, var3, var4, var9, var15));
            this.bottom = new Portal(var6, var4, var5, var3, var4, var20);
            this.top = new Portal(var3, var7, var8, var6, var7, var9);

            for (int var22 = 0; var22 < var10; var22++) {
               Rect var23 = new Rect(var3, var4 + var22 * var18, var5 + var22 * var19, var6, var4 + var22 * var18, var5 + (var22 + 1) * var19, var11);
               var23.setTileSize(var19, var19);
               var21.add(var23);
            }

            for (int var24 = 0; var24 < var10; var24++) {
               Rect var31 = Rect.floor(var3, var4 + var24 * var18, var5 + (var24 + 1) * var19, var6, var4 + (var24 + 1) * var18, var12);
               var31.setTileSize(Math.abs(var18), Math.abs(var18));
               var21.add(var31);
            }

            this.dzdx = 0.0F;
         } else {
            var21.add(new Rect(var3, var4 - 0.1F, var5, var6, var4 - 0.1F, var9, var13));
            var21.add(new Rect(var6, var7 + 0.1F, var5, var3, var7 + 0.1F, var9, var14));
            var21.add(new Rect(var3, var7, var20, var3, var4, var9, var15));
            this.bottom = new Portal(var3, var7, var5, var3, var4, var20);
            this.top = new Portal(var6, var4, var8, var6, var7, var9);

            for (int var25 = 0; var25 < var10; var25++) {
               Rect var32 = new Rect(var3 + var25 * var17, var4, var5 + var25 * var19, var3 + var25 * var17, var7, var5 + (var25 + 1) * var19, var11);
               var32.setTileSize(var19, var19);
               var21.add(var32);
            }

            for (int var26 = 0; var26 < var10; var26++) {
               Rect var33 = Rect.floor(var3 + var26 * var17, var7, var5 + (var26 + 1) * var19, var3 + (var26 + 1) * var17, var4, var12);
               var33.setTileSize(Math.abs(var17), Math.abs(var17));
               var21.add(var33);
            }

            this.dzdy = 0.0F;
         }
      } else if (var18 > 0.0F) {
         var21.add(new Rect(var3, var4 - 0.1F, var5, var6, var4 - 0.1F, var9, var13));
         var21.add(new Rect(var6, var7 + 0.1F, var5, var3, var7 + 0.1F, var9, var14));
         var21.add(new Rect(var3, var7, var20, var3, var4, var9, var15));
         this.bottom = new Portal(var3, var7, var5, var3, var4, var20);
         this.top = new Portal(var6, var4, var8, var6, var7, var9);

         for (int var27 = 0; var27 < var10; var27++) {
            Rect var34 = new Rect(var3 + var27 * var17, var4, var5 + var27 * var19, var3 + var27 * var17, var7, var5 + (var27 + 1) * var19, var11);
            var34.setTileSize(var19, var19);
            var21.add(var34);
         }

         for (int var28 = 0; var28 < var10; var28++) {
            Rect var35 = Rect.floor(var3 + (var28 + 1) * var17, var4, var5 + (var28 + 1) * var19, var3 + var28 * var17, var7, var12);
            var35.setTileSize(Math.abs(var17), Math.abs(var17));
            var21.add(var35);
         }

         this.dzdy = 0.0F;
      } else {
         var21.add(new Rect(var3 + 0.1F, var4, var5, var3 + 0.1F, var7, var9, var13));
         var21.add(new Rect(var6 - 0.1F, var7, var5, var6 - 0.1F, var4, var9, var14));
         var21.add(new Rect(var6, var4, var20, var3, var4, var9, var15));
         this.bottom = new Portal(var6, var4, var5, var3, var4, var20);
         this.top = new Portal(var3, var7, var8, var6, var7, var9);

         for (int var29 = 0; var29 < var10; var29++) {
            Rect var36 = new Rect(var3, var4 + var29 * var18, var5 + var29 * var19, var6, var4 + var29 * var18, var5 + (var29 + 1) * var19, var11);
            var36.setTileSize(var19, var19);
            var21.add(var36);
         }

         for (int var30 = 0; var30 < var10; var30++) {
            Rect var37 = Rect.floor(var6, var4 + (var30 + 1) * var18, var5 + (var30 + 1) * var19, var3, var4 + var30 * var18, var12);
            var37.setTileSize(Math.abs(var18), Math.abs(var18));
            var21.add(var37);
         }

         this.dzdx = 0.0F;
      }

      var21.add(this.bottom);
      var21.add(this.top);
   }

   public Staircase() {
   }

   public boolean handle(FrameEvent var1) {
      Enumeration var2 = this.getContents();

      while (var2.hasMoreElements()) {
         WObject var3 = (WObject)var2.nextElement();
         int var4 = this.seenThings.indexOf(var3);
         if (var4 == -1) {
            this.seenThings.addElement(var3);
            Point3Temp var5 = var3.getPosition();
            Point3Temp var6 = Point3Temp.make(this.top.getScaleX(), 0.0F, this.top.getScaleZ()).times(0.5F).times(this.top.getObjectToWorldMatrix());
            Point3Temp var7 = Point3Temp.make(this.bottom.getScaleX(), 0.0F, this.bottom.getScaleZ()).times(0.5F).times(this.bottom.getObjectToWorldMatrix());
            if (var6.x == var7.x) {
               float var8 = (var5.y - var7.y) / (var6.y - var7.y);
               if (var8 < 0.5F) {
                  var5.y = var7.y;
               } else {
                  var5.y = var6.y;
               }

               this.dzdx = 0.0F;
            } else if (var6.y == var7.y) {
               float var11 = (var5.x - var7.x) / (var6.x - var7.x);
               if (var11 < 0.5F) {
                  var5.x = var7.x;
               } else {
                  var5.x = var6.x;
               }

               this.dzdy = 0.0F;
            } else {
               Debug.assert_(false);
            }

            this.seenStarts.addElement(new Point3(var5));
            var4 = this.seenThings.size() - 1;
            Debug.assert_(var4 == this.seenStarts.size() - 1);
         }

         Point3Temp var9 = (Point3Temp)this.seenStarts.elementAt(var4);
         float var10 = this.dzdx * (var3.getX() - var9.x) + this.dzdy * (var3.getY() - var9.y) + var9.z - var3.getZ();
         if (var10 != 0.0F) {
            var3.raise(var10);
         }
      }

      return true;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.dzdx);
      var1.saveFloat(this.dzdy);
      var1.save(this.bottom);
      var1.save(this.top);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      Stair var2 = new Stair();
      var1.replace(this, var2);
      int var3 = var1.restoreVersion(classCookie);
      if (var3 != 0) {
         throw new TooNewException();
      }

      var2.superRestoreState(var1);
      float var4 = var1.restoreFloat();
      float var5 = var1.restoreFloat();
      var2.bottom = (Portal)var1.restore();
      var2.top = (Portal)var1.restore();
      Point3Temp var6 = var2.top.getPosition();
      Point3Temp var7 = var2.bottom.getPosition();
      var2.setRise(var6.z - var7.z);
      if (var4 == 0.0F) {
         if (var5 > 0.0F) {
            var2.setLengthwise(1);
            var2.setLength(var6.y - var7.y);
         } else {
            var2.setLengthwise(3);
            var2.setLength(var7.y - var6.y);
         }
      } else {
         Debug.assert_(var5 == 0.0F);
         if (var4 > 0.0F) {
            var2.setLengthwise(0);
            var2.setLength(var6.x - var7.x);
         } else {
            var2.setLengthwise(2);
            var2.setLength(var7.x - var6.x);
         }
      }
   }
}
