package net.openworlds.awt;

/**
 * The sound output of the machine the transpiled client runs on: SDL2
 * (PulseAudio/ALSA on Linux, sceAudioOut on the PSVita). Its natives are
 * C++ (vita/native), compiled with the transpiled program; on a JVM
 * there are none and the null output is used.
 */
final class NativeAudioDevice extends AudioDevice {
   private NativeAudioDevice() {
   }

   static AudioDevice open() {
      try {
         if (nativeOpen(RATE, FRAMES)) {
            return new NativeAudioDevice();
         }
         System.err.println("[audio] no sound output: " + nativeError());
      } catch (UnsatisfiedLinkError e) {
         // a JVM: no natives
      }
      return null;
   }

   public void play(short[] block) {
      nativePlay(block, FRAMES);
   }

   public void idle() {
      nativeIdle();
   }

   private static native boolean nativeOpen(int rate, int frames);

   private static native String nativeError();

   /** Queues the block; waits while more than a few blocks are queued. */
   private static native void nativePlay(short[] block, int frames);

   /** Lets the queue run dry (the output pauses when empty). */
   private static native void nativeIdle();
}
