package net.openworlds.bod;

/**
 * SeqSampler.keyTime: el key sale de trunc(segundos * 30) con el fistp en
 * modo chop de gamma.dll (0x43b9c0 en FUN_0043b950, 0x43b70f en
 * FUN_0043b5f0), no redondeado. Valores calculados a mano en cada caso
 * (el float de entrada ya redondeado a 24 bits, el producto en doble).
 */
public class SeqSamplerCheck {
   private static int fails;

   static void eq(int got, int want, String what) {
      boolean ok = got == want;
      System.out.println((ok ? "ok   " : "FAIL ") + what + " = " + got + (ok ? "" : " (esperado " + want + ")"));
      if (!ok) {
         fails++;
      }
   }

   public static void main(String[] args) {
      int loop = SeqSampler.MODE_LOOP;
      int hold = SeqSampler.MODE_HOLD;
      // 1.0 * 30 = 30 exacto.
      eq(SeqSampler.keyTime(1.0f, 33, loop), 30, "1 s -> key 30");
      // 0.05f = 0.05000000074505806; x30 = 1.5000000223 -> trunc 1 (round daria 2).
      eq(SeqSampler.keyTime(0.05f, 33, loop), 1, "0.05 s = 1.5 keys -> 1 (trunca)");
      // 0.0666666f = 0.06666660308837891; x30 = 1.9999980926 -> 1 (round daria 2).
      // Es el mismo caso que AnimatorPlaybackCheck del puente ("bucle con truncado: 1").
      eq(SeqSampler.keyTime(0.0666666f, 33, loop), 1, "1.99999 keys -> 1");
      // 0.033f = 0.032999999821186066; x30 = 0.98999999 -> 0 (round daria 1).
      eq(SeqSampler.keyTime(0.033f, 33, loop), 0, "0.99 keys -> 0");
      // 0.1f = 0.10000000149011612; x30 = 3.0000000447 -> 3.
      eq(SeqSampler.keyTime(0.1f, 858, hold), 3, "0.1 s -> key 3 (wait de axel en AnimatorPlaybackCheck)");
      // 1.1f = 1.100000023841858; x30 = 33.0000007 -> 33 == duracion: no envuelve.
      eq(SeqSampler.keyTime(1.1f, 33, loop), 33, "key == duracion se queda");
      // 1.2f = 1.2000000476837158; x30 = 36.0000014 -> 36 > 33.
      eq(SeqSampler.keyTime(1.2f, 33, loop), 2, "bucle: 36 % (33 + 1) = 2");
      eq(SeqSampler.keyTime(1.2f, 33, hold), 33, "modo 1: se queda en el ultimo key");
      eq(SeqSampler.keyTime(1.2f, 33, 0), -1, "modo 0: la reproduccion termina");
      // 30.3 s del wait de axel (858 keys): 30.299999237060547 x30 = 908.99997 -> 908 > 858 -> 858.
      eq(SeqSampler.keyTime(30.3f, 858, hold), 858, "30.3 s del wait: modo 1 -> 858");
      // Fuera de rango de int: fistp da 0x80000000, su short es 0.
      eq(SeqSampler.keyTime(1e10f, 33, loop), 0, "fuera de rango -> 0x80000000 -> short 0");
      eq(SeqSampler.fistpChop(Double.NaN), Integer.MIN_VALUE, "NaN -> entero indefinido");
      eq(SeqSampler.fistpChop(-2.7), -2, "chop hacia cero con negativos");

      System.out.println(fails == 0 ? "SeqSamplerCheck: OK" : "SeqSamplerCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}
