package net.openworlds.launcher;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/**
 * Just enough JSON for the GitHub releases API (the launcher has no
 * dependencies): objects become {@code Map<String, Object>}, arrays
 * {@code List<Object>}, numbers {@code Double} or {@code Long}, plus
 * String, Boolean and null.
 */
final class Json {
   private final String s;
   private int i;

   private Json(String s) {
      this.s = s;
   }

   static Object parse(String text) {
      Json j = new Json(text);
      j.space();
      Object v = j.value();
      j.space();
      if (j.i != j.s.length()) {
         throw j.error("trailing text");
      }
      return v;
   }

   @SuppressWarnings("unchecked")
   static Map<String, Object> object(Object o) {
      return o instanceof Map ? (Map<String, Object>) o : new LinkedHashMap<>();
   }

   @SuppressWarnings("unchecked")
   static List<Object> array(Object o) {
      return o instanceof List ? (List<Object>) o : new ArrayList<>();
   }

   static String string(Map<String, Object> m, String key) {
      Object v = m.get(key);
      return v instanceof String ? (String) v : null;
   }

   static boolean bool(Map<String, Object> m, String key) {
      return Boolean.TRUE.equals(m.get(key));
   }

   static long number(Map<String, Object> m, String key) {
      Object v = m.get(key);
      return v instanceof Number ? ((Number) v).longValue() : -1;
   }

   private Object value() {
      if (i >= s.length()) {
         throw error("unexpected end");
      }
      char c = s.charAt(i);
      switch (c) {
         case '{':
            return obj();
         case '[':
            return arr();
         case '"':
            return str();
         case 't':
            return word("true", Boolean.TRUE);
         case 'f':
            return word("false", Boolean.FALSE);
         case 'n':
            return word("null", null);
         default:
            if (c == '-' || c >= '0' && c <= '9') {
               return num();
            }
            throw error("unexpected value '" + c + "'");
      }
   }

   private Map<String, Object> obj() {
      Map<String, Object> m = new LinkedHashMap<>();
      i++;
      space();
      if (peek() == '}') {
         i++;
         return m;
      }
      while (true) {
         space();
         if (peek() != '"') {
            throw error("a key was expected");
         }
         String k = str();
         space();
         expect(':');
         space();
         m.put(k, value());
         space();
         char c = next();
         if (c == '}') {
            return m;
         }
         if (c != ',') {
            throw error("',' or '}' was expected");
         }
      }
   }

   private List<Object> arr() {
      List<Object> l = new ArrayList<>();
      i++;
      space();
      if (peek() == ']') {
         i++;
         return l;
      }
      while (true) {
         space();
         l.add(value());
         space();
         char c = next();
         if (c == ']') {
            return l;
         }
         if (c != ',') {
            throw error("',' or ']' was expected");
         }
      }
   }

   private String str() {
      expect('"');
      StringBuilder b = new StringBuilder();
      while (true) {
         char c = next();
         if (c == '"') {
            return b.toString();
         }
         if (c != '\\') {
            b.append(c);
            continue;
         }
         char e = next();
         switch (e) {
            case 'n':
               b.append('\n');
               break;
            case 't':
               b.append('\t');
               break;
            case 'r':
               b.append('\r');
               break;
            case 'b':
               b.append('\b');
               break;
            case 'f':
               b.append('\f');
               break;
            case 'u':
               if (i + 4 > s.length()) {
                  throw error("truncated \\u escape");
               }
               b.append((char) Integer.parseInt(s.substring(i, i + 4), 16));
               i += 4;
               break;
            default:
               b.append(e);
         }
      }
   }

   private Object num() {
      int start = i;
      while (i < s.length() && "+-0123456789.eE".indexOf(s.charAt(i)) >= 0) {
         i++;
      }
      String t = s.substring(start, i);
      try {
         if (t.indexOf('.') < 0 && t.indexOf('e') < 0 && t.indexOf('E') < 0) {
            return Long.parseLong(t);
         }
         return Double.parseDouble(t);
      } catch (NumberFormatException e) {
         throw error("malformed number " + t);
      }
   }

   private Object word(String w, Object v) {
      if (!s.startsWith(w, i)) {
         throw error("expected " + w);
      }
      i += w.length();
      return v;
   }

   private void space() {
      while (i < s.length() && Character.isWhitespace(s.charAt(i))) {
         i++;
      }
   }

   private char peek() {
      return i < s.length() ? s.charAt(i) : '\0';
   }

   private char next() {
      if (i >= s.length()) {
         throw error("unexpected end");
      }
      return s.charAt(i++);
   }

   private void expect(char c) {
      if (next() != c) {
         throw error("expected '" + c + "'");
      }
   }

   private IllegalArgumentException error(String what) {
      return new IllegalArgumentException("JSON: " + what + " at position " + i);
   }
}
