package NET.worlds.core;

import java.io.ByteArrayOutputStream;

/**
 * Console.encrypt (0x0040b7f0) / Console.decrypt (0x0040bb00) de gamma.dll:
 * el cifrado de la contrasena que el LoginWizard guarda en worlds.ini
 * ("Remember password": Console.encode pasa el resultado a hexadecimal).
 *
 * <p>Formato (leido del C decompilado y comprobado en el desensamblado):
 * <pre>
 *   b[0] = sal = XOR de los 4 bytes de timeGetTime()
 *   b[1] = longitud (strlen de GetStringUTFChars, tope 0xff)
 *   b[2..] = los bytes UTF-8 modificados de la contrasena (strcpy 0x0044d6b0)
 *   relleno con 0 hasta un multiplo de 3 bytes
 *   clave[k] = byte k (little endian) de DAT_0049fa6c ^ sal
 *   b[j] ^= clave[(j-1) % 4] para j = 1..n-1 (el byte de sal va en claro)
 *   cada 3 bytes v = b0<<16|b1<<8|b2 -> 4 caracteres ((v>>18)&63)+0x20,
 *   ((v>>12)&63)+0x20, ((v>>6)&63)+0x20, (v&63)+0x20
 * </pre>
 * DAT_0049fa6c es el numero de serie del volumen que escribe
 * Startup.computeVolumeInfo (0x00409e80, GetVolumeInformationA): la
 * contrasena guardada solo se descifra en el mismo disco. Aqui lo da
 * {@link NativeUiStartup#volumeInfo()}.
 *
 * <p>decrypt deshace los grupos de 4 (un grupo incompleto al final cuenta
 * como si los caracteres que faltan valieran 0x20, con el mismo
 * desplazamiento), aplica la misma XOR y valida la longitud: si no esta
 * entre n-4 y n-2 (n = bytes decodificados) la contrasena sale vacia. El
 * resultado es NewStringUTF de b[2..2+len), que corta en el primer 0.
 */
public final class NativeUiConsole {
   private NativeUiConsole() {
   }

   /** Tamano de los bufferes de pila: local_278[260] (encrypt), local_118[260] (decrypt). */
   static final int STACK_BUF = 260;

   /** GetStringUTFChars: UTF-8 modificado (U+0000 como C0 80, sustitutos por separado). */
   static byte[] modifiedUtf8(String s) {
      ByteArrayOutputStream o = new ByteArrayOutputStream();
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         if (c >= 1 && c <= 0x7f) {
            o.write(c);
         } else if (c <= 0x7ff) {
            o.write(0xc0 | (c >> 6));
            o.write(0x80 | (c & 0x3f));
         } else {
            o.write(0xe0 | (c >> 12));
            o.write(0x80 | ((c >> 6) & 0x3f));
            o.write(0x80 | (c & 0x3f));
         }
      }
      return o.toByteArray();
   }

   /**
    * NewStringUTF: decodifica UTF-8 modificado hasta el primer 0.
    * ⚠️ VERIFICAR: con una secuencia mal formada (solo posible si el
    * ini se edito a mano o se descifra con otra clave) HotSpot no esta
    * especificado; aqui un byte suelto se toma como Latin-1.
    */
   static String fromModifiedUtf8(byte[] b, int off, int len) {
      StringBuilder sb = new StringBuilder();
      int i = off;
      int end = off + len;
      while (i < end && b[i] != 0) {
         int c = b[i] & 0xff;
         if (c < 0x80) {
            sb.append((char) c);
            i++;
         } else if ((c & 0xe0) == 0xc0 && i + 1 < end && (b[i + 1] & 0xc0) == 0x80) {
            sb.append((char) (((c & 0x1f) << 6) | (b[i + 1] & 0x3f)));
            i += 2;
         } else if ((c & 0xf0) == 0xe0 && i + 2 < end && (b[i + 1] & 0xc0) == 0x80 && (b[i + 2] & 0xc0) == 0x80) {
            sb.append((char) (((c & 0x0f) << 12) | ((b[i + 1] & 0x3f) << 6) | (b[i + 2] & 0x3f)));
            i += 3;
         } else {
            sb.append((char) c);
            i++;
         }
      }
      return sb.toString();
   }

   /** La clave de 4 bytes: bytes de DAT_0049fa6c (little endian) XOR sal. */
   static byte[] key(int volume, int salt) {
      byte[] k = new byte[4];
      for (int i = 0; i < 4; i++) {
         k[i] = (byte) ((volume >>> (8 * i)) ^ salt);
      }
      return k;
   }

   /** Parte determinista de 0x0040b7f0: sal y serie de volumen explicitos. */
   public static String encrypt(String plain, int salt, int volume) {
      byte[] src = modifiedUtf8(plain);
      // strcpy en local_278+2 y strlen con tope 0xff (0x0040b83b..)
      int len = Math.min(src.length, 0xff);
      byte[] b = new byte[STACK_BUF];
      b[0] = (byte) salt;
      b[1] = (byte) len;
      System.arraycopy(src, 0, b, 2, len);
      int n = len + 2;
      while (n % 3 != 0) {
         b[n++] = 0;
      }
      byte[] k = key(volume, salt & 0xff);
      for (int i = 0; i < n - 1; i++) {
         b[i + 1] ^= k[i % 4];
      }
      StringBuilder out = new StringBuilder();
      for (int i = 0; i < n; i += 3) {
         int v = (b[i] & 0xff) << 16 | (b[i + 1] & 0xff) << 8 | (b[i + 2] & 0xff);
         out.append((char) ((v >> 18) + 0x20));
         out.append((char) (((v >> 12) & 0x3f) + 0x20));
         out.append((char) (((v >> 6) & 0x3f) + 0x20));
         out.append((char) ((v & 0x3f) + 0x20));
      }
      return out.toString();
   }

   /** Parte determinista de 0x0040bb00 con la serie de volumen explicita. */
   public static String decrypt(String cipher, int volume) {
      byte[] s = modifiedUtf8(cipher);
      // bufer de salida sin tope en el original (local_118, 260 bytes, y
      // detras la clave y la pila): una cadena de mas de 346 caracteres lo
      // desbordaria. Aqui el bufer crece; ⚠️ no se reproduce ese fallo.
      byte[] b = new byte[Math.max(STACK_BUF, (s.length + 3) / 4 * 3 + 3)];
      int p = 0;
      int n = 0;
      while (p < s.length) {
         int v = ((s[p++] & 0xff) - 0x20) * 0x40;
         if (p < s.length) {
            v += (s[p++] & 0xff) - 0x20;
         }
         v *= 0x40;
         if (p < s.length) {
            v += (s[p++] & 0xff) - 0x20;
         }
         v *= 0x40;
         if (p < s.length) {
            v += (s[p++] & 0xff) - 0x20;
         }
         b[n + 2] = (byte) v;
         b[n + 1] = (byte) (v >> 8);
         b[n] = (byte) (v >> 16);
         n += 3;
      }
      // con la cadena vacia la sal (local_118) queda sin inicializar, pero la
      // comprobacion de longitud (n-2 = -2 < len) deja la salida vacia igual
      byte[] k = key(volume, b[0] & 0xff);
      for (int i = 0; i < n - 1; i++) {
         b[i + 1] ^= k[i % 4];
      }
      int len = b[1] & 0xff;
      if (n - 2 < len || len + 2 < n - 2) {
         len = 0;
      }
      return fromModifiedUtf8(b, 2, len);
   }

   /** Console.encrypt (0x0040b7f0): sal de timeGetTime (reloj de NativeInput, GetTickCount). */
   public static String encrypt(String plain) {
      int t = NativeInput.tick();
      int salt = (t ^ (t >> 8) ^ (t >> 16) ^ (t >> 24)) & 0xff;
      return encrypt(plain, salt, NativeUiStartup.volumeInfo());
   }

   /** Console.decrypt (0x0040bb00). */
   public static String decrypt(String cipher) {
      return decrypt(cipher, NativeUiStartup.volumeInfo());
   }
}
