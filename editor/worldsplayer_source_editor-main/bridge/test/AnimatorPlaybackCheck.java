import NET.worlds.core.AnimAnimator;
import NET.worlds.core.AnimGraph;
import NET.worlds.core.AnimPose;
import NET.worlds.core.AnimRegistry;
import NET.worlds.core.AnimSeqCache;
import NET.worlds.core.AnimTime;
import NET.worlds.core.NativeAnimator;
import java.io.File;
import java.nio.file.Files;

/**
 * Reproduccion de DroneAnimator (gamma.dll): cache de .seq con addtype,
 * animate/getAnimationTime (duraciones), drivers por tiempo y por distancia
 * (keys truncados, bucle, ultimo key, marcha atras), cambio de implicito de
 * 250 ms y gesto encima del implicito. Avatar Axel del Avatars.dat de
 * assets/gammatutorial-samples/base-avatars y sus .seq. Valores a mano en
 * los comentarios.
 */
public class AnimatorPlaybackCheck {
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

   static void near(double got, double want, double tol, String what) {
      boolean ok = Math.abs(got - want) <= tol;
      check(ok, what + " = " + got + (ok ? "" : " (esperado " + want + ")"));
   }

   static File dir;
   static int requests;

   public static void main(String[] args) throws Exception {
      File d = new File(".").getAbsoluteFile();
      while (d != null && !new File(d, "assets/gammatutorial-samples/base-avatars/Avatars.dat").exists()) {
         d = d.getParentFile();
      }
      dir = new File(d, "assets/gammatutorial-samples/base-avatars");
      AnimSeqCache.reader = path -> {
         try {
            return Files.readAllBytes(new File(path).toPath());
         } catch (Exception e) {
            return null;
         }
      };
      AnimSeqCache.requester = (file, sync, handle) -> {
         requests++;
         File f = new File(dir, file);
         AnimSeqCache.notifySeqLoaded(handle, f.exists() ? f.getPath() : null);
      };
      AnimGraph.noImpChangeOverride = Boolean.FALSE;

      NativeAnimator.init(".");
      byte[] raw = Files.readAllBytes(new File(dir, "Avatars.dat").toPath());
      java.io.ByteArrayOutputStream o = new java.io.ByteArrayOutputStream();
      for (int i = 0; i < raw.length; i++) {
         if (!(raw[i] == 13 && i + 1 < raw.length && raw[i + 1] == 10)) {
            o.write(raw[i]);
         }
      }
      AnimRegistry.get().load(o.toByteArray(), "Avatars.dat");
      int axel = NativeAnimator.getnameindex("axel");
      check(axel >= 0, "Axel en Avatars.dat (indice " + axel + ")");

      // addtype registra implicitos y explicitos (cuenta 1, sin pedir nada).
      NativeAnimator.addtype(axel);
      eq(AnimSeqCache.refs("axelwave"), 1, "axelwave registrada");
      eq(AnimSeqCache.refs("axelwalk"), 1, "axelwalk registrada");
      eq(requests, 0, "addtype no pide ficheros (FUN_0042ffd0 inserta sin pedir)");
      eq(AnimSeqCache.refs("common_walk"), -1, "common_walk no es de Axel");

      int rep = NativeAnimator.CreateRep();
      AnimAnimator an = NativeAnimator.animator(rep);

      // axelwave: diccionario de 13 keys que suma 142. 142 * 1/30f =
      // 4.73333358.. -> float 4.7333336 -> {4 s, 733 ms} -> 4.733.
      near(NativeAnimator.getAnimationTime(rep, axel, "wave"), 4.733f, 0, "getAnimationTime(wave)");
      eq(requests, 1, "la primera duracion pide axelwave.seq en sincrono (FUN_0042fc90)");
      check(AnimSeqCache.loaded("axelwave"), "axelwave cargada por notifySeqLoaded");
      near(NativeAnimator.getAnimationTime(rep, axel, "WAVE"), 4.733f, 0, "el nombre pasa a minusculas");
      eq(NativeAnimator.getAnimationTime(rep, axel, "volar"), 0.0f, "explicito que no existe = 0.0 (DAT_00475524)");
      // axelyes: 142 keys tambien; common_happy: 389 keys -> 12.9666672 -> {12, 966}.
      near(NativeAnimator.getAnimationTime(rep, axel, "happy"), 12.966f, 0, "getAnimationTime(happy)");

      // Gesto: al segundo 1 el key es trunc(1.0 * 30) = 30; peso
      // 8x(1-x) con x = 1/4.733 = 0.211 -> 1.333 -> 1: la pose es la del
      // .seq en el key 30 (x e y negadas, hemisferio w >= 0).
      near(NativeAnimator.animate(rep, axel, "wave"), 4.733f, 0, "animate(wave) devuelve la duracion");
      check(!an.onlyImplicit(), "el gesto queda encima del implicito");
      an.step(0f, new AnimTime(1, 0));
      AnimPose p = an.pose();
      eq(p.entries.size(), 4, "axelwave mueve 4 joints (back, lfshoulder, lfelbow, lfwrist)");
      eq(p.entries.get(0).key, 4, "back = tag 2 -> id 4 (FUN_004298b0: tag + 2)");
      eq(p.entries.get(3).key, 15, "lfwrist = tag 13 -> id 15");
      net.openworlds.bod.SeqParser.SeqData wave = net.openworlds.bod.SeqParser.parseFile(new File(dir, "axelwave.seq").getPath());
      float[] q = net.openworlds.bod.SeqSampler.sample(wave.joints.get("lfshoulder"), (short) 30);
      float[] e = {q[0], -q[1], -q[2], q[3]};
      if (e[0] < 0) {
         for (int k = 0; k < 4; k++) {
            e[k] = -e[k];
         }
      }
      float[] g = p.find(13).v;
      near(g[0], e[0], 1e-5, "lfshoulder w en el key 30");
      near(g[1], e[1], 1e-5, "lfshoulder x (negada) en el key 30");
      near(g[3], e[3], 1e-5, "lfshoulder z en el key 30");
      // A 4.733 s el gesto termina y vuelve el implicito.
      an.step(0f, new AnimTime(3, 733));
      check(an.onlyImplicit(), "a {4 s, 733 ms} el overlay devuelve lo de debajo (FUN_0043a7e0)");

      // Implicito wait (indice 4: por tiempo, modo 1) con cambio de 250 ms.
      an.play(axel, 4, -1);
      eq(an.implicitIndex(), 4, "implicito 4 (wait)");
      check(an.implicitNode() instanceof AnimGraph.ShiftTo, "cambio de implicito = shiftto");
      an.step(0f, new AnimTime(0, 100));
      AnimPose mid = an.pose();
      net.openworlds.bod.SeqParser.SeqData wait = net.openworlds.bod.SeqParser.parseFile(new File(dir, "axelwait.seq").getPath());
      // A 100 ms: peso 100/250 = 0.4 entre la pose vacia (identidad) y la
      // de axelwait en el key trunc(0.1 * 30) = 3.
      float[] w3 = net.openworlds.bod.SeqSampler.sample(wait.joints.get("head"), (short) 3);
      float[] b = {w3[0], -w3[1], -w3[2], w3[3]};
      if (b[0] < 0) {
         for (int k = 0; k < 4; k++) {
            b[k] = -b[k];
         }
      }
      float[] m = {1f + (b[0] - 1f) * 0.4f, b[1] * 0.4f, b[2] * 0.4f, b[3] * 0.4f};
      double len = Math.sqrt(m[0] * m[0] + m[1] * m[1] + m[2] * m[2] + m[3] * m[3]);
      near(mid.find(6).v[0], m[0] / len, 1e-5, "head a mitad de la mezcla (nlerp 0.4)");
      an.step(0f, new AnimTime(0, 200));
      check(an.implicitNode() instanceof AnimGraph.Pipe, "a 300 ms el shiftto se sustituye por el pipe de wait");
      // 30 s despues: trunc(30.3 * 30) = 909 > 858 keys -> modo 1 se queda en 858.
      an.step(0f, new AnimTime(30, 0));
      float[] last = net.openworlds.bod.SeqSampler.sample(wait.joints.get("head"), (short) 858);
      near(Math.abs(an.pose().find(6).v[0]), Math.abs(last[0]), 1e-5, "wait en modo 1 se queda en el ultimo key (858)");

      // Walk (indice 3: por distancia, bucle). axelwalk: 34 keys,
      // duracion 34 * 1/30f = 1.1333334 "segundos".
      an.play(axel, 3, -1);
      an.step(0f, new AnimTime(0, 300));
      AnimGraph.Pipe walk = (AnimGraph.Pipe) an.implicitNode();
      AnimGraph.DistanceDriver dd = (AnimGraph.DistanceDriver) walkDriver(walk);
      eq(dd.key(), (short) 0, "walk sin avanzar: key 0");
      an.step(0.5f, AnimTime.ZERO);
      eq(dd.key(), (short) 15, "0.5 -> trunc(15.0) = 15");
      an.step(-0.7f, AnimTime.ZERO);
      // -0.2 -> fmod(-0.2, 1.1333334) + 1.1333334 = 0.9333334 -> trunc(28.000002) = 28
      eq(dd.key(), (short) 28, "hacia atras envuelve: 28");
      an.step(0.2666666f, AnimTime.ZERO);
      // 1.2 > 1.1333334 -> fmod -> 0.0666666 -> trunc(1.99999..) = 1 (trunca, no redondea)
      eq(dd.key(), (short) 1, "bucle con truncado: 1");

      // endanimations vuelve al implicito 1 con un pipe vacio.
      NativeAnimator.endanimations(rep);
      eq(an.implicitIndex(), 1, "endanimations -> implicito 1");
      eq(an.pose().entries.size(), 0, "pipe vacio: pose vacia (FUN_0043bc20)");

      // deltype suelta las secuencias (cuenta 0 -> fuera de la cache).
      NativeAnimator.deltype(axel);
      eq(AnimSeqCache.refs("axelwave"), -1, "deltype saca axelwave de la cache");
      NativeAnimator.DestroyRep(rep);
      eq(NativeAnimator.animator(rep), null, "DestroyRep");

      System.out.println(fails == 0 ? "AnimatorPlaybackCheck: OK" : "AnimatorPlaybackCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }

   static AnimGraph.Driver walkDriver(AnimGraph.Pipe p) {
      return p.driver();
   }
}
