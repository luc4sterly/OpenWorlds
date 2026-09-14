package NET.worlds.scape;

abstract class ClickWidget extends WidgetButton {
   ClickWidget(ToolBar var1, String var2, String var3) {
      super(var1, var2, var3);
   }

   public boolean usesDrag() {
      return false;
   }

   public boolean available() {
      return true;
   }
}
