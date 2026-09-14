package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;

public class Polygon extends Surface {
   protected float[] vertices;
   private static Object classCookie = new Object();

   public Polygon(int var1, Material var2) {
      this(new float[5 * var1], var2);
   }

   public Polygon(float[] var1, Material var2) {
      super(var2);
      Debug.dAssert(var1.length % 5 == 0);
      this.vertices = var1;
   }

   public Polygon() {
   }

   public void setVertex(int var1, float var2, float var3, float var4, float var5, float var6) {
      var1 *= 5;
      this.vertices[var1] = var2;
      this.vertices[var1 + 1] = var3;
      this.vertices[var1 + 2] = var4;
      this.vertices[var1 + 3] = var5;
      this.vertices[var1 + 4] = var6;
      this.nativeSetVertex(var1, var2, var3, var4, var5, var6);
   }

   public native void nativeSetVertex(int var1, float var2, float var3, float var4, float var5, float var6);

   protected void addRwChildren(WObject var1) {
      this.addNewRwChild(var1);

      for (byte var2 = 0; var2 < this.vertices.length; var2 += 5) {
         this.addVertex(this.vertices[var2], this.vertices[var2 + 1], this.vertices[var2 + 2], this.vertices[var2 + 3], this.vertices[var2 + 4]);
      }

      this.doneWithEditing();
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveInt(this.vertices.length);

      for (int var2 = 0; var2 < this.vertices.length; var2++) {
         var1.saveFloat(this.vertices[var2]);
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            int var2 = var1.restoreInt();
            this.vertices = new float[var2];

            for (int var3 = 0; var3 < var2; var3++) {
               this.vertices[var3] = var1.restoreFloat();
            }

            return;
         default:
            throw new TooNewException();
      }
   }
}
