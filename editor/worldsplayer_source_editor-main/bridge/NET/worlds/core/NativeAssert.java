package NET.worlds.core;

/**
 * gamma.dll's native assertion (FUN_00402800 -> FUN_004028c0): builds
 * "Assertion failed: line N in file F." , writes it with a newline to the
 * native log stream (0x49eda8), shows a MessageBox titled "Internal Program
 * Error" and calls exit(0x29). Here the message goes to stderr and the
 * process exits with the same code; the modal box is not shown so a run
 * without a user at the screen still terminates.
 */
public final class NativeAssert {
   private NativeAssert() {
   }

   public static void fail(String file, int line) {
      System.err.println("Assertion failed: line " + line + " in file " + file + ".");
      System.err.flush();
      System.exit(41);
   }
}
