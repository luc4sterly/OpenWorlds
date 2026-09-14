package NET.worlds.console;

import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.event.MouseEvent;

class WorldButtonBullet extends Component {
   int circleX;
   int circleY;
   WorldButton button;

   public WorldButtonBullet(int var1, int var2, WorldButton var3) {
      this.circleX = var1 - 2;
      this.circleY = var2 - 2;
      this.button = var3;
      this.setSize(6, 6);
      this.enableEvents(16L);
      this.enableEvents(32L);
   }

   public void update(Graphics var1) {
      this.paint(var1);
   }

   public void paint(Graphics var1) {
      if (var1 != null) {
         if (this.button.isLoaded) {
            if (WorldButton.currentPackageName.equalsIgnoreCase(this.button.pkg)) {
               var1.setColor(Color.green);
            } else {
               var1.setColor(Color.red);
            }

            var1.drawOval(0, 0, 3, 3);
            var1.fillOval(0, 0, 3, 3);
         } else {
            var1.setColor(Color.red);
            var1.drawOval(0, 0, 3, 3);
         }
      }
   }

   public void processMouseMotionEvent(MouseEvent var1) {
      switch (var1.getID()) {
         case 503:
         case 506:
            this.button.buttonAction(0, var1.getID());
         default:
            super.processMouseEvent(var1);
      }
   }

   public void processMouseEvent(MouseEvent var1) {
      switch (var1.getID()) {
         case 501:
         case 502:
         case 504:
         case 505:
            this.button.buttonAction(0, var1.getID());
            return;
         case 503:
         default:
            super.processMouseEvent(var1);
      }
   }
}
