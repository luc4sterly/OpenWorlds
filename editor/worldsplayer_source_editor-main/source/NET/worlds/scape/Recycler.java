package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Debug;

public class Recycler implements MainCallback {
   private static int minCapacity = 50;
   private Object[] list = new Object[minCapacity];
   private int numFilled = 0;
   private int numAllocked = 0;
   private int maxAllockedRecently = 0;
   private int howRecently = 0;

   Recycler() {
      Main.register(this);
   }

   private void resizeTo(int var1) {
      Debug.dAssert(var1 > this.numAllocked);
      if (var1 < minCapacity) {
         var1 = minCapacity;
      }

      if (var1 < this.list.length && this.list.length < 2 * var1) {
         while (this.numFilled > var1) {
            this.list[--this.numFilled] = null;
         }
      } else {
         Object[] var2 = new Object[var1];

         try {
            System.arraycopy(this.list, 0, var2, 0, this.numAllocked);
         } catch (Exception var4) {
            throw new Error(var4.toString());
         }

         this.list = var2;
         this.numFilled = this.numAllocked;
      }
   }

   public void mainCallback() {
      if (this.numAllocked > this.maxAllockedRecently) {
         this.maxAllockedRecently = this.numAllocked;
      }

      if (++this.howRecently == 1000) {
         int var1 = this.maxAllockedRecently + minCapacity;
         if (var1 < this.list.length) {
            this.resizeTo(var1);
         }

         this.howRecently = 0;
         this.maxAllockedRecently = this.numAllocked;
      }

      this.numAllocked = 0;
   }

   public Object alloc() {
      Debug.dAssert(Main.isMainThread());
      return this.numAllocked == this.numFilled ? null : this.list[this.numAllocked++];
   }

   public void recycle(Object var1) {
      if (this.numFilled == this.list.length) {
         this.resizeTo(this.list.length * 2);
      }

      this.list[this.numFilled++] = var1;
   }
}
