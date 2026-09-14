package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;

class WavSoundTerminator implements MainCallback, MainTerminalCallback {
   public WavSoundTerminator() {
      Main.register(this);
   }

   public void mainCallback() {
   }

   public void terminalCallback() {
      WavSoundPlayer.pauseSystem();
      Main.unregister(this);
   }
}
