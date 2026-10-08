package conformance;

import java.io.*;
import javax.sound.midi.*;
import javax.sound.sampled.*;

/**
 * javax.sound as the bridge uses it (NativeMediaSound, ImaAdpcmWav): WAV
 * headers, the conversions to 16-bit PCM, AudioInputStream's reads, MIDI
 * files, tempo maps and the sequencer's clock. On a JVM it is the JDK's
 * javax.sound; transpiled (and with vita/tools/run-runtime-conformance.sh)
 * it is ours (vita/runtime). The output must be the same.
 *
 * Not here, on purpose: what the JDK converts and ours does not (another
 * sample rate, to 8 bits, channels other than mono/stereo; the bridge never
 * asks for them), files the JDK reads besides WAV (AU, AIFF), and audio
 * output lines (the JDK has none without a sound card; ours are checked by
 * vita/test/sound/SoundCheck.java).
 *
 *   args: <work dir> <repository> (the corpus WAV and MIDI files)
 */
public class SoundConformance {
	static void p(Object o) { System.out.println(o); }

	static long hash(byte[] b, int n) {
		long h = 17;
		for (int i = 0; i < n; i++)
			h = h * 31 + (b[i] & 0xFF);
		return h;
	}

	static long seed = 12345;

	static int rnd() {
		seed = seed * 6364136223846793005L + 1442695040888963407L;
		return (int) (seed >>> 32);
	}

	public static void main(String[] args) throws Exception {
		File dir = new File(args[0]);
		File repo = args.length > 1 ? new File(args[1]) : null;
		formats();
		streams();
		tables();
		waves(dir, repo);
		messages();
		tracks();
		midiFiles(dir, repo);
		sequencer(dir);
		p("done");
	}

	// ---------------------------------------------------------------- formats

	static void formats() {
		AudioFormat[] fs = {new AudioFormat(22050f, 16, 2, true, true), new AudioFormat(8000, 8, 1, false, false), new AudioFormat(11025, 8, 2, true, false),
				new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, 44100, 16, 2, 4, 22050, false), new AudioFormat(AudioSystem.NOT_SPECIFIED, AudioSystem.NOT_SPECIFIED, AudioSystem.NOT_SPECIFIED, true, false),
				new AudioFormat(8000, 24, 5, true, false), new AudioFormat(8000, 12, 1, true, false), new AudioFormat(AudioFormat.Encoding.ULAW, 8000, 8, 1, 1, 8000, false),
				new AudioFormat(AudioFormat.Encoding.ALAW, 8000, 8, 2, 2, 8000, true), new AudioFormat(AudioFormat.Encoding.PCM_FLOAT, 48000, 32, 2, 8, 48000, false),
				new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, 8000, 16, 1, 2, AudioSystem.NOT_SPECIFIED, false), new AudioFormat(new AudioFormat.Encoding("MYCODEC"), 8000, 4, 1, 256, 31.25f, false)};
		for (AudioFormat f : fs)
			p("format " + f + " | " + f.getEncoding() + " " + f.getSampleRate() + " " + f.getSampleSizeInBits() + " " + f.getChannels() + " " + f.getFrameSize() + " " + f.getFrameRate() + " " + f.isBigEndian());
		AudioFormat a = new AudioFormat(22050f, 16, 2, true, false);
		AudioFormat[] others = {new AudioFormat(22050f, 16, 2, true, false), new AudioFormat(22050f, 16, 2, true, true), new AudioFormat(22050f, 16, 1, true, false),
				new AudioFormat(AudioSystem.NOT_SPECIFIED, 16, 2, true, false), new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, 22050f, 16, AudioSystem.NOT_SPECIFIED, AudioSystem.NOT_SPECIFIED, AudioSystem.NOT_SPECIFIED, false),
				new AudioFormat(22050f, 16, 2, false, false), new AudioFormat(22050f, 8, 2, true, false)};
		StringBuilder b = new StringBuilder("matches");
		for (AudioFormat o : others)
			b.append(" ").append(a.matches(o)).append("/").append(o.matches(a));
		AudioFormat u8 = new AudioFormat(8000, 8, 1, false, false);
		b.append(" 8-bit endianness ").append(u8.matches(new AudioFormat(8000, 8, 1, false, true)));
		p(b);
		p("encodings " + AudioFormat.Encoding.ULAW + " " + new AudioFormat.Encoding("ULAW").equals(AudioFormat.Encoding.ULAW) + " " + (new AudioFormat.Encoding("X").hashCode() == "X".hashCode())
				+ " equals " + a.equals(new AudioFormat(22050f, 16, 2, true, false)));
	}

	// ---------------------------------------------------------------- AudioInputStream

	static String reads(AudioInputStream in, int... lens) throws IOException {
		StringBuilder b = new StringBuilder();
		byte[] buf = new byte[2000];
		for (int len : lens)
			b.append(" ").append(in.read(buf, 0, len));
		return b.toString();
	}

	/** A stream that hands out at most `chunk` bytes per read, like a socket. */
	static class Trickle extends ByteArrayInputStream {
		final int chunk;

		Trickle(byte[] b, int chunk) {
			super(b);
			this.chunk = chunk;
		}

		public synchronized int read(byte[] b, int off, int len) {
			return super.read(b, off, Math.min(len, chunk));
		}
	}

	static void streams() throws IOException {
		AudioFormat s16 = new AudioFormat(8000, 16, 1, true, false);
		byte[] nine = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		AudioInputStream in = new AudioInputStream(new ByteArrayInputStream(nine), s16, 3);
		p("reads" + reads(in, 1, 3) + " skip " + in.skip(3) + " avail " + in.available() + reads(in, 10, 10));
		try {
			in.read();
			p("read() worked");
		} catch (IOException e) {
			p("read() " + e.getMessage());
		}
		in = new AudioInputStream(new ByteArrayInputStream(new byte[]{1, 2, 3, 4, 5}), s16, AudioSystem.NOT_SPECIFIED);
		p("partial" + reads(in, 10, 10) + " frames " + in.getFrameLength());
		in = new AudioInputStream(new Trickle(new byte[40], 3), new AudioFormat(8000, 16, 2, true, false), 9);
		p("trickle" + reads(in, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40));
		in = new AudioInputStream(new Trickle(new byte[40], 3), new AudioFormat(8000, 16, 2, true, false), 9);
		p("trickle skips " + in.skip(5) + " " + in.skip(6) + " " + in.skip(100) + reads(in, 40));
		in = new AudioInputStream(new ByteArrayInputStream(nine), new AudioFormat(8000, 8, 1, false, false), 7);
		StringBuilder b = new StringBuilder("bytes");
		int c;
		while ((c = in.read()) >= 0)
			b.append(" ").append(c);
		p(b + " then " + in.read());
		in = new AudioInputStream(new ByteArrayInputStream(new byte[20]), s16, 10);
		p("mark " + in.markSupported() + reads(in, 4));
		in.mark(100);
		p("after mark" + reads(in, 6) + " avail " + in.available());
		in.reset();
		p("after reset avail " + in.available() + reads(in, 30, 30));
		in = new AudioInputStream(new ByteArrayInputStream(new byte[20]), new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, 8000, 16, 1, AudioSystem.NOT_SPECIFIED, 8000, false), 5);
		p("unknown frame size" + reads(in, 3, 10));
	}

	// ---------------------------------------------------------------- conversions

	static short[] conv(byte[] data, AudioFormat src, AudioFormat dst) throws IOException {
		AudioInputStream c = AudioSystem.getAudioInputStream(dst, new AudioInputStream(new ByteArrayInputStream(data), src, data.length / src.getFrameSize()));
		ByteArrayOutputStream o = new ByteArrayOutputStream();
		byte[] buf = new byte[4096];
		int n;
		while ((n = c.read(buf, 0, buf.length)) > 0)
			o.write(buf, 0, n);
		byte[] b = o.toByteArray();
		short[] s = new short[b.length / 2];
		for (int i = 0; i < s.length; i++)
			s[i] = dst.isBigEndian() ? (short) (b[2 * i] << 8 | b[2 * i + 1] & 0xff) : (short) (b[2 * i] & 0xff | b[2 * i + 1] << 8);
		return s;
	}

	static String sum(short[] s) {
		long h = 17;
		for (short v : s)
			h = h * 31 + v;
		return s.length + " samples, hash " + h;
	}

	static String list(short[] s, int from, int to) {
		StringBuilder b = new StringBuilder();
		for (int i = from; i < to && i < s.length; i++)
			b.append(i > from ? " " : "").append(s[i]);
		return b.toString();
	}

	static void tables() throws IOException {
		byte[] all = new byte[256];
		for (int i = 0; i < 256; i++)
			all[i] = (byte) i;
		AudioFormat d16 = new AudioFormat(8000, 16, 1, true, false);
		AudioFormat d16be = new AudioFormat(8000, 16, 1, true, true);
		String[] names = {"u8", "s8", "ulaw", "alaw"};
		AudioFormat[] srcs = {new AudioFormat(8000, 8, 1, false, false), new AudioFormat(8000, 8, 1, true, false),
				new AudioFormat(AudioFormat.Encoding.ULAW, 8000, 8, 1, 1, 8000, false), new AudioFormat(AudioFormat.Encoding.ALAW, 8000, 8, 1, 1, 8000, false)};
		for (int k = 0; k < 4; k++) {
			short[] s = conv(all, srcs[k], d16);
			p(names[k] + " " + list(s, 0, 256));
			p(names[k] + " big-endian " + sum(conv(all, srcs[k], d16be)));
		}
		byte[] be = {0x12, 0x34, (byte) 0x80, 0, 0x7f, (byte) 0xff, (byte) 0xff, (byte) 0xff};
		p("s16be " + list(conv(be, new AudioFormat(8000, 16, 1, true, true), d16), 0, 4));
		p("u16be " + list(conv(be, new AudioFormat(8000, 16, 1, false, true), d16), 0, 4));
		// 24-bit: every 7th value of the whole range
		int n = (1 << 24) / 7 + 1;
		byte[] b = new byte[n * 3];
		for (int i = 0; i < n; i++) {
			int x = i * 7;
			b[3 * i] = (byte) x;
			b[3 * i + 1] = (byte) (x >> 8);
			b[3 * i + 2] = (byte) (x >> 16);
		}
		p("s24le " + sum(conv(b, new AudioFormat(8000, 24, 1, true, false), d16)));
		for (int i = 0; i < n; i++) {
			byte t = b[3 * i];
			b[3 * i] = b[3 * i + 2];
			b[3 * i + 2] = t;
		}
		p("s24be " + sum(conv(b, new AudioFormat(8000, 24, 1, true, true), d16)));
		p("u24be " + sum(conv(b, new AudioFormat(8000, 24, 1, false, true), d16)));
		// 32-bit: edges and random values
		int m = 300000;
		b = new byte[m * 4];
		for (int i = 0; i < m; i++) {
			int x = i < 40000 ? i - 20000 : i < 80000 ? Integer.MAX_VALUE - (i - 40000) : i < 120000 ? Integer.MIN_VALUE + (i - 80000) : rnd();
			b[4 * i] = (byte) x;
			b[4 * i + 1] = (byte) (x >> 8);
			b[4 * i + 2] = (byte) (x >> 16);
			b[4 * i + 3] = (byte) (x >> 24);
		}
		short[] s32 = conv(b, new AudioFormat(8000, 32, 1, true, false), d16);
		p("s32le " + sum(s32) + " first " + list(s32, 0, 4) + " max " + list(s32, 40000, 44000).hashCode());
		p("u32le " + sum(conv(b, new AudioFormat(8000, 32, 1, false, false), d16)));
		// float
		float[] fs = {0f, 0.5f, -0.5f, 1f, -1f, 1.5f, -1.5f, 2f, Float.NaN, 1e-6f, -1e-6f, Float.POSITIVE_INFINITY, Float.NEGATIVE_INFINITY, 1e10f, 0.99999f, -0.99999f, 3.0517578E-5f};
		b = new byte[fs.length * 4];
		for (int i = 0; i < fs.length; i++) {
			int x = Float.floatToRawIntBits(fs[i]);
			b[4 * i] = (byte) x;
			b[4 * i + 1] = (byte) (x >> 8);
			b[4 * i + 2] = (byte) (x >> 16);
			b[4 * i + 3] = (byte) (x >> 24);
		}
		p("float " + list(conv(b, new AudioFormat(AudioFormat.Encoding.PCM_FLOAT, 8000, 32, 1, 4, 8000, false), d16), 0, fs.length));
		// channels
		m = 200000;
		b = new byte[m * 4];
		for (int i = 0; i < m; i++) {
			int l, r;
			if (i < 65536) {
				l = i - 32768;
				r = l + 1 > 32767 ? l : l + 1;
			} else {
				l = (short) rnd();
				r = (short) rnd();
			}
			b[4 * i] = (byte) l;
			b[4 * i + 1] = (byte) (l >> 8);
			b[4 * i + 2] = (byte) r;
			b[4 * i + 3] = (byte) (r >> 8);
		}
		p("stereo to mono " + sum(conv(b, new AudioFormat(8000, 16, 2, true, false), d16)));
		AudioFormat st = new AudioFormat(8000, 16, 2, true, false);
		p("mono to stereo " + sum(conv(b, d16, st)));
		p("u8 mono to stereo " + list(conv(all, srcs[0], st), 250, 270));
		p("u8 stereo to mono " + list(conv(new byte[]{0, (byte) 255, (byte) 128, (byte) 129, 1, 3}, new AudioFormat(8000, 8, 2, false, false), d16), 0, 3));
		p("u8 stereo " + list(conv(new byte[]{0, (byte) 255, (byte) 128, (byte) 129}, new AudioFormat(8000, 8, 2, false, false), st), 0, 4));
		AudioInputStream x = new AudioInputStream(new ByteArrayInputStream(be), d16, 4);
		p("same format, same stream " + (AudioSystem.getAudioInputStream(new AudioFormat(8000, 16, 1, true, false), x) == x));
		AudioFormat[][] pairs = {{srcs[2], st}, {new AudioFormat(AudioFormat.Encoding.ALAW, 8000, 8, 2, 2, 8000, false), d16}};
		for (AudioFormat[] pr : pairs) {
			try {
				AudioSystem.getAudioInputStream(pr[1], new AudioInputStream(new ByteArrayInputStream(all), pr[0], 128));
				p("converted " + pr[0] + " to " + pr[1]);
			} catch (IllegalArgumentException e) {
				p("IllegalArgumentException " + e.getMessage());
			}
		}
		p("supported " + AudioSystem.isConversionSupported(d16, srcs[0]) + " " + AudioSystem.isConversionSupported(st, srcs[2]) + " " + AudioSystem.isConversionSupported(d16, d16)
				+ " " + AudioSystem.isConversionSupported(st, new AudioFormat(8000, 24, 1, true, false)));
		// the converted stream: frame length, available, reads of odd sizes
		AudioInputStream c = AudioSystem.getAudioInputStream(d16, new AudioInputStream(new ByteArrayInputStream(new byte[]{0, (byte) 255, (byte) 128, (byte) 129, 1, 3}), new AudioFormat(8000, 8, 2, false, false), 3));
		p("converted " + c.getFormat() + " frames " + c.getFrameLength() + reads(c, 3, 1, 4, 4));
		c = AudioSystem.getAudioInputStream(d16, new AudioInputStream(new ByteArrayInputStream(all), srcs[0], AudioSystem.NOT_SPECIFIED));
		p("unknown length " + c.getFrameLength() + reads(c, 100, 7, 1000, 1000) + " skip " + c.skip(10));
		c = AudioSystem.getAudioInputStream(d16, new AudioInputStream(new ByteArrayInputStream(all), srcs[2], 200));
		p("ulaw length " + c.getFrameLength() + " skip " + c.skip(101) + reads(c, 1000, 1000));
	}

	// ---------------------------------------------------------------- WAV files

	static ByteArrayOutputStream bo;

	static void le32(int v) {
		bo.write(v);
		bo.write(v >> 8);
		bo.write(v >> 16);
		bo.write(v >> 24);
	}

	static void le16(int v) {
		bo.write(v);
		bo.write(v >> 8);
	}

	static void tag(String s) {
		for (int i = 0; i < s.length(); i++)
			bo.write(s.charAt(i));
	}

	static byte[] wav(int fmtTag, int ch, int rate, int bits, int blockAlign, int fmtSize, int dataSize, int dataBytes, boolean listBefore, boolean listAfter, int riffSize) {
		bo = new ByteArrayOutputStream();
		tag("RIFF");
		le32(riffSize);
		tag("WAVE");
		if (listBefore) {
			tag("LIST");
			le32(5);
			tag("INFOx");
			bo.write(0);
		}
		tag("fmt ");
		le32(fmtSize);
		le16(fmtTag);
		le16(ch);
		le32(rate);
		le32(rate * blockAlign);
		le16(blockAlign);
		le16(bits);
		for (int i = 16; i < fmtSize; i++)
			bo.write(i == 16 ? (fmtSize - 18) : 0);
		if (fmtSize % 2 == 1)
			bo.write(0);
		if (listAfter) {
			tag("fact");
			le32(4);
			le32(1234);
			tag("LIST");
			le32(3);
			tag("abc");
			bo.write(0);
		}
		tag("data");
		le32(dataSize);
		for (int i = 0; i < dataBytes; i++)
			bo.write(i * 37 + (i >> 3));
		return bo.toByteArray();
	}

	static byte[] extensible(int sub, int bits, int ch, boolean goodGuid, int fmtSize) {
		bo = new ByteArrayOutputStream();
		tag("RIFF");
		le32(200);
		tag("WAVE");
		tag("fmt ");
		le32(fmtSize);
		le16(0xFFFE);
		le16(ch);
		le32(22050);
		le32(22050 * ch * bits / 8);
		le16(ch * bits / 8);
		le16(bits);
		le16(22);
		le16(bits);
		le32(3);
		le32(sub);
		le16(0);
		le16(0x10);
		int[] tail = {0x80, 0, 0, 0xAA, 0, 0x38, 0x9B, goodGuid ? 0x71 : 0x72};
		for (int t : tail)
			bo.write(t);
		for (int i = 40; i < fmtSize; i++)
			bo.write(0);
		if (fmtSize % 2 == 1)
			bo.write(0);
		tag("data");
		le32(120);
		for (int i = 0; i < 120; i++)
			bo.write(i * 11);
		return bo.toByteArray();
	}

	static void readWav(String name, File f) {
		try {
			AudioInputStream in = AudioSystem.getAudioInputStream(f);
			AudioFormat af = in.getFormat();
			ByteArrayOutputStream all = new ByteArrayOutputStream();
			byte[] buf = new byte[4096];
			int n;
			while ((n = in.read(buf, 0, 999)) > 0)
				all.write(buf, 0, n);
			byte[] d = all.toByteArray();
			p(name + ": " + af + " | frames " + in.getFrameLength() + " read " + d.length + " hash " + hash(d, d.length));
			in.close();
			// what the bridge does with it (NativeMediaSound.Playback.run)
			String conv = "";
			AudioFormat[] targets = {new AudioFormat(af.getSampleRate(), 16, af.getChannels() == 1 ? 1 : 2, true, false), new AudioFormat(af.getSampleRate(), 16, af.getChannels(), true, true),
					new AudioFormat(af.getSampleRate(), 16, af.getChannels() == 1 ? 2 : 1, true, false)};
			for (AudioFormat t : targets) {
				in = AudioSystem.getAudioInputStream(f);
				try {
					AudioInputStream c = AudioSystem.getAudioInputStream(t, in);
					ByteArrayOutputStream o = new ByteArrayOutputStream();
					while ((n = c.read(buf, 0, 4096 / c.getFormat().getFrameSize() * c.getFormat().getFrameSize())) > 0)
						o.write(buf, 0, n);
					conv += " | " + c.getFormat().getChannels() + (c.getFormat().isBigEndian() ? "be" : "le") + " " + o.size() + " " + hash(o.toByteArray(), o.size()) + " frames " + c.getFrameLength();
				} catch (IllegalArgumentException e) {
					conv += " | " + t.getChannels() + " channels: not converted";
				}
				in.close();
			}
			p("  converted" + conv);
		} catch (Exception e) {
			p(name + ": " + e.getClass().getName() + " " + (e instanceof FileNotFoundException ? "" : e.getMessage()));
		}
	}

	static void waves(File dir, File repo) throws IOException {
		Object[][] cases = {
				{"pcm16", wav(1, 1, 22050, 16, 2, 16, 100, 100, false, false, 136)},
				{"pcm8", wav(1, 1, 22050, 8, 1, 16, 99, 99, false, false, 135)},
				{"pcm8 stereo fmt18", wav(1, 2, 11025, 8, 2, 18, 100, 100, false, false, 138)},
				{"pcm16 stereo", wav(1, 2, 44100, 16, 4, 16, 400, 400, false, false, 436)},
				{"list before", wav(1, 1, 22050, 16, 2, 16, 100, 100, true, false, 150)},
				{"fact+list after", wav(1, 1, 22050, 16, 2, 16, 100, 100, false, true, 160)},
				{"data longer than file", wav(1, 1, 22050, 16, 2, 16, 1000, 100, false, false, 1036)},
				{"data shorter than file", wav(1, 1, 22050, 16, 2, 16, 50, 100, false, false, 136)},
				{"odd data", wav(1, 1, 22050, 16, 2, 16, 101, 101, false, false, 137)},
				{"data size ffffffff", wav(1, 1, 22050, 16, 2, 16, -1, 100, false, false, -1)},
				{"data size 0", wav(1, 1, 22050, 16, 2, 16, 0, 100, false, false, 36)},
				{"riff size 0", wav(1, 1, 22050, 16, 2, 16, 100, 100, false, false, 0)},
				{"ima adpcm", wav(0x11, 1, 11025, 4, 256, 20, 100, 100, false, false, 140)},
				{"ms adpcm", wav(2, 1, 11025, 4, 256, 50, 100, 100, false, false, 180)},
				{"mp3", wav(0x55, 1, 11025, 0, 1, 30, 100, 100, false, false, 180)},
				{"ulaw", wav(7, 1, 8000, 8, 1, 18, 100, 100, false, false, 138)},
				{"alaw stereo", wav(6, 2, 8000, 8, 2, 18, 100, 100, false, false, 138)},
				{"pcm24", wav(1, 2, 44100, 24, 6, 16, 600, 600, false, false, 636)},
				{"pcm32", wav(1, 1, 44100, 32, 4, 16, 400, 400, false, false, 436)},
				{"block align wrong", wav(1, 2, 8000, 16, 7, 16, 100, 100, false, false, 136)},
				{"float", wav(3, 1, 8000, 32, 4, 18, 100, 100, false, false, 138)},
				{"channels 0", wav(1, 0, 8000, 16, 2, 16, 100, 100, false, false, 136)},
				{"bits 0", wav(1, 1, 8000, 0, 2, 16, 100, 100, false, false, 136)},
				{"rate 0", wav(1, 1, 0, 16, 2, 16, 100, 100, false, false, 136)},
				{"fmt 14", wav(1, 1, 8000, 16, 2, 14, 100, 100, false, false, 136)},
				{"fmt 17", wav(1, 1, 8000, 16, 2, 17, 100, 100, false, false, 137)},
				{"fmt 40", wav(1, 1, 8000, 16, 2, 40, 100, 100, false, false, 160)},
				{"extensible pcm16", extensible(1, 16, 2, true, 40)},
				{"extensible pcm8", extensible(1, 8, 1, true, 40)},
				{"extensible float", extensible(3, 32, 1, true, 40)},
				{"extensible bad guid", extensible(1, 16, 2, false, 40)},
				{"extensible adpcm", extensible(2, 16, 2, true, 40)},
				{"extensible fmt 46", extensible(1, 16, 1, true, 46)},
		};
		for (Object[] c : cases) {
			File f = new File(dir, "t.wav");
			FileOutputStream o = new FileOutputStream(f);
			o.write((byte[]) c[1]);
			o.close();
			readWav((String) c[0], f);
		}
		byte[] good = wav(1, 1, 8000, 16, 2, 16, 100, 100, false, false, 136);
		byte[][] broken = {java.util.Arrays.copyOf(good, 30), java.util.Arrays.copyOf(good, 36), new byte[0], "hello world, this is not a wav file at all".getBytes("ISO-8859-1"), good.clone()};
		broken[4][3] = 'X';
		String[] bnames = {"truncated header", "no data chunk", "empty", "text", "RIFX"};
		for (int i = 0; i < broken.length; i++) {
			File f = new File(dir, "b.wav");
			FileOutputStream o = new FileOutputStream(f);
			o.write(broken[i]);
			o.close();
			readWav(bnames[i], f);
		}
		readWav("missing file", new File(dir, "nothing-here.wav"));
		// from a stream: needs mark/reset
		try {
			AudioSystem.getAudioInputStream(new FileInputStream(new File(dir, "t.wav")));
			p("unmarked stream read");
		} catch (IOException e) {
			p("unmarked stream: IOException " + e.getMessage());
		} catch (UnsupportedAudioFileException e) {
			p("unmarked stream: " + e);
		}
		try {
			AudioInputStream s = AudioSystem.getAudioInputStream(new BufferedInputStream(new ByteArrayInputStream(good)));
			p("stream " + s.getFormat() + " frames " + s.getFrameLength());
			BufferedInputStream bad = new BufferedInputStream(new ByteArrayInputStream("not a wav at all, not at all".getBytes("ISO-8859-1")));
			try {
				AudioSystem.getAudioInputStream(bad);
			} catch (UnsupportedAudioFileException e) {
				p("bad stream: " + e.getMessage() + ", then reads " + (char) bad.read());
			}
		} catch (Exception e) {
			p("stream: " + e);
		}
		if (repo != null) {
			String[] corpus = {"assets/WorldsPlayer/dummy.wav", "assets/GROUNDZERO/LIONDOOR.WAV", "assets/GROUNDZERO/S.WAV"};
			for (String c : corpus)
				readWav(c, new File(repo, c));
		}
	}

	// ---------------------------------------------------------------- MIDI messages

	static String msg(MidiMessage m) {
		StringBuilder b = new StringBuilder(m.getClass().getSimpleName() + " " + m.getStatus() + " " + m.getLength() + " [");
		byte[] d = m.getMessage();
		for (int i = 0; i < d.length; i++)
			b.append(i > 0 ? " " : "").append(d[i] & 0xFF);
		return b.append("]").toString();
	}

	static void messages() {
		try {
			ShortMessage s = new ShortMessage();
			p("short default " + msg(s) + " " + s.getCommand() + " " + s.getChannel() + " " + s.getData1() + " " + s.getData2());
			s.setMessage(ShortMessage.PROGRAM_CHANGE, 5, 33, 99);
			p("program change " + msg(s) + " " + s.getData2());
			s.setMessage(ShortMessage.TUNE_REQUEST);
			p("tune request " + msg(s));
			s.setMessage(0xF2, 1, 2);
			p("song position " + msg(s));
			ShortMessage c = (ShortMessage) s.clone();
			p("clone " + msg(c) + " " + (c != s));
			p("4 args " + msg(new ShortMessage(ShortMessage.NOTE_OFF, 15, 60, 0)));
		} catch (InvalidMidiDataException e) {
			p("short: " + e);
		}
		Object[][] bad = {{0x90, 128, 0}, {0x90, 0, -1}, {0x70, 0, 0}, {0xF4, 0, 0}};
		for (Object[] b : bad) {
			try {
				new ShortMessage((Integer) b[0], (Integer) b[1], (Integer) b[2]);
				p("accepted " + b[0]);
			} catch (InvalidMidiDataException e) {
				p("invalid " + b[0] + " " + b[1] + " " + b[2]);
			}
		}
		try {
			new ShortMessage(0x90);
			p("accepted a note on without data");
		} catch (InvalidMidiDataException e) {
			p("invalid note on without data");
		}
		try {
			new ShortMessage(0xF0, 0, 1, 2);
			p("accepted command F0");
		} catch (InvalidMidiDataException e) {
			p("invalid command F0");
		}
		int[] lens = {0, 1, 127, 128, 16383, 16384, 300000};
		for (int n : lens) {
			try {
				byte[] d = new byte[n];
				for (int i = 0; i < n; i++)
					d[i] = (byte) i;
				MetaMessage m = new MetaMessage(0x7F, d, n);
				p("meta " + n + ": " + m.getLength() + " type " + m.getType() + " data " + m.getData().length + " head " + (m.getMessage()[2] & 0xFF) + " hash " + hash(m.getMessage(), m.getLength())
						+ " clone " + ((MetaMessage) m.clone()).getData().length);
			} catch (InvalidMidiDataException e) {
				p("meta " + n + ": " + e);
			}
		}
		MetaMessage dm = new MetaMessage();
		p("meta default " + msg(dm) + " type " + dm.getType() + " data " + dm.getData().length);
		try {
			new MetaMessage(128, new byte[0], 0);
		} catch (InvalidMidiDataException e) {
			p("meta type 128 invalid");
		}
		try {
			new MetaMessage(1, new byte[2], 3);
		} catch (InvalidMidiDataException e) {
			p("meta length out of bounds");
		}
		try {
			SysexMessage x = new SysexMessage(new byte[]{(byte) 0xF0, 1, 2, (byte) 0xF7}, 4);
			p("sysex " + msg(x) + " data " + x.getData().length);
			x = new SysexMessage(0xF7, new byte[]{9, 8, 7}, 2);
			p("sysex F7 " + msg(x) + " data " + x.getData().length);
			p("sysex default " + msg(new SysexMessage()));
			new SysexMessage(new byte[]{(byte) 0x90, 1}, 2);
			p("sysex 90 accepted");
		} catch (InvalidMidiDataException e) {
			p("sysex invalid status");
		}
	}

	static String track(Track t) {
		StringBuilder b = new StringBuilder("size " + t.size() + " ticks " + t.ticks() + ":");
		for (int i = 0; i < t.size(); i++) {
			MidiEvent e = t.get(i);
			b.append(" ").append(e.getTick()).append("/").append(e.getMessage().getStatus());
			if (e.getMessage() instanceof MetaMessage)
				b.append("/").append(((MetaMessage) e.getMessage()).getType());
		}
		return b.toString();
	}

	static void tracks() throws InvalidMidiDataException {
		Sequence s = new Sequence(Sequence.PPQ, 96);
		Track t = s.createTrack();
		p("new track " + track(t));
		MidiEvent a = new MidiEvent(new ShortMessage(0x90, 60, 100), 50);
		p("add " + t.add(a) + " again " + t.add(a) + " " + track(t));
		t.add(new MidiEvent(new ShortMessage(0x80, 60, 0), 20));
		t.add(new MidiEvent(new ShortMessage(0xB0, 7, 100), 50));
		t.add(new MidiEvent(new ShortMessage(0xC0, 1, 0), 0));
		p("sorted " + track(t));
		p("eot earlier " + t.add(new MidiEvent(new MetaMessage(0x2F, new byte[0], 0), 10)) + " " + track(t));
		p("eot later " + t.add(new MidiEvent(new MetaMessage(0x2F, new byte[0], 0), 500)) + " " + track(t));
		t.add(new MidiEvent(new ShortMessage(0x90, 61, 100), 600));
		p("after the end " + track(t));
		t.add(new MidiEvent(new ShortMessage(0x90, 62, 100), 400));
		p("before the end " + track(t));
		p("remove " + t.remove(a) + " again " + t.remove(a) + " null " + t.add(null) + " " + track(t));
		p("sequence ticks " + s.getTickLength() + " us " + s.getMicrosecondLength() + " tracks " + s.getTracks().length + " delete " + s.deleteTrack(t) + " " + s.getTracks().length);
		try {
			new Sequence(12.5f, 10);
		} catch (InvalidMidiDataException e) {
			p("division 12.5 invalid");
		}
		Sequence three = new Sequence(Sequence.SMPTE_25, 40, 3);
		p("smpte " + three.getTracks().length + " " + three.getDivisionType() + " " + three.getResolution() + " us " + three.getMicrosecondLength());
	}

	// ---------------------------------------------------------------- MIDI files

	static ByteArrayOutputStream mo;

	static void be32(int v) {
		mo.write(v >> 24);
		mo.write(v >> 16);
		mo.write(v >> 8);
		mo.write(v);
	}

	static void be16(int v) {
		mo.write(v >> 8);
		mo.write(v);
	}

	static void bytes(int... b) {
		for (int x : b)
			mo.write(x);
	}

	static void str(String s) {
		for (int i = 0; i < s.length(); i++)
			mo.write(s.charAt(i));
	}

	static byte[] smf(int type, int ntracks, int division, int headerLength, int[][] tracks) {
		mo = new ByteArrayOutputStream();
		str("MThd");
		be32(headerLength);
		be16(type);
		be16(ntracks);
		be16(division);
		for (int i = 6; i < headerLength; i++)
			mo.write(0);
		for (int[] t : tracks) {
			if (t.length > 0 && t[0] == -1) {
				// a chunk of another kind
				str("XFIH");
				be32(t.length - 1);
				for (int i = 1; i < t.length; i++)
					mo.write(t[i]);
				continue;
			}
			str("MTrk");
			be32(t.length);
			for (int x : t)
				mo.write(x);
		}
		return mo.toByteArray();
	}

	static final int[] TEMPO_TRACK = {0, 0xFF, 0x51, 3, 0x07, 0xA1, 0x20, // 500000
			0x83, 0x60, 0xFF, 0x51, 3, 0x03, 0xD0, 0x90, // at 480: 250000
			0x87, 0x40, 0xFF, 0x51, 3, 0x0F, 0x42, 0x40, // at 1440: 1000000
			0x00, 0xFF, 0x01, 5, 'h', 'e', 'l', 'l', 'o',
			0x83, 0x60, 0xFF, 0x2F, 0};
	static final int[] NOTES = {0, 0x90, 60, 100, // note on
			0x60, 62, 100, // running status
			0x81, 0x40, 0x80, 60, 0, // at 192 note off
			0, 0xC5, 7, 0, 0xD5, 9, 0, 0xE5, 0, 64, 0, 0xB5, 7, 100,
			0x10, 0xF0, 3, 0x43, 0x12, 0xF7, // sysex
			0x05, 0xF7, 2, 1, 2, // escaped sysex
			0x00, 0x30, 0, // running status after sysex (0xB5 still)
			0x00, 0xFF, 0x51, 3, 0x01, 0x00, 0x00, // tempo in the second track
			0x00, 0xFF, 0x03, 0x81, 0x00}; // a meta with a 128-byte length (filled below)

	static int[] notesTrack(boolean withEnd) {
		int[] t = new int[NOTES.length + 128 + (withEnd ? 4 : 0)];
		System.arraycopy(NOTES, 0, t, 0, NOTES.length);
		for (int i = 0; i < 128; i++)
			t[NOTES.length + i] = 'a' + i % 26;
		if (withEnd) {
			t[t.length - 4] = 0x0F;
			t[t.length - 3] = 0xFF;
			t[t.length - 2] = 0x2F;
			t[t.length - 1] = 0;
		}
		return t;
	}

	static void readMidi(String name, byte[] data, File dir) {
		try {
			File f = new File(dir, "t.mid");
			FileOutputStream o = new FileOutputStream(f);
			o.write(data);
			o.close();
			readMidi(name, f);
		} catch (IOException e) {
			p(name + ": " + e);
		}
	}

	static void readMidi(String name, File f) {
		try {
			Sequence s = MidiSystem.getSequence(f);
			p(name + ": division " + s.getDivisionType() + " resolution " + s.getResolution() + " ticks " + s.getTickLength() + " us " + s.getMicrosecondLength() + " tracks " + s.getTracks().length);
			for (Track t : s.getTracks()) {
				long h = 17;
				StringBuilder kinds = new StringBuilder();
				for (int i = 0; i < t.size(); i++) {
					MidiEvent e = t.get(i);
					h = h * 31 + e.getTick();
					h = h * 31 + hash(e.getMessage().getMessage(), e.getMessage().getLength());
					MidiMessage mm = e.getMessage();
					if (i < 12)
						kinds.append(" ").append(mm instanceof ShortMessage ? "S" : mm instanceof MetaMessage ? "M" : mm instanceof SysexMessage ? "X" : "?").append(mm.getLength());
				}
				p("  track size " + t.size() + " ticks " + t.ticks() + " hash " + h + kinds);
			}
			Sequencer q = MidiSystem.getSequencer(false);
			q.open();
			q.setSequence(s);
			StringBuilder b = new StringBuilder("  positions");
			long[] ticks = {0, 1, 100, 479, 480, 481, 960, 1439, 1440, 1441, 2000, 3000, s.getTickLength()};
			for (long tk : ticks) {
				q.setTickPosition(tk);
				b.append(" ").append(tk).append(":").append(q.getMicrosecondPosition());
			}
			p(b + " length " + q.getTickLength() + " " + q.getMicrosecondLength());
			q.close();
		} catch (Exception e) {
			p(name + ": " + e.getClass().getName() + " " + e.getMessage());
		}
	}

	static void midiFiles(File dir, File repo) throws Exception {
		readMidi("type 1", smf(1, 2, 480, 6, new int[][]{TEMPO_TRACK, notesTrack(true)}), dir);
		readMidi("type 0 no end", smf(0, 1, 96, 6, new int[][]{notesTrack(false)}), dir);
		readMidi("header 8, other chunk", smf(1, 2, 480, 8, new int[][]{TEMPO_TRACK, {-1, 1, 2, 3}, notesTrack(true)}), dir);
		readMidi("fewer tracks than said", smf(1, 5, 480, 6, new int[][]{TEMPO_TRACK, notesTrack(true)}), dir);
		readMidi("smpte 25", smf(1, 2, 0xE728, 6, new int[][]{TEMPO_TRACK, notesTrack(true)}), dir);
		readMidi("smpte 29", smf(0, 1, 0xE350, 6, new int[][]{notesTrack(true)}), dir);
		readMidi("smpte 30", smf(0, 1, 0xE204, 6, new int[][]{notesTrack(true)}), dir);
		readMidi("smpte 23", smf(0, 1, 0xE904, 6, new int[][]{notesTrack(true)}), dir);
		readMidi("division 0", smf(0, 1, 0, 6, new int[][]{notesTrack(true)}), dir);
		readMidi("type 2", smf(2, 1, 480, 6, new int[][]{notesTrack(true)}), dir);
		readMidi("type 3", smf(3, 1, 480, 6, new int[][]{notesTrack(true)}), dir);
		readMidi("header 4", smf(0, 1, 480, 4, new int[][]{notesTrack(true)}), dir);
		readMidi("events after the end", smf(0, 1, 480, 6, new int[][]{{0, 0x90, 60, 100, 0x10, 0xFF, 0x2F, 0, 0x10, 0x90, 61, 100}}), dir);
		readMidi("end before the last note", smf(0, 1, 480, 6, new int[][]{{0, 0x90, 60, 100, 0x00, 0xFF, 0x2F, 0}, {0x40, 0x80, 60, 0, 0, 0xFF, 0x2F, 0}}), dir);
		readMidi("no running status", smf(0, 1, 480, 6, new int[][]{{0, 60, 100, 0, 0xFF, 0x2F, 0}}), dir);
		readMidi("running status after meta", smf(0, 1, 480, 6, new int[][]{{0, 0xFF, 0x01, 1, 'x', 0, 60, 100, 0, 0xFF, 0x2F, 0}}), dir);
		readMidi("system common", smf(0, 1, 480, 6, new int[][]{{0, 0xF2, 1, 2, 0, 0xFF, 0x2F, 0}}), dir);
		readMidi("meta type 200", smf(0, 1, 480, 6, new int[][]{{0, 0xFF, 200, 0, 0, 0xFF, 0x2F, 0}}), dir);
		readMidi("event cut short", smf(0, 1, 480, 6, new int[][]{{0, 0x90, 60}}), dir);
		readMidi("meta cut short", smf(0, 1, 480, 6, new int[][]{{0, 0xFF, 0x01, 10, 'a', 'b'}}), dir);
		byte[] full = smf(1, 2, 480, 6, new int[][]{TEMPO_TRACK, notesTrack(true)});
		readMidi("file cut short", java.util.Arrays.copyOf(full, full.length - 10), dir);
		readMidi("only the header", java.util.Arrays.copyOf(full, 14), dir);
		readMidi("header cut short", java.util.Arrays.copyOf(full, 10), dir);
		readMidi("not midi", "RIFF....WAVEfmt ".getBytes("ISO-8859-1"), dir);
		readMidi("empty", new byte[0], dir);
		try {
			MidiSystem.getSequence(new File(dir, "nothing.mid"));
		} catch (FileNotFoundException e) {
			p("missing file: FileNotFoundException");
		}
		Sequence fromStream = MidiSystem.getSequence(new ByteArrayInputStream(full));
		p("from a stream: " + fromStream.getTracks().length + " tracks, " + fromStream.getTickLength() + " ticks");
		if (repo != null)
			readMidi("GLEE3.MID", new File(repo, "assets/GROUNDZERO/GLEE3.MID"));
	}

	// ---------------------------------------------------------------- sequencer clock

	static void sequencer(File dir) throws Exception {
		// 120 bpm, 96 ticks per quarter: 192 ticks = 1 s, then a tempo change to 4x as fast
		mo = null;
		byte[] data = smf(0, 1, 96, 6, new int[][]{{0, 0x90, 60, 100, 0x60, 0x80, 60, 0, // 0.5 s
				0, 0xFF, 0x51, 3, 0x01, 0xE8, 0x48, // 125000 us per quarter
				0x81, 0x40, 0xFF, 0x2F, 0}}); // +192 ticks = 0.25 s
		Sequence s = MidiSystem.getSequence(new ByteArrayInputStream(data));
		Sequencer q = MidiSystem.getSequencer(false);
		p("sequencer open " + q.isOpen() + " running " + q.isRunning() + " length " + s.getMicrosecondLength());
		q.setSequence(s);
		try {
			q.start();
			p("started while closed");
		} catch (IllegalStateException e) {
			p("start while closed: IllegalStateException");
		}
		q.open();
		p("open " + q.isOpen() + " factor " + q.getTempoFactor() + " loops " + q.getLoopCount());
		long t0 = System.currentTimeMillis();
		q.start();
		p("running " + q.isRunning());
		Thread.sleep(300);
		long tick = q.getTickPosition();
		p("at 0.3 s running " + q.isRunning() + " tick about 58: " + (tick >= 40 && tick <= 80));
		while (q.isRunning() && System.currentTimeMillis() - t0 < 3000)
			Thread.sleep(10);
		long took = System.currentTimeMillis() - t0;
		p("ended by itself " + !q.isRunning() + " after about 0.75 s: " + (took >= 650 && took <= 1100) + " tick " + q.getTickPosition() + " tempo " + q.getTempoInMPQ());
		q.setTickPosition(0);
		q.start();
		Thread.sleep(100);
		q.stop();
		tick = q.getTickPosition();
		p("stopped " + !q.isRunning() + " at about 19: " + (tick >= 10 && tick <= 35));
		Thread.sleep(150);
		p("still there " + (q.getTickPosition() == tick));
		q.setMicrosecondPosition(500000);
		p("500000 us is tick " + q.getTickPosition());
		q.close();
		p("closed " + q.isOpen() + " running " + q.isRunning());
	}
}
