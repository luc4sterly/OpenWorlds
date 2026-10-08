package conformance;

import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;

/**
 * The runtime library as the 2004 client and the bridge use it: character
 * encodings, readers and writers, java.io.File, RandomAccessFile,
 * java.nio.file, System properties, threads. Printed output must be the
 * same on a JVM and transpiled (vita/tools/run-conformance.sh). Works in the
 * directory given as the first argument.
 */
public class RuntimeConformance {
	static void p(Object o) { System.out.println(o); }

	static String hex(byte[] b) {
		StringBuilder sb = new StringBuilder();
		for (byte x : b) sb.append(Character.forDigit((x >> 4) & 0xF, 16)).append(Character.forDigit(x & 0xF, 16));
		return sb.toString();
	}

	static String codes(String s) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length(); i++) sb.append(i > 0 ? " " : "").append(Integer.toHexString(s.charAt(i)));
		return sb.toString();
	}

	/** Gives one byte per read: decoding must survive sequences cut anywhere. */
	static class Trickle extends InputStream {
		final byte[] data; int pos;
		Trickle(byte[] data) { this.data = data; }
		public int read() { return pos < data.length ? data[pos++] & 0xFF : -1; }
		public int read(byte[] b, int off, int len) {
			if (len == 0) return 0;
			if (pos >= data.length) return -1;
			b[off] = data[pos++];
			return 1;
		}
	}

	public static void main(String[] args) throws Exception {
		File dir = new File(args[0]);
		p("args " + args.length);
		encodings();
		readersWriters();
		files(dir);
		randomAccess(dir);
		nio(dir);
		system();
		misc(dir);
		threads();
	}

	static void encodings() throws Exception {
		byte[] utf8 = {0x41, (byte) 0xC3, (byte) 0xA9, (byte) 0xE2, (byte) 0x82, (byte) 0xAC, (byte) 0xF0, (byte) 0x9F, (byte) 0x98, (byte) 0x80};
		p("utf8 " + codes(new String(utf8, "UTF-8")));
		byte[] bad = {0x41, (byte) 0x80, 0x42, (byte) 0xC3, 0x43, (byte) 0xE2, (byte) 0x82, 0x44, (byte) 0xED, (byte) 0xA0, (byte) 0x80, (byte) 0xC0, (byte) 0xAF, (byte) 0xF8, (byte) 0xE2, (byte) 0x82};
		p("utf8 bad " + codes(new String(bad, "UTF-8")));
		byte[] high = new byte[64];
		for (int i = 0; i < 64; i++) high[i] = (byte) (0x80 + i * 2);
		p("latin1 " + codes(new String(high, "ISO-8859-1")));
		p("cp1252 " + codes(new String(high, "Cp1252")));
		p("windows-1252 " + codes(new String(high, "windows-1252")));
		p("ascii " + codes(new String(high, 0, 4, "US-ASCII")));
		p("utf16 bom " + codes(new String(new byte[]{(byte) 0xFF, (byte) 0xFE, 0x41, 0, 0x42, 0}, "UTF-16")));
		p("utf16 " + codes(new String(new byte[]{0, 0x41, 0x30, 0x42, 0x43}, "UTF-16")));
		p("utf16le " + codes(new String(new byte[]{0x41, 0, 0x42, 0x30}, "UTF-16LE")));
		String s = "Aé€Œ中😀\ud800z";
		for (String cs : new String[]{"UTF-8", "ISO-8859-1", "US-ASCII", "Cp1252", "UTF-16", "UTF-16BE", "UTF-16LE", "UTF8", "ISO8859_1", "latin1"})
			p("encode " + cs + " " + hex(s.getBytes(cs)));
		p("default " + hex("é€".getBytes()) + " " + codes(new String(new byte[]{(byte) 0xC3, (byte) 0xA9})));
		p("charset " + Charset.forName("cp1252").name() + " " + Charset.forName("utf8").name() + " " + Charset.isSupported("windows-1252") + " " + Charset.isSupported("x-nothing"));
		p("charset bytes " + hex("€".getBytes(Charset.forName("windows-1252"))) + " " + codes(new String(new byte[]{(byte) 0x80}, Charset.forName("windows-1252"))));
		try {
			new String(new byte[1], "x-nothing");
			p("no exception");
		} catch (UnsupportedEncodingException e) {
			p("unsupported " + e.getMessage());
		}
		byte[] hb = {0x41, 0x42, (byte) 0xC9};
		p("hibyte " + codes(new String(hb, 0x12)) + " " + codes(new String(hb, 0, 1, 2)));
		byte[] dst = new byte[4];
		"Łbcd".getBytes(0, 3, dst, 1);
		p("getBytes4 " + hex(dst));
		p("join " + String.join("-", "a", "b", "c") + " " + String.join(", ", Arrays.asList("x", "y")));
	}

	static void readersWriters() throws Exception {
		byte[] utf8 = "héllo € 😀 end".getBytes("UTF-8");
		Reader r = new InputStreamReader(new Trickle(utf8), "UTF-8");
		StringBuilder sb = new StringBuilder();
		for (int c; (c = r.read()) >= 0; ) sb.append((char) c);
		p("trickle " + codes(sb.toString()));
		byte[] cut = {0x41, (byte) 0xE2, (byte) 0x82};
		BufferedReader br = new BufferedReader(new InputStreamReader(new ByteArrayInputStream(cut), "UTF-8"));
		p("cut " + codes(br.readLine()) + " " + br.readLine());
		BufferedReader lines = new BufferedReader(new InputStreamReader(new ByteArrayInputStream("one\r\ntwo\nthree\rfour".getBytes("ISO-8859-1")), "ISO-8859-1"));
		for (String l; (l = lines.readLine()) != null; ) p("line [" + l + "]");
		char[] buf = new char[5];
		Reader r2 = new InputStreamReader(new ByteArrayInputStream("abcdefgh".getBytes()));
		int n = r2.read(buf, 1, 3);
		p("read " + n + " " + new String(buf, 1, n));
		for (String cs : new String[]{"UTF-8", "Cp1252", "UTF-16", "ISO-8859-1"}) {
			ByteArrayOutputStream bo = new ByteArrayOutputStream();
			Writer w = new OutputStreamWriter(bo, cs);
			w.write("xé€");
			w.write('\ud83d');
			w.write('\ude00');
			w.write("!", 0, 1);
			w.close();
			p("writer " + cs + " " + hex(bo.toByteArray()));
		}
		ByteArrayOutputStream bo = new ByteArrayOutputStream();
		Writer w = new OutputStreamWriter(bo, Charset.forName("UTF-8"));
		w.write("a");
		p("unflushed " + bo.size());
		w.flush();
		p("flushed " + bo.size());
	}

	static void files(File dir) throws Exception {
		File a = new File("a//b///c/");
		p("path " + a.getPath() + " name " + a.getName() + " parent " + a.getParent() + " abs " + a.isAbsolute() + " str " + a);
		File root = new File("/");
		p("root " + root.getPath() + " name [" + root.getName() + "] parent " + root.getParent());
		File x = new File("/x");
		p("x parent " + x.getParent() + " name " + x.getName());
		p("child " + new File("p", "q").getPath() + " " + new File((String) null, "q").getPath() + " " + new File("", "q").getPath() + " " + new File(new File("/"), "q").getPath());
		p("equals " + new File("a/b").equals(new File("a//b/")) + " " + (new File("a/b").hashCode() == new File("a/b/").hashCode()) + " " + new File("a").compareTo(new File("b")));
		p("relative abs " + new File("rel/f").getAbsolutePath().endsWith("/rel/f") + " " + new File("rel/f").getAbsoluteFile().isAbsolute());
		File d = new File(dir, "files");
		p("mkdirs " + new File(d, "x/y").mkdirs() + " again " + new File(d, "x/y").mkdirs() + " isDir " + new File(d, "x").isDirectory());
		File f = new File(d, "one.txt");
		p("create " + f.createNewFile() + " again " + f.createNewFile() + " isFile " + f.isFile() + " isDir " + f.isDirectory() + " exists " + f.exists());
		FileOutputStream out = new FileOutputStream(f);
		out.write("hello".getBytes());
		out.close();
		p("length " + f.length() + " missing length " + new File(d, "none").length() + " missing isFile " + new File(d, "none").isFile());
		long t = 1234567890000L;
		p("setLastModified " + f.setLastModified(t) + " " + f.lastModified());
		File g = new File(d, "two.txt");
		p("rename " + f.renameTo(g) + " " + f.exists() + " " + g.exists());
		new File(d, "b.dat").createNewFile();
		String[] names = d.list();
		Arrays.sort(names);
		p("list " + Arrays.toString(names));
		String[] txt = d.list(new FilenameFilter() {
			public boolean accept(File dd, String name) { return name.endsWith(".txt"); }
		});
		p("filtered " + Arrays.toString(txt));
		File[] fs = d.listFiles();
		Arrays.sort(fs);
		p("listFiles " + fs.length + " " + fs[0].getName());
		p("list of a file " + g.list());
		p("canonical " + new File(d, "x/../two.txt").getCanonicalPath().equals(g.getCanonicalPath()));
		p("delete " + g.delete() + " " + new File(d, "x").delete() + " " + g.exists());
		p("read " + new File(d, "b.dat").canRead() + " write " + new File(d, "b.dat").canWrite());
		FileInputStream in = new FileInputStream(new File(d, "b.dat"));
		p("empty read " + in.read());
		in.close();
		try {
			new FileInputStream(new File(d, "nothing"));
		} catch (FileNotFoundException e) {
			p("not found");
		}
	}

	static void randomAccess(File dir) throws Exception {
		File f = new File(dir, "raf.bin");
		RandomAccessFile raf = new RandomAccessFile(f, "rw");
		raf.writeInt(0x12345678);
		raf.writeUTF("café");
		raf.writeBytes("line one\r\nline two\nlast");
		raf.writeLong(-2);
		raf.writeDouble(1.5);
		p("pointer " + raf.getFilePointer() + " length " + raf.length());
		raf.seek(0);
		p("int " + Integer.toHexString(raf.readInt()) + " utf " + raf.readUTF());
		p("lines [" + raf.readLine() + "] [" + raf.readLine() + "]");
		raf.seek(raf.getFilePointer() + 4);
		p("long " + raf.readLong() + " double " + raf.readDouble());
		try {
			raf.readInt();
		} catch (EOFException e) {
			p("eof");
		}
		raf.setLength(4);
		p("setLength " + raf.length() + " pointer " + raf.getFilePointer());
		raf.seek(0);
		byte[] b = new byte[8];
		p("read " + raf.read(b) + " " + hex(Arrays.copyOf(b, 4)) + " then " + raf.read());
		raf.close();
		RandomAccessFile ro = new RandomAccessFile(f.getPath(), "r");
		try {
			ro.write(1);
		} catch (IOException e) {
			p("read only");
		}
		p("lock " + (new RandomAccessFile(new File(dir, "lock"), "rw").getChannel().tryLock() != null));
		ro.close();
		try {
			new RandomAccessFile(new File(dir, "nope/x"), "r");
		} catch (FileNotFoundException e) {
			p("raf not found");
		}
	}

	static void nio(File dir) throws Exception {
		Path p = new File(dir, "nio.txt").toPath();
		Files.write(p, "first\nsecond\n".getBytes("UTF-8"));
		p("bytes " + Files.readAllBytes(p).length + " lines " + Files.readAllLines(p) + " size " + Files.size(p) + " exists " + Files.exists(p));
		List<String> l = Files.readAllLines(Paths.get(dir.getPath(), "nio.txt"));
		p("paths " + l.size() + " name " + p.getFileName() + " parent " + p.getParent().equals(dir.toPath()) + " toFile " + p.toFile().equals(new File(dir, "nio.txt")));
		p("normalize " + Paths.get("a/./b/../c").normalize() + " resolve " + Paths.get("a").resolve("b") + " abs " + Paths.get("/x").isAbsolute());
		try {
			Files.readAllBytes(Paths.get(dir.getPath(), "missing"));
		} catch (IOException e) {
			p("missing " + e.getClass().getSimpleName());
		}
		p("dev " + (Files.getAttribute(p, "unix:dev") instanceof Long));
	}

	static void system() {
		p("separators " + codes(System.getProperty("line.separator")) + " " + System.getProperty("file.separator") + " " + System.getProperty("path.separator") + " " + codes(System.lineSeparator()));
		p("user.dir " + (System.getProperty("user.dir") != null) + " " + new File(System.getProperty("user.dir")).isAbsolute());
		p("set " + System.setProperty("conf.key", "v1") + " " + System.getProperty("conf.key") + " " + System.setProperty("conf.key", "v2") + " " + System.getProperties().get("conf.key"));
		p("clear " + System.clearProperty("conf.key") + " " + System.getProperty("conf.key") + " " + System.getProperty("conf.key", "def"));
		System.setProperty("conf.flag", "TRUE");
		p("getBoolean " + Boolean.getBoolean("conf.flag") + " " + Boolean.getBoolean("conf.none"));
		p("decode " + Integer.decode("0x1F") + " " + Integer.decode("#ff") + " " + Integer.decode("010") + " " + Integer.decode("-12") + " " + Integer.decode("0") + " " + Integer.decode("-0x80000000"));
		try {
			Integer.decode("");
		} catch (NumberFormatException e) {
			p("decode empty");
		}
		p("float " + new Float("1.5") + " " + new Float("-2e3"));
		p("eof message " + new EOFException("end").getMessage() + " assertion " + new AssertionError("boom").getMessage() + " " + new AssertionError(7).getMessage());
		p("processors " + (Runtime.getRuntime().availableProcessors() > 0));
		try {
			Runtime.getRuntime().exec("definitely-not-a-program-xyz");
			p("exec ran");
		} catch (IOException e) {
			p("exec IOException");
		}
		PrintStream old = System.out;
		ByteArrayOutputStream captured = new ByteArrayOutputStream();
		System.setOut(new PrintStream(captured, true));
		System.out.println("captured");
		System.setOut(old);
		p("setOut " + captured.toString().trim());
	}

	static void misc(File dir) throws Exception {
		java.text.NumberFormat nf = java.text.NumberFormat.getNumberInstance(java.util.Locale.US);
		double[] ds = {0, 1, 12345, 1234567.891, 0.5, 2.5, 3.5, 1.0005, 1.0015, 0.0001, -0.0001, -1234.5, 1e15, 123.456789, Double.NaN, 1 / 0.0};
		StringBuilder sb = new StringBuilder();
		for (double d : ds) sb.append('[').append(nf.format(d)).append(']');
		p("numbers " + sb);
		p("longs " + nf.format(0L) + " " + nf.format(999L) + " " + nf.format(1000L) + " " + nf.format(-1234567L) + " " + java.text.NumberFormat.getInstance().format(42 / 1000));
		nf.setMaximumFractionDigits(1);
		nf.setMinimumFractionDigits(1);
		nf.setGroupingUsed(false);
		p("fraction " + nf.format(1234.56) + " " + nf.format(2) + " " + nf.isGroupingUsed());
		java.util.Calendar cal = java.util.Calendar.getInstance(java.util.TimeZone.getTimeZone("GMT"));
		cal.clear();
		cal.set(2004, java.util.Calendar.MARCH, 15, 10, 30, 45);
		p("calendar " + cal.getTime().getTime() + " " + cal.get(java.util.Calendar.DAY_OF_WEEK));
		p("utc " + java.util.Date.UTC(104, 2, 15, 10, 30, 45) + " " + java.util.Date.UTC(70, 0, 1, 0, 0, 0) + " " + java.util.Date.UTC(99, 13, 1, 0, 0, 0));
		p("base64 " + java.util.Base64.getEncoder().encodeToString("Worlds.com chat".getBytes()) + " " + java.util.Base64.getEncoder().encodeToString(new byte[]{(byte) 0xFF, 0}) + " " + new String(java.util.Base64.getDecoder().decode("V29ybGRz")));
		final java.util.concurrent.CountDownLatch latch = new java.util.concurrent.CountDownLatch(3);
		for (int i = 0; i < 3; i++)
			new Thread(new Runnable() { public void run() { latch.countDown(); } }).start();
		latch.await();
		p("latch " + latch.getCount());
		String name = java.lang.management.ManagementFactory.getRuntimeMXBean().getName();
		p("runtime bean " + name.matches("[0-9]+@.+") + " os bean " + (java.lang.management.ManagementFactory.getOperatingSystemMXBean().getAvailableProcessors() > 0));
		PrintWriter pw = new PrintWriter(new File(dir, "pw.txt"), "UTF-8");
		pw.println("pr\u00e9");
		pw.close();
		p("printwriter " + hex(Files.readAllBytes(new File(dir, "pw.txt").toPath())));
		p("link error " + new UnsatisfiedLinkError("no lib").getMessage() + " " + (new UnsatisfiedLinkError() instanceof LinkageError));
	}

	static void threads() throws Exception {
		Thread t = new Thread(new Runnable() { public void run() { } });
		p("daemon " + t.isDaemon() + " name " + t.getName().startsWith("Thread-") + " group " + (t.getThreadGroup() != null));
		p("main " + Thread.currentThread().getName() + " " + Thread.currentThread().getPriority() + " " + Thread.currentThread().getThreadGroup().getName() + " priority " + t.getPriority());
		t.setPriority(Thread.MAX_PRIORITY);
		p("priority " + t.getPriority() + " child " + new Thread(t, "named").getName());
		final boolean[] alive = new boolean[2];
		Thread quick = new Thread(new Runnable() { public void run() { alive[0] = true; } });
		quick.start();
		alive[1] = quick.isAlive() || alive[0];
		quick.join();
		p("alive after start " + alive[1] + " ran " + alive[0] + " after join " + quick.isAlive());
		try {
			quick.start();
			p("restarted");
		} catch (IllegalThreadStateException e) {
			p("start twice throws");
		}
		final boolean[] inner = new boolean[1];
		Thread d = new Thread(new Runnable() {
			public void run() { inner[0] = new Thread().isDaemon(); }
		});
		d.setDaemon(true);
		d.start();
		d.join();
		p("inherited " + inner[0]);
		try {
			d.setDaemon(false);
			p("setDaemon after start ok");
		} catch (IllegalThreadStateException e) {
			p("setDaemon after start throws");
		}
		Object lock = new Object();
		boolean before = Thread.holdsLock(lock);
		boolean inside;
		synchronized (lock) {
			inside = Thread.holdsLock(lock);
		}
		p("holdsLock " + before + " " + inside);
		// the program must go on after main while this thread runs (a JVM waits for non-daemon threads)
		Thread late = new Thread(new Runnable() {
			public void run() {
				try {
					Thread.sleep(300);
				} catch (InterruptedException e) {
				}
				p("late thread");
			}
		});
		late.start();
		Thread forever = new Thread(new Runnable() {
			public void run() {
				while (true) {
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
					}
				}
			}
		});
		forever.setDaemon(true);
		forever.start();
		p("main done");
	}
}
