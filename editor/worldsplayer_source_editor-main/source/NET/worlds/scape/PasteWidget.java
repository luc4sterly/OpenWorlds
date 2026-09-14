package NET.worlds.scape;

import NET.worlds.console.Console;

class PasteWidget extends ClickWidget {
   public PasteWidget(ToolBar var1) {
      super(var1, "paste.gif", Console.message("Paste"));
   }

   public void perform() {
      Console.getFrame().getEditTile().paste();
   }
}
