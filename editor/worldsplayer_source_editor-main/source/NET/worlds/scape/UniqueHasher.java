package NET.worlds.scape;

import java.util.Hashtable;

public class UniqueHasher {
   private int currentHash = 0;
   private static UniqueHasher uh_;
   private Hashtable ht = new Hashtable();

   private UniqueHasher() {
   }

   public static UniqueHasher uh() {
      if (uh_ == null) {
         uh_ = new UniqueHasher();
      }

      return uh_;
   }

   public int hash(Object var1) {
      Integer var2 = (Integer)this.ht.get(var1);
      if (var2 == null) {
         this.currentHash++;
         var2 = new Integer(this.currentHash);
         this.ht.put(var1, var2);
      }

      return var2;
   }
}
