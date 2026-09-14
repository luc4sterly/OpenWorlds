package NET.worlds.network;

import NET.worlds.core.Debug;

public class AnonUserServer extends WorldServer {
   protected sessionInitCmd buildSessionInitCmd() {
      OldPropertyList var1 = new OldPropertyList();
      var1.addProperty(new netProperty(3, String.valueOf(this.getVersion())));
      var1.addProperty(new netProperty(9, String.valueOf(this._clientVersion)));
      this._firstLogon = this._galaxy.addPendingServer(this);
      Debug.dAssert(this._firstLogon);
      Debug.dAssert(this._galaxy.getPassword() == null);
      Debug.dAssert(this._galaxy.getLoginMode() != 1);
      Debug.dAssert(this._galaxy.getLoginMode() != 4);
      Debug.dAssert(this._galaxy.getSerialNum() == null);
      switch (this._galaxy.getLoginMode()) {
         case 2:
            Debug.dAssert(this._galaxy.getChatname() != null);
            this.regShortID(1, this._galaxy.getChatname());
            var1.addProperty(new netProperty(2, this._galaxy.getChatname()));
            if (this._firstLogon) {
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

            if (this._galaxy.getLoginMode() == 3) {
               System.out.println("             VAR_GUEST");
            }
         }
      }

      return new sessionInitCmd(var1);
   }

   protected void state_XMIT_SI() {
      if (this._requestOffline) {
         this._state.setState(17);
      } else {
         sessionInitCmd var1 = this.buildSessionInitCmd();

         try {
            this.sendNetMsg(var1);
         } catch (PacketTooLargeException var3) {
            Debug.dAssert(false);
         }

         this._state.setState(8);
      }
   }
}
