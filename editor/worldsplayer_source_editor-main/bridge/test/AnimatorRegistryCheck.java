import NET.worlds.core.AnimRegistry;
import NET.worlds.core.NativeAnimator;
import java.io.File;
import java.nio.file.Files;
import java.util.Vector;

/**
 * gamma.dll's avatars.dat registry (AnimRegistry / NativeAnimator):
 * flex scanner, grammars 0.3 and 0.2, getnameindex, getindexgeom and
 * getActionList. Cases counted by hand on assets/WorldsPlayer/cachedir/45.dat
 * (the avatars.dat of the 2004 cache).
 *
 * javac -cp editor/.build-gamma/out -d /tmp/x AnimatorRegistryCheck.java
 * java -cp editor/.build-gamma/out:/tmp/x AnimatorRegistryCheck
 */
public class AnimatorRegistryCheck {
   private static int fails;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "ok   " : "FAIL ") + what);
      if (!ok) {
         fails++;
      }
   }

   static void eq(Object got, Object want, String what) {
      boolean ok = want == null ? got == null : want.equals(got);
      check(ok, what + " = " + got + (ok ? "" : " (expected " + want + ")"));
   }

   static File repo() {
      File d = new File(".").getAbsoluteFile();
      while (d != null && !new File(d, "assets/WorldsPlayer/cachedir/45.dat").exists()) {
         d = d.getParentFile();
      }
      if (d == null) {
         throw new IllegalStateException("assets/WorldsPlayer not found (run inside the repo)");
      }
      return d;
   }

   /** The same as Archive.readTextFile: CR LF -> LF. */
   static byte[] text(File f) throws Exception {
      byte[] b = Files.readAllBytes(f.toPath());
      java.io.ByteArrayOutputStream o = new java.io.ByteArrayOutputStream();
      for (int i = 0; i < b.length; i++) {
         if (b[i] == 13 && i + 1 < b.length && b[i + 1] == 10) {
            continue;
         }
         o.write(b[i]);
      }
      return o.toByteArray();
   }

   public static void main(String[] args) throws Exception {
      File root = repo();
      AnimRegistry reg = AnimRegistry.get();
      NativeAnimator.init(".");
      reg.load(text(new File(root, "assets/WorldsPlayer/cachedir/45.dat")), "45.dat");

      // 221 "avatar" blocks in 45.dat (grep -c '^avatar$').
      eq(reg.size(), 221, "types in 45.dat");
      // File order: Achoo 0, Aggie 1, alexa 2, Amy 3, Aura 4.
      eq(NativeAnimator.getnameindex("aura"), 4, "getnameindex(aura)");
      eq(NativeAnimator.getnameindex("AURA"), 4, "getnameindex case-insensitive (FUN_004508c0)");
      eq(NativeAnimator.getnameindex("achoo"), 0, "getnameindex(achoo)");
      eq(NativeAnimator.getnameindex("nadie"), -1, "getnameindex unknown");
      eq(NativeAnimator.getnameindex(""), -1, "getnameindex empty");
      eq(NativeAnimator.getindexgeom(1), "./avatars\\aggie.rwx", "getindexgeom(Aggie)");
      eq(NativeAnimator.getindexgeom(9999), "", "getindexgeom out of range");

      AnimRegistry.AvatarType aggie = reg.type(1);
      eq(aggie.impKeys.toString(), "[walk, wait, endwait]", "Aggie implicit keys");
      eq(aggie.impValues.toString(), "[common_walk, common_a_wait, common_a_endwait]", "Aggie implicit sequences");
      // 53 explicits counted by hand (chairsit ... quicknap); key in
      // lowercase, sequence as is.
      eq(aggie.expKeys.size(), 53, "Aggie explicit animations");
      eq(aggie.expKeys.get(4), "wave", "Aggie explicit animation 5");
      eq(aggie.expKeys.get(13), "ymca", "YMCA in lowercase (FUN_004280b0)");
      eq(aggie.expValues.get(13), "YMCA", "YMCA sequence as is");
      eq(aggie.expKeys.get(47), "getlost", "getLost in lowercase");
      eq(aggie.expValues.get(32), "Skating-1", "identifier with '-'");
      eq(aggie.changeImps.size(), 4, "Aggie changeimp blocks");
      AnimRegistry.ChangeImp stand = aggie.changeImp("stand");
      eq(stand.keys.toString(), "[wait, endwait, walk]", "changeimp of stand: keys");
      eq(stand.values.toString(), "[willwait, willendwait, willwalk]", "changeimp of stand: sequences");
      eq(aggie.changeImp("wave"), null, "wave without changeimp");

      Vector<String> acts = NativeAnimator.getActionList(1);
      eq(acts.size(), 53, "getActionList(Aggie)");
      eq(acts.get(0), "chairsit", "getActionList first");
      eq(NativeAnimator.getActionList(-1).size(), 0, "getActionList of an invalid type: empty Vector");

      // Grammar 0.2 (FUN_0042d840): fixed type cy + slots walk/wait/endwait/wave.
      AnimRegistry r2 = AnimRegistry.get();
      r2.clear();
      r2.load(("# animation registry version 0.2\n"
            + "avatar Tina geometry=tina.rwx walk=tw wave=twv foo=bar endavatar\n").getBytes("ISO-8859-1"), "v02");
      eq(r2.size(), 2, "v0.2: cy + Tina");
      eq(r2.type(0).attr("geometry"), "cy.rwx", "v0.2 cy");
      eq(r2.type(1).attr("name"), "Tina", "v0.2 name");
      eq(r2.type(1).impKeys.toString(), "[walk, , ]", "v0.2 implicit keys");
      eq(r2.type(1).impValues.toString(), "[tw, , ]", "v0.2 sequences");
      eq(r2.type(1).expKeys.toString(), "[wave]", "v0.2 explicit");

      // Scanner: comment, number versus identifier, attached '='.
      r2.clear();
      r2.load(("# animation registry version 0.3\nversion 3 # c\navatar\n name=2v\n"
            + " beginimp WALK=x.y-z endimp\nendavatar").getBytes("ISO-8859-1"), "lex");
      eq(r2.size(), 1, "text without a final '\\n'");
      eq(r2.type(0).attr("name"), "2v", "'2v' is an identifier (rule 13 wins by length)");
      eq(r2.type(0).impKeys.toString(), "[walk]", "implicit key in lowercase");
      eq(r2.type(0).impValues.toString(), "[x.y-z]", "identifier with '.' and '-'");

      boolean threw = false;
      try {
         r2.load("# animation registry version 0.3\nversion 2\n".getBytes("ISO-8859-1"), "v2");
      } catch (AnimRegistry.ParseError e) {
         threw = e.getMessage().startsWith("can't handle requested file version");
      }
      check(threw, "version 2 -> can't handle requested file version");
      threw = false;
      try {
         r2.load("# animation registry version 0.4\n".getBytes("ISO-8859-1"), "v4");
      } catch (AnimRegistry.ParseError e) {
         threw = e.getMessage().startsWith("unrecognized cookie");
      }
      check(threw, "unknown cookie");
      // Rule 12 (number) is ONE digit: "123" matches longer as an
      // identifier (13) and "3" ties and rule 12 wins by order.
      r2.clear();
      r2.load("# animation registry version 0.3\nversion 3\navatar name=123 endavatar\n".getBytes("ISO-8859-1"), "num");
      eq(r2.type(0).attr("name"), "123", "'123' is an identifier");
      threw = false;
      try {
         r2.load("# animation registry version 0.3\nversion 3\navatar name=3 endavatar\n".getBytes("ISO-8859-1"), "num");
      } catch (AnimRegistry.ParseError e) {
         threw = true;
      }
      check(threw, "a single digit is token 0x109, not an identifier -> error");

      System.out.println(fails == 0 ? "AnimatorRegistryCheck: OK" : "AnimatorRegistryCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}
