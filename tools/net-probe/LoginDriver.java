import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Component;
import java.awt.Container;
import java.awt.EventQueue;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.Toolkit;
import java.awt.Window;
import java.awt.event.ActionEvent;

/**
 * Arnes de red (tools/net-probe, docs/net-local-whirl.md): arranca el
 * NET.worlds.console.Gamma.main REAL y, en un hilo aparte, hace con la UI AWT
 * del original lo que haria una persona. No toca logica del cliente: solo
 * escribe en campos de texto y "pulsa" botones: al Button le postea en la cola
 * AWT el mismo ActionEvent que genera el peer al hacer clic (AWT lo convierte
 * al Event 1.0 que recibe LoginWizard.action); a la linea de chat le entrega
 * directamente el Event 1.0 ACTION_EVENT de Intro, porque en el JDK 25 de
 * macOS la conversion no ocurre en los TextField (ver chat()).
 *
 * - FREEWORLDS_LOGIN=contrasena: cuando aparece el LoginWizard (pantalla
 *   HAVE_USERS, la de "Sign-In"), escribe la contrasena en el campo con eco
 *   '*' (knownPassword), el nombre en typedUsername si esta vacio
 *   (FREEWORLDS_USER), desmarca "Remember password" y pulsa el ForwardButton.
 *   Desmarcarlo evita Console.encode -> Console.encrypt (nativo de gamma.dll
 *   aun sin traducir en el puente: con el mock devuelve null y
 *   LoginWizard.setConnected moriria en encode(null.toCharArray())). Solo
 *   para servidores locales de prueba: whirl no comprueba la contrasena.
 * - FREEWORLDS_CHAT=MS:texto[;MS:texto...] (o -Dfreeworlds.chatScript, sin
 *   espacios: run_gamma.sh parte JAVA_OPTS por espacios): a MS milisegundos de
 *   cerrarse el LoginWizard (o del arranque, sin FREEWORLDS_LOGIN) escribe el
 *   texto en la linea de chat (FocusPreservingTextField de ChatPart) y la
 *   "envia" (Intro).
 * - -Dfreeworlds.dumpChat=MS[,MS...]: vuelca a stdout el contenido del area de
 *   chat (TextArea de ClassicSharedTextArea) en esos instantes, con el prefijo
 *   [CHAT].
 * - -Dfreeworlds.dumpDrones=MS[,MS...]: lista los Drone (avatares de otros)
 *   de todas las salas cargadas, con su sala y posicion, prefijo [DRONES].
 */
public class LoginDriver {
   private static final long T0 = System.currentTimeMillis();

   public static void main(String[] args) throws Exception {
      Thread t = new Thread("freeworlds-loginDriver") {
         public void run() {
            try {
               drive();
            } catch (InterruptedException e) {
               // fin del proceso
            }
         }
      };
      t.setDaemon(true);
      t.start();
      NET.worlds.console.Gamma.main(args);
   }

   private static void log(String s) {
      System.out.println("[DRIVER " + (System.currentTimeMillis() - T0) + "ms] " + s);
   }

   private static void drive() throws InterruptedException {
      String password = System.getenv("FREEWORLDS_LOGIN");
      String user = System.getenv("FREEWORLDS_USER");
      String chat = System.getenv("FREEWORLDS_CHAT");
      if (chat == null) {
         chat = System.getProperty("freeworlds.chatScript", "");
      }
      String dump = System.getProperty("freeworlds.dumpChat", "");
      java.util.TreeMap<Long, String> events = new java.util.TreeMap<Long, String>();
      long seq = 0;
      for (String item : dump.split(",")) {
         if (item.trim().length() > 0) {
            events.put(Long.parseLong(item.trim()) * 1000 + seq++, "dump:");
         }
      }
      String drones = System.getProperty("freeworlds.dumpDrones", "");
      for (String item : drones.split(",")) {
         if (item.trim().length() > 0) {
            events.put(Long.parseLong(item.trim()) * 1000 + seq++, "drones:");
         }
      }
      java.util.TreeMap<Long, String> chats = new java.util.TreeMap<Long, String>();
      for (String item : chat.split(";")) {
         int c = item.indexOf(':');
         if (c > 0) {
            chats.put(Long.parseLong(item.substring(0, c).trim()) * 1000 + seq++, item.substring(c + 1));
         }
      }
      boolean signedIn = password == null || password.length() == 0;
      long chatBase = signedIn ? 0 : -1;
      while (true) {
         long now = System.currentTimeMillis() - T0;
         if (!signedIn) {
            signedIn = trySignIn(password, user);
         } else if (chatBase < 0 && findWindow("NET.worlds.console.LoginWizard") == null) {
            chatBase = now; // el asistente se cerro: sesion hecha
            log("LoginWizard cerrado; el guion de chat cuenta desde aqui");
         }
         while (!events.isEmpty() && events.firstKey() / 1000 <= now) {
            String ev = events.remove(events.firstKey());
            if (ev.startsWith("drones:")) {
               dumpDrones();
            } else {
               dumpChat();
            }
         }
         while (chatBase >= 0 && !chats.isEmpty() && chatBase + chats.firstKey() / 1000 <= now) {
            chat(chats.remove(chats.firstKey()));
         }
         if (signedIn && chatBase >= 0 && events.isEmpty() && chats.isEmpty()) {
            return;
         }
         Thread.sleep(250);
      }
   }

   /** Drones (avatares remotos) de todas las salas de todos los mundos cargados. */
   private static void dumpDrones() {
      int n = 0;
      try {
         java.util.Enumeration<?> ws = NET.worlds.scape.World.getWorlds();
         while (ws.hasMoreElements()) {
            NET.worlds.scape.World w = (NET.worlds.scape.World)ws.nextElement();
            java.util.Enumeration<?> rs = w.getRooms();
            while (rs.hasMoreElements()) {
               NET.worlds.scape.Room r = (NET.worlds.scape.Room)rs.nextElement();
               java.util.Enumeration<?> cs = r.getContents();
               while (cs.hasMoreElements()) {
                  Object o = cs.nextElement();
                  if (o instanceof NET.worlds.scape.Drone) {
                     NET.worlds.scape.Drone d = (NET.worlds.scape.Drone)o;
                     System.out.println("[DRONES " + (System.currentTimeMillis() - T0) + "ms] " + d.getClass().getSimpleName()
                        + " '" + d.getName() + "' en " + r.getName() + " @ " + d.getPosition());
                     n++;
                  }
               }
            }
         }
      } catch (RuntimeException e) {
         log("dumpDrones: " + e);
      }
      System.out.println("[DRONES " + (System.currentTimeMillis() - T0) + "ms] total " + n);
   }

   private static Window findWindow(String className) {
      for (Window w : Window.getWindows()) {
         if (w.getClass().getName().equals(className) && w.isShowing()) {
            return w;
         }
      }
      return null;
   }

   private static void collect(Component c, Class<?> type, java.util.List<Component> out) {
      if (type.isInstance(c) && c.isShowing()) {
         out.add(c);
      }
      if (c instanceof Container) {
         for (Component k : ((Container)c).getComponents()) {
            collect(k, type, out);
         }
      }
   }

   private static java.util.List<Component> all(Component root, Class<?> type) {
      java.util.List<Component> out = new java.util.ArrayList<Component>();
      collect(root, type, out);
      return out;
   }

   private static void onEdt(Runnable r) {
      try {
         EventQueue.invokeAndWait(r);
      } catch (Exception e) {
         log("error en el EDT: " + e);
      }
   }

   private static void press(Component target, String command) {
      Toolkit.getDefaultToolkit().getSystemEventQueue().postEvent(new ActionEvent(target, ActionEvent.ACTION_PERFORMED, command));
   }

   private static boolean trySignIn(final String password, final String user) {
      Window wiz = findWindow("NET.worlds.console.LoginWizard");
      if (wiz == null) {
         return false;
      }
      TextField pw = null;
      TextField name = null;
      for (Component c : all(wiz, TextField.class)) {
         TextField f = (TextField)c;
         if (f.getEchoChar() == '*') {
            pw = f;
         } else if (name == null) {
            name = f;
         }
      }
      Button forward = null;
      for (Component c : all(wiz, Button.class)) {
         if (c.getClass().getName().equals("NET.worlds.console.ForwardButton")) {
            forward = (Button)c;
         }
      }
      if (pw == null || forward == null) {
         return false; // otra pantalla del asistente (o aun sin construir)
      }
      final TextField fpw = pw;
      final TextField fname = name;
      final java.util.List<Component> boxes = all(wiz, Checkbox.class);
      onEdt(new Runnable() {
         public void run() {
            if (fname != null && fname.getText().length() == 0 && user != null) {
               fname.setText(user);
            }
            fpw.setText(password);
            for (Component b : boxes) {
               ((Checkbox)b).setState(false);
            }
         }
      });
      log("LoginWizard: usuario '" + (name == null ? "?" : name.getText()) + "', contrasena escrita, pulso '" + forward.getLabel() + "'");
      press(forward, forward.getLabel());
      return true;
   }

   private static Window gammaFrame() {
      return findWindow("NET.worlds.console.GammaFrame");
   }

   private static void chat(final String text) {
      Window f = gammaFrame();
      TextField line = null;
      if (f != null) {
         for (Component c : all(f, TextField.class)) {
            if (c.getClass().getName().equals("NET.worlds.console.FocusPreservingTextField")) {
               line = (TextField)c;
            }
         }
      }
      if (line == null) {
         log("chat: no hay linea de chat visible, no se envia '" + text + "'");
         return;
      }
      final TextField fl = line;
      log("chat: escribo '" + text + "' + Intro");
      onEdt(new Runnable() {
         public void run() {
            fl.setText(text);
            // Intro en un TextField: el peer postea un ActionEvent y el
            // Component.dispatchEventImpl de AWT lo convierte al Event 1.0
            // (ACTION_EVENT, arg = texto) y hace postEvent, que es lo que
            // DuplexPart.action espera. En el JDK 25 de macOS esa conversion
            // no ocurre en ningun TextField: al crear el peer se le anade un
            // InputMethodListener, eso pone Component.newEventsOnly = true y
            // dispatchEventImpl ya no genera eventos 1.0 (medido: false recien
            // creado, true tras addNotify; ni ActionEvent ni KEY_PRESSED llegan
            // a handleEvent). Aqui se hace a mano el paso de compatibilidad.
            fl.postEvent(new java.awt.Event(fl, java.awt.Event.ACTION_EVENT, fl.getText()));
         }
      });
      try {
         Thread.sleep(1000);
      } catch (InterruptedException e) {
         return;
      }
      // DuplexPart.trigger() vacia la linea al aceptar el texto
      log("chat: linea tras Intro = '" + line.getText() + "'");
   }

   private static void dumpChat() {
      Window f = gammaFrame();
      if (f == null) {
         log("dumpChat: sin ventana");
         return;
      }
      int i = 0;
      for (Component c : all(f, TextArea.class)) {
         String s = ((TextArea)c).getText();
         for (String l : s.split("\n")) {
            System.out.println("[CHAT " + (System.currentTimeMillis() - T0) + "ms #" + i + "] " + l);
         }
         i++;
      }
   }
}
