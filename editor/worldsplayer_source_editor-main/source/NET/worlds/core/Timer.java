package NET.worlds.core;

public class Timer extends Thread {
   private float m_delay;
   private TimerCallback m_callback;

   public Timer(float var1, TimerCallback var2) {
      this.m_delay = var1;
      this.m_callback = var2;
   }

   public void run() {
      try {
         sleep((long)(this.m_delay * 1000.0F));
      } catch (InterruptedException var2) {
      }

      this.m_callback.timerDone();
   }
}
