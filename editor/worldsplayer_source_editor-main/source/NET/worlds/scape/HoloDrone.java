package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.ServerTableManager;
import NET.worlds.network.ObjID;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Hashtable;

public class HoloDrone extends Drone implements HoloCallback {
   private WObject _avatar;
   private WObject _realAvatar = null;
   private boolean _isConstructing = false;
   private Hologram _proxyHCnewImage = null;
   private boolean _proxyHCok = false;
   private static int _debugLevel = IniFile.gamma().getIniInt("dronedebug", 0);
   private boolean permitAnyAvatar = IniFile.gamma().getIniInt("permitAnyAvatar", 0) != 0;
   private static String[] permittedList;
   private static String[] humanList;
   private static Hashtable permittedHash;
   private static Hashtable humanHash;
   private static Object classCookie;

   public HoloDrone() {
   }

   public HoloDrone(ObjID var1, WorldServer var2) {
      super(var1, var2);
      Debug.dAssert(Main.isMainThread());
      if (this._proxyHCnewImage != null) {
         this.holoCallback(this._proxyHCnewImage, this._proxyHCok);
         this._proxyHCnewImage = null;
      }
   }

   public static String[] getPermittedList() {
      String[] var0 = new String[permittedList.length / 2];

      for (int var1 = 0; var1 < var0.length; var1++) {
         var0[var1] = permittedList[2 * var1];
      }

      return var0;
   }

   static URL permission(URL var0) {
      String var1 = var0.getAbsolute().toLowerCase();
      if (var1.startsWith("avatar:") && var1.endsWith(".mov")) {
         var1 = var1.substring(7, var1.length() - 4);
         Object var2 = permittedHash.get(var1);
         if (var2 == null) {
            return null;
         } else {
            return var2 instanceof String ? URL.make((String)var2) : var0;
         }
      } else {
         return null;
      }
   }

   public static URL getHuman(URL var0) {
      if (!var0.endsWith(".mov")) {
         return PosableShape.getHuman(var0);
      }

      if (permission(var0) == null) {
         return URL.make("avatar:holden.mov");
      }

      String var1 = var0.getAbsolute().toLowerCase();
      int var2 = var1.length();

      for (int var3 = 7; var3 < var2; var3++) {
         if ("0123456789.".indexOf(var1.charAt(var3)) >= 0) {
            if (humanHash.get(var1.substring(7, var3)) != null) {
               return var0;
            }

            return URL.make(IniFile.override().getIniString("defaultHumanAv", "avatar:holden.mov"));
         }
      }

      return var0;
   }

   public Drone setAvatarNow(URL var1) {
      if (!this.shouldBeMuted() && var1.endsWith(".mov")) {
         if (this.shouldBeForcedHuman()) {
            var1 = getHuman(var1);
         }

         var1 = PosableShape.getPermitted(var1, this.getWorld());
         if (var1.equals(this.getSourceURL())) {
            return this;
         }

         this.setSourceURL(var1);
         URL var2 = permission(var1);
         if (var2 != null) {
            var1 = var2;
         } else if (!this.permitAnyAvatar) {
            var1 = Console.getDefaultURL();
         }

         this._realAvatar = this.makeAvatar(var1);
         if (this._proxyHCnewImage != null) {
            if ((_debugLevel & 1) > 0) {
               System.out.println("Holo.stAvNow(" + var1 + "): doing proxy");
            }

            this.holoCallback(this._proxyHCnewImage, this._proxyHCok);
            this._proxyHCnewImage = null;
         }

         return this;
      } else {
         return super.setAvatarNow(var1);
      }
   }

   public WObject makeAvatar(URL var1) {
      if ((_debugLevel & 1) > 0) {
         System.out.println("HoloDrone.makeAvatar(" + var1 + ")");
      }

      this._isConstructing = true;
      Hologram var2 = new Hologram(var1, this);
      this._isConstructing = false;
      var2.setVisible(true);
      var2.setBumpable(false);
      return var2;
   }

   public void holoCallback(Hologram var1, boolean var2) {
      if ((_debugLevel & 1) > 0) {
         System.out.println("HoloDrone.holoCallback(" + var1 + "," + var2 + ")");
      }

      if (this._isConstructing) {
         Debug.dAssert(this._proxyHCnewImage == null);
         this._proxyHCnewImage = var1;
         this._proxyHCok = var2;
         if ((_debugLevel & 1) > 0) {
            System.out.println("holoCallback: requesting proxy");
         }
      } else if (this._realAvatar == this._avatar) {
         if ((_debugLevel & 1) > 0) {
            System.out.println("holoCb: real avatar already loaded");
         }
      } else if (!var2) {
         if (var1 == this._realAvatar) {
            this._realAvatar = null;
         }

         if ((_debugLevel & 1) > 0) {
            System.out.println("holoCb: not ok");
         }
      } else {
         if ((_debugLevel & 1) > 0) {
            System.out.println("holoCb: swapping avatars");
         }

         if (this._avatar != null) {
            this._avatar.detach();
         }

         float var4 = var1.getW();
         float var5 = var1.getH();
         float var3;
         if (var5 < var4) {
            var3 = (float)Math.sqrt(25600.0F / (var4 * var5));
         } else {
            var3 = 160.0F / var5;
         }

         var5 *= var3;
         var4 *= var3;
         float var6 = 0.0F;
         if (var1 == this._avatar) {
            var6 = -this._avatar.getZ();
         }

         this._avatar = (WObject)var1.scale(var3).raise(var5 / 2.0F + var6);
         this.add(this._avatar);
         this.avatarHeightChangedTo(var5);
      }
   }

   public float getMinXYExtent() {
      return this._avatar == null ? 0.0F : this._avatar.getMinXYExtent();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         default:
            return super.properties(var1, var2 + 0, var3, var4);
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            Enumeration var2 = this.getContents();

            while (var2.hasMoreElements()) {
               WObject var3 = (WObject)var2.nextElement();
               if (var3 instanceof Hologram) {
                  Hologram var4 = (Hologram)var3;
                  if (var4.getMovieName() != null) {
                     this._avatar = var4;
                  }
               }
            }

            return;
         default:
            throw new TooNewException();
      }
   }

   static {
      if (_debugLevel > 0) {
         System.out.println("DRONE DEBUGGING LEVEL = " + _debugLevel);
      }

      permittedList = ServerTableManager.instance().getTable("permittedHoloList");
      humanList = ServerTableManager.instance().getTable("humanHoloList");
      permittedHash = new Hashtable();
      humanHash = new Hashtable();

      for (byte var0 = 0; var0 < permittedList.length; var0 += 2) {
         if (permittedList[var0 + 1] != null) {
            permittedHash.put(permittedList[var0], permittedList[var0 + 1]);
         } else {
            permittedHash.put(permittedList[var0], permittedList);
         }
      }

      for (int var1 = 0; var1 < humanList.length; var1++) {
         humanHash.put(humanList[var1], humanList[var1]);
      }

      classCookie = new Object();
   }
}
