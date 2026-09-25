import NET.worlds.console.NoWebControlException;
import NET.worlds.console.WebControlFactory;
import NET.worlds.core.NativeMediaUrl;
import NET.worlds.core.NativeMediaWeb;
import NET.worlds.network.DDEMLClass;
import NET.worlds.scape.TextureSurface;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Method;

/**
 * Web embebida sin IE/DDE y la decision abrir/registrar de las URLs.
 * Nunca abre un navegador: el proceso corre con java.awt.headless=true
 * (Desktop no soportado) y sin -Dfreeworlds.openUrls salvo en el hijo, que
 * tampoco tiene origen de usuario. Casos a mano:
 *  - decide(flag, usuario): solo (1,1) abre.
 *  - origen de usuario por pila: dialogDone / DefaultConsole.action si;
 *    DialogAction.trigger, scripts, LoginWizard.selectScreen no.
 *  - IE: nativeInit false -> WebControlFactory lanza NoWebControlException.
 *  - openBrowser -> IOException("nWebBrowser"); IWebBrowserApp -> IOException("nIWebBrowserApp").
 *  - DDE: create/Request false; sendURL.get 0.
 *  - TextureSurface: ventana y DIB 5-6-5 de w*h, liberado en finalize.
 */
public class MediaWebCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLO") + " " + what);
      if (!ok) {
         fails++;
      }
   }

   static StackTraceElement[] stack(String... frames) {
      StackTraceElement[] s = new StackTraceElement[frames.length];
      for (int i = 0; i < frames.length; i++) {
         int dot = frames[i].lastIndexOf('.');
         s[i] = new StackTraceElement(frames[i].substring(0, dot), frames[i].substring(dot + 1), "X.java", 1);
      }

      return s;
   }

   static boolean launch(String url) throws Exception {
      Method m = Class.forName("NET.worlds.scape.SendURLAction").getDeclaredMethod("launchViaRegistry", String.class);
      m.setAccessible(true);
      return (Boolean)m.invoke(null, url);
   }

   public static void main(String[] args) throws Exception {
      // Antes de tocar AWT: sin Desktop no hay navegador que abrir aunque fallara la logica.
      System.setProperty("java.awt.headless", "true");

      if (args.length > 0 && args[0].equals("hijo")) {
         // -Dfreeworlds.openUrls=1 pero sin origen de usuario: solo registra.
         boolean r = launch("http://example.invalid/hijo");
         int g = NET.worlds.scape.sendURL.get("http://example.invalid/bump");
         System.out.println("HIJO " + NativeMediaUrl.OPEN_URLS + " " + r + " " + g);
         System.exit(0);
      }

      // --- decision ---
      check(NativeMediaUrl.decide(false, false) == NativeMediaUrl.Decision.LOG_DISABLED, "sin flag, sin usuario -> registrar");
      check(NativeMediaUrl.decide(false, true) == NativeMediaUrl.Decision.LOG_DISABLED, "sin flag, con usuario -> registrar");
      check(NativeMediaUrl.decide(true, false) == NativeMediaUrl.Decision.LOG_NOT_USER, "con flag, sin usuario -> registrar");
      check(NativeMediaUrl.decide(true, true) == NativeMediaUrl.Decision.OPEN, "con flag y usuario -> abrir");

      check(NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.startBrowser", "NET.worlds.scape.SendURLAction.doIt", "NET.worlds.scape.DialogAction.dialogDone")),
         "OK del dialogo Browse? es origen de usuario");
      check(NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.startBrowser", "NET.worlds.console.DefaultConsole.action")), "menu de la consola es origen de usuario");
      check(NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.doIt", "NET.worlds.scape.Billboard.billboardClicked")), "clic en cartel es origen de usuario");
      check(!NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.doIt", "NET.worlds.scape.DialogAction.trigger", "NET.worlds.scape.Sensor.trigger")),
         "DialogAction.trigger sin dialogo (disparador del mundo) no lo es");
      check(!NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.doIt", "NET.worlds.scape.WorldScriptToolkitImp.showWebPage")), "script del mundo no lo es");
      check(!NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.startBrowser", "NET.worlds.console.LoginWizard.selectScreen")), "LoginWizard.selectScreen (automatico) no lo es");
      check(!NativeMediaUrl.isUserOrigin(null), "sin pila no lo es");
      check(!NativeMediaUrl.isUserOrigin(Thread.currentThread().getStackTrace()), "la pila de esta prueba no lo es");

      // --- sin flag nunca se abre ---
      check(!NativeMediaUrl.OPEN_URLS, "freeworlds.openUrls no puesto en la prueba");
      NativeMediaUrl.setPendingUserOrigin(true);
      check(!launch("http://example.invalid/menu"), "launchViaRegistry sin flag -> false aunque venga del usuario");
      check(NET.worlds.scape.sendURL.get("http://example.invalid/x") == 0, "sendURL.get sin flag -> 0");
      check(NET.worlds.scape.sendURL.silent_get("http://example.invalid/x") == 0, "sendURL.silent_get sin flag -> 0");
      check(NET.worlds.scape.sendURL.init("NETSCAPE") == 0, "sendURL.init sin DDEML -> 0");

      // --- con flag y sin usuario, en otro proceso ---
      String java = System.getProperty("java.home") + File.separator + "bin" + File.separator + "java";
      Process p = new ProcessBuilder(java, "-Xmx128m", "-Djava.awt.headless=true", "-Dfreeworlds.openUrls=1", "-cp", System.getProperty("java.class.path"), "MediaWebCheck", "hijo")
         .redirectErrorStream(true)
         .start();
      BufferedReader in = new BufferedReader(new InputStreamReader(p.getInputStream()));
      String line;
      String hijo = null;
      boolean notUserLogged = false;
      while ((line = in.readLine()) != null) {
         System.out.println("   | " + line);
         if (line.startsWith("HIJO ")) {
            hijo = line;
         }

         if (line.contains("no viene de una accion del usuario")) {
            notUserLogged = true;
         }
      }

      p.waitFor();
      check("HIJO true false 0".equals(hijo), "con openUrls=1 y sin origen de usuario: no abre (" + hijo + ")");
      check(notUserLogged, "y lo registra como 'no viene de una accion del usuario'");

      // --- IE embebido ---
      check(!NativeMediaWeb.ieNativeInit(0x1234, true), "IEWebControlImp.nativeInit -> false");
      boolean threw = false;
      try {
         WebControlFactory.createWebControlImp(0x1234, false, true);
      } catch (NoWebControlException e) {
         threw = true;
      }

      check(threw, "WebControlFactory.createWebControlImp lanza NoWebControlException");

      // --- WebBrowser / IWebBrowserApp ---
      try {
         NativeMediaWeb.openBrowser();
         check(false, "openBrowser deberia lanzar");
      } catch (Exception e) {
         check(e instanceof IOException && "nWebBrowser".equals(e.getMessage()), "openBrowser -> IOException(\"nWebBrowser\")");
      }

      try {
         NativeMediaWeb.webBrowserAppCall("Navigate");
         check(false, "IWebBrowserApp deberia lanzar");
      } catch (Exception e) {
         check(e instanceof IOException && "nIWebBrowserApp".equals(e.getMessage()), "IWebBrowserApp -> IOException(\"nIWebBrowserApp\")");
      }

      // --- DDEMLClass ---
      DDEMLClass dde = new DDEMLClass("NETSCAPE", "WWW_Activate");
      check(!dde.Request("-1,0"), "DDEMLClass.Request sin conversacion -> false");
      check(!dde.Poke("a", "b"), "DDEMLClass.Poke sin conversacion -> false");
      dde.destroy();

      // --- TextureSurface ---
      TextureSurface ts = new TextureSurface(null, 1, 468, 60);
      check(ts.getHwnd() != 0, "TextureSurface: ventana oculta con HWND != 0");
      int dc = NativeMediaWeb.surfaceMakeDC(ts.getHwnd(), 468, 60);
      NativeMediaWeb.Dib dib = NativeMediaWeb.dibOf(dc);
      check(dib != null && dib.pixels.length == 468 * 60 && dib.pixels[0] == 0, "DIB 5-6-5 de 468x60 a cero");
      NativeMediaWeb.surfaceDestroyDC(dc);
      check(NativeMediaWeb.dibOf(dc) == null, "nativeDestroyDC libera el DIB");
      ts.sendLeftClick(10, 10);
      ts.finalize();
      check(true, "sendLeftClick y finalize sin efecto ni excepcion");

      System.out.println(fails == 0 ? "MediaWebCheck: todo OK" : "MediaWebCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}
