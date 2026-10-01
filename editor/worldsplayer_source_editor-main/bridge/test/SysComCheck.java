package NET.worlds.core;

import NET.worlds.console.IDispatch;
import NET.worlds.console.IUnknown;
import NET.worlds.console.NSProtocolHandler;
import NET.worlds.console.Netscape;
import java.io.File;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * gamma.dll's COM outside Windows (NativeSysCom): the local factory of
 * NSProtocolHandler (0x00441f30) with its QueryInterface/AddRef/Release
 * (0x0040ac20/ab80/ab90) through the client's real classes, getPtr
 * (0x0040b2b0) and the failure branches with their literal messages. Exits
 * with 1 if anything fails.
 */
public final class SysComCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File store = File.createTempFile("fw-registry-com", ".reg");
      store.delete();
      System.setProperty("openworlds.registry", store.getPath());

      // IIDFromString
      eqs("lowercase GUID", NativeSysCom.parseGuid("{f8535c80-f5ee-11d2-a6ac-0050041a1735}"), "{F8535C80-F5EE-11D2-A6AC-0050041A1735}");
      eqs("without braces", NativeSysCom.parseGuid("f8535c80-f5ee-11d2-a6ac-0050041a1735"), null);
      eqs("dash moved", NativeSysCom.parseGuid("{f8535c80f-5ee-11d2-a6ac-0050041a1735}"), null);
      eqs("not hex", NativeSysCom.parseGuid("{g8535c80-f5ee-11d2-a6ac-0050041a1735}"), null);
      eqs("ProgID", NativeSysCom.parseGuid("Gamma.Protocol.1"), null);

      // the local factory through NSProtocolHandler: createLocal + IUnknown.init(int)
      NSProtocolHandler h = new NSProtocolHandler();
      int p = pInterface(h);
      check("pointer != 0", p != 0);
      eq("refs after creating", NativeSysCom.refs(p), 1);
      h.AddRef();
      eq("AddRef", NativeSysCom.refs(p), 2);
      int q = h.QueryInterface("{00000001-0000-0000-c000-000000000046}");
      eq("QI IClassFactory returns the same one", q, p);
      eq("QI raises the count", NativeSysCom.refs(p), 3);
      eq("QI IUnknown", h.QueryInterface("{00000000-0000-0000-C000-000000000046}"), p);
      eq("refs", NativeSysCom.refs(p), 4);
      NativeSysCom.release(p);
      NativeSysCom.release(p);
      eq("Release x2", NativeSysCom.refs(p), 2);
      eqs("QI IDispatch", thrown(() -> h.QueryInterface("{00020400-0000-0000-C000-000000000046}")),
         "java.io.IOException: IUnknown.QueryInterface: interface not available");
      eqs("QI with a malformed IID", thrown(() -> h.QueryInterface("IDispatch")),
         "java.io.IOException: nActiveX: Couldn't convert String to IID");
      eq("failures leave the count untouched", NativeSysCom.refs(p), 2);
      // IDispatch(IUnknown) = QueryInterface(IID_IDispatch): there is no IDispatch
      eqs("IDispatch over the factory", thrown(() -> new IDispatch(h)),
         "java.io.IOException: IUnknown.QueryInterface: interface not available");

      // nActivate: CLSIDFromString and CoRegisterClassObject without a COM runtime
      eqs("nActivate with its CLSID", thrown(() -> nActivate(h, NSProtocolHandler.CLSID_GammaProtocol1)),
         "java.io.IOException: Failed to register class with ActiveX");
      eqs("nActivate with an unknown ProgID", thrown(() -> nActivate(h, "Gamma.Protocol.1")),
         "java.io.IOException: Unable to determine CLSID");
      int k = NativeSysRegistry.createKey(NativeSysRegistry.reservedKey(0), "Gamma.Protocol.1\\CLSID");
      NativeSysRegistry.setString(k, "", NSProtocolHandler.CLSID_GammaProtocol1, false);
      eqs("ProgID via HKCR\\ProgID\\CLSID", NativeSysCom.clsidFromString("Gamma.Protocol.1"), "{F8535C80-F5EE-11D2-A6AC-0050041A1735}");
      eqs("nActivate with a registered ProgID", thrown(() -> nActivate(h, "Gamma.Protocol.1")),
         "java.io.IOException: Failed to register class with ActiveX");
      eqs("nDeactivate", thrown(() -> {
         NativeSysCom.revokeClassObject(1L);
         return null;
      }), "java.io.IOException: Failed to revoke class factory");

      // IDispatch.Invoke / INetscapeRegistry without objects that have IDispatch
      eqs("Invoke", thrown(() -> {
         NativeSysCom.invoke(p, "Navigate");
         return null;
      }), "java.io.IOException: IDispatch: bad function name");
      eqs("RegisterProtocol", thrown(() -> NativeSysCom.netscapeRegister(p, "RegisterProtocol")),
         "java.io.IOException: IDispatch: GetIDsOfNames() failed");

      // Release down to 0: destructor (0x00441f90) and _pInterface = 0
      h.Release();
      eq("Release Java 1", NativeSysCom.refs(p), 1);
      h.Release();
      eq("Release to 0 destroys", NativeSysCom.refs(p), -1);
      eq("_pInterface to 0", pInterface(h), 0);
      // getPtr (0x0040b2b0) with _pInterface 0: OLEInvalidObjectException, undeclared
      eqs("true_AddRef without an object", thrown(() -> {
         h.true_AddRef();
         return null;
      }), "NET.worlds.console.OLEInvalidObjectException: No C++ mirror object");
      eqs("QueryInterface without an object", thrown(() -> h.QueryInterface(NativeSysCom.IID_IUNKNOWN)),
         "NET.worlds.console.OLEInvalidObjectException: No C++ mirror object");
      eqs("Java AddRef without an object", thrown(() -> {
         h.AddRef();
         return null;
      }), "NET.worlds.console.OLEInvalidObjectException");

      // The whole Netscape.mainCallback: ActiveX fails and it follows its "No Netscape" path
      eqs("Netscape.mainCallback", thrown(() -> {
         new Netscape().mainCallback();
         return null;
      }), "(no exception)");

      store.delete();
      if (failures > 0) {
         System.out.println(failures + " failures");
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
         return "(no exception)";
      } catch (Throwable e) {
         return e.toString();
      }
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

   private static void eqs(String what, String got, String want) {
      check(what + ": \"" + got + "\" != \"" + want + "\"", got == null ? want == null : got.equals(want));
   }
}
