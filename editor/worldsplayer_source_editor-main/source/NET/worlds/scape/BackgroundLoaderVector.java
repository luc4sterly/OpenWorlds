package NET.worlds.scape;

import java.util.Vector;

class BackgroundLoaderVector extends Vector {
   BackgroundLoaderElement removeFirst() {
      BackgroundLoaderElement var1 = (BackgroundLoaderElement)this.elementAt(0);
      this.removeElementAt(0);
      return var1;
   }

   public synchronized Object get(int var1) {
      return this.elementAt(var1);
   }
}
