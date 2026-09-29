package net.openworlds.launcher;

import java.util.ArrayList;
import java.util.List;

/**
 * A OpenWorlds version as the CI stamps it: {@code 1.0.<commits>} (tag
 * {@code v1.0.<commits>}), and {@code 1.0.<commits>-pre.<run>} for a test
 * build published from a branch. Numbers compare numerically; with equal
 * numbers a version without suffix is newer than one with it (as in semver).
 */
final class Version implements Comparable<Version> {
   final String text;
   private final int[] numbers;
   private final String suffix;

   private Version(String text, int[] numbers, String suffix) {
      this.text = text;
      this.numbers = numbers;
      this.suffix = suffix;
   }

   /** Parses "1.0.150", "v1.0.150" or "1.0.150-pre.3"; null for anything else (a commit hash, "dev"). */
   static Version parse(String s) {
      if (s == null) {
         return null;
      }
      String t = s.trim();
      if (t.startsWith("v") || t.startsWith("V")) {
         t = t.substring(1);
      }
      int dash = t.indexOf('-');
      String core = dash >= 0 ? t.substring(0, dash) : t;
      String suffix = dash >= 0 ? t.substring(dash + 1) : "";
      if (core.isEmpty()) {
         return null;
      }
      List<Integer> nums = new ArrayList<>();
      for (String p : core.split("\\.", -1)) {
         if (p.isEmpty() || p.length() > 9 || !p.chars().allMatch(Character::isDigit)) {
            return null;
         }
         nums.add(Integer.parseInt(p));
      }
      if (nums.size() < 2) {
         return null;
      }
      int[] n = new int[nums.size()];
      for (int i = 0; i < n.length; i++) {
         n[i] = nums.get(i);
      }
      return new Version(t, n, suffix);
   }

   boolean isPrerelease() {
      return !suffix.isEmpty();
   }

   @Override
   public int compareTo(Version o) {
      int len = Math.max(numbers.length, o.numbers.length);
      for (int i = 0; i < len; i++) {
         int a = i < numbers.length ? numbers[i] : 0;
         int b = i < o.numbers.length ? o.numbers[i] : 0;
         if (a != b) {
            return Integer.compare(a, b);
         }
      }
      if (suffix.isEmpty() || o.suffix.isEmpty()) {
         return Boolean.compare(suffix.isEmpty(), o.suffix.isEmpty());
      }
      return natural(suffix, o.suffix);
   }

   /** "pre.10" after "pre.9": runs of digits compare as numbers. */
   private static int natural(String a, String b) {
      int i = 0, j = 0;
      while (i < a.length() && j < b.length()) {
         char ca = a.charAt(i);
         char cb = b.charAt(j);
         if (Character.isDigit(ca) && Character.isDigit(cb)) {
            int si = i, sj = j;
            while (i < a.length() && Character.isDigit(a.charAt(i))) {
               i++;
            }
            while (j < b.length() && Character.isDigit(b.charAt(j))) {
               j++;
            }
            String na = a.substring(si, i).replaceFirst("^0+(?=.)", "");
            String nb = b.substring(sj, j).replaceFirst("^0+(?=.)", "");
            int c = na.length() != nb.length() ? Integer.compare(na.length(), nb.length()) : na.compareTo(nb);
            if (c != 0) {
               return c;
            }
         } else {
            if (ca != cb) {
               return Character.compare(ca, cb);
            }
            i++;
            j++;
         }
      }
      return Integer.compare(a.length() - i, b.length() - j);
   }

   @Override
   public boolean equals(Object o) {
      return o instanceof Version && compareTo((Version) o) == 0;
   }

   @Override
   public int hashCode() {
      return text.hashCode();
   }

   @Override
   public String toString() {
      return text;
   }
}
