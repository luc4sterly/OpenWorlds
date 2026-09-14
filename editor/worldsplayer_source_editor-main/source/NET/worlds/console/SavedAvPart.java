package NET.worlds.console;

import NET.worlds.network.URL;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import java.awt.CheckboxMenuItem;
import java.awt.Container;
import java.awt.Event;
import java.awt.Font;
import java.awt.Menu;
import java.awt.MenuItem;
import java.util.Vector;

public class SavedAvPart extends Menu implements FramePart, DialogReceiver {
   private static final int firstUserItem = 3;
   private static final String avsFileName = "Gamma.avatars";
   private static URL savedAvsURL = URL.make("home:Gamma.avatars");
   private static Vector savedAvatars;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private Menu menu;
   private MenuItem saveItem = new MenuItem(Console.message("Save-Avatar"));
   private MenuItem deleteItem = new MenuItem(Console.message("Delete-Avatar"));
   private DefaultConsole console;

   public SavedAvPart() {
      super(Console.message("Saved-Avatars"));
      if (savedAvatars == null) {
         loadAvatars();
      }
   }

   private static void loadAvatars() {
      try {
         Restorer var0 = new Restorer(savedAvsURL);
         savedAvatars = var0.restoreVector();
         var0.done();
      } catch (Exception var1) {
         savedAvatars = new Vector();
      }
   }

   private static void saveAvatars() {
      try {
         Saver var0 = new Saver(savedAvsURL);
         var0.saveVector(savedAvatars);
         var0.done();
      } catch (Exception var1) {
      }
   }

   static int getAvatarCount() {
      return savedAvatars.size();
   }

   private static SavedAvMenuItem getAvatar(int var0) {
      return (SavedAvMenuItem)savedAvatars.elementAt(var0);
   }

   static String getAvatarName(int var0) {
      return getAvatar(var0).getLabel();
   }

   static String getAvatarAvatar(int var0) {
      return getAvatar(var0).getAvatar();
   }

   private SavedAvMenuItem addAvatar(String var1, String var2) {
      SavedAvMenuItem var3 = new SavedAvMenuItem(var1, var2);
      var3.setFont(font);
      this.add(var3);
      savedAvatars.addElement(var3);
      saveAvatars();
      return var3;
   }

   void removeAvatar(int var1) {
      Object var2 = savedAvatars.elementAt(var1);
      savedAvatars.removeElementAt(var1);
      this.remove(var1 + 3);
      saveAvatars();
      this.console.deletedSavedAvatar((CheckboxMenuItem)var2);
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var2) {
         SavedAvAddDialog var3 = (SavedAvAddDialog)var1;
         URL var4 = this.console.getDefaultAvatarURL();
         if (var4 != null) {
            this.console.setCurrentAvatarItem(this.addAvatar(var3.getName(), var4.getAbsolute()));
         }
      }
   }

   public void activate(Console var1, Container var2, Console var3) {
      this.console = (DefaultConsole)var1;
      this.saveItem.setFont(font);
      this.deleteItem.setFont(font);
      this.add(this.saveItem);
      this.add(this.deleteItem);
      this.addSeparator();

      for (int var4 = 0; var4 < savedAvatars.size(); var4++) {
         MenuItem var5 = (MenuItem)savedAvatars.elementAt(var4);
         var5.setFont(font);
         this.add(var5);
      }
   }

   public void deactivate() {
      this.removeAll();
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.saveItem) {
         new SavedAvAddDialog(Console.getFrame(), this);
      } else if (var3 == this.deleteItem) {
         new SavedAvDeleteDialog(this);
      } else {
         if (!(var3 instanceof SavedAvMenuItem)) {
            return false;
         }

         SavedAvMenuItem var4 = (SavedAvMenuItem)var3;
         this.console.setNextAvatar(URL.make(var4.getAvatar()), var4);
      }

      return true;
   }

   public boolean handle(FrameEvent var1) {
      return true;
   }

   public CheckboxMenuItem findMenuItem(URL var1) {
      String var2 = var1.getAbsolute();
      int var3 = getAvatarCount();

      for (int var4 = 0; var4 < var3; var4++) {
         SavedAvMenuItem var5 = getAvatar(var4);
         if (var5.getAvatar().equals(var2)) {
            return var5;
         }
      }

      return null;
   }
}
