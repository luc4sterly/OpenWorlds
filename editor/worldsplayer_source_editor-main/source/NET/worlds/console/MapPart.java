package NET.worlds.console;

import NET.worlds.network.URL;
import NET.worlds.scape.BGLoaded;
import NET.worlds.scape.BackgroundLoader;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Room;
import NET.worlds.scape.SendURLAction;
import NET.worlds.scape.TeleportAction;
import NET.worlds.scape.World;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.StringTokenizer;

public class MapPart extends ImageButtons implements FramePart, ImageButtonsCallback, BGLoaded {
   private static final int width = 158;
   private static final int height = 124;
   private URL lastURL;
   private URL mapURL;
   private URL infURL;
   private int filesLoaded;
   private Rectangle[] hotspots;
   private String[] names;
   private String[] locations;
   private int cursedButton;
   private DefaultConsole console;

   public MapPart() {
      this.setHandler(this);
      this.setBackground(true);
      this.setWidth(158);
      this.setHeight(124);
   }

   private synchronized void changeURL(URL var1) {
      this.lastURL = var1;
      String var2 = var1.getAbsolute();
      var2 = var2.substring(0, var2.lastIndexOf(46));
      this.filesLoaded = 0;
      this.setHotspots(new Rectangle[0]);
      this.console.exploreButton.show();
      this.console.relayoutMap();
      this.locations = null;
      this.repaint();
      BackgroundLoader.get(this, this.mapURL = URL.make(var2 + "-map.gif"), true);
      BackgroundLoader.get(this, this.infURL = URL.make(var2 + "-map.inf"), true);
   }

   private boolean readInfo(String var1) {
      DataInputStream var2 = null;

      try {
         var2 = new DataInputStream(new FileInputStream(var1));

         String var3;
         for (int var4 = -1; (var3 = var2.readLine()) != null; var4++) {
            var3 = var3.trim();
            if (var4 == -1) {
               int var18 = Integer.parseInt(var3);
               this.hotspots = new Rectangle[var18];
               this.names = new String[var18];
               this.locations = new String[var18];
            } else {
               StringTokenizer var5 = new StringTokenizer(var3);
               this.hotspots[var4] = new Rectangle(
                  Integer.parseInt(var5.nextToken()),
                  Integer.parseInt(var5.nextToken()),
                  Integer.parseInt(var5.nextToken()),
                  Integer.parseInt(var5.nextToken())
               );
               this.names[var4] = var5.nextToken().replace('_', ' ');
               this.locations[var4] = var5.nextToken();

               while (var5.hasMoreTokens()) {
                  this.locations[var4] = this.locations[var4] + " " + var5.nextToken();
               }
            }
         }

         return true;
      } catch (Exception var15) {
      } finally {
         try {
            if (var2 != null) {
               var2.close();
            }
         } catch (IOException var14) {
         }
      }

      return false;
   }

   private int hasLink(String var1) {
      if (this.locations != null) {
         for (int var2 = 0; var2 < this.locations.length; var2++) {
            if (var1.equals(this.locations[var2])) {
               return var2;
            }
         }
      }

      return -1;
   }

   public synchronized void paint(Graphics var1) {
      if (this.filesLoaded == 2) {
         super.paint(var1);
      }
   }

   public synchronized boolean handleEvent(Event var1) {
      return super.handleEvent(var1);
   }

   public Dimension preferredSize() {
      return new Dimension(158, 124);
   }

   protected Graphics drawButton(Graphics var1, int var2, int var3) {
      Graphics var4 = super.drawButton(var1, var2, var3);
      if (var3 == 2 || var3 == 3) {
         this.cursedButton = var2;
         if (var2 != -1 && this.console != null) {
            this.console.overrideStatusMsg(this.names[var2]);
         }
      } else if (var3 == 1 && var2 == this.cursedButton) {
         this.cursedButton = -1;
         if (this.console != null) {
            this.console.overrideStatusMsg(null);
         }
      }

      return var4;
   }

   public synchronized Object imageButtonsCallback(Component var1, int var2) {
      String var3 = this.locations[var2];
      if (var3.startsWith("pnm:")) {
         new SendURLAction(var3).startBrowser();
         return null;
      }

      if (var3.equals("system:universe")) {
         this.console.toggleUniverseMode();
         return null;
      }

      if (var3.charAt(0) == '-') {
         var3 = var3.substring(1);
      } else {
         var3 = this.lastURL.getAbsolute() + "#" + var3;
      }

      TeleportAction.teleport(var3, null);
      return null;
   }

   public void activate(Console var1, Container var2, Console var3) {
      this.console = (DefaultConsole)var1;
   }

   public void deactivate() {
   }

   public synchronized boolean handle(FrameEvent var1) {
      Pilot var2 = Pilot.getActive();
      if (var2 != null) {
         World var3 = var2.getWorld();
         if (var3 != null) {
            URL var4 = var3.getSourceURL();
            if (var4 != this.lastURL && var4 != null) {
               this.changeURL(var4);
            }
         }
      }

      return true;
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      boolean var3 = false;
      if (var1 != null) {
         if (var2 == this.mapURL) {
            this.image_ = loadImage(URL.make(var1), this);
            var3 = this.image_ != null;
            if (var3) {
               this.setWidth(this.image_.getWidth(null) / 4);
               this.setHeight(this.image_.getHeight(null));
            }
         } else {
            var3 = this.readInfo(var1);
            if (this.hasLink("system:universe") >= 0) {
               this.console.exploreButton.hide();
               this.console.relayoutMap();
            }
         }
      }

      if (var3) {
         synchronized (this) {
            if (++this.filesLoaded == 2) {
               this.setHotspots(this.hotspots);
               this.repaint();
            }
         }
      }

      return null;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      return false;
   }

   public Room getBackgroundLoadRoom() {
      return null;
   }
}
