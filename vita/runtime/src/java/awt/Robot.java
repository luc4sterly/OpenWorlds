package java.awt;

/** java.awt.Robot: moving the pointer is all the client asks of it. */
public class Robot {
   public Robot() throws AWTException {
   }

   public Robot(GraphicsDevice screen) throws AWTException {
   }

   public synchronized void mouseMove(int x, int y) {
   }

   public synchronized void mousePress(int buttons) {
   }

   public synchronized void mouseRelease(int buttons) {
   }

   public synchronized void mouseWheel(int wheelAmt) {
   }

   public synchronized void keyPress(int keycode) {
   }

   public synchronized void keyRelease(int keycode) {
   }

   public synchronized Color getPixelColor(int x, int y) {
      return Color.black;
   }

   public synchronized void setAutoDelay(int ms) {
   }

   public synchronized void delay(int ms) {
      try {
         Thread.sleep(ms);
      } catch (InterruptedException e) {
         Thread.currentThread().interrupt();
      }
   }

   public synchronized void waitForIdle() {
   }
}
