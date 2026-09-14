package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Hashtable;

public class SuperRoot implements Properties, Persister {
   private String name;
   protected static String helpURL = "home:internal/";
   private SuperRoot owner;
   protected URL sourceURL;
   private static Object classCookie = new Object();
   static Hashtable finalizedClasses = new Hashtable();
   static Hashtable classCounter = new Hashtable();

   public final String getShortClassName() {
      String var1 = this.getClass().getName();
      int var2;
      if ((var2 = var1.lastIndexOf(46)) != -1) {
         var1 = var1.substring(var2 + 1);
      }

      return var1;
   }

   public String getName() {
      if (this.name == null) {
         int var1 = 0;
         String var2 = this.getShortClassName();
         Enumeration var3 = this.getRoot().getDeepOwned();

         while (var3.hasMoreElements()) {
            SuperRoot var4 = (SuperRoot)var3.nextElement();
            if (var4.name != null && var4.name.startsWith(var2)) {
               try {
                  int var5 = Integer.valueOf(var4.name.substring(var2.length()));
                  if (var5 > var1) {
                     var1 = var5;
                  }
               } catch (NumberFormatException var6) {
               }
            }
         }

         this.name = var2 + ++var1;
      }

      return this.name;
   }

   public String getNameMaybeNull() {
      return this.name;
   }

   public void setName(String var1) {
      if (var1 == null && this.owner != null) {
         Object[] var2 = new Object[]{new String(this.owner.getName())};
         Console.println(MessageFormat.format(Console.message("Warning-null-name"), var2));
      }

      this.name = var1;
   }

   public static SuperRoot nameSearch(Enumeration var0, String var1) {
      while (var0.hasMoreElements()) {
         SuperRoot var2 = (SuperRoot)var0.nextElement();
         if (var1.equals(var2.name)) {
            return var2;
         }
      }

      return null;
   }

   public URL getHelpURL() {
      String var1 = helpURL + this.getClass().getName() + Console.message(".html");
      URL var2 = URL.make(var1);
      if (Console.wasHttpNoSuchFile(var1)) {
         var2 = URL.make(helpURL + this.getClass().getName() + ".html");
      }

      return var2;
   }

   public URL getHelpURL(Property var1) {
      String var2 = var1.getName().replace(' ', '_');
      String var3 = helpURL + this.getClass().getName() + "#" + var2 + Console.message(".html");
      URL var4 = URL.make(var3);
      if (Console.wasHttpNoSuchFile(var3)) {
         var4 = URL.make(helpURL + this.getClass().getName() + "#" + var2 + ".html");
      }

      return var4;
   }

   public String toString() {
      return this.isActive() ? this.getName() : this.getName() + "(inactive)";
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Name"));
            } else if (var3 == 1) {
               var5 = this.getName();
            } else if (var3 == 4) {
               this.setName(null);
            } else if (var3 == 2) {
               String var6 = (String)var4;
               if (!var6.equals(this.name) && this.owner != null && nameSearch(this.getRoot().getDeepOwned(), var6) != null) {
                  Object[] var7 = new Object[]{new String(var6), new String(this.getRoot().getName())};
                  Console.println(MessageFormat.format(Console.message("Name-in-use"), var7));
               } else {
                  this.setName((String)var4);
               }
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Source URL").allowSetNull(), "*wob", false);
            } else if (var3 == 1) {
               var5 = this.sourceURL;
            } else if (var3 == 2) {
               this.setSourceURL((URL)var4);
            }
            break;
         default:
            throw new NoSuchPropertyException();
      }

      return var5;
   }

   public Object propertyParent() {
      return this.owner;
   }

   public SuperRoot getOwner() {
      return this.owner;
   }

   public void discard() {
      this.detach();
   }

   protected void add(SuperRoot var1) {
      if (var1.owner != null && var1.owner != this) {
         System.out.println("double-setting owner of " + var1 + " from " + var1.owner + " to " + this);
         throw new Error("double-setting owner of " + var1);
      }

      var1.noteAddingTo(this);
      var1.owner = this;
   }

   public void detach() {
      if (this.owner != null) {
         this.owner.noteUnadding(this);
         this.owner = null;
      }
   }

   protected void noteAddingTo(SuperRoot var1) {
   }

   protected void noteUnadding(SuperRoot var1) {
   }

   public Enumeration getOwned() {
      return new ShallowEnumeration(this);
   }

   public Enumeration getDeepOwned() {
      return new DeepEnumeration(this);
   }

   public void getChildren(DeepEnumeration var1) {
   }

   public World getWorld() {
      SuperRoot var1 = this.getOwner();
      return var1 == null ? null : var1.getWorld();
   }

   public Room getRoom() {
      SuperRoot var1 = this.getOwner();
      return var1 == null ? null : var1.getRoom();
   }

   public SuperRoot getRoot() {
      SuperRoot var1 = this.getOwner();
      return var1 == null ? this : var1.getRoot();
   }

   public boolean isActive() {
      return this.getWorld() != null;
   }

   public URL getSourceURL() {
      return this.sourceURL;
   }

   public void setSourceURL(URL var1) {
      this.sourceURL = var1;
   }

   public URL getContainingSourceURL() {
      if (this.sourceURL != null) {
         return this.sourceURL;
      } else {
         return this.owner != null ? this.owner.getContainingSourceURL() : null;
      }
   }

   public void markEdited() {
      if (this.owner != null) {
         this.owner.markEdited();
      }
   }

   public static SuperRoot readFile(String var0, URL var1) {
      try {
         Restorer var3 = new Restorer(var0, var1);
         SuperRoot var4 = (SuperRoot)var3.restore();
         var3.done();
         var4.setSourceURL(var1);
         return var4;
      } catch (FileNotFoundException var5) {
      } catch (ClassCastException var6) {
      } catch (IOException var7) {
      } catch (TooNewException var8) {
      } catch (BadFormatException var9) {
      }

      return null;
   }

   public static SuperRoot readFile(URL var0) {
      return readFile(var0.unalias(), var0);
   }

   public void loadInit() {
   }

   public void saveFile(URL var1) throws IOException {
      if (this instanceof NonPersister) {
         throw new IOException("Can't save NonPersister");
      }

      Saver var2 = new Saver(var1);
      var2.save(this);
      var2.done();
      this.setSourceURL(var1);
   }

   public Object clone() {
      byte[] var1 = this.getByteCopy();
      return getCopyFromBytes(var1);
   }

   public byte[] getByteCopy() {
      if (this instanceof NonPersister) {
         return null;
      }

      ByteArrayOutputStream var1 = new ByteArrayOutputStream();

      try {
         Saver var2 = new Saver(new DataOutputStream(var1));
         var2.save(this);
         var2.done();
         return var1.toByteArray();
      } catch (Exception var3) {
         var3.printStackTrace(System.out);
         throw new Error("Can't save");
      }
   }

   public static SuperRoot getCopyFromBytes(byte[] var0) {
      if (var0 == null) {
         return null;
      }

      try {
         Restorer var1 = new Restorer(new DataInputStream(new ByteArrayInputStream(var0)));
         SuperRoot var2 = (SuperRoot)var1.restore();
         var1.done();
         return var2;
      } catch (Exception var3) {
         var3.printStackTrace(System.out);
         throw new Error("Can't restore");
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      var1.saveString(this.name);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreStateSuperRoot(var1);
   }

   protected final void restoreStateSuperRoot(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            var1.setOldFlag();
         case 2:
            String var3;
            if ((var3 = var1.restoreString()) != null) {
               this.setName(var3);
            }
            break;
         case 1:
            var1.setOldFlag();
            String var2;
            if ((var2 = var1.restoreString()) != null) {
               this.setName(var2);
            }

            var1.restoreMaybeNull();
            break;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }

   public static void finalizeCounter(Object var0) {
      Class var1 = var0.getClass();
      Integer var2 = (Integer)finalizedClasses.get(var1);
      int var3 = 0;
      if (var2 != null) {
         var3 = var2;
      }

      if (++var3 == 1000) {
         System.out.println("Finalized 1000 times: " + var1);
         var3 = 0;
      }

      finalizedClasses.put(var0.getClass(), new Integer(var3));
   }

   protected void finalize() {
   }

   public static void countClass(Object var0, int var1) {
      Class var2 = var0.getClass();
      Integer var3 = (Integer)classCounter.get(var2);
      int var4 = 0;
      if (var3 != null) {
         var4 = var3;
      }

      var4 += var1;
      classCounter.put(var2, new Integer(var4));
   }

   public static void printClassCounts() {
      Enumeration var0 = classCounter.keys();

      while (var0.hasMoreElements()) {
         Class var1 = (Class)var0.nextElement();
         System.out.println("Class " + var1.getName() + " has " + classCounter.get(var1));
      }
   }
}
