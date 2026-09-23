package NET.worlds.core;

/**
 * El tiempo del motor de animacion de gamma.dll: dos uint32 {segundos,
 * milisegundos}. Todas las comparaciones son sin signo, igual que en el
 * binario (los argumentos son uint*). Inmutable.
 */
public final class AnimTime {
   public final int s;
   public final int ms;

   public static final AnimTime ZERO = new AnimTime(0, 0);

   public AnimTime(int s, int ms) {
      this.s = s;
      this.ms = ms;
   }

   /** FUN_00427a20: {t / 1000, t % 1000} con division sin signo. */
   public static AnimTime ofMillis(int t) {
      return new AnimTime(Integer.divideUnsigned(t, 1000), Integer.remainderUnsigned(t, 1000));
   }

   /**
    * FUN_00427a50: segundos = floor(f) (frndint con la palabra de control
    * 0x077f de DAT_00480a7c, redondeo hacia abajo) y ms = floor((f -
    * segundos) * 1000.0) (DAT_00472028); los dos fistpll truncan y se
    * guarda la mitad baja.
    */
   public static AnimTime ofSeconds(float f) {
      double d = f;
      int s = (int) (long) Math.floor(d);
      double frac = d - (double) (s & 0xFFFFFFFFL);
      return new AnimTime(s, (int) (long) Math.floor(frac * 1000.0));
   }

   /** FUN_00427c50: suma con acarreo de los ms (division sin signo). */
   public AnimTime plus(AnimTime b) {
      int m = this.ms + b.ms;
      return new AnimTime(Integer.divideUnsigned(m, 1000) + this.s + b.s, Integer.remainderUnsigned(m, 1000));
   }

   /** FUN_00427cb0: resta; si ms &lt; b.ms (sin signo) pide prestado un segundo. */
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

   /** s + ms / 1000 en extendido (fild de 64 bits con la parte alta a 0, o sea sin signo). */
   public double seconds() {
      return (double) (this.s & 0xFFFFFFFFL) + (double) (this.ms & 0xFFFFFFFFL) / 1000.0;
   }

   /**
    * fistp de 32 bits: truncado ya aplicado por el llamante; fuera de rango
    * o NaN da el entero indefinido 0x80000000 como el x87.
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
