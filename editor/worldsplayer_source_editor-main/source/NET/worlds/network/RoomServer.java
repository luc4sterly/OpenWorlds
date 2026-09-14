package NET.worlds.network;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;

public class RoomServer extends AnonRoomServer {
   private boolean _firstRetry = true;

   public synchronized void incRefCnt(Object var1) {
      super.incRefCnt(var1);
      this.startConnect();
   }

   protected void state_Authprompt() {
      this._state.setState(3);
   }

   protected sessionInitCmd buildSessionInitCmd() {
      OldPropertyList var1 = new OldPropertyList();
      String var2 = null;
      var1.addProperty(new netProperty(3, String.valueOf(this.getVersion())));
      var1.addProperty(new netProperty(9, String.valueOf(this._clientVersion)));
      this._firstLogon = this._galaxy.addPendingServer(this);
      if (this._firstLogon) {
         return null;
      }

      int var3 = IniFile.gamma().getIniInt("avatars", 24);
      var1.addProperty(new netProperty(7, Integer.toString(var3)));
      Debug.dAssert(this._galaxy.getChatname() != null);
      var2 = this._galaxy.getChatname();
      this.regShortID(1, var2);
      var1.addProperty(new netProperty(2, var2));
      if (this._galaxy.getLoginMode() != 3 && this._galaxy.getPassword() != null) {
         var1.addProperty(new netProperty(6, this._galaxy.getPassword()));
      }

      if ((getDebugLevel() & 4) > 0) {
         synchronized (System.out) {
            System.out.println(this._serverURL.getHost() + ": sending sessionInit.");
            Debug.dAssert(var2 != null);
            System.out.println("  username = \"" + var2 + "\"");
            if (this._galaxy.getPassword() != null) {
               System.out.println("  password = \"" + this._galaxy.getPassword() + "\"");
            }
         }
      }

      return new sessionInitCmd(var1);
   }

   protected void state_Sleeping(int var1) {
      if (this.getGalaxy().isActive()) {
         super.state_Sleeping(var1);
      } else {
         this._state.setState(0);
      }
   }

   void goOnline() {
      this._requestOffline = false;
   }
}
