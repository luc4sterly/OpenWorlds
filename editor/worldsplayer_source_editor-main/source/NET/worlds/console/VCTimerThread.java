package NET.worlds.console;

class VCTimerThread extends Thread {
   private long _wait;
   public VoiceChat _vc;

   VCTimerThread(VoiceChat var1, long var2) {
      this._vc = var1;
      this._wait = var2;
   }

   public void run() {
      try {
         sleep(this._wait);
      } catch (InterruptedException var2) {
         this.stop();
      }

      if (this._vc != null) {
         this._vc.checkConnected();
      }
   }
}
