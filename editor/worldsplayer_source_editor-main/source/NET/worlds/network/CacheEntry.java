package NET.worlds.network;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.IniFile;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.Serializable;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URLConnection;
import java.net.UnknownHostException;
import java.util.Date;
import java.util.Observer;
import java.util.Vector;

public class CacheEntry implements Runnable, Serializable {
   static final long serialVersionUID = 1L;
   static boolean httpFaulted = IniFile.override().getIniInt("Offline", 0) == 1 || IniFile.gamma().getIniInt("Offline", 0) == 1;
   static boolean stopOnFault = IniFile.gamma().getIniInt("StopOnHttpFault", 0) == 1;
   static final int CACHE_MAX_ENTRIES = IniFile.gamma().getIniInt("NetCacheEntries", 1000);
   static final int MAX_THREADS = IniFile.gamma().getIniInt("NetCacheThreads", 2);
   static final long CACHE_MOD_TIMEOUT = 3600000L * IniFile.gamma().getIniInt("NetCacheModifiedCheck", 8);
   static Vector threadQueue = new Vector();
   public static final int START = 0;
   public static final int REFRESHING = 2;
   public static final int LOADING = 3;
   public static final int DONE = 4;
   public static final int ERROR = 5;
   public static final int NOSUCHFILE = 6;
   public static final int LOADED = 7;
   CacheEntry next;
   CacheEntry prev;
   int state;
   private transient int count;
   URL url;
   transient int lastRefTime;
   String localName;
   transient Vector observers;
   public long remoteTime = 0L;
   public Date checkTime;
   public transient int size = -1;
   int bytes;
   private transient CacheEntry nextDec;
   private static CacheEntry endDec = new CacheEntry();
   private static CacheEntry baseDec = endDec;
   static int refTime = 0;
   static int numActiveThreads = 0;
   private static Object finalizeSafeLock = new Object();
   private static CacheEntry.SafeFinalizer safeFinalizer = new CacheEntry.SafeFinalizer();
   private static int nextDownloader = 0;

   public static int getConcurrentDownloads() {
      return numActiveThreads;
   }

   public static synchronized void setOffline() {
      httpFaulted = true;
      stopOnFault = true;
   }

   public static boolean getOffline() {
      return httpFaulted;
   }

   public boolean inUse() {
      return this.count > 0 || this.state == 3 || this.state == 2;
   }

   private synchronized void setState(int var1) {
      this.state = var1;
      if (var1 >= 4) {
         this.notifyAll();
      }
   }

   boolean done() {
      return this.state >= 4;
   }

   CacheEntry() {
      this.next = this;
      this.prev = this;
   }

   CacheEntry(URL var1) {
      this.url = var1;
      this.localName = Cache.assignLocalName(var1);
      this.setState(0);
   }

   void incRef() {
      synchronized (finalizeSafeLock) {
         this.count++;
      }

      if (this.count == 1) {
         this.load();
      }
   }

   void safeDecRef() {
      synchronized (finalizeSafeLock) {
         if (this.nextDec == null) {
            this.nextDec = baseDec;
            baseDec = this;
         } else {
            this.count--;
            this.lastRefTime = refTime++;
         }
      }
   }

   synchronized void fullDecRef() {
      this.notifyAll();
      synchronized (Cache.cache) {
         synchronized (finalizeSafeLock) {
            this.count--;
            this.lastRefTime = refTime++;
         }

         if (this.count == 0 && this.remoteTime <= 0L && this.state == 7) {
            Cache.cache.remove(this);
         }
      }
   }

   void addObserver(Observer var1) {
      if (this.state >= 4) {
         var1.update(null, this.url);
      } else {
         if (this.observers == null) {
            this.observers = new Vector();
         }

         this.observers.addElement(var1);
      }
   }

   void notifyObservers() {
      Vector var1;
      synchronized (this) {
         var1 = this.observers;
         this.observers = null;
      }

      if (var1 != null) {
         int var2 = var1.size();

         for (int var3 = 0; var3 < var2; var3++) {
            ((Observer)var1.elementAt(var3)).update(null, this.url);
         }
      }
   }

   URLConnection openURL() throws Exception {
      int var1 = IniFile.gamma().getIniInt("NetCacheRetries", 8);
      java.net.URL var2 = null;
      URLConnection var3 = null;

      while (!httpFaulted) {
         try {
            if (var2 == null) {
               String var4 = this.url.unalias();
               if (var4.endsWith("upgrades.lst")) {
                  var4 = var4 + "?" + (int)(Math.random() * 1000000.0);
               }

               var2 = DNSLookup.lookup(new java.net.URL(var4));
            }

            var3 = var2.openConnection();
            this.remoteTime = var3.getLastModified();
            this.size = var3.getContentLength();
            return var3;
         } catch (UnknownHostException var5) {
            if (NetUpdate.isInternalVersion() || stopOnFault) {
               httpFaulted = true;
            }

            throw var5;
         } catch (IOException var6) {
            var1--;
            if (wasHttpNoSuchFile(var6, var3)) {
               throw new FileNotFoundException("Http " + this.url);
            }

            if (var1 <= 0 || var6 instanceof MalformedURLException) {
               throw var6;
            }

            if (this.state == 2) {
               throw var6;
            }

            System.out.println("Exception " + var6 + " opening " + this.url + ", retrying...");
         }
      }

      throw new FileNotFoundException("Http " + this.url);
   }

   private static boolean wasHttpNoSuchFile(Exception var0, URLConnection var1) {
      try {
         if (((HttpURLConnection)var1).getResponseCode() == 404) {
            return true;
         }
      } catch (Exception var3) {
      }

      return false;
   }

   void forceRecheck() {
      this.checkTime = null;
   }

   void load() {
      if (this.state != 2 && this.state != 3) {
         if (this.state != 5 && this.state != 0) {
            Date var1 = new Date();
            Date var2 = new Date(var1.getTime() - CACHE_MOD_TIMEOUT);
            if (this.checkTime != null && this.checkTime.after(var2) && (this.remoteTime > 0L || this.state == 6)) {
               this.notifyObservers();
               return;
            }

            this.setState(2);
         } else {
            this.setState(3);
         }

         this.checkTime = new Date();
         synchronized (threadQueue) {
            if (numActiveThreads < MAX_THREADS) {
               this.startThread();
            } else {
               threadQueue.addElement(this);
            }
         }
      }
   }

   private void startThread() {
      numActiveThreads++;
      Thread var1 = new Thread(this, "File Downloader " + ++nextDownloader);
      var1.setDaemon(true);
      var1.start();
   }

   public void run() {
      InputStream var1 = null;
      FileOutputStream var2 = null;
      URLConnection var3 = null;
      Cache.cache.totalBytes = Cache.cache.totalBytes - this.bytes;

      try {
         try {
            if (this.state == 2) {
               if (getOffline()) {
                  this.setState(7);
                  return;
               }

               long var4 = this.remoteTime;
               long var6 = DirTimeStamp.request(this.url);
               if (var6 > 0L && var6 <= var4) {
                  this.setState(7);
                  return;
               }

               var3 = this.openURL();
               if (this.remoteTime > 0L && this.remoteTime <= var4) {
                  this.setState(7);
                  return;
               }

               this.setState(3);
            }

            int var29;
            for (var29 = 0; var29 < 2; var29++) {
               this.bytes = 0;
               var1 = null;
               var2 = null;
               if (var3 == null) {
                  var3 = this.openURL();
               }

               var1 = var3.getInputStream();
               Cache.cache.makeSpaceFor(this.size);
               var2 = new FileOutputStream(this.localName);
               byte[] var5 = new byte[2048];

               int var30;
               while ((var30 = var1.read(var5)) != -1) {
                  var2.write(var5, 0, var30);
                  this.bytes += var30;
               }

               var1.close();
               var1 = null;
               var2.close();
               var2 = null;
               if (this.size == -1 || this.bytes == this.size) {
                  break;
               }

               if (var29 == 0) {
                  System.out.println("Network error while downloading, trying again...");
               }

               var3 = null;
            }

            if (this.size >= 0 && this.bytes != this.size) {
               throw new InterruptedException("Network error, got " + this.bytes + " rather than " + this.size + " bytes.");
            }

            if (var29 > 0) {
               System.out.println("Second download attempt succeeded.");
            }

            this.setState(7);
         } catch (Exception var24) {
            System.out.println("Download error for " + this.url);
            System.out.println("\t" + var24.getMessage());
            if (var2 != null) {
               try {
                  var2.close();
               } catch (IOException var22) {
               }

               new File(this.localName).delete();
            }

            this.bytes = 0;
            if (wasHttpNoSuchFile(var24, var3) || var24 instanceof FileNotFoundException) {
               this.setState(6);
               return;
            }

            if (this.state == 2) {
               this.setState(7);
            } else {
               this.setState(5);
            }

            return;
         }
      } finally {
         Cache.cache.totalBytes = Cache.cache.totalBytes + this.bytes;
         this.notifyObservers();
         synchronized (threadQueue) {
            numActiveThreads--;

            while (numActiveThreads < MAX_THREADS && !threadQueue.isEmpty()) {
               CacheEntry var11 = (CacheEntry)threadQueue.elementAt(0);
               threadQueue.removeElementAt(0);
               var11.startThread();
            }
         }
      }
   }

   static class SafeFinalizer implements MainCallback {
      SafeFinalizer() {
         Main.register(this);
      }

      public void mainCallback() {
         while (CacheEntry.baseDec != CacheEntry.endDec) {
            CacheEntry var1;
            synchronized (CacheEntry.finalizeSafeLock) {
               var1 = CacheEntry.baseDec;
               CacheEntry.baseDec = var1.nextDec;
               var1.nextDec = null;
            }

            var1.fullDecRef();
         }
      }
   }
}
