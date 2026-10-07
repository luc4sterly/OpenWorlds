package java.awt;

import java.awt.image.BufferStrategy;

/**
 * Canvas.createBufferStrategy: the drawing goes straight into the window's
 * pixels (the canvas' part of them) and show() hands that area to the
 * screen at once. The bridge blits each 3D frame this way.
 */
final class ComponentBufferStrategy extends BufferStrategy {
   private final Component target;

   ComponentBufferStrategy(Component target) {
      this.target = target;
   }

   public BufferCapabilities getCapabilities() {
      return new BufferCapabilities(new ImageCapabilities(false), new ImageCapabilities(false), null);
   }

   public Graphics getDrawGraphics() {
      Graphics g = target.getGraphics();
      return g != null ? g : WindowSystem.nullGraphics();
   }

   public boolean contentsLost() {
      return false;
   }

   public boolean contentsRestored() {
      return false;
   }

   public void show() {
      WindowSystem.showNow(target);
   }

   public void dispose() {
   }
}
