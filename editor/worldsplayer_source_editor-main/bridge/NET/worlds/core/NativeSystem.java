package NET.worlds.core;

/**
 * Win32 system queries that gamma.dll makes on behalf of the client.
 */
public final class NativeSystem {
   private NativeSystem() {
   }

   private static long clamp(long v) {
      return v < 0L ? 0L : (v > 0x7fffffffL ? 0x7fffffffL : v);
   }

   /**
    * GlobalMemoryStatus (StatMemNode.updateMemoryStatus, 0x0040a360):
    * {totalPhys, availPhys, totalPageFile, availPageFile} in bytes, each
    * clamped to 0x7fffffff as the native does. The page file figures are
    * the swap of this machine; where the OS does not report them (the JVM
    * has no such counter), the physical ones are used.
    */
   public static long[] memoryStatus() {
      long totalPhys = 0L, availPhys = 0L, totalPage = 0L, availPage = 0L;
      try {
         java.lang.management.OperatingSystemMXBean bean = java.lang.management.ManagementFactory.getOperatingSystemMXBean();
         totalPhys = (Long) call(bean, "getTotalMemorySize", "getTotalPhysicalMemorySize");
         availPhys = (Long) call(bean, "getFreeMemorySize", "getFreePhysicalMemorySize");
         totalPage = (Long) call(bean, "getTotalSwapSpaceSize", null);
         availPage = (Long) call(bean, "getFreeSwapSpaceSize", null);
      } catch (Exception e) {
         // no OS counters: fall back to the JVM heap below
      }
      if (totalPhys == 0L) {
         totalPhys = Runtime.getRuntime().maxMemory();
         availPhys = Runtime.getRuntime().freeMemory();
      }
      if (totalPage == 0L) {
         totalPage = totalPhys;
         availPage = availPhys;
      }
      return new long[]{clamp(totalPhys), clamp(availPhys), clamp(totalPage), clamp(availPage)};
   }

   private static Object call(Object bean, String name, String legacy) {
      for (String n : legacy == null ? new String[]{name} : new String[]{name, legacy}) {
         try {
            java.lang.reflect.Method m = bean.getClass().getMethod(n);
            m.setAccessible(true);
            return m.invoke(bean);
         } catch (Exception e) {
            // try the next name
         }
      }
      return Long.valueOf(0L);
   }
}
