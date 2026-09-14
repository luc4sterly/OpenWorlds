package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.ProgressDialog;
import NET.worlds.network.URL;
import NET.worlds.scape.BGLoaded;
import NET.worlds.scape.BackgroundLoader;
import NET.worlds.scape.Room;
import NET.worlds.scape.World;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Panel;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;

public class UniversePanel extends Panel implements MainCallback, ImageButtonsCallback, BGLoaded {
   UniverseImage bg;
   int xOff = 0;
   int yOff = 0;
   ImageButtons backButton;
   DefaultConsole owningConsole;
   private static String datName = "universe/universe.dat";
   private static String bgName = "universe/universe.jpg";
   static String lastCacheDat;
   static String lastCacheBg;
   static Object locker = new Object();
   Image offscreen;
   private boolean registered;
   int upDownState;
   int leftRightState;
   int lastKeyTime;
   Vector buttons = new Vector();
   Vector bullets = new Vector();

   public UniversePanel(DefaultConsole var1) {
      this.owningConsole = var1;
      this.setLayout(null);
      this.backButton = new ImageButtons(Console.message("back.gif"), 60, 22, this);
      String var2 = IniFile.override().getIniString("UniverseBgFile", bgName);
      String var3 = IniFile.override().getIniString("UniverseDatFile", datName);
      if (!new File(datName).exists()) {
         lastCacheDat = "";
         if (!ProgressDialog.copyFile("universe.dat", datName)) {
            ProgressDialog.copyFile("../universe.dat", datName);
         }
      }

      this.readUniverseFile(datName);
      if (!new File(bgName).exists()) {
         lastCacheBg = "";
         if (!ProgressDialog.copyFile("universe.jpg", bgName)) {
            ProgressDialog.copyFile("../universe.jpg", bgName);
         }
      }

      this.bg = new UniverseImage(bgName);
      this.add(this.bg);
      Dimension var4 = this.bg.imageSize();
      this.bg.setSize(var4.width, var4.height);
      String var5 = NetUpdate.getUpgradeServerURL();
      BackgroundLoader.get(this, URL.make(var5 + var2));
      BackgroundLoader.get(this, URL.make(var5 + var3));
   }

   private boolean safeCopyFile(String var1) {
      synchronized (locker) {
         if (var1.endsWith("dat") && !var1.equals(lastCacheDat)) {
            lastCacheDat = var1;
            if (ProgressDialog.copyFile(var1, datName)) {
               this.readUniverseFile(datName);
               this.add(this.bg);
               return true;
            }
         } else if (var1.endsWith("jpg") && !var1.equals(lastCacheBg)) {
            lastCacheBg = var1;
            if (ProgressDialog.copyFile(var1, bgName)) {
               this.remove(this.bg);
               this.bg.flushImage();
               this.add(this.bg = new UniverseImage(bgName));
               Dimension var3 = this.bg.imageSize();
               this.bg.setSize(var3.width, var3.height);
               return true;
            }
         }

         return false;
      }
   }

   public void flushImage() {
      this.remove(this.bg);
      this.bg.flushImage();
   }

   public synchronized Object asyncBackgroundLoad(String var1, URL var2) {
      return var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      String var3 = (String)var1;
      if (var3 != null && new File(var3).exists() && this.safeCopyFile(var3)) {
         this.invalidate();
         this.validate();
         this.doLayout();
         this.repaint();
      }

      return false;
   }

   public Room getBackgroundLoadRoom() {
      return null;
   }

   public synchronized void setViewportPos() {
      Dimension var1 = this.getSize();
      Dimension var2 = this.bg.imageSize();
      int var3 = var2.width - var1.width >> 1;
      int var4 = var2.height - var1.height >> 1;
      if (var3 < 0) {
         this.xOff = 0;
      }

      if (var4 < 0) {
         this.yOff = 0;
      }

      int var5 = this.xOff + var3;
      int var6 = this.yOff + var4;
      Dimension var7 = this.backButton.preferredSize();
      this.backButton.setSize(var7);
      this.backButton.setLocation(var1.width - var7.width - 5, var1.height - var7.height - 3);
      this.bg.setLocation(-var5, -var6);
      int var8 = this.buttons.size();

      while (--var8 >= 0) {
         WorldButton var9 = (WorldButton)this.buttons.elementAt(var8);
         var9.setLocation(-var5 + var9.buttonX, -var6 + var9.buttonY);
         WorldButtonBullet var10 = (WorldButtonBullet)this.bullets.elementAt(var8);
         var10.setLocation(-var5 + var10.circleX, -var6 + var10.circleY);
      }
   }

   public void invalidate() {
      super.invalidate();
      this.offscreen = null;
   }

   public void update(Graphics var1) {
      this.paint(var1);
   }

   public synchronized void paint(Graphics var1) {
      this.setViewportPos();
      if (this.offscreen == null) {
         this.offscreen = this.createImage(this.getSize().width, this.getSize().height);
      }

      Graphics var2 = this.offscreen.getGraphics();
      var2.setClip(0, 0, this.getSize().width, this.getSize().height);
      super.paint(var2);

      try {
         var1.drawImage(this.offscreen, 0, 0, this);
      } catch (NullPointerException var4) {
         this.offscreen = null;
      }

      var2.dispose();
      this.startWatch();
   }

   public synchronized void startWatch() {
      if (!this.registered) {
         Main.register(this);
         this.registered = true;
      }
   }

   public synchronized void stopWatch() {
      if (this.registered) {
         Main.unregister(this);
         this.registered = false;
      }
   }

   public void setOffset(int var1, int var2) {
      if (this.owningConsole.isUniverseMode()) {
         Dimension var3 = this.getSize();
         Dimension var4 = this.bg.imageSize();
         int var5 = var4.width - var3.width >> 1;
         int var6 = var4.height - var3.height >> 1;
         var1 += var5;
         var2 += var6;
         if (var1 < 0) {
            var1 = 0;
         } else if (var1 + var3.width > var4.width) {
            var1 = var4.width - var3.width;
         }

         if (var2 < 0) {
            var2 = 0;
         } else if (var2 + var3.height > var4.height) {
            var2 = var4.height - var3.height;
         }

         var1 -= var5;
         var2 -= var6;
         if (var3.width > var4.width) {
            var1 = 0;
         }

         if (var3.height > var4.height) {
            var2 = 0;
         }

         if (var1 != this.xOff || var2 != this.yOff) {
            this.xOff = var1;
            this.yOff = var2;
            this.repaint();
         }
      }
   }

   public void addOffset(int var1, int var2) {
      this.setOffset(this.xOff + var1, this.yOff + var2);
   }

   public boolean keyUp(Event var1, int var2) {
      if (var2 != 1004 && var2 != 1005 && var2 != 1006 && var2 != 1007) {
         return super.keyUp(var1, var2);
      }

      if (this.upDownState != 0 || this.leftRightState != 0) {
         this.mainCallback();
         this.upDownState = 0;
         this.leftRightState = 0;
      }

      return true;
   }

   public synchronized void mainCallback() {
      int var1 = Std.getRealTime();
      int var2 = 0;
      int var3 = 0;
      if (this.upDownState != 0) {
         var3 = this.upDownState * (var1 - this.lastKeyTime) / 5;
      }

      if (this.leftRightState != 0) {
         var2 = this.leftRightState * (var1 - this.lastKeyTime) / 5;
      }

      if (var2 < -50) {
         var2 = -50;
      }

      if (var2 > 50) {
         var2 = 50;
      }

      if (var3 < -50) {
         var3 = -50;
      }

      if (var3 > 50) {
         var3 = 50;
      }

      String var4 = WorldsMarkPart.getCurrentPackageName();
      if (var4 != null && !var4.equals(WorldButton.currentPackageName)) {
         WorldButton.currentPackageName = var4;
         if (var2 == 0 && var3 == 0) {
            this.repaint();
         }
      }

      if (var2 != 0 || var3 != 0) {
         this.addOffset(var2, var3);
      }

      this.lastKeyTime = var1;
      if (this.owningConsole != Console.getActive() || !this.owningConsole.isUniverseMode()) {
         this.stopWatch();
      }
   }

   public synchronized boolean keyDown(Event var1, int var2) {
      boolean var3 = false;
      if (var2 == 1004) {
         if (this.upDownState != -1) {
            this.upDownState = -1;
            var3 = true;
         }
      } else if (var2 == 1005) {
         if (this.upDownState != 1) {
            this.upDownState = 1;
            var3 = true;
         }
      } else if (var2 == 1006) {
         if (this.leftRightState != -1) {
            this.leftRightState = -1;
            var3 = true;
         }
      } else {
         if (var2 != 1007) {
            return super.keyDown(var1, var2);
         }

         if (this.leftRightState != 1) {
            this.leftRightState = 1;
            var3 = true;
         }
      }

      if (var3) {
         this.startWatch();
         this.lastKeyTime = Std.getRealTime() - 20;
      }

      return true;
   }

   private synchronized void readUniverseFile(String var1) {
      this.removeAll();
      this.buttons = new Vector();
      this.bullets = new Vector();
      boolean var2 = IniFile.gamma().getIniInt("ShowAllWorlds", 0) != 0;
      this.add(this.backButton);

      try {
         FileInputStream var3 = new FileInputStream(var1);
         DataInputStream var4 = new DataInputStream(var3);

         String var5;
         while ((var5 = var4.readLine()) != null) {
            StringTokenizer var6 = new StringTokenizer(var5);
            if (var6.hasMoreTokens() && var5.charAt(0) != ';') {
               int var7 = Integer.parseInt(var6.nextToken());
               int var8 = Integer.parseInt(var6.nextToken());
               int var9 = Integer.parseInt(var6.nextToken());
               int var10 = Integer.parseInt(var6.nextToken());
               String var11 = var6.nextToken();
               int var12 = Integer.parseInt(var6.nextToken());
               String var13 = var6.nextToken("").trim();
               Dimension var14 = WorldButton.measure(var13);
               String[] var15 = new String[]{var13};
               boolean var16 = WorldsMarkPart.findPackage(var11) != null;
               if (var2 || var12 == 0 || var12 == 1 && !World.isCloistered() || var12 <= 2 && var16 || var12 == 3 && !World.isWorldsStoreProscribed()) {
                  WorldButton var17 = new WorldButton(var16, var9, var10, var14.width, var14.height, var15, var11, var12, this.owningConsole, this);
                  this.add(var17);
                  this.buttons.addElement(var17);
                  WorldButtonBullet var18 = new WorldButtonBullet(var7, var8, var17);
                  if (var7 > 0 || var8 > 0) {
                     this.add(var18);
                  }

                  this.bullets.addElement(var18);
               }
            }
         }

         var4.close();
         var3.close();
      } catch (FileNotFoundException var19) {
         System.out.println(var19);
      } catch (IOException var20) {
         System.out.println(var20);
      }
   }

   public Object imageButtonsCallback(Component var1, int var2) {
      if (var1 instanceof WorldButton) {
         ((WorldButton)var1).doAction();
      } else if (var1 == this.backButton) {
         this.owningConsole.toggleUniverseMode();
      }

      return null;
   }
}
