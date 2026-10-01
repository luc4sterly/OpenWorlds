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
 * Network harness (tools/net-probe, docs/net-local-whirl.md): starts the REAL
 * NET.worlds.console.Gamma.main and, in a separate thread, does with the
 * original's AWT UI what a person would do. It touches no client logic: it
 * only types into text fields and "presses" buttons: for a Button it posts
 * to the AWT queue the same ActionEvent the peer generates on a click (AWT
 * converts it into the Event 1.0 that LoginWizard.action receives); to the
 * chat line it delivers the Enter key's Event 1.0 ACTION_EVENT directly,
 * because in macOS's JDK 25 that conversion does not happen in TextFields
 * (see chat()).
 *
 * - OPENWORLDS_LOGIN=password: when the LoginWizard shows up (the
 *   HAVE_USERS screen, the "Sign-In" one), types the password into the field
 *   that echoes '*' (knownPassword), the name into typedUsername if it is
 *   empty (OPENWORLDS_USER), unticks "Remember password" and presses the
 *   ForwardButton. Unticking it avoids Console.encode -> Console.encrypt (a
 *   gamma.dll native not yet translated in the bridge: with the mock it
 *   returns null and LoginWizard.setConnected would die in
 *   encode(null.toCharArray())). Only for local test servers: whirl does not
 *   check the password.
 * - OPENWORLDS_CHAT=MS:text[;MS:text...] (or -Dopenworlds.chatScript, without
 *   spaces: run_gamma.sh splits JAVA_OPTS on spaces): MS milliseconds after
 *   the LoginWizard closes (or after startup, without OPENWORLDS_LOGIN) it
 *   types the text into the chat line (ChatPart's FocusPreservingTextField)
 *   and "sends" it (Enter).
 * - -Dopenworlds.dumpChat=MS[,MS...]: dumps to stdout the contents of the
 *   chat area (ClassicSharedTextArea's TextArea) at those instants, with the
 *   prefix [CHAT].
 * - -Dopenworlds.dumpDrones=MS[,MS...]: lists the Drones (other people's
 *   avatars) in all the loaded rooms, with their room and position, prefix
 *   [DRONES].
 */
public class LoginDriver {
   private static final long T0 = System.currentTimeMillis();

   public static void main(String[] args) throws Exception {
      Thread t = new Thread("openworlds-loginDriver") {
         public void run() {
            try {
               drive();
            } catch (InterruptedException e) {
               // end of the process
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
      String password = System.getenv("OPENWORLDS_LOGIN");
      String user = System.getenv("OPENWORLDS_USER");
      String chat = System.getenv("OPENWORLDS_CHAT");
      if (chat == null) {
         chat = System.getProperty("openworlds.chatScript", "");
      }
      String dump = System.getProperty("openworlds.dumpChat", "");
      java.util.TreeMap<Long, String> events = new java.util.TreeMap<Long, String>();
      long seq = 0;
      for (String item : dump.split(",")) {
         if (item.trim().length() > 0) {
            events.put(Long.parseLong(item.trim()) * 1000 + seq++, "dump:");
         }
      }
      String drones = System.getProperty("openworlds.dumpDrones", "");
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
            chatBase = now; // the wizard closed: signed in
            log("LoginWizard closed; the chat script counts from here");
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

   /** Drones (remote avatars) in every room of every loaded world. */
   private static void dumpDrones() {
      int n = 0;
      int nw = 0;
      int nr = 0;
      try {
         java.util.Enumeration<?> ws = NET.worlds.scape.World.getWorlds();
         while (ws.hasMoreElements()) {
            NET.worlds.scape.World w = (NET.worlds.scape.World)ws.nextElement();
            nw++;
            java.util.Enumeration<?> rs = w.getRooms();
            while (rs.hasMoreElements()) {
               NET.worlds.scape.Room r = (NET.worlds.scape.Room)rs.nextElement();
               nr++;
               java.util.Enumeration<?> cs = r.getContents();
               while (cs.hasMoreElements()) {
                  Object o = cs.nextElement();
                  if (o instanceof NET.worlds.scape.Drone) {
                     NET.worlds.scape.Drone d = (NET.worlds.scape.Drone)o;
                     System.out.println("[DRONES " + (System.currentTimeMillis() - T0) + "ms] " + d.getClass().getSimpleName()
                        + " '" + d.getName() + "' in " + r.getName() + " @ " + d.getX() + "," + d.getY() + "," + d.getZ());
                     n++;
                  }
               }
            }
         }
      } catch (RuntimeException e) {
         log("dumpDrones: " + e);
         e.printStackTrace(System.out);
      }
      System.out.println("[DRONES " + (System.currentTimeMillis() - T0) + "ms] total " + n + " (worlds " + nw + ", rooms " + nr + ")");
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
         log("error on the EDT: " + e);
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
         return false; // another wizard screen (or not built yet)
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
      log("LoginWizard: user '" + (name == null ? "?" : name.getText()) + "', password typed, pressing '" + forward.getLabel() + "'");
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
         log("chat: no chat line visible, not sending '" + text + "'");
         return;
      }
      final TextField fl = line;
      log("chat: typing '" + text + "' + Enter");
      onEdt(new Runnable() {
         public void run() {
            fl.setText(text);
            // Enter in a TextField: the peer posts an ActionEvent and AWT's
            // Component.dispatchEventImpl converts it into the Event 1.0
            // (ACTION_EVENT, arg = text) and does postEvent, which is what
            // DuplexPart.action expects. In macOS's JDK 25 that conversion
            // does not happen in any TextField: creating the peer adds an
            // InputMethodListener, which sets Component.newEventsOnly = true
            // and dispatchEventImpl no longer generates 1.0 events (measured:
            // false when just created, true after addNotify; neither
            // ActionEvent nor KEY_PRESSED reach handleEvent). The
            // compatibility step is done by hand here.
            fl.postEvent(new java.awt.Event(fl, java.awt.Event.ACTION_EVENT, fl.getText()));
         }
      });
      try {
         Thread.sleep(1000);
      } catch (InterruptedException e) {
         return;
      }
      // DuplexPart.trigger() empties the line when it accepts the text
      log("chat: line after Enter = '" + line.getText() + "'");
   }

   private static void dumpChat() {
      Window f = gammaFrame();
      if (f == null) {
         log("dumpChat: no window");
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
