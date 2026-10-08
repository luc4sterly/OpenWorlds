package conformance;

import java.io.*;
import java.net.*;

/**
 * java.net as the client and the bridge use it: URL parsing, name lookups,
 * sockets (refused, timeouts, end of stream) and HTTP through URL against a
 * small server of its own on the loopback. Same output on a JVM and
 * transpiled (vita/tools/run-conformance.sh).
 */
public class NetConformance {
	static void p(Object o) { System.out.println(o); }

	static String url(URL u) {
		return u + " | " + u.getProtocol() + " | " + u.getHost() + " | " + u.getPort() + " | " + u.getFile() + " | " + u.getPath() + " | " + u.getQuery() + " | " + u.getRef() + " | " + u.getAuthority();
	}

	public static void main(String[] args) throws Exception {
		File dir = new File(args[0]);
		urls(dir);
		lookups();
		sockets();
		http();
		p("done");
	}

	static void urls(File dir) throws Exception {
		String[] specs = {"http://www.worlds.com/index.html", "http://host:8080/a/b?q=1#frag", "http://host", "http://host?x", "HTTP://Host/A",
				"file:/tmp/x.txt", "file:///tmp/x.txt", "file:rel/x", "http://user@host:81/p", "url:http://h/p", "  http://h/sp  "};
		for (String s : specs)
			p("url " + url(new URL(s)));
		URL base = new URL("http://h/a/b/c.html?x=1#r");
		String[] rel = {"d.html", "../d.html", "../../../d", "./d", "/root", "?q2", "#r2", "", "//other/x", "http:rel", "g/./h/../i", "d/.."};
		for (String s : rel)
			p("rel [" + s + "] " + url(new URL(base, s)));
		p("ctor " + url(new URL("http", "1.2.3.4", 80, "/up/x.lst?123")) + " / " + url(new URL("http", "h", -1, "/f#a")));
		String[] bad = {"nothing", "foo://x", ":x", ""};
		for (String s : bad) {
			try {
				new URL(s);
				p("bad accepted " + s);
			} catch (MalformedURLException e) {
				p("malformed [" + s + "] " + e.getMessage());
			}
		}
		p("equals " + new URL("http://H/x").equals(new URL("http://h:80/x")) + " " + new URL("http://h/x#a").equals(new URL("http://h/x#b")) + " sameFile " + new URL("http://h/x#a").sameFile(new URL("http://h/x#b")));
		File f = new File(dir, "file url.txt");
		FileOutputStream out = new FileOutputStream(f);
		out.write("file body".getBytes());
		out.close();
		URL fu = f.toURI().toURL();
		p("file url " + fu.getProtocol() + " " + fu.getPath().endsWith("/file%20url.txt"));
		URLConnection fc = fu.openConnection();
		p("file length " + fc.getContentLength() + " type " + fc.getContentType() + " modified " + (fc.getLastModified() == f.lastModified()));
		BufferedReader r = new BufferedReader(new InputStreamReader(fc.getInputStream()));
		p("file read " + r.readLine());
		r.close();
	}

	static void lookups() throws Exception {
		InetAddress a = InetAddress.getByName("127.0.0.1");
		p("literal " + a.getHostAddress() + " " + a.isLoopbackAddress());
		InetAddress l = InetAddress.getByName("localhost");
		p("localhost " + l.getHostAddress());
		p("loopback " + InetAddress.getLoopbackAddress().getHostAddress() + " " + InetAddress.getLoopbackAddress().getHostName());
		p("byAddress " + InetAddress.getByAddress(new byte[]{10, 0, 0, 1}).getHostAddress());
		try {
			InetAddress.getByName("no-such-host.invalid");
			p("resolved?");
		} catch (UnknownHostException e) {
			p("unknown host");
		}
		p("all " + InetAddress.getAllByName("127.0.0.1").length);
		p("local host " + (InetAddress.getLocalHost() != null));
	}

	static void sockets() throws Exception {
		ServerSocket ss = new ServerSocket(0, 5, InetAddress.getLoopbackAddress());
		int port = ss.getLocalPort();
		p("bound " + (port > 0) + " " + ss.isBound());
		Socket c = new Socket(InetAddress.getLoopbackAddress(), port);
		Socket s = ss.accept();
		p("connected " + c.isConnected() + " " + (c.getPort() == port) + " " + (s.getLocalPort() == port) + " " + c.getInetAddress().getHostAddress() + " local " + c.getLocalAddress().getHostAddress());
		c.getOutputStream().write("ping\n".getBytes());
		BufferedReader sr = new BufferedReader(new InputStreamReader(s.getInputStream()));
		p("server got " + sr.readLine());
		s.getOutputStream().write(new byte[]{1, 2, 3});
		InputStream ci = c.getInputStream();
		byte[] b = new byte[10];
		int n = ci.read(b);
		p("client got " + n + " " + b[0] + b[1] + b[2]);
		c.setSoTimeout(200);
		try {
			ci.read();
			p("read returned");
		} catch (SocketTimeoutException e) {
			p("read timed out");
		}
		s.close();
		c.setSoTimeout(0);
		p("end of stream " + ci.read());
		c.close();
		p("closed " + c.isClosed());
		try {
			ci.read();
		} catch (SocketException e) {
			p("read after close throws");
		}
		ss.setSoTimeout(100);
		try {
			ss.accept();
		} catch (SocketTimeoutException e) {
			p("accept timed out");
		}
		ss.close();
		try {
			new Socket(InetAddress.getLoopbackAddress(), port);
			p("connected to a closed port?");
		} catch (ConnectException e) {
			p("refused " + e.getClass().getSimpleName());
		}
		Socket u = new Socket();
		try {
			u.connect(new InetSocketAddress("127.0.0.1", port), 500);
		} catch (ConnectException e) {
			p("refused with timeout");
		}
	}

	/** A tiny HTTP server: answers by path, one request per connection. */
	static void http() throws Exception {
		final ServerSocket ss = new ServerSocket(0, 10, InetAddress.getLoopbackAddress());
		final int port = ss.getLocalPort();
		Thread server = new Thread(new Runnable() {
			public void run() {
				try {
					while (true) {
						Socket s = ss.accept();
						BufferedReader r = new BufferedReader(new InputStreamReader(s.getInputStream(), "ISO-8859-1"));
						String request = r.readLine();
						String line;
						String ims = null;
						while ((line = r.readLine()) != null && !line.isEmpty())
							if (line.toLowerCase().startsWith("if-modified-since:"))
								ims = line.substring(18).trim();
						String path = request.split(" ")[1];
						String method = request.split(" ")[0];
						OutputStream o = s.getOutputStream();
						String resp;
						if (path.startsWith("/ok")) {
							resp = "HTTP/1.1 200 OK\r\nContent-Length: 11\r\nLast-Modified: Sun, 06 Nov 1994 08:49:37 GMT\r\nContent-Type: text/plain\r\nX-Two: a\r\nX-Two: b\r\n\r\n"
									+ (method.equals("HEAD") ? "" : "hello world");
						} else if (path.startsWith("/chunked")) {
							resp = "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n5\r\nhello\r\n6;ext=1\r\n world\r\n0\r\nTrailer: x\r\n\r\n";
						} else if (path.startsWith("/move")) {
							resp = "HTTP/1.1 302 Found\r\nLocation: /ok\r\nContent-Length: 0\r\n\r\n";
						} else if (path.startsWith("/old")) {
							resp = "HTTP/1.1 200 OK\r\nLast-Modified: Sunday, 06-Nov-94 08:49:37 GMT\r\nDate: Sun Nov  6 08:49:37 1994\r\n\r\nno length, until close";
						} else if (path.startsWith("/ims")) {
							resp = "HTTP/1.1 200 OK\r\nContent-Length: " + (ims == null ? 4 : ims.length()) + "\r\n\r\n" + (ims == null ? "none" : ims);
						} else if (path.startsWith("/err")) {
							resp = "HTTP/1.1 500 Internal Server Error\r\nContent-Length: 4\r\n\r\noops";
						} else {
							resp = "HTTP/1.1 404 Not Found\r\nContent-Length: 9\r\n\r\nnot found";
						}
						o.write(resp.getBytes("ISO-8859-1"));
						o.flush();
						s.close();
					}
				} catch (IOException e) {
				}
			}
		});
		server.setDaemon(true);
		server.start();
		String base = "http://127.0.0.1:" + port;

		HttpURLConnection c = (HttpURLConnection) new URL(base + "/ok").openConnection();
		p("ok modified " + c.getLastModified() + " length " + c.getContentLength() + " type " + c.getContentType() + " code " + c.getResponseCode() + " " + c.getResponseMessage());
		p("ok body " + read(c.getInputStream()) + " header0 " + c.getHeaderField(0) + " last X-Two " + c.getHeaderField("x-two"));
		HttpURLConnection h = (HttpURLConnection) new URL(base + "/ok").openConnection();
		h.setRequestMethod("HEAD");
		p("head " + h.getResponseCode() + " length " + h.getContentLength() + " body [" + read(h.getInputStream()) + "]");
		URLConnection ch = new URL(base + "/chunked").openConnection();
		p("chunked " + read(ch.getInputStream()) + " length " + ch.getContentLength());
		HttpURLConnection mv = (HttpURLConnection) new URL(base + "/move").openConnection();
		p("redirect " + mv.getResponseCode() + " " + read(mv.getInputStream()) + " now " + mv.getURL().getPath());
		HttpURLConnection nf = (HttpURLConnection) new URL(base + "/missing").openConnection();
		p("missing code " + nf.getResponseCode());
		try {
			nf.getInputStream();
		} catch (FileNotFoundException e) {
			p("missing FileNotFoundException " + e.getMessage().endsWith("/missing"));
		}
		HttpURLConnection nf2 = (HttpURLConnection) new URL(base + "/missing2").openConnection();
		try {
			nf2.getInputStream();
		} catch (FileNotFoundException e) {
			p("missing first, then code " + nf2.getResponseCode());
		}
		HttpURLConnection er = (HttpURLConnection) new URL(base + "/err").openConnection();
		try {
			er.getInputStream();
		} catch (IOException e) {
			p("error " + e.getMessage().startsWith("Server returned HTTP response code: 500") + " code " + er.getResponseCode() + " stream " + read(er.getErrorStream()));
		}
		URLConnection old = new URL(base + "/old").openConnection();
		p("old dates " + old.getLastModified() + " " + old.getDate() + " length " + old.getContentLength() + " body " + read(old.getInputStream()));
		URLConnection ims = new URL(base + "/ims").openConnection();
		ims.setIfModifiedSince(784111777000L);
		p("if-modified-since " + read(ims.getInputStream()));
		HttpURLConnection nf3 = (HttpURLConnection) new URL(base + "/missing3").openConnection();
		p("missing length " + nf3.getContentLength() + " code " + nf3.getResponseCode());
		try {
			new URL("http://127.0.0.1:" + port + "/ok").openStream().close();
			p("openStream ok");
		} catch (IOException e) {
			p("openStream failed " + e);
		}
		ss.close();
	}

	static String read(InputStream in) throws IOException {
		if (in == null)
			return "null";
		ByteArrayOutputStream b = new ByteArrayOutputStream();
		int c;
		while ((c = in.read()) >= 0)
			b.write(c);
		return b.toString("ISO-8859-1");
	}
}
