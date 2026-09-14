package NET.worlds.console;

import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.URL;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.Label;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Vector;

class PersonalInfoDownload extends OkCancelDialog implements Runnable {
   private static int seqNumber;
   private String name;
   private CacheFile cf;
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);

   public PersonalInfoDownload(String var1, Console var2) {
      super(Console.getFrame(), null, Console.message("Downloading2"), Console.message("Cancel"), null, false);
      this.name = var1;
      String var3 = var2.getScriptServer() + "profile" + Console.message(".pl") + "?" + var1;
      this.cf = Cache.getFile(URL.make(var3));
      if (Console.wasHttpNoSuchFile(var3)) {
         this.cf = Cache.getFile(URL.make(var2.getScriptServer() + "profile.pl?" + var1));
      }

      this.setFont(new Font(Console.message("FriendsFont"), 0, 12));
      Thread var4 = new Thread(this);
      var4.setDaemon(true);
      var4.start();
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      var1.weightx = 1.0;
      var1.weighty = 1.0;
      var1.gridwidth = 0;
      Object[] var2 = new Object[]{new String(this.name)};
      Label var3 = new Label(MessageFormat.format(Console.message("Downloading"), var2));
      var3.setFont(font);
      this.add(this.gbag, var3, var1);
      Label var4 = new Label(Console.message("Please-wait"));
      var4.setFont(font);
      this.add(this.gbag, var4, var1);
      super.build();
   }

   public void run() {
      this.readySetGo();
      this.cf.waitUntilLoaded();
      if (this.cf.isActive()) {
         this.done(true);
         if (this.cf.error()) {
            Object[] var1 = new Object[]{new String(this.name)};
            new OkCancelDialog(
               Console.getFrame(),
               null,
               Console.message("Error"),
               null,
               Console.message("OK"),
               MessageFormat.format(Console.message("Error-down"), var1),
               false
            );
            System.out.println("Error downloading personal info for " + this.name);
         } else {
            Vector var18 = new Vector();
            DataInputStream var2 = null;

            try {
               var2 = new DataInputStream(new FileInputStream(this.cf.getLocalName()));

               String var3;
               while ((var3 = var2.readLine()) != null) {
                  var18.addElement(var3);
               }

               new PersonalInfoDialog(this.name, var18);
            } catch (FileNotFoundException var15) {
            } catch (IOException var16) {
            } finally {
               try {
                  if (var2 != null) {
                     var2.close();
                  }
               } catch (IOException var14) {
               }
            }
         }

         this.cf.close();
      }
   }
}
