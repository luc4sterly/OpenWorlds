package NET.worlds.scape;

public class BumpSensor extends Sensor implements BumpHandler {
   public BumpSensor(Action var1) {
      if (var1 != null) {
         this.addAction(var1);
      }
   }

   public BumpSensor() {
   }

   public boolean handle(BumpEventTemp var1) {
      if (var1.source instanceof Pilot) {
         this.trigger(var1);
      }

      return true;
   }
}
