package NET.worlds.scape;

import NET.worlds.console.Console;

class ScaleWidget extends WidgetButton {
   public ScaleWidget(ToolBar var1) {
      super(var1, "scale.gif", Console.message("Scale"));
   }

   public String drag(boolean var1, float var2, float var3) {
      WObject var4 = this.getWObject();
      float var5 = Math.abs(var2) > Math.abs(var3) ? var2 : var3;
      var5 = (float)Math.pow(1.01, var5);
      if (var1) {
         Console.getFrame().getEditTile().addUndoable(new UndoablTransform(var4));
      }

      var4.scale(var5);
      var4.markEdited();
      return "Scale: " + var4.getScale();
   }
}
