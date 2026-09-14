package NET.worlds.console;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Panel;

public class ExposedPanel extends Panel {
   public ExposedPanel() {
      this.setBackground(Color.white);
   }

   public void paint(Graphics var1) {
      var1.setColor(this.getBackground());
      var1.fillRect(0, 0, this.size().width, this.size().height);
   }
}
