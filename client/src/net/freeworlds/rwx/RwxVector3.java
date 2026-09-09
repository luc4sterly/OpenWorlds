package net.freeworlds.rwx;

/** Simple immutable 3-component float vector/point. */
public final class RwxVector3 {
   public final float x;
   public final float y;
   public final float z;

   public RwxVector3(float x, float y, float z) {
      this.x = x;
      this.y = y;
      this.z = z;
   }

   public RwxVector3 transform(RwxMatrix4 m) {
      return m.transformPoint(this);
   }
}
