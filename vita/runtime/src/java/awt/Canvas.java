package java.awt;

import java.awt.image.BufferStrategy;

/** A component to draw on, as java.awt.Canvas. */
public class Canvas extends Component {
   private BufferStrategy bufferStrategy;

   public Canvas() {
   }

   public Canvas(GraphicsConfiguration config) {
   }

   public void addNotify() {
      synchronized (LOCK) {
         super.addNotify();
      }
   }

   public void paint(Graphics g) {
      g.clearRect(0, 0, width, height);
   }

   public void update(Graphics g) {
      g.clearRect(0, 0, width, height);
      paint(g);
   }

   boolean postsOldMouseEvents() {
      return true;
   }

   public void createBufferStrategy(int numBuffers) {
      if (numBuffers < 1) {
         throw new IllegalArgumentException("Number of buffers must be at least 1");
      }
      if (!displayable) {
         throw new IllegalStateException("Component must have a valid peer");
      }
      bufferStrategy = new ComponentBufferStrategy(this);
   }

   public void createBufferStrategy(int numBuffers, BufferCapabilities caps) throws AWTException {
      createBufferStrategy(numBuffers);
   }

   public BufferStrategy getBufferStrategy() {
      return bufferStrategy;
   }
}
