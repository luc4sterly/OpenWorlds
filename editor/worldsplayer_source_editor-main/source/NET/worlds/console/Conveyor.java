package NET.worlds.console;

import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.FrameHandler;
import NET.worlds.scape.Point3;
import NET.worlds.scape.Point3Temp;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.WObject;
import java.io.IOException;
import java.util.Enumeration;

public class Conveyor extends SuperRoot implements FrameHandler {
   private Point3 vector;
   private static Object classCookie = new Object();

   public Conveyor(Point3Temp var1, float var2) {
      this.vector = new Point3(var1.normalize().times(var2));
   }

   public Conveyor(Point3Temp var1) {
      this.vector = new Point3(var1);
   }

   public boolean handle(FrameEvent var1) {
      Enumeration var2 = var1.receiver.getContents();
      Point3 var3 = this.vector;
      var3.times(var1.dt / 1000.0F);

      while (var2.hasMoreElements()) {
         WObject var4 = (WObject)var2.nextElement();
         var4.moveThrough(var3);
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
}
