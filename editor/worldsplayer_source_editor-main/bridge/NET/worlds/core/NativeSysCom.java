package NET.worlds.core;

import java.io.IOException;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/**
 * COM de gamma.dll ({@code IUnknown}, {@code IDispatch}, {@code IClassFactory},
 * {@code INetscapeRegistry}, {@code NSProtocolHandler}) fuera de Windows.
 *
 * <p>Sin ole32 no hay objetos COM ajenos: {@code ActiveX.getClassFClsID/
 * getClassFProgID} ya fallan con IOException (hunk de ActiveX en
 * natives.patch), así que el único objeto que puede existir es el que
 * gamma.dll implementa él mismo, la fábrica de clases local de
 * {@code NSProtocolHandler.createLocal} (0x00441f30: 8 bytes, vtable
 * 0x00478ce8 y cuenta de referencias 1 en +4). De ella se traduce lo que el
 * cliente puede llamar desde Java:
 * <ul>
 * <li>QueryInterface (0x0040ac20): IID_IUnknown (0x00466e40) o
 *     IID_IClassFactory (0x00466e30) -> AddRef y ella misma; otro ->
 *     E_NOINTERFACE 0x80004002.</li>
 * <li>AddRef (0x0040ab80) y Release (0x0040ab90: a 0 llama al destructor
 *     de vtable+0x18, 0x00441f90, que la libera).</li>
 * </ul>
 * CreateInstance (0x0040acc0) y LockServer (0x0040ad30) solo los llama el
 * runtime de COM de otro proceso, que aquí no existe.
 *
 * <p>Lo que sí delega en ole32 toma su rama de fallo, con los mensajes
 * literales de gamma.dll, para que el cliente siga su propio camino de
 * "no disponible" (Netscape.mainCallback: "OLEDEBUG: No Netscape").
 */
public final class NativeSysCom {
   /** 0x00466e40: {00000000-0000-0000-C000-000000000046}. */
   static final String IID_IUNKNOWN = "{00000000-0000-0000-C000-000000000046}";
   /** 0x00466e30: {00000001-0000-0000-C000-000000000046}. */
   static final String IID_ICLASSFACTORY = "{00000001-0000-0000-C000-000000000046}";

   /** Fábricas locales vivas: puntero -> cuenta de referencias (+4). */
   private static final Map<Integer, int[]> objects = new HashMap<Integer, int[]>();
   private static int nextPtr = 0x00500000;

   private NativeSysCom() {
   }

   /** NSProtocolHandler.createLocal (0x00441f30): la fábrica con 1 referencia. */
   public static synchronized int createLocalFactory() {
      int p = nextPtr;
      nextPtr += 8;
      objects.put(p, new int[]{1});
      return p;
   }

   /** Cuenta de referencias de un objeto local, o -1 si ya no existe (para las comprobaciones). */
   static synchronized int refs(int p) {
      int[] r = objects.get(p);
      return r == null ? -1 : r[0];
   }

   /** IUnknown.true_AddRef (0x0040b330) -> AddRef 0x0040ab80. */
   public static synchronized int addRef(int p) {
      return ++object(p)[0];
   }

   /** IUnknown.true_Release (0x0040b3c0) -> Release 0x0040ab90: a 0, destructor 0x00441f90. */
   public static synchronized int release(int p) {
      int[] r = object(p);
      if (--r[0] != 0) {
         return r[0];
      }
      objects.remove(p);
      return 0;
   }

   /**
    * IUnknown.QueryInterface (0x0040b450): el IID con FUN_0040a4d0
    * (IIDFromString: si falla, IOException "nActiveX: Couldn't convert
    * String to IID" y 0) y la QueryInterface del objeto (0x0040ac20); si
    * devuelve negativo, IOException "IUnknown.QueryInterface: interface not
    * available".
    */
   public static synchronized int queryInterface(int p, String iid) throws IOException {
      String g = parseGuid(iid);
      if (g == null) {
         throw new IOException("nActiveX: Couldn't convert String to IID");
      }
      object(p);
      if (!g.equals(IID_IUNKNOWN) && !g.equals(IID_ICLASSFACTORY)) {
         throw new IOException("IUnknown.QueryInterface: interface not available");
      }
      addRef(p);
      return p;
   }

   /**
    * IDispatch.Invoke (0x0040af10): GetIDsOfNames (vtable+0x14) con el
    * nombre; si falla, IOException "IDispatch: bad function name". Ningún
    * objeto que exista aquí implementa IDispatch (la fábrica local rechaza
    * IID_IDispatch en su QueryInterface y ActiveX no crea otros), así que el
    * nombre nunca se resuelve. El original seguía llamando a Invoke con el
    * DISPID sin inicializar y la excepción pendiente; aquí se para en la
    * primera, que es la que ve Java. Java no declara IOException en Invoke:
    * se lanza como JNI (NativeSysJni).
    */
   public static void invoke(int p, String name) {
      throw NativeSysJni.throwNew(new IOException("IDispatch: bad function name"));
   }

   /**
    * INetscapeRegistry.RegisterProtocol/RegisterViewer (0x0040b220/250 ->
    * FUN_0040b0b0 -> FUN_0040b030): GetIDsOfNames de L"RegisterProtocol" /
    * L"RegisterViewer"; al fallar, IOException "IDispatch: GetIDsOfNames()
    * failed" y false. Mismo motivo que {@link #invoke}.
    */
   public static boolean netscapeRegister(int p, String method) throws IOException {
      throw new IOException("IDispatch: GetIDsOfNames() failed");
   }

   /**
    * IClassFactory.nActivate (0x0040ad80): CLSIDFromString (si falla,
    * IOException "Unable to determine CLSID") y CoRegisterClassObject; sin
    * runtime de COM al que registrarse, su rama de error: IOException
    * "Failed to register class with ActiveX". Nunca devuelve.
    */
   public static long registerClassObject(int p, String clsid) throws IOException {
      if (clsidFromString(clsid) == null) {
         throw new IOException("Unable to determine CLSID");
      }
      throw new IOException("Failed to register class with ActiveX");
   }

   /**
    * IClassFactory.nDeactivate (0x0040ae60): CoRevokeClassObject del cookie.
    * No puede haber ninguno registrado (nActivate siempre falla aquí).
    * ⚠️ VERIFICAR: se supone que ole32 devuelve E_INVALIDARG para un cookie
    * desconocido (lo que hace Wine), que cae en la rama "Failed to revoke
    * class factory" (HRESULT negativo que no es E_UNEXPECTED ni
    * E_OUTOFMEMORY). El cliente solo llega aquí con _registerID != 0.
    */
   public static void revokeClassObject(long cookie) throws IOException {
      throw new IOException("Failed to revoke class factory");
   }

   /**
    * CLSIDFromString: un GUID entre llaves o un ProgID, cuyo CLSID es el
    * valor por defecto de HKCR\ProgID\CLSID (en el registro portable).
    */
   static String clsidFromString(String s) {
      String g = parseGuid(s);
      if (g != null || s == null || s.isEmpty()) {
         return g;
      }
      try {
         int k = NativeSysRegistry.openKey(NativeSysRegistry.reservedKey(0), s + "\\CLSID", 0);
         String v = NativeSysRegistry.getString(k, "");
         NativeSysRegistry.close(k);
         return parseGuid(v);
      } catch (RegKeyNotFoundException e) {
         return null;
      }
   }

   /**
    * IIDFromString: exactamente "{8-4-4-4-12}" en hexadecimal, sin
    * distinguir mayúsculas. Devuelve la forma canónica en mayúsculas o null.
    */
   static String parseGuid(String s) {
      if (s == null || s.length() != 38 || s.charAt(0) != '{' || s.charAt(37) != '}') {
         return null;
      }
      for (int i = 1; i < 37; i++) {
         char c = s.charAt(i);
         boolean dash = i == 9 || i == 14 || i == 19 || i == 24;
         if (dash ? c != '-' : Character.digit(c, 16) < 0) {
            return null;
         }
      }
      return s.toUpperCase(Locale.ROOT);
   }

   private static int[] object(int p) {
      int[] r = objects.get(p);
      if (r == null) {
         // el original llamaría por la vtable de memoria liberada o ajena
         throw new IllegalStateException("gamma.dll: puntero COM " + Integer.toHexString(p) + " sin objeto");
      }
      return r;
   }
}
