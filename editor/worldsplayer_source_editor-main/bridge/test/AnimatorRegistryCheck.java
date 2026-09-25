import NET.worlds.core.AnimRegistry;
import NET.worlds.core.NativeAnimator;
import java.io.File;
import java.nio.file.Files;
import java.util.Vector;

/**
 * Registro de avatars.dat de gamma.dll (AnimRegistry / NativeAnimator):
 * escaner flex, gramaticas 0.3 y 0.2, getnameindex, getindexgeom y
 * getActionList. Casos contados a mano sobre assets/WorldsPlayer/cachedir/45.dat
 * (el avatars.dat de la cache de 2004).
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
      check(ok, what + " = " + got + (ok ? "" : " (esperado " + want + ")"));
   }

   static File repo() {
      File d = new File(".").getAbsoluteFile();
      while (d != null && !new File(d, "assets/WorldsPlayer/cachedir/45.dat").exists()) {
         d = d.getParentFile();
      }
      if (d == null) {
         throw new IllegalStateException("no encuentro assets/WorldsPlayer (ejecutar dentro del repo)");
      }
      return d;
   }

   /** Lo mismo que Archive.readTextFile: CR LF -> LF. */
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

      // 221 bloques "avatar" en 45.dat (grep -c '^avatar$').
      eq(reg.size(), 221, "tipos en 45.dat");
      // Orden del fichero: Achoo 0, Aggie 1, alexa 2, Amy 3, Aura 4.
      eq(NativeAnimator.getnameindex("aura"), 4, "getnameindex(aura)");
      eq(NativeAnimator.getnameindex("AURA"), 4, "getnameindex sin mayusculas (FUN_004508c0)");
      eq(NativeAnimator.getnameindex("achoo"), 0, "getnameindex(achoo)");
      eq(NativeAnimator.getnameindex("nadie"), -1, "getnameindex desconocido");
      eq(NativeAnimator.getnameindex(""), -1, "getnameindex vacio");
      eq(NativeAnimator.getindexgeom(1), "./avatars\\aggie.rwx", "getindexgeom(Aggie)");
      eq(NativeAnimator.getindexgeom(9999), "", "getindexgeom fuera de rango");

      AnimRegistry.AvatarType aggie = reg.type(1);
      eq(aggie.impKeys.toString(), "[walk, wait, endwait]", "Aggie implicitos");
      eq(aggie.impValues.toString(), "[common_walk, common_a_wait, common_a_endwait]", "Aggie secuencias implicitas");
      // 53 explicitos contados a mano (chairsit ... quicknap); clave en
      // minusculas, secuencia tal cual.
      eq(aggie.expKeys.size(), 53, "Aggie explicitos");
      eq(aggie.expKeys.get(4), "wave", "Aggie explicito 5");
      eq(aggie.expKeys.get(13), "ymca", "YMCA en minusculas (FUN_004280b0)");
      eq(aggie.expValues.get(13), "YMCA", "secuencia YMCA tal cual");
      eq(aggie.expKeys.get(47), "getlost", "getLost en minusculas");
      eq(aggie.expValues.get(32), "Skating-1", "identificador con '-'");
      eq(aggie.changeImps.size(), 4, "Aggie bloques changeimp");
      AnimRegistry.ChangeImp stand = aggie.changeImp("stand");
      eq(stand.keys.toString(), "[wait, endwait, walk]", "changeimp de stand: claves");
      eq(stand.values.toString(), "[willwait, willendwait, willwalk]", "changeimp de stand: secuencias");
      eq(aggie.changeImp("wave"), null, "wave sin changeimp");

      Vector<String> acts = NativeAnimator.getActionList(1);
      eq(acts.size(), 53, "getActionList(Aggie)");
      eq(acts.get(0), "chairsit", "getActionList primero");
      eq(NativeAnimator.getActionList(-1).size(), 0, "getActionList de tipo invalido: Vector vacio");

      // Gramatica 0.2 (FUN_0042d840): tipo fijo cy + slots walk/wait/endwait/wave.
      AnimRegistry r2 = AnimRegistry.get();
      r2.clear();
      r2.load(("# animation registry version 0.2\n"
            + "avatar Tina geometry=tina.rwx walk=tw wave=twv foo=bar endavatar\n").getBytes("ISO-8859-1"), "v02");
      eq(r2.size(), 2, "v0.2: cy + Tina");
      eq(r2.type(0).attr("geometry"), "cy.rwx", "v0.2 cy");
      eq(r2.type(1).attr("name"), "Tina", "v0.2 nombre");
      eq(r2.type(1).impKeys.toString(), "[walk, , ]", "v0.2 implicitos");
      eq(r2.type(1).impValues.toString(), "[tw, , ]", "v0.2 secuencias");
      eq(r2.type(1).expKeys.toString(), "[wave]", "v0.2 explicito");

      // Escaner: comentario, numero frente a identificador, '=' pegado.
      r2.clear();
      r2.load(("# animation registry version 0.3\nversion 3 # c\navatar\n name=2v\n"
            + " beginimp WALK=x.y-z endimp\nendavatar").getBytes("ISO-8859-1"), "lex");
      eq(r2.size(), 1, "texto sin '\\n' final");
      eq(r2.type(0).attr("name"), "2v", "'2v' es identificador (regla 13 gana por longitud)");
      eq(r2.type(0).impKeys.toString(), "[walk]", "clave implicita en minusculas");
      eq(r2.type(0).impValues.toString(), "[x.y-z]", "identificador con '.' y '-'");

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
      check(threw, "cookie desconocido");
      // La regla 12 (numero) es UN digito: "123" casa mas largo como
      // identificador (13) y "3" empata y gana la 12 por orden.
      r2.clear();
      r2.load("# animation registry version 0.3\nversion 3\navatar name=123 endavatar\n".getBytes("ISO-8859-1"), "num");
      eq(r2.type(0).attr("name"), "123", "'123' es identificador");
      threw = false;
      try {
         r2.load("# animation registry version 0.3\nversion 3\navatar name=3 endavatar\n".getBytes("ISO-8859-1"), "num");
      } catch (AnimRegistry.ParseError e) {
         threw = true;
      }
      check(threw, "un solo digito es token 0x109, no identificador -> error");

      System.out.println(fails == 0 ? "AnimatorRegistryCheck: OK" : "AnimatorRegistryCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}
