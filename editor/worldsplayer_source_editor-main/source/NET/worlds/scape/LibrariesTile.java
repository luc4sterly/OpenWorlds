package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Cursor;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.awt.Color;
import java.awt.Component;
import java.awt.Point;
import java.io.File;
import java.util.Enumeration;
import java.util.Vector;

public class LibrariesTile extends TabbedPanel implements LibEventHandler, Properties, MainCallback, LibraryDropTarget {
   private static final int NOTHING = 0;
   private static final int ADD_LIBRARY = 1;
   private static final int ADD_ELEMENT = 2;
   private static URL libURL = URL.make("home:libraries/");
   private static String libSubdir;
   private Vector libraries = new Vector();
   private int queue = 0;
   private boolean iconsVisible = false;
   private Cursor dragCursor;
   private Cursor cantCursor;
   private LibraryEntry leftClickedOn;

   public static String getLibSubdir() {
      return libSubdir;
   }

   public LibrariesTile() {
      this.setBackground(Color.lightGray);
      Vector var1 = new FileList(libSubdir, "library").getList();
      Enumeration var2 = var1.elements();

      while (var2.hasMoreElements()) {
         Library var3 = Library.load(URL.make(libURL, (String)var2.nextElement()));
         if (var3 != null) {
            this.addLibrary(var3);
         }
      }

      if (this.libraries.size() != 0) {
         this.select(0);
      }

      Main.register(this);
   }

   public synchronized void addLibrary() {
      if (this.queue == 0) {
         this.queue = 1;
      }
   }

   public synchronized void addElement() {
      if (this.queue == 0) {
         this.queue = 2;
      }
   }

   public synchronized void mainCallback() {
      switch (this.queue) {
         case 1:
            this.syncAddLibrary(new Library());
            break;
         case 2:
            this.syncAddElement(new LibraryEntry());
      }

      this.queue = 0;
   }

   private boolean isUniqueLibraryURL(URL var1) {
      if (var1 != null) {
         Enumeration var2 = this.libraries.elements();

         while (var2.hasMoreElements()) {
            Library var3 = (Library)var2.nextElement();
            if (var3.getSourceURL().equals(var1)) {
               return false;
            }
         }

         return true;
      } else {
         return false;
      }
   }

   private boolean isUniqueLibraryName(String var1) {
      if (var1 != null) {
         Enumeration var2 = this.libraries.elements();

         while (var2.hasMoreElements()) {
            Library var3 = (Library)var2.nextElement();
            if (var3.getName().equals(var1)) {
               return false;
            }
         }

         return true;
      } else {
         return false;
      }
   }

   private void syncAddLibrary(Library var1) {
      boolean var2 = var1.getNameMaybeNull() == null;
      if (!this.isUniqueLibraryURL(var1.getSourceURL())) {
         int var4 = 1;

         URL var3;
         do {
            var3 = URL.make(libURL, "lib" + var4++ + ".library");
         } while (!this.isUniqueLibraryURL(var3));

         var1.setSourceURL(var3);
      }

      if (this.libraries.size() == 0) {
         File var5 = new File(libSubdir);
         var5.mkdir();
      }

      if (!this.isUniqueLibraryName(var1.getNameMaybeNull())) {
         int var7 = 1;

         String var6;
         do {
            var6 = "Category" + var7++;
         } while (!this.isUniqueLibraryName(var6));

         var1.setName(var6);
      }

      if (this.saveAllowed()) {
         var1.save();
      } else {
         Console.println(Console.message("AllowChangeLibrary"));
      }

      this.addLibrary(var1);
      if (var2) {
         this.select(this.libraries.indexOf(var1));
      }
   }

   private void syncDeleteLibrary(Library var1) {
      if (this.saveAllowed()) {
         var1.delete();
      } else {
         Console.println(Console.message("AllowChangeLibrary"));
      }

      int var2 = this.libraries.indexOf(var1);
      this.libraries.removeElementAt(var2);
      this.removeItem(var2);
   }

   private void syncAddElement(LibraryEntry var1) {
      if (this.libraries.size() != 0) {
         int var2 = this.selected();
         Library var3 = (Library)this.libraries.elementAt(var2);
         var3.add(var1);
      }
   }

   private void addLibrary(Library var1) {
      int var2 = this.libraries.size();
      String var3 = var1.getName();
      int var4 = 0;

      while (var4 < var2 && var3.compareTo(((Library)this.libraries.elementAt(var4)).getName()) >= 0) {
         var4++;
      }

      this.libraries.insertElementAt(var1, var4);
      this.insertItem(var4, var1.getName(), new ScrollingImagePanel(this, var1.getContents(), this.iconsVisible));
      var1.setEventHandler(this);
      var1.setOwningDialog(this);
   }

   public boolean isIconsVisible() {
      return this.iconsVisible;
   }

   public void setIconsVisible(boolean var1) {
      this.iconsVisible = var1;
      int var2 = this.libraries.size();

      for (int var3 = 0; var3 < var2; var3++) {
         ScrollingImagePanel var4 = (ScrollingImagePanel)this.getComponent(var3);
         var4.setIconsVisible(var1);
      }
   }

   public void libraryChanged(Library var1) {
      Library var2 = (Library)this.libraries.elementAt(this.selected());
      int var3 = this.libraries.indexOf(var1);
      this.libraries.removeElementAt(var3);
      this.removeItem(var3);
      this.addLibrary(var1);
      this.select(this.libraries.indexOf(var2));
      if (this.saveAllowed()) {
         var1.save();
      } else {
         Console.println(Console.message("AllowChangeLibrary"));
      }
   }

   private boolean saveAllowed() {
      return IniFile.gamma().getIniInt("AllowChangeLibrary", 0) == 1;
   }

   private Library getLibrary(ScrollingImagePanel var1) {
      int var2 = this.libraries.size();

      for (int var3 = 0; var3 < var2; var3++) {
         if (this.getComponent(var3) == var1) {
            return (Library)this.libraries.elementAt(var3);
         }
      }

      return null;
   }

   private LibraryEntry getLibraryEntry(Component var1, Point var2) {
      if (var1 instanceof ScrollingImagePanel) {
         ScrollingImagePanel var3 = (ScrollingImagePanel)var1;
         Library var4 = this.getLibrary(var3);
         if (var4 != null) {
            int var5 = var3.itemAt(var2);
            if (var5 >= 0) {
               return var4.getEntry(var5);
            }
         }
      }

      return null;
   }

   private boolean maybeMoveEntry(LibraryEntry var1, Component var2, Point var3) {
      LibraryEntry var4 = this.getLibraryEntry(var2, var3);
      if (var4 != null && var4 != var1) {
         Library var7 = (Library)var1.getOwner();
         Library var8 = (Library)var4.getOwner();
         Debug.dAssert(var7 == var8);
         var7.move(var1, var4);
         return true;
      }

      if (var2 == this) {
         Library var5 = (Library)this.libraries.elementAt(this.itemAt(var3));
         Library var6 = (Library)var1.getOwner();
         if (var5 != var6) {
            var6.delete(var1);
            var5.add(var1);
            return true;
         }
      }

      return false;
   }

   public void clickEvent(Component var1, Point var2, int var3) {
      if ((var3 & 1) != 0) {
         if ((var3 & 4) != 0 && var1 == this) {
            Console.getFrame().getEditTile().viewProperties(this.libraries.elementAt(this.itemAt(var2)));
         } else {
            LibraryEntry var4;
            if ((var4 = this.getLibraryEntry(var1, var2)) != null) {
               this.leftClickedOn = null;
               if (var4 != null) {
                  if ((var3 & 4) != 0) {
                     Console.getFrame().getEditTile().viewProperties(var4);
                  } else {
                     this.leftClickedOn = var4;
                     Console var5 = Console.getActive();
                     if (this.dragCursor == null) {
                        this.dragCursor = new Cursor(URL.make("home:drag.cur"));
                     } else {
                        this.dragCursor.detach();
                        var5.addCursor(this.dragCursor);
                        this.dragCursor.activate();
                     }
                  }
               }
            }
         }
      } else if ((var3 & 2) != 0) {
         Cursor var7 = Cursor.getActive();
         if (var7 != null && (var7 == this.dragCursor || var7 == this.cantCursor)) {
            Console.getActive().getCursor().activate();
         }

         if (this.leftClickedOn != null) {
            if (!this.maybeMoveEntry(this.leftClickedOn, var1, var2)) {
               URL var9 = this.leftClickedOn.getContentURL();
               String var6 = this.leftClickedOn.getPropertyName(true);
               if (var9 != null) {
                  Console.getFrame().getEditTile().libraryDrop(var9, var6, var1, var2);
               }
            }

            this.leftClickedOn = null;
         }
      } else {
         Cursor var8 = Cursor.getActive();
         boolean var10 = var1 instanceof LibraryDropTarget;
         if (var8 == this.dragCursor) {
            if (!var10) {
               Console var11 = Console.getActive();
               if (this.cantCursor == null) {
                  this.cantCursor = new Cursor(URL.make("system:CANNOT_CURSOR"));
               } else {
                  this.cantCursor.detach();
                  var11.addCursor(this.cantCursor);
                  this.cantCursor.activate();
               }

               this.cantCursor.activate();
            }
         } else if (var8 != null && var8 == this.cantCursor && var10) {
            this.dragCursor.activate();
         }
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Contents"));
            } else if (var3 == 1) {
               var5 = this.libraries;
            } else if (var3 == 3) {
               this.syncAddLibrary((Library)var4);
            } else if (var3 == 4) {
               this.syncDeleteLibrary((Library)var4);
            } else if (var3 == 5 && var4 instanceof Library) {
               var5 = var4;
            }

            return var5;
         default:
            throw new NoSuchPropertyException();
      }
   }

   public Object propertyParent() {
      return null;
   }

   public String toString() {
      return "Libraries";
   }

   static {
      String var0 = libURL.unalias();
      libSubdir = var0.substring(0, var0.length() - 1);
   }
}
