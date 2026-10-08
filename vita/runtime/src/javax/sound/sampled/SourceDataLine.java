package javax.sound.sampled;

/** javax.sound.sampled.SourceDataLine: samples written to it are played. */
public interface SourceDataLine extends DataLine {
   void open(AudioFormat format, int bufferSize) throws LineUnavailableException;

   void open(AudioFormat format) throws LineUnavailableException;

   int write(byte[] b, int off, int len);
}
