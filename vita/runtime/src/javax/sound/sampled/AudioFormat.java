package javax.sound.sampled;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

/** javax.sound.sampled.AudioFormat, with the JDK's frame sizes and toString. */
public class AudioFormat {
   protected Encoding encoding;
   protected float sampleRate;
   protected int sampleSizeInBits;
   protected int channels;
   protected int frameSize;
   protected float frameRate;
   protected boolean bigEndian;
   private HashMap<String, Object> properties;

   public AudioFormat(Encoding encoding, float sampleRate, int sampleSizeInBits, int channels, int frameSize, float frameRate, boolean bigEndian) {
      this.encoding = encoding;
      this.sampleRate = sampleRate;
      this.sampleSizeInBits = sampleSizeInBits;
      this.channels = channels;
      this.frameSize = frameSize;
      this.frameRate = frameRate;
      this.bigEndian = bigEndian;
   }

   public AudioFormat(Encoding encoding, float sampleRate, int sampleSizeInBits, int channels, int frameSize, float frameRate, boolean bigEndian,
         Map<String, Object> properties) {
      this(encoding, sampleRate, sampleSizeInBits, channels, frameSize, frameRate, bigEndian);
      this.properties = new HashMap<String, Object>(properties);
   }

   public AudioFormat(float sampleRate, int sampleSizeInBits, int channels, boolean signed, boolean bigEndian) {
      this(signed ? Encoding.PCM_SIGNED : Encoding.PCM_UNSIGNED, sampleRate, sampleSizeInBits, channels, pcmFrameSize(sampleSizeInBits, channels), sampleRate,
            bigEndian);
   }

   static int pcmFrameSize(int sampleSizeInBits, int channels) {
      if (sampleSizeInBits == AudioSystem.NOT_SPECIFIED || channels == AudioSystem.NOT_SPECIFIED) {
         return AudioSystem.NOT_SPECIFIED;
      }
      return ((sampleSizeInBits + 7) / 8) * channels;
   }

   public Encoding getEncoding() {
      return encoding;
   }

   public float getSampleRate() {
      return sampleRate;
   }

   public int getSampleSizeInBits() {
      return sampleSizeInBits;
   }

   public int getChannels() {
      return channels;
   }

   public int getFrameSize() {
      return frameSize;
   }

   public float getFrameRate() {
      return frameRate;
   }

   public boolean isBigEndian() {
      return bigEndian;
   }

   public Map<String, Object> properties() {
      if (properties == null) {
         return Collections.<String, Object>emptyMap();
      }
      return Collections.unmodifiableMap(properties);
   }

   public Object getProperty(String key) {
      return properties == null ? null : properties.get(key);
   }

   public boolean matches(AudioFormat format) {
      return format.getEncoding().equals(getEncoding())
            && (format.getChannels() == AudioSystem.NOT_SPECIFIED || format.getChannels() == getChannels())
            && (format.getSampleRate() == AudioSystem.NOT_SPECIFIED || format.getSampleRate() == getSampleRate())
            && (format.getSampleSizeInBits() == AudioSystem.NOT_SPECIFIED || format.getSampleSizeInBits() == getSampleSizeInBits())
            && (format.getFrameSize() == AudioSystem.NOT_SPECIFIED || format.getFrameSize() == getFrameSize())
            && (format.getFrameRate() == AudioSystem.NOT_SPECIFIED || format.getFrameRate() == getFrameRate())
            && (getSampleSizeInBits() <= 8 || format.isBigEndian() == isBigEndian());
   }

   public String toString() {
      String rate = getSampleRate() == AudioSystem.NOT_SPECIFIED ? "unknown sample rate" : getSampleRate() + " Hz";
      String size = getSampleSizeInBits() == AudioSystem.NOT_SPECIFIED ? "unknown bits per sample" : getSampleSizeInBits() + " bit";
      String ch;
      switch (getChannels()) {
         case 1:
            ch = "mono";
            break;
         case 2:
            ch = "stereo";
            break;
         case AudioSystem.NOT_SPECIFIED:
            ch = "unknown number of channels";
            break;
         default:
            ch = getChannels() + " channels";
      }
      String frame = getFrameSize() == AudioSystem.NOT_SPECIFIED ? "unknown frame size" : getFrameSize() + " bytes/frame";
      String fr = "";
      if (Math.abs(getSampleRate() - getFrameRate()) > 0.00001) {
         fr = getFrameRate() == AudioSystem.NOT_SPECIFIED ? ", unknown frame rate" : ", " + getFrameRate() + " frames/second";
      }
      String endian = "";
      if ((getEncoding().equals(Encoding.PCM_SIGNED) || getEncoding().equals(Encoding.PCM_UNSIGNED))
            && (getSampleSizeInBits() > 8 || getSampleSizeInBits() == AudioSystem.NOT_SPECIFIED)) {
         endian = isBigEndian() ? ", big-endian" : ", little-endian";
      }
      return getEncoding() + " " + rate + ", " + size + ", " + ch + ", " + frame + fr + endian;
   }

   public static class Encoding {
      public static final Encoding PCM_SIGNED = new Encoding("PCM_SIGNED");
      public static final Encoding PCM_UNSIGNED = new Encoding("PCM_UNSIGNED");
      public static final Encoding PCM_FLOAT = new Encoding("PCM_FLOAT");
      public static final Encoding ULAW = new Encoding("ULAW");
      public static final Encoding ALAW = new Encoding("ALAW");

      private final String name;

      public Encoding(String name) {
         this.name = name;
      }

      public final boolean equals(Object obj) {
         if (this == obj) {
            return true;
         }
         if (!(obj instanceof Encoding)) {
            return false;
         }
         return name == null ? ((Encoding) obj).name == null : name.equals(((Encoding) obj).name);
      }

      public final int hashCode() {
         return name == null ? 0 : name.hashCode();
      }

      public final String toString() {
         return name;
      }
   }
}
