package NET.worlds.console;

import NET.worlds.scape.WavSoundPlayer;

public class GammaPhoneMonitor extends Thread {
   public static final int GA_FAILEDCONNECT = 100;
   public static final int GPE_WHATEVER = 0;
   public static final int GPE_OUT_OF_MEM = 1;
   public static final int GPE_WEIRD = 2;
   public static final int GPE_SOCKET = 3;
   public static final int GPE_COMM = 4;
   public static final int GPE_HOST = 5;
   public static final int GPE_FILE = 6;
   public static final int GPE_CRYPTO = 7;
   public static final int GPE_MULTICAST = 8;
   public static final int GPE_RECORD = 9;
   public static final int GPE_WAVE_INPUT = 10;
   public static final int GPE_PLAY = 11;
   public static final int GPE_WAVE_OUTPUT = 12;
   public static final int GPE_PORT = 13;
   public static final int GPE_SOCKETS_VERSION = 14;
   public static final int GPE_HALF_DUPLEX = 15;
   public static final int GPE_USAGE = 16;
   public static final int GPE_IS_HALF_DUPLEX = 17;
   public static final int GPE_IS_FULL_DUPLEX = 18;
   public static final int GPE_LWL = 19;
   public static final int GPE_TIMEOUT = 20;
   public static final int GPE_WAVE_IN_USE = 21;
   public static final int GPE_CONNECTION_LOST = 22;
   public static final int GPE_SUCCESS = 900;
   public static final int GPE_STARTUP = 901;
   public static final int GPE_SHUTDOWN = 902;
   private VoiceChat _vc = null;

   public GammaPhoneMonitor(VoiceChat var1) {
      this._vc = var1;
   }

   private void release() {
      this._vc.release();
   }

   public void run() {
      boolean var1 = false;
      Window var2 = Window.getMainWindow();

      try {
         while (true) {
            if (Window.getVoiceChatWParam() != 0) {
               this.processMessage(Window.getVoiceChatWParam(), Window.getVoiceChatLParam());
               Window.resetVoiceChatMsg();
            }

            sleep(1000L);
         }
      } catch (InterruptedException var4) {
         this.stop();
      }
   }

   private void processMessage(int var1, int var2) {
      switch (var1) {
         case 0:
            this._vc.inform(var1, "whatever ");
            break;
         case 1:
            this._vc.inform(var1, "out of memory ");
            break;
         case 2:
            this._vc.inform(var1, "! ");
            break;
         case 3:
            this._vc.inform(var1, "An error occurred while setting up the socket for Voice Chat.");
            break;
         case 4:
            this._vc.inform(var1, "communications ");
            break;
         case 5:
            this._vc.inform(var1, "can't find host ");
            break;
         case 6:
            this._vc.inform(var1, "can't open/read/write file ");
            break;
         case 7:
            this._vc.inform(var1, "we don't even use this! ");
            break;
         case 8:
            this._vc.inform(var1, "we don't even use this! ");
            break;
         case 9:
            this._vc.inform(var1, "can't record at 8000 or 11200 samp/sec");
            break;
         case 10:
            this._vc.inform(var1, "error opening wave input device ");
            break;
         case 11:
            this._vc.inform(var1, "sound card can't play at 8000 or 11200");
            break;
         case 12:
            this._vc.inform(var1, "error opening wave output device ");
            break;
         case 13:
            this._vc.inform(var1, "invalid port number specified ");
            break;
         case 14:
            this._vc.inform(var1, "incompatible (old) sockets library ");
            break;
         case 15:
            this._vc.inform(var1, "sound drivers can't support full duplex");
            break;
         case 16:
            this._vc.inform(var1, "command line syntax error ");
            break;
         case 17:
            this._vc.inform(var1, "response to isFullDuplex command ");
            break;
         case 18:
            this._vc.inform(var1, "response to isFullDuplex command ");
            break;
         case 19:
            this._vc.inform(var1, " -Look Who's Listening- error, weird! ");
            break;
         case 20:
            this._vc.inform(var1, "Never heard back. ");
            break;
         case 21:
            this._vc.inform(var1, "VoiceChat failed because a  wav device is in use.");
            break;
         case 22:
            this._vc.inform(var1, "VoiceChat has lost its connection.");
            break;
         case 100:
            Console.println(Console.message("Voice-failed"));
            break;
         case 900:
            this._vc.inform(var1, "It worked o.k. ");
            break;
         case 901:
            this._vc.registerProcess(var2);
            break;
         case 902:
            WavSoundPlayer.resumeSystem();
            break;
         default:
            Console.println(Console.message("Unrec-message") + var1);
      }
   }
}
