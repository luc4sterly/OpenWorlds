package NET.worlds.scape;

import NET.worlds.console.BBWObjClickedCommand;
import NET.worlds.console.BlackBox;

public class MouseDownEvent extends MouseButtonEvent {
   public MouseDownEvent(int var1, WObject var2, char var3, int var4, int var5) {
      super(var1, var2, var3, var4, var5);
   }

   public boolean deliver(Object var1) {
      if (var1 instanceof MouseDownHandler) {
         BlackBox.getInstance().submitEvent(new BBWObjClickedCommand(((SuperRoot)var1).getName(), this.key, this.x, this.y));
         if (((MouseDownHandler)var1).handle(this)) {
            return true;
         }
      }

      return super.deliver(var1);
   }

   public String toString() {
      return "MouseDown" + super.toString();
   }
}
