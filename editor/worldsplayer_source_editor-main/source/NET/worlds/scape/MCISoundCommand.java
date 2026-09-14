package NET.worlds.scape;

abstract class MCISoundCommand {
   boolean isOnQueue;
   float left;
   float right;
   int frameNum;

   public abstract void run();

   public void onQueue(boolean var1) {
      this.isOnQueue = var1;
   }
}
