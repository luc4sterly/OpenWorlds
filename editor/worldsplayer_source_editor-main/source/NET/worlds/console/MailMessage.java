package NET.worlds.console;

import NET.worlds.network.DNSLookup;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Enumeration;
import java.util.Vector;

public class MailMessage extends Thread {
   private String server;
   private String from;
   private String to;
   private Vector cc;
   private String subject;
   private Vector body;
   private boolean lock = false;

   public MailMessage(String var1) {
      this(var1, null, null, null, null);
   }

   public MailMessage(String var1, String var2, String var3) {
      this(var1, var2, var3, null, null);
   }

   public MailMessage(String var1, String var2, String var3, String var4, String var5) {
      this.server = var1;
      this.from = var2;
      this.to = var3;
      this.cc = new Vector();
      this.subject = var4;
      this.body = new Vector();
      if (var5 != null) {
         this.body.addElement(var5);
      }
   }

   public void setFrom(String var1) {
      if (!this.locked()) {
         this.from = var1;
      }
   }

   public void setTo(String var1) {
      if (!this.locked()) {
         this.to = var1;
      }
   }

   public void addCC(String var1) {
      if (!this.locked()) {
         this.cc.addElement(var1);
      }
   }

   public void setSubject(String var1) {
      if (!this.locked()) {
         this.subject = var1;
      }
   }

   public void setBody(String var1) {
      if (!this.locked()) {
         this.body = new Vector();
         this.body.addElement(var1);
      }
   }

   public void appendBody(String var1) {
      if (!this.locked()) {
         this.body.addElement(var1);
      }
   }

   public void appendParagraphs(String var1, String var2, int var3) {
      if (!this.locked()) {
         String var4 = "";
         String var5 = "";
         String var6 = "";
         boolean var7 = false;
         int var8 = 0;

         for (int var9 = 0; var9 < var1.length(); var9++) {
            char var10 = var1.charAt(var9);
            if (var6.length() > 0 && Character.isWhitespace(var10)) {
               var8 += var5.length() + var6.length();
               if (var8 > var3) {
                  var4 = var4 + var2;
                  var8 = var6.length();
               } else {
                  var4 = var4 + var5;
               }

               var4 = var4 + var6;
               var6 = "";
               var5 = "";
            }

            if (var10 != '\n' && var10 != '\r') {
               var7 = false;
               if (Character.isWhitespace(var10)) {
                  var5 = var5 + var10;
               } else {
                  var6 = var6 + var10;
               }
            } else if (!var7) {
               var8 = 0;
               var4 = var4 + var2;
               var4 = var4 + var2;
               var7 = true;
            }
         }

         if (var6.length() > 0) {
            var4 = var4 + var5;
            var4 = var4 + var6;
         }

         this.body.addElement(var4);
      }
   }

   public void appendParagraphs(String var1) {
      this.appendParagraphs(var1, "\n", 70);
   }

   private synchronized void lockMessage() {
      this.lock = true;
   }

   private synchronized void unlockMessage() {
      this.lock = false;
   }

   private synchronized boolean locked() {
      return this.lock;
   }

   protected void finished(boolean var1) {
   }

   public void send() {
      this.start();
   }

   public void run() {
      this.lockMessage();
      this.from = Console.parseUnicode(this.from);
      this.to = Console.parseUnicode(this.to);
      this.cc = Console.parseUnicode(this.cc);
      this.subject = Console.parseUnicode(this.subject);
      this.body = Console.parseUnicode(this.body);
      boolean var1 = !sendNote(this.server, this.from, this.to, this.cc, this.subject, this.body);
      this.unlockMessage();
      this.finished(var1);
   }

   public static synchronized boolean sendNote(String var0, String var1, String var2, Vector var3, String var4, Vector var5) {
      int var6 = 25;
      int var7 = var0.indexOf(58);
      if (var7 != -1) {
         var6 = Integer.parseInt(var0.substring(var7 + 1));
         var0 = var0.substring(0, var7);
      }

      Socket var8 = null;

      try {
         var8 = new Socket(DNSLookup.lookup(var0), var6);
         InputStream var9 = var8.getInputStream();
         PrintWriter var10 = new PrintWriter(var8.getOutputStream());
         if (getReply(var9)
            && print(var10, "HELO worlds.net\r\n")
            && getReply(var9)
            && print(var10, "MAIL FROM:<" + var1 + ">\r\n")
            && getReply(var9)
            && print(var10, "RCPT TO:<" + var2 + ">\r\n")
            && getReply(var9)
            && printCCcmd(var10, var9, var3)
            && print(var10, "DATA\r\n")
            && getReply(var9)
            && print(var10, "MIME-Version: 1.0\r\n")
            && print(var10, "MContent-Type: text/plain; charset=\"us-ascii\"\r\n")
            && print(var10, "From: " + var1 + "\r\n")
            && print(var10, "To: " + var2 + "\r\n")
            && printCCline(var10, var3)
            && print(var10, "Subject: " + var4 + "\r\n\r\n")
            && print(var10, var5)
            && print(var10, "\r\n.\r\n")) {
            getReply(var9);
         }
      } catch (IOException var20) {
         System.out.println("Error communicating with mail server: " + var20);
         return false;
      } finally {
         try {
            if (var8 != null) {
               var8.close();
            }
         } catch (IOException var19) {
         }
      }

      System.out.println("MailMessage.sendNote: complete.");
      return true;
   }

   private static boolean print(PrintWriter var0, String var1) {
      var0.print(var1);
      return !var0.checkError();
   }

   private static boolean print(PrintWriter var0, Vector var1) {
      int var2 = var1.size();

      for (int var3 = 0; var3 < var2; var3++) {
         var0.print((String)var1.elementAt(var3));
         if (var0.checkError()) {
            return false;
         }
      }

      return true;
   }

   private static boolean printCCcmd(PrintWriter var0, InputStream var1, Vector var2) {
      if (var2.size() > 0) {
         Enumeration var3 = var2.elements();

         while (var3.hasMoreElements()) {
            String var4 = (String)var3.nextElement();
            if (!print(var0, "RCPT TO:<" + var4 + ">\r\n")) {
               return false;
            }

            if (!getReply(var1)) {
               return false;
            }
         }
      }

      return true;
   }

   private static boolean printCCline(PrintWriter var0, Vector var1) {
      int var2 = var1.size();
      if (var2 > 0) {
         if (!print(var0, "cc: ")) {
            return false;
         }

         Enumeration var3 = var1.elements();

         while (var3.hasMoreElements()) {
            String var4 = (String)var3.nextElement();
            if (var2-- > 1) {
               var4 = var4 + ", ";
            }

            if (!print(var0, var4)) {
               return false;
            }
         }

         if (!print(var0, "\r\n")) {
            return false;
         }
      }

      return true;
   }

   private static boolean getReply(InputStream var0) {
      try {
         int var1;
         while ((var1 = var0.read()) >= 0 && var1 != 10) {
         }

         return true;
      } catch (IOException var2) {
         return false;
      }
   }

   public static void main(String[] var0) {
      Vector var1 = new Vector();
      var1.addElement("Looks like it worked...\n");
      sendNote("www.3dcd.com:25", "Gamma Mail Service", "thumper@alumni.caltech.edu", new Vector(), "this is a test", var1);
   }
}
