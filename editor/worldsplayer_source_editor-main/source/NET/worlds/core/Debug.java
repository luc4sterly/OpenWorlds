package NET.worlds.core;

public class Debug {
   public static final boolean ON = true;

   public static void assert_(boolean var0) throws AssertionException {
      if (!var0) {
         throw new AssertionException();
      }
   }

   public static void assert_(boolean var0, String var1) throws AssertionException {
      if (!var0) {
         throw new AssertionException(var1);
      }
   }

   public static void dAssert(boolean var0) throws AssertionException {
      if (!var0) {
         throw new AssertionException();
      }
   }

   public static void dAssert(boolean var0, String var1) {
      if (!var0) {
         throw new AssertionException(var1);
      }
   }
}
