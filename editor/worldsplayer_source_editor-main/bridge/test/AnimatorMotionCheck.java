import NET.worlds.core.AnimAnimator;
import NET.worlds.core.AnimGraph;
import NET.worlds.core.AnimRegistry;
import NET.worlds.core.AnimSeqCache;
import NET.worlds.core.NativeAnimator;
import NET.worlds.core.NativeRw;
import NET.worlds.core.NativeScene;
import java.io.File;
import java.nio.file.Files;

/**
 * Movement of DroneAnimator (gamma.dll): the state machine of the implicit
 * animations (FUN_00434670) with a series of timed moveto calls, the
 * distance and direction that feed the walk (FUN_00431440 +
 * FUN_00435520/00433710), the application of the pose to the joints and the
 * root translation (FUN_00434470) and prepFigure (FUN_00434f00). Avatar Axel
 * from base-avatars; test figures built with NativeScene.
 */
public class AnimatorMotionCheck {
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

   static void near(double got, double want, double tol, String what) {
      boolean ok = Math.abs(got - want) <= tol;
      check(ok, what + " = " + got + (ok ? "" : " (expected " + want + ")"));
   }

   static float[] ltm(int c) {
      float[] m = new float[16];
      NativeScene.getClumpLTM(c, m);
      return m;
   }

   public static void main(String[] args) throws Exception {
      File d = new File(".").getAbsoluteFile();
      while (d != null && !new File(d, "assets/gammatutorial-samples/base-avatars/Avatars.dat").exists()) {
         d = d.getParentFile();
      }
      final File dir = new File(d, "assets/gammatutorial-samples/base-avatars");
      AnimSeqCache.reader = path -> {
         try {
            return Files.readAllBytes(new File(path).toPath());
         } catch (Exception e) {
            return null;
         }
      };
      AnimSeqCache.requester = (file, sync, handle) -> {
         File f = new File(dir, file);
         AnimSeqCache.notifySeqLoaded(handle, f.exists() ? f.getPath() : null);
      };
      AnimGraph.noImpChangeOverride = Boolean.FALSE;
      NativeAnimator.init(".");
      AnimRegistry.get().load(new String(Files.readAllBytes(new File(dir, "Avatars.dat").toPath()), "ISO-8859-1")
         .replace("\r\n", "\n").getBytes("ISO-8859-1"), "Avatars.dat");
      int axel = NativeAnimator.getnameindex("axel");
      NativeAnimator.addtype(axel);

      // ---- state machine (moveto times in ms)
      int rep = NativeAnimator.CreateRep();
      AnimAnimator an = NativeAnimator.animator(rep);
      NativeAnimator.moveto(rep, axel, (short) 0, (short) 0, (short) 0, (short) 0, 1000);
      eq(an.implicitIndex(), 1, "first moveto: state 1 (+0x30 = t)");
      NativeAnimator.moveto(rep, axel, (short) 0, (short) 0, (short) 0, (short) 0, 10999);
      eq(an.implicitIndex(), 1, "still for 9.999 s: stays at 1");
      NativeAnimator.moveto(rep, axel, (short) 0, (short) 0, (short) 0, (short) 0, 11000);
      eq(an.implicitIndex(), 4, "still for 10 s (1000 + {10,0} <= 11000): wait (4)");
      NativeAnimator.moveto(rep, axel, (short) 0, (short) 0, (short) 0, (short) 0, 40999);
      eq(an.implicitIndex(), 4, "wait 29.999 s: stays");
      NativeAnimator.moveto(rep, axel, (short) 0, (short) 0, (short) 0, (short) 0, 41000);
      eq(an.implicitIndex(), 5, "wait 30 s: endwait (5)");
      NativeAnimator.moveto(rep, axel, (short) 0, (short) 0, (short) 0, (short) 0, 51000);
      eq(an.implicitIndex(), 4, "endwait 10 s: back to wait");
      NativeAnimator.moveto(rep, axel, (short) 10, (short) 0, (short) 0, (short) 0, 52000);
      eq(an.implicitIndex(), 3, "moves: walk (3)");
      NativeAnimator.moveto(rep, axel, (short) 10, (short) 0, (short) 0, (short) 0, 52100);
      eq(an.implicitIndex(), 4, "stops: straight to wait (3 + still -> 4)");
      NativeAnimator.moveto(rep, axel, (short) 10, (short) 0, (short) 0, (short) 10, 52200);
      eq(an.implicitIndex(), 2, "turns 10 degrees in place: 2 (no sequence)");
      NativeAnimator.moveto(rep, axel, (short) 10, (short) 0, (short) 0, (short) 12, 52300);
      eq(an.implicitIndex(), 1, "turns 2 degrees: |dot-1| < 0.0005 -> equal -> still (1)");
      NativeAnimator.moveto(rep, axel, (short) 10, (short) 0, (short) 0, (short) 16, 52400);
      eq(an.implicitIndex(), 2, "turns 4 degrees (cos(2) = 0.99939): different -> 2");
      NativeAnimator.DestroyRep(rep);

      // ---- walk synchronized with the distance and pose applied
      int fig = NativeScene.createClump();
      int pelvis = NativeScene.createClump();
      NativeScene.setClumpTag(pelvis, 1);
      NativeScene.addChildToClump(fig, pelvis);
      int knee = NativeScene.createClump();
      NativeScene.setClumpTag(knee, 16);
      NativeScene.addChildToClump(fig, knee);
      rep = NativeAnimator.CreateRep();
      an = NativeAnimator.animator(rep);
      NativeAnimator.moveto(rep, axel, (short) 5, (short) 5, (short) 0, (short) 0, 1000);
      NativeAnimator.update(rep, 0, fig, 1000, 1.0F, false);
      NativeAnimator.moveto(rep, axel, (short) 5, (short) 105, (short) 0, (short) 0, 2000);
      eq(an.implicitIndex(), 3, "advances 100 in y: walk");
      // scale = 10 / (scaleX 1 * m00 1 * 1000) = 0.01; 100 * 0.01 = 1.0
      // walk "seconds" -> key trunc(1.0 * 30) = 30.
      NativeAnimator.update(rep, 0, fig, 2000, 1.0F, false);
      AnimGraph.DistanceDriver dd = (AnimGraph.DistanceDriver) ((AnimGraph.Pipe) an.implicitNode()).driver();
      eq(dd.key(), (short) 30, "100 units forward -> key 30");
      net.openworlds.bod.SeqParser.SeqData walk = net.openworlds.bod.SeqParser.parseFile(new File(dir, "axelwalk.seq").getPath());
      float[] q = net.openworlds.bod.SeqSampler.sample(walk.joints.get("rtknee"), (short) 30);
      float[] e = {q[0], -q[1], -q[2], q[3]};
      float n = (float) Math.sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3]);
      for (int k = 0; k < 4; k++) {
         e[k] /= n;
      }
      float[] want = net.openworlds.bod.SeqSampler.quatToMatrix(e);
      float[] got = ltm(knee);
      double err = 0;
      for (int k = 0; k < 16; k++) {
         err = Math.max(err, Math.abs(got[k] - want[k]));
      }
      near(err, 0, 1e-5, "joint of tag 16 (rtknee) = matrix of the key 30 quaternion");
      // Root translation: extras 0,1 of the .seq x 0.1 x diagonal (1); z = 0 in the walk (flag 0).
      float rx = net.openworlds.bod.SeqSampler.sample(walk.extras.get(0), (short) 30)[0];
      float ry = net.openworlds.bod.SeqSampler.sample(walk.extras.get(1), (short) 30)[0];
      float[] mp = new float[16];
      NativeScene.getClumpMatrix(pelvis, mp);
      near(mp[12], 0.1f * rx, 1e-5, "root translation x (x 0.1)");
      near(mp[13], 0.1f * ry, 1e-5, "root translation y (x 0.1)");
      near(mp[14], 0, 0, "root translation z zeroed (distance driver)");
      // Backwards: from y=105 to y=55 -> local y -50 -> distance -50 -> -0.5
      // -> acc 0.5 -> key 15.
      NativeAnimator.moveto(rep, axel, (short) 5, (short) 55, (short) 0, (short) 0, 3000);
      NativeAnimator.update(rep, 0, fig, 3000, 1.0F, false);
      eq(dd.key(), (short) 15, "50 units backwards -> key 15 (runs the walk in reverse)");
      // Scale with the pelvis at 0.5 (m00): 10 / (1 * 500) = 0.02; 25 * 0.02 = 0.5 -> acc 1.0 -> key 30.
      float[] half = NativeRw.identity();
      half[0] = 0.5f;
      half[5] = 0.5f;
      half[10] = 0.5f;
      NativeScene.transformClump(pelvis, half, NativeRw.REPLACE);
      NativeAnimator.moveto(rep, axel, (short) 5, (short) 80, (short) 0, (short) 0, 4000);
      NativeAnimator.update(rep, 0, fig, 4000, 1.0F, false);
      eq(dd.key(), (short) 30, "pelvis at scale 0.5: 25 units count double -> key 30");
      NativeAnimator.endanimations(rep);
      NativeAnimator.update(rep, 0, fig, 5000, 1.0F, false);
      float[] id = ltm(knee);
      near(id[0] + id[5] + id[10], 3, 1e-6, "empty pose: the joint goes back to the identity");

      // ---- prepFigure
      for (int cog = 0; cog < 2; cog++) {
         int f = NativeScene.createClump();
         int p = NativeScene.createClump();
         NativeScene.setClumpTag(p, 1);
         NativeScene.addChildToClump(f, p);
         float[] t = NativeRw.identity();
         t[13] = 0.9f;
         NativeScene.transformClump(p, t, NativeRw.REPLACE);
         NativeScene.addVertex(p, 0.1f, -1.0f, 0.1f);
         NativeScene.addVertex(p, 0.3f, 0.1f, -0.1f);
         NativeAnimator.prepFigure(f, cog == 1);
         float[] lp = ltm(p);
         float[] mp2 = new float[16];
         NativeScene.getClumpMatrix(p, mp2);
         // joint = T(0,0.9,0) S(1000) R(180 about (0,1,1): (x,y,z) -> (-x,z,y)).
         // Vertices in the world: z from -100 to 1000, x from -300 to -100; the
         // box includes the figure's origin (0,0,900): cx = -150, zmin = -100.
         // COG false: T(0,0,100) -> pelvis at (0,0,1000); COG true: T(150,0,100).
         near(mp2[13], 0, 0, "prepFigure zeroes the pelvis translation");
         near(lp[12], cog == 1 ? 150 : 0, 1e-2, "pelvis x with COG=" + (cog == 1));
         near(lp[13], 0, 1e-2, "pelvis y with COG=" + (cog == 1));
         near(lp[14], 1000, 1e-2, "pelvis z with COG=" + (cog == 1) + " (feet at z = 0)");
      }

      System.out.println(fails == 0 ? "AnimatorMotionCheck: OK" : "AnimatorMotionCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}
