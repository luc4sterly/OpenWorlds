package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import NET.worlds.scape.CDAudio;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.WavSoundPlayer;
import java.io.File;
import java.io.IOException;
import java.net.InetAddress;
import java.text.MessageFormat;

public class VoiceChat implements DialogReceiver {
   private static final String SPEAKFREELY = "sfmain.exe";
   private static final int INITIAL_STATE = 0;
   private static final int BEGINNING_CONNECTION = 1;
   private static final int REQUESTING_CONNECTION = 2;
   private static final int ATTEMPTING_CONNECTION = 3;
   private static final int SUCCESSFULLY_CONNECTED = 4;
   private static final int CONNECTION_FAILED_RESETTING = 5;
   private static final int CLOSING_CONNECTION = 6;
   private static final int CONNECTION_CLOSED_RESETTING = 7;
   private static final String[] _stateStrs = new String[]{
      "Initial State",
      "Beginning Connection",
      "Attempting Connection",
      "Successfully Connected",
      "Resetting (Connection Failed)",
      "Closing Connection",
      "Resetting (Connection Closed)"
   };
   private int _state = 0;
   private String _error = "";
   private static boolean _selfWhisper = false;
   public static String VCdebugCommand = "&|+debug>VCcommand=";
   public static String VCdebugCommandReset = "&|+debug>VCcommandReset=";
   private static String _extraCommand = "";
   private static GammaPhoneMonitor chatMonitor = null;
   private String _who = null;
   public static UpdateableDialog voiceChatDialog;
   private static UpdateableDialog voiceChatQueryDialog;
   private static String voiceChatQueryIP;
   private static String voiceChatQueryWho;
   public static boolean voiceChatEnabled = IniFile.gamma().getIniInt("VoiceChat", voiceChatAvailable() ? 1 : 0) != 0;
   private static boolean voiceChatExeChecked = false;
   private static boolean voiceChatExists = false;
   private int _gammaphoneWindow = 0;
   DefaultConsole _console = null;
   VCTimerThread _vtimer = null;
   private static final String voiceChatQuery = "&|+voicechat?";
   private static final String voiceChatAccept = "&|+voicechat>accept";
   private static final String voiceChatReject = "&|+voicechat>reject";
   private static final String voiceChatBusy = "&|+voicechat>busy";
   private static final String voiceChatNotVIP = "&|+voicechat>notvip";
   private static final String voiceChatDisabled = "&|+voicechat>disabled";

   public int getState() {
      return this._state;
   }

   public String getStateString() {
      return _stateStrs[this._state];
   }

   public String getLastError() {
      return this._error;
   }

   public static void activateSelfWhisper() {
      _selfWhisper = true;
      Console.println(Console.message("Selfwhisper-on"));
   }

   public static void deactivateSelfWhisper() {
      _selfWhisper = false;
      Console.println(Console.message("Selfwhisper-off"));
   }

   public static void setExtra(String var0) {
      int var1 = var0.indexOf(34) + 1;
      int var2 = var0.lastIndexOf(34);
      _extraCommand = var0.substring(var1, var2);
      Object[] var3 = new Object[]{new String(_extraCommand)};
      Console.println(MessageFormat.format(Console.message("Add-VoiceChat"), var3));
   }

   public static void resetExtra() {
      _extraCommand = "";
      Console.println(Console.message("VoiceChat-reset"));
   }

   public String who() {
      return this._who;
   }

   public static void setVoiceChatEnabled(boolean var0) {
      if (!voiceChatAvailable()) {
         var0 = false;
      }

      voiceChatEnabled = var0;
      IniFile.gamma().setIniInt("VoiceChat", var0 ? 1 : 0);
   }

   public static boolean voiceChatAvailable() {
      if (voiceChatExeChecked) {
         return voiceChatExists;
      }

      URL var0 = URL.make("home:sfmain.exe");
      String var1 = var0.unalias();
      File var2 = new File(var1);
      voiceChatExists = var2.exists();
      voiceChatExeChecked = true;
      return voiceChatExists;
   }

   public void registerProcess(int var1) {
      this._gammaphoneWindow = var1;
   }

   public void beginChat(String var1, DefaultConsole var2) {
      this._state = 1;
      this._console = var2;
      if (!var2.getVIP()) {
         this.resetConnection(Console.message("must-be-VIP"));
      } else {
         String var3 = null;

         try {
            InetAddress var4 = var2.getServerNew().getLocalAddress();
            var3 = var4 != null ? var4.toString() : null;
            var3 = var3.substring(var3.indexOf(47) + 1);
         } catch (SecurityException var7) {
            this.resetConnection(Console.message("sec-violation"));
         }

         if (var3 == null) {
            this.resetConnection(Console.message("cant-determine-IP"));
         } else {
            if (voiceChatDialog != null) {
               if (var1.equals(this._who)) {
                  Object[] var11 = new Object[]{new String(this._who)};
                  Console.println(MessageFormat.format(Console.message("already-VoiceChat"), var11));
                  return;
               }

               this.resetConnection(Console.message("chat-ended"));
            }

            if (voiceChatQueryDialog != null && voiceChatQueryWho.equals(var1)) {
               Object[] var10 = new Object[]{new String(var1)};
               Console.println(MessageFormat.format(Console.message("already-calling"), var10));
               return;
            }

            while (ConnectionRecord.checkList(this._who)) {
               Object[] var8 = new Object[]{new String(this._who)};
               Console.println(MessageFormat.format(Console.message("wait-a-few"), var8));

               try {
                  Thread.currentThread();
                  Thread.sleep(2000L);
               } catch (InterruptedException var6) {
               }
            }

            if (this.initiateVoiceChat(var1, null)) {
               Object[] var9 = new Object[]{new String(var1), new String(var3)};
               Console.println(MessageFormat.format(Console.message("Asking-to-call"), var9));
               this._state = 2;
               this.sendWhisper(var1, "&|+voicechat?" + var3);
               this._vtimer = new VCTimerThread(this, 30000L);
               this._vtimer.start();
            }
         }
      }
   }

   private static native void terminateVC(int var0);

   private boolean initiateVoiceChat(String var1, String var2) {
      this._who = var1;
      int var3 = Window.getHWnd();
      String var4 = URL.make(
            "home:sfmain.exe" + (var2 == null ? " -a " : " -c " + var2) + " -g " + var3 + " -p " + Window.getGammaProcessID() + " " + _extraCommand + " "
         )
         .unalias();
      WavSoundPlayer.pauseSystem();
      CDAudio.get().setEnabled(false);
      if (tryToRun(var4)) {
         Object[] var6 = new Object[]{new String(this._who)};
         voiceChatDialog = new UpdateableDialog(
            Console.getFrame(),
            this,
            Console.message("Voice-connect"),
            null,
            Console.message("Terminate"),
            MessageFormat.format(Console.message("end-VoiceChat"), var6),
            false
         );
         if (chatMonitor == null) {
            chatMonitor = new GammaPhoneMonitor(this);
            chatMonitor.start();
         }

         return true;
      } else {
         WavSoundPlayer.resumeSystem();
         CDAudio.get().setEnabled(true);
         Object[] var5 = new Object[]{new String(this._who), new String(var4)};
         voiceChatDialog = new UpdateableDialog(
            Console.getFrame(),
            this,
            Console.message("Voice-Chat-199"),
            null,
            Console.message("Continue"),
            MessageFormat.format(Console.message("Unable-to-chat"), var5),
            false
         );
         return false;
      }
   }

   public void inform(int var1, String var2) {
      if (var1 >= 900) {
         if (voiceChatDialog == null) {
            return;
         }

         voiceChatDialog.setTitle(Console.message("VoiceChat-Connected"));
         this._state = 4;
      } else {
         this.resetConnection(var2);
      }
   }

   public boolean handleChatRequest(String var1, String var2, DefaultConsole var3) {
      Object[] var4 = new Object[]{new String(var1)};
      if (!var3.getVIP()) {
         Console.println(MessageFormat.format(Console.message("reject-chat"), var4));
         this.sendWhisper(var1, "&|+voicechat>notvip");
      } else if (!voiceChatEnabled) {
         Console.println(MessageFormat.format(Console.message("chat-disabled"), var4));
         this.sendWhisper(var1, "&|+voicechat>disabled");
      } else if (voiceChatQueryDialog != null) {
         this.sendWhisper(var1, "&|+voicechat>busy");
      } else {
         voiceChatQueryIP = var2.substring("&|+voicechat?".length());
         voiceChatQueryWho = var1;
         voiceChatQueryDialog = new UpdateableDialog(
            Console.getFrame(),
            this,
            Console.message("Accept-voice"),
            Console.message("Reject"),
            Console.message("Accept"),
            MessageFormat.format(Console.message("do-you-voice"), var4),
            false
         );
      }

      return true;
   }

   public boolean handleChatWhisper(String var1, String var2, DefaultConsole var3) {
      Object[] var4 = new Object[]{new String(var1)};
      if (var2.startsWith("&|+voicechat?")) {
         this.handleChatRequest(var1, var2, var3);
         return true;
      }

      if (var2.startsWith("&|+voicechat>accept")) {
         if (this._state != 2) {
            this.sendWhisper(var1, "&|+voicechat>reject");
            return false;
         }

         Console.println(MessageFormat.format(Console.message("chat-accepted"), var4));
         synchronized (this._vtimer) {
            this._vtimer._vc = null;
         }

         this._vtimer = null;
         this._state = 3;
         this._vtimer = new VCTimerThread(this, 15000L);
         this._vtimer.start();
      } else if (var2.startsWith("&|+voicechat>notvip")) {
         if (voiceChatDialog != null && this._who.equals(var1)) {
            this.resetConnection(MessageFormat.format(Console.message("cannot-voice"), var4));
         }
      } else if (var2.startsWith("&|+voicechat>disabled")) {
         if (voiceChatDialog != null && this._who.equals(var1)) {
            this.resetConnection(MessageFormat.format(Console.message("user-voice-dis"), var4));
         }
      } else if (var2.startsWith("&|+voicechat>busy")) {
         if (voiceChatDialog != null && this._who.equals(var1)) {
            this.resetConnection(MessageFormat.format(Console.message("receiving-Voice"), var4));
         }
      } else if (var2.startsWith("&|+voicechat>reject")) {
         if (voiceChatDialog != null && this._who.equals(var1)) {
            this.resetConnection(MessageFormat.format(Console.message("Voice-terminated"), var4));
         }

         if (voiceChatQueryDialog != null && voiceChatQueryWho != null && voiceChatQueryWho.equals(var1)) {
            voiceChatQueryDialog.closeIt(false);
            voiceChatQueryWho = null;
            this.resetConnection(MessageFormat.format(Console.message("Voice-terminated"), var4));
         }
      }

      return false;
   }

   public static boolean tryToRun(String var0) {
      try {
         Runtime.getRuntime().exec(var0);
         return true;
      } catch (IOException var2) {
         return false;
      }
   }

   public void checkConnected() {
      if (this.getState() == 2) {
         this.resetConnection(Console.message("never-answered"));
         this.sendWhisper(this.who(), "&|+voicechat>reject");
      } else {
         if (this.getState() != 4) {
            this.resetConnection(Console.message("VoiceChat-failed"));
         }
      }
   }

   public void resetConnection(String var1) {
      this._error = var1;
      if (var1 != null) {
         this._state = 5;
         Console.println(this._error);
      }

      if (voiceChatDialog != null) {
         voiceChatDialog.closeIt(true);
      }
   }

   public void terminate() {
      if (this._vtimer != null) {
         synchronized (this._vtimer) {
            this._vtimer._vc = null;
         }

         this._vtimer = null;
      }

      CDAudio.get().setEnabled(true);
      ConnectionRecord.getList().addElement(new ConnectionRecord(this.who()));
      this._state = 0;
   }

   public void release() {
      if (chatMonitor != null) {
         chatMonitor.stop();
         chatMonitor = null;
      }
   }

   public synchronized void dialogDone(Object var1, boolean var2) {
      if (var1 == voiceChatQueryDialog) {
         voiceChatQueryDialog = null;
         if (var2) {
            this.sendWhisper(voiceChatQueryWho, "&|+voicechat>accept");
            this.initiateVoiceChat(voiceChatQueryWho, voiceChatQueryIP);
         } else if (voiceChatQueryWho != null) {
            this.sendWhisper(voiceChatQueryWho, "&|+voicechat>reject");
         }
      } else if (var1 == voiceChatDialog) {
         this._state = 6;
         String var3 = URL.make("home:sfmain.exe -q").unalias();
         tryToRun(var3);
         voiceChatDialog = null;
         this.sendWhisper(this._who, "&|+voicechat>reject");
         this.terminate();
      } else {
         String var4 = URL.make("home:sfmain.exe -q").unalias();
         tryToRun(var4);
      }
   }

   private void sendWhisper(String var1, String var2) {
      Pilot.sendText(var1, var2);
      if (_selfWhisper) {
         this.handleChatWhisper(var1, var2, this._console);
      }
   }
}
