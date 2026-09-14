package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;
import java.util.Enumeration;

public class sessionInitCmd extends propCmd {
   public static final byte SESSIONINITCMD = 6;

   public sessionInitCmd() {
      this._commandType = 6;
   }

   public sessionInitCmd(String var1, String var2, String var3, String var4, String var5) {
      this._commandType = 6;
      Debug.dAssert(var1 != null);
      this._propList.addProperty(new netProperty(2, var1));
      if (var2 != null) {
         this._propList.addProperty(new netProperty(6, var2));
      }

      this._propList.addProperty(new netProperty(3, var3));
      this._propList.addProperty(new netProperty(7, var4));
      this._propList.addProperty(new netProperty(9, var5));
   }

   public sessionInitCmd(OldPropertyList var1) {
      this._commandType = 6;
      this._propList = var1;
   }

   void process(WorldServer var1) throws Exception {
      if (var1.getState() == 8) {
         for (int var2 = 0; var2 < this._propList.size(); var2++) {
            netProperty var3 = this._propList.elementAt(var2);
            switch (var3.property()) {
               case 1:
               case 3:
               case 8:
               case 13:
               case 15:
                  break;
               case 2:
                  var1.setUsername(var3.value());
                  var1.getGalaxy().setNewChatname(null);
                  break;
               case 4:
                  try {
                     int var9 = Integer.parseInt(var3.value());
                     if (var9 != 0) {
                        throw new VarErrorException(var9);
                     }
                  } catch (NumberFormatException var7) {
                     System.err.println("sessionInitCmd: couldn't parse VAR_ERROR = " + var3.value());
                  }
                  break;
               case 5:
                  var1.getGalaxy().setChannel(var3.value());
                  break;
               case 6:
                  var1.getGalaxy().setPassword(var3.value());
                  var1.getGalaxy().setNewPassword(null);
                  break;
               case 7:
               case 9:
               case 11:
               case 12:
               case 14:
               case 16:
               case 17:
               case 18:
               case 19:
               case 20:
               case 21:
               default:
                  System.out.println("sessionInitCmd: received unknown property: " + var3.property());
                  Debug.dAssert(false);
                  break;
               case 10:
                  var1.getGalaxy().setSerialNum(var3.value());
                  break;
               case 22:
                  try {
                     int var4 = Integer.parseInt(var3.value());
                     Enumeration var5 = var1.getGalaxy().getConsoles();

                     while (var5.hasMoreElements()) {
                        Console var6 = (Console)var5.nextElement();
                        var6.setVIP((var4 & 8) != 0);
                        var6.setFullVIP((var4 & 16) != 0);
                        var6.setSpecialGuest((var4 & 64) != 0);
                     }

                     var5 = var1.getGalaxy().getConsoles();

                     while (var5.hasMoreElements()) {
                        Console var11 = (Console)var5.nextElement();
                        var11.enableBroadcast((var4 & 2) != 0);
                     }
                  } catch (NumberFormatException var8) {
                  }
            }
         }

         if (var1.getVersion() < 18) {
            var1.setState(9);
         } else {
            var1.setState(11);
         }
      }
   }

   public String toString(WorldServer var1) {
      return "SESSINIT " + this._propList;
   }
}
