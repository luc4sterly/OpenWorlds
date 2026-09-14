package NET.worlds.scape;

import NET.worlds.network.URL;

public class ASFSoundPlayer extends MCISoundPlayer {
   float ang;
   float dist;
   float vol;
   int leftToRepeat;
   int running;
   private URL url;

   public ASFSoundPlayer(Sound var1) {
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
      return true;
   }

   public int getState() {
      this.gotFinished(!ASFThread.isActive());
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
         URL var2 = this.owner == null ? this.url : this.owner.getURL();
         this.running = 2;
         new ASFThread(var2, this);
      }
   }

   public synchronized void start(URL var1) {
      this.url = var1;
      this.start(1);
   }

   public static void pauseSystem() {
      ASFThread.pauseASF();
      WavSoundPlayer.pauseSystemExceptASF();
   }

   public static void resumeSystem() {
      ASFThread.resumeASF();
      WavSoundPlayer.resumeSystemExceptASF();
   }

   synchronized void gotFinished(boolean var1) {
      if (var1 && this.running == 2) {
         this.start(this.leftToRepeat);
      }
   }

   public synchronized void stop() {
      this.leftToRepeat = 0;
      ASFThread.stopASF();
   }

   public void volume(float var1, float var2) {
   }

   public static synchronized boolean isActive() {
      return ASFThread.isActive();
   }

   static synchronized void shutdown() {
      ASFThread.stopASF();
   }

   static native boolean nativePlay(String var0);
}
