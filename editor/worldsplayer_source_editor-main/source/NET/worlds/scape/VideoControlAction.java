package NET.worlds.scape;

import java.io.IOException;

public class VideoControlAction extends Action {
   private final int play = 1;
   private final int stop = 2;
   private int mode = 1;
   private int repeat = 1;
   private VideoTexture videoTexture = null;
   private VideoWall videoWall = null;
   private static Object classCookie = new Object();

   VideoControlAction() {
   }

   public Persister trigger(Event var1, Persister var2) {
      if (!this.getVideoTexture()) {
         System.out.println("ERROR! Tried to attach VideoControlAction to something other than a Rect with a VideoTexture. or a VideoWall object.");
         return null;
      }

      switch (this.mode) {
         case 1:
            if (this.videoTexture == null) {
               this.videoWall.getVideoSurface().play(this.repeat);
            } else {
               this.videoTexture.getDirectShow().nPlay(this.repeat);
            }
            break;
         case 2:
            if (this.videoTexture == null) {
               this.videoWall.getVideoSurface().stop();
            } else {
               this.videoTexture.getDirectShow().nStop();
            }
      }

      return null;
   }

   private boolean getVideoTexture() {
      if (this.videoTexture != null) {
         return true;
      }

      SuperRoot var1 = this.getOwner();
      if (var1 != null && var1 instanceof Rect) {
         Rect var2 = (Rect)var1;
         this.videoTexture = var2.getVideoAttribute();
         if (this.videoTexture != null) {
            return true;
         } else if (var1 instanceof VideoWall) {
            this.videoWall = (VideoWall)var1;
            return true;
         } else {
            return false;
         }
      } else {
         return false;
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveInt(this.mode);
      var1.saveInt(this.repeat);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.mode = var1.restoreInt();
            break;
         case 1:
            super.restoreState(var1);
            this.mode = var1.restoreInt();
            this.repeat = var1.restoreInt();
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "1=Play, 2=Stop"));
            } else if (var3 == 1) {
               var5 = new Integer(this.mode);
            } else if (var3 == 2) {
               this.mode = (Integer)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Repeat count (-1 for infinite)"));
            } else if (var3 == 1) {
               var5 = new Integer(this.repeat);
            } else if (var3 == 2) {
               this.repeat = (Integer)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }
}
