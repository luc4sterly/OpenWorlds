package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.PolledDialog;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Vector;

public class CDPositionPropertyEditor extends PropEditor {
   private boolean ending;

   private CDPositionPropertyEditor(Property var1, boolean var2) {
      super(var1);
      this.ending = var2;
   }

   public PolledDialog edit(EditTile var1, String var2) {
      CDTrackInfo var3 = null;

      try {
         var3 = CDPlayerAction.getTrackList(0);
      } catch (IOException var9) {
      }

      Vector var4 = new Vector();
      if (var3 != null) {
         for (int var5 = 0; var5 < var3.getNumTracks(); var5++) {
            int var6 = this.ending ? var3.getEndFrames(var5) : var3.getStartFrames(var5);
            String var7 = this.ending ? Console.message("End") : Console.message("Start");
            Object[] var8 = new Object[]{new String("" + var6), new String(var7), new String("" + (var5 + 1))};
            var4.addElement(MessageFormat.format(Console.message("of-track"), var8));
         }
      }

      return new CDPositionEditorDialog(var1, var2, this.property, var4);
   }

   public static Property make(Property var0, boolean var1) {
      return var0.setEditor(new CDPositionPropertyEditor(var0, var1));
   }
}
