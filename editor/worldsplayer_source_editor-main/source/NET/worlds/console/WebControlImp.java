package NET.worlds.console;

import NET.worlds.core.Std;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.WorldServer;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Room;
import NET.worlds.scape.TextureSurfaceRenderer;
import java.util.Enumeration;
import java.util.Vector;

public abstract class WebControlImp implements TextureSurfaceRenderer {
   public static final int downloadBegin = 0;
   public static final int downloadEnd = 1;
   public static final int titleChanged = 2;
   public static final int propertyChanged = 3;
   public static final int statusChanged = 4;
   public static final int commandStateChanged = 5;
   Vector listeners = new Vector();
   private RenderCanvasOverlay canvas;

   WebControlImp(int var1) {
   }

   public static String processURL(String var0) {
      if (var0.indexOf("$USERNAME") == -1
         && var0.indexOf("$UPGRADESERVER") == -1
         && var0.indexOf("$SCRIPTSERVER") == -1
         && var0.indexOf("$SERIALNUM") == -1
         && var0.indexOf("$WORLD") == -1
         && var0.indexOf("$ROOM") == -1) {
         return var0;
      }

      var0 = Std.replaceStr(var0, "$UPGRADESERVER", NetUpdate.getUpgradeServerURL());
      if (Console.getActive() != null) {
         var0 = Std.replaceStr(var0, "$SCRIPTSERVER", Console.getActive().getScriptServer());
      } else if (var0.indexOf("$SCRIPTSERVER") != -1) {
         return null;
      }

      if (Pilot.getActive() != null) {
         Pilot var1 = Pilot.getActive();
         if (var1 != null && var1.getWorld() != null) {
            var0 = Std.replaceStr(var0, "$WORLD", var1.getWorld().toString());
         }

         Room var2 = Pilot.getActiveRoom();
         if (var2 != null) {
            var0 = Std.replaceStr(var0, "$ROOM", Pilot.getActiveRoom().toString());
         }

         WorldServer var3 = Pilot.getActive().getServer();
         if (var3 != null && var3.getGalaxy() != null) {
            String var4 = var3.getGalaxy().getChatname();
            if (var0.indexOf("$USERNAME") != -1) {
               if (var4 == null || var4.equals("")) {
                  return null;
               }

               var0 = Std.replaceStr(var0, "$USERNAME", var4);
            }

            String var5 = var3.getGalaxy().getSerialNum();
            if (var0.indexOf("$SERIALNUM") != -1) {
               if (var5 == null || var5.equals("")) {
                  return null;
               }

               var0 = Std.replaceStr(var0, "$SERIALNUM", var5);
            }
         } else if (var0.indexOf("$SERIALNUM") != -1 || var0.indexOf("$USERNAME") != -1) {
            return null;
         }
      }

      return var0.indexOf("$SERIALNUM") == -1 && var0.indexOf("$USERNAME") == -1 ? var0 : null;
   }

   public abstract boolean setURL(String var1);

   public abstract boolean setURL(String var1, String var2);

   public abstract void goBack();

   public abstract void goForward();

   public abstract void stop();

   public abstract void refresh();

   public abstract void home();

   public abstract void resize(int var1, int var2, int var3, int var4);

   public abstract int getHWND();

   public abstract void renderTo(int var1);

   public void addListener(WebControlListener var1) {
      this.listeners.addElement(var1);
   }

   public void removeListener(WebControlListener var1) {
      this.listeners.removeElement(var1);
   }

   void receiveEvent(int var1) {
      Enumeration var2 = this.listeners.elements();

      while (var2.hasMoreElements()) {
         WebControlListener var3 = (WebControlListener)var2.nextElement();
         if (var3 != null) {
            var3.webControlEvent(var1);
         }
      }
   }

   public void detach() {
      this.listeners.removeAllElements();
   }
}
