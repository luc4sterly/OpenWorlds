package NET.worlds.scape;

import NET.worlds.network.URL;

public class SeqFile implements BGLoaded {
   private int nativeNotifyObject;

   public SeqFile(int var1, URL var2) {
      this.nativeNotifyObject = var1;
      BackgroundLoader.get(this, var2);
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      PendingCacheDrone.notifySeqLoaded(this.nativeNotifyObject, var1);
      return var1;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      return false;
   }

   public Room getBackgroundLoadRoom() {
      Pilot var1 = Pilot.getActive();
      return var1 != null ? var1.getRoom() : null;
   }
}
