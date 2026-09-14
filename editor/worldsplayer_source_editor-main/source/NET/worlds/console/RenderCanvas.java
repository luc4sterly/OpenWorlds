package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.scape.Camera;
import NET.worlds.scape.EventQueue;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.LibraryDropTarget;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.ToolTipManager;
import java.awt.Canvas;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.IllegalComponentStateException;
import java.awt.Point;
import java.util.Enumeration;
import java.util.Vector;

public class RenderCanvas extends Canvas implements FramePart, LibraryDropTarget {
   DefaultConsole universeConsole;
   private Window w;
   private Dimension dim;
   private Camera camera;
   private int xRenderExtent;
   private int yRenderExtent;
   private boolean fullScreenOverlay = false;
   private boolean mayNeedToResize;
   private Vector overlays;

   public RenderCanvas(Dimension var1) {
      this(null, var1);
   }

   public RenderCanvas(DefaultConsole var1, Dimension var2) {
      this.universeConsole = var1;
      this.dim = var2;
      this.overlays = new Vector();
   }

   public void drive() {
      if (this.w != null && Pilot.getActiveRoom() != null) {
         this.w.setDeltaMode(true);
      }
   }

   public boolean getDeltaMode() {
      return this.w == null ? false : this.w.getDeltaMode();
   }

   public void activate(Console var1, Container var2, Console var3) {
   }

   public void deactivate() {
   }

   public void setCamera(Camera var1) {
      this.camera = var1;
      if (var1 != null) {
         var1.setCanvas(this);
      }
   }

   public Camera getCamera() {
      return this.camera;
   }

   public Window getWindow() {
      return this.w;
   }

   public void update(Graphics var1) {
   }

   public void paint(Graphics var1) {
   }

   public void reshape(int var1, int var2, int var3, int var4) {
      super.reshape(var1, var2, var3, var4);
      this.mayNeedToResize = true;
   }

   public Dimension minimumSize() {
      return this.dim;
   }

   public Dimension preferredSize() {
      return this.dim;
   }

   public void addOverlay(RenderCanvasOverlay var1) {
      Debug.assert_(this.overlays != null);
      this.overlays.addElement(var1);
      this.mayNeedToResize = true;
   }

   public void removeOverlay(RenderCanvasOverlay var1) {
      Debug.assert_(this.overlays != null);
      this.overlays.removeElement(var1);
      this.mayNeedToResize = true;
   }

   private void computeOverlayDimensions() {
      int var2 = 100;
      int var1 = 100;
      this.fullScreenOverlay = false;
      Dimension var3 = this.size();
      if (this.overlays != null) {
         Enumeration var4 = this.overlays.elements();

         while (var4.hasMoreElements()) {
            RenderCanvasOverlay var5 = (RenderCanvasOverlay)var4.nextElement();
            var5.canvasResized(var3.width, var3.height);
            if (var5.isFullscreen()) {
               this.fullScreenOverlay = true;
               var2 = 0;
               var1 = 0;
            }

            int var6 = 100 - var5.getXPercent();
            int var7 = 100 - var5.getYPercent();
            if (var6 < var1) {
               var1 = var6;
            }

            if (var7 < var2) {
               var2 = var7;
            }
         }
      }

      if (var1 == 0 && var2 == 0) {
         this.xRenderExtent = this.yRenderExtent = 0;
      } else if (var1 == 0) {
         this.xRenderExtent = var3.width;
         this.yRenderExtent = (int)((double)var3.height * var2 * 0.01);
      } else if (var2 == 0) {
         this.xRenderExtent = (int)((double)var3.width * var1 * 0.01);
         this.yRenderExtent = var3.height;
      } else {
         this.xRenderExtent = var3.width;
         this.yRenderExtent = var3.height;
      }
   }

   public boolean handle(FrameEvent var1) {
      if (this.camera == null) {
         return true;
      }

      if (!this.checkForWindow(true)) {
         return true;
      }

      EventQueue.pollForEvents(this.camera);
      if (this.w == null) {
         return true;
      }

      if (this.mayNeedToResize) {
         this.computeOverlayDimensions();
         this.w.maybeResize(this.xRenderExtent, this.yRenderExtent);
         if (Window.usingMicrosoftVMHacks()) {
            Point var2 = this.getLocationOnScreen();
            Dimension var3 = this.getSize();
            this.w.reShape(var2.x, var2.y, var3.width, var3.height);
         }

         this.mayNeedToResize = false;
      }

      if (this.camera != null) {
         this.doRender();
      }

      return true;
   }

   public boolean checkForWindow(boolean var1) {
      if (this.w == null) {
         String var2 = Console.getFrame().getTitle();
         if (var2 == null) {
            return false;
         }

         try {
            this.w = new Window(var2, this.getLocationOnScreen(), this.size(), this.camera, var1);
         } catch (IllegalComponentStateException var4) {
            return false;
         } catch (WindowNotFoundException var5) {
            return false;
         }

         this.mayNeedToResize = false;
      }

      return true;
   }

   private synchronized void doRender() {
      if (this.universeConsole != null && this.universeConsole.isUniverseMode()) {
         ToolTipManager.toolTipManager().killToolTip();
         if (this.w != null) {
            this.w.hideNativeWindow();
         }
      } else {
         ToolTipManager.toolTipManager().heartbeat();
         this.w.showNativeWindow();
         if (this.fullScreenOverlay) {
            ToolTipManager.toolTipManager().killToolTip();
         } else {
            this.camera.renderToCanvas();
         }
      }
   }

   public void removeNotify() {
      if (this.w != null) {
         this.w.dispose();
         this.w = null;
      }

      super.removeNotify();
   }
}
