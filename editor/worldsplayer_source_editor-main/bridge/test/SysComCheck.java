package NET.worlds.core;

import NET.worlds.console.IDispatch;
import NET.worlds.console.IUnknown;
import NET.worlds.console.NSProtocolHandler;
import NET.worlds.console.Netscape;
import java.io.File;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * COM de gamma.dll fuera de Windows (NativeSysCom): la fábrica local de
 * NSProtocolHandler (0x00441f30) con su QueryInterface/AddRef/Release
 * (0x0040ac20/ab80/ab90) a través de las clases reales del cliente, getPtr
 * (0x0040b2b0) y las ramas de fallo con sus mensajes literales. Sale con 1
 * si algo falla.
 */
public final class SysComCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File store = File.createTempFile("fw-registry-com", ".reg");
      store.delete();
      System.setProperty("openworlds.registry", store.getPath());

      // IIDFromString
      eqs("GUID minúsculas", NativeSysCom.parseGuid("{f8535c80-f5ee-11d2-a6ac-0050041a1735}"), "{F8535C80-F5EE-11D2-A6AC-0050041A1735}");
      eqs("sin llaves", NativeSysCom.parseGuid("f8535c80-f5ee-11d2-a6ac-0050041a1735"), null);
      eqs("guion movido", NativeSysCom.parseGuid("{f8535c80f-5ee-11d2-a6ac-0050041a1735}"), null);
      eqs("no hex", NativeSysCom.parseGuid("{g8535c80-f5ee-11d2-a6ac-0050041a1735}"), null);
      eqs("ProgID", NativeSysCom.parseGuid("Gamma.Protocol.1"), null);

      // la fábrica local por NSProtocolHandler: createLocal + IUnknown.init(int)
      NSProtocolHandler h = new NSProtocolHandler();
      int p = pInterface(h);
      check("puntero != 0", p != 0);
      eq("refs tras crear", NativeSysCom.refs(p), 1);
      h.AddRef();
      eq("AddRef", NativeSysCom.refs(p), 2);
      int q = h.QueryInterface("{00000001-0000-0000-c000-000000000046}");
      eq("QI IClassFactory devuelve la misma", q, p);
      eq("QI sube la cuenta", NativeSysCom.refs(p), 3);
      eq("QI IUnknown", h.QueryInterface("{00000000-0000-0000-C000-000000000046}"), p);
      eq("refs", NativeSysCom.refs(p), 4);
      NativeSysCom.release(p);
      NativeSysCom.release(p);
      eq("Release x2", NativeSysCom.refs(p), 2);
      eqs("QI IDispatch", thrown(() -> h.QueryInterface("{00020400-0000-0000-C000-000000000046}")),
         "java.io.IOException: IUnknown.QueryInterface: interface not available");
      eqs("QI con IID mal escrito", thrown(() -> h.QueryInterface("IDispatch")),
         "java.io.IOException: nActiveX: Couldn't convert String to IID");
      eq("fallos sin tocar la cuenta", NativeSysCom.refs(p), 2);
      // IDispatch(IUnknown) = QueryInterface(IID_IDispatch): no hay IDispatch
      eqs("IDispatch sobre la fábrica", thrown(() -> new IDispatch(h)),
         "java.io.IOException: IUnknown.QueryInterface: interface not available");

      // nActivate: CLSIDFromString y CoRegisterClassObject sin runtime de COM
      eqs("nActivate con su CLSID", thrown(() -> nActivate(h, NSProtocolHandler.CLSID_GammaProtocol1)),
         "java.io.IOException: Failed to register class with ActiveX");
      eqs("nActivate con ProgID desconocido", thrown(() -> nActivate(h, "Gamma.Protocol.1")),
         "java.io.IOException: Unable to determine CLSID");
      int k = NativeSysRegistry.createKey(NativeSysRegistry.reservedKey(0), "Gamma.Protocol.1\\CLSID");
      NativeSysRegistry.setString(k, "", NSProtocolHandler.CLSID_GammaProtocol1, false);
      eqs("ProgID por HKCR\\ProgID\\CLSID", NativeSysCom.clsidFromString("Gamma.Protocol.1"), "{F8535C80-F5EE-11D2-A6AC-0050041A1735}");
      eqs("nActivate con ProgID registrado", thrown(() -> nActivate(h, "Gamma.Protocol.1")),
         "java.io.IOException: Failed to register class with ActiveX");
      eqs("nDeactivate", thrown(() -> {
         NativeSysCom.revokeClassObject(1L);
         return null;
      }), "java.io.IOException: Failed to revoke class factory");

      // IDispatch.Invoke / INetscapeRegistry sin objetos con IDispatch
      eqs("Invoke", thrown(() -> {
         NativeSysCom.invoke(p, "Navigate");
         return null;
      }), "java.io.IOException: IDispatch: bad function name");
      eqs("RegisterProtocol", thrown(() -> NativeSysCom.netscapeRegister(p, "RegisterProtocol")),
         "java.io.IOException: IDispatch: GetIDsOfNames() failed");

      // Release hasta 0: destructor (0x00441f90) y _pInterface = 0
      h.Release();
      eq("Release Java 1", NativeSysCom.refs(p), 1);
      h.Release();
      eq("Release a 0 destruye", NativeSysCom.refs(p), -1);
      eq("_pInterface a 0", pInterface(h), 0);
      // getPtr (0x0040b2b0) con _pInterface 0: OLEInvalidObjectException sin declarar
      eqs("true_AddRef sin objeto", thrown(() -> {
         h.true_AddRef();
         return null;
      }), "NET.worlds.console.OLEInvalidObjectException: No C++ mirror object");
      eqs("QueryInterface sin objeto", thrown(() -> h.QueryInterface(NativeSysCom.IID_IUNKNOWN)),
         "NET.worlds.console.OLEInvalidObjectException: No C++ mirror object");
      eqs("AddRef Java sin objeto", thrown(() -> {
         h.AddRef();
         return null;
      }), "NET.worlds.console.OLEInvalidObjectException");

      // Netscape.mainCallback entero: ActiveX falla y sigue su camino "No Netscape"
      eqs("Netscape.mainCallback", thrown(() -> {
         new Netscape().mainCallback();
         return null;
      }), "(sin excepción)");

      store.delete();
      if (failures > 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("SysComCheck OK");
   }

   interface Call {
      Object run() throws Exception;
   }

   private static Object nActivate(Object h, String clsid) throws Exception {
      Method m = NET.worlds.console.IClassFactory.class.getDeclaredMethod("nActivate", String.class);
      m.setAccessible(true);
      try {
         return m.invoke(h, clsid);
      } catch (InvocationTargetException e) {
         throw (Exception) e.getCause();
      }
   }

   private static int pInterface(IUnknown u) throws Exception {
      java.lang.reflect.Field f = IUnknown.class.getDeclaredField("_pInterface");
      f.setAccessible(true);
      return f.getInt(u);
   }

   private static String thrown(Call c) {
      try {
         c.run();
         return "(sin excepción)";
      } catch (Throwable e) {
         return e.toString();
      }
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FALLA " + what);
      }
   }

   private static void eq(String what, int got, int want) {
      check(what + ": " + got + " != " + want, got == want);
   }

   private static void eqs(String what, String got, String want) {
      check(what + ": \"" + got + "\" != \"" + want + "\"", got == null ? want == null : got.equals(want));
   }
}
