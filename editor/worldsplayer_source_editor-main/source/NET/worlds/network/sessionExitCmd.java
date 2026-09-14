package NET.worlds.network;

import NET.worlds.core.Debug;

public class sessionExitCmd extends propCmd {
   public static final byte SESSIONEXITCMD = 7;

   public sessionExitCmd() {
      this._commandType = 7;
   }

   public sessionExitCmd(OldPropertyList var1) {
      this._commandType = 7;
      this._propList = var1;
   }

   void process(WorldServer var1) throws Exception {
      Debug.dAssert(var1.getState() == 16);
      netProperty var2 = this._propList.elementAt(0);

      try {
         int var3 = Integer.parseInt(var2.value());
         if (var3 != 0) {
            throw new VarErrorException(var3);
         }
      } catch (NumberFormatException var4) {
         System.err.println("appInitCmd: couldn't parse VAR_ERROR = " + var2.value());
      }

      var1.setState(17);
   }

   public String toString(WorldServer var1) {
      return "SESSEXIT " + this._propList;
   }
}
