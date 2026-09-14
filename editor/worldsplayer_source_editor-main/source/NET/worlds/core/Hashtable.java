package NET.worlds.core;

import NET.worlds.scape.Persister;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import NET.worlds.scape.TooNewException;
import java.io.IOException;
import java.util.Enumeration;

public class Hashtable extends java.util.Hashtable implements Persister {
   private static Object classCookie = new Object();

   public Hashtable(int var1, float var2) {
      super(var1, var2);
   }

   public Hashtable(int var1) {
      super(var1);
   }

   public Hashtable() {
   }

   public Object getKey(Object var1) {
      Enumeration var2 = this.keys();

      while (var2.hasMoreElements()) {
         Object var3 = var2.nextElement();
         if (this.get(var3) == var1) {
            return var3;
         }
      }

      return null;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      int var2 = 0;
      Enumeration var3 = this.keys();

      while (var3.hasMoreElements()) {
         Object var4 = var3.nextElement();
         Object var5 = this.get(var4);
         if ((var4 instanceof String || var4 instanceof Persister) && var5 instanceof Persister) {
            var2++;
         }
      }

      var1.saveInt(var2);
      var3 = this.keys();

      while (var3.hasMoreElements()) {
         Object var7 = var3.nextElement();
         Object var8 = this.get(var7);
         if ((var7 instanceof String || var7 instanceof Persister) && var8 instanceof Persister) {
            if (var7 instanceof String) {
               var1.saveBoolean(true);
               var1.saveString((String)var7);
            } else {
               var1.saveBoolean(false);
               var1.save((Persister)var7);
            }

            var1.save((Persister)var8);
         }
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = this.restoreCount(var1);

      for (int var3 = 0; var3 < var2; var3++) {
         this.restoreEntry(var1);
      }
   }

   public void postRestore(int var1) {
   }

   public int restoreCount(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            return var1.restoreInt();
         default:
            throw new TooNewException();
      }
   }

   public void restoreEntry(Restorer var1) throws IOException, TooNewException {
      Object var2;
      if (var1.restoreBoolean()) {
         var2 = var1.restoreString();
      } else {
         var2 = var1.restore();
      }

      Persister var3 = var1.restore();
      this.put(var2, var3);
   }
}
