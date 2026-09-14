package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.PolledDialog;
import NET.worlds.core.Sort;
import java.awt.Button;
import java.awt.Choice;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Panel;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

class EditRoomDialog extends PolledDialog {
   private Choice roomChoice = new Choice();
   private Choice musicChoice = new Choice();
   private Button okButton = new Button(Console.message("OK"));
   private Button cancelButton = new Button(Console.message("Cancel"));
   private MusicManagerDialog parent;
   private MusicRoom room;
   private String startSelect;
   private static String lastMusic;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);

   public EditRoomDialog(MusicManagerDialog var1, MusicRoom var2, String var3) {
      super(var1, var1, Console.message("Assign-Music"), true);
      this.parent = var1;
      this.room = var2;
      this.startSelect = var3;
      this.ready();
   }

   protected void build() {
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      var2.fill = 0;
      var2.anchor = 13;
      Label var3 = new Label(Console.message("Room-name"), 2);
      var3.setFont(font);
      this.add(var1, var3, var2);
      var2.gridwidth = 0;
      var2.anchor = 17;
      this.roomChoice.setFont(font);
      this.add(var1, this.roomChoice, var2);
      var2.gridwidth = 1;
      var2.anchor = 13;
      Label var4 = new Label(Console.message("Music"), 2);
      var4.setFont(font);
      this.add(var1, var4, var2);
      var2.gridwidth = 0;
      var2.anchor = 17;
      this.musicChoice.setFont(font);
      this.add(var1, this.musicChoice, var2);
      var2.anchor = 10;
      Panel var5 = new Panel();
      var5.setFont(bfont);
      var5.add(this.okButton);
      var5.add(this.cancelButton);
      this.add(var1, var5, var2);
      this.roomChoice.setFont(font);
      this.musicChoice.setFont(font);
      if (this.room != null) {
         this.roomChoice.add(this.room.getRoomName());
      }

      Enumeration var6 = this.parent.getAllRooms().elements();
      Hashtable var7 = this.parent.getManager().getRooms();
      Vector var8 = new Vector();

      while (var6.hasMoreElements()) {
         String var9 = (String)var6.nextElement();
         if (!var7.containsKey(var9)) {
            var8.addElement(var9);
         }
      }

      Sort.sortInto(this.roomChoice, var8);
      Sort.sortInto(this.musicChoice, this.parent.getManager().getMusic());
      if (this.room != null) {
         this.roomChoice.select(this.room.getRoomName());
         this.musicChoice.select(this.room.getMusicName());
      } else {
         this.roomChoice.select(this.startSelect);
         if (lastMusic != null) {
            this.musicChoice.select(lastMusic);
         }
      }
   }

   public boolean action(java.awt.Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton) {
         return this.done(true);
      } else {
         return var3 == this.cancelButton ? this.done(false) : false;
      }
   }

   public boolean isEditor() {
      return this.room != null;
   }

   public MusicRoom getMusicRoom() {
      String var1 = this.roomChoice.getSelectedItem();
      String var2 = this.musicChoice.getSelectedItem();
      lastMusic = var2;
      if (this.room == null) {
         return new MusicRoom(var1, var2);
      }

      this.room.setRoomName(var1);
      this.room.setMusicName(var2);
      return this.room;
   }
}
