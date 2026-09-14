package NET.worlds.scape;

import NET.worlds.console.Console;

class YawWidget extends WidgetButton {
   public YawWidget(ToolBar var1) {
      super(var1, "yaw.gif", Console.message("Yaw"));
   }

   public String drag(boolean var1, float var2, float var3) {
      if (Math.abs(var3) > Math.abs(var2)) {
         var2 = 0.0F;
      }

      Transform var4 = Transform.make();
      this.applyWorldTransform(var1, var4.spin(this.getWorldAxis(0, 0, 1), var2));
      var4.recycle();
      return "Yaw";
   }
}
