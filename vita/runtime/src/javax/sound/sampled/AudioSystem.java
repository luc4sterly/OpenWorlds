package javax.sound.sampled;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import net.openworlds.awt.SoundLine;

/**
 * javax.sound.sampled.AudioSystem as the bridge uses it: WAV files in
 * (WaveReader), conversions to 16-bit PCM (PcmConverter) and lines to the
 * machine's sound output (net.openworlds.awt.SoundLine, mixed and sent to
 * SDL2 on Linux and the PSVita).
 */
public class AudioSystem {
   public static final int NOT_SPECIFIED = -1;

   private AudioSystem() {
   }

   public static AudioInputStream getAudioInputStream(File file) throws UnsupportedAudioFileException, IOException {
      InputStream in = new BufferedInputStream(new FileInputStream(file));
      AudioInputStream a = null;
      try {
         a = WaveReader.read(in);
      } finally {
         if (a == null) {
            in.close();
         }
      }
      if (a == null) {
         throw new UnsupportedAudioFileException("File of unsupported format");
      }
      return a;
   }

   public static AudioInputStream getAudioInputStream(InputStream stream) throws UnsupportedAudioFileException, IOException {
      if (!stream.markSupported()) {
         throw new IOException("mark/reset not supported");
      }
      stream.mark(1 << 16);
      AudioInputStream a = WaveReader.read(stream);
      if (a == null) {
         stream.reset();
         throw new UnsupportedAudioFileException("Stream of unsupported format");
      }
      return a;
   }

   public static AudioInputStream getAudioInputStream(URL url) throws UnsupportedAudioFileException, IOException {
      InputStream in = new BufferedInputStream(url.openStream());
      AudioInputStream a = null;
      try {
         a = WaveReader.read(in);
      } finally {
         if (a == null) {
            in.close();
         }
      }
      if (a == null) {
         throw new UnsupportedAudioFileException("URL of unsupported format");
      }
      return a;
   }

   public static AudioInputStream getAudioInputStream(AudioFormat targetFormat, AudioInputStream sourceStream) {
      if (sourceStream.getFormat().matches(targetFormat)) {
         return sourceStream;
      }
      if (!PcmConverter.supports(targetFormat, sourceStream.getFormat())) {
         throw new IllegalArgumentException("Unsupported conversion: " + targetFormat + " from " + sourceStream.getFormat());
      }
      return PcmConverter.convert(targetFormat, sourceStream);
   }

   public static boolean isConversionSupported(AudioFormat targetFormat, AudioFormat sourceFormat) {
      return sourceFormat.matches(targetFormat) || PcmConverter.supports(targetFormat, sourceFormat);
   }

   public static SourceDataLine getSourceDataLine(AudioFormat format) throws LineUnavailableException {
      if (format != null && !SoundLine.supports(format)) {
         throw new IllegalArgumentException("No line matching interface SourceDataLine supporting format " + format + " is supported.");
      }
      return new SoundLine(format);
   }

   public static boolean isLineSupported(Line.Info info) {
      if (!SourceDataLine.class.isAssignableFrom(info.getLineClass()) && !info.getLineClass().isAssignableFrom(SourceDataLine.class)) {
         return false;
      }
      if (info instanceof DataLine.Info) {
         for (AudioFormat f : ((DataLine.Info) info).getFormats()) {
            if (!SoundLine.supports(f)) {
               return false;
            }
         }
      }
      return true;
   }

   public static Line getLine(Line.Info info) throws LineUnavailableException {
      if (!isLineSupported(info)) {
         throw new IllegalArgumentException("No line matching " + info + " is supported.");
      }
      AudioFormat f = null;
      if (info instanceof DataLine.Info && ((DataLine.Info) info).getFormats().length > 0) {
         f = ((DataLine.Info) info).getFormats()[0];
      }
      return new SoundLine(f);
   }
}
