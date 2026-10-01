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
 * Embedded web control without IE/DDE and the open/log decision for URLs.
 * It never opens a browser: the process runs with java.awt.headless=true
 * (Desktop not supported) and without -Dopenworlds.openUrls except in the
 * child process, which has no user origin either. Hand-made cases:
 *  - decide(flag, user): only (1,1) opens.
 *  - user origin by stack: dialogDone / DefaultConsole.action yes;
 *    DialogAction.trigger, scripts, LoginWizard.selectScreen no.
 *  - IE: nativeInit false -> WebControlFactory throws NoWebControlException.
 *  - openBrowser -> IOException("nWebBrowser"); IWebBrowserApp -> IOException("nIWebBrowserApp").
 *  - DDE: create/Request false; sendURL.get 0.
 *  - TextureSurface: window and 5-6-5 DIB of w*h, released in finalize.
 */
public class MediaWebCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + " " + what);
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
      // Before touching AWT: without Desktop there is no browser to open even if the logic failed.
      System.setProperty("java.awt.headless", "true");

      if (args.length > 0 && args[0].equals("child")) {
         // -Dopenworlds.openUrls=1 but no user origin: it only logs.
         boolean r = launch("http://example.invalid/child");
         int g = NET.worlds.scape.sendURL.get("http://example.invalid/bump");
         System.out.println("CHILD " + NativeMediaUrl.OPEN_URLS + " " + r + " " + g);
         System.exit(0);
      }

      // --- decision ---
      check(NativeMediaUrl.decide(false, false) == NativeMediaUrl.Decision.LOG_DISABLED, "no flag, no user -> log");
      check(NativeMediaUrl.decide(false, true) == NativeMediaUrl.Decision.LOG_DISABLED, "no flag, with user -> log");
      check(NativeMediaUrl.decide(true, false) == NativeMediaUrl.Decision.LOG_NOT_USER, "with flag, no user -> log");
      check(NativeMediaUrl.decide(true, true) == NativeMediaUrl.Decision.OPEN, "with flag and user -> open");

      check(NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.startBrowser", "NET.worlds.scape.SendURLAction.doIt", "NET.worlds.scape.DialogAction.dialogDone")),
         "OK in the Browse? dialog is a user origin");
      check(NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.startBrowser", "NET.worlds.console.DefaultConsole.action")), "console menu is a user origin");
      check(NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.doIt", "NET.worlds.scape.Billboard.billboardClicked")), "click on a billboard is a user origin");
      check(!NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.doIt", "NET.worlds.scape.DialogAction.trigger", "NET.worlds.scape.Sensor.trigger")),
         "DialogAction.trigger without a dialog (world trigger) is not");
      check(!NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.doIt", "NET.worlds.scape.WorldScriptToolkitImp.showWebPage")), "world script is not");
      check(!NativeMediaUrl.isUserOrigin(stack("NET.worlds.scape.SendURLAction.startBrowser", "NET.worlds.console.LoginWizard.selectScreen")), "LoginWizard.selectScreen (automatic) is not");
      check(!NativeMediaUrl.isUserOrigin(null), "without a stack it is not");
      check(!NativeMediaUrl.isUserOrigin(Thread.currentThread().getStackTrace()), "this test's stack is not");

      // --- without the flag it never opens ---
      check(!NativeMediaUrl.OPEN_URLS, "openworlds.openUrls not set in the test");
      NativeMediaUrl.setPendingUserOrigin(true);
      check(!launch("http://example.invalid/menu"), "launchViaRegistry without the flag -> false even if it comes from the user");
      check(NET.worlds.scape.sendURL.get("http://example.invalid/x") == 0, "sendURL.get without the flag -> 0");
      check(NET.worlds.scape.sendURL.silent_get("http://example.invalid/x") == 0, "sendURL.silent_get without the flag -> 0");
      check(NET.worlds.scape.sendURL.init("NETSCAPE") == 0, "sendURL.init without DDEML -> 0");

      // --- with the flag and no user, in another process ---
      String java = System.getProperty("java.home") + File.separator + "bin" + File.separator + "java";
      Process p = new ProcessBuilder(java, "-Xmx128m", "-Djava.awt.headless=true", "-Dopenworlds.openUrls=1", "-cp", System.getProperty("java.class.path"), "MediaWebCheck", "child")
         .redirectErrorStream(true)
         .start();
      BufferedReader in = new BufferedReader(new InputStreamReader(p.getInputStream()));
      String line;
      String child = null;
      boolean notUserLogged = false;
      while ((line = in.readLine()) != null) {
         System.out.println("   | " + line);
         if (line.startsWith("CHILD ")) {
            child = line;
         }

         if (line.contains("not from a user action")) {
            notUserLogged = true;
         }
      }

      p.waitFor();
      check("CHILD true false 0".equals(child), "with openUrls=1 and no user origin: does not open (" + child + ")");
      check(notUserLogged, "and logs it as 'not from a user action'");

      // --- embedded IE ---
      check(!NativeMediaWeb.ieNativeInit(0x1234, true), "IEWebControlImp.nativeInit -> false");
      boolean threw = false;
      try {
         WebControlFactory.createWebControlImp(0x1234, false, true);
      } catch (NoWebControlException e) {
         threw = true;
      }

      check(threw, "WebControlFactory.createWebControlImp throws NoWebControlException");

      // --- WebBrowser / IWebBrowserApp ---
      try {
         NativeMediaWeb.openBrowser();
         check(false, "openBrowser should throw");
      } catch (Exception e) {
         check(e instanceof IOException && "nWebBrowser".equals(e.getMessage()), "openBrowser -> IOException(\"nWebBrowser\")");
      }

      try {
         NativeMediaWeb.webBrowserAppCall("Navigate");
         check(false, "IWebBrowserApp should throw");
      } catch (Exception e) {
         check(e instanceof IOException && "nIWebBrowserApp".equals(e.getMessage()), "IWebBrowserApp -> IOException(\"nIWebBrowserApp\")");
      }

      // --- DDEMLClass ---
      DDEMLClass dde = new DDEMLClass("NETSCAPE", "WWW_Activate");
      check(!dde.Request("-1,0"), "DDEMLClass.Request without a conversation -> false");
      check(!dde.Poke("a", "b"), "DDEMLClass.Poke without a conversation -> false");
      dde.destroy();

      // --- TextureSurface ---
      TextureSurface ts = new TextureSurface(null, 1, 468, 60);
      check(ts.getHwnd() != 0, "TextureSurface: hidden window with HWND != 0");
      int dc = NativeMediaWeb.surfaceMakeDC(ts.getHwnd(), 468, 60);
      NativeMediaWeb.Dib dib = NativeMediaWeb.dibOf(dc);
      check(dib != null && dib.pixels.length == 468 * 60 && dib.pixels[0] == 0, "5-6-5 DIB of 468x60, zeroed");
      NativeMediaWeb.surfaceDestroyDC(dc);
      check(NativeMediaWeb.dibOf(dc) == null, "nativeDestroyDC releases the DIB");
      ts.sendLeftClick(10, 10);
      ts.finalize();
      check(true, "sendLeftClick and finalize have no effect and throw no exception");

      System.out.println(fails == 0 ? "MediaWebCheck: all OK" : "MediaWebCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}
