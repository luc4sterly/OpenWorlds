package NET.worlds.console;

import java.awt.Dimension;
import java.awt.Scrollbar;

public class WiderScrollbar extends Scrollbar {
   public Dimension preferredSize() {
      Dimension var1 = super.preferredSize();
      var1.width += 2;
      return var1;
   }

   public Dimension minimumSize() {
      Dimension var1 = super.minimumSize();
      var1.width += 2;
      return var1;
   }
}
