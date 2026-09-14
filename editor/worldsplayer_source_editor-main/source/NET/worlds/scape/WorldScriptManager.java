package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;
import NET.worlds.console.RenderCanvas;
import java.awt.PopupMenu;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Enumeration;
import java.util.Vector;

public class WorldScriptManager implements ActionListener, MainCallback, MainTerminalCallback {
   private static WorldScriptManager instance = new WorldScriptManager();
   private static WorldScriptLoader loader = new WorldScriptLoader();
   private WorldScript currentScript = null;
   private String lastRoom;

   public static WorldScriptManager getInstance() {
      return instance;
   }

   private WorldScriptManager() {
      Main.register(this);
   }

   public void terminalCallback() {
      if (this.currentScript != null) {
         this.currentScript.worldExit();
      }

      this.currentScript = null;
      Main.unregister(this);
   }

   public void worldEntered(String var1) {
      if (this.currentScript != null) {
         this.currentScript.worldExit();
      }

      this.currentScript = null;
      if (var1 != null) {
         var1 = var1.replace(' ', '_');
         var1 = var1.replace('-', '_');
         var1 = var1.replace('.', '_');
         var1 = var1.replace('/', '_');
         var1 = var1.replace('\\', '_');

         try {
            this.currentScript = (WorldScript)loader.loadClass("WorldScript" + var1 + ".class", true).newInstance();
         } catch (Exception var3) {
            System.out.println("Exception constructing world script: " + var3);
         } catch (Error var4) {
            System.out.println("Error constructing world script: " + var4);
         }

         if (this.currentScript != null) {
            if (this.currentScript.getMinScriptVersion() > 15) {
               System.out
                  .println("Script requires newer client version. script is ver. " + this.currentScript.getMinScriptVersion() + " and client has ver. " + 15);
               this.currentScript = null;
            } else {
               this.currentScript.worldEnter();
            }
         }
      }
   }

   public void mainCallback() {
      if (this.currentScript != null) {
         this.currentScript.onEachFrame();
      }
   }

   public void onPrerender(WObject var1, Camera var2) {
      if (this.currentScript != null) {
         Console var3 = Console.getActive();
         if (var3 == null) {
            return;
         }

         if (!(var3 instanceof DefaultConsole)) {
            return;
         }

         DefaultConsole var4 = (DefaultConsole)var3;
         RenderCanvas var5 = var4.getRender();
         if (var5 == null) {
            return;
         }

         Camera var6 = var5.getCamera();
         if (var2 != var6) {
            return;
         }

         Point3Temp var7 = var1.inCamSpace(var2);
         boolean var8 = var7 != null && var7.z > 1.0F && var7.x < var7.z && -var7.x < var7.z;
         this.currentScript.objectVisibilityNotification(var1, var8);
      }
   }

   public void action(String var1) {
      if (this.currentScript != null) {
         this.currentScript.onTriggerAction(var1);
      }
   }

   public PopupMenu shapeClicked(Shape var1) {
      if (this.currentScript != null) {
         SuperRoot var2 = var1;

         while (var2.getOwner() != null) {
            var2 = var2.getOwner();
            if (var2 instanceof PosableShape) {
               var1 = (Shape)var2;
               break;
            }
         }

         Vector var3 = this.currentScript.onShapeClick(var1, var1.getName());
         if (var3 != null) {
            PopupMenu var4 = new PopupMenu();
            Enumeration var5 = var3.elements();

            while (var5.hasMoreElements()) {
               var4.add((String)var5.nextElement());
            }

            return var4;
         }
      }

      return null;
   }

   public void actionPerformed(ActionEvent var1) {
      if (this.currentScript != null) {
         this.currentScript.onMenuClick(var1.getActionCommand(), var1.getSource());
      }
   }

   public void roomEntered(String var1) {
      if (this.currentScript != null) {
         if (this.lastRoom != null) {
            this.currentScript.roomExit(this.lastRoom);
         }

         this.currentScript.roomEnter(var1);
         this.lastRoom = new String(var1);
      }
   }

   public void onConversation(String var1, String var2) {
      if (this.currentScript != null) {
         this.currentScript.onConversation(var1, var2);
      }
   }
}
