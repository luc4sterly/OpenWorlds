package NET.worlds.scape;

import NET.worlds.core.Hashtable;
import NET.worlds.network.URL;
import java.io.IOException;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;
import java.util.Vector;

public class CDDBLookup implements Runnable {
   public static final int STATUS_SERVERERROR = -3;
   public static final int STATUS_NOTUNIQUE = -2;
   public static final int STATUS_NOTFOUND = -1;
   public static final int STATUS_LOOKING = 0;
   public static final int STATUS_EXACTMATCH = 1;
   public static final int STATUS_CLOSEMATCH = 2;
   private static final boolean debug = false;
   private static final String lookupThreadName = "lookup";
   private static final String siteThreadName = "site";
   private static final String pkgName = "gamma";
   private static final String pkgVersion = "1.0";
   private static final int TIMEOUT = 3000;
   private static final String dbName = "home:cdcache.db";
   private static CDDBHost siteHost = new CDDBHost("cddb.cddb.com", 888);
   private static Vector sites;
   private static Object siteMutex = new Object();
   private static Object knownDisksMutex = new Object();
   private static int lastHostUsed = -1;
   private static Hashtable threadActivity = new Hashtable();
   private static Hashtable knownDisks;
   private static String userName;
   private static String hostName;
   private CDTrackInfo tracks;
   private String hash;
   private CDDBStatus status;
   private static final String discTitleKey = "DTITLE=";
   private static final String trackTitleKey = "TTITLE";

   public CDDBLookup(CDTrackInfo var1) {
      if (userName == null) {
         userName = System.getProperty("user.name").replace(' ', '_');

         try {
            hostName = InetAddress.getLocalHost().getHostName();
         } catch (UnknownHostException var3) {
            hostName = "unknown";
         }
      }

      this.tracks = var1;
      this.hash = CDDBHash.hashString(var1);
      if ((this.status = this.dbLookup()) == null) {
         this.runThread("lookup");
      }
   }

   public String getHash() {
      return this.hash;
   }

   public CDDiskInfo getDiskInfo() {
      return this.getDiskInfo(false);
   }

   public synchronized CDDiskInfo getDiskInfo(boolean var1) {
      if (var1) {
         while (this.status == null) {
            try {
               this.wait();
            } catch (InterruptedException var3) {
            }
         }
      }

      return this.status != null ? this.status.getDiskInfo() : null;
   }

   public int getStatus() {
      return this.status != null ? this.status.getStatus() : 0;
   }

   public void run() {
      String var1 = Thread.currentThread().getName();
      if (var1.equals("lookup")) {
         this.maybeRunSiteThread();

         for (int var2 = 0; var2 < sites.size(); var2++) {
            synchronized (this) {
               Thread var4 = this.runThread("" + var2);

               try {
                  do {
                     this.wait(3000L);
                  } while (this.status == null && this.recentlyActive(var4));
               } catch (InterruptedException var16) {
               }

               this.forgetThread(var4);
               if (this.status != null) {
                  break;
               }

               if (var2 == sites.size() - 1) {
                  this.status = new CDDBStatus(-3);
                  this.notifyAll();
               }
            }
         }
      } else if (var1.equals("site")) {
         Vector var18 = getSiteList();
         synchronized (siteMutex) {
            if (sites == null) {
               sites = var18;
            }

            siteMutex.notifyAll();
         }
      } else {
         Object var19 = null;
         int var21 = 0;

         try {
            var21 = Integer.parseInt(var1);
         } catch (NumberFormatException var14) {
         }

         CDDBHost var22 = null;
         synchronized (siteMutex) {
            var22 = (CDDBHost)sites.elementAt(var21);
         }

         var19 = this.findDiskInfo(var22);
         synchronized (this) {
            if (this.status == null && var19 != null) {
               this.status = (CDDBStatus)var19;
               if (var21 != 0) {
                  synchronized (siteMutex) {
                     Object var7 = sites.elementAt(var21);
                     sites.removeElementAt(var21);
                     sites.insertElementAt(var7, 0);
                  }
               }

               this.notifyAll();
            }
         }
      }
   }

   private static void addSite(Vector var0, String var1, int var2) {
      var0.addElement(new CDDBHost(var1, var2));
   }

   private static void defaultSites() {
      sites = new Vector();
      addSite(sites, "cddb.moonsoft.com", 888);
      addSite(sites, "cddb.moonsoft.com", 8880);
      addSite(sites, "cddb.celestial.com", 888);
      addSite(sites, "cddb.sonic.net", 888);
      addSite(sites, "sunsite.unc.edu", 888);
      addSite(sites, "cddb.netads.com", 888);
      addSite(sites, "cddb.mattdm.org", 888);
      addSite(sites, "cddb.dartmouth.edu", 888);
   }

   private static Vector getSiteList() {
      CDDBConnection var0 = null;

      try {
         var0 = new CDDBConnection(siteHost, false);
         var0.command("sites").startsWith("210 ");
         Vector var2 = new Vector();

         String var1;
         while ((var1 = var0.readBody()) != null) {
            StringTokenizer var3 = new StringTokenizer(var1, " ");
            addSite(var2, var3.nextToken(), Integer.parseInt(var3.nextToken()));
         }

         return var2;
      } catch (IOException var9) {
      } catch (NumberFormatException var10) {
      } catch (NoSuchElementException var11) {
      } finally {
         if (var0 != null) {
            var0.close();
         }
      }

      return null;
   }

   private CDDBStatus findDiskInfo(CDDBHost var1) {
      CDDBConnection var2 = null;

      try {
         var2 = new CDDBConnection(var1, false);
         if (var2.command("cddb hello " + userName + " " + hostName + " " + "gamma" + " " + "1.0").startsWith("200 ")) {
            String var3 = var2.command("cddb query " + CDDBHash.lookupString(this.tracks));
            StringTokenizer var4 = new StringTokenizer(var3, " ");
            String var5 = var4.nextToken();
            if (var5.equals("200")) {
               return this.dbAdd(new CDDBStatus(1, this.getCDDBEntry(var2, var4)));
            }

            if (var5.equals("211")) {
               String var6 = var2.readBody();
               int var7 = 0;

               while (var2.readBody() != null) {
                  var7++;
               }

               if (var7 != 0) {
                  return this.dbAdd(new CDDBStatus(-2));
               }

               return this.dbAdd(new CDDBStatus(2, this.getCDDBEntry(var2, new StringTokenizer(var6, " "))));
            }

            if (var5.equals("202")) {
               return new CDDBStatus(-1);
            }
         }
      } catch (IOException var13) {
      } catch (NoSuchElementException var14) {
      } finally {
         if (var2 != null) {
            var2.close();
         }
      }

      return null;
   }

   private Thread runThread(String var1) {
      Thread var2 = new Thread(this, var1);
      var2.setDaemon(true);
      var2.start();
      return var2;
   }

   private void maybeRunSiteThread() {
      synchronized (siteMutex) {
         if (sites == null) {
            Thread var2 = this.runThread("site");

            try {
               do {
                  siteMutex.wait(3000L);
               } while (sites == null && this.recentlyActive(var2));
            } catch (InterruptedException var5) {
            }

            this.forgetThread(var2);
            if (sites == null) {
               defaultSites();
            }
         }
      }
   }

   private CDDiskInfo getCDDBEntry(CDDBConnection var1, StringTokenizer var2) {
      try {
         String var3 = var2.nextToken();
         String var4 = var2.nextToken();
         if (var1.command("cddb read " + var3 + " " + var4).startsWith("210 ")) {
            return this.parseCDDBEntry(var3, var1);
         }
      } catch (IOException var5) {
      } catch (NoSuchElementException var6) {
      }

      return null;
   }

   private CDDiskInfo parseCDDBEntry(String var1, CDDBConnection var2) throws IOException {
      String var3 = null;
      String var4 = null;
      String[] var5 = new String[this.tracks.getNumTracks()];

      for (int var6 = 0; var6 < var5.length; var6++) {
         var5[var6] = "";
      }

      String var11;
      while ((var11 = var2.readBody()) != null) {
         if (var11.startsWith("DTITLE=")) {
            var11 = var11.substring("DTITLE=".length());
            int var7 = var11.indexOf(47);
            if (var7 == -1) {
               var3 = var4 = var11.trim();
            } else {
               var3 = var11.substring(0, var7).trim();
               var4 = var11.substring(var7 + 1).trim();
            }
         } else if (var11.startsWith("TTITLE")) {
            int var13 = var11.indexOf(61);

            try {
               int var8 = Integer.parseInt(var11.substring("TTITLE".length(), var13));
               var5[var8] = var5[var8] + var11.substring(var13 + 1);
            } catch (NumberFormatException var9) {
            } catch (IndexOutOfBoundsException var10) {
            }
         }
      }

      return new CDDiskInfo(var3, var4, var1, var5);
   }

   static void markActivity() {
      threadActivity.put(Thread.currentThread(), new Long(System.currentTimeMillis()));
   }

   private boolean recentlyActive(Thread var1) {
      Long var2 = (Long)threadActivity.get(var1);
      return var2 != null ? System.currentTimeMillis() - var2 < 3000L : false;
   }

   private void forgetThread(Thread var1) {
      threadActivity.remove(var1);
   }

   private CDDBStatus dbAdd(CDDBStatus var1) {
      synchronized (knownDisksMutex) {
         if (knownDisks.get(this.hash) == null) {
            knownDisks.put(this.hash, var1);

            try {
               new Saver(new URL("home:cdcache.db")).save(knownDisks);
            } catch (Exception var5) {
            }
         }

         return var1;
      }
   }

   private CDDBStatus dbLookup() {
      synchronized (knownDisksMutex) {
         if (knownDisks == null) {
            try {
               knownDisks = (Hashtable)new Restorer(new URL("home:cdcache.db")).restore();
            } catch (Exception var4) {
               knownDisks = new Hashtable();
            }
         }

         return (CDDBStatus)knownDisks.get(this.hash);
      }
   }
}
