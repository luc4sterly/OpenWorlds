package NET.worlds.core;

/**
 * El {@code ThrowNew} de JNI que usan los nativos de sistema de gamma.dll
 * (su ayudante FUN_00402930 = FindClass + ThrowNew). JNI puede dejar
 * pendiente una excepción comprobada aunque el método Java no la declare
 * (p. ej. {@code RegKey.createKey} lanza {@code RegKeyNotFoundException} e
 * {@code IDispatch.Invoke} lanza {@code IOException} sin {@code throws}); el
 * compilador de Java no deja escribir eso, así que se lanza sin comprobar.
 */
public final class NativeSysJni {
   private NativeSysJni() {
   }

   /** Lanza {@code t} tal cual, sea comprobada o no. Nunca vuelve. */
   public static RuntimeException throwNew(Throwable t) {
      NativeSysJni.<RuntimeException>sneaky(t);
      return null;
   }

   @SuppressWarnings("unchecked")
   private static <T extends Throwable> void sneaky(Throwable t) throws T {
      throw (T) t;
   }
}
