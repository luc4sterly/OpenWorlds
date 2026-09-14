package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.OkCancelDialog;
import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.io.IOException;

public class VehicleShape extends PosableShape implements MouseDownHandler, DialogReceiver {
   static final int fourWheelDrive = 0;
   static final int frontWheelDrive = 1;
   static final int rearWheelDrive = 2;
   private String promptString = "Take her for a spin?";
   public float rearEndRatio = 3.07F;
   public float frontalArea = 42.5F;
   public float wheelDiameter = 2.167F;
   public float coeffKineticFriction = 0.05F;
   public float coeffStaticFriction = 0.2F;
   public float mass = 100.0F;
   public float gearRatio1 = 2.88F;
   public float gearRatio2 = 1.91F;
   public float gearRatio3 = 1.33F;
   public float gearRatio4 = 1.0F;
   public float gearRatio5 = 0.7F;
   public float maxEngineTorque = 300.0F;
   public float tireAdhesiveLimit = 1.1F;
   public float shockDampingCoeff = 3.0F;
   public float shockLength = 0.15F;
   public float rpmTorquePeak = 4200.0F;
   public float idleRPM = 1000.0F;
   public boolean stickShift = false;
   public float initialGas = -1.0F;
   public float adjustCogX = 0.0F;
   public float adjustCogY = 0.0F;
   public float adjustCogZ = 0.0F;
   public int driveType = 2;
   public boolean fixedCamera = true;
   public float camX = 0.0F;
   public float camY = -80.0F;
   public float camZ = -120.0F;
   public float camRoll = -10.0F;
   public float camPitch = 0.0F;
   public float camYaw = 0.0F;
   public float camAimX = 15.0F;
   public float camAimY = 0.0F;
   public float camAimZ = 10.0F;
   public float eyeHeight = 150.0F;
   public String lastURL = "";
   public Point3 centerOfGravity;
   public Point3 momentsOfInertia;
   public Point3[] tirePositions;
   private boolean avatarSwitchPending = false;
   private static String[] vehicleShapeNames = new String[]{"dash"};
   private static Object classCookie = new Object();

   VehicleShape() {
   }

   VehicleShape(URL var1) {
      super(var1);
   }

   public static boolean isVehicle(URL var0) {
      if (IniFile.gamma().getIniInt("enableVehicleShapes", 0) == 0) {
         return false;
      }

      String var1 = var0.toString();

      for (int var2 = 0; var2 < vehicleShapeNames.length; var2++) {
         if (var0.toString().indexOf(vehicleShapeNames[var2]) != -1) {
            return true;
         }
      }

      return false;
   }

   public boolean handle(MouseDownEvent var1) {
      if ((var1.key & 1) == 1) {
         new OkCancelDialog(Console.getFrame(), this, "Change Avatar", "No", "Yes", this.promptString, true);
      }

      return true;
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var1 instanceof OkCancelDialog && var2) {
         this.avatarSwitchPending = true;
         boolean var3 = Console.getActive().getVIP();
         Console.getActive().setVIP(true);
         Console.getActive().setAvatar(this.url);
         Console.getActive().setVIP(var3);
      }
   }

   protected native void nativeAnalyzeShape(int var1, float var2);

   protected native float nativeGetTirePosX(int var1);

   protected native float nativeGetTirePosY(int var1);

   protected native float nativeGetTirePosZ(int var1);

   protected native float nativeGetCogX();

   protected native float nativeGetCogY();

   protected native float nativeGetCogZ();

   protected native float nativeGetMoiX();

   protected native float nativeGetMoiY();

   protected native float nativeGetMoiZ();

   public void prerender(Camera var1) {
      if (!this.lastURL.equals(this.url.toString()) || this.avatarSwitchPending) {
         this.lastURL = new String(this.url.toString());
         System.out.println("Analyze shape " + this.lastURL);
         this.nativeAnalyzeShape(this.clumpID, this.mass);
         this.tirePositions = new Point3[4];

         for (int var2 = 0; var2 < 4; var2++) {
            this.tirePositions[var2] = new Point3(this.nativeGetTirePosX(var2), this.nativeGetTirePosY(var2), this.nativeGetTirePosZ(var2));
         }

         this.centerOfGravity = new Point3(this.nativeGetCogX(), this.nativeGetCogY(), this.nativeGetCogZ());
         this.centerOfGravity.x = this.centerOfGravity.x + this.adjustCogX;
         this.centerOfGravity.y = this.centerOfGravity.y + this.adjustCogY;
         this.centerOfGravity.z = this.centerOfGravity.z + this.adjustCogZ;
         this.momentsOfInertia = new Point3(this.nativeGetMoiX(), this.nativeGetMoiY(), this.nativeGetMoiZ());
         if (this.avatarSwitchPending) {
            Pilot var8 = Console.getActive().getPilot();
            if (var8 instanceof HoloPilot) {
               HoloPilot var3 = (HoloPilot)var8;
               Drone var4 = var3.getInternalDrone();
               if (var4 != null && var4 instanceof PosableDrone) {
                  PosableDrone var5 = (PosableDrone)var4;
                  PosableShape var6 = var5.getInternalPosableShape();
                  if (var6 != null && var6 instanceof VehicleShape) {
                     VehicleShape var7 = (VehicleShape)var6;
                     var7.fixedCamera = this.fixedCamera;
                     var7.camX = this.camX;
                     var7.camY = this.camY;
                     var7.camZ = this.camZ;
                     var7.camRoll = this.camRoll;
                     var7.camPitch = this.camPitch;
                     var7.camYaw = this.camYaw;
                     var7.camAimX = this.camAimX;
                     var7.camAimY = this.camAimY;
                     var7.camAimZ = this.camAimZ;
                     var7.eyeHeight = this.eyeHeight;
                     var3.setOutsideCameraMode(99, 4);
                  }
               }
            }

            this.avatarSwitchPending = false;
         }
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Prompt String"));
            } else if (var3 == 1) {
               var5 = new String(this.promptString);
            } else if (var3 == 2) {
               this.promptString = new String((String)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Rear End Ratio"));
            } else if (var3 == 1) {
               var5 = new Float(this.rearEndRatio);
            } else if (var3 == 2) {
               this.rearEndRatio = (Float)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Frontal Area (sq.ft.)"));
            } else if (var3 == 1) {
               var5 = new Float(this.frontalArea);
            } else if (var3 == 2) {
               this.frontalArea = (Float)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Wheel Diameter (ft.)"));
            } else if (var3 == 1) {
               var5 = new Float(this.wheelDiameter);
            } else if (var3 == 2) {
               this.wheelDiameter = (Float)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Coefficient of Kinetic Friction"));
            } else if (var3 == 1) {
               var5 = new Float(this.coeffKineticFriction);
            } else if (var3 == 2) {
               this.coeffKineticFriction = (Float)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Coefficient of Static Friction"));
            } else if (var3 == 1) {
               var5 = new Float(this.coeffStaticFriction);
            } else if (var3 == 2) {
               this.coeffStaticFriction = (Float)var4;
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Mass (slugs)"));
            } else if (var3 == 1) {
               var5 = new Float(this.mass);
            } else if (var3 == 2) {
               this.mass = (Float)var4;
            }
            break;
         case 7:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "1st Gear Ratio"));
            } else if (var3 == 1) {
               var5 = new Float(this.gearRatio1);
            } else if (var3 == 2) {
               this.gearRatio1 = (Float)var4;
            }
            break;
         case 8:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "2nd Gear Ratio"));
            } else if (var3 == 1) {
               var5 = new Float(this.gearRatio2);
            } else if (var3 == 2) {
               this.gearRatio2 = (Float)var4;
            }
            break;
         case 9:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "3rd Gear Ratio"));
            } else if (var3 == 1) {
               var5 = new Float(this.gearRatio3);
            } else if (var3 == 2) {
               this.gearRatio3 = (Float)var4;
            }
            break;
         case 10:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "4th Gear Ratio"));
            } else if (var3 == 1) {
               var5 = new Float(this.gearRatio4);
            } else if (var3 == 2) {
               this.gearRatio4 = (Float)var4;
            }
            break;
         case 11:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "5th Gear Ratio"));
            } else if (var3 == 1) {
               var5 = new Float(this.gearRatio5);
            } else if (var3 == 2) {
               this.gearRatio5 = (Float)var4;
            }
            break;
         case 12:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Max. Engine Torque (ft-lbs)"));
            } else if (var3 == 1) {
               var5 = new Float(this.maxEngineTorque);
            } else if (var3 == 2) {
               this.maxEngineTorque = (Float)var4;
            }
            break;
         case 13:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Tire Adhesive Limit"));
            } else if (var3 == 1) {
               var5 = new Float(this.tireAdhesiveLimit);
            } else if (var3 == 2) {
               this.tireAdhesiveLimit = (Float)var4;
            }
            break;
         case 14:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Shocks Damping Coefficient"));
            } else if (var3 == 1) {
               var5 = new Float(this.shockDampingCoeff);
            } else if (var3 == 2) {
               this.shockDampingCoeff = (Float)var4;
            }
            break;
         case 15:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Shock Length (ft)"));
            } else if (var3 == 1) {
               var5 = new Float(this.shockLength);
            } else if (var3 == 2) {
               this.shockLength = (Float)var4;
            }
            break;
         case 16:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Torque Peak (RPM)"));
            } else if (var3 == 1) {
               var5 = new Float(this.rpmTorquePeak);
            } else if (var3 == 2) {
               this.rpmTorquePeak = (Float)var4;
            }
            break;
         case 17:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Idle RPM"));
            } else if (var3 == 1) {
               var5 = new Float(this.idleRPM);
            } else if (var3 == 2) {
               this.idleRPM = (Float)var4;
            }
            break;
         case 18:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Transmission Type"), "Automatic", "Manual");
            } else if (var3 == 1) {
               var5 = new Boolean(this.stickShift);
            } else if (var3 == 2) {
               this.stickShift = (Boolean)var4;
            }
            break;
         case 19:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Gas (Gall., -1 for infinite)"));
            } else if (var3 == 1) {
               var5 = new Float(this.initialGas);
            } else if (var3 == 2) {
               this.initialGas = (Float)var4;
            }
            break;
         case 20:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Center of gravity X adjust"));
            } else if (var3 == 1) {
               var5 = new Float(this.adjustCogX);
            } else if (var3 == 2) {
               this.adjustCogX = (Float)var4;
            }
            break;
         case 21:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Center of gravity Y adjust"));
            } else if (var3 == 1) {
               var5 = new Float(this.adjustCogY);
            } else if (var3 == 2) {
               this.adjustCogY = (Float)var4;
            }
            break;
         case 22:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Center of gravity Z adjust"));
            } else if (var3 == 1) {
               var5 = new Float(this.adjustCogZ);
            } else if (var3 == 2) {
               this.adjustCogZ = (Float)var4;
            }
            break;
         case 23:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Use fixed camera"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.fixedCamera);
            } else if (var3 == 2) {
               this.fixedCamera = (Boolean)var4;
            }
            break;
         case 24:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera X offset"));
            } else if (var3 == 1) {
               var5 = new Float(this.camX);
            } else if (var3 == 2) {
               this.camX = (Float)var4;
            }
            break;
         case 25:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Y offset"));
            } else if (var3 == 1) {
               var5 = new Float(this.camY);
            } else if (var3 == 2) {
               this.camY = (Float)var4;
            }
            break;
         case 26:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Z offset"));
            } else if (var3 == 1) {
               var5 = new Float(this.camZ);
            } else if (var3 == 2) {
               this.camZ = (Float)var4;
            }
            break;
         case 27:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Roll"));
            } else if (var3 == 1) {
               var5 = new Float(this.camRoll);
            } else if (var3 == 2) {
               this.camRoll = (Float)var4;
            }
            break;
         case 28:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Pitch"));
            } else if (var3 == 1) {
               var5 = new Float(this.camPitch);
            } else if (var3 == 2) {
               this.camPitch = (Float)var4;
            }
            break;
         case 29:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Yaw"));
            } else if (var3 == 1) {
               var5 = new Float(this.camYaw);
            } else if (var3 == 2) {
               this.camYaw = (Float)var4;
            }
            break;
         case 30:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Aim X"));
            } else if (var3 == 1) {
               var5 = new Float(this.camAimX);
            } else if (var3 == 2) {
               this.camAimX = (Float)var4;
            }
            break;
         case 31:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Aim Y"));
            } else if (var3 == 1) {
               var5 = new Float(this.camAimY);
            } else if (var3 == 2) {
               this.camAimY = (Float)var4;
            }
            break;
         case 32:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Aim Z"));
            } else if (var3 == 1) {
               var5 = new Float(this.camAimZ);
            } else if (var3 == 2) {
               this.camAimZ = (Float)var4;
            }
            break;
         case 33:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Camera Eye Height"));
            } else if (var3 == 1) {
               var5 = new Float(this.eyeHeight);
            } else if (var3 == 2) {
               this.eyeHeight = (Float)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 34, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      var1.saveBoolean(this.fixedCamera);
      var1.saveFloat(this.camX);
      var1.saveFloat(this.camY);
      var1.saveFloat(this.camZ);
      var1.saveFloat(this.camRoll);
      var1.saveFloat(this.camPitch);
      var1.saveFloat(this.camYaw);
      var1.saveFloat(this.camAimX);
      var1.saveFloat(this.camAimY);
      var1.saveFloat(this.camAimZ);
      var1.saveFloat(this.eyeHeight);
      var1.saveString(this.promptString);
      var1.saveFloat(this.rearEndRatio);
      var1.saveFloat(this.frontalArea);
      var1.saveFloat(this.wheelDiameter);
      var1.saveFloat(this.coeffKineticFriction);
      var1.saveFloat(this.coeffStaticFriction);
      var1.saveFloat(this.mass);
      var1.saveFloat(this.gearRatio1);
      var1.saveFloat(this.gearRatio2);
      var1.saveFloat(this.gearRatio3);
      var1.saveFloat(this.gearRatio4);
      var1.saveFloat(this.gearRatio5);
      var1.saveFloat(this.maxEngineTorque);
      var1.saveFloat(this.tireAdhesiveLimit);
      var1.saveFloat(this.shockDampingCoeff);
      var1.saveFloat(this.shockLength);
      var1.saveFloat(this.rpmTorquePeak);
      var1.saveFloat(this.idleRPM);
      var1.saveBoolean(this.stickShift);
      var1.saveFloat(this.initialGas);
      var1.saveFloat(this.adjustCogX);
      var1.saveFloat(this.adjustCogY);
      var1.saveFloat(this.adjustCogZ);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 2:
            this.fixedCamera = var1.restoreBoolean();
            this.camX = var1.restoreFloat();
            this.camY = var1.restoreFloat();
            this.camZ = var1.restoreFloat();
            this.camRoll = var1.restoreFloat();
            this.camPitch = var1.restoreFloat();
            this.camYaw = var1.restoreFloat();
            this.camAimX = var1.restoreFloat();
            this.camAimY = var1.restoreFloat();
            this.camAimZ = var1.restoreFloat();
            this.eyeHeight = var1.restoreFloat();
         case 1:
            this.promptString = var1.restoreString();
            this.rearEndRatio = var1.restoreFloat();
            this.frontalArea = var1.restoreFloat();
            this.wheelDiameter = var1.restoreFloat();
            this.coeffKineticFriction = var1.restoreFloat();
            this.coeffStaticFriction = var1.restoreFloat();
            this.mass = var1.restoreFloat();
            this.gearRatio1 = var1.restoreFloat();
            this.gearRatio2 = var1.restoreFloat();
            this.gearRatio3 = var1.restoreFloat();
            this.gearRatio4 = var1.restoreFloat();
            this.gearRatio5 = var1.restoreFloat();
            this.maxEngineTorque = var1.restoreFloat();
            this.tireAdhesiveLimit = var1.restoreFloat();
            this.shockDampingCoeff = var1.restoreFloat();
            this.shockLength = var1.restoreFloat();
            this.rpmTorquePeak = var1.restoreFloat();
            this.idleRPM = var1.restoreFloat();
            this.stickShift = var1.restoreBoolean();
            this.initialGas = var1.restoreFloat();
            this.adjustCogX = var1.restoreFloat();
            this.adjustCogY = var1.restoreFloat();
            this.adjustCogZ = var1.restoreFloat();
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}
