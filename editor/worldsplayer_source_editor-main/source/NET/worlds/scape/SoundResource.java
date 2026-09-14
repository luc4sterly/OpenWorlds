package NET.worlds.scape;

class SoundResource {
   private static SoundResource instance = null;
   public static final int RSX = 1;
   public static final int RA = 2;
   private int currentPlayer = 0;
   private int counter = 0;
   private boolean isShutdownTime = false;

   private SoundResource() {
   }

   private static void debugOut(int var0, String var1) {
      if (Sound.debugLevel > var0) {
         System.out.println(var1);
      }
   }

   public static SoundResource instance() {
      if (instance == null) {
         debugOut(6, "Instantiating a new SoundResource");
         instance = new SoundResource();
      }

      return instance;
   }

   public boolean syncLock(int var1) {
      debugOut(6, "Calling syncLock with type " + var1 + " counter " + this.counter);
      if (this.isShutdownTime) {
         return false;
      }

      if (var1 != this.currentPlayer) {
         this.currentPlayer = var1;
         if (this.counter > 0) {
            this.isShutdownTime = true;
         } else {
            this.currentPlayer = var1;
            this.counter = 1;
         }
      } else {
         this.counter++;
      }

      return true;
   }

   public synchronized void asyncLock() {
      debugOut(6, "SoundResource::asyncLock with " + this.isShutdownTime);
      boolean var1 = false;

      while (this.isShutdownTime) {
         var1 = true;
         Thread.yield();
         debugOut(6, "asyncLock yield");
      }

      if (var1) {
         debugOut(6, "asyncLock: adding artificial delay");

         try {
            Thread.sleep(500L);
         } catch (InterruptedException var3) {
         }
      }
   }

   public boolean syncUnlock() {
      debugOut(6, "SoundResource::syncUnlock with " + this.counter);
      boolean var1 = false;
      this.counter--;
      if (this.counter <= 0) {
         var1 = true;
      }

      if (this.counter <= 0 && this.isShutdownTime) {
         this.counter = 1;
         this.isShutdownTime = false;
      }

      return var1;
   }

   public boolean isOK() {
      return !this.isShutdownTime;
   }
}
