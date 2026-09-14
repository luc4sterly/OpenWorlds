package NET.worlds.scape;

public class SubclumpShape extends Shape implements ShapeLoaderListener {
   private Material pendingMaterial = null;
   private static final boolean debug = false;

   public void setMaterial(Material var1) {
      SuperRoot var2 = this.getOwner();
      if (!(var2 instanceof Shape)) {
         super.setMaterial(var1);
      } else {
         Shape var3 = (Shape)var2;
         if (!var3.isFullyLoaded()) {
            var3.addLoadListener(this);
            this.pendingMaterial = var1;
         } else {
            super.setMaterial(var1);
         }
      }
   }

   protected synchronized void addRwChildren(WObject var1) {
      SuperRoot var2 = this.getOwner();
      if (var2 instanceof Shape) {
         Shape var3 = (Shape)var2;
         if (!var3.isFullyLoaded()) {
            this.setState(LOADING, null);
            var3.addLoadListener(this);
         }
      }

      super.addRwChildren(var1);
   }

   public void notifyShapeLoaded(Shape var1) {
      this.setState(NORMAL, null);
      this.shapeRedraw();
      if (this.pendingMaterial != null) {
         super.setMaterial(this.pendingMaterial);
      }

      this.pendingMaterial = null;
   }
}
