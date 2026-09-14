package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.console.FriendsListPart;
import NET.worlds.console.MuteListPart;
import NET.worlds.scape.WorldScriptManager;
import java.text.MessageFormat;

public class whisperCmd extends textCmd {
   public static final byte WHISPERCMD = 17;
   private static String rejectMsg = Console.message("not-whispers");

   public whisperCmd() {
      this._commandType = 17;
   }

   public whisperCmd(String var1, String var2) {
      super(var2);
      WorldScriptManager.getInstance().onConversation(var1, var2);
      this._commandType = 17;
      this._objID = new ObjID(var1);
   }

   void process(WorldServer var1) throws Exception {
      String var2;
      if (this._senderID.longID() == null) {
         Object[] var3 = new Object[]{new String(String.valueOf(this._senderID.shortID()))};
         var2 = MessageFormat.format(Console.message("Unknown-Name"), var3);
      } else {
         var2 = this._senderID.longID();
         if (MuteListPart.isMuted(var1, var2)) {
            try {
               var1.sendNetworkMsg(new whisperCmd(var2, Console.message("have-you-muted")));
            } catch (InfiniteWaitException var4) {
            } catch (PacketTooLargeException var5) {
            }

            return;
         }

         if (!this._text.startsWith("&|+") && MuteListPart.isRejecting(var1)) {
            try {
               if (!this._text.equals(rejectMsg)) {
                  Object[] var8 = new Object[]{new String(var2)};
                  Console.println(MessageFormat.format(Console.message("You-rejected"), var8));
                  var1.sendNetworkMsg(new whisperCmd(var2, rejectMsg));
               }
            } catch (InfiniteWaitException var6) {
            } catch (PacketTooLargeException var7) {
            }

            return;
         }
      }

      FriendsListPart.processWhisper(var1, var2, this._text);
      handleActionText(var1, this._text, var2, this._senderID);
      Console.printWhisper(var2, FilthFilter.get().filter(this._text));
   }

   public String toString(WorldServer var1) {
      return Console.message("WHISPER") + " " + this._senderID.toString(var1) + " --> " + this._objID.toString(var1) + ": " + this._text;
   }
}
