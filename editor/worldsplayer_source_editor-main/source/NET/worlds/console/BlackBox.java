package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.Galaxy;
import NET.worlds.network.URL;
import NET.worlds.scape.Camera;
import NET.worlds.scape.Drone;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.FrameHandler;
import NET.worlds.scape.HoloPilot;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Point3Temp;
import NET.worlds.scape.Postrenderable;
import NET.worlds.scape.Sound;
import NET.worlds.scape.SoundPlayer;
import NET.worlds.scape.WMPSoundPlayer;
import NET.worlds.scape.WavSoundPlayer;
import java.awt.FileDialog;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Enumeration;
import java.util.Properties;
import java.util.Vector;

public class BlackBox implements BlackBoxCallback, FrameHandler, Postrenderable {
   private static BlackBox instance = new BlackBox();
   private boolean disable = IniFile.gamma().getIniInt("disableRecorder", 0) == 1;
   private String autoFile = null;
   private SoundPlayer autoSound = null;
   static final int PLAYING = 0;
   static final int RECORDING = 1;
   static final int STOPPED = 2;
   private int state = 2;
   static final int CHATCMD = 0;
   static final int TELEPORTCMD = 1;
   static final int ACTORLISTCMD = 2;
   static final int MOVEDRONECMD = 3;
   static final int OBJCLICKEDCMD = 4;
   static final int APPEARDRONECMD = 5;
   static final int DISAPPEARDRONECMD = 6;
   static final int DRONEBITMAPCMD = 7;
   static final int DRONEDELTACMD = 8;
   static final int ANIMATECMD = 9;
   public static final String PilotID = "@Pilot";
   private Vector commandList = new Vector();
   private int commandIdx;
   private long basetime;
   static final int NOCMD = 0;
   static final int PLAYCMD = 1;
   static final int RECCMD = 2;
   static final int STOPCMD = 3;
   private int pendingCommand = 0;
   static final int FILE_VERSION = 1;

   public static BlackBox getInstance() {
      return instance;
   }

   private BlackBox() {
      this.autoFile = IniFile.override().getIniString("AutoPlaybackFile", "");
      if (!this.autoFile.equals("")) {
         this.play();
      } else {
         this.autoFile = null;
      }

      String var1 = IniFile.override().getIniString("AutoPlaybackSound", "");
      if (!var1.equals("")) {
         Sound var2 = new Sound(URL.make(var1));
         if (var1.toLowerCase().endsWith(".wav")) {
            this.autoSound = new WavSoundPlayer(var2);
         } else {
            this.autoSound = new WMPSoundPlayer(var2);
         }
      }
   }

   public void finalize() {
      this.stop();
   }

   public void postrender(Camera var1) {
      if (!this.disable) {
         if (Std.getSynchronizedTime() % 2 != 0) {
            if (this.isPlaying()) {
               var1.nDrawText(Console.message("PLAY"), 10, 10, 18, 16711680);
            } else if (this.isRecording()) {
               var1.nDrawText(Console.message("REC"), 10, 10, 18, 16711680);
            }
         }
      }
   }

   public synchronized void record() {
      this.pendingCommand = 2;
   }

   private boolean doRecord() {
      if (this.state != 2) {
         this.stop();
      }

      this.commandList.removeAllElements();
      this.basetime = Std.getFastTime();
      String var1 = "";
      Pilot var2 = Pilot.getActive();
      if (var2 == null) {
         return false;
      }

      var1 = var2.getURL();
      this.state = 1;
      this.submitEvent(new BBTeleportCommand(var1));
      URL var3 = Console.getActive().getAvatarName();
      if (var3 != null) {
         this.submitEvent(new BBDroneBitmapCommand("@Pilot", var3.toString()));
      }

      ArmyOfZombies.instance().zombify();
      return true;
   }

   public synchronized void play() {
      this.pendingCommand = 1;
   }

   public synchronized void play(URL var1) {
      this.autoFile = var1.unalias();
      this.pendingCommand = 1;
   }

   private void doPlay() {
      if (this.state != 2) {
         this.stop();
      }

      if (this.restore()) {
         Galaxy.forceOffline(false);
         Console.getActive().setChatname("");
         Pilot var1 = Pilot.getActive();
         if (var1 instanceof HoloPilot) {
            HoloPilot var2 = (HoloPilot)var1;
            var2.removeSmoothDriver();
         }

         if (this.autoSound != null) {
            this.autoSound.start(1);
            this.autoSound = null;
         }

         this.commandIdx = 0;
         this.basetime = Std.getFastTime();
         this.state = 0;
      }
   }

   public void commandCompleted(BlackBoxCommand var1, boolean var2) {
      if (var2) {
         this.commandIdx++;
      } else {
         System.out.println("Failed command!");
         this.stop();
      }
   }

   public boolean handle(FrameEvent var1) {
      if (this.disable) {
         return false;
      }

      switch (this.pendingCommand) {
         case 1:
            this.doPlay();
            this.pendingCommand = 0;
            break;
         case 2:
            this.doRecord();
            this.pendingCommand = 0;
            break;
         case 3:
            this.doStop();
            this.pendingCommand = 0;
      }

      if (this.isPlaying()) {
         if (this.commandIdx >= this.commandList.size()) {
            this.stop();
            return false;
         }

         long var2 = Std.getFastTime() - this.basetime;
         BlackBoxCommand var4 = (BlackBoxCommand)this.commandList.elementAt(this.commandIdx);
         if (var4.startTime <= var2) {
            var4.execute(this);
         }

         Pilot var5 = Pilot.getActive();
         if (var5 instanceof HoloPilot) {
            HoloPilot var6 = (HoloPilot)var5;
            Drone var7 = var6.getInternalDrone();
            if (var7 != null) {
               var7.interpolate(var1.time, 2000, var5);
               float var8 = var6.getSmoothDriver().getEyeHeight();
               var5.setZ(var8 + var5.getZ());
               Point3Temp var9 = var7.getPosition();
            }
         }
      }

      return false;
   }

   public boolean isRecording() {
      return this.state == 1;
   }

   public boolean isPlaying() {
      return this.state == 0;
   }

   public void submitEvent(BlackBoxCommand var1) {
      if (!this.disable) {
         if (this.isRecording()) {
            var1.timestamp(this.basetime);
            this.commandList.addElement(var1);
         }
      }
   }

   public synchronized void stop() {
      this.pendingCommand = 3;
   }

   private void doStop() {
      if (this.state != 2) {
         if (this.isRecording()) {
            this.save();
         }

         if (this.isPlaying()) {
            ArmyOfZombies.instance().killZombies();
            Pilot var1 = Pilot.getActive();
            if (var1 instanceof HoloPilot) {
               HoloPilot var2 = (HoloPilot)var1;
               var2.returnSmoothDriver();
            }

            Console var4 = Console.getActive();
            if (var4 instanceof DefaultConsole) {
               DefaultConsole var3 = (DefaultConsole)var4;
               var3.getGalaxy().localForceOnline();
               var3.getGalaxy().waitForConnection(var3);
            }
         }

         this.state = 2;
      }
   }

   private void save() {
      Console.getActive();
      GammaFrame var1 = Console.getFrame();
      Properties var2 = System.getProperties();
      String var3 = var2.getProperty("user.dir");
      FileDialog var4 = new FileDialog(var1, Console.message("Save-recording"), 1);
      var4.setFile("record.rec");
      var4.show();
      String var5 = var4.getFile();
      String var6 = var4.getDirectory();
      var2.remove("user.dir");
      var2.put("user.dir", var3);
      System.setProperties(var2);
      if (var5 != null) {
         File var7 = new File(var6, var5);

         try {
            FileOutputStream var8 = new FileOutputStream(var7);
            DataOutputStream var9 = new DataOutputStream(var8);
            var9.writeInt(1);
            Enumeration var10 = this.commandList.elements();

            while (var10.hasMoreElements()) {
               BlackBoxCommand var11 = (BlackBoxCommand)var10.nextElement();
               var11.save(var9);
            }

            var9.close();
            var8.close();
         } catch (Exception var12) {
            System.out.println(var12);
         }
      }
   }

   private boolean restore() {
      if (this.autoFile != null) {
         this.restoreFile(new File(this.autoFile));
         this.autoFile = null;
         return true;
      }

      Console.getActive();
      GammaFrame var1 = Console.getFrame();
      Properties var2 = System.getProperties();
      String var3 = var2.getProperty("user.dir");
      FileDialog var4 = new FileDialog(var1, Console.message("Load-recording"), 0);
      var4.show();
      String var5 = var4.getFile();
      String var6 = var4.getDirectory();
      var2.remove("user.dir");
      var2.put("user.dir", var3);
      System.setProperties(var2);
      if (var5 == null) {
         return false;
      }

      File var7 = new File(var6, var5);
      this.restoreFile(var7);
      return true;
   }

   private void restoreFile(File var1) {
      this.commandList.removeAllElements();

      try {
         FileInputStream var2 = new FileInputStream(var1);
         DataInputStream var3 = new DataInputStream(var2);
         int var4 = var3.readInt();
         if (var4 != 1) {
            Console.println("Invalid recorder file.");
            return;
         }

         try {
            while (true) {
               int var5 = var3.readInt();
               BlackBoxCommand var6 = null;
               switch (var5) {
                  case 0:
                     var6 = new BBChatCommand();
                     break;
                  case 1:
                     var6 = new BBTeleportCommand();
                     break;
                  case 2:
                  default:
                     System.out.println("Error! Unknown command type.");
                     break;
                  case 3:
                     var6 = new BBMoveDroneCommand();
                     break;
                  case 4:
                     var6 = new BBWObjClickedCommand();
                     break;
                  case 5:
                     var6 = new BBAppearDroneCommand();
                     break;
                  case 6:
                     var6 = new BBDisappearDroneCommand();
                     break;
                  case 7:
                     var6 = new BBDroneBitmapCommand();
                     break;
                  case 8:
                     var6 = new BBDroneDeltaPosCommand();
                     break;
                  case 9:
                     var6 = new BBAnimateDroneCommand();
               }

               if (var6 != null) {
                  var6.load(var3);
                  this.commandList.addElement(var6);
               }
            }
         } catch (EOFException var7) {
            var3.close();
            var2.close();
         }
      } catch (Exception var8) {
         System.out.println(var8);
      }
   }
}
