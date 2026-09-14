package NET.worlds.console;

import NET.worlds.core.Std;
import NET.worlds.scape.EditTile;
import NET.worlds.scape.LibrariesTile;
import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Container;
import java.awt.Event;
import java.awt.Frame;

public class GammaFrame extends Frame implements DialogDisabled {
   private Container consoleTile;
   private Tree treeTile;
   private EditTile editTile;
   private LibrariesTile librariesTile;
   private FourTilePanel fourTile;
   private boolean isDialogDisabled;

   public boolean handleEvent(Event var1) {
      if (this.isDialogDisabled) {
         return false;
      } else {
         Console var2 = Console.getActive();
         if (var2 != null && var2.handleEvent(var1)) {
            return true;
         } else {
            return var1.id == 201 ? Console.maybeQuit() : super.handleEvent(var1);
         }
      }
   }

   public static String getDefaultTitle() {
      return Std.getProductName();
   }

   public GammaFrame() {
      super(getDefaultTitle());
   }

   public void show() {
      Gamma.hideSplash();
      Window.allowFGJavaPalette(false);
      Console var1 = Console.getActive();
      if (var1 instanceof DefaultConsole) {
         ((DefaultConsole)var1).setOrthoEnabled(this.isShaperVisible());
      }

      super.show();
   }

   public Container getConsoleTile() {
      this.makeTiles();
      return this.consoleTile;
   }

   public Tree getTreeTile() {
      this.makeTiles();
      return this.treeTile;
   }

   public EditTile getEditTile() {
      this.makeTiles();
      return this.editTile;
   }

   public LibrariesTile getLibrariesTile() {
      this.makeTiles();
      return this.librariesTile;
   }

   private void makeTiles() {
      if (this.consoleTile == null) {
         if (Gamma.getShaper() == null) {
            this.consoleTile = this;
         } else {
            this.consoleTile = new ExposedPanel();
            this.treeTile = new Tree();
            this.editTile = new EditTile(this.treeTile);
            this.librariesTile = new LibrariesTile();
            this.setLayout(new BorderLayout());
            this.fourTile = new FourTilePanel(this.librariesTile, this.consoleTile, this.treeTile, this.editTile, 1);
            this.add("Center", this.fourTile);
         }

         this.consoleTile.setLayout(new CardLayout());
      }
   }

   public void setShaperVisible(boolean var1) {
      if (Gamma.getShaper() != null) {
         if (this.fourTile.isOneTileMode() == var1) {
            if (var1) {
               this.fourTile.useFourTileMode();
            } else {
               this.fourTile.useOneTileMode();
            }
         }

         Console var2 = Console.getActive();
         if (var2 instanceof DefaultConsole) {
            ((DefaultConsole)var2).setOrthoEnabled(var1);
         }
      }
   }

   public boolean isShaperVisible() {
      return Gamma.getShaper() != null && this.fourTile != null && !this.fourTile.isOneTileMode();
   }

   public void deactivate() {
   }

   public void activate() {
      if (!this.isShowing()) {
         new GammaFrameState(this);
         this.show();
      }
   }

   public boolean action(Event var1, Object var2) {
      Console var3 = Console.getActive();
      return var3 != null && var3.action(var1, var2) ? true : super.action(var1, var2);
   }

   public void dialogDisable(boolean var1) {
      this.isDialogDisabled = var1;
      Console var2 = Console.getActive();
      if (var2 != null) {
         var2.dialogDisable(var1);
      }

      if (this.isShaperVisible()) {
         this.getTreeTile().dialogDisable(var1);
         this.getLibrariesTile().dialogDisable(var1);
         this.getEditTile().dialogDisable(var1);
      }
   }
}
