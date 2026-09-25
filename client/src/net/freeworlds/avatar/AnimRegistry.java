package net.freeworlds.avatar;

import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

/**
 * Registro de animacion de avatares (avatars.dat) de gamma.dll: el objeto
 * de 0xf8 bytes que devuelve FUN_0042c7f0 (singleton DAT_0049ff24).
 *
 * <pre>
 * +0x04/+0x08  vector de tipos de avatar (0x4c bytes cada uno)
 * +0x0c/+0x58/+0xa4  tres tipos especiales vacios (indices 0xfb/0xfc/0xfd)
 * +0xf0        ultimo token leido
 * </pre>
 *
 * Cada tipo (FUN_0042ba20) guarda un mapa de atributos (name, geometry...)
 * en +0x00, los implicitos (claves +0x10, secuencias +0x1c), los
 * explicitos (claves +0x28, secuencias +0x34) y los bloques
 * beginchangeimp (+0x40). Las claves de accion se guardan en minusculas
 * (FUN_004280b0); los valores y los atributos tal cual.
 *
 * El texto lo parte un escaner generado por flex (FUN_0042a4c0) cuyas
 * tablas se copian aqui del binario; las reglas que resultan de ellas
 * estan en docs/seq-animation-reference.md.
 *
 * Portado al cliente propio (2026-09-25) desde el puente
 * (editor/.../bridge/NET/worlds/core/AnimRegistry.java), que es la traduccion
 * verificada con bridge/test/Animator*Check.java; aqui solo cambia el paquete.
 */
public final class AnimRegistry {
   /** Un bloque beginchangeimp...endchangeimp (0x11c bytes, FUN_0042bdc0). */
   public static final class ChangeImp {
      /** El explicito al que sigue el bloque (+0x00, FUN_0042be60). */
      public final String name;
      /** +0x104 (FUN_0042be70). */
      public final List<String> keys = new ArrayList<String>();
      /** +0x110 (FUN_0042be80). */
      public final List<String> values = new ArrayList<String>();

      ChangeImp(String name) {
         this.name = name;
      }
   }

   /** Un tipo de avatar: el registro de 0x4c bytes (FUN_0042ba20). */
   public static final class AvatarType {
      /** Mapa ordenado por strcmp (FUN_0042e0e0 inserta, FUN_0042bf40 busca). */
      final TreeMap<String, String> attrs = new TreeMap<String, String>();
      /** +0x10 (FUN_0042bd20). */
      public final List<String> impKeys = new ArrayList<String>();
      /** +0x1c (FUN_0042bd30). */
      public final List<String> impValues = new ArrayList<String>();
      /** +0x28 (FUN_0042bd40). */
      public final List<String> expKeys = new ArrayList<String>();
      /** +0x34 (FUN_0042bd50). */
      public final List<String> expValues = new ArrayList<String>();
      /** +0x40. */
      public final List<ChangeImp> changeImps = new ArrayList<ChangeImp>();

      /** FUN_0042bcb0: el valor del atributo o "" si no esta. */
      public String attr(String key) {
         String v = this.attrs.get(key);
         return v == null ? "" : v;
      }

      /** FUN_0042bd60: el primer bloque changeimp de ese explicito (strcmp) o null. */
      public ChangeImp changeImp(String expName) {
         for (ChangeImp c : this.changeImps) {
            if (c.name.equals(expName)) {
               return c;
            }
         }
         return null;
      }
   }

   /** Error de sintaxis: lo que FUN_0042c6a0 + FUN_00451670 lanzan (throw de C++). */
   public static final class ParseError extends RuntimeException {
      private static final long serialVersionUID = 1L;
      public final int line;

      ParseError(String msg, int line) {
         super(msg + " (linea " + line + ")");
         this.line = line;
      }
   }

   private final List<AvatarType> types = new ArrayList<AvatarType>();
   private final AvatarType[] special = {new AvatarType(), new AvatarType(), new AvatarType()};
   private String path;

   private static final AnimRegistry INSTANCE = new AnimRegistry();

   /** FUN_0042c7f0. */
   public static AnimRegistry get() {
      return INSTANCE;
   }

   /** FUN_0042ca50: borra los tipos (los tres especiales se quedan). */
   public synchronized void clear() {
      this.types.clear();
   }

   public synchronized int size() {
      return this.types.size();
   }

   /** FUN_0042ca00: 0xfb/0xfc/0xfd son los tipos especiales; fuera de rango -> null. */
   public synchronized AvatarType type(int idx) {
      if (idx == 0xfb) {
         return this.special[0];
      }
      if (idx == 0xfc) {
         return this.special[1];
      }
      if (idx == 0xfd) {
         return this.special[2];
      }
      return idx >= 0 && idx < this.types.size() ? this.types.get(idx) : null;
   }

   /**
    * FUN_0042c8a0: indice del primer tipo cuyo atributo "name"
    * (DAT_004748f0) es igual sin distinguir mayusculas (FUN_00427450 ->
    * FUN_004508c0, tabla tolower DAT_00482818); -1 si no hay o el nombre
    * es vacio.
    */
   public synchronized int nameIndex(String name) {
      if (name == null || name.isEmpty()) {
         return -1;
      }
      String n = str(name);
      for (int i = 0; i < this.types.size(); i++) {
         if (stricmp(n, str(this.types.get(i).attr("name"))) == 0) {
            return i;
         }
      }
      return -1;
   }

   /**
    * FUN_0042cb90: la primera linea (FUN_0041f300 = getline de hasta 32
    * caracteres hasta '\n') elige la gramatica: "# animation registry
    * version 0.2" (FUN_0042d840) o "... 0.3" (FUN_0042cda0); otra cosa es
    * "unrecognized cookie". Los tipos anadidos antes de un error se quedan.
    */
   public synchronized void load(byte[] text, String path) {
      this.path = path;
      int p = 0;
      StringBuilder cookie = new StringBuilder();
      int n = 0x21;
      while (p < text.length) {
         int c = text[p] & 0xFF;
         if (c == '\n') {
            p++;
            break;
         }
         if (n == 1) {
            break;
         }
         p++;
         cookie.append((char) c);
         n--;
      }
      Lexer lx = new Lexer(text, p);
      String ck = cookie.toString();
      if (ck.equals("# animation registry version 0.2")) {
         this.parseV02(lx);
      } else if (ck.equals("# animation registry version 0.3")) {
         this.parseV03(lx);
      } else {
         throw new ParseError("unrecognized cookie", lx.line);
      }
   }

   public synchronized String path() {
      return this.path;
   }

   // ------------------------------------------------------------- v0.3

   /** FUN_0042cda0: version 3, luego bloques avatar hasta el fin (-1). */
   private void parseV03(Lexer lx) {
      int t = lx.next();
      if (t != Lexer.VERSION) {
         throw lx.unexpected(t);
      }
      t = lx.next();
      if (t != Lexer.NUMBER) {
         throw lx.unexpected(t);
      }
      if (lx.version != 3) {
         throw new ParseError("can't handle requested file version", lx.line);
      }
      t = lx.next();
      while (t != Lexer.EOF) {
         if (t != Lexer.AVATAR) {
            throw lx.unexpected(t);
         }
         AvatarType a = new AvatarType();
         this.avatarV03(lx, a);
         this.types.add(a);
         t = lx.next();
      }
   }

   /** FUN_0042cfc0: atributos, beginimp y beginexp hasta endavatar. */
   private void avatarV03(Lexer lx, AvatarType a) {
      int t = lx.next();
      while (t != Lexer.ENDAVATAR) {
         if (t == Lexer.IDENT) {
            String key = str(lx.text);
            expect(lx, Lexer.EQUALS);
            expect(lx, Lexer.IDENT);
            a.attrs.put(key, str(lx.text));
         } else if (t == Lexer.BEGINIMP) {
            this.impV03(lx, a);
         } else if (t == Lexer.BEGINEXP) {
            this.expV03(lx, a);
         } else {
            throw lx.unexpected(t);
         }
         t = lx.next();
      }
   }

   /** FUN_0042d3e0: pares clave=secuencia hasta endimp; clave vacia = "invalid action name". */
   private void impV03(Lexer lx, AvatarType a) {
      int t = lx.next();
      while (t != Lexer.ENDIMP) {
         if (t != Lexer.IDENT) {
            throw lx.unexpected(t);
         }
         String key = str(lower(lx.text));
         if (key.isEmpty()) {
            throw new ParseError("invalid action name", lx.line);
         }
         expect(lx, Lexer.EQUALS);
         expect(lx, Lexer.IDENT);
         a.impKeys.add(key);
         a.impValues.add(str(lx.text));
         t = lx.next();
      }
   }

   /** FUN_0042d640: pares hasta endexp; beginchangeimp se cuelga del ultimo explicito leido. */
   private void expV03(Lexer lx, AvatarType a) {
      String last = "";
      int t = lx.next();
      while (t != Lexer.ENDEXP) {
         if (t == Lexer.BEGINCHANGEIMP) {
            this.changeImpV03(lx, a, last);
         } else {
            if (t != Lexer.IDENT) {
               throw lx.unexpected(t);
            }
            String key = str(lower(lx.text));
            last = key;
            expect(lx, Lexer.EQUALS);
            expect(lx, Lexer.IDENT);
            a.expKeys.add(key);
            a.expValues.add(str(lx.text));
         }
         t = lx.next();
      }
   }

   /** FUN_0042d0c0: pares hasta endchangeimp, claves en minusculas. */
   private void changeImpV03(Lexer lx, AvatarType a, String name) {
      ChangeImp c = new ChangeImp(name);
      int t = lx.next();
      while (t != Lexer.ENDCHANGEIMP) {
         if (t != Lexer.IDENT) {
            throw lx.unexpected(t);
         }
         String key = str(lower(lx.text));
         expect(lx, Lexer.EQUALS);
         expect(lx, Lexer.IDENT);
         c.keys.add(key);
         c.values.add(str(lx.text));
         t = lx.next();
      }
      a.changeImps.add(c);
   }

   // ------------------------------------------------------------- v0.2

   /**
    * FUN_0042d840: primero el tipo fijo "cy" (FUN_0042ca70: name=cy,
    * geometry=cy.rwx), luego "avatar NOMBRE clave=valor... endavatar" con
    * tres implicitos (walk, wait, endwait) y un explicito (wave) fijos.
    * ⚠️ Sin ejemplar en el corpus: todos los avatars.dat son version 0.3.
    */
   private void parseV02(Lexer lx) {
      AvatarType cy = new AvatarType();
      cy.attrs.put("name", "cy");
      cy.attrs.put("geometry", "cy.rwx");
      this.types.add(cy);
      int t = lx.next();
      while (t != Lexer.EOF) {
         if (t != Lexer.AVATAR) {
            throw lx.unexpected(t);
         }
         AvatarType a = new AvatarType();
         for (int i = 0; i < 3; i++) {
            a.impKeys.add("");
            a.impValues.add("");
         }
         a.expKeys.add("");
         a.expValues.add("");
         this.avatarV02(lx, a);
         this.types.add(a);
         t = lx.next();
      }
   }

   /** FUN_0042da80. */
   private void avatarV02(Lexer lx, AvatarType a) {
      expect(lx, Lexer.IDENT);
      if (str(lx.text).equals("cy")) {
         throw new ParseError("cy was handled specially", lx.line);
      }
      a.attrs.put("name", str(lx.text));
      int t = lx.next();
      while (t != Lexer.ENDAVATAR) {
         if (t != Lexer.IDENT) {
            throw lx.unexpected(t);
         }
         String key = str(lx.text);
         expect(lx, Lexer.EQUALS);
         expect(lx, Lexer.IDENT);
         String value = str(lx.text);
         if (key.equals("geometry")) {
            a.attrs.put("geometry", value);
         } else if (key.equals("walk")) {
            a.impKeys.set(0, key);
            a.impValues.set(0, value);
         } else if (key.equals("wait")) {
            a.impKeys.set(1, key);
            a.impValues.set(1, value);
         } else if (key.equals("endwait")) {
            a.impKeys.set(2, key);
            a.impValues.set(2, value);
         } else if (key.equals("wave")) {
            a.expKeys.set(0, key);
            a.expValues.set(0, value);
         }
         t = lx.next();
      }
   }

   private static void expect(Lexer lx, int tok) {
      int t = lx.next();
      if (t != tok) {
         throw lx.unexpected(t);
      }
   }

   // ------------------------------------------------------------- utilidades

   /** La clase String de gamma.dll (FUN_00427410) guarda como mucho 255 caracteres. */
   static String str(String s) {
      return s.length() > 0xff ? s.substring(0, 0xff) : s;
   }

   /** FUN_004280b0: solo A-Z pasan a minusculas (bit 0x80 de la tabla DAT_00482718). */
   static String lower(String s) {
      StringBuilder b = new StringBuilder(s.length());
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         b.append(c >= 'A' && c <= 'Z' ? (char) (c + 32) : c);
      }
      return b.toString();
   }

   /** FUN_004508c0: comparacion por la tabla tolower DAT_00482818 (0xff se compara como -1). */
   static int stricmp(String a, String b) {
      int n = Math.max(a.length(), b.length()) + 1;
      for (int i = 0; i < n; i++) {
         int ca = i < a.length() ? a.charAt(i) & 0xFF : 0;
         int cb = i < b.length() ? b.charAt(i) & 0xFF : 0;
         int la = ca == 0xFF ? -1 : (byte) (ca >= 'A' && ca <= 'Z' ? ca + 32 : ca);
         int lb = cb == 0xFF ? -1 : (byte) (cb >= 'A' && cb <= 'Z' ? cb + 32 : cb);
         if (la < lb) {
            return -1;
         }
         if (lb < la) {
            return 1;
         }
         if (la == 0) {
            return 0;
         }
      }
      return 0;
   }

   /**
    * El escaner flex de gamma.dll (FUN_0042a4c0, vtable 0x4744c4 +0x14),
    * con sus tablas tal cual: yy_acclist DAT_004738d8, yy_accept
    * DAT_0047399c, yy_ec 0x473a30 (int), yy_meta DAT_00473e30 (int),
    * yy_base DAT_00473e98, yy_def DAT_00473f30, yy_nxt DAT_00473fc8,
    * yy_chk DAT_004740b4; estado inicial 1, base de atasco 0x5b, estados
    * &gt; 0x48 usan yy_meta. Acciones: 1 y 14 se saltan (comentario # hasta
    * fin de linea, blancos), 2 '=', 3..11 palabras clave, 12 un digito (fija
    * DAT_0049fe04 = atoi), 13 identificador (texto en DAT_0049eeb8), 15
    * cualquier otro caracter (token 0), 17 fin de buffer.
    */
   static final class Lexer {
      static final int EOF = -1;
      static final int EQUALS = 0x101;
      static final int VERSION = 0x102;
      static final int AVATAR = 0x103;
      static final int ENDAVATAR = 0x104;
      static final int BEGINIMP = 0x105;
      static final int ENDIMP = 0x106;
      static final int BEGINEXP = 0x107;
      static final int ENDEXP = 0x108;
      static final int NUMBER = 0x109;
      static final int IDENT = 0x10a;
      static final int BEGINCHANGEIMP = 0x10b;
      static final int ENDCHANGEIMP = 0x10c;

      private static final short[] ACCLIST = {
         0, 17, 15, 16, 14, 15, 16, 14, 16, 15, 16, 12, 13, 15, 16, 2, 15, 16, 13, 15,
         16, 13, 15, 16, 13, 15, 16, 13, 15, 16, 13, 15, 16, 14, 1, 13, 13, 13, 13, 13,
         13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 4, 13,
         13, 13, 13, 13, 13, 9, 13, 7, 13, 13, 13, 13, 13, 13, 13, 3, 13, 13, 8, 13,
         6, 13, 13, 13, 13, 5, 13, 13, 13, 13, 13, 13, 13, 11, 13, 13, 10, 13,
      };
      private static final short[] ACCEPT = {
         0, 1, 1, 1, 2, 4, 7, 9, 11, 15, 18, 21, 24, 27, 30, 33, 34, 34, 35, 36,
         37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
         57, 58, 60, 61, 62, 63, 64, 65, 67, 69, 70, 71, 72, 73, 74, 75, 77, 78, 80, 82,
         83, 84, 85, 87, 88, 89, 90, 91, 92, 93, 95, 96, 98, 98,
      };
      private static final short[] EC = {
         0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         2, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 7, 1, 1,
         1, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 1, 1, 1, 1, 8,
         1, 9, 10, 11, 12, 13, 8, 14, 15, 16, 8, 8, 8, 17, 18, 19, 20, 8, 21, 22, 23, 8, 24, 8, 25, 8, 8, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      };
      private static final short[] META = {
         0, 1, 1, 1, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
         2, 2, 2, 2, 2, 2,
      };
      private static final short[] BASE = {
         0, 0, 0, 90, 91, 24, 26, 86, 0, 91, 0, 64, 74, 68, 72, 28, 81, 91, 0, 74,
         68, 69, 59, 56, 62, 23, 55, 67, 57, 50, 58, 47, 54, 54, 48, 22, 59, 58, 46, 45,
         45, 0, 48, 37, 44, 37, 41, 0, 0, 40, 48, 36, 35, 45, 39, 0, 34, 0, 0, 30,
         37, 35, 0, 32, 34, 29, 29, 24, 26, 0, 22, 0, 91, 39, 35, 0,
      };
      private static final short[] DEF = {
         0, 72, 1, 72, 72, 72, 72, 73, 74, 72, 74, 74, 74, 74, 74, 72, 73, 72, 74, 74,
         74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74,
         74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74,
         74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 74, 0, 72, 72, 0,
      };
      private static final short[] NXT = {
         0, 4, 5, 6, 7, 4, 8, 9, 10, 11, 12, 10, 10, 13, 10, 10, 10, 10, 10, 10,
         10, 10, 10, 10, 14, 10, 15, 15, 15, 15, 15, 15, 29, 42, 30, 43, 31, 18, 44, 32,
         16, 16, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54,
         53, 52, 51, 50, 49, 48, 47, 46, 45, 41, 40, 39, 38, 37, 36, 35, 34, 33, 28, 27,
         26, 25, 24, 23, 17, 22, 21, 20, 19, 17, 72, 3, 72, 72, 72, 72, 72, 72, 72, 72,
         72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 0,
      };
      private static final short[] CHK = {
         0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 5, 5, 6, 6, 15, 15, 25, 35, 25, 35, 25, 74, 35, 25,
         73, 73, 70, 68, 67, 66, 65, 64, 63, 61, 60, 59, 56, 54, 53, 52, 51, 50, 49, 46,
         45, 44, 43, 42, 40, 39, 38, 37, 36, 34, 33, 32, 31, 30, 29, 28, 27, 26, 24, 23,
         22, 21, 20, 19, 16, 14, 13, 12, 11, 7, 3, 72, 72, 72, 72, 72, 72, 72, 72, 72,
         72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 0,
      };

      /** Texto con los dos NUL de fin de buffer de flex. */
      private final byte[] buf;
      private final int end;
      private int pos;
      /** param_1[3]: lineas, contando los '\n' del texto de cada accion. */
      int line = 1;
      /** DAT_0049eeb8 (hasta 0x3ff caracteres). */
      String text = "";
      /** DAT_0049fe04. */
      int version;

      Lexer(byte[] src, int start) {
         this.end = src.length;
         this.buf = new byte[src.length + 2];
         System.arraycopy(src, 0, this.buf, 0, src.length);
         this.pos = start;
      }

      /** Un paso de yy_match + yy_find_action desde pos; devuelve {accion, fin}. */
      private int[] match(int from, boolean atEnd) {
         int st = 1;
         int[] stack = new int[this.buf.length - from + 2];
         int sp = 0;
         stack[sp++] = st;
         int cp = from;
         if (!atEnd) {
            do {
               int c = EC[this.buf[cp] & 0xFF];
               while (CHK[BASE[st] + c] != st) {
                  st = DEF[st];
                  if (st > 0x48) {
                     c = META[c];
                  }
               }
               cp++;
               st = NXT[BASE[st] + c];
               stack[sp++] = st;
            } while (BASE[st] != 0x5b);
         } else {
            // EOB_ACT_LAST_MATCH (FUN_0042aa90 == 2): yy_get_previous_state
            // sobre el texto que queda, sin el NUL de fin de buffer.
            while (cp < this.end) {
               int c = EC[this.buf[cp] & 0xFF];
               while (CHK[BASE[st] + c] != st) {
                  st = DEF[st];
                  if (st > 0x48) {
                     c = META[c];
                  }
               }
               cp++;
               st = NXT[BASE[st] + c];
               stack[sp++] = st;
            }
         }
         st = stack[--sp];
         int lp = ACCEPT[st];
         while (lp == 0 || ACCEPT[st + 1] <= lp) {
            cp--;
            st = stack[--sp];
            lp = ACCEPT[st];
         }
         return new int[]{ACCLIST[lp], cp};
      }

      /** yylex: el siguiente token (codigos 0x101..0x10c, 0 o -1). */
      int next() {
         boolean atEnd = false;
         while (true) {
            if (this.pos >= this.end) {
               return EOF;
            }
            int[] m = this.match(this.pos, atEnd);
            int act = m[0];
            int e = m[1];
            String t = new String(this.buf, this.pos, Math.min(e, this.end) - this.pos, java.nio.charset.StandardCharsets.ISO_8859_1);
            if (act != 17) {
               for (int i = 0; i < t.length(); i++) {
                  if (t.charAt(i) == '\n') {
                     this.line++;
                  }
               }
            }
            switch (act) {
               case 1:
               case 14:
                  this.pos = e;
                  atEnd = false;
                  continue;
               case 2:
                  this.pos = e;
                  return EQUALS;
               case 3:
                  this.pos = e;
                  return VERSION;
               case 4:
                  this.pos = e;
                  return AVATAR;
               case 5:
                  this.pos = e;
                  return ENDAVATAR;
               case 6:
                  this.pos = e;
                  return BEGINIMP;
               case 7:
                  this.pos = e;
                  return ENDIMP;
               case 8:
                  this.pos = e;
                  return BEGINEXP;
               case 9:
                  this.pos = e;
                  return ENDEXP;
               case 10:
                  this.pos = e;
                  return BEGINCHANGEIMP;
               case 11:
                  this.pos = e;
                  return ENDCHANGEIMP;
               case 12:
                  this.pos = e;
                  this.version = atoi(t);
                  return NUMBER;
               case 13:
                  this.pos = e;
                  this.text = t.length() > 0x3ff ? t.substring(0, 0x3ff) : t;
                  return IDENT;
               case 15:
                  this.pos = e;
                  this.text = t;
                  return 0;
               case 16:
                  // ECHO: el original lo escribe por la salida del escaner.
                  this.pos = e;
                  continue;
               case 17:
                  // Fin de buffer: si quedaba texto sin casar se vuelve a
                  // casar sin el NUL (ultimo token); si no, fin de fichero.
                  if (e - this.pos <= 1 || atEnd) {
                     this.pos = this.end;
                     return EOF;
                  }
                  atEnd = true;
                  continue;
               default:
                  throw new ParseError("fatal flex scanner internal error--no action found", this.line);
            }
         }
      }

      ParseError unexpected(int tok) {
         return new ParseError("token inesperado 0x" + Integer.toHexString(tok) + " '" + this.text + "'", this.line);
      }

      /** atoi de la CRT (FUN_00454250): digitos decimales. */
      private static int atoi(String s) {
         int v = 0;
         for (int i = 0; i < s.length(); i++) {
            v = v * 10 + (s.charAt(i) - '0');
         }
         return v;
      }
   }
}
