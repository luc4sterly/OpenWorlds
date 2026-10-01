package NET.worlds.core;

import java.io.IOException;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

/**
 * gamma.dll's COM ({@code IUnknown}, {@code IDispatch}, {@code IClassFactory},
 * {@code INetscapeRegistry}, {@code NSProtocolHandler}) outside Windows.
 *
 * <p>Without ole32 there are no foreign COM objects: {@code ActiveX.getClassFClsID/
 * getClassFProgID} already fail with IOException (ActiveX hunk in
 * natives.patch), so the only object that can exist is the one that
 * gamma.dll implements itself, the local class factory of
 * {@code NSProtocolHandler.createLocal} (0x00441f30: 8 bytes, vtable
 * 0x00478ce8 and reference count 1 at +4). Of it, what the client can call
 * from Java is translated:
 * <ul>
 * <li>QueryInterface (0x0040ac20): IID_IUnknown (0x00466e40) or
 *     IID_IClassFactory (0x00466e30) -> AddRef and itself; any other ->
 *     E_NOINTERFACE 0x80004002.</li>
 * <li>AddRef (0x0040ab80) and Release (0x0040ab90: at 0 it calls the
 *     destructor at vtable+0x18, 0x00441f90, which frees it).</li>
 * </ul>
 * CreateInstance (0x0040acc0) and LockServer (0x0040ad30) are only called by
 * the COM runtime of another process, which does not exist here.
 *
 * <p>What does delegate to ole32 takes its failure branch, with gamma.dll's
 * literal messages, so that the client follows its own "not available"
 * path (Netscape.mainCallback: "OLEDEBUG: No Netscape").
 */
public final class NativeSysCom {
   /** 0x00466e40: {00000000-0000-0000-C000-000000000046}. */
   static final String IID_IUNKNOWN = "{00000000-0000-0000-C000-000000000046}";
   /** 0x00466e30: {00000001-0000-0000-C000-000000000046}. */
   static final String IID_ICLASSFACTORY = "{00000001-0000-0000-C000-000000000046}";

   /** Live local factories: pointer -> reference count (+4). */
   private static final Map<Integer, int[]> objects = new HashMap<Integer, int[]>();
   private static int nextPtr = 0x00500000;

   private NativeSysCom() {
   }

   /** NSProtocolHandler.createLocal (0x00441f30): the factory with 1 reference. */
   public static synchronized int createLocalFactory() {
      int p = nextPtr;
      nextPtr += 8;
      objects.put(p, new int[]{1});
      return p;
   }

   /** Reference count of a local object, or -1 if it no longer exists (for the checks). */
   static synchronized int refs(int p) {
      int[] r = objects.get(p);
      return r == null ? -1 : r[0];
   }

   /** IUnknown.true_AddRef (0x0040b330) -> AddRef 0x0040ab80. */
   public static synchronized int addRef(int p) {
      return ++object(p)[0];
   }

   /** IUnknown.true_Release (0x0040b3c0) -> Release 0x0040ab90: at 0, destructor 0x00441f90. */
   public static synchronized int release(int p) {
      int[] r = object(p);
      if (--r[0] != 0) {
         return r[0];
      }
      objects.remove(p);
      return 0;
   }

   /**
    * IUnknown.QueryInterface (0x0040b450): the IID with FUN_0040a4d0
    * (IIDFromString: if it fails, IOException "nActiveX: Couldn't convert
    * String to IID" and 0) and the object's QueryInterface (0x0040ac20); if
    * that returns negative, IOException "IUnknown.QueryInterface: interface
    * not available".
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
    * IDispatch.Invoke (0x0040af10): GetIDsOfNames (vtable+0x14) with the
    * name; if it fails, IOException "IDispatch: bad function name". No
    * object that exists here implements IDispatch (the local factory rejects
    * IID_IDispatch in its QueryInterface and ActiveX does not create any
    * others), so the name is never resolved. The original went on to call
    * Invoke with the uninitialized DISPID and the exception pending; here it
    * stops at the first one, which is the one Java sees. Java does not
    * declare IOException on Invoke: it is thrown the way JNI does
    * (NativeSysJni).
    */
   public static void invoke(int p, String name) {
      throw NativeSysJni.throwNew(new IOException("IDispatch: bad function name"));
   }

   /**
    * INetscapeRegistry.RegisterProtocol/RegisterViewer (0x0040b220/250 ->
    * FUN_0040b0b0 -> FUN_0040b030): GetIDsOfNames of L"RegisterProtocol" /
    * L"RegisterViewer"; on failure, IOException "IDispatch: GetIDsOfNames()
    * failed" and false. Same reason as {@link #invoke}.
    */
   public static boolean netscapeRegister(int p, String method) throws IOException {
      throw new IOException("IDispatch: GetIDsOfNames() failed");
   }

   /**
    * IClassFactory.nActivate (0x0040ad80): CLSIDFromString (if it fails,
    * IOException "Unable to determine CLSID") and CoRegisterClassObject;
    * with no COM runtime to register with, its error branch: IOException
    * "Failed to register class with ActiveX". Never returns.
    */
   public static long registerClassObject(int p, String clsid) throws IOException {
      if (clsidFromString(clsid) == null) {
         throw new IOException("Unable to determine CLSID");
      }
      throw new IOException("Failed to register class with ActiveX");
   }

   /**
    * IClassFactory.nDeactivate (0x0040ae60): CoRevokeClassObject of the cookie.
    * None can be registered (nActivate always fails here).
    * ⚠️ VERIFY: ole32 is assumed to return E_INVALIDARG for an unknown cookie
    * (which is what Wine does), which falls into the "Failed to revoke
    * class factory" branch (a negative HRESULT that is neither E_UNEXPECTED
    * nor E_OUTOFMEMORY). The client only gets here with _registerID != 0.
    */
   public static void revokeClassObject(long cookie) throws IOException {
      throw new IOException("Failed to revoke class factory");
   }

   /**
    * CLSIDFromString: a GUID in braces or a ProgID, whose CLSID is the
    * default value of HKCR\ProgID\CLSID (in the portable registry).
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
    * IIDFromString: exactly "{8-4-4-4-12}" in hexadecimal, case
    * insensitive. Returns the canonical uppercase form or null.
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
         // the original would call through the vtable of freed or foreign memory
         throw new IllegalStateException("gamma.dll: COM pointer " + Integer.toHexString(p) + " without an object");
      }
      return r;
   }
}
