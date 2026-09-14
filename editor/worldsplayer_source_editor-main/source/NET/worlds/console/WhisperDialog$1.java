package NET.worlds.console;

import NET.worlds.scape.Pilot;

class WhisperDialog$1 implements MainCallback {
   String val$msg;

   WhisperDialog$1(String var1) {
      this.val$msg = var1;
   }

   public void mainCallback() {
      System.out.println("Sending a Text Message: " + this.val$msg);
      Pilot.sendText(this.val$msg);
      Main.unregister(this);
   }
}
