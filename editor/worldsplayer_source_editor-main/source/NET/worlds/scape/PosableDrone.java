package NET.worlds.scape;

import NET.worlds.console.BBAnimateDroneCommand;
import NET.worlds.console.BlackBox;
import NET.worlds.console.Console;
import NET.worlds.core.IniFile;
import NET.worlds.network.ObjID;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.Enumeration;
import java.util.Vector;

public class PosableDrone extends Drone implements FrameHandler {
   static PosableDroneLoader droneLoader = new PosableDroneLoader();
   public static boolean threadDroneLoads = IniFile.gamma().getIniInt("ThreadDroneLoading", 0) == 1;
   static boolean droneLoaderStarted = false;
   private PosableShape pendingShape = null;
   private static Object classCookie = new Object();

   public void SetPendingShape(PosableShape var1) {
      this.pendingShape = var1;
   }

   public boolean handle(FrameEvent var1) {
      if (this.pendingShape != null) {
         PosableShape var2 = this.getInternalPosableShape();
         if (var2 != null) {
            var2.detach();
         }

         this.add(this.pendingShape);
         this.pendingShape = null;
      }

      return super.handle(var1);
   }

   public PosableDrone(ObjID var1, WorldServer var2, URL var3) {
      super(var1, var2);
      this.makeFigure(var3);
   }

   public PosableDrone(ObjID var1, WorldServer var2) {
      super(var1, var2);
      this.loadInit();
   }

   public PosableDrone() {
   }

   public void loadInit() {
      this.makeFigure(PosableShape.getDefaultURL());
   }

   public synchronized URL getPosableShapeURL() {
      PosableShape var1 = this.getInternalPosableShape();
      return var1 == null ? null : var1.getURL();
   }

   public Drone setAvatarNow(URL var1) {
      if (!this.shouldBeMuted() && (var1.endsWith(".rwx") || var1.endsWith(".rwg"))) {
         if (this.shouldBeForcedHuman()) {
            var1 = PosableShape.getHuman(var1);
         }

         var1 = PosableShape.getPermitted(var1, this.getWorld());
         PosableShape var2 = this.getInternalPosableShape();
         if (var2 != null) {
            if (var1.equals(var2.getURL())) {
               return this;
            }

            var2.detach();
         }

         this.makeFigure(var1);
         return this;
      } else {
         return super.setAvatarNow(var1);
      }
   }

   public void makeFigure(URL var1) {
      boolean var2 = false;
      if (Console.getActive() != null && Console.getActive().getPilot() != null && Console.getActive().getPilot().hasContents()) {
         var2 = Console.getActive().getPilot().contentsContain(this);
      }

      if (!var2) {
         var2 = this.isPilotDrone(var1);
      }

      boolean var3 = false;

      try {
         if (!PosableDroneLoader.avatarExistsLocally(var1)) {
            var3 = true;
         } else {
            var3 = !var2 && !var1.toString().equals(PosableShape.getDefaultURL().toString());
         }
      } catch (MalformedURLException var5) {
         var3 = false;
      }

      if (var3 && threadDroneLoads) {
         if (!droneLoaderStarted) {
            droneLoaderStarted = true;
            Thread var7 = new Thread(droneLoader, "DroneLoaderDaemon");
            var7.setDaemon(true);
            var7.setPriority(1);
            var7.start();
         }

         droneLoader.load(this, var1);
      } else {
         PosableShape var4;
         if (VehicleShape.isVehicle(var1)) {
            var4 = new VehicleShape(var1);
         } else {
            var4 = new PosableShape(var1);
         }

         var4.setVisible(true);
         var4.setBumpable(false);
         if (!this.isPilotDrone(var1)) {
            var4.enableLOD(true);
         }

         this.add(var4);
      }
   }

   public PosableShape getInternalPosableShape() {
      Enumeration var1 = this.getContents();

      while (var1.hasMoreElements()) {
         Object var2 = var1.nextElement();
         if (var2 instanceof PosableShape) {
            return (PosableShape)var2;
         }
      }

      return null;
   }

   public boolean isPilotDrone(URL var1) {
      return Console.getActive() != null && Console.getActive().pendingPilot.equals(var1.toString());
   }

   public float animate(String var1) {
      super.animate(var1);
      BlackBox.getInstance().submitEvent(new BBAnimateDroneCommand(this.getName(), var1));
      PosableShape var2 = this.getInternalPosableShape();
      return var2 != null ? var2.animate(var1) : 0.0F;
   }

   public Vector getAnimationList() {
      PosableShape var1 = this.getInternalPosableShape();
      return var1 != null ? var1.getAnimationList() : super.getAnimationList();
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
         case 1:
            if (var2 == 0) {
               this.restoreStateDrone(var1);
            } else {
               super.restoreState(var1);
            }

            var1.setOldFlag();
            this.makeFigure(URL.make("avatar:" + var1.restoreString() + ".rwx"));
            break;
         case 2:
            super.restoreState(var1);
            break;
         default:
            throw new TooNewException();
      }
   }
}
