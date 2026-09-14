package NET.worlds.console;

import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.FrameHandler;
import NET.worlds.scape.NoSuchPropertyException;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Point3;
import NET.worlds.scape.Point3Temp;
import NET.worlds.scape.Property;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.WObject;
import java.io.IOException;
import java.util.Enumeration;

public class CameraConveyor extends SuperRoot implements FrameHandler {
   private Point3 vector;
   private static Object classCookie = new Object();

   public CameraConveyor() {
   }

   public CameraConveyor(Point3Temp var1, float var2) {
      this.vector = new Point3(var1.normalize().times(var2));
   }

   public CameraConveyor(Point3Temp var1) {
      this.vector = new Point3(var1);
   }

   public boolean handle(FrameEvent var1) {
      if (var1.dt == 0) {
         return true;
      }

      Enumeration var2 = var1.receiver.getContents();
      Point3Temp var3 = Point3Temp.make(this.vector);
      var3.times(var1.dt / 1000.0F);

      while (var2.hasMoreElements()) {
         WObject var4 = (WObject)var2.nextElement();
         if (var4 instanceof Pilot) {
            var4.moveThrough(var3);
         }
      }

      return true;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.save(this.vector);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
         case 0:
            this.vector = (Point3)var1.restore();
            return;
         default:
            throw new TooNewException();
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Velocity");
            } else if (var3 == 1) {
               var5 = this.vector;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }
}
