package NET.worlds.console;

import java.awt.Dimension;
import java.awt.Panel;
import java.awt.ScrollPane;

class WideScrollPane extends ScrollPane {
   Panel p;

   public WideScrollPane(Panel var1, boolean var2) {
      super(var2 ? 0 : 1);
      this.p = var1;
      this.add(var1);
   }

   public Dimension preferredSize() {
      Dimension var1 = this.p.preferredSize();
      var1.width += 5;
      var1.height += 5;
      return var1;
   }

   public Dimension minimumSize() {
      Dimension var1 = this.p.minimumSize();
      var1.width += 5;
      var1.height += 5;
      return var1;
   }
}
