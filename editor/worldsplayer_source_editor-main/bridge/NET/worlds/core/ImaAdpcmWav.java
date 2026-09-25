package NET.worlds.core;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.file.Files;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;

/**
 * WAV IMA ADPCM (WAVE_FORMAT_IMA_ADPCM = 0x11). PlaySound y MCI "waveaudio"
 * lo reproducian en Windows a traves del codec ACM del sistema
 * (imaadp32.acm); el JDK no trae ese codec. Es el caso de
 * GroundZero/wav/S.wav, el unico WAV comprimido de la instalacion (los otros
 * dos son PCM). Decodificador IMA/DVI estandar: tablas de indice y de paso
 * de la recomendacion IMA de 1992, bloques con cabecera de 4 bytes por canal
 * (muestra inicial int16, indice de paso) y nibbles bajos primero; en
 * estereo, grupos de 4 bytes (8 muestras) alternando canales. La cuenta de
 * muestras del chunk "fact" recorta el ultimo bloque.
 */
public final class ImaAdpcmWav {
   private ImaAdpcmWav() {
   }

   static final int[] INDEX_TABLE = new int[]{-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8};
   static final int[] STEP_TABLE = new int[]{
      7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 130, 143, 157, 173,
      190, 209, 230, 253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796, 876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
      2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899, 15289, 16818,
      18500, 20350, 22385, 24623, 27086, 29794, 32767
   };

   /** Estado de un canal: prediccion y indice de paso. */
   public static final class Channel {
      public int predictor;
      public int index;

      public Channel(int predictor, int index) {
         this.predictor = predictor;
         this.index = index;
      }

      /** Decodifica un nibble y devuelve la muestra de 16 bits. */
      public int decode(int nibble) {
         int step = STEP_TABLE[this.index];
         int diff = step >> 3;
         if ((nibble & 1) != 0) {
            diff += step >> 2;
         }

         if ((nibble & 2) != 0) {
            diff += step >> 1;
         }

         if ((nibble & 4) != 0) {
            diff += step;
         }

         this.predictor += (nibble & 8) != 0 ? -diff : diff;
         this.predictor = Math.max(-32768, Math.min(32767, this.predictor));
         this.index = Math.max(0, Math.min(88, this.index + INDEX_TABLE[nibble & 15]));
         return this.predictor;
      }
   }

   /** Formato 0x11 segun la cabecera RIFF, o false. */
   public static boolean isImaAdpcm(File f) {
      try {
         byte[] d = Files.readAllBytes(f.toPath());
         ByteBuffer fmt = chunk(d, "fmt ");
         return fmt != null && (fmt.getShort(0) & 0xFFFF) == 0x11;
      } catch (IOException e) {
         return false;
      }
   }

   private static ByteBuffer chunk(byte[] d, String id) {
      if (d.length < 12 || d[0] != 'R' || d[1] != 'I' || d[2] != 'F' || d[3] != 'F') {
         return null;
      }

      ByteBuffer b = ByteBuffer.wrap(d).order(ByteOrder.LITTLE_ENDIAN);
      int p = 12;
      while (p + 8 <= d.length) {
         String cid = new String(d, p, 4, java.nio.charset.StandardCharsets.ISO_8859_1);
         int len = b.getInt(p + 4);
         if (len < 0 || p + 8 + len > d.length) {
            len = d.length - p - 8;
         }

         if (cid.equals(id)) {
            return ByteBuffer.wrap(d, p + 8, len).slice().order(ByteOrder.LITTLE_ENDIAN);
         }

         p += 8 + len + (len & 1);
      }

      return null;
   }

   /** Decodifica el fichero entero a PCM 16 bits con signo, little-endian. */
   public static AudioInputStream open(File f) throws IOException {
      byte[] d = Files.readAllBytes(f.toPath());
      ByteBuffer fmt = chunk(d, "fmt ");
      ByteBuffer data = chunk(d, "data");
      if (fmt == null || data == null || (fmt.getShort(0) & 0xFFFF) != 0x11) {
         throw new IOException("no es un WAV IMA ADPCM: " + f);
      }

      int ch = fmt.getShort(2) & 0xFFFF;
      int rate = fmt.getInt(4);
      int blockAlign = fmt.getShort(12) & 0xFFFF;
      int bits = fmt.getShort(14) & 0xFFFF;
      if (bits != 4 || ch < 1 || ch > 2 || blockAlign < 4 * ch) {
         throw new IOException("IMA ADPCM no soportado (" + ch + " canales, " + bits + " bits): " + f);
      }

      int spb = (blockAlign - 4 * ch) * 8 / (4 * ch) + 1;
      if (fmt.limit() >= 20) {
         spb = fmt.getShort(18) & 0xFFFF;
      }

      ByteBuffer fact = chunk(d, "fact");
      short[] pcm = decode(data, ch, blockAlign, spb);
      int frames = pcm.length / ch;
      if (fact != null && fact.limit() >= 4 && fact.getInt(0) >= 0 && fact.getInt(0) < frames) {
         frames = fact.getInt(0);
      }

      byte[] out = new byte[frames * ch * 2];
      for (int i = 0; i < frames * ch; i++) {
         out[2 * i] = (byte)pcm[i];
         out[2 * i + 1] = (byte)(pcm[i] >> 8);
      }

      AudioFormat af = new AudioFormat(rate, 16, ch, true, false);
      return new AudioInputStream(new ByteArrayInputStream(out), af, frames);
   }

   /** Bloques completos o el ultimo parcial; muestras entrelazadas por canal. */
   public static short[] decode(ByteBuffer data, int ch, int blockAlign, int spb) {
      int n = data.limit();
      int blocks = (n + blockAlign - 1) / blockAlign;
      short[] out = new short[blocks * spb * ch];
      int o = 0;

      for (int blk = 0; blk < blocks; blk++) {
         int base = blk * blockAlign;
         int end = Math.min(n, base + blockAlign);
         if (end - base < 4 * ch) {
            break;
         }

         Channel[] st = new Channel[ch];
         for (int c = 0; c < ch; c++) {
            st[c] = new Channel(data.getShort(base + 4 * c), Math.max(0, Math.min(88, data.get(base + 4 * c + 2) & 0xFF)));
            out[o + c] = (short)st[c].predictor;
         }

         int written = 1;
         int p = base + 4 * ch;
         // grupos de 4 bytes (8 muestras) por canal, alternando
         while (p + 4 * ch <= end && written < spb) {
            for (int c = 0; c < ch; c++) {
               for (int k = 0; k < 4; k++) {
                  int byt = data.get(p + 4 * c + k) & 0xFF;
                  int s = written + 2 * k;
                  if (s < spb) {
                     out[o + s * ch + c] = (short)st[c].decode(byt & 15);
                  }

                  if (s + 1 < spb) {
                     out[o + (s + 1) * ch + c] = (short)st[c].decode(byt >> 4);
                  }
               }
            }

            written += 8;
            p += 4 * ch;
         }

         o += Math.min(written, spb) * ch;
      }

      short[] r = new short[o];
      System.arraycopy(out, 0, r, 0, o);
      return r;
   }
}
