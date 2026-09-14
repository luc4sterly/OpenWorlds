package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.io.DataInput;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

public class Restorer {
   private DataInput is;
   private boolean myFile;
   private Hashtable classTable;
   private Hashtable objectTable;
   private Hashtable cookieTable;
   private URL reference;
   private int _version;
   private boolean _oldFlag;
   private int _dblevel = 0;
   private Integer _firstRead = null;

   public URL getReferenceURL() {
      return this.reference;
   }

   public final int version() {
      return this._version;
   }

   private Restorer(String var1) throws IOException, BadFormatException, TooNewException {
      this(new DataInputStream(new FileInputStream(new File(var1))));
      if (this._dblevel > 0) {
         System.out.println("Restoring from " + var1);
      }

      this.myFile = true;
   }

   public Restorer(String var1, URL var2) throws IOException, BadFormatException, TooNewException {
      this(var1);
      this.reference = var2;
   }

   public Restorer(URL var1) throws IOException, BadFormatException, TooNewException {
      this(var1.unalias(), var1);
   }

   public Restorer(DataInput var1) throws IOException, BadFormatException, TooNewException {
      this.is = var1;
      this._dblevel = IniFile.gamma().getIniInt("RESTORE_DEBUG", 0);
      String var2 = this.restoreString();
      if (!var2.equals("PERSISTER Worlds, Inc.")) {
         throw new BadFormatException();
      }

      this._version = this.restoreInt();
      if (this._dblevel > 0) {
         System.out.println("Persister version " + this._version + " {");
      }

      if (this._version < 1) {
         throw new BadFormatException();
      }

      if (this._version > Saver.version()) {
         throw new TooNewException();
      }

      this.classTable = new Hashtable();
      this.objectTable = new Hashtable();
      this.cookieTable = new Hashtable();
   }

   public Restorer(DataInput var1, URL var2) throws IOException, BadFormatException, TooNewException {
      this(var1);
      this.reference = var2;
   }

   public int restoreVersion(Object var1) throws IOException {
      if (this._version == 1) {
         return 0;
      }

      Integer var2 = (Integer)this.cookieTable.get(var1);
      int var3;
      if (var2 == null) {
         var3 = this.restoreInt();
         this.cookieTable.put(var1, new Integer(var3));
      } else {
         var3 = var2;
      }

      return var3;
   }

   public Persister restore() throws IOException, TooNewException {
      return this.restore(true);
   }

   public Persister restore(boolean var1) throws IOException, TooNewException {
      boolean var2 = this._firstRead == null;
      Integer var3 = new Integer(this.restoreInt());
      if (this._dblevel > 0) {
         System.out.print("Object:" + Integer.toString(var3, 16));
      }

      if (this.objectTable.containsKey(var3)) {
         Persister var10 = (Persister)this.objectTable.get(var3);
         if (this._dblevel > 0) {
            System.out.println(" - old: " + var10.getClass().getName() + " (" + Integer.toString(var3, 16) + ")");
         }

         return var10;
      } else {
         Persister var4 = null;

         try {
            Class var5 = this.restoreClass(true);
            if (this._dblevel > 0) {
               System.out.println(" {");
            }

            try {
               var4 = (Persister)var5.newInstance();
            } catch (NoSuchMethodError var7) {
               System.out.println(var5);
               var7.printStackTrace(System.out);
               throw var7;
            }
         } catch (InstantiationException var8) {
            var8.printStackTrace(System.out);
            Debug.assert_(false);
         } catch (IllegalAccessException var9) {
            var9.printStackTrace(System.out);
            Debug.assert_(false);
         }

         this.objectTable.put(var3, var4);
         if (var1) {
            var4.restoreState(this);
         }

         if (this._dblevel > 0) {
            System.out.println((var1 ? "} Done with: " : "} Created: ") + Integer.toString(var3, 16));
         }

         Persister var11 = (Persister)this.objectTable.get(var3);
         if (var2) {
            this._firstRead = var3;
         }

         return var11;
      }
   }

   public Vector restoreVectorMaybeNull() throws IOException, TooNewException {
      return this.restoreBoolean() ? this.restoreVector() : null;
   }

   public Persister restoreMaybeNull() throws IOException, TooNewException {
      if (this.restoreBoolean()) {
         if (this._dblevel > 0) {
            System.out.println("null");
         }

         return null;
      } else {
         return this.restore();
      }
   }

   public Class restoreClass() throws IOException {
      return this.restoreClass(true);
   }

   public Class restoreClass(boolean var1) throws IOException {
      Class var2 = null;
      Integer var3 = new Integer(this.restoreInt());
      if (this.classTable.containsKey(var3)) {
         var2 = (Class)this.classTable.get(var3);
         if (this._dblevel > 0 && var1) {
            System.out.print("..." + var2.getName() + " [" + Integer.toString(var3, 16) + "]");
         }
      } else {
         String var4 = this.restoreString();
         if (this._dblevel > 0 && var1) {
            System.out.print("---" + var4 + " [" + Integer.toString(var3, 16) + "]");
         }

         try {
            var2 = Class.forName(var4);
         } catch (ClassNotFoundException var8) {
            try {
               if (var4.equals("NET.worlds.network.World")) {
                  if (this._dblevel > 0) {
                     System.out.print(" (Converting NET.worlds.network.World to NET.worlds.scape.World)");
                  }

                  var2 = Class.forName("NET.worlds.scape.World");
               } else {
                  if (this._dblevel > 0) {
                     System.out.print(" (Converting " + var4 + " to NET.worlds.scape." + var4 + ")");
                  }

                  var2 = Class.forName("NET.worlds.scape." + var4);
               }
            } catch (ClassNotFoundException var7) {
               throw new Error("Can't find class " + var4);
            }
         }

         this.classTable.put(var3, var2);
      }

      return var2;
   }

   private native Object makeArray(Class var1, int var2);

   public Persister[] restoreArray() throws IOException, TooNewException {
      Class var1 = null;
      if (this._version > 4) {
         var1 = this.restoreClass(false);
      }

      int var2 = this.restoreInt();
      Persister[] var3 = null;
      if (var1 == null) {
         if (this._dblevel > 0) {
            System.out.println("Array of " + Integer.toString(var2, 16) + " items {");
         }

         var3 = new Persister[var2];
      } else {
         String var4 = var1.getName();
         Debug.assert_(var4.startsWith("[L"));
         Debug.assert_(var4.endsWith(";"));
         var4 = var4.substring(2);
         var4 = var4.substring(0, var4.length() - 1);
         if (this._dblevel > 0) {
            System.out.println("Array of " + Integer.toString(var2, 16) + " " + var4 + " {");
         }

         try {
            var1 = Class.forName(var4);
         } catch (ClassNotFoundException var6) {
            throw new Error("Can't find class " + var4.substring(1));
         }

         Object var5 = this.makeArray(var1, var2);
         var3 = (Persister[])var5;
      }

      for (int var11 = 0; var11 < var2; var11++) {
         ((Object[])var3)[var11] = this.restoreMaybeNull();
      }

      if (this._dblevel > 0) {
         System.out.println("} Done with array");
      }

      return var3;
   }

   public Vector restoreVector() throws IOException, TooNewException {
      int var1 = this.restoreInt();
      if (this._dblevel > 0) {
         System.out.println("Vector of " + Integer.toString(var1, 16) + " items {");
      }

      Vector var2 = new Vector(var1);

      for (int var3 = 0; var3 < var1; var3++) {
         var2.addElement(this.restore());
      }

      if (this._dblevel > 0) {
         System.out.println("} Done with vector");
      }

      return var2;
   }

   public String restoreString() throws IOException {
      return this.restoreBoolean() ? null : this.is.readUTF();
   }

   public boolean restoreBoolean() throws IOException {
      return this.is.readBoolean();
   }

   public byte restoreByte() throws IOException {
      return this.is.readByte();
   }

   public short restoreShort() throws IOException {
      return this.is.readShort();
   }

   public int restoreInt() throws IOException {
      return this.is.readInt();
   }

   public long restoreLong() throws IOException {
      return this.is.readLong();
   }

   public float restoreFloat() throws IOException {
      return this.is.readFloat();
   }

   public double restoreDouble() throws IOException {
      return this.is.readDouble();
   }

   public void done() throws IOException, Error {
      if (this._dblevel > 0) {
         System.out.println("Calling all postRestores");
      }

      Enumeration var1 = this.objectTable.elements();

      while (var1.hasMoreElements()) {
         Persister var2 = (Persister)var1.nextElement();
         var2.postRestore(this._version);
      }

      var1 = this.objectTable.elements();

      while (var1.hasMoreElements()) {
         Object var5 = var1.nextElement();
         if (var5 != this.objectTable.get(this._firstRead) && var5 instanceof SuperRoot) {
            SuperRoot var3 = (SuperRoot)var5;
            if (var3.getOwner() == null) {
               System.out.println("Warning: " + var3.getName() + " was not owned by any object.");
               var3.finalize();
            }
         }
      }

      String var6 = this.restoreString();
      if (!var6.equals("END PERSISTER")) {
         throw new Error("Format error in save file");
      }

      if (this.myFile) {
         ((DataInputStream)this.is).close();
      }

      this.classTable = null;
      this.objectTable = null;
      this.cookieTable = null;
      if (this._dblevel > 0) {
         System.out.println("} Done with persister");
      }
   }

   public void setOldFlag() {
      this._oldFlag = true;
      if (this._dblevel > 0) {
         System.out.println("----OLD!----");
      }
   }

   public boolean oldFlag() {
      return this._oldFlag;
   }

   public void replace(Persister var1, Persister var2) {
      System.out.println("Converting a " + var1.getClass().getName() + " to a " + var2.getClass().getName());
      boolean var3 = false;
      Enumeration var4 = this.objectTable.keys();

      while (var4.hasMoreElements()) {
         Object var5 = var4.nextElement();
         if (this.objectTable.get(var5) == var1) {
            this.objectTable.put(var5, var2);
            var3 = true;
            break;
         }
      }

      Debug.assert_(var3);
   }
}
