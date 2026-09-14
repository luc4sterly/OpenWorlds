package NET.worlds.scape;

import NET.worlds.core.Std;
import java.util.Enumeration;

public class MoveCameraAction extends MoveAction {
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      Pilot var3 = Pilot.getActive();
      if (!(var3 instanceof HoloPilot)) {
         return null;
      }

      HoloPilot var4 = (HoloPilot)var3;
      var4.releaseCamera();
      Camera var5 = var4.getCamera();
      if (var5 != null && var5 instanceof WObject) {
         WObject var6 = var5;
         if (this.killed) {
            this.killed = false;
            this.activeID = null;
            var4.reclaimCamera();
            return null;
         }

         if (var2 == null) {
            if (this.activeID != null) {
               return this.activeID;
            }

            if (this.killOthers) {
               Enumeration var7 = var6.getActions();

               while (var7.hasMoreElements()) {
                  Action var8 = (Action)var7.nextElement();
                  if (var8 != this && var8 instanceof MoveAction) {
                     MoveAction var9 = (MoveAction)var8;
                     if (var9.isRunning()) {
                        var9.kill();
                     }
                  }
               }
            }

            this.startTime = Std.getRealTime();
            this.activeID = new SuperRoot();
            var2 = this.activeID;
         }

         if (var2 != this.activeID) {
            return null;
         }

         int var11 = Std.getRealTime();
         int var12 = (var11 - this.startTime) / this.cycleTime;
         float var13 = 1.0F;
         if (var12 >= this.cycles && !this.loopInfinite) {
            System.out.println("Killing MoveCameraAction.  loopInfinite = " + this.loopInfinite);
            this.activeID = null;
         } else {
            var13 = (float)((var11 - this.startTime) % this.cycleTime) / this.cycleTime;
         }

         var6.makeIdentity();
         var6.spin(this.extentSpin, this.extentRotation * var13);
         var6.spin(this.startSpin, this.startRotation);
         Point3Temp var10 = Point3Temp.make(
            (float)Math.pow(this.extentScale.x, var13), (float)Math.pow(this.extentScale.y, var13), (float)Math.pow(this.extentScale.z, var13)
         );
         var6.scale(var10.times(this.startScale));
         var6.moveTo(Point3Temp.make(this.extentPoint).times(var13).plus(this.startPoint));
         if (this.activeID == null) {
            var4.reclaimCamera();
         }

         return this.activeID;
      } else {
         return null;
      }
   }
}
