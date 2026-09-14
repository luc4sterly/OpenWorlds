package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Vector;

public class MetaEnumeration implements Enumeration {
   private Vector v;
   private int index;

   MetaEnumeration(Vector var1) {
      Debug.dAssert(var1.size() > 0);
      this.v = var1;
      this.index = 0;
      this.advanceToNext();
   }

   public boolean hasMoreElements() {
      return ((Enumeration)this.v.elementAt(this.index)).hasMoreElements();
   }

   public Object nextElement() {
      Object var1 = ((Enumeration)this.v.elementAt(this.index)).nextElement();
      this.advanceToNext();
      return var1;
   }

   private void advanceToNext() {
      while (!((Enumeration)this.v.elementAt(this.index)).hasMoreElements()) {
         if (++this.index == this.v.size()) {
            this.index--;
            break;
         }
      }
   }
}
