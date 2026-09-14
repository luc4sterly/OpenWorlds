package NET.worlds.scape;

import java.io.IOException;

public class Point3 extends Point3Temp implements Persister {
   private static Object classCookie = new Object();

   public Point3() {
      super(0);
   }

   public Point3(float var1, float var2, float var3) {
      super(0);
      this.x = var1;
      this.y = var2;
      this.z = var3;
   }

   public Point3(Point3Temp var1) {
      this(var1.x, var1.y, var1.z);
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      var1.saveFloat(this.x);
      var1.saveFloat(this.y);
      var1.saveFloat(this.z);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this.x = var1.restoreFloat();
            this.y = var1.restoreFloat();
            this.z = var1.restoreFloat();
            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }
}
