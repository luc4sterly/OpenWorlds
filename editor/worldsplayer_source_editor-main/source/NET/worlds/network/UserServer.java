package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;

public class UserServer extends AnonUserServer {
   protected sessionInitCmd buildSessionInitCmd() {
      OldPropertyList var1 = new OldPropertyList();
      String var2 = this._galaxy.getChatname();
      this._galaxy.setChatname(Console.parseUnicode(var2));
      var1.addProperty(new netProperty(3, String.valueOf(this.getVersion())));
      var1.addProperty(new netProperty(9, String.valueOf(this._clientVersion)));
      this._firstLogon = this._galaxy.addPendingServer(this);
      switch (this.getGalaxy().getLoginMode()) {
         case 1:
         case 2:
            Debug.dAssert(this._galaxy.getChatname() != null);
            this.regShortID(1, Console.parseUnicode(this._galaxy.getChatname()));
            var1.addProperty(new netProperty(2, Console.parseUnicode(this._galaxy.getChatname())));
            if (this._galaxy.getNewChatname() != null) {
               var1.addProperty(new netProperty(28, this._galaxy.getNewChatname()));
            }

            if (this._galaxy.getPassword() != null) {
               var1.addProperty(new netProperty(6, this._galaxy.getPassword()));
            }

            if (this._galaxy.getNewPassword() != null) {
               var1.addProperty(new netProperty(20, this._galaxy.getNewPassword()));
            }

            if (this._galaxy.getLoginMode() == 1) {
               if (this._galaxy.getSerialNum() != null) {
                  var1.addProperty(new netProperty(10, this._galaxy.getSerialNum()));
               }
            } else if (this._firstLogon) {
               var1.addProperty(new netProperty(12, "1"));
            }
            break;
         case 3:
            Debug.dAssert(this._galaxy.getGuestExpiration() != null);
            var1.addProperty(new netProperty(14, this._galaxy.getGuestExpiration()));
            if (this._firstLogon) {
               var1.addProperty(new netProperty(12, "1"));
            }
            break;
         default:
            Debug.dAssert(false);
      }

      if ((getDebugLevel() & 4) > 0) {
         synchronized (System.out) {
            System.out.println(this._serverURL.getHost() + ": sending sessionInit.");
            System.out.println("  username = \"" + this._galaxy.getChatname() + "\"");
            if (this._galaxy.getPassword() != null) {
               System.out.println("  password = " + this._galaxy.getPassword());
            }

            if (this._galaxy.getLoginMode() == 1 && this._galaxy.getSerialNum() != null) {
               System.out.println("  serial # = " + this._galaxy.getSerialNum());
            }

            if (this._galaxy.getLoginMode() == 3) {
               System.out.println("             VAR_GUEST");
            }
         }
      }

      return new sessionInitCmd(var1);
   }
}
