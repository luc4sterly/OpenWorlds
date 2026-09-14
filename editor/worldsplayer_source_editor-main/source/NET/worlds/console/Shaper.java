package NET.worlds.console;

import NET.worlds.network.URL;
import NET.worlds.scape.LoadedURLSelf;
import NET.worlds.scape.Manifest;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Saver;
import NET.worlds.scape.TeleportAction;
import NET.worlds.scape.URLSelf;
import NET.worlds.scape.World;
import java.awt.Container;
import java.awt.Event;
import java.awt.Menu;
import java.awt.MenuItem;
import java.io.IOException;
import java.util.Enumeration;

public class Shaper implements MainCallback, DialogReceiver, LoadedURLSelf {
   MenuItem newItem;
   MenuItem openItem;
   MenuItem saveItem;
   MenuItem propItem;
   MenuItem consolePropItem;
   MenuItem pilotPropItem;
   MenuItem undoItem;
   MenuItem cutItem;
   MenuItem copyItem;
   MenuItem pasteItem;
   MenuItem sortAttributesItem;
   MenuItem snapToolItem;
   MenuItem newLibraryItem;
   MenuItem newLibraryEntryItem;
   MenuItem iconsVisibleLibraryItem;
   Menu worldsMenu;
   MenuItem shaperVisibleItem;
   private World newWorldTemplate;
   private boolean makeNew = true;
   private static URL newworld = URL.make("home:NewWorld.world");
   private boolean quitFlag;
   private FileSaver fileSaver;
   private boolean worldListHasChanged = false;

   public Shaper() {
      Main.register(this);
   }

   public void activate(Console var1, Container var2, Console var3) {
      this.newItem = var1.addMenuItem(Console.message("New"), "File", 78, false);
      this.openItem = var1.addMenuItem(Console.message("Open"), "File", 79, false);
      this.saveItem = var1.addMenuItem(Console.message("Save"), "File", 83, false);
      this.propItem = var1.addMenuItem(Console.message("World-Prop"), "File");
      this.consolePropItem = var1.addMenuItem(Console.message("Console-Prop"), "File");
      this.pilotPropItem = var1.addMenuItem(Console.message("Pilot-Prop"), "File");
      this.undoItem = var1.addMenuItem(Console.message("Undo"), "Edit", 90, false);
      var1.getMenu("Edit").addSeparator();
      this.cutItem = var1.addMenuItem(Console.message("Cut"), "Edit", 88, false);
      this.copyItem = var1.addMenuItem(Console.message("Copy"), "Edit", 67, false);
      this.pasteItem = var1.addMenuItem(Console.message("Paste"), "Edit", 86, false);
      this.sortAttributesItem = var1.addMenuItem(Console.message("Sort-Attributes"), "Edit");
      this.snapToolItem = var1.addMenuItem(Console.message("Snap-Tool-Settings"), "Edit");
      this.newLibraryItem = var1.addMenuItem(Console.message("New-Library"), "Libraries");
      this.newLibraryEntryItem = var1.addMenuItem(Console.message("New-Library-Entry"), "Libraries");
      this.iconsVisibleLibraryItem = var1.addMenuItem(Console.message("Icons-On-Off"), "Libraries", 73, false);
      this.worldsMenu = var1.getMenu("Worlds");
      this.worldListChange();
      this.shaperVisibleItem = var1.addMenuItem(Console.message("Shaper-On-Off"), "Options");
   }

   public void deactivate() {
      this.worldsMenu = null;
   }

   public boolean action(Event var1, Object var2) {
      GammaFrame var3 = Console.getFrame();
      if (var1.target == this.newItem) {
         this.makeNew = true;
      } else if (var1.target == this.openItem) {
         new FileSysDialog(
            var3, this, Console.message("Open-World"), 0, "World Save Files|*.world|World Class Files|*.class|World Files|*.class;*.world", "", true
         );
      } else if (var1.target == this.saveItem) {
         new FileSysDialog(var3, this, Console.message("Save-World"), 1, "World Save Files|*.world|World Manifest (text) Files|*.mft", this.getSaveName(), true);
      } else if (var1.target == this.propItem) {
         if (Pilot.getActiveRoom() != null) {
            var3.getEditTile().viewProperties(Pilot.getActiveWorld());
         }
      } else if (var1.target == this.consolePropItem) {
         var3.getEditTile().viewProperties(Console.getActive());
      } else if (var1.target == this.pilotPropItem) {
         var3.getEditTile().viewProperties(Pilot.getActive());
      } else if (var1.target == this.sortAttributesItem) {
         new AttributeSortPanel(var3);
      } else if (var1.target == this.snapToolItem) {
         new SnapToolPanel(var3);
      } else if (var1.target == this.undoItem) {
         var3.getEditTile().undo();
      } else if (var1.target == this.cutItem) {
         var3.getEditTile().cut();
      } else if (var1.target == this.copyItem) {
         var3.getEditTile().copy();
      } else if (var1.target == this.pasteItem) {
         var3.getEditTile().paste();
      } else if (var1.target == this.newLibraryItem) {
         var3.getLibrariesTile().addLibrary();
      } else if (var1.target == this.newLibraryEntryItem) {
         var3.getLibrariesTile().addElement();
      } else if (var1.target == this.iconsVisibleLibraryItem) {
         var3.getLibrariesTile().setIconsVisible(!var3.getLibrariesTile().isIconsVisible());
      } else if (var1.target == this.shaperVisibleItem) {
         var3.setShaperVisible(!var3.isShaperVisible());
      } else {
         int var4 = this.worldsMenu.countItems();

         do {
            var4--;
         } while (var4 >= 0 && this.worldsMenu.getItem(var4) != var1.target);

         if (var4 < 0) {
            return false;
         }

         String var5 = (String)var2;
         if (var5.endsWith(" (changed)")) {
            var5 = var5.substring(0, var5.length() - 10);
         }

         TeleportAction.teleport(var5, null);
      }

      return true;
   }

   public String getSaveName() {
      return getSaveName(Pilot.getActive().getWorld());
   }

   public static String getSaveName(World var0) {
      URL var1 = var0.getSourceURL();
      String var2 = var1.unalias();
      int var3 = var2.indexOf(58);
      return var3 != -1 && var3 != 1 ? var1.getBase() : var2.replace('/', '\\');
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var2) {
         FileSysDialog var3 = (FileSysDialog)var1;
         String var4 = var3.fileName();
         if (var3.getMode() == 0) {
            TeleportAction.teleport(var4, null, true);
         } else {
            this.doSave(var4);
         }
      }
   }

   public void loadedURLSelf(URLSelf var1, URL var2, String var3) {
      this.newWorldTemplate = (World)var1;
   }

   public void mainCallback() {
      if (this.quitFlag) {
         if (this.fileSaver == null) {
            this.fileSaver = new FileSaver();
         }

         switch (this.fileSaver.getState()) {
            case 0:
               GammaFrameState.saveBorder();
               Main.end();
               break;
            case 2:
               this.quitFlag = false;
               this.fileSaver = null;
         }
      }

      if (this.newWorldTemplate != null) {
         this.newWorldTemplate.incRef();
      }

      if (this.makeNew) {
         this.makeNew = false;
         if (this.newWorldTemplate == null) {
            World.load(newworld, this, true);
         } else {
            World var1 = (World)this.newWorldTemplate.clone();
            var1.setEdited(true);
            TeleportAction.teleport(var1.getSourceURL().getAbsolute(), null);
         }
      }

      if (this.worldListHasChanged) {
         this.worldListHasChanged = false;
         this.rebuildWorldsMenu();
      }
   }

   public void maybeQuit() {
      this.quitFlag = true;
   }

   public void worldListChange() {
      this.worldListHasChanged = true;
   }

   private void rebuildWorldsMenu() {
      if (this.worldsMenu != null) {
         while (this.worldsMenu.countItems() > 0) {
            this.worldsMenu.remove(0);
         }

         Enumeration var1 = World.getWorlds();

         while (var1.hasMoreElements()) {
            World var2 = (World)var1.nextElement();
            URL var3 = var2.getSourceURL();
            String var4;
            if (var3 == null) {
               var4 = var2.getName();
            } else {
               var4 = var3.getAbsolute();
               if (var3.equals(newworld)) {
                  continue;
               }
            }

            if (var2.getEdited()) {
               var4 = var4 + " (changed)";
            }

            this.worldsMenu.add(new MenuItem(var4));
         }
      }
   }

   public void doSave(String var1) {
      doSave(var1, Pilot.getActive().getWorld(), true);
   }

   public static boolean doSave(String var0, World var1, boolean var2) {
      if (var2 && var0.endsWith(".mft")) {
         try {
            Manifest var6 = new Manifest(var0);
            var6.saveProps(var1);
            var6.done();
            return true;
         } catch (IOException var4) {
            Console.println(Console.message("Error-manifest") + var4.toString());
         }
      } else {
         if (var0.toLowerCase().endsWith(".wor")) {
            var0 = var0.substring(0, var0.length() - 4);
         }

         if (!var0.toLowerCase().endsWith(".world")) {
            var0 = var0 + ".world";
         }

         try {
            Saver var3 = new Saver(new URL(URL.getCurDir(), var0));
            var3.save(var1);
            var3.done();
            var1.setEdited(false);
            return true;
         } catch (IOException var5) {
            Console.println(Console.message("Error-saving") + var5.toString());
         }
      }

      return false;
   }
}
