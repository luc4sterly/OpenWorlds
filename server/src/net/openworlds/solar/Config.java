package net.openworlds.solar;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.Properties;

/** The server's settings (server.properties in the data folder), with the defaults a new server starts with. */
final class Config {
   final File file;
   String name = "My Worlds server";
   /** Name that system messages (welcome, broadcasts) come from in the chat. */
   String sender = "Solar";
   String welcome = "Welcome to {server}, {user}! Type /help to see the chat commands.";
   String bind = "0.0.0.0";
   int port = 6650;
   boolean plainEnabled = true;
   boolean tlsEnabled = false;
   int tlsPort = 6651;
   /** A PKCS#12 keystore of your own (e.g. for a real domain); empty = the generated self-signed one. */
   String tlsKeystore = "";
   String tlsPassword = "";
   /** A new name creates its account the first time it signs in (with the password typed then). */
   boolean openSignup = true;
   boolean guests = true;
   /** Players online at once; 0 = no limit. */
   int maxUsers = 100;
   /** The admin window starts the server as soon as it opens. */
   boolean autoStart = true;

   Config(File file) {
      this.file = file;
   }

   static Config load(File file) {
      Config c = new Config(file);
      Properties p = new Properties();
      if (file.isFile()) {
         try (InputStream in = new FileInputStream(file)) {
            p.load(in);
         } catch (IOException e) {
            System.err.println("[solar] could not read " + file + ": " + e.getMessage());
         }
      }
      c.name = p.getProperty("server.name", c.name);
      c.sender = p.getProperty("system.sender", c.sender);
      c.welcome = p.getProperty("welcome", c.welcome);
      c.bind = p.getProperty("bind", c.bind);
      c.port = num(p, "port", c.port);
      c.plainEnabled = bool(p, "plain.enabled", c.plainEnabled);
      c.tlsEnabled = bool(p, "tls.enabled", c.tlsEnabled);
      c.tlsPort = num(p, "tls.port", c.tlsPort);
      c.tlsKeystore = p.getProperty("tls.keystore", c.tlsKeystore);
      c.tlsPassword = p.getProperty("tls.password", c.tlsPassword);
      c.openSignup = bool(p, "signup.open", c.openSignup);
      c.guests = bool(p, "guests.allowed", c.guests);
      c.maxUsers = num(p, "max.users", c.maxUsers);
      c.autoStart = bool(p, "autostart", c.autoStart);
      return c;
   }

   synchronized void save() throws IOException {
      Properties p = new Properties();
      p.setProperty("server.name", name);
      p.setProperty("system.sender", sender);
      p.setProperty("welcome", welcome);
      p.setProperty("bind", bind);
      p.setProperty("port", Integer.toString(port));
      p.setProperty("plain.enabled", Boolean.toString(plainEnabled));
      p.setProperty("tls.enabled", Boolean.toString(tlsEnabled));
      p.setProperty("tls.port", Integer.toString(tlsPort));
      p.setProperty("tls.keystore", tlsKeystore);
      p.setProperty("tls.password", tlsPassword);
      p.setProperty("signup.open", Boolean.toString(openSignup));
      p.setProperty("guests.allowed", Boolean.toString(guests));
      p.setProperty("max.users", Integer.toString(maxUsers));
      p.setProperty("autostart", Boolean.toString(autoStart));
      File dir = file.getAbsoluteFile().getParentFile();
      dir.mkdirs();
      File tmp = new File(dir, file.getName() + ".tmp");
      try (OutputStream out = new FileOutputStream(tmp)) {
         p.store(out, "J Solar Server settings (edit while the server is stopped, or use the admin window)");
      }
      Files.move(tmp.toPath(), file.toPath(), StandardCopyOption.REPLACE_EXISTING, StandardCopyOption.ATOMIC_MOVE);
   }

   /** The welcome message with {server} and {user} filled in. */
   String welcomeFor(String user) {
      return welcome.replace("{server}", name).replace("{user}", user);
   }

   private static int num(Properties p, String key, int def) {
      try {
         return Integer.parseInt(p.getProperty(key, "").trim());
      } catch (NumberFormatException e) {
         return def;
      }
   }

   private static boolean bool(Properties p, String key, boolean def) {
      String v = p.getProperty(key);
      return v == null ? def : Boolean.parseBoolean(v.trim());
   }
}
