package NET.worlds.core;

/**
 * Java behaviour the 2004 client relies on and today's Java no longer has.
 * Java differences, not gamma.dll (AWT ones are in {@link AwtCompat}).
 */
public final class JavaCompat {
   private JavaCompat() {
   }

   /**
    * Thread.stop() as WorldServer.cleanup uses it on the packet reader of a
    * server it lets go (state_Detaching). Since Java 20 stop() only throws
    * UnsupportedOperationException (JDK-8289610, "Degrade Thread.stop"), which
    * cut cleanup short: neither the output stream nor the socket got closed and
    * the detach did not finish.
    *
    * <p>The reader (netPacketReader.run) is blocked reading that socket, which
    * cleanup closes a few lines later: the read fails, run() queues an
    * ExceptionCmd on the reader's own queue, which nobody reads any more
    * (cleanup has set WorldServer._reader to null), and the thread ends, as
    * the ThreadDeath of stop() ended it. So all that is left to do here is
    * the interrupt, the part of stop() Java still offers.
    */
   public static void stopThread(Thread t) {
      if (t != null) {
         t.interrupt();
      }
   }
}
