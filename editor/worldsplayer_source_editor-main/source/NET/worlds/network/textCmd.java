package NET.worlds.network;

import NET.worlds.console.BBChatCommand;
import NET.worlds.console.BlackBox;
import NET.worlds.console.Console;
import NET.worlds.console.GammaTextArea;
import NET.worlds.console.MuteListPart;
import NET.worlds.core.IniFile;
import NET.worlds.scape.Drone;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.PosableDrone;
import java.io.IOException;

public class textCmd extends receivedNetPacket {
   public static final byte TEXTCMD = 14;
   protected ObjID _senderID;
   protected String _text;

   public textCmd() {
      this._commandType = 14;
   }

   public textCmd(String var1) {
      super(null, 14);
      this._senderID = new ObjID("");
      this._text = var1;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._senderID = new ObjID();
      this._senderID.parseNetData(var1);
      this._text = var1.readUTF();
   }

   int packetSize() {
      return ServerOutputStream.utfLength(this._text) + 1 + this._senderID.packetSize() + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      this._senderID.send(var1);
      var1.writeUTF(this._text);
   }

   void process(WorldServer var1) throws Exception {
      String var2;
      if (this._senderID.longID() == null) {
         var2 = "[Unknown Name (#" + String.valueOf(this._senderID.shortID()) + ")]";
      } else {
         var2 = this._senderID.longID();
         if (MuteListPart.isMuted(var1, var2)) {
            return;
         }
      }

      handleActionText(var1, this._text, var2, this._senderID);
      if (!this._text.startsWith("&|+")) {
         this.displayText(var2, this._text);
      }
   }

   protected void displayText(String var1, String var2) {
      String var3 = FilthFilter.get().filterName(var1);
      String var4 = "";
      if (IniFile.gamma().getIniInt("classicChatBox", 1) == 1) {
         var4 = var3 + "> ";
         var4 = var4 + FilthFilter.get().filter(var2);
         BlackBox.getInstance().submitEvent(new BBChatCommand(var4));
         Console.println(var4);
      } else {
         boolean var5 = false;
         if (Drone.isEmployeeAccount(var1)) {
            var4 = GammaTextArea.colorStartBlueTag + " ";
            var5 = true;
         } else if (var1.toLowerCase().startsWith(Console.message("host"))) {
            var4 = GammaTextArea.colorStartRedTag + " ";
            var5 = true;
         } else if (var1.toLowerCase().startsWith(Console.message("guest-"))) {
            var4 = GammaTextArea.colorStartMagentaTag + " ";
            var5 = true;
         }

         var4 = var4 + "<b> " + var3 + "> </b>  ";
         if (var5) {
            var4 = var4 + " " + GammaTextArea.colorEndTag + " ";
         }

         var4 = var4 + FilthFilter.get().filter(var2);
         BlackBox.getInstance().submitEvent(new BBChatCommand(var4));
         Console.println(var4);
      }
   }

   public static void handleActionText(WorldServer var0, String var1, String var2, ObjID var3) {
      if (var1.startsWith("&|+action>")) {
         NetworkObject var4 = var0.getObject(var3);
         if (var4 == null) {
            return;
         }

         String var5 = var1.substring(10);
         if (!(var4 instanceof PosableDrone)) {
            return;
         }

         ((PosableDrone)var4).animate(var5);
      }

      if (var1.startsWith("&|+action2>")) {
         int var9 = var1.indexOf("|sender|");
         String var10 = null;
         String var6 = null;
         if (var9 != -1) {
            var10 = var1.substring(var9);
            var6 = var1.substring(11, var9);
            NetworkObject var7 = var0.getObject(var3);
            if (var7 != null && var7 instanceof PosableDrone) {
               ((PosableDrone)var7).animate(var10);
               Pilot.sendText("&|+action>" + var10);
            }
         } else {
            var6 = var1.substring(11);
         }

         try {
            Console.getActive().getPilot().animate(var6);
         } catch (Exception var8) {
            System.out.println("Error animating pilot " + var8.toString());
         }
      }
   }

   public String toString(WorldServer var1) {
      return "TEXT     " + this._senderID.toString(var1) + ": " + this._text;
   }
}
