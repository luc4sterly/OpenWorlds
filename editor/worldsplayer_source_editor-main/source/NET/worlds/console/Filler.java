package NET.worlds.console;

import java.awt.Dimension;
import java.awt.Panel;

public class Filler extends Panel {
   int wForced;
   int hForced;

   public Filler(int var1, int var2) {
      this.wForced = var1;
      this.hForced = var2;
   }

   public Dimension preferredSize() {
      return this.minimumSize();
   }

   public Dimension minimumSize() {
      return new Dimension(this.wForced, this.hForced);
   }
}
