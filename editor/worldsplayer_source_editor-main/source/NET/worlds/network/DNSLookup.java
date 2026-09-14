package NET.worlds.network;

import NET.worlds.core.Debug;
import java.net.MalformedURLException;
import java.net.UnknownHostException;
import java.util.Hashtable;
import java.util.StringTokenizer;

public class DNSLookup implements Runnable {
   private static final int defaultTimeout = 30;
   private static Hashtable cache = new Hashtable();
   private String hostName;
   private String[] dottedNames;
   private int timeout;

   public static java.net.URL lookup(java.net.URL var0) throws MalformedURLException, UnknownHostException {
      return lookup(var0, 30);
   }

   public static java.net.URL lookupAll(java.net.URL var0) throws MalformedURLException, UnknownHostException {
      return lookupAll(var0, 30);
   }

   public static java.net.URL lookup(java.net.URL var0, int var1) throws MalformedURLException, UnknownHostException {
      String var2 = var0.getHost();
      if (var2 == null) {
         return var0;
      }

      Debug.assert_(var0.getRef() == null);
      return new java.net.URL(var0.getProtocol(), lookup(var2, var1), var0.getPort(), var0.getFile());
   }

   public static java.net.URL lookupAll(java.net.URL var0, int var1) throws MalformedURLException, UnknownHostException {
      String var2 = var0.getHost();
      if (var2 == null) {
         return var0;
      }

      Debug.assert_(var0.getRef() == null);
      String[] var3 = lookupAll(var2, var1);
      String var4 = "";

      for (int var5 = 0; var5 < var3.length; var5++) {
         if (var5 != 0) {
            var4 = var4 + ";";
         }

         var4 = var4 + var3[var5];
      }

      return new java.net.URL(var0.getProtocol(), var4, var0.getPort(), var0.getFile());
   }

   public static String lookup(String var0) throws UnknownHostException {
      return lookup(var0, 30);
   }

   public static String lookup(String var0, int var1) throws UnknownHostException {
      return isDotted(var0) ? var0 : lookupAllCommon(var0, var1)[0];
   }

   public static String[] lookupAll(String var0) throws UnknownHostException {
      return lookupAll(var0, 30);
   }

   public static String[] lookupAll(String var0, int var1) throws UnknownHostException {
      return isDotted(var0) ? new String[]{var0} : lookupAllCommon(var0, var1);
   }

   private static String[] lookupAllCommon(String var0, int var1) throws UnknownHostException {
      String[] var2 = (String[])cache.get(var0);
      if (var2 == null) {
         var2 = new DNSLookup(var0, var1).getDottedNames();
         if (var2 == null) {
            throw new UnknownHostException(var0);
         }

         cache.put(var0, var2);
      }

      return var2;
   }

   private DNSLookup(String var1, int var2) {
      this.hostName = var1;
      this.timeout = var2;
      if (var2 != 0) {
         Thread var3 = new Thread(this);
         var3.setDaemon(true);
         var3.start();
      } else {
         this.run();
      }
   }

   public void run() {
      this.dottedNames = gethostbyname(this.hostName);
      if (this.timeout != 0) {
         synchronized (this) {
            this.notify();
         }
      }
   }

   private synchronized String[] getDottedNames() {
      if (this.dottedNames == null && this.timeout != 0) {
         try {
            this.wait(this.timeout * 1000);
         } catch (InterruptedException var2) {
         }
      }

      return this.dottedNames;
   }

   private static boolean isDotted(String var0) {
      StringTokenizer var1 = new StringTokenizer(var0, ".");
      if (var1.countTokens() != 4) {
         return false;
      }

      for (int var2 = 0; var2 < 4; var2++) {
         try {
            int var3 = Integer.parseInt(var1.nextToken());
            if (var3 < 0 || var3 > 255) {
               return false;
            }
         } catch (NumberFormatException var4) {
            return false;
         }
      }

      return true;
   }

   private static native String[] gethostbyname(String var0);
}
