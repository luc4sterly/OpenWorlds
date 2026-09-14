package NET.worlds.scape;

import NET.worlds.console.ConfirmDialog;
import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.OkCancelDialog;
import NET.worlds.console.PolledDialog;
import NET.worlds.core.Sort;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.CheckboxGroup;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.List;
import java.awt.Panel;
import java.awt.Point;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

class MusicManagerDialog extends PolledDialog implements DialogReceiver {
   private MusicManager manager;
   private String lastRoom = "";
   private Label curRoom = new Label();
   private Label curMusic = new Label();
   private Button assignCurButton = new Button(Console.message("Assign-Current"));
   private Checkbox autoAssign = new Checkbox(Console.message("Auto-assign"));
   private CheckboxGroup group = new CheckboxGroup();
   private Checkbox musicBox = new Checkbox(Console.message("Music"), this.group, true);
   private Checkbox aRoomsBox = new Checkbox(Console.message("Assigned-rooms"), this.group, false);
   private Checkbox uRoomsBox = new Checkbox(Console.message("Unassigned-rooms"), this.group, false);
   private List list = new List(10);
   private Button editButton = new Button(Console.message("Edit"));
   private Button addButton = new Button(Console.message("Add"));
   private Button delButton = new Button(Console.message("Delete"));
   private Button assignButton = new Button(Console.message("Assign"));
   private Button saveButton = new Button(Console.message("Save-Changes"));
   private Button okButton = new Button(Console.message("OK"));
   private Button cancelButton = new Button(Console.message("Cancel"));
   private PolledDialog subDialog;
   private Vector allRooms;
   private boolean madeChanges;
   private boolean confirmingState;
   static Point lastWindowLocation = null;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);
   private static final String title = Console.message("Music-Manager");

   public MusicManagerDialog(MusicManager var1) {
      super(Console.getFrame(), var1, title + var1.getName(), false);
      this.setAlignment(2);
      this.manager = var1;
      this.ready();
   }

   public MusicManager getManager() {
      return this.manager;
   }

   public String getCurRoom() {
      return this.curRoom.getText();
   }

   public Vector getAllRooms() {
      return this.allRooms;
   }

   protected void build() {
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      Panel var3 = new Panel(new BorderLayout());
      this.musicBox.setFont(font);
      this.aRoomsBox.setFont(font);
      this.uRoomsBox.setFont(font);
      var3.add("West", this.musicBox);
      var3.add("Center", this.aRoomsBox);
      var3.add("East", this.uRoomsBox);
      var2.weightx = 0.0;
      var2.gridwidth = 0;
      this.add(var1, var3, var2);
      var2.fill = 1;
      var2.weightx = 1.0;
      var2.weighty = 1.0;
      var2.gridwidth = 2;
      var2.gridheight = 6;
      this.list.setFont(font);
      this.add(var1, this.list, var2);
      var2.fill = 2;
      var2.weightx = 0.0;
      var2.weighty = 0.0;
      var2.gridwidth = 0;
      var2.gridheight = 1;
      this.assignButton.setFont(bfont);
      this.editButton.setFont(bfont);
      this.addButton.setFont(bfont);
      this.delButton.setFont(bfont);
      this.add(var1, this.assignButton, var2);
      this.add(var1, this.editButton, var2);
      this.add(var1, this.addButton, var2);
      this.add(var1, this.delButton, var2);

      for (int var4 = 0; var4 < 2; var4++) {
         this.add(var1, new Label(""), var2);
      }

      var2.gridwidth = 1;
      var2.fill = 0;
      Label var7 = new Label(Console.message("Current-room"));
      var7.setFont(font);
      this.add(var1, var7, var2);
      var2.gridwidth = 0;
      var2.weightx = 1.0;
      var2.fill = 2;
      this.curRoom.setFont(font);
      this.add(var1, this.curRoom, var2);
      var2.gridwidth = 1;
      var2.weightx = 0.0;
      Label var5 = new Label(Console.message("Assigned-music"));
      var5.setFont(font);
      this.add(var1, var5, var2);
      var2.fill = 0;
      var2.gridwidth = 0;
      var2.fill = 2;
      var2.weightx = 1.0;
      this.curMusic.setFont(font);
      this.add(var1, this.curMusic, var2);
      var2.weightx = 0.0;
      var2.weighty = 0.0;
      var2.gridwidth = 1;
      var2.fill = 0;
      this.assignCurButton.setFont(bfont);
      this.autoAssign.setFont(bfont);
      this.add(var1, this.assignCurButton, var2);
      var2.gridwidth = 0;
      this.add(var1, this.autoAssign, var2);
      var3 = new Panel();
      var3.setFont(bfont);
      var3.add(this.saveButton);
      var3.add(this.okButton);
      var3.add(this.cancelButton);
      var2.fill = 2;
      this.add(var1, var3, var2);
      this.rebuildList(false);
      this.buildAllRoomsList();
   }

   protected boolean done(boolean var1) {
      lastWindowLocation = this.getLocation();
      return super.done(var1);
   }

   protected void initialSize(int var1, int var2) {
      if (lastWindowLocation == null) {
         super.initialSize(var1, var2);
      } else {
         this.setLocation(lastWindowLocation);
         this.setSize(var1, var2);
      }
   }

   private void buildAllRoomsList() {
      this.allRooms = new Vector();
      Pilot var1 = Pilot.getActive();
      if (var1 != null) {
         World var2 = var1.getWorld();
         if (var2 != null) {
            Enumeration var3 = var2.getRooms();

            while (var3.hasMoreElements()) {
               this.allRooms.addElement(((Room)var3.nextElement()).getName());
            }
         }
      }
   }

   private void rebuildList(boolean var1) {
      boolean var2 = !this.uRoomsBox.getState();
      this.assignButton.setEnabled(!this.musicBox.getState());
      this.editButton.setEnabled(var2);
      this.addButton.setEnabled(var2);
      this.delButton.setEnabled(var2);
      this.list.removeAll();
      if (this.musicBox.getState()) {
         Sort.sortInto(this.list, this.manager.getMusic());
      } else if (this.aRoomsBox.getState()) {
         String[] var3 = Sort.sortKeys(this.manager.getRooms());

         for (int var4 = 0; var4 < var3.length; var4++) {
            String var5 = var3[var4];
            this.list.add(var5 + " (" + this.manager.getRoom(var5).getMusicName() + ")");
         }
      } else {
         Enumeration var7 = this.allRooms.elements();
         Hashtable var8 = this.manager.getRooms();
         Vector var9 = new Vector();

         while (var7.hasMoreElements()) {
            String var6 = (String)var7.nextElement();
            if (!var8.containsKey(var6)) {
               var9.addElement(var6);
            }
         }

         Sort.sortInto(this.list, var9);
      }

      if (var1) {
         this.madeChanges = true;
         this.manager.maybeChangedMusic();
      }
   }

   protected synchronized void activeCallback() {
      Pilot var1 = Pilot.getActive();
      if (var1 != null) {
         World var2 = var1.getWorld();
         if (var2 != null && var2.getSourceURL().equals(this.manager.getWorld().getSourceURL())) {
            Room var3 = var1.getRoom();
            if (var3 != null) {
               String var4 = var3.getName();
               if (!var4.equals(this.lastRoom)) {
                  this.lastRoom = var4;
                  this.curRoom.setText(var4);
                  MusicRoom var5 = this.manager.getRoom(var4);
                  if (var5 != null) {
                     this.curMusic.setText(var5.getMusicName());
                  } else {
                     this.curMusic.setText("");
                     if (this.autoAssign.getState() && this.subDialog == null) {
                        this.subDialog = new EditRoomDialog(this, null, var4);
                     }
                  }
               }

               return;
            }
         }
      }

      this.curRoom.setText("");
      this.curMusic.setText("");
   }

   public synchronized boolean action(java.awt.Event var1, Object var2) {
      Object var3 = var1.target;
      String var4 = this.list.getSelectedItem();
      boolean var5 = this.musicBox.getState();
      boolean var6 = this.manager.getMusic().size() != 0;
      if (var5 && var3 == this.editButton && var4 != null) {
         this.subDialog = new EditMusicDialog(this, this.manager.getMusic(var4));
      } else if (var5 && var3 == this.addButton) {
         this.subDialog = new EditMusicDialog(this, null);
      } else if (var5 && var3 == this.delButton && var4 != null) {
         if (!this.isMusicInUse(var4)) {
            this.manager.getMusic().remove(var4);
            if (this.manager.getMusic().size() == 0) {
               this.autoAssign.setState(false);
            }

            this.rebuildList(true);
         } else {
            this.cantChangeMusic();
         }
      } else if (!var5 && var3 == this.editButton && var4 != null && var6) {
         var4 = var4.substring(0, var4.lastIndexOf(40) - 1);
         this.subDialog = new EditRoomDialog(this, this.manager.getRoom(var4), var4);
      } else if (!var5 && var3 == this.addButton) {
         if (var6) {
            this.subDialog = new EditRoomDialog(this, null, this.getCurRoom());
         } else {
            this.needMusic();
         }
      } else if (!var5 && var3 == this.delButton && var4 != null) {
         var4 = var4.substring(0, var4.lastIndexOf(40) - 1);
         this.manager.getRooms().remove(var4);
         this.rebuildList(true);
      } else if (var3 == this.saveButton) {
         this.manager.save();
         this.madeChanges = false;
      } else if (var3 == this.okButton) {
         if (this.madeChanges) {
            this.confirmingState = true;
            new ConfirmDialog(this, this, Console.message("Save-Changes2"), Console.message("sure-save"));
         } else {
            this.done(false);
         }
      } else if (var3 == this.cancelButton) {
         if (this.madeChanges) {
            this.confirmingState = false;
            new ConfirmDialog(this, this, Console.message("Abandon-Changes"), Console.message("sure-cancel"));
         } else {
            this.done(false);
         }
      } else if (var3 != this.musicBox && var3 != this.aRoomsBox && var3 != this.uRoomsBox) {
         if ((var3 != this.assignButton || var4 == null) && var3 != this.assignCurButton) {
            if (var3 != this.autoAssign || !this.autoAssign.getState()) {
               return false;
            }

            if (var6) {
               if (this.manager.getRoom(this.lastRoom) == null) {
                  this.subDialog = new EditRoomDialog(this, null, this.lastRoom);
               }
            } else {
               this.autoAssign.setState(false);
               this.needMusic();
            }
         } else if (var6) {
            String var7 = var3 == this.assignButton ? var4 : this.lastRoom;
            this.subDialog = new EditRoomDialog(this, this.manager.getRoom(var7), var7);
         } else {
            this.needMusic();
         }
      } else {
         this.rebuildList(false);
      }

      return true;
   }

   public boolean handleEvent(java.awt.Event var1) {
      if (var1.key != 1004 && var1.key != 1005 && var1.key != 1006 && var1.key != 1007) {
         return super.handleEvent(var1);
      }

      Console.getFrame().requestFocus();
      return true;
   }

   private void needMusic() {
      this.subDialog = new OkCancelDialog(this, this, Console.message("Need-Music"), null, Console.message("OK"), Console.message("at-least-one"), true);
   }

   private boolean isMusicInUse(String var1) {
      Enumeration var2 = this.manager.getRooms().elements();

      while (var2.hasMoreElements()) {
         if (var1.equals(((MusicRoom)var2.nextElement()).getMusicName())) {
            return true;
         }
      }

      return false;
   }

   private void cantChangeMusic() {
      this.subDialog = new OkCancelDialog(this, this, Console.message("Cant-Change"), null, Console.message("OK"), Console.message("may-not-delete"), true);
   }

   public synchronized void dialogDone(Object var1, boolean var2) {
      boolean var3 = false;
      if (var2) {
         if (var1 instanceof EditMusicDialog) {
            EditMusicDialog var4 = (EditMusicDialog)var1;
            MusicTrack var5 = var4.getMusicTrack();
            String var6 = var4.getOldName();
            if (var6 != null && !var6.equals(var5.getName()) && this.isMusicInUse(var6)) {
               var5.setName(var6);
               var3 = true;
            }

            this.manager.getMusic().put(var5.getName(), var5);
            this.rebuildList(true);
         } else if (var1 instanceof EditRoomDialog) {
            EditRoomDialog var7 = (EditRoomDialog)var1;
            MusicRoom var9 = var7.getMusicRoom();
            this.manager.getRooms().put(var9.getRoomName(), var9);
            this.rebuildList(true);
         } else if (var1 instanceof ConfirmDialog) {
            this.done(this.confirmingState);
         }

         if (this.lastRoom != null) {
            MusicRoom var8 = this.manager.getRoom(this.lastRoom);
            if (var8 != null) {
               this.curMusic.setText(var8.getMusicName());
            }
         }
      }

      this.subDialog = null;
      if (var3) {
         this.cantChangeMusic();
      }
   }
}
