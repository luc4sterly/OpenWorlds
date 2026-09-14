package NET.worlds.scape;

import java.io.File;
import java.io.FilenameFilter;
import java.util.Enumeration;
import java.util.StringTokenizer;
import java.util.Vector;

public class FileList implements FilenameFilter {
   private String dirList;
   private String extList;
   private Vector exts;
   private boolean keepPathInfo;
   private boolean sort = true;

   public FileList(String var1, String var2) {
      this.dirList = var1;
      this.extList = var2;
   }

   public String getExtList() {
      return this.extList;
   }

   private static Vector breakUp(String var0) {
      StringTokenizer var1 = new StringTokenizer(var0, File.pathSeparator, false);
      Vector var2 = new Vector();

      while (var1.hasMoreTokens()) {
         var2.addElement(var1.nextToken());
      }

      return var2;
   }

   public boolean accept(File var1, String var2) {
      return extMatches(var2, this.exts);
   }

   public static boolean extMatches(String var0, Vector var1) {
      int var2 = var0.lastIndexOf(".");
      if (var2 != -1) {
         String var3 = var0.substring(var2 + 1);
         Enumeration var4 = var1.elements();

         while (var4.hasMoreElements()) {
            if (var3.equalsIgnoreCase((String)var4.nextElement())) {
               return true;
            }
         }
      }

      return false;
   }

   public static boolean extMatches(String var0, String var1) {
      return extMatches(var0, breakUp(var1));
   }

   public boolean extMatches(String var1) {
      return extMatches(var1, this.extList);
   }

   public FileList keepPathInfo() {
      this.keepPathInfo = true;
      return this;
   }

   public FileList dontSort() {
      this.sort = false;
      return this;
   }

   public static String removeTrailingSlash(String var0) {
      if (var0 != null) {
         int var1 = var0.length();
         if (var1 > 0) {
            char var2 = var0.charAt(var1 - 1);
            if (var2 == '/' || var2 == '\\') {
               var0 = var0.substring(0, var1 - 1);
            }
         }
      }

      return var0;
   }

   public Vector getList() {
      this.exts = breakUp(this.extList);
      Vector var1 = breakUp(this.dirList);
      Vector var2 = new Vector();
      Enumeration var3 = var1.elements();

      while (var3.hasMoreElements()) {
         String var4 = removeTrailingSlash((String)var3.nextElement());
         File var5 = new File(var4);
         if (var5.exists()) {
            String[] var6 = var5.list(this);
            if (this.keepPathInfo && !var4.equals(".")) {
               var4 = var4 + File.separator;
            } else {
               var4 = "";
            }

            for (int var7 = 0; var7 < var6.length; var7++) {
               String var8 = var4 + var6[var7];
               if (!this.sort) {
                  var2.addElement(var8);
               } else {
                  int var9 = var2.size();
                  String var11 = var8.toLowerCase();

                  int var10;
                  for (var10 = 0; var10 < var9; var10++) {
                     if (var11.compareTo(((String)var2.elementAt(var10)).toLowerCase()) < 0) {
                        var2.insertElementAt(var8, var10);
                        break;
                     }
                  }

                  if (var10 == var9) {
                     var2.addElement(var8);
                  }
               }
            }
         }
      }

      return var2;
   }
}
