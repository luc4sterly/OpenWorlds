package NET.worlds.scape;

import NET.worlds.console.SnapTool;

class VTransWidget extends WidgetButton {
   public VTransWidget(ToolBar var1) {
      super(var1, "vtrans.gif", "Move vertically");
   }

   public String drag(boolean var1, float var2, float var3) {
      Transform var4 = Transform.make();
      this.applyWorldTransform(
         var1, var4.moveBy(SnapTool.snapTool().snapTo(this.getWorldAxis(1, 0, 0).times(var2).plus(this.getWorldAxis(0, 0, 1).times(var3))))
      );
      var4.recycle();
      return "" + this.getWObject().getPosition();
   }
}
