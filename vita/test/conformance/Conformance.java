package conformance;

import java.util.*;

/**
 * Prints the results of Java semantics the 2004 client relies on. Transpiled
 * with Clearwing VM its output must be the same as on a JVM
 * (vita/tools/run-conformance.sh).
 *
 * Known differences, left out because the client does not depend on them:
 * HashMap's iteration order (the client only gets and puts), and storing an
 * object of the wrong type into an array (no ArrayStoreException).
 */
public class Conformance {
	static int sideEffects;
	static class Base { int v() { return 1; } static String s = init("Base"); }
	static class Derived extends Base { int v() { return 2; } static String t = init("Derived"); }
	static String init(String n) { sideEffects++; System.out.println("clinit " + n); return n; }
	interface Shape { int area(); }
	static volatile boolean flag;

	static void p(Object o) { System.out.println(o); }

	public static void main(String[] args) throws Exception {
		int imin = Integer.MIN_VALUE, m1 = -1, zero = 0, big = Integer.MAX_VALUE;
		long lmin = Long.MIN_VALUE, lm1 = -1;
		p("ints " + (big + 1) + " " + (imin / m1) + " " + (imin % m1) + " " + (-7 / 2) + " " + (-7 % 2) + " " + (7 % -2) + " " + (big * 3));
		p("longs " + (lmin / lm1) + " " + (lmin % lm1) + " " + (Long.MAX_VALUE + 1) + " " + (-7L / 2) + " " + (-7L % 2));
		int s33 = 33, sm1 = -1, s65 = 65;
		p("shifts " + (1 << s33) + " " + (-8 >> s33) + " " + (-8 >>> s33) + " " + (1 << sm1) + " " + (1L << s65) + " " + (-1L >>> s65) + " " + (-1 >>> 28) + " " + (0x80000000 >> 31));
		try { p(5 / zero); } catch (ArithmeticException e) { p("div0 " + e.getClass().getName()); }
		try { p(5L % (long) zero); } catch (ArithmeticException e) { p("rem0 " + e.getClass().getName()); }
		float fnan = Float.NaN; double dinf = Double.POSITIVE_INFINITY;
		double[] ds = { Double.NaN, dinf, -dinf, 1e10, -1e10, 3.99, -3.99, 2147483647.5, -2147483648.7, 1e19, -1e19 };
		StringBuilder sb = new StringBuilder("d2i");
		for (double d : ds) sb.append(' ').append((int) d).append('/').append((long) d);
		p(sb);
		sb = new StringBuilder("f2i");
		for (double d : ds) { float f = (float) d; sb.append(' ').append((int) f).append('/').append((long) f); }
		p(sb + " " + (int) fnan);
		p("chars " + (char) 65 + " " + (int) 'z' + " " + (char) ('a' + 2) + " " + (byte) 200 + " " + (short) 70000 + " " + (char) -1 + (int) (char) -1);
		double[] dv = { 0.1, 1.0 / 3, 100.0, 1e7, 9999999.0, 1.234e-5, 0.001, 123456789.0, Math.PI, -0.0, 1e-300, 4.9e-324, 1.7976931348623157e308, 2.5, 100.5, 0.5, 1e21, 12345.678 };
		sb = new StringBuilder("dstr");
		for (double d : dv) sb.append(' ').append(d);
		p(sb);
		float[] fv = { 0.1f, 1.0f / 3, 100.0f, 1e7f, 3.4028235e38f, 1.4e-45f, -0.0f, 0.001f, 16777216f, 1.5f, 123.456f };
		sb = new StringBuilder("fstr");
		for (float f : fv) sb.append(' ').append(f);
		p(sb + " " + Float.NaN + " " + Double.NEGATIVE_INFINITY);
		p("parse " + Double.parseDouble("1.5e3") + " " + Float.parseFloat("-2.25") + " " + Integer.parseInt("-123") + " " + Long.parseLong("9000000000") + " " + Integer.parseInt("7fffffff", 16) + " " + Double.valueOf(" 3.0 "));
		p("hex " + Integer.toHexString(-1) + " " + Integer.toHexString(255) + " " + Long.toHexString(-2L) + " " + Integer.toBinaryString(10) + " " + Integer.toOctalString(64) + " " + Integer.toString(-255, 16));
		p("math " + Math.sqrt(2) + " " + Math.sin(1) + " " + Math.cos(1) + " " + Math.atan2(1, 2) + " " + Math.floor(-2.5) + " " + Math.ceil(-2.5) + " " + Math.round(-2.5) + " " + Math.round(2.5) + " " + Math.round(-2.5f) + " " + Math.pow(2, 0.5) + " " + Math.abs(imin) + " " + Math.exp(1) + " " + Math.log(10) + " " + Math.tan(0.5) + " " + Math.asin(0.5) + " " + Math.acos(0.5) + " " + Math.atan(1) + " " + Math.rint(2.5) + " " + Math.max(-0.0, 0.0) + " " + Math.min(Float.NaN, 1f));
		p("strings " + "hello".hashCode() + " " + "".hashCode() + " " + "Hello World".toUpperCase() + " " + "MiXeD".toLowerCase() + " [" + "  trim me \t".trim() + "] " + "abcabc".indexOf("c", 3) + " " + "abcabc".lastIndexOf('b') + " " + "abc".compareTo("abd") + " " + "b".compareToIgnoreCase("A") + " " + "a,b,,c".indexOf(",,"));
		p("substr " + "hello".substring(1, 3) + " " + "hello".charAt(4) + " " + "hello".replace('l', 'L') + " " + "a.b.c".replace(".", "::") + " " + "abc".startsWith("ab") + " " + "abc".endsWith("bc") + " " + "ABC".equalsIgnoreCase("abc") + " " + String.valueOf(new char[] { 'o', 'k' }) + " " + "tab\there".length());
		sb = new StringBuilder("buf");
		StringBuffer buf = new StringBuffer("abcdef");
		buf.insert(2, "XY").reverse().setLength(5);
		buf.append(1.5f).append('c').append(true).append(7L).append((Object) null);
		p(sb.append(' ').append(buf).append(' ').append(buf.length()).append(' ').append(buf.indexOf("1.5")));
		StringTokenizer st = new StringTokenizer("a b\tc,,d", " \t,");
		sb = new StringBuilder("tok " + st.countTokens());
		while (st.hasMoreTokens()) sb.append(' ').append(st.nextToken());
		st = new StringTokenizer("x=1;y=2", "=;", true);
		while (st.hasMoreTokens()) sb.append('|').append(st.nextToken());
		p(sb);
		Hashtable<String, Integer> ht = new Hashtable<>();
		String[] keys = { "alpha", "beta", "gamma", "delta", "epsilon", "zeta", "eta", "theta", "iota", "kappa", "lambda", "mu", "nu" };
		for (int i = 0; i < keys.length; i++) ht.put(keys[i], i);
		sb = new StringBuilder("hashtable");
		for (Enumeration<String> e = ht.keys(); e.hasMoreElements();) sb.append(' ').append(e.nextElement());
		p(sb + " " + ht.get("mu") + " " + ht.containsKey("x") + " " + ht.size());
		HashMap<String, Integer> hm = new HashMap<>();
		for (int i = 0; i < keys.length; i++) hm.put(keys[i], i);
		hm.remove("beta");
		p("hashmap " + hm.get("gamma") + " " + hm.get("beta") + " " + hm.size() + " " + hm.containsKey("nu"));
		LinkedHashMap<String, Integer> lhm = new LinkedHashMap<>();
		for (int i = keys.length - 1; i >= 0; i--) lhm.put(keys[i], i);
		p("linked " + lhm.values());
		TreeMap<String, Integer> tm = new TreeMap<>();
		for (int i = 0; i < keys.length; i++) tm.put(keys[i], i);
		tm.remove("mu");
		p("tree " + tm.keySet() + " " + tm.get("eta"));
		Vector<Object> v = new Vector<>();
		v.addElement("one"); v.insertElementAt("zero", 0); v.addElement(3); v.removeElementAt(1); v.setElementAt("x", 1);
		p("vector " + v + " " + v.indexOf("x") + " " + v.contains("one") + " " + v.firstElement() + " " + v.lastElement());
		Stack<Integer> stk = new Stack<>(); stk.push(1); stk.push(2); p("stack " + stk.pop() + " " + stk.peek() + " " + stk.empty());
		Random r = new Random(42);
		p("random " + r.nextInt() + " " + r.nextInt(100) + " " + r.nextDouble() + " " + r.nextLong() + " " + r.nextFloat() + " " + r.nextBoolean() + " " + r.nextGaussian());
		int[] arr = { 1, 2, 3, 4, 5 };
		System.arraycopy(arr, 0, arr, 1, 4);
		int[] cl = arr.clone(); cl[0] = 9;
		p("arrays " + Arrays.toString(arr) + " " + Arrays.toString(cl) + " " + new int[3][4][2].length + " " + new int[3][4][2][1].length);
		try { int[] a = new int[2]; int idx = -1; a[idx] = 1; } catch (ArrayIndexOutOfBoundsException e) { p("aioobe neg"); }
		try { int[] a = new int[2]; a[2] = 1; } catch (ArrayIndexOutOfBoundsException e) { p("aioobe"); }
		try { Object o = "s"; Integer i = (Integer) o; p(i); } catch (ClassCastException e) { p("cce"); }
		try { int n = -1; int[] a = new int[n]; p(a); } catch (NegativeArraySizeException e) { p("nase"); }
		try { String s = null; s.length(); } catch (NullPointerException e) { p("npe"); }
		try { System.arraycopy(arr, 3, arr, 0, 5); } catch (IndexOutOfBoundsException e) { p("arraycopy " + (e instanceof ArrayIndexOutOfBoundsException)); }
		try { "abc".charAt(5); } catch (IndexOutOfBoundsException e) { p("charAt ioobe"); }
		try { Integer.parseInt("12x"); } catch (NumberFormatException e) { p("nfe"); }
		p("finally " + tryFinally());
		p("exceptions " + exceptions());
		Base b = new Derived();
		p("virtual " + b.v() + " " + (b instanceof Derived) + " " + sideEffects + " " + Derived.t);
		Shape sq = () -> 4;
		Shape anon = new Shape() { public int area() { return 9; } };
		p("iface " + sq.area() + " " + anon.area() + " " + (anon instanceof Shape));
		String sw = "beta"; int swr;
		switch (sw) { case "alpha": swr = 1; break; case "beta": swr = 2; break; default: swr = 3; }
		p("switch " + swr);
		final Object lock = new Object();
		final int[] got = new int[1];
		Thread t = new Thread() { public void run() { synchronized (lock) { got[0] = 1; lock.notifyAll(); } } };
		synchronized (lock) { t.start(); while (got[0] == 0) lock.wait(); }
		t.join();
		Thread sleeper = new Thread(() -> { try { Thread.sleep(10000); } catch (InterruptedException e) { flag = true; } });
		sleeper.start(); Thread.sleep(50); sleeper.interrupt(); sleeper.join(2000);
		p("threads " + got[0] + " " + t.isAlive() + " interrupted=" + flag);
		long t0 = System.currentTimeMillis(); Thread.sleep(20); long dt = System.currentTimeMillis() - t0;
		p("sleep " + (dt >= 15 && dt < 1000));
		p("integer " + Integer.valueOf(127).equals(127) + " " + Integer.MAX_VALUE + " " + Long.MIN_VALUE + " " + Character.isDigit('5') + " " + Character.isLetter('x') + " " + Character.toUpperCase('q') + " " + Character.isWhitespace('\t') + " " + Character.digit('f', 16) + " " + Character.forDigit(11, 16));
		p("bits " + Float.floatToIntBits(1.5f) + " " + Double.doubleToLongBits(-2.0) + " " + Float.intBitsToFloat(0x40490fdb) + " " + Integer.bitCount(255) + " " + Long.numberOfTrailingZeros(64));
		p("done");
	}

	static synchronized void lockedThrow() { throw new IllegalStateException("locked"); }

	static String exceptions() {
		StringBuilder r = new StringBuilder();
		for (int i = 0; i < 4; i++) {
			try {
				if (i == 0) throw new java.io.FileNotFoundException("f");
				if (i == 1) throw new java.io.IOException("io");
				if (i == 2) throw new IllegalArgumentException("ia");
				r.append("none");
			} catch (java.io.FileNotFoundException e) {
				r.append("fnf,");
			} catch (java.io.IOException e) {
				r.append("io,");
			} catch (RuntimeException e) {
				r.append("rt:").append(e.getMessage()).append(',');
			} finally {
				r.append('f').append(i).append(';');
			}
		}
		outer:
		for (int i = 0; i < 3; i++) {
			try {
				try {
					if (i == 1) continue outer;
					if (i == 2) break outer;
					r.append("body").append(i);
				} finally {
					r.append("[in").append(i).append(']');
				}
			} finally {
				r.append("[out").append(i).append(']');
			}
		}
		try {
			try {
				throw new RuntimeException("a");
			} catch (RuntimeException e) {
				throw new IllegalStateException("b:" + e.getMessage());
			}
		} catch (IllegalStateException e) {
			r.append(" nested=").append(e.getMessage());
		}
		final Object lock = Conformance.class;
		try { lockedThrow(); } catch (IllegalStateException e) { r.append(" locked"); }
		Thread other = new Thread(() -> { synchronized (lock) { flag = !flag; } });
		other.start();
		try { other.join(2000); } catch (InterruptedException e) { }
		r.append(" released=").append(!other.isAlive());
		try { recurse(0); } catch (StackOverflowError e) { r.append(" soe"); }
		return r.toString();
	}

	static int recurse(int n) { return recurse(n + 1) + 1; }

	static int tryFinally() {
		int x = 1;
		try { x = 2; throw new RuntimeException("x"); }
		catch (RuntimeException e) { x = 3; return x; }
		finally { x = 4; System.out.println("in finally " + x); }
	}
}
