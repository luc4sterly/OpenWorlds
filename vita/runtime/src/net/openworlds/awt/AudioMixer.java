package net.openworlds.awt;

import java.util.ArrayList;

/**
 * Mixes every started {@link SoundLine} into one stereo output at
 * {@link AudioDevice#RATE} Hz, as the Windows mixer did for the client's
 * PlaySound, MCI and MIDI. One thread, started with the first line; it
 * waits while no line is started. The device's play() sets the pace.
 */
final class AudioMixer implements Runnable {
   private static AudioMixer instance;

   private final ArrayList<SoundLine> lines = new ArrayList<SoundLine>();
   private final AudioDevice device;
   private final int[] acc = new int[AudioDevice.FRAMES * 2];
   private final short[] block = new short[AudioDevice.FRAMES * 2];
   /** Blocks handed to the device so far. */
   private long blocks;

   private AudioMixer(AudioDevice device) {
      this.device = device;
   }

   static synchronized AudioMixer get() {
      if (instance == null) {
         instance = new AudioMixer(AudioDevice.open());
         Thread t = new Thread(instance, "Audio mixer");
         t.setDaemon(true);
         t.setPriority(Thread.MAX_PRIORITY);
         t.start();
      }
      return instance;
   }

   void add(SoundLine line) {
      synchronized (lines) {
         if (!lines.contains(line)) {
            lines.add(line);
         }
         lines.notifyAll();
      }
   }

   void remove(SoundLine line) {
      synchronized (lines) {
         lines.remove(line);
         lines.notifyAll();
      }
   }

   /** A line started or got samples. */
   void wake() {
      synchronized (lines) {
         lines.notifyAll();
      }
   }

   /** The number of blocks handed to the device so far. */
   long blocks() {
      synchronized (lines) {
         return blocks;
      }
   }

   /** Waits until more than {@code block} blocks have been handed to the device, or for at most timeoutMillis. */
   void awaitBlock(long block, long timeoutMillis) throws InterruptedException {
      long end = System.currentTimeMillis() + timeoutMillis;
      synchronized (lines) {
         long left;
         while (blocks <= block && (left = end - System.currentTimeMillis()) > 0) {
            lines.wait(left);
         }
      }
   }

   public void run() {
      SoundLine[] active = new SoundLine[0];
      while (true) {
         long current;
         synchronized (lines) {
            boolean idle = false;
            while (!anyRunning()) {
               if (!idle) {
                  device.idle();
                  idle = true;
               }
               try {
                  lines.wait();
               } catch (InterruptedException e) {
                  return;
               }
            }
            active = lines.toArray(active);
            current = blocks;
         }
         for (int i = 0; i < acc.length; i++) {
            acc[i] = 0;
         }
         for (SoundLine l : active) {
            if (l == null) {
               // toArray marks the end of a shorter list with a null; what follows is stale
               break;
            }
            l.mixInto(acc, AudioDevice.FRAMES, AudioDevice.RATE, current);
         }
         for (int i = 0; i < acc.length; i++) {
            int v = acc[i];
            block[i] = (short) (v > 32767 ? 32767 : v < -32768 ? -32768 : v);
         }
         device.play(block);
         synchronized (lines) {
            blocks++;
            lines.notifyAll();
         }
      }
   }

   private boolean anyRunning() {
      for (SoundLine l : lines) {
         if (l.isRunning()) {
            return true;
         }
      }
      return false;
   }
}
