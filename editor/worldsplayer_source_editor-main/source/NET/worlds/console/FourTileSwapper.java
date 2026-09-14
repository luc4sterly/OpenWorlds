package NET.worlds.console;

import java.awt.Rectangle;

class FourTileSwapper extends Rectangle {
   private FourTilePanel parent;
   private int c1;
   private int c2;

   FourTileSwapper(FourTilePanel var1, int var2, int var3) {
      this.parent = var1;
      this.c1 = var2;
      this.c2 = var3;
   }

   boolean maybeSwap(int var1, int var2) {
      if (this.inside(var1, var2)) {
         this.parent.swap(this.c1, this.c2);
         return true;
      } else {
         return false;
      }
   }
}
