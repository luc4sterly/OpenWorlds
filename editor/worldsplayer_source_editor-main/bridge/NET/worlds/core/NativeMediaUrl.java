package NET.worlds.core;

import java.io.File;
import java.net.URI;

/**
 * Abrir una URL fuera del cliente: {@code SendURLAction.launchViaRegistry}
 * (0x00413a10, {@code ShellExecuteA(NULL, "open", url, NULL, NULL,
 * SW_SHOWNORMAL)}) y {@code sendURL.get/silent_get} (0x004210a0/0x00421300,
 * DDE {@code WWW_OpenURL} al navegador). Aqui eso es el navegador del
 * sistema ({@code java.awt.Desktop}), con dos candados:
 * <ol>
 * <li>solo con {@code -Dopenworlds.openUrls=1}; sin el, la URL se registra
 *     en el log y no se abre nada;</li>
 * <li>solo si la peticion sale de una accion explicita del usuario: la pila
 *     de la llamada que la origino contiene uno de los puntos de entrada de
 *     {@link #USER_ORIGINS} (confirmar el dialogo "Browse?" de
 *     {@code SendURLAction}, un menu, un boton del mapa o del asistente, un
 *     clic en un cartel). Todo lo demas (disparadores del mundo, scripts,
 *     banners, carga de sala) solo se registra.</li>
 * </ol>
 */
public final class NativeMediaUrl {
   private NativeMediaUrl() {
   }

   public static final boolean OPEN_URLS = "1".equals(System.getProperty("openworlds.openUrls"))
      || "true".equalsIgnoreCase(System.getProperty("openworlds.openUrls"));

   /** Metodos (clase.metodo) que solo se ejecutan por una accion del usuario. */
   static final String[] USER_ORIGINS = new String[]{
      "NET.worlds.scape.DialogAction.dialogDone", // OK en el dialogo de SendURLAction
      "NET.worlds.console.DefaultConsole.action", // menus de la consola
      "NET.worlds.console.DefaultConsole$2.actionPerformed", // menu de ayuda "file:"
      "NET.worlds.console.MapPart.imageButtonsCallback", // botones del mapa
      "NET.worlds.console.LoginWizard.action", // botones del asistente
      "NET.worlds.network.UpgradeDialog.action", // "mas informacion" de la actualizacion
      "NET.worlds.scape.Billboard.billboardClicked", // clic en un cartel
      "NET.worlds.scape.WebPageWall.handle" // clic en un WebPageWall (ver ⚠️ en el informe)
   };

   public enum Decision {
      OPEN,
      LOG_DISABLED,
      LOG_NOT_USER
   }

   /** true si alguna de las entradas de pila es un origen de usuario. */
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

   /** La decision, pura: con el flag y con origen de usuario se abre. */
   public static Decision decide(boolean openUrls, boolean userOrigin) {
      if (!openUrls) {
         return Decision.LOG_DISABLED;
      }

      return userOrigin ? Decision.OPEN : Decision.LOG_NOT_USER;
   }

   /**
    * Origen de la peticion en curso de este hilo. SendURLAction lo anota en
    * startBrowser (la pila aun tiene el menu o el dialogo) porque tryLaunch
    * puede correr despues desde Main.mainCallback, con otra pila.
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
   // exito si devuelve > 32. Si falla: "Error <n> in ShellExecuting <url>.\n"
   // y, solo con ERROR_FILE_NOT_FOUND (2), un reintento. Registrar sin
   // abrir devuelve false (no se lanzo nada): el Java imprime entonces su
   // mensaje "Unable-to-launch" en la consola.
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

   /** DDE WWW_OpenURL de sendURL.get/silent_get: 1 si se abrio, 0 como un DdeConnect fallido. */
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

   /** Equivalente de ShellExecute "open": >32 exito, 2 no encontrado, 31 sin asociacion. */
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
