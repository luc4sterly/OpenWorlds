package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.console.NoWebControlException;
import NET.worlds.console.OkCancelDialog;
import NET.worlds.console.WebControl;
import NET.worlds.console.WebControlImp;
import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.CacheEntry;
import NET.worlds.network.Galaxy;
import NET.worlds.network.URL;

class WorldScriptToolkitImp extends WorldScriptToolkit {
   public int getTime() {
      return Std.getSynchronizedTime();
   }

   public void teleport(String var1, boolean var2) {
      TeleportAction.teleport(var1, null, false, var2);
   }

   public float getPilotX() {
      Pilot var1 = Pilot.getActive();
      return var1 != null ? var1.getX() : 0.0F;
   }

   public float getPilotY() {
      Pilot var1 = Pilot.getActive();
      return var1 != null ? var1.getY() : 0.0F;
   }

   public float getPilotYaw() {
      Pilot var1 = Pilot.getActive();
      return var1 != null ? 360.0F - var1.getYaw() : 0.0F;
   }

   private SmoothDriver getSmoothDriver() {
      Pilot var1 = Pilot.getActive();
      if (var1 != null && var1 instanceof HoloPilot) {
         HoloPilot var2 = (HoloPilot)var1;
         return var2.getSmoothDriver();
      } else {
         return null;
      }
   }

   public float getWalkFriction() {
      SmoothDriver var1 = this.getSmoothDriver();
      return var1 != null ? var1.getVelocityDamping() : 0.0F;
   }

   public void setWalkFriction(float var1) {
      SmoothDriver var2 = this.getSmoothDriver();
      if (var2 != null) {
         var2.setVelocityDamping(var1);
      }
   }

   public void walkTo(float var1, float var2, float var3, float var4) {
      Pilot var5 = Pilot.getActive();
      if (var5 != null && var5 instanceof HoloPilot) {
         HoloPilot var6 = (HoloPilot)var5;
         var6.walkTo(new Point2(var1, var2), var3, var4);
      }
   }

   public void walkTo(float var1, float var2, float var3) {
      Pilot var4 = Pilot.getActive();
      if (var4 != null && var4 instanceof HoloPilot) {
         HoloPilot var5 = (HoloPilot)var4;
         var5.walkTo(new Point2(var1, var2), var3);
      }
   }

   public void walkTo(WorldScript var1, float var2, float var3, float var4, float var5) {
      Pilot var6 = Pilot.getActive();
      if (var6 != null && var6 instanceof HoloPilot) {
         HoloPilot var7 = (HoloPilot)var6;
         var7.walkTo(new Point2(var2, var3), var4, var5);
         var7.addCallback(var1);
      }
   }

   public void showWebPage(String var1) {
      this.showWebPage(var1, 100, 100);
   }

   public void showWebPage(String var1, int var2, int var3) {
      Console var4 = Console.getActive();
      if (var4 != null && var4 instanceof DefaultConsole) {
         DefaultConsole var5 = (DefaultConsole)var4;

         try {
            WebControl var6 = new WebControl(var5.getRender(), var2, var3, true, false, false);
            var6.activate();
            var6.setURL(var1);
         } catch (NoWebControlException var7) {
            new SendURLAction(var1).doIt();
         }
      }
   }

   public void showExternalWebPage(String var1) {
      new SendURLAction(var1).doIt();
   }

   public void showAdBanner(String var1, int var2, int var3) {
      Pilot var4 = Pilot.getActive();
      if (var4 != null) {
         World var5 = var4.getWorld();
         if (var5 != null) {
            var5.setHasAdBanner(true);
            var5.setBannerURL(var1);
            var5.setBannerWidth(var2);
            var5.setBannerHeight(var3);
            var5.setupAdBanner();
         }
      }
   }

   public Object playSound(String var1, int var2) {
      Sound var3 = new Sound(URL.make(var1));
      SoundPlayer var4 = null;
      if (var1.toLowerCase().endsWith(".wav")) {
         var4 = new WavSoundPlayer(var3);
      } else {
         var4 = new WMPSoundPlayer(var3);
      }

      var4.start(var2);
      return var4;
   }

   public boolean serviceSound(Object var1) {
      if (!(var1 instanceof SoundPlayer)) {
         System.out.println("Error - invalid handle passed to serviceSound");
         return false;
      } else {
         SoundPlayer var2 = (SoundPlayer)var1;
         return var2.getState() == 0;
      }
   }

   public void stopSound(Object var1) {
      if (!(var1 instanceof SoundPlayer)) {
         System.out.println("Error - invalid handle passed to stopSound");
      } else {
         SoundPlayer var2 = (SoundPlayer)var1;
         var2.stop();
      }
   }

   public String expandURLMacros(String var1) {
      return WebControlImp.processURL(var1);
   }

   public int getIniInt(String var1, int var2) {
      return IniFile.gamma().getIniInt(var1, var2);
   }

   public String getIniString(String var1, String var2) {
      return IniFile.gamma().getIniString(var1, var2);
   }

   public void setIniInt(String var1, int var2) {
      IniFile.gamma().setIniInt(var1, var2);
   }

   public void setIniString(String var1, String var2) {
      IniFile.gamma().setIniString(var1, var2);
   }

   public int getClientVersion() {
      return Std.getVersion();
   }

   public void messageBox(String var1, String var2) {
      Console var3 = Console.getActive();
      if (var3 != null) {
         new OkCancelDialog(Console.getFrame(), null, var2, null, Console.message("OK"), var1, true);
      }
   }

   public Object yesNoDialog(String var1, String var2, String var3, String var4, WorldScript var5) {
      Console var6 = Console.getActive();
      return var6 == null ? null : new OkCancelDialog(Console.getFrame(), var5, var2, var4, var3, var1);
   }

   public void printToChat(String var1) {
      Console var2 = Console.getActive();
      if (var2 != null) {
         Console.println(var1);
      }
   }

   public boolean watchVisibility(Object var1) {
      if (var1 == null) {
         return false;
      }

      if (!(var1 instanceof WObject)) {
         return false;
      }

      WObject var2 = (WObject)var1;
      Room var3 = var2.getRoom();
      if (var3 == null) {
         return false;
      }

      var3.addPrerenderHandler(var2);
      return true;
   }

   public int getVideoWallStatus(Object var1) {
      if (var1 != null && var1 instanceof VideoWall) {
         VideoWall var2 = (VideoWall)var1;
         return var2.getState();
      } else {
         return -1;
      }
   }

   public boolean playVideo(Object var1, int var2) {
      if (var1 != null && var1 instanceof VideoWall) {
         VideoWall var3 = (VideoWall)var1;
         VideoSurface var4 = var3.getVideoSurface();
         if (var4 == null) {
            return false;
         }

         var4.play(var2);
         return true;
      } else {
         return false;
      }
   }

   public boolean stopVideo(Object var1) {
      if (var1 != null && var1 instanceof VideoWall) {
         VideoWall var2 = (VideoWall)var1;
         VideoSurface var3 = var2.getVideoSurface();
         if (var3 == null) {
            return false;
         }

         var3.stop();
         return true;
      } else {
         return false;
      }
   }

   public boolean setVideoURL(Object var1, String var2, int var3, int var4) {
      if (var1 != null && var1 instanceof VideoWall) {
         VideoWall var5 = (VideoWall)var1;
         var5.changeURL(var2, var3, var4);
         return true;
      } else {
         return false;
      }
   }

   public boolean setWebWallURL(Object var1, String var2) {
      if (var1 != null && var1 instanceof WebPageWall) {
         WebPageWall var3 = (WebPageWall)var1;
         WebControlImp var4 = var3.getWebControlImp();
         return var4 != null && var2 != null ? var4.setURL(var2) : false;
      } else {
         return false;
      }
   }

   public boolean setWebWallURL(Object var1, String var2, String var3) {
      if (var1 != null && var1 instanceof WebPageWall) {
         WebPageWall var4 = (WebPageWall)var1;
         WebControlImp var5 = var4.getWebControlImp();
         return var5 != null && var2 != null ? var5.setURL(var2, var3) : false;
      } else {
         return false;
      }
   }

   public boolean animateBot(Object var1, String var2) {
      if (!(var1 instanceof PosableShape)) {
         return false;
      }

      PosableShape var3 = (PosableShape)var1;
      var3.animate(var2);
      return true;
   }

   public boolean setShapeURL(Object var1, String var2) {
      if (!(var1 instanceof Shape)) {
         return false;
      }

      Shape var3 = (Shape)var1;
      var3.setURL(URL.make(var2));
      return true;
   }

   public Object findObjectInRoom(String var1) {
      Room var2 = Pilot.getActive().getRoom();
      if (var2 != null) {
         DeepEnumeration var3 = new DeepEnumeration();
         var2.getChildren(var3);

         while (var3.hasMoreElements()) {
            SuperRoot var4 = (SuperRoot)var3.nextElement();
            if (var4.getName().equals(var1)) {
               return var4;
            }
         }
      }

      return null;
   }

   public void walkObjectTo(WorldScript var1, Object var2, float var3, float var4, float var5, float var6) {
      if (var2 instanceof WObject) {
         HandsOffDriver var7 = new HandsOffDriver();
         var7.setDestPos(new Point2(var3, var4), var5, var6);
         var7.setTarget((Transform)var2);
         var7.addCallback(var1);
         ((WObject)var2).addHandler(var7);
      }
   }

   public void moveObjectTo(Object var1, float var2, float var3, float var4) {
      if (var1 instanceof Transform) {
         Transform var5 = (Transform)var1;
         var5.moveTo(var2, var3, var5.getZ()).yaw(var4);
      }
   }

   public void moveObjectTo(Object var1, float var2, float var3, float var4, float var5) {
      if (var1 instanceof Transform) {
         Transform var6 = (Transform)var1;
         var6.moveTo(var2, var3, var4).yaw(var5);
      }
   }

   public void moveObjectTo(Object var1, float var2, float var3, float var4, float var5, float var6) {
      if (var1 instanceof Transform) {
         Transform var7 = (Transform)var1;
         var7.moveTo(var2, var3, var4).yaw(var5);
         var7.scale(var6);
      }
   }

   public boolean isLoggedIn() {
      Console var1 = Console.getActive();
      if (var1 != null) {
         Galaxy var2 = var1.getGalaxy();
         if (var2 != null) {
            return var2.getOnline();
         }
      }

      return false;
   }

   public int getConcurrentDownloads() {
      return CacheEntry.getConcurrentDownloads();
   }

   public boolean getIsVIP() {
      Console var1 = Console.getActive();
      return var1 != null ? var1.getVIP() : false;
   }

   public void setAdCube(boolean var1, boolean var2, String var3, String var4) {
      Pilot var5 = Pilot.getActive();
      if (var5 != null) {
         World var6 = var5.getWorld();
         if (var6 != null) {
            var6.setHasClickableAdCube(var1);
            var6.setAdCubeFormatIsGif(var2);
            var6.setAdCubeBaseURL(var3);
            var6.setDefaultAdCubeURL(var4);
         }
      }
   }
}
