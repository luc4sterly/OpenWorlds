package NET.worlds.console;

import java.awt.Font;

class MailDialogReceiver implements DialogReceiver {
   Console console;
   private static Font font = new Font(Console.message("ConsoleFont"), 0, 12);

   public MailDialogReceiver(Console var1) {
      this.console = var1;
   }

   public void dialogDone(Object var1, boolean var2) {
      MailDialog var3 = (MailDialog)var1;
      var3.setFont(font);
      if (var2) {
         String[] var4 = var3.getTo();
         if (var4.length > 0) {
            MailMessage var5 = new MailMessage(
               this.console.getSmtpServer(), this.console.getLongID() + "@" + this.console.getMailDomain(), var4[0], var3.getSubject(), null
            );

            for (int var6 = 1; var6 < var4.length; var6++) {
               var5.addCC(var4[var6]);
            }

            var5.appendParagraphs(var3.getBody());
            var5.send();
         } else {
            Console.println(Console.message("No-recipient"));
         }
      }
   }
}
