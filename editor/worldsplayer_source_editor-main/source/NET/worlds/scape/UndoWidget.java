package NET.worlds.scape;

import NET.worlds.console.Console;

class UndoWidget extends ClickWidget {
   public UndoWidget(ToolBar var1) {
      super(var1, "undo.gif", Console.message("Undo"));
   }

   public void perform() {
      Console.getFrame().getEditTile().undo();
   }
}
