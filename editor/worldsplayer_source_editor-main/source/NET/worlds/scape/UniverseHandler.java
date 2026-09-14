package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.console.UniversePanel;

public class UniverseHandler {
   public static boolean handle(MouseDeltaEvent var0) {
      if (var0.dx != 0 || var0.dy != 0) {
         Console var1 = Console.getActive();
         UniversePanel var2 = null;
         if (var1 instanceof DefaultConsole) {
            var2 = ((DefaultConsole)var1).getUniverse();
         }

         if (var2 != null) {
            var2.addOffset(-var0.dx, -var0.dy);
            return true;
         }
      }

      return false;
   }

   public static boolean handle(KeyDownEvent var0) {
      Console var1 = Console.getActive();
      UniversePanel var2 = null;
      if (var1 instanceof DefaultConsole) {
         var2 = ((DefaultConsole)var1).getUniverse();
      }

      if (var2 != null) {
         switch (var0.key) {
            case '\ue325':
               var2.keyDown(null, 1006);
               return true;
            case '\ue326':
               var2.keyDown(null, 1004);
               return true;
            case '\ue327':
               var2.keyDown(null, 1007);
               return true;
            case '\ue328':
               var2.keyDown(null, 1005);
               return true;
         }
      }

      return false;
   }

   public static boolean handle(KeyUpEvent var0) {
      Console var1 = Console.getActive();
      UniversePanel var2 = null;
      if (var1 instanceof DefaultConsole) {
         var2 = ((DefaultConsole)var1).getUniverse();
      }

      if (var2 != null) {
         var2.keyUp(null, 1004);
         return true;
      } else {
         return false;
      }
   }
}
