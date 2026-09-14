package NET.worlds.scape;

import java.io.File;
import java.io.FileInputStream;
import java.util.Hashtable;

public class WobClassLoader extends ClassLoader {
   static Hashtable loaders = new Hashtable();
   Hashtable classes = new Hashtable();
   String zipName;

   public static synchronized Class get(String var0, String var1) {
      WobClassLoader var2 = (WobClassLoader)loaders.get(var0);
      if (var2 == null) {
         var2 = new WobClassLoader(var0);
         loaders.put(var0, var2);
      }

      try {
         return var2.loadClass(var1, true);
      } catch (ClassNotFoundException var4) {
         return null;
      }
   }

   public WobClassLoader(String var1) {
      this.zipName = var1;
   }

   protected synchronized Class loadClass(String var1, boolean var2) throws ClassNotFoundException {
      Class var3 = (Class)this.classes.get(var1);
      if (var3 == null) {
         try {
            return this.findSystemClass(var1);
         } catch (NoClassDefFoundError var7) {
         } catch (ClassNotFoundException var8) {
         }

         byte[] var4 = this.loadData(var1);
         if (var4 != null) {
            try {
               var3 = this.defineClass(var4, 0, var4.length);
            } catch (ClassFormatError var6) {
               throw new ClassNotFoundException(var1);
            }
         }

         if (var3 == null || !var1.equals(var3.getName())) {
            throw new ClassNotFoundException(var1);
         }

         this.classes.put(var1, var3);
      }

      if (var2) {
         this.resolveClass(var3);
      }

      return var3;
   }

   private byte[] loadData(String var1) {
      byte[] var2 = null;
      FileInputStream var3 = null;

      try {
         if (var1 != null) {
            File var4 = new File(this.zipName);
            int var5 = (int)var4.length();
            var3 = new FileInputStream(var4);
            var2 = new byte[var5];
            if (var3.read((byte[])var2) == var5) {
               return (byte[])var2;
            }
         }
      } catch (Exception var17) {
      } finally {
         if (var3 != null) {
            try {
               var3.close();
            } catch (Exception var16) {
            }
         }
      }

      return null;
   }
}
