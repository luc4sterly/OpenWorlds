package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.PolledDialog;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.Window;

public class CDControl extends PolledDialog {
   private Label display;
   private Button stopButton = new Button("[]");
   private Button pauseButton = new Button("||");
   private Button playButton = new Button(">");
   private Button prevButton = new Button("|<<");
   private Button nextButton = new Button(">>|");
   private Panel top = new Panel();
   private Panel bottom = new Panel();
   private Checkbox cdBox = new Checkbox(Console.message("Autoplay-CD"), CDAudio.useAutoCDFlag);
   private Checkbox midiBox = new Checkbox(Console.message("Autoplay-MIDI"), CDAudio.useMidiFlag);
   private String time;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);

   public CDControl(Window var1, DialogReceiver var2) {
      super(var1, var2, Console.message("Music"), false);
      this.display = new Label(this.time = CDAudio.get().getTimeReadout());
      this.setAlignment(1);
      this.ready();
   }

   protected void build() {
      this.setLayout(new GridLayout(2, 1));
      this.top.setLayout(new FlowLayout());
      this.top.add(this.display);
      this.top.add(this.stopButton);
      this.top.add(this.pauseButton);
      this.top.add(this.playButton);
      this.top.add(this.prevButton);
      this.top.add(this.nextButton);
      this.bottom.setLayout(new GridLayout(2, 1));
      this.cdBox.setFont(font);
      this.midiBox.setFont(font);
      this.bottom.add(this.cdBox);
      this.bottom.add(this.midiBox);
      this.add(this.top);
      this.add(this.bottom);
   }

   protected void activeCallback() {
      String var1 = CDAudio.get().getTimeReadout();
      if (!var1.equals(this.time)) {
         this.display.setText(this.time = var1);
      }
   }

   public boolean action(java.awt.Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.stopButton) {
         CDAudio.get().stop();
      } else if (var3 == this.pauseButton) {
         CDAudio.get().pause();
      } else if (var3 == this.playButton) {
         CDAudio.get().play();
      } else if (var3 == this.prevButton) {
         CDAudio.get().prev();
      } else if (var3 == this.nextButton) {
         CDAudio.get().next();
      } else if (var3 == this.cdBox) {
         CDAudio.get().useAutoCD(this.cdBox.getState());
      } else {
         if (var3 != this.midiBox) {
            return false;
         }

         CDAudio.get().setMidiFlag(this.midiBox.getState());
      }

      return true;
   }
}
