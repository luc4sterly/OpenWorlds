package net.openworlds.bod;

/**
 * SeqSampler.keyTime: the key comes from trunc(seconds * 30) with gamma.dll's
 * fistp in chop mode (0x43b9c0 in FUN_0043b950, 0x43b70f in
 * FUN_0043b5f0), not rounded. Values calculated by hand in each case
 * (the input float already rounded to 24 bits, the product in double).
 */
public class SeqSamplerCheck {
   private static int fails;

   static void eq(int got, int want, String what) {
      boolean ok = got == want;
      System.out.println((ok ? "ok   " : "FAIL ") + what + " = " + got + (ok ? "" : " (expected " + want + ")"));
      if (!ok) {
         fails++;
      }
   }

   public static void main(String[] args) {
      int loop = SeqSampler.MODE_LOOP;
      int hold = SeqSampler.MODE_HOLD;
      // 1.0 * 30 = exactly 30.
      eq(SeqSampler.keyTime(1.0f, 33, loop), 30, "1 s -> key 30");
      // 0.05f = 0.05000000074505806; x30 = 1.5000000223 -> trunc 1 (round would give 2).
      eq(SeqSampler.keyTime(0.05f, 33, loop), 1, "0.05 s = 1.5 keys -> 1 (truncates)");
      // 0.0666666f = 0.06666660308837891; x30 = 1.9999980926 -> 1 (round would give 2).
      // It is the same case as the bridge's AnimatorPlaybackCheck ("loop with truncation: 1").
      eq(SeqSampler.keyTime(0.0666666f, 33, loop), 1, "1.99999 keys -> 1");
      // 0.033f = 0.032999999821186066; x30 = 0.98999999 -> 0 (round would give 1).
      eq(SeqSampler.keyTime(0.033f, 33, loop), 0, "0.99 keys -> 0");
      // 0.1f = 0.10000000149011612; x30 = 3.0000000447 -> 3.
      eq(SeqSampler.keyTime(0.1f, 858, hold), 3, "0.1 s -> key 3 (axel's wait in AnimatorPlaybackCheck)");
      // 1.1f = 1.100000023841858; x30 = 33.0000007 -> 33 == duration: does not wrap.
      eq(SeqSampler.keyTime(1.1f, 33, loop), 33, "key == duration stays");
      // 1.2f = 1.2000000476837158; x30 = 36.0000014 -> 36 > 33.
      eq(SeqSampler.keyTime(1.2f, 33, loop), 2, "loop: 36 % (33 + 1) = 2");
      eq(SeqSampler.keyTime(1.2f, 33, hold), 33, "mode 1: stays at the last key");
      eq(SeqSampler.keyTime(1.2f, 33, 0), -1, "mode 0: playback ends");
      // 30.3 s of axel's wait (858 keys): 30.299999237060547 x30 = 908.99997 -> 908 > 858 -> 858.
      eq(SeqSampler.keyTime(30.3f, 858, hold), 858, "30.3 s of the wait: mode 1 -> 858");
      // Outside the int range: fistp gives 0x80000000, whose short is 0.
      eq(SeqSampler.keyTime(1e10f, 33, loop), 0, "out of range -> 0x80000000 -> short 0");
      eq(SeqSampler.fistpChop(Double.NaN), Integer.MIN_VALUE, "NaN -> integer indefinite");
      eq(SeqSampler.fistpChop(-2.7), -2, "chop toward zero with negatives");

      System.out.println(fails == 0 ? "SeqSamplerCheck: OK" : "SeqSamplerCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}
