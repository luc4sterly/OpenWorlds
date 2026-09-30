package NET.worlds.core;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.RandomAccessFile;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;
import java.nio.file.Files;

/**
 * gamma.dll's Startup: volume serial number (0x00409e70/0x00409e80)
 * and the single instance (synchronizeStartup 0x004098b0 and its counterpart
 * FUN_00409ce0, which Window.install calls via 0x0040f250).
 *
 * <p><b>Volume serial</b> (DAT_0049fa6c, .bss: 0 until it is computed).
 * computeVolumeInfo does GetVolumeInformationA(root or NULL = the current
 * directory's drive) and, if that fails, the assertion "nStartup" line 0x9c.
 * Chosen POSIX equivalent: the {@code unix:dev} attribute (st_dev, the
 * identifier of the device that contains the file): like Win32's serial,
 * it identifies the volume and is stable as long as it is not reformatted
 * or remounted with another number. ⚠️ It is not the same number that disk
 * had on Windows: a password stored in a 2004 worlds.ini is not
 * decrypted here unless its serial is given with
 * {@code -Dopenworlds.volumeSerial=0xXXXXXXXX}. If the system does not have
 * the "unix" view the value stays at 0 (that of .bss) with a warning.
 *
 * <p><b>Single instance.</b> The original creates the named semaphore
 * "GammaUniqueStartupSemaphore_kjsd838jd382" (count 0, maximum 1):
 * <ul>
 * <li>if it is new, this is the first instance: DAT_0046dba0 = 0, returns true;
 * <li>if it already existed and this is autoplay, DAT_0046dba0 = 1 and returns false;
 * <li>otherwise, it waits up to 20 s for the first one to release it (which
 * FUN_00409ce0 does when its window is installed, after storing its HWND with
 * "%lu" in HKCU\Software\WorldsInc\Gamma\HWND), reads that HWND, sends it the
 * URL by WM_COPYDATA (cbData = strlen+1), releases the semaphore and returns
 * false (this second instance ends). The first one, in its WndProc
 * (0x0040c970, message 0x4a), restores the window and brings it to the front
 * and queues the URL as a teleport (FUN_00416aa0 -> NativeInput.addTeleport).
 * </ul>
 * Equivalents: semaphore = file lock ({@link FileLock}, which the
 * system releases when the process dies, just as the handle is closed),
 * registry HWND = TCP port on 127.0.0.1 written to a file,
 * WM_COPYDATA = connection to that port with the URL's bytes and its 0.
 * ⚠️ Scope: Win32's semaphore is session-wide; here it is per
 * installation directory (the working directory), because the bridge
 * deliberately runs several independent copies at once (two clients
 * against whirl, several agents). With MULTIRUN=1 in [Gamma] the client does
 * not call this, as in the original.
 */
public final class NativeUiStartup {
   private NativeUiStartup() {
   }

   // ------------------------------------------------------ volume serial

   private static volatile int volumeSerial;

   /** Startup.getVolumeInfo (0x00409e70) and Console.encrypt's key. */
   public static int volumeInfo() {
      return volumeSerial;
   }

   /** Startup.computeVolumeInfo (0x00409e80). */
   public static void computeVolumeInfo(String root) {
      String forced = System.getProperty("openworlds.volumeSerial");
      if (forced != null) {
         volumeSerial = (int) Long.parseLong(forced.replaceFirst("^0[xX]", ""), 16);
         return;
      }
      File f = new File(root == null ? System.getProperty("user.dir") : root);
      if (!f.exists()) {
         // GetVolumeInformationA fails with a root that does not exist
         NativeAssert.fail("nStartup", 0x9c);
         return;
      }
      try {
         Object dev = Files.getAttribute(f.toPath(), "unix:dev");
         volumeSerial = (int) ((Number) dev).longValue();
      } catch (UnsupportedOperationException e) {
         System.err.println("[STARTUP] sin atributo unix:dev: serie de volumen 0");
      } catch (IllegalArgumentException e) {
         System.err.println("[STARTUP] sin vista unix: serie de volumen 0");
      } catch (IOException e) {
         NativeAssert.fail("nStartup", 0x9c);
      }
   }

   // ------------------------------------------------------- single instance

   static final String SEMAPHORE = "GammaUniqueStartupSemaphore_kjsd838jd382";
   /** WaitForSingleObject(DAT_004890c8, 20000). */
   static final int WAIT_MS = 20000;

   /** DAT_0046dba0: 1 if this instance is not the first. */
   private static int notFirst;
   private static FileChannel semChannel;
   private static FileLock semLock;
   private static ServerSocket copyDataServer;

   /** Directory of the semaphore and "HWND" files (see scope above). */
   static File stateDir() {
      String cwd;
      try {
         cwd = new File(System.getProperty("user.dir")).getCanonicalPath();
      } catch (IOException e) {
         cwd = System.getProperty("user.dir");
      }
      File d = new File(System.getProperty("java.io.tmpdir"), "openworlds-startup-" + Integer.toHexString(cwd.hashCode()));
      d.mkdirs();
      return d;
   }

   private static File semFile() {
      return new File(stateDir(), SEMAPHORE + ".lock");
   }

   private static File hwndFile() {
      return new File(stateDir(), "HWND");
   }

   /** Startup.synchronizeStartup (0x004098b0). */
   public static synchronized boolean synchronizeStartup(String url, boolean autoplay) {
      try {
         semChannel = new RandomAccessFile(semFile(), "rw").getChannel();
         semLock = semChannel.tryLock();
      } catch (IOException e) {
         System.err.println("CreateSemaphore() failed: " + e);
         return false;
      }
      if (semLock != null) {
         // new semaphore (GetLastError() == 0): first instance, count 0
         hwndFile().delete();
         notFirst = 0;
         return true;
      }
      // ERROR_ALREADY_EXISTS (0xb7)
      try {
         semChannel.close();
      } catch (IOException e) {
         // nothing
      }
      semChannel = null;
      if (autoplay) {
         notFirst = 1;
         return false;
      }
      long deadline = System.currentTimeMillis() + WAIT_MS;
      File hwnd = hwndFile();
      while (!hwnd.exists()) {
         if (System.currentTimeMillis() >= deadline) {
            System.err.println("WaitForSingleObject(): TIMEOUT!");
            return false;
         }
         try {
            Thread.sleep(100);
         } catch (InterruptedException e) {
            System.err.println("WaitForSingleObject() failed: " + e);
            return false;
         }
      }
      String port;
      try {
         port = new String(Files.readAllBytes(hwnd.toPath()), "US-ASCII").trim();
      } catch (IOException e) {
         System.err.println("RegQueryValue() failed: " + e);
         return false;
      }
      // SendMessageA(hWnd, WM_COPYDATA, 0, {0, strlen+1, url}): synchronous
      try {
         Socket s = new Socket(InetAddress.getLoopbackAddress(), Integer.parseInt(port));
         OutputStream o = s.getOutputStream();
         o.write(url == null ? new byte[0] : NativeUiConsole.modifiedUtf8(url));
         o.write(0);
         o.flush();
         s.getInputStream().read();
         s.close();
      } catch (Exception e) {
         // SendMessage to an HWND that no longer exists simply returns 0
         System.err.println("[STARTUP] WM_COPYDATA a la primera instancia fallo: " + e);
      }
      notFirst = 1;
      return false;
   }

   /**
    * FUN_00409ce0 (called by Window.install, 0x0040f250): the first
    * instance publishes its "HWND" and releases the semaphore. Returns 1 if it did.
    */
   public static synchronized int instanceReady() {
      if (notFirst != 0 || semLock == null || copyDataServer != null) {
         return 0;
      }
      try {
         copyDataServer = new ServerSocket(0, 4, InetAddress.getLoopbackAddress());
         File tmp = new File(stateDir(), "HWND.tmp");
         Files.write(tmp.toPath(), String.valueOf(copyDataServer.getLocalPort()).getBytes("US-ASCII"));
         if (!tmp.renameTo(hwndFile())) {
            throw new IOException("rename");
         }
      } catch (IOException e) {
         System.err.println("RegSetValue() failed: " + e);
         return 0;
      }
      Thread t = new Thread("openworlds-WM_COPYDATA") {
         public void run() {
            while (true) {
               try {
                  Socket s = copyDataServer.accept();
                  InputStream in = s.getInputStream();
                  java.io.ByteArrayOutputStream b = new java.io.ByteArrayOutputStream();
                  int c;
                  while ((c = in.read()) > 0) {
                     b.write(c);
                  }
                  byte[] bytes = b.toByteArray();
                  copyData(NativeUiConsole.fromModifiedUtf8(bytes, 0, bytes.length));
                  s.getOutputStream().write(0);
                  s.close();
               } catch (IOException e) {
                  return;
               }
            }
         }
      };
      t.setDaemon(true);
      t.start();
      return 1;
   }

   /** 0x0040c970, WM_COPYDATA: ShowWindow(SW_RESTORE), SetForegroundWindow y FUN_00416aa0. */
   static void copyData(final String url) {
      final java.awt.Component c = NativeWindows.component(NativeWindows.mainHwnd());
      if (c != null) {
         java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
               java.awt.Window w = javax.swing.SwingUtilities.getWindowAncestor(c);
               if (w instanceof java.awt.Frame) {
                  ((java.awt.Frame) w).setExtendedState(java.awt.Frame.NORMAL);
               }
               if (w != null) {
                  w.toFront();
               }
            }
         });
      }
      NativeInput.addTeleport(url);
   }
}
