package NET.worlds.scape;

import NET.worlds.console.Console;

class CopyWidget extends ClickWidget {
   public CopyWidget(ToolBar var1) {
      super(var1, Console.message("copy.gif"), Console.message("Copy"));
   }

   public void perform() {
      Console.getFrame().getEditTile().copy();
   }
}
