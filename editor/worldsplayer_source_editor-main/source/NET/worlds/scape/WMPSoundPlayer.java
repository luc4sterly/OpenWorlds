package NET.worlds.scape;

import NET.worlds.console.WebControlImp;
import NET.worlds.network.URL;

public class WMPSoundPlayer extends SoundPlayer {
   protected DirectShow ds;
   protected boolean disabled;
   static int activeCount = 0;
   boolean playing = false;

   public WMPSoundPlayer(Sound var1) {
      super(var1);
      this.ds = new DirectShow();
   }

   public static boolean isActive() {
      return activeCount > 0;
   }

   public boolean open(float var1, float var2, boolean var3, boolean var4) {
      return true;
   }

   public void start(int var1) {
      String var2 = this.owner.getURL().toString();
      var2 = WebControlImp.processURL(var2);
      this.ds.nOpen(URL.make(var2).unalias());
      activeCount++;
      this.ds.nPlay(var1);
      this.playing = true;
   }

   public boolean position(Point3Temp var1, Point3Temp var2, Point3Temp var3, Point3Temp var4) {
      return true;
   }

   public int getState() {
      int var1 = this.ds.nTick();
      return var1 == 3 ? 0 : 1;
   }

   public void stop() {
      this.ds.nStop();
      activeCount--;
      this.playing = false;
   }

   public void close() {
      if (this.playing) {
         this.stop();
      }
   }

   public boolean setVolume(float var1) {
      return true;
   }
}
