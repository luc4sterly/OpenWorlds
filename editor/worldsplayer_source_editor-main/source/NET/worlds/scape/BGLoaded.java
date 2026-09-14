package NET.worlds.scape;

import NET.worlds.network.URL;

public interface BGLoaded {
   Object asyncBackgroundLoad(String var1, URL var2);

   boolean syncBackgroundLoad(Object var1, URL var2);

   Room getBackgroundLoadRoom();
}
