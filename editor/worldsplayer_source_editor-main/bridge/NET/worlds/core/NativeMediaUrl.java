package NET.worlds.core;

import java.io.File;
import java.net.URI;

/**
 * Opening a URL outside the client: {@code SendURLAction.launchViaRegistry}
 * (0x00413a10, {@code ShellExecuteA(NULL, "open", url, NULL, NULL,
 * SW_SHOWNORMAL)}) and {@code sendURL.get/silent_get} (0x004210a0/0x00421300,
 * DDE {@code WWW_OpenURL} to the browser). Here that is the system browser
 * ({@code java.awt.Desktop}), with two locks:
 * <ol>
 * <li>only with {@code -Dopenworlds.openUrls=1}; without it, the URL is
 *     logged and nothing is opened;</li>
 * <li>only if the request comes from an explicit user action: the stack of
 *     the call that originated it contains one of the entry points of
 *     {@link #USER_ORIGINS} (confirming {@code SendURLAction}'s "Browse?"
 *     dialog, a menu, a button of the map or of the wizard, a click on a
 *     billboard). Everything else (world triggers, scripts, banners, room
 *     loading) is only logged.</li>
 * </ol>
 */
public final class NativeMediaUrl {
   private NativeMediaUrl() {
   }

   public static final boolean OPEN_URLS = "1".equals(System.getProperty("openworlds.openUrls"))
      || "true".equalsIgnoreCase(System.getProperty("openworlds.openUrls"));

   /** Methods (class.method) that only run because of a user action. */
   static final String[] USER_ORIGINS = new String[]{
      "NET.worlds.scape.DialogAction.dialogDone", // OK in SendURLAction's dialog
      "NET.worlds.console.DefaultConsole.action", // console menus
      "NET.worlds.console.DefaultConsole$2.actionPerformed", // "file:" help menu
      "NET.worlds.console.MapPart.imageButtonsCallback", // map buttons
      "NET.worlds.console.LoginWizard.action", // wizard buttons
      "NET.worlds.network.UpgradeDialog.action", // the update's "more information"
      "NET.worlds.scape.Billboard.billboardClicked", // click on a billboard
      "NET.worlds.scape.WebPageWall.handle" // click on a WebPageWall (see the ⚠️ in the report)
   };

   public enum Decision {
      OPEN,
      LOG_DISABLED,
      LOG_NOT_USER
   }

   /** true if any of the stack entries is a user origin. */
   public static boolean isUserOrigin(StackTraceElement[] stack) {
      if (stack == null) {
         return false;
      }

      for (StackTraceElement e : stack) {
         String m = e.getClassName() + "." + e.getMethodName();
         for (String o : USER_ORIGINS) {
            if (o.equals(m)) {
               return true;
            }
         }
      }

      return false;
   }

   /** The decision, pure: with the flag and a user origin, it opens. */
   public static Decision decide(boolean openUrls, boolean userOrigin) {
      if (!openUrls) {
         return Decision.LOG_DISABLED;
      }

      return userOrigin ? Decision.OPEN : Decision.LOG_NOT_USER;
   }

   /**
    * Origin of this thread's current request. SendURLAction records it in
    * startBrowser (the stack still has the menu or the dialog) because
    * tryLaunch may run later from Main.mainCallback, with another stack.
    */
   private static final ThreadLocal<Boolean> PENDING_USER = new ThreadLocal<>();

   public static void setPendingUserOrigin(boolean user) {
      PENDING_USER.set(user);
   }

   private static boolean takePendingUserOrigin() {
      Boolean b = PENDING_USER.get();
      PENDING_USER.remove();
      return b != null && b || isUserOrigin(Thread.currentThread().getStackTrace());
   }

   // 0x00413a10 SendURLAction.launchViaRegistry: ShellExecuteA("open", url);
   // success if it returns > 32. On failure: "Error <n> in ShellExecuting <url>.\n"
   // and, only with ERROR_FILE_NOT_FOUND (2), one retry. Logging without
   // opening returns false (nothing was launched): the Java code then prints its
   // "Unable-to-launch" message on the console.
   public static boolean launchViaRegistry(String url) {
      Decision d = decide(OPEN_URLS, takePendingUserOrigin());
      if (!report("launchViaRegistry", url, d)) {
         return false;
      }

      int r = shellOpen(url);
      if (r <= 32) {
         System.out.println("Error " + r + " in ShellExecuting " + url + ".");
         if (r == 2) {
            r = shellOpen(url);
            if (r <= 32) {
               System.out.println("Retry failed too with error " + r);
            }
         }
      }

      return r > 32;
   }

   /** DDE WWW_OpenURL of sendURL.get/silent_get: 1 if opened, 0 like a failed DdeConnect. */
   public static int ddeOpenUrl(String via, String url) {
      Decision d = decide(OPEN_URLS, takePendingUserOrigin());
      if (!report(via, url, d)) {
         return 0;
      }

      return shellOpen(url) > 32 ? 1 : 0;
   }

   private static boolean report(String via, String url, Decision d) {
      switch (d) {
         case OPEN:
            NativeMediaSound.log("URL (" + via + "): abriendo en el navegador del sistema: " + url);
            return true;
         case LOG_DISABLED:
            NativeMediaSound.log("URL (" + via + ") registrada, no abierta (-Dopenworlds.openUrls=1 para abrirla): " + url);
            return false;
         default:
            NativeMediaSound.log("URL (" + via + ") registrada, no abierta: no viene de una accion del usuario: " + url);
            return false;
      }
   }

   /** Equivalent of ShellExecute "open": >32 success, 2 not found, 31 no association. */
   static int shellOpen(String target) {
      try {
         if (!java.awt.Desktop.isDesktopSupported()) {
            return 31;
         }

         java.awt.Desktop dt = java.awt.Desktop.getDesktop();
         int colon = target.indexOf(':');
         boolean scheme = colon > 1 && target.substring(0, colon).matches("[A-Za-z][A-Za-z0-9+.-]*");
         if (scheme && !target.regionMatches(true, 0, "file:", 0, 5)) {
            dt.browse(new URI(target));
            return 42;
         }

         File f = NativeMock.localFile(scheme ? target.substring(5) : target);
         if (!f.exists()) {
            return 2;
         }

         dt.open(f);
         return 42;
      } catch (Exception e) {
         NativeMediaSound.log("no se pudo abrir " + target + ": " + e);
         return 31;
      }
   }
}
