package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.core.SystemInfo;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.text.DateFormat;
import java.util.Date;

public class LogFile {
   private static PrintStream out = null;
   private static String baseName = null;
   private static final String tempSuffix = ".open";
   private static final String mailSuffix = ".mail";
   private static final String noCloseTag = ", it terminated unexpectedly.\nPlease fill in the box below with an explanation of which\nfeatures you were exercising at the time, then click the\nReport button to automatically email the report to Worlds.\n";
   private static final String errorFoundTag = ", it generated a debugging log.\nPlease fill in the box below with an explanation of anything\nunusual that occurred (if anything), then click the Report\nbutton to automatically email the report to Worlds.\n";
   private static final String includeEmail = "Also, please include your email address.\n";
   private static String mailReason = "error encountered";
   private static String mailTag = ", it generated a debugging log.\nPlease fill in the box below with an explanation of anything\nunusual that occurred (if anything), then click the Report\nbutton to automatically email the report to Worlds.\n";
   private static final String iniFile = "worlds.ini";

   public static void open() {
      baseName = IniFile.gamma().getIniString("logfile", "");
      if (baseName.length() != 0) {
         baseName = Gamma.earlyURLUnalias("home:" + baseName);
         File var0 = new File(baseName + ".open");
         if (var0.isFile()) {
            if (scanFileForException(var0)) {
               mailReason = "logfile not closed--probable crash";
               mailTag = ", it terminated unexpectedly.\nPlease fill in the box below with an explanation of which\nfeatures you were exercising at the time, then click the\nReport button to automatically email the report to Worlds.\n";
               File var1 = new File(baseName + ".mail");
               var0.renameTo(var1);
               Object var10 = null;
            } else {
               var0.delete();
            }
         }

         var0 = new File(baseName);
         if (var0.isFile()) {
            var0.delete();
         }

         Object var9 = null;
         OutputStream var11 = null;

         try {
            var11 = new FileOutputStream(baseName + ".open");
         } catch (IOException var6) {
            System.out.println("Error opening logfile \"" + baseName + "\"");
            return;
         }

         out = new PrintStream(new BufferedOutputStream(var11), true);
         System.setOut(out);
         System.setErr(out);
         out.println("Logfile of " + DateFormat.getDateTimeInstance().format(new Date()));
         out.println(
            "Gamma " + Std.getVersion() + ", build " + Std.getBuildInfo() + " of " + DateFormat.getDateTimeInstance().format(new Date(Std.getBuildDate()))
         );
         out.println("system info---------------------------------");
         SystemInfo.Record(out);
         out.println("worlds.ini----------------------------------");

         try {
            String var2 = System.getProperty("file.encoding");
            FileInputStream var3 = new FileInputStream("worlds.ini");
            BufferedReader var4 = new BufferedReader(new InputStreamReader(var3, var2));

            for (String var5 = var4.readLine(); var5 != null; var5 = var4.readLine()) {
               out.println(var5);
            }

            var4.close();
         } catch (IOException var7) {
         }

         out.println("--------------------------------------------");
      }
   }

   public static void close() {
      if (out != null) {
         out.println("Logfile closed.");
         out.close();
      }

      File var0 = new File(baseName + ".open");
      if (scanFileForException(var0)) {
         File var1 = new File(baseName + ".mail");
         var0.renameTo(var1);
         Object var3 = null;
      } else {
         File var4 = new File(baseName);
         if (var0.isFile()) {
            var0.renameTo(var4);
         }

         Object var5 = null;
      }

      Object var2 = null;
   }

   public static void mailLogIfPresent(String var0) {
      LogFile$1 var1 = new LogFile$1(var0);
      File var2 = new File(baseName + ".mail");
      if (var2.isFile()) {
         String var3 = "The last time you ran " + Std.getProductName() + mailTag;
         if (IniFile.gamma().getIniString("LASTCHATNAME", "").length() == 0) {
            new LogMailDialog(var1, var3 + "Also, please include your email address.\n");
         } else {
            new LogMailDialog(var1, var3);
         }
      }
   }

   static String access$000() {
      return baseName;
   }

   static String access$100() {
      return mailReason;
   }

   static void access$200(String var0, File var1, String var2, String var3) {
      sendCrashMail(var0, var1, var2, var3);
   }

   private static void sendCrashMail(String var0, File var1, String var2, String var3) {
      LogFileMailMessage var4 = new LogFileMailMessage(var0, var1);

      try {
         if (var2 != null) {
            var4.appendBody(" (" + var2 + ")");
         }

         var4.appendBody(".\n\n");
         if (var3 != null) {
            var4.appendBody("The user reports:\n");
            var4.appendParagraphs(var3);
            var4.appendBody("\n\n");
         }

         var4.appendBody("The log file reads:\n\n");
         String var5 = System.getProperty("file.encoding");
         FileInputStream var6 = new FileInputStream(var1);
         BufferedReader var7 = new BufferedReader(new InputStreamReader(var6, var5));
         long var8 = var1.length();
         if (var8 <= 23000L) {
            for (String var15 = var7.readLine(); var15 != null; var15 = var7.readLine()) {
               var4.appendBody(var15 + "\n");
            }
         } else {
            int var10 = 0;
            long var11 = 0L;

            for (String var13 = var7.readLine(); var13 != null && var10 < 128; var13 = var7.readLine()) {
               var4.appendBody(var13 + "\n");
               var10++;
               var11 += var13.length();
            }

            var4.appendBody("-------------------------------------...\n");
            var4.appendBody("   Log file too long; skipping center\n");
            var4.appendBody("...-------------------------------------\n");
            var7.skip(var8 - (var11 + 9030L));
            var7.readLine();

            for (String var16 = var7.readLine(); var16 != null; var16 = var7.readLine()) {
               var4.appendBody(var16 + "\n");
            }
         }

         var7.close();
      } catch (IOException var14) {
         System.out.println("Error writing logfile to mail note: " + var14);
      }

      var4.send();
   }

   private static boolean scanFileForException(File var0) {
      try {
         String var1 = System.getProperty("file.encoding");
         FileInputStream var2 = new FileInputStream(var0);
         BufferedReader var3 = new BufferedReader(new InputStreamReader(var2, var1));

         for (String var4 = var3.readLine(); var4 != null; var4 = var3.readLine()) {
            if (var4.indexOf("\tat NET.worlds") != -1 || var4.indexOf("\tat java.lang") != -1 || var4.indexOf("\tat sun.awt") != -1) {
               var3.close();
               return true;
            }
         }

         var3.close();
      } catch (IOException var5) {
      }

      return false;
   }
}
