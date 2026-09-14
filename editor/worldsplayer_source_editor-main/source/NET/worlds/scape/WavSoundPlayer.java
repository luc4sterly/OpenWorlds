package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.util.Vector;

public class WavSoundPlayer extends SoundPlayer implements Runnable {
   float ang;
   float dist;
   float vol;
   private String playingSoundFile = "";
   private URL url;
   private static Vector soundStack = new Vector();
   private static Thread activeThread;
   int repeatsLeft;
   private static int playingThreads;
   private static int systemPaused;
   static boolean ignoreVolumeChanges = IniFile.gamma().getIniInt("ignoreVolumeChanges", 1) != 0;
   private static WavSoundTerminator terminator = new WavSoundTerminator();
   private static float lastLeftVol;
   private static float lastRightVol;

   public WavSoundPlayer(Sound var1) {
      super(var1);
   }

   public static native void nativeInit();

   public boolean open(float var1, float var2, boolean var3, boolean var4) {
      return true;
   }

   public void close() {
      this.stop();
   }

   public boolean position(Point3Temp var1, Point3Temp var2, Point3Temp var3, Point3Temp var4) {
      Point3Temp var5 = Point3Temp.make(var2).minus(var1);
      Point3Temp var6 = Point3Temp.make(var3).cross(var4);
      float var7 = var5.dot(var3);
      float var8 = var5.dot(var6);
      this.ang = (float)(Math.atan2(var7, var8) / Math.PI);
      this.dist = var5.length();
      return this.setVolume(this.vol);
   }

   public boolean setVolume(float var1) {
      this.vol = var1;
      float var2 = 0.5F;
      if (this.owner != null && this.owner.getPanning()) {
         var2 = Math.abs(this.ang);
         if (this.ang < 0.0F) {
            var1 = this.vol * (float)(0.5 + Math.abs(0.5 + this.ang));
         }
      }

      if (this.owner != null && this.owner.getAttenuate()) {
         float var3 = this.owner.getStopDistance();
         if (this.dist > var3) {
            this.volume(0.0F, 0.0F);
            return false;
         }

         var1 *= (var3 - this.dist) / var3;
      }

      this.volume(var1 * var2, var1 * (1.0F - var2));
      return true;
   }

   public int getState() {
      return soundStack.contains(this) ? 0 : 1;
   }

   public void start(URL var1) {
      this.url = var1;
      this.start(1);
   }

   private static WavSoundPlayer getActive() {
      return !soundStack.isEmpty() ? (WavSoundPlayer)soundStack.lastElement() : null;
   }

   public static boolean isActive() {
      return !soundStack.isEmpty();
   }

   private void play(int var1, boolean var2) {
      this.playingSoundFile = this.url.unalias();
      soundStack.removeElement(this);
      soundStack.addElement(this);
      this.repeatsLeft = var1;
      if (this.repeatsLeft < 0) {
         if (!var2 && systemPaused == 0) {
            this.nativePlay(true);
         }

         activeThread = null;
      } else {
         activeThread = new Thread(this);
         activeThread.start();
      }
   }

   public void start(int var1) {
      synchronized (soundStack) {
         WavSoundPlayer var3 = getActive();
         Debug.assert_(this.repeatsLeft == 0 && var3 != this);
         if (this.owner != null) {
            this.url = this.owner.getURL();
         }

         boolean var4 = activeThread == null;
         boolean var5 = var3 != null && var4 && var1 < 0 && var3.playingSoundFile.equals(this.url.unalias());
         if (var3 != null) {
            var3.stop(var5);
            if (var4) {
               soundStack.addElement(var3);
            }
         }

         this.play(var1, var5);
      }
   }

   public void run() {
      synchronized (soundStack) {
         if (systemPaused > 0) {
            this.repeatsLeft = 0;
            return;
         }

         playingThreads++;
      }

      while (this.repeatsLeft > 0) {
         synchronized (soundStack) {
            if (activeThread != Thread.currentThread()) {
               break;
            }

            if (this.repeatsLeft > 0) {
               this.repeatsLeft--;
            }
         }

         this.nativePlay(false);
      }

      synchronized (soundStack) {
         if (activeThread == Thread.currentThread()) {
            Debug.assert_(getActive() == this);
            soundStack.removeElement(this);
            activeThread = null;
            WavSoundPlayer var2 = getActive();
            if (var2 != null) {
               var2.play(-1, false);
            }
         }

         playingThreads--;
         soundStack.notifyAll();
      }
   }

   private void stop(boolean var1) {
      if (getActive() == this) {
         boolean var2 = activeThread == null;
         Debug.assert_(this.repeatsLeft < 0 && var2 || !var1);
         this.repeatsLeft = 0;
         if (!var1 && var2 && systemPaused == 0) {
            this.nativeStop();
         }

         activeThread = null;
      }

      soundStack.removeElement(this);
   }

   public void stop() {
      synchronized (soundStack) {
         if (getActive() == this) {
            this.stop(false);
            WavSoundPlayer var2 = getActive();
            if (var2 != null) {
               var2.play(-1, false);
            }
         } else {
            soundStack.removeElement(this);
         }
      }
   }

   public static void pauseSystem() {
      pauseSystemExceptASF();
   }

   public static void pauseSystemExceptASF() {
      synchronized (soundStack) {
         WavSoundPlayer var1 = getActive();
         boolean var2 = activeThread == null;
         if (var1 != null) {
            if (var2) {
               var1.nativeStop();
            } else {
               var1.stop(false);
            }
         }

         systemPaused++;
         if (var1 != null) {
            var1.play(-1, false);
         }

         while (playingThreads > 0) {
            try {
               soundStack.wait();
            } catch (InterruptedException var5) {
            }
         }
      }
   }

   public static void resumeSystem() {
      resumeSystemExceptASF();
   }

   public static void resumeSystemExceptASF() {
      synchronized (soundStack) {
         if (systemPaused > 0) {
            systemPaused = 0;
            WavSoundPlayer var1 = getActive();
            if (var1 != null && activeThread == null) {
               var1.play(-1, false);
            }
         }
      }
   }

   public void volume(float var1, float var2) {
      if (!ignoreVolumeChanges) {
         synchronized (soundStack) {
            if (getActive() == this && (lastLeftVol != var1 || lastRightVol != var2)) {
               lastLeftVol = var1;
               lastRightVol = var2;
               this.nativeVolume(var1, var2);
            }
         }
      }
   }

   private native void nativePlay(boolean var1);

   private native void nativeVolume(float var1, float var2);

   private native void nativeStop();

   static {
      nativeInit();
   }
}
