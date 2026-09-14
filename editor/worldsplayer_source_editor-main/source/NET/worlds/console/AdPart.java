package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.URL;
import NET.worlds.scape.BGLoaded;
import NET.worlds.scape.BackgroundLoader;
import NET.worlds.scape.Camera;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.LoadedURLSelf;
import NET.worlds.scape.Material;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Rect;
import NET.worlds.scape.Room;
import NET.worlds.scape.SendURLAction;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.Transform;
import NET.worlds.scape.URLSelf;
import NET.worlds.scape.WObject;
import NET.worlds.scape.World;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Point;
import java.io.File;
import java.text.MessageFormat;

public class AdPart extends RenderCanvas implements LoadedURLSelf, BGLoaded {
   private static World world;
   private static Room room;
   private static Material[] faces = new Material[4];
   private static WObject cube;
   private static Transform cubeStart;
   private float angle;
   private int currentFace = -1;
   private int lastAd = -1;
   private boolean lastAdIsRemote = false;
   private boolean initialized;
   URL image0;
   int nextAdNumber;
   int nextLoadTime;
   int lastFrame;
   static boolean cycleAds = IniFile.gamma().getIniInt("CYCLEADS", 1) == 1;

   public AdPart(URL var1) {
      super(new Dimension(130, 130));
      this.image0 = var1;
   }

   private void init() {
      if (!this.initialized) {
         if (world == null) {
            World.load(URL.make("home:ad.world"), this, true);
         } else {
            this.initCamera();
         }
      }
   }

   private void initCamera() {
      this.setCamera(new Camera());
      room.add(this.getCamera());
      this.getCamera().moveTo(room.getDefaultPosition()).spin(room.getDefaultOrientationAxis(), room.getDefaultOrientation());
   }

   public synchronized void loadedURLSelf(URLSelf var1, URL var2, String var3) {
      if (world != null) {
         this.initCamera();
      } else if (var1 == null) {
         Object[] var6 = new Object[]{new String("" + var2)};
         Console.println(MessageFormat.format(Console.message("Error-ad"), var6));
      } else {
         world = (World)var1;
         room = world.getRoom(world.getDefaultRoomName());
         this.initCamera();
         cube = (WObject)SuperRoot.nameSearch(room.getContents(), "Cube");
         if (cube != null) {
            cubeStart = cube.getTransform();

            for (int var4 = 0; var4 < 4; var4++) {
               Rect var5 = (Rect)SuperRoot.nameSearch(cube.getContents(), "Rect" + (var4 + 1));
               if (var5 != null) {
                  faces[var4] = var5.getMaterial();
               }
            }
         }
      }
   }

   private String getAdBaseURL() {
      World var1 = Pilot.getActiveWorld();
      if (var1 == null) {
         return "ads/ad";
      }

      String var2 = var1.getSourceURL().toString();
      return var1.getAdCubeBaseURL();
   }

   public boolean action(Event var1, Object var2) {
      return false;
   }

   public boolean mouseDown(Event var1, int var2, int var3) {
      World var4 = Pilot.getActiveWorld();
      if (var4 == null || !var4.getHasClickableAdCube()) {
         return false;
      }

      if ((var1.modifiers & 12) != 0) {
         return false;
      }

      if (this.nextAdNumber > 1 && this.getAdBaseURL() != null) {
         new SendURLAction(this.getAdBaseURL() + (this.nextAdNumber - 1) + ".html").startBrowser();
      } else {
         new SendURLAction(var4.getDefaultAdCubeURL()).startBrowser();
      }

      return true;
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      return var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      String var3 = (String)var1;
      if (var2 != null != this.lastAdIsRemote) {
         this.lastAd = -1;
      }

      this.lastAdIsRemote = var2 != null;
      if (var3 != null && new File(var3).exists()) {
         var2 = URL.make(var3);
      } else {
         this.lastAd = this.nextAdNumber;
         this.nextAdNumber = 0;
         var2 = this.image0;
      }

      if (++this.currentFace > 3) {
         this.currentFace = 0;
      }

      Material var4 = faces[this.currentFace];
      if (var4 != null) {
         var4.loadTexture(var2);
      }

      if (++this.nextAdNumber == this.lastAd) {
         this.nextAdNumber = 0;
      }

      this.nextLoadTime = Std.getFastTime() + 10000;
      return false;
   }

   public Room getBackgroundLoadRoom() {
      return null;
   }

   public synchronized boolean handle(FrameEvent var1) {
      if (this.getCamera() != null && cube != null) {
         int var2 = Std.getRealTime();
         if (var2 >= this.nextLoadTime) {
            if (this.nextAdNumber == 0) {
               this.syncBackgroundLoad(null, null);
            } else if (cycleAds) {
               String var3 = ".cmp";
               World var4 = Pilot.getActiveWorld();
               if (var4 != null && var4.getAdCubeFormatIsGif()) {
                  var3 = ".gif";
               }

               String var5 = this.getAdBaseURL() + this.nextAdNumber + var3;
               BackgroundLoader.get(this, URL.make(var5));
               this.nextLoadTime = var2 + 10000;
            }
         } else {
            float var7 = (float) (Math.PI / 2) * this.currentFace;
            if (var7 != this.angle) {
               int var9 = var2 - this.lastFrame;
               float var11 = (float) (Math.PI / 4) * (var9 / 1000.0F);
               if (var7 == 0.0F) {
                  var7 = (float) (Math.PI * 2);
               }

               float var6 = var7 - this.angle;
               if (var11 >= var6) {
                  this.angle = (float) (Math.PI / 2) * this.currentFace;
               } else {
                  this.angle += var11;
               }

               cube.setTransform(cubeStart);
               cube.spin(0.0F, 0.0F, -1.0F, this.angle * 180.0F / (float) Math.PI);
            }
         }

         this.lastFrame = var2;
         if (this.checkForWindow(false)) {
            Point var8 = this.getLocationOnScreen();
            Dimension var10 = this.getSize();
            this.getWindow().reShape(var8.x, var8.y, var10.width, var10.height);
            this.getCamera().renderToCanvas();
         }

         return true;
      } else {
         return true;
      }
   }

   public void activate(Console var1, Container var2, Console var3) {
      super.activate(var1, var2, var3);
      this.init();
   }
}
