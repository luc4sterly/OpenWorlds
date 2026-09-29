package net.openworlds.solar;

import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.Writer;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.security.GeneralSecurityException;
import java.security.MessageDigest;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Base64;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

/**
 * The accounts (accounts.tsv in the data folder): one line per user with the
 * name, a salted PBKDF2 hash of the password (never the password itself),
 * the flags (vip, admin, banned), when it was created and last seen, the
 * last avatar and the friends list. Names are unique ignoring case.
 */
final class Accounts {
   private static final int ITERATIONS = 120_000;
   private static final SecureRandom RANDOM = new SecureRandom();

   static final class Account {
      final String name;
      private String hash;
      boolean vip;
      boolean admin;
      boolean banned;
      final long created;
      long lastSeen;
      String avatar = "";
      final Set<String> buddies = new LinkedHashSet<>();

      Account(String name, String hash, long created) {
         this.name = name;
         this.hash = hash;
         this.created = created;
      }

      /** VAR_PRIV for this account: VIP (both levels) and, for admins, broadcast. */
      int privileges() {
         int p = 0;
         if (vip || admin) {
            p |= Props.PRIV_VIP | Props.PRIV_VIP2;
         }
         if (admin) {
            p |= Props.PRIV_BROADCAST;
         }
         return p;
      }
   }

   private final File file;
   private final Map<String, Account> byKey = new TreeMap<>();

   private Accounts(File file) {
      this.file = file;
   }

   static Accounts load(File file) throws IOException {
      Accounts a = new Accounts(file);
      if (!file.isFile()) {
         return a;
      }
      try (BufferedReader r = Files.newBufferedReader(file.toPath(), StandardCharsets.UTF_8)) {
         String line;
         while ((line = r.readLine()) != null) {
            if (line.isEmpty() || line.startsWith("#")) {
               continue;
            }
            String[] f = line.split("\t", -1);
            if (f.length < 3 || !validName(f[0])) {
               continue;
            }
            Account acc = new Account(f[0], f[1], f.length > 3 ? parseLong(f[3]) : 0);
            for (String flag : f[2].split(",")) {
               switch (flag.trim()) {
                  case "vip":
                     acc.vip = true;
                     break;
                  case "admin":
                     acc.admin = true;
                     break;
                  case "banned":
                     acc.banned = true;
                     break;
                  default:
                     break;
               }
            }
            acc.lastSeen = f.length > 4 ? parseLong(f[4]) : 0;
            acc.avatar = f.length > 5 ? f[5] : "";
            if (f.length > 6 && !f[6].isEmpty()) {
               for (String b : f[6].split(",")) {
                  if (validName(b)) {
                     acc.buddies.add(b);
                  }
               }
            }
            a.byKey.put(key(acc.name), acc);
         }
      }
      return a;
   }

   synchronized void save() throws IOException {
      File dir = file.getAbsoluteFile().getParentFile();
      dir.mkdirs();
      File tmp = new File(dir, file.getName() + ".tmp");
      try (Writer w = Files.newBufferedWriter(tmp.toPath(), StandardCharsets.UTF_8)) {
         w.write("# J Solar Server accounts: name, password hash (PBKDF2), flags, created, last seen, avatar, friends\n");
         for (Account a : byKey.values()) {
            List<String> flags = new ArrayList<>();
            if (a.vip) {
               flags.add("vip");
            }
            if (a.admin) {
               flags.add("admin");
            }
            if (a.banned) {
               flags.add("banned");
            }
            w.write(a.name + "\t" + a.hash + "\t" + String.join(",", flags) + "\t" + a.created + "\t" + a.lastSeen
               + "\t" + clean(a.avatar) + "\t" + String.join(",", a.buddies) + "\n");
         }
      }
      tmp.setReadable(false, false);
      tmp.setReadable(true, true);
      tmp.setWritable(false, false);
      tmp.setWritable(true, true);
      Files.move(tmp.toPath(), file.toPath(), StandardCopyOption.REPLACE_EXISTING, StandardCopyOption.ATOMIC_MOVE);
   }

   synchronized Account get(String name) {
      return name == null ? null : byKey.get(key(name));
   }

   synchronized List<Account> list() {
      return new ArrayList<>(byKey.values());
   }

   synchronized int size() {
      return byKey.size();
   }

   /** A new account; throws IllegalArgumentException with a readable reason when it cannot be. */
   synchronized Account create(String name, String password) {
      if (!validName(name)) {
         throw new IllegalArgumentException("A name has 2 to 16 letters, digits, - or _.");
      }
      if (byKey.containsKey(key(name))) {
         throw new IllegalArgumentException("The name " + name + " is already taken.");
      }
      if (password == null || password.length() < 4) {
         throw new IllegalArgumentException("A password has at least 4 characters.");
      }
      Account a = new Account(name, hash(password), System.currentTimeMillis());
      byKey.put(key(name), a);
      return a;
   }

   synchronized boolean delete(String name) {
      return byKey.remove(key(name)) != null;
   }

   synchronized void setPassword(Account a, String password) {
      if (password == null || password.length() < 4) {
         throw new IllegalArgumentException("A password has at least 4 characters.");
      }
      a.hash = hash(password);
   }

   static boolean verify(Account a, String password) {
      return password != null && check(a.hash, password);
   }

   /**
    * What FriendsListPart.isValidUserName accepts, so every account can be a
    * friend in the client: 2 to 16 letters, digits, '-' and '_'.
    */
   static boolean validName(String name) {
      if (name == null || name.length() < 2 || name.length() > 16) {
         return false;
      }
      for (int i = 0; i < name.length(); i++) {
         char c = name.charAt(i);
         if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '-' || c == '_')) {
            return false;
         }
      }
      return true;
   }

   static String key(String name) {
      return name.toLowerCase(Locale.ROOT);
   }

   static String hash(String password) {
      byte[] salt = new byte[16];
      RANDOM.nextBytes(salt);
      byte[] h = pbkdf2(password, salt, ITERATIONS);
      Base64.Encoder b64 = Base64.getEncoder().withoutPadding();
      return "pbkdf2-sha256$" + ITERATIONS + "$" + b64.encodeToString(salt) + "$" + b64.encodeToString(h);
   }

   static boolean check(String stored, String password) {
      String[] f = stored.split("\\$");
      if (f.length != 4 || !f[0].equals("pbkdf2-sha256")) {
         return false;
      }
      try {
         byte[] salt = Base64.getDecoder().decode(f[2]);
         byte[] want = Base64.getDecoder().decode(f[3]);
         byte[] got = pbkdf2(password, salt, Integer.parseInt(f[1]));
         return MessageDigest.isEqual(want, got);
      } catch (IllegalArgumentException e) {
         return false;
      }
   }

   private static byte[] pbkdf2(String password, byte[] salt, int iterations) {
      try {
         PBEKeySpec spec = new PBEKeySpec(password.toCharArray(), salt, iterations, 256);
         return SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256").generateSecret(spec).getEncoded();
      } catch (GeneralSecurityException e) {
         throw new IllegalStateException(e);
      }
   }

   private static long parseLong(String s) {
      try {
         return Long.parseLong(s.trim());
      } catch (NumberFormatException e) {
         return 0;
      }
   }

   private static String clean(String s) {
      return s == null ? "" : s.replace('\t', ' ').replace('\n', ' ').replace('\r', ' ');
   }
}
