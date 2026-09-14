package NET.worlds.scape;

import NET.worlds.core.Debug;

public class VehicleDriver extends SwitchableBehavior implements MouseDeltaHandler, KeyUpHandler, KeyDownHandler, MouseDownHandler, MouseUpHandler, FrameHandler {
   protected VehicleShape vehicle;
   static final boolean debug = true;
   static final float gravity = 32.1F;
   static final float densityOfAir = 0.0801F;
   static final float dragCoefficient = 0.3F;
   static final float feetToWorld = 30.48F;
   static final float worldToFeet = 0.0328084F;
   static final float epsilon = 0.001F;
   static final float maxCamber = 0.4F;
   static final float rotationalDampener = 0.5F;
   static final int asphalt = 0;
   static final int grass = 1;
   static final int numTerrainTypes = 2;
   float acceleratorDepression = 0.0F;
   float brakesDepression = 0.0F;
   int currentGear = 1;
   float steeringWheelPosition = 0.0F;
   boolean gasKeyDown = false;
   boolean brakeKeyDown = false;
   boolean leftKeyDown = false;
   boolean rightKeyDown = false;
   Point3 velocityVector = new Point3(0.0F, 0.0F, 0.0F);
   Point3 velocityVectorCarFrame = new Point3(0.0F, 0.0F, 0.0F);
   float velocity = 0.0F;
   Point3 angularVelocity = new Point3(0.0F, 0.0F, 0.0F);
   Point3 angularVelocityCarFrame = new Point3(0.0F, 0.0F, 0.0F);
   Point3 worldCenterOfMass = new Point3(0.0F, 0.0F, 0.0F);
   float engineRPM = 0.0F;
   Point3 integratedForce = new Point3(0.0F, 0.0F, 0.0F);
   Point3 integratedTorque = new Point3(0.0F, 0.0F, 0.0F);
   boolean disabled = false;
   float[] minRPMs;
   VehicleDriver.Tire[] tires;
   protected Room room;
   protected Pilot pilot;
   static float lastTime = 0.0F;
   static final int lateralForceIncrements = 1000;
   static float[][] muTable;
   static boolean lateralForceTableInited = false;
   static final int torqueIncrements = 500;
   static final float maxRPM = 7000.0F;
   static final float minRPM = 1500.0F;
   static final float rpmInc = 500.0F;
   static final int numRPMs = 12;
   static float[] torqueTable;
   static boolean torqueTableInited = false;
   static float[] rawTorqueData = new float[]{80.0F, 82.0F, 91.0F, 92.0F, 89.0F, 90.0F, 98.0F, 93.0F, 94.0F, 78.0F, 83.0F, 75.0F};
   static final float torqueMax = 98.0F;

   public VehicleDriver(VehicleShape var1) {
      this.vehicle = var1;
      this.initLateralForceTable();
      this.initTorqueTable();
      this.initRPMTable();
      this.tires = new VehicleDriver.Tire[4];

      for (int var2 = 0; var2 < 4; var2++) {
         this.tires[var2] = new VehicleDriver.Tire();
         this.tires[var2].relativePos.copy(this.vehicle.tirePositions[var2]);
      }
   }

   public boolean handle(MouseDeltaEvent var1) {
      return UniverseHandler.handle(var1);
   }

   public boolean handle(KeyDownEvent var1) {
      if (UniverseHandler.handle(var1)) {
         return true;
      }

      switch (var1.key) {
         case '1':
            if (this.vehicle.stickShift) {
               this.currentGear = 1;
            }
            break;
         case '2':
            if (this.vehicle.stickShift) {
               this.currentGear = 2;
            }
            break;
         case '3':
            if (this.vehicle.stickShift) {
               this.currentGear = 3;
            }
            break;
         case '4':
            if (this.vehicle.stickShift) {
               this.currentGear = 4;
            }
            break;
         case '5':
            if (this.vehicle.stickShift) {
               this.currentGear = 5;
            }
            break;
         case 'R':
         case 'r':
            this.currentGear = 0;
            break;
         case '\ue325':
            this.leftKeyDown = true;
            break;
         case '\ue326':
            this.gasKeyDown = true;
            break;
         case '\ue327':
            this.rightKeyDown = true;
            break;
         case '\ue328':
            this.brakeKeyDown = true;
      }

      return true;
   }

   public boolean handle(KeyUpEvent var1) {
      if (UniverseHandler.handle(var1)) {
         return true;
      }

      switch (var1.key) {
         case '\ue325':
            this.leftKeyDown = false;
            break;
         case '\ue326':
            this.gasKeyDown = false;
            break;
         case '\ue327':
            this.rightKeyDown = false;
            break;
         case '\ue328':
            this.brakeKeyDown = false;
      }

      return true;
   }

   public boolean handle(MouseDownEvent var1) {
      return false;
   }

   public boolean handle(MouseUpEvent var1) {
      return false;
   }

   public boolean handle(FrameEvent var1) {
      if (!(var1.receiver instanceof Pilot)) {
         return true;
      }

      this.pilot = (Pilot)var1.receiver;
      if (!this.pilot.isActive()) {
         return true;
      }

      Point3Temp var2 = Point3Temp.make(this.vehicle.centerOfGravity);
      var2.times(30.48F);
      var2.times(this.pilot.getObjectToWorldMatrix());
      var2.times(0.0328084F);
      this.worldCenterOfMass.set(var2.x, var2.y, var2.z);
      this.room = this.pilot.getRoom();
      int var3 = var1.time;
      float var4 = (var3 - lastTime) / 1000.0F;
      lastTime = var3;
      if (var4 <= 0.0F) {
         return true;
      }

      if (var4 > 0.33F) {
         var4 = 0.33F;
      }

      if (this.gasKeyDown) {
         this.acceleratorDepression = (float)(this.acceleratorDepression + 1.2 * var4);
      } else {
         this.acceleratorDepression = 0.0F;
      }

      if (this.acceleratorDepression > 1.0) {
         this.acceleratorDepression = 1.0F;
      }

      if (this.brakeKeyDown) {
         this.brakesDepression = (float)(this.brakesDepression + 1.2 * var4);
      } else {
         this.brakesDepression = 0.0F;
      }

      if (this.brakesDepression > 1.0) {
         this.brakesDepression = 1.0F;
      }

      float var5 = 0.282F * var4;
      if (Math.abs(this.velocityVectorCarFrame.y) < 10.0F) {
         var5 = (float)(var5 * 0.5);
      }

      if (this.leftKeyDown) {
         this.steeringWheelPosition -= var5;
      } else if (this.rightKeyDown) {
         this.steeringWheelPosition += var5;
      } else {
         this.steeringWheelPosition = 0.0F;
      }

      if (this.steeringWheelPosition > 0.5) {
         this.steeringWheelPosition = 0.5F;
      }

      if (this.steeringWheelPosition < -0.5) {
         this.steeringWheelPosition = -0.5F;
      }

      this.DoPhysics(var4);
      return true;
   }

   protected void DoPhysics(float var1) {
      System.out.println("-----------------------------");
      float var2 = this.vehicle.maxEngineTorque * this.acceleratorDepression * this.getTorque(this.engineRPM);
      Debug.assert_(this.vehicle.wheelDiameter != 0.0F);
      float var3 = this.getGearRatio(this.currentGear);
      float var4 = var2 * this.vehicle.rearEndRatio * var3 / (this.vehicle.wheelDiameter * 0.5F);
      if (Math.abs(this.velocityVectorCarFrame.y) > 2.0) {
         var4 -= this.brakesDepression * this.vehicle.mass * 100.0F;
      } else if (this.brakesDepression > 0.0F) {
         this.velocityVectorCarFrame.y = 0.0F;
      }

      if (var3 == 0.0F) {
         var4 *= -1.0F;
      }

      if (this.disabled) {
         var4 = 0.0F;
      }

      switch (this.vehicle.driveType) {
         case 0:
            var4 = (float)(var4 * 0.25);
            this.tires[0].driveForce = this.tires[1].driveForce = var4;
            this.tires[2].driveForce = this.tires[3].driveForce = var4;
            break;
         case 1:
            var4 = (float)(var4 * 0.5);
            this.tires[0].driveForce = this.tires[1].driveForce = var4;
            this.tires[2].driveForce = this.tires[3].driveForce = 0.0;
            break;
         case 2:
         default:
            var4 = (float)(var4 * 0.5);
            this.tires[0].driveForce = this.tires[1].driveForce = 0.0;
            this.tires[2].driveForce = this.tires[3].driveForce = var4;
      }

      float var5 = this.steeringWheelPosition * 1.57F;
      this.tires[0].wheelAngle = this.tires[1].wheelAngle = -var5;
      float var6 = 60.0F * this.velocityVectorCarFrame.y / ((float) Math.PI * this.vehicle.wheelDiameter);
      this.engineRPM = var6 * this.vehicle.rearEndRatio * var3;
      if (this.engineRPM < this.vehicle.idleRPM) {
         this.engineRPM = this.vehicle.idleRPM;
      }

      if (!this.vehicle.stickShift) {
         if (this.engineRPM > this.vehicle.rpmTorquePeak && this.currentGear < 5) {
            this.currentGear++;
         }

         if (this.engineRPM < this.minRPMs[this.currentGear] && this.currentGear > 1) {
            this.currentGear--;
         }
      }

      Point3Temp var7 = Point3Temp.make(0.0F, 0.0F, 0.0F);
      Point3Temp var8 = Point3Temp.make(0.0F, 0.0F, 0.0F);

      for (int var9 = 0; var9 < 4; var9++) {
         this.calculateForces(this.tires[var9]);
         var7.plus(this.tires[var9].force);
         var8.plus(this.tires[var9].torque);
      }

      Point3Temp var24 = Point3Temp.make(this.velocityVectorCarFrame);
      var24.negate();
      var24.normalize();
      Debug.assert_(true);
      float var10 = 0.15F * this.vehicle.frontalArea * 0.0801F * this.velocity * this.velocity / 32.1F;
      var24.times(var10);
      var7.plus(var24);
      var7.vectorTimes(this.pilot.getObjectToWorldMatrix());
      System.out.println("Net force " + var7.x + " " + var7.y + " " + var7.z);
      System.out.println("Net torque " + var8.x + " " + var8.y + " " + var8.z);
      Point3Temp var11 = Point3Temp.make(0.0F, 0.0F, -this.vehicle.mass * 32.1F);
      var7.plus(var11);
      Point3Temp var12 = Point3Temp.make(0.5F, 0.5F, 0.5F);
      var12.times(this.angularVelocityCarFrame);
      var12.times(this.vehicle.momentsOfInertia);
      var12.times(1.0F / var1);
      var8.minus(var12);
      this.integratedForce.plus(var7);
      this.integratedForce.times(0.5F);
      this.integratedTorque.plus(var8);
      this.integratedTorque.times(0.5F);
      var12 = Point3Temp.make(this.integratedForce);
      var12.times(1.0F / this.vehicle.mass);
      Point3Temp var13 = Point3Temp.make(var12);
      var13.times(var1);
      Point3Temp var14 = Point3Temp.make(this.velocityVector);
      Point3Temp var15 = Point3Temp.make(this.angularVelocityCarFrame);
      this.velocityVector.plus(var13);
      this.velocityVector.plus(var14);
      this.velocityVector.times(0.5F);
      this.velocity = this.velocityVector.length();
      this.velocityVectorCarFrame.copy(this.velocityVector);
      this.velocityVectorCarFrame.vectorTimes(this.pilot.getObjectToWorldMatrix().invert());
      Point3Temp var16 = Point3Temp.make(this.integratedTorque);
      var16.times(var1);
      var16.dividedBy(this.vehicle.momentsOfInertia);
      this.angularVelocityCarFrame.plus(var16);
      this.angularVelocityCarFrame.plus(var15);
      this.angularVelocityCarFrame.times(0.5F);
      this.angularVelocity.copy(this.angularVelocityCarFrame);
      this.angularVelocity.vectorTimes(this.pilot.getObjectToWorldMatrix());
      Point3Temp var17 = Point3Temp.make(this.velocityVector);
      var17.times(var1);
      float var18 = 0.0F;

      for (int var19 = 0; var19 < 4; var19++) {
         float var20 = -this.tires[var19].underGround;
         if (var20 > var18) {
            var18 = var20;
         }
      }

      var17.z += var18;
      var17.times(30.48F);
      Point3Temp var26 = Point3Temp.make(this.angularVelocity);
      var26.times(var1);
      this.pilot.premoveThrough(var17);
      float var27 = 180.0F / (float)Math.PI;
      this.pilot.pitch(var26.x * var27);
      this.pilot.roll(var26.y * var27);
      this.pilot.yaw(var26.z * var27);
      System.out.println("dx " + var17.x + " " + var17.y + " " + var17.z);
      System.out.println("da " + var26.x + " " + var26.y + " " + var26.z);
      System.out.println("pos" + this.pilot.getX() + " " + this.pilot.getY() + " " + this.pilot.getZ());
   }

   protected void calculateForces(VehicleDriver.Tire var1) {
      var1.force.set(0.0F, 0.0F, 0.0F);
      var1.torque.set(0.0F, 0.0F, 0.0F);
      Transform var2 = this.pilot.getObjectToWorldMatrix();
      Transform var3 = this.pilot.getObjectToWorldMatrix().invert();
      Point3Temp var4 = Point3Temp.make(var1.relativePos);
      var4.plus(this.vehicle.centerOfGravity);
      var4.times(30.48F);
      var4.times(var2);
      double var5 = this.room.floorHeight(var4.x, var4.y, var4.z);
      Point3 var7 = this.room.surfaceNormal(var4.x, var4.y, var4.z);
      var5 *= 0.0328084F;
      var4.times(0.0328084F);
      var1.underGround = (float)(var4.z - var5);
      if (!(var1.underGround > this.vehicle.shockLength)) {
         Point3Temp var8 = Point3Temp.make(var1.relativePos);
         var8.vectorTimes(var2);
         Point3Temp var9 = Point3Temp.make(this.angularVelocity);
         var9.cross(var8);
         var9.plus(this.velocityVector);
         Point3Temp var10 = Point3Temp.make(var9);
         System.out.println("R " + var8.x + " " + var8.y + " " + var8.z);
         System.out.println("Vp " + var10.x + " " + var10.y + " " + var10.z);
         double var11 = var10.dot(var7);
         Point3Temp var13 = Point3Temp.make(var7);
         var13.vectorTimes(var3);
         Point3Temp var14 = Point3Temp.make(var13);
         double var15 = var14.dot(this.vehicle.momentsOfInertia);
         var15 = Math.abs(var15);
         Point3Temp var17 = Point3Temp.make(var8);
         var17.cross(var7);
         double var18 = var17.length();
         double var20 = var18 * this.vehicle.mass + var15;
         Debug.assert_(var20 != 0.0);
         double var22 = this.vehicle.mass * 0.25;
         double var24 = var15 * var22 / var20;
         if (var24 < 0.0) {
            var24 = 0.0;
         }

         if (var24 > this.vehicle.mass) {
            var24 = var22;
         }

         Debug.assert_(this.vehicle.shockLength != 0.0F);
         double var26 = var24 * 32.1F / this.vehicle.shockLength;
         double var28 = var4.z - (var5 + this.vehicle.shockLength);
         if (var28 < -this.vehicle.shockLength) {
            var28 = -this.vehicle.shockLength;
         }

         if (var28 > this.vehicle.shockLength) {
            var28 = this.vehicle.shockLength;
         }

         double var30 = var28;
         double var32 = -var26 * var30;
         double var34 = var26 * var24;
         Debug.assert_(var34 >= 0.0);
         double var36 = -Math.sqrt(var34) * var11 * this.vehicle.shockDampingCoeff;
         var32 += var36;
         Point3Temp var38 = Point3Temp.make(var13);
         var38.normalize();
         var38.times((float)var32);
         var1.force.plus(var38);
         Point3Temp var39 = Point3Temp.make(var10);
         var39.vectorTimes(var3);
         Point3Temp var42 = Point3Temp.make(var39);
         var42.z = 0.0F;
         Point3Temp var43 = Point3Temp.make(0.0F, 0.0F, 0.0F);
         Transform var44 = Transform.make();
         var44.yaw(var1.wheelAngle * 229.1831F);
         float var41;
         if (var42.length() < 0.001F) {
            var41 = 0.0F;
         } else if (Math.abs(var13.x) > 0.4F) {
            var41 = 0.0F;
         } else {
            var42.normalize();
            Point3Temp var45 = Point3Temp.make(0.0F, 1.0F, 0.0F);
            var45.vectorTimes(var44);
            var45.normalize();
            float var40 = var42.dot(var45);
            System.out.println("wheel direction " + var45.x + " " + var45.y + " " + var45.z);
            System.out.println("normal velocity " + var42.x + " " + var42.y + " " + var42.z);
            System.out.println("cos of slip angle " + var40);
            var41 = this.getLateralForceCoef(var40, 0);
            float var46 = var42.x * var45.y - var42.y * var45.x;
            if (var46 > 0.0F) {
               var41 *= -1.0F;
            }
         }

         var43.x = var41 * (float)var32;
         var43.y = (float)var1.driveForce;
         System.out.println("Lateral forces " + var43.x + ", " + var43.y);
         float var54 = var43.length();
         float var55 = (float)var32 * this.vehicle.tireAdhesiveLimit;
         if (var54 > var55) {
            var43.normalize();
            var43.times(var55);
            var1.slipping = true;
         } else {
            var1.slipping = false;
         }

         var43.vectorTimes(var44);
         var1.force.plus(var43);
         Point3Temp var47 = Point3Temp.make(0.0F, 0.0F, 0.0F);
         float var48 = 1.0F;
         float var49 = var10.length();
         var47.y = (float)var32 * 0.001F * (5.7F + 0.036F * var49 * 0.6818182F) * var48;
         if (this.velocityVectorCarFrame.y > 0.0F) {
            var47.y *= -1.0F;
         }

         var47.vectorTimes(var44);
         System.out.println("Rolling friction " + var47.x + " " + var47.y + " " + var47.z);
         var44.recycle();
         Point3Temp var50 = Point3Temp.make(var1.relativePos);
         var50.negate();
         var1.torque.copy(var1.force);
         var1.torque.cross(var50);
         System.out.println("Underground " + var28 + " damping " + var36);
         System.out.println("Force " + var1.force.x + " " + var1.force.y + " " + var1.force.z);
         System.out.println("Torque " + var1.torque.x + " " + var1.torque.y + " " + var1.torque.z);
         System.out.println();
      }
   }

   private float getGearRatio(int var1) {
      float var2;
      switch (var1) {
         case 0:
            var2 = this.vehicle.gearRatio1;
            break;
         case 1:
            var2 = this.vehicle.gearRatio1;
            break;
         case 2:
            var2 = this.vehicle.gearRatio2;
            break;
         case 3:
            var2 = this.vehicle.gearRatio3;
            break;
         case 4:
            var2 = this.vehicle.gearRatio4;
            break;
         case 5:
            var2 = this.vehicle.gearRatio5;
            break;
         default:
            System.out.println("Illegal gear " + this.currentGear);
            var2 = 1.0F;
      }

      return var2;
   }

   protected float getLateralForceCoef(float var1, int var2) {
      if (var1 > 1.0) {
         var1 = 1.0F;
      }

      if (var1 < -1.0) {
         var1 = -1.0F;
      }

      float var3 = (float)Math.ceil(Math.abs(var1) * 1000.0F / 1.0F);
      return muTable[var2][(int)var3];
   }

   protected void initLateralForceTable() {
      if (!lateralForceTableInited) {
         lateralForceTableInited = true;
         muTable = new float[2][1001];

         for (int var1 = 0; var1 < 2; var1++) {
            for (int var2 = 0; var2 <= 1000; var2++) {
               float var3 = (float)Math.acos(var2 / 1000.0F);
               var3 = var3 * 360.0F / (float) (Math.PI * 2);
               switch (var1) {
                  case 0:
                     if (var3 > 45.0F) {
                        var3 = 45.0F;
                     }

                     muTable[var1][var2] = -0.084496F
                        + 0.1241739F * var3
                        - 0.003676377F * (float)Math.pow(var3, 2.0)
                        - 5.5137E-6F * (float)Math.pow(var3, 3.0)
                        + 6.461E-7F * (float)Math.pow(var3, 4.0);
                     break;
                  case 1:
                     muTable[var1][var2] = 0.055731F + 0.069871F * var3 - 0.002175398F * var3 * var3;
               }

               if (muTable[var1][var2] < 0.0F) {
                  muTable[var1][var2] = 0.0F;
               }
            }
         }
      }
   }

   float getTorque(float var1) {
      if (var1 > 7000.0F) {
         var1 = 7000.0F;
      }

      if (var1 < 1500.0F) {
         var1 = 1500.0F;
      }

      int var2 = (int)(var1 / 7000.0F);
      return torqueTable[var2];
   }

   void initTorqueTable() {
      if (!torqueTableInited) {
         torqueTableInited = true;
         torqueTable = new float[501];

         for (int var1 = 0; var1 <= 500; var1++) {
            float var2 = var1 / 500.0F * 7000.0F;
            if (var2 < 1500.0F) {
               var2 = 1500.0F;
            }

            int var3 = 0;

            for (int var4 = 0; var4 < 12; var4++) {
               float var5 = var4 * 500.0F + 1500.0F;
               if (var5 >= var2) {
                  var3 = var4;
                  break;
               }
            }

            if (var3 == 0) {
               torqueTable[var1] = rawTorqueData[0] / 98.0F;
            } else {
               Point2 var8 = new Point2();
               Point2 var9 = new Point2();
               Point2 var6 = new Point2();
               var8.x = (var3 - 1) * 500.0F + 1500.0F;
               var8.y = rawTorqueData[var3 - 1];
               var9.x = var8.x + 500.0F;
               var9.y = rawTorqueData[var3];
               float var7 = (var2 - var8.x) / 500.0F;
               var6.x = var8.x * var7 + var9.x * (1.0F - var7);
               var6.y = var8.y * var7 + var9.y * (1.0F - var7);
               torqueTable[var1] = var6.y / 98.0F;
            }
         }
      }
   }

   private void initRPMTable() {
      this.minRPMs = new float[6];
      float[] var1 = new float[5];

      for (int var2 = 0; var2 < 5; var2++) {
         var1[var2] = this.vehicle.rpmTorquePeak * (float) Math.PI * this.vehicle.wheelDiameter / (60.0F * this.vehicle.rearEndRatio * this.getGearRatio(var2));
      }

      this.minRPMs[0] = 0.0F;

      for (int var3 = 1; var3 <= 5; var3++) {
         this.minRPMs[var3] = 60.0F * var1[var3 - 1] * this.vehicle.rearEndRatio * this.getGearRatio(var3) / ((float) Math.PI * this.vehicle.wheelDiameter);
      }
   }

   protected class Tire {
      Point3 force = new Point3();
      Point3 torque = new Point3();
      Point3 relativePos = new Point3();
      float underGround;
      double driveForce = 0.0;
      float wheelAngle;
      boolean slipping;

      public Tire() {
         this.underGround = 0.0F;
         this.wheelAngle = 0.0F;
         this.slipping = false;
      }
   }
}
