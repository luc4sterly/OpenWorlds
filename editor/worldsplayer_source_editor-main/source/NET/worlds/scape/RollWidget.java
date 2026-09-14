package NET.worlds.scape;

import NET.worlds.console.Console;

class RollWidget extends WidgetButton {
   public RollWidget(ToolBar var1) {
      super(var1, "roll.gif", Console.message("Roll"));
   }

   public String drag(boolean var1, float var2, float var3) {
      if (Math.abs(var3) > Math.abs(var2)) {
         var2 = 0.0F;
      }

      Transform var4 = Transform.make();
      this.applyWorldTransform(var1, var4.spin(this.getWorldAxis(0, 1, 0), var2));
      var4.recycle();
      return "Roll";
   }
}
