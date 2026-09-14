package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.network.Galaxy;
import NET.worlds.network.NetworkObject;
import NET.worlds.network.ObjID;
import NET.worlds.network.WorldServer;
import NET.worlds.scape.Drone;
import NET.worlds.scape.FrameEvent;
import java.awt.Container;
import java.awt.Event;
import java.awt.MenuItem;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.StringTokenizer;
import java.util.Vector;

public class MuteListPart implements FramePart, NameListOwner {
   private static final String oldIniItemName = "Mutes";
   private static final String iniItemName = "Mute";
   private static final int maxMutes = 50;
   private static final String separator = ";";
   private static MuteListPart active;
   private Vector mutes;
   private Vector syncMutes = new Vector();
   private MenuItem editItem;
   private MenuItem disableWhisperItem;
   private boolean rejectWhispers;
   private DefaultConsole console;
   private Galaxy galaxy;
   private IniFile serverSection;
   private Object mutesMutex = new Object();
   private Vector updates = new Vector();

   private void loadMutes() {
      this.mutes = new Vector();

      for (int var1 = 0; var1 < 50; var1++) {
         String var2 = this.serverSection.getIniString("Mute" + var1, "");
         if (var2.length() == 0) {
            break;
         }

         if (FriendsListPart.isValidUserName(var2) && !FriendsListPart.icontains(this.mutes, var2)) {
            this.mutes.addElement(var2);
         }
      }

      if (this.mutes.size() == 0) {
         String var4 = this.serverSection.getIniString("Mutes", "");
         StringTokenizer var5 = new StringTokenizer(var4, ";");

         while (var5.hasMoreTokens() && this.mutes.size() < 50) {
            String var3 = var5.nextToken();
            if (FriendsListPart.isValidUserName(var3) && !FriendsListPart.icontains(this.mutes, var3)) {
               this.mutes.addElement(var3);
            }
         }

         if (this.mutes.size() != 0) {
            this.saveMutes();
            this.serverSection.setIniString("Mutes", "");
         }
      }
   }

   void saveMutes() {
      String var1 = "";
      int var2 = this.mutes.size();

      for (int var3 = 0; var3 < var2; var3++) {
         this.serverSection.setIniString("Mute" + var3, (String)this.mutes.elementAt(var3));
      }

      this.serverSection.setIniString("Mute" + var2, "");
   }

   private void setDisableWhisper() {
      this.rejectWhispers = IniFile.gamma().getIniInt("RejectWhispers", 0) == 1;
      if (this.rejectWhispers) {
         this.disableWhisperItem.setLabel(Console.message("Accept-Whispers"));
      } else {
         this.disableWhisperItem.setLabel(Console.message("Reject-Whispers"));
      }
   }

   public void activate(Console var1, Container var2, Console var3) {
      active = this;
      this.console = (DefaultConsole)var1;
      this.editItem = var1.addMenuItem(Console.message("Edit-Mute-List"), "Options");
      this.editItem.setEnabled(this.mutes != null);
      this.disableWhisperItem = var1.addMenuItem(Console.message("Reject-Whispers"), "Options");
      this.setDisableWhisper();
   }

   public void deactivate() {
      active = null;
      this.editItem = null;
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.editItem) {
         new EditNamesDialog(this, Console.message("Edit-Mute-List"), Console.message("Add-Mute-List"));
         return true;
      }

      if (var1.target == this.disableWhisperItem) {
         IniFile.gamma().setIniInt("RejectWhispers", this.rejectWhispers ? 0 : 1);
         this.setDisableWhisper();
      }

      return false;
   }

   public boolean handle(FrameEvent var1) {
      synchronized (this.mutesMutex) {
         int var3 = this.updates.size();
         if (var3 != 0) {
            WorldServer var4 = this.console.getServerNew();
            if (var4 != null) {
               for (int var5 = 0; var5 < var3; var5++) {
                  String var6 = (String)this.updates.elementAt(var5);
                  boolean var7 = this.mutes.contains(var6);
                  NetworkObject var8 = var4.getObject(new ObjID(var6));
                  if (var8 instanceof Drone) {
                     Drone var9 = (Drone)var8;
                     var9.muteStateChanged();
                  }

                  this.console.getFriends().changeMuteState(var6, var7);
               }

               this.updates.removeAllElements();
               this.syncMutes = (Vector)this.mutes.clone();
            }
         }

         return true;
      }
   }

   public void setServer(WorldServer var1, IniFile var2) {
      this.serverSection = var2;
      this.galaxy = var1.getGalaxy();
      this.loadMutes();
      if (this.editItem != null) {
         this.editItem.setEnabled(true);
      }
   }

   public static boolean isMuted(WorldServer var0, String var1) {
      if (var0 != null && var1 != null) {
         Galaxy var2 = var0.getGalaxy();
         Enumeration var3 = var2.getConsoles();

         while (var3.hasMoreElements()) {
            Object var4 = var3.nextElement();
            if (var4 instanceof DefaultConsole) {
               MuteListPart var5 = ((DefaultConsole)var4).getMutes();
               if (var5.mutes != null) {
                  return FriendsListPart.icontains(var5.mutes, var1);
               }
            }
         }
      }

      return false;
   }

   public static boolean isRejecting(WorldServer var0) {
      if (var0 != null) {
         Galaxy var1 = var0.getGalaxy();
         Enumeration var2 = var1.getConsoles();

         while (var2.hasMoreElements()) {
            Object var3 = var2.nextElement();
            if (var3 instanceof DefaultConsole) {
               MuteListPart var4 = ((DefaultConsole)var3).getMutes();
               if (var4.rejectWhispers) {
                  return true;
               }
            }
         }
      }

      return false;
   }

   public int getNameListCount() {
      return this.mutes.size();
   }

   public String getNameListName(int var1) {
      return (String)this.mutes.elementAt(var1);
   }

   public void removeNameListName(int var1) {
      synchronized (this.mutesMutex) {
         String var3 = (String)this.mutes.elementAt(var1);
         this.mutes.removeElementAt(var1);
         this.saveMutes();
         if (!this.updates.contains(var3)) {
            this.updates.addElement(var3);
         }
      }
   }

   public boolean mayAddNameListName(java.awt.Window var1) {
      if (this.mutes.size() < 50) {
         return true;
      }

      Object[] var2 = new Object[]{new String("50")};
      new OkCancelDialog(
         var1, null, Console.message("Too-many-names"), null, Console.message("OK"), MessageFormat.format(Console.message("You-are-limitedM"), var2), true
      );
      return false;
   }

   public int addNameListName(String var1) {
      synchronized (this.mutesMutex) {
         if (var1.toLowerCase().startsWith("host")) {
            return -1;
         }

         int var3 = FriendsListPart.iindexOf(this.mutes, var1);
         if (var3 != -1) {
            return var3;
         }

         this.mutes.addElement(var1);
         this.saveMutes();
         if (!this.updates.contains(var1)) {
            this.updates.addElement(var1);
         }

         return this.mutes.size() - 1;
      }
   }
}
