package NET.worlds.console;

import NET.worlds.scape.World;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Vector;

class FileSaver implements DialogReceiver {
   private Vector saveList = new Vector();
   private int state;
   public static final int QUIT = 0;
   public static final int SAVING = 1;
   public static final int CANCEL = 2;

   FileSaver() {
      Enumeration var1 = World.getWorlds();

      while (var1.hasMoreElements()) {
         World var2 = (World)var1.nextElement();
         if (var2.getEdited()) {
            this.saveList.addElement(var2);
         }
      }

      this.saveNext(false);
   }

   public int getState() {
      return this.state;
   }

   private World getWorld() {
      return (World)this.saveList.elementAt(0);
   }

   private void saveNext(boolean var1) {
      if (var1) {
         this.saveList.removeElementAt(0);
      }

      if (this.saveList.size() != 0) {
         this.state = 1;
         Object[] var2 = new Object[]{new String(this.getWorld().getName())};
         new YesNoCancelDialog(Console.getFrame(), this, Console.message("Save-Changes2"), MessageFormat.format(Console.message("has-changed"), var2));
      } else {
         this.state = 0;
      }
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var1 instanceof YesNoCancelDialog) {
         switch (((YesNoCancelDialog)var1).getChoice()) {
            case -1:
               this.state = 2;
               break;
            case 0:
               this.saveNext(true);
               break;
            case 1:
               new FileSysDialog(
                  Console.getFrame(), this, Console.message("Save-World"), 1, "World Save Files|*.world", Shaper.getSaveName(this.getWorld()), true
               );
         }
      } else {
         if (var2) {
            FileSysDialog var3 = (FileSysDialog)var1;
            if (Shaper.doSave(var3.fileName(), this.getWorld(), false)) {
               this.saveNext(true);
               return;
            }
         }

         this.state = 2;
      }
   }
}
