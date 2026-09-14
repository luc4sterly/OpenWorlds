package NET.worlds.network;

import java.util.StringTokenizer;
import java.util.Vector;

public class FilthyPhrase {
   private long compareValue;
   private Vector filthyWords;
   private String rawData;

   public FilthyPhrase(String var1) {
      this.rawData = new String(var1);
      this.filthyWords = new Vector();
      StringTokenizer var2 = new StringTokenizer(var1, "\t\n\r.,;'\"!?*:/()[]{} ", true);
      if (var2.hasMoreTokens()) {
         String var3 = var2.nextToken().toLowerCase();
         this.compareValue = var3.hashCode();
         this.filthyWords.addElement(var3);
      }

      while (var2.hasMoreTokens()) {
         String var4 = var2.nextToken();
         this.filthyWords.addElement(var4.toLowerCase());
      }
   }

   public boolean check(String var1) {
      StringTokenizer var2 = new StringTokenizer(var1, "\t\n\r.,;'\"!?*:/()[]{} ", true);

      for (int var3 = 0; var3 < this.filthyWords.size(); var3++) {
         if (!var2.hasMoreTokens()) {
            return false;
         }

         String var4 = var2.nextToken().toLowerCase();
         String var5 = (String)this.filthyWords.elementAt(var3);
         if (var5.compareTo(var4) != 0) {
            return false;
         }
      }

      return true;
   }

   public String getReplacement() {
      String var1 = new String("$!@%#@&*!%#@%!@#$%@#@!@%!@#$%*&%$!");
      String var2 = new String();

      for (int var3 = 0; var3 < this.filthyWords.size(); var3++) {
         int var4 = ((String)this.filthyWords.elementAt(var3)).length();
         new String();
         String var5;
         if (var4 > 1) {
            var5 = var1.substring(0, var4);
         } else {
            var5 = (String)this.filthyWords.elementAt(var3);
         }

         var2 = var2 + var5;
      }

      return var2;
   }

   public long size() {
      return this.filthyWords.size();
   }

   public long compareValue() {
      return this.compareValue;
   }

   public String firstWord() {
      return this.filthyWords.size() > 0 ? (String)this.filthyWords.elementAt(0) : new String("");
   }

   public String asString() {
      return this.rawData;
   }
}
