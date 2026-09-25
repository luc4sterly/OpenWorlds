package net.freeworlds.avatar;

import net.freeworlds.bod.BodFile;
import net.freeworlds.bod.BodParser;
import net.freeworlds.bod.SeqParser;
import net.freeworlds.bod.SeqSampler;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.nio.file.Files;

/**
 * La regla de animacion de avatares de gamma.dll en el cliente propio
 * (net.freeworlds.avatar): con la MISMA serie de moveto/update que
 * bridge/test/AnimatorMotionCheck.java y AnimatorPlaybackCheck.java tienen
 * que salir los mismos estados y keys (valores a mano en los comentarios de
 * esas comprobaciones y repetidos aqui). Ademas lo que el puente hace con
 * RenderWare y aqui hace AvatarRig: FUN_00434470 (pose a joints y
 * traslacion de raiz), prepFigure (FUN_00434f00) y Transform.getYaw
 * (0x00425440). Avatar Axel de assets/gammatutorial-samples/base-avatars.
 */
public class AvatarAnimCheck {
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

   static short walkKey(AnimAnimator an) {
      return ((AnimGraph.DistanceDriver) ((AnimGraph.Pipe) an.implicitNode()).driver()).key();
   }

   public static void main(String[] args) throws Exception {
      File d = new File(".").getAbsoluteFile();
      while (d != null && !new File(d, "assets/gammatutorial-samples/base-avatars/Avatars.dat").exists()) {
         d = d.getParentFile();
      }
      File dir = new File(d, "assets/gammatutorial-samples/base-avatars");
      // Archive.readTextFile quita los CR (FUN_00403e80 -> FUN_00403eb0).
      byte[] raw = Files.readAllBytes(new File(dir, "Avatars.dat").toPath());
      ByteArrayOutputStream o = new ByteArrayOutputStream();
      for (byte b : raw) {
         if (b != 13) {
            o.write(b);
         }
      }
      AnimRegistry reg = AnimRegistry.get();
      reg.clear();
      reg.load(o.toByteArray(), "Avatars.dat");
      AnimSequence.Library lib = new AnimSequence.Library(dir);
      AnimGraph.noImpChange = false;
      int axel = reg.nameIndex("axel");
      check(axel >= 0, "Axel en Avatars.dat (indice " + axel + ")");

      // ---- maquina de estados (FUN_00434670), misma serie que AnimatorMotionCheck
      AnimAnimator an = new AnimAnimator(reg, lib, 1000);
      an.moveto(axel, (short) 0, (short) 0, (short) 0, (short) 0, 1000);
      eq(an.implicitIndex(), 1, "primer moveto: estado 1 (+0x30 = t)");
      an.moveto(axel, (short) 0, (short) 0, (short) 0, (short) 0, 10999);
      eq(an.implicitIndex(), 1, "quieto 9.999 s: sigue en 1");
      an.moveto(axel, (short) 0, (short) 0, (short) 0, (short) 0, 11000);
      eq(an.implicitIndex(), 4, "quieto 10 s (1000 + {10,0} <= 11000): wait (4)");
      an.moveto(axel, (short) 0, (short) 0, (short) 0, (short) 0, 40999);
      eq(an.implicitIndex(), 4, "wait 29.999 s: sigue");
      an.moveto(axel, (short) 0, (short) 0, (short) 0, (short) 0, 41000);
      eq(an.implicitIndex(), 5, "wait 30 s: endwait (5)");
      an.moveto(axel, (short) 0, (short) 0, (short) 0, (short) 0, 51000);
      eq(an.implicitIndex(), 4, "endwait 10 s: vuelve a wait");
      an.moveto(axel, (short) 10, (short) 0, (short) 0, (short) 0, 52000);
      eq(an.implicitIndex(), 3, "se mueve: walk (3)");
      an.moveto(axel, (short) 10, (short) 0, (short) 0, (short) 0, 52100);
      eq(an.implicitIndex(), 4, "se para: directo a wait (3 + quieto -> 4)");
      an.moveto(axel, (short) 10, (short) 0, (short) 0, (short) 10, 52200);
      eq(an.implicitIndex(), 2, "gira 10 grados en el sitio: 2 (sin secuencia)");
      an.moveto(axel, (short) 10, (short) 0, (short) 0, (short) 12, 52300);
      eq(an.implicitIndex(), 1, "gira 2 grados: |dot-1| < 0.0005 -> igual -> quieto (1)");
      an.moveto(axel, (short) 10, (short) 0, (short) 0, (short) 16, 52400);
      eq(an.implicitIndex(), 2, "gira 4 grados (cos(2) = 0.99939): distinto -> 2");

      // ---- walk sincronizado con la distancia (FUN_00431440 + FUN_00435520/00433710)
      // Creado antes del primer moveto (en el original CreateRep y el primer
      // FrameEvent son momentos distintos): si la hora de creacion fuera la
      // misma que la del moveto, FUN_00432a30 no tomaria la posicion.
      an = new AnimAnimator(reg, lib, 500);
      float scale = AnimAnimator.updateScale(1.0F, 1.0F);
      near(scale, 0.01, 1e-9, "escala = 10 / (scaleX 1 * m00 1 * 1000)");
      an.moveto(axel, (short) 5, (short) 5, (short) 0, (short) 0, 1000);
      an.update(1000, scale);
      an.moveto(axel, (short) 5, (short) 105, (short) 0, (short) 0, 2000);
      eq(an.implicitIndex(), 3, "avanza 100 en y: walk");
      // 100 * 0.01 = 1.0 "segundos" de walk -> key trunc(1.0 * 30) = 30.
      AnimPose p30 = an.update(2000, scale);
      eq(walkKey(an), (short) 30, "100 unidades hacia delante -> key 30");
      // Hacia atras: de y=105 a y=55 -> y local -50 -> -0.5 -> acc 0.5 -> key 15.
      an.moveto(axel, (short) 5, (short) 55, (short) 0, (short) 0, 3000);
      an.update(3000, scale);
      eq(walkKey(an), (short) 15, "50 unidades hacia atras -> key 15 (recorre el walk al reves)");
      // Pelvis a escala 0.5 (m00): 10 / (1 * 500) = 0.02; 25 * 0.02 = 0.5 -> acc 1.0 -> key 30.
      an.moveto(axel, (short) 5, (short) 80, (short) 0, (short) 0, 4000);
      an.update(4000, AnimAnimator.updateScale(1.0F, 0.5F));
      eq(walkKey(an), (short) 30, "pelvis a escala 0.5: 25 unidades cuentan el doble -> key 30");
      an.reset();
      eq(an.update(5000, scale).entries.size(), 0, "endanimations: pose vacia");

      // ---- pose del walk en la figura (FUN_00434470) y prepFigure
      BodFile bod = BodParser.parse(Files.readAllBytes(new File(dir, "axel.bod").toPath()));
      AvatarRig rig = new AvatarRig(bod, null);
      rig.prepFigure();
      float[] fj = rig.figureJoint();
      // S(1000) R(180 sobre (0,1,1)): fila 0 = (-1000,0,0), fila 1 = (0,0,1000), fila 2 = (0,1000,0).
      near(fj[0], -1000, 1e-3, "prepFigure: x -> -1000 x");
      near(fj[6], 1000, 1e-3, "prepFigure: y del .bod -> z (arriba) x 1000");
      near(fj[9], 1000, 1e-3, "prepFigure: z del .bod -> y x 1000");
      near(fj[5] + fj[10], 0, 1e-6, "prepFigure: sin y->y ni z->z");
      float[] bb = rig.bounds();
      check(bb[2] <= 1e-2 && bb[5] > 100, "prepFigure con COG=false: pies en z = 0 (min z " + bb[2] + ", alto " + bb[5] + ")");
      rig.applyPose(p30);
      SeqParser.SeqData walk = SeqParser.parseFile(new File(dir, "axelwalk.seq").getPath());
      float[] q = SeqSampler.sample(walk.joints.get("rtknee"), (short) 30);
      float[] want = {q[0], -q[1], -q[2], q[3]};
      float[] got = rig.joint(16);
      double err = 0;
      for (int k = 0; k < 4; k++) {
         err = Math.max(err, Math.abs(got[k] - want[k]));
      }
      near(err, 0, 1e-6, "joint del tag 16 (rtknee) = cuaternion del key 30 con x e y negadas");
      if (walk.extras.size() > 2) {
         float rx = SeqSampler.sample(walk.extras.get(0), (short) 30)[0];
         float ry = SeqSampler.sample(walk.extras.get(1), (short) 30)[0];
         float[] pt = rig.pelvisTranslation();
         near(pt[0], 0.1f * rx, 1e-6, "traslacion de raiz x (x 0.1)");
         near(pt[1], 0.1f * ry, 1e-6, "traslacion de raiz y (x 0.1)");
         near(pt[2], 0, 0, "traslacion de raiz z anulada (driver por distancia)");
      } else {
         check(false, "axelwalk.seq deberia traer traslacion de raiz (3 extras)");
      }
      rig.applyPose(null);
      eq(rig.joint(16)[0], 1f, "pose nula: joint a la identidad");

      // ---- reproduccion: duraciones, mezcla de 250 ms, hold, bucle (AnimatorPlaybackCheck)
      an = new AnimAnimator(reg, lib, 0);
      // axelwave: 142 keys * 1/30f = 4.73333358 -> {4 s, 733 ms} -> 4.733.
      near(an.getAnimationTime(axel, "wave"), 4.733f, 0, "getAnimationTime(wave)");
      near(an.getAnimationTime(axel, "WAVE"), 4.733f, 0, "el nombre pasa a minusculas");
      eq(an.getAnimationTime(axel, "volar"), 0.0f, "explicito que no existe = 0.0");
      near(an.animate(axel, "wave"), 4.733f, 0, "animate(wave) devuelve la duracion");
      check(!an.onlyImplicit(), "el gesto queda encima del implicito");
      an.step(0f, new AnimTime(1, 0));
      AnimPose gp = an.pose();
      eq(gp.entries.size(), 4, "axelwave mueve 4 joints (back, lfshoulder, lfelbow, lfwrist)");
      eq(gp.entries.get(0).key, 4, "back = tag 2 -> id 4");
      an.step(0f, new AnimTime(3, 733));
      check(an.onlyImplicit(), "a {4 s, 733 ms} el overlay devuelve lo de debajo");
      an.play(axel, 4, -1);
      check(an.implicitNode() instanceof AnimGraph.ShiftTo, "cambio de implicito = shiftto");
      an.step(0f, new AnimTime(0, 100));
      SeqParser.SeqData wait = SeqParser.parseFile(new File(dir, "axelwait.seq").getPath());
      // A 100 ms: peso 0.4 entre identidad y axelwait en el key trunc(0.1 * 30) = 3.
      float[] w3 = SeqSampler.sample(wait.joints.get("head"), (short) 3);
      float[] b = {w3[0], -w3[1], -w3[2], w3[3]};
      if (b[0] < 0) {
         for (int k = 0; k < 4; k++) {
            b[k] = -b[k];
         }
      }
      float[] m = {1f + (b[0] - 1f) * 0.4f, b[1] * 0.4f, b[2] * 0.4f, b[3] * 0.4f};
      double len = Math.sqrt(m[0] * m[0] + m[1] * m[1] + m[2] * m[2] + m[3] * m[3]);
      near(an.pose().find(6).v[0], m[0] / len, 1e-5, "head a mitad de la mezcla (nlerp 0.4)");
      an.step(0f, new AnimTime(0, 200));
      check(an.implicitNode() instanceof AnimGraph.Pipe, "a 300 ms el shiftto se sustituye por el pipe de wait");
      an.step(0f, new AnimTime(30, 0));
      float[] last = SeqSampler.sample(wait.joints.get("head"), (short) 858);
      near(Math.abs(an.pose().find(6).v[0]), Math.abs(last[0]), 1e-5, "wait en modo 1 se queda en el ultimo key (858)");
      an.play(axel, 3, -1);
      an.step(0f, new AnimTime(0, 300));
      eq(walkKey(an), (short) 0, "walk sin avanzar: key 0");
      an.step(0.5f, AnimTime.ZERO);
      eq(walkKey(an), (short) 15, "0.5 -> trunc(15.0) = 15");
      an.step(-0.7f, AnimTime.ZERO);
      eq(walkKey(an), (short) 28, "hacia atras envuelve: 28");
      an.step(0.2666666f, AnimTime.ZERO);
      eq(walkKey(an), (short) 1, "bucle con truncado: 1");

      // ---- Transform.getYaw (0x00425440): 90 - rumbo del eje Y, en [0, 360)
      near(AvatarRig.transformYaw(AvatarRig.identity()), 0, 1e-4, "getYaw(identidad) = 0");
      double c = Math.cos(Math.toRadians(30));
      double s = Math.sin(Math.toRadians(30));
      float[] rz = {(float) c, (float) s, 0, 0, (float) -s, (float) c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
      // eje Y -> (-0.5, 0.866): rumbo 120 -> 90 - 120 = -30 -> 330.
      near(AvatarRig.transformYaw(rz), 330, 1e-3, "girado 30 grados (antihorario): getYaw = 330");
      float[] ry = {(float) c, (float) -s, 0, 0, (float) s, (float) c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
      near(AvatarRig.transformYaw(ry), 30, 1e-3, "girado -30 grados: getYaw = 30");

      System.out.println(fails == 0 ? "AvatarAnimCheck: OK" : "AvatarAnimCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}
