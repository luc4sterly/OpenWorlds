package NET.worlds.scape;

import NET.worlds.console.Console;

class CutWidget extends ClickWidget {
   public CutWidget(ToolBar var1) {
      super(var1, "cut.gif", Console.message("Cut"));
   }

   public void perform() {
      Console.getFrame().getEditTile().cut();
   }
}
