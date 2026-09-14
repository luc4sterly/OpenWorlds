package NET.worlds.network;

import NET.worlds.core.IniFile;
import java.io.RandomAccessFile;
import java.util.Hashtable;
import java.util.StringTokenizer;
import java.util.Vector;

public class FilthFilter {
   private static FilthFilter theFilthFilter = null;
   private String filthFile;
   private int key = 253414429;
   private Hashtable naughtyPhrases;
   private Vector naughtyWords;
   private boolean allowObscenities;

   public static FilthFilter get() {
      if (theFilthFilter == null) {
         theFilthFilter = new FilthFilter();
      }

      return theFilthFilter;
   }

   private FilthFilter() {
      this.filthFile = IniFile.gamma().getIniString("filthfile", "filter.dat");
      if (IniFile.gamma().getIniInt("encryptfilth", 0) == 1) {
         this.encryptFilthFile();
      }

      this.allowObscenities = IniFile.gamma().getIniInt("allowObscenities", 0) == 1 || IniFile.override().getIniInt("allowObscentiies", 0) == 1;
      this.loadFilth();
   }

   private void loadFilth() {
      this.naughtyPhrases = new Hashtable();
      this.naughtyWords = new Vector();

      try {
         RandomAccessFile var1 = new RandomAccessFile(this.filthFile, "r");
         byte[] var2 = new byte[var1.readInt()];
         var1.readFully(var2);
         var1.close();
         String var3 = this.decrypt(var2);
         StringTokenizer var4 = new StringTokenizer(var3, "\n\r\t ", false);

         while (var4.hasMoreTokens()) {
            String var5 = var4.nextToken();
            FilthyPhrase var6 = new FilthyPhrase(var5);
            String var7 = var6.firstWord();
            Vector var8 = (Vector)this.naughtyPhrases.get(var7);
            if (var8 == null) {
               var8 = new Vector();
               this.naughtyPhrases.put(var7, var8);
            }

            var8.addElement(var6);
            if (var6.size() == 1L) {
               this.naughtyWords.addElement(var6.firstWord());
            }
         }
      } catch (Exception var9) {
         System.out.println("Error in filth file: " + var9.toString());
      }
   }

   private byte[] encrypt(String var1) {
      byte[] var2;
      try {
         var2 = var1.getBytes();
      } catch (Exception var6) {
         System.out.println("Error encoding to UTF8" + var6.toString());
         return null;
      }

      byte[] var3 = new byte[var2.length];
      int var4 = var2.length;
      var3[0] = var2[0];

      for (int var5 = 1; var5 < var4; var5++) {
         var3[var5] = (byte)(var2[var5] ^ var3[var5 - 1]);
      }

      return var3;
   }

   private String decrypt(byte[] var1) {
      byte[] var2 = new byte[var1.length];
      int var3 = var1.length;
      var2[0] = var1[0];

      for (int var4 = 1; var4 < var3; var4++) {
         var2[var4] = (byte)(var1[var4] ^ var1[var4 - 1]);
      }

      try {
         return new String(var2, "UTF8");
      } catch (Exception var6) {
         System.out.println("Error encoding UTF8 " + var6.toString());
         return null;
      }
   }

   private void encryptFilthFile() {
      try {
         System.out.println("Encoding filth file...");
         RandomAccessFile var1 = new RandomAccessFile("filth.txt", "r");
         String var2 = new String();

         while (var1.getFilePointer() < var1.length()) {
            String var3 = var1.readLine();
            System.out.println(var3);
            var2 = var2 + var3 + "\r\n";
         }

         var1.close();
         byte[] var6 = this.encrypt(var2);
         RandomAccessFile var4 = new RandomAccessFile(this.filthFile, "rw");
         var4.writeInt(var6.length);
         var4.write(var6);
         var4.close();
         System.out.println("Filth file " + this.filthFile + " successfully written.");
      } catch (Exception var5) {
         System.out.println("Error encoding filth file: " + var5.toString());
      }
   }

   public String filter(String var1) {
      if (this.allowObscenities) {
         return var1;
      }

      String var2 = new String();

      while (var1.length() > 0) {
         StringTokenizer var3 = new StringTokenizer(var1, "\t\n\r.,;'\"!?*:/()[]{} ", true);
         String var4 = var3.nextToken();
         String var5 = new String(var4.toLowerCase());
         Vector var6 = (Vector)this.naughtyPhrases.get(var5);
         if (var6 != null) {
            int var7 = 0;
            boolean var8 = false;

            while (var7 < var6.size()) {
               FilthyPhrase var9 = (FilthyPhrase)var6.elementAt(var7);
               if (var9.check(var1)) {
                  String var10 = var9.getReplacement();
                  var2 = var2 + var10;
                  var1 = var1.substring(var10.length(), var1.length());
                  var8 = true;
                  break;
               }

               var7++;
            }

            if (!var8) {
               var2 = var2 + var5;
               var1 = var1.substring(var5.length(), var1.length());
            }
         } else {
            var2 = var2 + var4;
            var1 = var1.substring(var5.length(), var1.length());
         }
      }

      return var2;
   }

   public String filterName(String var1) {
      if (this.allowObscenities) {
         return var1;
      }

      String var2 = new String(var1);

      for (int var3 = 0; var3 < this.naughtyWords.size(); var3++) {
         String var4 = (String)this.naughtyWords.elementAt(var3);
         int var5 = var2.indexOf(var4);
         if (var5 > -1) {
            String var6 = new String("$!@%#@&*!%#@%!@#$%@#@!@%!@#$%*&%$!");
            new String();
            String var7 = var2.substring(0, var5);
            var7 = var7 + var6.substring(0, var4.length());
            var7 = var7 + var2.substring(var5 + var4.length(), var2.length());
            var2 = var7;
         }
      }

      return var2;
   }

   public boolean isFilthy(String var1) {
      if (this.allowObscenities) {
         return false;
      }

      new String();

      while (var1.length() > 0) {
         StringTokenizer var3 = new StringTokenizer(var1, "\t\n\r.,;'\"!?*:/()[]{} ", true);
         String var4 = var3.nextToken().toLowerCase();
         Vector var5 = (Vector)this.naughtyPhrases.get(var4);
         if (var5 != null) {
            for (int var6 = 0; var6 < var5.size(); var6++) {
               FilthyPhrase var7 = (FilthyPhrase)var5.elementAt(var6);
               if (var7.check(var1)) {
                  return true;
               }
            }
         }
      }

      return false;
   }
}
