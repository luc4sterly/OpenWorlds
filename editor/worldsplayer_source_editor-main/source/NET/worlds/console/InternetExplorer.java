package NET.worlds.console;

import NET.worlds.scape.CDAudio;
import NET.worlds.scape.WavSoundPlayer;
import java.io.IOException;

public class InternetExplorer extends IUnknown implements MainCallback, MainTerminalCallback {
   WebBrowser _parent;

   public InternetExplorer(WebBrowser var1) throws IOException {
      ActiveX.init(this);
      this._parent = var1;
      this._refs = 1;
      Main.register(this);
   }

   public synchronized void Release() throws OLEInvalidObjectException {
      if (this._refs > 0) {
         this._refs--;
         if (this._parent != null) {
            this._parent.close();
         }

         ActiveX.uninit(this);
      }
   }

   public String toString() {
      return "InternetExplorer(" + this.internalData() + ")";
   }

   public void mainCallback() {
      boolean var1 = Window.getActivated();
      if (var1) {
         WebBrowser var2 = WebBrowser.findTag("sound:");
         if (var2 != null) {
            var2.close();
         }

         var2 = WebBrowser.findTag("videoMap:");
         if (var2 != null) {
            var2.close();
         }

         var2 = WebBrowser.findTag("videoAd:");
         if (var2 != null) {
            var2.close();
         }

         var2 = WebBrowser.findTag("zoom:");
         if (var2 != null) {
            var2.close();
         }

         var2 = WebBrowser.findTag("zoomLeft:");
         if (var2 != null) {
            var2.close();
         }

         var2 = WebBrowser.findTag("outside:");
         if (var2 != null) {
            var2.close();
         }

         try {
            Thread.sleep(1L);
         } catch (InterruptedException var4) {
         }

         WavSoundPlayer.resumeSystem();
         CDAudio.get().setEnabled(true);
      }
   }

   public void terminalCallback() {
      Main.unregister(this);
   }
}
