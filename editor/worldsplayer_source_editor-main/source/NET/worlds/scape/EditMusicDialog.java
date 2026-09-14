package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.FileSysDialog;
import NET.worlds.console.PolledDialog;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;

class EditMusicDialog extends PolledDialog implements DialogReceiver {
   private TextField nameField = new TextField(20);
   private TextField trackField = new TextField(3);
   private TextField midiField = new TextField(30);
   private Button browseButton = new Button(Console.message("Browse"));
   private Checkbox loopBox = new Checkbox(Console.message("Loop-cont"));
   private Button okButton = new Button(Console.message("OK"));
   private Button cancelButton = new Button(Console.message("Cancel"));
   private MusicManagerDialog parent;
   private MusicTrack music;
   private String oldName;
   private String path;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);

   public EditMusicDialog(MusicManagerDialog var1, MusicTrack var2) {
      super(var1, var1, var2 == null ? Console.message("Add-Music") : Console.message("Edit-Music"), true);
      this.parent = var1;
      this.music = var2;
      if (var2 != null) {
         this.oldName = var2.getName();
      }

      this.path = var1.getManager().getFileName().toLowerCase().replace('/', '\\');
      this.path = this.path.substring(0, this.path.lastIndexOf(92) + 1);
      this.ready();
   }

   protected void build() {
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      var2.fill = 0;
      var2.anchor = 13;
      this.add(var1, new Label(Console.message("Name"), 2), var2);
      var2.gridwidth = 0;
      var2.anchor = 17;
      this.nameField.setFont(font);
      this.trackField.setFont(font);
      this.midiField.setFont(font);
      this.browseButton.setFont(bfont);
      this.loopBox.setFont(font);
      this.add(var1, this.nameField, var2);
      var2.gridwidth = 1;
      var2.anchor = 13;
      Label var3 = new Label(Console.message("Virtual-track"), 2);
      var3.setFont(font);
      this.add(var1, var3, var2);
      var2.gridwidth = 0;
      var2.anchor = 17;
      this.add(var1, this.trackField, var2);
      var2.gridwidth = 1;
      var2.anchor = 13;
      Label var4 = new Label(Console.message("Alternate-MIDI"), 2);
      var4.setFont(font);
      this.add(var1, var4, var2);
      var2.fill = 2;
      var2.weightx = 1.0;
      var2.anchor = 17;
      this.add(var1, this.midiField, var2);
      var2.fill = 0;
      var2.weightx = 0.0;
      var2.gridwidth = 0;
      this.add(var1, this.browseButton, var2);
      this.add(var1, this.loopBox, var2);
      var2.fill = 0;
      var2.anchor = 10;
      Panel var5 = new Panel();
      this.okButton.setFont(bfont);
      this.cancelButton.setFont(bfont);
      var5.add(this.okButton);
      var5.add(this.cancelButton);
      this.add(var1, var5, var2);
      if (this.music != null) {
         this.nameField.setText(this.music.getName());
         this.trackField.setText("" + this.music.getVirtTrackNumber());
         this.midiField.setText(this.music.getMIDIFileName());
         this.loopBox.setState(this.music.getLooping());
      }
   }

   public boolean action(java.awt.Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton && this.nameField.getText().trim().length() != 0) {
         return this.done(true);
      }

      if (var3 == this.cancelButton) {
         return this.done(false);
      }

      if (var3 == this.browseButton) {
         this.dialogDisable(true);
         new FileSysDialog(
            Console.getFrame(), this, Console.message("Browse-MIDI"), 0, "MIDI Files|*.mid;*.midi|All Files|*.*", this.path + this.midiField.getText(), false
         );
      }

      return false;
   }

   public synchronized void dialogDone(Object var1, boolean var2) {
      this.dialogDisable(false);
      if (var2 && var1 instanceof FileSysDialog) {
         String var3 = ((FileSysDialog)var1).fileName().toLowerCase();
         if (var3.startsWith(this.path)) {
            this.midiField.setText(var3.substring(this.path.length()));
         }
      }
   }

   public boolean isEditor() {
      return this.music != null;
   }

   public MusicTrack getMusicTrack() {
      String var1 = this.nameField.getText().trim();
      int var2 = 0;

      try {
         var2 = Integer.parseInt(this.trackField.getText());
      } catch (NumberFormatException var5) {
      }

      String var3 = this.midiField.getText().trim();
      boolean var4 = this.loopBox.getState();
      if (this.music == null) {
         return new MusicTrack(var1, var2, var3, var4);
      }

      this.music.setName(var1);
      if (var2 != -1) {
         this.music.setVirtTrackNumber(var2);
      }

      this.music.setMIDIFileName(var3);
      this.music.setLooping(var4);
      return this.music;
   }

   public String getOldName() {
      return this.oldName;
   }
}
