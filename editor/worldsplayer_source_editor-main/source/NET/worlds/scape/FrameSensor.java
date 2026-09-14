package NET.worlds.scape;

public class FrameSensor extends Sensor implements FrameHandler {
   public FrameSensor(Action var1) {
      if (var1 != null) {
         this.addAction(var1);
      }
   }

   public FrameSensor() {
   }

   public boolean handle(FrameEvent var1) {
      this.trigger(var1);
      return true;
   }
}
