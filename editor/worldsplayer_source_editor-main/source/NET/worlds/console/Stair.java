package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.scape.Material;
import NET.worlds.scape.NoSuchPropertyException;
import NET.worlds.scape.Point3;
import NET.worlds.scape.Point3Temp;
import NET.worlds.scape.Portal;
import NET.worlds.scape.Property;
import NET.worlds.scape.Rect;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Room;
import NET.worlds.scape.RoomEnvironment;
import NET.worlds.scape.Saver;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.World;
import java.io.IOException;

public class Stair extends Room {
   public Portal bottom;
   public Portal top;
   private int _lengthwise;
   static final int PLUSX = 0;
   static final int PLUSY = 1;
   static final int MINUSX = 2;
   static final int MINUSY = 3;
   private float _length;
   private float _width;
   private float _rise;
   private static Object classCookie = new Object();

   public Stair(
      World var1,
      String var2,
      float var3,
      float var4,
      float var5,
      float var6,
      int var7,
      Material var8,
      Material var9,
      Material var10,
      Material var11,
      Material var12,
      Material var13
   ) {
      super(var1, var2);
      this._lengthwise = 1;
      this._length = var4;
      this._width = var3;
      this._rise = var5;
      RoomEnvironment var14 = this.getEnvironment();
      var14.add(Rect.ceiling(0.0F, 0.0F, var6, var3, var4, var13));
      float var15 = var6 - var5;
      var14.add(new Rect(-0.1F, 0.0F, 0.0F, -0.1F, var4, var6, var10));
      var14.add(new Rect(var3 + 0.1F, var4, 0.0F, var3 + 0.1F, 0.0F, var6, var11));
      var14.add(new Rect(var3, 0.0F, var15, 0.0F, 0.0F, var6, var12));
      this.bottom = new Portal(var3, 0.0F, 0.0F, 0.0F, 0.0F, var15);
      this.top = new Portal(0.0F, var4, var5, var3, var4, var6);
      float var16 = var4 / var7;
      float var17 = var5 / var7;

      for (int var18 = 0; var18 < var7; var18++) {
         Rect var19 = new Rect(0.0F, var18 * var16, var18 * var17, var3, var18 * var16, (var18 + 1) * var17, var8);
         var19.setTileSize(var17, var17);
         var14.add(var19);
      }

      for (int var20 = 0; var20 < var7; var20++) {
         Rect var21 = Rect.floor(0.0F, var20 * var16, (var20 + 1) * var17, var3, (var20 + 1) * var16, var9);
         var21.setTileSize(var16, var16);
         var14.add(var21);
      }

      var14.add(this.bottom);
      var14.add(this.top);
   }

   public Stair() {
   }

   void setLength(float var1) {
      this._length = var1;
   }

   void setRise(float var1) {
      this._rise = var1;
   }

   void setLengthwise(int var1) {
      this._lengthwise = var1;
   }

   public float floorHeight(float var1, float var2, float var3) {
      float var4 = 0.0F;
      switch (this._lengthwise) {
         case 0:
            var4 = var1;
            break;
         case 1:
            var4 = var2;
            break;
         case 2:
            var4 = this._length - var1;
            break;
         case 3:
            var4 = this._length - var2;
            break;
         default:
            Debug.assert_(false);
      }

      return var4 / this._length * this._rise;
   }

   public Point3 surfaceNormal(float var1, float var2) {
      Point3 var3 = new Point3(this._width, 0.0F, 0.0F);
      Point3Temp var4 = Point3Temp.make(0.0F, this._length, this._rise);
      var3.cross(var4);
      var3.normalize();
      return var3;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveFloat(this._length);
      var1.saveFloat(this._rise);
      var1.saveInt(this._lengthwise);
      var1.save(this.bottom);
      var1.save(this.top);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this._length = var1.restoreFloat();
            this._rise = var1.restoreFloat();
            this.bottom = (Portal)var1.restore();
            this.top = (Portal)var1.restore();
            this.setLengthwise(1);
            break;
         case 1:
            super.restoreState(var1);
            this._length = var1.restoreFloat();
            this._rise = var1.restoreFloat();
            this._lengthwise = var1.restoreInt();
            this.bottom = (Portal)var1.restore();
            this.top = (Portal)var1.restore();
            break;
         default:
            throw new TooNewException();
      }
   }

   void superRestoreState(Restorer var1) throws IOException, TooNewException {
      super.restoreState(var1);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Length");
            } else if (var3 == 1) {
               var5 = new Float(this._length);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Rise");
            } else if (var3 == 1) {
               var5 = new Float(this._rise);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Direction");
            } else if (var3 == 1) {
               var5 = new Integer(this._lengthwise);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 3, var3, var4);
      }

      return var5;
   }
}
