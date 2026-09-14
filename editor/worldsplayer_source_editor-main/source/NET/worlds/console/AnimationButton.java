package NET.worlds.console;

import NET.worlds.scape.FrameEvent;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Graphics;

public class AnimationButton extends ImageCanvas implements MainCallback, FramePart, DialogDisabled {
   private static final int frameInterval = 33;
   private String movieName;
   private int frameCount;
   private int curFrame;
   private int width;
   private int height;
   private boolean playVideoNext;
   private int videoHandle = -1;
   private boolean isDialogDisabled;

   public AnimationButton(String var1, int var2, String var3) {
      super(var1);
      this.frameCount = var2;
      this.movieName = var3;
   }

   public void paint(Graphics var1) {
      var1.clipRect(0, 0, this.width, this.height);
      var1.drawImage(this.image_, -this.width * this.curFrame, 0, null);
   }

   public Dimension preferredSize() {
      Dimension var1 = super.preferredSize();
      return new Dimension(this.width = var1.width / this.frameCount, this.height = var1.height);
   }

   public Dimension minimumSize() {
      return this.preferredSize();
   }

   public void mainCallback() {
      if (this.videoHandle == -1) {
         this.videoHandle = Window.playVideoClip(this, this.movieName);
         if (this.videoHandle == -1) {
            this.videoHandle = Window.playVideoClip(this, "..\\" + this.movieName);
            if (this.videoHandle == -1) {
               Main.unregister(this);
            }
         }
      } else if (!Window.isVideoPlaying(this.videoHandle)) {
         Main.unregister(this);
         this.videoHandle = -1;
         this.repaint();
      }
   }

   public boolean mouseDown(Event var1, int var2, int var3) {
      if (this.isDialogDisabled) {
         return false;
      }

      if (this.playVideoNext) {
         Main.register(this);
         this.playVideoNext = false;
      } else if (this.videoHandle == -1) {
         Graphics var4 = this.getGraphics();
         var4.clipRect(0, 0, this.width, this.height);
         int var5 = this.curFrame == 0 ? 1 : -1;
         long var6 = System.currentTimeMillis();
         long var8 = 0L;

         for (int var10 = 1; var10 < this.frameCount; var10++) {
            this.curFrame += var5;
            var4.drawImage(this.image_, -this.width * this.curFrame, 0, null);
            long var11 = System.currentTimeMillis() - var6;
            var8 += 33L;
            long var13 = var8 - var11;
            if (var13 > 0L) {
               try {
                  Thread.sleep(var13);
               } catch (InterruptedException var16) {
               }
            }
         }

         if (this.curFrame == this.frameCount - 1) {
            this.playVideoNext = true;
         }

         var4.dispose();
      }

      return true;
   }

   public void activate(Console var1, Container var2, Console var3) {
   }

   public void deactivate() {
   }

   public boolean action(Event var1, Object var2) {
      return false;
   }

   public boolean handle(FrameEvent var1) {
      return false;
   }

   public void dialogDisable(boolean var1) {
      this.isDialogDisabled = var1;
   }
}
