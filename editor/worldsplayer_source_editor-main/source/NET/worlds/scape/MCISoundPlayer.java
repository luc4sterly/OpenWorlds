package NET.worlds.scape;

import NET.worlds.network.URL;

public class MCISoundPlayer extends SoundPlayer {
   private static MCIThread mciThread = new MCIThread();
   float ang;
   float dist;
   float vol;
   int leftToRepeat;
   int running;
   MCISoundCommand poll = new MCISoundPlayer$1(this);
   private URL url;
   private static MCISoundCommand activeStopCmd;
   MCISoundCommand volumeCmd = new MCISoundPlayer$4(this);

   public MCISoundPlayer(Sound var1) {
      super(var1);
   }

   public boolean open(float var1, float var2, boolean var3, boolean var4) {
      return true;
   }

   public void close() {
      this.stop();
   }

   public boolean position(Point3Temp var1, Point3Temp var2, Point3Temp var3, Point3Temp var4) {
      Point3Temp var5 = Point3Temp.make(var2).minus(var1);
      Point3Temp var6 = Point3Temp.make(var3).cross(var4);
      float var7 = var5.dot(var3);
      float var8 = var5.dot(var6);
      this.ang = (float)(Math.atan2(var7, var8) / Math.PI);
      this.dist = var5.length();
      return this.setVolume(this.vol);
   }

   public boolean setVolume(float var1) {
      this.vol = var1;
      float var2 = 0.5F;
      if (this.owner != null && this.owner.getPanning()) {
         var2 = Math.abs(this.ang);
         if (this.ang < 0.0F) {
            var1 = this.vol * (float)(0.5 + Math.abs(0.5 + this.ang));
         }
      }

      if (this.owner != null && this.owner.getAttenuate()) {
         float var3 = this.owner.getStopDistance();
         if (this.dist > var3) {
            this.volume(0.0F, 0.0F);
            return false;
         }

         var1 *= (var3 - this.dist) / var3;
      }

      this.volume(var1 * var2, var1 * (1.0F - var2));
      return true;
   }

   public int getState() {
      if (!this.poll.isOnQueue) {
         mciThread.pushCommand(this.poll);
      }

      return this.running != 0 ? 0 : 1;
   }

   public synchronized void start(int var1) {
      if (var1 == 0) {
         this.running = 0;
      } else {
         this.leftToRepeat = var1;
         if (this.leftToRepeat > 0) {
            this.leftToRepeat--;
         }

         this.running = 1;
         activeStopCmd = null;
         mciThread.pushCommand(new MCISoundPlayer$2(this));
      }
   }

   public synchronized void start(URL var1) {
      this.url = var1;
      this.start(1);
   }

   synchronized void doStart() {
      this.running = 2;
      if (!this.nativeStart((this.owner == null ? this.url : this.owner.getURL()).unalias())) {
         this.running = 3;
      }
   }

   synchronized void gotFinished(boolean var1) {
      if (var1 && this.running == 2) {
         this.start(this.leftToRepeat);
      }
   }

   public synchronized void stop() {
      this.leftToRepeat = 0;
      activeStopCmd = new MCISoundPlayer$3(this);
      mciThread.pushCommand(activeStopCmd);
   }

   public void volume(float var1, float var2) {
      this.volumeCmd.left = var1;
      this.volumeCmd.right = var2;
      if (!this.volumeCmd.isOnQueue) {
         mciThread.pushCommand(this.volumeCmd);
      }
   }

   static boolean access$000(MCISoundPlayer var0) {
      return var0.nativeIsFinished();
   }

   static MCISoundCommand access$100() {
      return activeStopCmd;
   }

   static void access$102(MCISoundCommand var0) {
      activeStopCmd = var0;
   }

   static void access$200(MCISoundPlayer var0) {
      var0.nativeStop();
   }

   static void access$300(MCISoundPlayer var0, float var1, float var2) {
      var0.nativeVolume(var1, var2);
   }

   private native void nativeVolume(float var1, float var2);

   private native boolean nativeStart(String var1);

   private native boolean nativeIsFinished();

   private native void nativeStop();

   public static native boolean isActive();

   static native void shutdown();
}
