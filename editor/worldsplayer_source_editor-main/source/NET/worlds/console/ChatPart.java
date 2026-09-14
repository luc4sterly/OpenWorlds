package NET.worlds.console;

import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.Pilot;
import java.awt.Container;

public class ChatPart extends DuplexPart {
   private Window renderWindow;
   private DefaultConsole console;
   private static final String activateVCselfWhisper = "&|+debug<selfWhisperON";
   private static final String deactivateVCselfWhisper = "&|+debug<selfWhisperOFF";
   private static final String VCextraCommand = "&|+debug<VCcommand";

   protected void sendText(String var1) {
      int var2 = var1.indexOf(92);
      if (var1.startsWith("&|+debug<")) {
         this.triggerLocalDebug(var1);
      } else if (var2 >= 0 && var2 < var1.length() - 1 && var1.charAt(var2 + 1) == 'u') {
         Pilot.sendText(Console.parseUnicode(var1));
      } else {
         Pilot.sendText(var1);
      }
   }

   public void activate(Console var1, Container var2, Console var3) {
      super.activate(var1, var2, var3);
      this.console = (DefaultConsole)var1;
   }

   public void deactivate() {
      super.deactivate();
      this.renderWindow = null;
      this.console = null;
   }

   public synchronized boolean handle(FrameEvent var1) {
      boolean var2 = super.handle(var1);
      if (this.renderWindow == null && this.console != null) {
         RenderCanvas var3 = this.console.getRender();
         if (var3 != null) {
            Window var4 = var3.getWindow();
            if (var4 != null) {
               try {
                  var4.hookChatLine(this.line);
                  this.renderWindow = var4;
               } catch (WindowNotFoundException var6) {
               }
            }
         }
      }

      return var2;
   }

   private void triggerLocalDebug(String var1) {
      if (var1.startsWith("&|+debug<selfWhisperON")) {
         VoiceChat.activateSelfWhisper();
      }

      if (var1.startsWith("&|+debug<selfWhisperOFF")) {
         VoiceChat.deactivateSelfWhisper();
      }

      if (var1.startsWith("&|+debug<VCcommand")) {
         VoiceChat.setExtra(var1);
      }
   }
}
