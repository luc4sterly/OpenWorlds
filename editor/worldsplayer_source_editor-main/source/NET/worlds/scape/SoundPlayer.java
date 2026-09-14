package NET.worlds.scape;

public abstract class SoundPlayer {
   Sound owner;
   public static final int IS_PLAYING = 0;
   public static final int IS_STOPPED = 1;
   public static final int IS_TERMINATED = 2;
   public static final int IS_ERROR = 3;

   SoundPlayer(Sound var1) {
      this.owner = var1;
   }

   public Sound getOwner() {
      return this.owner;
   }

   public abstract boolean open(float var1, float var2, boolean var3, boolean var4);

   public abstract void start(int var1);

   public abstract boolean position(Point3Temp var1, Point3Temp var2, Point3Temp var3, Point3Temp var4);

   public abstract int getState();

   public abstract void stop();

   public abstract void close();

   public abstract boolean setVolume(float var1);
}
