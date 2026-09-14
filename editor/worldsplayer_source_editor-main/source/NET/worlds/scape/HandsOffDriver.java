package NET.worlds.scape;

public class HandsOffDriver extends SwitchableBehavior implements FrameHandler, AnimatedActionHandler, KeyDownHandler, KeyUpHandler {
   Point2 _destPoint;
   float _destYaw;
   float _velocity;
   int _lastFrameTime = 0;
   AnimatedActionHandlerImp handler;
   int _state = 0;
   Transform target = null;
   float cameraPan = 0.0F;
   float cameraZoom = 0.0F;
   int cameraPanning = 0;
   int cameraZooming = 0;
   static final float cameraPanRate = 45.0F;
   static final float cameraZoomRate = 100.0F;
   static final int noState = 0;
   static final int turnToDestination = 1;
   static final int moveToDestination = 2;
   static final int faceDestination = 3;

   public HandsOffDriver() {
      this.handler = new AnimatedActionHandlerImp();
   }

   public float getCameraPan() {
      return this.cameraPan;
   }

   public float getCameraZoom() {
      return this.cameraZoom;
   }

   public void setTarget(Transform var1) {
      this.target = var1;
   }

   public void addCallback(AnimatedActionCallback var1) {
      this.handler.addCallback(var1);
   }

   public void removeCallback(AnimatedActionCallback var1) {
      this.handler.removeCallback(var1);
   }

   public void notifyCallbacks(int var1) {
      this.handler.notifyCallbacks(var1);
   }

   public void setDestPos(Point2 var1, float var2, float var3) {
      if (var1 == null) {
         System.out.println("Point is null");
      }

      this._destPoint = var1;
      this._destYaw = var2;
      this._velocity = var3;
      this._state = 1;
   }

   public boolean handle(FrameEvent var1) {
      int var2 = var1.time;
      float var3 = (var2 - this._lastFrameTime) / 1000.0F;
      this._lastFrameTime = var2;
      this.cameraZoom = this.cameraZoom + var3 * 100.0F * this.cameraZooming;
      this.cameraPan = this.cameraPan + var3 * 45.0F * this.cameraPanning;
      Transform var4;
      if (this.target == null) {
         if (!(var1.receiver instanceof Pilot)) {
            System.out.println("Receiver not pilot...");
            return true;
         }

         Pilot var5 = (Pilot)var1.receiver;
         if (!var5.isActive()) {
            System.out.println("Pilot not active...");
            return true;
         }

         var4 = var5;
      } else {
         var4 = this.target;
      }

      if (var3 <= 0.0F) {
         System.out.println("Negative dt");
         return true;
      }

      if (var3 > 0.33F) {
         var3 = 0.33F;
      }

      this.moveObject(var4, var3);
      return true;
   }

   private void yawLevel(Transform var1, float var2) {
      float var3 = var1.getYaw();
      Point3Temp var4 = Point3Temp.make();
      float var5 = var1.getSpin(var4);
      Point3Temp var6 = var1.getPosition();
      var1.makeIdentity().moveTo(var6).yaw(-var2);
      var1.yaw(var3);
      var1.spin(var4, var5);
   }

   private void moveObject(Transform var1, float var2) {
      if (var1 != null && this._destPoint != null) {
         switch (this._state) {
            case 1:
               Point3Temp var7 = Point3Temp.make(this._destPoint.x, this._destPoint.y, var1.getZ());
               Point3Temp var8 = var1.getPosition();
               double var9 = Math.atan2(var7.y - var8.y, var7.x - var8.x);
               var9 = (Math.PI / 2) - var9;
               var9 *= 180.0 / Math.PI;
               this.yawLevel(var1, (float)var9);
               this._state = 2;
               break;
            case 2:
               Point3Temp var3 = Point3Temp.make(this._destPoint.x, this._destPoint.y, var1.getZ());
               Point3Temp var4 = var1.getPosition();
               float var5 = var2 * this._velocity;
               Point3Temp var6 = Point3Temp.make(var3);
               var6.minus(var1.getPosition());
               if (var6.length() <= var5) {
                  var1.moveTo(var3);
                  this._state = 3;
               } else {
                  var6.normalize();
                  var1.moveBy(var6.times(var5));
               }
               break;
            case 3:
               this.yawLevel(var1, this._destYaw);
               this._state = 0;
               this.notifyCallbacks(0);
         }
      }
   }

   public boolean handle(KeyDownEvent var1) {
      if (var1.key == '\ue326') {
         this.cameraZooming = -1;
      } else if (var1.key == '\ue328') {
         this.cameraZooming = 1;
      } else if (var1.key == '\ue325') {
         this.cameraPanning = -1;
      } else if (var1.key == '\ue327') {
         this.cameraPanning = 1;
      }

      return true;
   }

   public boolean handle(KeyUpEvent var1) {
      if (var1.key == '\ue326' || var1.key == '\ue328') {
         this.cameraZooming = 0;
      } else if (var1.key == '\ue325' || var1.key == '\ue327') {
         this.cameraPanning = 0;
      } else if (var1.key == '\ue31b') {
         this.notifyCallbacks(0);
      }

      return true;
   }
}
