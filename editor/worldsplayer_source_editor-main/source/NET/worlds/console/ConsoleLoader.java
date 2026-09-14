package NET.worlds.console;

import NET.worlds.network.URL;
import NET.worlds.scape.LoadedURLSelf;
import NET.worlds.scape.URLSelf;
import NET.worlds.scape.URLSelfLoader;

class ConsoleLoader implements LoadedURLSelf {
   private LoadedURLSelf callback;

   public ConsoleLoader(URL var1, LoadedURLSelf var2) {
      this.callback = var2;
      URLSelfLoader.load(var1, this, true);
   }

   public void loadedURLSelf(URLSelf var1, URL var2, String var3) {
      Console var4 = (Console)var1;
      if (var3 == null && var4.pilot == null) {
         if (var4.disableSingleUserAccess) {
            var4.callbacks.addElement(this.callback);
         } else {
            var4.initPilot(var2, this.callback);
         }
      } else {
         this.callback.loadedURLSelf(var1, var2, var3);
      }
   }
}
