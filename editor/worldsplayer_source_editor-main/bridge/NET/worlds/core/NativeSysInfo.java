package NET.worlds.core;

import java.io.File;

/**
 * {@code NET.worlds.core.SystemInfo} (gamma.dll 0x00442020-0x00442470): what
 * the client writes to the startup log ({@code SystemInfo.Record},
 * only if worlds.ini has {@code LogFile=}). The arithmetic and the strings
 * are gamma.dll's; the kernel32 queries are replaced by the JVM's on this
 * machine, in the original's units.
 */
public final class NativeSysInfo {
   /** Cap of GlobalMemoryStatus at 0x004421a0/200/260/2c0 (unsigned &gt; 0x7fffffff -> 0x7fffffff). */
   static final long MEM_CAP = 0x7fffffffL;
   /** 0x00478d48. */
   static final String UNKNOWN = "Unknown";
   /** 0x00478dd0: wProcessorArchitecture != 0 (not x86). */
   static final String UNKNOWN_ARCH = "Unknown Architecture";
   /** 0x00478e00: dwProcessorType == 0x24a (586). */
   static final String PENTIUM = "Intel Pentium (Generic - I/II/III/etc)";

   private NativeSysInfo() {
   }

   /**
    * GetDiskFreeSpace (0x00442020): GetDiskFreeSpaceA(root) and
    * {@code bytesPerSector * sectorsPerCluster * freeClusters >> 10} with
    * two 32-bit {@code imul} and {@code shr} (0x00442062-0x0044206a): free
    * KB of the volume modulo 4 GB. If the call fails, 0. A null root means
    * the current directory's.
    *
    * <p>Substitute: {@code File.getUsableSpace} is the free space for this
    * user (that of GetDiskFreeSpaceA, which accounts for quotas) and is a
    * product of blocks times block size, so the original's 32-bit product
    * is the same as truncating the free bytes to 32 bits. The root
    * goes through {@code NativeMock.localFile} (the bridge's synthetic "u:"
    * drive, '\\' as '/'); if it does not exist, the call fails. ⚠️ VERIFY:
    * the NT family is followed, which returns the real clusters; Windows 95
    * OSR2/98 capped the volume at 2 GB before multiplying.
    */
   public static int diskFreeKB(String root) {
      File f = root == null ? new File(System.getProperty("user.dir")) : NativeMock.localFile(root);
      if (!f.exists()) {
         return 0;
      }
      return diskFreeKB(f.getUsableSpace());
   }

   /** The arithmetic of 0x00442062: free bytes truncated to unsigned 32 bits, >> 10. */
   static int diskFreeKB(long freeBytes) {
      return (int) ((freeBytes & 0xffffffffL) >>> 10);
   }

   /**
    * GetSystemDirectory (0x00442100): GetSystemDirectoryA or, if it returns 0,
    * null. Outside Windows there is no Windows system directory: that failure
    * branch is taken, which Record already handles (it prints "null" and does
    * not measure the disk).
    */
   public static String systemDirectory() {
      return null;
   }

   /**
    * GetCurrentDirectory (0x00442150): GetCurrentDirectoryA. Here the
    * real working directory with the synthetic drive of the URL patch
    * ("u:" + user.dir, like {@code URL.normalizeCurrentDir}), so that Record
    * takes the drive with {@code substring(0, 2)} and measures that volume.
    */
   public static String currentDirectory() {
      String d = System.getProperty("user.dir").replace('\\', '/');
      return d.length() > 1 && d.charAt(1) == ':' ? d : "u:" + d;
   }

   /**
    * GlobalMemoryStatus (0x004421a0, 0x00442200, 0x00442260, 0x004422c0):
    * {dwTotalPhys, dwAvailPhys, dwTotalPageFile, dwAvailPageFile} capped at
    * 0x7fffffff. Win32's dwTotalPageFile/dwAvailPageFile are the commit
    * limit (physical memory + paging file) and what remains of
    * it, not just the paging file: here physical + swap and free physical +
    * free swap of this machine. Above 4 GB GlobalMemoryStatus saturates, and
    * gamma.dll's cap leaves the same result: min(real, 0x7fffffff).
    */
   public static int[] memoryStatus() {
      long totalPhys = bean("getTotalMemorySize", "getTotalPhysicalMemorySize");
      long availPhys = bean("getFreeMemorySize", "getFreePhysicalMemorySize");
      long totalSwap = bean("getTotalSwapSpaceSize", null);
      long freeSwap = bean("getFreeSwapSpaceSize", null);
      return memoryStatus(totalPhys, availPhys, totalSwap, freeSwap);
   }

   static int[] memoryStatus(long totalPhys, long availPhys, long totalSwap, long freeSwap) {
      return new int[]{cap(totalPhys), cap(availPhys), cap(totalPhys + totalSwap), cap(availPhys + freeSwap)};
   }

   static int cap(long v) {
      return (int) (v < 0L ? 0L : Math.min(v, MEM_CAP));
   }

   /** GetNumberOfProcessors (0x00442320): dwNumberOfProcessors = logical processors. */
   public static int processors() {
      return Runtime.getRuntime().availableProcessors();
   }

   /**
    * GetPlatformID (0x00442340): GetVersionExA with dwPlatformId 0/1/2 gives
    * "Microsoft Win32s", "MS Windows 95/98, version %d.%d" or "MS Windows NT
    * version %d.%d %s (Build %d)"; if GetVersionExA fails, "Unknown". Outside
    * Windows there is no dwPlatformId: the "Unknown" branch is taken. Nothing
    * is lost: Record prints {@code System.getProperties()} just before, with
    * os.name, os.version and os.arch.
    */
   public static String platformId() {
      return UNKNOWN;
   }

   /**
    * GetProcessorType (0x00442470): with wProcessorArchitecture 0 (x86)
    * it looks at dwProcessorType (0x182 "Intel 386", 0x1e6 "Intel 486", 0x24a
    * the generic Pentium) and otherwise at wProcessorLevel; with any other
    * architecture, "Unknown Architecture". gamma.dll is a 32-bit process: on
    * any x86 or x86-64 (this one, under WOW64) Windows gives it architecture
    * 0 and type 586 (PROCESSOR_INTEL_PENTIUM) for every Pentium or later, so
    * the string is that of 0x24a; for another architecture, that of
    * 0x00478dd0.
    */
   public static String processorType() {
      return processorType(System.getProperty("os.arch", ""));
   }

   static String processorType(String arch) {
      String a = arch.toLowerCase(java.util.Locale.ROOT);
      boolean x86 = a.equals("x86") || a.equals("amd64") || a.equals("x86_64") || a.matches("i[3-6]86");
      return x86 ? PENTIUM : UNKNOWN_ARCH;
   }

   /** Counters of the JVM's operating system via reflection (com.sun.management, without depending on it at compile time). */
   private static long bean(String name, String legacy) {
      Object b = java.lang.management.ManagementFactory.getOperatingSystemMXBean();
      for (String n : legacy == null ? new String[]{name} : new String[]{name, legacy}) {
         try {
            // through the exported interface: the implementation class is not exported
            java.lang.reflect.Method m = Class.forName("com.sun.management.OperatingSystemMXBean").getMethod(n);
            return ((Number) m.invoke(b)).longValue();
         } catch (ReflectiveOperationException | RuntimeException e) {
            // next name (getTotalMemorySize is JDK 14+)
         }
      }
      return 0L;
   }
}
