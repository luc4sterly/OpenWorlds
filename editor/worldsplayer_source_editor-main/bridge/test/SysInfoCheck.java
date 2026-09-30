package NET.worlds.core;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.PrintStream;

/**
 * SystemInfo (gamma.dll 0x00442020-0x00442470) over NativeSysInfo: the
 * free-KB arithmetic (two 32-bit imul and shr 10), the cap of
 * GlobalMemoryStatus, the literal strings and the real log of
 * SystemInfo.Record. Exits with 1 if anything fails.
 */
public final class SysInfoCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      // 0x00442062: (bytes libres mod 2^32) >> 10
      eq("0 bytes", NativeSysInfo.diskFreeKB(0L), 0);
      eq("1023 bytes", NativeSysInfo.diskFreeKB(1023L), 0);
      eq("1024 bytes", NativeSysInfo.diskFreeKB(1024L), 1);
      eq("exactly 4 GB: the 32-bit product gives 0", NativeSysInfo.diskFreeKB(0x100000000L), 0);
      eq("4 GB + 5 KB", NativeSysInfo.diskFreeKB(0x100000000L + 5 * 1024), 5);
      eq("0xffffffff", NativeSysInfo.diskFreeKB(0xffffffffL), 4194303);
      // 10 GiB = 8 sect/cluster * 512 B/sect * 2621440 clusters = 10737418240
      // mod 2^32 = 2147483648 -> >> 10 = 2097152
      eq("10 GiB", NativeSysInfo.diskFreeKB(8L * 512L * 2621440L), 2097152);
      eq("nonexistent root -> 0 (GetDiskFreeSpaceA fails)", NativeSysInfo.diskFreeKB("q:\\no\\existe\\"), 0);
      int root = NativeSysInfo.diskFreeKB("u:\\");
      int expect = NativeSysInfo.diskFreeKB(new File("/").getUsableSpace());
      check("u:\\ = root volume (" + root + " ~ " + expect + ")", Math.abs(root - expect) < 102400);
      int cwd = NativeSysInfo.diskFreeKB((String) null);
      int expectCwd = NativeSysInfo.diskFreeKB(new File(System.getProperty("user.dir")).getUsableSpace());
      check("null = current directory (" + cwd + " ~ " + expectCwd + ")", Math.abs(cwd - expectCwd) < 102400);

      // GlobalMemoryStatus + cap 0x7fffffff (0x004421a0...)
      long G = 1L << 30, M = 1L << 20;
      eqa("8G/3G/1G/512M all capped", NativeSysInfo.memoryStatus(8 * G, 3 * G, 1 * G, 512 * M),
         new int[]{0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff});
      eqa("1G/256M/512M/128M", NativeSysInfo.memoryStatus(1 * G, 256 * M, 512 * M, 128 * M),
         new int[]{1073741824, 268435456, 1610612736, 402653184});
      eqa("1.5G/1G/1G/0: 2.5G commit capped", NativeSysInfo.memoryStatus(3 * G / 2, 1 * G, 1 * G, 0),
         new int[]{1610612736, 1073741824, 0x7fffffff, 1073741824});
      eq("negative -> 0", NativeSysInfo.cap(-1L), 0);
      int[] real = NativeSysInfo.memoryStatus();
      check("real memory > 0 and <= cap", real[0] > 0 && real[1] > 0 && real[1] <= real[0] && real[2] >= real[0] && real[3] > 0);

      // literal strings of 0x00442470 / 0x00442340
      eqs("x86_64", NativeSysInfo.processorType("x86_64"), "Intel Pentium (Generic - I/II/III/etc)");
      eqs("amd64", NativeSysInfo.processorType("amd64"), "Intel Pentium (Generic - I/II/III/etc)");
      eqs("i686", NativeSysInfo.processorType("i686"), "Intel Pentium (Generic - I/II/III/etc)");
      eqs("x86", NativeSysInfo.processorType("x86"), "Intel Pentium (Generic - I/II/III/etc)");
      eqs("aarch64", NativeSysInfo.processorType("aarch64"), "Unknown Architecture");
      eqs("ppc", NativeSysInfo.processorType("ppc"), "Unknown Architecture");
      eqs("platform", NativeSysInfo.platformId(), "Unknown");
      eqs("system directory", NativeSysInfo.systemDirectory(), null);
      eqs("current directory", NativeSysInfo.currentDirectory(), "u:" + System.getProperty("user.dir"));
      eq("processors", NativeSysInfo.processors(), Runtime.getRuntime().availableProcessors());

      // the real startup log (LogFile.open -> SystemInfo.Record)
      ByteArrayOutputStream buf = new ByteArrayOutputStream();
      SystemInfo.Record(new PrintStream(buf, true));
      String log = buf.toString();
      check("SYSTEM null", log.contains("Windows SYSTEM path: null\n"));
      check("cwd", log.contains("Current Working Directory: u:" + System.getProperty("user.dir") + "\n"));
      check("disk of u:", log.matches("(?s).*\tFree disk space \\(u:\\): [0-9]+ KB\n.*"));
      check("only one disk measured (SYSTEM is null)", log.split("Free disk space", -1).length == 2);
      check("physical memory", log.matches("(?s).*\tTotal Physical Memory: [1-9][0-9]*\n.*"));
      check("CPUs", log.contains("Number of CPUs: " + Runtime.getRuntime().availableProcessors() + "\n"));
      check("platform", log.contains("Platform  Type: Unknown\n"));
      check("processor", log.contains("Processor Type: " + NativeSysInfo.processorType() + "\n"));

      if (failures > 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("SysInfoCheck OK");
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FAIL " + what);
      }
   }

   private static void eq(String what, int got, int want) {
      check(what + ": " + got + " != " + want, got == want);
   }

   private static void eqa(String what, int[] got, int[] want) {
      check(what + ": " + java.util.Arrays.toString(got) + " != " + java.util.Arrays.toString(want), java.util.Arrays.equals(got, want));
   }

   private static void eqs(String what, String got, String want) {
      check(what + ": \"" + got + "\" != \"" + want + "\"", got == null ? want == null : got.equals(want));
   }
}
