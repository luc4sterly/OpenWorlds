package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

public class Saver {
   static final String headerString = "PERSISTER Worlds, Inc.";
   static final String trailerString = "END PERSISTER";
   private static int _version = 7;
   private DataOutput os;
   private boolean myFile;
   private Hashtable classTable;
   private Hashtable objectTable;
   private Hashtable cookieTable;
   private URL reference;

   public static int version() {
      return _version;
   }

   public URL getReferenceURL() {
      return this.reference;
   }

   public Saver(URL var1) throws IOException {
      this(new DataOutputStream(new FileOutputStream(new File(var1.unalias()))));
      this.reference = var1;
      this.myFile = true;
   }

   public Saver(DataOutput var1) throws IOException {
      this.os = var1;
      this.saveString("PERSISTER Worlds, Inc.");
      this.saveInt(_version);
      this.classTable = new Hashtable();
      this.objectTable = new Hashtable();
      this.cookieTable = new Hashtable();
   }

   public void saveVersion(int var1, Object var2) throws IOException {
      Integer var3 = (Integer)this.cookieTable.get(var2);
      if (var3 == null) {
         this.saveInt(var1);
         this.cookieTable.put(var2, new Integer(var1));
      } else {
         Debug.assert_(var3 == var1);
      }
   }

   public void save(Persister var1) throws IOException {
      Debug.assert_(!(var1 instanceof NonPersister));
      int var2 = UniqueHasher.uh().hash(var1);
      this.saveInt(var2);
      if (!this.objectTable.containsKey(var1)) {
         this.objectTable.put(var1, var1);
         this.saveClass(var1.getClass());
         var1.saveState(this);
      }
   }

   public void saveVectorMaybeNull(Vector var1) throws IOException {
      if (var1 == null) {
         this.saveBoolean(false);
      } else {
         this.saveBoolean(true);
         this.saveVector(var1);
      }
   }

   public void saveMaybeNull(Persister var1) throws IOException {
      if (var1 != null && !(var1 instanceof NonPersister)) {
         this.saveBoolean(false);
         this.save(var1);
      } else {
         this.saveBoolean(true);
      }
   }

   public void saveClass(Class var1) throws IOException {
      UniqueHasher var2 = UniqueHasher.uh();
      this.saveInt(var2.hash(var1.toString()));
      if (!this.classTable.containsKey(var1)) {
         this.saveString(var1.getName());
         this.classTable.put(var1, var1);
      }
   }

   public void saveArray(Persister[] var1) throws IOException {
      this.saveClass(var1.getClass());
      this.saveInt(var1.length);

      for (int var2 = 0; var2 < var1.length; var2++) {
         this.saveMaybeNull(var1[var2]);
      }
   }

   public void saveVector(Vector var1) throws IOException {
      synchronized (var1) {
         Enumeration var3 = var1.elements();
         int var4 = 0;

         while (var3.hasMoreElements()) {
            Object var5 = var3.nextElement();
            if (var5 instanceof Persister && !(var5 instanceof NonPersister)) {
               var4++;
            }
         }

         this.saveInt(var4);
         var3 = var1.elements();

         while (var3.hasMoreElements()) {
            Object var9 = var3.nextElement();
            if (var9 instanceof Persister && !(var9 instanceof NonPersister)) {
               this.save((Persister)var9);
            }
         }
      }
   }

   public void saveString(String var1) throws IOException {
      this.saveBoolean(var1 == null);
      if (var1 != null) {
         this.os.writeUTF(var1);
      }
   }

   public void saveBoolean(boolean var1) throws IOException {
      this.os.writeBoolean(var1);
   }

   public void saveByte(byte var1) throws IOException {
      this.os.writeByte(var1);
   }

   public void saveShort(short var1) throws IOException {
      this.os.writeShort(var1);
   }

   public void saveInt(int var1) throws IOException {
      this.os.writeInt(var1);
   }

   public void saveLong(long var1) throws IOException {
      this.os.writeLong(var1);
   }

   public void saveFloat(float var1) throws IOException {
      this.os.writeFloat(var1);
   }

   public void saveDouble(double var1) throws IOException {
      this.os.writeDouble(var1);
   }

   public void done() throws IOException {
      this.saveString("END PERSISTER");
      if (this.myFile) {
         ((DataOutputStream)this.os).close();
      }

      this.classTable = null;
      this.objectTable = null;
      this.cookieTable = null;
   }
}
