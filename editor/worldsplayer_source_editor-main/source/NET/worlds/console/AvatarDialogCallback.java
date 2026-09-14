package NET.worlds.console;

import java.util.Vector;

public interface AvatarDialogCallback {
   Vector getComponents();

   Vector getChoices(int var1);

   int getCurrentSelection(int var1);

   void setCurrentSelection(int var1, int var2);
}
