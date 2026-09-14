package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.FileSysDialog;

class SaveWidget extends ClickWidget implements DialogReceiver {
   public SaveWidget(ToolBar var1) {
      super(var1, "save.gif", Console.message("Save-to-file"));
   }

   public void perform() {
      new FileSysDialog(
         Console.getFrame(),
         this,
         Console.message("Save-Object-As"),
         1,
         " wobject |*.wob| world   |*.world;*.wor| console |*.console| pilot   |*.pilot| drone   |*.drone| other   ||",
         "",
         false
      );
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var2) {
         Console.getFrame().getEditTile().save(((FileSysDialog)var1).fileName());
      }
   }
}
