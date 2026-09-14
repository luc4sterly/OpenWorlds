package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.console.PolledDialog;
import NET.worlds.core.Std;
import java.awt.Event;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Label;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.MessageFormat;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.Vector;

public class ProgressDialog extends PolledDialog {
   private static final String bytesMsg = Console.message("Bytes-remaining");
   private int bytesTotal;
   private int bytesLoaded;
   private ProgressBar progressBar;
   private Label progressBytes;
   private Label progressTime;
   private int startTime = Std.getFastTime();
   private CacheFile cf;
   private boolean cancelled;
   private int wholeFileBytes = 0;

   public ProgressDialog(int var1) {
      super(Console.getFrame(), null, Console.message("Download-Progress"), false);
      this.bytesTotal = var1;
      this.progressBar = new ProgressBar(240);
      NumberFormat var2 = NumberFormat.getNumberInstance(Locale.getDefault());
      String var3 = var2.format(var1);
      this.progressBytes = new Label(bytesMsg + var3);
      this.progressTime = new Label("");
      this.setAlignment(1);
      this.readySetGo();
   }

   public boolean loadFiles(Vector var1, Vector var2) throws IOException {
      try {
         int var3 = var1.size();

         for (int var4 = 0; var4 < var3; var4++) {
            synchronized (this) {
               if (this.cancelled) {
                  NetUpdate.warnUser("Upgrade cancelled.");
                  return false;
               }

               if (this.cf != null) {
                  this.wholeFileBytes = this.wholeFileBytes + this.cf.bytesLoaded();
               }

               this.cf = Cache.getFile((URL)var2.elementAt(var4));
            }

            this.cf.waitUntilLoaded();
            if (!this.cf.isActive()) {
               this.cf.markTemporary();
               NetUpdate.warnUser("Upgrade cancelled.");
               return false;
            }

            if (this.cf.error()) {
               this.cf.markTemporary();
               NetUpdate.warnUser("Error getting upgrade info, try again later");
               return false;
            }

            copyFile(this.cf.getLocalName(), (String)var1.elementAt(var4));
            this.cf.markTemporary();
            this.cf.close();
         }

         return true;
      } finally {
         this.done(true);
      }
   }

   public static boolean copyFile(String var0, String var1) {
      int var2 = var1.lastIndexOf(47);
      int var3 = var1.lastIndexOf(92);
      if (var3 > var2) {
         var2 = var3;
      }

      if (var2 >= 0) {
         new File(var1.substring(0, var2)).mkdirs();
      }

      FileInputStream var4 = null;
      FileOutputStream var5 = null;

      try {
         try {
            var4 = new FileInputStream(var0);
            var5 = new FileOutputStream(var1);
            byte[] var6 = new byte[1024];

            while (true) {
               int var7 = var4.read(var6);
               if (var7 == -1) {
                  return true;
               }

               var5.write(var6, 0, var7);
            }
         } finally {
            if (var5 != null) {
               var5.close();
            }

            if (var4 != null) {
               var4.close();
            }
         }
      } catch (IOException var13) {
         return false;
      }
   }

   protected void build() {
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      var2.anchor = 10;
      var2.gridwidth = 0;
      var2.weightx = 1.0;
      var2.weighty = 1.0;
      this.add(var1, new Label(Console.message("Downloading-update")), var2);
      var2.insets = new Insets(2, 2, 2, 2);
      this.add(var1, this.progressBar, var2);
      var2.insets = new Insets(0, 2, 0, 2);
      var2.anchor = 17;
      this.add(var1, this.progressBytes, var2);
      var2.fill = 2;
      this.add(var1, this.progressTime, var2);
   }

   protected synchronized void activeCallback() {
      int var1;
      synchronized (this) {
         var1 = this.wholeFileBytes;
         if (this.cf != null) {
            var1 += this.cf.bytesLoaded();
         }
      }

      if (var1 != this.bytesLoaded) {
         this.bytesLoaded = var1;
         this.progressBar.setProgress((double)this.bytesLoaded / this.bytesTotal);
         int var2 = this.bytesTotal - this.bytesLoaded;
         NumberFormat var3 = NumberFormat.getNumberInstance(Locale.getDefault());
         String var4 = var3.format(var2);
         this.progressBytes.setText(bytesMsg + var4);
         int var5 = (Std.getFastTime() - this.startTime) / 1000;
         if (var5 > 0) {
            double var6 = (double)this.bytesLoaded / var5;
            if (var6 > 0.0) {
               String var8 = formatTime((long)(var2 / var6));
               Object[] var9 = new Object[]{new String(var8)};
               this.progressTime.setText(MessageFormat.format(Console.message("Time-remaining"), var9));
            }
         }
      }

      this.notify();
   }

   protected boolean done(boolean var1) {
      synchronized (this) {
         this.cancelled = true;
         if (this.cf != null) {
            this.cf.close();
         }
      }

      return super.done(var1);
   }

   private static String fmtTwoDigit(long var0) {
      return var0 < 10L ? "0" + var0 : "" + var0;
   }

   private static String formatTime(long var0) {
      String var2 = "";
      long var3 = var0 / 3600L;
      var0 -= var3 * 3600L;
      long var5 = var0 / 60L;
      var0 -= var5 * 60L;
      if (var3 > 0L) {
         var2 = var2 + var3 + ":";
      }

      return var2 + fmtTwoDigit(var5) + ":" + fmtTwoDigit(var0);
   }

   public boolean handleEvent(Event var1) {
      if (var1.id == 1004) {
         Console.getFrame().requestFocus();
         return true;
      } else {
         return super.handleEvent(var1);
      }
   }
}
