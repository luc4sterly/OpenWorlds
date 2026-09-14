package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.core.FastDataInput;
import NET.worlds.network.URL;
import java.io.IOException;
import java.util.Hashtable;
import java.util.Vector;

public class URLSelfLoader implements BGLoaded {
   private static Hashtable loaded = new Hashtable();
   private static Hashtable loading = new Hashtable();
   private URL url;
   private Vector callbacks = new Vector();
   private static final int INIT = 0;
   private static final int DONE = -1;
   private int state = 0;
   private FastDataInput inFile;
   private Restorer restorer;
   private URLSelf loadedObj;
   public Object otemp1;
   public Object otemp2;
   public int itemp1;
   public int itemp2;

   public static void load(URL var0, LoadedURLSelf var1) {
      load(var0, var1, false);
   }

   public static void load(URL var0, LoadedURLSelf var1, boolean var2) {
      URLSelf var3 = (URLSelf)loaded.get(var0);
      if (var3 != null) {
         var3.incRef();
         var1.loadedURLSelf(var3, var0, null);
      } else {
         URLSelfLoader var4 = (URLSelfLoader)loading.get(var0);
         if (var4 != null) {
            var4.callbacks.addElement(var1);
         } else {
            new URLSelfLoader(var0, var1, var2);
         }
      }
   }

   public static void unload(URLSelf var0) {
      loaded.remove(var0.getSourceURL());
   }

   public static void immediateLoad(IncrementalRestorer var0, Restorer var1) throws IOException, TooNewException {
      new URLSelfLoader(var0, var1);
   }

   private URLSelfLoader(IncrementalRestorer var1, Restorer var2) throws IOException, TooNewException {
      this.url = null;

      while (this.state != -1) {
         try {
            this.state = var1.incRestore(this.state, var2, this);
         } catch (Exception var4) {
            var4.printStackTrace(System.out);
            Debug.assert_(false);
         }
      }
   }

   public URL getURL() {
      return this.url;
   }

   private URLSelfLoader(URL var1, LoadedURLSelf var2, boolean var3) {
      loading.put(var1, this);
      this.url = var1;
      this.callbacks.addElement(var2);
      BackgroundLoader.get(this, var1, var3);
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      if (var1 == null) {
         return "Can't find file " + this.url;
      }

      try {
         return new FastDataInput(var1);
      } catch (IOException var4) {
         return "Can't load file " + this.url;
      }
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      if (var1 instanceof String) {
         this.doneLoading(null, (String)var1);
         return false;
      }

      Debug.dAssert(this.state != -1);
      if (this.state == 0) {
         this.inFile = (FastDataInput)var1;
         URLSelf var3 = null;

         try {
            this.restorer = new Restorer(this.inFile, this.url);
            var3 = (URLSelf)this.restorer.restore(false);
            this.loadedObj = var3;
            this.loadedObj.setSourceURL(this.getURL());
            if (!(this.loadedObj instanceof IncrementalRestorer)) {
               this.loadedObj.restoreState(this.restorer);
               this.restorer.done();
               return this.doneLoading(this.loadedObj, null);
            }
         } catch (Exception var7) {
            var7.printStackTrace(System.out);
            return this.doneLoading(null, "Can't restore from file " + this.url + ": " + var7.toString());
         }
      }

      try {
         this.state = ((IncrementalRestorer)this.loadedObj).incRestore(this.state, this.restorer, this);
      } catch (Exception var6) {
         var6.printStackTrace(System.out);
         return this.doneLoading(null, var6.toString());
      }

      if (this.state == -1) {
         try {
            this.restorer.done();
         } catch (IOException var5) {
            var5.printStackTrace(System.out);
            return this.doneLoading(null, var5.toString());
         }

         if (this.restorer.version() < 3 && this.loadedObj instanceof Camera) {
            Camera var9 = (Camera)this.loadedObj;
            World var4 = var9.getWorld();
            var4.setSourceURL(var9.getSourceURL());
         }

         return this.doneLoading(this.loadedObj, null);
      } else {
         return true;
      }
   }

   private boolean doneLoading(URLSelf var1, String var2) {
      if (this.inFile != null) {
         this.inFile.close();
         this.inFile = null;
      }

      loading.remove(this.url);
      if (var1 != null) {
         if (this.restorer.version() < 4 && var1 instanceof Camera) {
            Camera var3 = (Camera)var1;
            var1 = var3.getWorld();
            var3.detach();
         }

         loaded.put(this.url, var1);
      }

      int var6 = this.callbacks.size();

      for (int var4 = 0; var4 < var6; var4++) {
         LoadedURLSelf var5 = (LoadedURLSelf)this.callbacks.elementAt(var4);
         if (var1 != null) {
            var1.incRef();
         }

         var5.loadedURLSelf(var1, this.url, var2);
      }

      this.state = -1;
      return false;
   }

   public Room getBackgroundLoadRoom() {
      return null;
   }
}
