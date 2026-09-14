package NET.worlds.scape;

import java.io.IOException;

public class ProximitySensor extends Sensor implements FrameHandler {
   private boolean _wasin = false;
   private Point3 _start = new Point3(0.0F, 0.0F, 0.0F);
   private Point3 _end = new Point3(1.0F, 1.0F, 1.0F);
   private boolean _triggerin = true;
   private boolean _triggerout = false;
   private boolean _silentTeleport = false;
   private Room _lastRoom;
   private static Object classCookie = new Object();

   public ProximitySensor(Action var1) {
      if (var1 != null) {
         this.addAction(var1);
      }
   }

   public ProximitySensor() {
   }

   public boolean handle(FrameEvent var1) {
      SuperRoot var2 = this.getOwner();
      if (!(var2 instanceof WObject)) {
         return true;
      }

      WObject var3 = (WObject)var2;
      Pilot var4 = Pilot.getActive();
      Room var5 = var4.getRoom();
      boolean var6 = var5 != this._lastRoom;
      this._lastRoom = var5;
      Point3Temp var7 = var4.getPosition();
      BoundBoxTemp var8 = BoundBoxTemp.make(Point3Temp.make(this._start).times(var3), Point3Temp.make(this._end).times(var3));
      if (var4.getRoom() == var3.getRoom() && var8.contains(var7)) {
         if (!this._wasin) {
            this._wasin = true;
            if (this._triggerin && (!var6 || !this._silentTeleport)) {
               this.trigger(var1);
            }
         }
      } else if (this._wasin) {
         this._wasin = false;
         if (this._triggerout && (!var6 || !this._silentTeleport)) {
            this.trigger(var1);
         }
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Start"));
            } else if (var3 == 1) {
               var5 = new Point3(this._start);
            } else if (var3 == 2) {
               this._start = (Point3)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "End"));
            } else if (var3 == 1) {
               var5 = new Point3(this._end);
            } else if (var3 == 2) {
               this._end = (Point3)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Trigger on entry"), "Don't trigger when entered", "Trigger when entered");
            } else if (var3 == 1) {
               var5 = new Boolean(this._triggerin);
            } else if (var3 == 2) {
               this._triggerin = (Boolean)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Trigger on exit"), "Don't trigger when exited", "Trigger when exited");
            } else if (var3 == 1) {
               var5 = new Boolean(this._triggerout);
            } else if (var3 == 2) {
               this._triggerout = (Boolean)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Teleport trigger"), "Don't trigger on teleports", "Trigger on teleports");
            } else if (var3 == 1) {
               var5 = new Boolean(!this._silentTeleport);
            } else if (var3 == 2) {
               this._silentTeleport = !(Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 5, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveBoolean(this._triggerin);
      var1.saveBoolean(this._triggerout);
      var1.saveBoolean(this._silentTeleport);
      var1.save(this._start);
      var1.save(this._end);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this._triggerin = var1.restoreBoolean();
            this._triggerout = var1.restoreBoolean();
            this._start = (Point3)var1.restore();
            this._end = (Point3)var1.restore();
            break;
         case 2:
            super.restoreState(var1);
            this._triggerin = var1.restoreBoolean();
            this._triggerout = var1.restoreBoolean();
            this._silentTeleport = var1.restoreBoolean();
            this._start = (Point3)var1.restore();
            this._end = (Point3)var1.restore();
            break;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + (this._triggerin ? "I" : " ") + (this._triggerout ? "O" : " ") + this._start + " to " + this._end + "]";
   }
}
