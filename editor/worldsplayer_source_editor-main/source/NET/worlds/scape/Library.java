package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.io.File;
import java.io.IOException;
import java.util.Vector;

public class Library extends SuperRoot {
   private Object owningDialog;
   private Vector contents = new Vector();
   private LibEventHandler handler;
   protected String propertyName;
   private static Object classCookie = new Object();

   public static Library load(URL var0) {
      return (Library)SuperRoot.readFile(var0);
   }

   public Library(URL var1, String var2) {
      this.setSourceURL(var1);
      this.setName(var2);
   }

   public Library() {
   }

   public void save() {
      try {
         this.saveFile(this.getSourceURL());
      } catch (IOException var2) {
      }
   }

   public void delete() {
      new File(this.getSourceURL().unalias()).delete();
   }

   public void add(LibraryEntry var1) {
      Debug.dAssert(var1.getOwner() == null);
      this.contents.addElement(var1);
      super.add(var1);
      this.changed();
   }

   public void delete(LibraryEntry var1) {
      boolean var2 = this.contents.removeElement(var1);
      Debug.dAssert(var2);
      Debug.dAssert(var1.getOwner() == this);
      var1.detach();
      this.changed();
   }

   public void move(LibraryEntry var1, LibraryEntry var2) {
      int var3 = this.contents.indexOf(var1);
      Debug.dAssert(var3 != -1);
      int var4 = this.contents.indexOf(var2);
      Debug.dAssert(var4 != -1);
      this.contents.removeElement(var1);
      this.contents.insertElementAt(var1, var4);
      this.changed();
   }

   void entryChanged(LibraryEntry var1) {
      this.changed();
   }

   private void changed() {
      if (this.handler != null) {
         this.handler.libraryChanged(this);
      }
   }

   public Object getOwningDialog() {
      return this.owningDialog;
   }

   public Vector getContents() {
      return (Vector)this.contents.clone();
   }

   public String getPropertyName() {
      return this.propertyName;
   }

   public LibraryEntry getEntry(int var1) {
      return (LibraryEntry)this.contents.elementAt(var1);
   }

   public void setOwningDialog(Object var1) {
      this.owningDialog = var1;
   }

   public void setName(String var1) {
      super.setName(var1);
      this.changed();
   }

   public void setPropertyName(String var1) {
      this.propertyName = var1;
      this.changed();
   }

   public void setEventHandler(LibEventHandler var1) {
      this.handler = var1;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = PropAdder.make(new VectorProperty(this, var1, "Contents"));
            } else if (var3 == 1) {
               var5 = this.getContents();
            } else if (var3 == 4) {
               this.delete((LibraryEntry)var4);
            } else if (var3 == 3) {
               this.add((LibraryEntry)var4);
            } else if (var3 == 5 && var4 instanceof LibraryEntry) {
               var5 = var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Property Name").allowSetNull());
            } else if (var3 == 1) {
               var5 = this.getPropertyName();
            } else if (var3 == 2) {
               this.setPropertyName((String)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public Object propertyParent() {
      return this.getOwningDialog();
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveVector(this.contents);
      var1.saveString(this.propertyName);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      Vector var2 = null;
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this.setName(var1.restoreString());
            var1.restoreString();
            var1.restoreString();
            var2 = var1.restoreVector();
            break;
         case 1:
            super.restoreState(var1);
            var1.restoreString();
            var1.restoreString();
            var2 = var1.restoreVector();
            break;
         case 2:
            super.restoreState(var1);
            var2 = var1.restoreVector();
            this.propertyName = var1.restoreString();
            break;
         default:
            throw new TooNewException();
      }

      for (int var3 = 0; var3 < var2.size(); var3++) {
         this.add((LibraryEntry)var2.elementAt(var3));
      }
   }
}
