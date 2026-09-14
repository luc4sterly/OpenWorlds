package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.GammaFrame;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.WorldsMarkPart;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.URL;
import java.io.IOException;
import java.net.MalformedURLException;
import java.text.MessageFormat;

public class TeleportAction extends Action implements LoadedURLSelf, MainCallback, DialogReceiver {
   private Point3 targetCoords = new Point3();
   private float targetRot = 0.0F;
   private Point3 targetAxis = new Point3(0.0F, 0.0F, -1.0F);
   private String targetRoomName = null;
   private String targetDimension = null;
   private URL targetWorldURL = null;
   private boolean useDefCoordinates = false;
   private boolean done = false;
   private boolean showDialog = true;
   private boolean forceWorldLoad = false;
   private boolean forceNoWorldLoad = false;
   private String targetURL;
   private static TeleportAction activeTeleport = null;
   private TeleportDialog dialog = null;
   private TeleportStatus doneCallback;
   String tempParseStr;
   private static Object classCookie = new Object();

   public TeleportAction() {
   }

   public Persister trigger(Event var1, Persister var2) {
      if (activeTeleport != this) {
         this.targetURL = this.asURL();
         this.startTeleport();
      }

      return !this.done && activeTeleport != this ? this : null;
   }

   public void stopLoading() {
      this.done = true;
      if (activeTeleport == this) {
         this.stopTeleport(null);
      }
   }

   public static boolean isTeleporting() {
      return activeTeleport != null;
   }

   public static void teleport(String var0, TeleportStatus var1) {
      TeleportAction var2 = new TeleportAction(var0, var1);
      if (Main.isMainThread()) {
         var2.startTeleport();
      } else {
         Main.register(var2);
      }
   }

   public static void teleport(String var0, TeleportStatus var1, boolean var2) {
      TeleportAction var3 = new TeleportAction(var0, var1);
      var3.forceWorldLoad = var2;
      var3.forceNoWorldLoad = !var2;
      if (Main.isMainThread()) {
         var3.startTeleport();
      } else {
         Main.register(var3);
      }
   }

   public static void teleport(String var0, TeleportStatus var1, boolean var2, boolean var3) {
      TeleportAction var4 = new TeleportAction(var0, var1);
      var4.showDialog = var3;
      var4.forceWorldLoad = var2;
      var4.forceNoWorldLoad = !var2;
      if (Main.isMainThread()) {
         var4.startTeleport();
      } else {
         Main.register(var4);
      }
   }

   public void mainCallback() {
      Main.unregister(this);
      this.startTeleport();
   }

   public static String toURLString(String var0) {
      if (var0 == null || var0.equals("world:")) {
         var0 = WorldsMarkPart.getFirstSystemMarkURL();
      }

      if (var0 == null) {
         var0 = "home:NewWorld.world";
      }

      if (var0.startsWith("world:")) {
         if (var0.equals("world:restart")) {
            var0 = IniFile.gamma().getIniString("RestartAt", WorldsMarkPart.getFirstSystemMarkURL());
         } else if (var0.equals("world:store")) {
            var0 = World.getHomeStore().getAbsolute();
         } else {
            var0 = var0.substring(6);
         }

         int var1 = var0.indexOf(".world?");
         if (var1 >= 0) {
            var0 = var0.substring(0, var1) + ".world#" + var0.substring(var1 + 7);
         }
      }

      if (var0.indexOf(58) < 0) {
         if (var0.indexOf(47) < 0 && var0.indexOf(92) < 0 && !var0.endsWith(".world")) {
            var0 = "home:" + var0 + "/" + var0 + ".world";
         } else {
            var0 = "file:" + var0;
         }
      }

      return var0;
   }

   private TeleportAction(String var1, TeleportStatus var2) {
      this.doneCallback = var2;
      this.targetURL = toURLString(var1);
      var1 = this.setFromURL(this.targetURL);

      try {
         if (this.targetURL.startsWith("http://")) {
            this.targetWorldURL = new URL(var1);
         } else {
            this.targetWorldURL = new URL(URL.getCurDir(), URL.maybeAddExt(var1, ".world"));
         }
      } catch (MalformedURLException var4) {
         this.targetWorldURL = URL.make("error:\"" + var1 + '"');
      }
   }

   private float getNextFloat(float var1) {
      String var2 = this.tempParseStr;
      int var3 = this.tempParseStr.indexOf(44);
      if (var3 == -1) {
         var3 = this.tempParseStr.length();
         this.tempParseStr = "";
      } else {
         this.tempParseStr = this.tempParseStr.substring(var3 + 1);
      }

      try {
         return Float.valueOf(var2.substring(0, var3));
      } catch (NumberFormatException var5) {
         return var1;
      }
   }

   private String setFromURL(String var1) {
      this.useDefCoordinates = true;
      int var2 = var1.lastIndexOf(35);
      if (var2 >= 0) {
         String var3 = var1.substring(var2 + 1);
         var1 = var1.substring(0, var2);
         int var4 = var3.lastIndexOf(64);
         if (var4 < 0) {
            this.targetRoomName = var3;
         } else {
            this.useDefCoordinates = false;
            this.targetRoomName = var3.substring(0, var4);
            this.tempParseStr = var3.substring(var4 + 1);
            this.targetCoords.x = this.getNextFloat(this.targetCoords.x);
            this.targetCoords.y = this.getNextFloat(this.targetCoords.y);
            this.targetCoords.z = this.getNextFloat(this.targetCoords.z);
            this.targetRot = this.getNextFloat(this.targetRot);
            this.targetAxis.x = this.getNextFloat(this.targetAxis.x);
            this.targetAxis.y = this.getNextFloat(this.targetAxis.y);
            this.targetAxis.z = this.getNextFloat(this.targetAxis.z);
            this.tempParseStr = null;
         }
      }

      if (this.targetRoomName != null) {
         int var5 = this.targetRoomName.lastIndexOf(62);
         int var6 = this.targetRoomName.lastIndexOf(60);
         if (var5 + 1 == this.targetRoomName.length() && var6 >= 0) {
            this.targetDimension = this.targetRoomName.substring(var6 + 1, var5);
            this.targetRoomName = this.targetRoomName.substring(0, var6);
         }
      }

      return var1;
   }

   private void makeTeleportDialog(URL var1) {
      if (this.showDialog) {
         GammaFrame var2 = Console.getFrame();
         if (var2 != null && var2.isShowing()) {
            this.dialog = new TeleportDialog(var2, this);
         }
      }
   }

   private void startTeleport() {
      if (activeTeleport != null) {
         if (activeTeleport.doneCallback != null) {
            activeTeleport.doneCallback.teleportStatus("overridden by new teleport", activeTeleport.targetURL);
         }

         activeTeleport.stopTeleport(null);
      }

      activeTeleport = this;
      Console.setFreezeFrameEvents(true);
      this.done = false;
      Console.teleportNotification("", this.targetURL);
      if (this.targetWorldURL != null) {
         this.makeTeleportDialog(this.targetWorldURL);
         World.load(this.targetWorldURL, this, this.forceWorldLoad);
      } else {
         Pilot var1 = Pilot.getActive();
         World var2;
         if (var1 != null && (var2 = var1.getWorld()) != null) {
            this.makeTeleportDialog(var2.getSourceURL());
            this.loadedURLSelf(var2, this.targetWorldURL, null);
         } else {
            this.stopTeleport("Pilot not in a room for intraworld teleport");
         }
      }
   }

   private Room stopTeleport(String var1) {
      Debug.assert_(this == activeTeleport);
      this.done = true;
      activeTeleport = null;
      Console.setFreezeFrameEvents(false);
      if (this.doneCallback != null) {
         this.doneCallback.teleportStatus(var1, this.targetURL);
      }

      if (var1 != null && !this.forceNoWorldLoad) {
         Console.teleportNotification(var1, this.targetURL);
         Console.println(var1);
      }

      if (this.dialog != null) {
         this.dialog.closeIt(true);
         this.dialog = null;
      }

      return null;
   }

   public synchronized void dialogDone(Object var1, boolean var2) {
      if (activeTeleport != null) {
         activeTeleport.stopTeleport(null);
      }
   }

   public static String getReadableNameOfWorld(URL var0) {
      String var1 = var0.getAbsolute();
      String var2 = var1;
      Object var3 = null;
      if (var2.startsWith("home:") && var2.length() > 6) {
         var2 = var2.substring(var2.charAt(5) == '/' ? 6 : 5);
         int var4 = var2.indexOf(47);
         if (var4 > 0) {
            var3 = var2.substring(0, var4);
            if (var2.regionMatches(true, var4 + 1, var2, 0, var4)) {
               var2 = (String)var3;
               String var5 = WorldsMarkPart.getExternalName(var2);
               if (var5 != null) {
                  var2 = var5;
               }
            }
         }

         int var8 = var2.indexOf(".world");
         if (var8 > 0) {
            var2 = var2.substring(0, var8);
         }

         var2 = "the " + var2 + " world";
      }

      return var2;
   }

   public static String getPackageNameOfWorld(URL var0) {
      String var1 = var0.getAbsolute();
      String var2 = var1;
      String var3 = null;
      if (var2.startsWith("home:") && var2.length() > 6) {
         var2 = var2.substring(var2.charAt(5) == '/' ? 6 : 5);
         int var4 = var2.indexOf(47);
         if (var4 > 0) {
            var3 = var2.substring(0, var4);
         }
      }

      return var3;
   }

   public void loadedURLSelf(URLSelf var1, URL var2, String var3) {
      if (activeTeleport != this) {
         if (var1 != null) {
            var1.decRef();
         }
      } else if (var3 == null && var1 instanceof World) {
         String var8 = this.targetRoomName;
         if (var8 == null) {
            var8 = ((World)var1).getDefaultRoomName();
         }

         Room var9 = ((World)var1).getRoom(var8);
         if (var9 == null) {
            this.stopTeleport("Error finding room " + this.targetRoomName);
         } else if (var9.getVIPOnly() && !((World)var1).getConsole().getVIP()) {
            this.stopTeleport("Only VIPs may go there.");
            if (this.forceNoWorldLoad) {
               Console.println(Console.message("Only-VIPs-there"));
            }
         } else {
            Console.teleportNotification(null, this.targetURL);
            Pilot var10 = Pilot.changeActiveRoom(var9);
            if (this.targetDimension != null) {
               var10.changeChannel(this.targetDimension);
            }

            var10.makeIdentity();
            if (this.useDefCoordinates) {
               var10.moveTo(var9.getDefaultPosition()).spin(var9.getDefaultOrientationAxis(), var9.getDefaultOrientation());
            } else {
               var10.moveTo(this.targetCoords).spin(this.targetAxis, this.targetRot);
            }

            this.stopTeleport(null);
         }
      } else {
         if (var3 == null) {
            var3 = "file " + var2 + " doesn't contain a World";
            var1.decRef();
         }

         String var4 = getReadableNameOfWorld(var2);
         String var5 = getPackageNameOfWorld(var2);
         Object[] var6 = new Object[]{new String(var4)};
         this.stopTeleport(MessageFormat.format(Console.message("cant-teleport"), var6));
         if (var5 != null && !this.forceNoWorldLoad) {
            NetUpdate.loadWorld(var5, this.forceWorldLoad);
         }
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = Point3PropertyEditor.make(new Property(this, var1, "X, Y, Z"));
            } else if (var3 == 1) {
               var5 = new Point3(this.targetCoords);
            } else if (var3 == 2) {
               this.targetCoords.copy((Point3)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = FloatPropertyEditor.make(new Property(this, var1, "Dir"));
            } else if (var3 == 1) {
               var5 = new Float(this.targetRot);
            } else if (var3 == 2) {
               this.targetRot = (Float)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Room Name").allowSetNull());
            } else if (var3 == 1) {
               if (this.targetRoomName == null) {
                  var5 = "";
               } else {
                  var5 = new String(this.targetRoomName);
               }
            } else if (var3 == 2) {
               this.targetRoomName = (String)var4;
               this.stopLoading();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "World URL").allowSetNull(), "world");
            } else if (var3 == 1) {
               var5 = this.targetWorldURL;
            } else if (var3 == 2) {
               this.targetWorldURL = (URL)var4;
               this.stopLoading();
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Use default coordinates"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.useDefCoordinates);
            } else if (var3 == 2) {
               this.useDefCoordinates = (Boolean)var4;
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Dimension Name").allowSetNull());
            } else if (var3 == 1) {
               if (this.targetDimension == null) {
                  var5 = "";
               } else {
                  var5 = new String(this.targetDimension);
               }
            } else if (var3 == 2) {
               this.targetDimension = (String)var4;
               if (this.targetDimension.equals("")) {
                  this.targetDimension = null;
               }

               this.stopLoading();
            }
            break;
         case 6:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Show dialog"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.showDialog);
            } else if (var3 == 2) {
               this.showDialog = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 7, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(3, classCookie);
      super.saveState(var1);
      var1.save(this.targetCoords);
      var1.saveFloat(this.targetRot);
      var1.save(this.targetAxis);
      var1.saveString(this.targetRoomName);
      URL.save(var1, this.targetWorldURL);
      var1.saveBoolean(this.useDefCoordinates);
      var1.saveString(this.targetDimension);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            super.restoreState(var1);
            this.targetCoords = (Point3)var1.restore();
            this.targetRot = var1.restoreInt();
            this.targetRoomName = var1.restoreString();
            this.targetWorldURL = URL.restore(var1, ".world");
            this.useDefCoordinates = var1.restoreBoolean();
            this.targetDimension = null;
            break;
         case 1:
         case 2:
            super.restoreState(var1);
            this.targetCoords = (Point3)var1.restore();
            this.targetRot = var1.restoreFloat();
            this.targetAxis = (Point3)var1.restore();
            this.targetRoomName = var1.restoreString();
            this.targetWorldURL = URL.restore(var1, ".world");
            this.useDefCoordinates = var1.restoreBoolean();
            this.targetDimension = null;
            break;
         case 3:
            super.restoreState(var1);
            this.targetCoords = (Point3)var1.restore();
            this.targetRot = var1.restoreFloat();
            this.targetAxis = (Point3)var1.restore();
            this.targetRoomName = var1.restoreString();
            this.targetWorldURL = URL.restore(var1, ".world");
            this.useDefCoordinates = var1.restoreBoolean();
            this.targetDimension = var1.restoreString();
            break;
         default:
            throw new TooNewException();
      }

      if (var2 < 2 && this.targetAxis.x == 0.0F && this.targetAxis.y == 0.0F && this.targetAxis.z == 1.0F) {
         this.targetAxis.z = -1.0F;
         this.targetRot = 360.0F - this.targetRot;
      }
   }

   public String toString() {
      return super.toString() + "[" + this.asURL() + "]";
   }

   public String asURL() {
      String var1;
      if (this.targetWorldURL != null) {
         var1 = this.targetWorldURL.getRelativeTo(this) + "#";
      } else {
         var1 = "#";
      }

      if (this.targetRoomName != null) {
         var1 = var1 + this.targetRoomName;
      }

      if (this.targetDimension != null) {
         var1 = var1 + "<" + this.targetDimension + ">";
      }

      if (!this.useDefCoordinates) {
         var1 = var1 + "@" + this.targetCoords + "," + this.targetRot;
         if (this.targetAxis.x != 0.0F || this.targetAxis.y != 0.0F || this.targetAxis.z != 1.0F) {
            var1 = var1 + "," + this.targetAxis;
         }
      }

      return var1;
   }
}
