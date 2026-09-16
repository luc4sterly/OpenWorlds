package net.freeworlds.avatar;

import java.util.Map;

/**
 * Decodificador del "lenguaje de nombre de avatar" de Worlds Chat.
 *
 * Port literal de NET/worlds/scape/PosableShape.java (Java pristino
 * decompilado). Un nombre de avatar es una URL
 * `avatar:<base>.0<programa>.rwg` donde `<programa>` es una secuencia de
 * tokens que construye el arbol de subpartes. Referencias:
 *
 * <pre>
 * createSubparts   PosableShape.java:1054-1111  cabecera + 17 limbs
 * findStarts       PosableShape.java:636-687    paleta + indice de limbs
 * getLimb          PosableShape.java:355-470    tokens dentro de una limb
 * scanTexture      PosableShape.java:248-258    T -> .cmp / .mov
 * readColor        PosableShape.java:294-315    C -> colorTable / RGB base64
 * getScale         PosableShape.java:329-335    S -> escala
 * scanBase64       PosableShape.java:289-292
 * addChange        PosableShape.java:472-492    cambios de material temporizados
 * bloque static    PosableShape.java:1318-1348  permittedHash/humanHash/faceTextures
 * </pre>
 *
 * Gramatica (reconstruida del codigo, no inventada):
 *
 * <pre>
 * URL      := "avatar:" base "." digito programa ".rwg"
 *             si el digito tras el punto no es '0', el nombre se busca en
 *             permittedHash y se sustituye por su valor
 *             (PosableShape.java:1059-1078)
 * programa := limb*
 * limb     := LETRA_MAYUSCULA token*     (la letra se apunta en starts[])
 * token    := 'G' int nombre     cambia el .bod del nodo actual
 *           | 'S' c c c          escala (x,y,z); "SZZZ" ademas desactiva prepFigure
 *           | 'Q'                no-op (separador; findStarts lo reutiliza
 *                                como prefijo de las referencias de paleta)
 *           | 'D' base64         retardo para el siguiente cambio de material
 *           | 'A' nombre         nombre de animacion
 *           | 'T' int nombre     define material-textura (va a la paleta)
 *           | 'C' color          define material-color (va a la paleta)
 *           | [a-z]              referencia a paleta: material del nodo actual
 *           | [0-9]+             crea un subclump y pasa a ser el nodo actual
 * </pre>
 *
 * Los tokens `T` y `C` NO se resuelven dentro de la limb: findStarts los
 * recoge en orden global en una paleta y los sustituye en la cadena por
 * `Q<letra>` (PosableShape.java:644-661), asi que cuando getLimb recorre
 * la limb solo ve referencias `[a-z]`.
 */
public final class AvatarNameDecoder {
   public static final String BASE64 = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+";

   /** PosableShape.colorTable (PosableShape.java:37-65), 26 entradas. */
   public static final int[][] COLOR_TABLE = {
      {0, 0, 0}, {51, 102, 204}, {234, 162, 115}, {255, 102, 51}, {255, 153, 204}, {139, 232, 0},
      {43, 131, 0}, {51, 51, 153}, {145, 51, 204}, {153, 204, 255}, {204, 51, 102}, {0, 204, 102},
      {255, 204, 102}, {102, 102, 102}, {254, 123, 26}, {255, 51, 153}, {188, 51, 204}, {204, 0, 38},
      {118, 0, 0}, {153, 102, 51}, {196, 196, 196}, {204, 153, 255}, {255, 255, 255}, {255, 179, 2},
      {247, 227, 2}, {255, 255, 153}
   };

   /**
    * Tabla de limbs de createSubparts (PosableShape.java:1094-1110):
    * {letra, tag, indice del padre en esta misma tabla; -1 = el PosableShape}.
    */
   public static final Object[][] LIMBS = {
      {'P', 1, -1}, {'B', 2, 0}, {'N', 3, 1}, {'H', 4, 2},
      {'L', 11, 1}, {'M', 12, 4}, {'O', 13, 5},
      {'R', 6, 1}, {'U', 7, 7}, {'V', 8, 8},
      {'I', 19, 0}, {'J', 20, 10}, {'K', 21, 11},
      {'W', 15, 0}, {'X', 16, 13}, {'Y', 17, 14},
      {'Z', 24, 0}
   };

   /** URL por defecto del cliente (PosableShape.java:34). */
   public static final String DEFAULT_URL = "avatar:aura.0PG.rwg";

   private final Map<String, String> permittedHash;
   private final AvatarFigure fig = new AvatarFigure();
   private int scanPos;

   private AvatarNameDecoder(Map<String, String> permittedHash) {
      this.permittedHash = permittedHash;
   }

   /** Excepcion equivalente al MalformedURLException que lanza createSubparts. */
   public static final class NombreInvalido extends RuntimeException {
      public NombreInvalido(String msg) {
         super(msg);
      }
   }

   public static AvatarFigure decode(String url, Map<String, String> permittedHash) {
      return new AvatarNameDecoder(permittedHash).run(url);
   }

   // ------------------------------------------------------------------
   // createSubparts (PosableShape.java:1054-1111)
   // ------------------------------------------------------------------
   private AvatarFigure run(String url) {
      fig.urlPedida = url;
      String s = url;
      String base;
      if (s.startsWith("avatar:") && (s.endsWith(".rwg") || s.endsWith(".RWG")) && s.charAt(7) != '.') {
         scanPos = s.indexOf(".", 7);
         base = s.substring(7, scanPos).toLowerCase();
         if (s.charAt(scanPos + 1) != '0') {
            // Nombre "corto": solo vale si esta en permittedList.
            scanPos = s.length() - 4;
            String coded = permittedHash.get(base);
            if (coded != null) {
               s = coded;
               scanPos = 0;
               base = scanName(s);
               if (s.charAt(scanPos) != '.') {
                  throw new NombreInvalido("falta '.' tras el nombre en permittedList: " + coded);
               }
               if (s.charAt(scanPos + 1) != '0') {
                  throw new NombreInvalido("el nombre de permittedList no empieza por '.0': " + coded);
               }
               scanPos += 2;
               fig.desdePermittedList = true;
            }
         } else {
            scanPos += 2;
         }
      } else {
         // Rama de fallback: avatar aura sin programa (PosableShape.java:1081-1084).
         scanPos = 0;
         s = ".rwg";
         base = "aura";
      }

      fig.cadena = s;
      fig.base = base;
      s = findStarts(s, s.length() - 4, base);
      fig.cadenaReescrita = s;

      AvatarPart[] creadas = new AvatarPart[LIMBS.length];
      AvatarPart[] devueltas = new AvatarPart[LIMBS.length];
      for (int i = 0; i < LIMBS.length; i++) {
         char letra = (Character) LIMBS[i][0];
         int tag = (Integer) LIMBS[i][1];
         int padreIdx = (Integer) LIMBS[i][2];
         AvatarPart padre = padreIdx < 0 ? null : devueltas[padreIdx];
         char letraPadre = padreIdx < 0 ? '*' : (Character) LIMBS[padreIdx][0];
         // La raiz recibe el nombre base explicito; el resto lo hereda del padre (null).
         String baseArg = padreIdx < 0 ? base : null;
         AvatarPart p = getLimb(s, baseArg, fig.arranques[letra - 'A'], tag, padre, letra, letraPadre);
         creadas[i] = p;
         devueltas[i] = p.adjunta ? p : padre;
         fig.partes.add(p);
      }

      for (char c = 'A'; c <= 'Z'; c++) {
         if (fig.arranques[c - 'A'] > 0 && !esLimbUsada(c)) {
            fig.letrasNoUsadas.add(c);
         }
      }
      return fig;
   }

   private static boolean esLimbUsada(char c) {
      for (Object[] l : LIMBS) {
         if ((Character) l[0] == c) {
            return true;
         }
      }
      return false;
   }

   // ------------------------------------------------------------------
   // findStarts (PosableShape.java:636-687)
   // ------------------------------------------------------------------
   private String findStarts(String s, int end, String base) {
      String ultimoNombre = base;
      while (scanPos < end) {
         char c = s.charAt(scanPos);
         if (c < 'A' || c > 'Z') {
            return s;
         }
         fig.arranques[c - 'A'] = scanPos++;

         while (scanPos < end) {
            char t = s.charAt(scanPos++);
            if (t < 'A' || t > 'Z') {
               if ((t < '0' || t > '9') && (t < 'a' || t > 'z')) {
                  // Caracter fuera del alfabeto: el cliente trunca aqui.
                  fig.anomalias.add("caracter '" + t + "' en la posicion " + (scanPos - 1)
                        + ": findStarts trunca el nombre");
                  return s.substring(0, scanPos - 1) + ".rwg";
               }
            } else if (t == 'G') {
               scanInt(s);
               scanName(s);
            } else if (t == 'S') {
               scanPos += 3;
            } else if (t != 'Q') {
               if (t == 'C' || t == 'T') {
                  int tokenPos = scanPos - 1;
                  int idx = fig.paleta.size();
                  AvatarMaterial mat;
                  if (t == 'C') {
                     mat = scanColor(s, idx, tokenPos);
                  } else {
                     int n = scanInt(s);
                     String nombre = scanName(s);
                     if (nombre.isEmpty()) {
                        nombre = ultimoNombre;   // hereda el ultimo nombre visto
                     } else {
                        ultimoNombre = nombre;
                     }
                     mat = AvatarMaterial.texture(idx, tokenPos, s.substring(tokenPos, scanPos), n, nombre);
                  }
                  fig.paleta.add(mat);
                  // Sustitucion en la cadena: el token entero pasa a ser "Q<letra>".
                  s = s.substring(0, tokenPos) + 'Q' + (char) (97 + idx) + s.substring(scanPos);
                  int delta = scanPos - tokenPos - 2;
                  scanPos -= delta;
                  end -= delta;
               } else if (t == 'D') {
                  scanPos++;
               } else if (t != 'A') {
                  scanPos--;
                  break;    // letra de limb: vuelve al bucle externo
               } else {
                  scanName(s);
               }
            }
         }
      }
      return s;
   }

   // ------------------------------------------------------------------
   // getLimb (PosableShape.java:355-470)
   // ------------------------------------------------------------------
   private AvatarPart getLimb(String s, String base, int start, int tag, AvatarPart padre, char letra, char letraPadre) {
      int end = s.length() - 4;
      if (base == null) {
         if (padre == null) {
            base = "";      // el padre es el propio PosableShape
         } else {
            base = getBodBase(padre.bodUrl());
            if (padre.bodUrl().indexOf("lod/") != -1) {
               base = "lod/" + base;
            }
         }
      }

      AvatarPart part = new AvatarPart(letra, tag, letraPadre);
      AvatarPart.Nodo limb = new AvatarPart.Nodo("limb", "avatar:" + base + tag / 10 + tag % 10 + ".bod");
      part.nodos.add(limb);
      AvatarPart.Nodo actual = limb;

      int nSubclumps = 0;
      AvatarMaterial anterior = null;
      int retardo = 0;
      int acumulado = 0;
      boolean primerCambio = false;
      boolean gVacio = false;

      if (start > 0) {
         scanPos = start + 1;
         while (true) {
            char c = s.charAt(scanPos++);
            if (c >= 'A' && c <= 'Z') {
               if (c == 'G') {
                  int n = scanInt(s);
                  if (n <= 0 || n > 99) {
                     n = tag;
                  }
                  base = scanName(s);
                  if (base.isEmpty()) {
                     gVacio = true;
                     break;      // G sin nombre: la limb se descarta entera
                  }
                  actual.url = "avatar:" + base + n / 10 + n % 10 + ".bod";
               } else if (c == 'S') {
                  char sx = s.charAt(scanPos++);
                  char sy = s.charAt(scanPos++);
                  char sz = s.charAt(scanPos++);
                  if (sx == 'Z' && sy == 'Z' && sz == 'Z') {
                     fig.prepFigure = false;
                  }
                  actual.escalaX *= getScale(sx);
                  actual.escalaY *= getScale(sy);
                  actual.escalaZ *= getScale(sz);
               } else if (c != 'Q') {
                  if (c == 'C') {
                     // Debug.assert_(false): no deberia quedar ninguna C tras findStarts.
                     fig.anomalias.add("limb " + letra + ": token 'C' residual en la posicion " + (scanPos - 1));
                  } else if (c == 'D') {
                     retardo += (int) (1000.0 * (Math.pow(1.0932, scanBase64(s.charAt(scanPos++))) - 0.9F));
                  } else if (c == 'A') {
                     part.animacion = scanName(s);
                  } else if (c == 'T') {
                     // System.out.println("Illegal av ...") en el original.
                     fig.anomalias.add("limb " + letra + ": token 'T' residual en la posicion " + (scanPos - 1)
                           + " (el cliente imprime \"Illegal av\")");
                  } else {
                     scanPos--;
                     break;      // otra letra de limb
                  }
               }
            } else if (c >= 'a') {
               AvatarMaterial mat = getMat(c);
               if (mat != null) {
                  if (retardo == 0) {
                     retardo = 50;
                  }
                  acumulado += retardo;
                  if (anterior != null) {
                     if (!primerCambio) {
                        primerCambio = true;
                        actual.cambios.add(new AvatarPart.Cambio(acumulado - retardo, anterior.index));
                     }
                     actual.cambios.add(new AvatarPart.Cambio(acumulado, mat.index));
                  }
                  actual.materiales.add(mat.index);
                  if (!mat.origMat) {
                     actual.material = mat.index;
                  }
                  anterior = mat;
                  retardo = 0;
               } else {
                  fig.anomalias.add("limb " + letra + ": referencia de paleta '" + c + "' fuera de rango en la posicion "
                        + (scanPos - 1) + " (paleta de " + fig.paleta.size() + ")");
               }
            } else {
               if (c < '0' || c > '9') {
                  break;
               }
               scanPos--;
               int absoluto = scanInt(s);
               int n = absoluto - nSubclumps;
               nSubclumps++;
               actual = new AvatarPart.Nodo("subclump " + absoluto, "system:subclump" + n);
               actual.subAbsoluto = absoluto;
               actual.subRelativo = n;
               part.nodos.add(actual);
               anterior = null;
               primerCambio = false;
               acumulado = 0;
               retardo = 0;
            }

            if (scanPos > end) {
               scanPos = end;
               part.adjunta = false;
               part.motivoDescarte = "el programa se desborda mas alla del final del nombre";
               part.base = base;
               return part;
            }
         }
      }

      part.base = base;
      if (base.isEmpty()) {
         part.adjunta = false;
         part.motivoDescarte = gVacio
               ? "token G sin nombre: getLimb devuelve el padre"
               : "sin nombre base (el padre es el PosableShape o una limb descartada)";
         return part;
      }
      part.adjunta = true;
      return part;
   }

   /** Shape.getBodBase (Shape.java:270-274). */
   private static String getBodBase(String url) {
      String name = url.startsWith("avatar:") ? url.substring(7) : url;
      return name.endsWith(".bod") && name.length() >= 6 ? name.substring(0, name.length() - 6) : null;
   }

   // ------------------------------------------------------------------
   // Escaneres elementales
   // ------------------------------------------------------------------

   /** scanName (PosableShape.java:210-219): [a-z_]*. */
   private String scanName(String s) {
      int start = scanPos;
      char c;
      while (scanPos < s.length() && ((c = s.charAt(scanPos)) >= 'a' && c <= 'z' || c == '_')) {
         scanPos++;
      }
      return s.substring(start, scanPos);
   }

   /** scanInt (PosableShape.java:237-247). */
   private int scanInt(String s) {
      int v = 0;
      char c;
      while (scanPos < s.length() && (c = s.charAt(scanPos)) >= '0' && c <= '9') {
         v = 10 * v + (c - '0');
         scanPos++;
      }
      return v;
   }

   /** scanBase64 (PosableShape.java:289-292). */
   public static int scanBase64(char c) {
      int i = BASE64.indexOf(c);
      return i < 0 ? 0 : i;
   }

   /** getScale (PosableShape.java:329-335). */
   public static float getScale(char c) {
      if (c >= 'a' && c <= 'z') {
         return 1.0F - (c - 'a' + 1) * 0.025615385F;
      }
      return c >= 'A' && c <= 'Z' ? 1.0F / (1.0F - (c - 'A' + 1) * 0.025615385F) : 1.0F;
   }

   /** readColor + scanColor (PosableShape.java:294-326). */
   private AvatarMaterial scanColor(String s, int idx, int tokenPos) {
      int p = scanPos;
      char c = s.charAt(p++);
      AvatarMaterial mat;
      if (c == '_') {
         int i = s.charAt(p++) - 'A';
         if (i >= 0 && i < COLOR_TABLE.length) {
            mat = AvatarMaterial.color(idx, tokenPos, s.substring(tokenPos, p),
                  COLOR_TABLE[i][0], COLOR_TABLE[i][1], COLOR_TABLE[i][2], true, i, false);
         } else {
            mat = AvatarMaterial.color(idx, tokenPos, s.substring(tokenPos, p), -1, -1, -1, true, i, true);
         }
         scanPos += 2;
      } else {
         int r = 4 * scanBase64(c);
         int g = 4 * scanBase64(s.charAt(p++));
         int b = 4 * scanBase64(s.charAt(p++));
         mat = AvatarMaterial.color(idx, tokenPos, s.substring(tokenPos, p), r, g, b, false, -1, false);
         scanPos += 3;
      }
      return mat;
   }

   /** getMat (PosableShape.java:337-345). */
   private AvatarMaterial getMat(char c) {
      int i = c - 'a';
      return i < fig.paleta.size() ? fig.paleta.get(i) : null;
   }
}
