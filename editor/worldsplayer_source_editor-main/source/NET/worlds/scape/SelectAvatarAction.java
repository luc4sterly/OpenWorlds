package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.OkCancelDialog;
import NET.worlds.console.PolledDialog;
import NET.worlds.core.ServerTableManager;
import NET.worlds.network.URL;
import java.io.IOException;

public class SelectAvatarAction extends DialogAction {
   URL url = null;
   String description;
   static String[] avatarAliases = ServerTableManager.instance().getTable("avatarAliases");
   private static Object classCookie = new Object();

   private URL getURLVal() {
      URL var1 = this.url;
      if (var1 == null) {
         SuperRoot var2 = this.getOwner();
         if (var2 instanceof Drone) {
            var1 = ((Drone)var2).getSourceURL();
         } else if (var2 instanceof PosableShape) {
            var1 = ((Shape)var2).getURL();
         } else if (var2 instanceof Hologram) {
            var1 = ((Hologram)var2).getMovieName();
         }
      }

      return var1;
   }

   public void doIt() {
      Console var1 = Console.getActive();
      URL var2 = this.getURLVal();
      if (var1 != null && var2 != null) {
         var1.setAvatar(var2);
      }
   }

   public PolledDialog getDialog() {
      URL var1 = this.getURLVal();
      if (!Console.getActive().getVIPAvatars() && var1.getInternal().toLowerCase().endsWith(".rwg")) {
         return new OkCancelDialog(
            Console.getFrame(), this, Console.message("Cant-change-AV"), Console.message("OK"), null, Console.message("Only-VIPs-change"), false
         );
      }

      String var2 = this.description;
      if (var2 == null || var2.length() == 0) {
         var2 = getPrettyAvatarName(var1.getBase());
      }

      return new ChangeAvatarDialog(Console.getFrame(), this, var2);
   }

   public static String getPrettyAvatarName(String var0) {
      int var1 = var0.indexOf(46);
      if (var1 >= 0) {
         var0 = var0.substring(0, var1).toLowerCase();
      } else {
         var0 = var0.toLowerCase();
      }

      for (byte var2 = 0; var2 < avatarAliases.length; var2 += 2) {
         if (avatarAliases[var2].equals(var0)) {
            return avatarAliases[var2 + 1];
         }
      }

      String var4 = var0.substring(0, 1).toUpperCase();
      if (var0.length() > 1) {
         var4 = var4 + var0.substring(1);
      }

      return var4;
   }

   public Persister trigger(Event var1, Persister var2) {
      URL var3 = this.getURLVal();
      return var3 == null ? null : super.trigger(var1, var2);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Avatar URL").allowSetNull(), "pilot;drone;rwx;rwg;mov");
            } else if (var3 == 1) {
               var5 = this.url;
            } else if (var3 == 2) {
               this.url = (URL)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString() + "[url " + (this.url == null ? "null" : this.url.getRelativeTo(this) + "]");
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(4, classCookie);
      super.saveState(var1);
      URL.save(var1, this.url);
      var1.saveString(this.description);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            var1.setOldFlag();
            this.dialogActionSkipRestore(var1);
            this.url = URL.restore(var1, ".world");
            break;
         case 1:
            var1.setOldFlag();
            this.dialogActionSkipRestore(var1);
            this.url = URL.restore(var1, ".world");
            this.showDialog = var1.restoreBoolean();
            break;
         case 2:
            this.dialogActionSkipRestore(var1);
            this.url = URL.restore(var1, ".world");
            this.showDialog = var1.restoreBoolean();
            this.cancelOnly = var1.restoreBoolean();
            break;
         case 3:
         case 4:
            super.restoreState(var1);
            this.url = URL.restore(var1, ".world");
            if (var2 >= 4) {
               this.description = var1.restoreString();
            }
            break;
         default:
            throw new TooNewException();
      }
   }
}
