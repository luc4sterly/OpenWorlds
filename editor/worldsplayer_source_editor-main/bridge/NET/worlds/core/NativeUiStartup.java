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
 * Startup de gamma.dll: numero de serie del volumen (0x00409e70/0x00409e80)
 * y la instancia unica (synchronizeStartup 0x004098b0 y su pareja
 * FUN_00409ce0, que Window.install llama via 0x0040f250).
 *
 * <p><b>Serie del volumen</b> (DAT_0049fa6c, .bss: 0 hasta que se calcula).
 * computeVolumeInfo hace GetVolumeInformationA(raiz o NULL = unidad del
 * directorio actual) y, si falla, la asercion "nStartup" linea 0x9c.
 * Equivalente POSIX elegido: el atributo {@code unix:dev} (st_dev, el
 * identificador del dispositivo que contiene el fichero): como la serie de
 * Win32, identifica el volumen y es estable mientras no se reformatee o
 * remonte con otro numero. ⚠️ No es el mismo numero que tuviera ese disco
 * en Windows: una contrasena guardada en un worlds.ini de 2004 no se
 * descifra aqui salvo que se de su serie con
 * {@code -Dfreeworlds.volumeSerial=0xXXXXXXXX}. Si el sistema no tiene la
 * vista "unix" el valor se queda en 0 (el de .bss) con un aviso.
 *
 * <p><b>Instancia unica.</b> El original crea el semaforo con nombre
 * "GammaUniqueStartupSemaphore_kjsd838jd382" (cuenta 0, maximo 1):
 * <ul>
 * <li>si es nuevo, es la primera instancia: DAT_0046dba0 = 0, devuelve true;
 * <li>si ya existia y es autoplay, DAT_0046dba0 = 1 y devuelve false;
 * <li>si no, espera hasta 20 s a que la primera lo libere (lo hace
 * FUN_00409ce0 cuando su ventana esta instalada, tras guardar su HWND con
 * "%lu" en HKCU\Software\WorldsInc\Gamma\HWND), lee ese HWND, le manda la
 * URL por WM_COPYDATA (cbData = strlen+1), libera el semaforo y devuelve
 * false (esta segunda instancia termina). La primera, en su WndProc
 * (0x0040c970, mensaje 0x4a), restaura y trae al frente la ventana y encola
 * la URL como teletransporte (FUN_00416aa0 -> NativeInput.addTeleport).
 * </ul>
 * Equivalentes: semaforo = cerrojo de fichero ({@link FileLock}, que el
 * sistema suelta al morir el proceso igual que se cierra el handle), HWND
 * del registro = puerto TCP en 127.0.0.1 escrito en un fichero,
 * WM_COPYDATA = conexion a ese puerto con los bytes de la URL y su 0.
 * ⚠️ Ambito: el semaforo de Win32 es de toda la sesion; aqui es por
 * directorio de instalacion (el directorio de trabajo), porque el puente
 * corre a proposito varias copias independientes a la vez (dos clientes
 * contra whirl, varios agentes). Con MULTIRUN=1 en [Gamma] el cliente no
 * llama a esto, como en el original.
 */
public final class NativeUiStartup {
   private NativeUiStartup() {
   }

   // ------------------------------------------------------ serie del volumen

   private static volatile int volumeSerial;

   /** Startup.getVolumeInfo (0x00409e70) y la clave de Console.encrypt. */
   public static int volumeInfo() {
      return volumeSerial;
   }

   /** Startup.computeVolumeInfo (0x00409e80). */
   public static void computeVolumeInfo(String root) {
      String forced = System.getProperty("freeworlds.volumeSerial");
      if (forced != null) {
         volumeSerial = (int) Long.parseLong(forced.replaceFirst("^0[xX]", ""), 16);
         return;
      }
      File f = new File(root == null ? System.getProperty("user.dir") : root);
      if (!f.exists()) {
         // GetVolumeInformationA falla con una raiz que no existe
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

   // ------------------------------------------------------- instancia unica

   static final String SEMAPHORE = "GammaUniqueStartupSemaphore_kjsd838jd382";
   /** WaitForSingleObject(DAT_004890c8, 20000). */
   static final int WAIT_MS = 20000;

   /** DAT_0046dba0: 1 si esta instancia no es la primera. */
   private static int notFirst;
   private static FileChannel semChannel;
   private static FileLock semLock;
   private static ServerSocket copyDataServer;

   /** Directorio de los ficheros del semaforo y del "HWND" (ver ambito arriba). */
   static File stateDir() {
      String cwd;
      try {
         cwd = new File(System.getProperty("user.dir")).getCanonicalPath();
      } catch (IOException e) {
         cwd = System.getProperty("user.dir");
      }
      File d = new File(System.getProperty("java.io.tmpdir"), "freeworlds-startup-" + Integer.toHexString(cwd.hashCode()));
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
         // semaforo nuevo (GetLastError() == 0): primera instancia, cuenta 0
         hwndFile().delete();
         notFirst = 0;
         return true;
      }
      // ERROR_ALREADY_EXISTS (0xb7)
      try {
         semChannel.close();
      } catch (IOException e) {
         // nada
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
      // SendMessageA(hWnd, WM_COPYDATA, 0, {0, strlen+1, url}): sincrono
      try {
         Socket s = new Socket(InetAddress.getLoopbackAddress(), Integer.parseInt(port));
         OutputStream o = s.getOutputStream();
         o.write(url == null ? new byte[0] : NativeUiConsole.modifiedUtf8(url));
         o.write(0);
         o.flush();
         s.getInputStream().read();
         s.close();
      } catch (Exception e) {
         // SendMessage a un HWND que ya no existe devuelve 0 sin mas
         System.err.println("[STARTUP] WM_COPYDATA a la primera instancia fallo: " + e);
      }
      notFirst = 1;
      return false;
   }

   /**
    * FUN_00409ce0 (llamada por Window.install, 0x0040f250): la primera
    * instancia publica su "HWND" y libera el semaforo. Devuelve 1 si lo hizo.
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
      Thread t = new Thread("freeworlds-WM_COPYDATA") {
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
