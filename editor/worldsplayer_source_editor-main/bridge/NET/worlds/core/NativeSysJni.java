package NET.worlds.core;

/**
 * The JNI {@code ThrowNew} that gamma.dll's system natives use (its helper
 * FUN_00402930 = FindClass + ThrowNew). JNI can leave a checked exception
 * pending even though the Java method does not declare it (e.g.
 * {@code RegKey.createKey} throws {@code RegKeyNotFoundException} and
 * {@code IDispatch.Invoke} throws {@code IOException} without a
 * {@code throws} clause); the Java compiler does not let you write that, so
 * it is thrown unchecked.
 */
public final class NativeSysJni {
   private NativeSysJni() {
   }

   /** Throws {@code t} as is, checked or not. Never returns. */
   public static RuntimeException throwNew(Throwable t) {
      NativeSysJni.<RuntimeException>sneaky(t);
      return null;
   }

   @SuppressWarnings("unchecked")
   private static <T extends Throwable> void sneaky(Throwable t) throws T {
      throw (T) t;
   }
}
