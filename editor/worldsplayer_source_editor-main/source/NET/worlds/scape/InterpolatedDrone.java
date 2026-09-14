package NET.worlds.scape;

import NET.worlds.console.BBAppearDroneCommand;
import NET.worlds.console.BBDisappearDroneCommand;
import NET.worlds.console.BBDroneDeltaPosCommand;
import NET.worlds.console.BBMoveDroneCommand;
import NET.worlds.console.BlackBox;
import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import NET.worlds.network.ObjID;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import java.io.IOException;

public class InterpolatedDrone extends Drone implements FrameHandler {
   private int _last_FrameTime;
   private int _last_PosTime;
   private int _vel_x;
   private int _vel_y;
   private int _vel_z;
   private int _vel_yaw;
   private int _last_x;
   private int _last_y;
   private int _last_z;
   private int _last_yaw;
   private int _x;
   private int _y;
   private int _z;
   private int _yaw;
   private boolean inited = false;
   private static Object classCookie = new Object();

   public InterpolatedDrone(ObjID var1, WorldServer var2) {
      super(var1, var2);
   }

   public InterpolatedDrone() {
   }

   public Point3Temp getVelocity() {
      return Point3Temp.make(this._vel_x, this._vel_y, this._vel_z);
   }

   public int getYawRate() {
      return this._vel_yaw;
   }

   public boolean handle(FrameEvent var1) {
      if (this._server == null) {
         return true;
      }

      int var2 = var1.time;
      this.interpolate(var2, this._server.getUpdateTime(), this);
      return true;
   }

   public void interpolate(int var1, int var2, Transform var3) {
      if (this.inited) {
         if (var1 - this._last_PosTime > var2) {
            this._last_PosTime = var1;
            this._vel_x = this._last_x - this._x;
            this._vel_y = this._last_y - this._y;
            this._vel_z = this._last_z - this._z;
            this._vel_yaw = ((this._last_yaw - this._yaw) % 360 + 360) % 360;
            Debug.dAssert(this._vel_yaw >= 0);
            if (this._vel_yaw > 180) {
               this._vel_yaw -= 360;
            }
         }

         double var4 = (double)(var1 - this._last_FrameTime) / var2;
         if (var1 - this._last_FrameTime > var2) {
            var4 = 0.0;
         }

         this._x = this._x + (int)(var4 * this._vel_x);
         this._y = this._y + (int)(var4 * this._vel_y);
         this._z = this._z + (int)(var4 * this._vel_z);
         this._yaw = this._yaw + (int)(var4 * this._vel_yaw) % 360;
         var3.makeIdentity().moveBy(this._x, this._y, this._z).yaw(this._yaw);
         this._last_FrameTime = var1;
      }
   }

   public void reset(short var1, short var2, short var3, short var4) {
      this._x = var1;
      this._y = var2;
      this._z = var3;
      this._yaw = var4;
      this._vel_x = this._vel_y = this._vel_z = 0;
      this._vel_yaw = 0;
      this._last_x = this._x;
      this._last_y = this._y;
      this._last_z = this._z;
      this._last_yaw = this._yaw;
      this._last_PosTime = this._last_FrameTime = Std.getRealTime();
      this.inited = true;
   }

   public void appear(Room var1, short var2, short var3, short var4, short var5) {
      Debug.dAssert(var1 != null);
      BlackBox.getInstance().submitEvent(new BBAppearDroneCommand(var1.toString(), this.getName(), var2, var3, var4, var5));
      if (this.getRoom() != var1) {
         this.detach();
         var1.add(this);
      }

      this.makeIdentity().moveBy(var2, var3, var4).yaw(var5);
      this._x = var2;
      this._y = var3;
      this._z = var4;
      this._yaw = var5;
      this._vel_x = this._vel_y = this._vel_z = 0;
      this._vel_yaw = 0;
      this._last_x = var2;
      this._last_y = var3;
      this._last_z = var4;
      this._last_yaw = var5;
      this._last_PosTime = this._last_FrameTime = Std.getRealTime();
      URL var6 = this.getCurrentURL();
      if (var6 != null) {
         this.setAvatarNow(var6);
      }

      this.inited = true;
   }

   public void disappear() {
      BlackBox.getInstance().submitEvent(new BBDisappearDroneCommand(this.getName()));
      this.detachFromServer(true);
      this.detach();
   }

   public void longLoc(short var1, short var2, short var3, short var4) {
      if (!(this.getOwner() instanceof Pilot)) {
         BlackBox.getInstance().submitEvent(new BBMoveDroneCommand(this.getName(), var1, var2, var3, var4));
      }

      this._last_x = var1;
      this._last_y = var2;
      this._last_z = var3;
      this._last_yaw = var4;
      this._vel_x = this._last_x - this._x;
      this._vel_y = this._last_y - this._y;
      this._vel_z = this._last_z - this._z;
      this._vel_yaw = ((this._last_yaw - this._yaw) % 360 + 360) % 360;
      Debug.dAssert(this._vel_yaw >= 0);
      if (this._vel_yaw > 180) {
         this._vel_yaw -= 360;
      }

      this._last_PosTime = Std.getRealTime();
      this.inited = true;
   }

   protected void transferFrom(Drone var1) {
      super.transferFrom(var1);
      if (var1 instanceof InterpolatedDrone) {
         InterpolatedDrone var2 = (InterpolatedDrone)var1;
         this._x = var2._x;
         this._y = var2._y;
         this._z = var2._z;
         this._yaw = var2._yaw;
         this._vel_x = var2._vel_x;
         this._vel_y = var2._vel_y;
         this._vel_z = var2._vel_z;
         this._vel_yaw = var2._vel_yaw;
         this._last_x = var2._last_x;
         this._last_y = var2._last_y;
         this._last_z = var2._last_z;
         this._last_yaw = var2._last_yaw;
         this._last_PosTime = var2._last_PosTime;
         this._last_FrameTime = var2._last_FrameTime;
         this.inited = true;
      }
   }

   public void roomChange(Room var1, short var2, short var3, short var4, short var5) {
      this.detach();
      if (var1 != null) {
         this.appear(var1, var2, var3, var4, var5);
      }
   }

   public void shortLoc(byte var1, byte var2, byte var3) {
      if (!(this.getOwner() instanceof Pilot)) {
         BlackBox.getInstance().submitEvent(new BBDroneDeltaPosCommand(this.getName(), var1, var2, var3));
      }

      this._last_x += var1;
      this._last_y += var2;
      this._last_yaw += var3;
      this._last_yaw %= 360;
      this._vel_x = this._last_x - this._x;
      this._vel_y = this._last_y - this._y;
      this._vel_z = 0;
      this._vel_yaw = ((this._last_yaw - this._yaw) % 360 + 360) % 360;
      Debug.dAssert(this._vel_yaw >= 0);
      if (this._vel_yaw > 180) {
         this._vel_yaw -= 360;
      }

      this._last_PosTime = Std.getRealTime();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         default:
            return super.properties(var1, var2 + 0, var3, var4);
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
