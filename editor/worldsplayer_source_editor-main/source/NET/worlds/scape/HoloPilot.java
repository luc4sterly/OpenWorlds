package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import NET.worlds.network.URL;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class HoloPilot extends Pilot implements AnimatedActionHandler, AnimatedActionCallback {
   private Camera cam;
   private SmoothDriver smoothDriver;
   private boolean cameraIsFree = false;
   private AnimatedActionHandlerImp handler;
   private HandsOffDriver hod;
   String lastName;
   Transform lastInverse;
   Point3 lastCamWorldPos;
   float lastCamRadius;
   float lastCamYaw;
   int lastDrawTime;
   int framesSinceMoved = 0;
   Room lastCamRoom;
   Transform defaultTransform = Transform.make();
   Point3 aimPoint = new Point3(0.0F, 0.0F, 0.0F);
   float defaultCameraYaw = 0.0F;
   float defaultCameraRadius = 0.0F;
   public static final int CAM_MODE_VEHICLE = 99;
   public static final int CAM_MODE_FIRST_PERSON = 1;
   public static final int CAM_MODE_LOW_FIRST_PERSON = 2;
   public static final int CAM_MODE_WAIST = 3;
   public static final int CAM_MODE_SHOULDER = 4;
   public static final int CAM_MODE_HEAD = 5;
   public static final int CAM_MODE_OVERHEAD = 6;
   public static final int CAM_MODE_BEHIND = 7;
   public static final int CAM_MODE_WIDESHOT = 8;
   public static final int CAM_MODE_ORTHOGRAPHIC = 9;
   public static final int CAM_SPEED_SLOW = 1;
   public static final int CAM_SPEED_MEDIUM = 2;
   public static final int CAM_SPEED_FAST = 3;
   public static final int CAM_SPEED_LOCKED = 4;
   private boolean substWarned = false;
   protected Point3 boxLo = new Point3();
   protected Point3 boxHi = new Point3();
   protected float stepHeight = 30.0F;
   private static Object classCookie = new Object();

   public HoloPilot(URL var1) {
      this.setSourceURL(var1);
      this.loadInit();
   }

   public void setSleepMode(String var1) {
      Drone var2 = this.getInternalDrone();
      if (var2 != null) {
         var2.setSleepMode(var1);
      }
   }

   public float animate(String var1) {
      super.animate(var1);
      Drone var2 = this.getInternalDrone();
      return var2 != null ? var2.animate(var1) : 0.0F;
   }

   public Vector getAnimationList() {
      Vector var1 = super.getAnimationList();
      Drone var2 = this.getInternalDrone();
      if (var2 == null) {
         return var1;
      }

      Vector var3 = (Vector)var2.getAnimationList().clone();

      for (int var4 = 0; var4 < var1.size(); var4++) {
         var3.addElement(var1.elementAt(var4));
      }

      return var3;
   }

   public HoloPilot() {
   }

   public void loadInit() {
      this.smoothDriver = new SmoothDriver();
      this.smoothDriver.setEyeHeight(0.0F);
      this.cam = new Camera();
      this.add(this.cam);
      Drone var1 = Drone.make(null, null);
      this.add(var1);
      var1.setAvatarNow(this.getSourceURL());
      this.addHandler(this.smoothDriver);
      this.addHandler(new PitchDriver());
      this.handler = new AnimatedActionHandlerImp();
      this.setEyeHeight(150.0F);
   }

   public void addCallback(AnimatedActionCallback var1) {
      Debug.dAssert(this.handler != null);
      this.handler.addCallback(var1);
   }

   public void removeCallback(AnimatedActionCallback var1) {
      Debug.dAssert(this.handler != null);
      this.handler.removeCallback(var1);
   }

   public void notifyCallbacks(int var1) {
      Debug.dAssert(this.handler != null);
      this.handler.notifyCallbacks(var1);
   }

   public void walkTo(Point2 var1, float var2) {
      this.walkTo(var1, var2, 80.0F);
   }

   public void walkTo(Point2 var1, float var2, float var3) {
      this.removeHandler(this.smoothDriver);
      this.hod = new HandsOffDriver();
      this.hod.setDestPos(var1, var2, var3);
      this.hod.addCallback(this);
      this.addHandler(this.hod);
   }

   public void removeSmoothDriver() {
      this.removeHandler(this.smoothDriver);
   }

   public void returnSmoothDriver() {
      this.addHandler(this.smoothDriver);
   }

   public SmoothDriver getSmoothDriver() {
      return this.smoothDriver;
   }

   public void removeHandsOffDriver() {
      if (this.hod != null) {
         this.removeHandler(this.hod);
         this.hod = null;
      }
   }

   public void returnHandsOffDriver() {
      if (this.hod == null) {
         this.hod = new HandsOffDriver();
         this.addHandler(this.hod);
      }
   }

   public void motionComplete(int var1) {
      this.removeHandler(this.hod);
      this.hod = null;
      this.addHandler(this.smoothDriver);
      this.notifyCallbacks(var1);
   }

   public void updateName() {
      String var1 = this.getLongID();
      if (var1 != null) {
         if (this.lastName == null || !this.lastName.equals(var1)) {
            this.lastName = var1;
            Drone var2 = this.getInternalDrone();
            if (var2 != null) {
               var2.setName(var1);
            }
         }
      }
   }

   public Drone getInternalDrone() {
      Enumeration var1 = this.getContents();

      while (var1.hasMoreElements()) {
         Object var2 = var1.nextElement();
         if (var2 instanceof Drone) {
            return (Drone)var2;
         }
      }

      return null;
   }

   private void setLastInverse(Transform var1) {
      if (this.lastInverse != null) {
         this.lastInverse.recycle();
      }

      this.lastInverse = var1;
   }

   protected void transferFrom(Pilot var1) {
      if (var1 != null && var1 instanceof HoloPilot) {
         HoloPilot var2 = (HoloPilot)var1;
         this.setOutsideCameraMode(var2.getOutsideCameraMode(), var2.getOutsideCameraSpeed());
         super.transferFrom(var1);
         if (var2.lastCamWorldPos != null) {
            this.setLastInverse(var2.lastInverse.getTransform());
            this.lastCamWorldPos = new Point3(var2.lastCamWorldPos);
         }

         this.lastCamRoom = var2.lastCamRoom;
         this.lastCamRadius = var2.lastCamRadius;
         this.lastCamYaw = var2.lastCamYaw;
         this.lastDrawTime = var2.lastDrawTime;
         this.framesSinceMoved = this.framesSinceMoved;
      } else {
         super.transferFrom(var1);
      }
   }

   public void aboutToDraw() {
      if (this.cameraMode == 1 || this.cameraMode == 2) {
         this.lastCamWorldPos = null;
         this.cam.makeIdentity();
      } else if (!this.cameraIsFree) {
         Transform var1 = this.getObjectToWorldMatrix();
         int var2 = Std.getRealTime();
         Room var5 = this.getRoom();
         Transform var6 = var1.getTransform().invert();
         float var3;
         float var4;
         if (this.lastCamWorldPos == null || this.cameraSpeed == 4 || this.cameraMode == 99) {
            this.lastCamWorldPos = new Point3();
            var3 = this.defaultCameraRadius;
            var4 = this.defaultCameraYaw;
         } else if (var5 != this.lastCamRoom) {
            var4 = this.lastCamYaw;
            var3 = this.lastCamRadius;
         } else {
            Point3 var7 = this.lastCamWorldPos;
            var7.times(var6);
            var3 = (float)Math.sqrt(var7.x * var7.x + var7.y * var7.y);
            if (var3 > this.defaultCameraRadius + 10.0F) {
               var3 = this.defaultCameraRadius + 10.0F;
            }

            if (this.cameraSpeed == 3) {
               var3 = this.defaultCameraRadius;
            }

            var4 = (float)(Math.atan2(var7.y, var7.x) * 180.0 / Math.PI);
            this.lastInverse.post(var1);
            float var8 = this.lastInverse.getYaw();
            if (var8 > 180.0F) {
               var8 -= 360.0F;
            }

            Point3Temp var9 = this.lastInverse.getPosition();
            if (this.cameraSpeed != 1 || Math.abs(var8) < 1.0F && var9.x * var9.x + var9.y * var9.y < 1.0F) {
               if (++this.framesSinceMoved > 2) {
                  float var10 = this.defaultCameraYaw - var4;
                  if (var10 < -180.0F) {
                     var10 += 360.0F;
                  } else if (var10 > 180.0F) {
                     var10 -= 360.0F;
                  }

                  float var11 = this.defaultCameraRadius - var3;
                  float var12 = var2 - this.lastDrawTime;
                  float var13 = 0.04F;
                  float var14 = 0.03F;
                  if (Math.abs(var10) > 1500.0F * var13) {
                     var13 *= 1.5F;
                  }

                  var13 *= var12;
                  if (var10 < -var13) {
                     var10 = -var13;
                  } else if (var10 > var13) {
                     var10 = var13;
                  }

                  var14 *= var12;
                  if (var11 < -var14) {
                     var11 = -var14;
                  } else if (var11 > var14) {
                     var11 = var14;
                  }

                  var4 += var10;
                  var3 += var11;
                  if (this.cameraSpeed == 3) {
                     if (var4 > this.defaultCameraYaw + 40.0F) {
                        var4 = this.defaultCameraYaw + 40.0F;
                     } else if (var4 < this.defaultCameraYaw - 40.0F) {
                        var4 = this.defaultCameraYaw - 40.0F;
                     }
                  }
               }
            } else {
               this.framesSinceMoved = 0;
            }
         }

         this.setLastInverse(var6);
         float var15 = this.aimPoint.z;
         float var16 = var4;
         float var17 = var3;
         if (this.hod != null) {
            var16 += this.hod.getCameraPan();
            var17 += this.hod.getCameraZoom();
            if (var17 < this.defaultCameraRadius) {
               var15 -= (this.defaultCameraRadius - var17) * this.smoothDriver.getEyeHeight() / this.defaultCameraRadius;
            }
         }

         this.cam.makeIdentity().post(this.defaultTransform);
         this.cam.moveBy(var17, 0.0F, 0.0F);
         this.cam.postspin(0.0F, 0.0F, 1.0F, var16);
         this.cam.moveBy(this.aimPoint.x, this.aimPoint.y, var15);
         this.lastCamRadius = var3;
         this.lastCamYaw = var4;
         double var18 = var4 * Math.PI / 180.0;
         this.lastCamWorldPos.x = (float)(var3 * Math.cos(var18));
         this.lastCamWorldPos.y = (float)(var3 * Math.sin(var18));
         this.lastCamWorldPos.z = 0.0F;
         this.lastCamWorldPos.times(var1);
         this.lastCamWorldPos.z = 0.0F;
         this.lastDrawTime = var2;
         this.lastCamRoom = var5;
         var1.recycle();
      }
   }

   public void setOutsideCameraMode(int var1, int var2) {
      this.defaultTransform.makeIdentity();
      this.aimPoint.x = 0.0F;
      this.aimPoint.y = 0.0F;
      this.aimPoint.z = 0.0F;
      this.setEyeHeight(150.0F);
      if (this.getInternalDrone() != null && this.getInternalDrone() instanceof PosableDrone) {
         PosableShape var3 = ((PosableDrone)this.getInternalDrone()).getInternalPosableShape();
         if (var3 != null && var3 instanceof VehicleShape) {
            VehicleShape var4 = (VehicleShape)var3;
            if (var4.fixedCamera) {
               this.defaultTransform
                  .moveTo(var4.camX, var4.camY, var4.camZ)
                  .postspin(1.0F, 0.0F, 0.0F, var4.camRoll)
                  .postspin(0.0F, 1.0F, 0.0F, var4.camYaw)
                  .postspin(0.0F, 0.0F, 1.0F, var4.camPitch);
               this.aimPoint.x = var4.camAimX;
               this.aimPoint.y = var4.camAimY;
               this.aimPoint.z = var4.camAimZ;
               this.setEyeHeight(var4.eyeHeight);
               var1 = 99;
            }
         }
      }

      this.cam.setAlwaysClearBackground(false);
      this.cam.setBumpable(true);
      switch (var1) {
         case 1:
         case 99:
            break;
         case 2:
            this.setEyeHeight(100.0F);
            break;
         case 3:
            this.defaultTransform.moveTo(0.0F, -120.0F, -60.0F).postspin(1.0F, 0.0F, 0.0F, -10.0F).postspin(0.0F, 0.0F, 1.0F, 30.0F);
            this.aimPoint.x = 15.0F;
            this.aimPoint.z = -10.0F;
            break;
         case 4:
            this.defaultTransform.moveTo(0.0F, -140.0F, -40.0F).postspin(1.0F, 0.0F, 0.0F, -10.0F).postspin(0.0F, 0.0F, 1.0F, 15.0F);
            this.aimPoint.x = 15.0F;
            this.aimPoint.z = 10.0F;
            break;
         case 5:
            this.defaultTransform.moveTo(0.0F, -140.0F, 0.0F).postspin(1.0F, 0.0F, 0.0F, -10.0F).postspin(0.0F, 0.0F, 1.0F, 15.0F);
            this.aimPoint.x = 15.0F;
            this.aimPoint.z = 10.0F;
            break;
         case 6:
            this.defaultTransform.moveTo(0.0F, -100.0F, 0.0F).postspin(1.0F, 0.0F, 0.0F, -30.0F).postspin(0.0F, 0.0F, 1.0F, 30.0F);
            this.aimPoint.x = 15.0F;
            this.aimPoint.z = 10.0F;
            break;
         case 7:
            this.defaultTransform.moveTo(0.0F, -140.0F, 0.0F).postspin(1.0F, 0.0F, 0.0F, -10.0F);
            break;
         case 8:
            this.defaultTransform.moveTo(0.0F, -220.0F, -40.0F).postspin(1.0F, 0.0F, 0.0F, -30.0F).postspin(0.0F, 0.0F, 1.0F, 30.0F);
            this.aimPoint.x = 15.0F;
            this.aimPoint.z = 10.0F;
            break;
         case 9:
            this.defaultTransform.moveTo(0.0F, -140.0F, 300.0F).postspin(1.0F, 0.0F, 0.0F, -10.0F);
            this.aimPoint.x = 0.0F;
            this.aimPoint.z = 300.0F;
            this.cam.setAlwaysClearBackground(true);
            this.cam.setBumpable(false);
            var2 = 4;
            break;
         default:
            var1 = 1;
            var2 = 3;
            this.defaultCameraRadius = 0.0F;
            this.defaultCameraYaw = 0.0F;
      }

      if (var1 != 1 && var1 != 2) {
         float var5 = this.defaultTransform.getX();
         float var6 = this.defaultTransform.getY();
         this.aimPoint.z = this.aimPoint.z + this.defaultTransform.getZ();
         this.defaultCameraRadius = (float)Math.sqrt(var5 * var5 + var6 * var6);
         this.defaultCameraYaw = (float)(Math.atan2(var6, var5) * 180.0 / Math.PI);
         this.defaultTransform.moveTo(0.0F, 0.0F, 0.0F);
         this.defaultTransform.postspin(0.0F, 0.0F, 1.0F, -this.defaultCameraYaw);
      }

      super.setOutsideCameraMode(var1, var2);
   }

   public void resetAvatarNow() {
      URL var1 = this.getSourceURL();
      Drone var2 = this.getInternalDrone();
      var2.setAvatarNow(var1);
      if (!var2.shouldBeForcedHuman() || PosableShape.getHuman(var1).equals(var1)) {
         this.substWarned = false;
      } else if (!this.substWarned) {
         this.substWarned = true;
         Console.println(Console.message("Sub-human"));
      }
   }

   public void setEyeHeight(float var1) {
      float var2 = this.smoothDriver.getEyeHeight();
      if (var1 != var2) {
         this.smoothDriver.setEyeHeight(var1);
         this.getInternalDrone().moveBy(0.0F, 0.0F, var2 - var1);
         this.setLocalBoundBox(Point3Temp.make(-30.0F, -30.0F, -var1), Point3Temp.make(30.0F, 50.0F, 20.0F));
      }
   }

   public BoundBoxTemp getLocalBoundBox() {
      return BoundBoxTemp.make(this.boxLo, this.boxHi);
   }

   public void setLocalBoundBox(BoundBoxTemp var1) {
      this.boxLo = new Point3(var1.lo);
      this.boxHi = new Point3(var1.hi);
   }

   public void setLocalBoundBox(Point3Temp var1, Point3Temp var2) {
      this.setLocalBoundBox(BoundBoxTemp.make(var1, var2));
   }

   public BoundBoxTemp getBoundBox() {
      Point3Temp var1 = Point3Temp.make(this.boxLo);
      var1.z = var1.z + this.stepHeight;
      Point3 var2 = this.boxHi;
      Transform var3 = this.getObjectToWorldMatrix();
      Point3Temp var4 = Point3Temp.make(var1).times(var3);
      BoundBoxTemp var5 = BoundBoxTemp.make(var4, var4);
      var5.encompass(Point3Temp.make(var2).times(var3));
      var5.encompass(Point3Temp.make(var1.x, var1.y, var2.z).times(var3));
      var5.encompass(Point3Temp.make(var1.x, var2.y, var1.z).times(var3));
      var5.encompass(Point3Temp.make(var1.x, var2.y, var2.z).times(var3));
      var5.encompass(Point3Temp.make(var2.x, var1.y, var1.z).times(var3));
      var5.encompass(Point3Temp.make(var2.x, var1.y, var2.z).times(var3));
      var5.encompass(Point3Temp.make(var2.x, var2.y, var1.z).times(var3));
      var3.recycle();
      return var5;
   }

   public float getFootHeight() {
      if (this.isActive()) {
         Transform var1 = this.getObjectToWorldMatrix();
         float var2 = var1.getPitch();
         var1.pitch(-var2);
         float var3 = Point3Temp.make(this.boxLo).times(var1).z;
         var1.recycle();
         return var3;
      } else {
         return 0.0F;
      }
   }

   public float getStepHeight() {
      return this.stepHeight;
   }

   public void setStepHeight(float var1) {
      this.stepHeight = var1;
   }

   public void releaseCamera() {
      this.cameraIsFree = true;
   }

   public void reclaimCamera() {
      this.cameraIsFree = false;
   }

   public Camera getCamera() {
      return this.cam;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Bump Box Start"));
            } else if (var3 == 1) {
               var5 = new Point3(this.boxLo);
            } else if (var3 == 2) {
               this.boxLo = new Point3((Point3)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "Bump Box End"));
            } else if (var3 == 1) {
               var5 = new Point3(this.boxHi);
            } else if (var3 == 2) {
               this.boxHi = new Point3((Point3)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Step Height"));
            } else if (var3 == 1) {
               var5 = new Float(this.getStepHeight());
            } else if (var3 == 2) {
               this.setStepHeight((Float)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 3, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveFloat(this.stepHeight);
      var1.save(this.boxLo);
      var1.save(this.boxHi);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.stepHeight = var1.restoreFloat();
            this.boxLo = (Point3)var1.restore();
            this.boxHi = (Point3)var1.restore();
            return;
         default:
            throw new TooNewException();
      }
   }
}
