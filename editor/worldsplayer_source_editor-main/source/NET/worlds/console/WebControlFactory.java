package NET.worlds.console;

public class WebControlFactory {
   public static WebControlImp createWebControlImp(int var0, boolean var1, boolean var2) throws NoWebControlException {
      try {
         return new IEWebControlImp(var0, var1, var2);
      } catch (Exception var4) {
         System.out.println("WebControlImp blew chow: " + var4.toString());
         throw new NoWebControlException();
      }
   }
}
