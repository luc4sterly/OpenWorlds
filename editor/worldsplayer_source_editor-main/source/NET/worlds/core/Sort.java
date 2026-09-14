package NET.worlds.core;

import java.awt.Choice;
import java.awt.List;
import java.util.Enumeration;
import java.util.Vector;

public class Sort {
   public static void sort(String[] var0) {
      quicksort(var0, 0, var0.length - 1);
   }

   public static String[] sort(Enumeration var0, int var1) {
      String[] var2 = new String[var1];

      for (int var3 = 0; var3 < var1; var3++) {
         var2[var3] = var0.nextElement().toString();
      }

      quicksort(var2, 0, var1 - 1);
      return var2;
   }

   public static String[] sort(Vector var0) {
      return sort(var0.elements(), var0.size());
   }

   public static String[] sortKeys(java.util.Hashtable var0) {
      return sort(var0.keys(), var0.size());
   }

   public static void sortInto(List var0, java.util.Hashtable var1) {
      String[] var2 = sortKeys(var1);

      for (int var3 = 0; var3 < var2.length; var3++) {
         var0.add(var2[var3]);
      }
   }

   public static void sortInto(List var0, Vector var1) {
      String[] var2 = sort(var1);

      for (int var3 = 0; var3 < var2.length; var3++) {
         var0.add(var2[var3]);
      }
   }

   public static void sortInto(Choice var0, java.util.Hashtable var1) {
      String[] var2 = sortKeys(var1);

      for (int var3 = 0; var3 < var2.length; var3++) {
         var0.add(var2[var3]);
      }
   }

   public static void sortInto(Choice var0, Vector var1) {
      String[] var2 = sort(var1);

      for (int var3 = 0; var3 < var2.length; var3++) {
         var0.add(var2[var3]);
      }
   }

   private static void quicksort(String[] var0, int var1, int var2) {
      if (var2 > var1) {
         String var3 = var0[var2];
         int var6 = var1 - 1;
         int var7 = var2;

         String var4;
         do {
            while (var0[++var6].compareTo(var3) < 0) {
            }

            do {
               var7--;
            } while (var7 > var1 && var0[var7].compareTo(var3) > 0);

            var4 = var0[var6];
            var0[var6] = var0[var7];
            var0[var7] = var4;
         } while (var7 > var6);

         var0[var7] = var0[var6];
         var0[var6] = var0[var2];
         var0[var2] = var4;
         quicksort(var0, var1, var6 - 1);
         quicksort(var0, var6 + 1, var2);
      }
   }
}
