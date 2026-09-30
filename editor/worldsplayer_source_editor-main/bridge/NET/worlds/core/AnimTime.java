package NET.worlds.core;

/**
 * The time of gamma.dll's animation engine: two uint32 {seconds,
 * milliseconds}. All comparisons are unsigned, exactly as in the binary
 * (the arguments are uint*). Immutable.
 */
public final class AnimTime {
   public final int s;
   public final int ms;

   public static final AnimTime ZERO = new AnimTime(0, 0);

   public AnimTime(int s, int ms) {
      this.s = s;
      this.ms = ms;
   }

   /** FUN_00427a20: {t / 1000, t % 1000} with unsigned division. */
   public static AnimTime ofMillis(int t) {
      return new AnimTime(Integer.divideUnsigned(t, 1000), Integer.remainderUnsigned(t, 1000));
   }

   /**
    * FUN_00427a50: seconds = floor(f) (frndint with the control word
    * 0x077f of DAT_00480a7c, rounding down) and ms = floor((f -
    * seconds) * 1000.0) (DAT_00472028); both fistpll truncate and the low
    * half is stored.
    */
   public static AnimTime ofSeconds(float f) {
      double d = f;
      int s = (int) (long) Math.floor(d);
      double frac = d - (double) (s & 0xFFFFFFFFL);
      return new AnimTime(s, (int) (long) Math.floor(frac * 1000.0));
   }

   /** FUN_00427c50: addition with carry from the ms (unsigned division). */
   public AnimTime plus(AnimTime b) {
      int m = this.ms + b.ms;
      return new AnimTime(Integer.divideUnsigned(m, 1000) + this.s + b.s, Integer.remainderUnsigned(m, 1000));
   }

   /** FUN_00427cb0: subtraction; if ms &lt; b.ms (unsigned) it borrows one second. */
   public AnimTime minus(AnimTime b) {
      if (Integer.compareUnsigned(this.ms, b.ms) < 0) {
         return new AnimTime(this.s - b.s - 1, this.ms + 1000 - b.ms);
      }
      return new AnimTime(this.s - b.s, this.ms - b.ms);
   }

   /** FUN_00427b00. */
   public boolean same(AnimTime b) {
      return this.s == b.s && this.ms == b.ms;
   }

   /** FUN_00427b70(this, b): this &lt; b. */
   public boolean less(AnimTime b) {
      int c = Integer.compareUnsigned(this.s, b.s);
      return c < 0 || c == 0 && Integer.compareUnsigned(this.ms, b.ms) < 0;
   }

   /** FUN_00427bb0(this, b): this &lt;= b. */
   public boolean lessOrEqual(AnimTime b) {
      return !b.less(this);
   }

   /** FUN_00427c00(this, b): this &gt;= b. */
   public boolean greaterOrEqual(AnimTime b) {
      return !this.less(b);
   }

   /** s + ms / 1000 in extended precision (64-bit fild with the high part at 0, i.e. unsigned). */
   public double seconds() {
      return (double) (this.s & 0xFFFFFFFFL) + (double) (this.ms & 0xFFFFFFFFL) / 1000.0;
   }

   /**
    * 32-bit fistp: truncation already applied by the caller; out of range
    * or NaN gives the integer indefinite 0x80000000 like the x87.
    */
   static int fistp(double v) {
      if (Double.isNaN(v) || v >= 2147483648.0 || v < -2147483648.0) {
         return Integer.MIN_VALUE;
      }
      return (int) v;
   }

   @Override
   public String toString() {
      return "{" + (this.s & 0xFFFFFFFFL) + "s," + (this.ms & 0xFFFFFFFFL) + "ms}";
   }
}
