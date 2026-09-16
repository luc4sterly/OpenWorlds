package net.freeworlds.avatar;

/**
 * Un material de la paleta que `findStarts` va acumulando al recorrer el
 * nombre codificado (PosableShape.java:636-687). Cada token `T`/`C` crea
 * uno y es sustituido en la cadena por `Q<letra>`, donde la letra es
 * `(char)(97 + paleta.size())` (PosableShape.java:646).
 *
 * Dos sabores:
 * - TEXTURA (`T<n><nombre>`): PosableShape.scanTexture
 *   (PosableShape.java:248-258) construye
 *     n <= 0 -> "avatar:<nombre>.cmp"
 *     n >  0 -> "avatar:<nombre><n>s*.mov"
 *   con Material(0.32f, 0.55f, 0.0f, colorTable[3], null, 1.0f, true, false).
 *   El "s*" NO es parte del nombre de fichero: Material.calcRes
 *   (Material.java:265-296) lo interpreta como selector de subimagen y
 *   Material.loadTextures (Material.java:298-325) carga realmente
 *   "<nombre>.mov" usando el fotograma sPos = n-1.
 * - COLOR (`C...`): PosableShape.readColor (PosableShape.java:294-315)
 *     '_' + letra -> colorTable[letra-'A'] (26 entradas,
 *                    PosableShape.java:37-65); fuera de rango -> origMat
 *     3 chars base64 -> RGB = 4*base64(c) cada componente
 *   base64 = "-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+"
 *   (PosableShape.java:69).
 */
public final class AvatarMaterial {
   public enum Kind { TEXTURA, COLOR }

   /** Indice en la paleta; la referencia en la cadena es (char)('a' + index). */
   public final int index;
   public final Kind kind;
   /** Posicion (offset de caracter) del token original dentro del nombre. */
   public final int tokenPos;
   /** Token tal y como aparece en el nombre original (p.ej. "T4_dtbwa", "C__"). */
   public final String token;

   // --- solo TEXTURA ---
   /** El entero que precede al nombre en `T<n><nombre>` (scanInt). */
   public final int textureNumber;
   /** El nombre escaneado (scanName: [a-z_]*), o el heredado si venia vacio. */
   public final String textureName;
   /** URL tal cual la construye scanTexture. */
   public final String textureUrl;
   /** Fichero real que carga Material.loadTextures. */
   public final String textureFile;
   /** Subimagen dentro del .mov (sPos = n-1); -1 para .cmp. */
   public final int textureSubIndex;

   // --- solo COLOR ---
   public final int r;
   public final int g;
   public final int b;
   /** true si el color venia de colorTable (forma '_' + letra). */
   public final boolean fromColorTable;
   public final int colorTableIndex;
   /** true si readColor devolvio origMat (indice de paleta fuera de rango). */
   public final boolean origMat;

   private AvatarMaterial(int index, Kind kind, int tokenPos, String token, int textureNumber, String textureName,
         String textureUrl, String textureFile, int textureSubIndex, int r, int g, int b, boolean fromColorTable,
         int colorTableIndex, boolean origMat) {
      this.index = index;
      this.kind = kind;
      this.tokenPos = tokenPos;
      this.token = token;
      this.textureNumber = textureNumber;
      this.textureName = textureName;
      this.textureUrl = textureUrl;
      this.textureFile = textureFile;
      this.textureSubIndex = textureSubIndex;
      this.r = r;
      this.g = g;
      this.b = b;
      this.fromColorTable = fromColorTable;
      this.colorTableIndex = colorTableIndex;
      this.origMat = origMat;
   }

   static AvatarMaterial texture(int index, int tokenPos, String token, int number, String name) {
      String url;
      String file;
      int sub;
      if (number <= 0) {
         url = "avatar:" + name + ".cmp";
         file = name + ".cmp";
         sub = -1;
      } else {
         url = "avatar:" + name + number + "s*.mov";
         file = name + ".mov";
         sub = number - 1;
      }
      return new AvatarMaterial(index, Kind.TEXTURA, tokenPos, token, number, name, url, file, sub,
            -1, -1, -1, false, -1, false);
   }

   static AvatarMaterial color(int index, int tokenPos, String token, int r, int g, int b, boolean fromTable,
         int tableIndex, boolean origMat) {
      return new AvatarMaterial(index, Kind.COLOR, tokenPos, token, 0, null, null, null, -1,
            r, g, b, fromTable, tableIndex, origMat);
   }

   /** Letra con la que se referencia este material en el nombre reescrito. */
   public char ref() {
      return (char) ('a' + index);
   }

   @Override
   public String toString() {
      if (kind == Kind.TEXTURA) {
         return ref() + "=" + token + " -> " + textureUrl
               + " [fichero " + textureFile + (textureSubIndex >= 0 ? ", subimagen " + textureSubIndex : "") + "]";
      }
      if (origMat) {
         return ref() + "=" + token + " -> origMat (indice de colorTable fuera de rango)";
      }
      String src = fromColorTable ? "colorTable[" + colorTableIndex + "]" : "base64 RGB";
      return ref() + "=" + token + " -> color " + src + " rgb(" + r + "," + g + "," + b + ")";
   }
}
