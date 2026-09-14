package NET.worlds.console;

import NET.worlds.scape.Pilot;

public class WhisperPart extends DuplexPart {
   private String partner;

   public WhisperPart(String var1) {
      super(false, 4);
      this.partner = var1;
   }

   public String getPartner() {
      return this.partner;
   }

   protected void sendText(String var1) {
      Pilot.sendText(this.partner, Console.parseUnicode(var1));
   }
}
