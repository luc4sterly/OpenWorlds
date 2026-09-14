package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.List;

class BookmarkListDialog extends PolledDialog implements DialogReceiver {
   private List listbox = new List(10);
   private Button editButton = new Button(Console.message("Edit"));
   private Button addButton = new Button(Console.message("Add"));
   private Button copyButton = new Button(Console.message("Copy"));
   private Button delButton = new Button(Console.message("Delete"));
   private Button okButton = new Button(Console.message("Go-To"));
   private Button cancelButton = new Button(Console.message("Done"));
   private WorldsMarkPart bookmarks;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);

   BookmarkListDialog(WorldsMarkPart var1) {
      super(Console.getFrame(), null, Console.message("Edit-WorldsMarkL"), true);
      this.bookmarks = var1;
      this.ready();
   }

   protected void build() {
      int var1 = WorldsMarkPart.getBookmarkCount();

      for (int var2 = 0; var2 < var1; var2++) {
         this.listbox.addItem(WorldsMarkPart.getBookmarkName(var2));
      }

      GridBagLayout var4 = new GridBagLayout();
      this.setLayout(var4);
      GridBagConstraints var3 = new GridBagConstraints();
      var3.fill = 1;
      var3.weightx = 1.0;
      var3.weighty = 1.0;
      var3.gridwidth = 2;
      var3.gridheight = 6;
      this.listbox.setFont(font);
      this.add(var4, this.listbox, var3);
      var3.weightx = 0.0;
      var3.weighty = 0.0;
      var3.gridwidth = 0;
      var3.gridheight = 1;
      var3.fill = 2;
      this.editButton.setFont(bfont);
      this.addButton.setFont(bfont);
      this.delButton.setFont(bfont);
      this.okButton.setFont(bfont);
      this.cancelButton.setFont(bfont);
      this.add(var4, this.editButton, var3);
      this.add(var4, this.addButton, var3);
      this.add(var4, this.copyButton, var3);
      this.add(var4, this.delButton, var3);
      var3.weighty = 1.0;
      var3.anchor = 15;
      this.add(var4, this.okButton, var3);
      var3.weighty = 0.0;
      this.add(var4, this.cancelButton, var3);
   }

   private void select(boolean var1) {
      this.editButton.enable(var1);
      this.delButton.enable(var1);
      this.copyButton.enable(var1);
      this.okButton.enable(var1);
   }

   public void show() {
      super.show();
      if (this.listbox.countItems() != 0) {
         this.listbox.select(0);
         this.select(true);
      } else {
         this.select(false);
      }

      this.listbox.requestFocus();
   }

   public boolean handleEvent(Event var1) {
      if (var1.id == 701) {
         this.select(true);
      } else if (var1.id == 702) {
         this.select(false);
      }

      return super.handleEvent(var1);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton || var3 == this.listbox) {
         WorldsMarkPart.gotoBookmark(this.listbox.getSelectedIndex());
         return this.done(true);
      }

      if (var3 == this.cancelButton) {
         return this.done(false);
      }

      if (var3 == this.delButton) {
         int var7 = this.listbox.getSelectedIndex();
         if (var7 != -1) {
            this.listbox.delItem(var7);
            this.bookmarks.removeBookmark(var7);
            int var5 = this.listbox.countItems();
            if (var7 < var5 - 1) {
               this.listbox.select(var7);
            } else if (var5 > 0) {
               this.listbox.select(var5 - 1);
            } else {
               this.select(false);
               this.listbox.requestFocus();
            }
         }

         return true;
      } else if (var3 == this.copyButton) {
         int var6 = this.listbox.getSelectedIndex();
         if (var6 != -1) {
            this.add(WorldsMarkPart.getBookmarkName(var6), WorldsMarkPart.getBookmarkTarget(var6));
         }

         return true;
      } else if (var3 == this.addButton) {
         new BookmarkAddDialog(this, this);
         return true;
      } else if (var3 == this.editButton) {
         int var4 = this.listbox.getSelectedIndex();
         new BookmarkEditDialog(this, this, WorldsMarkPart.getBookmarkName(var4), WorldsMarkPart.getBookmarkTarget(var4), var4);
         return true;
      } else {
         return false;
      }
   }

   public boolean keyDown(Event var1, int var2) {
      if (var2 == 27) {
         return this.done(false);
      } else if (var2 == 10) {
         WorldsMarkPart.gotoBookmark(this.listbox.getSelectedIndex());
         return this.done(true);
      } else {
         return super.keyDown(var1, var2);
      }
   }

   private void add(String var1, String var2) {
      this.bookmarks.addBookmark(var1, var2);
      this.listbox.addItem(var1);
      this.listbox.makeVisible(this.listbox.countItems() - 1);
      this.listbox.select(this.listbox.countItems() - 1);
      this.select(true);
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var2) {
         if (var1 instanceof BookmarkAddDialog) {
            BookmarkAddDialog var3 = (BookmarkAddDialog)var1;
            BookmarkEditDialog var4 = var3.getEditor();
            this.add(var4.getName(), var4.getTarget());
         } else if (var1 instanceof BookmarkEditDialog) {
            BookmarkEditDialog var7 = (BookmarkEditDialog)var1;
            int var8 = var7.getIndex();
            String var5 = var7.getName();
            String var6 = var7.getTarget();
            this.bookmarks.changeBookmark(var8, var5, var6);
            this.listbox.replaceItem(var5, var8);
            this.listbox.makeVisible(var8);
            this.listbox.select(var8);
         }
      }
   }
}
