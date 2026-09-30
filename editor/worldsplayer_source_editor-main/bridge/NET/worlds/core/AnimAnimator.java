package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * An avatar's animator (0x3c-byte object, FUN_00432880):
 *
 * <pre>
 * +0x00  motion (0x50 bytes, FUN_004313b0; used by update)
 * +0x05  active (param_2 != 0; CreateRep passes 1)
 * +0x08  W1: slot for the implicit animations (placeholder)
 * +0x10  W2: root, a placeholder that contains W1 or the explicit animations on top
 * +0x18  keys of the type's implicit animations (copy)
 * +0x24  sequences of the implicit animations (copy, changed by the changeimps)
 * +0x30  current type (-1)
 * +0x34  current implicit animation (1)
 * +0x38  last explicit animation (0)
 * </pre>
 */
public final class AnimAnimator {
   /**
    * Table of implicit animations (0x475288, 12 bytes per index 0..9): name,
    * arg1 (0 = by distance, 1 = by time) and arg2 (end mode:
    * 1 = stay on the last key, 2 = loop). Indices 1 and 2 have no
    * name (empty pipe): 1 = just arrived and standing still, 2 = turning in place.
    */
   static final String[] IMP_NAMES = {"", "", "", "walk", "wait", "endwait", "run", "fly", "hover", "sit"};
   static final int[] IMP_ARG1 = {0, 0, 0, 0, 1, 1, 0, 0, 1, 1};
   static final int[] IMP_ARG2 = {0, 0, 0, 2, 1, 1, 2, 2, 2, 2};
   /** Blend for an implicit animation change: {0 s, 0xfa ms} (FUN_00432d10). */
   static final AnimTime SHIFT_TIME = new AnimTime(0, 250);

   /** Diagnostics: -Dopenworlds.animLog=1 traces every implicit animation change and every explicit animation. */
   static final boolean LOG = "1".equals(System.getProperty("openworlds.animLog")) || Boolean.getBoolean("openworlds.animLog");

   final AnimMotion motion;
   final boolean active = true;
   AnimGraph.Placeholder w1;
   AnimGraph.Placeholder root;
   final List<String> impKeys = new ArrayList<String>();
   final List<String> impValues = new ArrayList<String>();
   int type = -1;
   int imp = 1;
   int exp = 0;

   AnimAnimator(AnimTime now) {
      this.motion = new AnimMotion(now);
      this.reset();
   }

   /**
    * FUN_00433420 (also endanimations): implicit 1, explicit 0, W1 =
    * placeholder(empty pipe) and root = placeholder(W1). It does not touch
    * the type or the lists of implicit animations.
    */
   synchronized void reset() {
      this.imp = 1;
      this.exp = 0;
      this.w1 = new AnimGraph.Placeholder(AnimGraph.emptyPipe());
      this.root = new AnimGraph.Placeholder(this.w1);
   }

   /**
    * FUN_004330a0: if the type changes it copies its implicit animations; if
    * expIdx (1..n) has a changeimp block and NoImpChange != 1, it replaces the
    * sequences of those implicit animations. ⚠️ Bug in the original: if a key
    * of the block is not among the implicit animations, it compares with the
    * end of the list of EXPLICIT ones (0x433378 against -0x164 =
    * FUN_0042bd40) and writes one position past the vector; since nobody
    * reads that position here, it is ignored.
    */
   boolean applyChangeImp(int type, int expIdx) {
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t == null) {
         return false;
      }
      if (type != this.type) {
         this.type = type;
         this.impValues.clear();
         this.impValues.addAll(t.impValues);
         this.impKeys.clear();
         this.impKeys.addAll(t.impKeys);
      }
      int i = expIdx - 1;
      if (i < 0 || t.expValues.size() <= i) {
         return false;
      }
      if (AnimGraph.noImpChange()) {
         return false;
      }
      AnimRegistry.ChangeImp c = t.changeImp(t.expKeys.get(i));
      if (c == null) {
         return false;
      }
      boolean changed = false;
      for (int k = 0; k < c.keys.size(); k++) {
         int j = this.impKeys.indexOf(c.keys.get(k));
         if (j >= 0) {
            this.impValues.set(j, AnimRegistry.str(c.values.get(k)));
         }
         changed = true;
      }
      return changed;
   }

   /**
    * FUN_00433a70: pipe of implicit animation idx (outside 1..9, 1 is taken).
    * With no name in the table, no type, or no such key among the avatar's
    * implicit animations -&gt; empty pipe; otherwise the pipe of its sequence
    * with arg1/arg2.
    */
   AnimGraph.Pipe implicitPipe(int type, int idx) {
      if (idx < 1 || 9 < idx) {
         idx = 1;
      }
      String name = IMP_NAMES[idx];
      if (name.isEmpty() || AnimRegistry.get().type(type) == null) {
         return AnimGraph.emptyPipe();
      }
      int j = this.impKeys.indexOf(name);
      if (j < 0) {
         return AnimGraph.emptyPipe();
      }
      return AnimGraph.pipe(this.impValues.get(j), IMP_ARG1[idx], IMP_ARG2[idx]);
   }

   /** FUN_00433f70: pipe of explicit animation idx (1..n) by time and mode 0, or null. */
   static AnimGraph.Pipe explicitPipe(int type, int idx) {
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t == null) {
         return null;
      }
      int i = idx - 1;
      if (i < 0 || t.expValues.size() <= i) {
         return null;
      }
      return AnimGraph.pipe(t.expValues.get(i), 1, 0);
   }

   /** FUN_00433e90: index 1..n of the explicit animation by its key (strcmp) or -1. */
   static int explicitIndex(int type, String lowerName) {
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t == null) {
         return -1;
      }
      int i = t.expKeys.indexOf(AnimRegistry.str(lowerName));
      return i < 0 ? -1 : i + 1;
   }

   /**
    * FUN_00432d10: first FUN_004330a0; if impIdx &gt;= 0 and it changes, W1
    * becomes shiftto(what was there, new implicit animation, 250 ms); if
    * expIdx &gt;= 0, the root becomes overlay(what was there, the explicit
    * animation's pipe, its duration) and that duration is returned in seconds
    * (s + ms / 1000, DAT_00472020 = 1000). Otherwise 0.
    */
   public synchronized float play(int type, int impIdx, int expIdx) {
      if (!this.active) {
         return 0.0F;
      }
      this.applyChangeImp(type, expIdx);
      if (impIdx >= 0 && impIdx != this.imp) {
         if (LOG && (impIdx > 2 || this.imp > 2)) {
            AnimRegistry.AvatarType at = AnimRegistry.get().type(type);
            System.out.println("[anim] " + (at == null ? "tipo " + type : at.attr("name")) + " en ("
               + this.motion.pos[0] + "," + this.motion.pos[1] + "," + this.motion.pos[2] + "): implicito "
               + this.imp + " -> " + impIdx + " (" + IMP_NAMES[impIdx < 1 || impIdx > 9 ? 1 : impIdx] + ")");
         }
         this.imp = impIdx;
         if (this.imp == 0) {
            return 0.0F;
         }
         AnimGraph.Pipe p = this.implicitPipe(type, this.imp);
         AnimGraph.Node cur = this.w1.take();
         this.w1.set(new AnimGraph.ShiftTo(cur, p, SHIFT_TIME));
      }
      if (expIdx >= 0) {
         this.exp = expIdx;
         if (this.exp == 0) {
            return 0.0F;
         }
         AnimGraph.Pipe p = explicitPipe(type, this.exp);
         if (p == null) {
            return 0.0F;
         }
         AnimGraph.Node cur = this.root.take();
         AnimTime d = p.duration();
         if (LOG) {
            System.out.println("[anim] explicito " + expIdx + " del tipo " + type + ": " + d);
         }
         this.root.set(new AnimGraph.Overlay(cur, p, d));
         return (float) d.seconds();
      }
      return 0.0F;
   }

   /**
    * The graph step of FUN_00433710: root = root.advance(amount, dt)
    * (vtable +4 on +0x14, FUN_00434350 stores the result).
    */
   public synchronized void step(float amount, AnimTime dt) {
      // W2 is a placeholder (FUN_00439aa0), which always returns itself.
      this.root.advance(amount, dt);
   }

   /**
    * FUN_00433710 (from update): records the time (vtable [6]); if there is a
    * clump1 it sets the movement's position and orientation on it
    * (FUN_00434440 -&gt; FUN_004318e0); amount = distance * |scale|
    * (vtable [11]); dt = now - time of the previous update; advances the root
    * and, if there is a figure (clump2), applies the pose to it
    * (FUN_00434470). The fifth argument of update (far &gt; 700) arrives here
    * and is not read (0x43372b and 0x433854 do ret 0x14 without touching
    * 0x18(%ebp)).
    */
   public synchronized void update(AnimTime t, int clump1, int clump2, float scale) {
      AnimTime prev = this.motion.lastUpdate;
      this.motion.lastUpdate = t;
      if (clump1 != 0) {
         float[] q = this.motion.quat.clone();
         AnimPose.normalize(q);
         float[] m = net.openworlds.bod.SeqSampler.quatToMatrix(q);
         m[12] = this.motion.pos[0];
         m[13] = this.motion.pos[1];
         m[14] = this.motion.pos[2];
         NativeScene.transformClump(clump1, m, NativeRw.REPLACE);
      }
      if (scale < 0.0F) {
         scale = -scale;
      }
      float amount = this.motion.takeDistance() * scale;
      AnimTime dt = t.minus(prev);
      this.step(amount, dt);
      if (clump2 != 0) {
         NativeAnimator.applyPose(this.pose(), clump2);
      }
   }

   /**
    * Common part of FUN_004351b0 (moveto) and FUN_004352f0 (moveby) once
    * position and orientation have been computed: the Rep's implicit
    * animation state, FUN_00432a30 and FUN_00432d10(type, state, -1).
    */
   synchronized void moved(AnimMotion.State st, int type, float[] p, float[] q, AnimTime t) {
      int state = st.moved(p, q, t);
      this.motion.offer(p, q, t);
      this.play(type, state, -1);
   }


   /** The root's pose (vtable +8 on +0x14). */
   public synchronized AnimPose pose() {
      return this.root.pose();
   }

   /** For the checks: current implicit animation (+0x34). */
   public synchronized int implicitIndex() {
      return this.imp;
   }

   /** For the checks: does the root have only the implicit animation slot (no explicit animation on top)? */
   public synchronized boolean onlyImplicit() {
      return this.root.inner == this.w1;
   }

   /** For the checks: the node of the implicit animation slot. */
   public synchronized AnimGraph.Node implicitNode() {
      return this.w1.inner;
   }

   /**
    * FUN_00432be0: duration of explicit animation idx (creates its pipe,
    * which requests the sequence if needed); 0 if idx &lt; 0.
    */
   synchronized float duration(int type, int expIdx) {
      if (!this.active || expIdx < 0) {
         return 0.0F;
      }
      AnimGraph.Pipe p = explicitPipe(type, expIdx);
      return p == null ? 0.0F : (float) p.duration().seconds();
   }
}
