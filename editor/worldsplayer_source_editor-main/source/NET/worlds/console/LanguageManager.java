package NET.worlds.console;

import NET.worlds.core.Std;
import NET.worlds.network.ProgressDialog;
import NET.worlds.network.URL;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.Vector;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

public class LanguageManager implements Runnable {
   private String m_Name;
   private String m_FinishName;
   private int m_fSize;

   public static void handle(String var0, int var1, String var2) {
      LanguageManager var3 = new LanguageManager(var0, var1, var2);
      Thread var4 = new Thread(var3);
      var4.setDaemon(true);
      var4.start();
   }

   public LanguageManager(String var1, int var2, String var3) {
      this.m_Name = var1;
      this.m_fSize = var2;
      this.m_FinishName = var3;
   }

   public void run() {
      String var1 = this.m_Name.substring(this.m_Name.lastIndexOf(47) + 1, this.m_Name.length());
      Console.println(Console.message("Downloading-update") + var1);
      Vector var2 = new Vector();
      var2.addElement(var1);
      Vector var3 = new Vector();
      var3.addElement(URL.make(this.m_Name));
      int var4 = Std.getFastTime();
      ProgressDialog var5 = new ProgressDialog(this.m_fSize);

      try {
         System.out.println("ProgressDialog start, now = " + var4);
         System.out.println("fName = " + var1 + ", name = " + this.m_Name);
         if (!var5.loadFiles(var2, var3)) {
            System.out.println("Can't load " + var1);
            return;
         }

         var4 = Std.getFastTime();
         System.out.println("ProgressDialog end, now = " + var4);
      } catch (IOException var7) {
         System.out.println("Exception " + var7.toString() + " loading file " + var1);
      }

      this.finishDownload(this.m_FinishName);
   }

   public synchronized boolean finishDownload(String var1) {
      String var2 = var1.substring(var1.lastIndexOf(46), var1.length());
      System.out.println("Finished Downloading " + var1);
      if (var2.equals(".EXE")) {
         if (tryToRun(var1)) {
            System.out.println(Console.message("Loading2") + var1);
         } else {
            Console.println(Console.message("Loading2") + var1 + " " + Console.message("failed"));
         }
      } else if (var2.equals(".zip")) {
         ZipFile var3;
         try {
            var3 = new ZipFile(var1);
         } catch (IOException var12) {
            System.out.println("Error opening language file " + var1);
            this.notify();
            return false;
         }

         System.out.println("Expanding language file.");
         Enumeration var4 = var3.entries();

         while (var4.hasMoreElements()) {
            ZipEntry var5 = (ZipEntry)var4.nextElement();
            String var6 = var5.getName();
            String var7 = var6;
            String[] var8 = new String[]{".properties", ".jpg", ".bmp", ".gif"};
            boolean var9 = false;

            for (int var10 = 0; var10 < var8.length; var10++) {
               if (var7.toString().endsWith(var8[var10])) {
                  var9 = true;
                  break;
               }
            }

            if (var9) {
               this.CopyLangFile(var3, var5, var7);
               System.out.println(var7);
               boolean var13 = false;
            }
         }

         try {
            var3.close();
         } catch (IOException var11) {
         }
      }

      this.notify();
      new OkCancelDialog(Console.getFrame(), null, Console.message("Alert"), null, Console.message("OK"), Console.message("Change-exit"), true);
      return false;
   }

   private void CopyLangFile(ZipFile var1, ZipEntry var2, String var3) {
      InputStream var4;
      try {
         var4 = var1.getInputStream(var2);
      } catch (IOException var11) {
         return;
      }

      FileOutputStream var5;
      try {
         var5 = new FileOutputStream(var3);
      } catch (IOException var10) {
         try {
            var4.close();
         } catch (IOException var8) {
         }

         return;
      }

      byte[] var6 = new byte[1024];

      while (true) {
         try {
            int var7 = var4.read(var6);
            if (var7 == -1) {
               break;
            }

            var5.write(var6, 0, var7);
         } catch (IOException var12) {
            break;
         }
      }

      try {
         var4.close();
         var5.close();
      } catch (IOException var9) {
      }
   }

   public static boolean tryToRun(String var0) {
      try {
         Runtime.getRuntime().exec(var0);
         return true;
      } catch (IOException var2) {
         return false;
      }
   }
}
