package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

public class VectorProperty extends Property {
   private PropAdder adder;
   private boolean allowSorting = true;

   public VectorProperty(Properties var1, int var2, String var3) {
      super(var1, var2, var3);
   }

   public static Vector toVector(Object[] var0) {
      Vector var1 = new Vector(var0.length);

      for (int var2 = 0; var2 < var0.length; var2++) {
         var1.addElement(var0[var2]);
      }

      return var1;
   }

   public static Vector toVector(Hashtable var0) {
      Vector var1 = new Vector(var0.size());
      Enumeration var2 = var0.elements();

      while (var2.hasMoreElements()) {
         var1.addElement(var2.nextElement());
      }

      return var1;
   }

   public Object delete(Object var1) {
      Debug.dAssert(var1 != null);
      Debug.dAssert(this.adder != null);
      return this.operate(4, var1);
   }

   public Object add(Object var1) {
      Debug.dAssert(var1 != null);
      Debug.dAssert(this.adder != null);
      return this.operate(3, var1);
   }

   public boolean addTest(Object var1) {
      Debug.dAssert(var1 != null);
      Debug.dAssert(this.adder != null);
      return this.operate(5, var1) != null;
   }

   public VectorProperty setAdder(PropAdder var1) {
      this.adder = var1;
      return this;
   }

   public PropAdder getAdder() {
      return this.adder;
   }

   public void allowSorting(boolean var1) {
      this.allowSorting = var1;
   }

   public boolean shouldSort() {
      return this.allowSorting;
   }
}
