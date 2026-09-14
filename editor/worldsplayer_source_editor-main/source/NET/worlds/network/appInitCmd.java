package NET.worlds.network;

import NET.worlds.core.Debug;

public class appInitCmd extends propCmd {
   public static final byte APPINITCMD = 8;

   public appInitCmd() {
      this._commandType = 8;
   }

   public appInitCmd(String var1) {
      this._commandType = 8;
      this._propList.addProperty(new netProperty(1, var1));
   }

   void process(WorldServer var1) throws Exception {
      Debug.dAssert(var1.getState() == 10);
      netProperty var2 = this._propList.elementAt(0);

      try {
         int var3 = Integer.parseInt(var2.value());
         if (var3 != 0) {
            throw new VarErrorException(var3);
         }
      } catch (NumberFormatException var4) {
         System.err.println("appInitCmd: couldn't parse VAR_ERROR = " + var2.value());
      }

      var1.setState(11);
   }

   public String toString(WorldServer var1) {
      return "APPINIT  " + this._propList;
   }
}
