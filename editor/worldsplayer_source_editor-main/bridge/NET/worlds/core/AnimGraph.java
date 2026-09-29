package NET.worlds.core;

/**
 * The playback graph of gamma.dll's animation engine: the "drivers" that
 * walk a sequence and the nodes that wrap, blend and chain them. All of
 * them are reached only through the vtable (functions recovered in
 * decompiled-native/gamma_dll, commit 130b4b4).
 *
 * <pre>
 * driver  [1] duration  [2] advance(amount, dt) -&gt; driver or null  [3] pose
 * node    [1] advance(amount, dt) -&gt; node or null                  [2] pose
 * </pre>
 *
 * "amount" is the scaled distance walked by the avatar (update) and dt the
 * real time elapsed; the time drivers use dt and the distance drivers use
 * the amount.
 */
public final class AnimGraph {
   private AnimGraph() {
   }

   /** 1/30 (DAT_00476ec0, float). */
   static final float INV_KEYS_PER_SECOND = 0.033333335F;
   /** 30.0 (DAT_00476ec8). */
   static final float KEYS_PER_SECOND = 30.0F;

   // ------------------------------------------------------------- drivers

   public abstract static class Driver {
      public abstract AnimTime duration();

      public abstract Driver advance(float amount, AnimTime dt);

      public abstract AnimPose pose();
   }

   /**
    * Empty driver (vtable 0x47700c, FUN_0043b320): lasts {10000 s, 0}
    * (FUN_0043b360), advancing leaves it as it is (FUN_0043b380) and its
    * pose is an empty pose (FUN_0043b3c0 -&gt; FUN_0043bc20).
    */
   public static final class EmptyDriver extends Driver {
      public AnimTime duration() {
         return new AnimTime(10000, 0);
      }

      public Driver advance(float amount, AnimTime dt) {
         return this;
      }

      public AnimPose pose() {
         return AnimPose.empty();
      }
   }

   /** FUN_0043b5c0 / FUN_0043b590 / FUN_0043b920: (float) duration * 1/30 converted to {s, ms}. */
   static AnimTime durationOf(AnimSeqCache.Sequence seq) {
      return AnimTime.ofSeconds((float) ((double) seq.duration() * (double) INV_KEYS_PER_SECOND));
   }

   /**
    * Time driver (vtable 0x476fdc, FUN_0043b840): +0x10 mode, +0x14
    * current key (short), +0x18 accumulated time {s, ms}.
    */
   public static final class TimeDriver extends Driver {
      final AnimSeqCache.Sequence seq;
      final int mode;
      short key;
      AnimTime elapsed = AnimTime.ZERO;

      TimeDriver(AnimSeqCache.Sequence seq, int mode) {
         this.seq = seq;
         this.mode = mode;
      }

      public AnimTime duration() {
         return durationOf(this.seq);
      }

      /**
       * FUN_0043b950: time += dt; key = (short) trunc(seconds * 30) (the fistp
       * runs with the control word set to truncate, "orb $0xc"). If key &gt;
       * duration: mode 2 -&gt; key % (duration + 1) (loop); mode 1 -&gt;
       * duration (stays at the last key); other -&gt; ends (null).
       */
      public Driver advance(float amount, AnimTime dt) {
         this.elapsed = this.elapsed.plus(dt);
         this.key = (short) AnimTime.fistp(truncate(this.elapsed.seconds() * (double) KEYS_PER_SECOND));
         short dur = this.seq.duration();
         if (dur < this.key) {
            if (this.mode == 2) {
               this.key = (short) (this.key % (short) (dur + 1));
            } else {
               if (this.mode != 1) {
                  return null;
               }
               this.key = dur;
            }
         }
         return this;
      }

      /** FUN_0043baa0: pose with the z of the root translation (flag 1). */
      public AnimPose pose() {
         return this.seq.pose(this.key, true);
      }
   }

   /**
    * Distance driver (vtable 0x476ff4, FUN_0043b490): +0x18 accumulated
    * amount (float, "seconds"), +0x1c duration in seconds (float) =
    * (float) duration * 1/30.
    */
   public static final class DistanceDriver extends Driver {
      final AnimSeqCache.Sequence seq;
      final int mode;
      short key;
      float acc;
      final float dur;

      DistanceDriver(AnimSeqCache.Sequence seq, int mode) {
         this.seq = seq;
         this.mode = mode;
         this.dur = (float) ((double) seq.duration() * (double) INV_KEYS_PER_SECOND);
      }

      public AnimTime duration() {
         return durationOf(this.seq);
      }

      /**
       * FUN_0043b5f0: acc += amount (float). If acc &lt; 0: acc = (float)
       * fmod(acc, |dur|) + dur (fprem). If acc &gt; dur: mode 2 -&gt; 0 if dur
       * == 0 and otherwise fmod(acc, |dur|); mode 1 -&gt; dur; other -&gt;
       * ends. key = (short) trunc(acc * 30.0f). Walking backwards (negative
       * amount) runs the sequence in reverse.
       */
      public Driver advance(float amount, AnimTime dt) {
         this.acc = this.acc + amount;
         if (this.acc < 0.0F) {
            float rem = (float) ((double) this.acc % Math.abs((double) this.dur));
            this.acc = rem + this.dur;
         }
         if (this.dur < this.acc) {
            if (this.mode == 2) {
               if (this.dur == 0.0F) {
                  this.acc = 0.0F;
               } else {
                  this.acc = (float) ((double) this.acc % Math.abs((double) this.dur));
               }
            } else {
               if (this.mode != 1) {
                  return null;
               }
               this.acc = this.dur;
            }
         }
         // flds acc; fmuls 30.0f: the product stays in the x87 register.
         this.key = (short) AnimTime.fistp(truncate((double) this.acc * (double) KEYS_PER_SECOND));
         return this;
      }

      /** For the checks: current key (+0x14). */
      public short key() {
         return this.key;
      }

      /** FUN_0043b770: pose without the z of the root translation (flag 0). */
      public AnimPose pose() {
         return this.seq.pose(this.key, false);
      }
   }

   static double truncate(double v) {
      return v < 0 ? Math.ceil(v) : Math.floor(v);
   }

   /**
    * FUN_00437d00: with no name or no sequence in the cache (FUN_0042fc90)
    * -&gt; empty driver; otherwise, distance driver if arg1 == 0
    * (FUN_0043b3e0) and time driver if not (FUN_0043b790), with mode arg2.
    */
   static Driver driver(String name, int arg1, int arg2) {
      if (name == null || name.isEmpty()) {
         return new EmptyDriver();
      }
      AnimSeqCache.Sequence seq = AnimSeqCache.get(name);
      if (seq == null) {
         return new EmptyDriver();
      }
      return arg1 == 0 ? new DistanceDriver(seq, arg2) : new TimeDriver(seq, arg2);
   }

   // ------------------------------------------------------------- nodes

   public abstract static class Node {
      public abstract Node advance(float amount, AnimTime dt);

      public abstract AnimPose pose();
   }

   /** "pipe" (vtable 0x476e78, FUN_00439990 / FUN_00439a10): a driver at +0xc. */
   public static final class Pipe extends Node {
      Driver driver;

      Pipe(Driver d) {
         this.driver = d;
      }

      /** For the checks: the driver (+0xc). */
      public Driver driver() {
         return this.driver;
      }

      /** FUN_00439880: duration of the driver or {0, 0}. */
      public AnimTime duration() {
         return this.driver != null ? this.driver.duration() : AnimTime.ZERO;
      }

      /** FUN_00439710: if the driver ends, the pipe does too (null). */
      public Node advance(float amount, AnimTime dt) {
         if (this.driver != null) {
            this.driver = this.driver.advance(amount, dt);
         }
         return this.driver != null ? this : null;
      }

      /** FUN_004397e0: with no driver, null pose. */
      public AnimPose pose() {
         return this.driver == null ? null : this.driver.pose();
      }
   }

   /** FUN_004398c0: pipe with the empty driver (FUN_00437c60). */
   static Pipe emptyPipe() {
      return new Pipe(new EmptyDriver());
   }

   /** FUN_00439920: pipe with the driver of that sequence. */
   static Pipe pipe(String name, int arg1, int arg2) {
      return new Pipe(driver(name, arg1, arg2));
   }

   /**
    * "placeholder" (vtable 0x476e60, FUN_00439db0; the variant 0x476e48 of
    * FUN_00439ed0 has the same methods): a node at +0xc that can be taken
    * out (FUN_00439c60) and put in (FUN_00439c40). It never ends.
    */
   public static final class Placeholder extends Node {
      Node inner;

      Placeholder(Node inner) {
         this.inner = inner;
      }

      /** FUN_00439c60: returns the node and leaves the slot empty. */
      Node take() {
         Node n = this.inner;
         this.inner = null;
         return n;
      }

      /** FUN_00439c40. */
      void set(Node n) {
         this.inner = n;
      }

      /** FUN_00439aa0. */
      public Node advance(float amount, AnimTime dt) {
         if (this.inner != null) {
            this.inner = this.inner.advance(amount, dt);
         }
         return this;
      }

      /** FUN_00439b40. */
      public AnimPose pose() {
         return this.inner != null ? this.inner.pose() : null;
      }
   }

   /**
    * Base of two children (vtable 0x476e30, FUN_0043a150): A at +0xc, B
    * at +0x14, time {s, ms} at +0x18 and duration at +0x20.
    */
   abstract static class Transition extends Node {
      Node a;
      Node b;
      AnimTime elapsed = AnimTime.ZERO;
      final AnimTime duration;

      Transition(Node a, Node b, AnimTime duration) {
         this.a = a;
         this.b = b;
         this.duration = duration;
      }

      /**
       * FUN_00439fb0: advances both; if A ends B remains, if B ends A
       * remains.
       */
      Node advanceBoth(float amount, AnimTime dt) {
         if (this.a != null) {
            this.a = this.a.advance(amount, dt);
         }
         if (this.b != null) {
            this.b = this.b.advance(amount, dt);
         }
         if (this.a == null) {
            return this.b;
         }
         if (this.b == null) {
            return this.a;
         }
         return this;
      }

      /** time / duration in seconds, not clamped. */
      double ratio() {
         return this.elapsed.seconds() / this.duration.seconds();
      }

      abstract float weight();

      abstract AnimPose blend(AnimPose pa, AnimPose pb, float r);

      /**
       * FUN_0043a290 / FUN_0043a880 (same shape): blends the pose of A (or
       * an empty one) with that of B (or an empty one) with the weight from
       * [4]; with neither A nor B, empty pose.
       */
      public AnimPose pose() {
         float r = this.weight();
         if (this.a != null) {
            return this.blend(this.a.pose(), this.b == null ? AnimPose.empty() : this.b.pose(), r);
         }
         if (this.b == null) {
            return AnimPose.empty();
         }
         return this.blend(AnimPose.empty(), this.b.pose(), r);
      }
   }

   /**
    * Change of implicit entry "shiftto" (vtable 0x476e14, FUN_0043a6f0),
    * created by FUN_00432d10 with duration {0 s, 0xfa = 250 ms}.
    */
   public static final class ShiftTo extends Transition {
      ShiftTo(Node from, Node to, AnimTime duration) {
         super(from, to, duration);
      }

      /**
       * FUN_0043a1f0: time += dt; on reaching the duration the node is
       * replaced by whatever B returns when advanced; before that both
       * advance.
       */
      public Node advance(float amount, AnimTime dt) {
         this.elapsed = this.elapsed.plus(dt);
         if (this.elapsed.greaterOrEqual(this.duration)) {
            return this.b == null ? null : this.b.advance(amount, dt);
         }
         return this.advanceBoth(amount, dt);
      }

      /** FUN_0043a540: clamp(time / duration, 0, 1) (DAT_004767b4 = 0, DAT_004767b8 = 1). */
      float weight() {
         double f = this.ratio();
         if (f < 0.0 || Double.isNaN(f)) {
            f = 0.0;
         }
         if (1.0 < f) {
            f = 1.0;
         }
         return (float) f;
      }

      /** FUN_0043bde0. */
      AnimPose blend(AnimPose pa, AnimPose pb, float r) {
         return AnimPose.blendImplicit(pa, pb, r);
      }
   }

   /**
    * Explicit entry on top of the implicit one (vtable 0x476df8,
    * FUN_0043ad60), created by FUN_00432d10 with the duration of the
    * explicit entry's pipe.
    */
   public static final class Overlay extends Transition {
      Overlay(Node under, Node gesture, AnimTime duration) {
         super(under, gesture, duration);
      }

      /**
       * FUN_0043a7e0: time += dt; on reaching the duration it goes back to
       * what was underneath (A advances and is returned); before that both
       * advance (and if the gesture's pipe ends earlier, A remains too).
       */
      public Node advance(float amount, AnimTime dt) {
         this.elapsed = this.elapsed.plus(dt);
         if (this.elapsed.greaterOrEqual(this.duration)) {
            return this.a == null ? null : this.a.advance(amount, dt);
         }
         return this.advanceBoth(amount, dt);
      }

      /**
       * FUN_0043ab30: with override.ini [Runtime] NoImpChange = 1, 1;
       * otherwise, x = clamp(time / duration, 0, 1) and weight = clamp(4 * x *
       * (1 - x) * 2, 0, 1) (DAT_004767f0 = 4, DAT_004767f4 = 2): it comes in
       * over the first 14.6 % of the gesture and goes out over the last.
       */
      float weight() {
         if (noImpChange()) {
            return 1.0F;
         }
         double f = this.ratio();
         if (f < 0.0 || Double.isNaN(f)) {
            f = 0.0;
         } else if (1.0 < f) {
            f = 1.0;
         }
         double w = 4.0 * f * (1.0 - f) * 2.0;
         if (w < 0.0 || Double.isNaN(w)) {
            w = 0.0;
         } else if (1.0 < w) {
            w = 1.0;
         }
         return (float) w;
      }

      /** FUN_0043beb0. */
      AnimPose blend(AnimPose pa, AnimPose pb, float r) {
         return AnimPose.blendExplicit(pa, pb, r);
      }
   }

   /** For the checks: forces the value of NoImpChange (null = read override.ini). */
   public static volatile Boolean noImpChangeOverride;

   /**
    * GetPrivateProfileIntA("Runtime", "NoImpChange", 0, ".\\override.ini")
    * == 1 (FUN_004330a0, FUN_0043ab30): IniFile.override() is that same
    * file and section.
    */
   static boolean noImpChange() {
      Boolean o = noImpChangeOverride;
      if (o != null) {
         return o;
      }
      return IniFile.override().getIniInt("NoImpChange", 0) == 1;
   }
}
