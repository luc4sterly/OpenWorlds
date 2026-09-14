package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;
import NET.worlds.core.IniFile;
import NET.worlds.network.CacheFile;

class SoundCallback implements MainCallback, MainTerminalCallback {
   public void mainCallback() {
   }

   public void terminalCallback() {
      while (!Sound.cachedEntries.isEmpty()) {
         CacheFile var1 = (CacheFile)Sound.cachedEntries.firstElement();
         if (IniFile.gamma().getIniInt("sounddebug", 0) > 6) {
            System.out.println("terminal unlocking " + var1.getLocalName());
         }

         Sound.cachedEntries.removeElementAt(0);
         var1.finalize();
      }

      Main.unregister(this);
   }
}
