package NET.worlds.network;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;

public class AnonRoomServer extends WorldServer {
   protected sessionInitCmd buildSessionInitCmd() {
      OldPropertyList var1 = new OldPropertyList();
      String var2 = null;
      Debug.dAssert(this._galaxy.getLoginMode() != 1);
      Debug.dAssert(this._galaxy.getPassword() == null);
      Debug.dAssert(this._galaxy.getSerialNum() == null);
      var1.addProperty(new netProperty(3, String.valueOf(this.getVersion())));
      var1.addProperty(new netProperty(9, String.valueOf(this._clientVersion)));
      this._firstLogon = this._galaxy.addPendingServer(this);
      Debug.dAssert(this._firstLogon);
      int var3 = IniFile.gamma().getIniInt("avatars", 24);
      var1.addProperty(new netProperty(7, Integer.toString(var3)));
      switch (this._galaxy.getLoginMode()) {
         case 2:
            Debug.dAssert(this._galaxy.getChatname() != null);
            var2 = this._galaxy.getChatname();
            this.regShortID(1, var2);
            var1.addProperty(new netProperty(2, var2));
            break;
         case 3:
            Debug.dAssert(this._galaxy.getGuestExpiration() != null);
            var1.addProperty(new netProperty(14, this._galaxy.getGuestExpiration()));
            var1.addProperty(new netProperty(12, "1"));
            break;
         default:
            Debug.dAssert(false);
      }

      if ((getDebugLevel() & 4) > 0) {
         synchronized (System.out) {
            System.out.println(this._serverURL.getHost() + ": sending AnonRoomServer sessionInit.");
            if (this._firstLogon && this._galaxy.getLoginMode() == 3) {
               System.out.println("             VAR_GUEST");
            } else {
               Debug.dAssert(var2 != null);
               System.out.println("  username = \"" + var2 + "\"");
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
         if (var1 != null) {
            try {
               this.sendNetMsg(var1);
            } catch (PacketTooLargeException var3) {
               Debug.dAssert(false);
            }

            this._state.setState(8);
         } else {
            this._lastError = new VarErrorException(204);
            this._state.setState(17);
         }
      }
   }
}
