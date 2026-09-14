package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;

public class AutoServer extends WorldServer {
   private static int counter = 0;

   public AutoServer() {
      if (counter++ > 0) {
         System.out.println("DEBUG: Created second AutoServer class.");
         Galaxy.printDebugging();
         new Exception().printStackTrace(System.out);
      }
   }

   public synchronized void incRefCnt(Object var1) {
      super.incRefCnt(var1);
      this.startConnect();
   }

   protected void state_Authprompt() {
      this._state.setState(3);
   }

   protected void state_XMIT_SI() {
      WorldServer var1 = null;
      int var2 = this.getServerType();
      if ((getDebugLevel() & 32) > 0) {
         System.out.println(this + ": AutoServer detected server type " + var2);
      }

      switch (var2) {
         case 1:
            var1 = new UserServer();
            break;
         case 2:
            var1 = new AnonUserServer();
            break;
         case 3:
            Console.println(this + Console.message("Error-in-server"));
            Console.println(this + Console.message("Error-user-server"));
            var1 = null;
            break;
         case 4:
            var1 = new AnonRoomServer();
            break;
         default:
            Debug.dAssert(false);
      }

      if (var1 != null) {
         var1.reuseConnection(this);
         var1.initInstance(this._galaxy, this._serverURL);
         var1.propertyUpdate(this._propList);
      }

      this._galaxy.killServer(this);
      this._galaxy.swapServer(this, var1);
      this._galaxy.setGalaxyType(var2);
      if (this._refCnt - this._tmpRefCnt != 0) {
         System.out.println(this + ": bad reference counts.  DEBUG INFO:");
         System.out.println("\t_refCnt = " + this._refCnt);
         System.out.println("\t_tmpRefCnt = " + this._tmpRefCnt);
         this.printReferrers();
      }

      Debug.dAssert(this._refCnt - this._tmpRefCnt == 0);
      this._state.setState(17);
   }

   public String toString() {
      return "AutoServer(" + super.toString() + ")";
   }

   void goOnline() {
      super.goOnline();
      System.out.println("DEBUG: AutoServer going online!");
      new Exception().printStackTrace(System.out);
   }
}
