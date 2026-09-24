package NET.worlds.core;

import java.io.File;

/**
 * {@code NET.worlds.core.SystemInfo} (gamma.dll 0x00442020-0x00442470): lo
 * que el cliente escribe en el log de arranque ({@code SystemInfo.Record},
 * solo si worlds.ini tiene {@code LogFile=}). La aritmética y las cadenas son
 * de gamma.dll; las consultas a kernel32 se sustituyen por las de la JVM
 * sobre esta máquina, en las unidades del original.
 */
public final class NativeSysInfo {
   /** Tope de GlobalMemoryStatus en 0x004421a0/200/260/2c0 (unsigned &gt; 0x7fffffff -> 0x7fffffff). */
   static final long MEM_CAP = 0x7fffffffL;
   /** 0x00478d48. */
   static final String UNKNOWN = "Unknown";
   /** 0x00478dd0: wProcessorArchitecture != 0 (no x86). */
   static final String UNKNOWN_ARCH = "Unknown Architecture";
   /** 0x00478e00: dwProcessorType == 0x24a (586). */
   static final String PENTIUM = "Intel Pentium (Generic - I/II/III/etc)";

   private NativeSysInfo() {
   }

   /**
    * GetDiskFreeSpace (0x00442020): GetDiskFreeSpaceA(raíz) y
    * {@code bytesPorSector * sectoresPorCluster * clustersLibres >> 10} con
    * dos {@code imul} de 32 bits y {@code shr} (0x00442062-0x0044206a): KB
    * libres del volumen módulo 4 GB. Si la llamada falla, 0. La raíz nula es
    * la del directorio actual.
    *
    * <p>Sustituto: {@code File.getUsableSpace} es el espacio libre para este
    * usuario (el de GetDiskFreeSpaceA, que descuenta cuotas) y es producto
    * de bloques por tamaño de bloque, así que el producto de 32 bits del
    * original es el mismo que truncar los bytes libres a 32 bits. La raíz
    * pasa por {@code NativeMock.localFile} (unidad sintética "u:" del puente,
    * '\\' como '/'); si no existe, la llamada falla. ⚠️ VERIFICAR: se sigue
    * la familia NT, que devuelve los clusters reales; Windows 95 OSR2/98
    * topaban el volumen a 2 GB antes de multiplicar.
    */
   public static int diskFreeKB(String root) {
      File f = root == null ? new File(System.getProperty("user.dir")) : NativeMock.localFile(root);
      if (!f.exists()) {
         return 0;
      }
      return diskFreeKB(f.getUsableSpace());
   }

   /** La aritmética de 0x00442062: bytes libres truncados a 32 bits sin signo, >> 10. */
   static int diskFreeKB(long freeBytes) {
      return (int) ((freeBytes & 0xffffffffL) >>> 10);
   }

   /**
    * GetSystemDirectory (0x00442100): GetSystemDirectoryA o, si devuelve 0,
    * null. Fuera de Windows no hay directorio de sistema de Windows: se toma
    * esa rama de fallo, que Record ya maneja (imprime "null" y no mide el
    * disco).
    */
   public static String systemDirectory() {
      return null;
   }

   /**
    * GetCurrentDirectory (0x00442150): GetCurrentDirectoryA. Aquí el
    * directorio de trabajo real con la unidad sintética del parche de URL
    * ("u:" + user.dir, como {@code URL.normalizeCurrentDir}), para que Record
    * saque la unidad con {@code substring(0, 2)} y mida ese volumen.
    */
   public static String currentDirectory() {
      String d = System.getProperty("user.dir").replace('\\', '/');
      return d.length() > 1 && d.charAt(1) == ':' ? d : "u:" + d;
   }

   /**
    * GlobalMemoryStatus (0x004421a0, 0x00442200, 0x00442260, 0x004422c0):
    * {dwTotalPhys, dwAvailPhys, dwTotalPageFile, dwAvailPageFile} topados a
    * 0x7fffffff. dwTotalPageFile/dwAvailPageFile de Win32 son el límite de
    * compromiso (memoria física + fichero de paginación) y lo que queda de
    * él, no solo la paginación: aquí física + swap y física libre + swap
    * libre de esta máquina. Por encima de 4 GB GlobalMemoryStatus satura, y
    * el tope de gamma.dll deja lo mismo: min(real, 0x7fffffff).
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

   /** GetNumberOfProcessors (0x00442320): dwNumberOfProcessors = procesadores lógicos. */
   public static int processors() {
      return Runtime.getRuntime().availableProcessors();
   }

   /**
    * GetPlatformID (0x00442340): GetVersionExA con dwPlatformId 0/1/2 da
    * "Microsoft Win32s", "MS Windows 95/98, version %d.%d" o "MS Windows NT
    * version %d.%d %s (Build %d)"; si GetVersionExA falla, "Unknown". Fuera
    * de Windows no hay dwPlatformId: se toma la rama "Unknown". No se pierde
    * nada: Record imprime justo antes {@code System.getProperties()}, con
    * os.name, os.version y os.arch.
    */
   public static String platformId() {
      return UNKNOWN;
   }

   /**
    * GetProcessorType (0x00442470): con wProcessorArchitecture 0 (x86)
    * mira dwProcessorType (0x182 "Intel 386", 0x1e6 "Intel 486", 0x24a el
    * Pentium genérico) y si no wProcessorLevel; con otra arquitectura,
    * "Unknown Architecture". gamma.dll es un proceso de 32 bits: en
    * cualquier x86 o x86-64 (este, en WOW64) Windows le da arquitectura 0 y
    * tipo 586 (PROCESSOR_INTEL_PENTIUM) para todo Pentium o posterior, así
    * que la cadena es la de 0x24a; otra arquitectura, la de 0x00478dd0.
    */
   public static String processorType() {
      return processorType(System.getProperty("os.arch", ""));
   }

   static String processorType(String arch) {
      String a = arch.toLowerCase(java.util.Locale.ROOT);
      boolean x86 = a.equals("x86") || a.equals("amd64") || a.equals("x86_64") || a.matches("i[3-6]86");
      return x86 ? PENTIUM : UNKNOWN_ARCH;
   }

   /** Contadores del sistema operativo de la JVM por reflexión (com.sun.management, sin depender de él al compilar). */
   private static long bean(String name, String legacy) {
      Object b = java.lang.management.ManagementFactory.getOperatingSystemMXBean();
      for (String n : legacy == null ? new String[]{name} : new String[]{name, legacy}) {
         try {
            // por la interfaz exportada: la clase de la implementación no lo está
            java.lang.reflect.Method m = Class.forName("com.sun.management.OperatingSystemMXBean").getMethod(n);
            return ((Number) m.invoke(b)).longValue();
         } catch (ReflectiveOperationException | RuntimeException e) {
            // siguiente nombre (getTotalMemorySize es de JDK 14+)
         }
      }
      return 0L;
   }
}
