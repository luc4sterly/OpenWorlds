package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

class WrVisiRectPatch extends RectPatch {
   private static Object classCookie = new Object();

   public void saveState(Saver var1) throws IOException {
      Debug.assert_(false);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      RectPatch var2 = new RectPatch();
      var1.replace(this, var2);
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.xTile = var1.restoreFloat();
            this.xTileOffset = var1.restoreFloat();
            this.yTile = var1.restoreFloat();
            this.yTileOffset = var1.restoreFloat();
            this.mat = (Material)var1.restoreMaybeNull();
            this.t[0] = (Polygon)var1.restoreMaybeNull();
            this.t[1] = (Polygon)var1.restoreMaybeNull();
            this.t[2] = (Polygon)var1.restoreMaybeNull();
            this.t[3] = (Polygon)var1.restoreMaybeNull();
            var2.xDim = this.xDim;
            var2.yDim = this.yDim;
            var2.z[0] = this.z[0];
            var2.z[1] = this.z[1];
            var2.z[2] = this.z[2];
            var2.z[3] = this.z[3];
            var2.xTile = this.xTile;
            var2.xTileOffset = this.xTileOffset;
            var2.yTile = this.yTile;
            var2.yTileOffset = this.yTileOffset;
            var2.mat = this.mat;
            var2.setVisible(true);
            return;
         default:
            throw new TooNewException();
      }
   }
}
