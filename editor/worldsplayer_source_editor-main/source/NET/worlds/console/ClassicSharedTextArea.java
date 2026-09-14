package NET.worlds.console;

import NET.worlds.core.Debug;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dialog;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.IllegalComponentStateException;
import java.awt.Point;
import java.awt.TextArea;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.util.Date;
import java.util.Observer;

class ClassicSharedTextArea extends TextArea implements SharedTextArea {
   private static Object lock = new Object();
   private static String sharedText;
   private boolean isShared;
   private String unsharedText;
   private String unaddedText;
   private boolean haveFocus;
   private int hwnd;
   private PrintWriter logFile;
   private String logFileName;
   private static final long oneMeg = 1048576L;
   private static final long logLengthLimit = 524288L;
   private static PublicObservable obsLogFile = new PublicObservable();

   public ClassicSharedTextArea(int var1, int var2, boolean var3) {
      super("", var1, var2, 1);
      this.isShared = var3;
      this.setEditable(false);
   }

   public Component getComponent() {
      return this;
   }

   public void finalize() {
      this.disableLogging();
   }

   public void validate() {
      super.validate();
      String var1 = this.isShared ? sharedText : this.unsharedText;
      if (var1 != null) {
         this.replaceRange("", 0, this.getText().length());
         this.append(var1);
      }

      this.hwnd = 0;
   }

   public synchronized void enableLogging(String var1, String var2, boolean var3) {
      if (this.logFile != null) {
         if (this.logFileName.equals(var1)) {
            return;
         }

         this.logFile.close();
      }

      try {
         if (var3 && new File(var1).exists()) {
            this.truncateIfExceeds(var1, var2, 524288L);
            this.logFile = new PrintWriter(new FileWriter(var1, true));
         } else {
            this.logFile = new PrintWriter(new FileWriter(var1, false));
            obsLogFile.setChanged(true);
            this.logFile.println("<html>");
            this.logFile.println("<head>");
            this.logFile.println("<title>" + var2 + "</title>");
            this.logFile.println("</head>");
            this.logFile.println("<body>");
         }

         this.logFileName = var1;
         this.logFile.println("<hr>");
         this.logFile.println("<h3>Conversation of " + DateFormat.getDateTimeInstance().format(new Date()) + "</h3>");
         this.logFile.flush();
         obsLogFile.notifyObservers(this);
      } catch (IOException var5) {
         System.out.println("Log file not opened: " + var5);
      }
   }

   public static void addLogObserver(Observer var0) {
      obsLogFile.addObserver(var0);
   }

   public static void deleteLogObserver(Observer var0) {
      obsLogFile.deleteObserver(var0);
   }

   private void truncateIfExceeds(String var1, String var2, long var3) {
      File var5 = new File(var1);
      if (var5.length() > var3) {
         File var6 = new File(var1 + ".temp");

         try {
            BufferedReader var7 = new BufferedReader(new FileReader(var5));
            PrintWriter var8 = new PrintWriter(new FileWriter(var6));
            var8.println("<html>");
            var8.println("<head>");
            var8.println("<title>" + var2 + "</title>");
            var8.println("</head>");
            var8.println("<body>");
            var7.skip(var5.length() - var3 / 2L);
            String var9 = var7.readLine();

            for (String var13 = var7.readLine(); var13 != null; var13 = var7.readLine()) {
               var8.println(var13);
            }

            var7.close();
            var8.close();
            var5.delete();
            var5 = new File(var1);
            var6.renameTo(var5);
         } catch (FileNotFoundException var10) {
            System.out.println("DuplexPart fatal: " + var10);
         } catch (IOException var11) {
            System.out.println("DuplexPart: Unable to write, " + var11);
         }
      }
   }

   public synchronized void disableLogging() {
      if (this.logFile != null) {
         this.logFile.close();
         this.logFile = null;
      }
   }

   public boolean canAddText() {
      if (!this.haveFocus) {
         return true;
      }

      if (this.hwnd == 0) {
         Container var1 = this.getParent();

         while (true) {
            if (var1 == null) {
               return true;
            }

            if (var1 instanceof java.awt.Window) {
               int var2;
               if (var1 instanceof Dialog) {
                  var2 = Window.findWindow(((Dialog)var1).getTitle());
               } else {
                  var2 = Window.getFrameHandle();
               }

               if (var2 != 0) {
                  try {
                     Point var3 = this.getLocationOnScreen();
                     Dimension var4 = this.size();
                     this.hwnd = Window.findChildWindow(var2, var3.x, var3.y, var4.width, var4.height);
                  } catch (IllegalComponentStateException var5) {
                  }
               }
               break;
            }

            var1 = var1.getParent();
         }
      }

      return Window.isLastLineVisible(this.hwnd, this);
   }

   private String toHtml(String var1) {
      Debug.assert_(var1 != null);
      String var2 = "";

      for (int var3 = 0; var3 < var1.length(); var3++) {
         char var4 = var1.charAt(var3);
         switch (var4) {
            case '"':
               var2 = var2 + "&quot;";
               break;
            case '&':
               var2 = var2 + "&amp;";
               break;
            case '<':
               var2 = var2 + "&lt;";
               break;
            case '>':
               var2 = var2 + "&gt;";
               break;
            default:
               var2 = var2 + var4;
         }
      }

      return var2;
   }

   public synchronized void println(String var1) {
      if (this.logFile != null && var1 != null) {
         this.logFile.println(this.toHtml(var1) + "<br>");
         this.logFile.flush();
      }

      if (this.unaddedText == null) {
         this.unaddedText = var1;
      } else if (var1 != null) {
         this.unaddedText = this.unaddedText + "\n" + var1;
      }

      if (this.unaddedText != null && this.canAddText()) {
         if (this.getText().length() == 0) {
            this.append(this.unaddedText);
         } else {
            this.append("\n" + this.unaddedText);
         }

         this.unaddedText = null;
         String var2 = this.getText();
         if (var2.length() > 5000) {
            int var3 = var2.indexOf(10, 1024);
            if (var3 >= 0) {
               var2 = var2.substring(var3 + 1);
               var3 = var2.lastIndexOf(10);
               if (var3 > 0) {
                  this.setText(var2.substring(0, var3));
                  this.append(var2.substring(var3));
               }
            }
         }

         if (this.isShared) {
            sharedText = var2;
         } else {
            this.unsharedText = var2;
         }
      }
   }

   public void scrollToBottom() {
      String var1 = this.getText();
      this.setText("");
      this.append(var1);
   }

   public boolean handleEvent(Event var1) {
      if (var1.id == 1004) {
         this.haveFocus = true;
      } else if (var1.id == 1005) {
         this.haveFocus = false;
      }

      this.poll();
      return super.handleEvent(var1);
   }

   public void poll() {
      if (this.unaddedText != null) {
         this.println(null);
      }
   }

   public boolean isFocusTraversable() {
      return false;
   }
}
