package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.core.Std;

public class FrameEvent extends Event {
   private static int lastFrameTime;
   private static int deltaFrameTime;
   public int dt;

   public FrameEvent(WObject var1) {
      super(lastFrameTime, null, var1);
      this.dt = deltaFrameTime;
   }

   public FrameEvent(WObject var1, WObject var2) {
      super(lastFrameTime, var1, var2);
      this.dt = deltaFrameTime;
   }

   public void newFrameTime() {
      this.time = Std.getRealTime();
      if (lastFrameTime == 0) {
         deltaFrameTime = 0;
      } else {
         deltaFrameTime = this.time - lastFrameTime;
         Debug.dAssert(this.time >= lastFrameTime && deltaFrameTime >= 0);
      }

      lastFrameTime = this.time;
      this.dt = deltaFrameTime;
   }

   public boolean deliver(Object var1) {
      return var1 instanceof FrameHandler && ((FrameHandler)var1).handle(this) ? true : true;
   }

   public void retargetAndDeliver(FrameHandler var1, WObject var2) {
      this.target = var2;
      this.receiver = var2;
      var1.handle(this);
   }
}
