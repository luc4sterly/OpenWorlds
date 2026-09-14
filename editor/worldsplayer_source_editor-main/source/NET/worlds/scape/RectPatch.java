package NET.worlds.scape;

import java.awt.Color;
import java.io.IOException;

public class RectPatch extends WObject implements FloorPatch {
   public float xDim;
   public float yDim;
   public float[] z = new float[]{0.0F, 0.0F, 0.0F, 0.0F};
   public Material mat;
   public float xTile = 1.0F;
   public float xTileOffset = 0.0F;
   public float yTile = 1.0F;
   public float yTileOffset = 0.0F;
   public Polygon[] t = new Polygon[]{null, null, null, null};
   private static Object classCookie = new Object();

   public RectPatch(float var1, float var2) {
      this.setVisible(true);
      this.setBumpable(false);
      this.xDim = var1;
      this.yDim = var2;
      this.setMaterial(new Material(Color.gray));
   }

   public RectPatch() {
      this.xDim = 1.0F;
      this.yDim = 1.0F;
      this.setMaterial(new Material(Color.gray));
   }

   protected void addRwChildren(WObject var1) {
      if (this.t[0] == null) {
         this.createAppearance();
      }

      super.addRwChildren(var1);
   }

   public void setVisible(boolean var1) {
      super.setVisible(var1);
      this.createAppearance();
   }

   public void setMaterial(Material var1) {
      if (this.mat != null) {
         this.mat.detach();
      }

      this.add(var1);
      this.mat = var1;
      this.createAppearance();
   }

   public Material getMaterial() {
      return this.mat;
   }

   public boolean inPatch(float var1, float var2) {
      Transform var3 = this.getObjectToWorldMatrix().invert();
      Point3Temp var4 = Point3Temp.make(var1, var2, 0.0F).times(var3);
      var3.recycle();
      var1 = var4.x;
      var2 = var4.y;
      return !(var1 < 0.0F) && !(var1 > this.xDim) && !(var2 < 0.0F) && !(var2 > this.yDim);
   }

   public float floorHeight(float var1, float var2) {
      Transform var3 = this.getObjectToWorldMatrix().invert();
      Point3Temp var4 = Point3Temp.make(var1, var2, 0.0F).times(var3);
      var3.recycle();
      var1 = var4.x;
      var2 = var4.y;
      float var5 = var1 / this.xDim;
      float var6 = var2 / this.yDim;
      float var7 = 1.0F - var5;
      float var8 = 1.0F - var6;
      return this.z[0] * var8 * var7 + this.z[1] * var6 * var7 + this.z[2] * var6 * var5 + this.z[3] * var8 * var5;
   }

   public Point3 surfaceNormal(float var1, float var2) {
      Point3 var3 = new Point3(this.xDim, 0.0F, this.z[1] - this.z[0]);
      Point3Temp var4 = Point3Temp.make(0.0F, this.yDim, this.z[3] - this.z[0]);
      var3.cross(var4);
      var3.normalize();
      var3.times(this.getObjectToWorldMatrix());
      return var3;
   }

   private void removeAppearance() {
      for (int var1 = 0; var1 < 4; var1++) {
         if (this.t[var1] != null) {
            this.t[var1].detach();
            this.t[var1] = null;
         }
      }
   }

   public void createAppearance() {
      this.removeAppearance();
      if (this.getVisible()) {
         if (!(this.xDim <= 0.0F) && !(this.yDim <= 0.0F)) {
            if (this.xTile <= 0.0F) {
               this.xTile = 1.0F;
            }

            if (this.xTile > 31.0F) {
               this.xTile = 31.0F;
            }

            if (this.yTile <= 0.0F) {
               this.yTile = 1.0F;
            }

            if (this.yTile > 31.0F) {
               this.yTile = 31.0F;
            }

            if (this.xTileOffset < 0.0F) {
               this.xTileOffset = 1.0F - (float)Math.floor(this.xTileOffset) + this.xTileOffset;
            }

            if (this.yTileOffset < 0.0F) {
               this.yTileOffset = 1.0F - (float)Math.floor(this.yTileOffset) + this.yTileOffset;
            }

            float var1 = this.xDim / 2.0F;
            float var2 = this.yDim / 2.0F;
            float var3 = (this.z[0] + this.z[1] + this.z[2] + this.z[3]) / 4.0F;
            float var4 = this.xTileOffset + this.xTile / 2.0F;
            float var5 = this.yTileOffset + this.yTile / 2.0F;
            this.t[0] = new Polygon(3, this.mat);
            this.t[0].setVertex(0, 0.0F, 0.0F, this.z[0], this.xTileOffset, this.yTileOffset);
            this.t[0].setVertex(1, var1, var2, var3, var4, var5);
            this.t[0].setVertex(2, 0.0F, this.yDim, this.z[1], this.xTileOffset, this.yTileOffset + this.yTile);
            this.add(this.t[0]);
            this.t[1] = new Polygon(3, this.mat);
            this.t[1].setVertex(0, 0.0F, this.yDim, this.z[1], this.xTileOffset, this.yTileOffset + this.yTile);
            this.t[1].setVertex(1, var1, var2, var3, var4, var5);
            this.t[1].setVertex(2, this.xDim, this.yDim, this.z[2], this.xTileOffset + this.xTile, this.yTileOffset + this.yTile);
            this.add(this.t[1]);
            this.t[2] = new Polygon(3, this.mat);
            this.t[2].setVertex(0, this.xDim, this.yDim, this.z[2], this.xTileOffset + this.xTile, this.yTileOffset + this.yTile);
            this.t[2].setVertex(1, var1, var2, var3, var4, var5);
            this.t[2].setVertex(2, this.xDim, 0.0F, this.z[3], this.xTileOffset + this.xTile, this.yTileOffset);
            this.add(this.t[2]);
            this.t[3] = new Polygon(3, this.mat);
            this.t[3].setVertex(0, this.xDim, 0.0F, this.z[3], this.xTileOffset + this.xTile, this.yTileOffset);
            this.t[3].setVertex(1, var1, var2, var3, var4, var5);
            this.t[3].setVertex(2, 0.0F, 0.0F, this.z[0], this.xTileOffset, this.yTileOffset);
            this.add(this.t[3]);
         }
      }
   }

   public void setCornerHeight(int var1, float var2) {
      this.z[var1] = var2;
      this.createAppearance();
   }

   public void setWidth(float var1) {
      this.xDim = var1;
      this.createAppearance();
   }

   public void setLength(float var1) {
      this.yDim = var1;
      this.createAppearance();
   }

   public Transform spin(float var1, float var2, float var3, float var4) {
      if (var1 == 0.0F && var2 == 0.0F) {
         return super.spin(var1, var2, var3, var4);
      }

      System.out.println("ERROR: cannot spin floor patch out of horizontal!");
      return this;
   }

   public Transform postspin(float var1, float var2, float var3, float var4) {
      if (var1 == 0.0F && var2 == 0.0F) {
         return super.spin(var1, var2, var3, var4);
      }

      System.out.println("ERROR: cannot spin floor patch out of horizontal!");
      return this;
   }

   public Transform worldSpin(float var1, float var2, float var3, float var4) {
      if (var1 == 0.0F && var2 == 0.0F) {
         return super.spin(var1, var2, var3, var4);
      }

      System.out.println("ERROR: cannot spin floor patch out of horizontal!");
      return this;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Length (y)"));
            } else if (var3 == 1) {
               var5 = new Float(this.yDim);
            } else if (var3 == 2) {
               this.setLength((Float)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Width (x)"));
            } else if (var3 == 1) {
               var5 = new Float(this.xDim);
            } else if (var3 == 2) {
               this.setWidth((Float)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "0,0 corner"));
            } else if (var3 == 1) {
               var5 = new Float(this.z[0]);
            } else if (var3 == 2) {
               this.setCornerHeight(0, (Float)var4);
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "0,y corner"));
            } else if (var3 == 1) {
               var5 = new Float(this.z[1]);
            } else if (var3 == 2) {
               this.setCornerHeight(1, (Float)var4);
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "x,y corner"));
            } else if (var3 == 1) {
               var5 = new Float(this.z[2]);
            } else if (var3 == 2) {
               this.setCornerHeight(2, (Float)var4);
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "x,0 corner"));
            } else if (var3 == 1) {
               var5 = new Float(this.z[3]);
            } else if (var3 == 2) {
               this.setCornerHeight(3, (Float)var4);
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "# Tiles (x)"));
            } else if (var3 == 1) {
               var5 = new Float(this.xTile);
            } else if (var3 == 2) {
               this.xTile = (Float)var4;
               this.createAppearance();
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "# Tiles (y)"));
            } else if (var3 == 1) {
               var5 = new Float(this.yTile);
            } else if (var3 == 2) {
               this.yTile = (Float)var4;
               this.createAppearance();
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Tile Offset (x)"));
            } else if (var3 == 1) {
               var5 = new Float(this.xTileOffset);
            } else if (var3 == 2) {
               this.xTileOffset = (Float)var4;
               this.createAppearance();
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Tile Offset (y)"));
            } else if (var3 == 1) {
               var5 = new Float(this.yTileOffset);
            } else if (var3 == 2) {
               this.yTileOffset = (Float)var4;
               this.createAppearance();
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Material");
            } else if (var3 == 1) {
               var5 = this.mat;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 11, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      this.removeAppearance();
      super.saveState(var1);
      var1.saveFloat(this.xDim);
      var1.saveFloat(this.yDim);

      for (int var2 = 0; var2 < 4; var2++) {
         var1.saveFloat(this.z[var2]);
      }

      var1.saveFloat(this.xTile);
      var1.saveFloat(this.xTileOffset);
      var1.saveFloat(this.yTile);
      var1.saveFloat(this.yTileOffset);
      var1.saveMaybeNull(this.mat);
      this.createAppearance();
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreStateRectPatchHelper(var1, classCookie);
   }

   public void restoreStateRectPatchHelper(Restorer var1, Object var2) throws IOException, TooNewException {
      switch (var1.restoreVersion(var2)) {
         case 0:
            var1.setOldFlag();
            super.restoreState(var1);
            this.xDim = var1.restoreFloat();
            this.yDim = var1.restoreFloat();

            for (int var5 = 0; var5 < 4; var5++) {
               this.z[var5] = var1.restoreFloat();
            }

            this.setVisible(false);
            break;
         case 1:
            var1.setOldFlag();
            super.restoreState(var1);
            this.xDim = var1.restoreFloat();
            this.yDim = var1.restoreFloat();

            for (int var4 = 0; var4 < 4; var4++) {
               this.z[var4] = var1.restoreFloat();
            }

            this.xTile = var1.restoreFloat();
            this.xTileOffset = var1.restoreFloat();
            this.yTile = var1.restoreFloat();
            this.yTileOffset = var1.restoreFloat();
            this.setMaterial(Material.restore(var1));
            var1.restoreMaybeNull();
            var1.restoreMaybeNull();
            var1.restoreMaybeNull();
            var1.restoreMaybeNull();
            break;
         case 2:
            super.restoreState(var1);
            this.xDim = var1.restoreFloat();
            this.yDim = var1.restoreFloat();

            for (int var3 = 0; var3 < 4; var3++) {
               this.z[var3] = var1.restoreFloat();
            }

            this.xTile = var1.restoreFloat();
            this.xTileOffset = var1.restoreFloat();
            this.yTile = var1.restoreFloat();
            this.yTileOffset = var1.restoreFloat();
            this.setMaterial(Material.restore(var1));
            break;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.xDim + "," + this.yDim + "]";
   }
}
