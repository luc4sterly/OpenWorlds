package NET.worlds.console;

import NET.worlds.network.NetUpdate;
import NET.worlds.scape.TeleportAction;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.MenuItem;
import java.awt.PopupMenu;

class WorldButton extends TextImageButtons {
   int buttonX;
   int buttonY;
   String pkg;
   int privacyLevel;
   boolean isLoaded;
   String readableName;
   DefaultConsole console;
   static String currentPackageName = "";
   private static Font wfont = new Font(Console.message("UniverseFont"), 0, 10);
   private static final int[] xText = new int[]{0};
   PopupMenu lastPackageMenu;

   public WorldButton(
      boolean var1, int var2, int var3, int var4, int var5, String[] var6, String var7, int var8, DefaultConsole var9, ImageButtonsCallback var10
   ) {
      super(null, var4, intToInts(var5), xText, var6, var10, wfont);
      this.readableName = var6[0];
      this.buttonX = var2;
      this.buttonY = var3;
      this.pkg = var7;
      this.isLoaded = var1;
      this.privacyLevel = var8;
      this.console = var9;
      this.setSize(var4, var5);
      this.setWidth(var4);
      this.setHeight(var5);
   }

   public static Dimension measure(String var0) {
      return TextImageButtons.measure(var0, wfont);
   }

   public void doAction() {
      if (this.console == null || !this.showPackageMenu()) {
         NetUpdate.loadWorld(this.pkg, true);
      }
   }

   public boolean showPackageMenu() {
      int var1 = this.getLocation().x;
      int var2 = this.getLocation().y + 8;
      if (this.lastPackageMenu != null) {
         this.remove(this.lastPackageMenu);
         this.lastPackageMenu = null;
      }

      this.lastPackageMenu = WorldsMarkPart.getPackageMenu(this.pkg);
      if (this.lastPackageMenu != null && this.lastPackageMenu.getItemCount() != 0) {
         MenuItem var3 = this.lastPackageMenu.getItem(0);
         if (var3 instanceof BookmarkMenuItem) {
            BookmarkMenuItem var4 = new BookmarkMenuItem(this.readableName + " World:", ((BookmarkMenuItem)var3).getTarget());
            this.lastPackageMenu.insert(var4, 0);
            this.lastPackageMenu.insertSeparator(1);
         }

         this.add(this.lastPackageMenu);

         try {
            this.lastPackageMenu.show(this, -15, -7);
         } catch (RuntimeException var5) {
            System.out.println("Warning - could not show teleport location menu.");
         }

         return true;
      } else {
         return false;
      }
   }

   public void update(Graphics var1) {
      this.paint(var1);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 instanceof BookmarkMenuItem) {
         TeleportAction.teleport(((BookmarkMenuItem)var3).getTarget(), null);
         this.console.toggleUniverseMode();
         return true;
      } else {
         return super.action(var1, var2);
      }
   }

   protected Graphics drawButton(Graphics var1, int var2, int var3) {
      Color var4;
      if (var3 == 1) {
         if (this.isLoaded) {
            var4 = currentPackageName.equalsIgnoreCase(this.pkg) ? new Color(192, 255, 192) : Color.white;
         } else {
            var4 = Color.red;
         }
      } else if (var3 == 2) {
         var4 = new Color(255, 192, 192);
      } else {
         var4 = Color.green;
      }

      return super.drawButton(var1, var2, var3, var4);
   }
}
