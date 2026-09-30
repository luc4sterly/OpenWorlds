package NET.worlds.core;

import java.io.ByteArrayOutputStream;

/**
 * gamma.dll's Console.encrypt (0x0040b7f0) / Console.decrypt (0x0040bb00):
 * the encryption of the password that the LoginWizard stores in worlds.ini
 * ("Remember password": Console.encode converts the result to hexadecimal).
 *
 * <p>Format (read from the decompiled C and checked in the disassembly):
 * <pre>
 *   b[0] = salt = XOR of the 4 bytes of timeGetTime()
 *   b[1] = length (strlen of GetStringUTFChars, capped at 0xff)
 *   b[2..] = the password's modified UTF-8 bytes (strcpy 0x0044d6b0)
 *   padded with 0 up to a multiple of 3 bytes
 *   key[k] = byte k (little endian) of DAT_0049fa6c ^ salt
 *   b[j] ^= key[(j-1) % 4] for j = 1..n-1 (the salt byte is in the clear)
 *   every 3 bytes v = b0<<16|b1<<8|b2 -> 4 characters ((v>>18)&63)+0x20,
 *   ((v>>12)&63)+0x20, ((v>>6)&63)+0x20, (v&63)+0x20
 * </pre>
 * DAT_0049fa6c is the volume serial number written by
 * Startup.computeVolumeInfo (0x00409e80, GetVolumeInformationA): the
 * stored password can only be decrypted on the same disk. Here it is
 * provided by {@link NativeUiStartup#volumeInfo()}.
 *
 * <p>decrypt undoes the groups of 4 (an incomplete group at the end counts
 * as if the missing characters were worth 0x20, with the same
 * shift), applies the same XOR and validates the length: if it is not
 * between n-4 and n-2 (n = decoded bytes) the password comes out empty. The
 * result is NewStringUTF of b[2..2+len), which cuts at the first 0.
 */
public final class NativeUiConsole {
   private NativeUiConsole() {
   }

   /** Size of the stack buffers: local_278[260] (encrypt), local_118[260] (decrypt). */
   static final int STACK_BUF = 260;

   /** GetStringUTFChars: modified UTF-8 (U+0000 as C0 80, surrogates separately). */
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
    * NewStringUTF: decodes modified UTF-8 up to the first 0.
    * ⚠️ VERIFY: with a malformed sequence (only possible if the
    * ini was edited by hand or decrypted with another key) HotSpot's behavior
    * is not specified; here a stray byte is taken as Latin-1.
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

   /** The 4-byte key: bytes of DAT_0049fa6c (little endian) XOR salt. */
   static byte[] key(int volume, int salt) {
      byte[] k = new byte[4];
      for (int i = 0; i < 4; i++) {
         k[i] = (byte) ((volume >>> (8 * i)) ^ salt);
      }
      return k;
   }

   /** Deterministic part of 0x0040b7f0: explicit salt and volume serial. */
   public static String encrypt(String plain, int salt, int volume) {
      byte[] src = modifiedUtf8(plain);
      // strcpy into local_278+2 and strlen capped at 0xff (0x0040b83b..)
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

   /** Deterministic part of 0x0040bb00 with the explicit volume serial. */
   public static String decrypt(String cipher, int volume) {
      byte[] s = modifiedUtf8(cipher);
      // uncapped output buffer in the original (local_118, 260 bytes, and
      // behind it the key and the stack): a string of more than 346
      // characters would overflow it. Here the buffer grows; ⚠️ that fault is
      // not reproduced.
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
      // with the empty string the salt (local_118) is left uninitialized, but
      // the length check (n-2 = -2 < len) leaves the output empty anyway
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

   /** Console.encrypt (0x0040b7f0): salt from timeGetTime (NativeInput's clock, GetTickCount). */
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
